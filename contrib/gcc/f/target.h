begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* target.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995, 1996 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       target.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_TARGET_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_TARGET_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FFE_STANDALONE
end_ifdef

begin_define
define|#
directive|define
name|HOST_WIDE_INT
value|long
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|TREE_CODE
end_ifndef

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For now, g77 requires the ability to determine the exact bit pattern    of a float on the target machine.  (Hopefully this will be changed    soon).  Make sure we can do this.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|REAL_ARITHMETIC
argument_list|)
expr|\
operator|&&
operator|(
operator|(
name|TARGET_FLOAT_FORMAT
operator|!=
name|HOST_FLOAT_FORMAT
operator|)
expr|\
operator|||
operator|(
name|FLOAT_WORDS_BIG_ENDIAN
operator|!=
name|HOST_FLOAT_WORDS_BIG_ENDIAN
operator|)
operator|)
end_if

begin_error
error|#
directive|error
literal|"g77 requires ability to access exact FP representation of target machine"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_define
define|#
directive|define
name|FFETARGET_charactersizeNONE
value|(-1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_charactersizeMAXIMUM
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_charactersizeMAXIMUM
value|2147483647
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_defaultIS_90
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_defaultIS_90
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_defaultIS_AUTOMATIC
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_defaultIS_AUTOMATIC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_defaultIS_BACKSLASH
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_defaultIS_BACKSLASH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_defaultIS_INIT_LOCAL_ZERO
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_defaultIS_INIT_LOCAL_ZERO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_defaultIS_DOLLAR_OK
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_defaultIS_DOLLAR_OK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_defaultIS_F2C
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_defaultIS_F2C
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_defaultIS_F2C_LIBRARY
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_defaultIS_F2C_LIBRARY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_defaultIS_FREE_FORM
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_defaultIS_FREE_FORM
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_defaultIS_PEDANTIC
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_defaultIS_PEDANTIC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_defaultCASE_INTRIN
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_defaultCASE_INTRIN
value|FFE_caseLOWER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_defaultCASE_MATCH
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_defaultCASE_MATCH
value|FFE_caseLOWER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_defaultCASE_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_defaultCASE_SOURCE
value|FFE_caseLOWER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_defaultCASE_SYMBOL
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_defaultCASE_SYMBOL
value|FFE_caseNONE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_defaultFIXED_LINE_LENGTH
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_defaultFIXED_LINE_LENGTH
value|72
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 1 if external Fortran names ("FOO" in SUBROUTINE FOO, COMMON /FOO/,    and even enforced/default-for-unnamed PROGRAM, blank-COMMON, and    BLOCK DATA names, but not names of library functions implementing    intrinsics or names of local/internal variables) should have an    underscore appended (for compatibility with existing systems).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_defaultEXTERNAL_UNDERSCORED
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_defaultEXTERNAL_UNDERSCORED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 1 if external Fortran names with underscores already in them should    have an extra underscore appended (in addition to the one they    might already have appened if FFETARGET_defaultEXTERNAL_UNDERSCORED). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_defaultUNDERSCORED_EXTERNAL_UNDERSCORED
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_defaultUNDERSCORED_EXTERNAL_UNDERSCORED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If FFETARGET_defaultEXTERNAL_UNDERSCORED is 0, the following definitions    might also need to be overridden to make g77 objects compatible with    f2c+gcc objects.  Although I don't think the unnamed BLOCK DATA one    is an issue at all.  Of course, on some systems it isn't f2c    compatibility that is the issue -- maybe compatibility with some    other compiler(s).  I don't know what to recommend for systems where    there is no existing Fortran compiler -- I suppose porting f2c and    pretending it's the existing one is best for now.  */
end_comment

begin_comment
comment|/* 1 if the "FOO" in "PROGRAM FOO" should be overridden and a particular    name imposed in place of it in the actual code (normally the case,    because the library's main entry point on most systems calls the main    function by a particular name).  Someday g77 might do the f2c trick    of also outputting a "FOO" procedure that just calls the main procedure,    but that'll wait until somebody shows why it is needed.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_isENFORCED_MAIN
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_isENFORCED_MAIN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The enforced name of the main program if ENFORCED_MAIN is 1.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_nameENFORCED_MAIN_NAME
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_nameENFORCED_MAIN_NAME
value|"MAIN__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The name used for an unnamed main program if ENFORCED_MAIN is 0.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_nameUNNAMED_MAIN
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_nameUNNAMED_MAIN
value|"MAIN__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The name used for an unnamed block data program.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_nameUNNAMED_BLOCK_DATA
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_nameUNNAMED_BLOCK_DATA
value|"_BLOCK_DATA__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The name used for blank common.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_nameBLANK_COMMON
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_nameBLANK_COMMON
value|"_BLNK__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_integerSMALLEST_POSITIVE
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_integerSMALLEST_POSITIVE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_integerLARGEST_POSITIVE
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_integerLARGEST_POSITIVE
value|2147483647
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_integerBIG_MAGICAL
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_integerBIG_MAGICAL
value|020000000000
end_define

begin_comment
comment|/* 2147483648 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_integerALMOST_BIG_MAGICAL
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_integerALMOST_BIG_MAGICAL
value|214748364
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_integerALMOST_BIG_OVERFLOW_BINARY
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_integerALMOST_BIG_OVERFLOW_BINARY
value|0x80000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_integerALMOST_BIG_OVERFLOW_HEX
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_integerALMOST_BIG_OVERFLOW_HEX
value|0x10000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_integerALMOST_BIG_OVERFLOW_OCTAL
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_integerALMOST_BIG_OVERFLOW_OCTAL
value|0x20000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_integerFINISH_BIG_MAGICAL
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_integerFINISH_BIG_MAGICAL
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_integerFINISH_BIG_OVERFLOW_BINARY
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_integerFINISH_BIG_OVERFLOW_BINARY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_integerFINISH_BIG_OVERFLOW_HEX
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_integerFINISH_BIG_OVERFLOW_HEX
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_integerFINISH_BIG_OVERFLOW_OCTAL
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_integerFINISH_BIG_OVERFLOW_OCTAL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FFETARGET_offsetNONE
end_ifndef

begin_define
define|#
directive|define
name|FFETARGET_offsetNONE
value|0
end_define

begin_comment
comment|/* Not used by FFE, for backend if needed. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FFETARGET_okINTEGER1
value|1
end_define

begin_define
define|#
directive|define
name|FFETARGET_okINTEGER2
value|1
end_define

begin_define
define|#
directive|define
name|FFETARGET_okINTEGER3
value|1
end_define

begin_define
define|#
directive|define
name|FFETARGET_okINTEGER4
value|1
end_define

begin_define
define|#
directive|define
name|FFETARGET_okLOGICAL1
value|1
end_define

begin_define
define|#
directive|define
name|FFETARGET_okLOGICAL2
value|1
end_define

begin_define
define|#
directive|define
name|FFETARGET_okLOGICAL3
value|1
end_define

begin_define
define|#
directive|define
name|FFETARGET_okLOGICAL4
value|1
end_define

begin_define
define|#
directive|define
name|FFETARGET_okREAL1
value|1
end_define

begin_define
define|#
directive|define
name|FFETARGET_okREAL2
value|1
end_define

begin_define
define|#
directive|define
name|FFETARGET_okREAL3
value|0
end_define

begin_define
define|#
directive|define
name|FFETARGET_okREALQUAD
value|FFETARGET_okREAL3
end_define

begin_define
define|#
directive|define
name|FFETARGET_okCOMPLEX1
value|1
end_define

begin_define
define|#
directive|define
name|FFETARGET_okCOMPLEX2
value|1
end_define

begin_define
define|#
directive|define
name|FFETARGET_okCOMPLEX3
value|0
end_define

begin_define
define|#
directive|define
name|FFETARGET_okCOMPLEXDOUBLE
value|FFETARGET_okCOMPLEX2
end_define

begin_define
define|#
directive|define
name|FFETARGET_okCOMPLEXQUAD
value|FFETARGET_okCOMPLEX3
end_define

begin_define
define|#
directive|define
name|FFETARGET_okCHARACTER1
value|1
end_define

begin_define
define|#
directive|define
name|FFETARGET_f2cTYUNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|FFETARGET_f2cTYADDR
value|1
end_define

begin_define
define|#
directive|define
name|FFETARGET_f2cTYSHORT
value|2
end_define

begin_define
define|#
directive|define
name|FFETARGET_f2cTYLONG
value|3
end_define

begin_define
define|#
directive|define
name|FFETARGET_f2cTYREAL
value|4
end_define

begin_define
define|#
directive|define
name|FFETARGET_f2cTYDREAL
value|5
end_define

begin_define
define|#
directive|define
name|FFETARGET_f2cTYCOMPLEX
value|6
end_define

begin_define
define|#
directive|define
name|FFETARGET_f2cTYDCOMPLEX
value|7
end_define

begin_define
define|#
directive|define
name|FFETARGET_f2cTYLOGICAL
value|8
end_define

begin_define
define|#
directive|define
name|FFETARGET_f2cTYCHAR
value|9
end_define

begin_define
define|#
directive|define
name|FFETARGET_f2cTYSUBR
value|10
end_define

begin_define
define|#
directive|define
name|FFETARGET_f2cTYINT1
value|11
end_define

begin_define
define|#
directive|define
name|FFETARGET_f2cTYLOGICAL1
value|12
end_define

begin_define
define|#
directive|define
name|FFETARGET_f2cTYLOGICAL2
value|13
end_define

begin_define
define|#
directive|define
name|FFETARGET_f2cTYQUAD
value|14
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__alpha__
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|_ARCH_PPC
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|__64BIT__
argument_list|)
operator|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|__sparc__
argument_list|)
operator|||
operator|(
operator|!
name|defined
argument_list|(
name|__sparcv9
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__arch64__
argument_list|)
operator|)
operator|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|__ia64__
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|__LP64__
argument_list|)
operator|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|__hppa__
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|__LP64__
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__s390x__
argument_list|)
end_if

begin_define
define|#
directive|define
name|FFETARGET_32bit_longs
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Typedefs. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|ffetargetAlign
typedef|;
end_typedef

begin_comment
comment|/* ffetargetOffset for alignment. */
end_comment

begin_define
define|#
directive|define
name|ffetargetAlign_f
value|""
end_define

begin_typedef
typedef|typedef
name|long
name|ffetargetCharacterSize
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetCharacterSize_f
value|"l"
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ffetargetCopyfunc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|ffetargetCharacterSize
name|ffetargetHollerithSize
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetHollerithSize_f
value|"l"
end_define

begin_typedef
typedef|typedef
name|long
name|long
name|ffetargetOffset
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetOffset_f
value|"ll"
end_define

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER1
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|FFETARGET_32bit_longs
end_ifdef

begin_typedef
typedef|typedef
name|long
name|int
name|ffetargetInteger1
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetInteger1_f
value|"l"
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|ffetargetInteger1
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetInteger1_f
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER2
end_if

begin_typedef
typedef|typedef
name|signed
name|char
name|ffetargetInteger2
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetInteger2_f
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER3
end_if

begin_typedef
typedef|typedef
name|short
name|int
name|ffetargetInteger3
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetInteger3_f
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER4
end_if

begin_typedef
typedef|typedef
name|long
name|long
name|int
name|ffetargetInteger4
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetInteger4_f
value|"ll"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER5
end_if

begin_typedef
typedef|typedef
operator|?
name|ffetargetInteger5
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetInteger5_f
end_define

begin_expr_stmt
operator|?
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER6
end_if

begin_typedef
typedef|typedef
operator|?
name|ffetargetInteger6
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetInteger6_f
end_define

begin_expr_stmt
operator|?
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER7
end_if

begin_typedef
typedef|typedef
operator|?
name|ffetargetInteger7
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetInteger7_f
end_define

begin_expr_stmt
operator|?
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER8
end_if

begin_typedef
typedef|typedef
operator|?
name|ffetargetInteger8
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetInteger8_f
end_define

begin_expr_stmt
operator|?
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okLOGICAL1
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|FFETARGET_32bit_longs
end_ifdef

begin_typedef
typedef|typedef
name|long
name|int
name|ffetargetLogical1
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetLogical1_f
value|"l"
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|ffetargetLogical1
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetLogical1_f
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okLOGICAL2
end_if

begin_typedef
typedef|typedef
name|signed
name|char
name|ffetargetLogical2
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetLogical2_f
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okLOGICAL3
end_if

begin_typedef
typedef|typedef
name|short
name|int
name|ffetargetLogical3
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetLogical3_f
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okLOGICAL4
end_if

begin_typedef
typedef|typedef
name|long
name|long
name|int
name|ffetargetLogical4
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetLogical4_f
value|"ll"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okLOGICAL5
end_if

begin_typedef
typedef|typedef
operator|?
name|ffetargetLogical5
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetLogical5_f
end_define

begin_expr_stmt
operator|?
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okLOGICAL6
end_if

begin_typedef
typedef|typedef
operator|?
name|ffetargetLogical6
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetLogical6_f
end_define

begin_expr_stmt
operator|?
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okLOGICAL7
end_if

begin_typedef
typedef|typedef
operator|?
name|ffetargetLogical7
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetLogical7_f
end_define

begin_expr_stmt
operator|?
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okLOGICAL8
end_if

begin_typedef
typedef|typedef
operator|?
name|ffetargetLogical8
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetLogical8_f
end_define

begin_expr_stmt
operator|?
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL1
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|FFETARGET_32bit_longs
end_ifdef

begin_typedef
typedef|typedef
name|long
name|int
name|ffetargetReal1
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetReal1_f
value|"l"
end_define

begin_define
define|#
directive|define
name|ffetarget_cvt_r1_to_rv_
value|REAL_VALUE_UNTO_TARGET_SINGLE
end_define

begin_define
define|#
directive|define
name|ffetarget_cvt_rv_to_r1_
value|REAL_VALUE_TO_TARGET_SINGLE
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|ffetargetReal1
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetReal1_f
value|""
end_define

begin_define
define|#
directive|define
name|ffetarget_cvt_r1_to_rv_
parameter_list|(
name|in
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE _rv; \      _rv = REAL_VALUE_UNTO_TARGET_SINGLE ((long) (in)); \      _rv; })
end_define

begin_define
define|#
directive|define
name|ffetarget_cvt_rv_to_r1_
parameter_list|(
name|in
parameter_list|,
name|out
parameter_list|)
define|\
value|({ long _tmp; \      REAL_VALUE_TO_TARGET_SINGLE ((in), _tmp); \      (out) = (ffetargetReal1) _tmp; })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* REAL_ARITHMETIC */
end_comment

begin_typedef
typedef|typedef
name|float
name|ffetargetReal1
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetReal1_f
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REAL_ARITHMETIC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL2
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|FFETARGET_32bit_longs
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|int
name|v
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ffetargetReal2
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetReal2_f
value|"l"
end_define

begin_define
define|#
directive|define
name|ffetarget_cvt_r2_to_rv_
value|REAL_VALUE_UNTO_TARGET_DOUBLE
end_define

begin_define
define|#
directive|define
name|ffetarget_cvt_rv_to_r2_
value|REAL_VALUE_TO_TARGET_DOUBLE
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|v
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ffetargetReal2
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetReal2_f
value|""
end_define

begin_define
define|#
directive|define
name|ffetarget_cvt_r2_to_rv_
parameter_list|(
name|in
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE _rv; \      long _tmp[2]; \      _tmp[0] = (in)[0]; \      _tmp[1] = (in)[1]; \      _rv = REAL_VALUE_UNTO_TARGET_DOUBLE (_tmp); \      _rv; })
end_define

begin_define
define|#
directive|define
name|ffetarget_cvt_rv_to_r2_
parameter_list|(
name|in
parameter_list|,
name|out
parameter_list|)
define|\
value|({ long _tmp[2]; \      REAL_VALUE_TO_TARGET_DOUBLE ((in), _tmp); \      (out)[0] = (int) (_tmp[0]); \      (out)[1] = (int) (_tmp[1]); })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|double
name|ffetargetReal2
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetReal2_f
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL3
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_typedef
typedef|typedef
name|long
name|ffetargetReal3
index|[
operator|?
index|]
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
operator|?
name|ffetargetReal3
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetReal3_f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
operator|?
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL4
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_typedef
typedef|typedef
name|long
name|ffetargetReal4
index|[
operator|?
index|]
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
operator|?
name|ffetargetReal4
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetReal4_f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
operator|?
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL5
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_typedef
typedef|typedef
name|long
name|ffetargetReal5
index|[
operator|?
index|]
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
operator|?
name|ffetargetReal5
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetReal5_f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
operator|?
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL6
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_typedef
typedef|typedef
name|long
name|ffetargetReal6
index|[
operator|?
index|]
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
operator|?
name|ffetargetReal6
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetReal6_f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
operator|?
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL7
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_typedef
typedef|typedef
name|long
name|ffetargetReal7
index|[
operator|?
index|]
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
operator|?
name|ffetargetReal7
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetReal7_f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
operator|?
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL8
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_typedef
typedef|typedef
name|long
name|ffetargetReal8
index|[
operator|?
index|]
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
operator|?
name|ffetargetReal8
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetReal8_f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
operator|?
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okCOMPLEX1
expr|struct
name|_ffetarget_complex_1_
block|{
name|ffetargetReal1
name|real
block|;
name|ffetargetReal1
name|imaginary
block|;   }
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|struct
name|_ffetarget_complex_1_
name|ffetargetComplex1
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX2
end_if

begin_struct
struct|struct
name|_ffetarget_complex_2_
block|{
name|ffetargetReal2
name|real
decl_stmt|;
name|ffetargetReal2
name|imaginary
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_ffetarget_complex_2_
name|ffetargetComplex2
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX3
end_if

begin_struct
struct|struct
name|_ffetarget_complex_3_
block|{
name|ffetargetReal3
name|real
decl_stmt|;
name|ffetargetReal3
name|imaginary
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_ffetarget_complex_3_
name|ffetargetComplex3
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX4
end_if

begin_struct
struct|struct
name|_ffetarget_complex_4_
block|{
name|ffetargetReal4
name|real
decl_stmt|;
name|ffetargetReal4
name|imaginary
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_ffetarget_complex_4_
name|ffetargetComplex4
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX5
end_if

begin_struct
struct|struct
name|_ffetarget_complex_5_
block|{
name|ffetargetReal5
name|real
decl_stmt|;
name|ffetargetReal5
name|imaginary
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_ffetarget_complex_5_
name|ffetargetComplex5
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX6
end_if

begin_struct
struct|struct
name|_ffetarget_complex_6_
block|{
name|ffetargetReal6
name|real
decl_stmt|;
name|ffetargetReal6
name|imaginary
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_ffetarget_complex_6_
name|ffetargetComplex6
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX7
end_if

begin_struct
struct|struct
name|_ffetarget_complex_7_
block|{
name|ffetargetReal7
name|real
decl_stmt|;
name|ffetargetReal7
name|imaginary
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_ffetarget_complex_7_
name|ffetargetComplex7
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX8
end_if

begin_struct
struct|struct
name|_ffetarget_complex_8_
block|{
name|ffetargetReal8
name|real
decl_stmt|;
name|ffetargetReal8
name|imaginary
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_ffetarget_complex_8_
name|ffetargetComplex8
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCHARACTER1
end_if

begin_struct
struct|struct
name|_ffetarget_char_1_
block|{
name|ffetargetCharacterSize
name|length
decl_stmt|;
name|unsigned
name|char
modifier|*
name|text
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_ffetarget_char_1_
name|ffetargetCharacter1
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|ffetargetCharacterUnit1
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCHARACTER2
end_if

begin_typedef
typedef|typedef
operator|?
name|ffetargetCharacter2
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
operator|?
name|ffetargetCharacterUnit2
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCHARACTER3
end_if

begin_typedef
typedef|typedef
operator|?
name|ffetargetCharacter3
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
operator|?
name|ffetargetCharacterUnit3
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCHARACTER4
end_if

begin_typedef
typedef|typedef
operator|?
name|ffetargetCharacter4
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
operator|?
name|ffetargetCharacterUnit4
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCHARACTER5
end_if

begin_typedef
typedef|typedef
operator|?
name|ffetargetCharacter5
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
operator|?
name|ffetargetCharacterUnit5
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCHARACTER6
end_if

begin_typedef
typedef|typedef
operator|?
name|ffetargetCharacter6
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
operator|?
name|ffetargetCharacterUnit6
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCHARACTER7
end_if

begin_typedef
typedef|typedef
operator|?
name|ffetargetCharacter7
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
operator|?
name|ffetargetCharacterUnit7
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCHARACTER8
end_if

begin_typedef
typedef|typedef
operator|?
name|ffetargetCharacter8
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
operator|?
name|ffetargetCharacterUnit8
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|int
name|ffetargetTypeless
typedef|;
end_typedef

begin_struct
struct|struct
name|_ffetarget_hollerith_
block|{
name|ffetargetHollerithSize
name|length
decl_stmt|;
name|unsigned
name|char
modifier|*
name|text
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_ffetarget_hollerith_
name|ffetargetHollerith
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ffetargetCharacter1
name|ffetargetCharacterDefault
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ffetargetComplex1
name|ffetargetComplexDefault
typedef|;
end_typedef

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEXDOUBLE
end_if

begin_typedef
typedef|typedef
name|ffetargetComplex2
name|ffetargetComplexDouble
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEXQUAD
end_if

begin_typedef
typedef|typedef
name|ffetargetComplex3
name|ffetargetComplexQuad
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|ffetargetInteger1
name|ffetargetIntegerDefault
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetIntegerDefault_f
value|ffetargetInteger1_f
end_define

begin_typedef
typedef|typedef
name|ffetargetLogical1
name|ffetargetLogicalDefault
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetLogicalDefault_f
value|ffetargetLogical1_f
end_define

begin_typedef
typedef|typedef
name|ffetargetReal1
name|ffetargetRealDefault
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetRealDefault_f
value|ffetargetReal1_f
end_define

begin_typedef
typedef|typedef
name|ffetargetReal2
name|ffetargetRealDouble
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetRealDouble_f
value|ffetargetReal2_f
end_define

begin_if
if|#
directive|if
name|FFETARGET_okREALQUAD
end_if

begin_typedef
typedef|typedef
name|ffetargetReal3
name|ffetargetRealQuad
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffetargetRealQuad_f
value|ffetargetReal3_f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"bad.h"
end_include

begin_include
include|#
directive|include
file|"info.h"
end_include

begin_include
include|#
directive|include
file|"lex.h"
end_include

begin_include
include|#
directive|include
file|"malloc.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ffetarget_string_
index|[
literal|40
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temp for ascii-to-double (atof). */
end_comment

begin_decl_stmt
specifier|extern
name|HOST_WIDE_INT
name|ffetarget_long_val_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HOST_WIDE_INT
name|ffetarget_long_junk_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|void
name|ffetarget_aggregate_info
parameter_list|(
name|ffeinfoBasictype
modifier|*
name|ebt
parameter_list|,
name|ffeinfoKindtype
modifier|*
name|ekt
parameter_list|,
name|ffetargetAlign
modifier|*
name|units
parameter_list|,
name|ffeinfoBasictype
name|abt
parameter_list|,
name|ffeinfoKindtype
name|akt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffetargetAlign
name|ffetarget_align
parameter_list|(
name|ffetargetAlign
modifier|*
name|updated_alignment
parameter_list|,
name|ffetargetAlign
modifier|*
name|updated_modulo
parameter_list|,
name|ffetargetOffset
name|offset
parameter_list|,
name|ffetargetAlign
name|alignment
parameter_list|,
name|ffetargetAlign
name|modulo
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFETARGET_okCHARACTER1
end_if

begin_function_decl
name|bool
name|ffetarget_character1
parameter_list|(
name|ffetargetCharacter1
modifier|*
name|val
parameter_list|,
name|ffelexToken
name|character
parameter_list|,
name|mallocPool
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ffetarget_cmp_character1
parameter_list|(
name|ffetargetCharacter1
name|l
parameter_list|,
name|ffetargetCharacter1
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_concatenate_character1
parameter_list|(
name|ffetargetCharacter1
modifier|*
name|res
parameter_list|,
name|ffetargetCharacter1
name|l
parameter_list|,
name|ffetargetCharacter1
name|r
parameter_list|,
name|mallocPool
name|pool
parameter_list|,
name|ffetargetCharacterSize
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_convert_character1_character1
parameter_list|(
name|ffetargetCharacter1
modifier|*
name|res
parameter_list|,
name|ffetargetCharacterSize
name|res_size
parameter_list|,
name|ffetargetCharacter1
name|l
parameter_list|,
name|mallocPool
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_convert_character1_hollerith
parameter_list|(
name|ffetargetCharacter1
modifier|*
name|res
parameter_list|,
name|ffetargetCharacterSize
name|res_size
parameter_list|,
name|ffetargetHollerith
name|l
parameter_list|,
name|mallocPool
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_convert_character1_integer4
parameter_list|(
name|ffetargetCharacter1
modifier|*
name|res
parameter_list|,
name|ffetargetCharacterSize
name|res_size
parameter_list|,
name|ffetargetInteger4
name|l
parameter_list|,
name|mallocPool
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_convert_character1_logical4
parameter_list|(
name|ffetargetCharacter1
modifier|*
name|res
parameter_list|,
name|ffetargetCharacterSize
name|res_size
parameter_list|,
name|ffetargetLogical4
name|l
parameter_list|,
name|mallocPool
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_convert_character1_typeless
parameter_list|(
name|ffetargetCharacter1
modifier|*
name|res
parameter_list|,
name|ffetargetCharacterSize
name|res_size
parameter_list|,
name|ffetargetTypeless
name|l
parameter_list|,
name|mallocPool
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_eq_character1
parameter_list|(
name|bool
modifier|*
name|res
parameter_list|,
name|ffetargetCharacter1
name|l
parameter_list|,
name|ffetargetCharacter1
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_le_character1
parameter_list|(
name|bool
modifier|*
name|res
parameter_list|,
name|ffetargetCharacter1
name|l
parameter_list|,
name|ffetargetCharacter1
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_ge_character1
parameter_list|(
name|bool
modifier|*
name|res
parameter_list|,
name|ffetargetCharacter1
name|l
parameter_list|,
name|ffetargetCharacter1
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_gt_character1
parameter_list|(
name|bool
modifier|*
name|res
parameter_list|,
name|ffetargetCharacter1
name|l
parameter_list|,
name|ffetargetCharacter1
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_lt_character1
parameter_list|(
name|bool
modifier|*
name|res
parameter_list|,
name|ffetargetCharacter1
name|l
parameter_list|,
name|ffetargetCharacter1
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_ne_character1
parameter_list|(
name|bool
modifier|*
name|res
parameter_list|,
name|ffetargetCharacter1
name|l
parameter_list|,
name|ffetargetCharacter1
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_substr_character1
parameter_list|(
name|ffetargetCharacter1
modifier|*
name|res
parameter_list|,
name|ffetargetCharacter1
name|l
parameter_list|,
name|ffetargetCharacterSize
name|first
parameter_list|,
name|ffetargetCharacterSize
name|last
parameter_list|,
name|mallocPool
name|pool
parameter_list|,
name|ffetargetCharacterSize
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|ffetarget_cmp_hollerith
parameter_list|(
name|ffetargetHollerith
name|l
parameter_list|,
name|ffetargetHollerith
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffetarget_hollerith
parameter_list|(
name|ffetargetHollerith
modifier|*
name|val
parameter_list|,
name|ffelexToken
name|hollerith
parameter_list|,
name|mallocPool
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ffetarget_cmp_typeless
parameter_list|(
name|ffetargetTypeless
name|l
parameter_list|,
name|ffetargetTypeless
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_convert_any_character1_
parameter_list|(
name|char
modifier|*
name|res
parameter_list|,
name|size_t
name|size
parameter_list|,
name|ffetargetCharacter1
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_convert_any_hollerith_
parameter_list|(
name|char
modifier|*
name|res
parameter_list|,
name|size_t
name|size
parameter_list|,
name|ffetargetHollerith
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_convert_any_typeless_
parameter_list|(
name|char
modifier|*
name|res
parameter_list|,
name|size_t
name|size
parameter_list|,
name|ffetargetTypeless
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX1
end_if

begin_function_decl
name|ffebad
name|ffetarget_divide_complex1
parameter_list|(
name|ffetargetComplex1
modifier|*
name|res
parameter_list|,
name|ffetargetComplex1
name|l
parameter_list|,
name|ffetargetComplex1
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX2
end_if

begin_function_decl
name|ffebad
name|ffetarget_divide_complex2
parameter_list|(
name|ffetargetComplex2
modifier|*
name|res
parameter_list|,
name|ffetargetComplex2
name|l
parameter_list|,
name|ffetargetComplex2
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX3
end_if

begin_function_decl
name|ffebad
name|ffetarget_divide_complex3
parameter_list|(
name|ffetargetComplex3
modifier|*
name|res
parameter_list|,
name|ffetargetComplex3
name|l
parameter_list|,
name|ffetargetComplex3
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX4
end_if

begin_function_decl
name|ffebad
name|ffetarget_divide_complex4
parameter_list|(
name|ffetargetComplex4
modifier|*
name|res
parameter_list|,
name|ffetargetComplex4
name|l
parameter_list|,
name|ffetargetComplex4
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX5
end_if

begin_function_decl
name|ffebad
name|ffetarget_divide_complex5
parameter_list|(
name|ffetargetComplex5
modifier|*
name|res
parameter_list|,
name|ffetargetComplex5
name|l
parameter_list|,
name|ffetargetComplex5
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX6
end_if

begin_function_decl
name|ffebad
name|ffetarget_divide_complex6
parameter_list|(
name|ffetargetComplex6
modifier|*
name|res
parameter_list|,
name|ffetargetComplex6
name|l
parameter_list|,
name|ffetargetComplex6
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX7
end_if

begin_function_decl
name|ffebad
name|ffetarget_divide_complex7
parameter_list|(
name|ffetargetComplex7
modifier|*
name|res
parameter_list|,
name|ffetargetComplex7
name|l
parameter_list|,
name|ffetargetComplex7
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX8
end_if

begin_function_decl
name|ffebad
name|ffetarget_divide_complex8
parameter_list|(
name|ffetargetComplex8
modifier|*
name|res
parameter_list|,
name|ffetargetComplex8
name|l
parameter_list|,
name|ffetargetComplex8
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER1
end_if

begin_function_decl
name|bool
name|ffetarget_integer1
parameter_list|(
name|ffetargetInteger1
modifier|*
name|val
parameter_list|,
name|ffelexToken
name|integer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER2
end_if

begin_function_decl
name|bool
name|ffetarget_integer2
parameter_list|(
name|ffetargetInteger2
modifier|*
name|val
parameter_list|,
name|ffelexToken
name|integer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER3
end_if

begin_function_decl
name|bool
name|ffetarget_integer3
parameter_list|(
name|ffetargetInteger3
modifier|*
name|val
parameter_list|,
name|ffelexToken
name|integer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER4
end_if

begin_function_decl
name|bool
name|ffetarget_integer4
parameter_list|(
name|ffetargetInteger4
modifier|*
name|val
parameter_list|,
name|ffelexToken
name|integer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER5
end_if

begin_function_decl
name|bool
name|ffetarget_integer5
parameter_list|(
name|ffetargetInteger5
modifier|*
name|val
parameter_list|,
name|ffelexToken
name|integer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER6
end_if

begin_function_decl
name|bool
name|ffetarget_integer6
parameter_list|(
name|ffetargetInteger6
modifier|*
name|val
parameter_list|,
name|ffelexToken
name|integer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER7
end_if

begin_function_decl
name|bool
name|ffetarget_integer7
parameter_list|(
name|ffetargetInteger7
modifier|*
name|val
parameter_list|,
name|ffelexToken
name|integer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER8
end_if

begin_function_decl
name|bool
name|ffetarget_integer8
parameter_list|(
name|ffetargetInteger8
modifier|*
name|val
parameter_list|,
name|ffelexToken
name|integer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|bool
name|ffetarget_integerbinary
parameter_list|(
name|ffetargetIntegerDefault
modifier|*
name|val
parameter_list|,
name|ffelexToken
name|integer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffetarget_integerhex
parameter_list|(
name|ffetargetIntegerDefault
modifier|*
name|val
parameter_list|,
name|ffelexToken
name|integer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffetarget_integeroctal
parameter_list|(
name|ffetargetIntegerDefault
modifier|*
name|val
parameter_list|,
name|ffelexToken
name|integer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffetarget_integer_bad_magical
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffetarget_integer_bad_magical_binary
parameter_list|(
name|ffelexToken
name|integer
parameter_list|,
name|ffelexToken
name|minus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffetarget_integer_bad_magical_precedence
parameter_list|(
name|ffelexToken
name|integer
parameter_list|,
name|ffelexToken
name|uminus
parameter_list|,
name|ffelexToken
name|higher_op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffetarget_integer_bad_magical_precedence_binary
parameter_list|(
name|ffelexToken
name|integer
parameter_list|,
name|ffelexToken
name|minus
parameter_list|,
name|ffelexToken
name|higher_op
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFETARGET_okCHARACTER1
end_if

begin_function_decl
name|bool
name|ffetarget_iszero_character1
parameter_list|(
name|ffetargetCharacter1
name|constant
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|bool
name|ffetarget_iszero_hollerith
parameter_list|(
name|ffetargetHollerith
name|constant
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffetarget_layout
parameter_list|(
specifier|const
name|char
modifier|*
name|error_text
parameter_list|,
name|ffetargetAlign
modifier|*
name|alignment
parameter_list|,
name|ffetargetAlign
modifier|*
name|modulo
parameter_list|,
name|ffetargetOffset
modifier|*
name|size
parameter_list|,
name|ffeinfoBasictype
name|bt
parameter_list|,
name|ffeinfoKindtype
name|kt
parameter_list|,
name|ffetargetCharacterSize
name|charsize
parameter_list|,
name|ffetargetIntegerDefault
name|num_elements
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX1
end_if

begin_function_decl
name|ffebad
name|ffetarget_multiply_complex1
parameter_list|(
name|ffetargetComplex1
modifier|*
name|res
parameter_list|,
name|ffetargetComplex1
name|l
parameter_list|,
name|ffetargetComplex1
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX2
end_if

begin_function_decl
name|ffebad
name|ffetarget_multiply_complex2
parameter_list|(
name|ffetargetComplex2
modifier|*
name|res
parameter_list|,
name|ffetargetComplex2
name|l
parameter_list|,
name|ffetargetComplex2
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX3
end_if

begin_function_decl
name|ffebad
name|ffetarget_multiply_complex3
parameter_list|(
name|ffetargetComplex3
modifier|*
name|res
parameter_list|,
name|ffetargetComplex3
name|l
parameter_list|,
name|ffetargetComplex3
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX4
end_if

begin_function_decl
name|ffebad
name|ffetarget_multiply_complex4
parameter_list|(
name|ffetargetComplex4
modifier|*
name|res
parameter_list|,
name|ffetargetComplex4
name|l
parameter_list|,
name|ffetargetComplex4
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX5
end_if

begin_function_decl
name|ffebad
name|ffetarget_multiply_complex5
parameter_list|(
name|ffetargetComplex5
modifier|*
name|res
parameter_list|,
name|ffetargetComplex5
name|l
parameter_list|,
name|ffetargetComplex5
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX6
end_if

begin_function_decl
name|ffebad
name|ffetarget_multiply_complex6
parameter_list|(
name|ffetargetComplex6
modifier|*
name|res
parameter_list|,
name|ffetargetComplex6
name|l
parameter_list|,
name|ffetargetComplex6
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX7
end_if

begin_function_decl
name|ffebad
name|ffetarget_multiply_complex7
parameter_list|(
name|ffetargetComplex7
modifier|*
name|res
parameter_list|,
name|ffetargetComplex7
name|l
parameter_list|,
name|ffetargetComplex7
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX8
end_if

begin_function_decl
name|ffebad
name|ffetarget_multiply_complex8
parameter_list|(
name|ffetargetComplex8
modifier|*
name|res
parameter_list|,
name|ffetargetComplex8
name|l
parameter_list|,
name|ffetargetComplex8
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ffebad
name|ffetarget_power_complexdefault_integerdefault
parameter_list|(
name|ffetargetComplexDefault
modifier|*
name|res
parameter_list|,
name|ffetargetComplexDefault
name|l
parameter_list|,
name|ffetargetIntegerDefault
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEXDOUBLE
end_if

begin_function_decl
name|ffebad
name|ffetarget_power_complexdouble_integerdefault
parameter_list|(
name|ffetargetComplexDouble
modifier|*
name|res
parameter_list|,
name|ffetargetComplexDouble
name|l
parameter_list|,
name|ffetargetIntegerDefault
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ffebad
name|ffetarget_power_integerdefault_integerdefault
parameter_list|(
name|ffetargetIntegerDefault
modifier|*
name|res
parameter_list|,
name|ffetargetIntegerDefault
name|l
parameter_list|,
name|ffetargetIntegerDefault
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_power_realdefault_integerdefault
parameter_list|(
name|ffetargetRealDefault
modifier|*
name|res
parameter_list|,
name|ffetargetRealDefault
name|l
parameter_list|,
name|ffetargetIntegerDefault
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebad
name|ffetarget_power_realdouble_integerdefault
parameter_list|(
name|ffetargetRealDouble
modifier|*
name|res
parameter_list|,
name|ffetargetRealDouble
name|l
parameter_list|,
name|ffetargetIntegerDefault
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffetarget_print_binary
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|ffetargetTypeless
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffetarget_print_character1
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|ffetargetCharacter1
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffetarget_print_hollerith
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|ffetargetHollerith
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffetarget_print_octal
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|ffetargetTypeless
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffetarget_print_hex
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|ffetargetTypeless
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFETARGET_okREAL1
end_if

begin_function_decl
name|bool
name|ffetarget_real1
parameter_list|(
name|ffetargetReal1
modifier|*
name|value
parameter_list|,
name|ffelexToken
name|integer
parameter_list|,
name|ffelexToken
name|decimal
parameter_list|,
name|ffelexToken
name|fraction
parameter_list|,
name|ffelexToken
name|exponent
parameter_list|,
name|ffelexToken
name|exponent_sign
parameter_list|,
name|ffelexToken
name|exponent_digits
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL2
end_if

begin_function_decl
name|bool
name|ffetarget_real2
parameter_list|(
name|ffetargetReal2
modifier|*
name|value
parameter_list|,
name|ffelexToken
name|integer
parameter_list|,
name|ffelexToken
name|decimal
parameter_list|,
name|ffelexToken
name|fraction
parameter_list|,
name|ffelexToken
name|exponent
parameter_list|,
name|ffelexToken
name|exponent_sign
parameter_list|,
name|ffelexToken
name|exponent_digits
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL3
end_if

begin_function_decl
name|bool
name|ffetarget_real3
parameter_list|(
name|ffetargetReal3
modifier|*
name|value
parameter_list|,
name|ffelexToken
name|integer
parameter_list|,
name|ffelexToken
name|decimal
parameter_list|,
name|ffelexToken
name|fraction
parameter_list|,
name|ffelexToken
name|exponent
parameter_list|,
name|ffelexToken
name|exponent_sign
parameter_list|,
name|ffelexToken
name|exponent_digits
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL4
end_if

begin_function_decl
name|bool
name|ffetarget_real4
parameter_list|(
name|ffetargetReal4
modifier|*
name|value
parameter_list|,
name|ffelexToken
name|integer
parameter_list|,
name|ffelexToken
name|decimal
parameter_list|,
name|ffelexToken
name|fraction
parameter_list|,
name|ffelexToken
name|exponent
parameter_list|,
name|ffelexToken
name|exponent_sign
parameter_list|,
name|ffelexToken
name|exponent_digits
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL5
end_if

begin_function_decl
name|bool
name|ffetarget_real5
parameter_list|(
name|ffetargetReal5
modifier|*
name|value
parameter_list|,
name|ffelexToken
name|integer
parameter_list|,
name|ffelexToken
name|decimal
parameter_list|,
name|ffelexToken
name|fraction
parameter_list|,
name|ffelexToken
name|exponent
parameter_list|,
name|ffelexToken
name|exponent_sign
parameter_list|,
name|ffelexToken
name|exponent_digits
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL6
end_if

begin_function_decl
name|bool
name|ffetarget_real6
parameter_list|(
name|ffetargetReal6
modifier|*
name|value
parameter_list|,
name|ffelexToken
name|integer
parameter_list|,
name|ffelexToken
name|decimal
parameter_list|,
name|ffelexToken
name|fraction
parameter_list|,
name|ffelexToken
name|exponent
parameter_list|,
name|ffelexToken
name|exponent_sign
parameter_list|,
name|ffelexToken
name|exponent_digits
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL7
end_if

begin_function_decl
name|bool
name|ffetarget_real7
parameter_list|(
name|ffetargetReal7
modifier|*
name|value
parameter_list|,
name|ffelexToken
name|integer
parameter_list|,
name|ffelexToken
name|decimal
parameter_list|,
name|ffelexToken
name|fraction
parameter_list|,
name|ffelexToken
name|exponent
parameter_list|,
name|ffelexToken
name|exponent_sign
parameter_list|,
name|ffelexToken
name|exponent_digits
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL8
end_if

begin_function_decl
name|bool
name|ffetarget_real8
parameter_list|(
name|ffetargetReal8
modifier|*
name|value
parameter_list|,
name|ffelexToken
name|integer
parameter_list|,
name|ffelexToken
name|decimal
parameter_list|,
name|ffelexToken
name|fraction
parameter_list|,
name|ffelexToken
name|exponent
parameter_list|,
name|ffelexToken
name|exponent_sign
parameter_list|,
name|ffelexToken
name|exponent_digits
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|bool
name|ffetarget_typeless_binary
parameter_list|(
name|ffetargetTypeless
modifier|*
name|value
parameter_list|,
name|ffelexToken
name|token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffetarget_typeless_octal
parameter_list|(
name|ffetargetTypeless
modifier|*
name|value
parameter_list|,
name|ffelexToken
name|token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffetarget_typeless_hex
parameter_list|(
name|ffetargetTypeless
modifier|*
name|value
parameter_list|,
name|ffelexToken
name|token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffetarget_verify_character1
parameter_list|(
name|mallocPool
name|pool
parameter_list|,
name|ffetargetCharacter1
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ffetarget_num_digits_
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ffetarget_memcpy_
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|FFETARGET_REAL_VALUE_FROM_INT_
parameter_list|(
name|resr
parameter_list|,
name|lf
parameter_list|,
name|kt
parameter_list|)
define|\
value|REAL_VALUE_FROM_INT (resr, (long) lf, (long) ((lf< 0) ? -1 : 0),	\ 		       ((kt == 1) ? SFmode : DFmode))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_add_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, li, rr, ri, resr, resi; \      lr = ffetarget_cvt_r1_to_rv_ ((l).real); \      li = ffetarget_cvt_r1_to_rv_ ((l).imaginary); \      rr = ffetarget_cvt_r1_to_rv_ ((r).real); \      ri = ffetarget_cvt_r1_to_rv_ ((r).imaginary); \      REAL_ARITHMETIC (resr, PLUS_EXPR, lr, rr); \      REAL_ARITHMETIC (resi, PLUS_EXPR, li, ri); \      ffetarget_cvt_rv_to_r1_ (resr, (res)->real); \      ffetarget_cvt_rv_to_r1_ (resi, (res)->imaginary); \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_add_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, li, rr, ri, resr, resi; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).real.v[0])); \      li = ffetarget_cvt_r2_to_rv_ (&((l).imaginary.v[0])); \      rr = ffetarget_cvt_r2_to_rv_ (&((r).real.v[0])); \      ri = ffetarget_cvt_r2_to_rv_ (&((r).imaginary.v[0])); \      REAL_ARITHMETIC (resr, PLUS_EXPR, lr, rr); \      REAL_ARITHMETIC (resi, PLUS_EXPR, li, ri); \      ffetarget_cvt_rv_to_r2_ (resr,&((res)->real.v[0])); \      ffetarget_cvt_rv_to_r2_ (resi,&((res)->imaginary.v[0])); \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_add_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|((res)->real = (l).real + (r).real, \    (res)->imaginary = (l).imaginary + (r).imaginary, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_add_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|((res)->real = (l).real + (r).real, \    (res)->imaginary = (l).imaginary + (r).imaginary, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_add_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) + (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_add_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) + (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_add_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) + (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_add_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) + (r), FFEBAD)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_add_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr, resr; \      lr = ffetarget_cvt_r1_to_rv_ ((l)); \      rr = ffetarget_cvt_r1_to_rv_ ((r)); \      REAL_ARITHMETIC (resr, PLUS_EXPR, lr, rr); \      ffetarget_cvt_rv_to_r1_ (resr, *(res)); \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_add_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr, resr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).v[0])); \      rr = ffetarget_cvt_r2_to_rv_ (&((r).v[0])); \      REAL_ARITHMETIC (resr, PLUS_EXPR, lr, rr); \      ffetarget_cvt_rv_to_r2_ (resr,&((res)->v[0])); \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_add_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) + (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_add_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) + (r), FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_aggregate_ptr_memcpy
parameter_list|(
name|dbt
parameter_list|,
name|dkt
parameter_list|,
name|sbt
parameter_list|,
name|skt
parameter_list|)
define|\
value|((ffetargetCopyfunc) ffetarget_memcpy_)
end_define

begin_define
define|#
directive|define
name|ffetarget_and_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l)& (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_and_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l)& (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_and_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l)& (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_and_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l)& (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_and_logical1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l)&& (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_and_logical2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l)&& (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_and_logical3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l)&& (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_and_logical4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l)&& (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_binarymil
parameter_list|(
name|v
parameter_list|,
name|t
parameter_list|)
value|ffetarget_typeless_binary (v, t)
end_define

begin_define
define|#
directive|define
name|ffetarget_binaryvxt
parameter_list|(
name|v
parameter_list|,
name|t
parameter_list|)
value|ffetarget_typeless_binary (v, t)
end_define

begin_define
define|#
directive|define
name|ffetarget_cmp_integer1
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|((l) == (r) ? 0 : ((l)< (r) ? -1 : 1))
end_define

begin_define
define|#
directive|define
name|ffetarget_cmp_integer2
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|((l) == (r) ? 0 : ((l)< (r) ? -1 : 1))
end_define

begin_define
define|#
directive|define
name|ffetarget_cmp_integer3
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|((l) == (r) ? 0 : ((l)< (r) ? -1 : 1))
end_define

begin_define
define|#
directive|define
name|ffetarget_cmp_integer4
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|((l) == (r) ? 0 : ((l)< (r) ? -1 : 1))
end_define

begin_define
define|#
directive|define
name|ffetarget_cmp_logical1
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|((l) == (r) ? 0 : ((l)< (r) ? -1 : 1))
end_define

begin_define
define|#
directive|define
name|ffetarget_cmp_logical2
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|((l) == (r) ? 0 : ((l)< (r) ? -1 : 1))
end_define

begin_define
define|#
directive|define
name|ffetarget_cmp_logical3
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|((l) == (r) ? 0 : ((l)< (r) ? -1 : 1))
end_define

begin_define
define|#
directive|define
name|ffetarget_cmp_logical4
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|((l) == (r) ? 0 : ((l)< (r) ? -1 : 1))
end_define

begin_define
define|#
directive|define
name|ffetarget_cmp_real1
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|memcmp (&(l),&(r), sizeof(l))
end_define

begin_define
define|#
directive|define
name|ffetarget_cmp_real2
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|memcmp (&(l),&(r), sizeof(l))
end_define

begin_define
define|#
directive|define
name|ffetarget_cmp_real3
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|memcmp (&(l),&(r), sizeof(l))
end_define

begin_define
define|#
directive|define
name|ffetarget_cmp_typeless
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|memcmp (&(l),&(r), sizeof ((l)))
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_character1_integer1
parameter_list|(
name|res
parameter_list|,
name|res_size
parameter_list|,
name|l
parameter_list|,
name|pool
parameter_list|)
define|\
value|ffetarget_convert_character1_integer4(res,res_size,(ffetargetInteger4)l,pool)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_character1_integer2
parameter_list|(
name|res
parameter_list|,
name|res_size
parameter_list|,
name|l
parameter_list|,
name|pool
parameter_list|)
define|\
value|ffetarget_convert_character1_integer4(res,res_size,(ffetargetInteger4)l,pool)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_character1_integer3
parameter_list|(
name|res
parameter_list|,
name|res_size
parameter_list|,
name|l
parameter_list|,
name|pool
parameter_list|)
define|\
value|ffetarget_convert_character1_integer4(res,res_size,(ffetargetInteger4)l,pool)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_character1_logical1
parameter_list|(
name|res
parameter_list|,
name|res_size
parameter_list|,
name|l
parameter_list|,
name|pool
parameter_list|)
define|\
value|ffetarget_convert_character1_logical4(res,res_size,(ffetargetLogical4)l,pool)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_character1_logical2
parameter_list|(
name|res
parameter_list|,
name|res_size
parameter_list|,
name|l
parameter_list|,
name|pool
parameter_list|)
define|\
value|ffetarget_convert_character1_logical4(res,res_size,(ffetargetLogical4)l,pool)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_character1_logical3
parameter_list|(
name|res
parameter_list|,
name|res_size
parameter_list|,
name|l
parameter_list|,
name|pool
parameter_list|)
define|\
value|ffetarget_convert_character1_logical4(res,res_size,(ffetargetLogical4)l,pool)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_complex1_character1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_character1_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_complex1_hollerith
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_hollerith_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_complex1_typeless
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_typeless_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_complex1_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, li; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).real.v[0])); \      li = ffetarget_cvt_r2_to_rv_ (&((l).imaginary.v[0])); \      ffetarget_cvt_rv_to_r1_ (lr, (res)->real); \      ffetarget_cvt_rv_to_r1_ (li, (res)->imaginary), \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_complex1_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|((res)->real = (l).real, (res)->imaginary = (l).imaginary, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_complex1_integer
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE resi, resr; \      ffetargetInteger1 lf = (l); \      FFETARGET_REAL_VALUE_FROM_INT_ (resr, lf, 1); \      resi = dconst0; \      ffetarget_cvt_rv_to_r1_ (resr, (res)->real); \      ffetarget_cvt_rv_to_r1_ (resi, (res)->imaginary); \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_complex1_integer
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|((res)->real = (l), (res)->imaginary = 0, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_convert_complex1_integer1
value|ffetarget_convert_complex1_integer
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_complex1_integer2
value|ffetarget_convert_complex1_integer
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_complex1_integer3
value|ffetarget_convert_complex1_integer
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_complex1_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|FFEBAD_NOCANDO
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_complex1_integer4
value|ffetarget_convert_complex1_integer
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_complex1_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|((res)->real = (l), \    ffetarget_cvt_rv_to_r1_ (dconst0, (res)->imaginary), \    FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_complex1_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).v[0])); \      ffetarget_cvt_rv_to_r1_ (lr, (res)->real); \      ffetarget_cvt_rv_to_r1_ (dconst0, (res)->imaginary), \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_complex1_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|((res)->real = (l), (res)->imaginary = 0, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_complex1_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|((res)->real = (l), (res)->imaginary = 0, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_convert_complex2_character1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_character1_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_complex2_hollerith
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_hollerith_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_complex2_typeless
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_typeless_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_complex2_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, li; \      lr = ffetarget_cvt_r1_to_rv_ ((l).real); \      li = ffetarget_cvt_r1_to_rv_ ((l).imaginary); \      ffetarget_cvt_rv_to_r2_ (lr,&((res)->real.v[0])); \      ffetarget_cvt_rv_to_r2_ (li,&((res)->imaginary.v[0])), \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_complex2_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|((res)->real = (l).real, (res)->imaginary = (l).imaginary, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_complex2_integer
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE resi, resr; \      ffetargetInteger1 lf = (l); \      FFETARGET_REAL_VALUE_FROM_INT_ (resr, lf, 2); \      resi = dconst0; \      ffetarget_cvt_rv_to_r2_ (resr,&((res)->real.v[0])); \      ffetarget_cvt_rv_to_r2_ (resi,&((res)->imaginary.v[0])); \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_complex2_integer
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|((res)->real = (l), (res)->imaginary = 0, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_convert_complex2_integer1
value|ffetarget_convert_complex2_integer
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_complex2_integer2
value|ffetarget_convert_complex2_integer
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_complex2_integer3
value|ffetarget_convert_complex2_integer
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_complex2_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|FFEBAD_NOCANDO
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_complex2_integer4
value|ffetarget_convert_complex2_integer
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_complex2_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr; \      lr = ffetarget_cvt_r1_to_rv_ (l); \      ffetarget_cvt_rv_to_r2_ (lr,&((res)->real.v[0])); \      ffetarget_cvt_rv_to_r2_ (dconst0,&((res)->imaginary.v[0])), \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_complex2_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|((res)->real = (l), \    ffetarget_cvt_rv_to_r2_ (dconst0,&((res)->imaginary.v[0])), \    FFEBAD)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_complex2_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|((res)->real = (l), (res)->imaginary = 0, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_complex2_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|((res)->real = (l), (res)->imaginary = 0, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_convert_integer2_character1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_character1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer2_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_complex1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer2_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_complex2(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer2_hollerith
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_hollerith(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer2_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer2_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer2_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer2_logical1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_logical1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer2_logical2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer2_logical1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer2_logical3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer2_logical1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer2_logical4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer2_logical1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer2_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_real1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer2_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_real2(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer2_typeless
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_typeless(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer3_character1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_character1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer3_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_complex1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer3_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_complex2(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer3_hollerith
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_hollerith(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer3_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer3_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer3_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer3_logical1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_logical1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer3_logical2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer3_logical1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer3_logical3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer3_logical1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer3_logical4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer3_logical1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer3_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_real1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer3_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_real2(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer3_typeless
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_typeless(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_character1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_character1(res,l)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|FFEBAD_NOCANDO
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|FFEBAD_NOCANDO
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_complex1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_complex2(res,l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_hollerith
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_hollerith(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_logical1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_logical1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_logical2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_logical1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_logical3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_logical1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_logical4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_logical1(res,l)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|FFEBAD_NOCANDO
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|FFEBAD_NOCANDO
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_real1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_real2(res,l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_convert_integer4_typeless
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_integer1_typeless(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical1_character1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_character1_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical1_hollerith
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_hollerith_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical1_typeless
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_typeless_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical1_logical2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical1_logical3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical1_logical4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical1_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical1_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical1_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical1_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical2_character1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_character1_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical2_hollerith
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_hollerith_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical2_typeless
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_typeless_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical2_logical1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical2_logical3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical2_logical4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical2_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical2_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical2_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical2_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical3_character1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_character1_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical3_hollerith
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_hollerith_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical3_typeless
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_typeless_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical3_logical1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical3_logical2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical3_logical4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical3_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical3_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical3_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical3_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical4_character1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_character1_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical4_hollerith
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_hollerith_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical4_typeless
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_typeless_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical4_logical1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical4_logical2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical4_logical3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical4_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical4_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical4_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_logical4_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_character1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_character1_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_hollerith
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_hollerith_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_typeless
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_typeless_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_logical1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_logical2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_logical3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_logical4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr; \      lr = ffetarget_cvt_r1_to_rv_ (l); \      REAL_VALUE_TO_INT (&ffetarget_long_val_,&ffetarget_long_junk_, lr); \      *(res) = ffetarget_long_val_; \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).v[0])); \      REAL_VALUE_TO_INT (&ffetarget_long_val_,&ffetarget_long_junk_, lr); \      *(res) = ffetarget_long_val_; \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr; \      lr = ffetarget_cvt_r1_to_rv_ ((l).real); \      REAL_VALUE_TO_INT (&ffetarget_long_val_,&ffetarget_long_junk_, lr); \      *(res) = ffetarget_long_val_; \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).real.v[0])); \      REAL_VALUE_TO_INT (&ffetarget_long_val_,&ffetarget_long_junk_, lr); \      *(res) = ffetarget_long_val_; \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l).real, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_integer1_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l).real, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_convert_real1_character1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_character1_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_real1_hollerith
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_hollerith_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_real1_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_real1_integer1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_real1_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_real1_integer1(res,l)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_real1_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|FFEBAD_NOCANDO
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_real1_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_real1_integer1(res,l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_convert_real1_typeless
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_typeless_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_real1_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l).real, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_real1_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_real1_real2 ((res), (l).real)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_real1_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE resr; \      ffetargetInteger1 lf = (l); \      FFETARGET_REAL_VALUE_FROM_INT_ (resr, lf, 1); \      ffetarget_cvt_rv_to_r1_ (resr, *(res)); \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_real1_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_real1_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).v[0])); \      ffetarget_cvt_rv_to_r1_ (lr, *(res)); \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_real1_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_convert_real2_character1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_character1_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_real2_hollerith
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_hollerith_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_real2_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_real2_integer1(res,l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_real2_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_real2_integer1(res,l)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_real2_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|FFEBAD_NOCANDO
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_real2_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_real2_integer1(res,l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_convert_real2_typeless
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_any_typeless_ ((char *) (res), sizeof(*(res)), l)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_real2_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|ffetarget_convert_real2_real1 ((res), (l).real)
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_real2_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l).real, FFEBAD)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_real2_integer
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE resr; \      ffetargetInteger1 lf = (l); \      FFETARGET_REAL_VALUE_FROM_INT_ (resr, lf, 2); \      ffetarget_cvt_rv_to_r2_ (resr,&((res)->v[0])); \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_convert_real2_integer1
value|ffetarget_convert_real2_integer
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_real2_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_convert_real2_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr; \      lr = ffetarget_cvt_r1_to_rv_ ((l)); \      ffetarget_cvt_rv_to_r2_ (lr,&((res)->v[0])); \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_convert_real2_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_divide_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(((r) == 0) ? (*(res) = 0, FFEBAD_DIV_BY_ZERO)  \    : (*(res) = (l) / (r), FFEBAD))
end_define

begin_define
define|#
directive|define
name|ffetarget_divide_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|ffetarget_divide_integer1(res,l,r)
end_define

begin_define
define|#
directive|define
name|ffetarget_divide_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|ffetarget_divide_integer1(res,l,r)
end_define

begin_define
define|#
directive|define
name|ffetarget_divide_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|ffetarget_divide_integer1(res,l,r)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_divide_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr, resr; \      lr = ffetarget_cvt_r1_to_rv_ ((l)); \      rr = ffetarget_cvt_r1_to_rv_ ((r)); \      REAL_VALUES_EQUAL (rr, dconst0) \        ? ({ ffetarget_cvt_rv_to_r1_ (dconst0, *(res)); \ 	    FFEBAD_DIV_BY_ZERO; \ 	  }) \ 	 : ({ REAL_ARITHMETIC (resr, RDIV_EXPR, lr, rr); \ 	      ffetarget_cvt_rv_to_r1_ (resr, *(res)); \ 	      FFEBAD; \ 	    }); \ 	 })
end_define

begin_define
define|#
directive|define
name|ffetarget_divide_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr, resr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).v[0])); \      rr = ffetarget_cvt_r2_to_rv_ (&((r).v[0])); \      REAL_VALUES_EQUAL (rr, dconst0) \        ? ({ ffetarget_cvt_rv_to_r2_ (dconst0,&((res)->v[0])); \ 	    FFEBAD_DIV_BY_ZERO; \ 	  }) \ 	 : ({ REAL_ARITHMETIC (resr, RDIV_EXPR, lr, rr); \ 	      ffetarget_cvt_rv_to_r2_ (resr,&((res)->v[0])); \ 	      FFEBAD; \ 	    }); \ 	 })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_divide_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(((r) == 0) ? (*(res) = 0, FFEBAD_DIV_BY_ZERO)  \    : (*(res) = (l) / (r), FFEBAD))
end_define

begin_define
define|#
directive|define
name|ffetarget_divide_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(((r) == 0) ? (*(res) = 0, FFEBAD_DIV_BY_ZERO)  \    : (*(res) = (l) / (r), FFEBAD))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_eq_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, li, rr, ri; \      lr = ffetarget_cvt_r1_to_rv_ ((l).real); \      li = ffetarget_cvt_r1_to_rv_ ((l).imaginary); \      rr = ffetarget_cvt_r1_to_rv_ ((r).real); \      ri = ffetarget_cvt_r1_to_rv_ ((r).imaginary); \      *(res) = (REAL_VALUES_EQUAL (lr, rr)&& REAL_VALUES_EQUAL (li, ri)) \        ? TRUE : FALSE; \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_eq_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, li, rr, ri; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).real.v[0])); \      li = ffetarget_cvt_r2_to_rv_ (&((l).imaginary.v[0])); \      rr = ffetarget_cvt_r2_to_rv_ (&((r).real.v[0])); \      ri = ffetarget_cvt_r2_to_rv_ (&((r).imaginary.v[0])); \      *(res) = (REAL_VALUES_EQUAL (lr, rr)&& REAL_VALUES_EQUAL (li, ri)) \        ? TRUE : FALSE; \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_eq_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = (((l).real == (r).real)&& ((l).imaginary == (r).imaginary))  \    ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_eq_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = (((l).real == (r).real)&& ((l).imaginary == (r).imaginary))  \    ? TRUE : FALSE, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_eq_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l) == (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_eq_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l) == (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_eq_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l) == (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_eq_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l) == (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_eq_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr; \      lr = ffetarget_cvt_r1_to_rv_ ((l)); \      rr = ffetarget_cvt_r1_to_rv_ ((r)); \      *(res) = REAL_VALUES_EQUAL (lr, rr) ? TRUE : FALSE; \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_eq_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).v[0])); \      rr = ffetarget_cvt_r2_to_rv_ (&((r).v[0])); \      *(res) = REAL_VALUES_EQUAL (lr, rr) ? TRUE : FALSE; \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_eq_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l) == (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_eq_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l) == (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_eqv_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) ^ ~(r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_eqv_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) ^ ~(r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_eqv_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) ^ ~(r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_eqv_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) ^ ~(r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_eqv_logical1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) == (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_eqv_logical2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) == (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_eqv_logical3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) == (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_eqv_logical4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) == (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_ge_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)>= (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_ge_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)>= (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_ge_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)>= (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_ge_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)>= (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_ge_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr; \      lr = ffetarget_cvt_r1_to_rv_ ((l)); \      rr = ffetarget_cvt_r1_to_rv_ ((r)); \      *(res) = REAL_VALUES_LESS (lr, rr) ? FALSE : TRUE; \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_ge_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).v[0])); \      rr = ffetarget_cvt_r2_to_rv_ (&((r).v[0])); \      *(res) = REAL_VALUES_LESS (lr, rr) ? FALSE : TRUE; \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_ge_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)>= (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_ge_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)>= (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_gt_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)> (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_gt_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)> (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_gt_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)> (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_gt_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)> (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_gt_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr; \      lr = ffetarget_cvt_r1_to_rv_ ((l)); \      rr = ffetarget_cvt_r1_to_rv_ ((r)); \      *(res) = (REAL_VALUES_LESS (lr, rr) || REAL_VALUES_EQUAL (lr, rr)) \        ? FALSE : TRUE; \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_gt_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).v[0])); \      rr = ffetarget_cvt_r2_to_rv_ (&((r).v[0])); \      *(res) = (REAL_VALUES_LESS (lr, rr) || REAL_VALUES_EQUAL (lr, rr)) \        ? FALSE : TRUE; \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_gt_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)> (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_gt_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)> (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_hexxmil
parameter_list|(
name|v
parameter_list|,
name|t
parameter_list|)
value|ffetarget_typeless_hex (v, t)
end_define

begin_define
define|#
directive|define
name|ffetarget_hexxvxt
parameter_list|(
name|v
parameter_list|,
name|t
parameter_list|)
value|ffetarget_typeless_hex (v, t)
end_define

begin_define
define|#
directive|define
name|ffetarget_hexzmil
parameter_list|(
name|v
parameter_list|,
name|t
parameter_list|)
value|ffetarget_typeless_hex (v, t)
end_define

begin_define
define|#
directive|define
name|ffetarget_hexzvxt
parameter_list|(
name|v
parameter_list|,
name|t
parameter_list|)
value|ffetarget_typeless_hex (v, t)
end_define

begin_define
define|#
directive|define
name|ffetarget_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetarget_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetarget_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetarget_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetarget_init_4
parameter_list|()
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FFETARGET_32bit_longs
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_integerdefault_is_magical
parameter_list|(
name|i
parameter_list|)
define|\
value|(((unsigned long int) i) == FFETARGET_integerBIG_MAGICAL)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_integerdefault_is_magical
parameter_list|(
name|i
parameter_list|)
define|\
value|(((unsigned int) i) == FFETARGET_integerBIG_MAGICAL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_iszero_real1
parameter_list|(
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr; \      lr = ffetarget_cvt_r1_to_rv_ ((l)); \      REAL_VALUES_EQUAL (lr, dconst0); \    })
end_define

begin_define
define|#
directive|define
name|ffetarget_iszero_real2
parameter_list|(
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).v[0])); \      REAL_VALUES_EQUAL (lr, dconst0); \    })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_iszero_real1
parameter_list|(
name|l
parameter_list|)
value|((l) == 0.)
end_define

begin_define
define|#
directive|define
name|ffetarget_iszero_real2
parameter_list|(
name|l
parameter_list|)
value|((l) == 0.)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_iszero_typeless
parameter_list|(
name|l
parameter_list|)
value|((l) == 0)
end_define

begin_define
define|#
directive|define
name|ffetarget_logical1
parameter_list|(
name|v
parameter_list|,
name|truth
parameter_list|)
value|(*(v) = truth ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|ffetarget_le_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)<= (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_le_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)<= (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_le_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)<= (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_le_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)<= (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_le_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr; \      lr = ffetarget_cvt_r1_to_rv_ ((l)); \      rr = ffetarget_cvt_r1_to_rv_ ((r)); \      *(res) = (REAL_VALUES_LESS (lr, rr) || REAL_VALUES_EQUAL (lr, rr)) \        ? TRUE : FALSE; \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_le_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).v[0])); \      rr = ffetarget_cvt_r2_to_rv_ (&((r).v[0])); \      *(res) = (REAL_VALUES_LESS (lr, rr) || REAL_VALUES_EQUAL (lr, rr)) \        ? TRUE : FALSE; \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_le_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)<= (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_le_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)<= (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_lt_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)< (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_lt_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)< (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_lt_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)< (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_lt_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)< (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_lt_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr; \      lr = ffetarget_cvt_r1_to_rv_ ((l)); \      rr = ffetarget_cvt_r1_to_rv_ ((r)); \      *(res) = REAL_VALUES_LESS (lr, rr) ? TRUE : FALSE; \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_lt_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).v[0])); \      rr = ffetarget_cvt_r2_to_rv_ (&((r).v[0])); \      *(res) = REAL_VALUES_LESS (lr, rr) ? TRUE : FALSE; \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_lt_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)< (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_lt_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l)< (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_length_character1
parameter_list|(
name|c
parameter_list|)
value|((c).length)
end_define

begin_define
define|#
directive|define
name|ffetarget_length_characterdefault
value|ffetarget_length_character1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_make_real1
parameter_list|(
name|res
parameter_list|,
name|lr
parameter_list|)
define|\
value|ffetarget_cvt_rv_to_r1_ ((lr), *(res))
end_define

begin_define
define|#
directive|define
name|ffetarget_make_real2
parameter_list|(
name|res
parameter_list|,
name|lr
parameter_list|)
define|\
value|ffetarget_cvt_rv_to_r2_ ((lr),&((res)->v[0]))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_make_real1
parameter_list|(
name|res
parameter_list|,
name|lr
parameter_list|)
value|(*(res) = (lr))
end_define

begin_define
define|#
directive|define
name|ffetarget_make_real2
parameter_list|(
name|res
parameter_list|,
name|lr
parameter_list|)
value|(*(res) = (lr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_multiply_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) * (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_multiply_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) * (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_multiply_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) * (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_multiply_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) * (r), FFEBAD)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_multiply_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr, resr; \      lr = ffetarget_cvt_r1_to_rv_ ((l)); \      rr = ffetarget_cvt_r1_to_rv_ ((r)); \      REAL_ARITHMETIC (resr, MULT_EXPR, lr, rr); \      ffetarget_cvt_rv_to_r1_ (resr, *(res)); \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_multiply_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr, resr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).v[0])); \      rr = ffetarget_cvt_r2_to_rv_ (&((r).v[0])); \      REAL_ARITHMETIC (resr, MULT_EXPR, lr, rr); \      ffetarget_cvt_rv_to_r2_ (resr,&((res)->v[0])); \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_multiply_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) * (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_multiply_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) * (r), FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_ne_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, li, rr, ri; \      lr = ffetarget_cvt_r1_to_rv_ ((l).real); \      li = ffetarget_cvt_r1_to_rv_ ((l).imaginary); \      rr = ffetarget_cvt_r1_to_rv_ ((r).real); \      ri = ffetarget_cvt_r1_to_rv_ ((r).imaginary); \      *(res) = (REAL_VALUES_EQUAL (lr, rr)&& REAL_VALUES_EQUAL (li, ri)) \        ? FALSE : TRUE; \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_ne_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, li, rr, ri; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).real.v[0])); \      li = ffetarget_cvt_r2_to_rv_ (&((l).imaginary.v[0])); \      rr = ffetarget_cvt_r2_to_rv_ (&((r).real.v[0])); \      ri = ffetarget_cvt_r2_to_rv_ (&((r).imaginary.v[0])); \      *(res) = (REAL_VALUES_EQUAL (lr, rr)&& REAL_VALUES_EQUAL (li, ri)) \        ? FALSE : TRUE; \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_ne_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = (((l).real != (r).real) || ((l).imaginary != (r).imaginary))  \    ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_ne_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = (((l).real != (r).real) || ((l).imaginary != (r).imaginary))  \    ? TRUE : FALSE, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_ne_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l) != (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_ne_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l) != (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_ne_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l) != (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_ne_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l) != (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_ne_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr; \      lr = ffetarget_cvt_r1_to_rv_ ((l)); \      rr = ffetarget_cvt_r1_to_rv_ ((r)); \      *(res) = REAL_VALUES_EQUAL (lr, rr) ? FALSE : TRUE; \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_ne_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).v[0])); \      rr = ffetarget_cvt_r2_to_rv_ (&((r).v[0])); \      *(res) = REAL_VALUES_EQUAL (lr, rr) ? FALSE : TRUE; \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_ne_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l) != (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_ne_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|(*(res) = ((l) != (r)) ? TRUE : FALSE, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_neqv_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) ^ (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_neqv_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) ^ (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_neqv_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) ^ (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_neqv_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) ^ (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_neqv_logical1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) != (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_neqv_logical2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) != (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_neqv_logical3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) != (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_neqv_logical4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) != (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_not_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = ~(l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_not_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = ~(l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_not_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = ~(l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_not_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = ~(l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_not_logical1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = !(l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_not_logical2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = !(l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_not_logical3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = !(l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_not_logical4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = !(l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_octalmil
parameter_list|(
name|v
parameter_list|,
name|t
parameter_list|)
value|ffetarget_typeless_octal (v, t)
end_define

begin_define
define|#
directive|define
name|ffetarget_octalvxt
parameter_list|(
name|v
parameter_list|,
name|t
parameter_list|)
value|ffetarget_typeless_octal (v, t)
end_define

begin_define
define|#
directive|define
name|ffetarget_offset
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = (l), TRUE)
end_define

begin_comment
comment|/* Overflow? */
end_comment

begin_define
define|#
directive|define
name|ffetarget_offset_add
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) + (r), TRUE)
end_define

begin_comment
comment|/* Overflow? */
end_comment

begin_define
define|#
directive|define
name|ffetarget_offset_charsize
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|u
parameter_list|)
value|(*(res) = (l) * (u), TRUE)
end_define

begin_comment
comment|/* Ov? */
end_comment

begin_define
define|#
directive|define
name|ffetarget_offset_multiply
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) * (r), TRUE)
end_define

begin_comment
comment|/* Ov? */
end_comment

begin_define
define|#
directive|define
name|ffetarget_offset_overflow
parameter_list|(
name|text
parameter_list|)
value|((void) 0)
end_define

begin_comment
comment|/* ~~no message? */
end_comment

begin_define
define|#
directive|define
name|ffetarget_or_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) | (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_or_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) | (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_or_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) | (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_or_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) | (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_or_logical1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) || (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_or_logical2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) || (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_or_logical3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) || (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_or_logical4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) || (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_print_binarymil
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
value|ffetarget_print_binary (f, v)
end_define

begin_define
define|#
directive|define
name|ffetarget_print_binaryvxt
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
value|ffetarget_print_binary (f, v)
end_define

begin_define
define|#
directive|define
name|ffetarget_print_hexxmil
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
value|ffetarget_print_hex (f, v)
end_define

begin_define
define|#
directive|define
name|ffetarget_print_hexxvxt
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
value|ffetarget_print_hex (f, v)
end_define

begin_define
define|#
directive|define
name|ffetarget_print_hexzmil
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
value|ffetarget_print_hex (f, v)
end_define

begin_define
define|#
directive|define
name|ffetarget_print_hexzvxt
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
value|ffetarget_print_hex (f, v)
end_define

begin_define
define|#
directive|define
name|ffetarget_print_integer1
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|fprintf ((f), "%" ffetargetInteger1_f "d", (v))
end_define

begin_define
define|#
directive|define
name|ffetarget_print_integer2
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|fprintf ((f), "%" ffetargetInteger2_f "d", (v))
end_define

begin_define
define|#
directive|define
name|ffetarget_print_integer3
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|fprintf ((f), "%" ffetargetInteger3_f "d", (v))
end_define

begin_define
define|#
directive|define
name|ffetarget_print_integer4
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|fprintf ((f), "%" ffetargetInteger4_f "d", (v))
end_define

begin_define
define|#
directive|define
name|ffetarget_print_logical1
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|fprintf ((f), "%" ffetargetLogical1_f "d", (v))
end_define

begin_define
define|#
directive|define
name|ffetarget_print_logical2
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|fprintf ((f), "%" ffetargetLogical2_f "d", (v))
end_define

begin_define
define|#
directive|define
name|ffetarget_print_logical3
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|fprintf ((f), "%" ffetargetLogical3_f "d", (v))
end_define

begin_define
define|#
directive|define
name|ffetarget_print_logical4
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|fprintf ((f), "%" ffetargetLogical4_f "d", (v))
end_define

begin_define
define|#
directive|define
name|ffetarget_print_octalmil
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
value|ffetarget_print_octal(f,v)
end_define

begin_define
define|#
directive|define
name|ffetarget_print_octalvxt
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
value|ffetarget_print_octal(f,v)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_print_real1
parameter_list|(
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr; \      lr = ffetarget_cvt_r1_to_rv_ ((l)); \      REAL_VALUE_TO_DECIMAL (lr, bad_fmt_val??, ffetarget_string_); \      fputs (ffetarget_string_, (f)); \    })
end_define

begin_define
define|#
directive|define
name|ffetarget_print_real2
parameter_list|(
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).v[0])); \      REAL_VALUE_TO_DECIMAL (lr, bad_fmt_val??, ffetarget_string_); \      fputs (ffetarget_string_, (f)); \    })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_print_real1
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|fprintf ((f), "%" ffetargetReal1_f "g", (v))
end_define

begin_define
define|#
directive|define
name|ffetarget_print_real2
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|fprintf ((f), "%" ffetargetReal2_f "g", (v))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_real1_one
parameter_list|(
name|res
parameter_list|)
value|ffetarget_cvt_rv_to_r1_ (dconst1, *(res))
end_define

begin_define
define|#
directive|define
name|ffetarget_real2_one
parameter_list|(
name|res
parameter_list|)
value|ffetarget_cvt_rv_to_r2_ (dconst1,&((res)->v[0]))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_real1_one
parameter_list|(
name|res
parameter_list|)
value|(*(res) = (float) 1.)
end_define

begin_define
define|#
directive|define
name|ffetarget_real2_one
parameter_list|(
name|res
parameter_list|)
value|(*(res) = 1.)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_real1_two
parameter_list|(
name|res
parameter_list|)
value|ffetarget_cvt_rv_to_r1_ (dconst2, *(res))
end_define

begin_define
define|#
directive|define
name|ffetarget_real2_two
parameter_list|(
name|res
parameter_list|)
value|ffetarget_cvt_rv_to_r2_ (dconst2,&((res)->v[0]))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_real1_two
parameter_list|(
name|res
parameter_list|)
value|(*(res) = (float) 2.)
end_define

begin_define
define|#
directive|define
name|ffetarget_real2_two
parameter_list|(
name|res
parameter_list|)
value|(*(res) = 2.)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_real1_zero
parameter_list|(
name|res
parameter_list|)
value|ffetarget_cvt_rv_to_r1_ (dconst0, *(res))
end_define

begin_define
define|#
directive|define
name|ffetarget_real2_zero
parameter_list|(
name|res
parameter_list|)
value|ffetarget_cvt_rv_to_r2_ (dconst0,&((res)->v[0]))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_real1_zero
parameter_list|(
name|res
parameter_list|)
value|(*(res) = (float) 0.)
end_define

begin_define
define|#
directive|define
name|ffetarget_real2_zero
parameter_list|(
name|res
parameter_list|)
value|(*(res) = 0.)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_size_typeless_binary
parameter_list|(
name|t
parameter_list|)
value|((ffetarget_num_digits_(t) + 7) / 8)
end_define

begin_define
define|#
directive|define
name|ffetarget_size_typeless_octal
parameter_list|(
name|t
parameter_list|)
define|\
value|((ffetarget_num_digits_(t) * 3 + 7) / 8)
end_define

begin_define
define|#
directive|define
name|ffetarget_size_typeless_hex
parameter_list|(
name|t
parameter_list|)
value|((ffetarget_num_digits_(t) + 1) / 2)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_subtract_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, li, rr, ri, resr, resi; \      lr = ffetarget_cvt_r1_to_rv_ ((l).real); \      li = ffetarget_cvt_r1_to_rv_ ((l).imaginary); \      rr = ffetarget_cvt_r1_to_rv_ ((r).real); \      ri = ffetarget_cvt_r1_to_rv_ ((r).imaginary); \      REAL_ARITHMETIC (resr, MINUS_EXPR, lr, rr); \      REAL_ARITHMETIC (resi, MINUS_EXPR, li, ri); \      ffetarget_cvt_rv_to_r1_ (resr, (res)->real); \      ffetarget_cvt_rv_to_r1_ (resi, (res)->imaginary); \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_subtract_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, li, rr, ri, resr, resi; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).real.v[0])); \      li = ffetarget_cvt_r2_to_rv_ (&((l).imaginary.v[0])); \      rr = ffetarget_cvt_r2_to_rv_ (&((r).real.v[0])); \      ri = ffetarget_cvt_r2_to_rv_ (&((r).imaginary.v[0])); \      REAL_ARITHMETIC (resr, MINUS_EXPR, lr, rr); \      REAL_ARITHMETIC (resi, MINUS_EXPR, li, ri); \      ffetarget_cvt_rv_to_r2_ (resr,&((res)->real.v[0])); \      ffetarget_cvt_rv_to_r2_ (resi,&((res)->imaginary.v[0])); \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_subtract_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|((res)->real = (l).real - (r).real, \    (res)->imaginary = (l).imaginary - (r).imaginary, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_subtract_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|((res)->real = (l).real - (r).real, \    (res)->imaginary = (l).imaginary - (r).imaginary, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_subtract_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) - (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_subtract_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) - (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_subtract_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) - (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_subtract_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) - (r), FFEBAD)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_subtract_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr, resr; \      lr = ffetarget_cvt_r1_to_rv_ ((l)); \      rr = ffetarget_cvt_r1_to_rv_ ((r)); \      REAL_ARITHMETIC (resr, MINUS_EXPR, lr, rr); \      ffetarget_cvt_rv_to_r1_ (resr, *(res)); \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_subtract_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, rr, resr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).v[0])); \      rr = ffetarget_cvt_r2_to_rv_ (&((r).v[0])); \      REAL_ARITHMETIC (resr, MINUS_EXPR, lr, rr); \      ffetarget_cvt_rv_to_r2_ (resr,&((res)->v[0])); \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_subtract_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) - (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_subtract_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) - (r), FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetarget_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetarget_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetarget_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetarget_terminate_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetarget_text_character1
parameter_list|(
name|c
parameter_list|)
value|((c).text)
end_define

begin_define
define|#
directive|define
name|ffetarget_text_characterdefault
value|ffetarget_text_character1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_uminus_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, li, resr, resi; \      lr = ffetarget_cvt_r1_to_rv_ ((l).real); \      li = ffetarget_cvt_r1_to_rv_ ((l).imaginary); \      resr = REAL_VALUE_NEGATE (lr); \      resi = REAL_VALUE_NEGATE (li); \      ffetarget_cvt_rv_to_r1_ (resr, (res)->real); \      ffetarget_cvt_rv_to_r1_ (resi, (res)->imaginary); \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_uminus_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, li, resr, resi; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).real.v[0])); \      li = ffetarget_cvt_r2_to_rv_ (&((l).imaginary.v[0])); \      resr = REAL_VALUE_NEGATE (lr); \      resi = REAL_VALUE_NEGATE (li); \      ffetarget_cvt_rv_to_r2_ (resr,&((res)->real.v[0])); \      ffetarget_cvt_rv_to_r2_ (resi,&((res)->imaginary.v[0])); \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_uminus_complex1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|((res)->real = -(l).real, (res)->imaginary = -(l).imaginary, FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_uminus_complex2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|((res)->real = -(l).real, (res)->imaginary = -(l).imaginary, FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_uminus_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = -(l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_uminus_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = -(l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_uminus_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = -(l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_uminus_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = -(l), FFEBAD)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_uminus_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, resr; \      lr = ffetarget_cvt_r1_to_rv_ ((l)); \      resr = REAL_VALUE_NEGATE (lr); \      ffetarget_cvt_rv_to_r1_ (resr, *(res)); \      FFEBAD; })
end_define

begin_define
define|#
directive|define
name|ffetarget_uminus_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
define|\
value|({ REAL_VALUE_TYPE lr, resr; \      lr = ffetarget_cvt_r2_to_rv_ (&((l).v[0])); \      resr = REAL_VALUE_NEGATE (lr); \      ffetarget_cvt_rv_to_r2_ (resr,&((res)->v[0])); \      FFEBAD; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_uminus_real1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = -(l), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_uminus_real2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|)
value|(*(res) = -(l), FFEBAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_ARITHMETIC
end_ifdef

begin_define
define|#
directive|define
name|ffetarget_value_real1
parameter_list|(
name|lr
parameter_list|)
value|ffetarget_cvt_r1_to_rv_ ((lr))
end_define

begin_define
define|#
directive|define
name|ffetarget_value_real2
parameter_list|(
name|lr
parameter_list|)
value|ffetarget_cvt_r2_to_rv_ (&((lr).v[0]))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffetarget_value_real1
end_define

begin_define
define|#
directive|define
name|ffetarget_value_real2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffetarget_xor_integer1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) ^ (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_xor_integer2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) ^ (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_xor_integer3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) ^ (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_xor_integer4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) ^ (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_xor_logical1
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) != (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_xor_logical2
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) != (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_xor_logical3
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) != (r), FFEBAD)
end_define

begin_define
define|#
directive|define
name|ffetarget_xor_logical4
parameter_list|(
name|res
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
value|(*(res) = (l) != (r), FFEBAD)
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_TARGET_H */
end_comment

end_unit

