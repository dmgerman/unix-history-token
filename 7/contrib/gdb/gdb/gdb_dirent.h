begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Portable<dirent.h>.    Copyright 2000, 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDB_DIRENT_H
end_ifndef

begin_define
define|#
directive|define
name|GDB_DIRENT_H
value|1
end_define

begin_comment
comment|/* See description of `AC_HEADER_DIRENT' in the Autoconf manual.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DIRENT_H
end_ifdef

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_comment
comment|/* OK: dirent.h */
end_comment

begin_define
define|#
directive|define
name|NAMELEN
parameter_list|(
name|dirent
parameter_list|)
value|strlen ((dirent)->d_name)
end_define

begin_comment
comment|/* OK: strlen d_name */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dirent
value|direct
end_define

begin_define
define|#
directive|define
name|NAMELEN
parameter_list|(
name|dirent
parameter_list|)
value|(dirent)->d_namelen
end_define

begin_comment
comment|/* OK: d_namelen */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_NDIR_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/ndir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_DIR_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NDIR_H
end_ifdef

begin_include
include|#
directive|include
file|<ndir.h>
end_include

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
comment|/* not GDB_DIRENT_H */
end_comment

end_unit

