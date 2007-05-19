begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// TR1 math.h -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2006 Free Software Foundation, Inc.
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
comment|// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
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
comment|/** @file tr1/math.h  *  This is a TR1 C++ Library header.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TR1_MATH_H
end_ifndef

begin_define
define|#
directive|define
name|_TR1_MATH_H
value|1
end_define

begin_include
include|#
directive|include
file|<tr1/cmath>
end_include

begin_if
if|#
directive|if
name|_GLIBCXX_USE_C99_MATH_TR1
end_if

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|acos
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|acosh
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|asin
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|asinh
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|atan
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|atan2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|atanh
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|cbrt
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|ceil
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|copysign
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|cos
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|cosh
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|erf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|erfc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|exp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|exp2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|expm1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|fabs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|fdim
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|floor
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|fma
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|fmax
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|fmin
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|fmod
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|frexp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|hypot
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|ilogb
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|ldexp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|lgamma
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|llrint
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|llround
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|log
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|log10
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|log1p
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|log2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|logb
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|lrint
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|lround
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|nearbyint
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|nextafter
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|nexttoward
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|pow
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|remainder
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|remquo
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|rint
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|round
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|scalbln
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|scalbn
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|sin
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|sinh
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|sqrt
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|tan
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|tanh
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|tgamma
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tr1
operator|::
name|trunc
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

