begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only -triple i686-pc-linux
end_comment

begin_decl_stmt
name|int
name|a
name|__attribute__
argument_list|(
operator|(
name|naked
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'naked' attribute only applies to functions}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(naked)
argument_list|)
end_macro

begin_function
name|int
name|t0
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|("mov r0, #0");
block|}
end_function

begin_function_decl
name|void
name|t1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(naked
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|t2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(naked
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'naked' attribute takes no arguments}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(naked)
argument_list|)
end_macro

begin_function
name|int
name|t3
parameter_list|()
block|{
comment|// expected-note{{attribute is here}}
return|return
literal|42
return|;
comment|// expected-error{{non-ASM statement in naked function is not supported}}
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(naked)
argument_list|)
end_macro

begin_function
name|int
name|t4
parameter_list|()
block|{
asm|asm("movl $42, %eax");
asm|asm("retl");
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(naked)
argument_list|)
end_macro

begin_function
name|int
name|t5
parameter_list|(
name|int
name|x
parameter_list|)
block|{
asm|asm("movl x, %eax");
asm|asm("retl");
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(naked)
argument_list|)
end_macro

begin_function
name|void
name|t6
parameter_list|()
block|{
empty_stmt|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(naked)
argument_list|)
end_macro

begin_function
name|void
name|t7
parameter_list|()
block|{
asm|asm("movl $42, %eax");
empty_stmt|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
end_decl_stmt

begin_macro
name|__attribute__
argument_list|(
argument|(naked)
argument_list|)
end_macro

begin_function
name|void
name|t8
parameter_list|(
name|int
name|z
parameter_list|)
block|{
comment|// expected-note{{attribute is here}}
asm|__asm__ ("movl $42, %1"            : "=r"(x),              "=r"(z)
comment|// expected-error{{parameter references not allowed in naked functions}}
asm|);
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(naked)
argument_list|)
end_macro

begin_function
name|void
name|t9
parameter_list|(
name|int
name|z
parameter_list|)
block|{
comment|// expected-note{{attribute is here}}
asm|__asm__ ("movl %eax, %1"            : : "r"(x),                "r"(z)
comment|// expected-error{{parameter references not allowed in naked functions}}
asm|);
block|}
end_function

end_unit

