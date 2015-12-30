begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify %s
end_comment

begin_function_decl
name|void
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|void
name|f
argument_list|()
end_expr_stmt

begin_asm
asm|__asm__("fish");
end_asm

begin_function_decl
name|void
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|f
parameter_list|()
block|{
name|g
argument_list|()
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|void
name|g
argument_list|()
end_expr_stmt

begin_asm
asm|__asm__("gold");
end_asm

begin_comment
comment|// expected-error{{cannot apply asm label to function after its first use}}
end_comment

begin_expr_stmt
name|void
name|h
argument_list|()
end_expr_stmt

begin_asm
asm|__asm__("hose");
end_asm

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_expr_stmt
name|void
name|h
argument_list|()
end_expr_stmt

begin_asm
asm|__asm__("hair");
end_asm

begin_comment
comment|// expected-error{{conflicting asm label}}
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|x
name|__asm__
argument_list|(
literal|"xenon"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|y
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test
parameter_list|()
block|{
return|return
name|y
return|;
block|}
end_function

begin_decl_stmt
name|int
name|y
name|__asm__
argument_list|(
literal|"yacht"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{cannot apply asm label to variable after its first use}}
end_comment

begin_decl_stmt
name|int
name|z
name|__asm__
argument_list|(
literal|"zebra"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_decl_stmt
name|int
name|z
name|__asm__
argument_list|(
literal|"zooms"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{conflicting asm label}}
end_comment

begin_comment
comment|// No diagnostics on the following.
end_comment

begin_expr_stmt
name|void
name|__real_readlink
argument_list|()
asm|__asm("readlink");
name|void
name|readlink
argument_list|()
asm|__asm("__protected_readlink");
name|void
name|readlink
argument_list|()
block|{
name|__real_readlink
argument_list|()
block|; }
end_expr_stmt

end_unit

