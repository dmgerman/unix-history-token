begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2001 WIDE Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-mpls.c,v 1.2 2001/06/26 06:24:57 guy Exp $ (LBL)"
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"addrtoname.h"
end_include

begin_include
include|#
directive|include
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_comment
comment|/* must come after interface.h */
end_comment

begin_define
define|#
directive|define
name|LABEL_MASK
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|LABEL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|EXP_MASK
value|0x00000e00
end_define

begin_define
define|#
directive|define
name|EXP_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|STACK_MASK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|STACK_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|TTL_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|TTL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MPLS_LABEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& LABEL_MASK)>> LABEL_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPLS_EXP
parameter_list|(
name|x
parameter_list|)
value|(((x)& EXP_MASK)>> EXP_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPLS_STACK
parameter_list|(
name|x
parameter_list|)
value|(((x)& STACK_MASK)>> STACK_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPLS_TTL
parameter_list|(
name|x
parameter_list|)
value|(((x)& TTL_MASK)>> TTL_SHIFT)
end_define

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|mpls_labelname
index|[]
init|=
block|{
comment|/*0*/
literal|"IPv4 explicit NULL"
block|,
literal|"router alert"
block|,
literal|"IPv6 explicit NULL"
block|,
literal|"implicit NULL"
block|,
literal|"rsvd"
block|,
comment|/*5*/
literal|"rsvd"
block|,
literal|"rsvd"
block|,
literal|"rsvd"
block|,
literal|"rsvd"
block|,
literal|"rsvd"
block|,
comment|/*10*/
literal|"rsvd"
block|,
literal|"rsvd"
block|,
literal|"rsvd"
block|,
literal|"rsvd"
block|,
literal|"rsvd"
block|,
comment|/*15*/
literal|"rsvd"
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * RFC3032: MPLS label stack encoding  */
end_comment

begin_function
name|void
name|mpls_print
parameter_list|(
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
specifier|const
name|u_char
modifier|*
name|p
decl_stmt|;
name|u_int32_t
name|v
decl_stmt|;
name|p
operator|=
name|bp
expr_stmt|;
name|printf
argument_list|(
literal|"MPLS"
argument_list|)
expr_stmt|;
name|TCHECK2
argument_list|(
operator|*
name|p
argument_list|,
sizeof|sizeof
argument_list|(
name|v
argument_list|)
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|v
argument_list|,
name|p
argument_list|,
sizeof|sizeof
argument_list|(
name|v
argument_list|)
argument_list|)
expr_stmt|;
name|v
operator|=
operator|(
name|u_int32_t
operator|)
name|ntohl
argument_list|(
name|v
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" ("
argument_list|)
expr_stmt|;
comment|/*)*/
name|printf
argument_list|(
literal|"label 0x%x"
argument_list|,
name|MPLS_LABEL
argument_list|(
name|v
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|vflag
operator|&&
name|MPLS_LABEL
argument_list|(
name|v
argument_list|)
operator|<
sizeof|sizeof
argument_list|(
name|mpls_labelname
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|mpls_labelname
index|[
literal|0
index|]
argument_list|)
condition|)
name|printf
argument_list|(
literal|"(%s)"
argument_list|,
name|mpls_labelname
index|[
name|MPLS_LABEL
argument_list|(
name|v
argument_list|)
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|MPLS_EXP
argument_list|(
name|v
argument_list|)
condition|)
name|printf
argument_list|(
literal|" exp 0x%x"
argument_list|,
name|MPLS_EXP
argument_list|(
name|v
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|MPLS_STACK
argument_list|(
name|v
argument_list|)
condition|)
name|printf
argument_list|(
literal|"[S]"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" TTL %u"
argument_list|,
name|MPLS_TTL
argument_list|(
name|v
argument_list|)
argument_list|)
expr_stmt|;
comment|/*(*/
name|printf
argument_list|(
literal|")"
argument_list|)
expr_stmt|;
name|p
operator|+=
sizeof|sizeof
argument_list|(
name|v
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|MPLS_LABEL
argument_list|(
name|v
argument_list|)
condition|)
block|{
case|case
literal|0
case|:
comment|/* IPv4 explicit NULL label */
name|ip_print
argument_list|(
name|p
argument_list|,
name|length
operator|-
operator|(
name|p
operator|-
name|bp
operator|)
argument_list|)
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|INET6
case|case
literal|2
case|:
comment|/* IPv6 explicit NULL label */
name|ip6_print
argument_list|(
name|p
argument_list|,
name|length
operator|-
operator|(
name|p
operator|-
name|bp
operator|)
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
default|default:
comment|/* 		 * Since there's no indication of protocol in MPLS label 		 * encoding, we can print nothing further. 		 */
return|return;
block|}
name|trunc
label|:
name|printf
argument_list|(
literal|"[|MPLS]"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

