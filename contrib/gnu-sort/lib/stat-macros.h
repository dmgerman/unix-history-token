begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stat-related macros     Copyright (C) 1993, 1994, 2001, 2002, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert and Jim Meyering.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STAT_MACROS_H
end_ifndef

begin_define
define|#
directive|define
name|STAT_MACROS_H
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

begin_error
error|#
directive|error
literal|"you must include<sys/stat.h> before including this file"
end_error

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* contiguous */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISCTG
end_ifndef

begin_define
define|#
directive|define
name|S_ISCTG
parameter_list|(
name|p
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Cray DMF (data migration facility): off line, with data  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISOFD
end_ifndef

begin_define
define|#
directive|define
name|S_ISOFD
parameter_list|(
name|p
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Cray DMF (data migration facility): off line, with no data  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISOFL
end_ifndef

begin_define
define|#
directive|define
name|S_ISOFL
parameter_list|(
name|p
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If any of the following are undefined,    define them to their de facto standard values.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|S_ISUID
end_if

begin_define
define|#
directive|define
name|S_ISUID
value|04000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_ISGID
end_if

begin_define
define|#
directive|define
name|S_ISGID
value|02000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* S_ISVTX is a common extension to POSIX.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISVTX
end_ifndef

begin_define
define|#
directive|define
name|S_ISVTX
value|01000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IRUSR
operator|&&
name|S_IREAD
end_if

begin_define
define|#
directive|define
name|S_IRUSR
value|S_IREAD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IRUSR
end_if

begin_define
define|#
directive|define
name|S_IRUSR
value|00400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IRGRP
end_if

begin_define
define|#
directive|define
name|S_IRGRP
value|(S_IRUSR>> 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IROTH
end_if

begin_define
define|#
directive|define
name|S_IROTH
value|(S_IRUSR>> 6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IWUSR
operator|&&
name|S_IWRITE
end_if

begin_define
define|#
directive|define
name|S_IWUSR
value|S_IWRITE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IWUSR
end_if

begin_define
define|#
directive|define
name|S_IWUSR
value|00200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IWGRP
end_if

begin_define
define|#
directive|define
name|S_IWGRP
value|(S_IWUSR>> 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IWOTH
end_if

begin_define
define|#
directive|define
name|S_IWOTH
value|(S_IWUSR>> 6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IXUSR
operator|&&
name|S_IEXEC
end_if

begin_define
define|#
directive|define
name|S_IXUSR
value|S_IEXEC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IXUSR
end_if

begin_define
define|#
directive|define
name|S_IXUSR
value|00100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IXGRP
end_if

begin_define
define|#
directive|define
name|S_IXGRP
value|(S_IXUSR>> 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IXOTH
end_if

begin_define
define|#
directive|define
name|S_IXOTH
value|(S_IXUSR>> 6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IRWXU
end_if

begin_define
define|#
directive|define
name|S_IRWXU
value|(S_IRUSR | S_IWUSR | S_IXUSR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IRWXG
end_if

begin_define
define|#
directive|define
name|S_IRWXG
value|(S_IRGRP | S_IWGRP | S_IXGRP)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IRWXO
end_if

begin_define
define|#
directive|define
name|S_IRWXO
value|(S_IROTH | S_IWOTH | S_IXOTH)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* S_IXUGO is a common extension to POSIX.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|S_IXUGO
end_if

begin_define
define|#
directive|define
name|S_IXUGO
value|(S_IXUSR | S_IXGRP | S_IXOTH)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRWXUGO
end_ifndef

begin_define
define|#
directive|define
name|S_IRWXUGO
value|(S_IRWXU | S_IRWXG | S_IRWXO)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* All the mode bits that can be affected by chmod.  */
end_comment

begin_define
define|#
directive|define
name|CHMOD_MODE_BITS
define|\
value|(S_ISUID | S_ISGID | S_ISVTX | S_IRWXU | S_IRWXG | S_IRWXO)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STAT_MACROS_H */
end_comment

end_unit

