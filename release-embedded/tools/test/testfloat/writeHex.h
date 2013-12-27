begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===============================================================================  This C header file is part of TestFloat, Release 2a, a package of programs for testing the correctness of floating-point arithmetic complying to the IEC/IEEE Standard for Floating-Point.  Written by John R. Hauser.  More information is available through the Web page `http://HTTP.CS.Berkeley.EDU/~jhauser/arithmetic/TestFloat.html'.  THIS SOFTWARE IS DISTRIBUTED AS IS, FOR FREE.  Although reasonable effort has been made to avoid it, THIS SOFTWARE MAY CONTAIN FAULTS THAT WILL AT TIMES RESULT IN INCORRECT BEHAVIOR.  USE OF THIS SOFTWARE IS RESTRICTED TO PERSONS AND ORGANIZATIONS WHO CAN AND WILL TAKE FULL RESPONSIBILITY FOR ANY AND ALL LOSSES, COSTS, OR OTHER PROBLEMS ARISING FROM ITS USE.  Derivative works are acceptable, even for commercial purposes, so long as (1) they include prominent notice that the work is derivative, and (2) they include prominent notice akin to these four paragraphs for those parts of this code that are retained.  =============================================================================== */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
name|void
name|writeHex_flag
parameter_list|(
name|flag
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|writeHex_bits32
parameter_list|(
name|bits32
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|BITS64
end_ifdef

begin_function_decl
name|void
name|writeHex_bits64
parameter_list|(
name|bits64
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|writeHex_float32
parameter_list|(
name|float32
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|writeHex_float64
parameter_list|(
name|float64
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FLOATX80
end_ifdef

begin_function_decl
name|void
name|writeHex_floatx80
parameter_list|(
name|floatx80
parameter_list|,
name|FILE
modifier|*
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
name|void
name|writeHex_float128
parameter_list|(
name|float128
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|writeHex_float_flags
parameter_list|(
name|uint8
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

