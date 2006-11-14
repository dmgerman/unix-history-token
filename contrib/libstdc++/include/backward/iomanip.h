begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright (C) 2000 Free Software Foundation, Inc.
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
name|_BACKWARD_IOMANIP_H
end_ifndef

begin_define
define|#
directive|define
name|_BACKWARD_IOMANIP_H
value|1
end_define

begin_include
include|#
directive|include
file|"backward_warning.h"
end_include

begin_include
include|#
directive|include
file|"iostream.h"
end_include

begin_include
include|#
directive|include
file|<iomanip>
end_include

begin_comment
comment|// These are from<ios> as per [27.4].
end_comment

begin_expr_stmt
name|using
name|std
operator|::
name|boolalpha
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|noboolalpha
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|showbase
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|noshowbase
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|showpoint
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|noshowpoint
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|showpos
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|noshowpos
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|skipws
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|noskipws
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|uppercase
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|nouppercase
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|internal
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|left
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|right
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|dec
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|hex
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|oct
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fixed
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|scientific
expr_stmt|;
end_expr_stmt

begin_comment
comment|// These are from<iomanip> as per [27.6].  Manipulators from<istream>
end_comment

begin_comment
comment|// and<ostream> (e.g., endl) are made available via<iostream.h>.
end_comment

begin_expr_stmt
name|using
name|std
operator|::
name|resetiosflags
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|setiosflags
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|setbase
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|setfill
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|setprecision
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|setw
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Local Variables:
end_comment

begin_comment
comment|// mode:C++
end_comment

begin_comment
comment|// End:
end_comment

end_unit

