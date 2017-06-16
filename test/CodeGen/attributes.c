begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -triple i386-linux-gnu -o %t %s
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t %s
end_comment

begin_comment
comment|// CHECK: @t5 = weak global i32 2
end_comment

begin_decl_stmt
name|int
name|t5
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @t13 = global %struct.s0 zeroinitializer, section "SECT"
end_comment

begin_struct
struct|struct
name|s0
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|s0
name|t13
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|"SECT"
argument_list|)
operator|)
argument_list|)
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @t14.x = internal global i32 0, section "SECT"
end_comment

begin_function
name|void
name|t14
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|"SECT"
argument_list|)
operator|)
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @t18 = global i32 1, align 4
end_comment

begin_decl_stmt
specifier|extern
name|int
name|t18
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|t18
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @t16 = extern_weak global i32
end_comment

begin_decl_stmt
specifier|extern
name|int
name|t16
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @t6 = common protected global i32 0
end_comment

begin_decl_stmt
name|int
name|t6
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"protected"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @t12 = global i32 0, section "SECT"
end_comment

begin_decl_stmt
name|int
name|t12
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|"SECT"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @t9 = weak alias void (...), bitcast (void ()* @__t8 to void (...)*)
end_comment

begin_function
name|void
name|__t8
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|t9
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(weak
operator|,
function_decl|alias
parameter_list|(
function_decl|"__t8"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: declare extern_weak i32 @t15()
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|weak_import
operator|)
argument_list|)
name|t15
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|t17
parameter_list|()
block|{
return|return
name|t15
argument_list|()
operator|+
name|t16
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @t1() [[NR:#[0-9]+]] {
end_comment

begin_function_decl
name|void
name|t1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t1
parameter_list|()
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_comment
comment|// CHECK: define void @t2() [[NUW:#[0-9]+]] {
end_comment

begin_function_decl
name|void
name|t2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(nothrow
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t2
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: define weak void @t3() [[NUW]] {
end_comment

begin_function_decl
name|void
name|t3
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(weak
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t3
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: define hidden void @t4() [[NUW]] {
end_comment

begin_function_decl
name|void
name|t4
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"hidden"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t4
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: define void @t7() [[NR]] {
end_comment

begin_function_decl
name|void
name|t7
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
operator|,
function_decl|nothrow
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t7
parameter_list|()
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_comment
comment|// CHECK: define void @t72() [[COLDDEF:#[0-9]+]] {
end_comment

begin_function_decl
name|void
name|t71
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(cold
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|t72
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(cold
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t72
parameter_list|()
block|{
name|t71
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: call void @t71() [[COLDSITE:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: declare void @t71() [[COLDDECL:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: define void @t10() [[NUW]] section "SECT" {
end_comment

begin_function_decl
name|void
name|t10
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(section
parameter_list|(
function_decl|"SECT"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t10
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @t11() [[NUW]] section "SECT" {
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|"SECT"
argument_list|)
operator|)
argument_list|)
name|t11
argument_list|(
name|void
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// CHECK: define i32 @t19() [[NUW]] {
end_comment

begin_function_decl
specifier|extern
name|int
name|t19
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak_import
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|t19
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|10
return|;
block|}
end_function

begin_comment
comment|// CHECK:define void @t20() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: call void @abort()
end_comment

begin_comment
comment|// CHECK-NEXT: unreachable
end_comment

begin_function
name|void
name|t20
parameter_list|(
name|void
parameter_list|)
block|{
name|__builtin_abort
argument_list|()
expr_stmt|;
block|}
end_function

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
name|fptr
argument_list|)
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|t21
parameter_list|(
name|void
parameter_list|)
block|{
name|fptr
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: [[FPTRVAR:%[a-z0-9]+]] = load void (i32)*, void (i32)** @fptr
end_comment

begin_comment
comment|// CHECK-NEXT: call x86_fastcallcc void [[FPTRVAR]](i32 inreg 10)
end_comment

begin_comment
comment|// PR9356: We might want to err on this, but for now at least make sure we
end_comment

begin_comment
comment|// use the section in the definition.
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|".foo"
argument_list|)
operator|)
argument_list|)
name|t22
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
name|section
argument_list|(
literal|".bar"
argument_list|)
operator|)
argument_list|)
name|t22
argument_list|(
name|void
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// CHECK: define void @t22() [[NUW]] section ".bar"
end_comment

begin_comment
comment|// CHECK: attributes [[NUW]] = { noinline nounwind{{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[NR]] = { noinline noreturn nounwind{{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[COLDDEF]] = { cold {{.*}}}
end_comment

begin_comment
comment|// CHECK: attributes [[COLDDECL]] = { cold {{.*}}}
end_comment

begin_comment
comment|// CHECK: attributes [[COLDSITE]] = { cold {{.*}}}
end_comment

end_unit

