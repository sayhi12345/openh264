#ifndef __FILEINPUTSTREAM_H__
#define __FILEINPUTSTREAM_H__

#include <fstream>
#include "InputStream.h"

class FileInputStream : public InputStream {
 public:
  bool Open(const char* fileName) {
    file_.open(fileName, std::ios_base::in | std::ios_base::binary);
    return file_.is_open();
  }
  int read(void* ptr, size_t len) {
    file_.read(static_cast<char*>(ptr), len);
    return file_.eof() ? -1 : file_.gcount();
  }
 private:
  std::ifstream file_;
};

#endif //__FILEINPUTSTREAM_H__
