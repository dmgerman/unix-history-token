begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// std::messages implementation details, GNU version -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002 Free Software Foundation, Inc.
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
comment|// ISO C++ 14882: 22.2.7.1.2  messages virtual functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Written by Benjamin Kosnik<bkoz@redhat.com>
end_comment

begin_comment
comment|// Non-virtual member functions.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|typename
name|messages
operator|<
name|_CharT
operator|>
operator|::
name|catalog
name|messages
operator|<
name|_CharT
operator|>
operator|::
name|open
argument_list|(
argument|const basic_string<char>& __s
argument_list|,
argument|const locale& __loc
argument_list|,
argument|const char* __dir
argument_list|)
specifier|const
block|{
name|bindtextdomain
argument_list|(
name|__s
operator|.
name|c_str
argument_list|()
argument_list|,
name|__dir
argument_list|)
block|;
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
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|typename
name|messages
operator|<
name|_CharT
operator|>
operator|::
name|catalog
name|messages
operator|<
name|_CharT
operator|>
operator|::
name|do_open
argument_list|(
argument|const basic_string<char>& __s
argument_list|,
argument|const locale&
argument_list|)
specifier|const
block|{
comment|// No error checking is done, assume the catalog exists and can
comment|// be used.
name|textdomain
argument_list|(
name|__s
operator|.
name|c_str
argument_list|()
argument_list|)
block|;
return|return
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|typename
name|messages
operator|<
name|_CharT
operator|>
operator|::
name|string_type
name|messages
operator|<
name|_CharT
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
argument|const string_type& __dfault
argument_list|)
specifier|const
block|{
if|#
directive|if
name|__GLIBC__
operator|>
literal|2
operator|||
operator|(
name|__GLIBC__
operator|==
literal|2
operator|&&
name|__GLIBC_MINOR__
operator|>
literal|2
operator|)
name|__c_locale
name|__old
operator|=
name|__uselocale
argument_list|(
name|_M_c_locale_messages
argument_list|)
block|;
name|char
operator|*
name|__msg
operator|=
name|gettext
argument_list|(
name|_M_convert_to_char
argument_list|(
name|__dfault
argument_list|)
argument_list|)
block|;
name|__uselocale
argument_list|(
name|__old
argument_list|)
block|;
return|return
name|_M_convert_from_char
argument_list|(
name|__msg
argument_list|)
return|;
else|#
directive|else
name|char
operator|*
name|__old
operator|=
name|strdup
argument_list|(
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
name|NULL
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
name|_M_name_messages
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|__msg
init|=
name|gettext
argument_list|(
name|_M_convert_to_char
argument_list|(
name|__dfault
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
name|__old
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|free
argument_list|(
name|__old
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|_M_convert_from_char
argument_list|(
name|__msg
argument_list|)
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_CharT
operator|>
name|void
name|messages
operator|<
name|_CharT
operator|>
operator|::
name|do_close
argument_list|(
argument|catalog
argument_list|)
specifier|const
block|{ }
end_expr_stmt

end_unit

