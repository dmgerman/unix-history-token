begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*===-- include/Support/DataTypes.h - Define fixed size types -----*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file contains definitions to figure out the size of _HOST_ data types.*| |* This file is important because different host OS's define different macros,*| |* which makes portability tough.  This file exports the following            *| |* definitions:                                                               *| |*                                                                            *| |*   [u]int(32|64)_t : typedefs for signed and unsigned 32/64 bit system types*| |*   [U]INT(8|16|32|64)_(MIN|MAX) : Constants for the min and max values.     *| |*                                                                            *| |* No library is required when using these functions.                         *| |*                                                                            *| |*===----------------------------------------------------------------------===*/
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

begin_define
define|#
directive|define
name|HAVE_U_INT64_T
value|1
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_include
include|#
directive|include
file|<cinttypes>
end_include

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_else
else|#
directive|else
end_else

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

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Compiler must provide an implementation of stdint.h"
end_error

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
name|_MSC_VER
end_ifndef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|UINT32_MAX
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"The standard header<cstdint> is not C++11 compliant. Must #define "
error|\
literal|"__STDC_LIMIT_MACROS before #including Support/DataTypes.h"
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
name|UINT32_C
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"The standard header<cstdint> is not C++11 compliant. Must #define "
error|\
literal|"__STDC_CONSTANT_MACROS before #including Support/DataTypes.h"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Note that<inttypes.h> includes<stdint.h>, if this is a C99 system. */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_comment
comment|// GCC is strict about defining large constants: they must have LL modifier.
end_comment

begin_undef
undef|#
directive|undef
name|INT64_MAX
end_undef

begin_undef
undef|#
directive|undef
name|INT64_MIN
end_undef

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _MSC_VER */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN64
argument_list|)
end_if

begin_typedef
typedef|typedef
name|signed
name|__int64
name|ssize_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|signed
name|int
name|ssize_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WIN64 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INTTYPES_H
end_ifndef

begin_define
define|#
directive|define
name|PRId64
value|"I64d"
end_define

begin_define
define|#
directive|define
name|PRIi64
value|"I64i"
end_define

begin_define
define|#
directive|define
name|PRIo64
value|"I64o"
end_define

begin_define
define|#
directive|define
name|PRIu64
value|"I64u"
end_define

begin_define
define|#
directive|define
name|PRIx64
value|"I64x"
end_define

begin_define
define|#
directive|define
name|PRIX64
value|"I64X"
end_define

begin_define
define|#
directive|define
name|PRId32
value|"d"
end_define

begin_define
define|#
directive|define
name|PRIi32
value|"i"
end_define

begin_define
define|#
directive|define
name|PRIo32
value|"o"
end_define

begin_define
define|#
directive|define
name|PRIu32
value|"u"
end_define

begin_define
define|#
directive|define
name|PRIx32
value|"x"
end_define

begin_define
define|#
directive|define
name|PRIX32
value|"X"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_INTTYPES_H */
end_comment

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

