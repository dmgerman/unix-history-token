begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)icmp_var.h	7.5 (Berkeley) 6/28/90  *	$Id: icmp_var.h,v 1.4 1993/11/18 00:08:11 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_ICMP_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_ICMP_VAR_H_
value|1
end_define

begin_comment
comment|/*  * Variables related to this implementation  * of the internet control message protocol.  */
end_comment

begin_struct
struct|struct
name|icmpstat
block|{
comment|/* statistics related to icmp packets generated */
name|int
name|icps_error
decl_stmt|;
comment|/* # of calls to icmp_error */
name|int
name|icps_oldshort
decl_stmt|;
comment|/* no error 'cuz old ip too short */
name|int
name|icps_oldicmp
decl_stmt|;
comment|/* no error 'cuz old was icmp */
name|int
name|icps_oldmcast
decl_stmt|;
comment|/* no error 'cuz old was multicast */
name|int
name|icps_oldbadaddr
decl_stmt|;
comment|/* no error 'cuz old had bad address */
name|int
name|icps_outhist
index|[
name|ICMP_MAXTYPE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* statistics related to input messages processed */
name|int
name|icps_badcode
decl_stmt|;
comment|/* icmp_code out of range */
name|int
name|icps_tooshort
decl_stmt|;
comment|/* packet< ICMP_MINLEN */
name|int
name|icps_checksum
decl_stmt|;
comment|/* bad checksum */
name|int
name|icps_badlen
decl_stmt|;
comment|/* calculated bound mismatch */
name|int
name|icps_reflect
decl_stmt|;
comment|/* number of responses */
name|int
name|icps_inhist
index|[
name|ICMP_MAXTYPE
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|icmpstat
name|icmpstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|icmpprintfs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipbroadcastecho
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipmaskagent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in
name|icmpmask
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_ICMP_VAR_H_ */
end_comment

end_unit

