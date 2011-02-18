begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sysdep.h -- handle host dependencies for binutils    Copyright 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000,    2001, 2002, 2003, 2005, 2006, 2007 Free Software Foundation, Inc.     This file is part of GNU Binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|_BIN_SYSDEP_H
end_ifndef

begin_define
define|#
directive|define
name|_BIN_SYSDEP_H
end_define

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

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
file|"bfdver.h"
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_BINARY_FOPEN
end_ifdef

begin_include
include|#
directive|include
file|"fopen-bin.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"fopen-same.h"
end_include

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRINGS_H
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strrchr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_STPCPY
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|stpcpy
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_STRSTR
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|strstr
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
name|HAVE_SBRK
end_ifdef

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_SBRK
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|sbrk
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_GETENV
end_if

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

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_ENVIRON
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_FPRINTF
end_if

begin_function_decl
specifier|extern
name|int
name|fprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_SNPRINTF
end_if

begin_function_decl
specifier|extern
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_VSNPRINTF
end_if

begin_function_decl
specifier|extern
name|int
name|vsnprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_RDONLY
end_ifndef

begin_define
define|#
directive|define
name|O_RDONLY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_RDWR
end_ifndef

begin_define
define|#
directive|define
name|O_RDWR
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_CUR
end_ifndef

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_END
end_ifndef

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|C_ALLOCA
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|alloca
end_undef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_ALLOCA_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|C_ALLOCA
argument_list|)
end_if

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_comment
comment|/* predefined by HP cc +Olibcalls */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_function_decl
name|char
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__, __hpux */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* alloca */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ALLOCA_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LOCALE_H
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ENABLE_NLS
end_ifndef

begin_comment
comment|/* The Solaris version of locale.h always includes libintl.h.  If we have       been configured with --disable-nls then ENABLE_NLS will not be defined       and the dummy definitions of bindtextdomain (et al) below will conflict       with the defintions in libintl.h.  So we define these values to prevent       the bogus inclusion of libintl.h.  */
end_comment

begin_define
define|#
directive|define
name|_LIBINTL_H
end_define

begin_define
define|#
directive|define
name|_LIBGETTEXT_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_NLS
end_ifdef

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|gettext (String)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|gettext_noop
end_ifdef

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|gettext_noop (String)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|gettext
parameter_list|(
name|Msgid
parameter_list|)
value|(Msgid)
end_define

begin_define
define|#
directive|define
name|dgettext
parameter_list|(
name|Domainname
parameter_list|,
name|Msgid
parameter_list|)
value|(Msgid)
end_define

begin_define
define|#
directive|define
name|dcgettext
parameter_list|(
name|Domainname
parameter_list|,
name|Msgid
parameter_list|,
name|Category
parameter_list|)
value|(Msgid)
end_define

begin_define
define|#
directive|define
name|textdomain
parameter_list|(
name|Domainname
parameter_list|)
value|while (0)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|bindtextdomain
parameter_list|(
name|Domainname
parameter_list|,
name|Dirname
parameter_list|)
value|while (0)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Used by ar.c and objcopy.c.  */
end_comment

begin_define
define|#
directive|define
name|BUFSIZE
value|8192
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BIN_SYSDEP_H */
end_comment

end_unit

