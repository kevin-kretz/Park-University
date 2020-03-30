/*******************************
 * Unit 4, Chapter 13 - Programming Assignment
 * By Kevin Kretz | 04 July 2019
 * This program tracks an investments for 2 person based on the input of an interest rate.
 * The initial balance should be $2,000, and $4,000. The interest should be added to the balance and output in table format as shown in the supplied sample.
 ********************************/

import java.util.Scanner;

public class KKUnit4Ch13Investor {
  //All variables should be declared private.
  //Declare a class variable called interestRate
  private float interestRate;
  //Declare a constant called ACCOUNT_NUMBER
  private final int ACCOUNT_NUMBER;
  //Declare an instance variable called balance
  private float balance;

  private float initialBalance;

  //Provide a two parameter constructor to initialize the constant account number and balance
  public KKUnit4Ch13Investor(int accountNumber, float balance) {
    this.ACCOUNT_NUMBER = accountNumber;
    this.balance = balance;
    this.initialBalance = balance;
  }

  //Provide a class method that will be used to set the annual interest rate
  public static void setAnnualIntrestRate(KKUnit4Ch13Investor investor, float interestRate) {
    investor.interestRate = interestRate;
  }

  //Provide an addInterest() method to update the balance based on the interestRate entered in the driver.
  public static void addInterest(KKUnit4Ch13Investor investor) {
    //Add the interest using (balance * interestRate / 12)
    investor.balance += investor.balance * investor.interestRate / 12;
  }

  public static float getBalance(KKUnit4Ch13Investor investor) {
    return investor.balance;
  }

  public static float getInterestEarned(KKUnit4Ch13Investor investor) {
    float interestEarned = investor.balance - investor.initialBalance;
    return interestEarned;
  }

  public static float getInterestRate(KKUnit4Ch13Investor investor){
    return investor.interestRate * 100;
  }

  public static int getACCOUNT_NUMBER(KKUnit4Ch13Investor investor){
    return investor.ACCOUNT_NUMBER;
  }
}
