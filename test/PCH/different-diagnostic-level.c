begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -x c-header %s -Weverything -o %t.h.pch
end_comment

begin_comment
comment|// RUN: %clang -x c %s -w -include %t.h -fsyntax-only -Xclang -verify
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

begin_decl_stmt
specifier|extern
name|int
name|foo
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|void
name|f
parameter_list|()
block|{
name|int
name|a
init|=
name|foo
decl_stmt|;
comment|// Make sure we parsed this by getting an error.
name|int
name|b
init|=
name|bar
decl_stmt|;
comment|// expected-error {{undeclared}}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

