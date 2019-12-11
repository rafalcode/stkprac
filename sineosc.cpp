// sineosc.cpp STK tutorial program

/* now this guy relies on a raw file,
 * so pretty much it just wavifies it .. not so great!
 *
 * That's what I said in the beginning, but the commentary on this tutorial
 * verifies that the raw file is actually the table. */

#include "FileLoop.h"
#include "FileWvOut.h"
#include <cstdlib>

using namespace stk;

int main()
{
    // Set the global sample rate before creating class instances.
    Stk::setSampleRate( 44100.0 );

    // int numfreqs=3;
    // double freqa[numfreqs]={180., 440.0, 1400.};

    int nFrames = 100000;
    FileLoop input;
    FileWvOut output;

    try {
        // Load the sine wavetable file. It's 2048 bytes worth of shorts 2 byte samples, mono.
        input.openFile( "sinewave.raw", true );

        // Open a 16-bit, one-channel WAV formatted output file
        output.openFile( "outsine.wav", 1, FileWrite::FILE_WAV, Stk::STK_SINT16 );
    } catch ( StkError & ) {
        exit( 1 );
    }

    // for(int i=0;i<numfreqs;++i) {
    // input.setFrequency(freqa[i]);
    input.setFrequency(220.);

    // Option 1: Use StkFrames
    StkFrames frames( nFrames, 1 );
    try {
        output.tick( input.tick( frames ) );
    } catch ( StkError & ) {
        exit( 1 );
    }

    // Option 2: Single-sample computations
    /* for ( int i=0; i<nFrames; i++ ) {
       try {
       output.tick( input.tick() );
       } catch ( StkError & ) {
       exit( 1 );
       }
       }
       */

    return 0;
}
