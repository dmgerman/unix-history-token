begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)kern_xxx.c	8.2 (Berkeley) 11/14/93  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_struct
struct|struct
name|reboot_args
block|{
name|int
name|opt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|reboot
argument_list|(
argument|p
argument_list|,
argument|uap
argument_list|,
argument|retval
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|reboot_args
modifier|*
name|uap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|retval
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|error
decl_stmt|;
if|if
condition|(
name|error
operator|=
name|suser
argument_list|(
name|p
operator|->
name|p_ucred
argument_list|,
operator|&
name|p
operator|->
name|p_acflag
argument_list|)
condition|)
return|return
operator|(
name|error
operator|)
return|;
name|boot
argument_list|(
name|uap
operator|->
name|opt
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|defined
argument_list|(
name|COMPAT_43
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_SUNOS
argument_list|)
end_if

begin_struct
struct|struct
name|gethostname_args
block|{
name|char
modifier|*
name|hostname
decl_stmt|;
name|u_int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|ogethostname
argument_list|(
argument|p
argument_list|,
argument|uap
argument_list|,
argument|retval
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|gethostname_args
modifier|*
name|uap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|retval
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|name
decl_stmt|;
name|name
operator|=
name|KERN_HOSTNAME
expr_stmt|;
return|return
operator|(
name|kern_sysctl
argument_list|(
operator|&
name|name
argument_list|,
literal|1
argument_list|,
name|uap
operator|->
name|hostname
argument_list|,
operator|&
name|uap
operator|->
name|len
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_block

begin_struct
struct|struct
name|sethostname_args
block|{
name|char
modifier|*
name|hostname
decl_stmt|;
name|u_int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|osethostname
argument_list|(
argument|p
argument_list|,
argument|uap
argument_list|,
argument|retval
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|struct
name|sethostname_args
modifier|*
name|uap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|retval
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|name
decl_stmt|;
name|int
name|error
decl_stmt|;
if|if
condition|(
name|error
operator|=
name|suser
argument_list|(
name|p
operator|->
name|p_ucred
argument_list|,
operator|&
name|p
operator|->
name|p_acflag
argument_list|)
condition|)
return|return
operator|(
name|error
operator|)
return|;
name|name
operator|=
name|KERN_HOSTNAME
expr_stmt|;
return|return
operator|(
name|kern_sysctl
argument_list|(
operator|&
name|name
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|uap
operator|->
name|hostname
argument_list|,
name|uap
operator|->
name|len
argument_list|)
operator|)
return|;
block|}
end_block

begin_decl_stmt
specifier|extern
name|long
name|hostid
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|gethostid_args
block|{
name|int
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|ogethostid
argument_list|(
argument|p
argument_list|,
argument|uap
argument_list|,
argument|retval
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|gethostid_args
modifier|*
name|uap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|retval
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
operator|(
name|long
operator|*
operator|)
name|retval
operator|=
name|hostid
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMPAT_43 || COMPAT_SUNOS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_43
end_ifdef

begin_struct
struct|struct
name|sethostid_args
block|{
name|long
name|hostid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|osethostid
argument_list|(
argument|p
argument_list|,
argument|uap
argument_list|,
argument|retval
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sethostid_args
modifier|*
name|uap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|retval
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|error
decl_stmt|;
if|if
condition|(
name|error
operator|=
name|suser
argument_list|(
name|p
operator|->
name|p_ucred
argument_list|,
operator|&
name|p
operator|->
name|p_acflag
argument_list|)
condition|)
return|return
operator|(
name|error
operator|)
return|;
name|hostid
operator|=
name|uap
operator|->
name|hostid
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|oquota
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMPAT_43 */
end_comment

end_unit

