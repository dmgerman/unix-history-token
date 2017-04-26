begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -w -triple i386-apple-darwin10 -analyzer-checker=core,debug.ExprInspection -verify %s
end_comment

begin_function_decl
name|void
name|clang_analyzer_eval
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|S
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|int
name|z
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|testOffsets
parameter_list|(
name|struct
name|S
modifier|*
name|s
parameter_list|,
name|int
name|coin
parameter_list|)
block|{
if|if
condition|(
name|s
operator|!=
literal|0
condition|)
return|return;
comment|// FIXME: Here we are testing the hack that computes offsets to null pointers
comment|// as 0 in order to find null dereferences of not-exactly-null pointers,
comment|// such as&(s->y) below, which is equal to 4 rather than 0 in run-time.
comment|// These are indeed null.
name|clang_analyzer_eval
argument_list|(
name|s
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
name|clang_analyzer_eval
argument_list|(
operator|&
operator|(
name|s
operator|->
name|x
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
comment|// FIXME: These should ideally be true.
name|clang_analyzer_eval
argument_list|(
operator|&
operator|(
name|s
operator|->
name|y
operator|)
operator|==
literal|4
argument_list|)
expr_stmt|;
comment|// expected-warning{{FALSE}}
name|clang_analyzer_eval
argument_list|(
operator|&
operator|(
name|s
operator|->
name|z
index|[
literal|0
index|]
operator|)
operator|==
literal|8
argument_list|)
expr_stmt|;
comment|// expected-warning{{FALSE}}
name|clang_analyzer_eval
argument_list|(
operator|&
operator|(
name|s
operator|->
name|z
index|[
literal|1
index|]
operator|)
operator|==
literal|12
argument_list|)
expr_stmt|;
comment|// expected-warning{{FALSE}}
comment|// FIXME: These should ideally be false.
name|clang_analyzer_eval
argument_list|(
operator|&
operator|(
name|s
operator|->
name|y
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
name|clang_analyzer_eval
argument_list|(
operator|&
operator|(
name|s
operator|->
name|z
index|[
literal|0
index|]
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
name|clang_analyzer_eval
argument_list|(
operator|&
operator|(
name|s
operator|->
name|z
index|[
literal|1
index|]
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
comment|// But these should still be reported as null dereferences.
if|if
condition|(
name|coin
condition|)
name|s
operator|->
name|y
operator|=
literal|5
expr_stmt|;
comment|// expected-warning{{Access to field 'y' results in a dereference of a null pointer (loaded from variable 's')}}
else|else
name|s
operator|->
name|z
index|[
literal|1
index|]
operator|=
literal|6
expr_stmt|;
comment|// expected-warning{{Array access (via field 'z') results in a null pointer dereference}}
block|}
end_function

end_unit

