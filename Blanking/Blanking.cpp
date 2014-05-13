/*
 * Blanking.cpp
 *
 *  Created on: 18.08.2013
 *      Author: niklausd
 */

#include "Timer.h"
#include "Blanking.h"

// ========================================================

class BlankTimerAdapter : public TimerAdapter
{
public:
  BlankTimerAdapter(Blanking* blanking)
  : m_blanking(blanking)
  { }

  void timeExpired()
  {
    if (0 != m_blanking)
    {
      m_blanking->toggle();
    }
  }

private:
  Blanking* m_blanking;
};

// ========================================================

const unsigned int Blanking::s_defaultBlankingMillis = 500;

Blanking::Blanking(unsigned int blankingMillis)
: m_timer(new Timer(new BlankTimerAdapter(this), Timer::IS_RECURRING, blankingMillis))
, m_signalIsBlanked(false)
{ }

Blanking::~Blanking()
{
  delete m_timer->adapter();
  delete m_timer; m_timer = 0;
}

void Blanking::toggle()
{
  m_signalIsBlanked = !m_signalIsBlanked;
}

bool Blanking::isSignalBlanked()
{
  return m_signalIsBlanked;
}
