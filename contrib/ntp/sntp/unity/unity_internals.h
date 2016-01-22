begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==========================================     Unity Project - A Test Framework for C     Copyright (c) 2007-14 Mike Karlesky, Mark VanderVoord, Greg Williams     [Released under MIT License. Please refer to license.txt for details] ========================================== */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_INTERNALS_H
end_ifndef

begin_define
define|#
directive|define
name|UNITY_INTERNALS_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|UNITY_INCLUDE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"unity_config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
comment|// Unity Attempts to Auto-Detect Integer Types
end_comment

begin_comment
comment|// Attempt 1: UINT_MAX, ULONG_MAX, etc in<stdint.h>
end_comment

begin_comment
comment|// Attempt 2: UINT_MAX, ULONG_MAX, etc in<limits.h>
end_comment

begin_comment
comment|// Attempt 3: Deduced from sizeof() macros
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_EXCLUDE_STDINT_H
end_ifndef

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_EXCLUDE_LIMITS_H
end_ifndef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_EXCLUDE_SIZEOF
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|UINT_MAX
end_ifndef

begin_define
define|#
directive|define
name|UINT_MAX
value|(sizeof(unsigned int) * 256 - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ULONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|ULONG_MAX
value|(sizeof(unsigned long) * 256 - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UINTPTR_MAX
end_ifndef

begin_comment
comment|//apparently this is not a constant expression: (sizeof(unsigned int *) * 256 - 1) so we have to just let this fall through
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Guess Widths If Not Specified
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Determine the size of an int, if not already specificied.
end_comment

begin_comment
comment|// We cannot use sizeof(int), because it is not yet defined
end_comment

begin_comment
comment|// at this stage in the trnslation of the C program.
end_comment

begin_comment
comment|// Therefore, infer it from UINT_MAX if possible.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_INT_WIDTH
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|UINT_MAX
end_ifdef

begin_if
if|#
directive|if
operator|(
name|UINT_MAX
operator|==
literal|0xFFFF
operator|)
end_if

begin_define
define|#
directive|define
name|UNITY_INT_WIDTH
value|(16)
end_define

begin_elif
elif|#
directive|elif
operator|(
name|UINT_MAX
operator|==
literal|0xFFFFFFFF
operator|)
end_elif

begin_define
define|#
directive|define
name|UNITY_INT_WIDTH
value|(32)
end_define

begin_elif
elif|#
directive|elif
operator|(
name|UINT_MAX
operator|==
literal|0xFFFFFFFFFFFFFFFF
operator|)
end_elif

begin_define
define|#
directive|define
name|UNITY_INT_WIDTH
value|(64)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_INT_WIDTH
end_ifndef

begin_define
define|#
directive|define
name|UNITY_INT_WIDTH
value|(32)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Determine the size of a long, if not already specified,
end_comment

begin_comment
comment|// by following the process used above to define
end_comment

begin_comment
comment|// UNITY_INT_WIDTH.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_LONG_WIDTH
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|ULONG_MAX
end_ifdef

begin_if
if|#
directive|if
operator|(
name|ULONG_MAX
operator|==
literal|0xFFFF
operator|)
end_if

begin_define
define|#
directive|define
name|UNITY_LONG_WIDTH
value|(16)
end_define

begin_elif
elif|#
directive|elif
operator|(
name|ULONG_MAX
operator|==
literal|0xFFFFFFFF
operator|)
end_elif

begin_define
define|#
directive|define
name|UNITY_LONG_WIDTH
value|(32)
end_define

begin_elif
elif|#
directive|elif
operator|(
name|ULONG_MAX
operator|==
literal|0xFFFFFFFFFFFFFFFF
operator|)
end_elif

begin_define
define|#
directive|define
name|UNITY_LONG_WIDTH
value|(64)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_LONG_WIDTH
end_ifndef

begin_define
define|#
directive|define
name|UNITY_LONG_WIDTH
value|(32)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Determine the size of a pointer, if not already specified,
end_comment

begin_comment
comment|// by following the process used above to define
end_comment

begin_comment
comment|// UNITY_INT_WIDTH.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_POINTER_WIDTH
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|UINTPTR_MAX
end_ifdef

begin_if
if|#
directive|if
operator|(
name|UINTPTR_MAX
operator|+
literal|0
operator|<=
literal|0xFFFF
operator|)
end_if

begin_define
define|#
directive|define
name|UNITY_POINTER_WIDTH
value|(16)
end_define

begin_elif
elif|#
directive|elif
operator|(
name|UINTPTR_MAX
operator|+
literal|0
operator|<=
literal|0xFFFFFFFF
operator|)
end_elif

begin_define
define|#
directive|define
name|UNITY_POINTER_WIDTH
value|(32)
end_define

begin_elif
elif|#
directive|elif
operator|(
name|UINTPTR_MAX
operator|+
literal|0
operator|<=
literal|0xFFFFFFFFFFFFFFFF
operator|)
end_elif

begin_define
define|#
directive|define
name|UNITY_POINTER_WIDTH
value|(64)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_POINTER_WIDTH
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|INTPTR_MAX
end_ifdef

begin_if
if|#
directive|if
operator|(
name|INTPTR_MAX
operator|+
literal|0
operator|<=
literal|0x7FFF
operator|)
end_if

begin_define
define|#
directive|define
name|UNITY_POINTER_WIDTH
value|(16)
end_define

begin_elif
elif|#
directive|elif
operator|(
name|INTPTR_MAX
operator|+
literal|0
operator|<=
literal|0x7FFFFFFF
operator|)
end_elif

begin_define
define|#
directive|define
name|UNITY_POINTER_WIDTH
value|(32)
end_define

begin_elif
elif|#
directive|elif
operator|(
name|INTPTR_MAX
operator|+
literal|0
operator|<=
literal|0x7FFFFFFFFFFFFFFF
operator|)
end_elif

begin_define
define|#
directive|define
name|UNITY_POINTER_WIDTH
value|(64)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_POINTER_WIDTH
end_ifndef

begin_define
define|#
directive|define
name|UNITY_POINTER_WIDTH
value|UNITY_LONG_WIDTH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Int Support (Define types based on detected sizes)
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_if
if|#
directive|if
operator|(
name|UNITY_INT_WIDTH
operator|==
literal|32
operator|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|char
name|_UU8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|_UU16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|_UU32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|char
name|_US8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|short
name|_US16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|int
name|_US32
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
operator|(
name|UNITY_INT_WIDTH
operator|==
literal|16
operator|)
end_elif

begin_typedef
typedef|typedef
name|unsigned
name|char
name|_UU8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|_UU16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|_UU32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|char
name|_US8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|int
name|_US16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|long
name|_US32
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Invalid UNITY_INT_WIDTH specified! (16 or 32 are supported)
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// 64-bit Support
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_SUPPORT_64
end_ifndef

begin_if
if|#
directive|if
name|UNITY_LONG_WIDTH
operator|>
literal|32
end_if

begin_define
define|#
directive|define
name|UNITY_SUPPORT_64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_SUPPORT_64
end_ifndef

begin_if
if|#
directive|if
name|UNITY_POINTER_WIDTH
operator|>
literal|32
end_if

begin_define
define|#
directive|define
name|UNITY_SUPPORT_64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_SUPPORT_64
end_ifndef

begin_comment
comment|//No 64-bit Support
end_comment

begin_typedef
typedef|typedef
name|_UU32
name|_U_UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_US32
name|_U_SINT
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|//64-bit Support
end_comment

begin_if
if|#
directive|if
operator|(
name|UNITY_LONG_WIDTH
operator|==
literal|32
operator|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|_UU64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|long
name|long
name|_US64
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
operator|(
name|UNITY_LONG_WIDTH
operator|==
literal|64
operator|)
end_elif

begin_typedef
typedef|typedef
name|unsigned
name|long
name|_UU64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|long
name|_US64
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Invalid UNITY_LONG_WIDTH specified! (32 or 64 are supported)
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|_UU64
name|_U_UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_US64
name|_U_SINT
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Pointer Support
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_if
if|#
directive|if
operator|(
name|UNITY_POINTER_WIDTH
operator|==
literal|32
operator|)
end_if

begin_typedef
typedef|typedef
name|_UU32
name|_UP
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UNITY_DISPLAY_STYLE_POINTER
value|UNITY_DISPLAY_STYLE_HEX32
end_define

begin_elif
elif|#
directive|elif
operator|(
name|UNITY_POINTER_WIDTH
operator|==
literal|64
operator|)
end_elif

begin_typedef
typedef|typedef
name|_UU64
name|_UP
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UNITY_DISPLAY_STYLE_POINTER
value|UNITY_DISPLAY_STYLE_HEX64
end_define

begin_elif
elif|#
directive|elif
operator|(
name|UNITY_POINTER_WIDTH
operator|==
literal|16
operator|)
end_elif

begin_typedef
typedef|typedef
name|_UU16
name|_UP
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UNITY_DISPLAY_STYLE_POINTER
value|UNITY_DISPLAY_STYLE_HEX16
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Invalid UNITY_POINTER_WIDTH specified! (16, 32 or 64 are supported)
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_PTR_ATTRIBUTE
end_ifndef

begin_define
define|#
directive|define
name|UNITY_PTR_ATTRIBUTE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Float Support
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNITY_EXCLUDE_FLOAT
end_ifdef

begin_comment
comment|//No Floating Point Support
end_comment

begin_undef
undef|#
directive|undef
name|UNITY_INCLUDE_FLOAT
end_undef

begin_undef
undef|#
directive|undef
name|UNITY_FLOAT_PRECISION
end_undef

begin_undef
undef|#
directive|undef
name|UNITY_FLOAT_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|UNITY_FLOAT_VERBOSE
end_undef

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_INCLUDE_FLOAT
end_ifndef

begin_define
define|#
directive|define
name|UNITY_INCLUDE_FLOAT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//Floating Point Support
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_FLOAT_PRECISION
end_ifndef

begin_define
define|#
directive|define
name|UNITY_FLOAT_PRECISION
value|(0.00001f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_FLOAT_TYPE
end_ifndef

begin_define
define|#
directive|define
name|UNITY_FLOAT_TYPE
value|float
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|UNITY_FLOAT_TYPE
name|_UF
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Double Float Support
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|//unlike FLOAT, we DON'T include by default
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_EXCLUDE_DOUBLE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_INCLUDE_DOUBLE
end_ifndef

begin_define
define|#
directive|define
name|UNITY_EXCLUDE_DOUBLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNITY_EXCLUDE_DOUBLE
end_ifdef

begin_comment
comment|//No Floating Point Support
end_comment

begin_undef
undef|#
directive|undef
name|UNITY_DOUBLE_PRECISION
end_undef

begin_undef
undef|#
directive|undef
name|UNITY_DOUBLE_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|UNITY_DOUBLE_VERBOSE
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|UNITY_INCLUDE_DOUBLE
end_ifdef

begin_undef
undef|#
directive|undef
name|UNITY_INCLUDE_DOUBLE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|//Double Floating Point Support
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_DOUBLE_PRECISION
end_ifndef

begin_define
define|#
directive|define
name|UNITY_DOUBLE_PRECISION
value|(1e-12f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_DOUBLE_TYPE
end_ifndef

begin_define
define|#
directive|define
name|UNITY_DOUBLE_TYPE
value|double
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|UNITY_DOUBLE_TYPE
name|_UD
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNITY_DOUBLE_VERBOSE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_FLOAT_VERBOSE
end_ifndef

begin_define
define|#
directive|define
name|UNITY_FLOAT_VERBOSE
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
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Output Method: stdout (DEFAULT)
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_OUTPUT_CHAR
end_ifndef

begin_comment
comment|//Default to using putchar, which is defined in stdio.h
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|UNITY_OUTPUT_CHAR
parameter_list|(
name|a
parameter_list|)
value|putchar(a)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|//If defined as something else, make sure we declare it here so it's ready for use
end_comment

begin_function_decl
specifier|extern
name|int
name|UNITY_OUTPUT_CHAR
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_OUTPUT_START
end_ifndef

begin_define
define|#
directive|define
name|UNITY_OUTPUT_START
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_OUTPUT_COMPLETE
end_ifndef

begin_define
define|#
directive|define
name|UNITY_OUTPUT_COMPLETE
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Footprint
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_LINE_TYPE
end_ifndef

begin_define
define|#
directive|define
name|UNITY_LINE_TYPE
value|_U_UINT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_COUNTER_TYPE
end_ifndef

begin_define
define|#
directive|define
name|UNITY_COUNTER_TYPE
value|_U_UINT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Language Features Available
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|UNITY_WEAK_ATTRIBUTE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|UNITY_WEAK_PRAGMA
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|// includes clang
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|__WIN32__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|UNITY_WEAK_ATTRIBUTE
value|__attribute__((weak))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNITY_NO_WEAK
end_ifdef

begin_undef
undef|#
directive|undef
name|UNITY_WEAK_ATTRIBUTE
end_undef

begin_undef
undef|#
directive|undef
name|UNITY_WEAK_PRAGMA
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|UNITY_NORETURN_ATTRIBUTE
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|// includes clang
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|__WIN32__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|UNITY_NORETURN_ATTRIBUTE
value|__attribute__((noreturn))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_NORETURN_ATTRIBUTE
end_ifndef

begin_define
define|#
directive|define
name|UNITY_NORETURN_ATTRIBUTE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Internal Structs Needed
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|UnityTestFunction
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|UNITY_DISPLAY_RANGE_INT
value|(0x10)
end_define

begin_define
define|#
directive|define
name|UNITY_DISPLAY_RANGE_UINT
value|(0x20)
end_define

begin_define
define|#
directive|define
name|UNITY_DISPLAY_RANGE_HEX
value|(0x40)
end_define

begin_define
define|#
directive|define
name|UNITY_DISPLAY_RANGE_AUTO
value|(0x80)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
if|#
directive|if
operator|(
name|UNITY_INT_WIDTH
operator|==
literal|16
operator|)
name|UNITY_DISPLAY_STYLE_INT
init|=
literal|2
operator|+
name|UNITY_DISPLAY_RANGE_INT
operator|+
name|UNITY_DISPLAY_RANGE_AUTO
block|,
elif|#
directive|elif
operator|(
name|UNITY_INT_WIDTH
operator|==
literal|32
operator|)
name|UNITY_DISPLAY_STYLE_INT
init|=
literal|4
operator|+
name|UNITY_DISPLAY_RANGE_INT
operator|+
name|UNITY_DISPLAY_RANGE_AUTO
block|,
elif|#
directive|elif
operator|(
name|UNITY_INT_WIDTH
operator|==
literal|64
operator|)
name|UNITY_DISPLAY_STYLE_INT
init|=
literal|8
operator|+
name|UNITY_DISPLAY_RANGE_INT
operator|+
name|UNITY_DISPLAY_RANGE_AUTO
block|,
endif|#
directive|endif
name|UNITY_DISPLAY_STYLE_INT8
init|=
literal|1
operator|+
name|UNITY_DISPLAY_RANGE_INT
block|,
name|UNITY_DISPLAY_STYLE_INT16
init|=
literal|2
operator|+
name|UNITY_DISPLAY_RANGE_INT
block|,
name|UNITY_DISPLAY_STYLE_INT32
init|=
literal|4
operator|+
name|UNITY_DISPLAY_RANGE_INT
block|,
ifdef|#
directive|ifdef
name|UNITY_SUPPORT_64
name|UNITY_DISPLAY_STYLE_INT64
init|=
literal|8
operator|+
name|UNITY_DISPLAY_RANGE_INT
block|,
endif|#
directive|endif
if|#
directive|if
operator|(
name|UNITY_INT_WIDTH
operator|==
literal|16
operator|)
name|UNITY_DISPLAY_STYLE_UINT
init|=
literal|2
operator|+
name|UNITY_DISPLAY_RANGE_UINT
operator|+
name|UNITY_DISPLAY_RANGE_AUTO
block|,
elif|#
directive|elif
operator|(
name|UNITY_INT_WIDTH
operator|==
literal|32
operator|)
name|UNITY_DISPLAY_STYLE_UINT
init|=
literal|4
operator|+
name|UNITY_DISPLAY_RANGE_UINT
operator|+
name|UNITY_DISPLAY_RANGE_AUTO
block|,
elif|#
directive|elif
operator|(
name|UNITY_INT_WIDTH
operator|==
literal|64
operator|)
name|UNITY_DISPLAY_STYLE_UINT
init|=
literal|8
operator|+
name|UNITY_DISPLAY_RANGE_UINT
operator|+
name|UNITY_DISPLAY_RANGE_AUTO
block|,
endif|#
directive|endif
name|UNITY_DISPLAY_STYLE_UINT8
init|=
literal|1
operator|+
name|UNITY_DISPLAY_RANGE_UINT
block|,
name|UNITY_DISPLAY_STYLE_UINT16
init|=
literal|2
operator|+
name|UNITY_DISPLAY_RANGE_UINT
block|,
name|UNITY_DISPLAY_STYLE_UINT32
init|=
literal|4
operator|+
name|UNITY_DISPLAY_RANGE_UINT
block|,
ifdef|#
directive|ifdef
name|UNITY_SUPPORT_64
name|UNITY_DISPLAY_STYLE_UINT64
init|=
literal|8
operator|+
name|UNITY_DISPLAY_RANGE_UINT
block|,
endif|#
directive|endif
name|UNITY_DISPLAY_STYLE_HEX8
init|=
literal|1
operator|+
name|UNITY_DISPLAY_RANGE_HEX
block|,
name|UNITY_DISPLAY_STYLE_HEX16
init|=
literal|2
operator|+
name|UNITY_DISPLAY_RANGE_HEX
block|,
name|UNITY_DISPLAY_STYLE_HEX32
init|=
literal|4
operator|+
name|UNITY_DISPLAY_RANGE_HEX
block|,
ifdef|#
directive|ifdef
name|UNITY_SUPPORT_64
name|UNITY_DISPLAY_STYLE_HEX64
init|=
literal|8
operator|+
name|UNITY_DISPLAY_RANGE_HEX
block|,
endif|#
directive|endif
name|UNITY_DISPLAY_STYLE_UNKNOWN
block|}
name|UNITY_DISPLAY_STYLE_T
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_EXCLUDE_FLOAT
end_ifndef

begin_typedef
typedef|typedef
enum|enum
name|_UNITY_FLOAT_TRAIT_T
block|{
name|UNITY_FLOAT_IS_NOT_INF
init|=
literal|0
block|,
name|UNITY_FLOAT_IS_INF
block|,
name|UNITY_FLOAT_IS_NOT_NEG_INF
block|,
name|UNITY_FLOAT_IS_NEG_INF
block|,
name|UNITY_FLOAT_IS_NOT_NAN
block|,
name|UNITY_FLOAT_IS_NAN
block|,
name|UNITY_FLOAT_IS_NOT_DET
block|,
name|UNITY_FLOAT_IS_DET
block|, }
name|UNITY_FLOAT_TRAIT_T
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|_Unity
block|{
specifier|const
name|char
modifier|*
name|TestFile
decl_stmt|;
specifier|const
name|char
modifier|*
name|CurrentTestName
decl_stmt|;
name|UNITY_LINE_TYPE
name|CurrentTestLineNumber
decl_stmt|;
name|UNITY_COUNTER_TYPE
name|NumberOfTests
decl_stmt|;
name|UNITY_COUNTER_TYPE
name|TestFailures
decl_stmt|;
name|UNITY_COUNTER_TYPE
name|TestIgnores
decl_stmt|;
name|UNITY_COUNTER_TYPE
name|CurrentTestFailed
decl_stmt|;
name|UNITY_COUNTER_TYPE
name|CurrentTestIgnored
decl_stmt|;
name|jmp_buf
name|AbortFrame
decl_stmt|;
name|int
name|isExpectingFail
decl_stmt|;
name|UNITY_COUNTER_TYPE
name|TestXFAILS
decl_stmt|;
name|UNITY_COUNTER_TYPE
name|TestPasses
decl_stmt|;
name|UNITY_COUNTER_TYPE
name|TestXPASSES
decl_stmt|;
specifier|const
name|char
modifier|*
name|XFAILMessage
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|_Unity
name|Unity
decl_stmt|;
end_decl_stmt

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Test Suite Management
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_function_decl
name|void
name|UnityBegin
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|UnityEnd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityConcludeTest
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityDefaultTestRun
parameter_list|(
name|UnityTestFunction
name|Func
parameter_list|,
specifier|const
name|char
modifier|*
name|FuncName
parameter_list|,
specifier|const
name|int
name|FuncLineNum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Test Output
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_function_decl
name|void
name|UnityPrint
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityPrintMask
parameter_list|(
specifier|const
name|_U_UINT
name|mask
parameter_list|,
specifier|const
name|_U_UINT
name|number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityPrintNumberByStyle
parameter_list|(
specifier|const
name|_U_SINT
name|number
parameter_list|,
specifier|const
name|UNITY_DISPLAY_STYLE_T
name|style
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityPrintNumber
parameter_list|(
specifier|const
name|_U_SINT
name|number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityPrintNumberUnsigned
parameter_list|(
specifier|const
name|_U_UINT
name|number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityPrintNumberHex
parameter_list|(
specifier|const
name|_U_UINT
name|number
parameter_list|,
specifier|const
name|char
name|nibbles
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|UNITY_FLOAT_VERBOSE
end_ifdef

begin_function_decl
name|void
name|UnityPrintFloat
parameter_list|(
specifier|const
name|_UF
name|number
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Test Assertion Fuctions
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|//  Use the macros below this section instead of calling
end_comment

begin_comment
comment|//  these directly. The macros have a consistent naming
end_comment

begin_comment
comment|//  convention and will pull in file and line information
end_comment

begin_comment
comment|//  for you.
end_comment

begin_function_decl
name|void
name|UnityAssertEqualNumber
parameter_list|(
specifier|const
name|_U_SINT
name|expected
parameter_list|,
specifier|const
name|_U_SINT
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|UNITY_LINE_TYPE
name|lineNumber
parameter_list|,
specifier|const
name|UNITY_DISPLAY_STYLE_T
name|style
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityAssertEqualIntArray
parameter_list|(
name|UNITY_PTR_ATTRIBUTE
specifier|const
name|void
modifier|*
name|expected
parameter_list|,
name|UNITY_PTR_ATTRIBUTE
specifier|const
name|void
modifier|*
name|actual
parameter_list|,
specifier|const
name|_UU32
name|num_elements
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|UNITY_LINE_TYPE
name|lineNumber
parameter_list|,
specifier|const
name|UNITY_DISPLAY_STYLE_T
name|style
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityAssertBits
parameter_list|(
specifier|const
name|_U_SINT
name|mask
parameter_list|,
specifier|const
name|_U_SINT
name|expected
parameter_list|,
specifier|const
name|_U_SINT
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|UNITY_LINE_TYPE
name|lineNumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityAssertEqualString
parameter_list|(
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|UNITY_LINE_TYPE
name|lineNumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityAssertEqualStringArray
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|actual
parameter_list|,
specifier|const
name|_UU32
name|num_elements
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|UNITY_LINE_TYPE
name|lineNumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityAssertEqualMemory
parameter_list|(
name|UNITY_PTR_ATTRIBUTE
specifier|const
name|void
modifier|*
name|expected
parameter_list|,
name|UNITY_PTR_ATTRIBUTE
specifier|const
name|void
modifier|*
name|actual
parameter_list|,
specifier|const
name|_UU32
name|length
parameter_list|,
specifier|const
name|_UU32
name|num_elements
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|UNITY_LINE_TYPE
name|lineNumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityAssertNumbersWithin
parameter_list|(
specifier|const
name|_U_SINT
name|delta
parameter_list|,
specifier|const
name|_U_SINT
name|expected
parameter_list|,
specifier|const
name|_U_SINT
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|UNITY_LINE_TYPE
name|lineNumber
parameter_list|,
specifier|const
name|UNITY_DISPLAY_STYLE_T
name|style
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|UnityFail
argument_list|(
specifier|const
name|char
operator|*
name|message
argument_list|,
specifier|const
name|UNITY_LINE_TYPE
name|line
argument_list|)
name|UNITY_NORETURN_ATTRIBUTE
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|UnityIgnore
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|,
specifier|const
name|UNITY_LINE_TYPE
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_EXCLUDE_FLOAT
end_ifndef

begin_function_decl
name|void
name|UnityAssertFloatsWithin
parameter_list|(
specifier|const
name|_UF
name|delta
parameter_list|,
specifier|const
name|_UF
name|expected
parameter_list|,
specifier|const
name|_UF
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|UNITY_LINE_TYPE
name|lineNumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityAssertEqualFloatArray
parameter_list|(
name|UNITY_PTR_ATTRIBUTE
specifier|const
name|_UF
modifier|*
name|expected
parameter_list|,
name|UNITY_PTR_ATTRIBUTE
specifier|const
name|_UF
modifier|*
name|actual
parameter_list|,
specifier|const
name|_UU32
name|num_elements
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|UNITY_LINE_TYPE
name|lineNumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityAssertFloatSpecial
parameter_list|(
specifier|const
name|_UF
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|UNITY_LINE_TYPE
name|lineNumber
parameter_list|,
specifier|const
name|UNITY_FLOAT_TRAIT_T
name|style
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_EXCLUDE_DOUBLE
end_ifndef

begin_function_decl
name|void
name|UnityAssertDoublesWithin
parameter_list|(
specifier|const
name|_UD
name|delta
parameter_list|,
specifier|const
name|_UD
name|expected
parameter_list|,
specifier|const
name|_UD
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|UNITY_LINE_TYPE
name|lineNumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityAssertEqualDoubleArray
parameter_list|(
name|UNITY_PTR_ATTRIBUTE
specifier|const
name|_UD
modifier|*
name|expected
parameter_list|,
name|UNITY_PTR_ATTRIBUTE
specifier|const
name|_UD
modifier|*
name|actual
parameter_list|,
specifier|const
name|_UU32
name|num_elements
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|UNITY_LINE_TYPE
name|lineNumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnityAssertDoubleSpecial
parameter_list|(
specifier|const
name|_UD
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|UNITY_LINE_TYPE
name|lineNumber
parameter_list|,
specifier|const
name|UNITY_FLOAT_TRAIT_T
name|style
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Error Strings We Might Need
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|UnityStrErrFloat
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|UnityStrErrDouble
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|UnityStrErr64
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Test Running Macros
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|TEST_PROTECT
parameter_list|()
value|(setjmp(Unity.AbortFrame) == 0)
end_define

begin_define
define|#
directive|define
name|TEST_ABORT
parameter_list|()
value|{longjmp(Unity.AbortFrame, 1);}
end_define

begin_comment
comment|//This tricky series of macros gives us an optional line argument to treat it as RUN_TEST(func, num=__LINE__)
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RUN_TEST
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC_VERSION__
end_ifdef

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|199901L
end_if

begin_define
define|#
directive|define
name|RUN_TEST
parameter_list|(
modifier|...
parameter_list|)
value|UnityDefaultTestRun(RUN_TEST_FIRST(__VA_ARGS__), RUN_TEST_SECOND(__VA_ARGS__))
end_define

begin_define
define|#
directive|define
name|RUN_TEST_FIRST
parameter_list|(
modifier|...
parameter_list|)
value|RUN_TEST_FIRST_HELPER(__VA_ARGS__, throwaway)
end_define

begin_define
define|#
directive|define
name|RUN_TEST_FIRST_HELPER
parameter_list|(
name|first
parameter_list|,
modifier|...
parameter_list|)
value|first, #first
end_define

begin_define
define|#
directive|define
name|RUN_TEST_SECOND
parameter_list|(
modifier|...
parameter_list|)
value|RUN_TEST_SECOND_HELPER(__VA_ARGS__, __LINE__, throwaway)
end_define

begin_define
define|#
directive|define
name|RUN_TEST_SECOND_HELPER
parameter_list|(
name|first
parameter_list|,
name|second
parameter_list|,
modifier|...
parameter_list|)
value|second
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//If we can't do the tricky version, we'll just have to require them to always include the line number
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RUN_TEST
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|CMOCK
end_ifdef

begin_define
define|#
directive|define
name|RUN_TEST
parameter_list|(
name|func
parameter_list|,
name|num
parameter_list|)
value|UnityDefaultTestRun(func, #func, num)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RUN_TEST
parameter_list|(
name|func
parameter_list|)
value|UnityDefaultTestRun(func, #func, __LINE__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TEST_LINE_NUM
value|(Unity.CurrentTestLineNumber)
end_define

begin_define
define|#
directive|define
name|TEST_IS_IGNORED
value|(Unity.CurrentTestIgnored)
end_define

begin_define
define|#
directive|define
name|UNITY_NEW_TEST
parameter_list|(
name|a
parameter_list|)
define|\
value|Unity.CurrentTestName = a; \     Unity.CurrentTestLineNumber = (UNITY_LINE_TYPE)(__LINE__); \     Unity.NumberOfTests++;
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_BEGIN
end_ifndef

begin_define
define|#
directive|define
name|UNITY_BEGIN
parameter_list|()
value|UnityBegin(__FILE__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_END
end_ifndef

begin_define
define|#
directive|define
name|UNITY_END
parameter_list|()
value|UnityEnd()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Basic Fail and Ignore
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|UNITY_TEST_FAIL
parameter_list|(
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityFail(   (message), (UNITY_LINE_TYPE)line);
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_IGNORE
parameter_list|(
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityIgnore( (message), (UNITY_LINE_TYPE)line);
end_define

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Test Asserts
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT
parameter_list|(
name|condition
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|if (condition) {} else {UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, message);}
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_NULL
parameter_list|(
name|pointer
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT(((pointer) == NULL),  (UNITY_LINE_TYPE)line, message)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_NOT_NULL
parameter_list|(
name|pointer
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT(((pointer) != NULL),  (UNITY_LINE_TYPE)line, message)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_INT
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualNumber((_U_SINT)(expected), (_U_SINT)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_INT)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_INT8
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualNumber((_U_SINT)(_US8 )(expected), (_U_SINT)(_US8 )(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_INT8)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_INT16
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualNumber((_U_SINT)(_US16)(expected), (_U_SINT)(_US16)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_INT16)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_INT32
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualNumber((_U_SINT)(_US32)(expected), (_U_SINT)(_US32)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_INT32)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_UINT
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualNumber((_U_SINT)(expected), (_U_SINT)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_UINT)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_UINT8
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualNumber((_U_SINT)(_UU8 )(expected), (_U_SINT)(_UU8 )(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_UINT8)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_UINT16
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualNumber((_U_SINT)(_UU16)(expected), (_U_SINT)(_UU16)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_UINT16)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_UINT32
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualNumber((_U_SINT)(_UU32)(expected), (_U_SINT)(_UU32)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_UINT32)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_HEX8
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualNumber((_U_SINT)(_US8 )(expected), (_U_SINT)(_US8 )(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_HEX8)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_HEX16
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualNumber((_U_SINT)(_US16)(expected), (_U_SINT)(_US16)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_HEX16)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_HEX32
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualNumber((_U_SINT)(_US32)(expected), (_U_SINT)(_US32)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_HEX32)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_BITS
parameter_list|(
name|mask
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertBits((_U_SINT)(mask), (_U_SINT)(expected), (_U_SINT)(actual), (message), (UNITY_LINE_TYPE)line)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_INT_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertNumbersWithin((_U_SINT)(delta), (_U_SINT)(expected), (_U_SINT)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_INT)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_INT8_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertNumbersWithin((_U_SINT)(_US8 )(delta), (_U_SINT)(_US8 )(expected), (_U_SINT)(_US8 )(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_INT8)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_INT16_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertNumbersWithin((_U_SINT)(_US16)(delta), (_U_SINT)(_US16)(expected), (_U_SINT)(_US16)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_INT16)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_INT32_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertNumbersWithin((_U_SINT)(_US32)(delta), (_U_SINT)(_US32)(expected), (_U_SINT)(_US32)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_INT32)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_UINT_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertNumbersWithin((_U_SINT)(delta), (_U_SINT)(expected), (_U_SINT)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_UINT)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_UINT8_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertNumbersWithin((_U_SINT)(_U_UINT)(_UU8 )(delta), (_U_SINT)(_U_UINT)(_UU8 )(expected), (_U_SINT)(_U_UINT)(_UU8 )(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_UINT8)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_UINT16_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertNumbersWithin((_U_SINT)(_U_UINT)(_UU16)(delta), (_U_SINT)(_U_UINT)(_UU16)(expected), (_U_SINT)(_U_UINT)(_UU16)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_UINT16)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_UINT32_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertNumbersWithin((_U_SINT)(_U_UINT)(_UU32)(delta), (_U_SINT)(_U_UINT)(_UU32)(expected), (_U_SINT)(_U_UINT)(_UU32)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_UINT32)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_HEX8_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertNumbersWithin((_U_SINT)(_U_UINT)(_UU8 )(delta), (_U_SINT)(_U_UINT)(_UU8 )(expected), (_U_SINT)(_U_UINT)(_UU8 )(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_HEX8)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_HEX16_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertNumbersWithin((_U_SINT)(_U_UINT)(_UU16)(delta), (_U_SINT)(_U_UINT)(_UU16)(expected), (_U_SINT)(_U_UINT)(_UU16)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_HEX16)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_HEX32_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertNumbersWithin((_U_SINT)(_U_UINT)(_UU32)(delta), (_U_SINT)(_U_UINT)(_UU32)(expected), (_U_SINT)(_U_UINT)(_UU32)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_HEX32)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_PTR
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualNumber((_U_SINT)(_UP)(expected), (_U_SINT)(_UP)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_POINTER)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_STRING
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualString((const char*)(expected), (const char*)(actual), (message), (UNITY_LINE_TYPE)line)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_MEMORY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|len
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualMemory((UNITY_PTR_ATTRIBUTE const void*)(expected), (UNITY_PTR_ATTRIBUTE const void*)(actual), (_UU32)(len), 1, (message), (UNITY_LINE_TYPE)line)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_INT_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualIntArray((UNITY_PTR_ATTRIBUTE const void*)(expected), (UNITY_PTR_ATTRIBUTE const void*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_INT)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_INT8_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualIntArray((UNITY_PTR_ATTRIBUTE const void*)(expected), (UNITY_PTR_ATTRIBUTE const void*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_INT8)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_INT16_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualIntArray((UNITY_PTR_ATTRIBUTE const void*)(expected), (UNITY_PTR_ATTRIBUTE const void*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_INT16)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_INT32_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualIntArray((UNITY_PTR_ATTRIBUTE const void*)(expected), (UNITY_PTR_ATTRIBUTE const void*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_INT32)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_UINT_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualIntArray((UNITY_PTR_ATTRIBUTE const void*)(expected), (UNITY_PTR_ATTRIBUTE const void*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_UINT)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_UINT8_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualIntArray((UNITY_PTR_ATTRIBUTE const void*)(expected), (UNITY_PTR_ATTRIBUTE const void*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_UINT8)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_UINT16_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualIntArray((UNITY_PTR_ATTRIBUTE const void*)(expected), (UNITY_PTR_ATTRIBUTE const void*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_UINT16)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_UINT32_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualIntArray((UNITY_PTR_ATTRIBUTE const void*)(expected), (UNITY_PTR_ATTRIBUTE const void*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_UINT32)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualIntArray((UNITY_PTR_ATTRIBUTE const void*)(expected), (UNITY_PTR_ATTRIBUTE const void*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_HEX8)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_HEX16_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualIntArray((UNITY_PTR_ATTRIBUTE const void*)(expected), (UNITY_PTR_ATTRIBUTE const void*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_HEX16)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_HEX32_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualIntArray((UNITY_PTR_ATTRIBUTE const void*)(expected), (UNITY_PTR_ATTRIBUTE const void*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_HEX32)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_PTR_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualIntArray((UNITY_PTR_ATTRIBUTE const void*)(_UP*)(expected), (const void*)(_UP*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_POINTER)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_STRING_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualStringArray((const char**)(expected), (const char**)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_MEMORY_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|len
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualMemory((UNITY_PTR_ATTRIBUTE void*)(expected), (UNITY_PTR_ATTRIBUTE void*)(actual), (_UU32)(len), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|UNITY_SUPPORT_64
end_ifdef

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_INT64
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualNumber((_U_SINT)(expected), (_U_SINT)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_INT64)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_UINT64
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualNumber((_U_SINT)(expected), (_U_SINT)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_UINT64)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_HEX64
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualNumber((_U_SINT)(expected), (_U_SINT)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_HEX64)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_INT64_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualIntArray((UNITY_PTR_ATTRIBUTE const _U_SINT*)(expected), (UNITY_PTR_ATTRIBUTE const _U_SINT*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_INT64)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_UINT64_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualIntArray((UNITY_PTR_ATTRIBUTE const _U_SINT*)(expected), (UNITY_PTR_ATTRIBUTE const _U_SINT*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_UINT64)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_HEX64_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualIntArray((UNITY_PTR_ATTRIBUTE const _U_SINT*)(expected), (UNITY_PTR_ATTRIBUTE const _U_SINT*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_HEX64)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_INT64_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertNumbersWithin((_U_SINT)(delta), (_U_SINT)(expected), (_U_SINT)(actual), NULL, (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_INT64)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_UINT64_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertNumbersWithin((_U_SINT)(delta), (_U_SINT)(expected), (_U_SINT)(actual), NULL, (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_UINT64)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_HEX64_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertNumbersWithin((_U_SINT)(delta), (_U_SINT)(expected), (_U_SINT)(actual), NULL, (UNITY_LINE_TYPE)line, UNITY_DISPLAY_STYLE_HEX64)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_INT64
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErr64)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_UINT64
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErr64)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_HEX64
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErr64)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_INT64_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErr64)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_UINT64_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErr64)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_HEX64_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErr64)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_INT64_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErr64)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_UINT64_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErr64)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_HEX64_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErr64)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNITY_EXCLUDE_FLOAT
end_ifdef

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrFloat)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_FLOAT
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrFloat)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_FLOAT_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrFloat)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_IS_INF
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrFloat)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_IS_NEG_INF
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrFloat)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_IS_NAN
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrFloat)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_IS_DETERMINATE
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrFloat)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_IS_NOT_INF
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrFloat)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_IS_NOT_NEG_INF
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrFloat)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_IS_NOT_NAN
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrFloat)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_IS_NOT_DETERMINATE
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrFloat)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertFloatsWithin((_UF)(delta), (_UF)(expected), (_UF)(actual), (message), (UNITY_LINE_TYPE)line)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_FLOAT
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_WITHIN((_UF)(expected) * (_UF)UNITY_FLOAT_PRECISION, (_UF)expected, (_UF)actual, (UNITY_LINE_TYPE)line, message)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_FLOAT_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualFloatArray((_UF*)(expected), (_UF*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_IS_INF
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertFloatSpecial((_UF)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_FLOAT_IS_INF)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_IS_NEG_INF
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertFloatSpecial((_UF)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_FLOAT_IS_NEG_INF)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_IS_NAN
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertFloatSpecial((_UF)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_FLOAT_IS_NAN)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_IS_DETERMINATE
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertFloatSpecial((_UF)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_FLOAT_IS_DET)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_IS_NOT_INF
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertFloatSpecial((_UF)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_FLOAT_IS_NOT_INF)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_IS_NOT_NEG_INF
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertFloatSpecial((_UF)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_FLOAT_IS_NOT_NEG_INF)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_IS_NOT_NAN
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertFloatSpecial((_UF)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_FLOAT_IS_NOT_NAN)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_FLOAT_IS_NOT_DETERMINATE
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertFloatSpecial((_UF)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_FLOAT_IS_NOT_DET)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNITY_EXCLUDE_DOUBLE
end_ifdef

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrDouble)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_DOUBLE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrDouble)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_DOUBLE_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrDouble)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_IS_INF
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrDouble)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_IS_NEG_INF
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrDouble)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_IS_NAN
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrDouble)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_IS_DETERMINATE
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrDouble)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_IS_NOT_INF
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrDouble)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_IS_NOT_NEG_INF
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrDouble)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_IS_NOT_NAN
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrDouble)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_IS_NOT_DETERMINATE
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_FAIL((UNITY_LINE_TYPE)line, UnityStrErrDouble)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertDoublesWithin((_UD)(delta), (_UD)(expected), (_UD)(actual), (message), (UNITY_LINE_TYPE)line)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_DOUBLE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_WITHIN((_UD)(expected) * (_UD)UNITY_DOUBLE_PRECISION, (_UD)expected, (_UD)actual, (UNITY_LINE_TYPE)line, message)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_EQUAL_DOUBLE_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertEqualDoubleArray((_UD*)(expected), (_UD*)(actual), (_UU32)(num_elements), (message), (UNITY_LINE_TYPE)line)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_IS_INF
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertDoubleSpecial((_UD)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_FLOAT_IS_INF)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_IS_NEG_INF
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertDoubleSpecial((_UD)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_FLOAT_IS_NEG_INF)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_IS_NAN
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertDoubleSpecial((_UD)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_FLOAT_IS_NAN)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_IS_DETERMINATE
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertDoubleSpecial((_UD)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_FLOAT_IS_DET)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_IS_NOT_INF
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertDoubleSpecial((_UD)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_FLOAT_IS_NOT_INF)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_IS_NOT_NEG_INF
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertDoubleSpecial((_UD)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_FLOAT_IS_NOT_NEG_INF)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_IS_NOT_NAN
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertDoubleSpecial((_UD)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_FLOAT_IS_NOT_NAN)
end_define

begin_define
define|#
directive|define
name|UNITY_TEST_ASSERT_DOUBLE_IS_NOT_DETERMINATE
parameter_list|(
name|actual
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|)
value|UnityAssertDoubleSpecial((_UD)(actual), (message), (UNITY_LINE_TYPE)line, UNITY_FLOAT_IS_NOT_DET)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//End of UNITY_INTERNALS_H
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//#define TEST_EXPECT_FAIL()																		Unity.isExpectingFail = 1;
end_comment

begin_comment
comment|//#define TEST_EXPECT_FAIL_MESSAGE(message)														Unity.isExpectingFail = 1; Unity.XFAILMessage = message; //PROBLEM : does this work on all compilers?
end_comment

begin_define
define|#
directive|define
name|TEST_EXPECT_FAIL
parameter_list|()
value|UnityExpectFail();
end_define

begin_define
define|#
directive|define
name|TEST_EXPECT_FAIL_MESSAGE
parameter_list|(
name|message
parameter_list|)
value|UnityExpectFailMessage( (message) );
end_define

end_unit

