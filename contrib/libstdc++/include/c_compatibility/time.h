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
name|_GLIBCXX_TIME_H
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_TIME_H
value|1
end_define

begin_include
include|#
directive|include
file|<ctime>
end_include

begin_comment
comment|// Get rid of those macros defined in<time.h> in lieu of real functions.
end_comment

begin_undef
undef|#
directive|undef
name|clock
end_undef

begin_undef
undef|#
directive|undef
name|difftime
end_undef

begin_undef
undef|#
directive|undef
name|mktime
end_undef

begin_undef
undef|#
directive|undef
name|time
end_undef

begin_undef
undef|#
directive|undef
name|asctime
end_undef

begin_undef
undef|#
directive|undef
name|ctime
end_undef

begin_undef
undef|#
directive|undef
name|gmtime
end_undef

begin_undef
undef|#
directive|undef
name|localtime
end_undef

begin_undef
undef|#
directive|undef
name|strftime
end_undef

begin_expr_stmt
name|using
name|std
operator|::
name|clock_t
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|time_t
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tm
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|clock
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|difftime
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|mktime
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|time
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|asctime
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|ctime
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|gmtime
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|localtime
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|strftime
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

