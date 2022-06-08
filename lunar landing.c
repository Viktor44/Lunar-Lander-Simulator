#include <stdio.h>

int main() {
    double m, T, H, g, vsoft, dt;
    scanf("%lf", &m);
    scanf("%lf", &T);
    scanf("%lf", &H);
    scanf("%lf", &g);
    scanf("%lf", &vsoft);
    scanf("%lf", &dt);
    printf("m=%.3lf\n", m);
    printf("T=%.3lf\n", T);
    printf("H=%.3lf\n", H);
    printf("g=%.3lf\n", g);
    printf("vsoft=%.3lf\n", vsoft);
    printf("dt=%.3lf\n", dt);
    double A = T / m;
    double df = ((A - g) * H) / A;
    double de = H - df;
    printf("de=%.3lf\n", de);
    double s = 0;
    double Hnew = H;
    double Tnew = 0;
    double vnew = 0;
    double a = -g;
    int x = 0;
    int y = 0;
    int max = 0;
    while (Hnew > 0) {
        if (Hnew <= de && vnew < vsoft) {
            s = 1;
            a = A - g;
            x++;
            y++;
            if (y > max)
                max = y;
        }
        else {
            s = 0;
            a = -g;
            y = 0;
        }
        printf("s=%.0lf h=%008.3lf t=%.3lf v=%.3lf\n", s, Hnew, Tnew, vnew);
        Hnew = Hnew + (vnew * dt) + ((a * dt * dt) / 2);
        vnew = vnew + (a * dt);
        Tnew = Tnew + dt;

    }
    printf("---Landed---\n");
    printf("h    =%008.3lf\n", Hnew);
    printf("t    =%8.3lf\n", Tnew);
    printf("v    =%8.3lf\n", vnew);
    printf("total=%4d\n", x);
    printf("max  =%4d", max);


    return 0;
}