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
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
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
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|class
name|StringRef
decl_stmt|;
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
comment|/// \b Implementation \n
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
comment|/// \b Efficiency Considerations \n
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
comment|/// A pointer to an unsigned int value, to render as an unsigned decimal
comment|/// integer.
name|DecUIKind
block|,
comment|/// A pointer to an int value, to render as a signed decimal integer.
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
name|private
label|:
comment|/// LHS - The prefix in the concatenation, which may be uninitialized for
comment|/// Null or Empty kinds.
specifier|const
name|void
modifier|*
name|LHS
decl_stmt|;
comment|/// RHS - The suffix in the concatenation, which may be uninitialized for
comment|/// Null or Empty kinds.
specifier|const
name|void
modifier|*
name|RHS
decl_stmt|;
comment|/// LHSKind - The NodeKind of the left hand side, \see getLHSKind().
name|NodeKind
name|LHSKind
range|:
literal|8
decl_stmt|;
comment|/// RHSKind - The NodeKind of the left hand side, \see getLHSKind().
name|NodeKind
name|RHSKind
range|:
literal|8
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
name|_LHS
argument_list|,
specifier|const
name|Twine
operator|&
name|_RHS
argument_list|)
operator|:
name|LHS
argument_list|(
operator|&
name|_LHS
argument_list|)
operator|,
name|RHS
argument_list|(
operator|&
name|_RHS
argument_list|)
operator|,
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
argument|const void *_LHS
argument_list|,
argument|NodeKind _LHSKind
argument_list|,
argument|const void *_RHS
argument_list|,
argument|NodeKind _RHSKind
argument_list|)
operator|:
name|LHS
argument_list|(
name|_LHS
argument_list|)
operator|,
name|RHS
argument_list|(
name|_RHS
argument_list|)
operator|,
name|LHSKind
argument_list|(
name|_LHSKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|_RHSKind
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
comment|/// isNull - Check for the null twine.
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
comment|/// isEmpty - Check for the empty twine.
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
comment|/// isNullary - Check if this is a nullary twine (null or empty).
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
comment|/// isUnary - Check if this is a unary twine.
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
comment|/// isBinary - Check if this is a binary twine.
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
comment|/// isValid - Check if this is a valid twine (satisfying the invariants on
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
name|static_cast
operator|<
specifier|const
name|Twine
operator|*
operator|>
operator|(
name|LHS
operator|)
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
name|static_cast
operator|<
specifier|const
name|Twine
operator|*
operator|>
operator|(
name|RHS
operator|)
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
comment|/// getLHSKind - Get the NodeKind of the left-hand side.
name|NodeKind
name|getLHSKind
argument_list|()
specifier|const
block|{
return|return
name|LHSKind
return|;
block|}
comment|/// getRHSKind - Get the NodeKind of the left-hand side.
name|NodeKind
name|getRHSKind
argument_list|()
specifier|const
block|{
return|return
name|RHSKind
return|;
block|}
comment|/// printOneChild - Print one child from a twine.
name|void
name|printOneChild
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|void
operator|*
name|Ptr
argument_list|,
name|NodeKind
name|Kind
argument_list|)
decl|const
decl_stmt|;
comment|/// printOneChildRepr - Print the representation of one child from a twine.
name|void
name|printOneChildRepr
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|void
operator|*
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
name|LHS
argument_list|(
operator|&
name|Str
argument_list|)
operator|,
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
name|LHS
argument_list|(
operator|&
name|Str
argument_list|)
operator|,
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
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"Invalid twine!"
argument_list|)
block|;     }
comment|/// Construct a twine to print \arg Val as an unsigned decimal integer.
name|explicit
name|Twine
argument_list|(
argument|const unsigned int&Val
argument_list|)
operator|:
name|LHS
argument_list|(
operator|&
name|Val
argument_list|)
operator|,
name|LHSKind
argument_list|(
name|DecUIKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{     }
comment|/// Construct a twine to print \arg Val as a signed decimal integer.
name|explicit
name|Twine
argument_list|(
specifier|const
name|int
operator|&
name|Val
argument_list|)
operator|:
name|LHS
argument_list|(
operator|&
name|Val
argument_list|)
operator|,
name|LHSKind
argument_list|(
name|DecIKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{     }
comment|/// Construct a twine to print \arg Val as an unsigned decimal integer.
name|explicit
name|Twine
argument_list|(
argument|const unsigned long&Val
argument_list|)
operator|:
name|LHS
argument_list|(
operator|&
name|Val
argument_list|)
operator|,
name|LHSKind
argument_list|(
name|DecULKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{     }
comment|/// Construct a twine to print \arg Val as a signed decimal integer.
name|explicit
name|Twine
argument_list|(
specifier|const
name|long
operator|&
name|Val
argument_list|)
operator|:
name|LHS
argument_list|(
operator|&
name|Val
argument_list|)
operator|,
name|LHSKind
argument_list|(
name|DecLKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{     }
comment|/// Construct a twine to print \arg Val as an unsigned decimal integer.
name|explicit
name|Twine
argument_list|(
argument|const unsigned long long&Val
argument_list|)
operator|:
name|LHS
argument_list|(
operator|&
name|Val
argument_list|)
operator|,
name|LHSKind
argument_list|(
name|DecULLKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{     }
comment|/// Construct a twine to print \arg Val as a signed decimal integer.
name|explicit
name|Twine
argument_list|(
argument|const long long&Val
argument_list|)
operator|:
name|LHS
argument_list|(
operator|&
name|Val
argument_list|)
operator|,
name|LHSKind
argument_list|(
name|DecLLKind
argument_list|)
operator|,
name|RHSKind
argument_list|(
argument|EmptyKind
argument_list|)
block|{     }
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
name|_LHS
argument_list|,
specifier|const
name|StringRef
operator|&
name|_RHS
argument_list|)
operator|:
name|LHS
argument_list|(
name|_LHS
argument_list|)
operator|,
name|RHS
argument_list|(
operator|&
name|_RHS
argument_list|)
operator|,
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
name|_LHS
argument_list|,
specifier|const
name|char
operator|*
name|_RHS
argument_list|)
operator|:
name|LHS
argument_list|(
operator|&
name|_LHS
argument_list|)
operator|,
name|RHS
argument_list|(
name|_RHS
argument_list|)
operator|,
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
comment|// Construct a twine to print \arg Val as an unsigned hexadecimal integer.
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
return|return
name|Twine
argument_list|(
operator|&
name|Val
argument_list|,
name|UHexKind
argument_list|,
literal|0
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
comment|/// isTriviallyEmpty - Check if this twine is trivially empty; a false
end_comment

begin_comment
comment|/// return value does not necessarily mean the twine is empty.
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
comment|/// @}
end_comment

begin_comment
comment|/// @name String Operations
end_comment

begin_comment
comment|/// @{
end_comment

begin_decl_stmt
name|Twine
name|concat
argument_list|(
specifier|const
name|Twine
operator|&
name|Suffix
argument_list|)
decl|const
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
comment|/// str - Return the twine contents as a std::string.
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
comment|/// toVector - Write the concatenated string into the given SmallString or
end_comment

begin_comment
comment|/// SmallVector.
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
comment|/// print - Write the concatenated string represented by this twine to the
end_comment

begin_comment
comment|/// stream \arg OS.
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
comment|/// dump - Dump the concatenated string represented by this twine to stderr.
end_comment

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// print - Write the representation of this twine to the stream \arg OS.
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
comment|/// dumpRepr - Dump the representation of this twine to stderr.
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
specifier|const
name|void
modifier|*
name|NewLHS
init|=
name|this
decl_stmt|,
modifier|*
name|NewRHS
init|=
operator|&
name|Suffix
decl_stmt|;
end_decl_stmt

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

