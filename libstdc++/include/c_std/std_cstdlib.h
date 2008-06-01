begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*- forwarding header.
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005
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
comment|/** @file include/cstdlib  *  This is a Standard C++ Library file.  You should @c #include this file  *  in your programs, rather than any of the "*.h" implementation files.  *  *  This is the C++ version of the Standard C Library header @c stdlib.h,  *  and its contents are (mostly) the same as that header, but are all  *  contained in the namespace @c std (except for names which are defined  *  as macros in C).  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_CSTDLIB
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_CSTDLIB
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

begin_if
if|#
directive|if
operator|!
name|_GLIBCXX_HOSTED
end_if

begin_comment
comment|// The C standard does not require a freestanding implementation to
end_comment

begin_comment
comment|// provide<stdlib.h>.  However, the C++ standard does still require
end_comment

begin_comment
comment|//<cstdlib> -- but only the functionality mentioned in
end_comment

begin_comment
comment|// [lib.support.start.term].
end_comment

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|std
argument_list|)
end_macro

begin_extern
extern|extern
literal|"C"
name|void
name|abort
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|atexit
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|()
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|void
name|exit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_extern

begin_decl_stmt
name|_GLIBCXX_END_NAMESPACE
else|#
directive|else
include|#
directive|include
file|<stdlib.h>
comment|// Get rid of those macros defined in<stdlib.h> in lieu of real functions.
undef|#
directive|undef
name|abort
undef|#
directive|undef
name|abs
undef|#
directive|undef
name|atexit
undef|#
directive|undef
name|atof
undef|#
directive|undef
name|atoi
undef|#
directive|undef
name|atol
undef|#
directive|undef
name|bsearch
undef|#
directive|undef
name|calloc
undef|#
directive|undef
name|div
undef|#
directive|undef
name|exit
undef|#
directive|undef
name|free
undef|#
directive|undef
name|getenv
undef|#
directive|undef
name|labs
undef|#
directive|undef
name|ldiv
undef|#
directive|undef
name|malloc
undef|#
directive|undef
name|mblen
undef|#
directive|undef
name|mbstowcs
undef|#
directive|undef
name|mbtowc
undef|#
directive|undef
name|qsort
undef|#
directive|undef
name|rand
undef|#
directive|undef
name|realloc
undef|#
directive|undef
name|srand
undef|#
directive|undef
name|strtod
undef|#
directive|undef
name|strtol
undef|#
directive|undef
name|strtoul
undef|#
directive|undef
name|system
undef|#
directive|undef
name|wcstombs
undef|#
directive|undef
name|wctomb
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
name|std
argument_list|)
name|using
decl|::
name|div_t
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|using
operator|::
name|ldiv_t
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|abort
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|abs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|atexit
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|atof
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|atoi
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|atol
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|bsearch
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|calloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|div
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|exit
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|free
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|getenv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|labs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|ldiv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|malloc
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_HAVE_MBSTATE_T
end_ifdef

begin_expr_stmt
name|using
operator|::
name|mblen
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|mbstowcs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|mbtowc
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _GLIBCXX_HAVE_MBSTATE_T
end_comment

begin_expr_stmt
name|using
operator|::
name|qsort
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|rand
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|realloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|srand
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|strtod
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|strtol
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|strtoul
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|system
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|using
operator|::
name|wcstombs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wctomb
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _GLIBCXX_USE_WCHAR_T
end_comment

begin_function
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
end_function

begin_function
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
end_function

begin_decl_stmt
name|_GLIBCXX_END_NAMESPACE
if|#
directive|if
name|_GLIBCXX_USE_C99
undef|#
directive|undef
name|_Exit
undef|#
directive|undef
name|llabs
undef|#
directive|undef
name|lldiv
undef|#
directive|undef
name|atoll
undef|#
directive|undef
name|strtoll
undef|#
directive|undef
name|strtoull
undef|#
directive|undef
name|strtof
undef|#
directive|undef
name|strtold
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
name|__gnu_cxx
argument_list|)
if|#
directive|if
operator|!
name|_GLIBCXX_USE_C99_LONG_LONG_DYNAMIC
name|using
decl|::
name|lldiv_t
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_GLIBCXX_USE_C99_CHECK
operator|||
name|_GLIBCXX_USE_C99_DYNAMIC
end_if

begin_extern
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
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|_GLIBCXX_USE_C99_DYNAMIC
end_if

begin_expr_stmt
name|using
operator|::
name|_Exit
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
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
end_function

begin_if
if|#
directive|if
operator|!
name|_GLIBCXX_USE_C99_LONG_LONG_DYNAMIC
end_if

begin_expr_stmt
name|using
operator|::
name|llabs
expr_stmt|;
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
name|using
operator|::
name|lldiv
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_GLIBCXX_USE_C99_LONG_LONG_CHECK
operator|||
name|_GLIBCXX_USE_C99_LONG_LONG_DYNAMIC
end_if

begin_extern
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
end_extern

begin_extern
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
end_extern

begin_extern
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
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|_GLIBCXX_USE_C99_LONG_LONG_DYNAMIC
end_if

begin_expr_stmt
name|using
operator|::
name|atoll
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|strtoll
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|strtoull
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|using
operator|::
name|strtof
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|strtold
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|_GLIBCXX_END_NAMESPACE
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
name|std
argument_list|)
if|#
directive|if
operator|!
name|_GLIBCXX_USE_C99_LONG_LONG_DYNAMIC
name|using
decl|::
name|__gnu_cxx
decl|::
name|lldiv_t
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|using
operator|::
name|__gnu_cxx
operator|::
name|_Exit
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|__gnu_cxx
operator|::
name|abs
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
operator|!
name|_GLIBCXX_USE_C99_LONG_LONG_DYNAMIC
end_if

begin_expr_stmt
name|using
operator|::
name|__gnu_cxx
operator|::
name|llabs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|__gnu_cxx
operator|::
name|div
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|__gnu_cxx
operator|::
name|lldiv
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|using
operator|::
name|__gnu_cxx
operator|::
name|atoll
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|__gnu_cxx
operator|::
name|strtof
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|__gnu_cxx
operator|::
name|strtoll
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|__gnu_cxx
operator|::
name|strtoull
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|__gnu_cxx
operator|::
name|strtold
expr_stmt|;
end_expr_stmt

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _GLIBCXX_USE_C99
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !_GLIBCXX_HOSTED
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

