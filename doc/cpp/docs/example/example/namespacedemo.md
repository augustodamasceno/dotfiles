

# Namespace demo



[**Namespace List**](namespaces.md) **>** [**demo**](namespacedemo.md)



_Top-level namespace for all example entities._ [More...](#detailed-description)
















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**Point**](structdemo_1_1_point.md) &lt;typename T&gt;<br>_Immutable 2-D point in floating-point space._  |
| class | [**Renderable**](classdemo_1_1_renderable.md) <br>_Abstract interface for renderable objects._  |
| class | [**Shape**](classdemo_1_1_shape.md) <br>_A geometric shape with a name, colour, and visibility flag._  |


## Public Types

| Type | Name |
| ---: | :--- |
| enum uint8\_t | [**Channel**](#enum-channel)  <br>_Colour channels supported by the image codec._  |
| enum  | [**LogLevel**](#enum-loglevel)  <br>_Severity levels used in logging._  |
| typedef std::vector&lt; std::string &gt; | [**StringList**](#typedef-stringlist)  <br>_Convenience alias for a vector of strings._  |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  std::string | [**greet**](#function-greet) (const std::string & name) <br>_Builds a greeting message for the given name._  |
|  T | [**maxOf**](#function-maxof) (T a, T b) <br>_Return the larger of two values._  |
|  std::string | [**toString**](#function-tostring) ([**LogLevel**](namespacedemo.md#enum-loglevel) level) <br>_Convert a_ [_**LogLevel**_](namespacedemo.md#enum-loglevel) _to a human-readable string._ |




























## Detailed Description


Everything lives here to exercise the Namespaces section of the generated documentation. 


    
## Public Types Documentation




### enum Channel 

_Colour channels supported by the image codec._ 
```C++
enum demo::Channel {
    Red = 0,
    Green = 1,
    Blue = 2,
    Alpha = 3
};
```




<hr>



### enum LogLevel 

_Severity levels used in logging._ 
```C++
enum demo::LogLevel {
    Debug,
    Info,
    Warning,
    Error,
    Fatal
};
```



Ordered from least to most severe. Use LogLevel::Fatal only when the process cannot continue. 


        

<hr>



### typedef StringList 

_Convenience alias for a vector of strings._ 
```C++
using demo::StringList = std::vector<std::string>;
```




<hr>
## Public Functions Documentation




### function greet 

_Builds a greeting message for the given name._ 
```C++
std::string demo::greet (
    const std::string & name
) 
```



Concatenates `"Hello, "` with the supplied name and a trailing `"!"`.




**
**


```C++
std::string msg = demo::greet("World");  // "Hello, World!"
```





**Parameters:**


* `name` The name to greet. 



**Returns:**

A greeting string in the form `"Hello, <name>!"`.




**Note:**

An empty `name` produces `"Hello, !"`. 





        

<hr>



### function maxOf 

_Return the larger of two values._ 
```C++
template<typename T>
T demo::maxOf (
    T a,
    T b
) 
```





**Template parameters:**


* `T` Any type that supports `operator>`. 



**Parameters:**


* `a` First value. 
* `b` Second value. 



**Returns:**

The greater of `a` and `b`.




**Note:**

When `a` == `b`, `b` is returned. 





        

<hr>



### function toString 

_Convert a_ [_**LogLevel**_](namespacedemo.md#enum-loglevel) _to a human-readable string._
```C++
std::string demo::toString (
    LogLevel level
) 
```





**Parameters:**


* `level` The log severity level. 



**Returns:**

String representation (e.g. `"Warning"`).




**See also:** [**LogLevel**](namespacedemo.md#enum-loglevel) 



        

<hr>

------------------------------
The documentation for this class was generated from the following file `include/example.cpp`

