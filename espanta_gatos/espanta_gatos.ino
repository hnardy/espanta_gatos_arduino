=================abertura de classe==================
class Armadilha {
    private: 
      int _pinGatilho;  //pino de leitura da luminosidade (deve ser uma porta analogica)
      int _pinDisparo;  //pino que ativa o mecanismo da armadilha 
      int _tolerancia; //tolerancia do gatilho
    
    public:
      //criação do obj armadilha deve instanciar o pino do gatilho e o pino que ativa o mecanismo e a tolerancia do gatilho
  
      //==========método construtor=============
      Armadilha(int pinGatilho, int pinDisparo, int tolerancia){
      _pinGatilho = pinGatilho;
      
        pinMode(_pinGatilho, INPUT_PULLUP);
      _pinDisparo = pinDisparo;
        
        pinMode(_pinDisparo, OUTPUT);
      _tolerancia = tolerancia;
      }
      //=======================================

      
      //==========interface====================
      bool leitura();//determina se o gatilho está ativado ou não 
      void disparo(bool disp); //rotina de desparo do mecanismo 
      //=========================================
      
};//================classe fechada===============

//========criação de rotinas da classe===========

// se o valor medido for maior que a tolerancia temos retorna true
bool Armadilha::leitura(){
  int medida = analogRead(this->_pinGatilho);
  Serial.println(medida);
  if(medida > this->_tolerancia){
    return true;
  }else{
    return false;
  }
}

void Armadilha::disparo(bool disp){
  if (disp){
    digitalWrite(this->_pinDisparo,HIGH);
    delay(5000);
  }else{
    digitalWrite(this->_pinDisparo,LOW);
  }
}
//============fim das rotinas==============


//objeto criado com escopo global
Armadilha* arm1 = new Armadilha(A0,7,300);

void setup() {
  //Serial.begin(9600);
}

void loop() {
  arm1->disparo(arm1->leitura()); //se a leitura retornar 1 o mecanismo de disparo deve ser acionado 
  delay(1000);
}
