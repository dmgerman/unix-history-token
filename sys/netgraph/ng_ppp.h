begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_ppp.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@whistle.com>  *  * $FreeBSD$  * $Whistle: ng_ppp.h,v 1.8 1999/01/25 02:40:02 archie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_PPP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_PPP_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_NODE_TYPE
value|"ppp"
end_define

begin_define
define|#
directive|define
name|NGM_PPP_COOKIE
value|860635544
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_DOWNLINK
value|"downlink"
end_define

begin_comment
comment|/* downstream hook */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_BYPASS
value|"bypass"
end_define

begin_comment
comment|/* any unhooked protocol */
end_comment

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_PPP_SET_PROTOCOMP
init|=
literal|1
block|,
comment|/* takes an integer 0 or 1 */
name|NGM_PPP_GET_STATS
block|,
comment|/* returns struct ng_ppp_stat */
name|NGM_PPP_CLR_STATS
block|,
comment|/* clear stats */
block|}
enum|;
end_enum

begin_comment
comment|/* Statistics struct */
end_comment

begin_struct
struct|struct
name|ng_ppp_stat
block|{
name|u_int32_t
name|xmitFrames
decl_stmt|;
comment|/* xmit frames on "downstream" */
name|u_int32_t
name|xmitOctets
decl_stmt|;
comment|/* xmit octets on "downstream" */
name|u_int32_t
name|recvFrames
decl_stmt|;
comment|/* recv frames on "downstream" */
name|u_int32_t
name|recvOctets
decl_stmt|;
comment|/* recv octets on "downstream" */
name|u_int32_t
name|badProto
decl_stmt|;
comment|/* frames with invalid protocol */
name|u_int32_t
name|unknownProto
decl_stmt|;
comment|/* frames sent to "unhooked" */
block|}
struct|;
end_struct

begin_comment
comment|/*  * We recognize these hook names for some various PPP protocols. But we  * always recognize the hook name "0xNNNN" for any protocol, including these.  * So these are really just alias hook names.  */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_LCP
value|"lcp"
end_define

begin_comment
comment|/* 0xc021 */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_IPCP
value|"ipcp"
end_define

begin_comment
comment|/* 0x8021 */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_ATCP
value|"atcp"
end_define

begin_comment
comment|/* 0x8029 */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_CCP
value|"ccp"
end_define

begin_comment
comment|/* 0x80fd */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_ECP
value|"ecp"
end_define

begin_comment
comment|/* 0x8053 */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_IP
value|"ip"
end_define

begin_comment
comment|/* 0x0021 */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_VJCOMP
value|"vjcomp"
end_define

begin_comment
comment|/* 0x002d */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_VJUNCOMP
value|"vjuncomp"
end_define

begin_comment
comment|/* 0x002f */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_MP
value|"mp"
end_define

begin_comment
comment|/* 0x003d */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_COMPD
value|"compd"
end_define

begin_comment
comment|/* 0x00fd */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_CRYPTD
value|"cryptd"
end_define

begin_comment
comment|/* 0x0053 */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_PAP
value|"pap"
end_define

begin_comment
comment|/* 0xc023 */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_CHAP
value|"chap"
end_define

begin_comment
comment|/* 0xc223 */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_LQR
value|"lqr"
end_define

begin_comment
comment|/* 0xc025 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_PPP_H_ */
end_comment

end_unit

