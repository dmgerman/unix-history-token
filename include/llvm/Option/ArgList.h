begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ArgList.h - Argument List Management ---------------------*- C++ -*-===//
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
name|LLVM_OPTION_ARGLIST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OPTION_ARGLIST_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

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
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Option/Arg.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Option/OptSpecifier.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Option/Option.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<initializer_list>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|namespace
name|opt
block|{
comment|/// arg_iterator - Iterates through arguments stored inside an ArgList.
name|template
operator|<
name|typename
name|BaseIter
operator|,
name|unsigned
name|NumOptSpecifiers
operator|=
literal|0
operator|>
name|class
name|arg_iterator
block|{
comment|/// The current argument and the end of the sequence we're iterating.
name|BaseIter
name|Current
block|,
name|End
block|;
comment|/// Optional filters on the arguments which will be match. To avoid a
comment|/// zero-sized array, we store one specifier even if we're asked for none.
name|OptSpecifier
name|Ids
index|[
name|NumOptSpecifiers
condition|?
name|NumOptSpecifiers
else|:
literal|1
index|]
block|;
name|void
name|SkipToNextArg
argument_list|()
block|{
for|for
control|(
init|;
name|Current
operator|!=
name|End
condition|;
operator|++
name|Current
control|)
block|{
comment|// Skip erased elements.
if|if
condition|(
operator|!
operator|*
name|Current
condition|)
continue|continue;
comment|// Done if there are no filters.
if|if
condition|(
operator|!
name|NumOptSpecifiers
condition|)
return|return;
comment|// Otherwise require a match.
specifier|const
name|Option
modifier|&
name|O
init|=
operator|(
operator|*
name|Current
operator|)
operator|->
name|getOption
argument_list|()
decl_stmt|;
for|for
control|(
name|auto
name|Id
range|:
name|Ids
control|)
block|{
if|if
condition|(
operator|!
name|Id
operator|.
name|isValid
argument_list|()
condition|)
break|break;
if|if
condition|(
name|O
operator|.
name|matches
argument_list|(
name|Id
argument_list|)
condition|)
return|return;
block|}
block|}
block|}
name|using
name|Traits
operator|=
name|std
operator|::
name|iterator_traits
operator|<
name|BaseIter
operator|>
block|;
name|public
operator|:
name|using
name|value_type
operator|=
name|typename
name|Traits
operator|::
name|value_type
block|;
name|using
name|reference
operator|=
name|typename
name|Traits
operator|::
name|reference
block|;
name|using
name|pointer
operator|=
name|typename
name|Traits
operator|::
name|pointer
block|;
name|using
name|iterator_category
operator|=
name|std
operator|::
name|forward_iterator_tag
block|;
name|using
name|difference_type
operator|=
name|std
operator|::
name|ptrdiff_t
block|;
name|arg_iterator
argument_list|(
argument|BaseIter Current
argument_list|,
argument|BaseIter End
argument_list|,
argument|const OptSpecifier (&Ids)[NumOptSpecifiers ? NumOptSpecifiers :
literal|1
argument|] = {}
argument_list|)
operator|:
name|Current
argument_list|(
name|Current
argument_list|)
block|,
name|End
argument_list|(
argument|End
argument_list|)
block|{
for|for
control|(
name|unsigned
name|I
init|=
literal|0
init|;
name|I
operator|!=
name|NumOptSpecifiers
condition|;
operator|++
name|I
control|)
name|this
operator|->
name|Ids
index|[
name|I
index|]
operator|=
name|Ids
index|[
name|I
index|]
expr_stmt|;
name|SkipToNextArg
argument_list|()
block|;   }
comment|// FIXME: This conversion function makes no sense.
name|operator
specifier|const
name|Arg
operator|*
operator|(
operator|)
block|{
return|return
operator|*
name|Current
return|;
block|}
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|Current
return|;
block|}
name|pointer
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|Current
return|;
block|}
name|arg_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|Current
block|;
name|SkipToNextArg
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|arg_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|arg_iterator
name|tmp
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
operator|(
operator|*
name|this
operator|)
block|;
return|return
name|tmp
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
name|arg_iterator
name|LHS
operator|,
name|arg_iterator
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|Current
operator|==
name|RHS
operator|.
name|Current
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
name|arg_iterator
name|LHS
operator|,
name|arg_iterator
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// ArgList - Ordered collection of driver arguments.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The ArgList class manages a list of Arg instances as well as
end_comment

begin_comment
comment|/// auxiliary data and convenience methods to allow Tools to quickly
end_comment

begin_comment
comment|/// check for the presence of Arg instances for a particular Option
end_comment

begin_comment
comment|/// and to iterate over groups of arguments.
end_comment

begin_decl_stmt
name|class
name|ArgList
block|{
name|public
label|:
name|using
name|arglist_type
init|=
name|SmallVector
operator|<
name|Arg
operator|*
decl_stmt|, 16>;
name|using
name|iterator
init|=
name|arg_iterator
operator|<
name|arglist_type
operator|::
name|iterator
operator|>
decl_stmt|;
name|using
name|const_iterator
init|=
name|arg_iterator
operator|<
name|arglist_type
operator|::
name|const_iterator
operator|>
decl_stmt|;
name|using
name|reverse_iterator
init|=
name|arg_iterator
operator|<
name|arglist_type
operator|::
name|reverse_iterator
operator|>
decl_stmt|;
name|using
name|const_reverse_iterator
init|=
name|arg_iterator
operator|<
name|arglist_type
operator|::
name|const_reverse_iterator
operator|>
decl_stmt|;
name|template
operator|<
name|unsigned
name|N
operator|>
name|using
name|filtered_iterator
operator|=
name|arg_iterator
operator|<
name|arglist_type
operator|::
name|const_iterator
operator|,
name|N
operator|>
expr_stmt|;
name|template
operator|<
name|unsigned
name|N
operator|>
name|using
name|filtered_reverse_iterator
operator|=
name|arg_iterator
operator|<
name|arglist_type
operator|::
name|const_reverse_iterator
operator|,
name|N
operator|>
expr_stmt|;
name|private
label|:
comment|/// The internal list of arguments.
name|arglist_type
name|Args
decl_stmt|;
name|using
name|OptRange
init|=
name|std
operator|::
name|pair
operator|<
name|unsigned
decl_stmt|,
name|unsigned
decl|>
decl_stmt|;
specifier|static
name|OptRange
name|emptyRange
parameter_list|()
block|{
return|return
block|{
operator|-
literal|1u
block|,
literal|0u
block|}
return|;
block|}
comment|/// The first and last index of each different OptSpecifier ID.
name|DenseMap
operator|<
name|unsigned
operator|,
name|OptRange
operator|>
name|OptRanges
expr_stmt|;
comment|/// Get the range of indexes in which options with the specified IDs might
comment|/// reside, or (0, 0) if there are no such options.
name|OptRange
name|getRange
argument_list|(
name|std
operator|::
name|initializer_list
operator|<
name|OptSpecifier
operator|>
name|Ids
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
comment|// Make the default special members protected so they won't be used to slice
comment|// derived objects, but can still be used by derived objects to implement
comment|// their own special members.
name|ArgList
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|// Explicit move operations to ensure the container is cleared post-move
comment|// otherwise it could lead to a double-delete in the case of moving of an
comment|// InputArgList which deletes the contents of the container. If we could fix
comment|// up the ownership here (delegate storage/ownership to the derived class so
comment|// it can be a container of unique_ptr) this would be simpler.
name|ArgList
argument_list|(
name|ArgList
operator|&&
name|RHS
argument_list|)
operator|:
name|Args
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|Args
argument_list|)
argument_list|)
operator|,
name|OptRanges
argument_list|(
argument|std::move(RHS.OptRanges)
argument_list|)
block|{
name|RHS
operator|.
name|Args
operator|.
name|clear
argument_list|()
block|;
name|RHS
operator|.
name|OptRanges
operator|.
name|clear
argument_list|()
block|;   }
name|ArgList
operator|&
name|operator
operator|=
operator|(
name|ArgList
operator|&&
name|RHS
operator|)
block|{
name|Args
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|Args
argument_list|)
block|;
name|RHS
operator|.
name|Args
operator|.
name|clear
argument_list|()
block|;
name|OptRanges
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|OptRanges
argument_list|)
block|;
name|RHS
operator|.
name|OptRanges
operator|.
name|clear
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
comment|// Protect the dtor to ensure this type is never destroyed polymorphically.
operator|~
name|ArgList
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|// Implicitly convert a value to an OptSpecifier. Used to work around a bug
comment|// in MSVC's implementation of narrowing conversion checking.
specifier|static
name|OptSpecifier
name|toOptSpecifier
parameter_list|(
name|OptSpecifier
name|S
parameter_list|)
block|{
return|return
name|S
return|;
block|}
name|public
label|:
comment|/// @name Arg Access
comment|/// @{
comment|/// append - Append \p A to the arg list.
name|void
name|append
parameter_list|(
name|Arg
modifier|*
name|A
parameter_list|)
function_decl|;
specifier|const
name|arglist_type
operator|&
name|getArgs
argument_list|()
specifier|const
block|{
return|return
name|Args
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Args
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name Arg Iteration
comment|/// @{
name|iterator
name|begin
parameter_list|()
block|{
return|return
block|{
name|Args
operator|.
name|begin
argument_list|()
block|,
name|Args
operator|.
name|end
argument_list|()
block|}
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
block|{
name|Args
operator|.
name|end
argument_list|()
block|,
name|Args
operator|.
name|end
argument_list|()
block|}
return|;
block|}
name|reverse_iterator
name|rbegin
parameter_list|()
block|{
return|return
block|{
name|Args
operator|.
name|rbegin
argument_list|()
block|,
name|Args
operator|.
name|rend
argument_list|()
block|}
return|;
block|}
name|reverse_iterator
name|rend
parameter_list|()
block|{
return|return
block|{
name|Args
operator|.
name|rend
argument_list|()
block|,
name|Args
operator|.
name|rend
argument_list|()
block|}
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
block|{
name|Args
operator|.
name|begin
argument_list|()
block|,
name|Args
operator|.
name|end
argument_list|()
block|}
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
block|{
name|Args
operator|.
name|end
argument_list|()
block|,
name|Args
operator|.
name|end
argument_list|()
block|}
return|;
block|}
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
block|{
name|Args
operator|.
name|rbegin
argument_list|()
block|,
name|Args
operator|.
name|rend
argument_list|()
block|}
return|;
block|}
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
block|{
name|Args
operator|.
name|rend
argument_list|()
block|,
name|Args
operator|.
name|rend
argument_list|()
block|}
return|;
block|}
name|template
operator|<
name|typename
operator|...
name|OptSpecifiers
operator|>
name|iterator_range
operator|<
name|filtered_iterator
operator|<
sizeof|sizeof...
argument_list|(
name|OptSpecifiers
argument_list|)
operator|>>
name|filtered
argument_list|(
argument|OptSpecifiers ...Ids
argument_list|)
specifier|const
block|{
name|OptRange
name|Range
operator|=
name|getRange
argument_list|(
block|{
name|toOptSpecifier
argument_list|(
name|Ids
argument_list|)
operator|...
block|}
argument_list|)
block|;
name|auto
name|B
operator|=
name|Args
operator|.
name|begin
argument_list|()
operator|+
name|Range
operator|.
name|first
block|;
name|auto
name|E
operator|=
name|Args
operator|.
name|begin
argument_list|()
operator|+
name|Range
operator|.
name|second
block|;
name|using
name|Iterator
operator|=
name|filtered_iterator
operator|<
sizeof|sizeof...
argument_list|(
name|OptSpecifiers
argument_list|)
operator|>
block|;
return|return
name|make_range
argument_list|(
name|Iterator
argument_list|(
name|B
argument_list|,
name|E
argument_list|,
block|{
name|toOptSpecifier
argument_list|(
name|Ids
argument_list|)
operator|...
block|}
argument_list|)
operator|,
name|Iterator
argument_list|(
name|E
argument_list|,
name|E
argument_list|,
block|{
name|toOptSpecifier
argument_list|(
name|Ids
argument_list|)
operator|...
block|}
block|))
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|OptSpecifiers
operator|>
name|iterator_range
operator|<
name|filtered_reverse_iterator
operator|<
sizeof|sizeof...
argument_list|(
name|OptSpecifiers
argument_list|)
operator|>>
name|filtered_reverse
argument_list|(
argument|OptSpecifiers ...Ids
argument_list|)
specifier|const
block|{
name|OptRange
name|Range
operator|=
name|getRange
argument_list|(
block|{
name|toOptSpecifier
argument_list|(
name|Ids
argument_list|)
operator|...
block|}
argument_list|)
block|;
name|auto
name|B
operator|=
name|Args
operator|.
name|rend
argument_list|()
operator|-
name|Range
operator|.
name|second
block|;
name|auto
name|E
operator|=
name|Args
operator|.
name|rend
argument_list|()
operator|-
name|Range
operator|.
name|first
block|;
name|using
name|Iterator
operator|=
name|filtered_reverse_iterator
operator|<
sizeof|sizeof...
argument_list|(
name|OptSpecifiers
argument_list|)
operator|>
block|;
return|return
name|make_range
argument_list|(
name|Iterator
argument_list|(
name|B
argument_list|,
name|E
argument_list|,
block|{
name|toOptSpecifier
argument_list|(
name|Ids
argument_list|)
operator|...
block|}
end_expr_stmt

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|Iterator
argument_list|(
name|E
argument_list|,
name|E
argument_list|,
block|{
name|toOptSpecifier
argument_list|(
name|Ids
argument_list|)
operator|...
block|}
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|/// @}
end_comment

begin_comment
comment|/// @name Arg Removal
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// eraseArg - Remove any option matching \p Id.
end_comment

begin_macro
unit|void
name|eraseArg
argument_list|(
argument|OptSpecifier Id
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Arg Access
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// hasArg - Does the arg list contain any option matching \p Id.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \p Claim Whether the argument should be claimed, if it exists.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|OptSpecifiers
operator|>
name|bool
name|hasArgNoClaim
argument_list|(
argument|OptSpecifiers ...Ids
argument_list|)
specifier|const
block|{
return|return
name|getLastArgNoClaim
argument_list|(
name|Ids
operator|...
argument_list|)
operator|!=
name|nullptr
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|OptSpecifiers
operator|>
name|bool
name|hasArg
argument_list|(
argument|OptSpecifiers ...Ids
argument_list|)
specifier|const
block|{
return|return
name|getLastArg
argument_list|(
name|Ids
operator|...
argument_list|)
operator|!=
name|nullptr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Return the last argument matching \p Id, or null.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|OptSpecifiers
operator|>
name|Arg
operator|*
name|getLastArg
argument_list|(
argument|OptSpecifiers ...Ids
argument_list|)
specifier|const
block|{
name|Arg
operator|*
name|Res
operator|=
name|nullptr
block|;
for|for
control|(
name|Arg
modifier|*
name|A
range|:
name|filtered
argument_list|(
name|Ids
operator|...
argument_list|)
control|)
block|{
name|Res
operator|=
name|A
expr_stmt|;
name|Res
operator|->
name|claim
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|Res
return|;
end_return

begin_comment
unit|}
comment|/// Return the last argument matching \p Id, or null. Do not "claim" the
end_comment

begin_comment
comment|/// option (don't mark it as having been used).
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
operator|...
name|OptSpecifiers
operator|>
name|Arg
operator|*
name|getLastArgNoClaim
argument_list|(
argument|OptSpecifiers ...Ids
argument_list|)
specifier|const
block|{
for|for
control|(
name|Arg
modifier|*
name|A
range|:
name|filtered_reverse
argument_list|(
name|Ids
operator|...
argument_list|)
control|)
return|return
name|A
return|;
end_expr_stmt

begin_return
return|return
name|nullptr
return|;
end_return

begin_comment
unit|}
comment|/// getArgString - Return the input argument string at \p Index.
end_comment

begin_decl_stmt
unit|virtual
specifier|const
name|char
modifier|*
name|getArgString
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getNumInputArgStrings - Return the number of original argument strings,
end_comment

begin_comment
comment|/// which are guaranteed to be the first strings in the argument string
end_comment

begin_comment
comment|/// list.
end_comment

begin_expr_stmt
name|virtual
name|unsigned
name|getNumInputArgStrings
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Argument Lookup Utilities
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// getLastArgValue - Return the value of the last argument, or a default.
end_comment

begin_decl_stmt
name|StringRef
name|getLastArgValue
argument_list|(
name|OptSpecifier
name|Id
argument_list|,
name|StringRef
name|Default
operator|=
literal|""
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getAllArgValues - Get the values of all instances of the given argument
end_comment

begin_comment
comment|/// as strings.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|getAllArgValues
argument_list|(
argument|OptSpecifier Id
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Translation Utilities
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// hasFlag - Given an option \p Pos and its negative form \p Neg, return
end_comment

begin_comment
comment|/// true if the option is present, false if the negation is present, and
end_comment

begin_comment
comment|/// \p Default if neither option is given. If both the option and its
end_comment

begin_comment
comment|/// negation are present, the last one wins.
end_comment

begin_decl_stmt
name|bool
name|hasFlag
argument_list|(
name|OptSpecifier
name|Pos
argument_list|,
name|OptSpecifier
name|Neg
argument_list|,
name|bool
name|Default
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// hasFlag - Given an option \p Pos, an alias \p PosAlias and its negative
end_comment

begin_comment
comment|/// form \p Neg, return true if the option or its alias is present, false if
end_comment

begin_comment
comment|/// the negation is present, and \p Default if none of the options are
end_comment

begin_comment
comment|/// given. If multiple options are present, the last one wins.
end_comment

begin_decl_stmt
name|bool
name|hasFlag
argument_list|(
name|OptSpecifier
name|Pos
argument_list|,
name|OptSpecifier
name|PosAlias
argument_list|,
name|OptSpecifier
name|Neg
argument_list|,
name|bool
name|Default
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// AddLastArg - Render only the last argument match \p Id0, if present.
end_comment

begin_decl_stmt
name|void
name|AddLastArg
argument_list|(
name|ArgStringList
operator|&
name|Output
argument_list|,
name|OptSpecifier
name|Id0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|AddLastArg
argument_list|(
name|ArgStringList
operator|&
name|Output
argument_list|,
name|OptSpecifier
name|Id0
argument_list|,
name|OptSpecifier
name|Id1
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// AddAllArgsExcept - Render all arguments matching any of the given ids
end_comment

begin_comment
comment|/// and not matching any of the excluded ids.
end_comment

begin_decl_stmt
name|void
name|AddAllArgsExcept
argument_list|(
name|ArgStringList
operator|&
name|Output
argument_list|,
name|ArrayRef
operator|<
name|OptSpecifier
operator|>
name|Ids
argument_list|,
name|ArrayRef
operator|<
name|OptSpecifier
operator|>
name|ExcludeIds
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// AddAllArgs - Render all arguments matching any of the given ids.
end_comment

begin_decl_stmt
name|void
name|AddAllArgs
argument_list|(
name|ArgStringList
operator|&
name|Output
argument_list|,
name|ArrayRef
operator|<
name|OptSpecifier
operator|>
name|Ids
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// AddAllArgs - Render all arguments matching the given ids.
end_comment

begin_decl_stmt
name|void
name|AddAllArgs
argument_list|(
name|ArgStringList
operator|&
name|Output
argument_list|,
name|OptSpecifier
name|Id0
argument_list|,
name|OptSpecifier
name|Id1
operator|=
literal|0U
argument_list|,
name|OptSpecifier
name|Id2
operator|=
literal|0U
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// AddAllArgValues - Render the argument values of all arguments
end_comment

begin_comment
comment|/// matching the given ids.
end_comment

begin_decl_stmt
name|void
name|AddAllArgValues
argument_list|(
name|ArgStringList
operator|&
name|Output
argument_list|,
name|OptSpecifier
name|Id0
argument_list|,
name|OptSpecifier
name|Id1
operator|=
literal|0U
argument_list|,
name|OptSpecifier
name|Id2
operator|=
literal|0U
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// AddAllArgsTranslated - Render all the arguments matching the
end_comment

begin_comment
comment|/// given ids, but forced to separate args and using the provided
end_comment

begin_comment
comment|/// name instead of the first option value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Joined - If true, render the argument as joined with
end_comment

begin_comment
comment|/// the option specifier.
end_comment

begin_decl_stmt
name|void
name|AddAllArgsTranslated
argument_list|(
name|ArgStringList
operator|&
name|Output
argument_list|,
name|OptSpecifier
name|Id0
argument_list|,
specifier|const
name|char
operator|*
name|Translation
argument_list|,
name|bool
name|Joined
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ClaimAllArgs - Claim all arguments which match the given
end_comment

begin_comment
comment|/// option id.
end_comment

begin_decl_stmt
name|void
name|ClaimAllArgs
argument_list|(
name|OptSpecifier
name|Id0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ClaimAllArgs - Claim all arguments.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|void
name|ClaimAllArgs
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Arg Synthesis
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// Construct a constant string pointer whose
end_comment

begin_comment
comment|/// lifetime will match that of the ArgList.
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char
modifier|*
name|MakeArgStringRef
argument_list|(
name|StringRef
name|Str
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|MakeArgString
argument_list|(
specifier|const
name|Twine
operator|&
name|Str
argument_list|)
decl|const
block|{
name|SmallString
operator|<
literal|256
operator|>
name|Buf
expr_stmt|;
return|return
name|MakeArgStringRef
argument_list|(
name|Str
operator|.
name|toStringRef
argument_list|(
name|Buf
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Create an arg string for (\p LHS + \p RHS), reusing the
end_comment

begin_comment
comment|/// string at \p Index if possible.
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|GetOrMakeJoinedArgString
argument_list|(
name|unsigned
name|Index
argument_list|,
name|StringRef
name|LHS
argument_list|,
name|StringRef
name|RHS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_decl_stmt
unit|};
name|class
name|InputArgList
name|final
range|:
name|public
name|ArgList
block|{
name|private
operator|:
comment|/// List of argument strings used by the contained Args.
comment|///
comment|/// This is mutable since we treat the ArgList as being the list
comment|/// of Args, and allow routines to add new strings (to have a
comment|/// convenient place to store the memory) via MakeIndex.
name|mutable
name|ArgStringList
name|ArgStrings
block|;
comment|/// Strings for synthesized arguments.
comment|///
comment|/// This is mutable since we treat the ArgList as being the list
comment|/// of Args, and allow routines to add new strings (to have a
comment|/// convenient place to store the memory) via MakeIndex.
name|mutable
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|string
operator|>
name|SynthesizedStrings
block|;
comment|/// The number of original input argument strings.
name|unsigned
name|NumInputArgStrings
block|;
comment|/// Release allocated arguments.
name|void
name|releaseMemory
argument_list|()
block|;
name|public
operator|:
name|InputArgList
argument_list|(
specifier|const
name|char
operator|*
specifier|const
operator|*
name|ArgBegin
argument_list|,
specifier|const
name|char
operator|*
specifier|const
operator|*
name|ArgEnd
argument_list|)
block|;
name|InputArgList
argument_list|(
name|InputArgList
operator|&&
name|RHS
argument_list|)
operator|:
name|ArgList
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|RHS
argument_list|)
argument_list|)
block|,
name|ArgStrings
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|ArgStrings
argument_list|)
argument_list|)
block|,
name|SynthesizedStrings
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|SynthesizedStrings
argument_list|)
argument_list|)
block|,
name|NumInputArgStrings
argument_list|(
argument|RHS.NumInputArgStrings
argument_list|)
block|{}
name|InputArgList
operator|&
name|operator
operator|=
operator|(
name|InputArgList
operator|&&
name|RHS
operator|)
block|{
name|releaseMemory
argument_list|()
block|;
name|ArgList
operator|::
name|operator
operator|=
operator|(
name|std
operator|::
name|move
argument_list|(
name|RHS
argument_list|)
operator|)
block|;
name|ArgStrings
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|ArgStrings
argument_list|)
block|;
name|SynthesizedStrings
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|SynthesizedStrings
argument_list|)
block|;
name|NumInputArgStrings
operator|=
name|RHS
operator|.
name|NumInputArgStrings
block|;
return|return
operator|*
name|this
return|;
block|}
operator|~
name|InputArgList
argument_list|()
block|{
name|releaseMemory
argument_list|()
block|; }
specifier|const
name|char
operator|*
name|getArgString
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
name|override
block|{
return|return
name|ArgStrings
index|[
name|Index
index|]
return|;
block|}
name|unsigned
name|getNumInputArgStrings
argument_list|()
specifier|const
name|override
block|{
return|return
name|NumInputArgStrings
return|;
block|}
comment|/// @name Arg Synthesis
comment|/// @{
name|public
operator|:
comment|/// MakeIndex - Get an index for the given string(s).
name|unsigned
name|MakeIndex
argument_list|(
argument|StringRef String0
argument_list|)
specifier|const
block|;
name|unsigned
name|MakeIndex
argument_list|(
argument|StringRef String0
argument_list|,
argument|StringRef String1
argument_list|)
specifier|const
block|;
name|using
name|ArgList
operator|::
name|MakeArgString
block|;
specifier|const
name|char
operator|*
name|MakeArgStringRef
argument_list|(
argument|StringRef Str
argument_list|)
specifier|const
name|override
block|;
comment|/// @}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// DerivedArgList - An ordered collection of driver arguments,
end_comment

begin_comment
comment|/// whose storage may be in another argument list.
end_comment

begin_decl_stmt
name|class
name|DerivedArgList
name|final
range|:
name|public
name|ArgList
block|{
specifier|const
name|InputArgList
operator|&
name|BaseArgs
block|;
comment|/// The list of arguments we synthesized.
name|mutable
name|SmallVector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Arg
operator|>
block|,
literal|16
operator|>
name|SynthesizedArgs
block|;
name|public
operator|:
comment|/// Construct a new derived arg list from \p BaseArgs.
name|DerivedArgList
argument_list|(
specifier|const
name|InputArgList
operator|&
name|BaseArgs
argument_list|)
block|;
specifier|const
name|char
operator|*
name|getArgString
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
name|override
block|{
return|return
name|BaseArgs
operator|.
name|getArgString
argument_list|(
name|Index
argument_list|)
return|;
block|}
name|unsigned
name|getNumInputArgStrings
argument_list|()
specifier|const
name|override
block|{
return|return
name|BaseArgs
operator|.
name|getNumInputArgStrings
argument_list|()
return|;
block|}
specifier|const
name|InputArgList
operator|&
name|getBaseArgs
argument_list|()
specifier|const
block|{
return|return
name|BaseArgs
return|;
block|}
comment|/// @name Arg Synthesis
comment|/// @{
comment|/// AddSynthesizedArg - Add a argument to the list of synthesized arguments
comment|/// (to be freed).
name|void
name|AddSynthesizedArg
argument_list|(
name|Arg
operator|*
name|A
argument_list|)
block|;
name|using
name|ArgList
operator|::
name|MakeArgString
block|;
specifier|const
name|char
operator|*
name|MakeArgStringRef
argument_list|(
argument|StringRef Str
argument_list|)
specifier|const
name|override
block|;
comment|/// AddFlagArg - Construct a new FlagArg for the given option \p Id and
comment|/// append it to the argument list.
name|void
name|AddFlagArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option Opt
argument_list|)
block|{
name|append
argument_list|(
name|MakeFlagArg
argument_list|(
name|BaseArg
argument_list|,
name|Opt
argument_list|)
argument_list|)
block|;   }
comment|/// AddPositionalArg - Construct a new Positional arg for the given option
comment|/// \p Id, with the provided \p Value and append it to the argument
comment|/// list.
name|void
name|AddPositionalArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option Opt
argument_list|,
argument|StringRef Value
argument_list|)
block|{
name|append
argument_list|(
name|MakePositionalArg
argument_list|(
name|BaseArg
argument_list|,
name|Opt
argument_list|,
name|Value
argument_list|)
argument_list|)
block|;   }
comment|/// AddSeparateArg - Construct a new Positional arg for the given option
comment|/// \p Id, with the provided \p Value and append it to the argument
comment|/// list.
name|void
name|AddSeparateArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option Opt
argument_list|,
argument|StringRef Value
argument_list|)
block|{
name|append
argument_list|(
name|MakeSeparateArg
argument_list|(
name|BaseArg
argument_list|,
name|Opt
argument_list|,
name|Value
argument_list|)
argument_list|)
block|;   }
comment|/// AddJoinedArg - Construct a new Positional arg for the given option
comment|/// \p Id, with the provided \p Value and append it to the argument list.
name|void
name|AddJoinedArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option Opt
argument_list|,
argument|StringRef Value
argument_list|)
block|{
name|append
argument_list|(
name|MakeJoinedArg
argument_list|(
name|BaseArg
argument_list|,
name|Opt
argument_list|,
name|Value
argument_list|)
argument_list|)
block|;   }
comment|/// MakeFlagArg - Construct a new FlagArg for the given option \p Id.
name|Arg
operator|*
name|MakeFlagArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option Opt
argument_list|)
specifier|const
block|;
comment|/// MakePositionalArg - Construct a new Positional arg for the
comment|/// given option \p Id, with the provided \p Value.
name|Arg
operator|*
name|MakePositionalArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option Opt
argument_list|,
argument|StringRef Value
argument_list|)
specifier|const
block|;
comment|/// MakeSeparateArg - Construct a new Positional arg for the
comment|/// given option \p Id, with the provided \p Value.
name|Arg
operator|*
name|MakeSeparateArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option Opt
argument_list|,
argument|StringRef Value
argument_list|)
specifier|const
block|;
comment|/// MakeJoinedArg - Construct a new Positional arg for the
comment|/// given option \p Id, with the provided \p Value.
name|Arg
operator|*
name|MakeJoinedArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option Opt
argument_list|,
argument|StringRef Value
argument_list|)
specifier|const
block|;
comment|/// @}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// end namespace opt
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_OPTION_ARGLIST_H
end_comment

end_unit

