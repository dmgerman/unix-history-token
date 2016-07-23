begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -triple=x86_64-pc-linux-gnu | FileCheck %s
end_comment

begin_comment
comment|// Verifying that we do, in fact, select the correct function in the following
end_comment

begin_comment
comment|// cases.
end_comment

begin_function_decl
name|void
name|foo
parameter_list|(
name|int
name|m
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
operator|,
function_decl|enable_if
parameter_list|(
function_decl|m> 0
operator|,
function_decl|""
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|foo
parameter_list|(
name|int
name|m
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK-LABEL: define void @test1
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
comment|// CHECK: store void (i32)* @_Z3fooi
name|void
function_decl|(
modifier|*
name|p
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
name|foo
function_decl|;
comment|// CHECK: store void (i32)* @_Z3fooi
name|void
function_decl|(
modifier|*
name|p2
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
operator|&
name|foo
function_decl|;
comment|// CHECK: store void (i32)* @_Z3fooi
name|p
operator|=
name|foo
expr_stmt|;
comment|// CHECK: store void (i32)* @_Z3fooi
name|p
operator|=
operator|&
name|foo
expr_stmt|;
comment|// CHECK: store i8* bitcast (void (i32)* @_Z3fooi to i8*)
name|void
modifier|*
name|vp1
init|=
operator|(
name|void
operator|*
operator|)
operator|&
name|foo
decl_stmt|;
comment|// CHECK: store i8* bitcast (void (i32)* @_Z3fooi to i8*)
name|void
modifier|*
name|vp2
init|=
operator|(
name|void
operator|*
operator|)
name|foo
decl_stmt|;
comment|// CHECK: store i8* bitcast (void (i32)* @_Z3fooi to i8*)
name|vp1
operator|=
operator|(
name|void
operator|*
operator|)
operator|&
name|foo
expr_stmt|;
comment|// CHECK: store i8* bitcast (void (i32)* @_Z3fooi to i8*)
name|vp1
operator|=
operator|(
name|void
operator|*
operator|)
name|foo
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|bar
parameter_list|(
name|int
name|m
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
operator|,
function_decl|enable_if
parameter_list|(
function_decl|m> 0
operator|,
function_decl|""
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|bar
parameter_list|(
name|int
name|m
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
operator|,
function_decl|enable_if
parameter_list|(
function_decl|1
operator|,
function_decl|""
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK-LABEL: define void @test2
end_comment

begin_function
name|void
name|test2
parameter_list|()
block|{
comment|// CHECK: store void (i32)* @_Z3barUa9enable_ifIXLi1EEEi
name|void
function_decl|(
modifier|*
name|p
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
name|bar
function_decl|;
comment|// CHECK: store void (i32)* @_Z3barUa9enable_ifIXLi1EEEi
name|void
function_decl|(
modifier|*
name|p2
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
operator|&
name|bar
function_decl|;
comment|// CHECK: store void (i32)* @_Z3barUa9enable_ifIXLi1EEEi
name|p
operator|=
name|bar
expr_stmt|;
comment|// CHECK: store void (i32)* @_Z3barUa9enable_ifIXLi1EEEi
name|p
operator|=
operator|&
name|bar
expr_stmt|;
comment|// CHECK: store i8* bitcast (void (i32)* @_Z3barUa9enable_ifIXLi1EEEi to i8*)
name|void
modifier|*
name|vp1
init|=
operator|(
name|void
operator|*
operator|)
operator|&
name|bar
decl_stmt|;
comment|// CHECK: store i8* bitcast (void (i32)* @_Z3barUa9enable_ifIXLi1EEEi to i8*)
name|void
modifier|*
name|vp2
init|=
operator|(
name|void
operator|*
operator|)
name|bar
decl_stmt|;
comment|// CHECK: store i8* bitcast (void (i32)* @_Z3barUa9enable_ifIXLi1EEEi to i8*)
name|vp1
operator|=
operator|(
name|void
operator|*
operator|)
operator|&
name|bar
expr_stmt|;
comment|// CHECK: store i8* bitcast (void (i32)* @_Z3barUa9enable_ifIXLi1EEEi to i8*)
name|vp1
operator|=
operator|(
name|void
operator|*
operator|)
name|bar
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|baz
parameter_list|(
name|int
name|m
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
operator|,
function_decl|enable_if
parameter_list|(
function_decl|1
operator|,
function_decl|""
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|baz
parameter_list|(
name|int
name|m
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK-LABEL: define void @test3
end_comment

begin_function
name|void
name|test3
parameter_list|()
block|{
comment|// CHECK: store void (i32)* @_Z3bazUa9enable_ifIXLi1EEEi
name|void
function_decl|(
modifier|*
name|p
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
name|baz
function_decl|;
comment|// CHECK: store void (i32)* @_Z3bazUa9enable_ifIXLi1EEEi
name|void
function_decl|(
modifier|*
name|p2
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
operator|&
name|baz
function_decl|;
comment|// CHECK: store void (i32)* @_Z3bazUa9enable_ifIXLi1EEEi
name|p
operator|=
name|baz
expr_stmt|;
comment|// CHECK: store void (i32)* @_Z3bazUa9enable_ifIXLi1EEEi
name|p
operator|=
operator|&
name|baz
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|const
name|int
name|TRUEFACTS
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|qux
parameter_list|(
name|int
name|m
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
operator|,
function_decl|enable_if
parameter_list|(
function_decl|1
operator|,
function_decl|""
end_function_decl

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|enable_if
argument_list|(
name|TRUEFACTS
argument_list|,
literal|""
argument_list|)
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|qux
parameter_list|(
name|int
name|m
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
operator|,
function_decl|enable_if
parameter_list|(
function_decl|1
operator|,
function_decl|""
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK-LABEL: define void @test4
end_comment

begin_function
name|void
name|test4
parameter_list|()
block|{
comment|// CHECK: store void (i32)* @_Z3quxUa9enable_ifIXLi1EEXL_Z9TRUEFACTSEEEi
name|void
function_decl|(
modifier|*
name|p
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
name|qux
function_decl|;
comment|// CHECK: store void (i32)* @_Z3quxUa9enable_ifIXLi1EEXL_Z9TRUEFACTSEEEi
name|void
function_decl|(
modifier|*
name|p2
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
operator|&
name|qux
function_decl|;
comment|// CHECK: store void (i32)* @_Z3quxUa9enable_ifIXLi1EEXL_Z9TRUEFACTSEEEi
name|p
operator|=
name|qux
expr_stmt|;
comment|// CHECK: store void (i32)* @_Z3quxUa9enable_ifIXLi1EEXL_Z9TRUEFACTSEEEi
name|p
operator|=
operator|&
name|qux
expr_stmt|;
block|}
end_function

begin_comment
comment|// There was a bug where, when enable_if was present, overload resolution
end_comment

begin_comment
comment|// wouldn't pay attention to lower-priority attributes.
end_comment

begin_comment
comment|// (N.B. `foo` with pass_object_size should always be preferred)
end_comment

begin_comment
comment|// CHECK-LABEL: define void @test5
end_comment

begin_function
name|void
name|test5
parameter_list|()
block|{
name|int
name|foo
argument_list|(
name|char
operator|*
name|i
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|enable_if
argument_list|(
literal|1
argument_list|,
literal|""
argument_list|)
operator|,
name|overloadable
operator|)
argument_list|)
decl_stmt|;
name|int
name|foo
argument_list|(
name|char
operator|*
name|i
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|0
argument_list|)
operator|)
argument_list|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|enable_if
argument_list|(
literal|1
argument_list|,
literal|""
argument_list|)
operator|,
name|overloadable
operator|)
argument_list|)
decl_stmt|;
comment|// CHECK: call i32 @_Z3fooUa9enable_ifIXLi1EEEPcU17pass_object_size0
name|foo
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

