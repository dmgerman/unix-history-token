begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: softfloat.h,v 1.6 2002/05/12 13:12:46 bjh21 Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* This is a derivative work. */
end_comment

begin_comment
comment|/* ===============================================================================  This C header file is part of the SoftFloat IEC/IEEE Floating-point Arithmetic Package, Release 2a.  Written by John R. Hauser.  This work was made possible in part by the International Computer Science Institute, located at Suite 600, 1947 Center Street, Berkeley, California 94704.  Funding was partially provided by the National Science Foundation under grant MIP-9311980.  The original version of this code was written as part of a project to build a fixed-point vector processor in collaboration with the University of California at Berkeley, overseen by Profs. Nelson Morgan and John Wawrzynek.  More information is available through the Web page `http://HTTP.CS.Berkeley.EDU/~jhauser/ arithmetic/SoftFloat.html'.  THIS SOFTWARE IS DISTRIBUTED AS IS, FOR FREE.  Although reasonable effort has been made to avoid it, THIS SOFTWARE MAY CONTAIN FAULTS THAT WILL AT TIMES RESULT IN INCORRECT BEHAVIOR.  USE OF THIS SOFTWARE IS RESTRICTED TO PERSONS AND ORGANIZATIONS WHO CAN AND WILL TAKE FULL RESPONSIBILITY FOR ANY AND ALL LOSSES, COSTS, OR OTHER PROBLEMS ARISING FROM ITS USE.  Derivative works are acceptable, even for commercial purposes, so long as (1) they include prominent notice that the work is derivative, and (2) they include prominent notice akin to these four paragraphs for those parts of this code that are retained.  =============================================================================== */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------------- The macro `FLOATX80' must be defined to enable the extended double-precision floating-point format `floatx80'.  If this macro is not defined, the `floatx80' type will not be defined, and none of the functions that either input or output the `floatx80' type will be defined.  The same applies to the `FLOAT128' macro and the quadruple-precision format `float128'. ------------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* #define FLOATX80 */
end_comment

begin_comment
comment|/* #define FLOAT128 */
end_comment

begin_include
include|#
directive|include
file|<machine/ieeefp.h>
end_include

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE floating-point types. ------------------------------------------------------------------------------- */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|float32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|float64
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|FLOATX80
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|high
decl_stmt|;
name|unsigned
name|long
name|long
name|low
decl_stmt|;
block|}
name|floatx80
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FLOAT128
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|long
name|high
decl_stmt|,
name|low
decl_stmt|;
block|}
name|float128
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE floating-point underflow tininess-detection mode. ------------------------------------------------------------------------------- */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|float_detect_tininess
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
block|{
name|float_tininess_after_rounding
init|=
literal|0
block|,
name|float_tininess_before_rounding
init|=
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE floating-point rounding mode. ------------------------------------------------------------------------------- */
end_comment

begin_decl_stmt
specifier|extern
name|fp_rnd_t
name|float_rounding_mode
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
block|{
name|float_round_nearest_even
init|=
name|FP_RN
block|,
name|float_round_to_zero
init|=
name|FP_RZ
block|,
name|float_round_down
init|=
name|FP_RM
block|,
name|float_round_up
init|=
name|FP_RP
block|}
enum|;
end_enum

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE floating-point exception flags. ------------------------------------------------------------------------------- */
end_comment

begin_decl_stmt
specifier|extern
name|fp_except
name|float_exception_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fp_except
name|float_exception_mask
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
block|{
name|float_flag_inexact
init|=
name|FP_X_IMP
block|,
name|float_flag_underflow
init|=
name|FP_X_UFL
block|,
name|float_flag_overflow
init|=
name|FP_X_OFL
block|,
name|float_flag_divbyzero
init|=
name|FP_X_DZ
block|,
name|float_flag_invalid
init|=
name|FP_X_INV
block|}
enum|;
end_enum

begin_comment
comment|/* ------------------------------------------------------------------------------- Routine to raise any or all of the software IEC/IEEE floating-point exception flags. ------------------------------------------------------------------------------- */
end_comment

begin_function_decl
name|void
name|float_raise
parameter_list|(
name|fp_except
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE integer-to-floating-point conversion routines. ------------------------------------------------------------------------------- */
end_comment

begin_function_decl
name|float32
name|int32_to_float32
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|int32_to_float64
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FLOATX80
end_ifdef

begin_function_decl
name|floatx80
name|int32_to_floatx80
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FLOAT128
end_ifdef

begin_function_decl
name|float128
name|int32_to_float128
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
name|SOFTFLOAT_FOR_GCC
end_ifndef

begin_comment
comment|/* __floatdi?f is in libgcc2.c */
end_comment

begin_function_decl
name|float32
name|int64_to_float32
parameter_list|(
name|long
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|int64_to_float64
parameter_list|(
name|long
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FLOATX80
end_ifdef

begin_function_decl
name|floatx80
name|int64_to_floatx80
parameter_list|(
name|long
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FLOAT128
end_ifdef

begin_function_decl
name|float128
name|int64_to_float128
parameter_list|(
name|long
name|long
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
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE single-precision conversion routines. ------------------------------------------------------------------------------- */
end_comment

begin_function_decl
name|int
name|float32_to_int32
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float32_to_int32_round_to_zero
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOFTFLOAT_FOR_GCC
argument_list|)
operator|&&
name|defined
argument_list|(
name|SOFTFLOAT_NEED_FIXUNS
argument_list|)
end_if

begin_function_decl
name|unsigned
name|int
name|float32_to_uint32_round_to_zero
parameter_list|(
name|float32
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
name|SOFTFLOAT_FOR_GCC
end_ifndef

begin_comment
comment|/* __fix?fdi provided by libgcc2.c */
end_comment

begin_function_decl
name|long
name|long
name|float32_to_int64
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|long
name|float32_to_int64_round_to_zero
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|float64
name|float32_to_float64
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FLOATX80
end_ifdef

begin_function_decl
name|floatx80
name|float32_to_floatx80
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FLOAT128
end_ifdef

begin_function_decl
name|float128
name|float32_to_float128
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE single-precision operations. ------------------------------------------------------------------------------- */
end_comment

begin_function_decl
name|float32
name|float32_round_to_int
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|float32_add
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|float32_sub
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|float32_mul
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|float32_div
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|float32_rem
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|float32_sqrt
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float32_eq
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float32_le
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float32_lt
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float32_eq_signaling
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float32_le_quiet
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float32_lt_quiet
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|SOFTFLOAT_FOR_GCC
end_ifndef

begin_function_decl
name|int
name|float32_is_signaling_nan
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE double-precision conversion routines. ------------------------------------------------------------------------------- */
end_comment

begin_function_decl
name|int
name|float64_to_int32
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float64_to_int32_round_to_zero
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOFTFLOAT_FOR_GCC
argument_list|)
operator|&&
name|defined
argument_list|(
name|SOFTFLOAT_NEED_FIXUNS
argument_list|)
end_if

begin_function_decl
name|unsigned
name|int
name|float64_to_uint32_round_to_zero
parameter_list|(
name|float64
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
name|SOFTFLOAT_FOR_GCC
end_ifndef

begin_comment
comment|/* __fix?fdi provided by libgcc2.c */
end_comment

begin_function_decl
name|long
name|long
name|float64_to_int64
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|long
name|float64_to_int64_round_to_zero
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|float32
name|float64_to_float32
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FLOATX80
end_ifdef

begin_function_decl
name|floatx80
name|float64_to_floatx80
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FLOAT128
end_ifdef

begin_function_decl
name|float128
name|float64_to_float128
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE double-precision operations. ------------------------------------------------------------------------------- */
end_comment

begin_function_decl
name|float64
name|float64_round_to_int
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|float64_add
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|float64_sub
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|float64_mul
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|float64_div
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|float64_rem
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|float64_sqrt
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float64_eq
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float64_le
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float64_lt
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float64_eq_signaling
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float64_le_quiet
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float64_lt_quiet
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|SOFTFLOAT_FOR_GCC
end_ifndef

begin_function_decl
name|int
name|float64_is_signaling_nan
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FLOATX80
end_ifdef

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE extended double-precision conversion routines. ------------------------------------------------------------------------------- */
end_comment

begin_function_decl
name|int
name|floatx80_to_int32
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|floatx80_to_int32_round_to_zero
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|long
name|floatx80_to_int64
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|long
name|floatx80_to_int64_round_to_zero
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|floatx80_to_float32
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|floatx80_to_float64
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FLOAT128
end_ifdef

begin_function_decl
name|float128
name|floatx80_to_float128
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE extended double-precision rounding precision.  Valid values are 32, 64, and 80. ------------------------------------------------------------------------------- */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|floatx80_rounding_precision
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE extended double-precision operations. ------------------------------------------------------------------------------- */
end_comment

begin_function_decl
name|floatx80
name|floatx80_round_to_int
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|floatx80_add
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|floatx80_sub
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|floatx80_mul
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|floatx80_div
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|floatx80_rem
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|floatx80_sqrt
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|floatx80_eq
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|floatx80_le
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|floatx80_lt
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|floatx80_eq_signaling
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|floatx80_le_quiet
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|floatx80_lt_quiet
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|floatx80_is_signaling_nan
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FLOAT128
end_ifdef

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE quadruple-precision conversion routines. ------------------------------------------------------------------------------- */
end_comment

begin_function_decl
name|int
name|float128_to_int32
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float128_to_int32_round_to_zero
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|long
name|float128_to_int64
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|long
name|float128_to_int64_round_to_zero
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|float128_to_float32
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|float128_to_float64
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FLOATX80
end_ifdef

begin_function_decl
name|floatx80
name|float128_to_floatx80
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE quadruple-precision operations. ------------------------------------------------------------------------------- */
end_comment

begin_function_decl
name|float128
name|float128_round_to_int
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|float128_add
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|float128_sub
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|float128_mul
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|float128_div
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|float128_rem
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|float128_sqrt
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float128_eq
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float128_le
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float128_lt
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float128_eq_signaling
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float128_le_quiet
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float128_lt_quiet
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|float128_is_signaling_nan
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

