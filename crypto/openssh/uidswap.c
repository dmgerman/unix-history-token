begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * Code for uid-swapping.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$OpenBSD: uidswap.c,v 1.9 2000/09/07 20:27:55 deraadt Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"ssh.h"
end_include

begin_include
include|#
directive|include
file|"uidswap.h"
end_include

begin_comment
comment|/*  * Note: all these functions must work in all of the following cases:  *    1. euid=0, ruid=0  *    2. euid=0, ruid!=0  *    3. euid!=0, ruid!=0  * Additionally, they must work regardless of whether the system has  * POSIX saved uids or not.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_SAVED_IDS
end_ifdef

begin_comment
comment|/* Lets assume that posix saved ids also work with seteuid, even though that    is not part of the posix specification. */
end_comment

begin_define
define|#
directive|define
name|SAVED_IDS_WORK_WITH_SETEUID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_SAVED_IDS */
end_comment

begin_comment
comment|/* Saved effective uid. */
end_comment

begin_decl_stmt
specifier|static
name|uid_t
name|saved_euid
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Temporarily changes to the given uid.  If the effective user  * id is not root, this does nothing.  This call cannot be nested.  */
end_comment

begin_function
name|void
name|temporarily_use_uid
parameter_list|(
name|uid_t
name|uid
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|SAVED_IDS_WORK_WITH_SETEUID
comment|/* Save the current euid. */
name|saved_euid
operator|=
name|geteuid
argument_list|()
expr_stmt|;
comment|/* Set the effective uid to the given (unprivileged) uid. */
if|if
condition|(
name|seteuid
argument_list|(
name|uid
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|debug
argument_list|(
literal|"seteuid %u: %.100s"
argument_list|,
operator|(
name|u_int
operator|)
name|uid
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* SAVED_IDS_WORK_WITH_SETUID */
comment|/* Propagate the privileged uid to all of our uids. */
if|if
condition|(
name|setuid
argument_list|(
name|geteuid
argument_list|()
argument_list|)
operator|<
literal|0
condition|)
name|debug
argument_list|(
literal|"setuid %u: %.100s"
argument_list|,
operator|(
name|u_int
operator|)
name|geteuid
argument_list|()
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Set the effective uid to the given (unprivileged) uid. */
if|if
condition|(
name|seteuid
argument_list|(
name|uid
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|debug
argument_list|(
literal|"seteuid %u: %.100s"
argument_list|,
operator|(
name|u_int
operator|)
name|uid
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SAVED_IDS_WORK_WITH_SETEUID */
block|}
end_function

begin_comment
comment|/*  * Restores to the original uid.  */
end_comment

begin_function
name|void
name|restore_uid
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|SAVED_IDS_WORK_WITH_SETEUID
comment|/* Set the effective uid back to the saved uid. */
if|if
condition|(
name|seteuid
argument_list|(
name|saved_euid
argument_list|)
operator|<
literal|0
condition|)
name|debug
argument_list|(
literal|"seteuid %u: %.100s"
argument_list|,
operator|(
name|u_int
operator|)
name|saved_euid
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* SAVED_IDS_WORK_WITH_SETEUID */
comment|/* 	 * We are unable to restore the real uid to its unprivileged value. 	 * Propagate the real uid (usually more privileged) to effective uid 	 * as well. 	 */
name|setuid
argument_list|(
name|getuid
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SAVED_IDS_WORK_WITH_SETEUID */
block|}
end_function

begin_comment
comment|/*  * Permanently sets all uids to the given uid.  This cannot be  * called while temporarily_use_uid is effective.  */
end_comment

begin_function
name|void
name|permanently_set_uid
parameter_list|(
name|uid_t
name|uid
parameter_list|)
block|{
if|if
condition|(
name|setuid
argument_list|(
name|uid
argument_list|)
operator|<
literal|0
condition|)
name|debug
argument_list|(
literal|"setuid %u: %.100s"
argument_list|,
operator|(
name|u_int
operator|)
name|uid
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

