/*
 * StringUtil.h
 *
 *  Created on: Jul 17, 2013
 *      Author: drom
 *
 *  See:  http://stackoverflow.com/questions/236129/splitting-a-string-in-c
 */

#ifndef STRINGUTIL_H_
#define STRINGUTIL_H_

#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::stringstream;

class StringUtil {

private:

  StringUtil();

public:

  static vector<string>& split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) {
      elems.push_back(item);
    }

    return elems;
  }

  static vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
  }

};

#endif /* STRINGUTIL_H_ */
