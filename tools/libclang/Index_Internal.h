begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CXString.h - Routines for manipulating CXStrings -------------------===//
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
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines routines for manipulating CXStrings.
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
name|LLVM_CLANG_TOOLS_LIBCLANG_INDEX_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLS_LIBCLANG_INDEX_INTERNAL_H
end_define

begin_include
include|#
directive|include
file|"clang-c/Index.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__has_feature
end_ifndef

begin_define
define|#
directive|define
name|__has_feature
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|blocks
argument_list|)
end_if

begin_define
define|#
directive|define
name|INVOKE_BLOCK2
parameter_list|(
name|block
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
value|block(arg1, arg2)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// If we are compiled with a compiler that doesn't have native blocks support,
end_comment

begin_comment
comment|// define and call the block manually.
end_comment

begin_define
define|#
directive|define
name|INVOKE_BLOCK2
parameter_list|(
name|block
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
value|block->invoke(block, arg1, arg2)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CXCursorAndRangeVisitorBlock
block|{
name|void
modifier|*
name|isa
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|int
name|reserved
decl_stmt|;
name|enum
name|CXVisitorResult
function_decl|(
modifier|*
name|invoke
function_decl|)
parameter_list|(
name|_CXCursorAndRangeVisitorBlock
modifier|*
parameter_list|,
name|CXCursor
parameter_list|,
name|CXSourceRange
parameter_list|)
function_decl|;
block|}
typedef|*
name|CXCursorAndRangeVisitorBlock
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !__has_feature(blocks)
end_comment

begin_comment
comment|/// \brief The result of comparing two source ranges.
end_comment

begin_enum
enum|enum
name|RangeComparisonResult
block|{
comment|/// \brief Either the ranges overlap or one of the ranges is invalid.
name|RangeOverlap
block|,
comment|/// \brief The first range ends before the second range starts.
name|RangeBefore
block|,
comment|/// \brief The first range starts after the second range ends.
name|RangeAfter
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

end_unit

