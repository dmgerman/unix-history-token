begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/SmallString.h - 'Normally small' strings --------*- C++ -*-===//
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
comment|// This file defines the SmallString class.
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
name|LLVM_ADT_SMALLSTRING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_SMALLSTRING_H
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

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// SmallString - A SmallString is just a SmallVector with methods and accessors
comment|/// that make it work better as a string (e.g. operator+ etc).
name|template
operator|<
name|unsigned
name|InternalLen
operator|>
name|class
name|SmallString
operator|:
name|public
name|SmallVector
operator|<
name|char
operator|,
name|InternalLen
operator|>
block|{
name|public
operator|:
comment|/// Default ctor - Initialize to empty.
name|SmallString
argument_list|()
block|{}
comment|/// Initialize from a StringRef.
name|SmallString
argument_list|(
argument|StringRef S
argument_list|)
operator|:
name|SmallVector
operator|<
name|char
block|,
name|InternalLen
operator|>
operator|(
name|S
operator|.
name|begin
argument_list|()
operator|,
name|S
operator|.
name|end
argument_list|()
operator|)
block|{}
comment|/// Initialize with a range.
name|template
operator|<
name|typename
name|ItTy
operator|>
name|SmallString
argument_list|(
argument|ItTy S
argument_list|,
argument|ItTy E
argument_list|)
operator|:
name|SmallVector
operator|<
name|char
block|,
name|InternalLen
operator|>
operator|(
name|S
operator|,
name|E
operator|)
block|{}
comment|// Note that in order to add new overloads for append& assign, we have to
comment|// duplicate the inherited versions so as not to inadvertently hide them.
comment|/// @}
comment|/// @name String Assignment
comment|/// @{
comment|/// Assign from a repeated element.
name|void
name|assign
argument_list|(
argument|size_t NumElts
argument_list|,
argument|char Elt
argument_list|)
block|{
name|this
operator|->
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|::
name|assign
argument_list|(
name|NumElts
argument_list|,
name|Elt
argument_list|)
block|;   }
comment|/// Assign from an iterator pair.
name|template
operator|<
name|typename
name|in_iter
operator|>
name|void
name|assign
argument_list|(
argument|in_iter S
argument_list|,
argument|in_iter E
argument_list|)
block|{
name|this
operator|->
name|clear
argument_list|()
block|;
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|::
name|append
argument_list|(
name|S
argument_list|,
name|E
argument_list|)
block|;   }
comment|/// Assign from a StringRef.
name|void
name|assign
argument_list|(
argument|StringRef RHS
argument_list|)
block|{
name|this
operator|->
name|clear
argument_list|()
block|;
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|::
name|append
argument_list|(
name|RHS
operator|.
name|begin
argument_list|()
argument_list|,
name|RHS
operator|.
name|end
argument_list|()
argument_list|)
block|;   }
comment|/// Assign from a SmallVector.
name|void
name|assign
argument_list|(
argument|const SmallVectorImpl<char>&RHS
argument_list|)
block|{
name|this
operator|->
name|clear
argument_list|()
block|;
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|::
name|append
argument_list|(
name|RHS
operator|.
name|begin
argument_list|()
argument_list|,
name|RHS
operator|.
name|end
argument_list|()
argument_list|)
block|;   }
comment|/// @}
comment|/// @name String Concatenation
comment|/// @{
comment|/// Append from an iterator pair.
name|template
operator|<
name|typename
name|in_iter
operator|>
name|void
name|append
argument_list|(
argument|in_iter S
argument_list|,
argument|in_iter E
argument_list|)
block|{
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|::
name|append
argument_list|(
name|S
argument_list|,
name|E
argument_list|)
block|;   }
name|void
name|append
argument_list|(
argument|size_t NumInputs
argument_list|,
argument|char Elt
argument_list|)
block|{
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|::
name|append
argument_list|(
name|NumInputs
argument_list|,
name|Elt
argument_list|)
block|;   }
comment|/// Append from a StringRef.
name|void
name|append
argument_list|(
argument|StringRef RHS
argument_list|)
block|{
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|::
name|append
argument_list|(
name|RHS
operator|.
name|begin
argument_list|()
argument_list|,
name|RHS
operator|.
name|end
argument_list|()
argument_list|)
block|;   }
comment|/// Append from a SmallVector.
name|void
name|append
argument_list|(
argument|const SmallVectorImpl<char>&RHS
argument_list|)
block|{
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|::
name|append
argument_list|(
name|RHS
operator|.
name|begin
argument_list|()
argument_list|,
name|RHS
operator|.
name|end
argument_list|()
argument_list|)
block|;   }
comment|/// @}
comment|/// @name String Comparison
comment|/// @{
comment|/// Check for string equality.  This is more efficient than compare() when
comment|/// the relative ordering of inequal strings isn't needed.
name|bool
name|equals
argument_list|(
argument|StringRef RHS
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|equals
argument_list|(
name|RHS
argument_list|)
return|;
block|}
comment|/// Check for string equality, ignoring case.
name|bool
name|equals_lower
argument_list|(
argument|StringRef RHS
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|equals_lower
argument_list|(
name|RHS
argument_list|)
return|;
block|}
comment|/// Compare two strings; the result is -1, 0, or 1 if this string is
comment|/// lexicographically less than, equal to, or greater than the \p RHS.
name|int
name|compare
argument_list|(
argument|StringRef RHS
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|compare
argument_list|(
name|RHS
argument_list|)
return|;
block|}
comment|/// compare_lower - Compare two strings, ignoring case.
name|int
name|compare_lower
argument_list|(
argument|StringRef RHS
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|compare_lower
argument_list|(
name|RHS
argument_list|)
return|;
block|}
comment|/// compare_numeric - Compare two strings, treating sequences of digits as
comment|/// numbers.
name|int
name|compare_numeric
argument_list|(
argument|StringRef RHS
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|compare_numeric
argument_list|(
name|RHS
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name String Predicates
comment|/// @{
comment|/// startswith - Check if this string starts with the given \p Prefix.
name|bool
name|startswith
argument_list|(
argument|StringRef Prefix
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|startswith
argument_list|(
name|Prefix
argument_list|)
return|;
block|}
comment|/// endswith - Check if this string ends with the given \p Suffix.
name|bool
name|endswith
argument_list|(
argument|StringRef Suffix
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|endswith
argument_list|(
name|Suffix
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name String Searching
comment|/// @{
comment|/// find - Search for the first character \p C in the string.
comment|///
comment|/// \return - The index of the first occurrence of \p C, or npos if not
comment|/// found.
name|size_t
name|find
argument_list|(
argument|char C
argument_list|,
argument|size_t From =
literal|0
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|find
argument_list|(
name|C
argument_list|,
name|From
argument_list|)
return|;
block|}
comment|/// Search for the first string \p Str in the string.
comment|///
comment|/// \returns The index of the first occurrence of \p Str, or npos if not
comment|/// found.
name|size_t
name|find
argument_list|(
argument|StringRef Str
argument_list|,
argument|size_t From =
literal|0
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|find
argument_list|(
name|Str
argument_list|,
name|From
argument_list|)
return|;
block|}
comment|/// Search for the last character \p C in the string.
comment|///
comment|/// \returns The index of the last occurrence of \p C, or npos if not
comment|/// found.
name|size_t
name|rfind
argument_list|(
argument|char C
argument_list|,
argument|size_t From = StringRef::npos
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|rfind
argument_list|(
name|C
argument_list|,
name|From
argument_list|)
return|;
block|}
comment|/// Search for the last string \p Str in the string.
comment|///
comment|/// \returns The index of the last occurrence of \p Str, or npos if not
comment|/// found.
name|size_t
name|rfind
argument_list|(
argument|StringRef Str
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|rfind
argument_list|(
name|Str
argument_list|)
return|;
block|}
comment|/// Find the first character in the string that is \p C, or npos if not
comment|/// found. Same as find.
name|size_t
name|find_first_of
argument_list|(
argument|char C
argument_list|,
argument|size_t From =
literal|0
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|find_first_of
argument_list|(
name|C
argument_list|,
name|From
argument_list|)
return|;
block|}
comment|/// Find the first character in the string that is in \p Chars, or npos if
comment|/// not found.
comment|///
comment|/// Complexity: O(size() + Chars.size())
name|size_t
name|find_first_of
argument_list|(
argument|StringRef Chars
argument_list|,
argument|size_t From =
literal|0
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|find_first_of
argument_list|(
name|Chars
argument_list|,
name|From
argument_list|)
return|;
block|}
comment|/// Find the first character in the string that is not \p C or npos if not
comment|/// found.
name|size_t
name|find_first_not_of
argument_list|(
argument|char C
argument_list|,
argument|size_t From =
literal|0
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|find_first_not_of
argument_list|(
name|C
argument_list|,
name|From
argument_list|)
return|;
block|}
comment|/// Find the first character in the string that is not in the string
comment|/// \p Chars, or npos if not found.
comment|///
comment|/// Complexity: O(size() + Chars.size())
name|size_t
name|find_first_not_of
argument_list|(
argument|StringRef Chars
argument_list|,
argument|size_t From =
literal|0
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|find_first_not_of
argument_list|(
name|Chars
argument_list|,
name|From
argument_list|)
return|;
block|}
comment|/// Find the last character in the string that is \p C, or npos if not
comment|/// found.
name|size_t
name|find_last_of
argument_list|(
argument|char C
argument_list|,
argument|size_t From = StringRef::npos
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|find_last_of
argument_list|(
name|C
argument_list|,
name|From
argument_list|)
return|;
block|}
comment|/// Find the last character in the string that is in \p C, or npos if not
comment|/// found.
comment|///
comment|/// Complexity: O(size() + Chars.size())
name|size_t
name|find_last_of
argument_list|(
argument|StringRef Chars
argument_list|,
argument|size_t From = StringRef::npos
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|find_last_of
argument_list|(
name|Chars
argument_list|,
name|From
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name Helpful Algorithms
comment|/// @{
comment|/// Return the number of occurrences of \p C in the string.
name|size_t
name|count
argument_list|(
argument|char C
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|count
argument_list|(
name|C
argument_list|)
return|;
block|}
comment|/// Return the number of non-overlapped occurrences of \p Str in the
comment|/// string.
name|size_t
name|count
argument_list|(
argument|StringRef Str
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|count
argument_list|(
name|Str
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name Substring Operations
comment|/// @{
comment|/// Return a reference to the substring from [Start, Start + N).
comment|///
comment|/// \param Start The index of the starting character in the substring; if
comment|/// the index is npos or greater than the length of the string then the
comment|/// empty substring will be returned.
comment|///
comment|/// \param N The number of characters to included in the substring. If \p N
comment|/// exceeds the number of characters remaining in the string, the string
comment|/// suffix (starting with \p Start) will be returned.
name|StringRef
name|substr
argument_list|(
argument|size_t Start
argument_list|,
argument|size_t N = StringRef::npos
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|substr
argument_list|(
name|Start
argument_list|,
name|N
argument_list|)
return|;
block|}
comment|/// Return a reference to the substring from [Start, End).
comment|///
comment|/// \param Start The index of the starting character in the substring; if
comment|/// the index is npos or greater than the length of the string then the
comment|/// empty substring will be returned.
comment|///
comment|/// \param End The index following the last character to include in the
comment|/// substring. If this is npos, or less than \p Start, or exceeds the
comment|/// number of characters remaining in the string, the string suffix
comment|/// (starting with \p Start) will be returned.
name|StringRef
name|slice
argument_list|(
argument|size_t Start
argument_list|,
argument|size_t End
argument_list|)
specifier|const
block|{
return|return
name|str
argument_list|()
operator|.
name|slice
argument_list|(
name|Start
argument_list|,
name|End
argument_list|)
return|;
block|}
comment|// Extra methods.
comment|/// Explicit conversion to StringRef.
name|StringRef
name|str
argument_list|()
specifier|const
block|{
return|return
name|StringRef
argument_list|(
name|this
operator|->
name|begin
argument_list|()
argument_list|,
name|this
operator|->
name|size
argument_list|()
argument_list|)
return|;
block|}
comment|// TODO: Make this const, if it's safe...
specifier|const
name|char
operator|*
name|c_str
argument_list|()
block|{
name|this
operator|->
name|push_back
argument_list|(
literal|0
argument_list|)
block|;
name|this
operator|->
name|pop_back
argument_list|()
block|;
return|return
name|this
operator|->
name|data
argument_list|()
return|;
block|}
comment|/// Implicit conversion to StringRef.
name|operator
name|StringRef
argument_list|()
specifier|const
block|{
return|return
name|str
argument_list|()
return|;
block|}
comment|// Extra operators.
specifier|const
name|SmallString
operator|&
name|operator
operator|=
operator|(
name|StringRef
name|RHS
operator|)
block|{
name|this
operator|->
name|clear
argument_list|()
block|;
return|return
operator|*
name|this
operator|+=
name|RHS
return|;
block|}
name|SmallString
operator|&
name|operator
operator|+=
operator|(
name|StringRef
name|RHS
operator|)
block|{
name|this
operator|->
name|append
argument_list|(
name|RHS
operator|.
name|begin
argument_list|()
argument_list|,
name|RHS
operator|.
name|end
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|SmallString
operator|&
name|operator
operator|+=
operator|(
name|char
name|C
operator|)
block|{
name|this
operator|->
name|push_back
argument_list|(
name|C
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

