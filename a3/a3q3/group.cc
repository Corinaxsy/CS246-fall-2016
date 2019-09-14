#include "Group.h"
#include <iostream>
#include <string>
using namespace std;


Group::Group(const string &name):
 grpname{name},
 grpemail{nullptr},
 grpnode{nullptr}
{}

Group::~Group() {
delete grpnode;
delete grpemail;
}

string Group::name() const{
 return grpname;
}

void tab(int n) {
 for (int i = 0;i<n;++i) {
  cout << "\t";
 }
}
static int ntab = 0;
string Group::emails() const{
 tab(ntab);
 cout << grpname << "\n";
 tab(ntab);
 if (grpemail == nullptr) {
  cout << "[]\n";
 } else {
  EmailNode *tmp = grpemail;
  cout << "[" << tmp->address();
  tmp=tmp->next;
  while (tmp) {
   cout << ", " << tmp->address();
   tmp = tmp->next;
  }
  cout << "]\n";
 } 
 if (grpnode) {
  GroupNode *tmp = grpnode;
  ++ntab;
  while(tmp) {
   tmp->g->emails();
   tmp= tmp->next;
  }
 }
 return "";
}

void Group::addGroup(Group * subg) {
 GroupNode *gn = new GroupNode{subg};
 if (grpnode == nullptr) {
  grpnode = gn;
 } else if (gn->g->name() <= grpnode->g->name()) {
  gn->next = grpnode;
  grpnode = gn;
 } else  {
  grpnode->addGroup(gn);
 }
}

void Group::addAddress(const string & emailname){
 EmailNode *em = new EmailNode{emailname};
 if (grpemail == nullptr) {
  grpemail = em;
 } else if (emailname <= grpemail->address()) {
  em->next = grpemail;
  grpemail = em;
 } else {
  grpemail->addAddress(emailname);
 }
}

bool Group::removeGroup(const string & groupname) {
 if (grpnode == nullptr) {
  return false;
 } else if (grpnode->g->name() == groupname) {
   grpnode = grpnode->next;
   return true;
 }  else if (grpnode->findGroup(groupname) == nullptr) {
  return false;
 } else {
 return grpnode->removeGroup(groupname);
 }
}

bool Group::removeAddress(const string & emailname) {
 if (grpemail == nullptr) {
  return (grpnode->removeAddress(emailname));
 } else if (grpemail->address() == emailname) {
   grpemail = grpemail->next;
   return true;
 } else if (grpemail->findAddress(emailname)) {
  grpemail->removeAddress(emailname);
  return true;
 } else {
  return grpnode->removeAddress(emailname);
 }
}

Group::EmailNode::EmailNode(const string & emailname):
 emlname{emailname},
 next{nullptr}
{}

Group::EmailNode::~EmailNode() {
 delete next;
}

void Group::EmailNode::addAddress(const string & emailname) {
 EmailNode *em = new EmailNode{emailname};
 EmailNode *tmp = this;
  while (tmp->next) {
   if (emailname <= tmp->next->address()) {
    em->next = tmp->next;
    tmp->next = em;
    break;
   }
   tmp = tmp->next;
  }
  if (tmp->next == nullptr) {
   tmp->next = em;
  } 
}

bool Group::EmailNode::removeAddress(const string &emailname) {
   EmailNode * tmp = this;
   while (tmp->next) {
    if (tmp->next->address() == emailname) {
      tmp->next = tmp->next->next;
      return true;
    }
    tmp=tmp->next;
   }
  return false;
}

string Group::EmailNode::address() const {
 return emlname;
}

Group::EmailNode * Group::EmailNode::findAddress(const string &emailname) {
 EmailNode *tmp = this;
 while (tmp) {
  if (emailname == tmp->address()) {
   return tmp;
  }
  tmp = tmp->next;
 }
 return tmp;
}

Group::GroupNode::GroupNode(Group *group):
 g{group},
 next{nullptr}
{}

Group::GroupNode::~GroupNode() {
 delete g;
 delete next;
}

Group * Group::GroupNode::group() const {
 return g;
}

void Group::GroupNode::addGroup(GroupNode * grpnd) {
  GroupNode *tmp = this;
  while (tmp->next) {
   if (grpnd->g->name() <= tmp->g->name()) {
    grpnd->next = tmp->next;
    tmp->next = grpnd;
    break;
   }
   tmp = tmp->next;
  }
  if (tmp->next == nullptr) {
   tmp->next = grpnd;
  }
}

bool Group::GroupNode::removeGroup(GroupNode * grpnd) {
  if (this == nullptr) {
   return false;
  } else {
   if (this->g->grpnode->removeGroup(grpnd)) {
     return true;
   }
   GroupNode *tmp = this;
   while (tmp->next) {
    if (tmp->next == grpnd) {
     tmp->next = tmp->next->next;
     return true;
    } else if (tmp->next->g->grpnode->removeGroup(grpnd)) {
     return true;
    }
    tmp=tmp->next;
   }
  }
 return false;
}

bool Group::GroupNode::removeAddress(const string & emailname) {
   GroupNode *tmp = this;
   while (tmp) {
    if (tmp->g->removeAddress(emailname)) {
     return true;
    }
    tmp=tmp->next;
   }
   return false;
}

bool Group::GroupNode::removeGroup(const string & groupname) {
   if (this->g->removeGroup(groupname)) {
     return true;
   }
   GroupNode *tmp = this;
   while (tmp->next) {
    if (tmp->next->g->name() == groupname) {
     tmp->next = tmp->next->next;
     return true;
    } else if (tmp->next->g->removeGroup(groupname)) {
     return true;
    }
    tmp=tmp->next;
   }
 return false;
}

Group::GroupNode* Group::GroupNode::findGroup(const string & groupname) {
 GroupNode* tmp = this;
 while (tmp) {
  if (groupname == tmp->g->name()) {
    return tmp; 
  } else if (tmp->g->grpnode->findGroup(groupname)) {
    return tmp->g->grpnode->findGroup(groupname);
  }
  tmp=tmp->next;
 }
 return nullptr;
}

Group::GroupNode* Group::GroupNode::findAddress(const string & emailname) {
  GroupNode* tmp = this;
  while (tmp) {
   if (tmp->g->findAddress(emailname)) {
     return tmp;
   } else if (tmp->g->grpnode->findAddress(emailname)) {
     return tmp->g->grpnode->findAddress(emailname);
   }
   tmp=tmp->next;
  }
  return nullptr;
}

Group::GroupNode* Group::findGroup(const string &groupname){
 if (grpnode == nullptr) { return nullptr;}
 return grpnode->findGroup(groupname);
}

Group::EmailNode* Group::findAddress(const string &emailname) {
  EmailNode* curgp = grpemail->findAddress(emailname);
  if (curgp != nullptr) {
   return curgp;
  } else if (grpnode->findAddress(emailname)) {
   return (grpnode->findAddress(emailname))->g->grpemail->findAddress(emailname);
  } else {
  return nullptr;
 }
}

ostream &operator<<(ostream & out, Group & gp) {
 ntab = 0;
 cout << gp.emails();
 return out;
}

ostream &operator<<(ostream & out, Group::EmailNode & emailnode) { 
 cout << emailnode.address();
 return out;
} 

ostream &operator<<(ostream & out, Group::GroupNode & groupnode) {
 cout << *(groupnode.group());
 return out;
}

