begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* savedir.c -- save the list of files in a directory in a string     Copyright 1990, 1997, 1998, 1999, 2000, 2001 Free Software    Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by David MacKenzie<djm@gnu.ai.mit.edu>. */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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

begin_if
if|#
directive|if
name|HAVE_DIRENT_H
end_if

begin_include
include|#
directive|include
file|<dirent.h>
end_include

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

begin_if
if|#
directive|if
name|HAVE_SYS_NDIR_H
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
name|HAVE_SYS_DIR_H
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
name|HAVE_NDIR_H
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOSEDIR_VOID
end_ifdef

begin_comment
comment|/* Fake a return value. */
end_comment

begin_define
define|#
directive|define
name|CLOSEDIR
parameter_list|(
name|d
parameter_list|)
value|(closedir (d), 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CLOSEDIR
parameter_list|(
name|d
parameter_list|)
value|closedir (d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"savedir.h"
end_include

begin_include
include|#
directive|include
file|"xalloc.h"
end_include

begin_comment
comment|/* Return a freshly allocated string containing the filenames    in directory DIR, separated by '\0' characters;    the end is marked by two '\0' characters in a row.    Return NULL (setting errno) if DIR cannot be opened, read, or closed.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAME_SIZE_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|NAME_SIZE_DEFAULT
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|savedir
parameter_list|(
specifier|const
name|char
modifier|*
name|dir
parameter_list|)
block|{
name|DIR
modifier|*
name|dirp
decl_stmt|;
name|struct
name|dirent
modifier|*
name|dp
decl_stmt|;
name|char
modifier|*
name|name_space
decl_stmt|;
name|size_t
name|allocated
init|=
name|NAME_SIZE_DEFAULT
decl_stmt|;
name|size_t
name|used
init|=
literal|0
decl_stmt|;
name|int
name|save_errno
decl_stmt|;
name|dirp
operator|=
name|opendir
argument_list|(
name|dir
argument_list|)
expr_stmt|;
if|if
condition|(
name|dirp
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|name_space
operator|=
name|xmalloc
argument_list|(
name|allocated
argument_list|)
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|dp
operator|=
name|readdir
argument_list|(
name|dirp
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
comment|/* Skip "", ".", and "..".  "" is returned by at least one buggy          implementation: Solaris 2.4 readdir on NFS filesystems.  */
name|char
specifier|const
modifier|*
name|entry
init|=
name|dp
operator|->
name|d_name
decl_stmt|;
if|if
condition|(
name|entry
index|[
name|entry
index|[
literal|0
index|]
operator|!=
literal|'.'
condition|?
literal|0
else|:
name|entry
index|[
literal|1
index|]
operator|!=
literal|'.'
condition|?
literal|1
else|:
literal|2
index|]
operator|!=
literal|'\0'
condition|)
block|{
name|size_t
name|entry_size
init|=
name|strlen
argument_list|(
name|entry
argument_list|)
operator|+
literal|1
decl_stmt|;
if|if
condition|(
name|used
operator|+
name|entry_size
operator|<
name|used
condition|)
name|xalloc_die
argument_list|()
expr_stmt|;
if|if
condition|(
name|allocated
operator|<=
name|used
operator|+
name|entry_size
condition|)
block|{
do|do
block|{
if|if
condition|(
literal|2
operator|*
name|allocated
operator|<
name|allocated
condition|)
name|xalloc_die
argument_list|()
expr_stmt|;
name|allocated
operator|*=
literal|2
expr_stmt|;
block|}
do|while
condition|(
name|allocated
operator|<=
name|used
operator|+
name|entry_size
condition|)
do|;
name|name_space
operator|=
name|xrealloc
argument_list|(
name|name_space
argument_list|,
name|allocated
argument_list|)
expr_stmt|;
block|}
name|memcpy
argument_list|(
name|name_space
operator|+
name|used
argument_list|,
name|entry
argument_list|,
name|entry_size
argument_list|)
expr_stmt|;
name|used
operator|+=
name|entry_size
expr_stmt|;
block|}
block|}
name|name_space
index|[
name|used
index|]
operator|=
literal|'\0'
expr_stmt|;
name|save_errno
operator|=
name|errno
expr_stmt|;
if|if
condition|(
name|CLOSEDIR
argument_list|(
name|dirp
argument_list|)
operator|!=
literal|0
condition|)
name|save_errno
operator|=
name|errno
expr_stmt|;
if|if
condition|(
name|save_errno
operator|!=
literal|0
condition|)
block|{
name|free
argument_list|(
name|name_space
argument_list|)
expr_stmt|;
name|errno
operator|=
name|save_errno
expr_stmt|;
return|return
name|NULL
return|;
block|}
return|return
name|name_space
return|;
block|}
end_function

end_unit

