begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// acconfig.h symbols and macros for libstdc++ v3 -*- C++ -*-
end_comment

begin_comment
comment|// Defines libstdc++ version.
end_comment

begin_undef
undef|#
directive|undef
name|PACKAGE
end_undef

begin_undef
undef|#
directive|undef
name|VERSION
end_undef

begin_comment
comment|// Needed for gettext.
end_comment

begin_undef
undef|#
directive|undef
name|ENABLE_NLS
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_CATGETS
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_GETTEXT
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_STPCPY
end_undef

begin_comment
comment|// Include I/O support for 'long long' and 'unsigned long long'.
end_comment

begin_undef
undef|#
directive|undef
name|_GLIBCXX_USE_LONG_LONG
end_undef

begin_comment
comment|// Include support for 'long double'.
end_comment

begin_undef
undef|#
directive|undef
name|_GLIBCXX_USE_LONG_DOUBLE
end_undef

begin_comment
comment|// Define if C99 math functions (like fpclassify) should be exposed.
end_comment

begin_undef
undef|#
directive|undef
name|_GLIBCXX_USE_C99_MATH
end_undef

begin_comment
comment|// Define if C99 features such as lldiv_t, llabs, lldiv should be exposed.
end_comment

begin_undef
undef|#
directive|undef
name|_GLIBCXX_USE_C99
end_undef

begin_comment
comment|// Define if code specialized for wchar_t should be used.
end_comment

begin_undef
undef|#
directive|undef
name|_GLIBCXX_USE_WCHAR_T
end_undef

begin_comment
comment|// Define if using setrlimit to set resource limits during 'make check'.
end_comment

begin_undef
undef|#
directive|undef
name|_GLIBCXX_RES_LIMITS
end_undef

begin_comment
comment|// Define to use concept checking code from the boost libraries.
end_comment

begin_undef
undef|#
directive|undef
name|_GLIBCXX_CONCEPT_CHECKS
end_undef

begin_comment
comment|// Define to use symbol versioning in the shared library.
end_comment

begin_undef
undef|#
directive|undef
name|_GLIBCXX_SYMVER
end_undef

begin_comment
comment|// Define symbol versioning in assember directives. If symbol
end_comment

begin_comment
comment|// versioning is beigng used, and the assembler supports this kind of
end_comment

begin_comment
comment|// thing, then use it.
end_comment

begin_comment
comment|// NB: _GLIBCXX_AT_AT is a hack to work around quoting issues in m4.
end_comment

begin_if
if|#
directive|if
name|_GLIBCXX_SYMVER
end_if

begin_define
define|#
directive|define
name|_GLIBCXX_ASM_SYMVER
parameter_list|(
name|cur
parameter_list|,
name|old
parameter_list|,
name|version
parameter_list|)
define|\
value|asm (".symver " #cur "," #old _GLIBCXX_AT_AT #version);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_GLIBCXX_ASM_SYMVER
parameter_list|(
name|cur
parameter_list|,
name|old
parameter_list|,
name|version
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Define if LFS support is available.
end_comment

begin_undef
undef|#
directive|undef
name|_GLIBCXX_USE_LFS
end_undef

begin_comment
comment|// Define if a fully dynamic basic_string is wanted.
end_comment

begin_undef
undef|#
directive|undef
name|_GLIBCXX_FULLY_DYNAMIC_STRING
end_undef

begin_comment
comment|// Define if NLS translations are to be used.
end_comment

begin_undef
undef|#
directive|undef
name|_GLIBCXX_USE_NLS
end_undef

begin_comment
comment|// Define if gthr-default.h exists (meaning that threading support is enabled).
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GTHR_DEFAULT
end_undef

begin_comment
comment|// Define if the atan2f function exists.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ATAN2F
end_undef

begin_comment
comment|// Define if the atan2l function exists.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ATAN2L
end_undef

begin_comment
comment|// Define if the tanl function exists.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_TANL
end_undef

begin_comment
comment|// Define if the copysignf function exists.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_COPYSIGNF
end_undef

begin_comment
comment|// Define if getpagesize exists.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GETPAGESIZE
end_undef

begin_comment
comment|// Define if setenv exists.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SETENV
end_undef

begin_comment
comment|// Define if sigsetjmp exists.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SIGSETJMP
end_undef

begin_comment
comment|// Define if mbstate_t exists in wchar.h.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_MBSTATE_T
end_undef

begin_comment
comment|// Define if you have the modff function.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_MODFF
end_undef

begin_comment
comment|// Define if you have the modfl function.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_MODFL
end_undef

begin_comment
comment|// Define if you have the expf function.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_EXPF
end_undef

begin_comment
comment|// Define if you have the expl function.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_EXPL
end_undef

begin_comment
comment|// Define if you have the hypot function.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_HYPOT
end_undef

begin_comment
comment|// Define if you have the hypotf function.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_HYPOTF
end_undef

begin_comment
comment|// Define if you have the hypotl function.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_HYPOTL
end_undef

begin_comment
comment|// Define if the compiler/host combination has __builtin_abs
end_comment

begin_undef
undef|#
directive|undef
name|HAVE___BUILTIN_ABS
end_undef

begin_comment
comment|// Define if the compiler/host combination has __builtin_labs
end_comment

begin_undef
undef|#
directive|undef
name|HAVE___BUILTIN_LABS
end_undef

begin_comment
comment|// Define if the compiler/host combination has __builtin_cos
end_comment

begin_undef
undef|#
directive|undef
name|HAVE___BUILTIN_COS
end_undef

begin_comment
comment|// Define if the compiler/host combination has __builtin_cosf
end_comment

begin_undef
undef|#
directive|undef
name|HAVE___BUILTIN_COSF
end_undef

begin_comment
comment|// Define if the compiler/host combination has __builtin_cosl
end_comment

begin_undef
undef|#
directive|undef
name|HAVE___BUILTIN_COSL
end_undef

begin_comment
comment|// Define if the compiler/host combination has __builtin_fabs
end_comment

begin_undef
undef|#
directive|undef
name|HAVE___BUILTIN_FABS
end_undef

begin_comment
comment|// Define if the compiler/host combination has __builtin_fabsf
end_comment

begin_undef
undef|#
directive|undef
name|HAVE___BUILTIN_FABSF
end_undef

begin_comment
comment|// Define if the compiler/host combination has __builtin_fabsl
end_comment

begin_undef
undef|#
directive|undef
name|HAVE___BUILTIN_FABSL
end_undef

begin_comment
comment|// Define if the compiler/host combination has __builtin_sin
end_comment

begin_undef
undef|#
directive|undef
name|HAVE___BUILTIN_SIN
end_undef

begin_comment
comment|// Define if the compiler/host combination has __builtin_sinf
end_comment

begin_undef
undef|#
directive|undef
name|HAVE___BUILTIN_SINF
end_undef

begin_comment
comment|// Define if the compiler/host combination has __builtin_sinl
end_comment

begin_undef
undef|#
directive|undef
name|HAVE___BUILTIN_SINL
end_undef

begin_comment
comment|// Define if the compiler/host combination has __builtin_sqrt
end_comment

begin_undef
undef|#
directive|undef
name|HAVE___BUILTIN_SQRT
end_undef

begin_comment
comment|// Define if the compiler/host combination has __builtin_sqrtf
end_comment

begin_undef
undef|#
directive|undef
name|HAVE___BUILTIN_SQRTF
end_undef

begin_comment
comment|// Define if the compiler/host combination has __builtin_sqrtl
end_comment

begin_undef
undef|#
directive|undef
name|HAVE___BUILTIN_SQRTL
end_undef

begin_comment
comment|// Define if poll is available in<poll.h>.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_POLL
end_undef

begin_comment
comment|// Define if S_ISREG (Posix) is available in<sys/stat.h>.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_S_ISREG
end_undef

begin_comment
comment|// Define if S_IFREG is available in<sys/stat.h>.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_S_IFREG
end_undef

begin_comment
comment|// Define if writev is available in<sys/uio.h>.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_WRITEV
end_undef

begin_comment
comment|// Define if int64_t is available in<stdint.h>.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_INT64_T
end_undef

begin_comment
comment|// Define if LC_MESSAGES is available in<locale.h>.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_LC_MESSAGES
end_undef

begin_comment
comment|// Define if<float.h> exists.
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_FLOAT_H
end_undef

begin_comment
comment|// Define if modf is present in<math.h>
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_MODF
end_undef

begin_comment
comment|// @BOTTOM@
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Systems that have certain non-standard functions prefixed with an
end_comment

begin_comment
comment|// underscore, we'll handle those here. Must come after config.h.in.
end_comment

begin_comment
comment|//
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__ISNAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ISNAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ISNAN
value|1
end_define

begin_define
define|#
directive|define
name|isnan
value|_isnan
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__ISNANF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ISNANF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ISNANF
value|1
end_define

begin_define
define|#
directive|define
name|isnanf
value|_isnanf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__ISNANL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ISNANL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ISNANL
value|1
end_define

begin_define
define|#
directive|define
name|isnanl
value|_isnanl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__ISINF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ISINF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ISINF
value|1
end_define

begin_define
define|#
directive|define
name|isinf
value|_isinf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__ISINFF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ISINFF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ISINFF
value|1
end_define

begin_define
define|#
directive|define
name|isinff
value|_isinff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__ISINFL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ISINFL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ISINFL
value|1
end_define

begin_define
define|#
directive|define
name|isinfl
value|_isinfl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__COPYSIGN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_COPYSIGN
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_COPYSIGN
value|1
end_define

begin_define
define|#
directive|define
name|copysign
value|_copysign
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__COPYSIGNL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_COPYSIGNL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_COPYSIGNL
value|1
end_define

begin_define
define|#
directive|define
name|copysignl
value|_copysignl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__COSF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_COSF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_COSF
value|1
end_define

begin_define
define|#
directive|define
name|cosf
value|_cosf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__ACOSF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ACOSF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ACOSF
value|1
end_define

begin_define
define|#
directive|define
name|acosf
value|_acosf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__ACOSL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ACOSL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ACOSL
value|1
end_define

begin_define
define|#
directive|define
name|acosl
value|_acosl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__ASINF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ASINF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ASINF
value|1
end_define

begin_define
define|#
directive|define
name|asinf
value|_asinf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__ASINL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ASINL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ASINL
value|1
end_define

begin_define
define|#
directive|define
name|asinl
value|_asinl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__ATANF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ATANF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ATANF
value|1
end_define

begin_define
define|#
directive|define
name|atanf
value|_atanf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__ATANL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ATANL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ATANL
value|1
end_define

begin_define
define|#
directive|define
name|atanl
value|_atanl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__CEILF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_CEILF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_CEILF
value|1
end_define

begin_define
define|#
directive|define
name|aceil
value|_ceilf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__CEILL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_CEILL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_CEILL
value|1
end_define

begin_define
define|#
directive|define
name|aceil
value|_ceill
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__COSHF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_COSHF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_COSHF
value|1
end_define

begin_define
define|#
directive|define
name|coshf
value|_coshf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__COSL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_COSL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_COSL
value|1
end_define

begin_define
define|#
directive|define
name|cosl
value|_cosl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__LOGF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_LOGF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_LOGF
value|1
end_define

begin_define
define|#
directive|define
name|logf
value|_logf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__COSHL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_COSHL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_COSHL
value|1
end_define

begin_define
define|#
directive|define
name|coshl
value|_coshl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__EXPF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EXPF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_EXPF
value|1
end_define

begin_define
define|#
directive|define
name|expf
value|_expf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__EXPL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EXPL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_EXPL
value|1
end_define

begin_define
define|#
directive|define
name|expl
value|_expl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__FABSF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_FABSF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_FABSF
value|1
end_define

begin_define
define|#
directive|define
name|fabsf
value|_fabsf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__FABSL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_FABSL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_FABSL
value|1
end_define

begin_define
define|#
directive|define
name|fabsl
value|_fabsl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__FLOORF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_FLOORF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_FLOORF
value|1
end_define

begin_define
define|#
directive|define
name|floorf
value|_floorf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__FLOORL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_FLOORL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_FLOORL
value|1
end_define

begin_define
define|#
directive|define
name|floorl
value|_floorl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__FMODF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_FMODF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_FMODF
value|1
end_define

begin_define
define|#
directive|define
name|fmodf
value|_fmodf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__FMODL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_FMODL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_FMODL
value|1
end_define

begin_define
define|#
directive|define
name|fmodl
value|_fmodl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__FREXPF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_FREXPF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_FREXPF
value|1
end_define

begin_define
define|#
directive|define
name|frexpf
value|_frexpf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__FREXPL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_FREXPL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_FREXPL
value|1
end_define

begin_define
define|#
directive|define
name|frexpl
value|_frexpl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__LDEXPF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_LDEXPF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_LDEXPF
value|1
end_define

begin_define
define|#
directive|define
name|ldexpf
value|_ldexpf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__LDEXPL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_LDEXPL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_LDEXPL
value|1
end_define

begin_define
define|#
directive|define
name|ldexpl
value|_ldexpl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__LOG10F
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_LOG10F
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_LOG10F
value|1
end_define

begin_define
define|#
directive|define
name|log10f
value|_log10f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__LOGL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_LOGL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_LOGL
value|1
end_define

begin_define
define|#
directive|define
name|logl
value|_logl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__POWF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_POWF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_POWF
value|1
end_define

begin_define
define|#
directive|define
name|powf
value|_powf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__LOG10L
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_LOG10L
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_LOG10L
value|1
end_define

begin_define
define|#
directive|define
name|log10l
value|_log10l
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__MODF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_MODF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_MODF
value|1
end_define

begin_define
define|#
directive|define
name|modf
value|_modf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__MODL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_MODL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_MODL
value|1
end_define

begin_define
define|#
directive|define
name|modl
value|_modl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__SINF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SINF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SINF
value|1
end_define

begin_define
define|#
directive|define
name|sinf
value|_sinf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__POWL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_POWL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_POWL
value|1
end_define

begin_define
define|#
directive|define
name|powl
value|_powl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__SINHF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SINHF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SINHF
value|1
end_define

begin_define
define|#
directive|define
name|sinhf
value|_sinhf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__SINL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SINL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SINL
value|1
end_define

begin_define
define|#
directive|define
name|sinl
value|_sinl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__SQRTF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SQRTF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SQRTF
value|1
end_define

begin_define
define|#
directive|define
name|sqrtf
value|_sqrtf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__SINHL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SINHL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SINHL
value|1
end_define

begin_define
define|#
directive|define
name|sinhl
value|_sinhl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__TANF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_TANF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_TANF
value|1
end_define

begin_define
define|#
directive|define
name|tanf
value|_tanf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__SQRTL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SQRTL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SQRTL
value|1
end_define

begin_define
define|#
directive|define
name|sqrtl
value|_sqrtl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__TANHF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_TANHF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_TANHF
value|1
end_define

begin_define
define|#
directive|define
name|tanhf
value|_tanhf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__TANL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_TANL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_TANF
value|1
end_define

begin_define
define|#
directive|define
name|tanf
value|_tanf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__STRTOF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_STRTOF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_STRTOF
value|1
end_define

begin_define
define|#
directive|define
name|strtof
value|_strtof
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__TANHL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_TANHL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_TANHL
value|1
end_define

begin_define
define|#
directive|define
name|tanhl
value|_tanhl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__STRTOLD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_STRTOLD
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_STRTOLD
value|1
end_define

begin_define
define|#
directive|define
name|strtold
value|_strtold
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__SINCOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SINCOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SINCOS
value|1
end_define

begin_define
define|#
directive|define
name|sincos
value|_sincos
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__SINCOSF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SINCOSF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SINCOSF
value|1
end_define

begin_define
define|#
directive|define
name|sincosf
value|_sincosf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__SINCOSL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SINCOSL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SINCOSL
value|1
end_define

begin_define
define|#
directive|define
name|sincosl
value|_sincosl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__FINITE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_FINITE
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_FINITE
value|1
end_define

begin_define
define|#
directive|define
name|finite
value|_finite
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__FINITEF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_FINITEF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_FINITEF
value|1
end_define

begin_define
define|#
directive|define
name|finitef
value|_finitef
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__FINITEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_FINITEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_FINITEL
value|1
end_define

begin_define
define|#
directive|define
name|finitel
value|_finitel
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__QFINITE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_QFINITE
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_QFINITE
value|1
end_define

begin_define
define|#
directive|define
name|qfinite
value|_qfinite
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__FPCLASS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_FPCLASS
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_FPCLASS
value|1
end_define

begin_define
define|#
directive|define
name|fpclass
value|_fpclass
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE__QFPCLASS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_QFPCLASS
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_QFPCLASS
value|1
end_define

begin_define
define|#
directive|define
name|qfpclass
value|_qfpclass
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

