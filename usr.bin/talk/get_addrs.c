begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)get_addrs.c	8.1 (Berkeley) 6/6/93";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"talk.h"
end_include

begin_include
include|#
directive|include
file|"talk_ctl.h"
end_include

begin_function
name|void
name|get_addrs
parameter_list|(
name|my_machine_name
parameter_list|,
name|his_machine_name
parameter_list|)
name|char
modifier|*
name|my_machine_name
decl_stmt|,
decl|*
name|his_machine_name
decl_stmt|;
end_function

begin_block
block|{
name|struct
name|hostent
modifier|*
name|hp
decl_stmt|;
name|struct
name|servent
modifier|*
name|sp
decl_stmt|;
name|msg
operator|.
name|pid
operator|=
name|htonl
argument_list|(
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
name|hp
operator|=
name|gethostbyname
argument_list|(
name|his_machine_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|hp
operator|==
name|NULL
condition|)
name|errx
argument_list|(
literal|1
argument_list|,
literal|"%s: %s"
argument_list|,
name|his_machine_name
argument_list|,
name|hstrerror
argument_list|(
name|h_errno
argument_list|)
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
name|hp
operator|->
name|h_addr
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|his_machine_addr
argument_list|,
name|hp
operator|->
name|h_length
argument_list|)
expr_stmt|;
if|if
condition|(
name|get_iface
argument_list|(
operator|&
name|his_machine_addr
argument_list|,
operator|&
name|my_machine_addr
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"failed to find my interface address"
argument_list|)
expr_stmt|;
comment|/* find the server's port */
name|sp
operator|=
name|getservbyname
argument_list|(
literal|"ntalk"
argument_list|,
literal|"udp"
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|==
literal|0
condition|)
name|errx
argument_list|(
literal|1
argument_list|,
literal|"ntalk/udp: service is not registered"
argument_list|)
expr_stmt|;
name|daemon_port
operator|=
name|sp
operator|->
name|s_port
expr_stmt|;
block|}
end_block

end_unit

