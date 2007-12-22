begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Return a string describing the type of a file.     Copyright (C) 1993, 1994, 2001, 2002, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert and Jim Meyering.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILE_TYPE_H
end_ifndef

begin_define
define|#
directive|define
name|FILE_TYPE_H
value|1
end_define

begin_if
if|#
directive|if
operator|!
name|defined
name|S_ISREG
operator|&&
operator|!
name|defined
name|S_IFREG
end_if

begin_expr_stmt
name|you
name|must
name|include
operator|<
name|sys
operator|/
name|stat
operator|.
name|h
operator|>
name|before
name|including
name|this
name|file
endif|#
directive|endif
name|char
specifier|const
operator|*
name|file_type
argument_list|(
expr|struct
name|stat
specifier|const
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFMT
end_ifndef

begin_define
define|#
directive|define
name|S_IFMT
value|0170000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|STAT_MACROS_BROKEN
end_if

begin_undef
undef|#
directive|undef
name|S_ISBLK
end_undef

begin_undef
undef|#
directive|undef
name|S_ISCHR
end_undef

begin_undef
undef|#
directive|undef
name|S_ISDIR
end_undef

begin_undef
undef|#
directive|undef
name|S_ISDOOR
end_undef

begin_undef
undef|#
directive|undef
name|S_ISFIFO
end_undef

begin_undef
undef|#
directive|undef
name|S_ISLNK
end_undef

begin_undef
undef|#
directive|undef
name|S_ISNAM
end_undef

begin_undef
undef|#
directive|undef
name|S_ISMPB
end_undef

begin_undef
undef|#
directive|undef
name|S_ISMPC
end_undef

begin_undef
undef|#
directive|undef
name|S_ISNWK
end_undef

begin_undef
undef|#
directive|undef
name|S_ISREG
end_undef

begin_undef
undef|#
directive|undef
name|S_ISSOCK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISBLK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFBLK
end_ifdef

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFBLK)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|m
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISCHR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFCHR
end_ifdef

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFCHR)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFDIR
end_ifdef

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDIR)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDOOR
end_ifndef

begin_comment
comment|/* Solaris 2.5 and up */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFDOOR
end_ifdef

begin_define
define|#
directive|define
name|S_ISDOOR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDOOR)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISDOOR
parameter_list|(
name|m
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISFIFO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFIFO
end_ifdef

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFIFO)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISLNK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFLNK
end_ifdef

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFLNK)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISMPB
end_ifndef

begin_comment
comment|/* V7 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFMPB
end_ifdef

begin_define
define|#
directive|define
name|S_ISMPB
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFMPB)
end_define

begin_define
define|#
directive|define
name|S_ISMPC
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFMPC)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISMPB
parameter_list|(
name|m
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|S_ISMPC
parameter_list|(
name|m
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISNAM
end_ifndef

begin_comment
comment|/* Xenix */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFNAM
end_ifdef

begin_define
define|#
directive|define
name|S_ISNAM
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFNAM)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISNAM
parameter_list|(
name|m
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISNWK
end_ifndef

begin_comment
comment|/* HP/UX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFNWK
end_ifdef

begin_define
define|#
directive|define
name|S_ISNWK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFNWK)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISNWK
parameter_list|(
name|m
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISREG
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFREG
end_ifdef

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFREG)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISSOCK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFSOCK
end_ifdef

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFSOCK)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_TYPEISMQ
end_ifndef

begin_define
define|#
directive|define
name|S_TYPEISMQ
parameter_list|(
name|p
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_TYPEISTMO
end_ifndef

begin_define
define|#
directive|define
name|S_TYPEISTMO
parameter_list|(
name|p
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_TYPEISSEM
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_INSEM
end_ifdef

begin_define
define|#
directive|define
name|S_TYPEISSEM
parameter_list|(
name|p
parameter_list|)
value|(S_ISNAM ((p)->st_mode)&& (p)->st_rdev == S_INSEM)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_TYPEISSEM
parameter_list|(
name|p
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_TYPEISSHM
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_INSHD
end_ifdef

begin_define
define|#
directive|define
name|S_TYPEISSHM
parameter_list|(
name|p
parameter_list|)
value|(S_ISNAM ((p)->st_mode)&& (p)->st_rdev == S_INSHD)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_TYPEISSHM
parameter_list|(
name|p
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FILE_TYPE_H */
end_comment

end_unit

