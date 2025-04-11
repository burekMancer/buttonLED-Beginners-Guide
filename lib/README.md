# Button controller LED - User Manual
### A __beginners__ guide meant to help beginners understand the setup and use of a Button-Controlled LED system
 $~$    
 $~$
 $~$    
 ![Project Preview](/img/tinkercad.png)       

## __Table of Contents__
* __Introduction__
* __Requiered Components__
* __Assembly Instructions (With Explanations)__
* __Software Setup (PlatformIO)__
* __Uploading Code & Testing__
* __Troubleshooting__
* __Safety Guidelines__
$~$   


### *If you are new to electronics and lack basic knowledge it would be a good idea to go through the "Safety Guidelines" page __before__ you start with the assembly*
$~$     


## Introduction
### What does the project do
This project creates an LED that the user can control through the use of a button.  
It is built using PlatformIO and is compatible with Arduino-based microcontrollers  
    
 $~$  
 ### Who is this manual for
This Manual is meant for beginners with none or very basic knowledge of electronics

 $~$  
 ### What is the purpose of this manual
 To provide a good startpoint in order for beginners to either begin or expand their knowledge of electronics as well as get an understanding of what PlatformIO is and how to use it.  
 The goal is for the user to be able to fully understand, assemble and code the project by themselves after going through the manual

$~$  

$~$  



## __Required Components__

 * ### __1x Microcontroller (this guide will be using the Arduino Uno R4 WIFI)__
  
  ![Arduino UNO R4 WIFI](/img/arduino.png)

 * ### __1x LED__
  
  ![LED](/img/led.png)  

 * ### __1x Push Button__  
  
  ![Push Button](/img/button.png)

 * ### __2x Reistors (One 300Ohm for the LED and One 1k Ohm for the button)__
  
  ![resistor](/img/res.png)

 * ### __1x Breadboard (this guide uses a small Breadboard)__
  
  ![Breadboard](/img/bB.png)

 * ### __7x Jumper wires(A good idea is to use different colors to help differentiate them from eachother)__
  
  ![wires](/img/jWire.png)

 * ### __1x USB Cable (used for uploading the code, the Arduino in this example uses a USB-C cable)__
  ![USB-C](/img/usbC.png)

  $~$  

  $~$  
  ## __Assembly Instructions (With Explanations)__
### Make sure to check the provided picture of the finished project found at the beginning of the manual when unsure of anything
  1. Start by connecting the __5V__ pin of your Arduino to the __Red(+)__ board rail of the breadboard. Connect the __GND__ pin of your Arduino to the __blue(-)__ board rail.  
   
  2. Next insert your Push Button in the middle of the breadboard so that the left legs are connected to the __24__ and the right on the __26__ rows of the breadboard(Look at the project image at the start of the manual to get a better understanding).  
$~$  
*When connecting a Push Button in such a way you create a larger rail by connecting both sides vertically, additionally when the button is pressed it establishes a "bridge" to connect the left and right sides allowing any signal to follow from one through the other.* **(Due to this being a __Push__ button the connection is only created while you press it).**
1. Using a __jumper wire__ connect the __26__ row of the breadboard to the __red(+)__ rail, the goal here is for the Arduino to recieve a **HIGH** signal when you press the button and a **LOW** one when you dont.  
Connect the __24__ row of the breadboard to the __-3__ pin of the Arduino with a __jumper wire__ (this will be used to read the state of the button).  
$~$  
*Now when the button is pressed the electricity will flow from the Arduino, letting it know that it is pressed. However when the button is released the connection has nowhere to go, this leads to the Arduino reading false as well as random values. We will be fixing this in the next step.*
1. In order to proceed from this point we need to bring the resistor in the picture, connect one side of your __1k Ohm resistor__ to the __24__ number row of the breadboard and connect the other side to the __19__ number row, after you have inserted the __1k Ohm resistor__ use a __jumper wire__ to connect the __19__ number row to the __blue(-)__ rail.  
$~$  
*This will cause the __-3 pin__ to connect to ground when the button is released, this enables electricity to flow from the ground to your arduino when the button is not pressed which leads to the reading of a __LOW__ signal.*
1. Next up is the __LED__, connect the __Anode__(the long leg) to the __12__ number row of the breadboard and the __Cathode__ to the number __11__ row *(you may notice that in the example shown at the top of the manual the LED is connected through __jumper wires__, that is only done in order to properly see the __LED__, you can insert it directly on your breadboard when assembling yourself)*.  
Now take your __300 Ohm resistor__ and connect one side to the number __12__ row where the __Anode__ is connected and the other side to the number __16__ row, after inserting the __resistor__ you need to connect the number __11__ number row where the __Cathode__ is to the __black(-)__ rail using a __jumper wire__. Next, in order for the breadboard to gain control of the __LED__ you need to connect the __2 pin__ of the __Arduino__ to the number __16__ row of the __breadboard__.

$~$  
$~$  
  
## __Software Setup (PlatformIO)__
* Begin by installing [Visual Studio Code](https://chatgpt.com/c/67ed0a11-e33c-800d-aec4-34ee7867eff7). After installing vsCode you need to go to your extentions (if you dont know where to find that click [Here](https://code.visualstudio.com/docs/getstarted/extensions)) and search for and install PlatformIO.  
* You can now access the PlatformIO homepage by pressing the little __house__ icon on the bottom-left of your vsCode screen, then you want to press __"New Project"__, this will take you to the "Project Wizard", where you input your Board and Framework, in this example we will be using an Arduino board and therefore also an Arduino Framework, after inputing the correct settings you will have to wait for the wizard to initialize, this may take abit of time  
* You will now see that the Wizard has created a work folder containing smaller folders as well as files inside, it should look something like this:  
>WorkFolder
>>.pio  
>>.vscode  
>>include  
>>lib  
>>src  
>>test  
>>.gitignore  
>>platformio.ini

* The most important folder/s to focus on now are the "src" and possibly the "lib" folders, in the "src" you will find your "main.cpp" file, this is where you will be doing your coding.  
Optionally you can check on your "lib" folder to access your "README.md" file, this is used for documentation and can come in handy if you are interested in documenting your experience.  
You can also open your "platformIO.ini" file to see your platformIO settings. This should be automatically made with your settings in mind when you create the "New Project" 
  
$~$  
$~$

## __Uploading Code & Testing__
### After setting up your software, open up your "main.cpp" file located in the "src" folder and insert this code:  
```cpp
#include <Arduino.h> //Including Arduino library for basic functions

//Defining the pin nums for the button and LED
const int button = 3; 
const int LED = 2;

void setup()
{
  pinMode(button, INPUT); //the button pin is set as an imput to read its state
  pinMode(LED, OUTPUT); //the LED pin is set as an output to control the LED
}

void loop()
{
  int buttonValue = digitalRead(button); //This is to read the buttons state(HIGH or LOW)
//IF the button is pressed (HIGH), turn on the LED
  if (buttonValue != 0)
  {digitalWrite(LED, HIGH);}//Turns the LED on

  else//ELSE if the button is not pressed (LOW), turn off the LED
  {digitalWrite(LED, LOW);} //Turns the LED off
}
```  
$~$  
$~$  
* After inserting your code, you want to finally plug your Arduino model onto your computer with the use of your __USB-C__ cable.  
You can now __Build__ your code by clicking the check-symbole on the top-right of your vsCode (or pressing Ctrl + Alt + B). Check if it is succesfull and then proceed with the __upload__ by pressing the arrow symbole, also located on the top-right (Or by pressing Ctrl + Alt + U)
$~$  
* __Your model should look something like this__  
  
  ![Finished model](/img/aPic.png)
* __Now to test the project you simply have to press the button. This should be the response__  
[![Watch the video](https://img.youtube.com/vi/S3uoCMsGVrU/0.jpg)](https://www.youtube.com/watch?v=S3uoCMsGVrU)
$~$  
$~$  

## Troubleshooting
Some common problems and fixes:  
* **LED not lighting up.**  
  This can be caused by a few easy to miss mistakes, you can start by ensuring that your wiring and placement of the resistor is correct, if that checks out you can move on to checking your code and making sure that the right pin is being associated with the LED
* **Button not functioning**  
  Simmilarly to the LED this might malfunction due to the same reasons, follow the same steps as the LED and begin by checking if all the wires and the resistor associated with the button are placed correctly, if that doesnt fix it move on to checking your code.
* **Common mistakes in code**  
  One of the most common mistakes in code would be to forget your semicollons (;) after a line of code, this is easy to miss but will lead to your entire code being unusable.  
  Another common mistake would be forgetting to use capital letters when needed, we are using a Capital letter-sensitive language to code our project, ie: 
  ```cpp
  digitalWrite(LED, HIGH);
  //This is as previously shown the proper way to write the function

  dititalwrite(LED, high);
  //This however would not work due to the 2 errors of not having a capital letter in "Write" and not using capital letters for "HIGH".
  ```
$~$  
$~$  
## Safety Guidelines
* Make sure you dont exceed voltage ratings
* Avoid short circuits, this can be done by using websites to assemble your project online before doing it in real life. [TinkerCad](https://www.tinkercad.com/dashboard) is a good place to start.
* Handle your components with care and caution
 
 $~$  
 $~$  
 ## Summary
 You have now successfully built your button-controlled LED, I hope that the guide has helped teach you the very basics of electronics and PlatformIO and pushed you to continue onto a bigger project.