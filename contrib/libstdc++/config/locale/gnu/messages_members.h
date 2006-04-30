begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// std::messages implementation details, GNU version -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
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
comment|// ISO C++ 14882: 22.2.7.1.2  messages functions
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
name|messages
operator|<
name|_CharT
operator|>
operator|::
name|messages
argument_list|(
argument|size_t __refs
argument_list|)
operator|:
name|facet
argument_list|(
name|__refs
argument_list|)
operator|,
name|_M_c_locale_messages
argument_list|(
name|_S_get_c_locale
argument_list|()
argument_list|)
operator|,
name|_M_name_messages
argument_list|(
argument|_S_get_c_name()
argument_list|)
block|{ }
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
name|messages
argument_list|(
argument|__c_locale __cloc
argument_list|,
argument|const char* __s
argument_list|,
argument|size_t __refs
argument_list|)
operator|:
name|facet
argument_list|(
name|__refs
argument_list|)
operator|,
name|_M_c_locale_messages
argument_list|(
name|_S_clone_c_locale
argument_list|(
name|__cloc
argument_list|)
argument_list|)
operator|,
name|_M_name_messages
argument_list|(
argument|__s
argument_list|)
block|{
name|char
operator|*
name|__tmp
operator|=
name|new
name|char
index|[
name|std
operator|::
name|strlen
argument_list|(
name|__s
argument_list|)
operator|+
literal|1
index|]
block|;
name|std
operator|::
name|strcpy
argument_list|(
name|__tmp
argument_list|,
name|__s
argument_list|)
block|;
name|_M_name_messages
operator|=
name|__tmp
block|;      }
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
block|{
if|if
condition|(
name|_M_name_messages
operator|!=
name|_S_get_c_name
argument_list|()
condition|)
name|delete
index|[]
name|_M_name_messages
decl_stmt|;
name|_S_destroy_c_locale
argument_list|(
name|_M_c_locale_messages
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}    template
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
comment|// messages_byname
name|template
operator|<
name|typename
name|_CharT
operator|>
name|messages_byname
operator|<
name|_CharT
operator|>
operator|::
name|messages_byname
argument_list|(
argument|const char* __s
argument_list|,
argument|size_t __refs
argument_list|)
operator|:
name|messages
operator|<
name|_CharT
operator|>
operator|(
name|__refs
operator|)
block|{
if|if
condition|(
name|this
operator|->
name|_M_name_messages
operator|!=
name|locale
operator|::
name|facet
operator|::
name|_S_get_c_name
argument_list|()
condition|)
name|delete
index|[]
name|this
operator|->
name|_M_name_messages
decl_stmt|;
name|char
operator|*
name|__tmp
operator|=
name|new
name|char
index|[
name|std
operator|::
name|strlen
argument_list|(
name|__s
argument_list|)
operator|+
literal|1
index|]
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|strcpy
argument_list|(
name|__tmp
argument_list|,
name|__s
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|this
operator|->
name|_M_name_messages
operator|=
name|__tmp
expr_stmt|;
end_expr_stmt

begin_if
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
name|_M_c_locale_messages
argument_list|)
expr_stmt|;
name|this
operator|->
name|_S_create_c_locale
argument_list|(
name|this
operator|->
name|_M_c_locale_messages
argument_list|,
name|__s
argument_list|)
expr_stmt|;
block|}
end_if

unit|}
end_unit

