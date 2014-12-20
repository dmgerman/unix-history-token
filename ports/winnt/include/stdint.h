begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * stdint_msvc.h - C99 integer types for older Visual C compilers  *  * Written by Juergen Perlinger (perlinger@ntp.org) for the NTP project.  * The contents of 'html/copyright.html' apply.  *  * ----------------------------------------------------------------------  *  * Fairly straight forward implementation of the C99 standard integer  * types.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDINT_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|__STDINT_INCLUDED
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|_MSC_VER
operator|>=
literal|1800
end_if

begin_error
error|#
directive|error
error|Use only with MSVC6 - MSVC11(VS2012)
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<crtdefs.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_comment
comment|/* ---------------------------------------------------------------------  * We declare the min/max values, using the MSVC syntax for literals of  * a given bit width.  */
end_comment

begin_define
define|#
directive|define
name|_VC_SI_LIT
parameter_list|(
name|lit
parameter_list|,
name|wbit
parameter_list|)
value|(lit ##  i ## wbit)
end_define

begin_define
define|#
directive|define
name|_VC_UI_LIT
parameter_list|(
name|lit
parameter_list|,
name|wbit
parameter_list|)
value|(lit ## ui ## wbit)
end_define

begin_comment
comment|/* ---------------------------------------------------------------------  * Exact width integer types  */
end_comment

begin_typedef
typedef|typedef
name|__int8
name|int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int16
name|int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32
name|int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int8
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int16
name|uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int32
name|uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|uint64_t
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|__STDC_LIMIT_MACROS
argument_list|)
end_if

begin_define
define|#
directive|define
name|INT8_MIN
value|_I8_MIN
end_define

begin_define
define|#
directive|define
name|INT8_MAX
value|_I8_MAX
end_define

begin_define
define|#
directive|define
name|UINT8_MAX
value|_UI8_MAX
end_define

begin_define
define|#
directive|define
name|INT16_MIN
value|_I16_MIN
end_define

begin_define
define|#
directive|define
name|INT16_MAX
value|_I16_MAX
end_define

begin_define
define|#
directive|define
name|UINT16_MAX
value|_UI16_MAX
end_define

begin_define
define|#
directive|define
name|INT32_MIN
value|_I32_MIN
end_define

begin_define
define|#
directive|define
name|INT32_MAX
value|_I32_MAX
end_define

begin_define
define|#
directive|define
name|UINT32_MAX
value|_UI32_MAX
end_define

begin_define
define|#
directive|define
name|INT64_MIN
value|_I64_MIN
end_define

begin_define
define|#
directive|define
name|INT64_MAX
value|_I64_MAX
end_define

begin_define
define|#
directive|define
name|UINT64_MAX
value|_UI64_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ---------------------------------------------------------------------  * Least-size integers  *  * These are mapped to exact size.  */
end_comment

begin_typedef
typedef|typedef
name|__int8
name|int_least8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int16
name|int_least16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32
name|int_least32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64
name|int_least64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int8
name|uint_least8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int16
name|uint_least16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int32
name|uint_least32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|uint_least64_t
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|__STDC_LIMIT_MACROS
argument_list|)
end_if

begin_define
define|#
directive|define
name|INT_LEAST8_MIN
value|_I8_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST8_MAX
value|_I8_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST8_MAX
value|_UI8_MAX
end_define

begin_define
define|#
directive|define
name|INT_LEAST16_MIN
value|_I16_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST16_MAX
value|_I16_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST16_MAX
value|_UI16_MAX
end_define

begin_define
define|#
directive|define
name|INT_LEAST32_MIN
value|_I32_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST32_MAX
value|_I32_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST32_MAX
value|_UI32_MAX
end_define

begin_define
define|#
directive|define
name|INT_LEAST64_MIN
value|_I64_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST64_MAX
value|_I64_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST64_MAX
value|_UI64_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ---------------------------------------------------------------------  * least-size, fastest integer  *  * The 'FAST' types are all 32 bits, except the 64 bit quantity; as the  * natural register width is 32 bits, quantities of that size are fastest  * to operate on naturally. (This even holds for the x86_64; MSVC uses  * the 'llp64' model.  */
end_comment

begin_typedef
typedef|typedef
name|__int32
name|int_fast8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32
name|int_fast16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32
name|int_fast32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64
name|int_fast64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int32
name|uint_fast8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int32
name|uint_fast16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int32
name|uint_fast32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|uint_fast64_t
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|__STDC_LIMIT_MACROS
argument_list|)
end_if

begin_define
define|#
directive|define
name|INT_FAST8_MIN
value|_I32_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST8_MAX
value|_I32_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST8_MAX
value|_UI32_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST16_MIN
value|_I32_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST16_MAX
value|_I32_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST16_MAX
value|_UI32_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST32_MIN
value|_I32_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST32_MAX
value|_I32_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST32_MAX
value|_UI32_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST64_MIN
value|_I64_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST64_MAX
value|_I64_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST64_MAX
value|_UI64_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ---------------------------------------------------------------------  * The (u)intptr_t, ptrdiff_t and size_t definitions depend on the  * target: 32bit for x86, and 64bit for x64, aka amd64. Well, we  * have to bite the bullet.  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN64
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN64
argument_list|)
end_if

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INTPTR_T_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_INTPTR_T_DEFINED
end_define

begin_typedef
typedef|typedef
name|__int64
name|intptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UINTPTR_T_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_UINTPTR_T_DEFINED
end_define

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|uintptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PTRDIFF_T_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_PTRDIFF_T_DEFINED
end_define

begin_typedef
typedef|typedef
name|__int64
name|ptrdiff_t
typedef|;
end_typedef

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
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|__STDC_LIMIT_MACROS
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|INTPTR_MIN
end_ifndef

begin_define
define|#
directive|define
name|INTPTR_MIN
value|_I64_MIN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INTPTR_MAX
end_ifndef

begin_define
define|#
directive|define
name|INTPTR_MAX
value|_I64_MAX
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

begin_define
define|#
directive|define
name|UINTPTR_MAX
value|_UI64_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTRDIFF_MIN
end_ifndef

begin_define
define|#
directive|define
name|PTRDIFF_MIN
value|_I64_MIN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTRDIFF_MAX
end_ifndef

begin_define
define|#
directive|define
name|PTRDIFF_MAX
value|_I64_MAX
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
comment|/* ------------------------------------------------------------------ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* 32 bit target assumed here! */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INTPTR_T_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_INTPTR_T_DEFINED
end_define

begin_typedef
typedef|typedef
name|__int32
name|intptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UINTPTR_T_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_UINTPTR_T_DEFINED
end_define

begin_typedef
typedef|typedef
name|unsigned
name|__int32
name|uintptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PTRDIFF_T_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_PTRDIFF_T_DEFINED
end_define

begin_typedef
typedef|typedef
name|__int64
name|ptrdiff_t
typedef|;
end_typedef

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
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|__STDC_LIMIT_MACROS
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|INTPTR_MIN
end_ifndef

begin_define
define|#
directive|define
name|INTPTR_MIN
value|_I32_MIN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INTPTR_MAX
end_ifndef

begin_define
define|#
directive|define
name|INTPTR_MAX
value|_I32_MAX
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

begin_define
define|#
directive|define
name|UINTPTR_MAX
value|_UI32_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTRDIFF_MIN
end_ifndef

begin_define
define|#
directive|define
name|PTRDIFF_MIN
value|_I32_MIN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTRDIFF_MAX
end_ifndef

begin_define
define|#
directive|define
name|PTRDIFF_MAX
value|_I32_MAX
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
comment|/* platform dependent stuff */
end_comment

begin_comment
comment|/* ---------------------------------------------------------------------  * max integer is 64-bit integer  */
end_comment

begin_typedef
typedef|typedef
name|__int64
name|intmax_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|uintmax_t
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|__STDC_LIMIT_MACROS
argument_list|)
end_if

begin_define
define|#
directive|define
name|INTMAX_MIN
value|_I64_MIN
end_define

begin_define
define|#
directive|define
name|INTMAX_MAX
value|_I64_MAX
end_define

begin_define
define|#
directive|define
name|UINTMAX_MAX
value|_UI64_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ---------------------------------------------------------------------  * limit for size_t (older MSVC versions lack that one)  */
end_comment

begin_if
if|#
directive|if
name|_MSC_VER
operator|<=
literal|1200
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN64
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN64
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIZE_MAX
value|_UI64_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIZE_MAX
value|_UI32_MAX
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
comment|/* ---------------------------------------------------------------------  * construct numerical literals with precise size  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|__STDC_CONSTANT_MACROS
argument_list|)
end_if

begin_define
define|#
directive|define
name|INT8_C
parameter_list|(
name|lit
parameter_list|)
value|_VC_SI_LIT(lit,8)
end_define

begin_define
define|#
directive|define
name|UINT8_C
parameter_list|(
name|lit
parameter_list|)
value|_VC_UI_LIT(lit,8)
end_define

begin_define
define|#
directive|define
name|INT16_C
parameter_list|(
name|lit
parameter_list|)
value|_VC_SI_LIT(lit,16)
end_define

begin_define
define|#
directive|define
name|UINT16_C
parameter_list|(
name|lit
parameter_list|)
value|_VC_UI_LIT(lit,16)
end_define

begin_define
define|#
directive|define
name|INT32_C
parameter_list|(
name|lit
parameter_list|)
value|_VC_SI_LIT(lit,32)
end_define

begin_define
define|#
directive|define
name|UINT32_C
parameter_list|(
name|lit
parameter_list|)
value|_VC_UI_LIT(lit,32)
end_define

begin_define
define|#
directive|define
name|INT64_C
parameter_list|(
name|lit
parameter_list|)
value|_VC_SI_LIT(lit,64)
end_define

begin_define
define|#
directive|define
name|UINT64_C
parameter_list|(
name|lit
parameter_list|)
value|_VC_UI_LIT(lit,64)
end_define

begin_define
define|#
directive|define
name|INTMAX_C
parameter_list|(
name|lit
parameter_list|)
value|_VC_SI_LIT(lit,64)
end_define

begin_define
define|#
directive|define
name|UINTMAX_C
parameter_list|(
name|lit
parameter_list|)
value|_VC_UI_LIT(lit,64)
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
comment|/**** EOF ****/
end_comment

end_unit

