/*
 * Investment.cpp
 * Airgead Banking Investment Calculator
 */

#include "Investment.h"

Investment::Investment() {
    m_initialInvestment = 0.0;
    m_monthlyDeposit = 0.0;
    m_annualInterest = 0.0;
    m_numberOfYears = 0;
}

void Investment::setInitialInvestment(double amount) {
    m_initialInvestment = amount;
}

void Investment::setMonthlyDeposit(double amount) {
    m_monthlyDeposit = amount;
}

void Investment::setAnnualInterest(double rate) {
    m_annualInterest = rate;
}

void Investment::setNumberOfYears(int years) {
    m_numberOfYears = years;
}

double Investment::getInitialInvestment() const {
    return m_initialInvestment;
}

double Investment::getMonthlyDeposit() const {
    return m_monthlyDeposit;
}

double Investment::getAnnualInterest() const {
    return m_annualInterest;
}

int Investment::getNumberOfYears() const {
    return m_numberOfYears;
}

void Investment::calculateBalanceWithoutDeposits(std::vector<double>& yearEndBalances,
    std::vector<double>& yearEndInterest) const {
    yearEndBalances.clear();
    yearEndInterest.clear();

    double openingAmount = m_initialInvestment;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double totalInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            double monthlyInterest = openingAmount * ((m_annualInterest / 100.0) / 12.0);
            totalInterest += monthlyInterest;
            openingAmount += monthlyInterest;
        }

        yearEndBalances.push_back(openingAmount);
        yearEndInterest.push_back(totalInterest);
    }
}

void Investment::calculateBalanceWithDeposits(std::vector<double>& yearEndBalances,
    std::vector<double>& yearEndInterest) const {
    yearEndBalances.clear();
    yearEndInterest.clear();

    double openingAmount = m_initialInvestment;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double totalInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            openingAmount += m_monthlyDeposit;
            double monthlyInterest = openingAmount * ((m_annualInterest / 100.0) / 12.0);
            totalInterest += monthlyInterest;
            openingAmount += monthlyInterest;
        }

        yearEndBalances.push_back(openingAmount);
        yearEndInterest.push_back(totalInterest);
    }
}