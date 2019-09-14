#include "subject.h"
#include "observer.h"
#include "subscriptions.h"

void Subject::attach(Observer *o) {observers.emplace_back(o); }

void Subject::notifyObservers(SubscriptionType t) {
 for (auto &ob:observers) {
   if (ob->subType() == SubscriptionType::All) {
    ob->notify(*this);
    break;
   } else {
    ob->notify(*this);
   }
 }
}

Subject::~Subject() {}
