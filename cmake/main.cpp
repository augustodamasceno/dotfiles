#include "core/core.h"
#include "ui/ui.h"
#include "utils/utils.h"

#include <torch/torch.h>


struct XorNet : torch::nn::Module {
    torch::nn::Linear fc1{nullptr}, fc2{nullptr};

    XorNet() {
        fc1 = register_module("fc1", torch::nn::Linear(2, 4));
        fc2 = register_module("fc2", torch::nn::Linear(4, 1));
    }

    torch::Tensor forward(torch::Tensor x) {
        x = torch::tanh(fc1->forward(x));
        x = torch::sigmoid(fc2->forward(x));
        return x;
    }
};

int main() {
    Ui   ui;
    Core core;

    ui.printBanner("XOR - LibTorch + Core / Ui / Utils");

    //-- Build network ------------------------------------------------------
    auto net = std::make_shared<XorNet>();

    //-- Prepare dataset via Core -------------------------------------------
    const auto dataset = core.xorDataset();

    std::vector<float> flatInputs;
    for (const auto& [in, out] : dataset)
        for (float v : in)
            flatInputs.push_back(v);

    //-- Normalise inputs via Utils -----------------------------------------
    flatInputs = Utils::normalize(flatInputs); // illustrative; {0,1} data is already normalised

    //-- Build tensors -------------------------------------------------------
    torch::Tensor xTrain = torch::zeros({4, 2});
    torch::Tensor yTrain = torch::zeros({4, 1});
    for (int i = 0; i < 4; ++i) {
        xTrain[i][0] = dataset[i].first[0];
        xTrain[i][1] = dataset[i].first[1];
        yTrain[i][0] = dataset[i].second[0];
    }

    //-- Train --------------------------------------------------------------
    torch::optim::Adam optimizer(net->parameters(),
                                 torch::optim::AdamOptions(0.01));
    net->train();
    for (int epoch = 0; epoch < 2000; ++epoch) {
        optimizer.zero_grad();
        auto pred = net->forward(xTrain);
        auto loss = torch::mse_loss(pred, yTrain);
        loss.backward();
        optimizer.step();
    }

    //-- Predict & display via Ui -------------------------------------------
    net->eval();
    torch::NoGradGuard no_grad;

    std::vector<float> predicted, expected;
    for (std::size_t i = 0; i < dataset.size(); ++i) {
        torch::Tensor input = torch::tensor({dataset[i].first[0],
                                             dataset[i].first[1]}).unsqueeze(0);
        const float pred = net->forward(input).item<float>();
        predicted.push_back(pred);
        expected.push_back(dataset[i].second[0]);
    }

    ui.printBanner("Results");
    for (std::size_t i = 0; i < dataset.size(); ++i)
        ui.printResult(static_cast<int>(i), dataset[i].first, predicted[i], expected[i]);

    ui.printAccuracy(Utils::accuracy(predicted, expected));

    return 0;
}

