#ifndef _STRATEGYPATTERN_HPP_
#define _STRATEGYPATTERN_HPP_

class FactoryPattern;

class StrategyPattern {
  public: 
    StrategyPattern(){};
    virtual void filtering_strategy(FactoryPattern* pointer_to_factory) = 0;
};
#endif


