begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=unix.Malloc,core,alpha.core.CallAndMessageUnInitRefArg -analyzer-output=text -verify %s
end_comment

begin_comment
comment|// Passing uninitialized const data to function
end_comment

begin_include
include|#
directive|include
file|"Inputs/system-header-simulator.h"
end_include

begin_typedef
typedef|typedef
name|__typeof
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|valloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|doStuff3
parameter_list|(
specifier|const
name|int
name|y
parameter_list|)
block|{}
end_function

begin_function
name|void
name|doStuff2
parameter_list|(
name|int
name|g
parameter_list|)
block|{}
end_function

begin_function
name|void
name|doStuff_pointerToConstInt
parameter_list|(
specifier|const
name|int
modifier|*
name|u
parameter_list|)
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|doStuff_arrayOfConstInt
parameter_list|(
specifier|const
name|int
name|a
index|[]
parameter_list|)
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|doStuff_constPointerToConstInt
parameter_list|(
name|int
specifier|const
modifier|*
specifier|const
name|u
parameter_list|)
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|doStuff_constPointerToConstPointerToConstInt
parameter_list|(
name|int
specifier|const
modifier|*
specifier|const
modifier|*
specifier|const
name|u
parameter_list|)
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|doStuff_pointerToConstPointerToConstInt
parameter_list|(
name|int
specifier|const
modifier|*
specifier|const
modifier|*
name|u
parameter_list|)
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|doStuff_pointerToPointerToConstInt
parameter_list|(
name|int
specifier|const
modifier|*
modifier|*
name|u
parameter_list|)
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|doStuff_constStaticSizedArray
parameter_list|(
specifier|const
name|int
name|a
index|[
specifier|static
literal|10
index|]
parameter_list|)
block|{}
end_function

begin_function
name|void
name|doStuff_variadic
parameter_list|(
specifier|const
name|int
modifier|*
name|u
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|f_1
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|t
decl_stmt|;
name|int
modifier|*
name|tp
init|=
operator|&
name|t
decl_stmt|;
comment|// expected-note {{'tp' initialized here}}
name|doStuff_pointerToConstInt
argument_list|(
name|tp
argument_list|)
expr_stmt|;
comment|// expected-warning {{1st function call argument is a pointer to uninitialized value}}
comment|// expected-note@-1 {{1st function call argument is a pointer to uninitialized value}}
block|}
end_function

begin_function
name|void
name|f_1_1
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|t
decl_stmt|;
name|int
modifier|*
name|tp1
init|=
operator|&
name|t
decl_stmt|;
name|int
modifier|*
name|tp2
init|=
name|tp1
decl_stmt|;
comment|// expected-note {{'tp2' initialized here}}
name|doStuff_pointerToConstInt
argument_list|(
name|tp2
argument_list|)
expr_stmt|;
comment|// expected-warning {{1st function call argument is a pointer to uninitialized value}}
comment|// expected-note@-1 {{1st function call argument is a pointer to uninitialized value}}
block|}
end_function

begin_function
name|int
modifier|*
name|f_2_sub
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
return|return
name|p
return|;
block|}
end_function

begin_function
name|void
name|f_2
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|t
decl_stmt|;
name|int
modifier|*
name|p
init|=
name|f_2_sub
argument_list|(
operator|&
name|t
argument_list|)
decl_stmt|;
name|int
modifier|*
name|tp
init|=
name|p
decl_stmt|;
comment|// expected-note {{'tp' initialized here}}
name|doStuff_pointerToConstInt
argument_list|(
name|tp
argument_list|)
expr_stmt|;
comment|// expected-warning {{1st function call argument is a pointer to uninitialized value}}
comment|// expected-note@-1 {{1st function call argument is a pointer to uninitialized value}}
block|}
end_function

begin_decl_stmt
name|int
name|z
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f_3
parameter_list|(
name|void
parameter_list|)
block|{
name|doStuff_pointerToConstInt
argument_list|(
operator|&
name|z
argument_list|)
expr_stmt|;
comment|// no warning
block|}
end_function

begin_function
name|void
name|f_4
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|x
init|=
literal|5
decl_stmt|;
name|doStuff_pointerToConstInt
argument_list|(
operator|&
name|x
argument_list|)
expr_stmt|;
comment|// no warning
block|}
end_function

begin_function
name|void
name|f_5
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|ta
index|[
literal|5
index|]
decl_stmt|;
name|int
modifier|*
name|tp
init|=
name|ta
decl_stmt|;
comment|// expected-note {{'tp' initialized here}}
name|doStuff_pointerToConstInt
argument_list|(
name|tp
argument_list|)
expr_stmt|;
comment|// expected-warning {{1st function call argument is a pointer to uninitialized value}}
comment|// expected-note@-1 {{1st function call argument is a pointer to uninitialized value}}
block|}
end_function

begin_function
name|void
name|f_5_1
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|ta
index|[
literal|5
index|]
decl_stmt|;
comment|// expected-note {{'ta' initialized here}}
name|doStuff_pointerToConstInt
argument_list|(
name|ta
argument_list|)
expr_stmt|;
comment|// expected-warning {{1st function call argument is a pointer to uninitialized value}}
comment|// expected-note@-1 {{1st function call argument is a pointer to uninitialized value}}
block|}
end_function

begin_function
name|void
name|f_6
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|ta
index|[
literal|5
index|]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|}
decl_stmt|;
name|int
modifier|*
name|tp
init|=
name|ta
decl_stmt|;
name|doStuff_pointerToConstInt
argument_list|(
name|tp
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|f_6_1
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|ta
index|[
literal|5
index|]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|}
decl_stmt|;
name|doStuff_pointerToConstInt
argument_list|(
name|ta
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|f_7
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|z
decl_stmt|;
comment|// expected-note {{'z' declared without an initial value}}
name|int
name|y
init|=
name|z
decl_stmt|;
comment|// expected-warning {{Assigned value is garbage or undefined}}
comment|// expected-note@-1 {{Assigned value is garbage or undefined}}
name|doStuff3
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f_8
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|g
decl_stmt|;
comment|// expected-note {{'g' declared without an initial value}}
name|doStuff2
argument_list|(
name|g
argument_list|)
expr_stmt|;
comment|// expected-warning {{1st function call argument is an uninitialized value}}
comment|// expected-note@-1 {{1st function call argument is an uninitialized value}}
block|}
end_function

begin_function
name|void
name|f_9
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|a
index|[
literal|6
index|]
decl_stmt|;
name|int
specifier|const
modifier|*
name|ptau
init|=
name|a
decl_stmt|;
comment|// expected-note {{'ptau' initialized here}}
name|doStuff_arrayOfConstInt
argument_list|(
name|ptau
argument_list|)
expr_stmt|;
comment|// expected-warning {{1st function call argument is a pointer to uninitialized value}}
comment|// expected-note@-1 {{1st function call argument is a pointer to uninitialized value}}
block|}
end_function

begin_function
name|void
name|f_10
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|a
index|[
literal|6
index|]
decl_stmt|;
comment|// expected-note {{'a' initialized here}}
name|doStuff_arrayOfConstInt
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// expected-warning {{1st function call argument is a pointer to uninitialized value}}
comment|// expected-note@-1 {{1st function call argument is a pointer to uninitialized value}}
block|}
end_function

begin_function
name|void
name|f_11
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|t
index|[
literal|10
index|]
decl_stmt|;
comment|//expected-note {{'t' initialized here}}
name|doStuff_constStaticSizedArray
argument_list|(
name|t
argument_list|)
expr_stmt|;
comment|// expected-warning {{1st function call argument is a pointer to uninitialized value}}
comment|// expected-note@-1 {{1st function call argument is a pointer to uninitialized value}}
block|}
end_function

begin_function
name|void
name|f_12
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|t
index|[
literal|10
index|]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|}
decl_stmt|;
name|doStuff_constStaticSizedArray
argument_list|(
name|t
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|int
name|f_malloc_1
parameter_list|(
name|void
parameter_list|)
block|{
name|int
modifier|*
name|ptr
decl_stmt|;
name|ptr
operator|=
operator|(
name|int
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-note {{Value assigned to 'ptr'}}
name|doStuff_pointerToConstInt
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
comment|// expected-warning {{1st function call argument is a pointer to uninitialized value}}
comment|// expected-note@-1 {{1st function call argument is a pointer to uninitialized value}}
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|f_malloc_2
parameter_list|(
name|void
parameter_list|)
block|{
name|int
modifier|*
name|ptr
decl_stmt|;
name|ptr
operator|=
operator|(
name|int
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|ptr
operator|=
literal|25
expr_stmt|;
name|doStuff_pointerToConstInt
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
comment|// no warning
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// uninit pointer, uninit val
end_comment

begin_function
name|void
name|f_variadic_unp_unv
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|t
decl_stmt|;
name|int
name|v
decl_stmt|;
name|int
modifier|*
name|tp
init|=
operator|&
name|t
decl_stmt|;
comment|// expected-note {{'tp' initialized here}}
name|doStuff_variadic
argument_list|(
name|tp
argument_list|,
name|v
argument_list|)
expr_stmt|;
comment|// expected-warning {{1st function call argument is a pointer to uninitialized value}}
comment|// expected-note@-1 {{1st function call argument is a pointer to uninitialized value}}
block|}
end_function

begin_comment
comment|// uninit pointer, init val
end_comment

begin_function
name|void
name|f_variadic_unp_inv
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|t
decl_stmt|;
name|int
name|v
init|=
literal|3
decl_stmt|;
name|int
modifier|*
name|tp
init|=
operator|&
name|t
decl_stmt|;
comment|// expected-note {{'tp' initialized here}}
name|doStuff_variadic
argument_list|(
name|tp
argument_list|,
name|v
argument_list|)
expr_stmt|;
comment|// expected-warning {{1st function call argument is a pointer to uninitialized value}}
comment|// expected-note@-1 {{1st function call argument is a pointer to uninitialized value}}
block|}
end_function

begin_comment
comment|// init pointer, uninit val
end_comment

begin_function
name|void
name|f_variadic_inp_unv
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|t
init|=
literal|5
decl_stmt|;
name|int
name|v
decl_stmt|;
comment|// expected-note {{'v' declared without an initial value}}
name|int
modifier|*
name|tp
init|=
operator|&
name|t
decl_stmt|;
name|doStuff_variadic
argument_list|(
name|tp
argument_list|,
name|v
argument_list|)
expr_stmt|;
comment|// expected-warning {{2nd function call argument is an uninitialized value}}
comment|// expected-note@-1 {{2nd function call argument is an uninitialized value}}
block|}
end_function

begin_comment
comment|// init pointer, init val
end_comment

begin_function
name|void
name|f_variadic_inp_inv
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|t
init|=
literal|5
decl_stmt|;
name|int
name|v
init|=
literal|3
decl_stmt|;
name|int
modifier|*
name|tp
init|=
operator|&
name|t
decl_stmt|;
name|doStuff_variadic
argument_list|(
name|tp
argument_list|,
name|v
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// init pointer, init pointer
end_comment

begin_function
name|void
name|f_variadic_inp_inp
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|t
init|=
literal|5
decl_stmt|;
name|int
name|u
init|=
literal|3
decl_stmt|;
name|int
modifier|*
name|vp
init|=
operator|&
name|u
decl_stmt|;
name|int
modifier|*
name|tp
init|=
operator|&
name|t
decl_stmt|;
name|doStuff_variadic
argument_list|(
name|tp
argument_list|,
name|vp
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|//uninit pointer, init pointer
end_comment

begin_function
name|void
name|f_variadic_unp_inp
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|t
decl_stmt|;
name|int
name|u
init|=
literal|3
decl_stmt|;
name|int
modifier|*
name|vp
init|=
operator|&
name|u
decl_stmt|;
name|int
modifier|*
name|tp
init|=
operator|&
name|t
decl_stmt|;
comment|// expected-note {{'tp' initialized here}}
name|doStuff_variadic
argument_list|(
name|tp
argument_list|,
name|vp
argument_list|)
expr_stmt|;
comment|// expected-warning {{1st function call argument is a pointer to uninitialized value}}
comment|// expected-note@-1 {{1st function call argument is a pointer to uninitialized value}}
block|}
end_function

begin_comment
comment|//init pointer, uninit pointer
end_comment

begin_function
name|void
name|f_variadic_inp_unp
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|t
init|=
literal|5
decl_stmt|;
name|int
name|u
decl_stmt|;
name|int
modifier|*
name|vp
init|=
operator|&
name|u
decl_stmt|;
name|int
modifier|*
name|tp
init|=
operator|&
name|t
decl_stmt|;
name|doStuff_variadic
argument_list|(
name|tp
argument_list|,
name|vp
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|//uninit pointer, uninit pointer
end_comment

begin_function
name|void
name|f_variadic_unp_unp
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|t
decl_stmt|;
name|int
name|u
decl_stmt|;
name|int
modifier|*
name|vp
init|=
operator|&
name|u
decl_stmt|;
name|int
modifier|*
name|tp
init|=
operator|&
name|t
decl_stmt|;
comment|// expected-note {{'tp' initialized here}}
name|doStuff_variadic
argument_list|(
name|tp
argument_list|,
name|vp
argument_list|)
expr_stmt|;
comment|// expected-warning {{1st function call argument is a pointer to uninitialized value}}
comment|// expected-note@-1 {{1st function call argument is a pointer to uninitialized value}}
block|}
end_function

end_unit

