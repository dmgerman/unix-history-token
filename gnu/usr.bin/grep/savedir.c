begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* savedir.c -- save the list of files in a directory in a string    Copyright (C) 1990, 1997, 1998, 1999, 2000 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_define
define|#
directive|define
name|NAMLEN
parameter_list|(
name|dirent
parameter_list|)
value|strlen((dirent)->d_name)
end_define

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
name|NAMLEN
parameter_list|(
name|dirent
parameter_list|)
value|(dirent)->d_namlen
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

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|realloc
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

begin_ifndef
ifndef|#
directive|ifndef
name|stpcpy
end_ifndef

begin_function_decl
name|char
modifier|*
name|stpcpy
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
file|"savedir.h"
end_include

begin_comment
comment|/* Return a freshly allocated string containing the filenames    in directory DIR, separated by '\0' characters;    the end is marked by two '\0' characters in a row.    NAME_SIZE is the number of bytes to initially allocate    for the string; it will be enlarged as needed.    Return NULL if DIR cannot be opened or if out of memory. */
end_comment

begin_function
name|char
modifier|*
name|savedir
parameter_list|(
specifier|const
name|char
modifier|*
name|dir
parameter_list|,
name|off_t
name|name_size
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
name|char
modifier|*
name|namep
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
comment|/* Be sure name_size is at least `1' so there's room for      the final NUL byte.  */
name|name_size
operator|+=
operator|!
name|name_size
expr_stmt|;
name|name_space
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|name_size
argument_list|)
expr_stmt|;
if|if
condition|(
name|name_space
operator|==
name|NULL
condition|)
block|{
name|closedir
argument_list|(
name|dirp
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|namep
operator|=
name|name_space
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
comment|/* Skip "." and ".." (some NFS filesystems' directories lack them). */
if|if
condition|(
name|dp
operator|->
name|d_name
index|[
literal|0
index|]
operator|!=
literal|'.'
operator|||
operator|(
name|dp
operator|->
name|d_name
index|[
literal|1
index|]
operator|!=
literal|'\0'
operator|&&
operator|(
name|dp
operator|->
name|d_name
index|[
literal|1
index|]
operator|!=
literal|'.'
operator|||
name|dp
operator|->
name|d_name
index|[
literal|2
index|]
operator|!=
literal|'\0'
operator|)
operator|)
condition|)
block|{
name|off_t
name|size_needed
init|=
operator|(
name|namep
operator|-
name|name_space
operator|)
operator|+
name|NAMLEN
argument_list|(
name|dp
argument_list|)
operator|+
literal|2
decl_stmt|;
if|if
condition|(
name|size_needed
operator|>
name|name_size
condition|)
block|{
name|char
modifier|*
name|new_name_space
decl_stmt|;
while|while
condition|(
name|size_needed
operator|>
name|name_size
condition|)
name|name_size
operator|+=
literal|1024
expr_stmt|;
name|new_name_space
operator|=
name|realloc
argument_list|(
name|name_space
argument_list|,
name|name_size
argument_list|)
expr_stmt|;
if|if
condition|(
name|new_name_space
operator|==
name|NULL
condition|)
block|{
name|closedir
argument_list|(
name|dirp
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|namep
operator|+=
name|new_name_space
operator|-
name|name_space
expr_stmt|;
name|name_space
operator|=
name|new_name_space
expr_stmt|;
block|}
name|namep
operator|=
name|stpcpy
argument_list|(
name|namep
argument_list|,
name|dp
operator|->
name|d_name
argument_list|)
operator|+
literal|1
expr_stmt|;
block|}
block|}
operator|*
name|namep
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|CLOSEDIR
argument_list|(
name|dirp
argument_list|)
condition|)
block|{
name|free
argument_list|(
name|name_space
argument_list|)
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

