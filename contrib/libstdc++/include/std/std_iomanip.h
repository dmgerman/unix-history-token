begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Standard stream manipulators -*- C++ -*-
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
comment|//
end_comment

begin_comment
comment|// ISO C++ 14882: 27.6.3  Standard manipulators
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/** @file iomanip  *  This is a Standard C++ Library header.  You should @c #include this header  *  in your programs, rather than any of the "st[dl]_*.h" implementation files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_IOMANIP
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_IOMANIP
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
file|<bits/c++config.h>
end_include

begin_include
include|#
directive|include
file|<istream>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|// [27.6.3] standard manipulators
comment|// Also see DR 183.
struct|struct
name|_Resetiosflags
block|{
name|ios_base
operator|::
name|fmtflags
name|_M_mask
expr_stmt|;
block|}
struct|;
comment|/**    *  @brief  Manipulator for @c setf.    *  @param  mask  A format flags mask.    *    *  Sent to a stream object, this manipulator resets the specified flags,    *  via @e stream.setf(0,mask).   */
specifier|inline
name|_Resetiosflags
name|resetiosflags
argument_list|(
name|ios_base
operator|::
name|fmtflags
name|__mask
argument_list|)
block|{
name|_Resetiosflags
name|__x
decl_stmt|;
name|__x
operator|.
name|_M_mask
operator|=
name|__mask
expr_stmt|;
return|return
name|__x
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
specifier|inline
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
name|__is
operator|,
name|_Resetiosflags
name|__f
operator|)
block|{
name|__is
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|fmtflags
argument_list|(
literal|0
argument_list|)
argument_list|,
name|__f
operator|.
name|_M_mask
argument_list|)
block|;
return|return
name|__is
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
specifier|inline
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|operator
operator|<<
operator|(
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|__os
operator|,
name|_Resetiosflags
name|__f
operator|)
block|{
name|__os
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|fmtflags
argument_list|(
literal|0
argument_list|)
argument_list|,
name|__f
operator|.
name|_M_mask
argument_list|)
block|;
return|return
name|__os
return|;
block|}
struct|struct
name|_Setiosflags
block|{
name|ios_base
operator|::
name|fmtflags
name|_M_mask
expr_stmt|;
block|}
struct|;
comment|/**    *  @brief  Manipulator for @c setf.    *  @param  mask  A format flags mask.    *    *  Sent to a stream object, this manipulator sets the format flags    *  to @a mask.   */
specifier|inline
name|_Setiosflags
name|setiosflags
argument_list|(
name|ios_base
operator|::
name|fmtflags
name|__mask
argument_list|)
block|{
name|_Setiosflags
name|__x
decl_stmt|;
name|__x
operator|.
name|_M_mask
operator|=
name|__mask
expr_stmt|;
return|return
name|__x
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
specifier|inline
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
name|__is
operator|,
name|_Setiosflags
name|__f
operator|)
block|{
name|__is
operator|.
name|setf
argument_list|(
name|__f
operator|.
name|_M_mask
argument_list|)
block|;
return|return
name|__is
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
specifier|inline
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|operator
operator|<<
operator|(
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|__os
operator|,
name|_Setiosflags
name|__f
operator|)
block|{
name|__os
operator|.
name|setf
argument_list|(
name|__f
operator|.
name|_M_mask
argument_list|)
block|;
return|return
name|__os
return|;
block|}
struct|struct
name|_Setbase
block|{
name|int
name|_M_base
decl_stmt|;
block|}
struct|;
comment|/**    *  @brief  Manipulator for @c setf.    *  @param  base  A numeric base.    *    *  Sent to a stream object, this manipulator changes the    *  @c ios_base::basefield flags to @c oct, @c dec, or @c hex when @a base    *  is 8, 10, or 16, accordingly, and to 0 if @a base is any other value.   */
specifier|inline
name|_Setbase
name|setbase
parameter_list|(
name|int
name|__base
parameter_list|)
block|{
name|_Setbase
name|__x
decl_stmt|;
name|__x
operator|.
name|_M_base
operator|=
name|__base
expr_stmt|;
return|return
name|__x
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
specifier|inline
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
name|__is
operator|,
name|_Setbase
name|__f
operator|)
block|{
name|__is
operator|.
name|setf
argument_list|(
name|__f
operator|.
name|_M_base
operator|==
literal|8
operator|?
name|ios_base
operator|::
name|oct
operator|:
name|__f
operator|.
name|_M_base
operator|==
literal|10
operator|?
name|ios_base
operator|::
name|dec
operator|:
name|__f
operator|.
name|_M_base
operator|==
literal|16
operator|?
name|ios_base
operator|::
name|hex
operator|:
name|ios_base
operator|::
name|fmtflags
argument_list|(
literal|0
argument_list|)
argument_list|,
name|ios_base
operator|::
name|basefield
argument_list|)
block|;
return|return
name|__is
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
specifier|inline
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|operator
operator|<<
operator|(
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|__os
operator|,
name|_Setbase
name|__f
operator|)
block|{
name|__os
operator|.
name|setf
argument_list|(
name|__f
operator|.
name|_M_base
operator|==
literal|8
operator|?
name|ios_base
operator|::
name|oct
operator|:
name|__f
operator|.
name|_M_base
operator|==
literal|10
operator|?
name|ios_base
operator|::
name|dec
operator|:
name|__f
operator|.
name|_M_base
operator|==
literal|16
operator|?
name|ios_base
operator|::
name|hex
operator|:
name|ios_base
operator|::
name|fmtflags
argument_list|(
literal|0
argument_list|)
argument_list|,
name|ios_base
operator|::
name|basefield
argument_list|)
block|;
return|return
name|__os
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|>
expr|struct
name|_Setfill
block|{
name|_CharT
name|_M_c
block|; }
expr_stmt|;
comment|/**    *  @brief  Manipulator for @c fill.    *  @param  c  The new fill character.    *    *  Sent to a stream object, this manipulator calls @c fill(c) for that    *  object.   */
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|_Setfill
operator|<
name|_CharT
operator|>
name|setfill
argument_list|(
argument|_CharT __c
argument_list|)
block|{
name|_Setfill
operator|<
name|_CharT
operator|>
name|__x
block|;
name|__x
operator|.
name|_M_c
operator|=
name|__c
block|;
return|return
name|__x
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
specifier|inline
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
name|__is
operator|,
name|_Setfill
operator|<
name|_CharT
operator|>
name|__f
operator|)
block|{
name|__is
operator|.
name|fill
argument_list|(
name|__f
operator|.
name|_M_c
argument_list|)
block|;
return|return
name|__is
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
specifier|inline
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|operator
operator|<<
operator|(
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|__os
operator|,
name|_Setfill
operator|<
name|_CharT
operator|>
name|__f
operator|)
block|{
name|__os
operator|.
name|fill
argument_list|(
name|__f
operator|.
name|_M_c
argument_list|)
block|;
return|return
name|__os
return|;
block|}
struct|struct
name|_Setprecision
block|{
name|int
name|_M_n
decl_stmt|;
block|}
struct|;
comment|/**    *  @brief  Manipulator for @c precision.    *  @param  n  The new precision.    *    *  Sent to a stream object, this manipulator calls @c precision(n) for    *  that object.   */
specifier|inline
name|_Setprecision
name|setprecision
parameter_list|(
name|int
name|__n
parameter_list|)
block|{
name|_Setprecision
name|__x
decl_stmt|;
name|__x
operator|.
name|_M_n
operator|=
name|__n
expr_stmt|;
return|return
name|__x
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
specifier|inline
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
name|__is
operator|,
name|_Setprecision
name|__f
operator|)
block|{
name|__is
operator|.
name|precision
argument_list|(
name|__f
operator|.
name|_M_n
argument_list|)
block|;
return|return
name|__is
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
specifier|inline
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|operator
operator|<<
operator|(
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|__os
operator|,
name|_Setprecision
name|__f
operator|)
block|{
name|__os
operator|.
name|precision
argument_list|(
name|__f
operator|.
name|_M_n
argument_list|)
block|;
return|return
name|__os
return|;
block|}
struct|struct
name|_Setw
block|{
name|int
name|_M_n
decl_stmt|;
block|}
struct|;
comment|/**    *  @brief  Manipulator for @c width.    *  @param  n  The new width.    *    *  Sent to a stream object, this manipulator calls @c width(n) for    *  that object.   */
specifier|inline
name|_Setw
name|setw
parameter_list|(
name|int
name|__n
parameter_list|)
block|{
name|_Setw
name|__x
decl_stmt|;
name|__x
operator|.
name|_M_n
operator|=
name|__n
expr_stmt|;
return|return
name|__x
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
specifier|inline
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
name|__is
operator|,
name|_Setw
name|__f
operator|)
block|{
name|__is
operator|.
name|width
argument_list|(
name|__f
operator|.
name|_M_n
argument_list|)
block|;
return|return
name|__is
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
specifier|inline
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|operator
operator|<<
operator|(
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|__os
operator|,
name|_Setw
name|__f
operator|)
block|{
name|__os
operator|.
name|width
argument_list|(
name|__f
operator|.
name|_M_n
argument_list|)
block|;
return|return
name|__os
return|;
block|}
comment|// Inhibit implicit instantiations for required instantiations,
comment|// which are defined via explicit instantiations elsewhere.
comment|// NB:  This syntax is a GNU extension.
if|#
directive|if
name|_GLIBCXX_EXTERN_TEMPLATE
extern|extern template ostream& operator<<(ostream&
operator|,
extern|_Setfill<char>
block|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern template ostream& operator<<(ostream&
operator|,
extern|_Setiosflags
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template ostream& operator<<(ostream&
operator|,
extern|_Resetiosflags
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template ostream& operator<<(ostream&
operator|,
extern|_Setbase
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template ostream& operator<<(ostream&
operator|,
extern|_Setprecision
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template ostream& operator<<(ostream&
operator|,
extern|_Setw
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template istream& operator>>(istream&
operator|,
extern|_Setfill<char>
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template istream& operator>>(istream&
operator|,
extern|_Setiosflags
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template istream& operator>>(istream&
operator|,
extern|_Resetiosflags
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template istream& operator>>(istream&
operator|,
extern|_Setbase
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template istream& operator>>(istream&
operator|,
extern|_Setprecision
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template istream& operator>>(istream&
operator|,
extern|_Setw
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
end_ifdef

begin_extern
extern|extern template wostream& operator<<(wostream&
operator|,
extern|_Setfill<wchar_t>
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template wostream& operator<<(wostream&
operator|,
extern|_Setiosflags
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template wostream& operator<<(wostream&
operator|,
extern|_Resetiosflags
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template wostream& operator<<(wostream&
operator|,
extern|_Setbase
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template wostream& operator<<(wostream&
operator|,
extern|_Setprecision
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template wostream& operator<<(wostream&
operator|,
extern|_Setw
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template wistream& operator>>(wistream&
operator|,
extern|_Setfill<wchar_t>
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template wistream& operator>>(wistream&
operator|,
extern|_Setiosflags
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template wistream& operator>>(wistream&
operator|,
extern|_Resetiosflags
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template wistream& operator>>(wistream&
operator|,
extern|_Setbase
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template wistream& operator>>(wistream&
operator|,
extern|_Setprecision
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template wistream& operator>>(wistream&
operator|,
extern|_Setw
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|}
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GLIBCXX_IOMANIP */
end_comment

end_unit

