begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* backupfile.c -- make Emacs style backup file names    Copyright (C) 1990 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* David MacKenzie<djm@ai.mit.edu>.    Some algorithms adapted from GNU Emacs. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"backupfile.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|||
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DIRENT
end_ifdef

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|direct
end_ifdef

begin_undef
undef|#
directive|undef
name|direct
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|direct
value|dirent
end_define

begin_define
define|#
directive|define
name|NLENGTH
parameter_list|(
name|direct
parameter_list|)
value|(strlen((direct)->d_name))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !DIRENT */
end_comment

begin_define
define|#
directive|define
name|NLENGTH
parameter_list|(
name|direct
parameter_list|)
value|((direct)->d_namlen)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSNDIR
end_ifdef

begin_include
include|#
directive|include
file|<sys/ndir.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !SYSNDIR */
end_comment

begin_include
include|#
directive|include
file|<ndir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SYSNDIR */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !USG */
end_comment

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !USG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !DIRENT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VOID_CLOSEDIR
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|isascii
end_ifndef

begin_define
define|#
directive|define
name|ISDIGIT
parameter_list|(
name|c
parameter_list|)
value|(isdigit ((unsigned char) (c)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISDIGIT
parameter_list|(
name|c
parameter_list|)
value|(isascii (c)&& isdigit (c))
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
name|HAVE_UNISTD_H
argument_list|)
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
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
end_if

begin_comment
comment|/* POSIX does not require that the d_ino field be present, and some    systems do not provide it. */
end_comment

begin_define
define|#
directive|define
name|REAL_DIR_ENTRY
parameter_list|(
name|dp
parameter_list|)
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REAL_DIR_ENTRY
parameter_list|(
name|dp
parameter_list|)
value|((dp)->d_ino != 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Which type of backup file names are generated. */
end_comment

begin_decl_stmt
name|enum
name|backup_type
name|backup_type
init|=
name|none
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The extension added to file names to produce a simple (as opposed    to numbered) backup file name. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|simple_backup_suffix
init|=
literal|"~"
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|basename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|dirname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|char
modifier|*
name|concat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|find_backup_file_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|char
modifier|*
name|make_version_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|max_backup_version
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|version_number
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the name of the new backup file for file FILE,    allocated with malloc.  Return 0 if out of memory.    FILE must not end with a '/' unless it is the root directory.    Do not call this function if backup_type == none. */
end_comment

begin_function
name|char
modifier|*
name|find_backup_file_name
parameter_list|(
name|file
parameter_list|)
name|char
modifier|*
name|file
decl_stmt|;
block|{
name|char
modifier|*
name|dir
decl_stmt|;
name|char
modifier|*
name|base_versions
decl_stmt|;
name|int
name|highest_backup
decl_stmt|;
if|if
condition|(
name|backup_type
operator|==
name|simple
condition|)
return|return
name|concat
argument_list|(
name|file
argument_list|,
name|simple_backup_suffix
argument_list|)
return|;
name|base_versions
operator|=
name|concat
argument_list|(
name|basename
argument_list|(
name|file
argument_list|)
argument_list|,
literal|".~"
argument_list|)
expr_stmt|;
if|if
condition|(
name|base_versions
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|dir
operator|=
name|dirname
argument_list|(
name|file
argument_list|)
expr_stmt|;
if|if
condition|(
name|dir
operator|==
literal|0
condition|)
block|{
name|free
argument_list|(
name|base_versions
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|highest_backup
operator|=
name|max_backup_version
argument_list|(
name|base_versions
argument_list|,
name|dir
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|base_versions
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|dir
argument_list|)
expr_stmt|;
if|if
condition|(
name|backup_type
operator|==
name|numbered_existing
operator|&&
name|highest_backup
operator|==
literal|0
condition|)
return|return
name|concat
argument_list|(
name|file
argument_list|,
name|simple_backup_suffix
argument_list|)
return|;
return|return
name|make_version_name
argument_list|(
name|file
argument_list|,
name|highest_backup
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Return the number of the highest-numbered backup file for file    FILE in directory DIR.  If there are no numbered backups    of FILE in DIR, or an error occurs reading DIR, return 0.    FILE should already have ".~" appended to it. */
end_comment

begin_function
specifier|static
name|int
name|max_backup_version
parameter_list|(
name|file
parameter_list|,
name|dir
parameter_list|)
name|char
modifier|*
name|file
decl_stmt|,
decl|*
name|dir
decl_stmt|;
end_function

begin_block
block|{
name|DIR
modifier|*
name|dirp
decl_stmt|;
name|struct
name|direct
modifier|*
name|dp
decl_stmt|;
name|int
name|highest_version
decl_stmt|;
name|int
name|this_version
decl_stmt|;
name|int
name|file_name_length
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
operator|!
name|dirp
condition|)
return|return
literal|0
return|;
name|highest_version
operator|=
literal|0
expr_stmt|;
name|file_name_length
operator|=
name|strlen
argument_list|(
name|file
argument_list|)
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
literal|0
condition|)
block|{
if|if
condition|(
operator|!
name|REAL_DIR_ENTRY
argument_list|(
name|dp
argument_list|)
operator|||
name|NLENGTH
argument_list|(
name|dp
argument_list|)
operator|<=
name|file_name_length
condition|)
continue|continue;
name|this_version
operator|=
name|version_number
argument_list|(
name|file
argument_list|,
name|dp
operator|->
name|d_name
argument_list|,
name|file_name_length
argument_list|)
expr_stmt|;
if|if
condition|(
name|this_version
operator|>
name|highest_version
condition|)
name|highest_version
operator|=
name|this_version
expr_stmt|;
block|}
if|if
condition|(
name|CLOSEDIR
argument_list|(
name|dirp
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
name|highest_version
return|;
block|}
end_block

begin_comment
comment|/* Return a string, allocated with malloc, containing    "FILE.~VERSION~".  Return 0 if out of memory. */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|make_version_name
parameter_list|(
name|file
parameter_list|,
name|version
parameter_list|)
name|char
modifier|*
name|file
decl_stmt|;
name|int
name|version
decl_stmt|;
block|{
name|char
modifier|*
name|backup_name
decl_stmt|;
name|backup_name
operator|=
name|malloc
argument_list|(
name|strlen
argument_list|(
name|file
argument_list|)
operator|+
literal|16
argument_list|)
expr_stmt|;
if|if
condition|(
name|backup_name
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|sprintf
argument_list|(
name|backup_name
argument_list|,
literal|"%s.~%d~"
argument_list|,
name|file
argument_list|,
name|version
argument_list|)
expr_stmt|;
return|return
name|backup_name
return|;
block|}
end_function

begin_comment
comment|/* If BACKUP is a numbered backup of BASE, return its version number;    otherwise return 0.  BASE_LENGTH is the length of BASE.    BASE should already have ".~" appended to it. */
end_comment

begin_function
specifier|static
name|int
name|version_number
parameter_list|(
name|base
parameter_list|,
name|backup
parameter_list|,
name|base_length
parameter_list|)
name|char
modifier|*
name|base
decl_stmt|;
name|char
modifier|*
name|backup
decl_stmt|;
name|int
name|base_length
decl_stmt|;
block|{
name|int
name|version
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|version
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|base
argument_list|,
name|backup
argument_list|,
name|base_length
argument_list|)
operator|&&
name|ISDIGIT
argument_list|(
name|backup
index|[
name|base_length
index|]
argument_list|)
condition|)
block|{
for|for
control|(
name|p
operator|=
operator|&
name|backup
index|[
name|base_length
index|]
init|;
name|ISDIGIT
argument_list|(
operator|*
name|p
argument_list|)
condition|;
operator|++
name|p
control|)
name|version
operator|=
name|version
operator|*
literal|10
operator|+
operator|*
name|p
operator|-
literal|'0'
expr_stmt|;
if|if
condition|(
name|p
index|[
literal|0
index|]
operator|!=
literal|'~'
operator|||
name|p
index|[
literal|1
index|]
condition|)
name|version
operator|=
literal|0
expr_stmt|;
block|}
return|return
name|version
return|;
block|}
end_function

begin_comment
comment|/* Return the newly-allocated concatenation of STR1 and STR2.    If out of memory, return 0. */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|concat
parameter_list|(
name|str1
parameter_list|,
name|str2
parameter_list|)
name|char
modifier|*
name|str1
decl_stmt|,
decl|*
name|str2
decl_stmt|;
end_function

begin_block
block|{
name|char
modifier|*
name|newstr
decl_stmt|;
name|char
name|str1_length
init|=
name|strlen
argument_list|(
name|str1
argument_list|)
decl_stmt|;
name|newstr
operator|=
name|malloc
argument_list|(
name|str1_length
operator|+
name|strlen
argument_list|(
name|str2
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|newstr
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|strcpy
argument_list|(
name|newstr
argument_list|,
name|str1
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|newstr
operator|+
name|str1_length
argument_list|,
name|str2
argument_list|)
expr_stmt|;
return|return
name|newstr
return|;
block|}
end_block

end_unit

