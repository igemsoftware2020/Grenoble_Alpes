#include <HermAs.h>
#include <Move_plate.h>


Move_plate Mot;
HermAs herm(0b010,Mot);

void setup() {
  herm.setup_OpClass();
}


void loop() {

    if(herm.readMg()){
      herm.interpretMg(); 
    }
    herm.Exec_inWL();    
  
}
