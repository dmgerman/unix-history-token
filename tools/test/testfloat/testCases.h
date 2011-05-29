begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===============================================================================  This C header file is part of TestFloat, Release 2a, a package of programs for testing the correctness of floating-point arithmetic complying to the IEC/IEEE Standard for Floating-Point.  Written by John R. Hauser.  More information is available through the Web page `http://HTTP.CS.Berkeley.EDU/~jhauser/arithmetic/TestFloat.html'.  THIS SOFTWARE IS DISTRIBUTED AS IS, FOR FREE.  Although reasonable effort has been made to avoid it, THIS SOFTWARE MAY CONTAIN FAULTS THAT WILL AT TIMES RESULT IN INCORRECT BEHAVIOR.  USE OF THIS SOFTWARE IS RESTRICTED TO PERSONS AND ORGANIZATIONS WHO CAN AND WILL TAKE FULL RESPONSIBILITY FOR ANY AND ALL LOSSES, COSTS, OR OTHER PROBLEMS ARISING FROM ITS USE.  Derivative works are acceptable, even for commercial purposes, so long as (1) they include prominent notice that the work is derivative, and (2) they include prominent notice akin to these four paragraphs for those parts of this code that are retained.  =============================================================================== */
end_comment

begin_function_decl
name|void
name|testCases_setLevel
parameter_list|(
name|int8
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|testCases_initSequence
parameter_list|(
name|int8
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|testCases_sequence_a_int32
block|,
ifdef|#
directive|ifdef
name|BITS64
name|testCases_sequence_a_int64
block|,
endif|#
directive|endif
name|testCases_sequence_a_float32
block|,
name|testCases_sequence_ab_float32
block|,
name|testCases_sequence_a_float64
block|,
name|testCases_sequence_ab_float64
block|,
ifdef|#
directive|ifdef
name|FLOATX80
name|testCases_sequence_a_floatx80
block|,
name|testCases_sequence_ab_floatx80
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|FLOAT128
name|testCases_sequence_a_float128
block|,
name|testCases_sequence_ab_float128
block|,
endif|#
directive|endif
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|uint32
name|testCases_total
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|flag
name|testCases_done
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|testCases_next
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int32
name|testCases_a_int32
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BITS64
end_ifdef

begin_decl_stmt
specifier|extern
name|int64
name|testCases_a_int64
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|float32
name|testCases_a_float32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float32
name|testCases_b_float32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float64
name|testCases_a_float64
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float64
name|testCases_b_float64
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|FLOATX80
end_ifdef

begin_decl_stmt
specifier|extern
name|floatx80
name|testCases_a_floatx80
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|floatx80
name|testCases_b_floatx80
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
specifier|extern
name|float128
name|testCases_a_float128
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float128
name|testCases_b_float128
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

