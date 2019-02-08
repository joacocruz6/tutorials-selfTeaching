# Structs in Go
Like in C, there are no classes and, some consecuences, there are no objects. But also like in C, there are structs!.

For this lesson we will do a simple struct, so now we have to built a game in go about a car. So we need to represent it in some way that is not an object. For this is the structs of Go, it is a primitive representation of an object.

So to declare our car struct we put in our code:
```Go
type car struct {
  gas_pedal uint16 //min 0 max 65535
  brake_pedal uint16
  steering_wheel int16 //-32k to +32k of values possibles
  top_speed_kmh float64
}
```
So now we will create a car in our main function
```Go
func main(){
  a_car := car{gas_pedal: 22341,
              brake_pedal: 0,
              steering_wheel: 1256,
              top_speed_kmh: 225.0}
  var another_car car = car{22341,
                            0,
                            1256,
                            225.0}
}
```
To access the data on our structs we use the . like in C.
