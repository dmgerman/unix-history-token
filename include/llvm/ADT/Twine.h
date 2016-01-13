begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Twine.h - Fast Temporary String Concatenation -----------*- C++ -*-===//
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
name|LLVM_ADT_TWINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_TWINE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
comment|/// Twine - A lightweight data structure for efficiently representing the
comment|/// concatenation of temporary values as strings.
comment|///
comment|/// A Twine is a kind of rope, it represents a concatenated string using a
comment|/// binary-tree, where the string is the preorder of the nodes. Since the
comment|/// Twine can be efficiently rendered into a buffer when its result is used,
comment|/// it avoids the cost of generating temporary values for intermediate string
comment|/// results -- particularly in cases when the Twine result is never
comment|/// required. By explicitly tracking the type of leaf nodes, we can also avoid
comment|/// the creation of temporary strings for conversions operations (such as
comment|/// appending an integer to a string).
comment|///
comment|/// A Twine is not intended for use directly and should not be stored, its
comment|/// implementation relies on the ability to store pointers to temporary stack
comment|/// objects which may be deallocated at the end of a statement. Twines should
comment|/// only be used accepted as const references in arguments, when an API wishes
comment|/// to accept possibly-concatenated strings.
comment|///
comment|/// Twines support a special 'null' value, which always concatenates to form
comment|/// itself, and renders as an empty string. This can be returned from APIs to
comment|/// effectively nullify any concatenations performed on the result.
comment|///
comment|/// \b Implementation
comment|///
comment|/// Given the nature of a Twine, it is not possible for the Twine's
comment|/// concatenation method to construct interior nodes; the result must be
comment|/// represented inside the returned value. For this reason a Twine object
comment|/// actually holds two values, the left- and right-hand sides of a
comment|/// concatenation. We also have nullary Twine objects, which are effectively
comment|/// sentinel values that represent empty strings.
comment|///
comment|/// Thus, a Twine can effectively have zero, one, or two children. The \see
comment|/// isNullary(), \see isUnary(), and \see isBinary() predicates exist for
comment|/// testing the number of children.
comment|///
comment|/// We maintain a number of invariants on Twine objects (FIXME: Why):
comment|///  - Nullary twines are always represented with their Kind on the left-hand
comment|///    side, and the Empty kind on the right-hand side.
comment|///  - Unary twines are always represented with the value on the left-hand
comment|///    side, and the Empty kind on the right-hand side.
comment|///  - If a Twine has another Twine as a child, that child should always be
comment|///    binary (otherwise it could have been folded into the parent).
comment|///
comment|/// These invariants are check by \see isValid().
comment|///
comment|/// \b Efficiency Considerations
comment|///
comment|/// The Twine is designed to yield efficient and small code for common
comment|/// situations. For this reason, the concat() method is inlined so that
comment|/// concatenations of leaf nodes can be optimized into stores directly into a
comment|/// single stack allocated object.
comment|///
comment|/// In practice, not all compilers can be trusted to optimize concat() fully,
comment|/// so we provide two additional methods (and accompanying operator+
comment|/// overloads) to guarantee that particularly important cases (cstring plus
comment|/// StringRef) codegen as desired.
name|class
name|Twine
block|{
comment|/// NodeKind - Represent the type of an argument.
enum|enum
name|NodeKind
enum|:
name|unsigned
name|char
block|{
comment|/// An empty string; the result of concatenating anything with it is also
comment|/// empty.
name|NullKind
block|,
comment|/// The empty string.
name|EmptyKind
block|,
comment|/// A pointer to a Twine instance.
name|TwineKind
block|,
comment|/// A pointer to a C string instance.
name|CStringKind
block|,
comment|/// A pointer to an std::string instance.
name|StdStringKind
block|,
comment|/// A pointer to a StringRef instance.
name|StringRefKind
block|,
comment|/// A pointer to a SmallString instance.
name|SmallStringKind
block|,
comment|/// A char value, to render as a character.
name|CharKind
block|,
comment|/// An unsigned int value, to render as an unsigned decimal integer.
name|DecUIKind
block|,
comment|/// An int value, to render as a signed decimal integer.
name|DecIKind
block|,
comment|/// A pointer to an unsigned long value, to render as an unsigned decimal
comment|/// integer.
name|DecULKind
block|,
comment|/// A pointer to a long value, to render as a signed decimal integer.
name|DecLKind
block|,
comment|/// A pointer to an unsigned long long value, to render as an unsigned
comment|/// decimal integer.
name|DecULLKind
block|,
comment|/// A pointer to a long long value, to render as a signed decimal integer.
name|DecLLKind
block|,
comment|/// A pointer to a uint64_t value, to render as an unsigned hexadecimal
comment|/// integer.
name|UHexKind
block|}
enum|;
union|union
name|Child
block|{
specifier|const
name|Twine
modifier|*
name|twine
decl_stmt|;
specifier|const
name|char
modifier|*
name|cString
decl_stmt|;
specifier|const
name|std
operator|::
name|string
operator|*
name|stdString
expr_stmt|;
specifier|const
name|StringRef
modifier|*
name|stringRef
decl_stmt|;
specifier|const
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|*
name|smallString
expr_stmt|;
name|char
name|character
decl_stmt|;
name|unsigned
name|int
name|decUI
decl_stmt|;
name|int
name|decI
decl_stmt|;
specifier|const
name|unsigned
name|long
modifier|*
name|decUL
decl_stmt|;
specifier|const
name|long
modifier|*
name|decL
decl_stmt|;
specifier|const
name|unsigned
name|long
name|long
modifier|*
name|decULL
decl_stmt|;
specifier|const
name|long
name|long
modifier|*
name|decLL
decl_stmt|;
specifier|const
name|uint64_t
modifier|*
name|uHex
decl_stmt|;
block|}
union|;
name|private
label|:
comment|/// LHS - The prefix in the concatenation, which may be uninitialized for
comment|/// Null or Empty kinds.
name|Child
name|LHS
decl_stmt|;
comment|/// RHS - The suffix in the concatenation, which may be uninitialized for
comment|/// Null or Empty kinds.
name|Child
name|RHS
decl_stmt|;
comment|/// LHSKind - The NodeKind of the left hand side, \see getLHSKind().
name|NodeKind
name|LHSKind
decl_stmt|;
comment|/// RHSKind - The NodeKind of the right hand side, \see getRHSKind().
name|NodeKind
name|RHSKind
decl_stmt|;
name|private
label|:
comment|/// Construct a nullary twine; the kind must be NullKind or EmptyKind.
name|explicit
name|Twine
argument_list|(
argument|NodeKind Kind
argument_list|)
block|:
name|LHSKind
argument_list|(
name|Kind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{
name|assert
argument_list|(
name|isNullary
argument_list|()
operator|&&
literal|"Invalid kind!"
argument_list|)
block|;     }
comment|/// Construct a binary twine.
name|explicit
name|Twine
argument_list|(
specifier|const
name|Twine
operator|&
name|LHS
argument_list|,
specifier|const
name|Twine
operator|&
name|RHS
argument_list|)
operator|:
name|LHSKind
argument_list|(
name|TwineKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|TwineKind
argument_list|)
block|{
name|this
operator|->
name|LHS
operator|.
name|twine
operator|=
operator|&
name|LHS
block|;
name|this
operator|->
name|RHS
operator|.
name|twine
operator|=
operator|&
name|RHS
block|;
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"Invalid twine!"
argument_list|)
block|;     }
comment|/// Construct a twine from explicit values.
name|explicit
name|Twine
argument_list|(
argument|Child LHS
argument_list|,
argument|NodeKind LHSKind
argument_list|,
argument|Child RHS
argument_list|,
argument|NodeKind RHSKind
argument_list|)
operator|:
name|LHS
argument_list|(
name|LHS
argument_list|)
operator|,
name|RHS
argument_list|(
name|RHS
argument_list|)
operator|,
name|LHSKind
argument_list|(
name|LHSKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|RHSKind
argument_list|)
block|{
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"Invalid twine!"
argument_list|)
block|;     }
comment|/// Since the intended use of twines is as temporary objects, assignments
comment|/// when concatenating might cause undefined behavior or stack corruptions
name|Twine
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Twine
operator|&
name|Other
operator|)
operator|=
name|delete
expr_stmt|;
comment|/// Check for the null twine.
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|getLHSKind
argument_list|()
operator|==
name|NullKind
return|;
block|}
comment|/// Check for the empty twine.
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|getLHSKind
argument_list|()
operator|==
name|EmptyKind
return|;
block|}
comment|/// Check if this is a nullary twine (null or empty).
name|bool
name|isNullary
argument_list|()
specifier|const
block|{
return|return
name|isNull
argument_list|()
operator|||
name|isEmpty
argument_list|()
return|;
block|}
comment|/// Check if this is a unary twine.
name|bool
name|isUnary
argument_list|()
specifier|const
block|{
return|return
name|getRHSKind
argument_list|()
operator|==
name|EmptyKind
operator|&&
operator|!
name|isNullary
argument_list|()
return|;
block|}
comment|/// Check if this is a binary twine.
name|bool
name|isBinary
argument_list|()
specifier|const
block|{
return|return
name|getLHSKind
argument_list|()
operator|!=
name|NullKind
operator|&&
name|getRHSKind
argument_list|()
operator|!=
name|EmptyKind
return|;
block|}
comment|/// Check if this is a valid twine (satisfying the invariants on
comment|/// order and number of arguments).
name|bool
name|isValid
argument_list|()
specifier|const
block|{
comment|// Nullary twines always have Empty on the RHS.
if|if
condition|(
name|isNullary
argument_list|()
operator|&&
name|getRHSKind
argument_list|()
operator|!=
name|EmptyKind
condition|)
return|return
name|false
return|;
comment|// Null should never appear on the RHS.
if|if
condition|(
name|getRHSKind
argument_list|()
operator|==
name|NullKind
condition|)
return|return
name|false
return|;
comment|// The RHS cannot be non-empty if the LHS is empty.
if|if
condition|(
name|getRHSKind
argument_list|()
operator|!=
name|EmptyKind
operator|&&
name|getLHSKind
argument_list|()
operator|==
name|EmptyKind
condition|)
return|return
name|false
return|;
comment|// A twine child should always be binary.
if|if
condition|(
name|getLHSKind
argument_list|()
operator|==
name|TwineKind
operator|&&
operator|!
name|LHS
operator|.
name|twine
operator|->
name|isBinary
argument_list|()
condition|)
return|return
name|false
return|;
if|if
condition|(
name|getRHSKind
argument_list|()
operator|==
name|TwineKind
operator|&&
operator|!
name|RHS
operator|.
name|twine
operator|->
name|isBinary
argument_list|()
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
comment|/// Get the NodeKind of the left-hand side.
name|NodeKind
name|getLHSKind
argument_list|()
specifier|const
block|{
return|return
name|LHSKind
return|;
block|}
comment|/// Get the NodeKind of the right-hand side.
name|NodeKind
name|getRHSKind
argument_list|()
specifier|const
block|{
return|return
name|RHSKind
return|;
block|}
comment|/// Print one child from a twine.
name|void
name|printOneChild
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|Child
name|Ptr
argument_list|,
name|NodeKind
name|Kind
argument_list|)
decl|const
decl_stmt|;
comment|/// Print the representation of one child from a twine.
name|void
name|printOneChildRepr
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|Child
name|Ptr
argument_list|,
name|NodeKind
name|Kind
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
comment|/// @name Constructors
comment|/// @{
comment|/// Construct from an empty string.
comment|/*implicit*/
name|Twine
argument_list|()
operator|:
name|LHSKind
argument_list|(
name|EmptyKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"Invalid twine!"
argument_list|)
block|;     }
name|Twine
argument_list|(
specifier|const
name|Twine
operator|&
argument_list|)
operator|=
expr|default
expr_stmt|;
comment|/// Construct from a C string.
comment|///
comment|/// We take care here to optimize "" into the empty twine -- this will be
comment|/// optimized out for string constants. This allows Twine arguments have
comment|/// default "" values, without introducing unnecessary string constants.
comment|/*implicit*/
name|Twine
argument_list|(
specifier|const
name|char
operator|*
name|Str
argument_list|)
operator|:
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{
if|if
condition|(
name|Str
index|[
literal|0
index|]
operator|!=
literal|'\0'
condition|)
block|{
name|LHS
operator|.
name|cString
operator|=
name|Str
expr_stmt|;
name|LHSKind
operator|=
name|CStringKind
expr_stmt|;
block|}
else|else
name|LHSKind
operator|=
name|EmptyKind
expr_stmt|;
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"Invalid twine!"
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// Construct from an std::string.
end_comment

begin_comment
comment|/*implicit*/
end_comment

begin_expr_stmt
name|Twine
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Str
argument_list|)
operator|:
name|LHSKind
argument_list|(
name|StdStringKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{
name|LHS
operator|.
name|stdString
operator|=
operator|&
name|Str
block|;
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"Invalid twine!"
argument_list|)
block|;     }
comment|/// Construct from a StringRef.
comment|/*implicit*/
name|Twine
argument_list|(
specifier|const
name|StringRef
operator|&
name|Str
argument_list|)
operator|:
name|LHSKind
argument_list|(
name|StringRefKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{
name|LHS
operator|.
name|stringRef
operator|=
operator|&
name|Str
block|;
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"Invalid twine!"
argument_list|)
block|;     }
comment|/// Construct from a SmallString.
comment|/*implicit*/
name|Twine
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Str
argument_list|)
operator|:
name|LHSKind
argument_list|(
name|SmallStringKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{
name|LHS
operator|.
name|smallString
operator|=
operator|&
name|Str
block|;
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"Invalid twine!"
argument_list|)
block|;     }
comment|/// Construct from a char.
name|explicit
name|Twine
argument_list|(
argument|char Val
argument_list|)
operator|:
name|LHSKind
argument_list|(
name|CharKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{
name|LHS
operator|.
name|character
operator|=
name|Val
block|;     }
comment|/// Construct from a signed char.
name|explicit
name|Twine
argument_list|(
argument|signed char Val
argument_list|)
operator|:
name|LHSKind
argument_list|(
name|CharKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{
name|LHS
operator|.
name|character
operator|=
name|static_cast
operator|<
name|char
operator|>
operator|(
name|Val
operator|)
block|;     }
comment|/// Construct from an unsigned char.
name|explicit
name|Twine
argument_list|(
argument|unsigned char Val
argument_list|)
operator|:
name|LHSKind
argument_list|(
name|CharKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{
name|LHS
operator|.
name|character
operator|=
name|static_cast
operator|<
name|char
operator|>
operator|(
name|Val
operator|)
block|;     }
comment|/// Construct a twine to print \p Val as an unsigned decimal integer.
name|explicit
name|Twine
argument_list|(
argument|unsigned Val
argument_list|)
operator|:
name|LHSKind
argument_list|(
name|DecUIKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{
name|LHS
operator|.
name|decUI
operator|=
name|Val
block|;     }
comment|/// Construct a twine to print \p Val as a signed decimal integer.
name|explicit
name|Twine
argument_list|(
argument|int Val
argument_list|)
operator|:
name|LHSKind
argument_list|(
name|DecIKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{
name|LHS
operator|.
name|decI
operator|=
name|Val
block|;     }
comment|/// Construct a twine to print \p Val as an unsigned decimal integer.
name|explicit
name|Twine
argument_list|(
argument|const unsigned long&Val
argument_list|)
operator|:
name|LHSKind
argument_list|(
name|DecULKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{
name|LHS
operator|.
name|decUL
operator|=
operator|&
name|Val
block|;     }
comment|/// Construct a twine to print \p Val as a signed decimal integer.
name|explicit
name|Twine
argument_list|(
specifier|const
name|long
operator|&
name|Val
argument_list|)
operator|:
name|LHSKind
argument_list|(
name|DecLKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{
name|LHS
operator|.
name|decL
operator|=
operator|&
name|Val
block|;     }
comment|/// Construct a twine to print \p Val as an unsigned decimal integer.
name|explicit
name|Twine
argument_list|(
argument|const unsigned long long&Val
argument_list|)
operator|:
name|LHSKind
argument_list|(
name|DecULLKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{
name|LHS
operator|.
name|decULL
operator|=
operator|&
name|Val
block|;     }
comment|/// Construct a twine to print \p Val as a signed decimal integer.
name|explicit
name|Twine
argument_list|(
argument|const long long&Val
argument_list|)
operator|:
name|LHSKind
argument_list|(
name|DecLLKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{
name|LHS
operator|.
name|decLL
operator|=
operator|&
name|Val
block|;     }
comment|// FIXME: Unfortunately, to make sure this is as efficient as possible we
comment|// need extra binary constructors from particular types. We can't rely on
comment|// the compiler to be smart enough to fold operator+()/concat() down to the
comment|// right thing. Yet.
comment|/// Construct as the concatenation of a C string and a StringRef.
comment|/*implicit*/
name|Twine
argument_list|(
specifier|const
name|char
operator|*
name|LHS
argument_list|,
specifier|const
name|StringRef
operator|&
name|RHS
argument_list|)
operator|:
name|LHSKind
argument_list|(
name|CStringKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|StringRefKind
argument_list|)
block|{
name|this
operator|->
name|LHS
operator|.
name|cString
operator|=
name|LHS
block|;
name|this
operator|->
name|RHS
operator|.
name|stringRef
operator|=
operator|&
name|RHS
block|;
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"Invalid twine!"
argument_list|)
block|;     }
comment|/// Construct as the concatenation of a StringRef and a C string.
comment|/*implicit*/
name|Twine
argument_list|(
specifier|const
name|StringRef
operator|&
name|LHS
argument_list|,
specifier|const
name|char
operator|*
name|RHS
argument_list|)
operator|:
name|LHSKind
argument_list|(
name|StringRefKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|CStringKind
argument_list|)
block|{
name|this
operator|->
name|LHS
operator|.
name|stringRef
operator|=
operator|&
name|LHS
block|;
name|this
operator|->
name|RHS
operator|.
name|cString
operator|=
name|RHS
block|;
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"Invalid twine!"
argument_list|)
block|;     }
comment|/// Create a 'null' string, which is an empty string that always
comment|/// concatenates to form another empty string.
specifier|static
name|Twine
name|createNull
argument_list|()
block|{
return|return
name|Twine
argument_list|(
name|NullKind
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Numeric Conversions
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|// Construct a twine to print \p Val as an unsigned hexadecimal integer.
end_comment

begin_function
specifier|static
name|Twine
name|utohexstr
parameter_list|(
specifier|const
name|uint64_t
modifier|&
name|Val
parameter_list|)
block|{
name|Child
name|LHS
decl_stmt|,
name|RHS
decl_stmt|;
name|LHS
operator|.
name|uHex
operator|=
operator|&
name|Val
expr_stmt|;
name|RHS
operator|.
name|twine
operator|=
name|nullptr
expr_stmt|;
return|return
name|Twine
argument_list|(
name|LHS
argument_list|,
name|UHexKind
argument_list|,
name|RHS
argument_list|,
name|EmptyKind
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Predicate Operations
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// Check if this twine is trivially empty; a false return value does not
end_comment

begin_comment
comment|/// necessarily mean the twine is empty.
end_comment

begin_expr_stmt
name|bool
name|isTriviallyEmpty
argument_list|()
specifier|const
block|{
return|return
name|isNullary
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Return true if this twine can be dynamically accessed as a single
end_comment

begin_comment
comment|/// StringRef value with getSingleStringRef().
end_comment

begin_expr_stmt
name|bool
name|isSingleStringRef
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getRHSKind
argument_list|()
operator|!=
name|EmptyKind
condition|)
return|return
name|false
return|;
end_expr_stmt

begin_switch
switch|switch
condition|(
name|getLHSKind
argument_list|()
condition|)
block|{
case|case
name|EmptyKind
case|:
case|case
name|CStringKind
case|:
case|case
name|StdStringKind
case|:
case|case
name|StringRefKind
case|:
case|case
name|SmallStringKind
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
end_switch

begin_comment
unit|}
comment|/// @}
end_comment

begin_comment
comment|/// @name String Operations
end_comment

begin_comment
comment|/// @{
end_comment

begin_macro
unit|Twine
name|concat
argument_list|(
argument|const Twine&Suffix
argument_list|)
end_macro

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Output& Conversion.
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// Return the twine contents as a std::string.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|str
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Append the concatenated string into the given SmallString or SmallVector.
end_comment

begin_decl_stmt
name|void
name|toVector
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Out
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// This returns the twine as a single StringRef.  This method is only valid
end_comment

begin_comment
comment|/// if isSingleStringRef() is true.
end_comment

begin_expr_stmt
name|StringRef
name|getSingleStringRef
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isSingleStringRef
argument_list|()
operator|&&
literal|"This cannot be had as a single stringref!"
argument_list|)
block|;
switch|switch
condition|(
name|getLHSKind
argument_list|()
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"Out of sync with isSingleStringRef"
argument_list|)
expr_stmt|;
case|case
name|EmptyKind
case|:
return|return
name|StringRef
argument_list|()
return|;
case|case
name|CStringKind
case|:
return|return
name|StringRef
argument_list|(
name|LHS
operator|.
name|cString
argument_list|)
return|;
case|case
name|StdStringKind
case|:
return|return
name|StringRef
argument_list|(
operator|*
name|LHS
operator|.
name|stdString
argument_list|)
return|;
case|case
name|StringRefKind
case|:
return|return
operator|*
name|LHS
operator|.
name|stringRef
return|;
case|case
name|SmallStringKind
case|:
return|return
name|StringRef
argument_list|(
name|LHS
operator|.
name|smallString
operator|->
name|data
argument_list|()
argument_list|,
name|LHS
operator|.
name|smallString
operator|->
name|size
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|/// This returns the twine as a single StringRef if it can be
end_comment

begin_comment
comment|/// represented as such. Otherwise the twine is written into the given
end_comment

begin_comment
comment|/// SmallVector and a StringRef to the SmallVector's data is returned.
end_comment

begin_macro
unit|StringRef
name|toStringRef
argument_list|(
argument|SmallVectorImpl<char>&Out
argument_list|)
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
name|isSingleStringRef
argument_list|()
condition|)
return|return
name|getSingleStringRef
argument_list|()
return|;
name|toVector
argument_list|(
name|Out
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|StringRef
argument_list|(
name|Out
operator|.
name|data
argument_list|()
argument_list|,
name|Out
operator|.
name|size
argument_list|()
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// This returns the twine as a single null terminated StringRef if it
end_comment

begin_comment
comment|/// can be represented as such. Otherwise the twine is written into the
end_comment

begin_comment
comment|/// given SmallVector and a StringRef to the SmallVector's data is returned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The returned StringRef's size does not include the null terminator.
end_comment

begin_macro
unit|StringRef
name|toNullTerminatedStringRef
argument_list|(
argument|SmallVectorImpl<char>&Out
argument_list|)
end_macro

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Write the concatenated string represented by this twine to the
end_comment

begin_comment
comment|/// stream \p OS.
end_comment

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Dump the concatenated string represented by this twine to stderr.
end_comment

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Write the representation of this twine to the stream \p OS.
end_comment

begin_decl_stmt
name|void
name|printRepr
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Dump the representation of this twine to stderr.
end_comment

begin_expr_stmt
name|void
name|dumpRepr
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
unit|};
comment|/// @name Twine Inline Implementations
end_comment

begin_comment
comment|/// @{
end_comment

begin_expr_stmt
specifier|inline
name|Twine
name|Twine
operator|::
name|concat
argument_list|(
argument|const Twine&Suffix
argument_list|)
specifier|const
block|{
comment|// Concatenation with null is null.
if|if
condition|(
name|isNull
argument_list|()
operator|||
name|Suffix
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|Twine
argument_list|(
name|NullKind
argument_list|)
return|;
end_expr_stmt

begin_comment
comment|// Concatenation with empty yields the other side.
end_comment

begin_if
if|if
condition|(
name|isEmpty
argument_list|()
condition|)
return|return
name|Suffix
return|;
end_if

begin_if
if|if
condition|(
name|Suffix
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
operator|*
name|this
return|;
end_if

begin_comment
comment|// Otherwise we need to create a new node, taking care to fold in unary
end_comment

begin_comment
comment|// twines.
end_comment

begin_decl_stmt
name|Child
name|NewLHS
decl_stmt|,
name|NewRHS
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NewLHS
operator|.
name|twine
operator|=
name|this
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NewRHS
operator|.
name|twine
operator|=
operator|&
name|Suffix
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|NodeKind
name|NewLHSKind
init|=
name|TwineKind
decl_stmt|,
name|NewRHSKind
init|=
name|TwineKind
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|isUnary
argument_list|()
condition|)
block|{
name|NewLHS
operator|=
name|LHS
expr_stmt|;
name|NewLHSKind
operator|=
name|getLHSKind
argument_list|()
expr_stmt|;
block|}
end_if

begin_if
if|if
condition|(
name|Suffix
operator|.
name|isUnary
argument_list|()
condition|)
block|{
name|NewRHS
operator|=
name|Suffix
operator|.
name|LHS
expr_stmt|;
name|NewRHSKind
operator|=
name|Suffix
operator|.
name|getLHSKind
argument_list|()
expr_stmt|;
block|}
end_if

begin_return
return|return
name|Twine
argument_list|(
name|NewLHS
argument_list|,
name|NewLHSKind
argument_list|,
name|NewRHS
argument_list|,
name|NewRHSKind
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}    inline
name|Twine
name|operator
operator|+
operator|(
specifier|const
name|Twine
operator|&
name|LHS
operator|,
specifier|const
name|Twine
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|concat
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Additional overload to guarantee simplified codegen; this is equivalent to
end_comment

begin_comment
comment|/// concat().
end_comment

begin_expr_stmt
specifier|inline
name|Twine
name|operator
operator|+
operator|(
specifier|const
name|char
operator|*
name|LHS
operator|,
specifier|const
name|StringRef
operator|&
name|RHS
operator|)
block|{
return|return
name|Twine
argument_list|(
name|LHS
argument_list|,
name|RHS
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Additional overload to guarantee simplified codegen; this is equivalent to
end_comment

begin_comment
comment|/// concat().
end_comment

begin_expr_stmt
specifier|inline
name|Twine
name|operator
operator|+
operator|(
specifier|const
name|StringRef
operator|&
name|LHS
operator|,
specifier|const
name|char
operator|*
name|RHS
operator|)
block|{
return|return
name|Twine
argument_list|(
name|LHS
argument_list|,
name|RHS
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|Twine
operator|&
name|RHS
operator|)
block|{
name|RHS
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

