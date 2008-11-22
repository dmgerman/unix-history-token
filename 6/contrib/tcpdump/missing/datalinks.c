begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994, 1995, 1996, 1997, 1998  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the Computer Systems  *	Engineering Group at Lawrence Berkeley Laboratory.  * 4. Neither the name of the University nor of the Laboratory may be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
name|_U_
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/missing/datalinks.c,v 1.3 2003/11/16 09:36:47 guy Exp $ (LBL)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<tcpdump-stdinc.h>
end_include

begin_include
include|#
directive|include
file|<pcap.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"pcap-missing.h"
end_include

begin_comment
comment|/*  * Stub versions for platforms that don't support them.  */
end_comment

begin_function
name|int
name|pcap_list_datalinks
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|,
name|int
modifier|*
modifier|*
name|dlt_buffer
parameter_list|)
block|{
comment|/* 	 * This platform doesn't support changing the DLT for an 	 * interface.  Return a list of DLTs containing only the 	 * DLT this device supports. 	 */
operator|*
name|dlt_buffer
operator|=
operator|(
name|int
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
operator|*
name|dlt_buffer
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|dlt_buffer
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
operator|*
operator|*
name|dlt_buffer
operator|=
name|pcap_datalink
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

end_unit

