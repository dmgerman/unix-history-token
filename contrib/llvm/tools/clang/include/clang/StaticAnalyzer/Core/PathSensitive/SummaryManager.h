begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== SummaryManager.h - Generic handling of function summaries --*- C++ -*--==//
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
comment|//  This file defines SummaryManager and related classes, which provides
end_comment

begin_comment
comment|//  a generic mechanism for managing function summaries.
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
name|LLVM_CLANG_GR_SUMMARY
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GR_SUMMARY
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|namespace
name|summMgr
block|{
comment|/* Key kinds:    - C functions  - C++ functions (name + parameter types)  - ObjC methods:    - Class, selector (class method)    - Class, selector (instance method)    - Category, selector (instance method)    - Protocol, selector (instance method)  - C++ methods   - Class, function name + parameter types + const  */
name|class
name|SummaryKey
block|{    }
empty_stmt|;
block|}
comment|// end namespace clang::summMgr
name|class
name|SummaryManagerImpl
block|{    }
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SummaryManager
operator|:
name|SummaryManagerImpl
block|{    }
expr_stmt|;
block|}
comment|// end GR namespace
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

