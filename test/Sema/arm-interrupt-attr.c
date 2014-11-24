begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple arm-apple-darwin -verify -fsyntax-only
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

end_unit

