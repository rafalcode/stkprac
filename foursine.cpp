// foursine.cpp STK tutorial program

#include "SineWave.h"
#include "FileWvOut.h"
#include <cstdlib>

using namespace stk;

int main()
{
  const float sarate = 44100.0;
  // Set the global sample rate before creating class instances.
  Stk::setSampleRate(sarate);

  int i;
  FileWvOut output;
  SineWave inputs[4];

  // Set the sine wave frequencies.
  for ( i=0; i<4; i++ )
    inputs[i].setFrequency( 220.0 * (i+1) );

  try {
    output.openFile( "foursine.wav", 4, FileWrite::FILE_WAV, Stk::STK_SINT16 );
  } catch (StkError &) {
    exit( 1 );
  }

  // Write two seconds of four sines to the output file
  const int dursecs=2;
  float nsamps=sarate*dursecs;
  StkFrames frames(nsamps, 4);
  for ( i=0; i<4; i++ )
    inputs[i].tick(frames, i);

  output.tick(frames);

  // Now write the first sine to all four channels for two seconds
  for(i=0; i<nsamps; i++) {
    output.tick( inputs[0].tick() );
  }

  return 0;
}
