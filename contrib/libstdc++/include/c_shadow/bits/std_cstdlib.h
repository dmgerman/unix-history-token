begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*- header wrapper
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

begin_comment
comment|//
end_comment

begin_comment
comment|// ISO C++ 14882: 20.4.6  C library
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Function decls in this header are overloaded on the
end_comment

begin_comment
comment|// extern "C"-ness of arguments.  This is a rich ground
end_comment

begin_comment
comment|// for compiler bugs.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_CSTDLIB
end_ifndef

begin_define
define|#
directive|define
name|_CPP_CSTDLIB
value|1
end_define

begin_include
include|#
directive|include
file|<bits/c++config.h>
end_include

begin_include
include|#
directive|include
file|<bits/std_cstddef.h>
end_include

begin_decl_stmt
name|namespace
name|_C_legacy
block|{
extern|extern
literal|"C"
block|{
define|#
directive|define
name|_IN_C_LEGACY_
pragma|#
directive|pragma
name|GCC
name|system_header
empty|#     include_next<stdlib.h>
typedef|typedef
name|int
function_decl|(
modifier|*
name|_C_cmp_fun_ptr
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
comment|// C fn ptr
block|}
typedef|typedef
name|div_t
name|_CPP_div_t_capture
typedef|;
typedef|typedef
name|ldiv_t
name|_CPP_ldiv_t_capture
typedef|;
if|#
directive|if
name|_GLIBCPP_HAVE_LLDIV_T
typedef|typedef
name|lldiv_t
name|_CPP_lldiv_t_capture
typedef|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_comment
comment|// namespace _C_legacy
end_comment

begin_undef
undef|#
directive|undef
name|wchar_t
end_undef

begin_undef
undef|#
directive|undef
name|div_t
end_undef

begin_undef
undef|#
directive|undef
name|ldiv_t
end_undef

begin_undef
undef|#
directive|undef
name|atof
end_undef

begin_undef
undef|#
directive|undef
name|atoi
end_undef

begin_undef
undef|#
directive|undef
name|atol
end_undef

begin_undef
undef|#
directive|undef
name|strtod
end_undef

begin_undef
undef|#
directive|undef
name|strtol
end_undef

begin_undef
undef|#
directive|undef
name|strtoul
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_HAVE_STRTOLD
end_ifdef

begin_undef
undef|#
directive|undef
name|strtold
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|rand
end_undef

begin_undef
undef|#
directive|undef
name|srand
end_undef

begin_undef
undef|#
directive|undef
name|calloc
end_undef

begin_undef
undef|#
directive|undef
name|free
end_undef

begin_undef
undef|#
directive|undef
name|malloc
end_undef

begin_undef
undef|#
directive|undef
name|realloc
end_undef

begin_undef
undef|#
directive|undef
name|abort
end_undef

begin_undef
undef|#
directive|undef
name|atexit
end_undef

begin_undef
undef|#
directive|undef
name|exit
end_undef

begin_undef
undef|#
directive|undef
name|getenv
end_undef

begin_undef
undef|#
directive|undef
name|system
end_undef

begin_undef
undef|#
directive|undef
name|bsearch
end_undef

begin_undef
undef|#
directive|undef
name|qsort
end_undef

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
name|labs
end_undef

begin_undef
undef|#
directive|undef
name|ldiv
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_C99
end_ifdef

begin_undef
undef|#
directive|undef
name|llabs
end_undef

begin_undef
undef|#
directive|undef
name|lldiv
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|mblen
end_undef

begin_undef
undef|#
directive|undef
name|mbtowc
end_undef

begin_undef
undef|#
directive|undef
name|wctomb
end_undef

begin_undef
undef|#
directive|undef
name|mbstowcs
end_undef

begin_undef
undef|#
directive|undef
name|wcstombs
end_undef

begin_decl_stmt
name|namespace
name|std
block|{
name|struct
name|div_t
range|:
name|_C_legacy
operator|::
name|_CPP_div_t_capture
block|{ }
decl_stmt|;
name|struct
name|ldiv_t
range|:
name|_C_legacy
operator|::
name|_CPP_ldiv_t_capture
block|{ }
decl_stmt|;
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_C99
ifdef|#
directive|ifdef
name|_GLIBCPP_HAVE_LLDIV_T
name|struct
name|lldiv_t
range|:
name|_C_legacy
operator|::
name|_CPP_lldiv_t_capture
block|{ }
decl_stmt|;
else|#
directive|else
struct|struct
name|lldiv_t
block|{
name|long
name|long
name|quot
decl_stmt|;
name|long
name|long
name|rem
decl_stmt|;
block|}
struct|;
endif|#
directive|endif
endif|#
directive|endif
name|using
name|_C_legacy
operator|::
name|atof
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|atoi
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|atol
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|strtod
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|strtol
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|strtoul
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|rand
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|srand
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|calloc
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|free
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|malloc
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|realloc
expr_stmt|;
comment|//  using _C_legacy::abort;
name|using
name|_C_legacy
operator|::
name|atexit
expr_stmt|;
comment|//  using _C_legacy::exit;
name|using
name|_C_legacy
operator|::
name|bsearch
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|qsort
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|getenv
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|system
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|mbtowc
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wctomb
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|mbstowcs
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcstombs
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|strtof
expr_stmt|;
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_LONG_LONG
name|using
name|_C_legacy
operator|::
name|strtoll
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|strtoull
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_GLIBCPP_HAVE_STRTOLD
name|using
name|_C_legacy
operator|::
name|strtold
expr_stmt|;
endif|#
directive|endif
name|using
name|_C_legacy
operator|::
name|mblen
expr_stmt|;
specifier|inline
name|int
name|abs
parameter_list|(
name|int
name|__x
parameter_list|)
block|{
return|return
name|__x
operator|>=
literal|0
condition|?
name|__x
else|:
operator|-
name|__x
return|;
block|}
specifier|inline
name|div_t
name|div
parameter_list|(
name|int
name|__n
parameter_list|,
name|int
name|__d
parameter_list|)
block|{
name|div_t
name|__q
decl_stmt|;
name|__q
operator|.
name|quot
operator|=
name|__n
operator|/
name|__d
expr_stmt|;
name|__q
operator|.
name|rem
operator|=
name|__n
operator|%
name|__d
expr_stmt|;
return|return
name|__q
return|;
block|}
specifier|inline
name|long
name|labs
parameter_list|(
name|long
name|__x
parameter_list|)
block|{
return|return
name|__x
operator|>=
literal|0
condition|?
name|__x
else|:
operator|-
name|__x
return|;
block|}
specifier|inline
name|long
name|abs
parameter_list|(
name|long
name|__x
parameter_list|)
block|{
return|return
name|__x
operator|>=
literal|0
condition|?
name|__x
else|:
operator|-
name|__x
return|;
block|}
specifier|inline
name|ldiv_t
name|ldiv
parameter_list|(
name|long
name|__n
parameter_list|,
name|long
name|__d
parameter_list|)
block|{
name|ldiv_t
name|__q
decl_stmt|;
name|__q
operator|.
name|quot
operator|=
name|__n
operator|/
name|__d
expr_stmt|;
name|__q
operator|.
name|rem
operator|=
name|__n
operator|%
name|__d
expr_stmt|;
return|return
name|__q
return|;
block|}
specifier|inline
name|ldiv_t
name|div
parameter_list|(
name|long
name|__n
parameter_list|,
name|long
name|__d
parameter_list|)
block|{
name|ldiv_t
name|__q
decl_stmt|;
name|__q
operator|.
name|quot
operator|=
name|__n
operator|/
name|__d
expr_stmt|;
name|__q
operator|.
name|rem
operator|=
name|__n
operator|%
name|__d
expr_stmt|;
return|return
name|__q
return|;
block|}
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_C99
specifier|inline
name|long
name|long
name|llabs
parameter_list|(
name|long
name|long
name|__x
parameter_list|)
block|{
return|return
name|__x
operator|>=
literal|0
condition|?
name|__x
else|:
operator|-
name|__x
return|;
block|}
specifier|inline
name|long
name|long
name|abs
parameter_list|(
name|long
name|long
name|__x
parameter_list|)
block|{
return|return
name|__x
operator|>=
literal|0
condition|?
name|__x
else|:
operator|-
name|__x
return|;
block|}
specifier|inline
name|lldiv_t
name|lldiv
parameter_list|(
name|long
name|long
name|__n
parameter_list|,
name|long
name|long
name|__d
parameter_list|)
block|{
name|lldiv_t
name|__q
decl_stmt|;
name|__q
operator|.
name|quot
operator|=
name|__n
operator|/
name|__d
expr_stmt|;
name|__q
operator|.
name|rem
operator|=
name|__n
operator|%
name|__d
expr_stmt|;
return|return
name|__q
return|;
block|}
specifier|inline
name|lldiv_t
name|div
parameter_list|(
name|long
name|long
name|__n
parameter_list|,
name|long
name|long
name|__d
parameter_list|)
block|{
name|lldiv_t
name|__q
decl_stmt|;
name|__q
operator|.
name|quot
operator|=
name|__n
operator|/
name|__d
expr_stmt|;
name|__q
operator|.
name|rem
operator|=
name|__n
operator|%
name|__d
expr_stmt|;
return|return
name|__q
return|;
block|}
endif|#
directive|endif
block|}
end_decl_stmt

begin_comment
comment|// namespace std
end_comment

begin_undef
undef|#
directive|undef
name|_IN_C_LEGACY_
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

