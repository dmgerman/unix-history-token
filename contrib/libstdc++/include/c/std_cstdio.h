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

begin_empty
empty|#include_next<stdio.h>
end_empty

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

