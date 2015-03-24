begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lld/Core/range.h - Iterator ranges ----------------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Iterator range type based on c++1y range proposal.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// See http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3350.html
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_CORE_RANGE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_RANGE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<array>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<type_traits>
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
name|lld
block|{
comment|// Nothing in this namespace is part of the exported interface.
name|namespace
name|detail
block|{
name|using
name|std
operator|::
name|begin
expr_stmt|;
name|using
name|std
operator|::
name|end
expr_stmt|;
comment|/// Used as the result type of undefined functions.
struct|struct
name|undefined
block|{}
struct|;
name|template
operator|<
name|typename
name|R
operator|>
name|class
name|begin_result
block|{
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|auto
name|check
argument_list|(
name|T
operator|&&
name|t
argument_list|)
operator|->
name|decltype
argument_list|(
name|begin
argument_list|(
name|t
argument_list|)
argument_list|)
block|;
specifier|static
name|undefined
name|check
argument_list|(
operator|...
argument_list|)
block|;
name|public
operator|:
typedef|typedef
name|decltype
argument_list|(
argument|check(std::declval<R>())
argument_list|)
name|type
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|R
operator|>
name|class
name|end_result
block|{
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|auto
name|check
argument_list|(
name|T
operator|&&
name|t
argument_list|)
operator|->
name|decltype
argument_list|(
name|end
argument_list|(
name|t
argument_list|)
argument_list|)
block|;
specifier|static
name|undefined
name|check
argument_list|(
operator|...
argument_list|)
block|;
name|public
operator|:
typedef|typedef
name|decltype
argument_list|(
argument|check(std::declval<R>())
argument_list|)
name|type
expr_stmt|;
block|}
empty_stmt|;
comment|// Things that begin and end work on, in compatible ways, are
comment|// ranges. [stmt.ranged]
name|template
operator|<
name|typename
name|R
operator|>
expr|struct
name|is_range
operator|:
name|std
operator|::
name|is_same
operator|<
name|typename
name|detail
operator|::
name|begin_result
operator|<
name|R
operator|>
operator|::
name|type
operator|,
name|typename
name|detail
operator|::
name|end_result
operator|<
name|R
operator|>
operator|::
name|type
operator|>
block|{}
expr_stmt|;
comment|// This currently requires specialization and doesn't work for
comment|// detecting \c range<>s or iterators.  We should add
comment|// \c contiguous_iterator_tag to fix that.
name|template
operator|<
name|typename
name|R
operator|>
expr|struct
name|is_contiguous_range
operator|:
name|std
operator|::
name|false_type
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|R
operator|>
expr|struct
name|is_contiguous_range
operator|<
name|R
operator|&
operator|>
operator|:
name|is_contiguous_range
operator|<
name|R
operator|>
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|R
operator|>
expr|struct
name|is_contiguous_range
operator|<
name|R
operator|&&
operator|>
operator|:
name|is_contiguous_range
operator|<
name|R
operator|>
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|R
operator|>
expr|struct
name|is_contiguous_range
operator|<
specifier|const
name|R
operator|>
operator|:
name|is_contiguous_range
operator|<
name|R
operator|>
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|,
name|size_t
name|N
operator|>
expr|struct
name|is_contiguous_range
operator|<
name|T
index|[
name|N
index|]
operator|>
operator|:
name|std
operator|::
name|true_type
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|,
name|size_t
name|N
operator|>
expr|struct
name|is_contiguous_range
operator|<
specifier|const
name|T
index|[
name|N
index|]
operator|>
operator|:
name|std
operator|::
name|true_type
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|,
name|size_t
name|N
operator|>
expr|struct
name|is_contiguous_range
operator|<
name|std
operator|::
name|array
operator|<
name|T
operator|,
name|N
operator|>
expr|>
operator|:
name|std
operator|::
name|true_type
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|charT
operator|,
name|typename
name|traits
operator|,
name|typename
name|Allocator
operator|>
expr|struct
name|is_contiguous_range
operator|<
name|std
operator|::
name|basic_string
operator|<
name|charT
operator|,
name|traits
operator|,
name|Allocator
operator|>
expr|>
operator|:
name|std
operator|::
name|true_type
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Allocator
operator|>
expr|struct
name|is_contiguous_range
operator|<
name|std
operator|::
name|vector
operator|<
name|T
operator|,
name|Allocator
operator|>
expr|>
operator|:
name|std
operator|::
name|true_type
block|{}
expr_stmt|;
comment|// Removes cv qualifiers from all levels of a multi-level pointer
comment|// type, not just the type level.
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_all_cv_ptr
block|{
typedef|typedef
name|T
name|type
typedef|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_all_cv_ptr
operator|<
name|T
operator|*
operator|>
block|{
typedef|typedef
name|typename
name|remove_all_cv_ptr
operator|<
name|T
operator|>
operator|::
name|type
operator|*
name|type
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_all_cv_ptr
operator|<
specifier|const
name|T
operator|>
block|{
typedef|typedef
name|typename
name|remove_all_cv_ptr
operator|<
name|T
operator|>
operator|::
name|type
name|type
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_all_cv_ptr
operator|<
specifier|volatile
name|T
operator|>
block|{
typedef|typedef
name|typename
name|remove_all_cv_ptr
operator|<
name|T
operator|>
operator|::
name|type
name|type
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_all_cv_ptr
operator|<
specifier|const
specifier|volatile
name|T
operator|>
block|{
typedef|typedef
name|typename
name|remove_all_cv_ptr
operator|<
name|T
operator|>
operator|::
name|type
name|type
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|From
operator|,
name|typename
name|To
operator|>
expr|struct
name|conversion_preserves_array_indexing
operator|:
name|std
operator|::
name|false_type
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|FromVal
operator|,
name|typename
name|ToVal
operator|>
expr|struct
name|conversion_preserves_array_indexing
operator|<
name|FromVal
operator|*
operator|,
name|ToVal
operator|*
operator|>
operator|:
name|std
operator|::
name|integral_constant
operator|<
name|bool
operator|,
name|std
operator|::
name|is_convertible
operator|<
name|FromVal
operator|*
operator|,
name|ToVal
operator|*
operator|>
operator|::
name|value
operator|&&
name|std
operator|::
name|is_same
operator|<
name|typename
name|remove_all_cv_ptr
operator|<
name|FromVal
operator|>
operator|::
name|type
operator|,
name|typename
name|remove_all_cv_ptr
operator|<
name|ToVal
operator|>
operator|::
name|type
operator|>
operator|::
name|value
operator|>
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|LLVM_CONSTEXPR
name|auto
name|adl_begin
argument_list|(
name|T
operator|&&
name|t
argument_list|)
operator|->
name|decltype
argument_list|(
argument|begin(t)
argument_list|)
block|{
return|return
name|begin
argument_list|(
name|std
operator|::
name|forward
operator|<
name|T
operator|>
operator|(
name|t
operator|)
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|LLVM_CONSTEXPR
name|auto
name|adl_end
argument_list|(
name|T
operator|&&
name|t
argument_list|)
operator|->
name|decltype
argument_list|(
argument|end(t)
argument_list|)
block|{
return|return
name|end
argument_list|(
name|std
operator|::
name|forward
operator|<
name|T
operator|>
operator|(
name|t
operator|)
argument_list|)
return|;
block|}
block|}
comment|// end namespace detail
comment|/// A \c std::range<Iterator> represents a half-open iterator range
comment|/// built from two iterators, \c 'begin', and \c 'end'.  If \c end is
comment|/// not reachable from \c begin, the behavior is undefined.
comment|///
comment|/// The mutability of elements of the range is controlled by the
comment|/// Iterator argument.  Instantiate
comment|///<code>range<<var>Foo</var>::iterator></code> or
comment|///<code>range<<var>T</var>*></code>, or call
comment|///<code>make_range(<var>non_const_container</var>)</code>, and you
comment|/// get a mutable range.  Instantiate
comment|///<code>range<<var>Foo</var>::const_iterator></code> or
comment|///<code>range<const<var>T</var>*></code>, or call
comment|///<code>make_range(<var>const_container</var>)</code>, and you get a
comment|/// constant range.
comment|///
comment|/// \todo Inherit from std::pair<Iterator, Iterator>?
comment|///
comment|/// \todo This interface contains some functions that could be
comment|/// provided as free algorithms rather than member functions, and all
comment|/// of the<code>pop_*()</code> functions could be replaced by \c
comment|/// slice() at the cost of some extra iterator copies.  This makes
comment|/// them more awkward to use, but makes it easier for users to write
comment|/// their own types that follow the same interface. On the other hand,
comment|/// a \c range_facade could be provided to help users write new
comment|/// ranges, and it could provide the members.  Such functions are
comment|/// marked with a note in their documentation.  (Of course, all of
comment|/// these member functions could be provided as free functions using
comment|/// the iterator access methods, but one goal here is to allow people
comment|/// to program without touching iterators at all.)
name|template
operator|<
name|typename
name|Iterator
operator|>
name|class
name|range
block|{
name|Iterator
name|begin_
block|,
name|end_
block|;
name|public
operator|:
comment|/// \name types
comment|/// @{
comment|/// The iterator category of \c Iterator.
comment|/// \todo Consider defining range categories. If they don't add
comment|/// anything over the corresponding iterator categories, then
comment|/// they're probably not worth defining.
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|Iterator
operator|>
operator|::
name|iterator_category
name|iterator_category
expr_stmt|;
comment|/// The type of elements of the range. Not cv-qualified.
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|Iterator
operator|>
operator|::
name|value_type
name|value_type
expr_stmt|;
comment|/// The type of the size of the range and offsets within the range.
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|Iterator
operator|>
operator|::
name|difference_type
name|difference_type
expr_stmt|;
comment|/// The return type of element access methods: \c front(), \c back(), etc.
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|Iterator
operator|>
operator|::
name|reference
name|reference
expr_stmt|;
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|Iterator
operator|>
operator|::
name|pointer
name|pointer
expr_stmt|;
comment|/// @}
comment|/// \name constructors
comment|/// @{
comment|/// Creates a range of default-constructed (<em>not</em>
comment|/// value-initialized) iterators.  For most \c Iterator types, this
comment|/// will be an invalid range.
name|range
argument_list|()
operator|:
name|begin_
argument_list|()
operator|,
name|end_
argument_list|()
block|{}
comment|/// \pre \c end is reachable from \c begin.
comment|/// \post<code>this->begin() == begin&& this->end() == end</code>
name|LLVM_CONSTEXPR
name|range
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|)
operator|:
name|begin_
argument_list|(
name|begin
argument_list|)
operator|,
name|end_
argument_list|(
argument|end
argument_list|)
block|{}
comment|/// \par Participates in overload resolution if:
comment|///   - \c Iterator is not a pointer type,
comment|///   - \c begin(r) and \c end(r) return the same type, and
comment|///   - that type is convertible to \c Iterator.
comment|///
comment|/// \todo std::begin and std::end are overloaded between T& and
comment|/// const T&, which means that if a container has only a non-const
comment|/// begin or end method, then it's ill-formed to pass an rvalue to
comment|/// the free function.  To avoid that problem, we don't use
comment|/// std::forward<> here, so begin() and end() are always called with
comment|/// an lvalue.  Another option would be to insist that rvalue
comment|/// arguments to range() must have const begin() and end() methods.
name|template
operator|<
name|typename
name|R
operator|>
name|LLVM_CONSTEXPR
name|range
argument_list|(
argument|R&&r
argument_list|,
argument|typename std::enable_if<         !std::is_pointer<Iterator>::value&&         detail::is_range<R>::value&&         std::is_convertible<typename detail::begin_result<R>::type
argument_list|,
argument|Iterator>::value>::type* =
literal|0
argument_list|)
operator|:
name|begin_
argument_list|(
name|detail
operator|::
name|adl_begin
argument_list|(
name|r
argument_list|)
argument_list|)
operator|,
name|end_
argument_list|(
argument|detail::adl_end(r)
argument_list|)
block|{}
comment|/// This constructor creates a \c range<T*> from any range with
comment|/// contiguous iterators. Because dereferencing a past-the-end
comment|/// iterator can be undefined behavior, empty ranges get initialized
comment|/// with \c nullptr rather than \c&*begin().
comment|///
comment|/// \par Participates in overload resolution if:
comment|///   - \c Iterator is a pointer type \c T*,
comment|///   - \c begin(r) and \c end(r) return the same type,
comment|///   - elements \c i of that type satisfy the invariant
comment|///<code>&*(i + N) == (&*i) + N</code>, and
comment|///   - The result of<code>&*begin()</code> is convertible to \c T*
comment|///     using only qualification conversions [conv.qual] (since
comment|///     pointer conversions stop the pointer from pointing to an
comment|///     array element).
comment|///
comment|/// \todo The<code>&*(i + N) == (&*i) + N</code> invariant is
comment|/// currently impossible to check for user-defined types.  We need a
comment|/// \c contiguous_iterator_tag to let users assert it.
name|template
operator|<
name|typename
name|R
operator|>
name|LLVM_CONSTEXPR
name|range
argument_list|(
argument|R&&r
argument_list|,
argument|typename std::enable_if<         std::is_pointer<Iterator>::value&&         detail::is_contiguous_range<R>::value
comment|// MSVC returns false for this in this context, but not if we lift it out of the
comment|// constructor.
ifndef|#
directive|ifndef
name|_MSC_VER
argument|&& detail::conversion_preserves_array_indexing<              decltype(&*detail::adl_begin(r))
argument_list|,
argument|Iterator>::value
endif|#
directive|endif
argument|>::type* =
literal|0
argument_list|)
operator|:
name|begin_
argument_list|(
operator|(
name|detail
operator|::
name|adl_begin
argument_list|(
name|r
argument_list|)
operator|==
name|detail
operator|::
name|adl_end
argument_list|(
name|r
argument_list|)
operator|&&
operator|!
name|std
operator|::
name|is_pointer
operator|<
name|decltype
argument_list|(
name|detail
operator|::
name|adl_begin
argument_list|(
name|r
argument_list|)
argument_list|)
operator|>
operator|::
name|value
operator|)
comment|// For non-pointers,&*begin(r) is only defined behavior
comment|// if there's an element there.  Otherwise, use nullptr
comment|// since the user can't dereference it anyway.  This _is_
comment|// detectable.
operator|?
name|nullptr
operator|:
operator|&
operator|*
name|detail
operator|::
name|adl_begin
argument_list|(
name|r
argument_list|)
argument_list|)
operator|,
name|end_
argument_list|(
argument|begin_ + (detail::adl_end(r) - detail::adl_begin(r))
argument_list|)
block|{}
comment|/// @}
comment|/// \name iterator access
comment|/// @{
name|LLVM_CONSTEXPR
name|Iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|begin_
return|;
block|}
name|LLVM_CONSTEXPR
name|Iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|end_
return|;
block|}
comment|/// @}
comment|/// \name element access
comment|/// @{
comment|/// \par Complexity:
comment|/// O(1)
comment|/// \pre \c !empty()
comment|/// \returns a reference to the element at the front of the range.
name|LLVM_CONSTEXPR
name|reference
name|front
argument_list|()
specifier|const
block|{
return|return
operator|*
name|begin
argument_list|()
return|;
block|}
comment|/// \par Ill-formed unless:
comment|/// \c iterator_category is convertible to \c
comment|/// std::bidirectional_iterator_tag.
comment|///
comment|/// \par Complexity:
comment|/// O(2) (Involves copying and decrementing an iterator, so not
comment|/// quite as cheap as \c front())
comment|///
comment|/// \pre \c !empty()
comment|/// \returns a reference to the element at the front of the range.
name|LLVM_CONSTEXPR
name|reference
name|back
argument_list|()
specifier|const
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|is_convertible
operator|<
name|iterator_category
argument_list|,
name|std
operator|::
name|bidirectional_iterator_tag
operator|>
operator|::
name|value
argument_list|,
literal|"Can only retrieve the last element of a bidirectional range."
argument_list|)
block|;
name|using
name|std
operator|::
name|prev
block|;
return|return
operator|*
name|prev
argument_list|(
name|end
argument_list|()
argument_list|)
return|;
block|}
comment|/// This method is drawn from scripting language indexing.  It
comment|/// indexes std::forward from the beginning of the range if the argument
comment|/// is positive, or backwards from the end of the array if the
comment|/// argument is negative.
comment|///
comment|/// \par Ill-formed unless:
comment|/// \c iterator_category is convertible to \c
comment|/// std::random_access_iterator_tag.
comment|///
comment|/// \par Complexity:
comment|/// O(1)
comment|///
comment|/// \pre<code>abs(index)< size() || index == -size()</code>
comment|///
comment|/// \returns if<code>index>= 0</code>, a reference to the
comment|///<code>index</code>'th element in the range. Otherwise, a
comment|/// reference to the<code>size()+index</code>'th element.
name|LLVM_CONSTEXPR
name|reference
name|operator
index|[]
argument_list|(
name|difference_type
name|index
argument_list|)
decl|const
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|is_convertible
operator|<
name|iterator_category
argument_list|,
name|std
operator|::
name|random_access_iterator_tag
operator|>
operator|::
name|value
argument_list|,
literal|"Can only index into a random-access range."
argument_list|)
expr_stmt|;
comment|// Less readable construction for constexpr support.
return|return
name|index
operator|<
literal|0
condition|?
name|end
argument_list|()
index|[
name|index
index|]
else|:
name|begin
argument_list|()
index|[
name|index
index|]
return|;
block|}
comment|/// @}
comment|/// \name size
comment|/// @{
comment|/// \par Complexity:
comment|/// O(1)
comment|/// \returns \c true if the range contains no elements.
name|LLVM_CONSTEXPR
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|begin
argument_list|()
operator|==
name|end
argument_list|()
return|;
block|}
comment|/// \par Ill-formed unless:
comment|/// \c iterator_category is convertible to
comment|/// \c std::forward_iterator_tag.
comment|///
comment|/// \par Complexity:
comment|/// O(1) if \c iterator_category is convertible to \c
comment|/// std::random_access_iterator_tag. O(<code>size()</code>)
comment|/// otherwise.
comment|///
comment|/// \returns the number of times \c pop_front() can be called before
comment|/// \c empty() becomes true.
name|LLVM_CONSTEXPR
name|difference_type
name|size
argument_list|()
specifier|const
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|is_convertible
operator|<
name|iterator_category
argument_list|,
name|std
operator|::
name|forward_iterator_tag
operator|>
operator|::
name|value
argument_list|,
literal|"Calling size on an input range would destroy the range."
argument_list|)
block|;
return|return
name|dispatch_size
argument_list|(
name|iterator_category
argument_list|()
argument_list|)
return|;
block|}
comment|/// @}
comment|/// \name traversal from the beginning of the range
comment|/// @{
comment|/// Advances the beginning of the range by one element.
comment|/// \pre \c !empty()
name|void
name|pop_front
parameter_list|()
block|{
operator|++
name|begin_
expr_stmt|;
block|}
comment|/// Advances the beginning of the range by \c n elements.
comment|///
comment|/// \par Complexity:
comment|/// O(1) if \c iterator_category is convertible to \c
comment|/// std::random_access_iterator_tag, O(<code>n</code>) otherwise.
comment|///
comment|/// \pre<code>n>= 0</code>, and there must be at least \c n
comment|/// elements in the range.
name|void
name|pop_front
parameter_list|(
name|difference_type
name|n
parameter_list|)
block|{
name|advance
argument_list|(
name|begin_
argument_list|,
name|n
argument_list|)
expr_stmt|;
block|}
comment|/// Advances the beginning of the range by at most \c n elements,
comment|/// stopping if the range becomes empty.  A negative argument causes
comment|/// no change.
comment|///
comment|/// \par Complexity:
comment|/// O(1) if \c iterator_category is convertible to \c
comment|/// std::random_access_iterator_tag, O(<code>min(n,
comment|///<var>#-elements-in-range</var>)</code>) otherwise.
comment|///
comment|/// \note Could be provided as a free function with little-to-no
comment|/// loss in efficiency.
name|void
name|pop_front_upto
parameter_list|(
name|difference_type
name|n
parameter_list|)
block|{
name|advance_upto
argument_list|(
name|begin_
argument_list|,
name|std
operator|::
name|max
operator|<
name|difference_type
operator|>
operator|(
literal|0
operator|,
name|n
operator|)
argument_list|,
name|end_
argument_list|,
name|iterator_category
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// @}
comment|/// \name traversal from the end of the range
comment|/// @{
comment|/// Moves the end of the range earlier by one element.
comment|///
comment|/// \par Ill-formed unless:
comment|/// \c iterator_category is convertible to
comment|/// \c std::bidirectional_iterator_tag.
comment|///
comment|/// \par Complexity:
comment|/// O(1)
comment|///
comment|/// \pre \c !empty()
name|void
name|pop_back
parameter_list|()
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|is_convertible
operator|<
name|iterator_category
argument_list|,
name|std
operator|::
name|bidirectional_iterator_tag
operator|>
operator|::
name|value
argument_list|,
literal|"Can only access the end of a bidirectional range."
argument_list|)
expr_stmt|;
operator|--
name|end_
expr_stmt|;
block|}
comment|/// Moves the end of the range earlier by \c n elements.
comment|///
comment|/// \par Ill-formed unless:
comment|/// \c iterator_category is convertible to
comment|/// \c std::bidirectional_iterator_tag.
comment|///
comment|/// \par Complexity:
comment|/// O(1) if \c iterator_category is convertible to \c
comment|/// std::random_access_iterator_tag, O(<code>n</code>) otherwise.
comment|///
comment|/// \pre<code>n>= 0</code>, and there must be at least \c n
comment|/// elements in the range.
name|void
name|pop_back
parameter_list|(
name|difference_type
name|n
parameter_list|)
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|is_convertible
operator|<
name|iterator_category
argument_list|,
name|std
operator|::
name|bidirectional_iterator_tag
operator|>
operator|::
name|value
argument_list|,
literal|"Can only access the end of a bidirectional range."
argument_list|)
expr_stmt|;
name|advance
argument_list|(
name|end_
argument_list|,
operator|-
name|n
argument_list|)
expr_stmt|;
block|}
comment|/// Moves the end of the range earlier by<code>min(n,
comment|/// size())</code> elements.  A negative argument causes no change.
comment|///
comment|/// \par Ill-formed unless:
comment|/// \c iterator_category is convertible to
comment|/// \c std::bidirectional_iterator_tag.
comment|///
comment|/// \par Complexity:
comment|/// O(1) if \c iterator_category is convertible to \c
comment|/// std::random_access_iterator_tag, O(<code>min(n,
comment|///<var>#-elements-in-range</var>)</code>) otherwise.
comment|///
comment|/// \note Could be provided as a free function with little-to-no
comment|/// loss in efficiency.
name|void
name|pop_back_upto
parameter_list|(
name|difference_type
name|n
parameter_list|)
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|is_convertible
operator|<
name|iterator_category
argument_list|,
name|std
operator|::
name|bidirectional_iterator_tag
operator|>
operator|::
name|value
argument_list|,
literal|"Can only access the end of a bidirectional range."
argument_list|)
expr_stmt|;
name|advance_upto
argument_list|(
name|end_
argument_list|,
operator|-
name|std
operator|::
name|max
operator|<
name|difference_type
operator|>
operator|(
literal|0
operator|,
name|n
operator|)
argument_list|,
name|begin_
argument_list|,
name|iterator_category
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// @}
comment|/// \name creating derived ranges
comment|/// @{
comment|/// Divides the range into two pieces at \c index, where a positive
comment|/// \c index represents an offset from the beginning of the range
comment|/// and a negative \c index represents an offset from the end.
comment|///<code>range[index]</code> is the first element in the second
comment|/// piece.  If<code>index>= size()</code>, the second piece
comment|/// will be empty. If<code>index< -size()</code>, the first
comment|/// piece will be empty.
comment|///
comment|/// \par Ill-formed unless:
comment|/// \c iterator_category is convertible to
comment|/// \c std::forward_iterator_tag.
comment|///
comment|/// \par Complexity:
comment|///   - If \c iterator_category is convertible to \c
comment|///     std::random_access_iterator_tag: O(1)
comment|///   - Otherwise, if \c iterator_category is convertible to \c
comment|///     std::bidirectional_iterator_tag, \c abs(index) iterator increments
comment|///     or decrements
comment|///   - Otherwise, if<code>index>= 0</code>,  \c index iterator
comment|///     increments
comment|///   - Otherwise,<code>size() + (size() + index)</code>
comment|///     iterator increments.
comment|///
comment|/// \returns a pair of adjacent ranges.
comment|///
comment|/// \post
comment|///   -<code>result.first.size() == min(index, this->size())</code>
comment|///   -<code>result.first.end() == result.second.begin()</code>
comment|///   -<code>result.first.size() + result.second.size()</code><code>==
comment|///     this->size()</code>
comment|///
comment|/// \todo split() could take an arbitrary number of indices and
comment|/// return an<code>N+1</code>-element \c tuple<>. This is tricky to
comment|/// implement with negative indices in the optimal number of
comment|/// increments or decrements for a bidirectional iterator, but it
comment|/// should be possible.  Do we want it?
name|std
operator|::
name|pair
operator|<
name|range
operator|,
name|range
operator|>
name|split
argument_list|(
argument|difference_type index
argument_list|)
specifier|const
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|is_convertible
operator|<
name|iterator_category
argument_list|,
name|std
operator|::
name|forward_iterator_tag
operator|>
operator|::
name|value
argument_list|,
literal|"Calling split on a non-std::forward range would return a useless "
literal|"first result."
argument_list|)
block|;
if|if
condition|(
name|index
operator|>=
literal|0
condition|)
block|{
name|range
name|second
init|=
operator|*
name|this
decl_stmt|;
name|second
operator|.
name|pop_front_upto
argument_list|(
name|index
argument_list|)
expr_stmt|;
return|return
name|make_pair
argument_list|(
name|range
argument_list|(
name|begin
argument_list|()
argument_list|,
name|second
operator|.
name|begin
argument_list|()
argument_list|)
argument_list|,
name|second
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|dispatch_split_neg
argument_list|(
name|index
argument_list|,
name|iterator_category
argument_list|()
argument_list|)
return|;
block|}
block|}
comment|/// \returns A sub-range from \c start to \c stop (not including \c
comment|/// stop, as usual).  \c start and \c stop are interpreted as for
comment|///<code>operator[]</code>, with negative values offsetting from
comment|/// the end of the range.  Omitting the \c stop argument makes the
comment|/// sub-range continue to the end of the original range. Positive
comment|/// arguments saturate to the end of the range, and negative
comment|/// arguments saturate to the beginning.  If \c stop is before \c
comment|/// start, returns an empty range beginning and ending at \c start.
comment|///
comment|/// \par Ill-formed unless:
comment|/// \c iterator_category is convertible to
comment|/// \c std::forward_iterator_tag.
comment|///
comment|/// \par Complexity:
comment|///   - If \c iterator_category is convertible to \c
comment|///     std::random_access_iterator_tag: O(1)
comment|///   - Otherwise, if \c iterator_category is convertible to \c
comment|///     std::bidirectional_iterator_tag, at most<code>min(abs(start),
comment|///     size()) + min(abs(stop), size())</code> iterator
comment|///     increments or decrements
comment|///   - Otherwise, if<code>start>= 0&& stop>= 0</code>,
comment|///<code>max(start, stop)</code> iterator increments
comment|///   - Otherwise,<code>size() + max(start', stop')</code>
comment|///     iterator increments, where \c start' and \c stop' are the
comment|///     offsets of the elements \c start and \c stop refer to.
comment|///
comment|/// \note \c slice(start) should be implemented with a different
comment|/// overload, rather than defaulting \c stop to
comment|///<code>numeric_limits<difference_type>::max()</code>, because
comment|/// using a default would force non-random-access ranges to use an
comment|/// O(<code>size()</code>) algorithm to compute the end rather
comment|/// than the O(1) they're capable of.
name|range
name|slice
argument_list|(
argument|difference_type start
argument_list|,
argument|difference_type stop
argument_list|)
specifier|const
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|is_convertible
operator|<
name|iterator_category
argument_list|,
name|std
operator|::
name|forward_iterator_tag
operator|>
operator|::
name|value
argument_list|,
literal|"Calling slice on a non-std::forward range would destroy the original "
literal|"range."
argument_list|)
block|;
return|return
name|dispatch_slice
argument_list|(
name|start
argument_list|,
name|stop
argument_list|,
name|iterator_category
argument_list|()
argument_list|)
return|;
block|}
name|range
name|slice
argument_list|(
name|difference_type
name|start
argument_list|)
decl|const
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|is_convertible
operator|<
name|iterator_category
argument_list|,
name|std
operator|::
name|forward_iterator_tag
operator|>
operator|::
name|value
argument_list|,
literal|"Calling slice on a non-std::forward range would destroy the original "
literal|"range."
argument_list|)
expr_stmt|;
return|return
name|split
argument_list|(
name|start
argument_list|)
operator|.
name|second
return|;
block|}
comment|/// @}
name|private
label|:
comment|// advance_upto: should be added to<algorithm>, but I'll use it as
comment|// a helper function here.
comment|//
comment|// These return the number of increments that weren't applied
comment|// because we ran into 'limit' (or 0 if we didn't run into limit).
specifier|static
name|difference_type
name|advance_upto
argument_list|(
name|Iterator
operator|&
name|it
argument_list|,
name|difference_type
name|n
argument_list|,
name|Iterator
name|limit
argument_list|,
name|std
operator|::
name|input_iterator_tag
argument_list|)
block|{
if|if
condition|(
name|n
operator|<
literal|0
condition|)
return|return
literal|0
return|;
while|while
condition|(
name|it
operator|!=
name|limit
operator|&&
name|n
operator|>
literal|0
condition|)
block|{
operator|++
name|it
expr_stmt|;
operator|--
name|n
expr_stmt|;
block|}
return|return
name|n
return|;
block|}
specifier|static
name|difference_type
name|advance_upto
argument_list|(
name|Iterator
operator|&
name|it
argument_list|,
name|difference_type
name|n
argument_list|,
name|Iterator
name|limit
argument_list|,
name|std
operator|::
name|bidirectional_iterator_tag
argument_list|)
block|{
if|if
condition|(
name|n
operator|<
literal|0
condition|)
block|{
while|while
condition|(
name|it
operator|!=
name|limit
operator|&&
name|n
operator|<
literal|0
condition|)
block|{
operator|--
name|it
expr_stmt|;
operator|++
name|n
expr_stmt|;
block|}
block|}
else|else
block|{
while|while
condition|(
name|it
operator|!=
name|limit
operator|&&
name|n
operator|>
literal|0
condition|)
block|{
operator|++
name|it
expr_stmt|;
operator|--
name|n
expr_stmt|;
block|}
block|}
return|return
name|n
return|;
block|}
specifier|static
name|difference_type
name|advance_upto
argument_list|(
name|Iterator
operator|&
name|it
argument_list|,
name|difference_type
name|n
argument_list|,
name|Iterator
name|limit
argument_list|,
name|std
operator|::
name|random_access_iterator_tag
argument_list|)
block|{
name|difference_type
name|distance
init|=
name|limit
operator|-
name|it
decl_stmt|;
if|if
condition|(
name|distance
operator|<
literal|0
condition|)
name|assert
argument_list|(
name|n
operator|<=
literal|0
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|distance
operator|>
literal|0
condition|)
name|assert
argument_list|(
name|n
operator|>=
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|abs
argument_list|(
name|distance
argument_list|)
operator|>
name|abs
argument_list|(
name|n
argument_list|)
condition|)
block|{
name|it
operator|+=
name|n
expr_stmt|;
return|return
literal|0
return|;
block|}
else|else
block|{
name|it
operator|=
name|limit
expr_stmt|;
return|return
name|n
operator|-
name|distance
return|;
block|}
block|}
comment|// Dispatch functions.
name|difference_type
name|dispatch_size
argument_list|(
name|std
operator|::
name|forward_iterator_tag
argument_list|)
decl|const
block|{
return|return
name|std
operator|::
name|distance
argument_list|(
name|begin
argument_list|()
argument_list|,
name|end
argument_list|()
argument_list|)
return|;
block|}
name|LLVM_CONSTEXPR
name|difference_type
name|dispatch_size
argument_list|(
name|std
operator|::
name|random_access_iterator_tag
argument_list|)
decl|const
block|{
return|return
name|end
argument_list|()
operator|-
name|begin
argument_list|()
return|;
block|}
name|std
operator|::
name|pair
operator|<
name|range
operator|,
name|range
operator|>
name|dispatch_split_neg
argument_list|(
argument|difference_type index
argument_list|,
argument|std::forward_iterator_tag
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|index
operator|<
literal|0
argument_list|)
block|;
name|difference_type
name|size
operator|=
name|this
operator|->
name|size
argument_list|()
block|;
return|return
name|split
argument_list|(
name|std
operator|::
name|max
operator|<
name|difference_type
operator|>
operator|(
literal|0
operator|,
name|size
operator|+
name|index
operator|)
argument_list|)
return|;
block|}
name|std
operator|::
name|pair
operator|<
name|range
operator|,
name|range
operator|>
name|dispatch_split_neg
argument_list|(
argument|difference_type index
argument_list|,
argument|std::bidirectional_iterator_tag
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|index
operator|<
literal|0
argument_list|)
block|;
name|range
name|first
operator|=
operator|*
name|this
block|;
name|first
operator|.
name|pop_back_upto
argument_list|(
operator|-
name|index
argument_list|)
block|;
return|return
name|make_pair
argument_list|(
name|first
argument_list|,
name|range
argument_list|(
name|first
operator|.
name|end
argument_list|()
argument_list|,
name|end
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
name|range
name|dispatch_slice
argument_list|(
name|difference_type
name|start
argument_list|,
name|difference_type
name|stop
argument_list|,
name|std
operator|::
name|forward_iterator_tag
argument_list|)
decl|const
block|{
if|if
condition|(
name|start
operator|<
literal|0
operator|||
name|stop
operator|<
literal|0
condition|)
block|{
name|difference_type
name|size
init|=
name|this
operator|->
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|start
operator|<
literal|0
condition|)
name|start
operator|=
name|std
operator|::
name|max
operator|<
name|difference_type
operator|>
operator|(
literal|0
operator|,
name|size
operator|+
name|start
operator|)
expr_stmt|;
if|if
condition|(
name|stop
operator|<
literal|0
condition|)
name|stop
operator|=
name|size
operator|+
name|stop
expr_stmt|;
comment|// Possibly negative; will be fixed in 2 lines.
block|}
name|stop
operator|=
name|std
operator|::
name|max
operator|<
name|difference_type
operator|>
operator|(
name|start
operator|,
name|stop
operator|)
expr_stmt|;
name|Iterator
name|first
init|=
name|begin
argument_list|()
decl_stmt|;
name|advance_upto
argument_list|(
name|first
argument_list|,
name|start
argument_list|,
name|end
argument_list|()
argument_list|,
name|iterator_category
argument_list|()
argument_list|)
expr_stmt|;
name|Iterator
name|last
init|=
name|first
decl_stmt|;
name|advance_upto
argument_list|(
name|last
argument_list|,
name|stop
operator|-
name|start
argument_list|,
name|end
argument_list|()
argument_list|,
name|iterator_category
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|range
argument_list|(
name|first
argument_list|,
name|last
argument_list|)
return|;
block|}
name|range
name|dispatch_slice
argument_list|(
specifier|const
name|difference_type
name|start
argument_list|,
specifier|const
name|difference_type
name|stop
argument_list|,
name|std
operator|::
name|bidirectional_iterator_tag
argument_list|)
decl|const
block|{
name|Iterator
name|first
decl_stmt|;
if|if
condition|(
name|start
operator|<
literal|0
condition|)
block|{
name|first
operator|=
name|end
argument_list|()
expr_stmt|;
name|advance_upto
argument_list|(
name|first
argument_list|,
name|start
argument_list|,
name|begin
argument_list|()
argument_list|,
name|iterator_category
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|first
operator|=
name|begin
argument_list|()
expr_stmt|;
name|advance_upto
argument_list|(
name|first
argument_list|,
name|start
argument_list|,
name|end
argument_list|()
argument_list|,
name|iterator_category
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|Iterator
name|last
decl_stmt|;
if|if
condition|(
name|stop
operator|<
literal|0
condition|)
block|{
name|last
operator|=
name|end
argument_list|()
expr_stmt|;
name|advance_upto
argument_list|(
name|last
argument_list|,
name|stop
argument_list|,
name|first
argument_list|,
name|iterator_category
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|start
operator|>=
literal|0
condition|)
block|{
name|last
operator|=
name|first
expr_stmt|;
if|if
condition|(
name|stop
operator|>
name|start
condition|)
name|advance_upto
argument_list|(
name|last
argument_list|,
name|stop
operator|-
name|start
argument_list|,
name|end
argument_list|()
argument_list|,
name|iterator_category
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Complicated: 'start' walked from the end of the sequence,
comment|// but 'stop' needs to walk from the beginning.
name|Iterator
name|dummy
init|=
name|begin
argument_list|()
decl_stmt|;
comment|// Walk up to 'stop' increments from begin(), stopping when we
comment|// get to 'first', and capturing the remaining number of
comment|// increments.
name|difference_type
name|increments_past_start
init|=
name|advance_upto
argument_list|(
name|dummy
argument_list|,
name|stop
argument_list|,
name|first
argument_list|,
name|iterator_category
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|increments_past_start
operator|==
literal|0
condition|)
block|{
comment|// If this is 0, then stop was before start.
name|last
operator|=
name|first
expr_stmt|;
block|}
else|else
block|{
comment|// Otherwise, count that many spaces beyond first.
name|last
operator|=
name|first
expr_stmt|;
name|advance_upto
argument_list|(
name|last
argument_list|,
name|increments_past_start
argument_list|,
name|end
argument_list|()
argument_list|,
name|iterator_category
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
return|return
name|range
argument_list|(
name|first
argument_list|,
name|last
argument_list|)
return|;
block|}
name|range
name|dispatch_slice
argument_list|(
name|difference_type
name|start
argument_list|,
name|difference_type
name|stop
argument_list|,
name|std
operator|::
name|random_access_iterator_tag
argument_list|)
decl|const
block|{
specifier|const
name|difference_type
name|size
init|=
name|this
operator|->
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|start
operator|<
literal|0
condition|)
name|start
operator|=
name|size
operator|+
name|start
expr_stmt|;
if|if
condition|(
name|start
operator|<
literal|0
condition|)
name|start
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|start
operator|>
name|size
condition|)
name|start
operator|=
name|size
expr_stmt|;
if|if
condition|(
name|stop
operator|<
literal|0
condition|)
name|stop
operator|=
name|size
operator|+
name|stop
expr_stmt|;
if|if
condition|(
name|stop
operator|<
name|start
condition|)
name|stop
operator|=
name|start
expr_stmt|;
if|if
condition|(
name|stop
operator|>
name|size
condition|)
name|stop
operator|=
name|size
expr_stmt|;
return|return
name|range
argument_list|(
name|begin
argument_list|()
operator|+
name|start
argument_list|,
name|begin
argument_list|()
operator|+
name|stop
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \name deducing constructor wrappers
end_comment

begin_comment
comment|/// \relates std::range
end_comment

begin_comment
comment|/// \xmlonly<nonmember/> \endxmlonly
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These functions do the same thing as the constructor with the same
end_comment

begin_comment
comment|/// signature. They just allow users to avoid writing the iterator
end_comment

begin_comment
comment|/// type.
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// \todo I'd like to define a \c make_range taking a single iterator
end_comment

begin_comment
comment|/// argument representing the beginning of a range that ends with a
end_comment

begin_comment
comment|/// default-constructed \c Iterator.  This would help with using
end_comment

begin_comment
comment|/// iterators like \c istream_iterator.  However, using just \c
end_comment

begin_comment
comment|/// make_range() could be confusing and lead to people writing
end_comment

begin_comment
comment|/// incorrect ranges of more common iterators. Is there a better name?
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Iterator
operator|>
name|LLVM_CONSTEXPR
name|range
operator|<
name|Iterator
operator|>
name|make_range
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|)
block|{
return|return
name|range
operator|<
name|Iterator
operator|>
operator|(
name|begin
operator|,
name|end
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \par Participates in overload resolution if:
end_comment

begin_comment
comment|/// \c begin(r) and \c end(r) return the same type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Range
operator|>
name|LLVM_CONSTEXPR
name|auto
name|make_range
argument_list|(
argument|Range&&r
argument_list|,
argument|typename std::enable_if<detail::is_range<Range>::value>::type* =
literal|0
argument_list|)
operator|->
name|range
operator|<
name|decltype
argument_list|(
name|detail
operator|::
name|adl_begin
argument_list|(
name|r
argument_list|)
argument_list|)
operator|>
block|{
return|return
name|range
operator|<
name|decltype
argument_list|(
name|detail
operator|::
name|adl_begin
argument_list|(
name|r
argument_list|)
argument_list|)
operator|>
operator|(
name|r
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \par Participates in overload resolution if:
end_comment

begin_comment
comment|///   - \c begin(r) and \c end(r) return the same type,
end_comment

begin_comment
comment|///   -  that type satisfies the invariant that<code>&*(i + N) ==
end_comment

begin_comment
comment|///      (&*i) + N</code>, and
end_comment

begin_comment
comment|///   - \c&*begin(r) has a pointer type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Range
operator|>
name|LLVM_CONSTEXPR
name|auto
name|make_ptr_range
argument_list|(
argument|Range&&r
argument_list|,
argument|typename std::enable_if<       detail::is_contiguous_range<Range>::value&&       std::is_pointer<decltype(&*detail::adl_begin(r))>::value>::type* =
literal|0
argument_list|)
operator|->
name|range
operator|<
name|decltype
argument_list|(
operator|&
operator|*
name|detail
operator|::
name|adl_begin
argument_list|(
name|r
argument_list|)
argument_list|)
operator|>
block|{
return|return
name|range
operator|<
name|decltype
argument_list|(
operator|&
operator|*
name|detail
operator|::
name|adl_begin
argument_list|(
name|r
argument_list|)
argument_list|)
operator|>
operator|(
name|r
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
unit|}
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

