begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Decimal context module for the decNumber C Library.    Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by IBM Corporation.  Author Mike Cowlishaw.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it under    the terms of the GNU General Public License as published by the Free    Software Foundation; either version 2, or (at your option) any later    version.     In addition to the permissions in the GNU General Public License,    the Free Software Foundation gives you unlimited permission to link    the compiled version of this file into combinations with other    programs, and to distribute those combinations without any    restriction coming from the use of this file.  (The General Public    License restrictions do apply in other respects; for example, they    cover modification of the file, and distribution when not linked    into a combine executable.)     GCC is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_comment
comment|/*  This module compirises the routines for handling the arithmetic     context structures. */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* for strcmp */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"decContext.h"
end_include

begin_comment
comment|/* context and base types */
end_comment

begin_include
include|#
directive|include
file|"decNumberLocal.h"
end_include

begin_comment
comment|/* decNumber local types, etc. */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decContextDefault -- initialize a context structure                */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  context is the structure to be initialized                        */
end_comment

begin_comment
comment|/*  kind selects the required set of default values, one of:          */
end_comment

begin_comment
comment|/*      DEC_INIT_BASE       -- select ANSI X3-274 defaults            */
end_comment

begin_comment
comment|/*      DEC_INIT_DECIMAL32  -- select IEEE 754r defaults, 32-bit      */
end_comment

begin_comment
comment|/*      DEC_INIT_DECIMAL64  -- select IEEE 754r defaults, 64-bit      */
end_comment

begin_comment
comment|/*      DEC_INIT_DECIMAL128 -- select IEEE 754r defaults, 128-bit     */
end_comment

begin_comment
comment|/*      For any other value a valid context is returned, but with     */
end_comment

begin_comment
comment|/*      Invalid_operation set in the status field.                    */
end_comment

begin_comment
comment|/*  returns a context structure with the appropriate initial values.  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decContext
modifier|*
name|decContextDefault
parameter_list|(
name|decContext
modifier|*
name|context
parameter_list|,
name|Int
name|kind
parameter_list|)
block|{
comment|/* set defaults... */
name|context
operator|->
name|digits
operator|=
literal|9
expr_stmt|;
comment|/* 9 digits */
name|context
operator|->
name|emax
operator|=
name|DEC_MAX_EMAX
expr_stmt|;
comment|/* 9-digit exponents */
name|context
operator|->
name|emin
operator|=
name|DEC_MIN_EMIN
expr_stmt|;
comment|/* .. balanced */
name|context
operator|->
name|round
operator|=
name|DEC_ROUND_HALF_UP
expr_stmt|;
comment|/* 0.5 rises */
name|context
operator|->
name|traps
operator|=
name|DEC_Errors
expr_stmt|;
comment|/* all but informational */
name|context
operator|->
name|status
operator|=
literal|0
expr_stmt|;
comment|/* cleared */
name|context
operator|->
name|clamp
operator|=
literal|0
expr_stmt|;
comment|/* no clamping */
if|#
directive|if
name|DECSUBSET
name|context
operator|->
name|extended
operator|=
literal|0
expr_stmt|;
comment|/* cleared */
endif|#
directive|endif
switch|switch
condition|(
name|kind
condition|)
block|{
case|case
name|DEC_INIT_BASE
case|:
comment|/* [use defaults] */
break|break;
case|case
name|DEC_INIT_DECIMAL32
case|:
name|context
operator|->
name|digits
operator|=
literal|7
expr_stmt|;
comment|/* digits */
name|context
operator|->
name|emax
operator|=
literal|96
expr_stmt|;
comment|/* Emax */
name|context
operator|->
name|emin
operator|=
operator|-
literal|95
expr_stmt|;
comment|/* Emin */
name|context
operator|->
name|round
operator|=
name|DEC_ROUND_HALF_EVEN
expr_stmt|;
comment|/* 0.5 to nearest even */
name|context
operator|->
name|traps
operator|=
literal|0
expr_stmt|;
comment|/* no traps set */
name|context
operator|->
name|clamp
operator|=
literal|1
expr_stmt|;
comment|/* clamp exponents */
if|#
directive|if
name|DECSUBSET
name|context
operator|->
name|extended
operator|=
literal|1
expr_stmt|;
comment|/* set */
endif|#
directive|endif
break|break;
case|case
name|DEC_INIT_DECIMAL64
case|:
name|context
operator|->
name|digits
operator|=
literal|16
expr_stmt|;
comment|/* digits */
name|context
operator|->
name|emax
operator|=
literal|384
expr_stmt|;
comment|/* Emax */
name|context
operator|->
name|emin
operator|=
operator|-
literal|383
expr_stmt|;
comment|/* Emin */
name|context
operator|->
name|round
operator|=
name|DEC_ROUND_HALF_EVEN
expr_stmt|;
comment|/* 0.5 to nearest even */
name|context
operator|->
name|traps
operator|=
literal|0
expr_stmt|;
comment|/* no traps set */
name|context
operator|->
name|clamp
operator|=
literal|1
expr_stmt|;
comment|/* clamp exponents */
if|#
directive|if
name|DECSUBSET
name|context
operator|->
name|extended
operator|=
literal|1
expr_stmt|;
comment|/* set */
endif|#
directive|endif
break|break;
case|case
name|DEC_INIT_DECIMAL128
case|:
name|context
operator|->
name|digits
operator|=
literal|34
expr_stmt|;
comment|/* digits */
name|context
operator|->
name|emax
operator|=
literal|6144
expr_stmt|;
comment|/* Emax */
name|context
operator|->
name|emin
operator|=
operator|-
literal|6143
expr_stmt|;
comment|/* Emin */
name|context
operator|->
name|round
operator|=
name|DEC_ROUND_HALF_EVEN
expr_stmt|;
comment|/* 0.5 to nearest even */
name|context
operator|->
name|traps
operator|=
literal|0
expr_stmt|;
comment|/* no traps set */
name|context
operator|->
name|clamp
operator|=
literal|1
expr_stmt|;
comment|/* clamp exponents */
if|#
directive|if
name|DECSUBSET
name|context
operator|->
name|extended
operator|=
literal|1
expr_stmt|;
comment|/* set */
endif|#
directive|endif
break|break;
default|default:
comment|/* invalid Kind */
comment|/* use defaults, and .. */
name|decContextSetStatus
argument_list|(
name|context
argument_list|,
name|DEC_Invalid_operation
argument_list|)
expr_stmt|;
comment|/* trap */
block|}
return|return
name|context
return|;
block|}
end_function

begin_comment
comment|/* decContextDefault */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decContextStatusToString -- convert status flags to a string       */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  context is a context with valid status field                      */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  returns a constant string describing the condition.  If multiple  */
end_comment

begin_comment
comment|/*    (or no) flags are set, a generic constant message is returned.  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|decContextStatusToString
parameter_list|(
specifier|const
name|decContext
modifier|*
name|context
parameter_list|)
block|{
name|Int
name|status
init|=
name|context
operator|->
name|status
decl_stmt|;
if|if
condition|(
name|status
operator|==
name|DEC_Conversion_syntax
condition|)
return|return
name|DEC_Condition_CS
return|;
if|if
condition|(
name|status
operator|==
name|DEC_Division_by_zero
condition|)
return|return
name|DEC_Condition_DZ
return|;
if|if
condition|(
name|status
operator|==
name|DEC_Division_impossible
condition|)
return|return
name|DEC_Condition_DI
return|;
if|if
condition|(
name|status
operator|==
name|DEC_Division_undefined
condition|)
return|return
name|DEC_Condition_DU
return|;
if|if
condition|(
name|status
operator|==
name|DEC_Inexact
condition|)
return|return
name|DEC_Condition_IE
return|;
if|if
condition|(
name|status
operator|==
name|DEC_Insufficient_storage
condition|)
return|return
name|DEC_Condition_IS
return|;
if|if
condition|(
name|status
operator|==
name|DEC_Invalid_context
condition|)
return|return
name|DEC_Condition_IC
return|;
if|if
condition|(
name|status
operator|==
name|DEC_Invalid_operation
condition|)
return|return
name|DEC_Condition_IO
return|;
if|#
directive|if
name|DECSUBSET
if|if
condition|(
name|status
operator|==
name|DEC_Lost_digits
condition|)
return|return
name|DEC_Condition_LD
return|;
endif|#
directive|endif
if|if
condition|(
name|status
operator|==
name|DEC_Overflow
condition|)
return|return
name|DEC_Condition_OV
return|;
if|if
condition|(
name|status
operator|==
name|DEC_Clamped
condition|)
return|return
name|DEC_Condition_PA
return|;
if|if
condition|(
name|status
operator|==
name|DEC_Rounded
condition|)
return|return
name|DEC_Condition_RO
return|;
if|if
condition|(
name|status
operator|==
name|DEC_Subnormal
condition|)
return|return
name|DEC_Condition_SU
return|;
if|if
condition|(
name|status
operator|==
name|DEC_Underflow
condition|)
return|return
name|DEC_Condition_UN
return|;
if|if
condition|(
name|status
operator|==
literal|0
condition|)
return|return
name|DEC_Condition_ZE
return|;
return|return
name|DEC_Condition_MU
return|;
comment|/* Multiple errors */
block|}
end_function

begin_comment
comment|/* decContextStatusToString */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decContextSetStatusFromString -- set status from a string          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  context is the controlling context                                */
end_comment

begin_comment
comment|/*  string is a string exactly equal to one that might be returned    */
end_comment

begin_comment
comment|/*            by decContextStatusToString                             */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  The status bit corresponding to the string is set, and a trap     */
end_comment

begin_comment
comment|/*  is raised if appropriate.                                         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  returns the context structure, unless the string is equal to      */
end_comment

begin_comment
comment|/*    DEC_Condition_MU or is not recognized.  In these cases NULL is  */
end_comment

begin_comment
comment|/*    returned.                                                       */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decContext
modifier|*
name|decContextSetStatusFromString
parameter_list|(
name|decContext
modifier|*
name|context
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
name|DEC_Condition_CS
argument_list|)
operator|==
literal|0
condition|)
return|return
name|decContextSetStatus
argument_list|(
name|context
argument_list|,
name|DEC_Conversion_syntax
argument_list|)
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
name|DEC_Condition_DZ
argument_list|)
operator|==
literal|0
condition|)
return|return
name|decContextSetStatus
argument_list|(
name|context
argument_list|,
name|DEC_Division_by_zero
argument_list|)
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
name|DEC_Condition_DI
argument_list|)
operator|==
literal|0
condition|)
return|return
name|decContextSetStatus
argument_list|(
name|context
argument_list|,
name|DEC_Division_impossible
argument_list|)
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
name|DEC_Condition_DU
argument_list|)
operator|==
literal|0
condition|)
return|return
name|decContextSetStatus
argument_list|(
name|context
argument_list|,
name|DEC_Division_undefined
argument_list|)
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
name|DEC_Condition_IE
argument_list|)
operator|==
literal|0
condition|)
return|return
name|decContextSetStatus
argument_list|(
name|context
argument_list|,
name|DEC_Inexact
argument_list|)
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
name|DEC_Condition_IS
argument_list|)
operator|==
literal|0
condition|)
return|return
name|decContextSetStatus
argument_list|(
name|context
argument_list|,
name|DEC_Insufficient_storage
argument_list|)
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
name|DEC_Condition_IC
argument_list|)
operator|==
literal|0
condition|)
return|return
name|decContextSetStatus
argument_list|(
name|context
argument_list|,
name|DEC_Invalid_context
argument_list|)
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
name|DEC_Condition_IO
argument_list|)
operator|==
literal|0
condition|)
return|return
name|decContextSetStatus
argument_list|(
name|context
argument_list|,
name|DEC_Invalid_operation
argument_list|)
return|;
if|#
directive|if
name|DECSUBSET
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
name|DEC_Condition_LD
argument_list|)
operator|==
literal|0
condition|)
return|return
name|decContextSetStatus
argument_list|(
name|context
argument_list|,
name|DEC_Lost_digits
argument_list|)
return|;
endif|#
directive|endif
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
name|DEC_Condition_OV
argument_list|)
operator|==
literal|0
condition|)
return|return
name|decContextSetStatus
argument_list|(
name|context
argument_list|,
name|DEC_Overflow
argument_list|)
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
name|DEC_Condition_PA
argument_list|)
operator|==
literal|0
condition|)
return|return
name|decContextSetStatus
argument_list|(
name|context
argument_list|,
name|DEC_Clamped
argument_list|)
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
name|DEC_Condition_RO
argument_list|)
operator|==
literal|0
condition|)
return|return
name|decContextSetStatus
argument_list|(
name|context
argument_list|,
name|DEC_Rounded
argument_list|)
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
name|DEC_Condition_SU
argument_list|)
operator|==
literal|0
condition|)
return|return
name|decContextSetStatus
argument_list|(
name|context
argument_list|,
name|DEC_Subnormal
argument_list|)
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
name|DEC_Condition_UN
argument_list|)
operator|==
literal|0
condition|)
return|return
name|decContextSetStatus
argument_list|(
name|context
argument_list|,
name|DEC_Underflow
argument_list|)
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
name|DEC_Condition_ZE
argument_list|)
operator|==
literal|0
condition|)
return|return
name|context
return|;
return|return
name|NULL
return|;
comment|/* Multiple status, or unknown */
block|}
end_function

begin_comment
comment|/* decContextSetStatusFromString */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* decContextSetStatus -- set status and raise trap if appropriate    */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  context is the controlling context                                */
end_comment

begin_comment
comment|/*  status  is the DEC_ exception code                                */
end_comment

begin_comment
comment|/*  returns the context structure                                     */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Control may never return from this routine, if there is a signal   */
end_comment

begin_comment
comment|/* handler and it takes a long jump.                                  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_function
name|decContext
modifier|*
name|decContextSetStatus
parameter_list|(
name|decContext
modifier|*
name|context
parameter_list|,
name|uInt
name|status
parameter_list|)
block|{
name|context
operator|->
name|status
operator||=
name|status
expr_stmt|;
if|if
condition|(
name|status
operator|&
name|context
operator|->
name|traps
condition|)
name|raise
argument_list|(
name|SIGFPE
argument_list|)
expr_stmt|;
return|return
name|context
return|;
block|}
end_function

begin_comment
comment|/* decContextSetStatus */
end_comment

end_unit

