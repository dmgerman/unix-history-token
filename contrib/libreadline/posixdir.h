begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* posixdir.h -- Posix directory reading includes and defines. */
end_comment

begin_comment
comment|/* Copyright (C) 1987,1991 Free Software Foundation, Inc.     This file is part of GNU Bash, the Bourne Again SHell.     Bash is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     Bash is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with Bash; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_comment
comment|/* This file should be included instead of<dirent.h> or<sys/dir.h>. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIXDIR_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_POSIXDIR_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DIRENT_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_define
define|#
directive|define
name|D_NAMLEN
parameter_list|(
name|d
parameter_list|)
value|(strlen ((d)->d_name))
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
name|HAVE_SYS_NDIR_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ndir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_DIR_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_NDIR_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<ndir.h>
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
argument_list|(
name|dirent
argument_list|)
end_if

begin_define
define|#
directive|define
name|dirent
value|direct
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !dirent */
end_comment

begin_define
define|#
directive|define
name|D_NAMLEN
parameter_list|(
name|d
parameter_list|)
value|((d)->d_namlen)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_DIRENT_H */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STRUCT_DIRENT_HAS_D_INO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|STRUCT_DIRENT_HAS_D_FILENO
argument_list|)
end_if

begin_define
define|#
directive|define
name|d_fileno
value|d_ino
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
comment|/* !_POSIXDIR_H_ */
end_comment

end_unit

