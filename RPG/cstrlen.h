#pragma once

#include<cstdlib>




//Strings longer than TEXT_COLUMNS must be truncated.
#define cstrlen(x) strnlen(x, TEXT_COLUMNS)