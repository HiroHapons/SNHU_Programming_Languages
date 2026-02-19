/*
 * Investment.h
 * Airgead Banking Investment Calculator
 */

#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <vector>

class Investment {
public:
    Investment();

    void setInitialInvestment(double amount);
    void setMonthlyDeposit(double amount);
    void setAnnualInterest(double rate);
    void setNumberOfYears(int years);

    double getInitialInvestment() const;
    double getMonthlyDeposit() const;
    double getAnnualInterest() const;
    int getNumberOfYears() const;

    void calculateBalanceWithoutDeposits(std::vector<double>& yearEndBalances,
        std::vector<double>& yearEndInterest) const;
    void calculateBalanceWithDeposits(std::vector<double>& yearEndBalances,
        std::vector<double>& yearEndInterest) const;

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;
};

#endif // INVESTMENT_H
