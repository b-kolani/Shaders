#version 120

// Transmet la couleur reçue de SFML -> GPU qui doit l'interpoler 
// puis ensuite être envoyée au fragment shader
varying vec4 outColor;

// Transmet la position du sommet reçue de SFML -> GPU qui doit 
// l'interpolée et l'envoyer ensuite au fragement shader
varying vec2 position;

void main() {
    // Position du sommet fournie par SFML
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

    // Couleur du sommet fournie par SFML au vertex shader puis 
    // envoyée au GPU pour une couleur interpolée après Rastaterisation
    // et transmise comme couleur finale au fragment shader
    outColor = gl_Color;

    position = gl_Vertex.xy;
}