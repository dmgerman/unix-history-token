begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,debug.ExprInspection -triple x86_64-apple-darwin13 -Wno-shift-count-overflow -verify %s
end_comment

begin_function_decl
name|void
name|clang_analyzer_eval
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CHECK
parameter_list|(
name|expr
parameter_list|)
value|if (!(expr)) return; clang_analyzer_eval(expr)
end_define

begin_function
name|void
name|testPersistentConstraints
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
comment|// Sanity check
name|CHECK
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
name|CHECK
argument_list|(
name|x
operator|&
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
comment|// False positives due to SValBuilder giving up on certain kinds of exprs.
name|CHECK
argument_list|(
literal|1
operator|-
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
name|CHECK
argument_list|(
name|x
operator|&
name|y
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
block|}
end_function

begin_function
name|int
name|testConstantShifts_PR18073
parameter_list|(
name|int
name|which
parameter_list|)
block|{
comment|// FIXME: We should have a checker that actually specifically checks bitwise
comment|// shifts against the width of the LHS's /static/ type, rather than just
comment|// having BasicValueFactory return "undefined" when dealing with two constant
comment|// operands.
switch|switch
condition|(
name|which
condition|)
block|{
case|case
literal|1
case|:
return|return
literal|0ULL
operator|<<
literal|63
return|;
comment|// no-warning
case|case
literal|2
case|:
return|return
literal|0ULL
operator|<<
literal|64
return|;
comment|// expected-warning{{The result of the '<<' expression is undefined}}
case|case
literal|3
case|:
return|return
literal|0ULL
operator|<<
literal|65
return|;
comment|// expected-warning{{The result of the '<<' expression is undefined}}
default|default:
return|return
literal|0
return|;
block|}
block|}
end_function

end_unit

