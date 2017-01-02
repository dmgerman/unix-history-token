begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -std=c99 -Wno-nullability-declspec -pedantic %s -verify
end_comment

begin_decl_stmt
name|_Nonnull
name|int
modifier|*
name|ptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{type nullability specifier '_Nonnull' is a Clang extension}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wnullability-extension"
end_pragma

begin_decl_stmt
name|_Nonnull
name|int
modifier|*
name|ptr2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// no-warning
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
end_pragma

begin_if
if|#
directive|if
operator|!
name|__has_feature
argument_list|(
name|nullability
argument_list|)
end_if

begin_error
error|#
directive|error
error|Nullability should always be supported
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|__has_feature
argument_list|(
name|nullability_on_arrays
argument_list|)
end_if

begin_error
error|#
directive|error
error|Nullability on array parameters should always be supported
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|__has_extension
argument_list|(
name|nullability
argument_list|)
end_if

begin_error
error|#
directive|error
error|Nullability should always be supported as an extension
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|__has_extension
argument_list|(
name|nullability_on_arrays
argument_list|)
end_if

begin_error
error|#
directive|error
error|Nullability on array parameters should always be supported as an extension
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

