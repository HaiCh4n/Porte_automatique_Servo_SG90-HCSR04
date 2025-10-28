# 🚪 Porte automatique utilisant un capteur à ultrasons et un servomoteur

## 🔧 Introduction
Ce projet simule l'ouverture d'une **porte automatique** à l'approche d'une personne ou d'un objet.

Le système utilise un **capteur à ultrasons HC-SR04** pour mesurer la distance, un **servomoteur SG90** pour contrôler l'ouverture/fermeture de la porte, et une **LED** pour indiquer l'état de fonctionnement.

## ⚙️ Composants
- Arduino Mega 2560 (ou Uno)
- HC-SR04 (capteur à ultrasons)
- Servomoteur SG90
- LED + résistance 220 Ω
- Câble / Plaque d'essai

## 🔩 Connexion
| Appareil | Arduino |
|------------|----------|
| HC-SR04 VCC | 5 V |
| HC-SR04 GND | GND |
| HC-SR04 TRIG | D11 |
| HC-SR04 ECHO | D12 |
| Signal du servomoteur | D10 |
| Servo VCC | 5 V |
| Servo GND | GND |
| LED (+) | D3 (via 220 Ω) |
| LED (–) | GND |

## 🧠 Principe de fonctionnement
1. Le capteur à ultrasons envoie et reçoit des ondes pour calculer la distance.

2. Si un objet **< 20 cm** se trouve à **l'intérieur**, le servomoteur tourne pour ouvrir la porte et la **LED s'allume**.

3. La porte est maintenue ouverte pendant **10 s**, puis le servomoteur revient à sa position initiale (porte fermée) et la **LED s'éteint**.

4. Après chaque cycle, le système **attend 15 s** avant de mesurer à nouveau la nouvelle distance.

## 💻 Objectifs d'apprentissage
- Se familiariser avec la bibliothèque « Servo.h »
- Lire les capteurs avec « pulseIn() »
- Programmer la logique pour contrôler les cycles dans « loop() »
- Comprendre l'application de base d'Arduino aux systèmes automatiques

## 📸 Résultats
En fonctionnement :
- Approche de l'objet → La LED s'allume, la porte s'ouvre pendant 10 s
- Après 10 s → La porte se ferme, la LED s'éteint
- Attendre 15 s → Le système mesure à nouveau et répète le cycle

---

> Ce projet permet de se familiariser avec l'**IDE Arduino**, le **capteur de distance** et le **servocontrôle**.
> Il constitue la base du développement de projets avancés tels qu'un **lave-mains automatique**,
> une **porte intelligente avec ESP32-CAM** ou un **appareil IoT**.
