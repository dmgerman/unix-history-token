begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Input streams -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2001, 2002 Free Software Foundation, Inc.
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
comment|// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
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
comment|//
end_comment

begin_comment
comment|// ISO C++ 14882: 27.6.1  Input streams
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/** @file istream  *  This is a Standard C++ Library header.  You should @c #include this header  *  in your programs, rather than any of the "st[dl]_*.h" implementation files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_ISTREAM
end_ifndef

begin_define
define|#
directive|define
name|_CPP_ISTREAM
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
file|<ios>
end_include

begin_include
include|#
directive|include
file|<limits>
end_include

begin_comment
comment|// For numeric_limits
end_comment

begin_decl_stmt
name|namespace
name|std
block|{
comment|// [27.6.1.1] Template class basic_istream
comment|/**    *  @brief  Controlling input.    *    *  This is the base class for all input streams.  It provides text    *  formatting of all builtin types, and communicates with any class    *  derived from basic_streambuf to do the actual input.   */
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
name|class
name|basic_istream
operator|:
name|virtual
name|public
name|basic_ios
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
block|{
name|public
operator|:
comment|// Types (inherited from basic_ios (27.4.4)):
typedef|typedef
name|_CharT
name|char_type
typedef|;
typedef|typedef
name|typename
name|_Traits
operator|::
name|int_type
name|int_type
expr_stmt|;
typedef|typedef
name|typename
name|_Traits
operator|::
name|pos_type
name|pos_type
expr_stmt|;
typedef|typedef
name|typename
name|_Traits
operator|::
name|off_type
name|off_type
expr_stmt|;
typedef|typedef
name|_Traits
name|traits_type
typedef|;
comment|// Non-standard Types:
typedef|typedef
name|basic_streambuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|__streambuf_type
expr_stmt|;
typedef|typedef
name|basic_ios
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|__ios_type
expr_stmt|;
typedef|typedef
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|__istream_type
expr_stmt|;
typedef|typedef
name|istreambuf_iterator
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|__istreambuf_iter
expr_stmt|;
typedef|typedef
name|num_get
operator|<
name|_CharT
operator|,
name|__istreambuf_iter
operator|>
name|__numget_type
expr_stmt|;
typedef|typedef
name|ctype
operator|<
name|_CharT
operator|>
name|__ctype_type
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT2
operator|,
name|typename
name|_Traits2
operator|>
name|friend
name|basic_istream
operator|<
name|_CharT2
operator|,
name|_Traits2
operator|>
operator|&
name|operator
operator|>>
operator|(
name|basic_istream
operator|<
name|_CharT2
operator|,
name|_Traits2
operator|>
operator|&
operator|,
name|_CharT2
operator|&
operator|)
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT2
operator|,
name|typename
name|_Traits2
operator|>
name|friend
name|basic_istream
operator|<
name|_CharT2
operator|,
name|_Traits2
operator|>
operator|&
name|operator
operator|>>
operator|(
name|basic_istream
operator|<
name|_CharT2
operator|,
name|_Traits2
operator|>
operator|&
operator|,
name|_CharT2
operator|*
operator|)
expr_stmt|;
name|protected
label|:
comment|// Data Members:
comment|/**        *  @if maint        *  The number of characters extracted in the previous unformatted        *  function; see gcount().        *  @endif       */
name|streamsize
name|_M_gcount
decl_stmt|;
name|public
label|:
comment|// [27.6.1.1.1] constructor/destructor
comment|/**        *  @brief  Base constructor.        *        *  This ctor is almost never called by the user directly, rather from        *  derived classes' initialization lists, which pass a pointer to        *  their own stream buffer.       */
name|explicit
name|basic_istream
parameter_list|(
name|__streambuf_type
modifier|*
name|__sb
parameter_list|)
block|{
name|this
operator|->
name|init
argument_list|(
name|__sb
argument_list|)
expr_stmt|;
name|_M_gcount
operator|=
name|streamsize
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/**        *  @brief  Base destructor.        *        *  This does very little apart from providing a virtual base dtor.       */
name|virtual
operator|~
name|basic_istream
argument_list|()
block|{
name|_M_gcount
operator|=
name|streamsize
argument_list|(
literal|0
argument_list|)
block|; }
comment|// [27.6.1.1.2] prefix/suffix
name|class
name|sentry
expr_stmt|;
name|friend
name|class
name|sentry
decl_stmt|;
comment|// [27.6.1.2] formatted input
comment|// [27.6.1.2.3] basic_istream::operator>>
comment|//@{
comment|/**        *  @brief  Interface for manipulators.        *        *  Manuipulators such as @c std::ws and @c std::dec use these        *  functions in constructs like "std::cin>> std::ws".  For more        *  information, see the iomanip header.       */
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|__istream_type
operator|&
call|(
modifier|*
name|__pf
call|)
argument_list|(
name|__istream_type
operator|&
argument_list|)
operator|)
expr_stmt|;
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|__ios_type
operator|&
call|(
modifier|*
name|__pf
call|)
argument_list|(
name|__ios_type
operator|&
argument_list|)
operator|)
expr_stmt|;
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|ios_base
operator|&
call|(
modifier|*
name|__pf
call|)
argument_list|(
name|ios_base
operator|&
argument_list|)
operator|)
expr_stmt|;
comment|//@}
comment|// [27.6.1.2.2] arithmetic extractors
comment|/**        *  @name Arithmetic Extractors        *        *  All the @c operator>> functions (aka<em>formatted input        *  functions</em>) have some common behavior.  Each starts by        *  constructing a temporary object of type std::basic_istream::sentry        *  with the second argument (noskipws) set to false.  This has several        *  effects, concluding with the setting of a status flag; see the        *  sentry documentation for more.        *        *  If the sentry status is good, the function tries to extract        *  whatever data is appropriate for the type of the argument.        *        *  If an exception is thrown during extraction, ios_base::badbit        *  will be turned on in the stream's error state without causing an        *  ios_base::failure to be thrown.  The original exception will then        *  be rethrown.       */
comment|//@{
comment|/**        *  @brief  Basic arithmetic extractors        *  @param  A variable of builtin type.        *  @return  @c *this if successful        *        *  These functions use the stream's current locale (specifically, the        *  @c num_get facet) to parse the input data.       */
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|bool
operator|&
name|__n
operator|)
expr_stmt|;
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|short
operator|&
name|__n
operator|)
expr_stmt|;
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|unsigned
name|short
operator|&
name|__n
operator|)
expr_stmt|;
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|int
operator|&
name|__n
operator|)
expr_stmt|;
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|unsigned
name|int
operator|&
name|__n
operator|)
expr_stmt|;
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|long
operator|&
name|__n
operator|)
expr_stmt|;
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|unsigned
name|long
operator|&
name|__n
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_LONG_LONG
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|long
name|long
operator|&
name|__n
operator|)
expr_stmt|;
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|unsigned
name|long
name|long
operator|&
name|__n
operator|)
expr_stmt|;
endif|#
directive|endif
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|float
operator|&
name|__f
operator|)
expr_stmt|;
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|double
operator|&
name|__f
operator|)
expr_stmt|;
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|long
name|double
operator|&
name|__f
operator|)
expr_stmt|;
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|void
operator|*
operator|&
name|__p
operator|)
expr_stmt|;
comment|/**        *  @brief  Extracting into another streambuf.        *  @param  sb  A pointer to a streambuf        *        *  This function behaves like one of the basic arithmetic extractors,        *  in that it also constructs a sentry onject and has the same error        *  handling behavior.        *        *  If @a sb is NULL, the stream will set failbit in its error state.        *        *  Characters are extracted from this stream and inserted into the        *  @a sb streambuf until one of the following occurs:        *        *  - the input stream reaches end-of-file,        *  - insertion into the output buffer fails (in this case, the        *    character that would have been inserted is not extracted), or        *  - an exception occurs (and in this case is caught)        *        *  If the function inserts no characters, failbit is set.       */
name|__istream_type
operator|&
name|operator
operator|>>
operator|(
name|__streambuf_type
operator|*
name|__sb
operator|)
expr_stmt|;
comment|//@}
comment|// [27.6.1.3] unformatted input
comment|/**        *  @brief  Character counting        *  @return  The number of characters extracted by the previous        *           unformatted input function dispatched for this stream.       */
specifier|inline
name|streamsize
name|gcount
argument_list|()
specifier|const
block|{
return|return
name|_M_gcount
return|;
block|}
comment|/**        *  @name Unformatted Input Functions        *        *  All the unformatted input functions have some common behavior.        *  Each starts by constructing a temporary object of type        *  std::basic_istream::sentry with the second argument (noskipws)        *  set to true.  This has several effects, concluding with the        *  setting of a status flag; see the sentry documentation for more.        *        *  If the sentry status is good, the function tries to extract        *  whatever data is appropriate for the type of the argument.        *        *  The number of characters extracted is stored for later retrieval        *  by gcount().        *        *  If an exception is thrown during extraction, ios_base::badbit        *  will be turned on in the stream's error state without causing an        *  ios_base::failure to be thrown.  The original exception will then        *  be rethrown.       */
comment|//@{
comment|/**        *  @brief  Simple extraction.        *  @return  A character, or eof().        *        *  Tries to extract a character.  If none are available, sets failbit        *  and returns traits::eof().       */
name|int_type
name|get
parameter_list|()
function_decl|;
comment|/**        *  @brief  Simple extraction.        *  @param  c  The character in which to store data.        *  @return  *this        *        *  Tries to extract a character and store it in @a c.  If none are        *  available, sets failbit and returns traits::eof().        *        *  @note  This function is not overloaded on signed char and        *         unsigned char.       */
name|__istream_type
modifier|&
name|get
parameter_list|(
name|char_type
modifier|&
name|__c
parameter_list|)
function_decl|;
comment|/**        *  @brief  Simple multiple-character extraction.        *  @param  s  Pointer to an array.        *  @param  n  Maximum number of characters to store in @a s.        *  @param  delim  A "stop" character.        *  @return  *this        *        *  Characters are extracted and stored into @a s until one of the        *  following happens:        *        *  - @c n-1 characters are stored        *  - the input sequence reaches EOF        *  - the next character equals @a delim, in which case the character        *    is not extracted        *        * If no characters are stored, failbit is set in the stream's error        * state.        *        * In any case, a null character is stored into the next location in        * the array.        *        *  @note  This function is not overloaded on signed char and        *         unsigned char.       */
name|__istream_type
modifier|&
name|get
parameter_list|(
name|char_type
modifier|*
name|__s
parameter_list|,
name|streamsize
name|__n
parameter_list|,
name|char_type
name|__delim
parameter_list|)
function_decl|;
comment|/**        *  @brief  Simple multiple-character extraction.        *  @param  s  Pointer to an array.        *  @param  n  Maximum number of characters to store in @a s.        *  @return  *this        *        *  Returns @c get(s,n,widen('\n')).       */
specifier|inline
name|__istream_type
modifier|&
name|get
parameter_list|(
name|char_type
modifier|*
name|__s
parameter_list|,
name|streamsize
name|__n
parameter_list|)
block|{
return|return
name|this
operator|->
name|get
argument_list|(
name|__s
argument_list|,
name|__n
argument_list|,
name|this
operator|->
name|widen
argument_list|(
literal|'\n'
argument_list|)
argument_list|)
return|;
block|}
comment|/**        *  @brief  Extraction into another streambuf.        *  @param  sb  A streambuf in which to store data.        *  @param  delim  A "stop" character.        *  @return  *this        *        *  Characters are extracted and inserted into @a sb until one of the        *  following happens:        *        *  - the input sequence reaches EOF        *  - insertion into the output buffer fails (in this case, the        *    character that would have been inserted is not extracted)        *  - the next character equals @a delim (in this case, the character        *    is not extracted)        *  - an exception occurs (and in this case is caught)        *        * If no characters are stored, failbit is set in the stream's error        * state.       */
name|__istream_type
modifier|&
name|get
parameter_list|(
name|__streambuf_type
modifier|&
name|__sb
parameter_list|,
name|char_type
name|__delim
parameter_list|)
function_decl|;
comment|/**        *  @brief  Extraction into another streambuf.        *  @param  sb  A streambuf in which to store data.        *  @return  *this        *        *  Returns @c get(sb,widen('\n')).       */
specifier|inline
name|__istream_type
modifier|&
name|get
parameter_list|(
name|__streambuf_type
modifier|&
name|__sb
parameter_list|)
block|{
return|return
name|this
operator|->
name|get
argument_list|(
name|__sb
argument_list|,
name|this
operator|->
name|widen
argument_list|(
literal|'\n'
argument_list|)
argument_list|)
return|;
block|}
comment|/**        *  @brief  String extraction.        *  @param  s  A character array in which to store the data.        *  @param  n  Maximum number of characters to extract.        *  @param  delim  A "stop" character.        *  @return  *this        *        *  Extracts and stores characters into @a s until one of the        *  following happens.  Note that these criteria are required to be        *  tested in the order listed here, to allow an input line to exactly        *  fill the @a s array without setting failbit.        *        *  -# the input sequence reaches end-of-file, in which case eofbit        *     is set in the stream error state        *  -# the next character equals @c delim, in which case the character        *     is extracted (and therefore counted in @c gcount()) but not stored        *  -# @c n-1 characters are stored, in which case failbit is set        *     in the stream error state        *        *  If no characters are extracted, failbit is set.  (An empty line of        *  input should therefore not cause failbit to be set.)        *        *  In any case, a null character is stored in the next location in        *  the array.       */
name|__istream_type
modifier|&
name|getline
parameter_list|(
name|char_type
modifier|*
name|__s
parameter_list|,
name|streamsize
name|__n
parameter_list|,
name|char_type
name|__delim
parameter_list|)
function_decl|;
comment|/**        *  @brief  String extraction.        *  @param  s  A character array in which to store the data.        *  @param  n  Maximum number of characters to extract.        *  @return  *this        *        *  Returns @c getline(s,n,widen('\n')).       */
specifier|inline
name|__istream_type
modifier|&
name|getline
parameter_list|(
name|char_type
modifier|*
name|__s
parameter_list|,
name|streamsize
name|__n
parameter_list|)
block|{
return|return
name|this
operator|->
name|getline
argument_list|(
name|__s
argument_list|,
name|__n
argument_list|,
name|this
operator|->
name|widen
argument_list|(
literal|'\n'
argument_list|)
argument_list|)
return|;
block|}
comment|/**        *  @brief  Discarding characters        *  @param  n  Number of characters to discard.        *  @param  delim  A "stop" character.        *  @return  *this        *        *  Extracts characters and throws them away until one of the        *  following happens:        *  - if @a n @c != @c std::numeric_limits<int>::max(), @a n        *    characters are extracted        *  - the input sequence reaches end-of-file        *  - the next character equals @a delim (in this case, the character        *    is extracted); note that this condition will never occur if        *    @a delim equals @c traits::eof().       */
name|__istream_type
modifier|&
name|ignore
parameter_list|(
name|streamsize
name|__n
init|=
literal|1
parameter_list|,
name|int_type
name|__delim
init|=
name|traits_type
operator|::
name|eof
argument_list|()
parameter_list|)
function_decl|;
comment|/**        *  @brief  Looking ahead in the stream        *  @return  The next character, or eof().        *        *  If, after constructing the sentry object, @c good() is false,        *  returns @c traits::eof().  Otherwise reads but does not extract        *  the next input character.       */
name|int_type
name|peek
parameter_list|()
function_decl|;
comment|/**        *  @brief  Extraction without delimiters.        *  @param  s  A character array.        *  @param  n  Maximum number of characters to store.        *  @return  *this        *        *  If the stream state is @c good(), extracts characters and stores        *  them into @a s until one of the following happens:        *  - @a n characters are stored        *  - the input sequence reaches end-of-file, in which case the error        *    state is set to @c failbit|eofbit.        *        *  @note  This function is not overloaded on signed char and        *         unsigned char.       */
name|__istream_type
modifier|&
name|read
parameter_list|(
name|char_type
modifier|*
name|__s
parameter_list|,
name|streamsize
name|__n
parameter_list|)
function_decl|;
comment|/**        *  @brief  Extraction until the buffer is exhausted, but no more.        *  @param  s  A character array.        *  @param  n  Maximum number of characters to store.        *  @return  The number of characters extracted.        *        *  Extracts characters and stores them into @a s depending on the        *  number of characters remaining in the streambuf's buffer,        *  @c rdbuf()->in_avail(), called @c A here:        *  - if @c A @c == @c -1, sets eofbit and extracts no characters        *  - if @c A @c == @c 0, extracts no characters        *  - if @c A @c> @c 0, extracts @c min(A,n)        *        *  The goal is to empty the current buffer, and to not request any        *  more from the external input sequence controlled by the streambuf.       */
name|streamsize
name|readsome
parameter_list|(
name|char_type
modifier|*
name|__s
parameter_list|,
name|streamsize
name|__n
parameter_list|)
function_decl|;
comment|/**        *  @brief  Unextracting a single character.        *  @param  c  The character to push back into the input stream.        *  @return  *this        *        *  If @c rdbuf() is not null, calls @c rdbuf()->sputbackc(c).        *        *  If @c rdbuf() is null or if @c sputbackc() fails, sets badbit in        *  the error state.        *        *  @note  Since no characters are extracted, the next call to        *         @c gcount() will return 0, as required by DR 60.       */
name|__istream_type
modifier|&
name|putback
parameter_list|(
name|char_type
name|__c
parameter_list|)
function_decl|;
comment|/**        *  @brief  Unextracting the previous character.        *  @return  *this        *        *  If @c rdbuf() is not null, calls @c rdbuf()->sungetc(c).        *        *  If @c rdbuf() is null or if @c sungetc() fails, sets badbit in        *  the error state.        *        *  @note  Since no characters are extracted, the next call to        *         @c gcount() will return 0, as required by DR 60.       */
name|__istream_type
modifier|&
name|unget
parameter_list|()
function_decl|;
comment|/**        *  @brief  Synchronizing the stream buffer.        *  @return  0 on success, -1 on failure        *        *  If @c rdbuf() is a null pointer, returns -1.        *        *  Otherwise, calls @c rdbuf()->pubsync(), and if that returns -1,        *  sets badbit and returns -1.        *        *  Otherwise, returns 0.        *        *  @note  This function does not count the number of characters        *         extracted, if any, and therefore does not affect the next        *         call to @c gcount().       */
name|int
name|sync
parameter_list|()
function_decl|;
comment|/**        *  @brief  Getting the current read position.        *  @return  A file position object.        *        *  If @c fail() is not false, returns @c pos_type(-1) to indicate        *  failure.  Otherwise returns @c rdbuf()->pubseekoff(0,cur,in).        *        *  @note  This function does not count the number of characters        *         extracted, if any, and therefore does not affect the next        *         call to @c gcount().       */
name|pos_type
name|tellg
parameter_list|()
function_decl|;
comment|/**        *  @brief  Changing the current read position.        *  @param  pos  A file position object.        *  @return  *this        *        *  If @c fail() is not true, calls @c rdbuf()->pubseekpos(pos).  If        *  that function fails, sets failbit.        *        *  @note  This function does not count the number of characters        *         extracted, if any, and therefore does not affect the next        *         call to @c gcount().       */
name|__istream_type
modifier|&
name|seekg
parameter_list|(
name|pos_type
parameter_list|)
function_decl|;
comment|/**        *  @brief  Changing the current read position.        *  @param  off  A file offset object.        *  @param  dir  The direction in which to seek.        *  @return  *this        *        *  If @c fail() is not true, calls @c rdbuf()->pubseekoff(off,dir).        *  If that function fails, sets failbit.        *        *  @note  This function does not count the number of characters        *         extracted, if any, and therefore does not affect the next        *         call to @c gcount().       */
name|__istream_type
modifier|&
name|seekg
argument_list|(
name|off_type
argument_list|,
name|ios_base
operator|::
name|seekdir
argument_list|)
decl_stmt|;
comment|//@}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**    *  @brief  Performs setup work for input streams.    *    *  Objects of this class are created before all of the standard    *  extractors are run.  It is responsible for "exception-safe prefix and    *  suffix operations," although only prefix actions are currently required    *  by the standard.  Additional actions may be added by the    *  implementation, and we list them in    *  http://gcc.gnu.org/onlinedocs/libstdc++/17_intro/howto.html#5    *  under [27.6] notes.   */
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
name|class
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|::
name|sentry
block|{
name|public
operator|:
comment|/// Easy access to dependant types.
typedef|typedef
name|_Traits
name|traits_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_streambuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|__streambuf_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|__istream_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|__istream_type
operator|::
name|__ctype_type
name|__ctype_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Traits
operator|::
name|int_type
name|__int_type
expr_stmt|;
end_typedef

begin_comment
comment|/**        *  @brief  The constructor performs all the work.        *  @param  is  The input stream to guard.        *  @param  noskipws  Whether to consume whitespace or not.        *        *  If the stream state is good (@a is.good() is true), then the        *  following actions are performed, otherwise the sentry state is        *  false ("not okay") and failbit is set in the stream state.        *        *  The sentry's preparatory actions are:        *        *  -# if the stream is tied to an output stream, @c is.tie()->flush()        *     is called to synchronize the output sequence        *  -# if @a noskipws is false, and @c ios_base::skipws is set in        *     @c is.flags(), the sentry extracts and discards whitespace        *     characters from the stream.  The currently imbued locale is        *     used to determine whether each character is whitespace.        *        *  If the stream state is still good, then the sentry state becomes        *  true ("okay").       */
end_comment

begin_decl_stmt
name|explicit
name|sentry
argument_list|(
name|basic_istream
operator|<
name|_CharT
argument_list|,
name|_Traits
operator|>
operator|&
name|__is
argument_list|,
name|bool
name|__noskipws
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Quick status checking.        *  @return  The sentry state.        *        *  For ease of use, sentries may be converted to booleans.  The        *  return value is that of the sentry state (true == okay).       */
end_comment

begin_function
name|operator
name|bool
parameter_list|()
block|{
return|return
name|_M_ok
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|bool
name|_M_ok
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// [27.6.1.2.3] character extraction templates
end_comment

begin_comment
comment|//@{
end_comment

begin_comment
comment|/**    *  @brief  Character extractors    *  @param  in  An input stream.    *  @param  c  A character reference.    *  @return  in    *    *  Behaves like one of the formatted arithmetic extractors described in    *  std::basic_istream.  After constructing a sentry object with good    *  status, this function extracts a character (if one is available) and    *  stores it in @a c.  Otherwise, sets failbit in the input stream.   */
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
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|operator
operator|>>
operator|(
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|__in
operator|,
name|_CharT
operator|&
name|__c
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Traits
operator|>
name|basic_istream
operator|<
name|char
operator|,
name|_Traits
operator|>
operator|&
name|operator
operator|>>
operator|(
name|basic_istream
operator|<
name|char
operator|,
name|_Traits
operator|>
operator|&
name|__in
operator|,
name|unsigned
name|char
operator|&
name|__c
operator|)
block|{
return|return
operator|(
name|__in
operator|>>
name|reinterpret_cast
operator|<
name|char
operator|&
operator|>
operator|(
name|__c
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Traits
operator|>
name|basic_istream
operator|<
name|char
operator|,
name|_Traits
operator|>
operator|&
name|operator
operator|>>
operator|(
name|basic_istream
operator|<
name|char
operator|,
name|_Traits
operator|>
operator|&
name|__in
operator|,
name|signed
name|char
operator|&
name|__c
operator|)
block|{
return|return
operator|(
name|__in
operator|>>
name|reinterpret_cast
operator|<
name|char
operator|&
operator|>
operator|(
name|__c
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|//@}
end_comment

begin_comment
comment|//@{
end_comment

begin_comment
comment|/**    *  @brief  Character string extractors    *  @param  in  An input stream.    *  @param  s  A pointer to a character array.    *  @return  in    *    *  Behaves like one of the formatted arithmetic extractors described in    *  std::basic_istream.  After constructing a sentry object with good    *  status, this function extracts up to @c n characters and stores them    *  into the array starting at @a s.  @c n is defined as:    *    *  - if @c width() is greater than zero, @c n is width()    *  - otherwise @c n is "the number of elements of the largest array of    *    @c char_type that can store a terminating @c eos." [27.6.1.2.3]/6    *    *  Characters are extracted and stored until one of the following happens:    *  - @c n-1 characters are stored    *  - EOF is reached    *  - the next character is whitespace according to the current locale    *  - the next character is a null byte (i.e., @c charT() )    *    *  @c width(0) is then called for the input stream.    *    *  If no characters are extracted, sets failbit.   */
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
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|operator
operator|>>
operator|(
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|__in
operator|,
name|_CharT
operator|*
name|__s
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Traits
operator|>
name|basic_istream
operator|<
name|char
operator|,
name|_Traits
operator|>
operator|&
name|operator
operator|>>
operator|(
name|basic_istream
operator|<
name|char
operator|,
name|_Traits
operator|>
operator|&
name|__in
operator|,
name|unsigned
name|char
operator|*
name|__s
operator|)
block|{
return|return
operator|(
name|__in
operator|>>
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|__s
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Traits
operator|>
name|basic_istream
operator|<
name|char
operator|,
name|_Traits
operator|>
operator|&
name|operator
operator|>>
operator|(
name|basic_istream
operator|<
name|char
operator|,
name|_Traits
operator|>
operator|&
name|__in
operator|,
name|signed
name|char
operator|*
name|__s
operator|)
block|{
return|return
operator|(
name|__in
operator|>>
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|__s
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|//@}
end_comment

begin_comment
comment|// 27.6.1.5 Template class basic_iostream
end_comment

begin_comment
comment|/**    *  @brief  Merging istream and ostream capabilities.    *    *  This class multiply inherits from the input and output stream classes    *  simply to provide a single interface.   */
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
name|class
name|basic_iostream
operator|:
name|public
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|,
name|public
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
block|{
name|public
operator|:
ifdef|#
directive|ifdef
name|_GLIBCPP_RESOLVE_LIB_DEFECTS
comment|// 271. basic_iostream missing typedefs
comment|// Types (inherited):
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|_Traits
operator|::
name|int_type
name|int_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Traits
operator|::
name|pos_type
name|pos_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Traits
operator|::
name|off_type
name|off_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|_Traits
name|traits_type
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Non-standard Types:
end_comment

begin_typedef
typedef|typedef
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|__istream_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|__ostream_type
expr_stmt|;
end_typedef

begin_comment
comment|/**        *  @brief  Constructor does nothing.        *        *  Both of the parent classes are initialized with the same        *  streambuf pointer passed to this constructor.       */
end_comment

begin_decl_stmt
name|explicit
name|basic_iostream
argument_list|(
name|basic_streambuf
operator|<
name|_CharT
argument_list|,
name|_Traits
operator|>
operator|*
name|__sb
argument_list|)
range|:
name|__istream_type
argument_list|(
name|__sb
argument_list|)
decl_stmt|,
name|__ostream_type
argument_list|(
name|__sb
argument_list|)
block|{ }
end_decl_stmt

begin_comment
comment|/**        *  @brief  Destructor does nothing.       */
end_comment

begin_expr_stmt
name|virtual
operator|~
name|basic_iostream
argument_list|()
block|{ }
end_expr_stmt

begin_comment
unit|};
comment|// [27.6.1.4] standard basic_istream manipulators
end_comment

begin_comment
comment|/**    *  @brief  Quick and easy way to eat whitespace    *    *  This manipulator extracts whitespace characters, stopping when the    *  next character is non-whitespace, or when the input sequence is empty.    *  If the sequence is empty, @c eofbit is set in the stream, but not    *  @c failbit.    *    *  The current locale is used to distinguish whitespace characters.    *    *  Example:    *  @code    *     MyClass   mc;    *    *     std::cin>> std::ws>> mc;    *  @endcode    *  will skip leading whitespace before calling operator>> on cin and your    *  object.  Note that the same effect can be achieved by creating a    *  std::basic_istream::sentry inside your definition of operator>>.   */
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
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|ws
argument_list|(
name|basic_istream
operator|<
name|_CharT
argument_list|,
name|_Traits
operator|>
operator|&
name|__is
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// namespace std
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_NO_TEMPLATE_EXPORT
end_ifdef

begin_define
define|#
directive|define
name|export
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_FULLY_COMPLIANT_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|<bits/istream.tcc>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CPP_ISTREAM */
end_comment

end_unit

