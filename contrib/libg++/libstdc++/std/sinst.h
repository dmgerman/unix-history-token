begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Forward declarations of -*- C++ -*- string instantiations.
end_comment

begin_comment
comment|// Copyright (C) 1994 Free Software Foundation
end_comment

begin_comment
comment|// This file is part of the GNU ANSI C++ Library.  This library is free
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
comment|// You should have received a copy of the GNU General Public License
end_comment

begin_comment
comment|// along with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
end_comment

begin_comment
comment|// As a special exception, if you link this library with files
end_comment

begin_comment
comment|// compiled with a GNU compiler to produce an executable, this does not cause
end_comment

begin_comment
comment|// the resulting executable to be covered by the GNU General Public License.
end_comment

begin_comment
comment|// This exception does not however invalidate any other reasons why
end_comment

begin_comment
comment|// the executable file might be covered by the GNU General Public License.
end_comment

begin_comment
comment|// Written by Jason Merrill based upon the specification by Takanori Adachi
end_comment

begin_comment
comment|// in ANSI X3J16/94-0013R2.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SINST__
end_ifndef

begin_define
define|#
directive|define
name|__SINST__
end_define

begin_extern
extern|extern
literal|"C++"
block|{
define|#
directive|define
name|__S
value|basic_string<char,string_char_traits<char>>
comment|//#define __W basic_string<wchar_t,string_char_traits<wchar_t>>
extern|extern template class __bsrep<char
operator|,
extern|string_char_traits<char>>;
specifier|extern
name|template
name|class
name|__S
decl_stmt|;
comment|// extern template class __W;
comment|// extern template class __bsrep<wchar_t, string_char_traits<wchar_t>>;
define|#
directive|define
name|__DOPR
parameter_list|(
name|op
parameter_list|,
name|ret
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|)
define|\
value|extern template ret operator op (const s&, const s&); \   extern template ret operator op (const c*, const s&); \   extern template ret operator op (const s&, const c*); \  #define __DO(op, ret, c, s) \   extern template ret operator op (const s&, const s&); \   extern template ret operator op (const c*, const s&); \   extern template ret operator op (const s&, const c*); \   extern template ret operator op (c, const s&); \   extern template ret operator op (const s&, c);
name|__DO
argument_list|(
argument|+
argument_list|,
argument|__S
argument_list|,
argument|char
argument_list|,
argument|__S
argument_list|)
comment|// __DO (+, __W, wchar_t, __W) */
define|#
directive|define
name|__DOB
parameter_list|(
name|op
parameter_list|)
define|\
value|__DOPR (op, bool, char, __S)
comment|//  __DOPR (op, bool, wchar_t, __W)
name|__DOB
argument_list|(
argument|==
argument_list|)
name|__DOB
argument_list|(
argument|!=
argument_list|)
name|__DOB
argument_list|(
argument|<
argument_list|)
name|__DOB
argument_list|(
argument|>
argument_list|)
name|__DOB
argument_list|(
argument|<=
argument_list|)
name|__DOB
argument_list|(
argument|>=
argument_list|)
undef|#
directive|undef
name|__S
comment|//#undef __W
undef|#
directive|undef
name|__DO
undef|#
directive|undef
name|__DOB
undef|#
directive|undef
name|__DOPR
block|}
end_extern

begin_comment
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

