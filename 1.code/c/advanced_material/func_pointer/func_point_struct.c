#include <stdio.h>

/* ¶šÒåÒ»žöº¯ÊýÖžÕëÀàÐÍ£¬ÓÃÓÚÖŽÐÐÊýÑ§ÔËËã */
typedef int(*calc_func_t)(int, int);

/* ¶šÒåÒ»žö°üº¬º¯ÊýÖžÕëºÍÁœžö²Ù×÷ÊýµÄŒÆËãÆ÷œá¹¹Ìå */
typedef struct {
    calc_func_t calc; /* º¯ÊýÖžÕë³ÉÔ± */
    int operand1;     /* ²Ù×÷Êý1 */
    int operand2;     /* ²Ù×÷Êý2 */
} calculator_t;

// ŒÆËã²¢·µ»Ø2žöÊýµÄºÍ
int add(int a, int b)
{
    return a + b;
}
// ŒÆËã²¢·µ»Ø2žöÊýµÄ²î
int subtract(int a, int b)
{
    return a - b;
}

/* ÖŽÐÐÊýÑ§ÔËËãµÄº¯Êý */
int perform_calc(calculator_t* calculator)
{
    int result;
    // ÅÐ¶ÏÊÇ·ñÊÇ¿ÕÖžÕë
    if (calculator && calculator->calc) {
        // Èç¹ûº¯ÊýÖžÕëÓÐÐ§£¬Ôòµ÷ÓÃÏàÓŠº¯Êý
        result = calculator->calc(calculator->operand1, calculator->operand2);
    }
    return result;
}

int main(void)
{
    // ¶šÒå2žöŒÆËãÆ÷
    calculator_t calculator1, calculator2;

    /* ÅäÖÃŒÓ·šŒÆËãÆ÷ */
    calculator1.calc = add;
    calculator1.operand1 = 5;
    calculator1.operand2 = 3;
    printf("5 + 3 = %d\n", perform_calc(&calculator1));

    /* ÅäÖÃŒõ·šŒÆËãÆ÷ */
    calculator2.calc = subtract;
    calculator2.operand1 = 5;
    calculator2.operand2 = 3;
    printf("5 - 3 = %d\n", perform_calc(&calculator2));
    
    return 0;
}