begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -DMRTD -mrtd -triple i386-unknown-unknown -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -verify %s
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MRTD
end_ifndef

begin_comment
comment|// expected-note@+5 {{previous declaration is here}}
end_comment

begin_comment
comment|// expected-error@+5 {{function declared 'stdcall' here was previously declared without calling convention}}
end_comment

begin_comment
comment|// expected-note@+5 {{previous declaration is here}}
end_comment

begin_comment
comment|// expected-error@+5 {{function declared 'stdcall' here was previously declared without calling convention}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|nonvariadic1
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|nonvariadic1
argument_list|(
name|int
name|a
argument_list|,
name|int
name|b
argument_list|,
name|int
name|c
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|nonvariadic2
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|nonvariadic2
argument_list|(
name|int
name|a
argument_list|,
name|int
name|b
argument_list|,
name|int
name|c
argument_list|)
block|{ }
end_decl_stmt

begin_comment
comment|// expected-warning@+2 {{stdcall calling convention ignored on variadic function}}
end_comment

begin_function_decl
name|void
name|variadic
parameter_list|(
name|int
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|variadic
argument_list|(
name|int
name|a
argument_list|,
operator|...
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MRTD
end_ifdef

begin_comment
comment|// expected-note@+3 {{previous definition is here}}
end_comment

begin_comment
comment|// expected-error@+3 {{redefinition of 'a' with a different type: 'void ((*))(int, int) __attribute__((cdecl))' vs 'void (*)(int, int) __attribute__((stdcall))'}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|a
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__attribute__
argument_list|(
argument|(cdecl)
argument_list|)
end_macro

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|a
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|b
function_decl|)
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__attribute__
argument_list|(
argument|(cdecl)
argument_list|)
end_macro

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|b
function_decl|)
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|MRTD
end_ifndef

begin_comment
comment|// expected-note@+3 {{previous definition is here}}
end_comment

begin_comment
comment|// expected-error@+3 {{redefinition of 'c' with a different type: 'void ((*))(int, int) __attribute__((stdcall))' vs 'void (*)(int, int)'}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|c
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__attribute__
argument_list|(
argument|(stdcall)
argument_list|)
end_macro

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|c
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning@+2 {{stdcall calling convention ignored on variadic function}}
end_comment

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|d
function_decl|)
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__attribute__
argument_list|(
argument|(stdcall)
argument_list|)
end_macro

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|d
function_decl|)
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

end_unit

