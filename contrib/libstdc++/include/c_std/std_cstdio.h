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
comment|/** @file include/cstdio  *  This is a Standard C++ Library file.  You should @c #include this file  *  in your programs, rather than any of the "*.h" implementation files.  *  *  This is the C++ version of the Standard C Library header @c stdio.h,  *  and its contents are (mostly) the same as that header, but are all  *  contained in the namespace @c std (except for names which are defined  *  as macros in C).  */
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ISO C++ 14882: 27.8.2  C Library files
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_CSTDIO
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_CSTDIO
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
file|<stdio.h>
end_include

begin_comment
comment|// Get rid of those macros defined in<stdio.h> in lieu of real functions.
end_comment

begin_undef
undef|#
directive|undef
name|clearerr
end_undef

begin_undef
undef|#
directive|undef
name|fclose
end_undef

begin_undef
undef|#
directive|undef
name|feof
end_undef

begin_undef
undef|#
directive|undef
name|ferror
end_undef

begin_undef
undef|#
directive|undef
name|fflush
end_undef

begin_undef
undef|#
directive|undef
name|fgetc
end_undef

begin_undef
undef|#
directive|undef
name|fgetpos
end_undef

begin_undef
undef|#
directive|undef
name|fgets
end_undef

begin_undef
undef|#
directive|undef
name|fopen
end_undef

begin_undef
undef|#
directive|undef
name|fprintf
end_undef

begin_undef
undef|#
directive|undef
name|fputc
end_undef

begin_undef
undef|#
directive|undef
name|fputs
end_undef

begin_undef
undef|#
directive|undef
name|fread
end_undef

begin_undef
undef|#
directive|undef
name|freopen
end_undef

begin_undef
undef|#
directive|undef
name|fscanf
end_undef

begin_undef
undef|#
directive|undef
name|fseek
end_undef

begin_undef
undef|#
directive|undef
name|fsetpos
end_undef

begin_undef
undef|#
directive|undef
name|ftell
end_undef

begin_undef
undef|#
directive|undef
name|fwrite
end_undef

begin_undef
undef|#
directive|undef
name|getc
end_undef

begin_undef
undef|#
directive|undef
name|getchar
end_undef

begin_undef
undef|#
directive|undef
name|gets
end_undef

begin_undef
undef|#
directive|undef
name|perror
end_undef

begin_undef
undef|#
directive|undef
name|printf
end_undef

begin_undef
undef|#
directive|undef
name|putc
end_undef

begin_undef
undef|#
directive|undef
name|putchar
end_undef

begin_undef
undef|#
directive|undef
name|puts
end_undef

begin_undef
undef|#
directive|undef
name|remove
end_undef

begin_undef
undef|#
directive|undef
name|rename
end_undef

begin_undef
undef|#
directive|undef
name|rewind
end_undef

begin_undef
undef|#
directive|undef
name|scanf
end_undef

begin_undef
undef|#
directive|undef
name|setbuf
end_undef

begin_undef
undef|#
directive|undef
name|setvbuf
end_undef

begin_undef
undef|#
directive|undef
name|sprintf
end_undef

begin_undef
undef|#
directive|undef
name|sscanf
end_undef

begin_undef
undef|#
directive|undef
name|tmpfile
end_undef

begin_undef
undef|#
directive|undef
name|tmpnam
end_undef

begin_undef
undef|#
directive|undef
name|ungetc
end_undef

begin_undef
undef|#
directive|undef
name|vfprintf
end_undef

begin_undef
undef|#
directive|undef
name|vprintf
end_undef

begin_undef
undef|#
directive|undef
name|vsprintf
end_undef

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|std
argument_list|)
end_macro

begin_expr_stmt
name|using
operator|::
name|FILE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fpos_t
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|clearerr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fclose
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|feof
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|ferror
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fflush
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fgetc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fgetpos
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fgets
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fopen
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fputc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fputs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fread
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|freopen
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fscanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fseek
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fsetpos
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|ftell
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fwrite
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|getc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|getchar
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|gets
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|perror
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|printf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|putc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|putchar
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|puts
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|remove
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|rename
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|rewind
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|scanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|setbuf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|setvbuf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|sprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|sscanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|tmpfile
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|tmpnam
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|ungetc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|vfprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|vprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|vsprintf
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|_GLIBCXX_END_NAMESPACE
if|#
directive|if
name|_GLIBCXX_USE_C99
undef|#
directive|undef
name|snprintf
undef|#
directive|undef
name|vfscanf
undef|#
directive|undef
name|vscanf
undef|#
directive|undef
name|vsnprintf
undef|#
directive|undef
name|vsscanf
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
name|__gnu_cxx
argument_list|)
if|#
directive|if
name|_GLIBCXX_USE_C99_CHECK
operator|||
name|_GLIBCXX_USE_C99_DYNAMIC
decl|extern "C"
name|int
argument_list|(
name|snprintf
argument_list|)
argument_list|(
name|char
operator|*
specifier|restrict
argument_list|,
name|size_t
argument_list|,
specifier|const
name|char
operator|*
specifier|restrict
argument_list|,
operator|...
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern
literal|"C"
name|int
function_decl|(
name|vfscanf
function_decl|)
parameter_list|(
name|FILE
modifier|*
specifier|restrict
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
name|__gnuc_va_list
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
function_decl|(
name|vscanf
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
name|__gnuc_va_list
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
function_decl|(
name|vsnprintf
function_decl|)
parameter_list|(
name|char
modifier|*
specifier|restrict
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
name|__gnuc_va_list
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
function_decl|(
name|vsscanf
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
name|__gnuc_va_list
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
name|snprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|vfscanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|vscanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|vsnprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|vsscanf
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|_GLIBCXX_END_NAMESPACE
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
name|std
argument_list|)
name|using
decl|::
name|__gnu_cxx
decl|::
name|snprintf
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|using
operator|::
name|__gnu_cxx
operator|::
name|vfscanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|__gnu_cxx
operator|::
name|vscanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|__gnu_cxx
operator|::
name|vsnprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|__gnu_cxx
operator|::
name|vsscanf
expr_stmt|;
end_expr_stmt

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

