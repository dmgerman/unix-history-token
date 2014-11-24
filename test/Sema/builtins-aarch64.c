begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -DTEST1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -DTEST1 -fsyntax-only -verify %s
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
comment|// AArch32 version of this is variadic (at least syntactically).
comment|// However, on AArch64 GCC does not permit this call and the
comment|// implementation I've seen would go disastrously wrong.
name|__clear_cache
argument_list|()
expr_stmt|;
comment|// expected-error {{too few arguments to function call}}
block|}
end_function

end_unit

