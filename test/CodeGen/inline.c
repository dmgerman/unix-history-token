begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: echo "GNU89 tests:"
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-unknown-unknown -O1 -disable-llvm-optzns -emit-llvm -o - -std=gnu89 | FileCheck %s --check-prefix=CHECK1
end_comment

begin_comment
comment|// CHECK1-LABEL: define i32 @foo()
end_comment

begin_comment
comment|// CHECK1-LABEL: define i32 @bar()
end_comment

begin_comment
comment|// CHECK1-LABEL: define void @unreferenced1()
end_comment

begin_comment
comment|// CHECK1-NOT: unreferenced2
end_comment

begin_comment
comment|// CHECK1-LABEL: define void @gnu_inline()
end_comment

begin_comment
comment|// CHECK1-LABEL: define i32 @test1
end_comment

begin_comment
comment|// CHECK1-LABEL: define i32 @test2
end_comment

begin_comment
comment|// CHECK1-LABEL: define void @test3()
end_comment

begin_comment
comment|// CHECK1-LABEL: define available_externally i32 @test4
end_comment

begin_comment
comment|// CHECK1-LABEL: define available_externally i32 @test5
end_comment

begin_comment
comment|// CHECK1-LABEL: define i32 @test6
end_comment

begin_comment
comment|// CHECK1-LABEL: define void @test7
end_comment

begin_comment
comment|// CHECK1: define i{{..}} @strlcpy
end_comment

begin_comment
comment|// CHECK1-NOT: test9
end_comment

begin_comment
comment|// CHECK1-LABEL: define void @testA
end_comment

begin_comment
comment|// CHECK1-LABEL: define void @testB
end_comment

begin_comment
comment|// CHECK1-LABEL: define void @testC
end_comment

begin_comment
comment|// CHECK1-LABEL: define available_externally void @gnu_ei_inline()
end_comment

begin_comment
comment|// CHECK1-LABEL: define available_externally i32 @ei()
end_comment

begin_comment
comment|// RUN: echo "C99 tests:"
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-unknown-unknown -O1 -disable-llvm-optzns -emit-llvm -o - -std=gnu99 | FileCheck %s --check-prefix=CHECK2
end_comment

begin_comment
comment|// CHECK2-LABEL: define i32 @ei()
end_comment

begin_comment
comment|// CHECK2-LABEL: define i32 @bar()
end_comment

begin_comment
comment|// CHECK2-NOT: unreferenced1
end_comment

begin_comment
comment|// CHECK2-LABEL: define void @unreferenced2()
end_comment

begin_comment
comment|// CHECK2-LABEL: define void @gnu_inline()
end_comment

begin_comment
comment|// CHECK2-LABEL: define i32 @test1
end_comment

begin_comment
comment|// CHECK2-LABEL: define i32 @test2
end_comment

begin_comment
comment|// CHECK2-LABEL: define void @test3
end_comment

begin_comment
comment|// CHECK2-LABEL: define available_externally i32 @test4
end_comment

begin_comment
comment|// CHECK2-LABEL: define available_externally i32 @test5
end_comment

begin_comment
comment|// CHECK2-LABEL: define i32 @test6
end_comment

begin_comment
comment|// CHECK2-LABEL: define void @test7
end_comment

begin_comment
comment|// CHECK2: define available_externally i{{..}} @strlcpy
end_comment

begin_comment
comment|// CHECK2-LABEL: define void @test9
end_comment

begin_comment
comment|// CHECK2-LABEL: define void @testA
end_comment

begin_comment
comment|// CHECK2-LABEL: define void @testB
end_comment

begin_comment
comment|// CHECK2-LABEL: define void @testC
end_comment

begin_comment
comment|// CHECK2-LABEL: define available_externally void @gnu_ei_inline()
end_comment

begin_comment
comment|// CHECK2-LABEL: define available_externally i32 @foo()
end_comment

begin_comment
comment|// RUN: echo "C++ tests:"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ %s -triple i386-unknown-unknown -O1 -disable-llvm-optzns -emit-llvm -o - -std=c++98 | FileCheck %s --check-prefix=CHECK3
end_comment

begin_comment
comment|// CHECK3-LABEL: define i32 @_Z3barv()
end_comment

begin_comment
comment|// CHECK3-LABEL: define linkonce_odr i32 @_Z3foov()
end_comment

begin_comment
comment|// CHECK3-NOT: unreferenced
end_comment

begin_comment
comment|// CHECK3-LABEL: define void @_Z10gnu_inlinev()
end_comment

begin_comment
comment|// CHECK3-LABEL: define available_externally void @_Z13gnu_ei_inlinev()
end_comment

begin_comment
comment|// CHECK3-LABEL: define linkonce_odr i32 @_Z2eiv()
end_comment

begin_comment
comment|// RUN: echo "MS C Mode tests:"
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-unknown-unknown -O1 -disable-llvm-optzns -emit-llvm -o - -std=c99 -fms-compatibility | FileCheck %s --check-prefix=CHECK4
end_comment

begin_comment
comment|// CHECK4-LABEL: define weak_odr i32 @ei()
end_comment

begin_comment
comment|// CHECK4-LABEL: define i32 @bar()
end_comment

begin_comment
comment|// CHECK4-NOT: unreferenced1
end_comment

begin_comment
comment|// CHECK4-LABEL: define weak_odr void @unreferenced2()
end_comment

begin_comment
comment|// CHECK4-LABEL: define void @gnu_inline()
end_comment

begin_comment
comment|// CHECK4-LABEL: define available_externally void @gnu_ei_inline()
end_comment

begin_comment
comment|// CHECK4-LABEL: define linkonce_odr i32 @foo()
end_comment

begin_function
specifier|extern
name|__inline
name|int
name|ei
parameter_list|()
block|{
return|return
literal|123
return|;
block|}
end_function

begin_function
name|__inline
name|int
name|foo
parameter_list|()
block|{
return|return
name|ei
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|bar
parameter_list|()
block|{
return|return
name|foo
argument_list|()
return|;
block|}
end_function

begin_function
name|__inline
name|void
name|unreferenced1
parameter_list|()
block|{}
end_function

begin_function
specifier|extern
name|__inline
name|void
name|unreferenced2
parameter_list|()
block|{}
end_function

begin_decl_stmt
name|__inline
name|__attribute
argument_list|(
operator|(
name|__gnu_inline__
operator|)
argument_list|)
name|void
name|gnu_inline
argument_list|()
block|{}
end_decl_stmt

begin_comment
comment|// PR3988
end_comment

begin_decl_stmt
specifier|extern
name|__inline
name|__attribute__
argument_list|(
operator|(
name|gnu_inline
operator|)
argument_list|)
name|void
name|gnu_ei_inline
argument_list|()
block|{}
end_decl_stmt

begin_function_decl
name|void
function_decl|(
modifier|*
name|P
function_decl|)
parameter_list|()
init|=
name|gnu_ei_inline
function_decl|;
end_function_decl

begin_comment
comment|//<rdar://problem/6818429>
end_comment

begin_function_decl
name|int
name|test1
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|__inline
name|int
name|test1
parameter_list|()
block|{
return|return
literal|4
return|;
block|}
end_function

begin_function
name|__inline
name|int
name|test2
parameter_list|()
block|{
return|return
literal|5
return|;
block|}
end_function

begin_function_decl
name|__inline
name|int
name|test2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test2
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test_test1
parameter_list|()
block|{
name|test1
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_test2
parameter_list|()
block|{
name|test2
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// PR3989
end_comment

begin_function_decl
specifier|extern
name|__inline
name|void
name|test3
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(gnu_inline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|__inline
name|void
name|__attribute__
argument_list|(
operator|(
name|gnu_inline
operator|)
argument_list|)
name|test3
argument_list|()
block|{}
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|test4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|__inline
name|__attribute__
argument_list|(
operator|(
name|__gnu_inline__
operator|)
argument_list|)
name|int
name|test4
argument_list|(
name|void
argument_list|)
block|{
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_function
name|void
name|test_test4
parameter_list|()
block|{
name|test4
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|__inline
name|int
name|test5
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__gnu_inline__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|extern
name|__inline
name|int
name|__attribute__
argument_list|(
operator|(
name|__gnu_inline__
operator|)
argument_list|)
name|test5
argument_list|(
name|void
argument_list|)
block|{
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_function
name|void
name|test_test5
parameter_list|()
block|{
name|test5
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// PR10233
end_comment

begin_function
name|__inline
name|int
name|test6
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
specifier|extern
name|int
name|test6
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// No PR#, but this once crashed clang in C99 mode due to buggy extern inline
end_comment

begin_comment
comment|// redeclaration detection.
end_comment

begin_function
name|void
name|test7
parameter_list|()
block|{ }
end_function

begin_function_decl
name|void
name|test7
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// PR11062; the fact that the function is named strlcpy matters here.
end_comment

begin_expr_stmt
specifier|inline
name|__typeof
argument_list|(
argument|sizeof(int)
argument_list|)
name|strlcpy
argument_list|(
argument|char *dest
argument_list|,
argument|const char *src
argument_list|,
argument|__typeof(sizeof(int)) size
argument_list|)
block|{
return|return
literal|3
return|;
block|}
end_expr_stmt

begin_function
name|void
name|test8
parameter_list|()
block|{
name|strlcpy
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// PR10657; the test crashed in C99 mode
end_comment

begin_function
specifier|extern
specifier|inline
name|void
name|test9
parameter_list|()
block|{ }
end_function

begin_function_decl
name|void
name|test9
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|inline
name|void
name|testA
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|testA
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|testB
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|inline
name|void
name|testB
parameter_list|()
block|{}
end_function

begin_function_decl
specifier|extern
name|void
name|testB
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|extern
specifier|inline
name|void
name|testC
parameter_list|()
block|{}
end_function

begin_function_decl
specifier|inline
name|void
name|testC
parameter_list|()
function_decl|;
end_function_decl

end_unit

