begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Testing/Support/SupportHelpers.h -----------------------------------===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TESTING_SUPPORT_SUPPORTHELPERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TESTING_SUPPORT_SUPPORTHELPERS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"gtest/gtest-printers.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|detail
block|{
struct|struct
name|ErrorHolder
block|{
name|bool
name|Success
decl_stmt|;
name|std
operator|::
name|string
name|Message
expr_stmt|;
block|}
struct|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|ExpectedHolder
operator|:
name|public
name|ErrorHolder
block|{
name|Optional
operator|<
name|T
operator|*
operator|>
name|Value
block|; }
expr_stmt|;
specifier|inline
name|void
name|PrintTo
argument_list|(
specifier|const
name|ErrorHolder
operator|&
name|Err
argument_list|,
name|std
operator|::
name|ostream
operator|*
name|Out
argument_list|)
block|{
operator|*
name|Out
operator|<<
operator|(
name|Err
operator|.
name|Success
condition|?
literal|"succeeded"
else|:
literal|"failed"
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|Err
operator|.
name|Success
condition|)
block|{
operator|*
name|Out
operator|<<
literal|"  ("
operator|<<
name|StringRef
argument_list|(
name|Err
operator|.
name|Message
argument_list|)
operator|.
name|trim
argument_list|()
operator|.
name|str
argument_list|()
operator|<<
literal|")"
expr_stmt|;
block|}
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|PrintTo
argument_list|(
argument|const ExpectedHolder<T>&Item
argument_list|,
argument|std::ostream *Out
argument_list|)
block|{
if|if
condition|(
name|Item
operator|.
name|Success
condition|)
block|{
operator|*
name|Out
operator|<<
literal|"succeeded with value \""
operator|<<
operator|::
name|testing
operator|::
name|PrintToString
argument_list|(
operator|*
operator|*
name|Item
operator|.
name|Value
argument_list|)
operator|<<
literal|"\""
expr_stmt|;
block|}
else|else
block|{
name|PrintTo
argument_list|(
name|static_cast
operator|<
specifier|const
name|ErrorHolder
operator|&
operator|>
operator|(
name|Item
operator|)
argument_list|,
name|Out
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|// namespace detail
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

