begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* getugroups.c -- return a list of the groups a user is in    Copyright (C) 1990, 1991 Free Software Foundation.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Written by David MacKenzie. */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
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
comment|/* not sun and not ultrix */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not _POSIX_VERSION */
end_comment

begin_function_decl
name|struct
name|group
modifier|*
name|getgrent
parameter_list|()
function_decl|;
end_function_decl

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
comment|/* _POSIX_VERSION */
end_comment

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not USG and not STDC_HEADERS */
end_comment

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USG or STDC_HEADERS */
end_comment

begin_comment
comment|/* Like `getgroups', but for user USERNAME instead of for    the current process. */
end_comment

begin_function
name|int
name|getugroups
parameter_list|(
name|maxcount
parameter_list|,
name|grouplist
parameter_list|,
name|username
parameter_list|)
name|int
name|maxcount
decl_stmt|;
name|GETGROUPS_T
modifier|*
name|grouplist
decl_stmt|;
name|char
modifier|*
name|username
decl_stmt|;
block|{
name|struct
name|group
modifier|*
name|grp
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|cp
decl_stmt|;
specifier|register
name|int
name|count
init|=
literal|0
decl_stmt|;
name|setgrent
argument_list|()
expr_stmt|;
while|while
condition|(
operator|(
name|grp
operator|=
name|getgrent
argument_list|()
operator|)
operator|!=
literal|0
condition|)
for|for
control|(
name|cp
operator|=
name|grp
operator|->
name|gr_mem
init|;
operator|*
name|cp
condition|;
operator|++
name|cp
control|)
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|username
argument_list|,
operator|*
name|cp
argument_list|)
condition|)
block|{
if|if
condition|(
name|maxcount
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|count
operator|>=
name|maxcount
condition|)
block|{
name|endgrent
argument_list|()
expr_stmt|;
return|return
name|count
return|;
block|}
name|grouplist
index|[
name|count
index|]
operator|=
name|grp
operator|->
name|gr_gid
expr_stmt|;
block|}
name|count
operator|++
expr_stmt|;
block|}
name|endgrent
argument_list|()
expr_stmt|;
return|return
name|count
return|;
block|}
end_function

end_unit

