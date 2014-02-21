begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===============================================================================  This C header file is part of TestFloat, Release 2a, a package of programs for testing the correctness of floating-point arithmetic complying to the IEC/IEEE Standard for Floating-Point.  Written by John R. Hauser.  More information is available through the Web page `http://HTTP.CS.Berkeley.EDU/~jhauser/arithmetic/TestFloat.html'.  THIS SOFTWARE IS DISTRIBUTED AS IS, FOR FREE.  Although reasonable effort has been made to avoid it, THIS SOFTWARE MAY CONTAIN FAULTS THAT WILL AT TIMES RESULT IN INCORRECT BEHAVIOR.  USE OF THIS SOFTWARE IS RESTRICTED TO PERSONS AND ORGANIZATIONS WHO CAN AND WILL TAKE FULL RESPONSIBILITY FOR ANY AND ALL LOSSES, COSTS, OR OTHER PROBLEMS ARISING FROM ITS USE.  Derivative works are acceptable, even for commercial purposes, so long as (1) they include prominent notice that the work is derivative, and (2) they include prominent notice akin to these four paragraphs for those parts of this code that are retained.  =============================================================================== */
end_comment

begin_decl_stmt
specifier|extern
name|int8
name|slow_float_rounding_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int8
name|slow_float_exception_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int8
name|slow_float_detect_tininess
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|FLOATX80
end_ifdef

begin_decl_stmt
specifier|extern
name|int8
name|slow_floatx80_rounding_precision
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|float32
name|slow_int32_to_float32
parameter_list|(
name|int32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|slow_int32_to_float64
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
name|slow_int32_to_floatx80
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
name|slow_int32_to_float128
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
name|slow_int64_to_float32
parameter_list|(
name|int64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|slow_int64_to_float64
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
name|slow_int64_to_floatx80
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
name|slow_int64_to_float128
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
name|slow_float32_to_int32
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32
name|slow_float32_to_int32_round_to_zero
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
name|slow_float32_to_int64
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int64
name|slow_float32_to_int64_round_to_zero
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
name|slow_float32_to_float64
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
name|slow_float32_to_floatx80
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
name|slow_float32_to_float128
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
name|slow_float32_round_to_int
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|slow_float32_add
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|slow_float32_sub
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|slow_float32_mul
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|slow_float32_div
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|slow_float32_rem
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float32
name|slow_float32_sqrt
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float32_eq
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float32_le
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float32_lt
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float32_eq_signaling
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float32_le_quiet
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float32_lt_quiet
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32
name|slow_float64_to_int32
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32
name|slow_float64_to_int32_round_to_zero
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
name|slow_float64_to_int64
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int64
name|slow_float64_to_int64_round_to_zero
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
name|slow_float64_to_float32
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
name|slow_float64_to_floatx80
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
name|slow_float64_to_float128
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
name|slow_float64_round_to_int
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|slow_float64_add
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|slow_float64_sub
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|slow_float64_mul
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|slow_float64_div
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|slow_float64_rem
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|slow_float64_sqrt
parameter_list|(
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float64_eq
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float64_le
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float64_lt
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float64_eq_signaling
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float64_le_quiet
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float64_lt_quiet
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
name|slow_floatx80_to_int32
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32
name|slow_floatx80_to_int32_round_to_zero
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
name|slow_floatx80_to_int64
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int64
name|slow_floatx80_to_int64_round_to_zero
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
name|slow_floatx80_to_float32
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|slow_floatx80_to_float64
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
name|slow_floatx80_to_float128
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
name|slow_floatx80_round_to_int
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|slow_floatx80_add
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|slow_floatx80_sub
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|slow_floatx80_mul
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|slow_floatx80_div
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|slow_floatx80_rem
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|floatx80
name|slow_floatx80_sqrt
parameter_list|(
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_floatx80_eq
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_floatx80_le
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_floatx80_lt
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_floatx80_eq_signaling
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_floatx80_le_quiet
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_floatx80_lt_quiet
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
name|slow_float128_to_int32
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32
name|slow_float128_to_int32_round_to_zero
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
name|slow_float128_to_int64
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int64
name|slow_float128_to_int64_round_to_zero
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
name|slow_float128_to_float32
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float64
name|slow_float128_to_float64
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
name|slow_float128_to_floatx80
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
name|slow_float128_round_to_int
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|slow_float128_add
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|slow_float128_sub
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|slow_float128_mul
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|slow_float128_div
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|slow_float128_rem
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float128
name|slow_float128_sqrt
parameter_list|(
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float128_eq
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float128_le
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float128_lt
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float128_eq_signaling
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float128_le_quiet
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|flag
name|slow_float128_lt_quiet
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

