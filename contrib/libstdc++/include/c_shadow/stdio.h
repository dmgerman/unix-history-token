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
name|_INCLUDED_CPP_STDIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_INCLUDED_CPP_STDIO_H_
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
name|_STDIO_NEED_C_LEGACY_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<cstdio>
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
name|FILE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fpos_t
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|remove
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|rename
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tmpfile
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|tmpnam
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fclose
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fflush
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fopen
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|freopen
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|setbuf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|setvbuf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fscanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|printf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|scanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|sprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|sscanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|vfprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|vprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|vsprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fgetc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fgets
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fputc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fputs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|getc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|getchar
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|gets
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|putc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|putchar
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|puts
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|ungetc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fread
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fwrite
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fgetpos
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fseek
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fsetpos
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|ftell
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|rewind
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|clearerr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|feof
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|ferror
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|perror
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_STDIO_NEED_C_LEGACY_
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
name|_STDIO_NEED_C_LEGACY_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDIO_NEED_C_LEGACY_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _INCLUDED_CPP_STDIO_H_ */
end_comment

end_unit

