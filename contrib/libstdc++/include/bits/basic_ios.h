begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Iostreams base classes -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2001, 2002, 2003
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
comment|/** @file basic_ios.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_BITS_BASICIOS_H
end_ifndef

begin_define
define|#
directive|define
name|_CPP_BITS_BASICIOS_H
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
file|<bits/streambuf_iterator.h>
end_include

begin_include
include|#
directive|include
file|<bits/localefwd.h>
end_include

begin_include
include|#
directive|include
file|<bits/locale_classes.h>
end_include

begin_include
include|#
directive|include
file|<bits/locale_facets.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|// 27.4.5  Template class basic_ios
comment|/**    *  @brief  Virtual base class for all stream classes.    *    *  Most of the member functions called dispatched on stream objects    *  (e.g., @c std::cout.foo(bar);) are consolidated in this class.   */
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
name|class
name|basic_ios
operator|:
name|public
name|ios_base
block|{
name|public
operator|:
comment|//@{
comment|/**        *  These are standard types.  They permit a standardized way of        *  referring to names of (or names dependant on) the template        *  parameters, which are specific to the implementation.       */
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
comment|//@}
comment|//@{
comment|/**        *  @if maint        *  These are non-standard types.        *  @endif       */
typedef|typedef
name|ctype
operator|<
name|_CharT
operator|>
name|__ctype_type
expr_stmt|;
typedef|typedef
name|ostreambuf_iterator
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|__ostreambuf_iter
expr_stmt|;
typedef|typedef
name|num_put
operator|<
name|_CharT
operator|,
name|__ostreambuf_iter
operator|>
name|__numput_type
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
comment|//@}
name|friend
name|void
name|ios_base
operator|::
name|Init
operator|::
name|_S_ios_create
argument_list|(
name|bool
argument_list|)
expr_stmt|;
comment|// Data members:
name|protected
label|:
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|*
name|_M_tie
expr_stmt|;
name|mutable
name|char_type
name|_M_fill
decl_stmt|;
name|mutable
name|bool
name|_M_fill_init
decl_stmt|;
name|basic_streambuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|*
name|_M_streambuf
expr_stmt|;
comment|// Cached use_facet<ctype>, which is based on the current locale info.
specifier|const
name|__ctype_type
modifier|*
name|_M_fctype
decl_stmt|;
comment|// From ostream.
specifier|const
name|__numput_type
modifier|*
name|_M_fnumput
decl_stmt|;
comment|// From istream.
specifier|const
name|__numget_type
modifier|*
name|_M_fnumget
decl_stmt|;
name|public
label|:
comment|//@{
comment|/**        *  @brief  The quick-and-easy status check.        *        *  This allows you to write constructs such as        *  "if (!a_stream) ..." and "while (a_stream) ..."       */
name|operator
name|void
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|fail
argument_list|()
operator|?
literal|0
operator|:
name|const_cast
operator|<
name|basic_ios
operator|*
operator|>
operator|(
name|this
operator|)
return|;
block|}
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|fail
argument_list|()
return|;
block|}
comment|//@}
comment|/**        *  @brief  Returns the error state of the stream buffer.        *  @return  A bit pattern (well, isn't everything?)        *        *  See std::ios_base::iostate for the possible bit values.  Most        *  users will call one of the interpreting wrappers, e.g., good().       */
name|iostate
name|rdstate
argument_list|()
specifier|const
block|{
return|return
name|_M_streambuf_state
return|;
block|}
comment|/**        *  @brief  [Re]sets the error state.        *  @param  state  The new state flag(s) to set.        *        *  See std::ios_base::iostate for the possible bit values.  Most        *  users will not need to pass an argument.       */
name|void
name|clear
parameter_list|(
name|iostate
name|__state
init|=
name|goodbit
parameter_list|)
function_decl|;
comment|/**        *  @brief  Sets additional flags in the error state.        *  @param  state  The additional state flag(s) to set.        *        *  See std::ios_base::iostate for the possible bit values.       */
name|void
name|setstate
parameter_list|(
name|iostate
name|__state
parameter_list|)
block|{
name|this
operator|->
name|clear
argument_list|(
name|this
operator|->
name|rdstate
argument_list|()
operator||
name|__state
argument_list|)
expr_stmt|;
block|}
comment|/**        *  @brief  Fast error checking.        *  @return  True if no error flags are set.        *        *  A wrapper around rdstate.       */
name|bool
name|good
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|rdstate
argument_list|()
operator|==
literal|0
return|;
block|}
comment|/**        *  @brief  Fast error checking.        *  @return  True if the eofbit is set.        *        *  Note that other iostate flags may also be set.       */
name|bool
name|eof
argument_list|()
specifier|const
block|{
return|return
operator|(
name|this
operator|->
name|rdstate
argument_list|()
operator|&
name|eofbit
operator|)
operator|!=
literal|0
return|;
block|}
comment|/**        *  @brief  Fast error checking.        *  @return  True if either the badbit or the failbit is set.        *        *  Checking the badbit in fail() is historical practice.        *  Note that other iostate flags may also be set.       */
name|bool
name|fail
argument_list|()
specifier|const
block|{
return|return
operator|(
name|this
operator|->
name|rdstate
argument_list|()
operator|&
operator|(
name|badbit
operator||
name|failbit
operator|)
operator|)
operator|!=
literal|0
return|;
block|}
comment|/**        *  @brief  Fast error checking.        *  @return  True if the badbit is set.        *        *  Note that other iostate flags may also be set.       */
name|bool
name|bad
argument_list|()
specifier|const
block|{
return|return
operator|(
name|this
operator|->
name|rdstate
argument_list|()
operator|&
name|badbit
operator|)
operator|!=
literal|0
return|;
block|}
comment|/**        *  @brief  Throwing exceptions on errors.        *  @return  The current exceptions mask.        *        *  This changes nothing in the stream.  See the one-argument version        *  of exceptions(iostate) for the meaning of the return value.       */
name|iostate
name|exceptions
argument_list|()
specifier|const
block|{
return|return
name|_M_exception
return|;
block|}
comment|/**        *  @brief  Throwing exceptions on errors.        *  @param  except  The new exceptions mask.        *        *  By default, error flags are set silently.  You can set an        *  exceptions mask for each stream; if a bit in the mask becomes set        *  in the error flags, then an exception of type        *  std::ios_base::failure is thrown.        *        *  If the error flage is already set when the exceptions mask is        *  added, the exception is immediately thrown.  Try running the        *  following under GCC 3.1 or later:        *  @code        *  #include<iostream>        *  #include<fstream>        *  #include<exception>        *          *  int main()        *  {        *      std::set_terminate (__gnu_cxx::__verbose_terminate_handler);        *          *      std::ifstream f ("/etc/motd");        *          *      std::cerr<< "Setting badbit\n";        *      f.setstate (std::ios_base::badbit);        *          *      std::cerr<< "Setting exception mask\n";        *      f.exceptions (std::ios_base::badbit);        *  }        *  @endcode       */
name|void
name|exceptions
parameter_list|(
name|iostate
name|__except
parameter_list|)
block|{
name|_M_exception
operator|=
name|__except
expr_stmt|;
name|this
operator|->
name|clear
argument_list|(
name|_M_streambuf_state
argument_list|)
expr_stmt|;
block|}
comment|// Constructor/destructor:
comment|/**        *  @brief  Constructor performs initialization.        *        *  The parameter is passed by derived streams.       */
name|explicit
name|basic_ios
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
name|ios_base
argument_list|()
block|{
name|this
operator|->
name|init
argument_list|(
name|__sb
argument_list|)
block|; }
comment|/**        *  @brief  Empty.        *        *  The destructor does nothing.  More specifically, it does not        *  destroy the streambuf held by rdbuf().       */
name|virtual
operator|~
name|basic_ios
argument_list|()
block|{ }
comment|// Members:
comment|/**        *  @brief  Fetches the current @e tied stream.        *  @return  A pointer to the tied stream, or NULL if the stream is        *           not tied.        *        *  A stream may be @e tied (or synchronized) to a second output        *  stream.  When this stream performs any I/O, the tied stream is        *  first flushed.  For example, @c std::cin is tied to @c std::cout.       */
name|basic_ostream
operator|<
name|_CharT
decl_stmt|,
name|_Traits
decl|>
modifier|*
name|tie
argument_list|()
decl|const
block|{
return|return
name|_M_tie
return|;
block|}
comment|/**        *  @brief  Ties this stream to an output stream.        *  @param  tiestr  The output stream.        *  @return  The previously tied output stream, or NULL if the stream        *           was not tied.        *        *  This sets up a new tie; see tie() for more.       */
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|*
name|tie
argument_list|(
argument|basic_ostream<_CharT
argument_list|,
argument|_Traits>* __tiestr
argument_list|)
block|{
name|basic_ostream
operator|<
name|_CharT
block|,
name|_Traits
operator|>
operator|*
name|__old
operator|=
name|_M_tie
block|;
name|_M_tie
operator|=
name|__tiestr
block|;
return|return
name|__old
return|;
block|}
comment|/**        *  @brief  Accessing the underlying buffer.        *  @return  The current stream buffer.        *        *  This does not change the state of the stream.       */
name|basic_streambuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|*
name|rdbuf
argument_list|()
specifier|const
block|{
return|return
name|_M_streambuf
return|;
block|}
comment|/**        *  @brief  Changing the underlying buffer.        *  @param  sb  The new stream buffer.        *  @return  The previous stream buffer.        *        *  Associates a new buffer with the current stream, and clears the        *  error state.        *        *  Due to historical accidents which the LWG refuses to correct, the        *  I/O library suffers from a design error:  this function is hidden        *  in derived classes by overrides of the zero-argument @c rdbuf(),        *  which is non-virtual for hysterical raisins.  As a result, you        *  must use explicit qualifications to access this function via any        *  derived class.       */
name|basic_streambuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|*
name|rdbuf
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
expr_stmt|;
comment|/**        *  @doctodo       */
name|basic_ios
modifier|&
name|copyfmt
parameter_list|(
specifier|const
name|basic_ios
modifier|&
name|__rhs
parameter_list|)
function_decl|;
comment|/**        *  @brief  Retreives the "empty" character.        *  @return  The current fill character.        *        *  It defaults to a space (' ') in the current locale.       */
name|char_type
name|fill
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|_M_fill_init
condition|)
block|{
name|_M_fill
operator|=
name|this
operator|->
name|widen
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|_M_fill_init
operator|=
name|true
expr_stmt|;
block|}
return|return
name|_M_fill
return|;
block|}
comment|/**        *  @brief  Sets a new "empty" character.        *  @param  ch  The new character.        *  @return  The previous fill character.        *        *  The fill character is used to fill out space when P+ characters        *  have been requested (e.g., via setw), Q characters are actually        *  used, and Q<P.  It defaults to a space (' ') in the current locale.       */
name|char_type
name|fill
parameter_list|(
name|char_type
name|__ch
parameter_list|)
block|{
name|char_type
name|__old
init|=
name|this
operator|->
name|fill
argument_list|()
decl_stmt|;
name|_M_fill
operator|=
name|__ch
expr_stmt|;
return|return
name|__old
return|;
block|}
comment|// Locales:
comment|/**        *  @brief  Moves to a new locale.        *  @param  loc  The new locale.        *  @return  The previous locale.        *        *  Calls @c ios_base::imbue(loc), and if a stream buffer is associated        *  with this stream, calls that buffer's @c pubimbue(loc).        *        *  Additional l10n notes are at        *  http://gcc.gnu.org/onlinedocs/libstdc++/22_locale/howto.html       */
name|locale
name|imbue
parameter_list|(
specifier|const
name|locale
modifier|&
name|__loc
parameter_list|)
function_decl|;
comment|/**        *  @brief  Squeezes characters.        *  @param  c  The character to narrow.        *  @param  dfault  The character to narrow.        *  @return  The narrowed character.        *        *  Maps a character of @c char_type to a character of @c char,        *  if possible.        *        *  Returns the result of        *  @code        *    std::use_facet< ctype<char_type>>(getloc()).narrow(c,dfault)        *  @endcode        *        *  Additional l10n notes are at        *  http://gcc.gnu.org/onlinedocs/libstdc++/22_locale/howto.html       */
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
decl_stmt|;
comment|/**        *  @brief  Widens characters.        *  @param  c  The character to widen.        *  @return  The widened character.        *        *  Maps a character of @c char to a character of @c char_type.        *        *  Returns the result of        *  @code        *    std::use_facet< ctype<char_type>>(getloc()).widen(c)        *  @endcode        *        *  Additional l10n notes are at        *  http://gcc.gnu.org/onlinedocs/libstdc++/22_locale/howto.html       */
name|char_type
name|widen
argument_list|(
name|char
name|__c
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
comment|// 27.4.5.1  basic_ios constructors
comment|/**        *  @brief  Empty.        *        *  The default constructor does nothing and is not normally        *  accessible to users.       */
name|basic_ios
argument_list|()
operator|:
name|ios_base
argument_list|()
block|{ }
comment|/**        *  @brief  All setup is performed here.        *        *  This is called from the public constructor.  It is not virtual and        *  cannot be redefined.  The second argument, __cache, is used        *  to initialize the standard streams without allocating        *  memory.       */
name|void
name|init
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
expr_stmt|;
name|bool
name|_M_check_facet
argument_list|(
specifier|const
name|locale
operator|::
name|facet
operator|*
name|__f
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|__f
condition|)
name|__throw_bad_cast
argument_list|()
expr_stmt|;
return|return
name|true
return|;
block|}
name|void
name|_M_cache_locale
parameter_list|(
specifier|const
name|locale
modifier|&
name|__loc
parameter_list|)
function_decl|;
if|#
directive|if
literal|1
comment|// XXX GLIBCXX_ABI Deprecated, compatibility only.
name|void
name|_M_cache_facets
parameter_list|(
specifier|const
name|locale
modifier|&
name|__loc
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// Internal state setter that won't throw, only set the state bits.
comment|// Used to guarantee we don't throw when setting badbit.
name|void
name|_M_setstate
parameter_list|(
name|iostate
name|__state
parameter_list|)
block|{
name|_M_streambuf_state
operator||=
name|__state
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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

begin_include
include|#
directive|include
file|<bits/basic_ios.tcc>
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
comment|/* _CPP_BITS_BASICIOS_H */
end_comment

end_unit

