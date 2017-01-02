begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-linux-gnu -emit-llvm -o - %s | FileCheck -check-prefix=CHECKBASIC %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7a-eabi -mfloat-abi hard -emit-llvm -o - %s | FileCheck -check-prefix=CHECKCC %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7a-eabi -mfloat-abi hard -S -o - %s | FileCheck -check-prefix=CHECKASM %s
end_comment

begin_decl_stmt
name|int
name|g0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECKBASIC-DAG: @g0 = common global i32 0
end_comment

begin_comment
comment|// CHECKASM-DAG: .comm g0,4,4
end_comment

begin_decl_stmt
name|__thread
name|int
name|TL_WITH_ALIAS
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECKBASIC-DAG: @TL_WITH_ALIAS = thread_local global i32 0, align 4
end_comment

begin_comment
comment|// CHECKASM-DAG: .globl TL_WITH_ALIAS
end_comment

begin_comment
comment|// CHECKASM-DAG: .size TL_WITH_ALIAS, 4
end_comment

begin_decl_stmt
specifier|static
name|int
name|bar1
init|=
literal|42
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECKBASIC-DAG: @bar1 = internal global i32 42
end_comment

begin_comment
comment|// CHECKASM-DAG: bar1:
end_comment

begin_comment
comment|// CHECKASM-DAG: .size bar1, 4
end_comment

begin_comment
comment|// PR24379: alias variable expected to have same size as aliasee even when types differ
end_comment

begin_decl_stmt
specifier|const
name|int
name|wacom_usb_ids
index|[]
init|=
block|{
literal|1
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|5
block|,
literal|8
block|,
literal|13
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECKBASIC-DAG: @wacom_usb_ids = constant [8 x i32] [i32 1, i32 1, i32 2, i32 3, i32 5, i32 8, i32 13, i32 0], align 4
end_comment

begin_comment
comment|// CHECKASM-DAG: .globl wacom_usb_ids
end_comment

begin_comment
comment|// CHECKASM-DAG: .size wacom_usb_ids, 32
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|__mod_usb_device_table
name|__attribute__
argument_list|(
operator|(
name|alias
argument_list|(
literal|"wacom_usb_ids"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECKBASIC-DAG: @__mod_usb_device_table = alias i32, getelementptr inbounds ([8 x i32], [8 x i32]* @wacom_usb_ids, i32 0, i32 0)
end_comment

begin_comment
comment|// CHECKASM-DAG: .globl __mod_usb_device_table
end_comment

begin_comment
comment|// CHECKASM-DAG: __mod_usb_device_table = wacom_usb_ids
end_comment

begin_comment
comment|// CHECKASM-NOT: .size __mod_usb_device_table
end_comment

begin_decl_stmt
specifier|extern
name|int
name|g1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|g1
name|__attribute
argument_list|(
operator|(
name|alias
argument_list|(
literal|"g0"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECKBASIC-DAG: @g1 = alias i32, i32* @g0
end_comment

begin_comment
comment|// CHECKASM-DAG: .globl g1
end_comment

begin_comment
comment|// CHECKASM-DAG: g1 = g0
end_comment

begin_comment
comment|// CHECKASM-NOT: .size g1
end_comment

begin_decl_stmt
specifier|extern
name|__thread
name|int
name|__libc_errno
name|__attribute__
argument_list|(
operator|(
name|alias
argument_list|(
literal|"TL_WITH_ALIAS"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECKBASIC-DAG: @__libc_errno = thread_local alias i32, i32* @TL_WITH_ALIAS
end_comment

begin_comment
comment|// CHECKASM-DAG: .globl __libc_errno
end_comment

begin_comment
comment|// CHECKASM-DAG: __libc_errno = TL_WITH_ALIAS
end_comment

begin_comment
comment|// CHECKASM-NOT: .size __libc_errno
end_comment

begin_function
name|void
name|f0
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function_decl
specifier|extern
name|void
name|f1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|f1
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"f0"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECKBASIC-DAG: @f1 = alias void (), void ()* @f0
end_comment

begin_comment
comment|// CHECKBASIC-DAG: @test8_foo = weak alias void (...), bitcast (void ()* @test8_bar to void (...)*)
end_comment

begin_comment
comment|// CHECKBASIC-DAG: @test8_zed = alias void (...), bitcast (void ()* @test8_bar to void (...)*)
end_comment

begin_comment
comment|// CHECKBASIC-DAG: @test9_zed = alias void (), void ()* @test9_bar
end_comment

begin_comment
comment|// CHECKBASIC: define void @f0() [[NUW:#[0-9]+]] {
end_comment

begin_comment
comment|// Make sure that aliases cause referenced values to be emitted.
end_comment

begin_comment
comment|// PR3200
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|foo1
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECKBASIC-LABEL: define internal i32 @foo1()
end_comment

begin_function_decl
name|int
name|foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"foo1"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|bar
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"bar1"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|test6
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test7
parameter_list|()
block|{
name|test6
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// test6 is emitted as extern.
end_comment

begin_comment
comment|// test6 changes to alias.
end_comment

begin_function_decl
name|int
name|test6
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"test7"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
specifier|static
name|int
name|inner
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|inner_weak
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_extern
extern|extern __typeof(inner
end_extern

begin_decl_stmt
unit|)
name|inner_a
name|__attribute__
argument_list|(
operator|(
name|alias
argument_list|(
literal|"inner"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|__typeof
argument_list|(
argument|inner_weak
argument_list|)
name|inner_weak_a
name|__attribute__
argument_list|(
operator|(
name|weakref
operator|,
name|alias
argument_list|(
literal|"inner_weak"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECKCC: @inner_a = alias i32 (i32), i32 (i32)* @inner
end_comment

begin_comment
comment|// CHECKCC: define internal arm_aapcs_vfpcc i32 @inner(i32 %a) [[NUW:#[0-9]+]] {
end_comment

begin_function
name|int
name|outer
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|inner
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECKCC: define arm_aapcs_vfpcc i32 @outer(i32 %a) [[NUW]] {
end_comment

begin_comment
comment|// CHECKCC: call arm_aapcs_vfpcc  i32 @inner(i32 %{{.*}})
end_comment

begin_function
name|int
name|outer_weak
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|inner_weak_a
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECKCC: define arm_aapcs_vfpcc i32 @outer_weak(i32 %a) [[NUW]] {
end_comment

begin_comment
comment|// CHECKCC: call arm_aapcs_vfpcc  i32 @inner_weak(i32 %{{.*}})
end_comment

begin_comment
comment|// CHECKCC: define internal arm_aapcs_vfpcc i32 @inner_weak(i32 %a) [[NUW]] {
end_comment

begin_comment
comment|// CHECKBASIC: attributes [[NUW]] = { noinline nounwind{{.*}} }
end_comment

begin_comment
comment|// CHECKCC: attributes [[NUW]] = { noinline nounwind{{.*}} }
end_comment

begin_function
name|void
name|test8_bar
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|test8_foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(weak
operator|,
function_decl|alias
parameter_list|(
function_decl|"test8_bar"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|test8_zed
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"test8_foo"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test9_bar
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function_decl
name|void
name|test9_zed
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(section
parameter_list|(
function_decl|"test"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|test9_zed
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"test9_bar"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

end_unit

