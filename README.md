# Creative Embedded Systems Module 1
## by Hayagreevan Sriram, hs3387

Module 1 of the Creative Embedded Systems class Demo and Blog of Build: https://hs3387.github.io/

### The code
The code has three main parts:
1. Image converted into the formats required for my UTFT libraries
2. Image scroll
3. Timed text

#### 1. Image Conversion
> Using Henning Karlsen's Rinky-Dink Electronics [ImageConverter tool](http://www.rinkydinkelectronics.com/t_imageconverter565.php) which takes an image input and produces a text output which has an array of numbers in a format undnerstandable by TFT libraries
> This data is then stored in a header file image.h in the project directory

#### 2. Image Scroll
The scroll works by having two arrays: 
 1. currently displayed pixels
 2. total available image pixels

Array 1 is a subset of array 2 (i.e. the portion of the image which is displayed)

The program is in an infinite loop that takes a starting position on the screen and image, both as top left
With each iteration of the loop, the smaller array is moved further through the bigger array (with the width values of [1] initially being 1 to n values of that of [2] then (1+1) and (n+1) values of [2] and so on, where n is the screen width in pixels). 

In this particular project, the scroll works like this to move left to right on a sheet of musical notes. There is also a bigger loop that divides the height of the image in two and switches every time a scroll reaches the right end of the sheet. So the height values of array [1] only ever change to two distinct values.

#### 3. Timed Text
The text portion of the code displays once every two width scrolls, i.e. once both lines of the sheet music have been fully displayed.
The text is simply a set of tft library print statements with ms delays selected for artistic effect.

#### Reproducing
1. Use the tool to generate the image.h file.
2. Change the values of imageW, imageH to match your image and screenW, screenH to match your TFT display
3. Change the value of start to change the scroll start position, and the equation of m to change the scrolling direction
4. Use the set of IF statements to set scroll limits


### Dependencies
Ensure that the Arduino IDE, TTGO T-Display Drivers, and TFT_eSPI library for ESP32s are all installed
