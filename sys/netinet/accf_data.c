begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Alfred Perlstein<alfred@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|ACCEPT_FILTER_MOD
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysproto.h>
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_comment
comment|/* accept filter that holds a socket until data arrives */
end_comment

begin_function_decl
specifier|static
name|void
name|sohasdata
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|waitflag
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|struct
name|accept_filter
name|accf_data_filter
init|=
block|{
literal|"dataready"
block|,
name|sohasdata
block|,
name|NULL
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|moduledata_t
name|accf_data_mod
init|=
block|{
literal|"accf_data"
block|,
name|accept_filt_generic_mod_event
block|,
operator|&
name|accf_data_filter
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DECLARE_MODULE
argument_list|(
name|accf_data
argument_list|,
name|accf_data_mod
argument_list|,
name|SI_SUB_DRIVERS
argument_list|,
name|SI_ORDER_MIDDLE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|void
name|sohasdata
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|waitflag
parameter_list|)
block|{
if|if
condition|(
operator|!
name|soreadable
argument_list|(
name|so
argument_list|)
condition|)
block|{
return|return;
block|}
name|so
operator|->
name|so_upcall
operator|=
name|NULL
expr_stmt|;
name|so
operator|->
name|so_rcv
operator|.
name|sb_flags
operator|&=
operator|~
name|SB_UPCALL
expr_stmt|;
name|soisconnected
argument_list|(
name|so
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

