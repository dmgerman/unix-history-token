begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Edward Tomasz NapieraÅa<trasz@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * ALTHOUGH THIS SOFTWARE IS MADE OF WIN AND SCIENCE, IT IS PROVIDED BY THE  * AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY  * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/acl.h>
end_include

begin_comment
comment|/*  * Compatibility wrappers for applications compiled against libc from before  * NFSv4 ACLs were added.  */
end_comment

begin_function
name|int
name|__oldacl_get_perm_np
parameter_list|(
name|acl_permset_t
name|permset_d
parameter_list|,
name|oldacl_perm_t
name|perm
parameter_list|)
block|{
return|return
operator|(
name|acl_get_perm_np
argument_list|(
name|permset_d
argument_list|,
name|perm
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|__oldacl_add_perm
parameter_list|(
name|acl_permset_t
name|permset_d
parameter_list|,
name|oldacl_perm_t
name|perm
parameter_list|)
block|{
return|return
operator|(
name|acl_add_perm
argument_list|(
name|permset_d
argument_list|,
name|perm
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|__oldacl_delete_perm
parameter_list|(
name|acl_permset_t
name|permset_d
parameter_list|,
name|oldacl_perm_t
name|perm
parameter_list|)
block|{
return|return
operator|(
name|acl_delete_perm
argument_list|(
name|permset_d
argument_list|,
name|perm
argument_list|)
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|__sym_compat
argument_list|(
name|acl_get_perm_np
argument_list|,
name|__oldacl_get_perm_np
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|acl_add_perm
argument_list|,
name|__oldacl_add_perm
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|acl_delete_perm
argument_list|,
name|__oldacl_delete_perm
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

