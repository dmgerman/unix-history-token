begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* system.h: System-dependent declarations.  Include this first.    $Id: system.h,v 1.5 1997/07/31 20:34:36 karl Exp $     Copyright (C) 1997 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TEXINFO_SYSTEM_H
end_ifndef

begin_define
define|#
directive|define
name|TEXINFO_SYSTEM_H
end_define

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_comment
comment|/*<unistd.h> should be included before any preprocessor test    of _POSIX_VERSION.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UNISTD_H */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LOCALE_H
end_ifdef

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_comment
comment|/* Don't use bcopy!  Use memmove if source and destination may overlap,    memcpy otherwise.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_if
if|#
directive|if
operator|!
name|STDC_HEADERS
operator|&&
name|HAVE_MEMORY_H
end_if

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_function_decl
name|char
modifier|*
name|memchr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
end_ifdef

begin_define
define|#
directive|define
name|getopt
value|system_getopt
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_undef
undef|#
directive|undef
name|getopt
end_undef

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRERROR
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strerror
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|errno
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_include
include|#
directive|include
file|<perror.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FILE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FILE_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|O_RDONLY
end_ifndef

begin_comment
comment|/* Since<fcntl.h> is POSIX, prefer that to<sys/fcntl.h>.    This also avoids some useless warnings on (at least) Linux.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FCNTL_H
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_FCNTL_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FCNTL_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_SYS_FCNTL_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_FCNTL_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not O_RDONLY */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PWD_H
end_ifdef

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some systems don't declare this function in pwd.h. */
end_comment

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwnam
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Our library routines not included in any system library.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|xmalloc
argument_list|()
decl_stmt|,
modifier|*
name|xrealloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|xstrdup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TEXINFO_SYSTEM_H */
end_comment

end_unit

