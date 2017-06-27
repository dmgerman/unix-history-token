begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Testing/Support/Error.h ---------------------------------------===//
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
name|LLVM_TESTING_SUPPORT_ERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TESTING_SUPPORT_ERROR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Testing/Support/SupportHelpers.h"
end_include

begin_include
include|#
directive|include
file|"gmock/gmock.h"
end_include

begin_include
include|#
directive|include
file|<ostream>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|detail
block|{
name|ErrorHolder
name|TakeError
parameter_list|(
name|Error
name|Err
parameter_list|)
function_decl|;
name|template
operator|<
name|typename
name|T
operator|>
name|ExpectedHolder
operator|<
name|T
operator|>
name|TakeExpected
argument_list|(
argument|Expected<T>&Exp
argument_list|)
block|{
name|llvm
operator|::
name|detail
operator|::
name|ExpectedHolder
operator|<
name|T
operator|>
name|Result
block|;
name|auto
operator|&
name|EH
operator|=
name|static_cast
operator|<
name|llvm
operator|::
name|detail
operator|::
name|ErrorHolder
operator|&
operator|>
operator|(
name|Result
operator|)
block|;
name|EH
operator|=
name|TakeError
argument_list|(
name|Exp
operator|.
name|takeError
argument_list|()
argument_list|)
block|;
if|if
condition|(
name|Result
operator|.
name|Success
condition|)
name|Result
operator|.
name|Value
operator|=
operator|&
operator|(
operator|*
name|Exp
operator|)
expr_stmt|;
return|return
name|Result
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|ExpectedHolder
operator|<
name|T
operator|>
name|TakeExpected
argument_list|(
argument|Expected<T>&&Exp
argument_list|)
block|{
return|return
name|TakeExpected
argument_list|(
name|Exp
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace detail
end_comment

begin_define
define|#
directive|define
name|EXPECT_THAT_ERROR
parameter_list|(
name|Err
parameter_list|,
name|Matcher
parameter_list|)
define|\
value|EXPECT_THAT(llvm::detail::TakeError(Err), Matcher)
end_define

begin_define
define|#
directive|define
name|ASSERT_THAT_ERROR
parameter_list|(
name|Err
parameter_list|,
name|Matcher
parameter_list|)
define|\
value|ASSERT_THAT(llvm::detail::TakeError(Err), Matcher)
end_define

begin_define
define|#
directive|define
name|EXPECT_THAT_EXPECTED
parameter_list|(
name|Err
parameter_list|,
name|Matcher
parameter_list|)
define|\
value|EXPECT_THAT(llvm::detail::TakeExpected(Err), Matcher)
end_define

begin_define
define|#
directive|define
name|ASSERT_THAT_EXPECTED
parameter_list|(
name|Err
parameter_list|,
name|Matcher
parameter_list|)
define|\
value|ASSERT_THAT(llvm::detail::TakeExpected(Err), Matcher)
end_define

begin_macro
name|MATCHER
argument_list|(
argument|Succeeded
argument_list|,
literal|""
argument_list|)
end_macro

begin_block
block|{
return|return
name|arg
operator|.
name|Success
return|;
block|}
end_block

begin_macro
name|MATCHER
argument_list|(
argument|Failed
argument_list|,
literal|""
argument_list|)
end_macro

begin_block
block|{
return|return
operator|!
name|arg
operator|.
name|Success
return|;
block|}
end_block

begin_macro
name|MATCHER_P
argument_list|(
argument|HasValue
argument_list|,
argument|value
argument_list|,
literal|"succeeded with value "
argument|+ testing::PrintToString(value)
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
operator|!
name|arg
operator|.
name|Success
condition|)
block|{
operator|*
name|result_listener
operator|<<
literal|"operation failed"
expr_stmt|;
return|return
name|false
return|;
block|}
name|assert
argument_list|(
name|arg
operator|.
name|Value
operator|.
name|hasValue
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
operator|*
name|arg
operator|.
name|Value
operator|!=
name|value
condition|)
block|{
operator|*
name|result_listener
operator|<<
literal|"but \""
operator|+
name|testing
operator|::
name|PrintToString
argument_list|(
operator|*
operator|*
name|arg
operator|.
name|Value
argument_list|)
operator|+
literal|"\" != "
operator|+
name|testing
operator|::
name|PrintToString
argument_list|(
name|value
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
return|return
name|true
return|;
block|}
end_block

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

