begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Temporary support for a libc-like fp environment for decimal float.    Copyright (C) 2005 Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     In addition to the permissions in the GNU General Public License,    the Free Software Foundation gives you unlimited permission to link    the compiled version of this file into combinations with other    programs, and to distribute those combinations without any    restriction coming from the use of this file.  (The General Public    License restrictions do apply in other respects; for example, they    cover modification of the file, and distribution when not linked    into a combine executable.)     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA    02110-1301, USA.  */
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

begin_define
define|#
directive|define
name|FE_DEC_DOWNWARD
value|0
end_define

begin_define
define|#
directive|define
name|FE_DEC_TONEAREST
value|1
end_define

begin_define
define|#
directive|define
name|FE_DEC_TONEARESTFROMZERO
value|2
end_define

begin_define
define|#
directive|define
name|FE_DEC_TOWARDZERO
value|3
end_define

begin_define
define|#
directive|define
name|FE_DEC_UPWARD
value|4
end_define

begin_define
define|#
directive|define
name|FE_DEC_MAX
value|5
end_define

begin_function_decl
specifier|extern
name|void
name|__dfp_set_round
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__dfp_get_round
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|rounding
name|__decGetRound
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FIXME: these should be in thread-local storage for runtime support.  */
end_comment

begin_decl_stmt
specifier|static
name|enum
name|rounding
name|__dfp_rounding_mode
init|=
name|DEC_ROUND_HALF_EVEN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the decNumber rounding mode from the FE_DEC_* value in MODE.  */
end_comment

begin_function
name|void
name|__dfp_set_round
parameter_list|(
name|int
name|mode
parameter_list|)
block|{
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
name|FE_DEC_DOWNWARD
case|:
name|__dfp_rounding_mode
operator|=
name|DEC_ROUND_FLOOR
expr_stmt|;
break|break;
case|case
name|FE_DEC_TONEAREST
case|:
name|__dfp_rounding_mode
operator|=
name|DEC_ROUND_HALF_EVEN
expr_stmt|;
break|break;
case|case
name|FE_DEC_TONEARESTFROMZERO
case|:
name|__dfp_rounding_mode
operator|=
name|DEC_ROUND_HALF_UP
expr_stmt|;
break|break;
case|case
name|FE_DEC_TOWARDZERO
case|:
name|__dfp_rounding_mode
operator|=
name|DEC_ROUND_DOWN
expr_stmt|;
break|break;
case|case
name|FE_DEC_UPWARD
case|:
name|__dfp_rounding_mode
operator|=
name|DEC_ROUND_CEILING
expr_stmt|;
break|break;
default|default:
comment|/* We can't use assert in libgcc, so just return the default mode.  */
name|__dfp_rounding_mode
operator|=
name|DEC_ROUND_HALF_EVEN
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_comment
comment|/* Return the decNumber rounding mode as an FE_DEC_* value.  */
end_comment

begin_function
name|int
name|__dfp_get_round
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|mode
decl_stmt|;
switch|switch
condition|(
name|__dfp_rounding_mode
condition|)
block|{
case|case
name|DEC_ROUND_FLOOR
case|:
name|mode
operator|=
name|FE_DEC_DOWNWARD
expr_stmt|;
break|break;
case|case
name|DEC_ROUND_HALF_EVEN
case|:
name|mode
operator|=
name|FE_DEC_TONEAREST
expr_stmt|;
break|break;
case|case
name|DEC_ROUND_HALF_UP
case|:
name|mode
operator|=
name|FE_DEC_TONEARESTFROMZERO
expr_stmt|;
break|break;
case|case
name|DEC_ROUND_DOWN
case|:
name|mode
operator|=
name|FE_DEC_TOWARDZERO
expr_stmt|;
break|break;
case|case
name|DEC_ROUND_CEILING
case|:
name|mode
operator|=
name|FE_DEC_UPWARD
expr_stmt|;
break|break;
default|default:
comment|/* We shouldn't get here, but can't use assert in libgcc.  */
name|mode
operator|=
operator|-
literal|1
expr_stmt|;
block|}
return|return
name|mode
return|;
block|}
end_function

begin_comment
comment|/* Return the decNumber version of the current rounding mode.  */
end_comment

begin_function
name|enum
name|rounding
name|__decGetRound
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|__dfp_rounding_mode
return|;
block|}
end_function

end_unit

