/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:57:36 by abillote          #+#    #+#             */
/*   Updated: 2025/11/25 15:13:12 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
    : m_capacity(0){

      };

Span::Span(unsigned int n) : m_capacity(n) { m_storage.reserve(m_capacity); };

Span::Span(const Span& other)
    : m_capacity(other.m_capacity),
      m_storage(other.m_storage){

      };

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        m_capacity = other.m_capacity;
        m_storage = other.m_storage;
    }
    return *this;
}

Span::~Span(){

};

void Span::addNumber(int number) {
    if (m_capacity == m_storage.size())
        throw StorageFullException();
    else
        m_storage.push_back(number);
}

int Span::shortestSpan() const {
    if (m_storage.size() <= 1) throw NotEnoughIntegersException();
    std::vector<int> sortedVec(m_storage);
    std::sort(sortedVec.begin(), sortedVec.end());

    int minDist = INT_MAX;
    std::vector<int>::iterator temp_pos = sortedVec.begin();
    std::vector<int>::iterator temp_next = sortedVec.begin() + 1;
    while (temp_next != sortedVec.end()) {
        int currentDiff = *temp_next - *temp_pos;
        if (currentDiff < minDist) minDist = currentDiff;
        if (minDist == 0) return minDist;
        temp_pos++;
        temp_next++;
    }
    return minDist;
}

int Span::longestSpan() const {
    if (m_storage.size() <= 1) throw NotEnoughIntegersException();

    std::vector<int> sortedVec(m_storage);
    std::sort(sortedVec.begin(), sortedVec.end());
    return sortedVec.back() - sortedVec.front();
}

unsigned int Span::getSize() { return m_storage.size(); }

const char* Span::StorageFullException::what() const throw() {
    return "This operation would overflow the storage capacity\n";
}

const char* Span::NotEnoughIntegersException::what() const throw() {
    return "There are less than 2 integers stored\n";
}
