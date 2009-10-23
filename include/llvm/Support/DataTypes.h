begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* include/llvm/Support/DataTypes.h.  Generated from DataTypes.h.in by configure.  */
end_comment

begin_comment
comment|/*===-- include/Support/DataTypes.h - Define fixed size types -----*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file contains definitions to figure out the size of _HOST_ data types.*| |* This file is important because different host OS's define different macros,*| |* which makes portability tough.  This file exports the following            *| |* definitions:                                                               *| |*                                                                            *| |*   [u]int(32|64)_t : typedefs for signed and unsigned 32/64 bit system types*| |*   [U]INT(8|16|32|64)_(MIN|MAX) : Constants for the min and max values.     *| |*                                                                            *| |* No library is required when using these functinons.                        *| |*                                                                            *| |*===----------------------------------------------------------------------===*/
end_comment

begin_comment
comment|/* Please leave this file C-compatible. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORT_DATATYPES_H
end_ifndef

begin_define
define|#
directive|define
name|SUPPORT_DATATYPES_H
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UINT64_T
value|1
end_define

begin_comment
comment|/* #undef HAVE_U_INT64_T */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_include
include|#
directive|include
file|<cmath>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MSC_VER
end_ifndef

begin_comment
comment|/* Note that this header's correct operation depends on __STDC_LIMIT_MACROS    being defined.  We would define it here, but in order to prevent Bad Things    happening when system headers or C++ STL headers include stdint.h before we    define it here, we define it on the g++ command line (in Makefile.rules). */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC_LIMIT_MACROS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Must #define __STDC_LIMIT_MACROS before #including Support/DataTypes.h"
end_error

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
name|__STDC_CONSTANT_MACROS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Must #define __STDC_CONSTANT_MACROS before "
error|\
literal|"#including Support/DataTypes.h"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Note that<inttypes.h> includes<stdint.h>, if this is a C99 system. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_INTTYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDINT_H
end_ifdef

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_include
include|#
directive|include
file|"llvm/Support/AIXDataTypesFix.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Handle incorrect definition of uint64_t as u_int64_t */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UINT64_T
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_U_INT64_T
end_ifdef

begin_typedef
typedef|typedef
name|u_int64_t
name|uint64_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Don't have a definition for uint64_t on this platform"
end_error

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
name|_OpenBSD_
end_ifdef

begin_define
define|#
directive|define
name|INT8_MAX
value|127
end_define

begin_define
define|#
directive|define
name|INT8_MIN
value|-128
end_define

begin_define
define|#
directive|define
name|UINT8_MAX
value|255
end_define

begin_define
define|#
directive|define
name|INT16_MAX
value|32767
end_define

begin_define
define|#
directive|define
name|INT16_MIN
value|-32768
end_define

begin_define
define|#
directive|define
name|UINT16_MAX
value|65535
end_define

begin_define
define|#
directive|define
name|INT32_MAX
value|2147483647
end_define

begin_define
define|#
directive|define
name|INT32_MIN
value|-2147483648
end_define

begin_define
define|#
directive|define
name|UINT32_MAX
value|4294967295U
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
comment|/* _MSC_VER */
end_comment

begin_comment
comment|/* Visual C++ doesn't provide standard integer headers, but it does provide    built-in data types. */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_typedef
typedef|typedef
name|__int64
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|uint64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|int
name|int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|char
name|int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|int
name|ssize_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INT8_MAX
value|127
end_define

begin_define
define|#
directive|define
name|INT8_MIN
value|-128
end_define

begin_define
define|#
directive|define
name|UINT8_MAX
value|255
end_define

begin_define
define|#
directive|define
name|INT16_MAX
value|32767
end_define

begin_define
define|#
directive|define
name|INT16_MIN
value|-32768
end_define

begin_define
define|#
directive|define
name|UINT16_MAX
value|65535
end_define

begin_define
define|#
directive|define
name|INT32_MAX
value|2147483647
end_define

begin_define
define|#
directive|define
name|INT32_MIN
value|-2147483648
end_define

begin_define
define|#
directive|define
name|UINT32_MAX
value|4294967295U
end_define

begin_define
define|#
directive|define
name|INT8_C
parameter_list|(
name|C
parameter_list|)
value|C
end_define

begin_define
define|#
directive|define
name|UINT8_C
parameter_list|(
name|C
parameter_list|)
value|C
end_define

begin_define
define|#
directive|define
name|INT16_C
parameter_list|(
name|C
parameter_list|)
value|C
end_define

begin_define
define|#
directive|define
name|UINT16_C
parameter_list|(
name|C
parameter_list|)
value|C
end_define

begin_define
define|#
directive|define
name|INT32_C
parameter_list|(
name|C
parameter_list|)
value|C
end_define

begin_define
define|#
directive|define
name|UINT32_C
parameter_list|(
name|C
parameter_list|)
value|C ## U
end_define

begin_define
define|#
directive|define
name|INT64_C
parameter_list|(
name|C
parameter_list|)
value|((int64_t) C ## LL)
end_define

begin_define
define|#
directive|define
name|UINT64_C
parameter_list|(
name|C
parameter_list|)
value|((uint64_t) C ## ULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

begin_comment
comment|/* Set defaults for constants which we cannot find. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INT64_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|INT64_MAX
value|9223372036854775807LL
end_define

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
name|INT64_MIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|INT64_MIN
value|((-INT64_MAX)-1)
end_define

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
name|UINT64_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|UINT64_MAX
value|0xffffffffffffffffULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__GNUC__
operator|>
literal|3
end_if

begin_define
define|#
directive|define
name|END_WITH_NULL
value|__attribute__((sentinel))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|END_WITH_NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HUGE_VALF
end_ifndef

begin_define
define|#
directive|define
name|HUGE_VALF
value|(float)HUGE_VAL
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
comment|/* SUPPORT_DATATYPES_H */
end_comment

end_unit

