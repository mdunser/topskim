/*************************************************************
 *
 * Class Usage:
 *
 * This class should only be used for upgrading and downgrading 
 * if a single operating point is used in an analysis. 
 *
 * bool isBTagged = b-tag flag for jet
 * int pdgIdPart = parton id
 * float Btag_SF = MC/data scale factor for b/c-tagging efficiency
 * float Btag_eff = b/c-tagging efficiency in data
 * float Bmistag_SF = MC/data scale factor for mistag efficiency
 * float Bmistag_eff = mistag efficiency in data
 *
 * Author: Michael Segala
 * Contact: michael.segala@gmail.com
 * Updated: Ulrich Heintz 12/23/2011
 *
 * v 1.1
 *
 * *************************************************************/


#ifndef BTagSFUtil_lite_h
#define BTagSFUtil_lite_h

#include <Riostream.h>
#include "TRandom3.h"
#include "TMath.h"


class BTagSFUtil{

 public:
    
  BTagSFUtil( int seed=0 );
  ~BTagSFUtil();
    
  void modifyBTagsWithSF( bool& isBTagged, float Btag_SF = 0.98, float Btag_eff = 1.0);


 private:
  
  bool applySF(bool& isBTagged, float Btag_SF = 0.98, float Btag_eff = 1.0);
  
  TRandom3* rand_;

};


BTagSFUtil::BTagSFUtil( int seed ) {

  rand_ = new TRandom3(seed);

}

BTagSFUtil::~BTagSFUtil() {

  delete rand_;

}


void BTagSFUtil::modifyBTagsWithSF(bool& isBTagged, float tag_SF, float tag_Eff){
  bool newBTag = isBTagged;
  newBTag = applySF(isBTagged, tag_SF, tag_Eff);
  isBTagged = newBTag;
}


bool BTagSFUtil::applySF(bool& isBTagged, float Btag_SF, float Btag_eff){
  
  bool newBTag = isBTagged;

  if (Btag_SF == 1) return newBTag; //no correction needed 

  //throw die
  float coin = rand_->Uniform(1.);    
  
  if(Btag_SF > 1){  // use this if SF>1

    if( !isBTagged ) {

      //fraction of jets that need to be upgraded
      float mistagPercent = (1.0 - Btag_SF) / (1.0 - (Btag_SF/Btag_eff) );

      //upgrade to tagged
      if( coin < mistagPercent ) {newBTag = true;}
    }

  }else{  // use this if SF<1
      
    //downgrade tagged to untagged
    if( isBTagged && coin > Btag_SF ) {newBTag = false;}

  }

  return newBTag;
}
#endif
