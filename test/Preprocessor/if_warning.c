begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -Eonly -Werror=undef -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -Eonly -Werror-undef -verify
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|foo
end_if

begin_comment
comment|// expected-error {{'foo' is not defined, evaluates to 0}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|foo
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|foo
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PR3938
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|D
end_ifdef

begin_else
else|#
directive|else
else|1
end_else

begin_comment
comment|// Should not warn due to C99 6.10p4
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

