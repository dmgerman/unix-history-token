begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vmsysent.c	2.1	1/5/80	*/
end_comment

begin_comment
comment|/*  * This table is the switch used to transfer  * to the appropriate routine for processing a vmunix special system call.  * Each row contains the number of arguments expected  * and a pointer to the routine.  */
end_comment

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/systm.h"
end_include

begin_function_decl
name|int
name|nosys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nullsys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfork
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vwrite
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|sysent
name|vmsysent
index|[
literal|64
index|]
init|=
block|{
comment|/*  * Executing system call 64 indirect will tell whether the current  * system is a vmunix, since this will give an error indication on  * a non-virtual system, but just return without error on a virtual system.  */
define|#
directive|define
name|isvmsys
value|nullsys
literal|0
block|,
literal|0
block|,
name|isvmsys
block|,
comment|/*  0 = isvmsys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/*  1 = nosys */
literal|0
block|,
literal|0
block|,
name|vfork
block|,
comment|/*  2 = vfork */
literal|3
block|,
literal|0
block|,
name|vread
block|,
comment|/*  3 = vread */
literal|3
block|,
literal|0
block|,
name|vwrite
block|,
comment|/*  4 = vwrite */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/*  5 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/*  6 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/*  7 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/*  8 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/*  9 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 10 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 11 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 12 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 13 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 14 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 15 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 16 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 17 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 18 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 19 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 20 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 21 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 22 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 23 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 24 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 25 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 26 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 27 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 28 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 29 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 30 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 31 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 32 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 33 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 34 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 35 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 36 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 37 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 38 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 39 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 40 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 41 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 42 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 43 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 44 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 45 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 46 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 47 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 48 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 49 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 50 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 51 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 52 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 53 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 54 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 55 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 56 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 57 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 58 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 59 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 60 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 61 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 62 = nosys */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 63 = nosys */
block|}
decl_stmt|;
end_decl_stmt

end_unit

