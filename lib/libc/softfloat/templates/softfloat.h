begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* ===============================================================================  This C header file is part of the SoftFloat IEC/IEEE Floating-point Arithmetic Package, Release 2a.  Written by John R. Hauser.  This work was made possible in part by the International Computer Science Institute, located at Suite 600, 1947 Center Street, Berkeley, California 94704.  Funding was partially provided by the National Science Foundation under grant MIP-9311980.  The original version of this code was written as part of a project to build a fixed-point vector processor in collaboration with the University of California at Berkeley, overseen by Profs. Nelson Morgan and John Wawrzynek.  More information is available through the Web page `http://HTTP.CS.Berkeley.EDU/~jhauser/ arithmetic/SoftFloat.html'.  THIS SOFTWARE IS DISTRIBUTED AS IS, FOR FREE.  Although reasonable effort has been made to avoid it, THIS SOFTWARE MAY CONTAIN FAULTS THAT WILL AT TIMES RESULT IN INCORRECT BEHAVIOR.  USE OF THIS SOFTWARE IS RESTRICTED TO PERSONS AND ORGANIZATIONS WHO CAN AND WILL TAKE FULL RESPONSIBILITY FOR ANY AND ALL LOSSES, COSTS, OR OTHER PROBLEMS ARISING FROM ITS USE.  Derivative works are acceptable, even for commercial purposes, so long as (1) they include prominent notice that the work is derivative, and (2) they include prominent notice akin to these four paragraphs for those parts of this code that are retained.  =============================================================================== */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------------- The macro `FLOATX80' must be defined to enable the extended double-precision floating-point format `floatx80'.  If this macro is not defined, the `floatx80' type will not be defined, and none of the functions that either input or output the `floatx80' type will be defined.  The same applies to the `FLOAT128' macro and the quadruple-precision format `float128'. ------------------------------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|FLOATX80
end_define

begin_define
define|#
directive|define
name|FLOAT128
end_define

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE floating-point types. ------------------------------------------------------------------------------- */
end_comment

begin_typedef
typedef|typedef
operator|!
operator|!
operator|!
name|bits32
name|float32
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
operator|!
operator|!
operator|!
name|bits64
name|float64
expr_stmt|;
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
operator|!
operator|!
operator|!
name|bits16
name|high
expr_stmt|;
operator|!
operator|!
operator|!
name|bits64
name|low
expr_stmt|;
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
operator|!
operator|!
operator|!
name|bits64
name|high
operator|,
name|low
expr_stmt|;
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

begin_extern
extern|extern !!!int8 float_detect_tininess;
end_extern

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

begin_extern
extern|extern !!!int8 float_rounding_mode;
end_extern

begin_enum
enum|enum
block|{
name|float_round_nearest_even
init|=
literal|0
block|,
name|float_round_to_zero
init|=
literal|1
block|,
name|float_round_down
init|=
literal|2
block|,
name|float_round_up
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE floating-point exception flags. ------------------------------------------------------------------------------- */
end_comment

begin_extern
extern|extern !!!int8 float_exception_flags;
end_extern

begin_enum
enum|enum
block|{
name|float_flag_inexact
init|=
literal|1
block|,
name|float_flag_underflow
init|=
literal|2
block|,
name|float_flag_overflow
init|=
literal|4
block|,
name|float_flag_divbyzero
init|=
literal|8
block|,
name|float_flag_invalid
init|=
literal|16
block|}
enum|;
end_enum

begin_comment
comment|/* ------------------------------------------------------------------------------- Routine to raise any or all of the software IEC/IEEE floating-point exception flags. ------------------------------------------------------------------------------- */
end_comment

begin_decl_stmt
name|void
name|float_raise
argument_list|(
operator|!
operator|!
operator|!
name|int8
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE integer-to-floating-point conversion routines. ------------------------------------------------------------------------------- */
end_comment

begin_decl_stmt
name|float32
name|int32_to_float32
argument_list|(
operator|!
operator|!
operator|!
name|int32
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float64
name|int32_to_float64
argument_list|(
operator|!
operator|!
operator|!
name|int32
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|FLOATX80
end_ifdef

begin_decl_stmt
name|floatx80
name|int32_to_floatx80
argument_list|(
operator|!
operator|!
operator|!
name|int32
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FLOAT128
end_ifdef

begin_decl_stmt
name|float128
name|int32_to_float128
argument_list|(
operator|!
operator|!
operator|!
name|int32
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|float32
name|int64_to_float32
argument_list|(
operator|!
operator|!
operator|!
name|int64
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float64
name|int64_to_float64
argument_list|(
operator|!
operator|!
operator|!
name|int64
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|FLOATX80
end_ifdef

begin_decl_stmt
name|floatx80
name|int64_to_floatx80
argument_list|(
operator|!
operator|!
operator|!
name|int64
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FLOAT128
end_ifdef

begin_decl_stmt
name|float128
name|int64_to_float128
argument_list|(
operator|!
operator|!
operator|!
name|int64
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE single-precision conversion routines. ------------------------------------------------------------------------------- */
end_comment

begin_expr_stmt
operator|!
operator|!
operator|!
name|int32
name|float32_to_int32
argument_list|(
name|float32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|int32
name|float32_to_int32_round_to_zero
argument_list|(
name|float32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|int64
name|float32_to_int64
argument_list|(
name|float32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|int64
name|float32_to_int64_round_to_zero
argument_list|(
name|float32
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float32_eq
argument_list|(
name|float32
argument_list|,
name|float32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float32_le
argument_list|(
name|float32
argument_list|,
name|float32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float32_lt
argument_list|(
name|float32
argument_list|,
name|float32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float32_eq_signaling
argument_list|(
name|float32
argument_list|,
name|float32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float32_le_quiet
argument_list|(
name|float32
argument_list|,
name|float32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float32_lt_quiet
argument_list|(
name|float32
argument_list|,
name|float32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float32_is_signaling_nan
argument_list|(
name|float32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE double-precision conversion routines. ------------------------------------------------------------------------------- */
end_comment

begin_expr_stmt
operator|!
operator|!
operator|!
name|int32
name|float64_to_int32
argument_list|(
name|float64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|int32
name|float64_to_int32_round_to_zero
argument_list|(
name|float64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|int64
name|float64_to_int64
argument_list|(
name|float64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|int64
name|float64_to_int64_round_to_zero
argument_list|(
name|float64
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float64_eq
argument_list|(
name|float64
argument_list|,
name|float64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float64_le
argument_list|(
name|float64
argument_list|,
name|float64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float64_lt
argument_list|(
name|float64
argument_list|,
name|float64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float64_eq_signaling
argument_list|(
name|float64
argument_list|,
name|float64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float64_le_quiet
argument_list|(
name|float64
argument_list|,
name|float64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float64_lt_quiet
argument_list|(
name|float64
argument_list|,
name|float64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float64_is_signaling_nan
argument_list|(
name|float64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|FLOATX80
end_ifdef

begin_comment
comment|/* ------------------------------------------------------------------------------- Software IEC/IEEE extended double-precision conversion routines. ------------------------------------------------------------------------------- */
end_comment

begin_expr_stmt
operator|!
operator|!
operator|!
name|int32
name|floatx80_to_int32
argument_list|(
name|floatx80
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|int32
name|floatx80_to_int32_round_to_zero
argument_list|(
name|floatx80
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|int64
name|floatx80_to_int64
argument_list|(
name|floatx80
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|int64
name|floatx80_to_int64_round_to_zero
argument_list|(
name|floatx80
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_extern
extern|extern !!!int8 floatx80_rounding_precision;
end_extern

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

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|floatx80_eq
argument_list|(
name|floatx80
argument_list|,
name|floatx80
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|floatx80_le
argument_list|(
name|floatx80
argument_list|,
name|floatx80
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|floatx80_lt
argument_list|(
name|floatx80
argument_list|,
name|floatx80
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|floatx80_eq_signaling
argument_list|(
name|floatx80
argument_list|,
name|floatx80
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|floatx80_le_quiet
argument_list|(
name|floatx80
argument_list|,
name|floatx80
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|floatx80_lt_quiet
argument_list|(
name|floatx80
argument_list|,
name|floatx80
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|floatx80_is_signaling_nan
argument_list|(
name|floatx80
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
operator|!
operator|!
operator|!
name|int32
name|float128_to_int32
argument_list|(
name|float128
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|int32
name|float128_to_int32_round_to_zero
argument_list|(
name|float128
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|int64
name|float128_to_int64
argument_list|(
name|float128
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|int64
name|float128_to_int64_round_to_zero
argument_list|(
name|float128
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float128_eq
argument_list|(
name|float128
argument_list|,
name|float128
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float128_le
argument_list|(
name|float128
argument_list|,
name|float128
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float128_lt
argument_list|(
name|float128
argument_list|,
name|float128
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float128_eq_signaling
argument_list|(
name|float128
argument_list|,
name|float128
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float128_le_quiet
argument_list|(
name|float128
argument_list|,
name|float128
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float128_lt_quiet
argument_list|(
name|float128
argument_list|,
name|float128
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|!
operator|!
operator|!
name|flag
name|float128_is_signaling_nan
argument_list|(
name|float128
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

