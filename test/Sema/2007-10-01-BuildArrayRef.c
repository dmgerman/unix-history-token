begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// PR 1603
end_comment

begin_function
name|void
name|func
parameter_list|()
block|{
specifier|const
name|int
modifier|*
name|arr
decl_stmt|;
name|arr
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
comment|// expected-error {{read-only variable is not assignable}}
block|}
end_function

begin_struct
struct|struct
name|foo
block|{
name|int
name|bar
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|foo
name|sfoo
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|func2
parameter_list|()
block|{
specifier|const
name|struct
name|foo
modifier|*
name|fp
decl_stmt|;
name|fp
operator|=
operator|&
name|sfoo
expr_stmt|;
name|fp
index|[
literal|0
index|]
operator|.
name|bar
operator|=
literal|1
expr_stmt|;
comment|// expected-error {{read-only variable is not assignable}}
return|return
name|sfoo
operator|.
name|bar
return|;
block|}
end_function

end_unit

