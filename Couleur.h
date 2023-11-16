#pragma once
#include <assert.h>

class Couleur {
private:
    unsigned char _r; // Color red value
    unsigned char _g; // Color green value
    unsigned char _b; // Color blue value
    unsigned char _a; // Color alpha value

public:
    // Constructeurs
    constexpr Couleur(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : _r(r), _g(g), _b(b), _a(a) {}
    constexpr Couleur() : _r(255), _g(255), _b(255), _a(255)
    {}
    
    constexpr Couleur(int r, int g, int b, int a) : _r(0), _g(0), _b(0), _a(0) {
        if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0) || (a > 255 || a < 0))
        {
            _r = 255;
            _g = 255;
            _b = 255;
            _a = 255;
        }

        _r = r;
        _g = g;
        _b = b;
        _a = a;
    }

    // Accesseurs
    unsigned char GetRed() { return _r; }
    unsigned char GetGreen() { return _g; }
    unsigned char GetBlue() { return _b; }
    unsigned char GetAlpha() { return _a; }

    // Mutateurs
    void SetRed(unsigned char r) { _r = r; }
    void SetGreen(unsigned char g) { _g = g; }
    void SetBlue(unsigned char b) { _b = b; }
    void SetAlpha(unsigned char a) { _a = a; }
};

// Définissez des "macros" pour les couleurs
#define GRISCLAIR Couleur(200, 200, 200, 255)   // Light Gray
#define GRIS Couleur(130, 130, 130, 255)        // Gray
#define JAUNE Couleur(253, 249, 0, 255)         // Yellow
#define OR Couleur(255, 203, 0, 255)           // Gold
#define ROSE Couleur(255, 109, 194, 255)       // Pink
#define ROUGE Couleur(230, 41, 55, 255)        // Red
#define VERT Couleur(0, 228, 48, 255)          // Green
#define VERTFONCE Couleur(0, 117, 44, 255)     // Dark Green
#define BLEUCIEL Couleur(102, 191, 255, 255)   // Sky Blue
#define BLEU Couleur(0, 121, 241, 255)         // Blue
#define BLEUFONCE Couleur(0, 82, 172, 255)     // Dark Blue
#define VIOLETFONCE Couleur(112, 31, 126, 255) // Dark Purple
#define MARRON Couleur(127, 106, 79, 255)      // Brown
#define MARRONFONCE Couleur(76, 63, 47, 255)   // Dark Brown

#define BLANC Couleur(255, 255, 255, 255)     // White
#define NOIR Couleur(0, 0, 0, 255)           // Black
#define VIDE Couleur(0, 0, 0, 0)             // Blank (Transparent)
