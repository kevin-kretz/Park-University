/*******************************
 * Unit 4, Chapter 13 - Programming Assignment
 * By Kevin Kretz | 04 July 2019
 * This program tracks an investments for 2 person based on the input of an interest rate.
 * The initial balance should be $2,000, and $4,000. The interest should be added to the balance and output in table format as shown in the supplied sample.
 ********************************/
 
import java.util.Scanner;

 public class KKUnit4Ch13 {
    public static void main(String[] args) {

        //Instantiate an investor1 object using a two parameter constructor passing the account number 1001 and the initial balance of $2,000
        KKUnit4Ch13Investor investor1 = new KKUnit4Ch13Investor(1001, 2000);

        //Instantiate an investor2 object using a two parameter constructor passing the account number 2001 and the initial balance of $4,000
        KKUnit4Ch13Investor investor2 = new KKUnit4Ch13Investor(2001, 4000);

        //Get input for interest rate (in the format .08 for 8%)
        Scanner scnr = new Scanner(System.in);
        System.out.print("Please enter the APR in the form .05 for 5%: ");
        float interestRate = scnr.nextFloat();
        scnr.close();

        KKUnit4Ch13Investor.setAnnualIntrestRate(investor1, interestRate);
        KKUnit4Ch13Investor.setAnnualIntrestRate(investor2, interestRate);

        //Output header as per sample showing interest rate
        System.out.printf("Monthly balances for one year with %.2f annual intreset rate:", interestRate);
        System.out.printf("\n\n%s %-10s %s %-10s %s", "Month", "Account #", "Balance", "Account #", "Balance");
        System.out.printf("\n%s %-10s %s %-10s %s", "-----", "---------", "-------", "---------", "-------");

        //Print the table using a for loop displaying the current month
        for (int i = 1; i < 16; i++) {

            //addInterest() to add the monthly interest for each iteration
            KKUnit4Ch13Investor.addInterest(investor1);
            KKUnit4Ch13Investor.addInterest(investor2);

            //Output results for 15 months.
            System.out.printf("\n%5d %9d  %7.2f %9d  %7.2f", i, KKUnit4Ch13Investor.getACCOUNT_NUMBER(investor1), KKUnit4Ch13Investor.getBalance(investor1), KKUnit4Ch13Investor.getACCOUNT_NUMBER(investor2), KKUnit4Ch13Investor.getBalance(investor2));
        }

        //Print the interest earned as shown in the sample for each investor utilizing a printf statement.
        System.out.printf("\n\nInvestor1 earned : %.2f interest in 15 months at %.2f%s", KKUnit4Ch13Investor.getInterestEarned(investor1), KKUnit4Ch13Investor.getInterestRate(investor1), "%");
        System.out.printf("\nInvestor2 earned : %.2f interest in 15 months at %.2f%s", KKUnit4Ch13Investor.getInterestEarned(investor2), KKUnit4Ch13Investor.getInterestRate(investor2), "%");
    }
}
