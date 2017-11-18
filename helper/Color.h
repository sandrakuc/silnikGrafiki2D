#ifndef COLOR_H
#define COLOR_H

enum DefinedColor{RED = 1, ORANGE = 2, YELLOW = 3, GREEN = 4, CYAN = 5, BLUE = 6, VIOLET = 7, WHITE = 8};

class Color
{
    public:
        Color();
        virtual ~Color();
        static int createIntColor(int red, int green, int blue);

        /**
         * w postaci składowych RGB typu zmiennoprzecinkowego (0-1),
         */
        static int createIntColor(double red, double green, double blue);
        static int createIntColor(DefinedColor color);
    protected:

    private:
};

#endif // COLOR_H
