begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*- header wrapper.
end_comment

begin_comment
comment|// Copyright (C) 1997-1999, 2000 Free Software Foundation, Inc.
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
name|_INCLUDED_CPP_MATH_H_
end_ifndef

begin_define
define|#
directive|define
name|_INCLUDED_CPP_MATH_H_
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_IN_C_LEGACY_
end_ifdef

begin_comment
comment|/* sub-included by a C header */
end_comment

begin_comment
comment|// get out of the "legacy"
end_comment

begin_comment
unit|}
comment|// close extern "C"
end_comment

begin_comment
unit|}
comment|// close namespace _C_legacy::
end_comment

begin_undef
undef|#
directive|undef
name|_IN_C_LEGACY_
end_undef

begin_define
define|#
directive|define
name|_MATH_NEED_C_LEGACY_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<cmath>
end_include

begin_comment
comment|// Expose global C names, including non-standard ones, but shadow
end_comment

begin_comment
comment|// some names and types with the std:: C++ version.
end_comment

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

begin_comment
comment|// From ISO/IEC 9899:1999
end_comment

begin_expr_stmt
name|using
name|std
operator|::
name|absf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|acosf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|asinf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|atanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|atan2f
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|cosf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|sinf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|coshf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|sinhf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tanhf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|expf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|frexpf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|ldexpf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|logf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|log10f
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|modff
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|powf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|sqrtf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|ceilf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fabsf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|floorf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fmodf
expr_stmt|;
end_expr_stmt

begin_comment
comment|// From ISO/IEC 9899:1999
end_comment

begin_expr_stmt
name|using
name|std
operator|::
name|absl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|acosl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|asinl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|atanl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|atan2l
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|cosl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|sinl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tanl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|coshl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|sinhl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tanhl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|expl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|frexpl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|ldexpl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|logl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|log10l
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|modfl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|powl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|sqrtl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|ceill
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fabsl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|floorl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fmodl
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_MATH_NEED_C_LEGACY_
end_ifdef

begin_comment
comment|// dive back into the "swamp"
end_comment

begin_decl_stmt
name|namespace
name|_C_legacy
block|{
extern|extern
literal|"C"
block|{
end_decl_stmt

begin_define
define|#
directive|define
name|_IN_C_LEGACY_
end_define

begin_undef
undef|#
directive|undef
name|_MATH_NEED_C_LEGACY_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MATH_NEED_C_LEGACY_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _INCLUDED_CPP_MATH_H_ */
end_comment

end_unit

