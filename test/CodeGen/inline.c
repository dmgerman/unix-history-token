begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: echo "GNU89 tests:"
end_comment

begin_comment
comment|// RUN: %clang %s -O1 -emit-llvm -S -o %t -std=gnu89
end_comment

begin_comment
comment|// RUN: grep "define available_externally i32 @ei()" %t
end_comment

begin_comment
comment|// RUN: grep "define i32 @foo()" %t
end_comment

begin_comment
comment|// RUN: grep "define i32 @bar()" %t
end_comment

begin_comment
comment|// RUN: grep "define void @unreferenced1()" %t
end_comment

begin_comment
comment|// RUN: not grep unreferenced2 %t
end_comment

begin_comment
comment|// RUN: grep "define void @gnu_inline()" %t
end_comment

begin_comment
comment|// RUN: grep "define available_externally void @gnu_ei_inline()" %t
end_comment

begin_comment
comment|// RUN: grep "define i32 @test1" %t
end_comment

begin_comment
comment|// RUN: grep "define i32 @test2" %t
end_comment

begin_comment
comment|// RUN: grep "define void @test3()" %t
end_comment

begin_comment
comment|// RUN: grep "define available_externally i32 @test4" %t
end_comment

begin_comment
comment|// RUN: grep "define available_externally i32 @test5" %t
end_comment

begin_comment
comment|// RUN: grep "define i32 @test6" %t
end_comment

begin_comment
comment|// RUN: grep "define void @test7" %t
end_comment

begin_comment
comment|// RUN: grep "define i.. @strlcpy" %t
end_comment

begin_comment
comment|// RUN: not grep test9 %t
end_comment

begin_comment
comment|// RUN: grep "define void @testA" %t
end_comment

begin_comment
comment|// RUN: grep "define void @testB" %t
end_comment

begin_comment
comment|// RUN: grep "define void @testC" %t
end_comment

begin_comment
comment|// RUN: echo "C99 tests:"
end_comment

begin_comment
comment|// RUN: %clang %s -O1 -emit-llvm -S -o %t -std=gnu99
end_comment

begin_comment
comment|// RUN: grep "define i32 @ei()" %t
end_comment

begin_comment
comment|// RUN: grep "define available_externally i32 @foo()" %t
end_comment

begin_comment
comment|// RUN: grep "define i32 @bar()" %t
end_comment

begin_comment
comment|// RUN: not grep unreferenced1 %t
end_comment

begin_comment
comment|// RUN: grep "define void @unreferenced2()" %t
end_comment

begin_comment
comment|// RUN: grep "define void @gnu_inline()" %t
end_comment

begin_comment
comment|// RUN: grep "define available_externally void @gnu_ei_inline()" %t
end_comment

begin_comment
comment|// RUN: grep "define i32 @test1" %t
end_comment

begin_comment
comment|// RUN: grep "define i32 @test2" %t
end_comment

begin_comment
comment|// RUN: grep "define void @test3" %t
end_comment

begin_comment
comment|// RUN: grep "define available_externally i32 @test4" %t
end_comment

begin_comment
comment|// RUN: grep "define available_externally i32 @test5" %t
end_comment

begin_comment
comment|// RUN: grep "define i32 @test6" %t
end_comment

begin_comment
comment|// RUN: grep "define void @test7" %t
end_comment

begin_comment
comment|// RUN: grep "define available_externally i.. @strlcpy" %t
end_comment

begin_comment
comment|// RUN: grep "define void @test9" %t
end_comment

begin_comment
comment|// RUN: grep "define void @testA" %t
end_comment

begin_comment
comment|// RUN: grep "define void @testB" %t
end_comment

begin_comment
comment|// RUN: grep "define void @testC" %t
end_comment

begin_comment
comment|// RUN: echo "C++ tests:"
end_comment

begin_comment
comment|// RUN: %clang -x c++ %s -O1 -emit-llvm -S -o %t -std=c++98
end_comment

begin_comment
comment|// RUN: grep "define linkonce_odr i32 @_Z2eiv()" %t
end_comment

begin_comment
comment|// RUN: grep "define linkonce_odr i32 @_Z3foov()" %t
end_comment

begin_comment
comment|// RUN: grep "define i32 @_Z3barv()" %t
end_comment

begin_comment
comment|// RUN: not grep unreferenced %t
end_comment

begin_comment
comment|// RUN: grep "define void @_Z10gnu_inlinev()" %t
end_comment

begin_comment
comment|// RUN: grep "define available_externally void @_Z13gnu_ei_inlinev()" %t
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

