#include <iostream>
#include <string>
using namespace std;

#define NEG '-'
#define DOT '.'
#define ZERO '0'
#define NO_DOT -1

enum sign {
    POS_POS,
    POS_NEG,
    NEG_POS,
    NEG_NEG,
};

sign getSignResult(char char_sign_1, char char_sign_2);
void initIntegralPart(string & str_1, string & str_2);
void initDecimalPart(string & str_1, string & str_2);
string bigNumberAddInteger(string str_1, string str_2);
string bigNumberAddOneDecimal(string decimal_str, string integer_str, int dot_index);
string bigNumberAdd(string str_1, string str_2);
string bigNumberSub(string str_1, string str_2);

int main(int argc, char *args []) {
    string str_1 = args[1];
    string str_2 = args[2];
    char char_sign_1 = str_1[0];
    char char_sign_2 = str_2[0];
    int len_str_1 = str_1.length();
    int len_str_2 = str_2.length();
    sign sign_result = getSignResult(char_sign_1, char_sign_2);
    string result;
    switch (sign_result) {
        case POS_POS :
            result = bigNumberAdd(str_1, str_2);
            break;
        case POS_NEG :
            result = bigNumberSub(str_1, str_2.substr(1, len_str_2-1));
            break;
        case NEG_POS :
            result = bigNumberSub(str_2, str_1.substr(1, len_str_1-1));
            break;
        default:
            // NEG_NEG
            result = '-' + bigNumberAdd(str_1.substr(1, len_str_1-1), str_2.substr(1, len_str_2-1));
    }
    cout << "result: " << result << endl;
    return 0;
}

sign getSignResult(char char_sign_1, char char_sign_2) {
    if ((char_sign_1 != NEG) && (char_sign_2 != NEG)) {
        return POS_POS;
    } else if ((char_sign_1 != NEG) && (char_sign_2 == NEG)) {
        return POS_NEG;
    } else if ((char_sign_1 == NEG) and (char_sign_2 != NEG)) {
        return NEG_POS;
    }
    else {
        // } else if ((char_sign_1 == NEG) and (char_sign_2 == NEG)) {
        return NEG_NEG;
    }
}

void initIntegralPart(string & str_1, string & str_2) {
    if (str_1.length() > str_2.length()) {
        int diff_length = str_1.length() - str_2.length();
        str_2.insert(0, diff_length, ZERO);
    } else if (str_1.length() < str_2.length()) {
        int diff_length = str_2.length() - str_1.length();
        str_1.insert(0, diff_length, ZERO);
    }
    str_1 = ZERO + str_1;
    str_2 = ZERO + str_2;
}

void initDecimalPart(string & str_1, string & str_2) {
    if (str_1.length() > str_2.length()) {
        int diff_length = str_1.length() - str_2.length();
        str_2.append(diff_length, ZERO);
    } else if (str_1.length() < str_2.length()) {
        int diff_length = str_2.length() - str_1.length();
        str_1.append(diff_length, ZERO);
    }
}


string bigNumberAddInteger(string str_1, string str_2) {
    for (int i = str_1.length() - 1; i >= 0; i--) {
        int num_1 = str_1[i] - ZERO;
        int num_2 = str_2[i] - ZERO;
        if (num_1 + num_2 > 9) {
            str_1[i - 1] = str_1[i - 1] - ZERO + 1 + ZERO;
            str_1[i] = (num_1 + num_2) - 10 + ZERO;
        } else {
            str_1[i] = (num_1 + num_2) + ZERO;
        }
    }
    if (str_1[0] == ZERO) {
        str_1.erase(0, 1);
    }
    return str_1;
}

string bigNumberAddOneDecimal(string decimal_str, string integer_str, int dot_index) {
    int decimal_start = dot_index + 1;
    string decimal_str_integer = decimal_str.substr(0, dot_index);
    string decimal_str_decimal = decimal_str.substr(decimal_start, decimal_str.length()-decimal_start);
    initIntegralPart(integer_str, decimal_str_integer);
    string result = bigNumberAddInteger(integer_str, decimal_str_integer);
    result = result + DOT + decimal_str_decimal;
    return result;
}

string bigNumberAdd(string str_1, string str_2) {
    int dot_index_1 = str_1.find(DOT, 0);
    int dot_index_2 = str_2.find(DOT, 0);
    string result;
    if ((dot_index_1 == NO_DOT) && (dot_index_2 == NO_DOT)) {
        // If both of str_1 and str_2 are integer
        initIntegralPart(str_1, str_2);
        result = bigNumberAddInteger(str_1, str_2);
    } else if (dot_index_1 == NO_DOT) {
        // If str_1 is the only integer
        result = bigNumberAddOneDecimal(str_2, str_1, dot_index_2);
    } else if (dot_index_2 == NO_DOT) {
        // If str_2 is the only integer
        result = bigNumberAddOneDecimal(str_1, str_2, dot_index_1);
    } else {
        // If both of str_1 and str_2 are decimal
        int decimal_start_1 = dot_index_1 + 1;
        int decimal_start_2 = dot_index_2 + 1;
        string str_1_integer = str_1.substr(0, dot_index_1);
        string str_2_integer = str_2.substr(0, dot_index_2);
        string str_1_decimal = str_1.substr(decimal_start_1, str_1.length()-decimal_start_1);
        string str_2_decimal = str_2.substr(decimal_start_2, str_2.length()-decimal_start_2);
        initIntegralPart(str_1_integer, str_2_integer);
        initDecimalPart(str_1_decimal, str_2_decimal);
        result = bigNumberAddInteger(
                str_1_integer + str_1_decimal,
                str_2_integer + str_2_decimal);
        if (result.length() == (str_1_integer.length() + str_1_decimal.length())) {
            result.insert(str_1_integer.length(), 1, DOT);
        } else {
            result.insert(str_1_integer.length()-1, 1, DOT);
        }
    }
    return result;
}

string bigNumberSub(string str_1, string str_2) {
    return str_1;
}
