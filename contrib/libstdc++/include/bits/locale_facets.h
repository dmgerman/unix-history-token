begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Locale support -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006
end_comment

begin_comment
comment|// Free Software Foundation, Inc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is part of the GNU ISO C++ Library.  This library is free
end_comment

begin_comment
comment|// software; you can redistribute it and/or modify it under the
end_comment

begin_comment
comment|// terms of the GNU General Public License as published by the
end_comment

begin_comment
comment|// Free Software Foundation; either version 2, or (at your option)
end_comment

begin_comment
comment|// any later version.
end_comment

begin_comment
comment|// This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// GNU General Public License for more details.
end_comment

begin_comment
comment|// You should have received a copy of the GNU General Public License along
end_comment

begin_comment
comment|// with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
end_comment

begin_comment
comment|// USA.
end_comment

begin_comment
comment|// As a special exception, you may use this file as part of a free software
end_comment

begin_comment
comment|// library without restriction.  Specifically, if other files instantiate
end_comment

begin_comment
comment|// templates or use macros or inline functions from this file, or you compile
end_comment

begin_comment
comment|// this file and link it with other files to produce an executable, this
end_comment

begin_comment
comment|// file does not by itself cause the resulting executable to be covered by
end_comment

begin_comment
comment|// the GNU General Public License.  This exception does not however
end_comment

begin_comment
comment|// invalidate any other reasons why the executable file might be covered by
end_comment

begin_comment
comment|// the GNU General Public License.
end_comment

begin_comment
comment|/** @file locale_facets.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ISO C++ 14882: 22.1  Locales
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCALE_FACETS_H
end_ifndef

begin_define
define|#
directive|define
name|_LOCALE_FACETS_H
value|1
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_include
include|#
directive|include
file|<ctime>
end_include

begin_comment
comment|// For struct tm
end_comment

begin_include
include|#
directive|include
file|<cwctype>
end_include

begin_comment
comment|// For wctype_t
end_comment

begin_include
include|#
directive|include
file|<bits/ctype_base.h>
end_include

begin_include
include|#
directive|include
file|<iosfwd>
end_include

begin_include
include|#
directive|include
file|<bits/ios_base.h>
end_include

begin_comment
comment|// For ios_base, ios_base::iostate
end_comment

begin_include
include|#
directive|include
file|<streambuf>
end_include

begin_include
include|#
directive|include
file|<bits/cpp_type_traits.h>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|std
argument_list|)
end_macro

begin_comment
comment|// NB: Don't instantiate required wchar_t facets if no wchar_t support.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
end_ifdef

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_FACETS
value|28
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_FACETS
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Convert string to numeric value of type _Tv and store results.
end_comment

begin_comment
comment|// NB: This is specialized for all required types, there is no
end_comment

begin_comment
comment|// generic definition.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tv
operator|>
name|void
name|__convert_to_v
argument_list|(
specifier|const
name|char
operator|*
name|__in
argument_list|,
name|_Tv
operator|&
name|__out
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
specifier|const
name|__c_locale
operator|&
name|__cloc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Explicit specializations for required types.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|__convert_to_v
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|float
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
argument_list|,
specifier|const
name|__c_locale
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|__convert_to_v
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|double
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
argument_list|,
specifier|const
name|__c_locale
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|__convert_to_v
argument_list|(
argument|const char*
argument_list|,
argument|long double&
argument_list|,
argument|ios_base::iostate&
argument_list|,
argument|const __c_locale&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// NB: __pad is a struct, rather than a function, so it can be
end_comment

begin_comment
comment|// partially-specialized.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
expr|struct
name|__pad
block|{
specifier|static
name|void
name|_S_pad
argument_list|(
argument|ios_base& __io
argument_list|,
argument|_CharT __fill
argument_list|,
argument|_CharT* __news
argument_list|,
argument|const _CharT* __olds
argument_list|,
argument|const streamsize __newlen
argument_list|,
argument|const streamsize __oldlen
argument_list|,
argument|const bool __num
argument_list|)
block|;     }
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Used by both numeric and monetary facets.
end_comment

begin_comment
comment|// Inserts "group separator" characters into an array of characters.
end_comment

begin_comment
comment|// It's recursive, one iteration per group.  It moves the characters
end_comment

begin_comment
comment|// in the buffer this way: "xxxx12345" -> "12,345xxx".  Call this
end_comment

begin_comment
comment|// only with __glen != 0.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|_CharT
operator|*
name|__add_grouping
argument_list|(
argument|_CharT* __s
argument_list|,
argument|_CharT __sep
argument_list|,
argument|const char* __gbeg
argument_list|,
argument|size_t __gsize
argument_list|,
argument|const _CharT* __first
argument_list|,
argument|const _CharT* __last
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// This template permits specializing facet output code for
end_comment

begin_comment
comment|// ostreambuf_iterator.  For ostreambuf_iterator, sputn is
end_comment

begin_comment
comment|// significantly more efficient than incrementing iterators.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|ostreambuf_iterator
operator|<
name|_CharT
operator|>
name|__write
argument_list|(
argument|ostreambuf_iterator<_CharT> __s
argument_list|,
argument|const _CharT* __ws
argument_list|,
argument|int __len
argument_list|)
block|{
name|__s
operator|.
name|_M_put
argument_list|(
name|__ws
argument_list|,
name|__len
argument_list|)
block|;
return|return
name|__s
return|;
block|}
end_expr_stmt

begin_comment
comment|// This is the unspecialized form of the template.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|>
specifier|inline
name|_OutIter
name|__write
argument_list|(
argument|_OutIter __s
argument_list|,
argument|const _CharT* __ws
argument_list|,
argument|int __len
argument_list|)
block|{
for|for
control|(
name|int
name|__j
init|=
literal|0
init|;
name|__j
operator|<
name|__len
condition|;
name|__j
operator|++
operator|,
operator|++
name|__s
control|)
operator|*
name|__s
operator|=
name|__ws
index|[
name|__j
index|]
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__s
return|;
end_return

begin_comment
unit|}
comment|// 22.2.1.1  Template class ctype
end_comment

begin_comment
comment|// Include host and configuration specific ctype enums for ctype_base.
end_comment

begin_comment
comment|// Common base for ctype<_CharT>.
end_comment

begin_comment
comment|/**    *  @brief  Common base for ctype facet    *    *  This template class provides implementations of the public functions    *  that forward to the protected virtual functions.    *    *  This template also provides abtract stubs for the protected virtual    *  functions.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|__ctype_abstract_base
operator|:
name|public
name|locale
operator|::
name|facet
operator|,
name|public
name|ctype_base
block|{
name|public
operator|:
comment|// Types:
comment|/// Typedef for the template parameter
typedef|typedef
name|_CharT
name|char_type
typedef|;
comment|/**        *  @brief  Test char_type classification.        *        *  This function finds a mask M for @a c and compares it to mask @a m.        *  It does so by returning the value of ctype<char_type>::do_is().        *        *  @param c  The char_type to compare the mask of.        *  @param m  The mask to compare against.        *  @return  (M& m) != 0.       */
name|bool
name|is
argument_list|(
argument|mask __m
argument_list|,
argument|char_type __c
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_is
argument_list|(
name|__m
argument_list|,
name|__c
argument_list|)
return|;
block|}
comment|/**        *  @brief  Return a mask array.        *        *  This function finds the mask for each char_type in the range [lo,hi)        *  and successively writes it to vec.  vec must have as many elements        *  as the char array.  It does so by returning the value of        *  ctype<char_type>::do_is().        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @param vec  Pointer to an array of mask storage.        *  @return  @a hi.       */
specifier|const
name|char_type
operator|*
name|is
argument_list|(
argument|const char_type *__lo
argument_list|,
argument|const char_type *__hi
argument_list|,
argument|mask *__vec
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_is
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|,
name|__vec
argument_list|)
return|;
block|}
comment|/**        *  @brief  Find char_type matching a mask        *        *  This function searches for and returns the first char_type c in        *  [lo,hi) for which is(m,c) is true.  It does so by returning        *  ctype<char_type>::do_scan_is().        *        *  @param m  The mask to compare against.        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @return  Pointer to matching char_type if found, else @a hi.       */
specifier|const
name|char_type
operator|*
name|scan_is
argument_list|(
argument|mask __m
argument_list|,
argument|const char_type* __lo
argument_list|,
argument|const char_type* __hi
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_scan_is
argument_list|(
name|__m
argument_list|,
name|__lo
argument_list|,
name|__hi
argument_list|)
return|;
block|}
comment|/**        *  @brief  Find char_type not matching a mask        *        *  This function searches for and returns the first char_type c in        *  [lo,hi) for which is(m,c) is false.  It does so by returning        *  ctype<char_type>::do_scan_not().        *        *  @param m  The mask to compare against.        *  @param lo  Pointer to first char in range.        *  @param hi  Pointer to end of range.        *  @return  Pointer to non-matching char if found, else @a hi.       */
specifier|const
name|char_type
operator|*
name|scan_not
argument_list|(
argument|mask __m
argument_list|,
argument|const char_type* __lo
argument_list|,
argument|const char_type* __hi
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_scan_not
argument_list|(
name|__m
argument_list|,
name|__lo
argument_list|,
name|__hi
argument_list|)
return|;
block|}
comment|/**        *  @brief  Convert to uppercase.        *        *  This function converts the argument to uppercase if possible.        *  If not possible (for example, '2'), returns the argument.  It does        *  so by returning ctype<char_type>::do_toupper().        *        *  @param c  The char_type to convert.        *  @return  The uppercase char_type if convertible, else @a c.       */
name|char_type
name|toupper
argument_list|(
argument|char_type __c
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_toupper
argument_list|(
name|__c
argument_list|)
return|;
block|}
comment|/**        *  @brief  Convert array to uppercase.        *        *  This function converts each char_type in the range [lo,hi) to        *  uppercase if possible.  Other elements remain untouched.  It does so        *  by returning ctype<char_type>:: do_toupper(lo, hi).        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @return  @a hi.       */
specifier|const
name|char_type
operator|*
name|toupper
argument_list|(
argument|char_type *__lo
argument_list|,
argument|const char_type* __hi
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_toupper
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|)
return|;
block|}
comment|/**        *  @brief  Convert to lowercase.        *        *  This function converts the argument to lowercase if possible.  If        *  not possible (for example, '2'), returns the argument.  It does so        *  by returning ctype<char_type>::do_tolower(c).        *        *  @param c  The char_type to convert.        *  @return  The lowercase char_type if convertible, else @a c.       */
name|char_type
name|tolower
argument_list|(
argument|char_type __c
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_tolower
argument_list|(
name|__c
argument_list|)
return|;
block|}
comment|/**        *  @brief  Convert array to lowercase.        *        *  This function converts each char_type in the range [lo,hi) to        *  lowercase if possible.  Other elements remain untouched.  It does so        *  by returning ctype<char_type>:: do_tolower(lo, hi).        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @return  @a hi.       */
specifier|const
name|char_type
operator|*
name|tolower
argument_list|(
argument|char_type* __lo
argument_list|,
argument|const char_type* __hi
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_tolower
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|)
return|;
block|}
comment|/**        *  @brief  Widen char to char_type        *        *  This function converts the char argument to char_type using the        *  simplest reasonable transformation.  It does so by returning        *  ctype<char_type>::do_widen(c).        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param c  The char to convert.        *  @return  The converted char_type.       */
name|char_type
name|widen
argument_list|(
argument|char __c
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_widen
argument_list|(
name|__c
argument_list|)
return|;
block|}
comment|/**        *  @brief  Widen array to char_type        *        *  This function converts each char in the input to char_type using the        *  simplest reasonable transformation.  It does so by returning        *  ctype<char_type>::do_widen(c).        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @param to  Pointer to the destination array.        *  @return  @a hi.       */
specifier|const
name|char
operator|*
name|widen
argument_list|(
argument|const char* __lo
argument_list|,
argument|const char* __hi
argument_list|,
argument|char_type* __to
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_widen
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|,
name|__to
argument_list|)
return|;
block|}
comment|/**        *  @brief  Narrow char_type to char        *        *  This function converts the char_type to char using the simplest        *  reasonable transformation.  If the conversion fails, dfault is        *  returned instead.  It does so by returning        *  ctype<char_type>::do_narrow(c).        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param c  The char_type to convert.        *  @param dfault  Char to return if conversion fails.        *  @return  The converted char.       */
name|char
name|narrow
argument_list|(
argument|char_type __c
argument_list|,
argument|char __dfault
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_narrow
argument_list|(
name|__c
argument_list|,
name|__dfault
argument_list|)
return|;
block|}
comment|/**        *  @brief  Narrow array to char array        *        *  This function converts each char_type in the input to char using the        *  simplest reasonable transformation and writes the results to the        *  destination array.  For any char_type in the input that cannot be        *  converted, @a dfault is used instead.  It does so by returning        *  ctype<char_type>::do_narrow(lo, hi, dfault, to).        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @param dfault  Char to use if conversion fails.        *  @param to  Pointer to the destination array.        *  @return  @a hi.       */
specifier|const
name|char_type
operator|*
name|narrow
argument_list|(
argument|const char_type* __lo
argument_list|,
argument|const char_type* __hi
argument_list|,
argument|char __dfault
argument_list|,
argument|char *__to
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_narrow
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|,
name|__dfault
argument_list|,
name|__to
argument_list|)
return|;
block|}
name|protected
operator|:
name|explicit
name|__ctype_abstract_base
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
operator|:
name|facet
argument_list|(
argument|__refs
argument_list|)
block|{ }
name|virtual
operator|~
name|__ctype_abstract_base
argument_list|()
block|{ }
comment|/**        *  @brief  Test char_type classification.        *        *  This function finds a mask M for @a c and compares it to mask @a m.        *        *  do_is() is a hook for a derived facet to change the behavior of        *  classifying.  do_is() must always return the same result for the        *  same input.        *        *  @param c  The char_type to find the mask of.        *  @param m  The mask to compare against.        *  @return  (M& m) != 0.       */
name|virtual
name|bool
name|do_is
argument_list|(
argument|mask __m
argument_list|,
argument|char_type __c
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return a mask array.        *        *  This function finds the mask for each char_type in the range [lo,hi)        *  and successively writes it to vec.  vec must have as many elements        *  as the input.        *        *  do_is() is a hook for a derived facet to change the behavior of        *  classifying.  do_is() must always return the same result for the        *  same input.        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @param vec  Pointer to an array of mask storage.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_is
argument_list|(
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|,
name|mask
operator|*
name|__vec
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find char_type matching mask        *        *  This function searches for and returns the first char_type c in        *  [lo,hi) for which is(m,c) is true.        *        *  do_scan_is() is a hook for a derived facet to change the behavior of        *  match searching.  do_is() must always return the same result for the        *  same input.        *        *  @param m  The mask to compare against.        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @return  Pointer to a matching char_type if found, else @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_scan_is
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find char_type not matching mask        *        *  This function searches for and returns a pointer to the first        *  char_type c of [lo,hi) for which is(m,c) is false.        *        *  do_scan_is() is a hook for a derived facet to change the behavior of        *  match searching.  do_is() must always return the same result for the        *  same input.        *        *  @param m  The mask to compare against.        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @return  Pointer to a non-matching char_type if found, else @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_scan_not
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Convert to uppercase.        *        *  This virtual function converts the char_type argument to uppercase        *  if possible.  If not possible (for example, '2'), returns the        *  argument.        *        *  do_toupper() is a hook for a derived facet to change the behavior of        *  uppercasing.  do_toupper() must always return the same result for        *  the same input.        *        *  @param c  The char_type to convert.        *  @return  The uppercase char_type if convertible, else @a c.       */
end_comment

begin_decl_stmt
name|virtual
name|char_type
name|do_toupper
argument_list|(
name|char_type
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Convert array to uppercase.        *        *  This virtual function converts each char_type in the range [lo,hi)        *  to uppercase if possible.  Other elements remain untouched.        *        *  do_toupper() is a hook for a derived facet to change the behavior of        *  uppercasing.  do_toupper() must always return the same result for        *  the same input.        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_toupper
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Convert to lowercase.        *        *  This virtual function converts the argument to lowercase if        *  possible.  If not possible (for example, '2'), returns the argument.        *        *  do_tolower() is a hook for a derived facet to change the behavior of        *  lowercasing.  do_tolower() must always return the same result for        *  the same input.        *        *  @param c  The char_type to convert.        *  @return  The lowercase char_type if convertible, else @a c.       */
end_comment

begin_decl_stmt
name|virtual
name|char_type
name|do_tolower
argument_list|(
name|char_type
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Convert array to lowercase.        *        *  This virtual function converts each char_type in the range [lo,hi)        *  to lowercase if possible.  Other elements remain untouched.        *        *  do_tolower() is a hook for a derived facet to change the behavior of        *  lowercasing.  do_tolower() must always return the same result for        *  the same input.        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_tolower
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Widen char        *        *  This virtual function converts the char to char_type using the        *  simplest reasonable transformation.        *        *  do_widen() is a hook for a derived facet to change the behavior of        *  widening.  do_widen() must always return the same result for the        *  same input.        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param c  The char to convert.        *  @return  The converted char_type       */
end_comment

begin_decl_stmt
name|virtual
name|char_type
name|do_widen
argument_list|(
name|char
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Widen char array        *        *  This function converts each char in the input to char_type using the        *  simplest reasonable transformation.        *        *  do_widen() is a hook for a derived facet to change the behavior of        *  widening.  do_widen() must always return the same result for the        *  same input.        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param lo  Pointer to start range.        *  @param hi  Pointer to end of range.        *  @param to  Pointer to the destination array.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char
modifier|*
name|do_widen
argument_list|(
specifier|const
name|char
operator|*
name|__lo
argument_list|,
specifier|const
name|char
operator|*
name|__hi
argument_list|,
name|char_type
operator|*
name|__dest
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Narrow char_type to char        *        *  This virtual function converts the argument to char using the        *  simplest reasonable transformation.  If the conversion fails, dfault        *  is returned instead.        *        *  do_narrow() is a hook for a derived facet to change the behavior of        *  narrowing.  do_narrow() must always return the same result for the        *  same input.        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param c  The char_type to convert.        *  @param dfault  Char to return if conversion fails.        *  @return  The converted char.       */
end_comment

begin_decl_stmt
name|virtual
name|char
name|do_narrow
argument_list|(
name|char_type
argument_list|,
name|char
name|__dfault
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Narrow char_type array to char        *        *  This virtual function converts each char_type in the range [lo,hi) to        *  char using the simplest reasonable transformation and writes the        *  results to the destination array.  For any element in the input that        *  cannot be converted, @a dfault is used instead.        *        *  do_narrow() is a hook for a derived facet to change the behavior of        *  narrowing.  do_narrow() must always return the same result for the        *  same input.        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @param dfault  Char to use if conversion fails.        *  @param to  Pointer to the destination array.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_narrow
argument_list|(
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|,
name|char
name|__dfault
argument_list|,
name|char
operator|*
name|__dest
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// NB: Generic, mostly useless implementation.
end_comment

begin_comment
comment|/**    *  @brief  Template ctype facet    *    *  This template class defines classification and conversion functions for    *  character sets.  It wraps<cctype> functionality.  Ctype gets used by    *  streams for many I/O operations.    *    *  This template provides the protected virtual functions the developer    *  will have to replace in a derived class or specialization to make a    *  working facet.  The public functions that access them are defined in    *  __ctype_abstract_base, to allow for implementation flexibility.  See    *  ctype<wchar_t> for an example.  The functions are documented in    *  __ctype_abstract_base.    *    *  Note: implementations are provided for all the protected virtual    *  functions, but will likely not be useful.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|ctype
operator|:
name|public
name|__ctype_abstract_base
operator|<
name|_CharT
operator|>
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|__ctype_abstract_base
operator|<
name|_CharT
operator|>
operator|::
name|mask
name|mask
expr_stmt|;
end_typedef

begin_comment
comment|/// The facet id for ctype<char_type>
end_comment

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_macro
name|explicit
end_macro

begin_macro
name|ctype
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|__ctype_abstract_base
operator|<
name|_CharT
operator|>
operator|(
name|__refs
operator|)
block|{ }
name|protected
operator|:
name|virtual
operator|~
name|ctype
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|bool
name|do_is
argument_list|(
name|mask
name|__m
argument_list|,
name|char_type
name|__c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_is
argument_list|(
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|,
name|mask
operator|*
name|__vec
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_scan_is
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_scan_not
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char_type
name|do_toupper
argument_list|(
name|char_type
name|__c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_toupper
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char_type
name|do_tolower
argument_list|(
name|char_type
name|__c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_tolower
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char_type
name|do_widen
argument_list|(
name|char
name|__c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char
modifier|*
name|do_widen
argument_list|(
specifier|const
name|char
operator|*
name|__lo
argument_list|,
specifier|const
name|char
operator|*
name|__hi
argument_list|,
name|char_type
operator|*
name|__dest
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char
name|do_narrow
argument_list|(
name|char_type
argument_list|,
name|char
name|__dfault
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_narrow
argument_list|(
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|,
name|char
name|__dfault
argument_list|,
name|char
operator|*
name|__dest
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|>
name|locale
operator|::
name|id
name|ctype
operator|<
name|_CharT
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|// 22.2.1.3  ctype<char> specialization.
end_comment

begin_comment
comment|/**    *  @brief  The ctype<char> specialization.    *    *  This class defines classification and conversion functions for    *  the char type.  It gets used by char streams for many I/O    *  operations.  The char specialization provides a number of    *  optimizations as well.   */
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|ctype
operator|<
name|char
operator|>
operator|:
name|public
name|locale
operator|::
name|facet
operator|,
name|public
name|ctype_base
block|{
name|public
operator|:
comment|// Types:
comment|/// Typedef for the template parameter char.
typedef|typedef
name|char
name|char_type
typedef|;
name|protected
operator|:
comment|// Data Members:
name|__c_locale
name|_M_c_locale_ctype
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|_M_del
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__to_type
name|_M_toupper
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__to_type
name|_M_tolower
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|mask
modifier|*
name|_M_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mutable
name|char
name|_M_widen_ok
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mutable
name|char
name|_M_widen
index|[
literal|1
operator|+
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
operator|-
literal|1
operator|)
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mutable
name|char
name|_M_narrow
index|[
literal|1
operator|+
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
operator|-
literal|1
operator|)
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mutable
name|char
name|_M_narrow_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|// 0 uninitialized, 1 init,
end_comment

begin_comment
comment|// 2 memcpy can't be used
end_comment

begin_label
name|public
label|:
end_label

begin_comment
comment|/// The facet id for ctype<char>
end_comment

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The size of the mask table.  It is SCHAR_MAX + 1.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|size_t
name|table_size
init|=
literal|1
operator|+
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
operator|-
literal|1
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Constructor performs initialization.        *        *  This is the constructor provided by the standard.        *        *  @param table If non-zero, table is used as the per-char mask.        *               Else classic_table() is used.        *  @param del   If true, passes ownership of table to this facet.        *  @param refs  Passed to the base facet class.       */
end_comment

begin_function_decl
name|explicit
name|ctype
parameter_list|(
specifier|const
name|mask
modifier|*
name|__table
init|=
literal|0
parameter_list|,
name|bool
name|__del
init|=
name|false
parameter_list|,
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Constructor performs static initialization.        *        *  This constructor is used to construct the initial C locale facet.        *        *  @param cloc  Handle to C locale data.        *  @param table If non-zero, table is used as the per-char mask.        *  @param del   If true, passes ownership of table to this facet.        *  @param refs  Passed to the base facet class.       */
end_comment

begin_function_decl
name|explicit
name|ctype
parameter_list|(
name|__c_locale
name|__cloc
parameter_list|,
specifier|const
name|mask
modifier|*
name|__table
init|=
literal|0
parameter_list|,
name|bool
name|__del
init|=
name|false
parameter_list|,
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Test char classification.        *        *  This function compares the mask table[c] to @a m.        *        *  @param c  The char to compare the mask of.        *  @param m  The mask to compare against.        *  @return  True if m& table[c] is true, false otherwise.       */
end_comment

begin_decl_stmt
specifier|inline
name|bool
name|is
argument_list|(
name|mask
name|__m
argument_list|,
name|char
name|__c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Return a mask array.        *        *  This function finds the mask for each char in the range [lo, hi) and        *  successively writes it to vec.  vec must have as many elements as        *  the char array.        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @param vec  Pointer to an array of mask storage.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
specifier|inline
specifier|const
name|char
modifier|*
name|is
argument_list|(
specifier|const
name|char
operator|*
name|__lo
argument_list|,
specifier|const
name|char
operator|*
name|__hi
argument_list|,
name|mask
operator|*
name|__vec
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find char matching a mask        *        *  This function searches for and returns the first char in [lo,hi) for        *  which is(m,char) is true.        *        *  @param m  The mask to compare against.        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @return  Pointer to a matching char if found, else @a hi.       */
end_comment

begin_decl_stmt
specifier|inline
specifier|const
name|char
modifier|*
name|scan_is
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char
operator|*
name|__lo
argument_list|,
specifier|const
name|char
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find char not matching a mask        *        *  This function searches for and returns a pointer to the first char        *  in [lo,hi) for which is(m,char) is false.        *        *  @param m  The mask to compare against.        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @return  Pointer to a non-matching char if found, else @a hi.       */
end_comment

begin_decl_stmt
specifier|inline
specifier|const
name|char
modifier|*
name|scan_not
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char
operator|*
name|__lo
argument_list|,
specifier|const
name|char
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Convert to uppercase.        *        *  This function converts the char argument to uppercase if possible.        *  If not possible (for example, '2'), returns the argument.        *        *  toupper() acts as if it returns ctype<char>::do_toupper(c).        *  do_toupper() must always return the same result for the same input.        *        *  @param c  The char to convert.        *  @return  The uppercase char if convertible, else @a c.       */
end_comment

begin_decl_stmt
name|char_type
name|toupper
argument_list|(
name|char_type
name|__c
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_toupper
argument_list|(
name|__c
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Convert array to uppercase.        *        *  This function converts each char in the range [lo,hi) to uppercase        *  if possible.  Other chars remain untouched.        *        *  toupper() acts as if it returns ctype<char>:: do_toupper(lo, hi).        *  do_toupper() must always return the same result for the same input.        *        *  @param lo  Pointer to first char in range.        *  @param hi  Pointer to end of range.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
specifier|const
name|char_type
modifier|*
name|toupper
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_toupper
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Convert to lowercase.        *        *  This function converts the char argument to lowercase if possible.        *  If not possible (for example, '2'), returns the argument.        *        *  tolower() acts as if it returns ctype<char>::do_tolower(c).        *  do_tolower() must always return the same result for the same input.        *        *  @param c  The char to convert.        *  @return  The lowercase char if convertible, else @a c.       */
end_comment

begin_decl_stmt
name|char_type
name|tolower
argument_list|(
name|char_type
name|__c
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_tolower
argument_list|(
name|__c
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Convert array to lowercase.        *        *  This function converts each char in the range [lo,hi) to lowercase        *  if possible.  Other chars remain untouched.        *        *  tolower() acts as if it returns ctype<char>:: do_tolower(lo, hi).        *  do_tolower() must always return the same result for the same input.        *        *  @param lo  Pointer to first char in range.        *  @param hi  Pointer to end of range.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
specifier|const
name|char_type
modifier|*
name|tolower
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_tolower
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Widen char        *        *  This function converts the char to char_type using the simplest        *  reasonable transformation.  For an underived ctype<char> facet, the        *  argument will be returned unchanged.        *        *  This function works as if it returns ctype<char>::do_widen(c).        *  do_widen() must always return the same result for the same input.        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param c  The char to convert.        *  @return  The converted character.       */
end_comment

begin_decl_stmt
name|char_type
name|widen
argument_list|(
name|char
name|__c
argument_list|)
decl|const
block|{
if|if
condition|(
name|_M_widen_ok
condition|)
return|return
name|_M_widen
index|[
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
name|__c
operator|)
index|]
return|;
name|this
operator|->
name|_M_widen_init
argument_list|()
expr_stmt|;
return|return
name|this
operator|->
name|do_widen
argument_list|(
name|__c
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Widen char array        *        *  This function converts each char in the input to char using the        *  simplest reasonable transformation.  For an underived ctype<char>        *  facet, the argument will be copied unchanged.        *        *  This function works as if it returns ctype<char>::do_widen(c).        *  do_widen() must always return the same result for the same input.        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param lo  Pointer to first char in range.        *  @param hi  Pointer to end of range.        *  @param to  Pointer to the destination array.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|widen
argument_list|(
specifier|const
name|char
operator|*
name|__lo
argument_list|,
specifier|const
name|char
operator|*
name|__hi
argument_list|,
name|char_type
operator|*
name|__to
argument_list|)
decl|const
block|{
if|if
condition|(
name|_M_widen_ok
operator|==
literal|1
condition|)
block|{
name|memcpy
argument_list|(
name|__to
argument_list|,
name|__lo
argument_list|,
name|__hi
operator|-
name|__lo
argument_list|)
expr_stmt|;
return|return
name|__hi
return|;
block|}
if|if
condition|(
operator|!
name|_M_widen_ok
condition|)
name|_M_widen_init
argument_list|()
expr_stmt|;
return|return
name|this
operator|->
name|do_widen
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|,
name|__to
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Narrow char        *        *  This function converts the char to char using the simplest        *  reasonable transformation.  If the conversion fails, dfault is        *  returned instead.  For an underived ctype<char> facet, @a c        *  will be returned unchanged.        *        *  This function works as if it returns ctype<char>::do_narrow(c).        *  do_narrow() must always return the same result for the same input.        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param c  The char to convert.        *  @param dfault  Char to return if conversion fails.        *  @return  The converted character.       */
end_comment

begin_decl_stmt
name|char
name|narrow
argument_list|(
name|char_type
name|__c
argument_list|,
name|char
name|__dfault
argument_list|)
decl|const
block|{
if|if
condition|(
name|_M_narrow
index|[
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
name|__c
operator|)
index|]
condition|)
return|return
name|_M_narrow
index|[
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
name|__c
operator|)
index|]
return|;
specifier|const
name|char
name|__t
init|=
name|do_narrow
argument_list|(
name|__c
argument_list|,
name|__dfault
argument_list|)
decl_stmt|;
if|if
condition|(
name|__t
operator|!=
name|__dfault
condition|)
name|_M_narrow
index|[
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
name|__c
operator|)
index|]
operator|=
name|__t
expr_stmt|;
return|return
name|__t
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Narrow char array        *        *  This function converts each char in the input to char using the        *  simplest reasonable transformation and writes the results to the        *  destination array.  For any char in the input that cannot be        *  converted, @a dfault is used instead.  For an underived ctype<char>        *  facet, the argument will be copied unchanged.        *        *  This function works as if it returns ctype<char>::do_narrow(lo, hi,        *  dfault, to).  do_narrow() must always return the same result for the        *  same input.        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @param dfault  Char to use if conversion fails.        *  @param to  Pointer to the destination array.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
specifier|const
name|char_type
modifier|*
name|narrow
argument_list|(
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|,
name|char
name|__dfault
argument_list|,
name|char
operator|*
name|__to
argument_list|)
decl|const
block|{
if|if
condition|(
name|__builtin_expect
argument_list|(
name|_M_narrow_ok
operator|==
literal|1
argument_list|,
name|true
argument_list|)
condition|)
block|{
name|memcpy
argument_list|(
name|__to
argument_list|,
name|__lo
argument_list|,
name|__hi
operator|-
name|__lo
argument_list|)
expr_stmt|;
return|return
name|__hi
return|;
block|}
if|if
condition|(
operator|!
name|_M_narrow_ok
condition|)
name|_M_narrow_init
argument_list|()
expr_stmt|;
return|return
name|this
operator|->
name|do_narrow
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|,
name|__dfault
argument_list|,
name|__to
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// Returns a pointer to the mask table provided to the constructor, or
end_comment

begin_comment
comment|/// the default from classic_table() if none was provided.
end_comment

begin_expr_stmt
specifier|const
name|mask
operator|*
name|table
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
name|_M_table
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns a pointer to the C locale mask table.
end_comment

begin_function_decl
specifier|static
specifier|const
name|mask
modifier|*
name|classic_table
parameter_list|()
function_decl|throw
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Destructor.        *        *  This function deletes table() if @a del was true in the        *  constructor.       */
end_comment

begin_expr_stmt
name|virtual
operator|~
name|ctype
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Convert to uppercase.        *        *  This virtual function converts the char argument to uppercase if        *  possible.  If not possible (for example, '2'), returns the argument.        *        *  do_toupper() is a hook for a derived facet to change the behavior of        *  uppercasing.  do_toupper() must always return the same result for        *  the same input.        *        *  @param c  The char to convert.        *  @return  The uppercase char if convertible, else @a c.       */
end_comment

begin_decl_stmt
name|virtual
name|char_type
name|do_toupper
argument_list|(
name|char_type
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Convert array to uppercase.        *        *  This virtual function converts each char in the range [lo,hi) to        *  uppercase if possible.  Other chars remain untouched.        *        *  do_toupper() is a hook for a derived facet to change the behavior of        *  uppercasing.  do_toupper() must always return the same result for        *  the same input.        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_toupper
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Convert to lowercase.        *        *  This virtual function converts the char argument to lowercase if        *  possible.  If not possible (for example, '2'), returns the argument.        *        *  do_tolower() is a hook for a derived facet to change the behavior of        *  lowercasing.  do_tolower() must always return the same result for        *  the same input.        *        *  @param c  The char to convert.        *  @return  The lowercase char if convertible, else @a c.       */
end_comment

begin_decl_stmt
name|virtual
name|char_type
name|do_tolower
argument_list|(
name|char_type
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Convert array to lowercase.        *        *  This virtual function converts each char in the range [lo,hi) to        *  lowercase if possible.  Other chars remain untouched.        *        *  do_tolower() is a hook for a derived facet to change the behavior of        *  lowercasing.  do_tolower() must always return the same result for        *  the same input.        *        *  @param lo  Pointer to first char in range.        *  @param hi  Pointer to end of range.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_tolower
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Widen char        *        *  This virtual function converts the char to char using the simplest        *  reasonable transformation.  For an underived ctype<char> facet, the        *  argument will be returned unchanged.        *        *  do_widen() is a hook for a derived facet to change the behavior of        *  widening.  do_widen() must always return the same result for the        *  same input.        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param c  The char to convert.        *  @return  The converted character.       */
end_comment

begin_decl_stmt
name|virtual
name|char_type
name|do_widen
argument_list|(
name|char
name|__c
argument_list|)
decl|const
block|{
return|return
name|__c
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Widen char array        *        *  This function converts each char in the range [lo,hi) to char using        *  the simplest reasonable transformation.  For an underived        *  ctype<char> facet, the argument will be copied unchanged.        *        *  do_widen() is a hook for a derived facet to change the behavior of        *  widening.  do_widen() must always return the same result for the        *  same input.        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @param to  Pointer to the destination array.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char
modifier|*
name|do_widen
argument_list|(
specifier|const
name|char
operator|*
name|__lo
argument_list|,
specifier|const
name|char
operator|*
name|__hi
argument_list|,
name|char_type
operator|*
name|__dest
argument_list|)
decl|const
block|{
name|memcpy
argument_list|(
name|__dest
argument_list|,
name|__lo
argument_list|,
name|__hi
operator|-
name|__lo
argument_list|)
expr_stmt|;
return|return
name|__hi
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Narrow char        *        *  This virtual function converts the char to char using the simplest        *  reasonable transformation.  If the conversion fails, dfault is        *  returned instead.  For an underived ctype<char> facet, @a c will be        *  returned unchanged.        *        *  do_narrow() is a hook for a derived facet to change the behavior of        *  narrowing.  do_narrow() must always return the same result for the        *  same input.        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param c  The char to convert.        *  @param dfault  Char to return if conversion fails.        *  @return  The converted char.       */
end_comment

begin_decl_stmt
name|virtual
name|char
name|do_narrow
argument_list|(
name|char_type
name|__c
argument_list|,
name|char
argument_list|)
decl|const
block|{
return|return
name|__c
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Narrow char array to char array        *        *  This virtual function converts each char in the range [lo,hi) to        *  char using the simplest reasonable transformation and writes the        *  results to the destination array.  For any char in the input that        *  cannot be converted, @a dfault is used instead.  For an underived        *  ctype<char> facet, the argument will be copied unchanged.        *        *  do_narrow() is a hook for a derived facet to change the behavior of        *  narrowing.  do_narrow() must always return the same result for the        *  same input.        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @param dfault  Char to use if conversion fails.        *  @param to  Pointer to the destination array.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_narrow
argument_list|(
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|,
name|char
argument_list|,
name|char
operator|*
name|__dest
argument_list|)
decl|const
block|{
name|memcpy
argument_list|(
name|__dest
argument_list|,
name|__lo
argument_list|,
name|__hi
operator|-
name|__lo
argument_list|)
expr_stmt|;
return|return
name|__hi
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|void
name|_M_widen_init
argument_list|()
specifier|const
block|{
name|char
name|__tmp
index|[
sizeof|sizeof
argument_list|(
name|_M_widen
argument_list|)
index|]
block|;
for|for
control|(
name|size_t
name|__i
init|=
literal|0
init|;
name|__i
operator|<
sizeof|sizeof
argument_list|(
name|_M_widen
argument_list|)
condition|;
operator|++
name|__i
control|)
name|__tmp
index|[
name|__i
index|]
operator|=
name|__i
expr_stmt|;
name|do_widen
argument_list|(
name|__tmp
argument_list|,
name|__tmp
operator|+
sizeof|sizeof
argument_list|(
name|__tmp
argument_list|)
argument_list|,
name|_M_widen
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_M_widen_ok
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Set _M_widen_ok to 2 if memcpy can't be used.
end_comment

begin_if
if|if
condition|(
name|memcmp
argument_list|(
name|__tmp
argument_list|,
name|_M_widen
argument_list|,
sizeof|sizeof
argument_list|(
name|_M_widen
argument_list|)
argument_list|)
condition|)
name|_M_widen_ok
operator|=
literal|2
expr_stmt|;
end_if

begin_comment
unit|}
comment|// Fill in the narrowing cache and flag whether all values are
end_comment

begin_comment
comment|// valid or not.  _M_narrow_ok is set to 2 if memcpy can't
end_comment

begin_comment
comment|// be used.
end_comment

begin_macro
unit|void
name|_M_narrow_init
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
name|char
name|__tmp
index|[
sizeof|sizeof
argument_list|(
name|_M_narrow
argument_list|)
index|]
block|;
for|for
control|(
name|size_t
name|__i
init|=
literal|0
init|;
name|__i
operator|<
sizeof|sizeof
argument_list|(
name|_M_narrow
argument_list|)
condition|;
operator|++
name|__i
control|)
name|__tmp
index|[
name|__i
index|]
operator|=
name|__i
expr_stmt|;
name|do_narrow
argument_list|(
name|__tmp
argument_list|,
name|__tmp
operator|+
sizeof|sizeof
argument_list|(
name|__tmp
argument_list|)
argument_list|,
literal|0
argument_list|,
name|_M_narrow
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_M_narrow_ok
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|memcmp
argument_list|(
name|__tmp
argument_list|,
name|_M_narrow
argument_list|,
sizeof|sizeof
argument_list|(
name|_M_narrow
argument_list|)
argument_list|)
condition|)
name|_M_narrow_ok
operator|=
literal|2
expr_stmt|;
else|else
block|{
comment|// Deal with the special case of zero: renarrow with a
comment|// different default and compare.
name|char
name|__c
decl_stmt|;
name|do_narrow
argument_list|(
name|__tmp
argument_list|,
name|__tmp
operator|+
literal|1
argument_list|,
literal|1
argument_list|,
operator|&
name|__c
argument_list|)
expr_stmt|;
if|if
condition|(
name|__c
operator|==
literal|1
condition|)
name|_M_narrow_ok
operator|=
literal|2
expr_stmt|;
block|}
end_if

begin_empty_stmt
unit|}     }
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
specifier|const
name|ctype
operator|<
name|char
operator|>
operator|&
name|use_facet
operator|<
name|ctype
operator|<
name|char
operator|>
expr|>
operator|(
specifier|const
name|locale
operator|&
name|__loc
operator|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
end_ifdef

begin_comment
comment|// 22.2.1.3  ctype<wchar_t> specialization
end_comment

begin_comment
comment|/**    *  @brief  The ctype<wchar_t> specialization.    *    *  This class defines classification and conversion functions for the    *  wchar_t type.  It gets used by wchar_t streams for many I/O operations.    *  The wchar_t specialization provides a number of optimizations as well.    *    *  ctype<wchar_t> inherits its public methods from    *  __ctype_abstract_base<wchar_t>.   */
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|ctype
operator|<
name|wchar_t
operator|>
operator|:
name|public
name|__ctype_abstract_base
operator|<
name|wchar_t
operator|>
block|{
name|public
operator|:
comment|// Types:
comment|/// Typedef for the template parameter wchar_t.
typedef|typedef
name|wchar_t
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|wctype_t
name|__wmask_type
typedef|;
end_typedef

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|__c_locale
name|_M_c_locale_ctype
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Pre-computed narrowed and widened chars.
end_comment

begin_decl_stmt
name|bool
name|_M_narrow_ok
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|_M_narrow
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|wint_t
name|_M_widen
index|[
literal|1
operator|+
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
operator|-
literal|1
operator|)
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Pre-computed elements for do_is.
end_comment

begin_decl_stmt
name|mask
name|_M_bit
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__wmask_type
name|_M_wmask
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|// Data Members:
end_comment

begin_comment
comment|/// The facet id for ctype<wchar_t>
end_comment

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Constructor performs initialization.        *        *  This is the constructor provided by the standard.        *        *  @param refs  Passed to the base facet class.       */
end_comment

begin_function_decl
name|explicit
name|ctype
parameter_list|(
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Constructor performs static initialization.        *        *  This constructor is used to construct the initial C locale facet.        *        *  @param cloc  Handle to C locale data.        *  @param refs  Passed to the base facet class.       */
end_comment

begin_function_decl
name|explicit
name|ctype
parameter_list|(
name|__c_locale
name|__cloc
parameter_list|,
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|__wmask_type
name|_M_convert_to_wmask
argument_list|(
specifier|const
name|mask
name|__m
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Destructor
end_comment

begin_expr_stmt
name|virtual
operator|~
name|ctype
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Test wchar_t classification.        *        *  This function finds a mask M for @a c and compares it to mask @a m.        *        *  do_is() is a hook for a derived facet to change the behavior of        *  classifying.  do_is() must always return the same result for the        *  same input.        *        *  @param c  The wchar_t to find the mask of.        *  @param m  The mask to compare against.        *  @return  (M& m) != 0.       */
end_comment

begin_decl_stmt
name|virtual
name|bool
name|do_is
argument_list|(
name|mask
name|__m
argument_list|,
name|char_type
name|__c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Return a mask array.        *        *  This function finds the mask for each wchar_t in the range [lo,hi)        *  and successively writes it to vec.  vec must have as many elements        *  as the input.        *        *  do_is() is a hook for a derived facet to change the behavior of        *  classifying.  do_is() must always return the same result for the        *  same input.        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @param vec  Pointer to an array of mask storage.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_is
argument_list|(
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|,
name|mask
operator|*
name|__vec
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find wchar_t matching mask        *        *  This function searches for and returns the first wchar_t c in        *  [lo,hi) for which is(m,c) is true.        *        *  do_scan_is() is a hook for a derived facet to change the behavior of        *  match searching.  do_is() must always return the same result for the        *  same input.        *        *  @param m  The mask to compare against.        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @return  Pointer to a matching wchar_t if found, else @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_scan_is
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Find wchar_t not matching mask        *        *  This function searches for and returns a pointer to the first        *  wchar_t c of [lo,hi) for which is(m,c) is false.        *        *  do_scan_is() is a hook for a derived facet to change the behavior of        *  match searching.  do_is() must always return the same result for the        *  same input.        *        *  @param m  The mask to compare against.        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @return  Pointer to a non-matching wchar_t if found, else @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_scan_not
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Convert to uppercase.        *        *  This virtual function converts the wchar_t argument to uppercase if        *  possible.  If not possible (for example, '2'), returns the argument.        *        *  do_toupper() is a hook for a derived facet to change the behavior of        *  uppercasing.  do_toupper() must always return the same result for        *  the same input.        *        *  @param c  The wchar_t to convert.        *  @return  The uppercase wchar_t if convertible, else @a c.       */
end_comment

begin_decl_stmt
name|virtual
name|char_type
name|do_toupper
argument_list|(
name|char_type
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Convert array to uppercase.        *        *  This virtual function converts each wchar_t in the range [lo,hi) to        *  uppercase if possible.  Other elements remain untouched.        *        *  do_toupper() is a hook for a derived facet to change the behavior of        *  uppercasing.  do_toupper() must always return the same result for        *  the same input.        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_toupper
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Convert to lowercase.        *        *  This virtual function converts the argument to lowercase if        *  possible.  If not possible (for example, '2'), returns the argument.        *        *  do_tolower() is a hook for a derived facet to change the behavior of        *  lowercasing.  do_tolower() must always return the same result for        *  the same input.        *        *  @param c  The wchar_t to convert.        *  @return  The lowercase wchar_t if convertible, else @a c.       */
end_comment

begin_decl_stmt
name|virtual
name|char_type
name|do_tolower
argument_list|(
name|char_type
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Convert array to lowercase.        *        *  This virtual function converts each wchar_t in the range [lo,hi) to        *  lowercase if possible.  Other elements remain untouched.        *        *  do_tolower() is a hook for a derived facet to change the behavior of        *  lowercasing.  do_tolower() must always return the same result for        *  the same input.        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_tolower
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Widen char to wchar_t        *        *  This virtual function converts the char to wchar_t using the        *  simplest reasonable transformation.  For an underived ctype<wchar_t>        *  facet, the argument will be cast to wchar_t.        *        *  do_widen() is a hook for a derived facet to change the behavior of        *  widening.  do_widen() must always return the same result for the        *  same input.        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param c  The char to convert.        *  @return  The converted wchar_t.       */
end_comment

begin_decl_stmt
name|virtual
name|char_type
name|do_widen
argument_list|(
name|char
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Widen char array to wchar_t array        *        *  This function converts each char in the input to wchar_t using the        *  simplest reasonable transformation.  For an underived ctype<wchar_t>        *  facet, the argument will be copied, casting each element to wchar_t.        *        *  do_widen() is a hook for a derived facet to change the behavior of        *  widening.  do_widen() must always return the same result for the        *  same input.        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param lo  Pointer to start range.        *  @param hi  Pointer to end of range.        *  @param to  Pointer to the destination array.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char
modifier|*
name|do_widen
argument_list|(
specifier|const
name|char
operator|*
name|__lo
argument_list|,
specifier|const
name|char
operator|*
name|__hi
argument_list|,
name|char_type
operator|*
name|__dest
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Narrow wchar_t to char        *        *  This virtual function converts the argument to char using        *  the simplest reasonable transformation.  If the conversion        *  fails, dfault is returned instead.  For an underived        *  ctype<wchar_t> facet, @a c will be cast to char and        *  returned.        *        *  do_narrow() is a hook for a derived facet to change the        *  behavior of narrowing.  do_narrow() must always return the        *  same result for the same input.        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param c  The wchar_t to convert.        *  @param dfault  Char to return if conversion fails.        *  @return  The converted char.       */
end_comment

begin_decl_stmt
name|virtual
name|char
name|do_narrow
argument_list|(
name|char_type
argument_list|,
name|char
name|__dfault
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Narrow wchar_t array to char array        *        *  This virtual function converts each wchar_t in the range [lo,hi) to        *  char using the simplest reasonable transformation and writes the        *  results to the destination array.  For any wchar_t in the input that        *  cannot be converted, @a dfault is used instead.  For an underived        *  ctype<wchar_t> facet, the argument will be copied, casting each        *  element to char.        *        *  do_narrow() is a hook for a derived facet to change the behavior of        *  narrowing.  do_narrow() must always return the same result for the        *  same input.        *        *  Note: this is not what you want for codepage conversions.  See        *  codecvt for that.        *        *  @param lo  Pointer to start of range.        *  @param hi  Pointer to end of range.        *  @param dfault  Char to use if conversion fails.        *  @param to  Pointer to the destination array.        *  @return  @a hi.       */
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_narrow
argument_list|(
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|,
name|char
name|__dfault
argument_list|,
name|char
operator|*
name|__dest
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// For use at construction time only.
end_comment

begin_function_decl
name|void
name|_M_initialize_ctype
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
specifier|const
name|ctype
operator|<
name|wchar_t
operator|>
operator|&
name|use_facet
operator|<
name|ctype
operator|<
name|wchar_t
operator|>
expr|>
operator|(
specifier|const
name|locale
operator|&
name|__loc
operator|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//_GLIBCXX_USE_WCHAR_T
end_comment

begin_comment
comment|/// @brief  class ctype_byname [22.2.1.2].
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|ctype_byname
operator|:
name|public
name|ctype
operator|<
name|_CharT
operator|>
block|{
name|public
operator|:
typedef|typedef
name|_CharT
name|char_type
typedef|;
name|explicit
name|ctype_byname
argument_list|(
argument|const char* __s
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|ctype_byname
argument_list|()
block|{ }
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// 22.2.1.4  Class ctype_byname specializations.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|ctype_byname
operator|<
name|char
operator|>
operator|::
name|ctype_byname
argument_list|(
argument|const char*
argument_list|,
argument|size_t refs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|ctype_byname
operator|<
name|wchar_t
operator|>
operator|::
name|ctype_byname
argument_list|(
argument|const char*
argument_list|,
argument|size_t refs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|_GLIBCXX_END_NAMESPACE
comment|// Include host and configuration specific ctype inlines.
include|#
directive|include
file|<bits/ctype_inline.h>
comment|// 22.2.1.5  Template class codecvt
include|#
directive|include
file|<bits/codecvt.h>
name|_GLIBCXX_BEGIN_NAMESPACE
parameter_list|(
name|std
parameter_list|)
comment|// 22.2.2  The numeric category.
name|class
name|__num_base
decl_stmt|{   public:
comment|// NB: Code depends on the order of _S_atoms_out elements.
comment|// Below are the indices into _S_atoms_out.
decl_stmt|enum
block|{
name|_S_ominus
operator|,
name|_S_oplus
operator|,
name|_S_ox
operator|,
name|_S_oX
operator|,
name|_S_odigits
operator|,
name|_S_odigits_end
operator|=
name|_S_odigits
operator|+
literal|16
operator|,
name|_S_oudigits
operator|=
name|_S_odigits_end
operator|,
name|_S_oudigits_end
operator|=
name|_S_oudigits
operator|+
literal|16
operator|,
name|_S_oe
operator|=
name|_S_odigits
operator|+
literal|14
operator|,
comment|// For scientific notation, 'e'
name|_S_oE
operator|=
name|_S_oudigits
operator|+
literal|14
operator|,
comment|// For scientific notation, 'E'
name|_S_oend
operator|=
name|_S_oudigits_end
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// A list of valid numeric literals for output.  This array
end_comment

begin_comment
comment|// contains chars that will be passed through the current locale's
end_comment

begin_comment
comment|// ctype<_CharT>.widen() and then used to render numbers.
end_comment

begin_comment
comment|// For the standard "C" locale, this is
end_comment

begin_comment
comment|// "-+xX0123456789abcdef0123456789ABCDEF".
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|_S_atoms_out
decl_stmt|;
end_decl_stmt

begin_comment
comment|// String literal of acceptable (narrow) input, for num_get.
end_comment

begin_comment
comment|// "-+xX0123456789abcdefABCDEF"
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|_S_atoms_in
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
block|{
name|_S_iminus
block|,
name|_S_iplus
block|,
name|_S_ix
block|,
name|_S_iX
block|,
name|_S_izero
block|,
name|_S_ie
init|=
name|_S_izero
operator|+
literal|14
block|,
name|_S_iE
init|=
name|_S_izero
operator|+
literal|20
block|,
name|_S_iend
init|=
literal|26
block|}
enum|;
end_enum

begin_comment
comment|// num_put
end_comment

begin_comment
comment|// Construct and return valid scanf format for floating point types.
end_comment

begin_function_decl
specifier|static
name|void
name|_S_format_float
parameter_list|(
specifier|const
name|ios_base
modifier|&
name|__io
parameter_list|,
name|char
modifier|*
name|__fptr
parameter_list|,
name|char
name|__mod
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|>
expr|struct
name|__numpunct_cache
operator|:
name|public
name|locale
operator|::
name|facet
block|{
specifier|const
name|char
operator|*
name|_M_grouping
block|;
name|size_t
name|_M_grouping_size
block|;
name|bool
name|_M_use_grouping
block|;
specifier|const
name|_CharT
operator|*
name|_M_truename
block|;
name|size_t
name|_M_truename_size
block|;
specifier|const
name|_CharT
operator|*
name|_M_falsename
block|;
name|size_t
name|_M_falsename_size
block|;
name|_CharT
name|_M_decimal_point
block|;
name|_CharT
name|_M_thousands_sep
block|;
comment|// A list of valid numeric literals for output: in the standard
comment|// "C" locale, this is "-+xX0123456789abcdef0123456789ABCDEF".
comment|// This array contains the chars after having been passed
comment|// through the current locale's ctype<_CharT>.widen().
name|_CharT
name|_M_atoms_out
index|[
name|__num_base
operator|::
name|_S_oend
index|]
block|;
comment|// A list of valid numeric literals for input: in the standard
comment|// "C" locale, this is "-+xX0123456789abcdefABCDEF"
comment|// This array contains the chars after having been passed
comment|// through the current locale's ctype<_CharT>.widen().
name|_CharT
name|_M_atoms_in
index|[
name|__num_base
operator|::
name|_S_iend
index|]
block|;
name|bool
name|_M_allocated
block|;
name|__numpunct_cache
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
operator|:
name|facet
argument_list|(
name|__refs
argument_list|)
block|,
name|_M_grouping
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_grouping_size
argument_list|(
literal|0
argument_list|)
block|,
name|_M_use_grouping
argument_list|(
name|false
argument_list|)
block|,
name|_M_truename
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_truename_size
argument_list|(
literal|0
argument_list|)
block|,
name|_M_falsename
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_falsename_size
argument_list|(
literal|0
argument_list|)
block|,
name|_M_decimal_point
argument_list|(
name|_CharT
argument_list|()
argument_list|)
block|,
name|_M_thousands_sep
argument_list|(
name|_CharT
argument_list|()
argument_list|)
block|,
name|_M_allocated
argument_list|(
argument|false
argument_list|)
block|{ }
operator|~
name|__numpunct_cache
argument_list|()
block|;
name|void
name|_M_cache
argument_list|(
specifier|const
name|locale
operator|&
name|__loc
argument_list|)
block|;
name|private
operator|:
name|__numpunct_cache
operator|&
name|operator
operator|=
operator|(
specifier|const
name|__numpunct_cache
operator|&
operator|)
block|;
name|explicit
name|__numpunct_cache
argument_list|(
specifier|const
name|__numpunct_cache
operator|&
argument_list|)
block|;     }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|__numpunct_cache
operator|<
name|_CharT
operator|>
operator|::
operator|~
name|__numpunct_cache
argument_list|()
block|{
if|if
condition|(
name|_M_allocated
condition|)
block|{
name|delete
index|[]
name|_M_grouping
decl_stmt|;
name|delete
index|[]
name|_M_truename
decl_stmt|;
name|delete
index|[]
name|_M_falsename
decl_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|/**    *  @brief  Numpunct facet.    *    *  This facet stores several pieces of information related to printing and    *  scanning numbers, such as the decimal point character.  It takes a    *  template parameter specifying the char type.  The numpunct facet is    *  used by streams for many I/O operations involving numbers.    *    *  The numpunct template uses protected virtual functions to provide the    *  actual results.  The public accessors forward the call to the virtual    *  functions.  These virtual functions are hooks for developers to    *  implement the behavior they require from a numpunct facet.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|numpunct
operator|:
name|public
name|locale
operator|::
name|facet
block|{
name|public
operator|:
comment|// Types:
comment|//@{
comment|/// Public typedefs
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_comment
comment|//@}
end_comment

begin_typedef
typedef|typedef
name|__numpunct_cache
operator|<
name|_CharT
operator|>
name|__cache_type
expr_stmt|;
end_typedef

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|__cache_type
modifier|*
name|_M_data
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Numpunct facet id.
end_comment

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Numpunct constructor.        *        *  @param  refs  Refcount to pass to the base class.        */
end_comment

begin_macro
name|explicit
end_macro

begin_macro
name|numpunct
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|facet
argument_list|(
name|__refs
argument_list|)
operator|,
name|_M_data
argument_list|(
argument|NULL
argument_list|)
block|{
name|_M_initialize_numpunct
argument_list|()
block|; }
comment|/**        *  @brief  Internal constructor.  Not for general use.        *        *  This is a constructor for use by the library itself to set up the        *  predefined locale facets.        *        *  @param  cache  __numpunct_cache object.        *  @param  refs  Refcount to pass to the base class.        */
name|explicit
name|numpunct
argument_list|(
argument|__cache_type* __cache
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
operator|:
name|facet
argument_list|(
name|__refs
argument_list|)
operator|,
name|_M_data
argument_list|(
argument|__cache
argument_list|)
block|{
name|_M_initialize_numpunct
argument_list|()
block|; }
comment|/**        *  @brief  Internal constructor.  Not for general use.        *        *  This is a constructor for use by the library itself to set up new        *  locales.        *        *  @param  cloc  The "C" locale.        *  @param  refs  Refcount to pass to the base class.        */
name|explicit
name|numpunct
argument_list|(
argument|__c_locale __cloc
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
operator|:
name|facet
argument_list|(
name|__refs
argument_list|)
operator|,
name|_M_data
argument_list|(
argument|NULL
argument_list|)
block|{
name|_M_initialize_numpunct
argument_list|(
name|__cloc
argument_list|)
block|; }
comment|/**        *  @brief  Return decimal point character.        *        *  This function returns a char_type to use as a decimal point.  It        *  does so by returning returning        *  numpunct<char_type>::do_decimal_point().        *        *  @return  @a char_type representing a decimal point.       */
name|char_type
name|decimal_point
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_decimal_point
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return thousands separator character.        *        *  This function returns a char_type to use as a thousands        *  separator.  It does so by returning returning        *  numpunct<char_type>::do_thousands_sep().        *        *  @return  char_type representing a thousands separator.       */
end_comment

begin_expr_stmt
name|char_type
name|thousands_sep
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_thousands_sep
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return grouping specification.        *        *  This function returns a string representing groupings for the        *  integer part of a number.  Groupings indicate where thousands        *  separators should be inserted in the integer part of a number.        *        *  Each char in the return string is interpret as an integer        *  rather than a character.  These numbers represent the number        *  of digits in a group.  The first char in the string        *  represents the number of digits in the least significant        *  group.  If a char is negative, it indicates an unlimited        *  number of digits for the group.  If more chars from the        *  string are required to group a number, the last char is used        *  repeatedly.        *        *  For example, if the grouping() returns "\003\002" and is        *  applied to the number 123456789, this corresponds to        *  12,34,56,789.  Note that if the string was "32", this would        *  put more than 50 digits into the least significant group if        *  the character set is ASCII.        *        *  The string is returned by calling        *  numpunct<char_type>::do_grouping().        *        *  @return  string representing grouping specification.       */
end_comment

begin_expr_stmt
name|string
name|grouping
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_grouping
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return string representation of bool true.        *        *  This function returns a string_type containing the text        *  representation for true bool variables.  It does so by calling        *  numpunct<char_type>::do_truename().        *        *  @return  string_type representing printed form of true.       */
end_comment

begin_expr_stmt
name|string_type
name|truename
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_truename
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return string representation of bool false.        *        *  This function returns a string_type containing the text        *  representation for false bool variables.  It does so by calling        *  numpunct<char_type>::do_falsename().        *        *  @return  string_type representing printed form of false.       */
end_comment

begin_expr_stmt
name|string_type
name|falsename
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_falsename
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// Destructor.
end_comment

begin_expr_stmt
name|virtual
operator|~
name|numpunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return decimal point character.        *        *  Returns a char_type to use as a decimal point.  This function is a        *  hook for derived classes to change the value returned.        *        *  @return  @a char_type representing a decimal point.       */
end_comment

begin_expr_stmt
name|virtual
name|char_type
name|do_decimal_point
argument_list|()
specifier|const
block|{
return|return
name|_M_data
operator|->
name|_M_decimal_point
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return thousands separator character.        *        *  Returns a char_type to use as a thousands separator.  This function        *  is a hook for derived classes to change the value returned.        *        *  @return  @a char_type representing a thousands separator.       */
end_comment

begin_expr_stmt
name|virtual
name|char_type
name|do_thousands_sep
argument_list|()
specifier|const
block|{
return|return
name|_M_data
operator|->
name|_M_thousands_sep
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return grouping specification.        *        *  Returns a string representing groupings for the integer part of a        *  number.  This function is a hook for derived classes to change the        *  value returned.  @see grouping() for details.        *        *  @return  String representing grouping specification.       */
end_comment

begin_expr_stmt
name|virtual
name|string
name|do_grouping
argument_list|()
specifier|const
block|{
return|return
name|_M_data
operator|->
name|_M_grouping
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return string representation of bool true.        *        *  Returns a string_type containing the text representation for true        *  bool variables.  This function is a hook for derived classes to        *  change the value returned.        *        *  @return  string_type representing printed form of true.       */
end_comment

begin_expr_stmt
name|virtual
name|string_type
name|do_truename
argument_list|()
specifier|const
block|{
return|return
name|_M_data
operator|->
name|_M_truename
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return string representation of bool false.        *        *  Returns a string_type containing the text representation for false        *  bool variables.  This function is a hook for derived classes to        *  change the value returned.        *        *  @return  string_type representing printed form of false.       */
end_comment

begin_expr_stmt
name|virtual
name|string_type
name|do_falsename
argument_list|()
specifier|const
block|{
return|return
name|_M_data
operator|->
name|_M_falsename
return|;
block|}
end_expr_stmt

begin_comment
comment|// For use at construction time only.
end_comment

begin_function_decl
name|void
name|_M_initialize_numpunct
parameter_list|(
name|__c_locale
name|__cloc
init|=
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|>
name|locale
operator|::
name|id
name|numpunct
operator|<
name|_CharT
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|numpunct
operator|<
name|char
operator|>
operator|::
operator|~
name|numpunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|numpunct
operator|<
name|char
operator|>
operator|::
name|_M_initialize_numpunct
argument_list|(
argument|__c_locale __cloc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
name|numpunct
operator|<
name|wchar_t
operator|>
operator|::
operator|~
name|numpunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|numpunct
operator|<
name|wchar_t
operator|>
operator|::
name|_M_initialize_numpunct
argument_list|(
argument|__c_locale __cloc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// @brief  class numpunct_byname [22.2.3.2].
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|numpunct_byname
operator|:
name|public
name|numpunct
operator|<
name|_CharT
operator|>
block|{
name|public
operator|:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_macro
name|explicit
end_macro

begin_macro
name|numpunct_byname
argument_list|(
argument|const char* __s
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|numpunct
operator|<
name|_CharT
operator|>
operator|(
name|__refs
operator|)
block|{
if|if
condition|(
name|std
operator|::
name|strcmp
argument_list|(
name|__s
argument_list|,
literal|"C"
argument_list|)
operator|!=
literal|0
operator|&&
name|std
operator|::
name|strcmp
argument_list|(
name|__s
argument_list|,
literal|"POSIX"
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|__c_locale
name|__tmp
decl_stmt|;
name|this
operator|->
name|_S_create_c_locale
argument_list|(
name|__tmp
argument_list|,
name|__s
argument_list|)
expr_stmt|;
name|this
operator|->
name|_M_initialize_numpunct
argument_list|(
name|__tmp
argument_list|)
expr_stmt|;
name|this
operator|->
name|_S_destroy_c_locale
argument_list|(
name|__tmp
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}      protected:
name|virtual
operator|~
name|numpunct_byname
argument_list|()
block|{ }
end_expr_stmt

begin_expr_stmt
unit|};
name|_GLIBCXX_BEGIN_LDBL_NAMESPACE
comment|/**    *  @brief  Facet for parsing number strings.    *    *  This facet encapsulates the code to parse and return a number    *  from a string.  It is used by the istream numeric extraction    *  operators.    *    *  The num_get template uses protected virtual functions to provide the    *  actual results.  The public accessors forward the call to the virtual    *  functions.  These virtual functions are hooks for developers to    *  implement the behavior they require from the num_get facet.   */
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_InIter
operator|>
name|class
name|num_get
operator|:
name|public
name|locale
operator|::
name|facet
block|{
name|public
operator|:
comment|// Types:
comment|//@{
comment|/// Public typedefs
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_InIter
name|iter_type
typedef|;
end_typedef

begin_comment
comment|//@}
end_comment

begin_comment
comment|/// Numpunct facet id.
end_comment

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Constructor performs initialization.        *        *  This is the constructor provided by the standard.        *        *  @param refs  Passed to the base facet class.       */
end_comment

begin_macro
name|explicit
end_macro

begin_macro
name|num_get
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_macro
unit|:
name|facet
argument_list|(
argument|__refs
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_comment
comment|/**        *  @brief  Numeric parsing.        *        *  Parses the input stream into the bool @a v.  It does so by calling        *  num_get::do_get().        *        *  If ios_base::boolalpha is set, attempts to read        *  ctype<CharT>::truename() or ctype<CharT>::falsename().  Sets        *  @a v to true or false if successful.  Sets err to        *  ios_base::failbit if reading the string fails.  Sets err to        *  ios_base::eofbit if the stream is emptied.        *        *  If ios_base::boolalpha is not set, proceeds as with reading a long,        *  except if the value is 1, sets @a v to true, if the value is 0, sets        *  @a v to false, and otherwise set err to ios_base::failbit.        *        *  @param  in  Start of input stream.        *  @param  end  End of input stream.        *  @param  io  Source of locale and flags.        *  @param  err  Error flags to set.        *  @param  v  Value to format and insert.        *  @return  Iterator after reading.       */
end_comment

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|bool
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|//@{
end_comment

begin_comment
comment|/**        *  @brief  Numeric parsing.        *        *  Parses the input stream into the integral variable @a v.  It does so        *  by calling num_get::do_get().        *        *  Parsing is affected by the flag settings in @a io.        *        *  The basic parse is affected by the value of io.flags()&        *  ios_base::basefield.  If equal to ios_base::oct, parses like the        *  scanf %o specifier.  Else if equal to ios_base::hex, parses like %X        *  specifier.  Else if basefield equal to 0, parses like the %i        *  specifier.  Otherwise, parses like %d for signed and %u for unsigned        *  types.  The matching type length modifier is also used.        *        *  Digit grouping is intrepreted according to numpunct::grouping() and        *  numpunct::thousands_sep().  If the pattern of digit groups isn't        *  consistent, sets err to ios_base::failbit.        *        *  If parsing the string yields a valid value for @a v, @a v is set.        *  Otherwise, sets err to ios_base::failbit and leaves @a v unaltered.        *  Sets err to ios_base::eofbit if the stream is emptied.        *        *  @param  in  Start of input stream.        *  @param  end  End of input stream.        *  @param  io  Source of locale and flags.        *  @param  err  Error flags to set.        *  @param  v  Value to format and insert.        *  @return  Iterator after reading.       */
end_comment

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|long
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|unsigned
name|short
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|unsigned
name|int
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|unsigned
name|long
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_LONG_LONG
end_ifdef

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|long
name|long
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|unsigned
name|long
name|long
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//@}
end_comment

begin_comment
comment|//@{
end_comment

begin_comment
comment|/**        *  @brief  Numeric parsing.        *        *  Parses the input stream into the integral variable @a v.  It does so        *  by calling num_get::do_get().        *        *  The input characters are parsed like the scanf %g specifier.  The        *  matching type length modifier is also used.        *        *  The decimal point character used is numpunct::decimal_point().        *  Digit grouping is intrepreted according to numpunct::grouping() and        *  numpunct::thousands_sep().  If the pattern of digit groups isn't        *  consistent, sets err to ios_base::failbit.        *        *  If parsing the string yields a valid value for @a v, @a v is set.        *  Otherwise, sets err to ios_base::failbit and leaves @a v unaltered.        *  Sets err to ios_base::eofbit if the stream is emptied.        *        *  @param  in  Start of input stream.        *  @param  end  End of input stream.        *  @param  io  Source of locale and flags.        *  @param  err  Error flags to set.        *  @param  v  Value to format and insert.        *  @return  Iterator after reading.       */
end_comment

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|float
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|double
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|long
name|double
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|//@}
end_comment

begin_comment
comment|/**        *  @brief  Numeric parsing.        *        *  Parses the input stream into the pointer variable @a v.  It does so        *  by calling num_get::do_get().        *        *  The input characters are parsed like the scanf %p specifier.        *        *  Digit grouping is intrepreted according to numpunct::grouping() and        *  numpunct::thousands_sep().  If the pattern of digit groups isn't        *  consistent, sets err to ios_base::failbit.        *        *  Note that the digit grouping effect for pointers is a bit ambiguous        *  in the standard and shouldn't be relied on.  See DR 344.        *        *  If parsing the string yields a valid value for @a v, @a v is set.        *  Otherwise, sets err to ios_base::failbit and leaves @a v unaltered.        *  Sets err to ios_base::eofbit if the stream is emptied.        *        *  @param  in  Start of input stream.        *  @param  end  End of input stream.        *  @param  io  Source of locale and flags.        *  @param  err  Error flags to set.        *  @param  v  Value to format and insert.        *  @return  Iterator after reading.       */
end_comment

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|void
operator|*
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// Destructor.
end_comment

begin_expr_stmt
name|virtual
operator|~
name|num_get
argument_list|()
block|{ }
name|iter_type
name|_M_extract_float
argument_list|(
argument|iter_type
argument_list|,
argument|iter_type
argument_list|,
argument|ios_base&
argument_list|,
argument|ios_base::iostate&
argument_list|,
argument|string& __xtrc
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_ValueT
operator|>
name|iter_type
name|_M_extract_int
argument_list|(
argument|iter_type
argument_list|,
argument|iter_type
argument_list|,
argument|ios_base&
argument_list|,
argument|ios_base::iostate&
argument_list|,
argument|_ValueT& __v
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT2
operator|>
name|typename
name|__gnu_cxx
operator|::
name|__enable_if
operator|<
name|__is_char
operator|<
name|_CharT2
operator|>
operator|::
name|__value
operator|,
name|int
operator|>
operator|::
name|__type
name|_M_find
argument_list|(
argument|const _CharT2*
argument_list|,
argument|size_t __len
argument_list|,
argument|_CharT2 __c
argument_list|)
specifier|const
block|{
name|int
name|__ret
operator|=
operator|-
literal|1
block|;
if|if
condition|(
name|__len
operator|<=
literal|10
condition|)
block|{
if|if
condition|(
name|__c
operator|>=
name|_CharT2
argument_list|(
literal|'0'
argument_list|)
operator|&&
name|__c
operator|<
name|_CharT2
argument_list|(
name|_CharT2
argument_list|(
literal|'0'
argument_list|)
operator|+
name|__len
argument_list|)
condition|)
name|__ret
operator|=
name|__c
operator|-
name|_CharT2
argument_list|(
literal|'0'
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
if|if
condition|(
name|__c
operator|>=
name|_CharT2
argument_list|(
literal|'0'
argument_list|)
operator|&&
name|__c
operator|<=
name|_CharT2
argument_list|(
literal|'9'
argument_list|)
condition|)
name|__ret
operator|=
name|__c
operator|-
name|_CharT2
argument_list|(
literal|'0'
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|__c
operator|>=
name|_CharT2
argument_list|(
literal|'a'
argument_list|)
operator|&&
name|__c
operator|<=
name|_CharT2
argument_list|(
literal|'f'
argument_list|)
condition|)
name|__ret
operator|=
literal|10
operator|+
operator|(
name|__c
operator|-
name|_CharT2
argument_list|(
literal|'a'
argument_list|)
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|__c
operator|>=
name|_CharT2
argument_list|(
literal|'A'
argument_list|)
operator|&&
name|__c
operator|<=
name|_CharT2
argument_list|(
literal|'F'
argument_list|)
condition|)
name|__ret
operator|=
literal|10
operator|+
operator|(
name|__c
operator|-
name|_CharT2
argument_list|(
literal|'A'
argument_list|)
operator|)
expr_stmt|;
block|}
end_else

begin_return
return|return
name|__ret
return|;
end_return

begin_expr_stmt
unit|}        template
operator|<
name|typename
name|_CharT2
operator|>
name|typename
name|__gnu_cxx
operator|::
name|__enable_if
operator|<
operator|!
name|__is_char
operator|<
name|_CharT2
operator|>
operator|::
name|__value
operator|,
name|int
operator|>
operator|::
name|__type
name|_M_find
argument_list|(
argument|const _CharT2* __zero
argument_list|,
argument|size_t __len
argument_list|,
argument|_CharT2 __c
argument_list|)
specifier|const
block|{
name|int
name|__ret
operator|=
operator|-
literal|1
block|;
specifier|const
name|char_type
operator|*
name|__q
operator|=
name|char_traits
operator|<
name|_CharT2
operator|>
operator|::
name|find
argument_list|(
name|__zero
argument_list|,
name|__len
argument_list|,
name|__c
argument_list|)
block|;
if|if
condition|(
name|__q
condition|)
block|{
name|__ret
operator|=
name|__q
operator|-
name|__zero
expr_stmt|;
if|if
condition|(
name|__ret
operator|>
literal|15
condition|)
name|__ret
operator|-=
literal|6
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|__ret
return|;
end_return

begin_comment
unit|}
comment|//@{
end_comment

begin_comment
comment|/**        *  @brief  Numeric parsing.        *        *  Parses the input stream into the variable @a v.  This function is a        *  hook for derived classes to change the value returned.  @see get()        *  for more details.        *        *  @param  in  Start of input stream.        *  @param  end  End of input stream.        *  @param  io  Source of locale and flags.        *  @param  err  Error flags to set.        *  @param  v  Value to format and insert.        *  @return  Iterator after reading.       */
end_comment

begin_decl_stmt
unit|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
argument_list|,
name|bool
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
argument_list|,
name|long
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|unsigned
name|short
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|unsigned
name|int
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|unsigned
name|long
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_LONG_LONG
end_ifdef

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|long
name|long
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|unsigned
name|long
name|long
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|float
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|double
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// XXX GLIBCXX_ABI Deprecated
end_comment

begin_if
if|#
directive|if
name|defined
name|_GLIBCXX_LONG_DOUBLE_COMPAT
operator|&&
name|defined
name|__LONG_DOUBLE_128__
end_if

begin_decl_stmt
name|virtual
name|iter_type
name|__do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|double
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|long
name|double
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|void
operator|*
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// XXX GLIBCXX_ABI Deprecated
end_comment

begin_if
if|#
directive|if
name|defined
name|_GLIBCXX_LONG_DOUBLE_COMPAT
operator|&&
name|defined
name|__LONG_DOUBLE_128__
end_if

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|long
name|double
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//@}
end_comment

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_InIter
operator|>
name|locale
operator|::
name|id
name|num_get
operator|<
name|_CharT
operator|,
name|_InIter
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**    *  @brief  Facet for converting numbers to strings.    *    *  This facet encapsulates the code to convert a number to a string.  It is    *  used by the ostream numeric insertion operators.    *    *  The num_put template uses protected virtual functions to provide the    *  actual results.  The public accessors forward the call to the virtual    *  functions.  These virtual functions are hooks for developers to    *  implement the behavior they require from the num_put facet.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|>
name|class
name|num_put
operator|:
name|public
name|locale
operator|::
name|facet
block|{
name|public
operator|:
comment|// Types:
comment|//@{
comment|/// Public typedefs
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_OutIter
name|iter_type
typedef|;
end_typedef

begin_comment
comment|//@}
end_comment

begin_comment
comment|/// Numpunct facet id.
end_comment

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Constructor performs initialization.        *        *  This is the constructor provided by the standard.        *        *  @param refs  Passed to the base facet class.       */
end_comment

begin_macro
name|explicit
end_macro

begin_macro
name|num_put
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_macro
unit|:
name|facet
argument_list|(
argument|__refs
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_comment
comment|/**        *  @brief  Numeric formatting.        *        *  Formats the boolean @a v and inserts it into a stream.  It does so        *  by calling num_put::do_put().        *        *  If ios_base::boolalpha is set, writes ctype<CharT>::truename() or        *  ctype<CharT>::falsename().  Otherwise formats @a v as an int.        *        *  @param  s  Stream to write to.        *  @param  io  Source of locale and flags.        *  @param  fill  Char_type to use for filling.        *  @param  v  Value to format and insert.        *  @return  Iterator after writing.       */
end_comment

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__f
argument_list|,
name|char_type
name|__fill
argument_list|,
name|bool
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__f
argument_list|,
name|__fill
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|//@{
end_comment

begin_comment
comment|/**        *  @brief  Numeric formatting.        *        *  Formats the integral value @a v and inserts it into a        *  stream.  It does so by calling num_put::do_put().        *        *  Formatting is affected by the flag settings in @a io.        *        *  The basic format is affected by the value of io.flags()&        *  ios_base::basefield.  If equal to ios_base::oct, formats like the        *  printf %o specifier.  Else if equal to ios_base::hex, formats like        *  %x or %X with ios_base::uppercase unset or set respectively.        *  Otherwise, formats like %d, %ld, %lld for signed and %u, %lu, %llu        *  for unsigned values.  Note that if both oct and hex are set, neither        *  will take effect.        *        *  If ios_base::showpos is set, '+' is output before positive values.        *  If ios_base::showbase is set, '0' precedes octal values (except 0)        *  and '0[xX]' precedes hex values.        *        *  Thousands separators are inserted according to numpunct::grouping()        *  and numpunct::thousands_sep().  The decimal point character used is        *  numpunct::decimal_point().        *        *  If io.width() is non-zero, enough @a fill characters are inserted to        *  make the result at least that wide.  If        *  (io.flags()& ios_base::adjustfield) == ios_base::left, result is        *  padded at the end.  If ios_base::internal, then padding occurs        *  immediately after either a '+' or '-' or after '0x' or '0X'.        *  Otherwise, padding occurs at the beginning.        *        *  @param  s  Stream to write to.        *  @param  io  Source of locale and flags.        *  @param  fill  Char_type to use for filling.        *  @param  v  Value to format and insert.        *  @return  Iterator after writing.       */
end_comment

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__f
argument_list|,
name|char_type
name|__fill
argument_list|,
name|long
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__f
argument_list|,
name|__fill
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__f
argument_list|,
name|char_type
name|__fill
argument_list|,
name|unsigned
name|long
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__f
argument_list|,
name|__fill
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_LONG_LONG
end_ifdef

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__f
argument_list|,
name|char_type
name|__fill
argument_list|,
name|long
name|long
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__f
argument_list|,
name|__fill
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__f
argument_list|,
name|char_type
name|__fill
argument_list|,
name|unsigned
name|long
name|long
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__f
argument_list|,
name|__fill
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//@}
end_comment

begin_comment
comment|//@{
end_comment

begin_comment
comment|/**        *  @brief  Numeric formatting.        *        *  Formats the floating point value @a v and inserts it into a stream.        *  It does so by calling num_put::do_put().        *        *  Formatting is affected by the flag settings in @a io.        *        *  The basic format is affected by the value of io.flags()&        *  ios_base::floatfield.  If equal to ios_base::fixed, formats like the        *  printf %f specifier.  Else if equal to ios_base::scientific, formats        *  like %e or %E with ios_base::uppercase unset or set respectively.        *  Otherwise, formats like %g or %G depending on uppercase.  Note that        *  if both fixed and scientific are set, the effect will also be like        *  %g or %G.        *        *  The output precision is given by io.precision().  This precision is        *  capped at numeric_limits::digits10 + 2 (different for double and        *  long double).  The default precision is 6.        *        *  If ios_base::showpos is set, '+' is output before positive values.        *  If ios_base::showpoint is set, a decimal point will always be        *  output.        *        *  Thousands separators are inserted according to numpunct::grouping()        *  and numpunct::thousands_sep().  The decimal point character used is        *  numpunct::decimal_point().        *        *  If io.width() is non-zero, enough @a fill characters are inserted to        *  make the result at least that wide.  If        *  (io.flags()& ios_base::adjustfield) == ios_base::left, result is        *  padded at the end.  If ios_base::internal, then padding occurs        *  immediately after either a '+' or '-' or after '0x' or '0X'.        *  Otherwise, padding occurs at the beginning.        *        *  @param  s  Stream to write to.        *  @param  io  Source of locale and flags.        *  @param  fill  Char_type to use for filling.        *  @param  v  Value to format and insert.        *  @return  Iterator after writing.       */
end_comment

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__f
argument_list|,
name|char_type
name|__fill
argument_list|,
name|double
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__f
argument_list|,
name|__fill
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__f
argument_list|,
name|char_type
name|__fill
argument_list|,
name|long
name|double
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__f
argument_list|,
name|__fill
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|//@}
end_comment

begin_comment
comment|/**        *  @brief  Numeric formatting.        *        *  Formats the pointer value @a v and inserts it into a stream.  It        *  does so by calling num_put::do_put().        *        *  This function formats @a v as an unsigned long with ios_base::hex        *  and ios_base::showbase set.        *        *  @param  s  Stream to write to.        *  @param  io  Source of locale and flags.        *  @param  fill  Char_type to use for filling.        *  @param  v  Value to format and insert.        *  @return  Iterator after writing.       */
end_comment

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__f
argument_list|,
name|char_type
name|__fill
argument_list|,
specifier|const
name|void
operator|*
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__f
argument_list|,
name|__fill
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|template
operator|<
name|typename
name|_ValueT
operator|>
name|iter_type
name|_M_insert_float
argument_list|(
argument|iter_type
argument_list|,
argument|ios_base& __io
argument_list|,
argument|char_type __fill
argument_list|,
argument|char __mod
argument_list|,
argument|_ValueT __v
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|_M_group_float
argument_list|(
specifier|const
name|char
operator|*
name|__grouping
argument_list|,
name|size_t
name|__grouping_size
argument_list|,
name|char_type
name|__sep
argument_list|,
specifier|const
name|char_type
operator|*
name|__p
argument_list|,
name|char_type
operator|*
name|__new
argument_list|,
name|char_type
operator|*
name|__cs
argument_list|,
name|int
operator|&
name|__len
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_ValueT
operator|>
name|iter_type
name|_M_insert_int
argument_list|(
argument|iter_type
argument_list|,
argument|ios_base& __io
argument_list|,
argument|char_type __fill
argument_list|,
argument|_ValueT __v
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|_M_group_int
argument_list|(
specifier|const
name|char
operator|*
name|__grouping
argument_list|,
name|size_t
name|__grouping_size
argument_list|,
name|char_type
name|__sep
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
operator|*
name|__new
argument_list|,
name|char_type
operator|*
name|__cs
argument_list|,
name|int
operator|&
name|__len
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_M_pad
argument_list|(
name|char_type
name|__fill
argument_list|,
name|streamsize
name|__w
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
operator|*
name|__new
argument_list|,
specifier|const
name|char_type
operator|*
name|__cs
argument_list|,
name|int
operator|&
name|__len
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Destructor.
end_comment

begin_expr_stmt
name|virtual
operator|~
name|num_put
argument_list|()
block|{ }
expr_stmt|;
end_expr_stmt

begin_comment
comment|//@{
end_comment

begin_comment
comment|/**        *  @brief  Numeric formatting.        *        *  These functions do the work of formatting numeric values and        *  inserting them into a stream. This function is a hook for derived        *  classes to change the value returned.        *        *  @param  s  Stream to write to.        *  @param  io  Source of locale and flags.        *  @param  fill  Char_type to use for filling.        *  @param  v  Value to format and insert.        *  @return  Iterator after writing.       */
end_comment

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
name|bool
name|__v
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
name|long
name|__v
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
name|unsigned
name|long
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_LONG_LONG
end_ifdef

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
name|long
name|long
name|__v
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
name|unsigned
name|long
name|long
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
name|double
name|__v
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// XXX GLIBCXX_ABI Deprecated
end_comment

begin_if
if|#
directive|if
name|defined
name|_GLIBCXX_LONG_DOUBLE_COMPAT
operator|&&
name|defined
name|__LONG_DOUBLE_128__
end_if

begin_decl_stmt
name|virtual
name|iter_type
name|__do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
name|double
name|__v
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
name|long
name|double
name|__v
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
specifier|const
name|void
operator|*
name|__v
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// XXX GLIBCXX_ABI Deprecated
end_comment

begin_if
if|#
directive|if
name|defined
name|_GLIBCXX_LONG_DOUBLE_COMPAT
operator|&&
name|defined
name|__LONG_DOUBLE_128__
end_if

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
name|long
name|double
name|__v
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//@}
end_comment

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|>
name|locale
operator|::
name|id
name|num_put
operator|<
name|_CharT
operator|,
name|_OutIter
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_GLIBCXX_END_LDBL_NAMESPACE
comment|/**    *  @brief  Facet for localized string comparison.    *    *  This facet encapsulates the code to compare strings in a localized    *  manner.    *    *  The collate template uses protected virtual functions to provide    *  the actual results.  The public accessors forward the call to    *  the virtual functions.  These virtual functions are hooks for    *  developers to implement the behavior they require from the    *  collate facet.   */
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|collate
operator|:
name|public
name|locale
operator|::
name|facet
block|{
name|public
operator|:
comment|// Types:
comment|//@{
comment|/// Public typedefs
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_comment
comment|//@}
end_comment

begin_label
name|protected
label|:
end_label

begin_comment
comment|// Underlying "C" library locale information saved from
end_comment

begin_comment
comment|// initialization, needed by collate_byname as well.
end_comment

begin_decl_stmt
name|__c_locale
name|_M_c_locale_collate
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Numpunct facet id.
end_comment

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Constructor performs initialization.        *        *  This is the constructor provided by the standard.        *        *  @param refs  Passed to the base facet class.       */
end_comment

begin_macro
name|explicit
end_macro

begin_macro
name|collate
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|facet
argument_list|(
name|__refs
argument_list|)
operator|,
name|_M_c_locale_collate
argument_list|(
argument|_S_get_c_locale()
argument_list|)
block|{ }
comment|/**        *  @brief  Internal constructor. Not for general use.        *        *  This is a constructor for use by the library itself to set up new        *  locales.        *        *  @param cloc  The "C" locale.        *  @param refs  Passed to the base facet class.       */
name|explicit
name|collate
argument_list|(
argument|__c_locale __cloc
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
operator|:
name|facet
argument_list|(
name|__refs
argument_list|)
operator|,
name|_M_c_locale_collate
argument_list|(
argument|_S_clone_c_locale(__cloc)
argument_list|)
block|{ }
comment|/**        *  @brief  Compare two strings.        *        *  This function compares two strings and returns the result by calling        *  collate::do_compare().        *        *  @param lo1  Start of string 1.        *  @param hi1  End of string 1.        *  @param lo2  Start of string 2.        *  @param hi2  End of string 2.        *  @return  1 if string1> string2, -1 if string1< string2, else 0.       */
name|int
name|compare
argument_list|(
argument|const _CharT* __lo1
argument_list|,
argument|const _CharT* __hi1
argument_list|,
argument|const _CharT* __lo2
argument_list|,
argument|const _CharT* __hi2
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_compare
argument_list|(
name|__lo1
argument_list|,
name|__hi1
argument_list|,
name|__lo2
argument_list|,
name|__hi2
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Transform string to comparable form.        *        *  This function is a wrapper for strxfrm functionality.  It takes the        *  input string and returns a modified string that can be directly        *  compared to other transformed strings.  In the "C" locale, this        *  function just returns a copy of the input string.  In some other        *  locales, it may replace two chars with one, change a char for        *  another, etc.  It does so by returning collate::do_transform().        *        *  @param lo  Start of string.        *  @param hi  End of string.        *  @return  Transformed string_type.       */
end_comment

begin_decl_stmt
name|string_type
name|transform
argument_list|(
specifier|const
name|_CharT
operator|*
name|__lo
argument_list|,
specifier|const
name|_CharT
operator|*
name|__hi
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_transform
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Return hash of a string.        *        *  This function computes and returns a hash on the input string.  It        *  does so by returning collate::do_hash().        *        *  @param lo  Start of string.        *  @param hi  End of string.        *  @return  Hash value.       */
end_comment

begin_decl_stmt
name|long
name|hash
argument_list|(
specifier|const
name|_CharT
operator|*
name|__lo
argument_list|,
specifier|const
name|_CharT
operator|*
name|__hi
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_hash
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Used to abstract out _CharT bits in virtual member functions, below.
end_comment

begin_decl_stmt
name|int
name|_M_compare
argument_list|(
specifier|const
name|_CharT
operator|*
argument_list|,
specifier|const
name|_CharT
operator|*
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|_M_transform
argument_list|(
name|_CharT
operator|*
argument_list|,
specifier|const
name|_CharT
operator|*
argument_list|,
name|size_t
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// Destructor.
end_comment

begin_expr_stmt
name|virtual
operator|~
name|collate
argument_list|()
block|{
name|_S_destroy_c_locale
argument_list|(
name|_M_c_locale_collate
argument_list|)
block|; }
comment|/**        *  @brief  Compare two strings.        *        *  This function is a hook for derived classes to change the value        *  returned.  @see compare().        *        *  @param lo1  Start of string 1.        *  @param hi1  End of string 1.        *  @param lo2  Start of string 2.        *  @param hi2  End of string 2.        *  @return  1 if string1> string2, -1 if string1< string2, else 0.       */
name|virtual
name|int
name|do_compare
argument_list|(
argument|const _CharT* __lo1
argument_list|,
argument|const _CharT* __hi1
argument_list|,
argument|const _CharT* __lo2
argument_list|,
argument|const _CharT* __hi2
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Transform string to comparable form.        *        *  This function is a hook for derived classes to change the value        *  returned.        *        *  @param lo1  Start of string 1.        *  @param hi1  End of string 1.        *  @param lo2  Start of string 2.        *  @param hi2  End of string 2.        *  @return  1 if string1> string2, -1 if string1< string2, else 0.       */
end_comment

begin_decl_stmt
name|virtual
name|string_type
name|do_transform
argument_list|(
specifier|const
name|_CharT
operator|*
name|__lo
argument_list|,
specifier|const
name|_CharT
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Return hash of a string.        *        *  This function computes and returns a hash on the input string.  This        *  function is a hook for derived classes to change the value returned.        *        *  @param lo  Start of string.        *  @param hi  End of string.        *  @return  Hash value.       */
end_comment

begin_decl_stmt
name|virtual
name|long
name|do_hash
argument_list|(
specifier|const
name|_CharT
operator|*
name|__lo
argument_list|,
specifier|const
name|_CharT
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|>
name|locale
operator|::
name|id
name|collate
operator|<
name|_CharT
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Specializations.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|int
name|collate
operator|<
name|char
operator|>
operator|::
name|_M_compare
argument_list|(
argument|const char*
argument_list|,
argument|const char*
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|size_t
name|collate
operator|<
name|char
operator|>
operator|::
name|_M_transform
argument_list|(
argument|char*
argument_list|,
argument|const char*
argument_list|,
argument|size_t
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
name|int
name|collate
operator|<
name|wchar_t
operator|>
operator|::
name|_M_compare
argument_list|(
argument|const wchar_t*
argument_list|,
argument|const wchar_t*
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|size_t
name|collate
operator|<
name|wchar_t
operator|>
operator|::
name|_M_transform
argument_list|(
argument|wchar_t*
argument_list|,
argument|const wchar_t*
argument_list|,
argument|size_t
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// @brief  class collate_byname [22.2.4.2].
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|collate_byname
operator|:
name|public
name|collate
operator|<
name|_CharT
operator|>
block|{
name|public
operator|:
comment|//@{
comment|/// Public typedefs
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_comment
comment|//@}
end_comment

begin_macro
name|explicit
end_macro

begin_macro
name|collate_byname
argument_list|(
argument|const char* __s
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|collate
operator|<
name|_CharT
operator|>
operator|(
name|__refs
operator|)
block|{
if|if
condition|(
name|std
operator|::
name|strcmp
argument_list|(
name|__s
argument_list|,
literal|"C"
argument_list|)
operator|!=
literal|0
operator|&&
name|std
operator|::
name|strcmp
argument_list|(
name|__s
argument_list|,
literal|"POSIX"
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|this
operator|->
name|_S_destroy_c_locale
argument_list|(
name|this
operator|->
name|_M_c_locale_collate
argument_list|)
expr_stmt|;
name|this
operator|->
name|_S_create_c_locale
argument_list|(
name|this
operator|->
name|_M_c_locale_collate
argument_list|,
name|__s
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}      protected:
name|virtual
operator|~
name|collate_byname
argument_list|()
block|{ }
end_expr_stmt

begin_comment
unit|};
comment|/**    *  @brief  Time format ordering data.    *    *  This class provides an enum representing different orderings of day,    *  month, and year.   */
end_comment

begin_decl_stmt
name|class
name|time_base
block|{
name|public
label|:
enum|enum
name|dateorder
block|{
name|no_order
block|,
name|dmy
block|,
name|mdy
block|,
name|ymd
block|,
name|ydm
block|}
enum|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
expr|struct
name|__timepunct_cache
operator|:
name|public
name|locale
operator|::
name|facet
block|{
comment|// List of all known timezones, with GMT first.
specifier|static
specifier|const
name|_CharT
operator|*
name|_S_timezones
index|[
literal|14
index|]
block|;
specifier|const
name|_CharT
operator|*
name|_M_date_format
block|;
specifier|const
name|_CharT
operator|*
name|_M_date_era_format
block|;
specifier|const
name|_CharT
operator|*
name|_M_time_format
block|;
specifier|const
name|_CharT
operator|*
name|_M_time_era_format
block|;
specifier|const
name|_CharT
operator|*
name|_M_date_time_format
block|;
specifier|const
name|_CharT
operator|*
name|_M_date_time_era_format
block|;
specifier|const
name|_CharT
operator|*
name|_M_am
block|;
specifier|const
name|_CharT
operator|*
name|_M_pm
block|;
specifier|const
name|_CharT
operator|*
name|_M_am_pm_format
block|;
comment|// Day names, starting with "C"'s Sunday.
specifier|const
name|_CharT
operator|*
name|_M_day1
block|;
specifier|const
name|_CharT
operator|*
name|_M_day2
block|;
specifier|const
name|_CharT
operator|*
name|_M_day3
block|;
specifier|const
name|_CharT
operator|*
name|_M_day4
block|;
specifier|const
name|_CharT
operator|*
name|_M_day5
block|;
specifier|const
name|_CharT
operator|*
name|_M_day6
block|;
specifier|const
name|_CharT
operator|*
name|_M_day7
block|;
comment|// Abbreviated day names, starting with "C"'s Sun.
specifier|const
name|_CharT
operator|*
name|_M_aday1
block|;
specifier|const
name|_CharT
operator|*
name|_M_aday2
block|;
specifier|const
name|_CharT
operator|*
name|_M_aday3
block|;
specifier|const
name|_CharT
operator|*
name|_M_aday4
block|;
specifier|const
name|_CharT
operator|*
name|_M_aday5
block|;
specifier|const
name|_CharT
operator|*
name|_M_aday6
block|;
specifier|const
name|_CharT
operator|*
name|_M_aday7
block|;
comment|// Month names, starting with "C"'s January.
specifier|const
name|_CharT
operator|*
name|_M_month01
block|;
specifier|const
name|_CharT
operator|*
name|_M_month02
block|;
specifier|const
name|_CharT
operator|*
name|_M_month03
block|;
specifier|const
name|_CharT
operator|*
name|_M_month04
block|;
specifier|const
name|_CharT
operator|*
name|_M_month05
block|;
specifier|const
name|_CharT
operator|*
name|_M_month06
block|;
specifier|const
name|_CharT
operator|*
name|_M_month07
block|;
specifier|const
name|_CharT
operator|*
name|_M_month08
block|;
specifier|const
name|_CharT
operator|*
name|_M_month09
block|;
specifier|const
name|_CharT
operator|*
name|_M_month10
block|;
specifier|const
name|_CharT
operator|*
name|_M_month11
block|;
specifier|const
name|_CharT
operator|*
name|_M_month12
block|;
comment|// Abbreviated month names, starting with "C"'s Jan.
specifier|const
name|_CharT
operator|*
name|_M_amonth01
block|;
specifier|const
name|_CharT
operator|*
name|_M_amonth02
block|;
specifier|const
name|_CharT
operator|*
name|_M_amonth03
block|;
specifier|const
name|_CharT
operator|*
name|_M_amonth04
block|;
specifier|const
name|_CharT
operator|*
name|_M_amonth05
block|;
specifier|const
name|_CharT
operator|*
name|_M_amonth06
block|;
specifier|const
name|_CharT
operator|*
name|_M_amonth07
block|;
specifier|const
name|_CharT
operator|*
name|_M_amonth08
block|;
specifier|const
name|_CharT
operator|*
name|_M_amonth09
block|;
specifier|const
name|_CharT
operator|*
name|_M_amonth10
block|;
specifier|const
name|_CharT
operator|*
name|_M_amonth11
block|;
specifier|const
name|_CharT
operator|*
name|_M_amonth12
block|;
name|bool
name|_M_allocated
block|;
name|__timepunct_cache
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
operator|:
name|facet
argument_list|(
name|__refs
argument_list|)
block|,
name|_M_date_format
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_date_era_format
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_time_format
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_time_era_format
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_date_time_format
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_date_time_era_format
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_am
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_pm
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_am_pm_format
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_day1
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_day2
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_day3
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_day4
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_day5
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_day6
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_day7
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_aday1
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_aday2
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_aday3
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_aday4
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_aday5
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_aday6
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_aday7
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_month01
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_month02
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_month03
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_month04
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_month05
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_month06
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_month07
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_month08
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_month09
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_month10
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_month11
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_month12
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_amonth01
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_amonth02
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_amonth03
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_amonth04
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_amonth05
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_amonth06
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_amonth07
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_amonth08
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_amonth09
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_amonth10
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_amonth11
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_amonth12
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_allocated
argument_list|(
argument|false
argument_list|)
block|{ }
operator|~
name|__timepunct_cache
argument_list|()
block|;
name|void
name|_M_cache
argument_list|(
specifier|const
name|locale
operator|&
name|__loc
argument_list|)
block|;
name|private
operator|:
name|__timepunct_cache
operator|&
name|operator
operator|=
operator|(
specifier|const
name|__timepunct_cache
operator|&
operator|)
block|;
name|explicit
name|__timepunct_cache
argument_list|(
specifier|const
name|__timepunct_cache
operator|&
argument_list|)
block|;     }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|__timepunct_cache
operator|<
name|_CharT
operator|>
operator|::
operator|~
name|__timepunct_cache
argument_list|()
block|{
if|if
condition|(
name|_M_allocated
condition|)
block|{
comment|// Unused.
block|}
end_expr_stmt

begin_comment
unit|}
comment|// Specializations.
end_comment

begin_expr_stmt
unit|template
operator|<
operator|>
specifier|const
name|char
operator|*
name|__timepunct_cache
operator|<
name|char
operator|>
operator|::
name|_S_timezones
index|[
literal|14
index|]
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
specifier|const
name|wchar_t
operator|*
name|__timepunct_cache
operator|<
name|wchar_t
operator|>
operator|::
name|_S_timezones
index|[
literal|14
index|]
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Generic.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|const
name|_CharT
operator|*
name|__timepunct_cache
operator|<
name|_CharT
operator|>
operator|::
name|_S_timezones
index|[
literal|14
index|]
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|__timepunct
operator|:
name|public
name|locale
operator|::
name|facet
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|__char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|__string_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|__timepunct_cache
operator|<
name|_CharT
operator|>
name|__cache_type
expr_stmt|;
end_typedef

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|__cache_type
modifier|*
name|_M_data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__c_locale
name|_M_c_locale_timepunct
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|_M_name_timepunct
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Numpunct facet id.
end_comment

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_function_decl
name|explicit
name|__timepunct
parameter_list|(
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|explicit
name|__timepunct
parameter_list|(
name|__cache_type
modifier|*
name|__cache
parameter_list|,
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Internal constructor. Not for general use.        *        *  This is a constructor for use by the library itself to set up new        *  locales.        *        *  @param cloc  The "C" locale.        *  @param s  The name of a locale.        *  @param refs  Passed to the base facet class.       */
end_comment

begin_function_decl
name|explicit
name|__timepunct
parameter_list|(
name|__c_locale
name|__cloc
parameter_list|,
specifier|const
name|char
modifier|*
name|__s
parameter_list|,
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// FIXME: for error checking purposes _M_put should return the return
end_comment

begin_comment
comment|// value of strftime/wcsftime.
end_comment

begin_decl_stmt
name|void
name|_M_put
argument_list|(
name|_CharT
operator|*
name|__s
argument_list|,
name|size_t
name|__maxlen
argument_list|,
specifier|const
name|_CharT
operator|*
name|__format
argument_list|,
specifier|const
name|tm
operator|*
name|__tm
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_M_date_formats
argument_list|(
specifier|const
name|_CharT
operator|*
operator|*
name|__date
argument_list|)
decl|const
block|{
comment|// Always have default first.
name|__date
index|[
literal|0
index|]
operator|=
name|_M_data
operator|->
name|_M_date_format
expr_stmt|;
name|__date
index|[
literal|1
index|]
operator|=
name|_M_data
operator|->
name|_M_date_era_format
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|_M_time_formats
argument_list|(
specifier|const
name|_CharT
operator|*
operator|*
name|__time
argument_list|)
decl|const
block|{
comment|// Always have default first.
name|__time
index|[
literal|0
index|]
operator|=
name|_M_data
operator|->
name|_M_time_format
expr_stmt|;
name|__time
index|[
literal|1
index|]
operator|=
name|_M_data
operator|->
name|_M_time_era_format
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|_M_date_time_formats
argument_list|(
specifier|const
name|_CharT
operator|*
operator|*
name|__dt
argument_list|)
decl|const
block|{
comment|// Always have default first.
name|__dt
index|[
literal|0
index|]
operator|=
name|_M_data
operator|->
name|_M_date_time_format
expr_stmt|;
name|__dt
index|[
literal|1
index|]
operator|=
name|_M_data
operator|->
name|_M_date_time_era_format
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|_M_am_pm_format
argument_list|(
specifier|const
name|_CharT
operator|*
name|__ampm
argument_list|)
decl|const
block|{
name|__ampm
operator|=
name|_M_data
operator|->
name|_M_am_pm_format
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|_M_am_pm
argument_list|(
specifier|const
name|_CharT
operator|*
operator|*
name|__ampm
argument_list|)
decl|const
block|{
name|__ampm
index|[
literal|0
index|]
operator|=
name|_M_data
operator|->
name|_M_am
expr_stmt|;
name|__ampm
index|[
literal|1
index|]
operator|=
name|_M_data
operator|->
name|_M_pm
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|_M_days
argument_list|(
specifier|const
name|_CharT
operator|*
operator|*
name|__days
argument_list|)
decl|const
block|{
name|__days
index|[
literal|0
index|]
operator|=
name|_M_data
operator|->
name|_M_day1
expr_stmt|;
name|__days
index|[
literal|1
index|]
operator|=
name|_M_data
operator|->
name|_M_day2
expr_stmt|;
name|__days
index|[
literal|2
index|]
operator|=
name|_M_data
operator|->
name|_M_day3
expr_stmt|;
name|__days
index|[
literal|3
index|]
operator|=
name|_M_data
operator|->
name|_M_day4
expr_stmt|;
name|__days
index|[
literal|4
index|]
operator|=
name|_M_data
operator|->
name|_M_day5
expr_stmt|;
name|__days
index|[
literal|5
index|]
operator|=
name|_M_data
operator|->
name|_M_day6
expr_stmt|;
name|__days
index|[
literal|6
index|]
operator|=
name|_M_data
operator|->
name|_M_day7
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|_M_days_abbreviated
argument_list|(
specifier|const
name|_CharT
operator|*
operator|*
name|__days
argument_list|)
decl|const
block|{
name|__days
index|[
literal|0
index|]
operator|=
name|_M_data
operator|->
name|_M_aday1
expr_stmt|;
name|__days
index|[
literal|1
index|]
operator|=
name|_M_data
operator|->
name|_M_aday2
expr_stmt|;
name|__days
index|[
literal|2
index|]
operator|=
name|_M_data
operator|->
name|_M_aday3
expr_stmt|;
name|__days
index|[
literal|3
index|]
operator|=
name|_M_data
operator|->
name|_M_aday4
expr_stmt|;
name|__days
index|[
literal|4
index|]
operator|=
name|_M_data
operator|->
name|_M_aday5
expr_stmt|;
name|__days
index|[
literal|5
index|]
operator|=
name|_M_data
operator|->
name|_M_aday6
expr_stmt|;
name|__days
index|[
literal|6
index|]
operator|=
name|_M_data
operator|->
name|_M_aday7
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|_M_months
argument_list|(
specifier|const
name|_CharT
operator|*
operator|*
name|__months
argument_list|)
decl|const
block|{
name|__months
index|[
literal|0
index|]
operator|=
name|_M_data
operator|->
name|_M_month01
expr_stmt|;
name|__months
index|[
literal|1
index|]
operator|=
name|_M_data
operator|->
name|_M_month02
expr_stmt|;
name|__months
index|[
literal|2
index|]
operator|=
name|_M_data
operator|->
name|_M_month03
expr_stmt|;
name|__months
index|[
literal|3
index|]
operator|=
name|_M_data
operator|->
name|_M_month04
expr_stmt|;
name|__months
index|[
literal|4
index|]
operator|=
name|_M_data
operator|->
name|_M_month05
expr_stmt|;
name|__months
index|[
literal|5
index|]
operator|=
name|_M_data
operator|->
name|_M_month06
expr_stmt|;
name|__months
index|[
literal|6
index|]
operator|=
name|_M_data
operator|->
name|_M_month07
expr_stmt|;
name|__months
index|[
literal|7
index|]
operator|=
name|_M_data
operator|->
name|_M_month08
expr_stmt|;
name|__months
index|[
literal|8
index|]
operator|=
name|_M_data
operator|->
name|_M_month09
expr_stmt|;
name|__months
index|[
literal|9
index|]
operator|=
name|_M_data
operator|->
name|_M_month10
expr_stmt|;
name|__months
index|[
literal|10
index|]
operator|=
name|_M_data
operator|->
name|_M_month11
expr_stmt|;
name|__months
index|[
literal|11
index|]
operator|=
name|_M_data
operator|->
name|_M_month12
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|_M_months_abbreviated
argument_list|(
specifier|const
name|_CharT
operator|*
operator|*
name|__months
argument_list|)
decl|const
block|{
name|__months
index|[
literal|0
index|]
operator|=
name|_M_data
operator|->
name|_M_amonth01
expr_stmt|;
name|__months
index|[
literal|1
index|]
operator|=
name|_M_data
operator|->
name|_M_amonth02
expr_stmt|;
name|__months
index|[
literal|2
index|]
operator|=
name|_M_data
operator|->
name|_M_amonth03
expr_stmt|;
name|__months
index|[
literal|3
index|]
operator|=
name|_M_data
operator|->
name|_M_amonth04
expr_stmt|;
name|__months
index|[
literal|4
index|]
operator|=
name|_M_data
operator|->
name|_M_amonth05
expr_stmt|;
name|__months
index|[
literal|5
index|]
operator|=
name|_M_data
operator|->
name|_M_amonth06
expr_stmt|;
name|__months
index|[
literal|6
index|]
operator|=
name|_M_data
operator|->
name|_M_amonth07
expr_stmt|;
name|__months
index|[
literal|7
index|]
operator|=
name|_M_data
operator|->
name|_M_amonth08
expr_stmt|;
name|__months
index|[
literal|8
index|]
operator|=
name|_M_data
operator|->
name|_M_amonth09
expr_stmt|;
name|__months
index|[
literal|9
index|]
operator|=
name|_M_data
operator|->
name|_M_amonth10
expr_stmt|;
name|__months
index|[
literal|10
index|]
operator|=
name|_M_data
operator|->
name|_M_amonth11
expr_stmt|;
name|__months
index|[
literal|11
index|]
operator|=
name|_M_data
operator|->
name|_M_amonth12
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|__timepunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// For use at construction time only.
end_comment

begin_function_decl
name|void
name|_M_initialize_timepunct
parameter_list|(
name|__c_locale
name|__cloc
init|=
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|>
name|locale
operator|::
name|id
name|__timepunct
operator|<
name|_CharT
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Specializations.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|__timepunct
operator|<
name|char
operator|>
operator|::
name|_M_initialize_timepunct
argument_list|(
argument|__c_locale __cloc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|__timepunct
operator|<
name|char
operator|>
operator|::
name|_M_put
argument_list|(
argument|char*
argument_list|,
argument|size_t
argument_list|,
argument|const char*
argument_list|,
argument|const tm*
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|__timepunct
operator|<
name|wchar_t
operator|>
operator|::
name|_M_initialize_timepunct
argument_list|(
argument|__c_locale __cloc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|__timepunct
operator|<
name|wchar_t
operator|>
operator|::
name|_M_put
argument_list|(
argument|wchar_t*
argument_list|,
argument|size_t
argument_list|,
argument|const wchar_t*
argument_list|,
argument|const tm*
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|_GLIBCXX_END_NAMESPACE
comment|// Include host and configuration specific timepunct functions.
include|#
directive|include
file|<bits/time_members.h>
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
name|std
argument_list|)
comment|/**    *  @brief  Facet for parsing dates and times.    *    *  This facet encapsulates the code to parse and return a date or    *  time from a string.  It is used by the istream numeric    *  extraction operators.    *    *  The time_get template uses protected virtual functions to provide the    *  actual results.  The public accessors forward the call to the virtual    *  functions.  These virtual functions are hooks for developers to    *  implement the behavior they require from the time_get facet.   */
name|template
decl|<
name|typename
name|_CharT
decl_stmt|,
name|typename
name|_InIter
decl|>
name|class
name|time_get
range|:
name|public
name|locale
operator|::
name|facet
decl_stmt|,
name|public
name|time_base
block|{
name|public
label|:
comment|// Types:
comment|//@{
comment|/// Public typedefs
typedef|typedef
name|_CharT
name|char_type
typedef|;
typedef|typedef
name|_InIter
name|iter_type
typedef|;
comment|//@}
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|__string_type
expr_stmt|;
comment|/// Numpunct facet id.
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
comment|/**        *  @brief  Constructor performs initialization.        *        *  This is the constructor provided by the standard.        *        *  @param refs  Passed to the base facet class.       */
name|explicit
name|time_get
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
block|:
name|facet
argument_list|(
argument|__refs
argument_list|)
block|{ }
comment|/**        *  @brief  Return preferred order of month, day, and year.        *        *  This function returns an enum from timebase::dateorder giving the        *  preferred ordering if the format "x" given to time_put::put() only        *  uses month, day, and year.  If the format "x" for the associated        *  locale uses other fields, this function returns        *  timebase::dateorder::noorder.        *        *  NOTE: The library always returns noorder at the moment.        *        *  @return  A member of timebase::dateorder.       */
name|dateorder
name|date_order
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_date_order
argument_list|()
return|;
block|}
comment|/**        *  @brief  Parse input time string.        *        *  This function parses a time according to the format "x" and puts the        *  results into a user-supplied struct tm.  The result is returned by        *  calling time_get::do_get_time().        *        *  If there is a valid time string according to format "x", @a tm will        *  be filled in accordingly and the returned iterator will point to the        *  first character beyond the time string.  If an error occurs before        *  the end, err |= ios_base::failbit.  If parsing reads all the        *  characters, err |= ios_base::eofbit.        *        *  @param  beg  Start of string to parse.        *  @param  end  End of string to parse.        *  @param  io  Source of the locale.        *  @param  err  Error flags to set.        *  @param  tm  Pointer to struct tm to fill in.        *  @return  Iterator to first char beyond time string.       */
name|iter_type
name|get_time
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get_time
argument_list|(
name|__beg
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__tm
argument_list|)
return|;
block|}
comment|/**        *  @brief  Parse input date string.        *        *  This function parses a date according to the format "X" and puts the        *  results into a user-supplied struct tm.  The result is returned by        *  calling time_get::do_get_date().        *        *  If there is a valid date string according to format "X", @a tm will        *  be filled in accordingly and the returned iterator will point to the        *  first character beyond the date string.  If an error occurs before        *  the end, err |= ios_base::failbit.  If parsing reads all the        *  characters, err |= ios_base::eofbit.        *        *  @param  beg  Start of string to parse.        *  @param  end  End of string to parse.        *  @param  io  Source of the locale.        *  @param  err  Error flags to set.        *  @param  tm  Pointer to struct tm to fill in.        *  @return  Iterator to first char beyond date string.       */
name|iter_type
name|get_date
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get_date
argument_list|(
name|__beg
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__tm
argument_list|)
return|;
block|}
comment|/**        *  @brief  Parse input weekday string.        *        *  This function parses a weekday name and puts the results into a        *  user-supplied struct tm.  The result is returned by calling        *  time_get::do_get_weekday().        *        *  Parsing starts by parsing an abbreviated weekday name.  If a valid        *  abbreviation is followed by a character that would lead to the full        *  weekday name, parsing continues until the full name is found or an        *  error occurs.  Otherwise parsing finishes at the end of the        *  abbreviated name.        *        *  If an error occurs before the end, err |= ios_base::failbit.  If        *  parsing reads all the characters, err |= ios_base::eofbit.        *        *  @param  beg  Start of string to parse.        *  @param  end  End of string to parse.        *  @param  io  Source of the locale.        *  @param  err  Error flags to set.        *  @param  tm  Pointer to struct tm to fill in.        *  @return  Iterator to first char beyond weekday name.       */
name|iter_type
name|get_weekday
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get_weekday
argument_list|(
name|__beg
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__tm
argument_list|)
return|;
block|}
comment|/**        *  @brief  Parse input month string.        *        *  This function parses a month name and puts the results into a        *  user-supplied struct tm.  The result is returned by calling        *  time_get::do_get_monthname().        *        *  Parsing starts by parsing an abbreviated month name.  If a valid        *  abbreviation is followed by a character that would lead to the full        *  month name, parsing continues until the full name is found or an        *  error occurs.  Otherwise parsing finishes at the end of the        *  abbreviated name.        *        *  If an error occurs before the end, err |= ios_base::failbit.  If        *  parsing reads all the characters, err |=        *  ios_base::eofbit.        *        *  @param  beg  Start of string to parse.        *  @param  end  End of string to parse.        *  @param  io  Source of the locale.        *  @param  err  Error flags to set.        *  @param  tm  Pointer to struct tm to fill in.        *  @return  Iterator to first char beyond month name.       */
name|iter_type
name|get_monthname
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get_monthname
argument_list|(
name|__beg
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__tm
argument_list|)
return|;
block|}
comment|/**        *  @brief  Parse input year string.        *        *  This function reads up to 4 characters to parse a year string and        *  puts the results into a user-supplied struct tm.  The result is        *  returned by calling time_get::do_get_year().        *        *  4 consecutive digits are interpreted as a full year.  If there are        *  exactly 2 consecutive digits, the library interprets this as the        *  number of years since 1900.        *        *  If an error occurs before the end, err |= ios_base::failbit.  If        *  parsing reads all the characters, err |= ios_base::eofbit.        *        *  @param  beg  Start of string to parse.        *  @param  end  End of string to parse.        *  @param  io  Source of the locale.        *  @param  err  Error flags to set.        *  @param  tm  Pointer to struct tm to fill in.        *  @return  Iterator to first char beyond year.       */
name|iter_type
name|get_year
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get_year
argument_list|(
name|__beg
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__tm
argument_list|)
return|;
block|}
name|protected
label|:
comment|/// Destructor.
name|virtual
operator|~
name|time_get
argument_list|()
block|{ }
comment|/**        *  @brief  Return preferred order of month, day, and year.        *        *  This function returns an enum from timebase::dateorder giving the        *  preferred ordering if the format "x" given to time_put::put() only        *  uses month, day, and year.  This function is a hook for derived        *  classes to change the value returned.        *        *  @return  A member of timebase::dateorder.       */
name|virtual
name|dateorder
name|do_date_order
argument_list|()
specifier|const
expr_stmt|;
comment|/**        *  @brief  Parse input time string.        *        *  This function parses a time according to the format "x" and puts the        *  results into a user-supplied struct tm.  This function is a hook for        *  derived classes to change the value returned.  @see get_time() for        *  details.        *        *  @param  beg  Start of string to parse.        *  @param  end  End of string to parse.        *  @param  io  Source of the locale.        *  @param  err  Error flags to set.        *  @param  tm  Pointer to struct tm to fill in.        *  @return  Iterator to first char beyond time string.       */
name|virtual
name|iter_type
name|do_get_time
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
decl_stmt|;
comment|/**        *  @brief  Parse input date string.        *        *  This function parses a date according to the format "X" and puts the        *  results into a user-supplied struct tm.  This function is a hook for        *  derived classes to change the value returned.  @see get_date() for        *  details.        *        *  @param  beg  Start of string to parse.        *  @param  end  End of string to parse.        *  @param  io  Source of the locale.        *  @param  err  Error flags to set.        *  @param  tm  Pointer to struct tm to fill in.        *  @return  Iterator to first char beyond date string.       */
name|virtual
name|iter_type
name|do_get_date
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
decl_stmt|;
comment|/**        *  @brief  Parse input weekday string.        *        *  This function parses a weekday name and puts the results into a        *  user-supplied struct tm.  This function is a hook for derived        *  classes to change the value returned.  @see get_weekday() for        *  details.        *        *  @param  beg  Start of string to parse.        *  @param  end  End of string to parse.        *  @param  io  Source of the locale.        *  @param  err  Error flags to set.        *  @param  tm  Pointer to struct tm to fill in.        *  @return  Iterator to first char beyond weekday name.       */
name|virtual
name|iter_type
name|do_get_weekday
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
decl_stmt|;
comment|/**        *  @brief  Parse input month string.        *        *  This function parses a month name and puts the results into a        *  user-supplied struct tm.  This function is a hook for derived        *  classes to change the value returned.  @see get_monthname() for        *  details.        *        *  @param  beg  Start of string to parse.        *  @param  end  End of string to parse.        *  @param  io  Source of the locale.        *  @param  err  Error flags to set.        *  @param  tm  Pointer to struct tm to fill in.        *  @return  Iterator to first char beyond month name.       */
name|virtual
name|iter_type
name|do_get_monthname
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
decl_stmt|;
comment|/**        *  @brief  Parse input year string.        *        *  This function reads up to 4 characters to parse a year string and        *  puts the results into a user-supplied struct tm.  This function is a        *  hook for derived classes to change the value returned.  @see        *  get_year() for details.        *        *  @param  beg  Start of string to parse.        *  @param  end  End of string to parse.        *  @param  io  Source of the locale.        *  @param  err  Error flags to set.        *  @param  tm  Pointer to struct tm to fill in.        *  @return  Iterator to first char beyond year.       */
name|virtual
name|iter_type
name|do_get_year
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
decl_stmt|;
comment|// Extract numeric component of length __len.
name|iter_type
name|_M_extract_num
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|int
operator|&
name|__member
argument_list|,
name|int
name|__min
argument_list|,
name|int
name|__max
argument_list|,
name|size_t
name|__len
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|)
decl|const
decl_stmt|;
comment|// Extract day or month name, or any unique array of string
comment|// literals in a const _CharT* array.
name|iter_type
name|_M_extract_name
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|int
operator|&
name|__member
argument_list|,
specifier|const
name|_CharT
operator|*
operator|*
name|__names
argument_list|,
name|size_t
name|__indexlen
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|)
decl|const
decl_stmt|;
comment|// Extract on a component-by-component basis, via __format argument.
name|iter_type
name|_M_extract_via_format
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|,
specifier|const
name|_CharT
operator|*
name|__format
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_InIter
operator|>
name|locale
operator|::
name|id
name|time_get
operator|<
name|_CharT
operator|,
name|_InIter
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @brief  class time_get_byname [22.2.5.2].
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_InIter
operator|>
name|class
name|time_get_byname
operator|:
name|public
name|time_get
operator|<
name|_CharT
operator|,
name|_InIter
operator|>
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_InIter
name|iter_type
typedef|;
end_typedef

begin_macro
name|explicit
end_macro

begin_macro
name|time_get_byname
argument_list|(
argument|const char*
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|time_get
operator|<
name|_CharT
operator|,
name|_InIter
operator|>
operator|(
name|__refs
operator|)
block|{ }
name|protected
operator|:
name|virtual
operator|~
name|time_get_byname
argument_list|()
block|{ }
end_expr_stmt

begin_comment
unit|};
comment|/**    *  @brief  Facet for outputting dates and times.    *    *  This facet encapsulates the code to format and output dates and times    *  according to formats used by strftime().    *    *  The time_put template uses protected virtual functions to provide the    *  actual results.  The public accessors forward the call to the virtual    *  functions.  These virtual functions are hooks for developers to    *  implement the behavior they require from the time_put facet.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|>
name|class
name|time_put
operator|:
name|public
name|locale
operator|::
name|facet
block|{
name|public
operator|:
comment|// Types:
comment|//@{
comment|/// Public typedefs
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_OutIter
name|iter_type
typedef|;
end_typedef

begin_comment
comment|//@}
end_comment

begin_comment
comment|/// Numpunct facet id.
end_comment

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Constructor performs initialization.        *        *  This is the constructor provided by the standard.        *        *  @param refs  Passed to the base facet class.       */
end_comment

begin_macro
name|explicit
end_macro

begin_macro
name|time_put
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_macro
unit|:
name|facet
argument_list|(
argument|__refs
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_comment
comment|/**        *  @brief  Format and output a time or date.        *        *  This function formats the data in struct tm according to the        *  provided format string.  The format string is interpreted as by        *  strftime().        *        *  @param  s  The stream to write to.        *  @param  io  Source of locale.        *  @param  fill  char_type to use for padding.        *  @param  tm  Struct tm with date and time info to format.        *  @param  beg  Start of format string.        *  @param  end  End of format string.        *  @return  Iterator after writing.        */
end_comment

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
name|__fill
argument_list|,
specifier|const
name|tm
operator|*
name|__tm
argument_list|,
specifier|const
name|_CharT
operator|*
name|__beg
argument_list|,
specifier|const
name|_CharT
operator|*
name|__end
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Format and output a time or date.        *        *  This function formats the data in struct tm according to the        *  provided format char and optional modifier.  The format and modifier        *  are interpreted as by strftime().  It does so by returning        *  time_put::do_put().        *        *  @param  s  The stream to write to.        *  @param  io  Source of locale.        *  @param  fill  char_type to use for padding.        *  @param  tm  Struct tm with date and time info to format.        *  @param  format  Format char.        *  @param  mod  Optional modifier char.        *  @return  Iterator after writing.        */
end_comment

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
name|__fill
argument_list|,
specifier|const
name|tm
operator|*
name|__tm
argument_list|,
name|char
name|__format
argument_list|,
name|char
name|__mod
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__io
argument_list|,
name|__fill
argument_list|,
name|__tm
argument_list|,
name|__format
argument_list|,
name|__mod
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// Destructor.
end_comment

begin_expr_stmt
name|virtual
operator|~
name|time_put
argument_list|()
block|{ }
comment|/**        *  @brief  Format and output a time or date.        *        *  This function formats the data in struct tm according to the        *  provided format char and optional modifier.  This function is a hook        *  for derived classes to change the value returned.  @see put() for        *  more details.        *        *  @param  s  The stream to write to.        *  @param  io  Source of locale.        *  @param  fill  char_type to use for padding.        *  @param  tm  Struct tm with date and time info to format.        *  @param  format  Format char.        *  @param  mod  Optional modifier char.        *  @return  Iterator after writing.        */
name|virtual
name|iter_type
name|do_put
argument_list|(
argument|iter_type __s
argument_list|,
argument|ios_base& __io
argument_list|,
argument|char_type __fill
argument_list|,
argument|const tm* __tm
argument_list|,
argument|char __format
argument_list|,
argument|char __mod
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|>
name|locale
operator|::
name|id
name|time_put
operator|<
name|_CharT
operator|,
name|_OutIter
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @brief  class time_put_byname [22.2.5.4].
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|>
name|class
name|time_put_byname
operator|:
name|public
name|time_put
operator|<
name|_CharT
operator|,
name|_OutIter
operator|>
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_OutIter
name|iter_type
typedef|;
end_typedef

begin_macro
name|explicit
end_macro

begin_macro
name|time_put_byname
argument_list|(
argument|const char*
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|time_put
operator|<
name|_CharT
operator|,
name|_OutIter
operator|>
operator|(
name|__refs
operator|)
block|{ }
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|time_put_byname
argument_list|()
block|{ }
end_expr_stmt

begin_comment
unit|};
comment|/**    *  @brief  Money format ordering data.    *    *  This class contains an ordered array of 4 fields to represent the    *  pattern for formatting a money amount.  Each field may contain one entry    *  from the part enum.  symbol, sign, and value must be present and the    *  remaining field must contain either none or space.  @see    *  moneypunct::pos_format() and moneypunct::neg_format() for details of how    *  these fields are interpreted.   */
end_comment

begin_decl_stmt
name|class
name|money_base
block|{
name|public
label|:
enum|enum
name|part
block|{
name|none
block|,
name|space
block|,
name|symbol
block|,
name|sign
block|,
name|value
block|}
enum|;
struct|struct
name|pattern
block|{
name|char
name|field
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
specifier|static
specifier|const
name|pattern
name|_S_default_pattern
decl_stmt|;
enum|enum
block|{
name|_S_minus
block|,
name|_S_zero
block|,
name|_S_end
init|=
literal|11
block|}
enum|;
comment|// String literal of acceptable (narrow) input/output, for
comment|// money_get/money_put. "-0123456789"
specifier|static
specifier|const
name|char
modifier|*
name|_S_atoms
decl_stmt|;
comment|// Construct and return valid pattern consisting of some combination of:
comment|// space none symbol sign value
specifier|static
name|pattern
name|_S_construct_pattern
parameter_list|(
name|char
name|__precedes
parameter_list|,
name|char
name|__space
parameter_list|,
name|char
name|__posn
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|bool
name|_Intl
operator|>
expr|struct
name|__moneypunct_cache
operator|:
name|public
name|locale
operator|::
name|facet
block|{
specifier|const
name|char
operator|*
name|_M_grouping
block|;
name|size_t
name|_M_grouping_size
block|;
name|bool
name|_M_use_grouping
block|;
name|_CharT
name|_M_decimal_point
block|;
name|_CharT
name|_M_thousands_sep
block|;
specifier|const
name|_CharT
operator|*
name|_M_curr_symbol
block|;
name|size_t
name|_M_curr_symbol_size
block|;
specifier|const
name|_CharT
operator|*
name|_M_positive_sign
block|;
name|size_t
name|_M_positive_sign_size
block|;
specifier|const
name|_CharT
operator|*
name|_M_negative_sign
block|;
name|size_t
name|_M_negative_sign_size
block|;
name|int
name|_M_frac_digits
block|;
name|money_base
operator|::
name|pattern
name|_M_pos_format
block|;
name|money_base
operator|::
name|pattern
name|_M_neg_format
block|;
comment|// A list of valid numeric literals for input and output: in the standard
comment|// "C" locale, this is "-0123456789". This array contains the chars after
comment|// having been passed through the current locale's ctype<_CharT>.widen().
name|_CharT
name|_M_atoms
index|[
name|money_base
operator|::
name|_S_end
index|]
block|;
name|bool
name|_M_allocated
block|;
name|__moneypunct_cache
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
operator|:
name|facet
argument_list|(
name|__refs
argument_list|)
block|,
name|_M_grouping
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_grouping_size
argument_list|(
literal|0
argument_list|)
block|,
name|_M_use_grouping
argument_list|(
name|false
argument_list|)
block|,
name|_M_decimal_point
argument_list|(
name|_CharT
argument_list|()
argument_list|)
block|,
name|_M_thousands_sep
argument_list|(
name|_CharT
argument_list|()
argument_list|)
block|,
name|_M_curr_symbol
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_curr_symbol_size
argument_list|(
literal|0
argument_list|)
block|,
name|_M_positive_sign
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_positive_sign_size
argument_list|(
literal|0
argument_list|)
block|,
name|_M_negative_sign
argument_list|(
name|NULL
argument_list|)
block|,
name|_M_negative_sign_size
argument_list|(
literal|0
argument_list|)
block|,
name|_M_frac_digits
argument_list|(
literal|0
argument_list|)
block|,
name|_M_pos_format
argument_list|(
name|money_base
operator|::
name|pattern
argument_list|()
argument_list|)
block|,
name|_M_neg_format
argument_list|(
name|money_base
operator|::
name|pattern
argument_list|()
argument_list|)
block|,
name|_M_allocated
argument_list|(
argument|false
argument_list|)
block|{ }
operator|~
name|__moneypunct_cache
argument_list|()
block|;
name|void
name|_M_cache
argument_list|(
specifier|const
name|locale
operator|&
name|__loc
argument_list|)
block|;
name|private
operator|:
name|__moneypunct_cache
operator|&
name|operator
operator|=
operator|(
specifier|const
name|__moneypunct_cache
operator|&
operator|)
block|;
name|explicit
name|__moneypunct_cache
argument_list|(
specifier|const
name|__moneypunct_cache
operator|&
argument_list|)
block|;     }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|bool
name|_Intl
operator|>
name|__moneypunct_cache
operator|<
name|_CharT
operator|,
name|_Intl
operator|>
operator|::
operator|~
name|__moneypunct_cache
argument_list|()
block|{
if|if
condition|(
name|_M_allocated
condition|)
block|{
name|delete
index|[]
name|_M_grouping
decl_stmt|;
name|delete
index|[]
name|_M_curr_symbol
decl_stmt|;
name|delete
index|[]
name|_M_positive_sign
decl_stmt|;
name|delete
index|[]
name|_M_negative_sign
decl_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|/**    *  @brief  Facet for formatting data for money amounts.    *    *  This facet encapsulates the punctuation, grouping and other formatting    *  features of money amount string representations.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_CharT
operator|,
name|bool
name|_Intl
operator|>
name|class
name|moneypunct
operator|:
name|public
name|locale
operator|::
name|facet
operator|,
name|public
name|money_base
block|{
name|public
operator|:
comment|// Types:
comment|//@{
comment|/// Public typedefs
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_comment
comment|//@}
end_comment

begin_typedef
typedef|typedef
name|__moneypunct_cache
operator|<
name|_CharT
operator|,
name|_Intl
operator|>
name|__cache_type
expr_stmt|;
end_typedef

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|__cache_type
modifier|*
name|_M_data
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// This value is provided by the standard, but no reason for its
end_comment

begin_comment
comment|/// existence.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|intl
init|=
name|_Intl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Numpunct facet id.
end_comment

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Constructor performs initialization.        *        *  This is the constructor provided by the standard.        *        *  @param refs  Passed to the base facet class.       */
end_comment

begin_macro
name|explicit
end_macro

begin_macro
name|moneypunct
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|facet
argument_list|(
name|__refs
argument_list|)
operator|,
name|_M_data
argument_list|(
argument|NULL
argument_list|)
block|{
name|_M_initialize_moneypunct
argument_list|()
block|; }
comment|/**        *  @brief  Constructor performs initialization.        *        *  This is an internal constructor.        *        *  @param cache  Cache for optimization.        *  @param refs  Passed to the base facet class.       */
name|explicit
name|moneypunct
argument_list|(
argument|__cache_type* __cache
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
operator|:
name|facet
argument_list|(
name|__refs
argument_list|)
operator|,
name|_M_data
argument_list|(
argument|__cache
argument_list|)
block|{
name|_M_initialize_moneypunct
argument_list|()
block|; }
comment|/**        *  @brief  Internal constructor. Not for general use.        *        *  This is a constructor for use by the library itself to set up new        *  locales.        *        *  @param cloc  The "C" locale.        *  @param s  The name of a locale.        *  @param refs  Passed to the base facet class.       */
name|explicit
name|moneypunct
argument_list|(
argument|__c_locale __cloc
argument_list|,
argument|const char* __s
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
operator|:
name|facet
argument_list|(
name|__refs
argument_list|)
operator|,
name|_M_data
argument_list|(
argument|NULL
argument_list|)
block|{
name|_M_initialize_moneypunct
argument_list|(
name|__cloc
argument_list|,
name|__s
argument_list|)
block|; }
comment|/**        *  @brief  Return decimal point character.        *        *  This function returns a char_type to use as a decimal point.  It        *  does so by returning returning        *  moneypunct<char_type>::do_decimal_point().        *        *  @return  @a char_type representing a decimal point.       */
name|char_type
name|decimal_point
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_decimal_point
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return thousands separator character.        *        *  This function returns a char_type to use as a thousands        *  separator.  It does so by returning returning        *  moneypunct<char_type>::do_thousands_sep().        *        *  @return  char_type representing a thousands separator.       */
end_comment

begin_expr_stmt
name|char_type
name|thousands_sep
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_thousands_sep
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return grouping specification.        *        *  This function returns a string representing groupings for the        *  integer part of an amount.  Groupings indicate where thousands        *  separators should be inserted.        *        *  Each char in the return string is interpret as an integer rather        *  than a character.  These numbers represent the number of digits in a        *  group.  The first char in the string represents the number of digits        *  in the least significant group.  If a char is negative, it indicates        *  an unlimited number of digits for the group.  If more chars from the        *  string are required to group a number, the last char is used        *  repeatedly.        *        *  For example, if the grouping() returns "\003\002" and is applied to        *  the number 123456789, this corresponds to 12,34,56,789.  Note that        *  if the string was "32", this would put more than 50 digits into the        *  least significant group if the character set is ASCII.        *        *  The string is returned by calling        *  moneypunct<char_type>::do_grouping().        *        *  @return  string representing grouping specification.       */
end_comment

begin_expr_stmt
name|string
name|grouping
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_grouping
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return currency symbol string.        *        *  This function returns a string_type to use as a currency symbol.  It        *  does so by returning returning        *  moneypunct<char_type>::do_curr_symbol().        *        *  @return  @a string_type representing a currency symbol.       */
end_comment

begin_expr_stmt
name|string_type
name|curr_symbol
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_curr_symbol
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return positive sign string.        *        *  This function returns a string_type to use as a sign for positive        *  amounts.  It does so by returning returning        *  moneypunct<char_type>::do_positive_sign().        *        *  If the return value contains more than one character, the first        *  character appears in the position indicated by pos_format() and the        *  remainder appear at the end of the formatted string.        *        *  @return  @a string_type representing a positive sign.       */
end_comment

begin_expr_stmt
name|string_type
name|positive_sign
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_positive_sign
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return negative sign string.        *        *  This function returns a string_type to use as a sign for negative        *  amounts.  It does so by returning returning        *  moneypunct<char_type>::do_negative_sign().        *        *  If the return value contains more than one character, the first        *  character appears in the position indicated by neg_format() and the        *  remainder appear at the end of the formatted string.        *        *  @return  @a string_type representing a negative sign.       */
end_comment

begin_expr_stmt
name|string_type
name|negative_sign
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_negative_sign
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return number of digits in fraction.        *        *  This function returns the exact number of digits that make up the        *  fractional part of a money amount.  It does so by returning        *  returning moneypunct<char_type>::do_frac_digits().        *        *  The fractional part of a money amount is optional.  But if it is        *  present, there must be frac_digits() digits.        *        *  @return  Number of digits in amount fraction.       */
end_comment

begin_expr_stmt
name|int
name|frac_digits
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_frac_digits
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|//@{
end_comment

begin_comment
comment|/**        *  @brief  Return pattern for money values.        *        *  This function returns a pattern describing the formatting of a        *  positive or negative valued money amount.  It does so by returning        *  returning moneypunct<char_type>::do_pos_format() or        *  moneypunct<char_type>::do_neg_format().        *        *  The pattern has 4 fields describing the ordering of symbol, sign,        *  value, and none or space.  There must be one of each in the pattern.        *  The none and space enums may not appear in the first field and space        *  may not appear in the final field.        *        *  The parts of a money string must appear in the order indicated by        *  the fields of the pattern.  The symbol field indicates that the        *  value of curr_symbol() may be present.  The sign field indicates        *  that the value of positive_sign() or negative_sign() must be        *  present.  The value field indicates that the absolute value of the        *  money amount is present.  none indicates 0 or more whitespace        *  characters, except at the end, where it permits no whitespace.        *  space indicates that 1 or more whitespace characters must be        *  present.        *        *  For example, for the US locale and pos_format() pattern        *  {symbol,sign,value,none}, curr_symbol() == '$' positive_sign() ==        *  '+', and value 10.01, and options set to force the symbol, the        *  corresponding string is "$+10.01".        *        *  @return  Pattern for money values.       */
end_comment

begin_expr_stmt
name|pattern
name|pos_format
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_pos_format
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|pattern
name|neg_format
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_neg_format
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|//@}
end_comment

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// Destructor.
end_comment

begin_expr_stmt
name|virtual
operator|~
name|moneypunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return decimal point character.        *        *  Returns a char_type to use as a decimal point.  This function is a        *  hook for derived classes to change the value returned.        *        *  @return  @a char_type representing a decimal point.       */
end_comment

begin_expr_stmt
name|virtual
name|char_type
name|do_decimal_point
argument_list|()
specifier|const
block|{
return|return
name|_M_data
operator|->
name|_M_decimal_point
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return thousands separator character.        *        *  Returns a char_type to use as a thousands separator.  This function        *  is a hook for derived classes to change the value returned.        *        *  @return  @a char_type representing a thousands separator.       */
end_comment

begin_expr_stmt
name|virtual
name|char_type
name|do_thousands_sep
argument_list|()
specifier|const
block|{
return|return
name|_M_data
operator|->
name|_M_thousands_sep
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return grouping specification.        *        *  Returns a string representing groupings for the integer part of a        *  number.  This function is a hook for derived classes to change the        *  value returned.  @see grouping() for details.        *        *  @return  String representing grouping specification.       */
end_comment

begin_expr_stmt
name|virtual
name|string
name|do_grouping
argument_list|()
specifier|const
block|{
return|return
name|_M_data
operator|->
name|_M_grouping
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return currency symbol string.        *        *  This function returns a string_type to use as a currency symbol.        *  This function is a hook for derived classes to change the value        *  returned.  @see curr_symbol() for details.        *        *  @return  @a string_type representing a currency symbol.       */
end_comment

begin_expr_stmt
name|virtual
name|string_type
name|do_curr_symbol
argument_list|()
specifier|const
block|{
return|return
name|_M_data
operator|->
name|_M_curr_symbol
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return positive sign string.        *        *  This function returns a string_type to use as a sign for positive        *  amounts.  This function is a hook for derived classes to change the        *  value returned.  @see positive_sign() for details.        *        *  @return  @a string_type representing a positive sign.       */
end_comment

begin_expr_stmt
name|virtual
name|string_type
name|do_positive_sign
argument_list|()
specifier|const
block|{
return|return
name|_M_data
operator|->
name|_M_positive_sign
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return negative sign string.        *        *  This function returns a string_type to use as a sign for negative        *  amounts.  This function is a hook for derived classes to change the        *  value returned.  @see negative_sign() for details.        *        *  @return  @a string_type representing a negative sign.       */
end_comment

begin_expr_stmt
name|virtual
name|string_type
name|do_negative_sign
argument_list|()
specifier|const
block|{
return|return
name|_M_data
operator|->
name|_M_negative_sign
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return number of digits in fraction.        *        *  This function returns the exact number of digits that make up the        *  fractional part of a money amount.  This function is a hook for        *  derived classes to change the value returned.  @see frac_digits()        *  for details.        *        *  @return  Number of digits in amount fraction.       */
end_comment

begin_expr_stmt
name|virtual
name|int
name|do_frac_digits
argument_list|()
specifier|const
block|{
return|return
name|_M_data
operator|->
name|_M_frac_digits
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return pattern for money values.        *        *  This function returns a pattern describing the formatting of a        *  positive valued money amount.  This function is a hook for derived        *  classes to change the value returned.  @see pos_format() for        *  details.        *        *  @return  Pattern for money values.       */
end_comment

begin_expr_stmt
name|virtual
name|pattern
name|do_pos_format
argument_list|()
specifier|const
block|{
return|return
name|_M_data
operator|->
name|_M_pos_format
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Return pattern for money values.        *        *  This function returns a pattern describing the formatting of a        *  negative valued money amount.  This function is a hook for derived        *  classes to change the value returned.  @see neg_format() for        *  details.        *        *  @return  Pattern for money values.       */
end_comment

begin_expr_stmt
name|virtual
name|pattern
name|do_neg_format
argument_list|()
specifier|const
block|{
return|return
name|_M_data
operator|->
name|_M_neg_format
return|;
block|}
end_expr_stmt

begin_comment
comment|// For use at construction time only.
end_comment

begin_function_decl
name|void
name|_M_initialize_moneypunct
parameter_list|(
name|__c_locale
name|__cloc
init|=
name|NULL
parameter_list|,
specifier|const
name|char
modifier|*
name|__name
init|=
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|bool
name|_Intl
operator|>
name|locale
operator|::
name|id
name|moneypunct
operator|<
name|_CharT
operator|,
name|_Intl
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|bool
name|_Intl
operator|>
specifier|const
name|bool
name|moneypunct
operator|<
name|_CharT
operator|,
name|_Intl
operator|>
operator|::
name|intl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|moneypunct
operator|<
name|char
operator|,
name|true
operator|>
operator|::
operator|~
name|moneypunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|moneypunct
operator|<
name|char
operator|,
name|false
operator|>
operator|::
operator|~
name|moneypunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|moneypunct
operator|<
name|char
operator|,
name|true
operator|>
operator|::
name|_M_initialize_moneypunct
argument_list|(
name|__c_locale
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|moneypunct
operator|<
name|char
operator|,
name|false
operator|>
operator|::
name|_M_initialize_moneypunct
argument_list|(
name|__c_locale
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
name|moneypunct
operator|<
name|wchar_t
operator|,
name|true
operator|>
operator|::
operator|~
name|moneypunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|moneypunct
operator|<
name|wchar_t
operator|,
name|false
operator|>
operator|::
operator|~
name|moneypunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|moneypunct
operator|<
name|wchar_t
operator|,
name|true
operator|>
operator|::
name|_M_initialize_moneypunct
argument_list|(
name|__c_locale
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|moneypunct
operator|<
name|wchar_t
operator|,
name|false
operator|>
operator|::
name|_M_initialize_moneypunct
argument_list|(
name|__c_locale
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// @brief  class moneypunct_byname [22.2.6.4].
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|bool
name|_Intl
operator|>
name|class
name|moneypunct_byname
operator|:
name|public
name|moneypunct
operator|<
name|_CharT
operator|,
name|_Intl
operator|>
block|{
name|public
operator|:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|intl
init|=
name|_Intl
decl_stmt|;
end_decl_stmt

begin_macro
name|explicit
end_macro

begin_macro
name|moneypunct_byname
argument_list|(
argument|const char* __s
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|moneypunct
operator|<
name|_CharT
operator|,
name|_Intl
operator|>
operator|(
name|__refs
operator|)
block|{
if|if
condition|(
name|std
operator|::
name|strcmp
argument_list|(
name|__s
argument_list|,
literal|"C"
argument_list|)
operator|!=
literal|0
operator|&&
name|std
operator|::
name|strcmp
argument_list|(
name|__s
argument_list|,
literal|"POSIX"
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|__c_locale
name|__tmp
decl_stmt|;
name|this
operator|->
name|_S_create_c_locale
argument_list|(
name|__tmp
argument_list|,
name|__s
argument_list|)
expr_stmt|;
name|this
operator|->
name|_M_initialize_moneypunct
argument_list|(
name|__tmp
argument_list|)
expr_stmt|;
name|this
operator|->
name|_S_destroy_c_locale
argument_list|(
name|__tmp
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}      protected:
name|virtual
operator|~
name|moneypunct_byname
argument_list|()
block|{ }
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|bool
name|_Intl
operator|>
specifier|const
name|bool
name|moneypunct_byname
operator|<
name|_CharT
operator|,
name|_Intl
operator|>
operator|::
name|intl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_GLIBCXX_BEGIN_LDBL_NAMESPACE
comment|/**    *  @brief  Facet for parsing monetary amounts.    *    *  This facet encapsulates the code to parse and return a monetary    *  amount from a string.    *    *  The money_get template uses protected virtual functions to    *  provide the actual results.  The public accessors forward the    *  call to the virtual functions.  These virtual functions are    *  hooks for developers to implement the behavior they require from    *  the money_get facet.   */
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_InIter
operator|>
name|class
name|money_get
operator|:
name|public
name|locale
operator|::
name|facet
block|{
name|public
operator|:
comment|// Types:
comment|//@{
comment|/// Public typedefs
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_InIter
name|iter_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_comment
comment|//@}
end_comment

begin_comment
comment|/// Numpunct facet id.
end_comment

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Constructor performs initialization.        *        *  This is the constructor provided by the standard.        *        *  @param refs  Passed to the base facet class.       */
end_comment

begin_macro
name|explicit
end_macro

begin_macro
name|money_get
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_macro
unit|:
name|facet
argument_list|(
argument|__refs
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_comment
comment|/**        *  @brief  Read and parse a monetary value.        *        *  This function reads characters from @a s, interprets them as a        *  monetary value according to moneypunct and ctype facets retrieved        *  from io.getloc(), and returns the result in @a units as an integral        *  value moneypunct::frac_digits() * the actual amount.  For example,        *  the string $10.01 in a US locale would store 1001 in @a units.        *        *  Any characters not part of a valid money amount are not consumed.        *        *  If a money value cannot be parsed from the input stream, sets        *  err=(err|io.failbit).  If the stream is consumed before finishing        *  parsing,  sets err=(err|io.failbit|io.eofbit).  @a units is        *  unchanged if parsing fails.        *        *  This function works by returning the result of do_get().        *        *  @param  s  Start of characters to parse.        *  @param  end  End of characters to parse.        *  @param  intl  Parameter to use_facet<moneypunct<CharT,intl>>.        *  @param  io  Source of facets and io state.        *  @param  err  Error field to set if parsing fails.        *  @param  units  Place to store result of parsing.        *  @return  Iterator referencing first character beyond valid money        *	   amount.        */
end_comment

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__s
argument_list|,
name|iter_type
name|__end
argument_list|,
name|bool
name|__intl
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|long
name|double
operator|&
name|__units
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__s
argument_list|,
name|__end
argument_list|,
name|__intl
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__units
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Read and parse a monetary value.        *        *  This function reads characters from @a s, interprets them as a        *  monetary value according to moneypunct and ctype facets retrieved        *  from io.getloc(), and returns the result in @a digits.  For example,        *  the string $10.01 in a US locale would store "1001" in @a digits.        *        *  Any characters not part of a valid money amount are not consumed.        *        *  If a money value cannot be parsed from the input stream, sets        *  err=(err|io.failbit).  If the stream is consumed before finishing        *  parsing,  sets err=(err|io.failbit|io.eofbit).        *        *  This function works by returning the result of do_get().        *        *  @param  s  Start of characters to parse.        *  @param  end  End of characters to parse.        *  @param  intl  Parameter to use_facet<moneypunct<CharT,intl>>.        *  @param  io  Source of facets and io state.        *  @param  err  Error field to set if parsing fails.        *  @param  digits  Place to store result of parsing.        *  @return  Iterator referencing first character beyond valid money        *	   amount.        */
end_comment

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__s
argument_list|,
name|iter_type
name|__end
argument_list|,
name|bool
name|__intl
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|string_type
operator|&
name|__digits
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__s
argument_list|,
name|__end
argument_list|,
name|__intl
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__digits
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// Destructor.
end_comment

begin_expr_stmt
name|virtual
operator|~
name|money_get
argument_list|()
block|{ }
comment|/**        *  @brief  Read and parse a monetary value.        *        *  This function reads and parses characters representing a monetary        *  value.  This function is a hook for derived classes to change the        *  value returned.  @see get() for details.        */
comment|// XXX GLIBCXX_ABI Deprecated
if|#
directive|if
name|defined
name|_GLIBCXX_LONG_DOUBLE_COMPAT
operator|&&
name|defined
name|__LONG_DOUBLE_128__
name|virtual
name|iter_type
name|__do_get
argument_list|(
argument|iter_type __s
argument_list|,
argument|iter_type __end
argument_list|,
argument|bool __intl
argument_list|,
argument|ios_base& __io
argument_list|,
argument|ios_base::iostate& __err
argument_list|,
argument|double& __units
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
name|__s
argument_list|,
name|iter_type
name|__end
argument_list|,
name|bool
name|__intl
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|long
name|double
operator|&
name|__units
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**        *  @brief  Read and parse a monetary value.        *        *  This function reads and parses characters representing a monetary        *  value.  This function is a hook for derived classes to change the        *  value returned.  @see get() for details.        */
end_comment

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
name|__s
argument_list|,
name|iter_type
name|__end
argument_list|,
name|bool
name|__intl
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|string_type
operator|&
name|__digits
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// XXX GLIBCXX_ABI Deprecated
end_comment

begin_if
if|#
directive|if
name|defined
name|_GLIBCXX_LONG_DOUBLE_COMPAT
operator|&&
name|defined
name|__LONG_DOUBLE_128__
end_if

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
name|__s
argument_list|,
name|iter_type
name|__end
argument_list|,
name|bool
name|__intl
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|long
name|double
operator|&
name|__units
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|template
operator|<
name|bool
name|_Intl
operator|>
name|iter_type
name|_M_extract
argument_list|(
argument|iter_type __s
argument_list|,
argument|iter_type __end
argument_list|,
argument|ios_base& __io
argument_list|,
argument|ios_base::iostate& __err
argument_list|,
argument|string& __digits
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_InIter
operator|>
name|locale
operator|::
name|id
name|money_get
operator|<
name|_CharT
operator|,
name|_InIter
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**    *  @brief  Facet for outputting monetary amounts.    *    *  This facet encapsulates the code to format and output a monetary    *  amount.    *    *  The money_put template uses protected virtual functions to    *  provide the actual results.  The public accessors forward the    *  call to the virtual functions.  These virtual functions are    *  hooks for developers to implement the behavior they require from    *  the money_put facet.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|>
name|class
name|money_put
operator|:
name|public
name|locale
operator|::
name|facet
block|{
name|public
operator|:
comment|//@{
comment|/// Public typedefs
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_OutIter
name|iter_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_comment
comment|//@}
end_comment

begin_comment
comment|/// Numpunct facet id.
end_comment

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Constructor performs initialization.        *        *  This is the constructor provided by the standard.        *        *  @param refs  Passed to the base facet class.       */
end_comment

begin_macro
name|explicit
end_macro

begin_macro
name|money_put
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_macro
unit|:
name|facet
argument_list|(
argument|__refs
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_comment
comment|/**        *  @brief  Format and output a monetary value.        *        *  This function formats @a units as a monetary value according to        *  moneypunct and ctype facets retrieved from io.getloc(), and writes        *  the resulting characters to @a s.  For example, the value 1001 in a        *  US locale would write "$10.01" to @a s.        *        *  This function works by returning the result of do_put().        *        *  @param  s  The stream to write to.        *  @param  intl  Parameter to use_facet<moneypunct<CharT,intl>>.        *  @param  io  Source of facets and io state.        *  @param  fill  char_type to use for padding.        *  @param  units  Place to store result of parsing.        *  @return  Iterator after writing.        */
end_comment

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|bool
name|__intl
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
name|__fill
argument_list|,
name|long
name|double
name|__units
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__intl
argument_list|,
name|__io
argument_list|,
name|__fill
argument_list|,
name|__units
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Format and output a monetary value.        *        *  This function formats @a digits as a monetary value according to        *  moneypunct and ctype facets retrieved from io.getloc(), and writes        *  the resulting characters to @a s.  For example, the string "1001" in        *  a US locale would write "$10.01" to @a s.        *        *  This function works by returning the result of do_put().        *        *  @param  s  The stream to write to.        *  @param  intl  Parameter to use_facet<moneypunct<CharT,intl>>.        *  @param  io  Source of facets and io state.        *  @param  fill  char_type to use for padding.        *  @param  units  Place to store result of parsing.        *  @return  Iterator after writing.        */
end_comment

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|bool
name|__intl
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
name|__fill
argument_list|,
specifier|const
name|string_type
operator|&
name|__digits
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__intl
argument_list|,
name|__io
argument_list|,
name|__fill
argument_list|,
name|__digits
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// Destructor.
end_comment

begin_expr_stmt
name|virtual
operator|~
name|money_put
argument_list|()
block|{ }
comment|/**        *  @brief  Format and output a monetary value.        *        *  This function formats @a units as a monetary value according to        *  moneypunct and ctype facets retrieved from io.getloc(), and writes        *  the resulting characters to @a s.  For example, the value 1001 in a        *  US locale would write "$10.01" to @a s.        *        *  This function is a hook for derived classes to change the value        *  returned.  @see put().        *        *  @param  s  The stream to write to.        *  @param  intl  Parameter to use_facet<moneypunct<CharT,intl>>.        *  @param  io  Source of facets and io state.        *  @param  fill  char_type to use for padding.        *  @param  units  Place to store result of parsing.        *  @return  Iterator after writing.        */
comment|// XXX GLIBCXX_ABI Deprecated
if|#
directive|if
name|defined
name|_GLIBCXX_LONG_DOUBLE_COMPAT
operator|&&
name|defined
name|__LONG_DOUBLE_128__
name|virtual
name|iter_type
name|__do_put
argument_list|(
argument|iter_type __s
argument_list|,
argument|bool __intl
argument_list|,
argument|ios_base& __io
argument_list|,
argument|char_type __fill
argument_list|,
argument|double __units
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|bool
name|__intl
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
name|__fill
argument_list|,
name|long
name|double
name|__units
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**        *  @brief  Format and output a monetary value.        *        *  This function formats @a digits as a monetary value according to        *  moneypunct and ctype facets retrieved from io.getloc(), and writes        *  the resulting characters to @a s.  For example, the string "1001" in        *  a US locale would write "$10.01" to @a s.        *        *  This function is a hook for derived classes to change the value        *  returned.  @see put().        *        *  @param  s  The stream to write to.        *  @param  intl  Parameter to use_facet<moneypunct<CharT,intl>>.        *  @param  io  Source of facets and io state.        *  @param  fill  char_type to use for padding.        *  @param  units  Place to store result of parsing.        *  @return  Iterator after writing.        */
end_comment

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|bool
name|__intl
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
name|__fill
argument_list|,
specifier|const
name|string_type
operator|&
name|__digits
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// XXX GLIBCXX_ABI Deprecated
end_comment

begin_if
if|#
directive|if
name|defined
name|_GLIBCXX_LONG_DOUBLE_COMPAT
operator|&&
name|defined
name|__LONG_DOUBLE_128__
end_if

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|bool
name|__intl
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
name|__fill
argument_list|,
name|long
name|double
name|__units
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|template
operator|<
name|bool
name|_Intl
operator|>
name|iter_type
name|_M_insert
argument_list|(
argument|iter_type __s
argument_list|,
argument|ios_base& __io
argument_list|,
argument|char_type __fill
argument_list|,
argument|const string_type& __digits
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|>
name|locale
operator|::
name|id
name|money_put
operator|<
name|_CharT
operator|,
name|_OutIter
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|_GLIBCXX_END_LDBL_NAMESPACE
comment|/**    *  @brief  Messages facet base class providing catalog typedef.    */
name|class
name|messages_base
block|{
name|public
label|:
typedef|typedef
name|int
name|catalog
typedef|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**    *  @brief  Facet for handling message catalogs    *    *  This facet encapsulates the code to retrieve messages from    *  message catalogs.  The only thing defined by the standard for this facet    *  is the interface.  All underlying functionality is    *  implementation-defined.    *    *  This library currently implements 3 versions of the message facet.  The    *  first version (gnu) is a wrapper around gettext, provided by libintl.    *  The second version (ieee) is a wrapper around catgets.  The final    *  version (default) does no actual translation.  These implementations are    *  only provided for char and wchar_t instantiations.    *    *  The messages template uses protected virtual functions to    *  provide the actual results.  The public accessors forward the    *  call to the virtual functions.  These virtual functions are    *  hooks for developers to implement the behavior they require from    *  the messages facet.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|messages
operator|:
name|public
name|locale
operator|::
name|facet
operator|,
name|public
name|messages_base
block|{
name|public
operator|:
comment|// Types:
comment|//@{
comment|/// Public typedefs
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_comment
comment|//@}
end_comment

begin_label
name|protected
label|:
end_label

begin_comment
comment|// Underlying "C" library locale information saved from
end_comment

begin_comment
comment|// initialization, needed by messages_byname as well.
end_comment

begin_decl_stmt
name|__c_locale
name|_M_c_locale_messages
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|_M_name_messages
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Numpunct facet id.
end_comment

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Constructor performs initialization.        *        *  This is the constructor provided by the standard.        *        *  @param refs  Passed to the base facet class.       */
end_comment

begin_function_decl
name|explicit
name|messages
parameter_list|(
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Non-standard.
end_comment

begin_comment
comment|/**        *  @brief  Internal constructor.  Not for general use.        *        *  This is a constructor for use by the library itself to set up new        *  locales.        *        *  @param  cloc  The "C" locale.        *  @param  s  The name of a locale.        *  @param  refs  Refcount to pass to the base class.        */
end_comment

begin_function_decl
name|explicit
name|messages
parameter_list|(
name|__c_locale
name|__cloc
parameter_list|,
specifier|const
name|char
modifier|*
name|__s
parameter_list|,
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*        *  @brief  Open a message catalog.        *        *  This function opens and returns a handle to a message catalog by        *  returning do_open(s, loc).        *        *  @param  s  The catalog to open.        *  @param  loc  Locale to use for character set conversions.        *  @return  Handle to the catalog or value< 0 if open fails.       */
end_comment

begin_decl_stmt
name|catalog
name|open
argument_list|(
specifier|const
name|basic_string
operator|<
name|char
operator|>
operator|&
name|__s
argument_list|,
specifier|const
name|locale
operator|&
name|__loc
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_open
argument_list|(
name|__s
argument_list|,
name|__loc
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Non-standard and unorthodox, yet effective.
end_comment

begin_comment
comment|/*        *  @brief  Open a message catalog.        *        *  This non-standard function opens and returns a handle to a message        *  catalog by returning do_open(s, loc).  The third argument provides a        *  message catalog root directory for gnu gettext and is ignored        *  otherwise.        *        *  @param  s  The catalog to open.        *  @param  loc  Locale to use for character set conversions.        *  @param  dir  Message catalog root directory.        *  @return  Handle to the catalog or value< 0 if open fails.       */
end_comment

begin_decl_stmt
name|catalog
name|open
argument_list|(
specifier|const
name|basic_string
operator|<
name|char
operator|>
operator|&
argument_list|,
specifier|const
name|locale
operator|&
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*        *  @brief  Look up a string in a message catalog.        *        *  This function retrieves and returns a message from a catalog by        *  returning do_get(c, set, msgid, s).        *        *  For gnu, @a set and @a msgid are ignored.  Returns gettext(s).        *  For default, returns s. For ieee, returns catgets(c,set,msgid,s).        *        *  @param  c  The catalog to access.        *  @param  set  Implementation-defined.        *  @param  msgid  Implementation-defined.        *  @param  s  Default return value if retrieval fails.        *  @return  Retrieved message or @a s if get fails.       */
end_comment

begin_decl_stmt
name|string_type
name|get
argument_list|(
name|catalog
name|__c
argument_list|,
name|int
name|__set
argument_list|,
name|int
name|__msgid
argument_list|,
specifier|const
name|string_type
operator|&
name|__s
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__c
argument_list|,
name|__set
argument_list|,
name|__msgid
argument_list|,
name|__s
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/*        *  @brief  Close a message catalog.        *        *  Closes catalog @a c by calling do_close(c).        *        *  @param  c  The catalog to close.       */
end_comment

begin_decl_stmt
name|void
name|close
argument_list|(
name|catalog
name|__c
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_close
argument_list|(
name|__c
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// Destructor.
end_comment

begin_expr_stmt
name|virtual
operator|~
name|messages
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*        *  @brief  Open a message catalog.        *        *  This function opens and returns a handle to a message catalog in an        *  implementation-defined manner.  This function is a hook for derived        *  classes to change the value returned.        *        *  @param  s  The catalog to open.        *  @param  loc  Locale to use for character set conversions.        *  @return  Handle to the opened catalog, value< 0 if open failed.       */
end_comment

begin_decl_stmt
name|virtual
name|catalog
name|do_open
argument_list|(
specifier|const
name|basic_string
operator|<
name|char
operator|>
operator|&
argument_list|,
specifier|const
name|locale
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*        *  @brief  Look up a string in a message catalog.        *        *  This function retrieves and returns a message from a catalog in an        *  implementation-defined manner.  This function is a hook for derived        *  classes to change the value returned.        *        *  For gnu, @a set and @a msgid are ignored.  Returns gettext(s).        *  For default, returns s. For ieee, returns catgets(c,set,msgid,s).        *        *  @param  c  The catalog to access.        *  @param  set  Implementation-defined.        *  @param  msgid  Implementation-defined.        *  @param  s  Default return value if retrieval fails.        *  @return  Retrieved message or @a s if get fails.       */
end_comment

begin_decl_stmt
name|virtual
name|string_type
name|do_get
argument_list|(
name|catalog
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
specifier|const
name|string_type
operator|&
name|__dfault
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*        *  @brief  Close a message catalog.        *        *  @param  c  The catalog to close.       */
end_comment

begin_decl_stmt
name|virtual
name|void
name|do_close
argument_list|(
name|catalog
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Returns a locale and codeset-converted string, given a char* message.
end_comment

begin_decl_stmt
name|char
modifier|*
name|_M_convert_to_char
argument_list|(
specifier|const
name|string_type
operator|&
name|__msg
argument_list|)
decl|const
block|{
comment|// XXX
return|return
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|_CharT
operator|*
operator|>
operator|(
name|__msg
operator|.
name|c_str
argument_list|()
operator|)
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Returns a locale and codeset-converted string, given a char* message.
end_comment

begin_decl_stmt
name|string_type
name|_M_convert_from_char
argument_list|(
name|char
operator|*
argument_list|)
decl|const
block|{
if|#
directive|if
literal|0
comment|// Length of message string without terminating null.
block|size_t __len = char_traits<char>::length(__msg) - 1;
comment|// "everybody can easily convert the string using
comment|// mbsrtowcs/wcsrtombs or with iconv()"
comment|// Convert char* to _CharT in locale used to open catalog.
comment|// XXX need additional template parameter on messages class for this..
comment|// typedef typename codecvt<char, _CharT, _StateT> __codecvt_type;
block|typedef typename codecvt<char, _CharT, mbstate_t> __codecvt_type;  	__codecvt_type::state_type __state;
comment|// XXX may need to initialize state.
comment|//initialize_state(__state._M_init());
block|char* __from_next;
comment|// XXX what size for this string?
block|_CharT* __to = static_cast<_CharT*>(__builtin_alloca(__len + 1)); 	const __codecvt_type& __cvt = use_facet<__codecvt_type>(_M_locale_conv); 	__cvt.out(__state, __msg, __msg + __len, __from_next, 		  __to, __to + __len + 1, __to_next); 	return string_type(__to);
endif|#
directive|endif
if|#
directive|if
literal|0
block|typedef ctype<_CharT> __ctype_type;
comment|// const __ctype_type& __cvt = use_facet<__ctype_type>(_M_locale_msg);
block|const __ctype_type& __cvt = use_facet<__ctype_type>(locale());
comment|// XXX Again, proper length of converted string an issue here.
comment|// For now, assume the converted length is not larger.
block|_CharT* __dest = static_cast<_CharT*>(__builtin_alloca(__len + 1)); 	__cvt.widen(__msg, __msg + __len, __dest); 	return basic_string<_CharT>(__dest);
endif|#
directive|endif
return|return
name|string_type
argument_list|()
return|;
block|}
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|>
name|locale
operator|::
name|id
name|messages
operator|<
name|_CharT
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Specializations for required instantiations.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|string
name|messages
operator|<
name|char
operator|>
operator|::
name|do_get
argument_list|(
argument|catalog
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument|const string&
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
name|wstring
name|messages
operator|<
name|wchar_t
operator|>
operator|::
name|do_get
argument_list|(
argument|catalog
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument|const wstring&
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// @brief class messages_byname [22.2.7.2].
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|messages_byname
operator|:
name|public
name|messages
operator|<
name|_CharT
operator|>
block|{
name|public
operator|:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_function_decl
name|explicit
name|messages_byname
parameter_list|(
specifier|const
name|char
modifier|*
name|__s
parameter_list|,
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|messages_byname
argument_list|()
block|{ }
end_expr_stmt

begin_decl_stmt
unit|};
name|_GLIBCXX_END_NAMESPACE
comment|// Include host and configuration specific messages functions.
include|#
directive|include
file|<bits/messages_members.h>
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
name|std
argument_list|)
comment|// Subclause convenience interfaces, inlines.
comment|// NB: These are inline because, when used in a loop, some compilers
comment|// can hoist the body out of the loop; then it's just as fast as the
comment|// C is*() function.
comment|/// Convenience interface to ctype.is(ctype_base::space, __c).
name|template
decl|<
name|typename
name|_CharT
decl|>
specifier|inline
namespace|bool
name|isspace
namespace|(
name|_CharT
name|__c
operator|,
namespace|const
name|locale
namespace|&
name|__loc
decl_stmt|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|space
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Convenience interface to ctype.is(ctype_base::print, __c).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|isprint
argument_list|(
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|print
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Convenience interface to ctype.is(ctype_base::cntrl, __c).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|iscntrl
argument_list|(
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|cntrl
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Convenience interface to ctype.is(ctype_base::upper, __c).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|isupper
argument_list|(
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|upper
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Convenience interface to ctype.is(ctype_base::lower, __c).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|islower
argument_list|(
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|lower
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Convenience interface to ctype.is(ctype_base::alpha, __c).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|isalpha
argument_list|(
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|alpha
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Convenience interface to ctype.is(ctype_base::digit, __c).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|isdigit
argument_list|(
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|digit
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Convenience interface to ctype.is(ctype_base::punct, __c).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|ispunct
argument_list|(
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|punct
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Convenience interface to ctype.is(ctype_base::xdigit, __c).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|isxdigit
argument_list|(
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|xdigit
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Convenience interface to ctype.is(ctype_base::alnum, __c).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|isalnum
argument_list|(
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|alnum
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Convenience interface to ctype.is(ctype_base::graph, __c).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|isgraph
argument_list|(
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|graph
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Convenience interface to ctype.toupper(__c).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|_CharT
name|toupper
argument_list|(
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|toupper
argument_list|(
name|__c
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Convenience interface to ctype.tolower(__c).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|_CharT
name|tolower
argument_list|(
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|tolower
argument_list|(
name|__c
argument_list|)
return|;
block|}
end_expr_stmt

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

