begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===============================================================================  This C header file is part of TestFloat, Release 2a, a package of programs for testing the correctness of floating-point arithmetic complying to the IEC/IEEE Standard for Floating-Point.  Written by John R. Hauser.  More information is available through the Web page `http://HTTP.CS.Berkeley.EDU/~jhauser/arithmetic/TestFloat.html'.  THIS SOFTWARE IS DISTRIBUTED AS IS, FOR FREE.  Although reasonable effort has been made to avoid it, THIS SOFTWARE MAY CONTAIN FAULTS THAT WILL AT TIMES RESULT IN INCORRECT BEHAVIOR.  USE OF THIS SOFTWARE IS RESTRICTED TO PERSONS AND ORGANIZATIONS WHO CAN AND WILL TAKE FULL RESPONSIBILITY FOR ANY AND ALL LOSSES, COSTS, OR OTHER PROBLEMS ARISING FROM ITS USE.  Derivative works are acceptable, even for commercial purposes, so long as (1) they include prominent notice that the work is derivative, and (2) they include prominent notice akin to these four paragraphs for those parts of this code that are retained.  =============================================================================== */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|"softfloat.h"
end_include

begin_include
include|#
directive|include
file|"milieu.h"
end_include

begin_comment
comment|/* ------------------------------------------------------------------------------- The following macros are defined to indicate that the corresponding functions exist. ------------------------------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|SYST_INT32_TO_FLOAT32
end_define

begin_define
define|#
directive|define
name|SYST_INT32_TO_FLOAT64
end_define

begin_define
define|#
directive|define
name|SYST_INT32_TO_FLOAT128
end_define

begin_define
define|#
directive|define
name|SYST_INT64_TO_FLOAT32
end_define

begin_define
define|#
directive|define
name|SYST_INT64_TO_FLOAT64
end_define

begin_define
define|#
directive|define
name|SYST_INT64_TO_FLOAT128
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT32_TO_INT32_ROUND_TO_ZERO
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT32_TO_INT64_ROUND_TO_ZERO
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT32_TO_FLOAT64
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT32_TO_FLOAT128
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT32_ADD
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT32_SUB
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT32_MUL
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT32_DIV
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT32_SQRT
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT32_EQ
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT32_LE
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT32_LT
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT32_EQ_SIGNALING
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT32_LE_QUIET
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT32_LT_QUIET
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT64_TO_INT32_ROUND_TO_ZERO
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT64_TO_INT64_ROUND_TO_ZERO
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT64_TO_FLOAT32
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT64_TO_FLOAT128
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT64_ADD
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT64_SUB
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT64_MUL
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT64_DIV
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT64_SQRT
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT64_EQ
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT64_LE
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT64_LT
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT64_EQ_SIGNALING
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT64_LE_QUIET
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT64_LT_QUIET
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT128_TO_INT32_ROUND_TO_ZERO
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT128_TO_INT64_ROUND_TO_ZERO
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT128_TO_FLOAT32
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT128_TO_FLOAT64
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT128_ADD
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT128_SUB
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT128_MUL
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT128_DIV
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT128_SQRT
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT128_EQ
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT128_LE
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT128_LT
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT128_EQ_SIGNALING
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT128_LE_QUIET
end_define

begin_define
define|#
directive|define
name|SYST_FLOAT128_LT_QUIET
end_define

begin_comment
comment|/* ------------------------------------------------------------------------------- System function declarations.  (Some of these functions may not exist.) ------------------------------------------------------------------------------- */
end_comment

begin_function_decl
name|float32
name|syst_int32_to_float32
parameter_list|(
name|int32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|syst_int32_to_float64
parameter_list|(
name|int32
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
name|syst_int32_to_floatx80
parameter_list|(
name|int32
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
name|syst_int32_to_float128
parameter_list|(
name|int32
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
name|BITS64
end_ifdef

begin_function_decl
name|float32
name|syst_int64_to_float32
parameter_list|(
name|int64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|syst_int64_to_float64
parameter_list|(
name|int64
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
name|syst_int64_to_floatx80
parameter_list|(
name|int64
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
name|syst_int64_to_float128
parameter_list|(
name|int64
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

begin_function_decl
name|int32
name|syst_float32_to_int32
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32
name|syst_float32_to_int32_round_to_zero
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|BITS64
end_ifdef

begin_function_decl
name|int64
name|syst_float32_to_int64
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int64
name|syst_float32_to_int64_round_to_zero
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
name|syst_float32_to_float64
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
name|syst_float32_to_floatx80
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
name|syst_float32_to_float128
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
name|float32
name|syst_float32_round_to_int
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|syst_float32_add
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|syst_float32_sub
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|syst_float32_mul
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|syst_float32_div
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|syst_float32_rem
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|syst_float32_sqrt
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float32_eq
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float32_le
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float32_lt
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float32_eq_signaling
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float32_le_quiet
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float32_lt_quiet
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32
name|syst_float64_to_int32
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32
name|syst_float64_to_int32_round_to_zero
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|BITS64
end_ifdef

begin_function_decl
name|int64
name|syst_float64_to_int64
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int64
name|syst_float64_to_int64_round_to_zero
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
name|syst_float64_to_float32
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
name|syst_float64_to_floatx80
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
name|syst_float64_to_float128
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
name|float64
name|syst_float64_round_to_int
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|syst_float64_add
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|syst_float64_sub
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|syst_float64_mul
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|syst_float64_div
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|syst_float64_rem
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|syst_float64_sqrt
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float64_eq
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float64_le
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float64_lt
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float64_eq_signaling
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float64_le_quiet
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float64_lt_quiet
parameter_list|(
name|float64
parameter_list|,
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
name|int32
name|syst_floatx80_to_int32
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32
name|syst_floatx80_to_int32_round_to_zero
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|BITS64
end_ifdef

begin_function_decl
name|int64
name|syst_floatx80_to_int64
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int64
name|syst_floatx80_to_int64_round_to_zero
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|float32
name|syst_floatx80_to_float32
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|syst_floatx80_to_float64
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
name|syst_floatx80_to_float128
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|floatx80
name|syst_floatx80_round_to_int
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|syst_floatx80_add
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|syst_floatx80_sub
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|syst_floatx80_mul
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|syst_floatx80_div
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|syst_floatx80_rem
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|syst_floatx80_sqrt
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_floatx80_eq
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_floatx80_le
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_floatx80_lt
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_floatx80_eq_signaling
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_floatx80_le_quiet
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_floatx80_lt_quiet
parameter_list|(
name|floatx80
parameter_list|,
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

begin_function_decl
name|int32
name|syst_float128_to_int32
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32
name|syst_float128_to_int32_round_to_zero
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|BITS64
end_ifdef

begin_function_decl
name|int64
name|syst_float128_to_int64
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int64
name|syst_float128_to_int64_round_to_zero
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|float32
name|syst_float128_to_float32
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|syst_float128_to_float64
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
name|syst_float128_to_floatx80
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|float128
name|syst_float128_round_to_int
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|syst_float128_add
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|syst_float128_sub
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|syst_float128_mul
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|syst_float128_div
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|syst_float128_rem
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|syst_float128_sqrt
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float128_eq
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float128_le
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float128_lt
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float128_eq_signaling
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float128_le_quiet
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|syst_float128_lt_quiet
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

