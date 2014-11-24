begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64 %s -S -o /dev/null -DWARN -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64 %s -S -o /dev/null -Werror -verify
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
asm|asm("movaps %xmm3, (%esi, 2)");
comment|// expected-note@1 {{instantiated into assembly here}}
ifdef|#
directive|ifdef
name|WARN
comment|// expected-warning@-3 {{scale factor without index register is ignored}}
else|#
directive|else
comment|// expected-error@-5 {{scale factor without index register is ignored}}
endif|#
directive|endif
block|}
end_function

begin_decl_stmt
specifier|static
name|unsigned
name|var
index|[
literal|1
index|]
init|=
block|{}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|g
parameter_list|(
name|void
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|("movd %%xmm0, %0"                             :                             : "m"(var));
block|}
end_function

end_unit

