begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* eaccess -- check if effective user id can access file    Copyright (C) 1990, 1991 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Written by David MacKenzie and Torbjorn Granlund. */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

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
name|_POSIX_VERSION
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__386BSD__
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|NGROUPS_MAX
end_ifdef

begin_undef
undef|#
directive|undef
name|NGROUPS_MAX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NGROUPS_MAX */
end_comment

begin_define
define|#
directive|define
name|NGROUPS_MAX
value|sysconf (_SC_NGROUPS_MAX)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __386BSD__ */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ultrix
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__386BSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|GETGROUPS_T
value|gid_t
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* sun or ultrix */
end_comment

begin_define
define|#
directive|define
name|GETGROUPS_T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun or ultrix */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not _POSIX_VERSION */
end_comment

begin_function_decl
name|uid_t
name|geteuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|gid_t
name|getegid
parameter_list|()
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NGROUPS_MAX
argument_list|)
operator|&&
name|defined
argument_list|(
name|NGROUPS
argument_list|)
end_if

begin_define
define|#
directive|define
name|NGROUPS_MAX
value|NGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NGROUPS_MAX and NGROUPS */
end_comment

begin_define
define|#
directive|define
name|GETGROUPS_T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX_VERSION */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|STDC_HEADERS
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
name|defined
argument_list|(
name|EACCES
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|EACCESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|EACCESS
value|EACCES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|F_OK
end_ifndef

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|eaccess_stat
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The user's effective user id. */
end_comment

begin_decl_stmt
specifier|static
name|uid_t
name|euid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The user's effective group id. */
end_comment

begin_decl_stmt
specifier|static
name|gid_t
name|egid
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NGROUPS_MAX
end_ifdef

begin_function_decl
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|in_group
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Array of group id's that the user is in. */
end_comment

begin_decl_stmt
specifier|static
name|GETGROUPS_T
modifier|*
name|groups
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of valid elements in `groups'. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ngroups
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonzero if the other static variables have valid values. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|initialized
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return 0 if the user has permission of type MODE on file PATH;    otherwise, return -1 and set `errno' to EACCESS.    Like access, except that it uses the effective user and group    id's instead of the real ones, and it does not check for read-only    filesystem, text busy, etc. */
end_comment

begin_function
name|int
name|eaccess
parameter_list|(
name|path
parameter_list|,
name|mode
parameter_list|)
name|char
modifier|*
name|path
decl_stmt|;
name|int
name|mode
decl_stmt|;
block|{
name|struct
name|stat
name|stats
decl_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|path
argument_list|,
operator|&
name|stats
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|eaccess_stat
argument_list|(
operator|&
name|stats
argument_list|,
name|mode
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Like eaccess, except that a pointer to a filled-in stat structure    describing the file is provided instead of a filename. */
end_comment

begin_function
name|int
name|eaccess_stat
parameter_list|(
name|statp
parameter_list|,
name|mode
parameter_list|)
name|struct
name|stat
modifier|*
name|statp
decl_stmt|;
name|int
name|mode
decl_stmt|;
block|{
name|int
name|granted
decl_stmt|;
name|mode
operator|&=
operator|(
name|X_OK
operator||
name|W_OK
operator||
name|R_OK
operator|)
expr_stmt|;
comment|/* Clear any bogus bits. */
if|if
condition|(
name|mode
operator|==
name|F_OK
condition|)
return|return
literal|0
return|;
comment|/* The file exists. */
if|if
condition|(
name|initialized
operator|==
literal|0
condition|)
block|{
name|initialized
operator|=
literal|1
expr_stmt|;
name|euid
operator|=
name|geteuid
argument_list|()
expr_stmt|;
name|egid
operator|=
name|getegid
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|NGROUPS_MAX
name|groups
operator|=
operator|(
name|GETGROUPS_T
operator|*
operator|)
name|xmalloc
argument_list|(
name|NGROUPS_MAX
operator|*
sizeof|sizeof
argument_list|(
name|GETGROUPS_T
argument_list|)
argument_list|)
expr_stmt|;
name|ngroups
operator|=
name|getgroups
argument_list|(
name|NGROUPS_MAX
argument_list|,
name|groups
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/* The super-user can read and write any file, and execute any file      that anyone can execute. */
if|if
condition|(
name|euid
operator|==
literal|0
operator|&&
operator|(
operator|(
name|mode
operator|&
name|X_OK
operator|)
operator|==
literal|0
operator|||
operator|(
name|statp
operator|->
name|st_mode
operator|&
literal|0111
operator|)
operator|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|euid
operator|==
name|statp
operator|->
name|st_uid
condition|)
name|granted
operator|=
operator|(
name|statp
operator|->
name|st_mode
operator|&
operator|(
name|mode
operator|<<
literal|6
operator|)
operator|)
operator|>>
literal|6
expr_stmt|;
elseif|else
if|if
condition|(
name|egid
operator|==
name|statp
operator|->
name|st_gid
ifdef|#
directive|ifdef
name|NGROUPS_MAX
operator|||
name|in_group
argument_list|(
name|statp
operator|->
name|st_gid
argument_list|)
endif|#
directive|endif
condition|)
name|granted
operator|=
operator|(
name|statp
operator|->
name|st_mode
operator|&
operator|(
name|mode
operator|<<
literal|3
operator|)
operator|)
operator|>>
literal|3
expr_stmt|;
else|else
name|granted
operator|=
operator|(
name|statp
operator|->
name|st_mode
operator|&
name|mode
operator|)
expr_stmt|;
if|if
condition|(
name|granted
operator|==
name|mode
condition|)
return|return
literal|0
return|;
name|errno
operator|=
name|EACCESS
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|NGROUPS_MAX
end_ifdef

begin_function
specifier|static
name|int
name|in_group
parameter_list|(
name|gid
parameter_list|)
name|GETGROUPS_T
name|gid
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ngroups
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|gid
operator|==
name|groups
index|[
name|i
index|]
condition|)
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TEST
end_ifdef

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|eaccess
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
name|atoi
argument_list|(
name|argv
index|[
literal|2
index|]
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

