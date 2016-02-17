#include "Ping.h"

struct PingSensor PingSensor_create(int pin)
{
  struct PingSensor sensor;
  sensor.pin = pin;
  return sensor;
}
long PingSensor_measure(struct PingSensor*p)
{
  pinMode(p->pin, OUTPUT);      // Modo salida
  digitalWrite(p->pin, LOW);    // Baja el pulso
  delayMicroseconds(2);         // 2 microsegundos para estabilizar
  digitalWrite(p->pin, HIGH);   // Sube el pulso por 5 microsegundos
  delayMicroseconds(5);          
  digitalWrite(p->pin, LOW);    // Baja el pulso
  pinMode(p->pin, INPUT);       // Modo entrada
  return pulseIn(p->pin, HIGH); // Tiempo que tardo el pulso en volver
}
long PingSensor_measureCM(struct PingSensor*p)
{
   return PingSensor_measure(p) / 29 / 2;
}
long PingSensor_measureInches(struct PingSensor*p)
{
    return PingSensor_measure(p)/37;
}
long PingSensor_measureCM_prom(struct PingSensor*p)
{
   return (PingSensor_measureCM(p) + PingSensor_measureCM(p) + PingSensor_measureCM(p))/3;
}