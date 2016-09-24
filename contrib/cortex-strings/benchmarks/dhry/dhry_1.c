begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *************************************************************************  *  *                   "DHRYSTONE" Benchmark Program  *                   -----------------------------  *  *  Version:    C, Version 2.1  *  *  File:       dhry_1.c (part 2 of 3)  *  *  Date:       May 25, 1988  *  *  Author:     Reinhold P. Weicker  *  *************************************************************************  */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"dhry.h"
end_include

begin_comment
comment|/*COMPILER COMPILER COMPILER COMPILER COMPILER COMPILER COMPILER*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COW
end_ifdef

begin_define
define|#
directive|define
name|compiler
value|"Watcom C/C++ 10.5 Win386"
end_define

begin_define
define|#
directive|define
name|options
value|"  -otexan -zp8 -5r -ms"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CNW
end_ifdef

begin_define
define|#
directive|define
name|compiler
value|"Watcom C/C++ 10.5 Win386"
end_define

begin_define
define|#
directive|define
name|options
value|"   No optimisation"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|COD
end_ifdef

begin_define
define|#
directive|define
name|compiler
value|"Watcom C/C++ 10.5 Dos4GW"
end_define

begin_define
define|#
directive|define
name|options
value|"  -otexan -zp8 -5r -ms"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CND
end_ifdef

begin_define
define|#
directive|define
name|compiler
value|"Watcom C/C++ 10.5 Dos4GW"
end_define

begin_define
define|#
directive|define
name|options
value|"   No optimisation"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONT
end_ifdef

begin_define
define|#
directive|define
name|compiler
value|"Watcom C/C++ 10.5 Win32NT"
end_define

begin_define
define|#
directive|define
name|options
value|"  -otexan -zp8 -5r -ms"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CNNT
end_ifdef

begin_define
define|#
directive|define
name|compiler
value|"Watcom C/C++ 10.5 Win32NT"
end_define

begin_define
define|#
directive|define
name|options
value|"   No optimisation"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|COO2
end_ifdef

begin_define
define|#
directive|define
name|compiler
value|"Watcom C/C++ 10.5 OS/2-32"
end_define

begin_define
define|#
directive|define
name|options
value|"  -otexan -zp8 -5r -ms"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CNO2
end_ifdef

begin_define
define|#
directive|define
name|compiler
value|"Watcom C/C++ 10.5 OS/2-32"
end_define

begin_define
define|#
directive|define
name|options
value|"   No optimisation"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Global Variables: */
end_comment

begin_decl_stmt
name|Rec_Pointer
name|Ptr_Glob
decl_stmt|,
name|Next_Ptr_Glob
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Int_Glob
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Boolean
name|Bool_Glob
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Ch_1_Glob
decl_stmt|,
name|Ch_2_Glob
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Arr_1_Glob
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Arr_2_Glob
index|[
literal|50
index|]
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getinput
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Reg_Define
index|[
literal|100
index|]
init|=
literal|"Register option      Selected."
decl_stmt|;
end_decl_stmt

begin_function_decl
name|Enumeration
name|Func_1
parameter_list|(
name|Capital_Letter
name|Ch_1_Par_Val
parameter_list|,
name|Capital_Letter
name|Ch_2_Par_Val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*     forward declaration necessary since Enumeration may not simply be int    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ROPT
end_ifndef

begin_define
define|#
directive|define
name|REG
end_define

begin_comment
comment|/* REG becomes defined as empty */
end_comment

begin_comment
comment|/* i.e. no register variables   */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REG
value|register
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|Proc_1
parameter_list|(
name|REG
name|Rec_Pointer
name|Ptr_Val_Par
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Proc_2
parameter_list|(
name|One_Fifty
modifier|*
name|Int_Par_Ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Proc_3
parameter_list|(
name|Rec_Pointer
modifier|*
name|Ptr_Ref_Par
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Proc_4
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Proc_5
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Proc_6
parameter_list|(
name|Enumeration
name|Enum_Val_Par
parameter_list|,
name|Enumeration
modifier|*
name|Enum_Ref_Par
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Proc_7
parameter_list|(
name|One_Fifty
name|Int_1_Par_Val
parameter_list|,
name|One_Fifty
name|Int_2_Par_Val
parameter_list|,
name|One_Fifty
modifier|*
name|Int_Par_Ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Proc_8
parameter_list|(
name|Arr_1_Dim
name|Arr_1_Par_Ref
parameter_list|,
name|Arr_2_Dim
name|Arr_2_Par_Ref
parameter_list|,
name|int
name|Int_1_Par_Val
parameter_list|,
name|int
name|Int_2_Par_Val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Func_2
parameter_list|(
name|Str_30
name|Str_1_Par_Ref
parameter_list|,
name|Str_30
name|Str_2_Par_Ref
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* variables for time measurement: */
end_comment

begin_define
define|#
directive|define
name|Too_Small_Time
value|2
end_define

begin_comment
comment|/* Measurements should last at least 2 seconds */
end_comment

begin_decl_stmt
name|double
name|Begin_Time
decl_stmt|,
name|End_Time
decl_stmt|,
name|User_Time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|Microseconds
decl_stmt|,
name|Dhrystones_Per_Second
decl_stmt|,
name|Vax_Mips
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of variables for time measurement */
end_comment

begin_function
name|void
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
comment|/*****/
comment|/* main program, corresponds to procedures        */
comment|/* Main and Proc_0 in the Ada version             */
block|{
name|double
name|dtime
parameter_list|()
function_decl|;
name|One_Fifty
name|Int_1_Loc
decl_stmt|;
name|REG
name|One_Fifty
name|Int_2_Loc
decl_stmt|;
name|One_Fifty
name|Int_3_Loc
decl_stmt|;
name|REG
name|char
name|Ch_Index
decl_stmt|;
name|Enumeration
name|Enum_Loc
decl_stmt|;
name|Str_30
name|Str_1_Loc
decl_stmt|;
name|Str_30
name|Str_2_Loc
decl_stmt|;
name|REG
name|int
name|Run_Index
decl_stmt|;
name|REG
name|int
name|Number_Of_Runs
decl_stmt|;
name|int
name|endit
decl_stmt|,
name|count
init|=
literal|10
decl_stmt|;
name|FILE
modifier|*
name|Ap
decl_stmt|;
name|char
name|general
index|[
literal|9
index|]
index|[
literal|80
index|]
init|=
block|{
literal|" "
block|}
decl_stmt|;
comment|/* Initializations */
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
block|{
switch|switch
condition|(
name|argv
index|[
literal|1
index|]
index|[
literal|0
index|]
condition|)
block|{
case|case
literal|'N'
case|:
name|getinput
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'n'
case|:
name|getinput
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|(
name|Ap
operator|=
name|fopen
argument_list|(
literal|"Dhry.txt"
argument_list|,
literal|"a+"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"Can not open Dhry.txt\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Press any key\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/***********************************************************************  *         Change for compiler and optimisation used                   *  ***********************************************************************/
name|Next_Ptr_Glob
operator|=
operator|(
name|Rec_Pointer
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|Rec_Type
argument_list|)
argument_list|)
expr_stmt|;
name|Ptr_Glob
operator|=
operator|(
name|Rec_Pointer
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|Rec_Type
argument_list|)
argument_list|)
expr_stmt|;
name|Ptr_Glob
operator|->
name|Ptr_Comp
operator|=
name|Next_Ptr_Glob
expr_stmt|;
name|Ptr_Glob
operator|->
name|Discr
operator|=
name|Ident_1
expr_stmt|;
name|Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Enum_Comp
operator|=
name|Ident_3
expr_stmt|;
name|Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Int_Comp
operator|=
literal|40
expr_stmt|;
name|strcpy
argument_list|(
name|Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Str_Comp
argument_list|,
literal|"DHRYSTONE PROGRAM, SOME STRING"
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|Str_1_Loc
argument_list|,
literal|"DHRYSTONE PROGRAM, 1'ST STRING"
argument_list|)
expr_stmt|;
name|Arr_2_Glob
index|[
literal|8
index|]
index|[
literal|7
index|]
operator|=
literal|10
expr_stmt|;
comment|/* Was missing in published program. Without this statement,   */
comment|/* Arr_2_Glob [8][7] would have an undefined value.            */
comment|/* Warning: With 16-Bit processors and Number_Of_Runs> 32000, */
comment|/* overflow may occur for this array element.                  */
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Dhrystone Benchmark, Version 2.1 (Language: C or C++)\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|getinput
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"No run time input data\n\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"With run time input data\n\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"Compiler        %s\n"
argument_list|,
name|compiler
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Optimisation    %s\n"
argument_list|,
name|options
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ROPT
name|printf
argument_list|(
literal|"Register option selected\n\n"
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"Register option not selected\n\n"
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|Reg_Define
argument_list|,
literal|"Register option      Not selected."
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/*      if (Reg)    {      printf ("Program compiled with 'register' attribute\n");      printf ("\n");    }    else    {      printf ("Program compiled without 'register' attribute\n");      printf ("\n");    }     printf ("Please give the number of runs through the benchmark: ");    {      int n;      scanf ("%d",&n);      Number_Of_Runs = n;    }       printf ("\n");     printf ("Execution starts, %d runs through Dhrystone\n",                                                  Number_Of_Runs);  */
name|Number_Of_Runs
operator|=
literal|5000
expr_stmt|;
do|do
block|{
name|Number_Of_Runs
operator|=
name|Number_Of_Runs
operator|*
literal|2
expr_stmt|;
name|count
operator|=
name|count
operator|-
literal|1
expr_stmt|;
name|Arr_2_Glob
index|[
literal|8
index|]
index|[
literal|7
index|]
operator|=
literal|10
expr_stmt|;
comment|/***************/
comment|/* Start timer */
comment|/***************/
name|Begin_Time
operator|=
name|dtime
argument_list|()
expr_stmt|;
for|for
control|(
name|Run_Index
operator|=
literal|1
init|;
name|Run_Index
operator|<=
name|Number_Of_Runs
condition|;
operator|++
name|Run_Index
control|)
block|{
name|Proc_5
argument_list|()
expr_stmt|;
name|Proc_4
argument_list|()
expr_stmt|;
comment|/* Ch_1_Glob == 'A', Ch_2_Glob == 'B', Bool_Glob == true */
name|Int_1_Loc
operator|=
literal|2
expr_stmt|;
name|Int_2_Loc
operator|=
literal|3
expr_stmt|;
name|strcpy
argument_list|(
name|Str_2_Loc
argument_list|,
literal|"DHRYSTONE PROGRAM, 2'ND STRING"
argument_list|)
expr_stmt|;
name|Enum_Loc
operator|=
name|Ident_2
expr_stmt|;
name|Bool_Glob
operator|=
operator|!
name|Func_2
argument_list|(
name|Str_1_Loc
argument_list|,
name|Str_2_Loc
argument_list|)
expr_stmt|;
comment|/* Bool_Glob == 1 */
while|while
condition|(
name|Int_1_Loc
operator|<
name|Int_2_Loc
condition|)
comment|/* loop body executed once */
block|{
name|Int_3_Loc
operator|=
literal|5
operator|*
name|Int_1_Loc
operator|-
name|Int_2_Loc
expr_stmt|;
comment|/* Int_3_Loc == 7 */
name|Proc_7
argument_list|(
name|Int_1_Loc
argument_list|,
name|Int_2_Loc
argument_list|,
operator|&
name|Int_3_Loc
argument_list|)
expr_stmt|;
comment|/* Int_3_Loc == 7 */
name|Int_1_Loc
operator|+=
literal|1
expr_stmt|;
block|}
comment|/* while */
comment|/* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
name|Proc_8
argument_list|(
name|Arr_1_Glob
argument_list|,
name|Arr_2_Glob
argument_list|,
name|Int_1_Loc
argument_list|,
name|Int_3_Loc
argument_list|)
expr_stmt|;
comment|/* Int_Glob == 5 */
name|Proc_1
argument_list|(
name|Ptr_Glob
argument_list|)
expr_stmt|;
for|for
control|(
name|Ch_Index
operator|=
literal|'A'
init|;
name|Ch_Index
operator|<=
name|Ch_2_Glob
condition|;
operator|++
name|Ch_Index
control|)
comment|/* loop body executed twice */
block|{
if|if
condition|(
name|Enum_Loc
operator|==
name|Func_1
argument_list|(
name|Ch_Index
argument_list|,
literal|'C'
argument_list|)
condition|)
comment|/* then, not executed */
block|{
name|Proc_6
argument_list|(
name|Ident_1
argument_list|,
operator|&
name|Enum_Loc
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|Str_2_Loc
argument_list|,
literal|"DHRYSTONE PROGRAM, 3'RD STRING"
argument_list|)
expr_stmt|;
name|Int_2_Loc
operator|=
name|Run_Index
expr_stmt|;
name|Int_Glob
operator|=
name|Run_Index
expr_stmt|;
block|}
block|}
comment|/* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
name|Int_2_Loc
operator|=
name|Int_2_Loc
operator|*
name|Int_1_Loc
expr_stmt|;
name|Int_1_Loc
operator|=
name|Int_2_Loc
operator|/
name|Int_3_Loc
expr_stmt|;
name|Int_2_Loc
operator|=
literal|7
operator|*
operator|(
name|Int_2_Loc
operator|-
name|Int_3_Loc
operator|)
operator|-
name|Int_1_Loc
expr_stmt|;
comment|/* Int_1_Loc == 1, Int_2_Loc == 13, Int_3_Loc == 7 */
name|Proc_2
argument_list|(
operator|&
name|Int_1_Loc
argument_list|)
expr_stmt|;
comment|/* Int_1_Loc == 5 */
block|}
comment|/* loop "for Run_Index" */
comment|/**************/
comment|/* Stop timer */
comment|/**************/
name|End_Time
operator|=
name|dtime
argument_list|()
expr_stmt|;
name|User_Time
operator|=
name|End_Time
operator|-
name|Begin_Time
expr_stmt|;
name|printf
argument_list|(
literal|"%12.0f runs %6.2f seconds \n"
argument_list|,
operator|(
name|double
operator|)
name|Number_Of_Runs
argument_list|,
name|User_Time
argument_list|)
expr_stmt|;
if|if
condition|(
name|User_Time
operator|>
literal|5
condition|)
block|{
name|count
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|User_Time
operator|<
literal|0.1
condition|)
block|{
name|Number_Of_Runs
operator|=
name|Number_Of_Runs
operator|*
literal|5
expr_stmt|;
block|}
block|}
block|}
comment|/* calibrate/run do while */
do|while
condition|(
name|count
operator|>
literal|0
condition|)
do|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Final values (* implementation-dependent):\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Int_Glob:      "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Int_Glob
operator|==
literal|5
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d  "
argument_list|,
name|Int_Glob
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Bool_Glob:     "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Bool_Glob
operator|==
literal|1
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|Bool_Glob
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Ch_1_Glob:     "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Ch_1_Glob
operator|==
literal|'A'
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%c  "
argument_list|,
name|Ch_1_Glob
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Ch_2_Glob:     "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Ch_2_Glob
operator|==
literal|'B'
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%c\n"
argument_list|,
name|Ch_2_Glob
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Arr_1_Glob[8]: "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Arr_1_Glob
index|[
literal|8
index|]
operator|==
literal|7
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d  "
argument_list|,
name|Arr_1_Glob
index|[
literal|8
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Arr_2_Glob8/7: "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Arr_2_Glob
index|[
literal|8
index|]
index|[
literal|7
index|]
operator|==
name|Number_Of_Runs
operator|+
literal|10
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%10d\n"
argument_list|,
name|Arr_2_Glob
index|[
literal|8
index|]
index|[
literal|7
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Ptr_Glob->            "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  Ptr_Comp:       *    %d\n"
argument_list|,
operator|(
name|int
operator|)
name|Ptr_Glob
operator|->
name|Ptr_Comp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  Discr:       "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Ptr_Glob
operator|->
name|Discr
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d  "
argument_list|,
name|Ptr_Glob
operator|->
name|Discr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Enum_Comp:     "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Enum_Comp
operator|==
literal|2
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Enum_Comp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  Int_Comp:    "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Int_Comp
operator|==
literal|17
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d "
argument_list|,
name|Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Int_Comp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Str_Comp:      "
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Str_Comp
argument_list|,
literal|"DHRYSTONE PROGRAM, SOME STRING"
argument_list|)
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Str_Comp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Next_Ptr_Glob->       "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  Ptr_Comp:       *    %d"
argument_list|,
operator|(
name|int
operator|)
name|Next_Ptr_Glob
operator|->
name|Ptr_Comp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" same as above\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  Discr:       "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Next_Ptr_Glob
operator|->
name|Discr
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d  "
argument_list|,
name|Next_Ptr_Glob
operator|->
name|Discr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Enum_Comp:     "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Next_Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Enum_Comp
operator|==
literal|1
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|Next_Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Enum_Comp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  Int_Comp:    "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Next_Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Int_Comp
operator|==
literal|18
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d "
argument_list|,
name|Next_Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Int_Comp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Str_Comp:      "
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|Next_Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Str_Comp
argument_list|,
literal|"DHRYSTONE PROGRAM, SOME STRING"
argument_list|)
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|Next_Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Str_Comp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Int_1_Loc:     "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Int_1_Loc
operator|==
literal|5
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d  "
argument_list|,
name|Int_1_Loc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Int_2_Loc:     "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Int_2_Loc
operator|==
literal|13
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|Int_2_Loc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Int_3_Loc:     "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Int_3_Loc
operator|==
literal|7
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d  "
argument_list|,
name|Int_3_Loc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Enum_Loc:      "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Enum_Loc
operator|==
literal|1
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|Enum_Loc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Str_1_Loc:                             "
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|Str_1_Loc
argument_list|,
literal|"DHRYSTONE PROGRAM, 1'ST STRING"
argument_list|)
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|Str_1_Loc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Str_2_Loc:                             "
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|Str_2_Loc
argument_list|,
literal|"DHRYSTONE PROGRAM, 2'ND STRING"
argument_list|)
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"WRONG "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|Str_2_Loc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|User_Time
operator|<
name|Too_Small_Time
condition|)
block|{
name|printf
argument_list|(
literal|"Measured time too small to obtain meaningful results\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Please increase number of runs\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Microseconds
operator|=
name|User_Time
operator|*
name|Mic_secs_Per_Second
operator|/
operator|(
name|double
operator|)
name|Number_Of_Runs
expr_stmt|;
name|Dhrystones_Per_Second
operator|=
operator|(
name|double
operator|)
name|Number_Of_Runs
operator|/
name|User_Time
expr_stmt|;
name|Vax_Mips
operator|=
name|Dhrystones_Per_Second
operator|/
literal|1757.0
expr_stmt|;
name|printf
argument_list|(
literal|"Microseconds for one run through Dhrystone: "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%12.2lf \n"
argument_list|,
name|Microseconds
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Dhrystones per Second:                      "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%10.0lf \n"
argument_list|,
name|Dhrystones_Per_Second
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"VAX  MIPS rating =                          "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%12.2lf \n"
argument_list|,
name|Vax_Mips
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
comment|/************************************************************************  *             Type details of hardware, software etc.                  *  ************************************************************************/
if|if
condition|(
name|getinput
operator|==
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"Enter the following which will be added with results to file DHRY.TXT\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"When submitting a number of results you need only provide details once\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"but a cross reference such as an abbreviated CPU type would be useful.\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"You can kill (exit or close) the program now and no data will be added.\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"PC Supplier/model     ? "
argument_list|)
expr_stmt|;
name|gets
argument_list|(
name|general
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"CPU chip              ? "
argument_list|)
expr_stmt|;
name|gets
argument_list|(
name|general
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Clock MHz             ? "
argument_list|)
expr_stmt|;
name|gets
argument_list|(
name|general
index|[
literal|3
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Cache size            ? "
argument_list|)
expr_stmt|;
name|gets
argument_list|(
name|general
index|[
literal|4
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Chipset& H/W options ? "
argument_list|)
expr_stmt|;
name|gets
argument_list|(
name|general
index|[
literal|5
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"OS/DOS version        ? "
argument_list|)
expr_stmt|;
name|gets
argument_list|(
name|general
index|[
literal|6
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Your name             ? "
argument_list|)
expr_stmt|;
name|gets
argument_list|(
name|general
index|[
literal|7
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Company/Location      ? "
argument_list|)
expr_stmt|;
name|gets
argument_list|(
name|general
index|[
literal|8
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"E-mail address        ? "
argument_list|)
expr_stmt|;
name|gets
argument_list|(
name|general
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
comment|/************************************************************************  *                Add results to output file Dhry.txt                   *  ************************************************************************/
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"-------------------- -----------------------------------"
literal|"\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Dhrystone Benchmark  Version 2.1 (Language: C++)\n\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"PC model             %s\n"
argument_list|,
name|general
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"CPU                  %s\n"
argument_list|,
name|general
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Clock MHz            %s\n"
argument_list|,
name|general
index|[
literal|3
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Cache                %s\n"
argument_list|,
name|general
index|[
literal|4
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Options              %s\n"
argument_list|,
name|general
index|[
literal|5
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"OS/DOS               %s\n"
argument_list|,
name|general
index|[
literal|6
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Compiler             %s\n"
argument_list|,
name|compiler
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"OptLevel             %s\n"
argument_list|,
name|options
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Run by               %s\n"
argument_list|,
name|general
index|[
literal|7
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"From                 %s\n"
argument_list|,
name|general
index|[
literal|8
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Mail                 %s\n\n"
argument_list|,
name|general
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Final values         (* implementation-dependent):\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Int_Glob:      "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Int_Glob
operator|==
literal|5
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%d\n"
argument_list|,
name|Int_Glob
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Bool_Glob:     "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Bool_Glob
operator|==
literal|1
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%d\n"
argument_list|,
name|Bool_Glob
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Ch_1_Glob:     "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Ch_1_Glob
operator|==
literal|'A'
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%c\n"
argument_list|,
name|Ch_1_Glob
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Ch_2_Glob:     "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Ch_2_Glob
operator|==
literal|'B'
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%c\n"
argument_list|,
name|Ch_2_Glob
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Arr_1_Glob[8]: "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Arr_1_Glob
index|[
literal|8
index|]
operator|==
literal|7
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%d\n"
argument_list|,
name|Arr_1_Glob
index|[
literal|8
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Arr_2_Glob8/7: "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Arr_2_Glob
index|[
literal|8
index|]
index|[
literal|7
index|]
operator|==
name|Number_Of_Runs
operator|+
literal|10
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%10d\n"
argument_list|,
name|Arr_2_Glob
index|[
literal|8
index|]
index|[
literal|7
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Ptr_Glob->  \n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"  Ptr_Comp:       *  %d\n"
argument_list|,
operator|(
name|int
operator|)
name|Ptr_Glob
operator|->
name|Ptr_Comp
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"  Discr:       "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Ptr_Glob
operator|->
name|Discr
operator|==
literal|0
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%d\n"
argument_list|,
name|Ptr_Glob
operator|->
name|Discr
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"  Enum_Comp:   "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Enum_Comp
operator|==
literal|2
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%d\n"
argument_list|,
name|Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Enum_Comp
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"  Int_Comp:    "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Int_Comp
operator|==
literal|17
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%d\n"
argument_list|,
name|Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Int_Comp
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"  Str_Comp:    "
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Str_Comp
argument_list|,
literal|"DHRYSTONE PROGRAM, SOME STRING"
argument_list|)
operator|==
literal|0
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%s\n"
argument_list|,
name|Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Str_Comp
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Next_Ptr_Glob-> \n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"  Ptr_Comp:       *  %d"
argument_list|,
operator|(
name|int
operator|)
name|Next_Ptr_Glob
operator|->
name|Ptr_Comp
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|" same as above\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"  Discr:       "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Next_Ptr_Glob
operator|->
name|Discr
operator|==
literal|0
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%d\n"
argument_list|,
name|Next_Ptr_Glob
operator|->
name|Discr
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"  Enum_Comp:   "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Next_Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Enum_Comp
operator|==
literal|1
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%d\n"
argument_list|,
name|Next_Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Enum_Comp
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"  Int_Comp:    "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Next_Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Int_Comp
operator|==
literal|18
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%d\n"
argument_list|,
name|Next_Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Int_Comp
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"  Str_Comp:    "
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|Next_Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Str_Comp
argument_list|,
literal|"DHRYSTONE PROGRAM, SOME STRING"
argument_list|)
operator|==
literal|0
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%s\n"
argument_list|,
name|Next_Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Str_Comp
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Int_1_Loc:     "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Int_1_Loc
operator|==
literal|5
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%d\n"
argument_list|,
name|Int_1_Loc
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Int_2_Loc:     "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Int_2_Loc
operator|==
literal|13
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%d\n"
argument_list|,
name|Int_2_Loc
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Int_3_Loc:     "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Int_3_Loc
operator|==
literal|7
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%d\n"
argument_list|,
name|Int_3_Loc
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Enum_Loc:      "
argument_list|)
expr_stmt|;
if|if
condition|(
name|Enum_Loc
operator|==
literal|1
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%d\n"
argument_list|,
name|Enum_Loc
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Str_1_Loc:     "
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|Str_1_Loc
argument_list|,
literal|"DHRYSTONE PROGRAM, 1'ST STRING"
argument_list|)
operator|==
literal|0
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%s\n"
argument_list|,
name|Str_1_Loc
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Str_2_Loc:     "
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|Str_2_Loc
argument_list|,
literal|"DHRYSTONE PROGRAM, 2'ND STRING"
argument_list|)
operator|==
literal|0
condition|)
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"O.K.  "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"WRONG "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%s\n"
argument_list|,
name|Str_2_Loc
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"%s\n"
argument_list|,
name|Reg_Define
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Microseconds 1 loop:  %12.2lf\n"
argument_list|,
name|Microseconds
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"Dhrystones / second:  %10.0lf\n"
argument_list|,
name|Dhrystones_Per_Second
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|Ap
argument_list|,
literal|"VAX MIPS rating:      %12.2lf\n\n"
argument_list|,
name|Vax_Mips
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|Ap
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"A new results file will have been created in the same directory as the\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".EXE files if one did not already exist. If you made a mistake on input, \n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"you can use a text editor to correct it, delete the results or copy \n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"them to a different file name. If you intend to run multiple tests you\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"you may wish to rename DHRY.TXT with a more informative title.\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Please submit feedback and results files as a posting in Section 12\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"or to Roy_Longbottom@compuserve.com\n\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|getinput
operator|==
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"Press any key to exit\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nIf this is displayed you must close the window in the normal way\n"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|Proc_1
parameter_list|(
name|REG
name|Rec_Pointer
name|Ptr_Val_Par
parameter_list|)
comment|/******************/
comment|/* executed once */
block|{
name|REG
name|Rec_Pointer
name|Next_Record
init|=
name|Ptr_Val_Par
operator|->
name|Ptr_Comp
decl_stmt|;
comment|/* == Ptr_Glob_Next */
comment|/* Local variable, initialized with Ptr_Val_Par->Ptr_Comp,    */
comment|/* corresponds to "rename" in Ada, "with" in Pascal           */
name|structassign
argument_list|(
operator|*
name|Ptr_Val_Par
operator|->
name|Ptr_Comp
argument_list|,
operator|*
name|Ptr_Glob
argument_list|)
expr_stmt|;
name|Ptr_Val_Par
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Int_Comp
operator|=
literal|5
expr_stmt|;
name|Next_Record
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Int_Comp
operator|=
name|Ptr_Val_Par
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Int_Comp
expr_stmt|;
name|Next_Record
operator|->
name|Ptr_Comp
operator|=
name|Ptr_Val_Par
operator|->
name|Ptr_Comp
expr_stmt|;
name|Proc_3
argument_list|(
operator|&
name|Next_Record
operator|->
name|Ptr_Comp
argument_list|)
expr_stmt|;
comment|/* Ptr_Val_Par->Ptr_Comp->Ptr_Comp                           == Ptr_Glob->Ptr_Comp */
if|if
condition|(
name|Next_Record
operator|->
name|Discr
operator|==
name|Ident_1
condition|)
comment|/* then, executed */
block|{
name|Next_Record
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Int_Comp
operator|=
literal|6
expr_stmt|;
name|Proc_6
argument_list|(
name|Ptr_Val_Par
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Enum_Comp
argument_list|,
operator|&
name|Next_Record
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Enum_Comp
argument_list|)
expr_stmt|;
name|Next_Record
operator|->
name|Ptr_Comp
operator|=
name|Ptr_Glob
operator|->
name|Ptr_Comp
expr_stmt|;
name|Proc_7
argument_list|(
name|Next_Record
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Int_Comp
argument_list|,
literal|10
argument_list|,
operator|&
name|Next_Record
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Int_Comp
argument_list|)
expr_stmt|;
block|}
else|else
comment|/* not executed */
name|structassign
argument_list|(
operator|*
name|Ptr_Val_Par
argument_list|,
operator|*
name|Ptr_Val_Par
operator|->
name|Ptr_Comp
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Proc_1 */
end_comment

begin_function
name|void
name|Proc_2
parameter_list|(
name|One_Fifty
modifier|*
name|Int_Par_Ref
parameter_list|)
comment|/******************/
comment|/* executed once */
comment|/* *Int_Par_Ref == 1, becomes 4 */
block|{
name|One_Fifty
name|Int_Loc
decl_stmt|;
name|Enumeration
name|Enum_Loc
decl_stmt|;
name|Int_Loc
operator|=
operator|*
name|Int_Par_Ref
operator|+
literal|10
expr_stmt|;
do|do
comment|/* executed once */
if|if
condition|(
name|Ch_1_Glob
operator|==
literal|'A'
condition|)
comment|/* then, executed */
block|{
name|Int_Loc
operator|-=
literal|1
expr_stmt|;
operator|*
name|Int_Par_Ref
operator|=
name|Int_Loc
operator|-
name|Int_Glob
expr_stmt|;
name|Enum_Loc
operator|=
name|Ident_1
expr_stmt|;
block|}
comment|/* if */
do|while
condition|(
name|Enum_Loc
operator|!=
name|Ident_1
condition|)
do|;
comment|/* true */
block|}
end_function

begin_comment
comment|/* Proc_2 */
end_comment

begin_function
name|void
name|Proc_3
parameter_list|(
name|Rec_Pointer
modifier|*
name|Ptr_Ref_Par
parameter_list|)
comment|/******************/
comment|/* executed once */
comment|/* Ptr_Ref_Par becomes Ptr_Glob */
block|{
if|if
condition|(
name|Ptr_Glob
operator|!=
name|Null
condition|)
comment|/* then, executed */
operator|*
name|Ptr_Ref_Par
operator|=
name|Ptr_Glob
operator|->
name|Ptr_Comp
expr_stmt|;
name|Proc_7
argument_list|(
literal|10
argument_list|,
name|Int_Glob
argument_list|,
operator|&
name|Ptr_Glob
operator|->
name|variant
operator|.
name|var_1
operator|.
name|Int_Comp
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Proc_3 */
end_comment

begin_function
name|void
name|Proc_4
parameter_list|()
comment|/* without parameters */
comment|/*******/
comment|/* executed once */
block|{
name|Boolean
name|Bool_Loc
decl_stmt|;
name|Bool_Loc
operator|=
name|Ch_1_Glob
operator|==
literal|'A'
expr_stmt|;
name|Bool_Glob
operator|=
name|Bool_Loc
operator||
name|Bool_Glob
expr_stmt|;
name|Ch_2_Glob
operator|=
literal|'B'
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Proc_4 */
end_comment

begin_function
name|void
name|Proc_5
parameter_list|()
comment|/* without parameters */
comment|/*******/
comment|/* executed once */
block|{
name|Ch_1_Glob
operator|=
literal|'A'
expr_stmt|;
name|Bool_Glob
operator|=
name|false
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Proc_5 */
end_comment

begin_comment
comment|/* Procedure for the assignment of structures,          */
end_comment

begin_comment
comment|/* if the C compiler doesn't support this feature       */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOSTRUCTASSIGN
end_ifdef

begin_expr_stmt
name|memcpy
argument_list|(
name|d
argument_list|,
name|s
argument_list|,
name|l
argument_list|)
specifier|register
name|char
operator|*
name|d
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|int
name|l
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
name|l
operator|--
condition|)
operator|*
name|d
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|double
name|dtime
parameter_list|()
block|{
comment|/* #include<ctype.h> */
define|#
directive|define
name|HZ
value|CLOCKS_PER_SEC
name|clock_t
name|tnow
decl_stmt|;
name|double
name|q
decl_stmt|;
name|tnow
operator|=
name|clock
argument_list|()
expr_stmt|;
name|q
operator|=
operator|(
name|double
operator|)
name|tnow
operator|/
operator|(
name|double
operator|)
name|HZ
expr_stmt|;
return|return
name|q
return|;
block|}
end_function

end_unit

