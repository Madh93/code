#include <iostream>
// #include "sensorsreport.pb.h"
#include "captura.pb.h"
#include <vector>
using namespace std;


int main(void){

  Captura captura;

  captura.set_usuario("Migue");
  for (int i=0; i<3; i++) {
      Captura::Roi *roi = captura.add_rois();
      roi->set_x(1+i);
      roi->set_y(2+i);
      roi->set_width(3+i);
      roi->set_height(4+i);
  }

  cout << "Usuario: " << captura.usuario() << endl;
  cout << "Roi: " << captura.rois_size() << endl;

  Captura::Roi vuelta = captura.rois(2);
  cout << vuelta.x() << endl;


  vector<Captura::Roi> mivector();
  //cout << captura.rois().data() << endl;


  // report.set_devicename("ARDUINO01");
  // report.set_timestamp(1362507283);

  // cout << "Device name: " << report.devicename() << endl;
  // cout << "Timestamp: " << report.timestamp() << endl;  
    

  return 0;
}
