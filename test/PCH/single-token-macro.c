begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// rdar://10588825
end_comment

begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -include %s -verify -fsyntax-only
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-pch -o %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -include-pch %t -verify -fsyntax-only
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER
end_ifndef

begin_define
define|#
directive|define
name|HEADER
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__stdcall
end_ifdef

begin_comment
comment|// __stdcall is defined as __attribute__((__stdcall__)) for targeting mingw32.
end_comment

begin_undef
undef|#
directive|undef
name|__stdcall
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__stdcall
end_define

begin_define
define|#
directive|define
name|STDCALL
value|__stdcall
end_define

begin_function_decl
name|void
name|STDCALL
name|Foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function
name|void
name|STDCALL
name|Foo
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

