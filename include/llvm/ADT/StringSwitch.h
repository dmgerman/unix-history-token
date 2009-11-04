begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- StringSwitch.h - Switch-on-literal-string Construct --------------===/
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
comment|//===----------------------------------------------------------------------===/
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file implements the StringSwitch template, which mimics a switch()
end_comment

begin_comment
comment|//  statements whose cases are string literals.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ADT_STRINGSWITCH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_STRINGSWITCH_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief A switch()-like statement whose cases are string literals.
comment|///
comment|/// The StringSwitch class is a simple form of a switch() statement that
comment|/// determines whether the given string matches one of the given string
comment|/// literals. The template type parameter \p T is the type of the value that
comment|/// will be returned from the string-switch expression. For example,
comment|/// the following code switches on the name of a color in \c argv[i]:
comment|///
comment|/// \code
comment|/// Color color = StringSwitch<Color>(argv[i])
comment|///   .Case("red", Red)
comment|///   .Case("orange", Orange)
comment|///   .Case("yellow", Yellow)
comment|///   .Case("green", Green)
comment|///   .Case("blue", Blue)
comment|///   .Case("indigo", Indigo)
comment|///   .Case("violet", Violet)
comment|///   .Default(UnknownColor);
comment|/// \endcode
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|StringSwitch
block|{
comment|/// \brief The string we are matching.
name|StringRef
name|Str
block|;
comment|/// \brief The result of this switch statement, once known.
name|T
name|Result
block|;
comment|/// \brief Set true when the result of this switch is already known; in this
comment|/// case, Result is valid.
name|bool
name|ResultKnown
block|;
name|public
operator|:
name|explicit
name|StringSwitch
argument_list|(
argument|StringRef Str
argument_list|)
operator|:
name|Str
argument_list|(
name|Str
argument_list|)
block|,
name|ResultKnown
argument_list|(
argument|false
argument_list|)
block|{ }
name|template
operator|<
name|unsigned
name|N
operator|>
name|StringSwitch
operator|&
name|Case
argument_list|(
argument|const char (&S)[N]
argument_list|,
argument|const T& Value
argument_list|)
block|{
if|if
condition|(
operator|!
name|ResultKnown
operator|&&
name|N
operator|-
literal|1
operator|==
name|Str
operator|.
name|size
argument_list|()
operator|&&
operator|(
name|std
operator|::
name|memcmp
argument_list|(
name|S
argument_list|,
name|Str
operator|.
name|data
argument_list|()
argument_list|,
name|N
operator|-
literal|1
argument_list|)
operator|==
literal|0
operator|)
condition|)
block|{
name|Result
operator|=
name|Value
expr_stmt|;
name|ResultKnown
operator|=
name|true
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
name|T
name|Default
argument_list|(
argument|const T& Value
argument_list|)
block|{
if|if
condition|(
name|ResultKnown
condition|)
return|return
name|Result
return|;
return|return
name|Value
return|;
block|}
name|operator
name|T
parameter_list|()
block|{
name|assert
argument_list|(
name|ResultKnown
operator|&&
literal|"Fell off the end of a string-switch"
argument_list|)
expr_stmt|;
return|return
name|Result
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_STRINGSWITCH_H
end_comment

end_unit

