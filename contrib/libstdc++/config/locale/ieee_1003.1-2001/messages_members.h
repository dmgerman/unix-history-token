begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// std::messages implementation details, IEEE 1003.1-200x version -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001 Free Software Foundation, Inc.
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
argument|const char*
argument_list|)
specifier|const
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
end_expr_stmt

begin_comment
comment|// Virtual member functions.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|messages
operator|<
name|_CharT
operator|>
operator|::
operator|~
name|messages
argument_list|()
block|{ }
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
return|return
name|reinterpret_cast
operator|<
name|catalog
operator|>
operator|(
name|catopen
argument_list|(
name|__s
operator|.
name|c_str
argument_list|()
argument_list|,
name|NL_CAT_LOCALE
argument_list|)
operator|)
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
argument|catalog __c
argument_list|,
argument|int __setid
argument_list|,
argument|int __msgid
argument_list|,
argument|const string_type& __dfault
argument_list|)
specifier|const
block|{
name|nl_catd
name|__nlc
operator|=
name|reinterpret_cast
operator|<
name|nl_catd
operator|>
operator|(
name|__c
operator|)
block|;
name|char
operator|*
name|__msg
operator|=
name|catgets
argument_list|(
name|__nlc
argument_list|,
name|__setid
argument_list|,
name|__msgid
argument_list|,
name|_M_convert_to_char
argument_list|(
name|__dfault
argument_list|)
argument_list|)
block|;
return|return
name|_M_convert_from_char
argument_list|(
name|__msg
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
name|void
name|messages
operator|<
name|_CharT
operator|>
operator|::
name|do_close
argument_list|(
argument|catalog __c
argument_list|)
specifier|const
block|{
name|catclose
argument_list|(
name|reinterpret_cast
operator|<
name|nl_catd
operator|>
operator|(
name|__c
operator|)
argument_list|)
block|; }
end_expr_stmt

end_unit

