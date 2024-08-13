#include<stdio.h>

int calc_salary(float salary, float *yanglao, float *yiliao, float *shiye, float *gongshang, float *shengyu, float *gongjijin, float *geshui, float *salary_after_tax);
int main()
{
    float salary;
    float yanglao, yiliao, shiye, gongshang, shengyu, gongjijin, geshui, salary_after_tax, yuenashui;
    float result = 0;
    yanglao = 0.08;
    yiliao = 0.02+3;
    shiye = 0.005;
    gongshang = 0;
    shengyu = 0;
    gongjijin = 0.12;
   
    
    printf("input your salary: ");
    scanf(" %f", &salary);
    
   
    yuenashui = salary - salary*(yanglao + yiliao + shiye + gongshang + shengyu + gongjijin) - 5000;
    if(yuenashui>0 && yuenashui<3000)
    {
        geshui = yuenashui * 0.03;
    }
    else if(yuenashui>3000 && yuenashui<12000)
    {
        geshui = yuenashui * 0.1 - 210;
    }
    else if(yuenashui>12000 && yuenashui<25000)
    {
        geshui = yuenashui *0.2 -1410;
    }
    else if(yuenashui>25000 && yuenashui<35000)
    {
        geshui = yuenashui * 0.25 - 2660;
    }
    else if(yuenashui>35000 && yuenashui<55000)
    {
        geshui = yuenashui * 0.3 - 4410;
    }
    else if(yuenashui>55000 && yuenashui<80000)
    {
        geshui = yuenashui * 0.35 - 7160;
    }
    else
    {
        geshui = yuenashui * 0.45 - 15160;
    }



    result = calc_salary(salary, &yanglao, &yiliao, &shiye, &gongshang, &shengyu, &gongjijin, &geshui, &salary_after_tax);
    printf("net salary: %f\n", result);

    
    return 0;
}

int calc_salary(float salary, float *yanglao, float *yiliao, float *shiye, float *gongshang, float *shengyu, float *gongjijin, float *geshui, float *salary_after_tax)
{
    *salary_after_tax = salary - salary*(*yanglao+*yiliao+*shiye+*gongshang+*shengyu+*gongjijin) - *geshui;
    return *salary_after_tax;

}
