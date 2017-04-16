begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,debug.ExprInspection -verify %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,debug.ExprInspection -triple x86_64-unknown-linux -verify %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,debug.ExprInspection -triple powerpc64-linux-gnu -verify %s
end_comment

begin_define
define|#
directive|define
name|_Complex_I
value|(__extension__ 1.0iF)
end_define

begin_function_decl
name|void
name|clang_analyzer_eval
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|complex_float
parameter_list|(
name|double
specifier|_Complex
name|x
parameter_list|,
name|double
specifier|_Complex
name|y
parameter_list|)
block|{
name|clang_analyzer_eval
argument_list|(
name|x
operator|==
name|y
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
if|if
condition|(
name|x
operator|!=
literal|1.0
operator|+
literal|3.0
operator|*
name|_Complex_I
operator|&&
name|y
operator|!=
literal|1.0
operator|-
literal|4.0
operator|*
name|_Complex_I
condition|)
return|return
name|clang_analyzer_eval
argument_list|(
name|x
operator|==
name|y
argument_list|)
return|;
comment|// expected-warning{{UNKNOWN}}
name|clang_analyzer_eval
argument_list|(
name|x
operator|+
name|y
operator|==
literal|2.0
operator|-
literal|1.0
operator|*
name|_Complex_I
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
block|}
end_function

begin_function
name|void
name|complex_int
parameter_list|(
name|int
specifier|_Complex
name|x
parameter_list|,
name|int
specifier|_Complex
name|y
parameter_list|)
block|{
name|clang_analyzer_eval
argument_list|(
name|x
operator|==
name|y
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
if|if
condition|(
name|x
operator|!=
literal|1.0
operator|+
literal|3.0
operator|*
name|_Complex_I
operator|&&
name|y
operator|!=
literal|1.0
operator|-
literal|4.0
operator|*
name|_Complex_I
condition|)
return|return
name|clang_analyzer_eval
argument_list|(
name|x
operator|==
name|y
argument_list|)
return|;
comment|// expected-warning{{UNKNOWN}}
name|clang_analyzer_eval
argument_list|(
name|x
operator|+
name|y
operator|==
literal|2.0
operator|-
literal|1.0
operator|*
name|_Complex_I
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
block|}
end_function

begin_function
name|void
name|longdouble_float
parameter_list|(
name|long
name|double
name|x
parameter_list|,
name|long
name|double
name|y
parameter_list|)
block|{
name|clang_analyzer_eval
argument_list|(
name|x
operator|==
name|y
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
if|if
condition|(
name|x
operator|!=
literal|0.0L
operator|&&
name|y
operator|!=
literal|1.0L
condition|)
return|return
name|clang_analyzer_eval
argument_list|(
name|x
operator|==
name|y
argument_list|)
return|;
comment|// expected-warning{{UNKNOWN}}
name|clang_analyzer_eval
argument_list|(
name|x
operator|+
name|y
operator|==
literal|1.0L
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
block|}
end_function

end_unit

