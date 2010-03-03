begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wunused-variable -fblocks -verify %s
end_comment

begin_struct
struct|struct
name|s0
block|{
name|unsigned
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|proto
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f0
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|a
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
decl_stmt|,
name|b
decl_stmt|;
comment|// expected-warning{{unused}}
return|return;
block|}
end_function

begin_function
name|void
name|f1
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|i
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|// PR5933
end_comment

begin_function
name|int
name|f2
parameter_list|()
block|{
name|int
name|X
init|=
literal|4
decl_stmt|;
comment|// Shouldn't have a bogus 'unused variable X' warning.
return|return
name|Y
operator|+
name|X
return|;
comment|// expected-error {{use of undeclared identifier 'Y'}}
block|}
end_function

begin_function
name|int
name|f3
parameter_list|()
block|{
name|int
name|X1
init|=
literal|4
decl_stmt|;
call|(
name|void
call|)
argument_list|(
name|Y1
operator|+
name|X1
argument_list|)
expr_stmt|;
comment|// expected-error {{use of undeclared identifier 'Y1'}}
call|(
name|void
call|)
argument_list|(
lambda|^
parameter_list|()
block|{
name|int
name|X
init|=
literal|4
decl_stmt|;
block|}
argument_list|)
expr_stmt|;
comment|// expected-warning{{unused}}
call|(
name|void
call|)
argument_list|(
lambda|^
parameter_list|()
block|{
name|int
name|X
init|=
literal|4
decl_stmt|;
return|return
name|Y
operator|+
name|X
return|;
block|}
argument_list|)
expr_stmt|;
comment|// expected-error {{use of undeclared identifier 'Y'}}
block|}
end_function

end_unit

