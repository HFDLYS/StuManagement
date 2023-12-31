// File operation function declaration
#pragma once
#ifndef STU_FILE_H
#define STU_FILE_H

#include "global.h"
#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <stdlib.h>


//Save student info to database
void saveStuInfo();

//Load student info from database
void loadStuInfo();















#endif