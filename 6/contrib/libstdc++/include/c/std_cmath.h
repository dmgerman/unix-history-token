begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*- forwarding header.
end_comment

begin_comment
comment|// Copyright (C) 2000, 2002, 2003 Free Software Foundation, Inc.
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
comment|// ISO C++ 14882: 26.5  C library
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_CMATH
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_CMATH
value|1
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_include
include|#
directive|include
file|<bits/c++config.h>
end_include

begin_empty
empty|#include_next<math.h>
end_empty

begin_comment
comment|// Get rid of those macros defined in<math.h> in lieu of real functions.
end_comment

begin_undef
undef|#
directive|undef
name|abs
end_undef

begin_undef
undef|#
directive|undef
name|div
end_undef

begin_undef
undef|#
directive|undef
name|acos
end_undef

begin_undef
undef|#
directive|undef
name|asin
end_undef

begin_undef
undef|#
directive|undef
name|atan
end_undef

begin_undef
undef|#
directive|undef
name|atan2
end_undef

begin_undef
undef|#
directive|undef
name|ceil
end_undef

begin_undef
undef|#
directive|undef
name|cos
end_undef

begin_undef
undef|#
directive|undef
name|cosh
end_undef

begin_undef
undef|#
directive|undef
name|exp
end_undef

begin_undef
undef|#
directive|undef
name|fabs
end_undef

begin_undef
undef|#
directive|undef
name|floor
end_undef

begin_undef
undef|#
directive|undef
name|fmod
end_undef

begin_undef
undef|#
directive|undef
name|frexp
end_undef

begin_undef
undef|#
directive|undef
name|ldexp
end_undef

begin_undef
undef|#
directive|undef
name|log
end_undef

begin_undef
undef|#
directive|undef
name|log10
end_undef

begin_undef
undef|#
directive|undef
name|modf
end_undef

begin_undef
undef|#
directive|undef
name|pow
end_undef

begin_undef
undef|#
directive|undef
name|sin
end_undef

begin_undef
undef|#
directive|undef
name|sinh
end_undef

begin_undef
undef|#
directive|undef
name|sqrt
end_undef

begin_undef
undef|#
directive|undef
name|tan
end_undef

begin_undef
undef|#
directive|undef
name|tanh
end_undef

begin_undef
undef|#
directive|undef
name|fpclassify
end_undef

begin_undef
undef|#
directive|undef
name|isfinite
end_undef

begin_undef
undef|#
directive|undef
name|isinf
end_undef

begin_undef
undef|#
directive|undef
name|isnan
end_undef

begin_undef
undef|#
directive|undef
name|isnormal
end_undef

begin_undef
undef|#
directive|undef
name|signbit
end_undef

begin_undef
undef|#
directive|undef
name|isgreater
end_undef

begin_undef
undef|#
directive|undef
name|isgreaterequal
end_undef

begin_undef
undef|#
directive|undef
name|isless
end_undef

begin_undef
undef|#
directive|undef
name|islessequal
end_undef

begin_undef
undef|#
directive|undef
name|islessgreater
end_undef

begin_undef
undef|#
directive|undef
name|isunordered
end_undef

begin_decl_stmt
name|namespace
name|std
block|{
specifier|inline
name|double
name|abs
parameter_list|(
name|double
name|__x
parameter_list|)
block|{
return|return
name|__builtin_fabs
argument_list|(
name|__x
argument_list|)
return|;
block|}
specifier|inline
name|float
name|abs
parameter_list|(
name|float
name|__x
parameter_list|)
block|{
return|return
name|__builtin_fabsf
argument_list|(
name|__x
argument_list|)
return|;
block|}
specifier|inline
name|long
name|double
name|abs
parameter_list|(
name|long
name|double
name|__x
parameter_list|)
block|{
return|return
name|__builtin_fabsl
argument_list|(
name|__x
argument_list|)
return|;
block|}
if|#
directive|if
name|_GLIBCXX_HAVE_MODFF
specifier|inline
name|float
name|modf
parameter_list|(
name|float
name|__x
parameter_list|,
name|float
modifier|*
name|__iptr
parameter_list|)
block|{
return|return
name|modff
argument_list|(
name|__x
argument_list|,
name|__iptr
argument_list|)
return|;
block|}
else|#
directive|else
specifier|inline
name|float
name|modf
parameter_list|(
name|float
name|__x
parameter_list|,
name|float
modifier|*
name|__iptr
parameter_list|)
block|{
name|double
name|__tmp
decl_stmt|;
name|double
name|__res
init|=
name|modf
argument_list|(
name|static_cast
operator|<
name|double
operator|>
operator|(
name|__x
operator|)
argument_list|,
operator|&
name|__tmp
argument_list|)
decl_stmt|;
operator|*
name|__iptr
operator|=
name|static_cast
operator|<
name|float
operator|>
operator|(
name|__tmp
operator|)
expr_stmt|;
return|return
name|__res
return|;
block|}
endif|#
directive|endif
if|#
directive|if
name|_GLIBCXX_HAVE_MODFL
specifier|inline
name|long
name|double
name|modf
parameter_list|(
name|long
name|double
name|__x
parameter_list|,
name|long
name|double
modifier|*
name|__iptr
parameter_list|)
block|{
return|return
name|modfl
argument_list|(
name|__x
argument_list|,
name|__iptr
argument_list|)
return|;
block|}
else|#
directive|else
specifier|inline
name|long
name|double
name|modf
parameter_list|(
name|long
name|double
name|__x
parameter_list|,
name|long
name|double
modifier|*
name|__iptr
parameter_list|)
block|{
name|double
name|__tmp
decl_stmt|;
name|double
name|__res
init|=
name|modf
argument_list|(
name|static_cast
operator|<
name|double
operator|>
operator|(
name|__x
operator|)
argument_list|,
operator|&
name|__tmp
argument_list|)
decl_stmt|;
operator|*
name|__iptr
operator|=
name|static_cast
operator|<
name|long
name|double
operator|>
operator|(
name|__tmp
operator|)
expr_stmt|;
return|return
name|__res
return|;
block|}
endif|#
directive|endif
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

