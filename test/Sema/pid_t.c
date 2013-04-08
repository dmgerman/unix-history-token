begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i586-pc-haiku -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux -fsyntax-only -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__HAIKU__
end_ifdef

begin_typedef
typedef|typedef
name|signed
name|long
name|pid_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|signed
name|int
name|pid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|pid_t
name|vfork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

