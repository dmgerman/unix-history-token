begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_comment
comment|// Basic parsing/Sema tests for _Atomic
end_comment

begin_comment
comment|// No operations are actually supported on objects of this type yet.
end_comment

begin_comment
comment|// The qualifier syntax is not supported yet.
end_comment

begin_decl_stmt
atomic|_Atomic
argument_list|(
name|int
argument_list|)
name|t1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
atomic|_Atomic
argument_list|(
name|int
argument_list|)
modifier|*
name|t2
init|=
operator|&
name|t1
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|testf
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{
atomic|_Atomic
argument_list|(
type|_Atomic(
name|int
decl_stmt|)*
block|)
function|t3;
end_function

begin_decl_stmt
atomic|_Atomic
argument_list|(
type|_Atomic(
name|int
decl_stmt|)*
end_decl_stmt

begin_expr_stmt
unit|)
operator|*
name|t4
index|[
literal|2
index|]
operator|=
block|{
operator|&
name|t3
block|,
literal|0
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|testf
argument_list|(
name|t4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|} extern
atomic|_Atomic
argument_list|(
name|int
argument_list|(
operator|*
argument_list|)
operator|(
name|int
argument_list|(
operator|*
argument_list|)
index|[]
operator|,
name|int
argument_list|(
operator|*
argument_list|)
index|[
literal|10
index|]
operator|)
argument_list|)
name|mergetest
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
atomic|_Atomic
argument_list|(
name|int
argument_list|(
operator|*
argument_list|)
operator|(
name|int
argument_list|(
operator|*
argument_list|)
index|[
literal|10
index|]
operator|,
name|int
argument_list|(
operator|*
argument_list|)
index|[]
operator|)
argument_list|)
name|mergetest
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
atomic|_Atomic
argument_list|(
name|int
argument_list|(
operator|*
argument_list|)
operator|(
name|int
argument_list|(
operator|*
argument_list|)
index|[
literal|10
index|]
operator|,
name|int
argument_list|(
operator|*
argument_list|)
index|[
literal|10
index|]
operator|)
argument_list|)
name|mergetest
decl_stmt|;
end_decl_stmt

begin_decl_stmt
atomic|_Atomic
argument_list|(
name|int
argument_list|()
argument_list|)
name|error1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{_Atomic cannot be applied to function type}}
end_comment

begin_decl_stmt
atomic|_Atomic
argument_list|(
expr|struct
name|ErrorS
argument_list|)
name|error2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{_Atomic cannot be applied to incomplete type}}
end_comment

begin_decl_stmt
atomic|_Atomic
argument_list|(
name|int
index|[
literal|10
index|]
argument_list|)
name|error3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{_Atomic cannot be applied to array type}}
end_comment

begin_decl_stmt
atomic|_Atomic
argument_list|(
specifier|const
name|int
argument_list|)
name|error4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{_Atomic cannot be applied to qualified type}}
end_comment

begin_decl_stmt
atomic|_Atomic
argument_list|(
type|_Atomic(
name|int
decl_stmt|)
end_decl_stmt

begin_expr_stmt
unit|)
name|error5
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{_Atomic cannot be applied to atomic type}}
end_comment

end_unit

