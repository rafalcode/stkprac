/* note ... tick() seems to be the hallmark of STK .. it's the value of sample at a certain point */
#include<Noise.h>
using namespace stk;
int main()

/* preallocation via StlFrames() so that vectorization can take place */
{
    StkFrames output(20, 1);   // initialize StkFrames to 20 frames and 1 channel (default: interleaved)
    Noise noise;
    noise.tick( output );
    for ( unsigned int i=0; i<output.size(); i++ ) {
        std::cout << "i = " << i << " : output = " << output[i] << std::endl;
    }
    return 0;
}
