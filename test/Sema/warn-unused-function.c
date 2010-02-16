begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wunused-function -verify %s
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

begin_function
specifier|static
name|void
name|f2
parameter_list|()
block|{}
end_function

begin_function
specifier|static
name|void
name|f1
parameter_list|()
block|{
name|f2
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning{{unused}}
end_comment

begin_function
specifier|static
name|int
name|f0
parameter_list|()
block|{
return|return
literal|17
return|;
block|}
end_function

begin_comment
comment|// expected-warning{{unused}}
end_comment

begin_decl_stmt
name|int
name|x
init|=
sizeof|sizeof
argument_list|(
name|f0
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|f3
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|extern
name|void
name|f3
parameter_list|()
block|{ }
end_function

begin_comment
comment|// expected-warning{{unused}}
end_comment

begin_comment
comment|// FIXME: This will trigger a warning when it should not.
end_comment

begin_comment
comment|// Update once PR6281 is fixed.
end_comment

begin_comment
comment|//inline static void f4();
end_comment

begin_comment
comment|//void f4() { }
end_comment

end_unit

