begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Decimal Context module header for the decNumber C Library    Copyright (C) 2005, 2006 Free Software Foundation, Inc.    Contributed by IBM Corporation.  Author Mike Cowlishaw.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it under    the terms of the GNU General Public License as published by the Free    Software Foundation; either version 2, or (at your option) any later    version.     In addition to the permissions in the GNU General Public License,    the Free Software Foundation gives you unlimited permission to link    the compiled version of this file into combinations with other    programs, and to distribute those combinations without any    restriction coming from the use of this file.  (The General Public    License restrictions do apply in other respects; for example, they    cover modification of the file, and distribution when not linked    into a combine executable.)     GCC is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* Context must always be set correctly:                              */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  digits   -- must be in the range 1 through 999999999              */
end_comment

begin_comment
comment|/*  emax     -- must be in the range 0 through 999999999              */
end_comment

begin_comment
comment|/*  emin     -- must be in the range 0 through -999999999             */
end_comment

begin_comment
comment|/*  round    -- must be one of the enumerated rounding modes          */
end_comment

begin_comment
comment|/*  traps    -- only defined bits may be set                          */
end_comment

begin_comment
comment|/*  status   -- [any bits may be cleared, but not set, by user]       */
end_comment

begin_comment
comment|/*  clamp    -- must be either 0 or 1                                 */
end_comment

begin_comment
comment|/*  extended -- must be either 0 or 1 [present only if DECSUBSET]     */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DECCONTEXT
argument_list|)
end_if

begin_define
define|#
directive|define
name|DECCONTEXT
end_define

begin_define
define|#
directive|define
name|DECCNAME
value|"decContext"
end_define

begin_comment
comment|/* Short name */
end_comment

begin_define
define|#
directive|define
name|DECCFULLNAME
value|"Decimal Context Descriptor"
end_define

begin_comment
comment|/* Verbose name */
end_comment

begin_define
define|#
directive|define
name|DECCAUTHOR
value|"Mike Cowlishaw"
end_define

begin_comment
comment|/* Who to blame */
end_comment

begin_include
include|#
directive|include
file|"gstdint.h"
end_include

begin_comment
comment|/* C99 standard integers */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/* for traps */
end_comment

begin_comment
comment|/* Conditional code flag -- set this to 0 for best performance */
end_comment

begin_define
define|#
directive|define
name|DECSUBSET
value|0
end_define

begin_comment
comment|/* 1 to enable subset arithmetic */
end_comment

begin_comment
comment|/* Context for operations, with associated constants */
end_comment

begin_enum
enum|enum
name|rounding
block|{
name|DEC_ROUND_CEILING
block|,
comment|/* round towards +infinity */
name|DEC_ROUND_UP
block|,
comment|/* round away from 0 */
name|DEC_ROUND_HALF_UP
block|,
comment|/* 0.5 rounds up */
name|DEC_ROUND_HALF_EVEN
block|,
comment|/* 0.5 rounds to nearest even */
name|DEC_ROUND_HALF_DOWN
block|,
comment|/* 0.5 rounds down */
name|DEC_ROUND_DOWN
block|,
comment|/* round towards 0 (truncate) */
name|DEC_ROUND_FLOOR
block|,
comment|/* round towards -infinity */
name|DEC_ROUND_MAX
comment|/* enum must be less than this */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
block|{
name|int32_t
name|digits
decl_stmt|;
comment|/* working precision */
name|int32_t
name|emax
decl_stmt|;
comment|/* maximum positive exponent */
name|int32_t
name|emin
decl_stmt|;
comment|/* minimum negative exponent */
name|enum
name|rounding
name|round
decl_stmt|;
comment|/* rounding mode */
name|uint32_t
name|traps
decl_stmt|;
comment|/* trap-enabler flags */
name|uint32_t
name|status
decl_stmt|;
comment|/* status flags */
name|uint8_t
name|clamp
decl_stmt|;
comment|/* flag: apply IEEE exponent clamp */
if|#
directive|if
name|DECSUBSET
name|uint8_t
name|extended
decl_stmt|;
comment|/* flag: special-values allowed */
endif|#
directive|endif
block|}
name|decContext
typedef|;
end_typedef

begin_comment
comment|/* Maxima and Minima */
end_comment

begin_define
define|#
directive|define
name|DEC_MAX_DIGITS
value|999999999
end_define

begin_define
define|#
directive|define
name|DEC_MIN_DIGITS
value|1
end_define

begin_define
define|#
directive|define
name|DEC_MAX_EMAX
value|999999999
end_define

begin_define
define|#
directive|define
name|DEC_MIN_EMAX
value|0
end_define

begin_define
define|#
directive|define
name|DEC_MAX_EMIN
value|0
end_define

begin_define
define|#
directive|define
name|DEC_MIN_EMIN
value|-999999999
end_define

begin_comment
comment|/* Trap-enabler and Status flags (exceptional conditions), and their names */
end_comment

begin_comment
comment|/* Top byte is reserved for internal use */
end_comment

begin_define
define|#
directive|define
name|DEC_Conversion_syntax
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DEC_Division_by_zero
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DEC_Division_impossible
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DEC_Division_undefined
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DEC_Insufficient_storage
value|0x00000010
end_define

begin_comment
comment|/* [used if malloc fails] */
end_comment

begin_define
define|#
directive|define
name|DEC_Inexact
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DEC_Invalid_context
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DEC_Invalid_operation
value|0x00000080
end_define

begin_if
if|#
directive|if
name|DECSUBSET
end_if

begin_define
define|#
directive|define
name|DEC_Lost_digits
value|0x00000100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEC_Overflow
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DEC_Clamped
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DEC_Rounded
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DEC_Subnormal
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DEC_Underflow
value|0x00002000
end_define

begin_comment
comment|/* IEEE 854 groupings for the flags */
end_comment

begin_comment
comment|/* [DEC_Clamped, DEC_Lost_digits, DEC_Rounded, and DEC_Subnormal are */
end_comment

begin_comment
comment|/* not in IEEE 854] */
end_comment

begin_define
define|#
directive|define
name|DEC_IEEE_854_Division_by_zero
value|(DEC_Division_by_zero)
end_define

begin_if
if|#
directive|if
name|DECSUBSET
end_if

begin_define
define|#
directive|define
name|DEC_IEEE_854_Inexact
value|(DEC_Inexact | DEC_Lost_digits)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEC_IEEE_854_Inexact
value|(DEC_Inexact)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEC_IEEE_854_Invalid_operation
value|(DEC_Conversion_syntax |     \                                           DEC_Division_impossible |   \                                           DEC_Division_undefined |    \                                           DEC_Insufficient_storage |  \                                           DEC_Invalid_context |       \                                           DEC_Invalid_operation)
end_define

begin_define
define|#
directive|define
name|DEC_IEEE_854_Overflow
value|(DEC_Overflow)
end_define

begin_define
define|#
directive|define
name|DEC_IEEE_854_Underflow
value|(DEC_Underflow)
end_define

begin_comment
comment|/* flags which are normally errors (results are qNaN, infinite, or 0) */
end_comment

begin_define
define|#
directive|define
name|DEC_Errors
value|(DEC_IEEE_854_Division_by_zero |                 \                       DEC_IEEE_854_Invalid_operation |                \                       DEC_IEEE_854_Overflow | DEC_IEEE_854_Underflow)
end_define

begin_comment
comment|/* flags which cause a result to become qNaN */
end_comment

begin_define
define|#
directive|define
name|DEC_NaNs
value|DEC_IEEE_854_Invalid_operation
end_define

begin_comment
comment|/* flags which are normally for information only (have finite results) */
end_comment

begin_if
if|#
directive|if
name|DECSUBSET
end_if

begin_define
define|#
directive|define
name|DEC_Information
value|(DEC_Clamped | DEC_Rounded | DEC_Inexact     \                           | DEC_Lost_digits)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEC_Information
value|(DEC_Clamped | DEC_Rounded | DEC_Inexact)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* name strings for the exceptional conditions */
end_comment

begin_define
define|#
directive|define
name|DEC_Condition_CS
value|"Conversion syntax"
end_define

begin_define
define|#
directive|define
name|DEC_Condition_DZ
value|"Division by zero"
end_define

begin_define
define|#
directive|define
name|DEC_Condition_DI
value|"Division impossible"
end_define

begin_define
define|#
directive|define
name|DEC_Condition_DU
value|"Division undefined"
end_define

begin_define
define|#
directive|define
name|DEC_Condition_IE
value|"Inexact"
end_define

begin_define
define|#
directive|define
name|DEC_Condition_IS
value|"Insufficient storage"
end_define

begin_define
define|#
directive|define
name|DEC_Condition_IC
value|"Invalid context"
end_define

begin_define
define|#
directive|define
name|DEC_Condition_IO
value|"Invalid operation"
end_define

begin_if
if|#
directive|if
name|DECSUBSET
end_if

begin_define
define|#
directive|define
name|DEC_Condition_LD
value|"Lost digits"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEC_Condition_OV
value|"Overflow"
end_define

begin_define
define|#
directive|define
name|DEC_Condition_PA
value|"Clamped"
end_define

begin_define
define|#
directive|define
name|DEC_Condition_RO
value|"Rounded"
end_define

begin_define
define|#
directive|define
name|DEC_Condition_SU
value|"Subnormal"
end_define

begin_define
define|#
directive|define
name|DEC_Condition_UN
value|"Underflow"
end_define

begin_define
define|#
directive|define
name|DEC_Condition_ZE
value|"No status"
end_define

begin_define
define|#
directive|define
name|DEC_Condition_MU
value|"Multiple status"
end_define

begin_define
define|#
directive|define
name|DEC_Condition_Length
value|21
end_define

begin_comment
comment|/* length of the longest string, */
end_comment

begin_comment
comment|/* including terminator */
end_comment

begin_comment
comment|/* Initialization descriptors, used by decContextDefault */
end_comment

begin_define
define|#
directive|define
name|DEC_INIT_BASE
value|0
end_define

begin_define
define|#
directive|define
name|DEC_INIT_DECIMAL32
value|32
end_define

begin_define
define|#
directive|define
name|DEC_INIT_DECIMAL64
value|64
end_define

begin_define
define|#
directive|define
name|DEC_INIT_DECIMAL128
value|128
end_define

begin_comment
comment|/* decContext routines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_define
define|#
directive|define
name|decContextDefault
value|__decContextDefault
end_define

begin_define
define|#
directive|define
name|decContextSetStatus
value|__decContextSetStatus
end_define

begin_define
define|#
directive|define
name|decContextStatusToString
value|__decContextStatusToString
end_define

begin_define
define|#
directive|define
name|decContextSetStatusFromString
value|__decContextSetStatusFromString
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|decContext
modifier|*
name|decContextDefault
parameter_list|(
name|decContext
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decContext
modifier|*
name|decContextSetStatus
parameter_list|(
name|decContext
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|decContextStatusToString
parameter_list|(
specifier|const
name|decContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|decContext
modifier|*
name|decContextSetStatusFromString
parameter_list|(
name|decContext
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

