begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: print-mobile.c,v 1.2 1998/09/30 08:57:01 hwr Exp $ */
end_comment

begin_comment
comment|/*  * (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Heiko W.Rupp<hwr@pilhuhn.de>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

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
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-mobile.c,v 1.7 2001/08/20 17:53:54 fenner Exp $"
decl_stmt|;
end_decl_stmt

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
file|<sys/uio.h>
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
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"addrtoname.h"
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
name|MOBILE_SIZE
value|(8)
end_define

begin_struct
struct|struct
name|mobile_ip
block|{
name|u_int16_t
name|proto
decl_stmt|;
name|u_int16_t
name|hcheck
decl_stmt|;
name|u_int32_t
name|odst
decl_stmt|;
name|u_int32_t
name|osrc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OSRC_PRES
value|0x0080
end_define

begin_comment
comment|/* old source is present */
end_comment

begin_comment
comment|/*  * Deencapsulate and print a mobile-tunneled IP datagram  */
end_comment

begin_function
name|void
name|mobile_print
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
name|cp
init|=
name|bp
operator|+
literal|8
decl_stmt|;
specifier|const
name|struct
name|mobile_ip
modifier|*
name|mob
decl_stmt|;
name|u_short
name|proto
decl_stmt|,
name|crc
decl_stmt|;
name|u_char
name|osp
init|=
literal|0
decl_stmt|;
comment|/* old source address present */
name|mob
operator|=
operator|(
specifier|const
expr|struct
name|mobile_ip
operator|*
operator|)
name|bp
expr_stmt|;
if|if
condition|(
name|length
operator|<
name|MOBILE_SIZE
condition|)
block|{
name|fputs
argument_list|(
literal|"[|mobile]"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
return|return;
block|}
name|fputs
argument_list|(
literal|"mobile: "
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|proto
operator|=
name|EXTRACT_16BITS
argument_list|(
operator|&
name|mob
operator|->
name|proto
argument_list|)
expr_stmt|;
name|crc
operator|=
name|EXTRACT_16BITS
argument_list|(
operator|&
name|mob
operator|->
name|hcheck
argument_list|)
expr_stmt|;
if|if
condition|(
name|proto
operator|&
name|OSRC_PRES
condition|)
block|{
name|osp
operator|=
literal|1
expr_stmt|;
name|cp
operator|+=
literal|4
expr_stmt|;
block|}
if|if
condition|(
name|osp
condition|)
block|{
name|fputs
argument_list|(
literal|"[S] "
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
if|if
condition|(
name|vflag
condition|)
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s "
argument_list|,
name|ipaddr_string
argument_list|(
operator|&
name|mob
operator|->
name|osrc
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fputs
argument_list|(
literal|"[] "
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|vflag
condition|)
block|{
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"> %s "
argument_list|,
name|ipaddr_string
argument_list|(
operator|&
name|mob
operator|->
name|odst
argument_list|)
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"(oproto=%d)"
argument_list|,
name|proto
operator|>>
literal|8
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|in_cksum
argument_list|(
operator|(
name|u_short
operator|*
operator|)
name|mob
argument_list|,
name|osp
condition|?
literal|12
else|:
literal|8
argument_list|,
literal|0
argument_list|)
operator|!=
literal|0
condition|)
block|{
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" (bad checksum %d)"
argument_list|,
name|crc
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
end_function

end_unit

