#ifndef __CATALOGUE_H__
#define __CATALOGUE_H__
#include <map>
#include <string>

#include "BookVisitor.h"
#include "book.h"
#include "comic.h"
#include "text.h"

class CatalogueVisitor: public BookVisitor {
  std::map<std::string, int> theCatalogue;

 public:
  std::map<std::string, int> getResult() const;

  virtual void visit(Book &b);
  virtual void visit(Comic &cb);
  virtual void visit(Text &csb);
};

#endif
