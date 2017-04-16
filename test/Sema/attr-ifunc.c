begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux -fsyntax-only -verify -emit-llvm-only -DCHECK_ALIASES %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux -fsyntax-only -verify -emit-llvm-only %s
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|bar
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(ifunc
parameter_list|(
function_decl|"foo"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-warning@-1 {{'ifunc' attribute ignored}}
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CHECK_ALIASES
argument_list|)
end_if

begin_function_decl
name|void
modifier|*
name|f1_ifunc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(ifunc
parameter_list|(
function_decl|"f1_ifunc"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error@-1 {{ifunc must point to a defined function}}
end_comment

begin_function_decl
name|void
modifier|*
name|f2_a
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(ifunc
parameter_list|(
function_decl|"f2_b"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error@-1 {{ifunc definition is part of a cycle}}
end_comment

begin_function_decl
name|void
modifier|*
name|f2_b
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(ifunc
parameter_list|(
function_decl|"f2_a"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error@-1 {{ifunc definition is part of a cycle}}
end_comment

begin_function_decl
name|void
modifier|*
name|f3_a
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(ifunc
parameter_list|(
function_decl|"f3_b"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-warning@-1 {{ifunc will always resolve to f3_c even if weak definition of f3_b is overridden}}
end_comment

begin_function_decl
name|void
modifier|*
name|f3_b
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(weak
operator|,
function_decl|alias
parameter_list|(
function_decl|"f3_c"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
modifier|*
name|f3_c
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|f4_ifunc
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|f4
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(ifunc
parameter_list|(
function_decl|"f4_ifunc"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error@-1 {{ifunc resolver function must return a pointer}}
end_comment

begin_function
name|void
modifier|*
name|f5_ifunc
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|void
name|f5
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(ifunc
parameter_list|(
function_decl|"f5_ifunc"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error@-1 {{ifunc resolver function must have no parameters}}
end_comment

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|void
name|f1a
argument_list|()
asm|__asm("f1");
name|void
name|f1a
argument_list|()
block|{}
comment|//expected-note@-1 {{previous definition is here}}
name|void
name|f1
argument_list|()
name|__attribute__
argument_list|(
operator|(
name|ifunc
argument_list|(
literal|"f1_ifunc"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//expected-error@-1 {{definition with same mangled name as another definition}}
end_comment

begin_function
name|void
modifier|*
name|f1_ifunc
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|void
modifier|*
name|f6_ifunc
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|ifunc
argument_list|(
literal|"f6_ifunc"
argument_list|)
operator|)
argument_list|)
name|f6
argument_list|()
block|{}
end_decl_stmt

begin_comment
comment|//expected-error@-1 {{definition 'f6' cannot also be an ifunc}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

