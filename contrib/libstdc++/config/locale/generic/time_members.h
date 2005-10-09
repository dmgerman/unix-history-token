begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// std::time_get, std::time_put implementation, generic version -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.
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
comment|// ISO C++ 14882: 22.2.5.1.2 - time_get functions
end_comment

begin_comment
comment|// ISO C++ 14882: 22.2.5.3.2 - time_put functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Written by Benjamin Kosnik<bkoz@redhat.com>
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|__timepunct
operator|<
name|_CharT
operator|>
operator|::
name|__timepunct
argument_list|(
argument|size_t __refs
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
name|_M_name_timepunct
operator|=
name|_S_get_c_name
argument_list|()
block|;
name|_M_initialize_timepunct
argument_list|()
block|;      }
name|template
operator|<
name|typename
name|_CharT
operator|>
name|__timepunct
operator|<
name|_CharT
operator|>
operator|::
name|__timepunct
argument_list|(
argument|__cache_type* __cache
argument_list|,
argument|size_t __refs
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
name|_M_name_timepunct
operator|=
name|_S_get_c_name
argument_list|()
block|;
name|_M_initialize_timepunct
argument_list|()
block|;      }
name|template
operator|<
name|typename
name|_CharT
operator|>
name|__timepunct
operator|<
name|_CharT
operator|>
operator|::
name|__timepunct
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
name|_M_data
argument_list|(
argument|NULL
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
name|_M_name_timepunct
operator|=
name|__tmp
block|;
name|_M_initialize_timepunct
argument_list|(
name|__cloc
argument_list|)
block|;      }
name|template
operator|<
name|typename
name|_CharT
operator|>
name|__timepunct
operator|<
name|_CharT
operator|>
operator|::
operator|~
name|__timepunct
argument_list|()
block|{
if|if
condition|(
name|_M_name_timepunct
operator|!=
name|_S_get_c_name
argument_list|()
condition|)
name|delete
index|[]
name|_M_name_timepunct
decl_stmt|;
name|delete
name|_M_data
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_S_destroy_c_locale
argument_list|(
name|_M_c_locale_timepunct
argument_list|)
expr_stmt|;
end_expr_stmt

unit|}
end_unit

