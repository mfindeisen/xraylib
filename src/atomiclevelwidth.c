/*
Copyright (c) 2011, Tom Schoonjans
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
    * The names of the contributors may not be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY Tom Schoonjans ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL Bruno Golosio, Antonio Brunetti, Manuel Sanchez del Rio, Tom Schoonjans and Teemu Ikonen BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "xrayglob.h"
#include "xraylib.h"

/*////////////////////////////////////////////////////////////////////
//                                                                  //
//                    Atomic level width (keV)                      //
//                                                                  //
//          Z : atomic number                                       //
//          shell :                                                 //
//            K_SHELL  0                                            //
//            L1_SHELL 1                                            //
//            L2_SHELL 2                                            //
//            L3_SHELL 3                                            //
//            M1_SHELL 4                                            //
//            M2_SHELL 5                                            //
//            M3_SHELL 6                                            //
//            M4_SHELL 7                                            //
//            M5_SHELL 8                                            //
//             .......                                              //
//                                                                  //
/////////////////////////////////////////////////////////////////// */

double AtomicLevelWidth(int Z, int shell)
{
  double atomic_level_width;

  if (Z<1 || Z>ZMAX) {
    ErrorExit("Z out of range in function AtomicLevelWidth");
    return 0;
  }
  if (shell<0 || shell>=SHELLNUM) {
    ErrorExit("Shell not available in function AtomicLevelWidth");
    return 0;
  }
  atomic_level_width = AtomicLevelWidth_arr[Z][shell];

  if (atomic_level_width < 0.) {
    ErrorExit("Shell not available in function AtomicLevelWidth");
    return 0;
  }

  return atomic_level_width;
}

