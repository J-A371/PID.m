#include "USB.h"
#include "PID.h"
#include <avr/io.h>
#include "Descriptors.h"
#include <stdint.h>
#include "VirtualSerial.h"

float PID(float erreur) {
    // Constantes PID (à ajuster selon le système)
    static const float Kp = 1.0f;   // Gain proportionnel
    static const float Ki = 0.1f;   // Gain intégral
    static const float Kd = 0.01f;  // Gain dérivé
    static const float dt = 0.01f;  // Période d'échantillonnage [s]

    // Variables d'état statiques (mémorisées entre les appels)
    static float integrale = 0.0f;
    static float erreur_avant = 0.0f;

    // Terme intégral (avec anti-windup)
    integrale += erreur * dt;
    if (integrale > 100.0f)      integrale = 100.0f;  // Limite haute
    else if (integrale < -100.0f) integrale = -100.0f; // Limite basse

    // Terme dérivé
    float derivee = (erreur - erreur_avant) / dt;

    // Calcul de la commande PID
    float commande = Kp * erreur + Ki * integrale + Kd * derivee;

    // Saturation de la commande (ex: 0-100%)
    if (commande > 100.0f)      commande = 100.0f;
    else if (commande < 0.0f)   commande = 0.0f;

    // Mise à jour pour l'itération suivante
    erreur_avant = erreur;

    return commande;
}
