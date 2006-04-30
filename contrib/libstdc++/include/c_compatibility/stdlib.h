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
name|_GLIBCXX_STDLIB_H
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_STDLIB_H
value|1
end_define

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_expr_stmt
name|using
name|std
operator|::
name|div_t
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|ldiv_t
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|abort
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|abs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|atexit
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|atof
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|atoi
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|atol
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|bsearch
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|calloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|div
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|exit
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|free
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|getenv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|labs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|ldiv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|malloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|mblen
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|mbstowcs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|mbtowc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|qsort
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|rand
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|realloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|srand
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strtod
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strtol
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strtoul
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|system
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcstombs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wctomb
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

