begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_tee.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_tee.h,v 1.2 1999/01/20 00:22:14 archie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_TEE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_TEE_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_TEE_NODE_TYPE
value|"tee"
end_define

begin_define
define|#
directive|define
name|NGM_TEE_COOKIE
value|916107047
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_TEE_HOOK_RIGHT
value|"right"
end_define

begin_define
define|#
directive|define
name|NG_TEE_HOOK_LEFT
value|"left"
end_define

begin_define
define|#
directive|define
name|NG_TEE_HOOK_RIGHT2LEFT
value|"right2left"
end_define

begin_define
define|#
directive|define
name|NG_TEE_HOOK_LEFT2RIGHT
value|"left2right"
end_define

begin_comment
comment|/* Statistics structure for one hook */
end_comment

begin_struct
struct|struct
name|ng_tee_hookstat
block|{
name|u_int64_t
name|inOctets
decl_stmt|;
name|u_int64_t
name|inFrames
decl_stmt|;
name|u_int64_t
name|outOctets
decl_stmt|;
name|u_int64_t
name|outFrames
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_TEE_HOOKSTAT_INFO
value|{				\ 	{							\ 	  { "inOctets",&ng_parse_uint64_type	},	\ 	  { "inFrames",&ng_parse_uint64_type	},	\ 	  { "outOctets",&ng_parse_uint64_type	},	\ 	  { "outFrames",&ng_parse_uint64_type	},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Statistics structure returned by NGM_TEE_GET_STATS */
end_comment

begin_struct
struct|struct
name|ng_tee_stats
block|{
name|struct
name|ng_tee_hookstat
name|right
decl_stmt|;
name|struct
name|ng_tee_hookstat
name|left
decl_stmt|;
name|struct
name|ng_tee_hookstat
name|right2left
decl_stmt|;
name|struct
name|ng_tee_hookstat
name|left2right
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_TEE_STATS_INFO
parameter_list|(
name|hstype
parameter_list|)
value|{			\ 	{							\ 	  { "right",		(hstype)		},	\ 	  { "left",		(hstype)		},	\ 	  { "right2left",	(hstype)		},	\ 	  { "left2right",	(hstype)		},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_TEE_GET_STATS
init|=
literal|1
block|,
comment|/* get stats */
name|NGM_TEE_CLR_STATS
block|,
comment|/* clear stats */
name|NGM_TEE_GETCLR_STATS
block|,
comment|/* atomically get and clear stats */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_TEE_H_ */
end_comment

end_unit

