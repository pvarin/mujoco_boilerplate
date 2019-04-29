/*  Copyright © 2018, Roboti LLC

    This file is licensed under the MuJoCo Resource License (the "License").
    You may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        https://www.roboti.us/resourcelicense.txt
*/

// System dependencies
#include <stdio.h>
#include <string.h>

// External dependencies
#include "mujoco.h"

// Local dependencies
#include "mj_visualize.h"


// main function
int main(int argc, const char** argv)
{
    // check command-line arguments
    if( argc!=2 )
    {
        printf(" USAGE:  load_model modelfile\n");
        return 0;
    }

    // activate software
    mj_activate("../mjkey.txt");

    // MuJoCo data structures
    mjModel* m = NULL;                  // MuJoCo model
    mjData* d = NULL;                   // MuJoCo data

    // load and compile model
    char error[1000] = "Could not load binary model";
    if( strlen(argv[1])>4 && !strcmp(argv[1]+strlen(argv[1])-4, ".mjb") )
        m = mj_loadModel(argv[1], 0);
    else
        m = mj_loadXML(argv[1], 0, error, 1000);
    if( !m )
        mju_error_s("Load model error: %s", error);

    // make data
    d = mj_makeData(m);

    simulate_and_visualize(m, d);


    // free MuJoCo model and data, deactivate
    mj_deleteData(d);
    mj_deleteModel(m);
    mj_deactivate();

    return 1;
}
