#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>


/**
 * @brief Splits a string based on a substring, returning a vector of all substrings.
 * NOTE: Substrings may include whitespace that was included in the inputString.
 * 
 * @param inputString The string to be split up.
 * @param delimiter The string to divide the inputString
 * @return std::vector<std::string> The set of substrings from the inputString.
 */
std::vector<std::string> split(std::string inputString, std::string delimiter);

#endif