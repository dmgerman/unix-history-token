begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios -DTEST1 -fsyntax-only -verify %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST1
end_ifdef

begin_function_decl
name|void
name|__clear_cache
parameter_list|(
name|void
modifier|*
name|start
parameter_list|,
name|void
modifier|*
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|test_clear_cache_chars
parameter_list|(
name|char
modifier|*
name|start
parameter_list|,
name|char
modifier|*
name|end
parameter_list|)
block|{
name|__clear_cache
argument_list|(
name|start
argument_list|,
name|end
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_clear_cache_voids
parameter_list|(
name|void
modifier|*
name|start
parameter_list|,
name|void
modifier|*
name|end
parameter_list|)
block|{
name|__clear_cache
argument_list|(
name|start
argument_list|,
name|end
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_clear_cache_no_args
parameter_list|()
block|{
name|__clear_cache
argument_list|()
expr_stmt|;
comment|// expected-error {{too few arguments to function call}}
block|}
end_function

begin_function
name|void
name|test_memory_barriers
parameter_list|()
block|{
name|__builtin_arm_dmb
argument_list|(
literal|16
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_arm_dsb
argument_list|(
literal|17
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_arm_isb
argument_list|(
literal|18
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
block|}
end_function

end_unit

