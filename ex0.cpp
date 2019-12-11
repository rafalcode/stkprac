#include<Noise.h>
using namespace stk;

/*
 * Audio and control signals throughout STK use a floating-point data type, StkFloat, the exact precision of which can be controlled via a typedef statement in Stk.h. By default, an StkFloat is a double-precision floating-point value. Thus, the ToolKit can use any normalization scheme desired. The base instruments and algorithms are implemented with a general audio sample dynamic maximum of +/-1.0.

In general, the computation and/or passing of values is performed on a "single-sample" basis. For example, the stk::Noise class outputs random floating-point numbers in the range +/-1.0. The computation of such values occurs in the stk::Noise::tick() function. The following program will generate 20 random floating-point (StkFloat) values in the range -1.0 to +1.0:
*/

int main()
{
    StkFloat output;
    Noise noise;
    for ( unsigned int i=0; i<20; i++ ) {
        output = noise.tick();
        std::cout << "i = " << i << " : output = " << output << std::endl;
    }
    printf("Who wants sound anyway? Using STK's Noise to generate random floats from -1 to +1.\n"); 
    return 0;
}
