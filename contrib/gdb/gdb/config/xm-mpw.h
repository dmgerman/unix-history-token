begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for running GDB on Apple Macintoshes.    Copyright (C) 1994, 1995 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"mpw.h"
end_include

begin_include
include|#
directive|include
file|"fopen-bin.h"
end_include

begin_include
include|#
directive|include
file|"spin.h"
end_include

begin_define
define|#
directive|define
name|CANT_FORK
end_define

begin_comment
comment|/* Map these standard functions to versions that can do I/O in a console    window. */
end_comment

begin_define
define|#
directive|define
name|printf
value|hacked_printf
end_define

begin_define
define|#
directive|define
name|fprintf
value|hacked_fprintf
end_define

begin_define
define|#
directive|define
name|vprintf
value|hacked_vfprintf
end_define

begin_define
define|#
directive|define
name|fputs
value|hacked_fputs
end_define

begin_define
define|#
directive|define
name|fputc
value|hacked_fputc
end_define

begin_undef
undef|#
directive|undef
name|putc
end_undef

begin_define
define|#
directive|define
name|putc
value|hacked_putc
end_define

begin_define
define|#
directive|define
name|fflush
value|hacked_fflush
end_define

begin_define
define|#
directive|define
name|fgetc
value|hacked_fgetc
end_define

begin_define
define|#
directive|define
name|POSIX_UTIME
end_define

begin_comment
comment|/* No declaration of strdup in MPW's string.h, oddly enough. */
end_comment

begin_function_decl
name|char
modifier|*
name|strdup
parameter_list|(
name|char
modifier|*
name|s1
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* '.' indicates drivers on the Mac, so we need a different filename. */
end_comment

begin_define
define|#
directive|define
name|GDBINIT_FILENAME
value|"_gdbinit"
end_define

begin_comment
comment|/* Commas are more common to separate dirnames in a path on Macs. */
end_comment

begin_define
define|#
directive|define
name|DIRNAME_SEPARATOR
value|','
end_define

begin_comment
comment|/* This is a real crufty hack. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIO
end_define

begin_comment
comment|/* Addons to the basic MPW-supported signal list. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIGQUIT
end_ifndef

begin_define
define|#
directive|define
name|SIGQUIT
value|(1<<6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIGHUP
end_ifndef

begin_define
define|#
directive|define
name|SIGHUP
value|(1<<7)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If __STDC__ is on, then this definition will be missing. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|fileno
end_ifndef

begin_define
define|#
directive|define
name|fileno
parameter_list|(
name|p
parameter_list|)
value|(p)->_file
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|R_OK
end_ifndef

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|StandAlone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mac_app
decl_stmt|;
end_decl_stmt

end_unit

