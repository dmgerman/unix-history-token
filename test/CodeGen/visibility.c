begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-unknown-unknown -fvisibility default -emit-llvm -o - | FileCheck %s -check-prefix=CHECK-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-unknown-unknown -fvisibility protected -emit-llvm -o - | FileCheck %s -check-prefix=CHECK-PROTECTED
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-unknown-unknown -fvisibility hidden -emit-llvm -o - | FileCheck %s -check-prefix=CHECK-HIDDEN
end_comment

begin_comment
comment|// CHECK-DEFAULT: @g_def = global i32 0
end_comment

begin_comment
comment|// CHECK-DEFAULT: @g_com = common global i32 0
end_comment

begin_comment
comment|// CHECK-DEFAULT: @g_ext = external global i32
end_comment

begin_comment
comment|// CHECK-DEFAULT: @g_deferred = internal global
end_comment

begin_comment
comment|// CHECK-PROTECTED: @g_def = protected global i32 0
end_comment

begin_comment
comment|// CHECK-PROTECTED: @g_com = common protected global i32 0
end_comment

begin_comment
comment|// CHECK-PROTECTED: @g_ext = external global i32
end_comment

begin_comment
comment|// CHECK-PROTECTED: @g_deferred = internal global
end_comment

begin_comment
comment|// CHECK-HIDDEN: @g_def = hidden global i32 0
end_comment

begin_comment
comment|// CHECK-HIDDEN: @g_com = common hidden global i32 0
end_comment

begin_comment
comment|// CHECK-HIDDEN: @g_ext = external global i32
end_comment

begin_comment
comment|// CHECK-HIDDEN: @g_deferred = internal global
end_comment

begin_decl_stmt
name|int
name|g_com
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|g_def
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|g_ext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|g_deferred
index|[]
init|=
literal|"hello"
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DEFAULT: @test4 = hidden global i32 10
end_comment

begin_comment
comment|// CHECK-PROTECTED: @test4 = hidden global i32 10
end_comment

begin_comment
comment|// CHECK-HIDDEN: @test4 = hidden global i32 10
end_comment

begin_comment
comment|// CHECK-DEFAULT-LABEL: define i32 @f_def()
end_comment

begin_comment
comment|// CHECK-DEFAULT: declare void @f_ext()
end_comment

begin_comment
comment|// CHECK-DEFAULT-LABEL: define internal void @f_deferred()
end_comment

begin_comment
comment|// CHECK-PROTECTED-LABEL: define protected i32 @f_def()
end_comment

begin_comment
comment|// CHECK-PROTECTED: declare void @f_ext()
end_comment

begin_comment
comment|// CHECK-PROTECTED-LABEL: define internal void @f_deferred()
end_comment

begin_comment
comment|// CHECK-HIDDEN-LABEL: define hidden i32 @f_def()
end_comment

begin_comment
comment|// CHECK-HIDDEN: declare void @f_ext()
end_comment

begin_comment
comment|// CHECK-HIDDEN-LABEL: define internal void @f_deferred()
end_comment

begin_function_decl
specifier|extern
name|void
name|f_ext
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|f_deferred
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|int
name|f_def
parameter_list|(
name|void
parameter_list|)
block|{
name|f_ext
argument_list|()
expr_stmt|;
name|f_deferred
argument_list|()
expr_stmt|;
return|return
name|g_com
operator|+
name|g_def
operator|+
name|g_ext
operator|+
name|g_deferred
index|[
literal|0
index|]
return|;
block|}
end_function

begin_comment
comment|// PR8457
end_comment

begin_comment
comment|// CHECK-DEFAULT-LABEL: define void @test1(
end_comment

begin_comment
comment|// CHECK-PROTECTED-LABEL: define void @test1(
end_comment

begin_comment
comment|// CHECK-HIDDEN-LABEL: define void @test1(
end_comment

begin_struct
struct|struct
name|Test1
block|{
name|int
name|field
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"default"
argument_list|)
operator|)
argument_list|)
name|test1
argument_list|(
expr|struct
name|Test1
operator|*
name|v
argument_list|)
block|{ }
end_decl_stmt

begin_comment
comment|// rdar://problem/8595231
end_comment

begin_comment
comment|// CHECK-DEFAULT-LABEL: define void @test2()
end_comment

begin_comment
comment|// CHECK-PROTECTED-LABEL: define void @test2()
end_comment

begin_comment
comment|// CHECK-HIDDEN-LABEL: define void @test2()
end_comment

begin_function_decl
name|void
name|test2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"default"
argument_list|)
operator|)
argument_list|)
name|test2
argument_list|(
name|void
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// CHECK-DEFAULT-LABEL: define hidden void @test3()
end_comment

begin_comment
comment|// CHECK-PROTECTED-LABEL: define hidden void @test3()
end_comment

begin_comment
comment|// CHECK-HIDDEN-LABEL: define hidden void @test3()
end_comment

begin_function_decl
specifier|extern
name|void
name|test3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|__private_extern__
name|void
name|test3
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// Top of file.
end_comment

begin_decl_stmt
specifier|extern
name|int
name|test4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__private_extern__
name|int
name|test4
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_comment
comment|// rdar://12399248
end_comment

begin_comment
comment|// CHECK-DEFAULT-LABEL: define hidden void @test5()
end_comment

begin_comment
comment|// CHECK-PROTECTED-LABEL: define hidden void @test5()
end_comment

begin_comment
comment|// CHECK-HIDDEN-LABEL: define hidden void @test5()
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(availability(macosx,introduced=
literal|10.5
argument|,deprecated=
literal|10.6
argument|))
argument_list|)
end_macro

begin_function
name|__private_extern__
name|void
name|test5
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

end_unit

