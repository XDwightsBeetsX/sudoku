#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

/**
 * @brief Splits a string based on a substring, returning a vector of all substrings.
 * NOTE: Substrings may include whitespace that was included in the inputString.
 * 
 * @param inputString 
 * @param delimiter 
 * @return std::vector<std::string> 
 */
std::vector<std::string> split(std::string inputString, std::string delimiter);

#endif