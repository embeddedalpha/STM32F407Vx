# NAU7802 


### NAU7802 is a 24-Bit Dual-Channel ADC For Bridge Sensors. 

#### When running for the first time, make sure NAU7802_Debug is equal to 1. This will print all the values of the register on the serial monitor. Connect the pins A9 and A10 of the microcontroller to a USB-2-Serial Converter. 

#### This is the register map of the device. When NAU7802_Debug = 1, all these register values will be printed on the serial monitor. 
<img width="400" alt="image" src="https://user-images.githubusercontent.com/38166489/145681988-abf9817f-462f-4e8d-82df-11cde4af4ab5.png">

### User has access to the following functions: 

```C
void NAU7802_Setup(I2C_TypeDef *I2C);
float NAU7802_Get_Load_Cell_1(void);
float NAU7802_Get_Load_Cell_2(void);
float NAU7802_Get_Temperature(void);
```

### Example Code:
```C
NAU7802_Setup(I2C1);

float x = NAU7802_Get_Load_Cell_1();
```
