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
name|_GLIBCXX_MATH_H
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_MATH_H
value|1
end_define

begin_include
include|#
directive|include
file|<cmath>
end_include

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
name|acos
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|asin
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|atan
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|atan2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|cos
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|sin
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tan
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|cosh
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|sinh
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tanh
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|exp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|frexp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|ldexp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|log
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|log10
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|modf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|pow
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|sqrt
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|ceil
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fabs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|floor
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fmod
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|_GLIBCXX_USE_C99
end_if

begin_expr_stmt
name|using
name|std
operator|::
name|fpclassify
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|isfinite
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|isinf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|isnan
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|isnormal
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|signbit
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|isgreater
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|isgreaterequal
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|isless
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|islessequal
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|islessgreater
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|isunordered
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

