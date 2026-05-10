

# File example.cpp



[**FileList**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**example.cpp**](example_8cpp.md)

[Go to the source code of this file](example_8cpp_source.md)

_Dot Files — C++ example to test the dotfiles documentation pipeline._ [More...](#detailed-description)

* `#include <string>`
* `#include <iostream>`
* `#include <vector>`
* `#include <stdexcept>`













## Namespaces

| Type | Name |
| ---: | :--- |
| namespace | [**demo**](namespacedemo.md) <br>_Top-level namespace for all example entities._  |


## Classes

| Type | Name |
| ---: | :--- |
| struct | [**Point**](structdemo_1_1_point.md) &lt;typename T&gt;<br>_Immutable 2-D point in floating-point space._  |
| class | [**Renderable**](classdemo_1_1_renderable.md) <br>_Abstract interface for renderable objects._  |
| class | [**Shape**](classdemo_1_1_shape.md) <br>_A geometric shape with a name, colour, and visibility flag._  |






















## Public Functions

| Type | Name |
| ---: | :--- |
|  int | [**main**](#function-main) (int argc, char \* argv) <br>_Program entry point._  |



























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**DEMO\_MAX\_ITEMS**](example_8cpp.md#define-demo_max_items)  `64`<br>_Maximum number of items the demo container will hold._  |

## Detailed Description


Covers free functions, enums, structs, classes, templates, typedefs, and macros so every section of the generated Markdown output can be exercised.




**Author:**

Augusto Damasceno 




**Copyright:**

BSD-2-Clause. See [https://github.com/augustodamasceno/dotfiles](https://github.com/augustodamasceno/dotfiles) 





    
## Public Functions Documentation




### function main 

_Program entry point._ 
```C++
int main (
    int argc,
    char * argv
) 
```



Exercises all demo entities and prints results to standard output.




**Parameters:**


* `argc` Number of command-line arguments (unused). 
* `argv` Array of command-line argument strings (unused). 



**Returns:**

0 on success.




**See also:** [**demo::greet()**](namespacedemo.md#function-greet) 


**See also:** [**demo::Shape**](classdemo_1_1_shape.md) 


**See also:** [**demo::LogLevel**](namespacedemo.md#enum-loglevel) 



        

<hr>
## Macro Definition Documentation





### define DEMO\_MAX\_ITEMS 

_Maximum number of items the demo container will hold._ 
```C++
#define DEMO_MAX_ITEMS `64`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/example.cpp`

