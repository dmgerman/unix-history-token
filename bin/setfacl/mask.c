begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Chris D. Faulhaber  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR THE VOICES IN HIS HEAD BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/acl.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_include
include|#
directive|include
file|"setfacl.h"
end_include

begin_comment
comment|/* set the appropriate mask the given ACL's */
end_comment

begin_function
name|int
name|set_acl_mask
parameter_list|(
name|acl_t
name|prev_acl
parameter_list|)
block|{
name|acl_t
name|acl
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|/* 	 * ... if a mask entry is specified, then the permissions of the mask 	 * entry in the resulting ACL shall be set to the permissions in the 	 * specified ACL mask entry. 	 */
if|if
condition|(
name|have_mask
condition|)
return|return
literal|0
return|;
name|acl
operator|=
name|acl_dup
argument_list|(
name|prev_acl
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|acl
condition|)
name|err
argument_list|(
name|EX_OSERR
argument_list|,
literal|"acl_dup() failed"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|n_flag
condition|)
block|{
comment|/* 		 * If no mask entry is specified and the -n option is not 		 * specified, then the permissions of the resulting ACL mask 		 * entry shall be set to the union of the permissions 		 * associated with all entries which belong to the file group 		 * class in the resulting ACL 		 */
if|if
condition|(
name|acl_calc_mask
argument_list|(
operator|&
name|acl
argument_list|)
condition|)
block|{
name|warn
argument_list|(
literal|"acl_calc_mask() failed"
argument_list|)
expr_stmt|;
name|acl_free
argument_list|(
name|acl
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
else|else
block|{
comment|/* 		 * If no mask entry is specified and the -n option is 		 * specified, then the permissions of the resulting ACL 		 * mask entry shall remain unchanged ... 		 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|acl
operator|->
name|acl_cnt
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|acl
operator|->
name|acl_entry
index|[
name|i
index|]
operator|.
name|ae_tag
operator|==
name|ACL_MASK
condition|)
block|{
name|acl_free
argument_list|(
name|acl
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/* 		 * If no mask entry is specified, the -n option is specified, 		 * and no ACL mask entry exists in the ACL associated with the 		 * file, then write an error message to standard error and 		 * continue with the next file. 		 */
name|warnx
argument_list|(
literal|"warning: no mask entry"
argument_list|)
expr_stmt|;
name|acl_free
argument_list|(
name|acl
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
operator|*
name|prev_acl
operator|=
operator|*
name|acl
expr_stmt|;
name|acl_free
argument_list|(
name|acl
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

