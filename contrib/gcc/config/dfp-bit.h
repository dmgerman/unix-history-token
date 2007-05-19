begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header file for dfp-bit.c.    Copyright (C) 2005, 2006 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  In addition to the permissions in the GNU General Public License, the Free Software Foundation gives you unlimited permission to link the compiled version of this file into combinations with other programs, and to distribute those combinations without any restriction coming from the use of this file.  (The General Public License restrictions do apply in other respects; for example, they cover modification of the file, and distribution when not linked into a combine executable.)  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DFPBIT_H
end_ifndef

begin_define
define|#
directive|define
name|_DFPBIT_H
end_define

begin_include
include|#
directive|include
file|"tconfig.h"
end_include

begin_include
include|#
directive|include
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LIBGCC2_WORDS_BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|LIBGCC2_WORDS_BIG_ENDIAN
value|WORDS_BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LIBGCC2_FLOAT_WORDS_BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|LIBGCC2_FLOAT_WORDS_BIG_ENDIAN
value|LIBGCC2_WORDS_BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
value|LONG_DOUBLE_TYPE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LIBGCC2_HAS_XF_MODE
end_ifndef

begin_define
define|#
directive|define
name|LIBGCC2_HAS_XF_MODE
define|\
value|(BITS_PER_UNIT == 8&& LIBGCC2_LONG_DOUBLE_TYPE_SIZE == 80)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Depending on WIDTH, define a number of macros:     DFP_C_TYPE: type of the arguments to the libgcc functions; 	(eg _Decimal32)     IEEE_TYPE: the corresponding (encoded) IEEE754R type; 	(eg decimal32)        TO_INTERNAL: the name of the decNumber function to convert an    encoded value into the decNumber internal representation;     TO_ENCODED: the name of the decNumber function to convert an    internally represented decNumber into the encoded    representation.     FROM_STRING: the name of the decNumber function to read an    encoded value from a string.     TO_STRING: the name of the decNumber function to write an    encoded value to a string.  */
end_comment

begin_if
if|#
directive|if
name|WIDTH
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|DFP_C_TYPE
value|_Decimal32
end_define

begin_define
define|#
directive|define
name|IEEE_TYPE
value|decimal32
end_define

begin_define
define|#
directive|define
name|HOST_TO_IEEE
value|__host_to_ieee_32
end_define

begin_define
define|#
directive|define
name|IEEE_TO_HOST
value|__ieee_to_host_32
end_define

begin_define
define|#
directive|define
name|TO_INTERNAL
value|__decimal32ToNumber
end_define

begin_define
define|#
directive|define
name|TO_ENCODED
value|__decimal32FromNumber
end_define

begin_define
define|#
directive|define
name|FROM_STRING
value|__decimal32FromString
end_define

begin_define
define|#
directive|define
name|TO_STRING
value|__decimal32ToString
end_define

begin_elif
elif|#
directive|elif
name|WIDTH
operator|==
literal|64
end_elif

begin_define
define|#
directive|define
name|DFP_C_TYPE
value|_Decimal64
end_define

begin_define
define|#
directive|define
name|IEEE_TYPE
value|decimal64
end_define

begin_define
define|#
directive|define
name|HOST_TO_IEEE
value|__host_to_ieee_64
end_define

begin_define
define|#
directive|define
name|IEEE_TO_HOST
value|__ieee_to_host_64
end_define

begin_define
define|#
directive|define
name|TO_INTERNAL
value|__decimal64ToNumber
end_define

begin_define
define|#
directive|define
name|TO_ENCODED
value|__decimal64FromNumber
end_define

begin_define
define|#
directive|define
name|FROM_STRING
value|__decimal64FromString
end_define

begin_define
define|#
directive|define
name|TO_STRING
value|__decimal64ToString
end_define

begin_elif
elif|#
directive|elif
name|WIDTH
operator|==
literal|128
end_elif

begin_define
define|#
directive|define
name|DFP_C_TYPE
value|_Decimal128
end_define

begin_define
define|#
directive|define
name|IEEE_TYPE
value|decimal128
end_define

begin_define
define|#
directive|define
name|HOST_TO_IEEE
value|__host_to_ieee_128
end_define

begin_define
define|#
directive|define
name|IEEE_TO_HOST
value|__ieee_to_host_128
end_define

begin_define
define|#
directive|define
name|TO_INTERNAL
value|__decimal128ToNumber
end_define

begin_define
define|#
directive|define
name|TO_ENCODED
value|__decimal128FromNumber
end_define

begin_define
define|#
directive|define
name|FROM_STRING
value|__decimal128FromString
end_define

begin_define
define|#
directive|define
name|TO_STRING
value|__decimal128ToString
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|invalid decimal float word width
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We define __DEC_EVAL_METHOD__ to 2, saying that we evaluate all    operations and constants to the range and precision of the _Decimal128    type.  Make it so.  */
end_comment

begin_if
if|#
directive|if
name|WIDTH
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|CONTEXT_INIT
value|DEC_INIT_DECIMAL32
end_define

begin_elif
elif|#
directive|elif
name|WIDTH
operator|==
literal|64
end_elif

begin_define
define|#
directive|define
name|CONTEXT_INIT
value|DEC_INIT_DECIMAL64
end_define

begin_elif
elif|#
directive|elif
name|WIDTH
operator|==
literal|128
end_elif

begin_define
define|#
directive|define
name|CONTEXT_INIT
value|DEC_INIT_DECIMAL128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define CONTEXT_ROUND to obtain the current decNumber rounding mode.  */
end_comment

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

begin_define
define|#
directive|define
name|CONTEXT_ROUND
value|__decGetRound ()
end_define

begin_decl_stmt
specifier|extern
name|int
name|__dfp_traps
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CONTEXT_TRAPS
value|__dfp_traps
end_define

begin_define
define|#
directive|define
name|CONTEXT_ERRORS
parameter_list|(
name|context
parameter_list|)
value|context.status& DEC_Errors
end_define

begin_function_decl
specifier|extern
name|void
name|__dfp_raise
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DFP_RAISE
parameter_list|(
name|A
parameter_list|)
value|__dfp_raise(A)
end_define

begin_comment
comment|/* Conversions between different decimal float types use WIDTH_TO to    determine additional macros to define.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_dd_to_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_sd
argument_list|)
end_if

begin_define
define|#
directive|define
name|WIDTH_TO
value|32
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|L_sd_to_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_dd
argument_list|)
end_elif

begin_define
define|#
directive|define
name|WIDTH_TO
value|64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|L_sd_to_td
argument_list|)
operator|||
name|defined
argument_list|(
name|L_dd_to_td
argument_list|)
end_elif

begin_define
define|#
directive|define
name|WIDTH_TO
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If WIDTH_TO is defined, define additional macros:     DFP_C_TYPE_TO: type of the result of dfp to dfp conversion.     IEEE_TYPE_TO: the corresponding (encoded) IEEE754R type.     TO_ENCODED_TO: the name of the decNumber function to convert an    internally represented decNumber into the encoded representation    for the destination.  */
end_comment

begin_if
if|#
directive|if
name|WIDTH_TO
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|DFP_C_TYPE_TO
value|_Decimal32
end_define

begin_define
define|#
directive|define
name|IEEE_TYPE_TO
value|decimal32
end_define

begin_define
define|#
directive|define
name|TO_ENCODED_TO
value|__decimal32FromNumber
end_define

begin_define
define|#
directive|define
name|IEEE_TO_HOST_TO
value|__ieee_to_host_32
end_define

begin_elif
elif|#
directive|elif
name|WIDTH_TO
operator|==
literal|64
end_elif

begin_define
define|#
directive|define
name|DFP_C_TYPE_TO
value|_Decimal64
end_define

begin_define
define|#
directive|define
name|IEEE_TYPE_TO
value|decimal64
end_define

begin_define
define|#
directive|define
name|TO_ENCODED_TO
value|__decimal64FromNumber
end_define

begin_define
define|#
directive|define
name|IEEE_TO_HOST_TO
value|__ieee_to_host_64
end_define

begin_elif
elif|#
directive|elif
name|WIDTH_TO
operator|==
literal|128
end_elif

begin_define
define|#
directive|define
name|DFP_C_TYPE_TO
value|_Decimal128
end_define

begin_define
define|#
directive|define
name|IEEE_TYPE_TO
value|decimal128
end_define

begin_define
define|#
directive|define
name|TO_ENCODED_TO
value|__decimal128FromNumber
end_define

begin_define
define|#
directive|define
name|IEEE_TO_HOST_TO
value|__ieee_to_host_128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Conversions between decimal float types and integral types use INT_KIND    to determine the data type and C functions to use.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_sd_to_si
argument_list|)
operator|||
name|defined
argument_list|(
name|L_dd_to_si
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_si
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_si_to_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_si_to_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_si_to_td
argument_list|)
end_if

begin_define
define|#
directive|define
name|INT_KIND
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|L_sd_to_di
argument_list|)
operator|||
name|defined
argument_list|(
name|L_dd_to_di
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_di
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_di_to_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_di_to_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_di_to_td
argument_list|)
end_elif

begin_define
define|#
directive|define
name|INT_KIND
value|2
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|L_sd_to_usi
argument_list|)
operator|||
name|defined
argument_list|(
name|L_dd_to_usi
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_usi
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_usi_to_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_usi_to_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_usi_to_td
argument_list|)
end_elif

begin_define
define|#
directive|define
name|INT_KIND
value|3
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|L_sd_to_udi
argument_list|)
operator|||
name|defined
argument_list|(
name|L_dd_to_udi
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_udi
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_udi_to_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_udi_to_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_udi_to_td
argument_list|)
end_elif

begin_define
define|#
directive|define
name|INT_KIND
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  If INT_KIND is defined, define additional macros:      INT_TYPE: The integer data type.      INT_FMT: The format string for writing the integer to a string.      CAST_FOR_FMT: Cast variable of INT_KIND to C type for sprintf.     This works for ILP32 and LP64, won't for other type size systems.      STR_TO_INT: The function to read the integer from a string.  */
end_comment

begin_if
if|#
directive|if
name|INT_KIND
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|INT_TYPE
value|SItype
end_define

begin_define
define|#
directive|define
name|INT_FMT
value|"%d"
end_define

begin_define
define|#
directive|define
name|CAST_FOR_FMT
parameter_list|(
name|A
parameter_list|)
value|(int)A
end_define

begin_define
define|#
directive|define
name|STR_TO_INT
value|strtol
end_define

begin_elif
elif|#
directive|elif
name|INT_KIND
operator|==
literal|2
end_elif

begin_define
define|#
directive|define
name|INT_TYPE
value|DItype
end_define

begin_define
define|#
directive|define
name|INT_FMT
value|"%lld"
end_define

begin_define
define|#
directive|define
name|CAST_FOR_FMT
parameter_list|(
name|A
parameter_list|)
value|(long long)A
end_define

begin_define
define|#
directive|define
name|STR_TO_INT
value|strtoll
end_define

begin_elif
elif|#
directive|elif
name|INT_KIND
operator|==
literal|3
end_elif

begin_define
define|#
directive|define
name|INT_TYPE
value|USItype
end_define

begin_define
define|#
directive|define
name|INT_FMT
value|"%u"
end_define

begin_define
define|#
directive|define
name|CAST_FOR_FMT
parameter_list|(
name|A
parameter_list|)
value|(unsigned int)A
end_define

begin_define
define|#
directive|define
name|STR_TO_INT
value|strtoul
end_define

begin_elif
elif|#
directive|elif
name|INT_KIND
operator|==
literal|4
end_elif

begin_define
define|#
directive|define
name|INT_TYPE
value|UDItype
end_define

begin_define
define|#
directive|define
name|INT_FMT
value|"%llu"
end_define

begin_define
define|#
directive|define
name|CAST_FOR_FMT
parameter_list|(
name|A
parameter_list|)
value|(unsigned long long)A
end_define

begin_define
define|#
directive|define
name|STR_TO_INT
value|strtoull
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Conversions between decimal float types and binary float types use    BFP_KIND to determine the data type and C functions to use.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_sd_to_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_dd_to_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_sf
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_sf_to_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_sf_to_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_sf_to_td
argument_list|)
end_if

begin_define
define|#
directive|define
name|BFP_KIND
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|L_sd_to_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_dd_to_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_df
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_df_to_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_df_to_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_df_to_td
argument_list|)
end_elif

begin_define
define|#
directive|define
name|BFP_KIND
value|2
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|L_sd_to_xf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_dd_to_xf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_xf
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_xf_to_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_xf_to_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_xf_to_td
argument_list|)
end_elif

begin_define
define|#
directive|define
name|BFP_KIND
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  If BFP_KIND is defined, define additional macros:      BFP_TYPE: The binary floating point data type.      BFP_FMT: The format string for writing the value to a string.      STR_TO_BFP: The function to read the value from a string.  */
end_comment

begin_if
if|#
directive|if
name|BFP_KIND
operator|==
literal|1
end_if

begin_comment
comment|/* strtof is declared in<stdlib.h> only for C99.  */
end_comment

begin_function_decl
specifier|extern
name|float
name|strtof
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BFP_TYPE
value|SFtype
end_define

begin_define
define|#
directive|define
name|BFP_FMT
value|"%e"
end_define

begin_define
define|#
directive|define
name|STR_TO_BFP
value|strtof
end_define

begin_elif
elif|#
directive|elif
name|BFP_KIND
operator|==
literal|2
end_elif

begin_define
define|#
directive|define
name|BFP_TYPE
value|DFtype
end_define

begin_define
define|#
directive|define
name|BFP_FMT
value|"%e"
end_define

begin_define
define|#
directive|define
name|STR_TO_BFP
value|strtod
end_define

begin_elif
elif|#
directive|elif
name|BFP_KIND
operator|==
literal|3
end_elif

begin_if
if|#
directive|if
name|LIBGCC2_HAS_XF_MODE
end_if

begin_comment
comment|/* These aren't used if XF mode is not supported.  */
end_comment

begin_define
define|#
directive|define
name|BFP_TYPE
value|XFtype
end_define

begin_define
define|#
directive|define
name|BFP_FMT
value|"%e"
end_define

begin_define
define|#
directive|define
name|BFP_VIA_TYPE
value|double
end_define

begin_define
define|#
directive|define
name|STR_TO_BFP
value|strtod
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BFP_KIND */
end_comment

begin_if
if|#
directive|if
name|WIDTH
operator|==
literal|128
operator|||
name|WIDTH_TO
operator|==
literal|128
end_if

begin_include
include|#
directive|include
file|"decimal128.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|WIDTH
operator|==
literal|64
operator|||
name|WIDTH_TO
operator|==
literal|64
end_if

begin_include
include|#
directive|include
file|"decimal64.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|WIDTH
operator|==
literal|32
operator|||
name|WIDTH_TO
operator|==
literal|32
end_if

begin_include
include|#
directive|include
file|"decimal32.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"decNumber.h"
end_include

begin_comment
comment|/* Names of arithmetic functions.  */
end_comment

begin_if
if|#
directive|if
name|WIDTH
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|DFP_ADD
value|__addsd3
end_define

begin_define
define|#
directive|define
name|DFP_SUB
value|__subsd3
end_define

begin_define
define|#
directive|define
name|DFP_MULTIPLY
value|__mulsd3
end_define

begin_define
define|#
directive|define
name|DFP_DIVIDE
value|__divsd3
end_define

begin_define
define|#
directive|define
name|DFP_EQ
value|__eqsd2
end_define

begin_define
define|#
directive|define
name|DFP_NE
value|__nesd2
end_define

begin_define
define|#
directive|define
name|DFP_LT
value|__ltsd2
end_define

begin_define
define|#
directive|define
name|DFP_GT
value|__gtsd2
end_define

begin_define
define|#
directive|define
name|DFP_LE
value|__lesd2
end_define

begin_define
define|#
directive|define
name|DFP_GE
value|__gesd2
end_define

begin_define
define|#
directive|define
name|DFP_UNORD
value|__unordsd2
end_define

begin_elif
elif|#
directive|elif
name|WIDTH
operator|==
literal|64
end_elif

begin_define
define|#
directive|define
name|DFP_ADD
value|__adddd3
end_define

begin_define
define|#
directive|define
name|DFP_SUB
value|__subdd3
end_define

begin_define
define|#
directive|define
name|DFP_MULTIPLY
value|__muldd3
end_define

begin_define
define|#
directive|define
name|DFP_DIVIDE
value|__divdd3
end_define

begin_define
define|#
directive|define
name|DFP_EQ
value|__eqdd2
end_define

begin_define
define|#
directive|define
name|DFP_NE
value|__nedd2
end_define

begin_define
define|#
directive|define
name|DFP_LT
value|__ltdd2
end_define

begin_define
define|#
directive|define
name|DFP_GT
value|__gtdd2
end_define

begin_define
define|#
directive|define
name|DFP_LE
value|__ledd2
end_define

begin_define
define|#
directive|define
name|DFP_GE
value|__gedd2
end_define

begin_define
define|#
directive|define
name|DFP_UNORD
value|__unorddd2
end_define

begin_elif
elif|#
directive|elif
name|WIDTH
operator|==
literal|128
end_elif

begin_define
define|#
directive|define
name|DFP_ADD
value|__addtd3
end_define

begin_define
define|#
directive|define
name|DFP_SUB
value|__subtd3
end_define

begin_define
define|#
directive|define
name|DFP_MULTIPLY
value|__multd3
end_define

begin_define
define|#
directive|define
name|DFP_DIVIDE
value|__divtd3
end_define

begin_define
define|#
directive|define
name|DFP_EQ
value|__eqtd2
end_define

begin_define
define|#
directive|define
name|DFP_NE
value|__netd2
end_define

begin_define
define|#
directive|define
name|DFP_LT
value|__lttd2
end_define

begin_define
define|#
directive|define
name|DFP_GT
value|__gttd2
end_define

begin_define
define|#
directive|define
name|DFP_LE
value|__letd2
end_define

begin_define
define|#
directive|define
name|DFP_GE
value|__getd2
end_define

begin_define
define|#
directive|define
name|DFP_UNORD
value|__unordtd2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Names of functions to convert between different decimal float types.  */
end_comment

begin_if
if|#
directive|if
name|WIDTH
operator|==
literal|32
end_if

begin_if
if|#
directive|if
name|WIDTH_TO
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|DFP_TO_DFP
value|__extendsddd2
end_define

begin_elif
elif|#
directive|elif
name|WIDTH_TO
operator|==
literal|128
end_elif

begin_define
define|#
directive|define
name|DFP_TO_DFP
value|__extendsdtd2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|WIDTH
operator|==
literal|64
end_elif

begin_if
if|#
directive|if
name|WIDTH_TO
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|DFP_TO_DFP
value|__truncddsd2
end_define

begin_elif
elif|#
directive|elif
name|WIDTH_TO
operator|==
literal|128
end_elif

begin_define
define|#
directive|define
name|DFP_TO_DFP
value|__extendddtd2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|WIDTH
operator|==
literal|128
end_elif

begin_if
if|#
directive|if
name|WIDTH_TO
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|DFP_TO_DFP
value|__trunctdsd2
end_define

begin_elif
elif|#
directive|elif
name|WIDTH_TO
operator|==
literal|64
end_elif

begin_define
define|#
directive|define
name|DFP_TO_DFP
value|__trunctddd2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Names of functions to convert between decimal float and integers.  */
end_comment

begin_if
if|#
directive|if
name|WIDTH
operator|==
literal|32
end_if

begin_if
if|#
directive|if
name|INT_KIND
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|INT_TO_DFP
value|__floatsisd
end_define

begin_define
define|#
directive|define
name|DFP_TO_INT
value|__fixsdsi
end_define

begin_elif
elif|#
directive|elif
name|INT_KIND
operator|==
literal|2
end_elif

begin_define
define|#
directive|define
name|INT_TO_DFP
value|__floatdisd
end_define

begin_define
define|#
directive|define
name|DFP_TO_INT
value|__fixsddi
end_define

begin_elif
elif|#
directive|elif
name|INT_KIND
operator|==
literal|3
end_elif

begin_define
define|#
directive|define
name|INT_TO_DFP
value|__floatunssisd
end_define

begin_define
define|#
directive|define
name|DFP_TO_INT
value|__fixunssdsi
end_define

begin_elif
elif|#
directive|elif
name|INT_KIND
operator|==
literal|4
end_elif

begin_define
define|#
directive|define
name|INT_TO_DFP
value|__floatunsdisd
end_define

begin_define
define|#
directive|define
name|DFP_TO_INT
value|__fixunssddi
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|WIDTH
operator|==
literal|64
end_elif

begin_if
if|#
directive|if
name|INT_KIND
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|INT_TO_DFP
value|__floatsidd
end_define

begin_define
define|#
directive|define
name|DFP_TO_INT
value|__fixddsi
end_define

begin_elif
elif|#
directive|elif
name|INT_KIND
operator|==
literal|2
end_elif

begin_define
define|#
directive|define
name|INT_TO_DFP
value|__floatdidd
end_define

begin_define
define|#
directive|define
name|DFP_TO_INT
value|__fixdddi
end_define

begin_elif
elif|#
directive|elif
name|INT_KIND
operator|==
literal|3
end_elif

begin_define
define|#
directive|define
name|INT_TO_DFP
value|__floatunssidd
end_define

begin_define
define|#
directive|define
name|DFP_TO_INT
value|__fixunsddsi
end_define

begin_elif
elif|#
directive|elif
name|INT_KIND
operator|==
literal|4
end_elif

begin_define
define|#
directive|define
name|INT_TO_DFP
value|__floatunsdidd
end_define

begin_define
define|#
directive|define
name|DFP_TO_INT
value|__fixunsdddi
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|WIDTH
operator|==
literal|128
end_elif

begin_if
if|#
directive|if
name|INT_KIND
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|INT_TO_DFP
value|__floatsitd
end_define

begin_define
define|#
directive|define
name|DFP_TO_INT
value|__fixtdsi
end_define

begin_elif
elif|#
directive|elif
name|INT_KIND
operator|==
literal|2
end_elif

begin_define
define|#
directive|define
name|INT_TO_DFP
value|__floatditd
end_define

begin_define
define|#
directive|define
name|DFP_TO_INT
value|__fixtddi
end_define

begin_elif
elif|#
directive|elif
name|INT_KIND
operator|==
literal|3
end_elif

begin_define
define|#
directive|define
name|INT_TO_DFP
value|__floatunssitd
end_define

begin_define
define|#
directive|define
name|DFP_TO_INT
value|__fixunstdsi
end_define

begin_elif
elif|#
directive|elif
name|INT_KIND
operator|==
literal|4
end_elif

begin_define
define|#
directive|define
name|INT_TO_DFP
value|__floatunsditd
end_define

begin_define
define|#
directive|define
name|DFP_TO_INT
value|__fixunstddi
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Names of functions to convert between decimal float and binary float.  */
end_comment

begin_if
if|#
directive|if
name|WIDTH
operator|==
literal|32
end_if

begin_if
if|#
directive|if
name|BFP_KIND
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|BFP_TO_DFP
value|__extendsfsd
end_define

begin_define
define|#
directive|define
name|DFP_TO_BFP
value|__truncsdsf
end_define

begin_elif
elif|#
directive|elif
name|BFP_KIND
operator|==
literal|2
end_elif

begin_define
define|#
directive|define
name|BFP_TO_DFP
value|__truncdfsd
end_define

begin_define
define|#
directive|define
name|DFP_TO_BFP
value|__extendsddf
end_define

begin_elif
elif|#
directive|elif
name|BFP_KIND
operator|==
literal|3
end_elif

begin_define
define|#
directive|define
name|BFP_TO_DFP
value|__truncxfsd
end_define

begin_define
define|#
directive|define
name|DFP_TO_BFP
value|__extendsdxf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BFP_KIND */
end_comment

begin_elif
elif|#
directive|elif
name|WIDTH
operator|==
literal|64
end_elif

begin_if
if|#
directive|if
name|BFP_KIND
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|BFP_TO_DFP
value|__extendsfdd
end_define

begin_define
define|#
directive|define
name|DFP_TO_BFP
value|__truncddsf
end_define

begin_elif
elif|#
directive|elif
name|BFP_KIND
operator|==
literal|2
end_elif

begin_define
define|#
directive|define
name|BFP_TO_DFP
value|__extenddfdd
end_define

begin_define
define|#
directive|define
name|DFP_TO_BFP
value|__truncdddf
end_define

begin_elif
elif|#
directive|elif
name|BFP_KIND
operator|==
literal|3
end_elif

begin_define
define|#
directive|define
name|BFP_TO_DFP
value|__truncxfdd
end_define

begin_define
define|#
directive|define
name|DFP_TO_BFP
value|__extendddxf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BFP_KIND */
end_comment

begin_elif
elif|#
directive|elif
name|WIDTH
operator|==
literal|128
end_elif

begin_if
if|#
directive|if
name|BFP_KIND
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|BFP_TO_DFP
value|__extendsftd
end_define

begin_define
define|#
directive|define
name|DFP_TO_BFP
value|__trunctdsf
end_define

begin_elif
elif|#
directive|elif
name|BFP_KIND
operator|==
literal|2
end_elif

begin_define
define|#
directive|define
name|BFP_TO_DFP
value|__extenddftd
end_define

begin_define
define|#
directive|define
name|DFP_TO_BFP
value|__trunctddf
end_define

begin_elif
elif|#
directive|elif
name|BFP_KIND
operator|==
literal|3
end_elif

begin_define
define|#
directive|define
name|BFP_TO_DFP
value|__extendxftd
end_define

begin_define
define|#
directive|define
name|DFP_TO_BFP
value|__trunctdxf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BFP_KIND */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIDTH */
end_comment

begin_comment
comment|/* Some handy typedefs.  */
end_comment

begin_typedef
typedef|typedef
name|float
name|SFtype
name|__attribute__
typedef|((
name|mode
typedef|(
name|SF
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|DFtype
name|__attribute__
typedef|((
name|mode
typedef|(
name|DF
typedef|)));
end_typedef

begin_if
if|#
directive|if
name|LIBGCC2_HAS_XF_MODE
end_if

begin_typedef
typedef|typedef
name|float
name|XFtype
name|__attribute__
typedef|((
name|mode
typedef|(
name|XF
typedef|)));
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBGCC2_HAS_XF_MODE */
end_comment

begin_typedef
typedef|typedef
name|int
name|SItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|DItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|USItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UDItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_comment
comment|/* The type of the result of a decimal float comparison.  This must    match `word_mode' in GCC for the target.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|CMPtype
name|__attribute__
typedef|((
name|mode
typedef|(
name|word
typedef|)));
end_typedef

begin_comment
comment|/* Prototypes.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_mul_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_mul_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_mul_td
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DFP_C_TYPE
name|DFP_MULTIPLY
parameter_list|(
name|DFP_C_TYPE
parameter_list|,
name|DFP_C_TYPE
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
name|defined
argument_list|(
name|L_div_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_div_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_div_td
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DFP_C_TYPE
name|DFP_DIVIDE
parameter_list|(
name|DFP_C_TYPE
parameter_list|,
name|DFP_C_TYPE
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
name|defined
argument_list|(
name|L_addsub_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_addsub_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_addsub_td
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DFP_C_TYPE
name|DFP_ADD
parameter_list|(
name|DFP_C_TYPE
parameter_list|,
name|DFP_C_TYPE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DFP_C_TYPE
name|DFP_SUB
parameter_list|(
name|DFP_C_TYPE
parameter_list|,
name|DFP_C_TYPE
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
name|defined
argument_list|(
name|L_eq_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_eq_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_eq_td
argument_list|)
end_if

begin_function_decl
specifier|extern
name|CMPtype
name|DFP_EQ
parameter_list|(
name|DFP_C_TYPE
parameter_list|,
name|DFP_C_TYPE
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
name|defined
argument_list|(
name|L_ne_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_ne_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_ne_td
argument_list|)
end_if

begin_function_decl
specifier|extern
name|CMPtype
name|DFP_NE
parameter_list|(
name|DFP_C_TYPE
parameter_list|,
name|DFP_C_TYPE
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
name|defined
argument_list|(
name|L_lt_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_lt_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_lt_td
argument_list|)
end_if

begin_function_decl
specifier|extern
name|CMPtype
name|DFP_LT
parameter_list|(
name|DFP_C_TYPE
parameter_list|,
name|DFP_C_TYPE
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
name|defined
argument_list|(
name|L_gt_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_gt_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_gt_td
argument_list|)
end_if

begin_function_decl
specifier|extern
name|CMPtype
name|DFP_GT
parameter_list|(
name|DFP_C_TYPE
parameter_list|,
name|DFP_C_TYPE
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
name|defined
argument_list|(
name|L_le_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_le_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_le_td
argument_list|)
end_if

begin_function_decl
specifier|extern
name|CMPtype
name|DFP_LE
parameter_list|(
name|DFP_C_TYPE
parameter_list|,
name|DFP_C_TYPE
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
name|defined
argument_list|(
name|L_ge_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_ge_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_ge_td
argument_list|)
end_if

begin_function_decl
specifier|extern
name|CMPtype
name|DFP_GE
parameter_list|(
name|DFP_C_TYPE
parameter_list|,
name|DFP_C_TYPE
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
name|defined
argument_list|(
name|L_unord_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_unord_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_unord_td
argument_list|)
end_if

begin_function_decl
specifier|extern
name|CMPtype
name|DFP_UNORD
parameter_list|(
name|DFP_C_TYPE
parameter_list|,
name|DFP_C_TYPE
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
name|defined
argument_list|(
name|L_sd_to_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_sd_to_td
argument_list|)
operator|||
name|defined
argument_list|(
name|L_dd_to_sd
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_dd_to_td
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_dd
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DFP_C_TYPE_TO
name|DFP_TO_DFP
parameter_list|(
name|DFP_C_TYPE
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
name|defined
argument_list|(
name|L_sd_to_si
argument_list|)
operator|||
name|defined
argument_list|(
name|L_dd_to_si
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_si
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_sd_to_di
argument_list|)
operator|||
name|defined
argument_list|(
name|L_dd_to_di
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_di
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_sd_to_usi
argument_list|)
operator|||
name|defined
argument_list|(
name|L_dd_to_usi
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_usi
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_sd_to_udi
argument_list|)
operator|||
name|defined
argument_list|(
name|L_dd_to_udi
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_udi
argument_list|)
end_if

begin_function_decl
specifier|extern
name|INT_TYPE
name|DFP_TO_INT
parameter_list|(
name|DFP_C_TYPE
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
name|defined
argument_list|(
name|L_si_to_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_si_to_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_si_to_td
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_di_to_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_di_to_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_di_to_td
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_usi_to_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_usi_to_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_usi_to_td
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_udi_to_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_udi_to_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_udi_to_td
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DFP_C_TYPE
name|INT_TO_DFP
parameter_list|(
name|INT_TYPE
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
name|defined
argument_list|(
name|L_sd_to_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_dd_to_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_sf
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_sd_to_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_dd_to_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_df
argument_list|)
expr|\
operator|||
operator|(
operator|(
name|defined
argument_list|(
name|L_sd_to_xf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_dd_to_xf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_td_to_xf
argument_list|)
operator|)
expr|\
operator|&&
name|LIBGCC2_HAS_XF_MODE
operator|)
end_if

begin_function_decl
specifier|extern
name|BFP_TYPE
name|DFP_TO_BFP
parameter_list|(
name|DFP_C_TYPE
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
name|defined
argument_list|(
name|L_sf_to_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_sf_to_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_sf_to_td
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_df_to_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_df_to_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_df_to_td
argument_list|)
expr|\
operator|||
operator|(
operator|(
name|defined
argument_list|(
name|L_xf_to_sd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_xf_to_dd
argument_list|)
operator|||
name|defined
argument_list|(
name|L_xf_to_td
argument_list|)
operator|)
expr|\
operator|&&
name|LIBGCC2_HAS_XF_MODE
operator|)
end_if

begin_function_decl
specifier|extern
name|DFP_C_TYPE
name|BFP_TO_DFP
parameter_list|(
name|BFP_TYPE
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DFPBIT_H */
end_comment

end_unit

