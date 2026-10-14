#version 120

// Reçoit la couleur interpolée par le GPU
varying vec4 outColor;

// Reçoit la position interpolée par le GPU 
varying vec2 position;

// Variables dont les valeurs sont fournies par 
// le programme qui utilise le shader ici notre 
// programme C++. Elles restent constantes pendant 
// un appel de dessin donné, contrairement à position
// qui varie d'un fragment à l'autre.
uniform float top;
uniform float height;

void main()
{
    // Coordonnée normalisée entre 0.0 et 1.0
    float normalizedY = (position.y - top) / height;

    // Utilise la couleur reçue pour colorer le fragment
    // gl_FragColor = outColor * vec4(0.5, 0.5, 0.5, 1.0);
    // gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);

    if (normalizedY < 0.5)
    {
        gl_FragColor = vec4(0.0, 0.0, 1.0, 1.0);
    }
    else 
    {
        gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
    }
}