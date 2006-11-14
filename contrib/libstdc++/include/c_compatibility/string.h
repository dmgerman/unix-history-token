begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*- compatibility header.
end_comment

begin_comment
comment|// Copyright (C) 2002 Free Software Foundation, Inc.
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

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_STRING_H
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_STRING_H
value|1
end_define

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_expr_stmt
name|using
name|std
operator|::
name|memcpy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|memmove
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strcpy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strncpy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strcat
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strncat
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|memcmp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strcmp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strcoll
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strncmp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strxfrm
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|memchr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strchr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strcspn
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strpbrk
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strrchr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strspn
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strstr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strtok
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|memset
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strerror
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strlen
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

