begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*- forwarding header.
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003
end_comment

begin_comment
comment|// Free Software Foundation, Inc.
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
comment|/** @file cstdlib  *  This is a Standard C++ Library file.  You should @c #include this file  *  in your programs, rather than any of the "*.h" implementation files.  *  *  This is the C++ version of the Standard C Library header @c stdlib.h,  *  and its contents are (mostly) the same as that header, but are all  *  contained in the namespace @c std.  */
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

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|// Get rid of those macros defined in<stdlib.h> in lieu of real functions.
end_comment

begin_undef
undef|#
directive|undef
name|abort
end_undef

begin_undef
undef|#
directive|undef
name|abs
end_undef

begin_undef
undef|#
directive|undef
name|atexit
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
name|bsearch
end_undef

begin_undef
undef|#
directive|undef
name|calloc
end_undef

begin_undef
undef|#
directive|undef
name|div
end_undef

begin_undef
undef|#
directive|undef
name|exit
end_undef

begin_undef
undef|#
directive|undef
name|free
end_undef

begin_undef
undef|#
directive|undef
name|getenv
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

begin_undef
undef|#
directive|undef
name|malloc
end_undef

begin_undef
undef|#
directive|undef
name|mblen
end_undef

begin_undef
undef|#
directive|undef
name|mbstowcs
end_undef

begin_undef
undef|#
directive|undef
name|mbtowc
end_undef

begin_undef
undef|#
directive|undef
name|qsort
end_undef

begin_undef
undef|#
directive|undef
name|rand
end_undef

begin_undef
undef|#
directive|undef
name|realloc
end_undef

begin_undef
undef|#
directive|undef
name|srand
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

begin_undef
undef|#
directive|undef
name|system
end_undef

begin_undef
undef|#
directive|undef
name|wcstombs
end_undef

begin_undef
undef|#
directive|undef
name|wctomb
end_undef

begin_decl_stmt
name|namespace
name|std
block|{
name|using
operator|::
name|div_t
expr_stmt|;
name|using
operator|::
name|ldiv_t
expr_stmt|;
name|using
operator|::
name|abort
expr_stmt|;
name|using
operator|::
name|abs
expr_stmt|;
name|using
operator|::
name|atexit
expr_stmt|;
name|using
operator|::
name|atof
expr_stmt|;
name|using
operator|::
name|atoi
expr_stmt|;
name|using
operator|::
name|atol
expr_stmt|;
name|using
operator|::
name|bsearch
expr_stmt|;
name|using
operator|::
name|calloc
expr_stmt|;
name|using
operator|::
name|div
expr_stmt|;
name|using
operator|::
name|exit
expr_stmt|;
name|using
operator|::
name|free
expr_stmt|;
name|using
operator|::
name|getenv
expr_stmt|;
name|using
operator|::
name|labs
expr_stmt|;
name|using
operator|::
name|ldiv
expr_stmt|;
name|using
operator|::
name|malloc
expr_stmt|;
name|using
operator|::
name|mblen
expr_stmt|;
name|using
operator|::
name|mbstowcs
expr_stmt|;
name|using
operator|::
name|mbtowc
expr_stmt|;
name|using
operator|::
name|qsort
expr_stmt|;
name|using
operator|::
name|rand
expr_stmt|;
name|using
operator|::
name|realloc
expr_stmt|;
name|using
operator|::
name|srand
expr_stmt|;
name|using
operator|::
name|strtod
expr_stmt|;
name|using
operator|::
name|strtol
expr_stmt|;
name|using
operator|::
name|strtoul
expr_stmt|;
name|using
operator|::
name|system
expr_stmt|;
name|using
operator|::
name|wcstombs
expr_stmt|;
name|using
operator|::
name|wctomb
expr_stmt|;
specifier|inline
name|long
name|abs
parameter_list|(
name|long
name|__i
parameter_list|)
block|{
return|return
name|labs
argument_list|(
name|__i
argument_list|)
return|;
block|}
specifier|inline
name|ldiv_t
name|div
parameter_list|(
name|long
name|__i
parameter_list|,
name|long
name|__j
parameter_list|)
block|{
return|return
name|ldiv
argument_list|(
name|__i
argument_list|,
name|__j
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_if
if|#
directive|if
name|_GLIBCPP_USE_C99
end_if

begin_undef
undef|#
directive|undef
name|_Exit
end_undef

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

begin_undef
undef|#
directive|undef
name|atoll
end_undef

begin_undef
undef|#
directive|undef
name|strtoll
end_undef

begin_undef
undef|#
directive|undef
name|strtoull
end_undef

begin_undef
undef|#
directive|undef
name|strtof
end_undef

begin_undef
undef|#
directive|undef
name|strtold
end_undef

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
if|#
directive|if
operator|!
name|_GLIBCPP_USE_C99_LONG_LONG_DYNAMIC
name|using
operator|::
name|lldiv_t
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|_GLIBCPP_USE_C99_CHECK
operator|||
name|_GLIBCPP_USE_C99_DYNAMIC
extern|extern
literal|"C"
name|void
function_decl|(
name|_Exit
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
if|#
directive|if
operator|!
name|_GLIBCPP_USE_C99_DYNAMIC
name|using
operator|::
name|_Exit
expr_stmt|;
endif|#
directive|endif
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
if|#
directive|if
operator|!
name|_GLIBCPP_USE_C99_LONG_LONG_DYNAMIC
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
endif|#
directive|endif
if|#
directive|if
name|_GLIBCPP_USE_C99_LONG_LONG_CHECK
operator|||
name|_GLIBCPP_USE_C99_LONG_LONG_DYNAMIC
extern|extern
literal|"C"
name|long
name|long
name|int
function_decl|(
name|atoll
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
extern|extern
literal|"C"
name|long
name|long
name|int
function_decl|(
name|strtoll
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
name|char
modifier|*
modifier|*
specifier|restrict
parameter_list|,
name|int
parameter_list|)
function_decl|;
extern|extern
literal|"C"
name|unsigned
name|long
name|long
name|int
function_decl|(
name|strtoull
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
name|char
modifier|*
modifier|*
specifier|restrict
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
if|#
directive|if
operator|!
name|_GLIBCPP_USE_C99_LONG_LONG_DYNAMIC
name|using
operator|::
name|atoll
expr_stmt|;
name|using
operator|::
name|strtoll
expr_stmt|;
name|using
operator|::
name|strtoull
expr_stmt|;
endif|#
directive|endif
name|using
operator|::
name|strtof
expr_stmt|;
name|using
operator|::
name|strtold
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|std
block|{
if|#
directive|if
operator|!
name|_GLIBCPP_USE_C99_LONG_LONG_DYNAMIC
name|using
name|__gnu_cxx
operator|::
name|lldiv_t
expr_stmt|;
endif|#
directive|endif
name|using
name|__gnu_cxx
operator|::
name|_Exit
expr_stmt|;
name|using
name|__gnu_cxx
operator|::
name|abs
expr_stmt|;
name|using
name|__gnu_cxx
operator|::
name|llabs
expr_stmt|;
if|#
directive|if
operator|!
name|_GLIBCPP_USE_C99_LONG_LONG_DYNAMIC
name|using
name|__gnu_cxx
operator|::
name|div
expr_stmt|;
name|using
name|__gnu_cxx
operator|::
name|lldiv
expr_stmt|;
endif|#
directive|endif
name|using
name|__gnu_cxx
operator|::
name|atoll
expr_stmt|;
name|using
name|__gnu_cxx
operator|::
name|strtof
expr_stmt|;
name|using
name|__gnu_cxx
operator|::
name|strtoll
expr_stmt|;
name|using
name|__gnu_cxx
operator|::
name|strtoull
expr_stmt|;
name|using
name|__gnu_cxx
operator|::
name|strtold
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

