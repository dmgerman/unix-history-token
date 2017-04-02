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
file|"llvm/Support/Compiler.h"
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
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|explicit
name|StringSwitch
argument_list|(
argument|StringRef S
argument_list|)
operator|:
name|Str
argument_list|(
name|S
argument_list|)
block|,
name|Result
argument_list|(
argument|nullptr
argument_list|)
block|{ }
comment|// StringSwitch is not copyable.
name|StringSwitch
argument_list|(
specifier|const
name|StringSwitch
operator|&
argument_list|)
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|StringSwitch
operator|&
operator|)
operator|=
name|delete
block|;
name|StringSwitch
argument_list|(
argument|StringSwitch&&other
argument_list|)
block|{
operator|*
name|this
operator|=
name|std
operator|::
name|move
argument_list|(
name|other
argument_list|)
block|;   }
name|StringSwitch
operator|&
name|operator
operator|=
operator|(
name|StringSwitch
operator|&&
name|other
operator|)
block|{
name|Str
operator|=
name|other
operator|.
name|Str
block|;
name|Result
operator|=
name|other
operator|.
name|Result
block|;
return|return
operator|*
name|this
return|;
block|}
operator|~
name|StringSwitch
argument_list|()
operator|=
expr|default
block|;
comment|// Case-sensitive case matchers
name|template
operator|<
name|unsigned
name|N
operator|>
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|StringSwitch
operator|&
name|Case
argument_list|(
argument|const char (&S)[N]
argument_list|,
argument|const T& Value
argument_list|)
block|{
name|assert
argument_list|(
name|N
argument_list|)
block|;
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
name|N
operator|==
literal|1
operator|||
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
name|N
operator|>
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|StringSwitch
operator|&
name|EndsWith
argument_list|(
argument|const char (&S)[N]
argument_list|,
argument|const T&Value
argument_list|)
block|{
name|assert
argument_list|(
name|N
argument_list|)
block|;
if|if
condition|(
operator|!
name|Result
operator|&&
name|Str
operator|.
name|size
argument_list|()
operator|>=
name|N
operator|-
literal|1
operator|&&
operator|(
name|N
operator|==
literal|1
operator|||
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
operator|+
name|Str
operator|.
name|size
argument_list|()
operator|+
literal|1
operator|-
name|N
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
name|N
operator|>
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|StringSwitch
operator|&
name|StartsWith
argument_list|(
argument|const char (&S)[N]
argument_list|,
argument|const T&Value
argument_list|)
block|{
name|assert
argument_list|(
name|N
argument_list|)
block|;
if|if
condition|(
operator|!
name|Result
operator|&&
name|Str
operator|.
name|size
argument_list|()
operator|>=
name|N
operator|-
literal|1
operator|&&
operator|(
name|N
operator|==
literal|1
operator|||
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
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
name|Cases
argument_list|(
name|S1
argument_list|,
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
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
name|Cases
argument_list|(
name|S1
argument_list|,
name|S2
argument_list|,
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
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
name|Cases
argument_list|(
name|S1
argument_list|,
name|S2
argument_list|,
name|S3
argument_list|,
name|S4
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
block|,
name|unsigned
name|N5
operator|>
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
argument|const char (&S5)[N5]
argument_list|,
argument|const T&Value
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
name|Cases
argument_list|(
name|S1
argument_list|,
name|S2
argument_list|,
name|S3
argument_list|,
name|S4
argument_list|,
name|S5
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
block|,
name|unsigned
name|N5
block|,
name|unsigned
name|N6
operator|>
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
argument|const char (&S5)[N5]
argument_list|,
argument|const char (&S6)[N6]
argument_list|,
argument|const T&Value
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
name|Cases
argument_list|(
name|S1
argument_list|,
name|S2
argument_list|,
name|S3
argument_list|,
name|S4
argument_list|,
name|S5
argument_list|,
name|S6
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
block|,
name|unsigned
name|N5
block|,
name|unsigned
name|N6
block|,
name|unsigned
name|N7
operator|>
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
argument|const char (&S5)[N5]
argument_list|,
argument|const char (&S6)[N6]
argument_list|,
argument|const char (&S7)[N7]
argument_list|,
argument|const T&Value
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
name|Cases
argument_list|(
name|S1
argument_list|,
name|S2
argument_list|,
name|S3
argument_list|,
name|S4
argument_list|,
name|S5
argument_list|,
name|S6
argument_list|,
name|S7
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
block|,
name|unsigned
name|N5
block|,
name|unsigned
name|N6
block|,
name|unsigned
name|N7
block|,
name|unsigned
name|N8
operator|>
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
argument|const char (&S5)[N5]
argument_list|,
argument|const char (&S6)[N6]
argument_list|,
argument|const char (&S7)[N7]
argument_list|,
argument|const char (&S8)[N8]
argument_list|,
argument|const T&Value
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
name|Cases
argument_list|(
name|S1
argument_list|,
name|S2
argument_list|,
name|S3
argument_list|,
name|S4
argument_list|,
name|S5
argument_list|,
name|S6
argument_list|,
name|S7
argument_list|,
name|S8
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
block|,
name|unsigned
name|N5
block|,
name|unsigned
name|N6
block|,
name|unsigned
name|N7
block|,
name|unsigned
name|N8
block|,
name|unsigned
name|N9
operator|>
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
argument|const char (&S5)[N5]
argument_list|,
argument|const char (&S6)[N6]
argument_list|,
argument|const char (&S7)[N7]
argument_list|,
argument|const char (&S8)[N8]
argument_list|,
argument|const char (&S9)[N9]
argument_list|,
argument|const T&Value
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
name|Cases
argument_list|(
name|S1
argument_list|,
name|S2
argument_list|,
name|S3
argument_list|,
name|S4
argument_list|,
name|S5
argument_list|,
name|S6
argument_list|,
name|S7
argument_list|,
name|S8
argument_list|,
name|S9
argument_list|,
name|Value
argument_list|)
return|;
block|}
comment|// Case-insensitive case matchers.
name|template
operator|<
name|unsigned
name|N
operator|>
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|StringSwitch
operator|&
name|CaseLower
argument_list|(
argument|const char (&S)[N]
argument_list|,
argument|const T&Value
argument_list|)
block|{
if|if
condition|(
operator|!
name|Result
operator|&&
name|Str
operator|.
name|equals_lower
argument_list|(
name|StringRef
argument_list|(
name|S
argument_list|,
name|N
operator|-
literal|1
argument_list|)
argument_list|)
condition|)
name|Result
operator|=
operator|&
name|Value
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|template
operator|<
name|unsigned
name|N
operator|>
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|StringSwitch
operator|&
name|EndsWithLower
argument_list|(
argument|const char (&S)[N]
argument_list|,
argument|const T&Value
argument_list|)
block|{
if|if
condition|(
operator|!
name|Result
operator|&&
name|Str
operator|.
name|endswith_lower
argument_list|(
name|StringRef
argument_list|(
name|S
argument_list|,
name|N
operator|-
literal|1
argument_list|)
argument_list|)
condition|)
name|Result
operator|=
operator|&
name|Value
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|unsigned
name|N
operator|>
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|StringSwitch
operator|&
name|StartsWithLower
argument_list|(
argument|const char (&S)[N]
argument_list|,
argument|const T&Value
argument_list|)
block|{
if|if
condition|(
operator|!
name|Result
operator|&&
name|Str
operator|.
name|startswith_lower
argument_list|(
name|StringRef
argument_list|(
name|S
argument_list|,
name|N
operator|-
literal|1
argument_list|)
argument_list|)
condition|)
name|Result
operator|=
operator|&
name|Value
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}   template
operator|<
name|unsigned
name|N0
operator|,
name|unsigned
name|N1
operator|>
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|StringSwitch
operator|&
name|CasesLower
argument_list|(
argument|const char (&S0)[N0]
argument_list|,
argument|const char (&S1)[N1]
argument_list|,
argument|const T&Value
argument_list|)
block|{
return|return
name|CaseLower
argument_list|(
name|S0
argument_list|,
name|Value
argument_list|)
operator|.
name|CaseLower
argument_list|(
name|S1
argument_list|,
name|Value
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|unsigned
name|N0
operator|,
name|unsigned
name|N1
operator|,
name|unsigned
name|N2
operator|>
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|StringSwitch
operator|&
name|CasesLower
argument_list|(
argument|const char (&S0)[N0]
argument_list|,
argument|const char (&S1)[N1]
argument_list|,
argument|const char (&S2)[N2]
argument_list|,
argument|const T&Value
argument_list|)
block|{
return|return
name|CaseLower
argument_list|(
name|S0
argument_list|,
name|Value
argument_list|)
operator|.
name|CasesLower
argument_list|(
name|S1
argument_list|,
name|S2
argument_list|,
name|Value
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|unsigned
name|N0
operator|,
name|unsigned
name|N1
operator|,
name|unsigned
name|N2
operator|,
name|unsigned
name|N3
operator|>
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|StringSwitch
operator|&
name|CasesLower
argument_list|(
argument|const char (&S0)[N0]
argument_list|,
argument|const char (&S1)[N1]
argument_list|,
argument|const char (&S2)[N2]
argument_list|,
argument|const char (&S3)[N3]
argument_list|,
argument|const T&Value
argument_list|)
block|{
return|return
name|CaseLower
argument_list|(
name|S0
argument_list|,
name|Value
argument_list|)
operator|.
name|CasesLower
argument_list|(
name|S1
argument_list|,
name|S2
argument_list|,
name|S3
argument_list|,
name|Value
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|unsigned
name|N0
operator|,
name|unsigned
name|N1
operator|,
name|unsigned
name|N2
operator|,
name|unsigned
name|N3
operator|,
name|unsigned
name|N4
operator|>
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|StringSwitch
operator|&
name|CasesLower
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
argument|const T&Value
argument_list|)
block|{
return|return
name|CaseLower
argument_list|(
name|S0
argument_list|,
name|Value
argument_list|)
operator|.
name|CasesLower
argument_list|(
name|S1
argument_list|,
name|S2
argument_list|,
name|S3
argument_list|,
name|S4
argument_list|,
name|Value
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|R
name|Default
argument_list|(
specifier|const
name|T
operator|&
name|Value
argument_list|)
decl|const
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
end_decl_stmt

begin_expr_stmt
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
end_expr_stmt

begin_comment
unit|};  }
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

