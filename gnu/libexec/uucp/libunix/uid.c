begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* uid.c    Switch back and forth between UUCP and user permissions.     Copyright (C) 1992, 1995 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|"uudefs.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* NetBSD apparently does not support setuid as required by POSIX when    using saved setuid, so use seteuid instead.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_SETEUID
end_if

begin_define
define|#
directive|define
name|setuid
value|seteuid
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Switch to permissions of the invoking user.  */
end_comment

begin_function
name|boolean
name|fsuser_perms
parameter_list|(
name|pieuid
parameter_list|)
name|uid_t
modifier|*
name|pieuid
decl_stmt|;
block|{
name|uid_t
name|ieuid
decl_stmt|,
name|iuid
decl_stmt|;
name|ieuid
operator|=
name|geteuid
argument_list|()
expr_stmt|;
name|iuid
operator|=
name|getuid
argument_list|()
expr_stmt|;
if|if
condition|(
name|pieuid
operator|!=
name|NULL
condition|)
operator|*
name|pieuid
operator|=
name|ieuid
expr_stmt|;
if|#
directive|if
name|HAVE_SETREUID
comment|/* Swap the effective user id and the real user id.  We can then      swap them back again when we want to return to the uucp user's      permissions.  */
if|if
condition|(
name|setreuid
argument_list|(
name|ieuid
argument_list|,
name|iuid
argument_list|)
operator|<
literal|0
condition|)
block|{
name|ulog
argument_list|(
name|LOG_ERROR
argument_list|,
literal|"setreuid (%ld, %ld): %s"
argument_list|,
operator|(
name|long
operator|)
name|ieuid
argument_list|,
operator|(
name|long
operator|)
name|iuid
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
block|}
else|#
directive|else
comment|/* ! HAVE_SETREUID */
if|#
directive|if
name|HAVE_SAVED_SETUID
comment|/* Set the effective user id to the real user id.  Since the      effective user id is saved (it's the saved setuid) we will able      to set back to it later.  If the real user id is root we will not      be able to switch back and forth, so don't even try.  */
if|if
condition|(
name|iuid
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|setuid
argument_list|(
name|iuid
argument_list|)
operator|<
literal|0
condition|)
block|{
name|ulog
argument_list|(
name|LOG_ERROR
argument_list|,
literal|"setuid (%ld): %s"
argument_list|,
operator|(
name|long
operator|)
name|iuid
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
block|}
block|}
else|#
directive|else
comment|/* ! HAVE_SAVED_SETUID */
comment|/* There's no way to switch between real permissions and effective      permissions.  Just try to open the file with the uucp      permissions.  */
endif|#
directive|endif
comment|/* ! HAVE_SAVED_SETUID */
endif|#
directive|endif
comment|/* ! HAVE_SETREUID */
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/* Restore the uucp permissions.  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|boolean
name|fsuucp_perms
parameter_list|(
name|ieuid
parameter_list|)
name|long
name|ieuid
decl_stmt|;
block|{
if|#
directive|if
name|HAVE_SETREUID
comment|/* Swap effective and real user id's back to what they were.  */
if|if
condition|(
operator|!
name|fsuser_perms
argument_list|(
operator|(
name|uid_t
operator|*
operator|)
name|NULL
argument_list|)
condition|)
return|return
name|FALSE
return|;
else|#
directive|else
comment|/* ! HAVE_SETREUID */
if|#
directive|if
name|HAVE_SAVED_SETUID
comment|/* Set ourselves back to our original effective user id.  */
if|if
condition|(
name|setuid
argument_list|(
operator|(
name|uid_t
operator|)
name|ieuid
argument_list|)
operator|<
literal|0
condition|)
block|{
name|ulog
argument_list|(
name|LOG_ERROR
argument_list|,
literal|"setuid (%ld): %s"
argument_list|,
operator|(
name|long
operator|)
name|ieuid
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Is this error message helpful or confusing?  */
if|if
condition|(
name|errno
operator|==
name|EPERM
condition|)
name|ulog
argument_list|(
name|LOG_ERROR
argument_list|,
literal|"Probably HAVE_SAVED_SETUID in policy.h should be set to 0"
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
block|}
else|#
directive|else
comment|/* ! HAVE_SAVED_SETUID */
comment|/* We didn't switch, no need to switch back.  */
endif|#
directive|endif
comment|/* ! HAVE_SAVED_SETUID */
endif|#
directive|endif
comment|/* ! HAVE_SETREUID */
return|return
name|TRUE
return|;
block|}
end_function

end_unit

