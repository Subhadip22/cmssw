
// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/Utilities/interface/RunningAverage.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "RecoParticleFlow/PFClusterProducer/interface/PFRecHitCreatorBase.h"
#include "RecoParticleFlow/PFClusterProducer/interface/PFRecHitNavigatorBase.h"

//
// class declaration
//

class PFRecHitProducer : public edm::EDProducer {
   public:
      explicit PFRecHitProducer(const edm::ParameterSet& iConfig);
      ~PFRecHitProducer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

   private:
      const bool _useHitMap;
      virtual void produce(edm::Event&, const edm::EventSetup&) override;
      std::vector<std::unique_ptr<PFRecHitCreatorBase> > creators_;
      std::unique_ptr<PFRecHitNavigatorBase> navigator_;
      edm::RunningAverage outputSizeGuess_; ///< Use this to try and accurately reserve space for the output
      edm::RunningAverage cleanedOutputSizeGuess_; ///< Use this to try and accurately reserve space for the output
};

#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(PFRecHitProducer);
