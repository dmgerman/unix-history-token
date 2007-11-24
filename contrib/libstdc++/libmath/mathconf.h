begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration data for libmath subpart of libstdc++. */
end_comment

begin_comment
comment|/* Copyright (C) 1997-1999, 2000, 2001 Free Software Foundation, Inc.     This file is part of the GNU ISO C++ Library.  This library is free    software; you can redistribute it and/or modify it under the    terms of the GNU General Public License as published by the    Free Software Foundation; either version 2, or (at your option)    any later version.     This library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this library; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,    USA.     As a special exception, you may use this file as part of a free software    library without restriction.  Specifically, if other files instantiate    templates or use macros or inline functions from this file, or you compile    this file and link it with other files to produce an executable, this    file does not by itself cause the resulting executable to be covered by    the GNU General Public License.  This exception does not however    invalidate any other reasons why the executable file might be covered by    the GNU General Public License.  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ENDIAN_H
end_ifdef

begin_include
include|#
directive|include
file|<endian.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MACHINE_ENDIAN_H
end_ifdef

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

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_MACHINE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/machine.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
name|HAVE_SYS_ISA_DEFS_H
operator|||
name|defined
name|HAVE_MACHINE_PARAM_H
end_if

begin_comment
comment|/* This is on Solaris.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_ISA_DEFS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/isa_defs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MACHINE_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<machine/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_LITTLE_ENDIAN
end_ifdef

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BIG_ENDIAN
end_ifdef

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BYTE_ORDER
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* We have to rely on the AC_C_BIGENDIAN test.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WORDS_BIGENDIAN
end_ifdef

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BYTE_ORDER
value|1
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

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|int
name|U_int32_t
name|__attribute
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|Int32_t
name|__attribute
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
name|U_int64_t
name|__attribute
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|Int64_t
name|__attribute
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NAN_H
end_ifdef

begin_include
include|#
directive|include
file|<nan.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_IEEEFP_H
end_ifdef

begin_include
include|#
directive|include
file|<ieeefp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FP_H
end_ifdef

begin_include
include|#
directive|include
file|<fp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FLOAT_H
end_ifdef

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* `float' variant of HUGE_VAL.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HUGE_VALF
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HUGE_VALf
end_ifdef

begin_define
define|#
directive|define
name|HUGE_VALF
value|HUGE_VALf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HUGE_VALF
value|HUGE_VAL
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
comment|/* `long double' variant of HUGE_VAL.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HUGE_VALL
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HUGE_VALl
end_ifdef

begin_define
define|#
directive|define
name|HUGE_VALL
value|HUGE_VALl
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HUGE_VALL
value|HUGE_VAL
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
comment|/* Make sure that at least HUGE_VAL is defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HUGE_VAL
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HUGE
end_ifdef

begin_define
define|#
directive|define
name|HUGE_VAL
value|HUGE
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MAXFLOAT
end_ifdef

begin_define
define|#
directive|define
name|HUGE_VAL
value|MAXFLOAT
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"We need HUGE_VAL!"
end_error

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
name|M_PI
end_ifndef

begin_define
define|#
directive|define
name|M_PI
value|3.14159265358979323846
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* signbit is a macro in ISO C99.  */
ifndef|#
directive|ifndef
name|signbit
specifier|extern
name|int
name|__signbitf
parameter_list|(
name|float
parameter_list|)
function_decl|;
specifier|extern
name|int
name|__signbit
parameter_list|(
name|double
parameter_list|)
function_decl|;
specifier|extern
name|int
name|__signbitl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
define|#
directive|define
name|signbit
parameter_list|(
name|x
parameter_list|)
define|\
value|(sizeof (x) == sizeof (float) ?                                          \         __signbitf (x)                                                        \       : sizeof (x) == sizeof (double) ?                                       \         __signbit (x) : __signbitl (x))
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
typedef|typedef
union|union
block|{
name|double
name|value
decl_stmt|;
struct|struct
block|{
name|U_int32_t
name|msw
decl_stmt|;
name|U_int32_t
name|lsw
decl_stmt|;
block|}
name|parts
struct|;
block|}
name|ieee_double_shape_type
typedef|;
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
typedef|typedef
union|union
block|{
name|double
name|value
decl_stmt|;
struct|struct
block|{
name|U_int32_t
name|lsw
decl_stmt|;
name|U_int32_t
name|msw
decl_stmt|;
block|}
name|parts
struct|;
block|}
name|ieee_double_shape_type
typedef|;
endif|#
directive|endif
comment|/* Get the more significant 32 bit int from a double.  */
define|#
directive|define
name|GET_HIGH_WORD
parameter_list|(
name|i
parameter_list|,
name|d
parameter_list|)
define|\
value|do {                                                            \   ieee_double_shape_type gh_u;                                  \   gh_u.value = (d);                                             \   (i) = gh_u.parts.msw;                                         \ } while (0)
typedef|typedef
union|union
block|{
name|float
name|value
decl_stmt|;
name|U_int32_t
name|word
decl_stmt|;
block|}
name|ieee_float_shape_type
typedef|;
comment|/* Get a 32 bit int from a float.  */
define|#
directive|define
name|GET_FLOAT_WORD
parameter_list|(
name|i
parameter_list|,
name|d
parameter_list|)
define|\
value|do {                                                            \   ieee_float_shape_type gf_u;                                   \   gf_u.value = (d);                                             \   (i) = gf_u.word;                                              \ } while (0)
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
typedef|typedef
union|union
block|{
name|long
name|double
name|value
decl_stmt|;
struct|struct
block|{
name|unsigned
name|int
name|sign_exponent
range|:
literal|16
decl_stmt|;
name|unsigned
name|int
name|empty
range|:
literal|16
decl_stmt|;
name|U_int32_t
name|msw
decl_stmt|;
name|U_int32_t
name|lsw
decl_stmt|;
block|}
name|parts
struct|;
block|}
name|ieee_long_double_shape_type
typedef|;
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
typedef|typedef
union|union
block|{
name|long
name|double
name|value
decl_stmt|;
struct|struct
block|{
name|U_int32_t
name|lsw
decl_stmt|;
name|U_int32_t
name|msw
decl_stmt|;
name|unsigned
name|int
name|sign_exponent
range|:
literal|16
decl_stmt|;
name|unsigned
name|int
name|empty
range|:
literal|16
decl_stmt|;
block|}
name|parts
struct|;
block|}
name|ieee_long_double_shape_type
typedef|;
endif|#
directive|endif
comment|/* Get int from the exponent of a long double.  */
define|#
directive|define
name|GET_LDOUBLE_EXP
parameter_list|(
name|exp
parameter_list|,
name|d
parameter_list|)
define|\
value|do {                                                            \   ieee_long_double_shape_type ge_u;                             \   ge_u.value = (d);                                             \   (exp) = ge_u.parts.sign_exponent;                             \ } while (0)
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
typedef|typedef
union|union
block|{
name|long
name|double
name|value
decl_stmt|;
struct|struct
block|{
name|U_int64_t
name|msw
decl_stmt|;
name|U_int64_t
name|lsw
decl_stmt|;
block|}
name|parts64
struct|;
struct|struct
block|{
name|U_int32_t
name|w0
decl_stmt|,
name|w1
decl_stmt|,
name|w2
decl_stmt|,
name|w3
decl_stmt|;
block|}
name|parts32
struct|;
block|}
name|ieee_quad_double_shape_type
typedef|;
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
typedef|typedef
union|union
block|{
name|long
name|double
name|value
decl_stmt|;
struct|struct
block|{
name|U_int64_t
name|lsw
decl_stmt|;
name|U_int64_t
name|msw
decl_stmt|;
block|}
name|parts64
struct|;
struct|struct
block|{
name|U_int32_t
name|w3
decl_stmt|,
name|w2
decl_stmt|,
name|w1
decl_stmt|,
name|w0
decl_stmt|;
block|}
name|parts32
struct|;
block|}
name|ieee_quad_double_shape_type
typedef|;
endif|#
directive|endif
comment|/* Get most significant 64 bit int from a quad long double.  */
define|#
directive|define
name|GET_LDOUBLE_MSW64
parameter_list|(
name|msw
parameter_list|,
name|d
parameter_list|)
define|\
value|do {								\   ieee_quad_double_shape_type qw_u;				\   qw_u.value = (d);						\   (msw) = qw_u.parts64.msw;					\ } while (0)
comment|/* Replacement for non-existing float functions.  */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_FABSF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE___BUILTIN_FABSF
argument_list|)
define|#
directive|define
name|fabsf
parameter_list|(
name|x
parameter_list|)
value|fabs (x)
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_COSF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE___BUILTIN_COSF
argument_list|)
define|#
directive|define
name|cosf
parameter_list|(
name|x
parameter_list|)
value|cos (x)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_COSHF
define|#
directive|define
name|coshf
parameter_list|(
name|x
parameter_list|)
value|cosh (x)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_EXPF
define|#
directive|define
name|expf
parameter_list|(
name|x
parameter_list|)
value|expf (x)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_LOGF
define|#
directive|define
name|logf
parameter_list|(
name|x
parameter_list|)
value|log(x)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_LOG10F
define|#
directive|define
name|log10f
parameter_list|(
name|x
parameter_list|)
value|log10 (x)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_POWF
define|#
directive|define
name|powf
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|pow (x, y)
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SINF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE___BUILTIN_SINF
argument_list|)
define|#
directive|define
name|sinf
parameter_list|(
name|x
parameter_list|)
value|sin (x)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_SINHF
define|#
directive|define
name|sinhf
parameter_list|(
name|x
parameter_list|)
value|sinh (x)
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SQRTF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE___BUILTIN_SQRTF
argument_list|)
define|#
directive|define
name|sqrtf
parameter_list|(
name|x
parameter_list|)
value|sqrt (x)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_TANF
define|#
directive|define
name|tanf
parameter_list|(
name|x
parameter_list|)
value|tan (x)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_TANHF
define|#
directive|define
name|tanhf
parameter_list|(
name|x
parameter_list|)
value|tanh (x)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_STRTOF
define|#
directive|define
name|strtof
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|)
value|strtod (s, e)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

end_unit

