begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=i686-apple-darwin -target-feature +mmx -emit-llvm -o - -Wall -Werror
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +mmx -emit-llvm -o - -Wall -Werror
end_comment

begin_comment
comment|// REQUIRES: asserts
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|__vector_size__
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
name|b
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|b
operator|=
name|__builtin_ia32_vec_init_v2si
argument_list|(
literal|0
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

