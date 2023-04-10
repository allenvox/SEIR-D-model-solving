#include <iostream>

#define MU 0.0188     // коэф. смертности от COVID-19
#define BETA 0.999    // скорость выздоровления заражённых случаев
#define RO 0.952      // скорость восстановления выявленных случаев
#define ALPHA_E 0.999 // коэф. заражения между бессимптомно-инфицированным и восприимчивым населением
#define ALPHA_I 0.999 // коэф. заражения между инфицированным и восприимчивым населением (социальные факторы)
#define K 0.042       // частота появления симптомов в открытых случаях
#define C_ISOL 0      // коэф. влияния индекса самоизоляции на заражаемость (0 - не влияет)
#define E0 99         // начальное количество бессимптомно инфицированных
#define R0 24         // начальное количество вылеченных
#define GAMMA 0       // скорость повторного заражения, раз (0 - устойчивый иммунитет)
#define TETTA 2       // латетный/инкубационный период (запаздывание заразности), дни
#define C             //

double dS_dt(double S, double E, double I, double R, double D)
{
    double N = S + E + I + R + D;
    return -C * (ALPHA_I * S * I + ALPHA_E * S * E) / N + GAMMA * R;
}

double dE_dt(double S, double E, double I, double R, double D)
{
    double N = S + E + I + R + D;
    return C * (ALPHA_I * S * I + ALPHA_E * S * E) / N - (K + RO) * E;
}

double dI_dt(double S, double E, double I, double R, double D)
{
    return K * E - BETA * I - MU * I;
}

double dR_dt(double S, double E, double I, double R, double D)
{
    return BETA * I + RO * E - GAMMA * R;
}

double dD_dt(double S, double E, double I, double R, double D)
{
    return MU * I;
}

int main()
{
    double a = 0, b = 90, eps = 1e-2;

    std::cout.precision(5);
    std::cout.setf(std::ios::fixed);

    return 0;
}