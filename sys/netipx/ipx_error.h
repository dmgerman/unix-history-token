begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, Mike Mitchell  * Copyright (c) 1984, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ipx_error.h  *  * $Id: ipx_error.h,v 1.7 1997/02/22 09:41:53 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPX_IPX_ERROR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPX_IPX_ERROR_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IPXERRORMSGS
end_ifdef

begin_comment
comment|/*  * IPX error messages  */
end_comment

begin_struct
struct|struct
name|ipx_errp
block|{
name|u_short
name|ipx_err_num
decl_stmt|;
comment|/* Error Number */
name|u_short
name|ipx_err_param
decl_stmt|;
comment|/* Error Parameter */
name|struct
name|ipx
name|ipx_err_ipx
decl_stmt|;
comment|/* Initial segment of offending 						   packet */
name|u_char
name|ipx_err_lev2
index|[
literal|12
index|]
decl_stmt|;
comment|/* at least this much higher 						   level protocol */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipx_epipx
block|{
name|struct
name|ipx
name|ipx_ep_ipx
decl_stmt|;
name|struct
name|ipx_errp
name|ipx_ep_errp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IPX_ERR_UNSPEC
value|0
end_define

begin_comment
comment|/* Unspecified Error detected at dest. */
end_comment

begin_define
define|#
directive|define
name|IPX_ERR_BADSUM
value|1
end_define

begin_comment
comment|/* Bad Checksum detected at dest */
end_comment

begin_define
define|#
directive|define
name|IPX_ERR_NOSOCK
value|2
end_define

begin_comment
comment|/* Specified socket does not exist at dest*/
end_comment

begin_define
define|#
directive|define
name|IPX_ERR_FULLUP
value|3
end_define

begin_comment
comment|/* Dest. refuses packet due to resource lim.*/
end_comment

begin_define
define|#
directive|define
name|IPX_ERR_UNSPEC_T
value|0x200
end_define

begin_comment
comment|/* Unspec. Error occured before reaching dest*/
end_comment

begin_define
define|#
directive|define
name|IPX_ERR_BADSUM_T
value|0x201
end_define

begin_comment
comment|/* Bad Checksum detected in transit */
end_comment

begin_define
define|#
directive|define
name|IPX_ERR_UNREACH_HOST
value|0x202
end_define

begin_comment
comment|/* Dest cannot be reached from here*/
end_comment

begin_define
define|#
directive|define
name|IPX_ERR_TOO_OLD
value|0x203
end_define

begin_comment
comment|/* Packet x'd 15 routers without delivery*/
end_comment

begin_define
define|#
directive|define
name|IPX_ERR_TOO_BIG
value|0x204
end_define

begin_comment
comment|/* Packet too large to be forwarded through 				   some intermediate gateway.  The error 				   parameter field contains the max packet 				   size that can be accommodated */
end_comment

begin_define
define|#
directive|define
name|IPX_ERR_MAX
value|20
end_define

begin_comment
comment|/*  * Variables related to this implementation  * of the network systems error message protocol.  */
end_comment

begin_struct
struct|struct
name|ipx_errstat
block|{
comment|/* statistics related to ipx_err packets generated */
name|int
name|ipx_es_error
decl_stmt|;
comment|/* # of calls to ipx_error */
name|int
name|ipx_es_oldshort
decl_stmt|;
comment|/* no error 'cuz old ip too short */
name|int
name|ipx_es_oldipx_err
decl_stmt|;
comment|/* no error 'cuz old was ipx_err */
name|int
name|ipx_es_outhist
index|[
name|IPX_ERR_MAX
index|]
decl_stmt|;
comment|/* statistics related to input messages processed */
name|int
name|ipx_es_badcode
decl_stmt|;
comment|/* ipx_err_code out of range */
name|int
name|ipx_es_tooshort
decl_stmt|;
comment|/* packet< IPX_MINLEN */
name|int
name|ipx_es_checksum
decl_stmt|;
comment|/* bad checksum */
name|int
name|ipx_es_badlen
decl_stmt|;
comment|/* calculated bound mismatch */
name|int
name|ipx_es_reflect
decl_stmt|;
comment|/* number of responses */
name|int
name|ipx_es_inhist
index|[
name|IPX_ERR_MAX
index|]
decl_stmt|;
name|u_short
name|ipx_es_codes
index|[
name|IPX_ERR_MAX
index|]
decl_stmt|;
comment|/* which error code for outhist 					   since we might not know all */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|IPXERRORMSGS
end_ifdef

begin_decl_stmt
specifier|extern
name|u_char
name|ipxctlerrmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipx_errstat
name|ipx_errstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipx_echo
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipx_err_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipx_err_x
name|__P
argument_list|(
operator|(
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipx_error
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
name|om
operator|,
name|int
name|type
operator|,
name|int
name|param
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|ipx_printhost
name|__P
argument_list|(
operator|(
expr|struct
name|ipx_addr
operator|*
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETIPX_IPX_ERROR_H_ */
end_comment

end_unit

