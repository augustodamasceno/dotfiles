

# Class demo::Shape



[**ClassList**](annotated.md) **>** [**demo**](namespacedemo.md) **>** [**Shape**](classdemo_1_1_shape.md)



_A geometric shape with a name, colour, and visibility flag._ [More...](#detailed-description)




Inherits the following classes: [demo::Renderable](classdemo_1_1_renderable.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Shape**](#function-shape) (const std::string & name, const std::string & color="white") <br>_Construct a shape._  |
|  const std::string & | [**color**](#function-color) () const<br>_Returns the fill colour string._  |
| virtual void | [**draw**](#function-draw) () override const<br>_Draw the shape if visible._  |
|  void | [**hide**](#function-hide) () <br>_Hide the shape from the output surface._  |
|  bool | [**isVisible**](#function-isvisible) () const<br>_Returns_ `true` _if the shape is currently visible._ |
|  const std::string & | [**name**](#function-name) () const<br>_Returns the shape's name._  |
|  void | [**setColor**](#function-setcolor) (const std::string & color) <br>_Change the fill colour._  |
|  void | [**show**](#function-show) () <br>_Make the shape visible._  |


## Public Functions inherited from demo::Renderable

See [demo::Renderable](classdemo_1_1_renderable.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**draw**](classdemo_1_1_renderable.md#function-draw) () const = 0<br>_Draw the object to the current output surface._  |
| virtual  | [**~Renderable**](classdemo_1_1_renderable.md#function-renderable) () = default<br> |






















































## Detailed Description


Inherits [**Renderable**](classdemo_1_1_renderable.md) and adds metadata. The default colour is `"white"` and the shape is visible on construction.




**
**


```C++
demo::Shape circle("circle", "red");
circle.draw();        // prints: [draw] circle (red)
circle.hide();
circle.draw();        // prints: [hidden] circle
```





**See also:** [**Renderable**](classdemo_1_1_renderable.md) 


**See also:** [**LogLevel**](namespacedemo.md#enum-loglevel) 



    
## Public Functions Documentation




### function Shape 

_Construct a shape._ 
```C++
inline demo::Shape::Shape (
    const std::string & name,
    const std::string & color="white"
) 
```





**Parameters:**


* `name` Human-readable label for the shape. 
* `color` Fill colour string (e.g. `"red"`, `"#ff0000"`). 




        

<hr>



### function color 

_Returns the fill colour string._ 
```C++
inline const std::string & demo::Shape::color () const
```




<hr>



### function draw 

_Draw the shape if visible._ 
```C++
inline virtual void demo::Shape::draw () override const
```



Prints `[ draw ] < name > (< color >)` when visible, or `[hidden] < name >` when the shape has been hidden with [**hide()**](classdemo_1_1_shape.md#function-hide). 


        
Implements [*demo::Renderable::draw*](classdemo_1_1_renderable.md#function-draw)


<hr>



### function hide 

_Hide the shape from the output surface._ 
```C++
inline void demo::Shape::hide () 
```




<hr>



### function isVisible 

_Returns_ `true` _if the shape is currently visible._
```C++
inline bool demo::Shape::isVisible () const
```




<hr>



### function name 

_Returns the shape's name._ 
```C++
inline const std::string & demo::Shape::name () const
```




<hr>



### function setColor 

_Change the fill colour._ 
```C++
inline void demo::Shape::setColor (
    const std::string & color
) 
```





**Parameters:**


* `color` New colour string. 



**Exception:**


* `std::invalid_argument` if `color` is empty. 




        

<hr>



### function show 

_Make the shape visible._ 
```C++
inline void demo::Shape::show () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/example.cpp`

