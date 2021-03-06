#ifndef LeptonSummary_h
#define LeptonSummary_h

#include "TLorentzVector.h"

class LeptonSummary {

 public:
 LeptonSummary(int _id,TLorentzVector &_p4) : 
  id(_id), charge(0), p4(_p4),
    idFlags(0),
    chiso(0.), nhiso(0.), phoiso(0.), rho(0.),isofull(0.), miniiso(0.), isofullR(0), d0(0.), d0err(0.), dz(0.), origIdx(-1), isMatched(false), isTauFeedDown(false), isTrigMatch(false), rawpt(0.) { }
  LeptonSummary(const LeptonSummary &l) {
    id=l.id;
    p4=l.p4;
    charge=l.charge;
    idFlags=l.idFlags;
    chiso=l.chiso;
    nhiso=l.nhiso;
    phoiso=l.phoiso;
    rho=l.rho;
    isofull=l.isofull;
    isofullR=l.isofullR;
    miniiso=l.miniiso;
    d0=l.d0;
    d0err=l.d0err;
    dz = l.dz;
    origIdx=l.origIdx;
    isMatched=l.isMatched;
    isTauFeedDown=l.isTauFeedDown;
    isTrigMatch=l.isTrigMatch;
    rawpt=l.rawpt;
  }

  int id;
  int charge;
  TLorentzVector p4;//we store calibrated pt
  unsigned int idFlags;
  float chiso, nhiso, phoiso;
  float rho;
  float isofull, miniiso;
  std::vector<float> isofullR;
  float d0, d0err, dz;
  int origIdx;
  bool isMatched,isTauFeedDown,isTrigMatch;
  float rawpt;
};

#endif
