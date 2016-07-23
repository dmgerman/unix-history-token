begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_TESTING_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_TESTING_H
end_define

begin_include
include|#
directive|include
file|"test_macros.h"
end_include

begin_if
if|#
directive|if
name|TEST_HAS_FEATURE
argument_list|(
name|address_sanitizer
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
name|int
name|__sanitizer_verify_contiguous_container
parameter_list|(
specifier|const
name|void
modifier|*
name|beg
parameter_list|,
specifier|const
name|void
modifier|*
name|mid
parameter_list|,
specifier|const
name|void
modifier|*
name|end
parameter_list|)
function_decl|;
end_extern

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Alloc
operator|>
name|bool
name|is_contiguous_container_asan_correct
argument_list|(
argument|const std::vector<T
argument_list|,
argument|Alloc>&c
argument_list|)
block|{
if|if
condition|(
name|std
operator|::
name|is_same
operator|<
name|Alloc
operator|,
name|std
operator|::
name|allocator
operator|<
name|T
operator|>
expr|>
operator|::
name|value
operator|&&
name|c
operator|.
name|data
argument_list|()
operator|!=
name|NULL
condition|)
return|return
name|__sanitizer_verify_contiguous_container
argument_list|(
name|c
operator|.
name|data
argument_list|()
argument_list|,
name|c
operator|.
name|data
argument_list|()
operator|+
name|c
operator|.
name|size
argument_list|()
argument_list|,
name|c
operator|.
name|data
argument_list|()
operator|+
name|c
operator|.
name|capacity
argument_list|()
argument_list|)
operator|!=
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_else
unit|}
else|#
directive|else
end_else

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Alloc
operator|>
name|bool
name|is_contiguous_container_asan_correct
argument_list|(
argument|const std::vector<T
argument_list|,
argument|Alloc>&
argument_list|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_TESTING_H
end_comment

end_unit

