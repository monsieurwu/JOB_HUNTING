// Polymorphic
public class Main {
    public static void main(String[] args) {
        // 给一个有普通收入、工资收入和享受国务院特殊津贴的小伙伴算税:
        Income[] incomes = new Income[] {
            new Salary(7500),
            new ScriptFee(15000)
        };
        System.out.println(totalTax(incomes));
    }

    public static double totalTax(Income... incomes) {
        double total = 0;
        for (Income income: incomes) {
            total = total + income.getTax();
        }
        return total;
    }
}

interface Income {
    //protected double income;
    //public Income(double income) {  // 在抽象类中定义一个构造方法来初始化收入字段
    //    this.income = income;
    //}
    double getTax();
}



class Salary implements Income {
    private double income;
    public Salary(double income) {
        this.income = income;
    }

    @Override
    public double getTax() {
        if (income <= 5000) {
            return 0;
        }
        return (income - 5000) * 0.2;
    }
}

class ScriptFee implements  Income {
    private double income;
    public ScriptFee(double income) {
        this.income = income;
    }

    @Override
    public double getTax() {
        return 0;
    }
}