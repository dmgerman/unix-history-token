begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm< %s | FileCheck %s
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|f1
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|f2
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|thiscall
operator|)
argument_list|)
name|f3
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|f4
argument_list|(
name|void
argument_list|)
block|{
comment|// CHECK-LABEL: define x86_fastcallcc void @f4()
name|f1
argument_list|()
expr_stmt|;
comment|// CHECK: call x86_fastcallcc void @f1()
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|f5
argument_list|(
name|void
argument_list|)
block|{
comment|// CHECK-LABEL: define x86_stdcallcc void @f5()
name|f2
argument_list|()
expr_stmt|;
comment|// CHECK: call x86_stdcallcc void @f2()
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|thiscall
operator|)
argument_list|)
name|f6
argument_list|(
name|void
argument_list|)
block|{
comment|// CHECK-LABEL: define x86_thiscallcc void @f6()
name|f3
argument_list|()
expr_stmt|;
comment|// CHECK: call x86_thiscallcc void @f3()
block|}
end_decl_stmt

begin_comment
comment|// PR5280
end_comment

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
operator|*
name|pf1
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
name|f1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
operator|*
name|pf2
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
name|f2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|thiscall
operator|)
argument_list|)
operator|*
name|pf3
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
name|f3
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
operator|*
name|pf4
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
name|f4
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
operator|*
name|pf5
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
name|f5
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|thiscall
operator|)
argument_list|)
operator|*
name|pf6
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
name|f6
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|f4
argument_list|()
expr_stmt|;
name|f5
argument_list|()
expr_stmt|;
name|f6
argument_list|()
expr_stmt|;
comment|// CHECK: call x86_fastcallcc void @f4()
comment|// CHECK: call x86_stdcallcc void @f5()
comment|// CHECK: call x86_thiscallcc void @f6()
name|pf1
argument_list|()
expr_stmt|;
name|pf2
argument_list|()
expr_stmt|;
name|pf3
argument_list|()
expr_stmt|;
name|pf4
argument_list|()
expr_stmt|;
name|pf5
argument_list|()
expr_stmt|;
name|pf6
argument_list|()
expr_stmt|;
comment|// CHECK: call x86_fastcallcc void %{{.*}}()
comment|// CHECK: call x86_stdcallcc void %{{.*}}()
comment|// CHECK: call x86_thiscallcc void %{{.*}}()
comment|// CHECK: call x86_fastcallcc void %{{.*}}()
comment|// CHECK: call x86_stdcallcc void %{{.*}}()
comment|// CHECK: call x86_thiscallcc void %{{.*}}()
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// PR7117
end_comment

begin_decl_stmt
name|void
name|__attribute
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|f7
argument_list|(
name|foo
argument_list|)
name|int
name|foo
decl_stmt|;
end_decl_stmt

begin_block
block|{}
end_block

begin_function
name|void
name|f8
parameter_list|(
name|void
parameter_list|)
block|{
name|f7
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call x86_stdcallcc void @f7(i32 0)
block|}
end_function

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|foo1
argument_list|(
name|int
name|y
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar1
parameter_list|(
name|int
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @bar1
comment|// CHECK: call x86_fastcallcc void @foo1(i32 inreg %
name|foo1
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|S1
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|foo2
argument_list|(
expr|struct
name|S1
name|y
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar2
parameter_list|(
name|struct
name|S1
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @bar2
comment|// CHECK: call x86_fastcallcc void @foo2(i32 inreg undef, i32 %
name|foo2
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|foo3
argument_list|(
name|int
operator|*
name|y
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar3
parameter_list|(
name|int
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @bar3
comment|// CHECK: call x86_fastcallcc void @foo3(i32* inreg %
name|foo3
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_enum
enum|enum
name|Enum
block|{
name|Eval
block|}
enum|;
end_enum

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|foo4
argument_list|(
expr|enum
name|Enum
name|y
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar4
parameter_list|(
name|enum
name|Enum
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @bar4
comment|// CHECK: call x86_fastcallcc void @foo4(i32 inreg %
name|foo4
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|S2
block|{
name|int
name|x1
decl_stmt|;
name|double
name|x2
decl_stmt|;
name|double
name|x3
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|foo5
argument_list|(
expr|struct
name|S2
name|y
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar5
parameter_list|(
name|struct
name|S2
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @bar5
comment|// CHECK: call x86_fastcallcc void @foo5(%struct.S2* byval align 4 %
name|foo5
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|foo6
argument_list|(
name|long
name|long
name|y
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar6
parameter_list|(
name|long
name|long
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @bar6
comment|// CHECK: call x86_fastcallcc void @foo6(i64 %
name|foo6
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|foo7
argument_list|(
name|int
name|a
argument_list|,
expr|struct
name|S1
name|b
argument_list|,
name|int
name|c
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar7
parameter_list|(
name|int
name|a
parameter_list|,
name|struct
name|S1
name|b
parameter_list|,
name|int
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @bar7
comment|// CHECK: call x86_fastcallcc void @foo7(i32 inreg %{{.*}}, i32 %{{.*}}, i32 %{{.*}}
name|foo7
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|foo8
argument_list|(
expr|struct
name|S1
name|a
argument_list|,
name|int
name|b
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar8
parameter_list|(
name|struct
name|S1
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @bar8
comment|// CHECK: call x86_fastcallcc void @foo8(i32 inreg undef, i32 %{{.*}}, i32 inreg %
name|foo8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|foo9
argument_list|(
expr|struct
name|S2
name|a
argument_list|,
name|int
name|b
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar9
parameter_list|(
name|struct
name|S2
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @bar9
comment|// CHECK: call x86_fastcallcc void @foo9(%struct.S2* byval align 4 %{{.*}}, i32 %
name|foo9
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|foo10
argument_list|(
name|float
name|y
argument_list|,
name|int
name|x
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar10
parameter_list|(
name|float
name|y
parameter_list|,
name|int
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @bar10
comment|// CHECK: call x86_fastcallcc void @foo10(float %{{.*}}, i32 inreg %
name|foo10
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|foo11
argument_list|(
name|double
name|y
argument_list|,
name|int
name|x
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar11
parameter_list|(
name|double
name|y
parameter_list|,
name|int
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @bar11
comment|// CHECK: call x86_fastcallcc void @foo11(double %{{.*}}, i32 inreg %
name|foo11
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|S3
block|{
name|float
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|foo12
argument_list|(
expr|struct
name|S3
name|y
argument_list|,
name|int
name|x
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar12
parameter_list|(
name|struct
name|S3
name|y
parameter_list|,
name|int
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @bar12
comment|// CHECK: call x86_fastcallcc void @foo12(float %{{.*}}, i32 inreg %
name|foo12
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

