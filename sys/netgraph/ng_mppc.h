begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_mppc.h  *  * Copyright (c) 1996-2000 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@freebsd.org>  *  * $Whistle: ng_mppc.h,v 1.3 2000/02/12 01:17:22 archie Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_MPPC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_MPPC_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_MPPC_NODE_TYPE
value|"mppc"
end_define

begin_define
define|#
directive|define
name|NGM_MPPC_COOKIE
value|942886745
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_MPPC_HOOK_COMP
value|"comp"
end_define

begin_comment
comment|/* compression hook */
end_comment

begin_define
define|#
directive|define
name|NG_MPPC_HOOK_DECOMP
value|"decomp"
end_define

begin_comment
comment|/* decompression hook */
end_comment

begin_comment
comment|/* Length of MPPE key */
end_comment

begin_define
define|#
directive|define
name|MPPE_KEY_LEN
value|16
end_define

begin_comment
comment|/* Max expansion due to MPPC header and compression algorithm */
end_comment

begin_define
define|#
directive|define
name|MPPC_MAX_BLOWUP
parameter_list|(
name|n
parameter_list|)
value|((n) * 9 / 8 + 26)
end_define

begin_comment
comment|/* MPPC/MPPE PPP negotiation bits */
end_comment

begin_define
define|#
directive|define
name|MPPC_BIT
value|0x00000001
end_define

begin_comment
comment|/* mppc compression bits */
end_comment

begin_define
define|#
directive|define
name|MPPE_40
value|0x00000020
end_define

begin_comment
comment|/* use 40 bit key */
end_comment

begin_define
define|#
directive|define
name|MPPE_128
value|0x00000040
end_define

begin_comment
comment|/* use 128 bit key */
end_comment

begin_define
define|#
directive|define
name|MPPE_BITS
value|0x00000060
end_define

begin_comment
comment|/* mppe encryption bits */
end_comment

begin_define
define|#
directive|define
name|MPPE_STATELESS
value|0x01000000
end_define

begin_comment
comment|/* use stateless mode */
end_comment

begin_define
define|#
directive|define
name|MPPC_VALID_BITS
value|0x01000061
end_define

begin_comment
comment|/* possibly valid bits */
end_comment

begin_comment
comment|/* Config struct (per-direction) */
end_comment

begin_struct
struct|struct
name|ng_mppc_config
block|{
name|u_char
name|enable
decl_stmt|;
comment|/* enable */
name|u_int32_t
name|bits
decl_stmt|;
comment|/* config bits */
name|u_char
name|startkey
index|[
name|MPPE_KEY_LEN
index|]
decl_stmt|;
comment|/* start key */
block|}
struct|;
end_struct

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_MPPC_CONFIG_COMP
init|=
literal|1
block|,
name|NGM_MPPC_CONFIG_DECOMP
block|,
name|NGM_MPPC_RESETREQ
block|,
comment|/* sent either way! */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_MPPC_H_ */
end_comment

end_unit

