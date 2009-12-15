begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -O3 -S -o - -emit-llvm %s | grep extern_weak
end_comment

begin_comment
comment|// RUN: %llvmgcc -O3 -S -o - -emit-llvm %s | llc
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__DragonFly__
argument_list|)
end_if

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(weak_import
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(weak
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|bar
parameter_list|()
block|{
name|foo
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

