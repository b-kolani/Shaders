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
// uniform float splitRatio;
uniform float left;
uniform float width;

void main()
{
    // Coordonnée normalisée entre 0.0 et 1.0
    float normalizedY = (position.y - top) / height;
    float normalizedX = (position.x - left) / width;
    // float blend = (normalizedY + normalizedX) / 2.0;
    // float blend = normalizedX * 0.8 + normalizedY * 0.2;
    float blend = normalizedX * 1.2 + normalizedY * 0.2;
    float clamped = clamp(blend, 0.0, 1.0);


    // Utilise la couleur reçue pour colorer le fragment
    // gl_FragColor = outColor * vec4(0.5, 0.5, 0.5, 1.0);
    // gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);

    // if (normalizedY < splitRatio)
    // {
    //     gl_FragColor = vec4(0.0, 0.0, 1.0, 1.0);
    // }
    // else 
    // {
    //     gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
    // }

    // Dégradé vertical
    // gl_FragColor = mix(
    //     vec4(0.0, 0.0, 1.0, 1.0),
    //     vec4(1.0, 0.0, 0.0, 1.0),
    //     1.0 - normalizedY
    // );

    // Dégradé horizontal
    // gl_FragColor = mix(
    //     vec4(0.0, 0.0, 1.0, 1.0),
    //     vec4(1.0, 0.0, 0.0, 1.0),
    //     1.0 - normalizedX
    // );

    // Mélange du dégradé vertical et horizontal
    gl_FragColor = mix(
        vec4(0.0, 0.0, 1.0, 1.0),
        vec4(1.0, 0.0, 0.0, 1.0),
        clamped
    );
}