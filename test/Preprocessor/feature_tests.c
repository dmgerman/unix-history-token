begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -triple=i686-apple-darwin9
end_comment

begin_comment
comment|// RUN: clang-cc %s -E -triple=i686-apple-darwin9
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__has_feature
end_ifndef

begin_error
error|#
directive|error
error|Should have __has_feature
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|something_we_dont_have
argument_list|)
end_if

begin_error
error|#
directive|error
error|Bad
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|__has_builtin
argument_list|(
name|__builtin_huge_val
argument_list|)
operator|||
expr|\
operator|!
name|__has_builtin
argument_list|(
name|__builtin_shufflevector
argument_list|)
operator|||
expr|\
operator|!
name|__has_builtin
argument_list|(
name|__builtin_trap
argument_list|)
operator|||
expr|\
operator|!
name|__has_feature
argument_list|(
name|attribute_analyzer_noreturn
argument_list|)
operator|||
expr|\
operator|!
name|__has_feature
argument_list|(
name|attribute_overloadable
argument_list|)
end_if

begin_error
error|#
directive|error
error|Clang should have these
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_insanity
argument_list|)
end_if

begin_error
error|#
directive|error
error|Clang should not have this
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Make sure we have x86 builtins only (forced with target triple).
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_builtin
argument_list|(
name|__builtin_ia32_emms
argument_list|)
operator|||
expr|\
name|__has_builtin
argument_list|(
name|__builtin_altivec_abs_v4sf
argument_list|)
end_if

begin_error
error|#
directive|error
error|Broken handling of target-specific builtins
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

