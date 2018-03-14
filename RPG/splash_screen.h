#pragma once

#include "stdafx.h"



/**
*   Packages a splash screen filename and the time to display it for.
*/
struct Splash_screen
{
    string path; // The filename and path.
    int time; // The time in millisecond to show the splash screen for.
};