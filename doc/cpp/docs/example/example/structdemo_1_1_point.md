

# Struct demo::Point

**template &lt;typename T&gt;**



[**ClassList**](annotated.md) **>** [**demo**](namespacedemo.md) **>** [**Point**](structdemo_1_1_point.md)



_Immutable 2-D point in floating-point space._ [More...](#detailed-description)






















## Public Attributes

| Type | Name |
| ---: | :--- |
|  T | [**x**](#variable-x)  <br>_Horizontal coordinate._  |
|  T | [**y**](#variable-y)  <br>_Vertical coordinate._  |
















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Point**](#function-point) (T x, T y) <br>_Construct a point at (x, y)._  |
|  T | [**distanceSquared**](#function-distancesquared) (const [**Point**](structdemo_1_1_point.md#function-point)&lt; T &gt; & other) const<br>_Compute the squared distance to another point._  |




























## Detailed Description




**Template parameters:**


* `T` Numeric type for the coordinates (default: `double`). 




    
## Public Attributes Documentation




### variable x 

_Horizontal coordinate._ 
```C++
T demo::Point< T >::x;
```




<hr>



### variable y 

_Vertical coordinate._ 
```C++
T demo::Point< T >::y;
```




<hr>
## Public Functions Documentation




### function Point 

_Construct a point at (x, y)._ 
```C++
inline demo::Point::Point (
    T x,
    T y
) 
```





**Parameters:**


* `x` Horizontal coordinate. 
* `y` Vertical coordinate. 




        

<hr>



### function distanceSquared 

_Compute the squared distance to another point._ 
```C++
inline T demo::Point::distanceSquared (
    const Point < T > & other
) const
```



Uses squared distance to avoid the cost of `std::sqrt` when only relative ordering is required.




**Parameters:**


* `other` The target point. 



**Returns:**

Squared Euclidean distance.




**
**


```C++
Point<> a{0.0, 0.0};
Point<> b{3.0, 4.0};
double d2 = a.distanceSquared(b);  // 25.0
```
 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `include/example.cpp`

