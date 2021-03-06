/*
 * Blanking.h
 *
 *  Created on: 18.08.2013
 *      Author: niklausd
 */

#ifndef BLANKING_H_
#define BLANKING_H_

class Timer;

/*
 *
 */
class Blanking
{
public:
  Blanking(unsigned int blankingMillis = s_defaultBlankingMillis);
  virtual ~Blanking();

  bool isSignalBlanked();
  void toggle();

private:
  Timer* m_timer;
  bool m_signalIsBlanked;

  static const unsigned int s_defaultBlankingMillis;

private: // forbidden default functions
  Blanking& operator = (const Blanking& );  // assignment operator
  Blanking(const Blanking& src);            // copy constructor
};

#endif /* BLANKING_H_ */
