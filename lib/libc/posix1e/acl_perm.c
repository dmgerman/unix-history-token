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
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/*  * acl_add_perm() adds the permission contained in perm to the  * permission set permset_d  */
end_comment

begin_function
name|int
name|acl_add_perm
parameter_list|(
name|acl_permset_t
name|permset_d
parameter_list|,
name|acl_perm_t
name|perm
parameter_list|)
block|{
if|if
condition|(
operator|!
name|permset_d
operator|||
operator|(
name|perm
operator|&
operator|!
operator|(
name|ACL_PERM_BITS
operator|)
operator|)
condition|)
block|{
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
operator|*
name|permset_d
operator||=
name|perm
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * acl_clear_perm() clears all permisions from the permission  * set permset_d  */
end_comment

begin_function
name|int
name|acl_clear_perm
parameter_list|(
name|acl_permset_t
name|permset_d
parameter_list|)
block|{
if|if
condition|(
operator|!
name|permset_d
condition|)
block|{
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
operator|*
name|permset_d
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * acl_delete_perm() removes the permission in perm from the  * permission set permset_d  */
end_comment

begin_function
name|int
name|acl_delete_perm
parameter_list|(
name|acl_permset_t
name|permset_d
parameter_list|,
name|acl_perm_t
name|perm
parameter_list|)
block|{
if|if
condition|(
operator|!
name|permset_d
condition|)
block|{
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
operator|*
name|permset_d
operator|&=
operator|~
operator|(
name|perm
operator|&
name|ACL_PERM_BITS
operator|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

