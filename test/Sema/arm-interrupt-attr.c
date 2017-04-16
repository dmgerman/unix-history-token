begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple arm-apple-darwin -verify -fsyntax-only
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple thumb-apple-darwin -verify -fsyntax-only
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple armeb-none-eabi -verify -fsyntax-only
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple thumbeb-none-eabi -verify -fsyntax-only
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(IRQ))
argument_list|)
end_macro

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-error {{'interrupt' attribute requires a string}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"irq"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|foo1
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning {{'interrupt' attribute argument not supported: irq}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"IRQ"
argument|,
literal|1
argument|))
argument_list|)
end_macro

begin_function
name|void
name|foo2
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-error {{'interrupt' attribute takes no more than 1 argument}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"IRQ"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|foo3
parameter_list|()
block|{}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"FIQ"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|foo4
parameter_list|()
block|{}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"SWI"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|foo5
parameter_list|()
block|{}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"ABORT"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|foo6
parameter_list|()
block|{}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"UNDEF"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|foo7
parameter_list|()
block|{}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt)
argument_list|)
end_macro

begin_function
name|void
name|foo8
parameter_list|()
block|{}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt())
argument_list|)
end_macro

begin_function
name|void
name|foo9
parameter_list|()
block|{}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|""
argument|))
argument_list|)
end_macro

begin_function
name|void
name|foo10
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|callee1
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"IRQ"
argument|))
argument_list|)
end_macro

begin_function_decl
name|void
name|callee2
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|caller1
parameter_list|()
block|{
name|callee1
argument_list|()
expr_stmt|;
name|callee2
argument_list|()
expr_stmt|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"IRQ"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|caller2
parameter_list|()
block|{
name|callee1
argument_list|()
expr_stmt|;
comment|// expected-warning {{call to function without interrupt attribute could clobber interruptee's VFP registers}}
name|callee2
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
function_decl|(
modifier|*
name|callee3
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"IRQ"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|caller3
parameter_list|()
block|{
name|callee3
argument_list|()
expr_stmt|;
comment|// expected-warning {{call to function without interrupt attribute could clobber interruptee's VFP registers}}
block|}
end_function

end_unit

