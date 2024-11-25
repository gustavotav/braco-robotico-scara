#include <VarSpeedServo.h> // https://github.com/netlabtoolkit/VarSpeedServo

// Declaração dos objetos servo para cada eixo
VarSpeedServo servo_x; // Eixo X: direita e esquerda
VarSpeedServo servo_y; // Eixo Y: frente e trás
VarSpeedServo servo_z; // Eixo Z: sobe e desce
VarSpeedServo servo_w; // Eixo W: abre e fecha

// Definição das entradas analógicas para os joysticks
const int js_x = A0; // Joystick eixo X
const int js_y = A1; // Joystick eixo Y
const int js_z = A3; // Joystick eixo Z
const int js_w = A4; // Joystick eixo W

// Definição das portas PWM para os servos
const int s_x = 3;  // Servo eixo X
const int s_y = 5;  // Servo eixo Y
const int s_z = 10; // Servo eixo Z
const int s_w = 11; // Servo eixo W

// Definição das posições iniciais dos servos
int val_x = 90;
int val_y = 90;
int val_z = 90;
int val_w = 90;

void setup() {
  Serial.begin(9600);

  // Inicializa os servos e reporta no monitor serial
  servo_x.attach(s_x, 1, 180);
  Serial.println("Servo X inicializado na porta 3.");
  
  servo_y.attach(s_y, 1, 180);
  Serial.println("Servo Y inicializado na porta 5.");
  
  servo_z.attach(s_z, 1, 180);
  Serial.println("Servo Z inicializado na porta 10.");
  
  servo_w.attach(s_w, 1, 180);
  Serial.println("Servo W inicializado na porta 11.");

  Serial.println("Setup completo.");
}

void loop() {
  // Leitura dos valores dos joysticks
  int leitura_js_x = analogRead(js_x);
  int leitura_js_y = analogRead(js_y);
  int leitura_js_z = analogRead(js_z);
  int leitura_js_w = analogRead(js_w);

  // Exibe as leituras para diagnóstico
  Serial.print("Leituras dos Joysticks - X: "); Serial.print(leitura_js_x);
  Serial.print(", Y: "); Serial.print(leitura_js_y);
  Serial.print(", Z: "); Serial.print(leitura_js_z);
  Serial.print(", W: "); Serial.println(leitura_js_w);

  // Controle do eixo X (esquerda e direita)
  if (leitura_js_x > 970) { 
    val_x = min(val_x + 1, 180); // Limita o valor a 180
    servo_x.write(val_x, 120, true);
    Serial.print("Eixo X movendo para a direita: "); Serial.println(val_x);
  } else if (leitura_js_x < 50) {
    val_x = max(val_x - 1, 0); // Limita o valor a 0
    servo_x.write(val_x, 120, true);
    Serial.print("Eixo X movendo para a esquerda: "); Serial.println(val_x);
  }

  // Controle do eixo Y (frente e trás)
  if (leitura_js_y < 50) {
    val_y = min(val_y + 1, 180);
    servo_y.write(val_y, 120, true);
    Serial.print("Eixo Y movendo para frente: "); Serial.println(val_y);
  } else if (leitura_js_y > 970) {
    val_y = max(val_y - 1, 0);
    servo_y.write(val_y, 120, true);
    Serial.print("Eixo Y movendo para trás: "); Serial.println(val_y);
  }

  // Controle do eixo Z (sobe e desce)
  if (leitura_js_z < 50) {
    val_z = min(val_z + 1, 180);
    servo_z.write(val_z, 120, true);
    Serial.print("Eixo Z subindo: "); Serial.println(val_z);
  } else if (leitura_js_z > 970) {
    val_z = max(val_z - 1, 0);
    servo_z.write(val_z, 120, true);
    Serial.print("Eixo Z descendo: "); Serial.println(val_z);
  }

  // Controle do eixo W (abre e fecha)
  if (leitura_js_w < 50) {
    val_w = min(val_w + 1, 180);
    servo_w.write(val_w, 120, true);
    Serial.print("Eixo W abrindo: "); Serial.println(val_w);
  } else if (leitura_js_w > 970) {
    val_w = max(val_w - 1, 0);
    servo_w.write(val_w, 120, true);
    Serial.print("Eixo W fechando: "); Serial.println(val_w);
  }

  delay(30); // Aguarda para estabilidade
}
