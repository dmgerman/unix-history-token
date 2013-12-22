begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fms-extensions -D MS -isystem %S/Inputs %s -fsyntax-only -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fms-extensions -D MS -Wno-keyword-compat -I %S/Inputs %s -fsyntax-only -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fms-extensions -D MS -D NOT_SYSTEM -I %S/Inputs %s -fsyntax-only -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -isystem %S/Inputs %s -fsyntax-only -verify
end_comment

begin_comment
comment|// PR17824: GNU libc uses MS keyword __uptr as an identifier in C mode
end_comment

begin_include
include|#
directive|include
file|<ms-keyword-system-header.h>
end_include

begin_function
name|void
name|fn
parameter_list|()
block|{
name|WS
name|ws
decl_stmt|;
name|ws
operator|.
name|__uptr
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|MS
comment|// expected-error@-2 {{expected identifier}}
else|#
directive|else
comment|// expected-no-diagnostics
endif|#
directive|endif
block|}
end_function

end_unit

