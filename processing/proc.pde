import processing.serial.*;
import java.awt.Robot; //java library that lets us take screenshots
import java.awt.AWTException;
import java.awt.event.InputEvent;
import java.awt.image.BufferedImage;
import java.awt.Rectangle;
import java.awt.Dimension;

int RES_X;
int RES_Y;

Serial myPort;
Robot robby;

//String val;

void setup(){
  RES_X = 1920;
  RES_Y = 1080;
  size(200,200);
  String portName = Serial.list()[1];
  myPort = new Serial(this, portName, 9600);
  
  try{ //standard Robot class error check
    robby = new Robot();
  }
  catch (AWTException e){
    println("Robot class not supported by your system!");
    exit();
  }
  
}

void draw(){
  /*if (myPort.available() > 0){
    println(myPort.readStringUntil('\n')); 
  }*/
  
  /*if(mousePressed == true){
    myPort.write('1');
    println("1"); 
  }*/
  
  myPort.write(0xff);
  WriteSection(new Rectangle(0,RES_Y/2,RES_X/3,RES_Y/2));
  WriteSection(new Rectangle(0,0,RES_X/3,RES_Y/2));
}

void WriteSection(Rectangle rect){
  int pixel;
  float r = 0;
  float g = 0;
  float b = 0;
  
  BufferedImage screenshot = robby.createScreenCapture(rect);
  
  for (int i = 0; i < RES_X/3; i=i+2){
    for(int j = 0; j < RES_Y/2; j = j+2){
      pixel = screenshot.getRGB(i,j);
      r += (int)(255&(pixel>>16));
      g += (int)(255&(pixel>>8));
      b += (int)(255&(pixel));
    } 
  }
  
  r=r/(RES_X/6 * RES_Y/4); //average red calc
  g=g/(RES_X/6 * RES_Y/4); //average green
  b=b/(RES_X/6 * RES_Y/4); //average blue
  
  myPort.write((byte)(r));
  myPort.write((byte)(g));
  myPort.write((byte)(b));
}
