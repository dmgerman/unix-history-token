begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple mips-img-elf -verify -fsyntax-only
end_comment

begin_struct
struct|struct
name|a
block|{
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|a
name|test
name|__attribute__
argument_list|(
operator|(
name|interrupt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'interrupt' attribute only applies to functions and methods}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"EIC"
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
comment|// expected-warning {{'interrupt' attribute argument not supported: 'EIC'}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"eic"
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
literal|"eic"
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
literal|"vector=sw0"
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
literal|"vector=hw0"
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
literal|"vector=hw1"
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
literal|"vector=hw2"
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
argument|(interrupt(
literal|"vector=hw3"
argument|))
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
argument|(interrupt(
literal|"vector=hw4"
argument|))
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
literal|"vector=hw5"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|fooa
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
name|food
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
name|int
name|foob
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// expected-warning {{MIPS 'interrupt' attribute only applies to functions that have a 'void' return type}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt())
argument_list|)
end_macro

begin_function
name|void
name|fooc
parameter_list|(
name|int
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-warning {{MIPS 'interrupt' attribute only applies to functions that have no parameters}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt,mips16)
argument_list|)
end_macro

begin_function
name|void
name|fooe
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-error {{'interrupt' and 'mips16' attributes are not compatible}} \
end_comment

begin_comment
comment|// expected-note {{conflicting attribute is here}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(mips16,interrupt)
argument_list|)
end_macro

begin_function
name|void
name|foof
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-error {{'mips16' and 'interrupt' attributes are not compatible}} \
end_comment

begin_comment
comment|// expected-note {{conflicting attribute is here}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt)
argument_list|)
end_macro

begin_macro
name|__attribute__
argument_list|(
argument|(mips16)
argument_list|)
end_macro

begin_function
name|void
name|foo10
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-error {{'interrupt' and 'mips16' attributes are not compatible}} \
end_comment

begin_comment
comment|// expected-note {{conflicting attribute is here}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(mips16)
argument_list|)
end_macro

begin_macro
name|__attribute
argument_list|(
argument|(interrupt)
argument_list|)
end_macro

begin_function
name|void
name|foo11
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-error {{'mips16' and 'interrupt' attributes are not compatible}} \
end_comment

begin_comment
comment|// expected-note {{conflicting attribute is here}}
end_comment

end_unit

