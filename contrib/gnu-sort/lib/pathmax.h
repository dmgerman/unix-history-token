begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define PATH_MAX somehow.  Requires sys/types.h.    Copyright (C) 1992, 1999, 2001, 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATHMAX_H
end_ifndef

begin_define
define|#
directive|define
name|_PATHMAX_H
end_define

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
end_if

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
comment|/* Non-POSIX BSD systems might have gcc's limits.h, which doesn't define    PATH_MAX but might cause redefinition warnings when sys/param.h is    later included (as on MORE/BSD 4.3).  */
end_comment

begin_if
if|#
directive|if
name|defined
name|_POSIX_VERSION
operator|||
operator|!
name|defined
name|__GNUC__
end_if

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_PATH_MAX
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_PATH_MAX
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|PATH_MAX
operator|&&
name|defined
name|_PC_PATH_MAX
end_if

begin_define
define|#
directive|define
name|PATH_MAX
value|(pathconf ("/", _PC_PATH_MAX)< 1 ? 1024 \ 		    : pathconf ("/", _PC_PATH_MAX))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Don't include sys/param.h if it already has been.  */
end_comment

begin_if
if|#
directive|if
name|defined
name|HAVE_SYS_PARAM_H
operator|&&
operator|!
name|defined
name|PATH_MAX
operator|&&
operator|!
name|defined
name|MAXPATHLEN
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|PATH_MAX
operator|&&
name|defined
name|MAXPATHLEN
end_if

begin_define
define|#
directive|define
name|PATH_MAX
value|MAXPATHLEN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_MAX
end_ifndef

begin_define
define|#
directive|define
name|PATH_MAX
value|_POSIX_PATH_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATHMAX_H */
end_comment

end_unit

