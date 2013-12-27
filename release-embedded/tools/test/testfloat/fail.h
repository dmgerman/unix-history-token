begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===============================================================================  This C header file is part of TestFloat, Release 2a, a package of programs for testing the correctness of floating-point arithmetic complying to the IEC/IEEE Standard for Floating-Point.  Written by John R. Hauser.  More information is available through the Web page `http://HTTP.CS.Berkeley.EDU/~jhauser/arithmetic/TestFloat.html'.  THIS SOFTWARE IS DISTRIBUTED AS IS, FOR FREE.  Although reasonable effort has been made to avoid it, THIS SOFTWARE MAY CONTAIN FAULTS THAT WILL AT TIMES RESULT IN INCORRECT BEHAVIOR.  USE OF THIS SOFTWARE IS RESTRICTED TO PERSONS AND ORGANIZATIONS WHO CAN AND WILL TAKE FULL RESPONSIBILITY FOR ANY AND ALL LOSSES, COSTS, OR OTHER PROBLEMS ARISING FROM ITS USE.  Derivative works are acceptable, even for commercial purposes, so long as (1) they include prominent notice that the work is derivative, and (2) they include prominent notice akin to these four paragraphs for those parts of this code that are retained.  =============================================================================== */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fail_programName
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|fail
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

end_unit

