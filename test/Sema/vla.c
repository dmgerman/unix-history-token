begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only -pedantic
end_comment

begin_function
name|int
name|test1
parameter_list|()
block|{
typedef|typedef
name|int
name|x
index|[
name|test1
argument_list|()
index|]
typedef|;
comment|// vla
specifier|static
name|int
name|y
init|=
sizeof|sizeof
argument_list|(
name|x
argument_list|)
decl_stmt|;
comment|// expected-error {{not a compile-time constant}}
block|}
end_function

begin_comment
comment|// PR2347
end_comment

begin_function
name|void
name|f
parameter_list|(
name|unsigned
name|int
name|m
parameter_list|)
block|{
name|int
name|e
index|[
literal|2
index|]
index|[
name|m
index|]
decl_stmt|;
name|e
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|// PR3048
end_comment

begin_decl_stmt
name|int
name|x
init|=
expr|sizeof
operator|(
expr|struct
block|{
name|char
name|qq
index|[
name|x
index|]
block|;}
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{fields must have a constant size}}
end_comment

begin_comment
comment|// PR2352
end_comment

begin_function
name|void
name|f2
parameter_list|(
name|unsigned
name|int
name|m
parameter_list|)
block|{
specifier|extern
name|int
name|e1
index|[
literal|2
index|]
index|[
name|m
index|]
decl_stmt|;
comment|// expected-error {{variable length array declaration can not have 'extern' linkage}}
name|e1
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|// PR2361
end_comment

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|c
index|[]
index|[
name|i
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{variably modified type declaration not allowed at file scope}}
end_comment

begin_decl_stmt
name|int
name|d
index|[
name|i
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{variable length array declaration not allowed at file scope}}
end_comment

begin_expr_stmt
name|int
argument_list|(
operator|*
name|e
argument_list|)
index|[
name|i
index|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{variably modified type declaration not allowed at file scope}}
end_comment

begin_function
name|void
name|f3
parameter_list|()
block|{
specifier|static
name|int
name|a
index|[
name|i
index|]
decl_stmt|;
comment|// expected-error {{variable length array declaration can not have 'static' storage duration}}
specifier|extern
name|int
name|b
index|[
name|i
index|]
decl_stmt|;
comment|// expected-error {{variable length array declaration can not have 'extern' linkage}}
extern|extern int (*c1
block|)
function|[i];
end_function

begin_comment
comment|// expected-error {{variably modified type declaration can not have 'extern' linkage}}
end_comment

begin_expr_stmt
specifier|static
name|int
argument_list|(
operator|*
name|d
argument_list|)
index|[
name|i
index|]
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// PR3663
end_comment

begin_decl_stmt
unit|static
specifier|const
name|unsigned
name|array
index|[
operator|(
operator|(
literal|2
operator|*
call|(
name|int
call|)
argument_list|(
operator|(
operator|(
operator|(
literal|4
operator|)
operator|/
literal|2
operator|)
operator|+
literal|1.0
operator|/
literal|3.0
operator|)
operator|*
operator|(
literal|4
operator|)
operator|-
literal|1e-8
argument_list|)
operator|)
operator|+
literal|1
operator|)
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{size of static array must be an integer constant expression}}
end_comment

begin_decl_stmt
name|int
name|a
index|[
operator|*
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{star modifier used outside of function prototype}}
end_comment

begin_function_decl
name|int
name|f4
parameter_list|(
name|int
name|a
index|[
operator|*
index|]
index|[
operator|*
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// PR2044
end_comment

begin_function
name|int
name|pr2044
parameter_list|(
name|int
name|b
parameter_list|)
block|{
name|int
argument_list|(
operator|*
name|c
argument_list|(
name|void
argument_list|)
argument_list|)
index|[
name|b
index|]
expr_stmt|;
operator|*
operator|*
name|c
argument_list|()
operator|=
literal|2
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-error {{variably modified type}}
end_comment

begin_decl_stmt
name|int
name|pr2044b
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|int
argument_list|(
operator|*
name|pr2044c
argument_list|(
name|void
argument_list|)
argument_list|)
index|[
name|pr2044b
index|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{variably modified type}}
end_comment

begin_decl_stmt
specifier|const
name|int
name|f5_ci
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f5
parameter_list|()
block|{
name|char
name|a
index|[]
index|[
name|f5_ci
index|]
init|=
block|{
literal|""
block|}
decl_stmt|;
block|}
end_function

begin_comment
comment|// expected-error {{variable-sized object may not be initialized}}
end_comment

end_unit

