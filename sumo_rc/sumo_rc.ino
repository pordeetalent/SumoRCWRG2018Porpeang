//Sasiraporn Nokyoongthong
//porpeangtalent@gmail.com
//2018-07-14
#include <popxt.h>
char key;
void setup(){  
  glcdMode(1);  
  setTextSize(2);  
  glcd(4,1,"HWN ROBOT");
  glcd(5,1,"PorPeang");
  glcd(1,1,"Press OK");  
  sw_ok_press();  
  glcdClear();
  pinMode(0,INPUT_PULLUP);
}
void loop(){  
  glcd(4,1,"HWN ROBOT");
  glcd(5,1,"PorPeang");
  if(uart1_available())  {    
    key=uart1_getkey();    
    if(key==0x38){      
      glcd(1,1,"Forward   ");      
      glcd(2,1,"                  ");
      fd(60);    
    }    
    else if (key==0x43){      
      glcd(1,1,"Forward          ");      
      glcd(2,1,"Gear1");
      fd(80);    
    }
    else if (key==0x44){      
      glcd(1,1,"Forward          ");  
      glcd(2,1,"Gear2");    
      fd(100);    
    }   
    else if (key==0x32){      
      glcd(1,1,"Backward  ");     
      glcd(2,1,"                  "); 
      bk(60);    
    }    
    else if (key==0x36){      
      glcd(1,1,"Spin Right           ");      
      glcd(2,1,"                  ");
      sl(50);    
    }    
    else if (key==0x34){      
      glcd(1,1,"Spin Left         ");      
      glcd(2,1,"                  ");
      sr(50);    
    }    
    else {    
      glcd(1,1,"Motor Stop");    
      glcd(2,1,"                  ");
      ao();  
    }
  }
}
