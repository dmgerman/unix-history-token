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
comment|//  statement whose cases are string literals.
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
comment|///   .Cases("violet", "purple", Violet)
comment|///   .Default(UnknownColor);
comment|/// \endcode
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|R
operator|=
name|T
operator|>
name|class
name|StringSwitch
block|{
comment|/// \brief The string we are matching.
name|StringRef
name|Str
block|;
comment|/// \brief The pointer to the result of this switch statement, once known,
comment|/// null before that.
specifier|const
name|T
operator|*
name|Result
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
name|Result
argument_list|(
literal|0
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
name|Result
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
operator|&
name|Value
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
name|template
operator|<
name|unsigned
name|N0
block|,
name|unsigned
name|N1
operator|>
name|StringSwitch
operator|&
name|Cases
argument_list|(
argument|const char (&S0)[N0]
argument_list|,
argument|const char (&S1)[N1]
argument_list|,
argument|const T& Value
argument_list|)
block|{
return|return
name|Case
argument_list|(
name|S0
argument_list|,
name|Value
argument_list|)
operator|.
name|Case
argument_list|(
name|S1
argument_list|,
name|Value
argument_list|)
return|;
block|}
name|template
operator|<
name|unsigned
name|N0
block|,
name|unsigned
name|N1
block|,
name|unsigned
name|N2
operator|>
name|StringSwitch
operator|&
name|Cases
argument_list|(
argument|const char (&S0)[N0]
argument_list|,
argument|const char (&S1)[N1]
argument_list|,
argument|const char (&S2)[N2]
argument_list|,
argument|const T& Value
argument_list|)
block|{
return|return
name|Case
argument_list|(
name|S0
argument_list|,
name|Value
argument_list|)
operator|.
name|Case
argument_list|(
name|S1
argument_list|,
name|Value
argument_list|)
operator|.
name|Case
argument_list|(
name|S2
argument_list|,
name|Value
argument_list|)
return|;
block|}
name|template
operator|<
name|unsigned
name|N0
block|,
name|unsigned
name|N1
block|,
name|unsigned
name|N2
block|,
name|unsigned
name|N3
operator|>
name|StringSwitch
operator|&
name|Cases
argument_list|(
argument|const char (&S0)[N0]
argument_list|,
argument|const char (&S1)[N1]
argument_list|,
argument|const char (&S2)[N2]
argument_list|,
argument|const char (&S3)[N3]
argument_list|,
argument|const T& Value
argument_list|)
block|{
return|return
name|Case
argument_list|(
name|S0
argument_list|,
name|Value
argument_list|)
operator|.
name|Case
argument_list|(
name|S1
argument_list|,
name|Value
argument_list|)
operator|.
name|Case
argument_list|(
name|S2
argument_list|,
name|Value
argument_list|)
operator|.
name|Case
argument_list|(
name|S3
argument_list|,
name|Value
argument_list|)
return|;
block|}
name|template
operator|<
name|unsigned
name|N0
block|,
name|unsigned
name|N1
block|,
name|unsigned
name|N2
block|,
name|unsigned
name|N3
block|,
name|unsigned
name|N4
operator|>
name|StringSwitch
operator|&
name|Cases
argument_list|(
argument|const char (&S0)[N0]
argument_list|,
argument|const char (&S1)[N1]
argument_list|,
argument|const char (&S2)[N2]
argument_list|,
argument|const char (&S3)[N3]
argument_list|,
argument|const char (&S4)[N4]
argument_list|,
argument|const T& Value
argument_list|)
block|{
return|return
name|Case
argument_list|(
name|S0
argument_list|,
name|Value
argument_list|)
operator|.
name|Case
argument_list|(
name|S1
argument_list|,
name|Value
argument_list|)
operator|.
name|Case
argument_list|(
name|S2
argument_list|,
name|Value
argument_list|)
operator|.
name|Case
argument_list|(
name|S3
argument_list|,
name|Value
argument_list|)
operator|.
name|Case
argument_list|(
name|S4
argument_list|,
name|Value
argument_list|)
return|;
block|}
name|R
name|Default
argument_list|(
argument|const T& Value
argument_list|)
specifier|const
block|{
if|if
condition|(
name|Result
condition|)
return|return
operator|*
name|Result
return|;
return|return
name|Value
return|;
block|}
name|operator
name|R
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Result
operator|&&
literal|"Fell off the end of a string-switch"
argument_list|)
block|;
return|return
operator|*
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

