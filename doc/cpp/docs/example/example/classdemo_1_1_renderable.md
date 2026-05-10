

# Class demo::Renderable



[**ClassList**](annotated.md) **>** [**demo**](namespacedemo.md) **>** [**Renderable**](classdemo_1_1_renderable.md)



_Abstract interface for renderable objects._ [More...](#detailed-description)






Inherited by the following classes: [demo::Shape](classdemo_1_1_shape.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**draw**](#function-draw) () const = 0<br>_Draw the object to the current output surface._  |
| virtual  | [**~Renderable**](#function-renderable) () = default<br> |




























## Detailed Description


Any object that can be drawn on screen should inherit from this class and implement [**draw()**](classdemo_1_1_renderable.md#function-draw).




**See also:** [**Shape**](classdemo_1_1_shape.md) 



    
## Public Functions Documentation




### function draw 

_Draw the object to the current output surface._ 
```C++
virtual void demo::Renderable::draw () const = 0
```




<hr>



### function ~Renderable 

```C++
virtual demo::Renderable::~Renderable () = default
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/example.cpp`

