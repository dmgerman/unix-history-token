begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_bpf.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANBPF, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_bpf.h,v 1.3 1999/12/03 20:30:23 archie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_BPF_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_BPF_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_BPF_NODE_TYPE
value|"bpf"
end_define

begin_define
define|#
directive|define
name|NGM_BPF_COOKIE
value|944100792
end_define

begin_comment
comment|/* Program structure for one hook */
end_comment

begin_struct
struct|struct
name|ng_bpf_hookprog
block|{
name|char
name|thisHook
index|[
name|NG_HOOKLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name of hook */
name|char
name|ifMatch
index|[
name|NG_HOOKLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* match dest hook */
name|char
name|ifNotMatch
index|[
name|NG_HOOKLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* !match dest hook */
name|int32_t
name|bpf_prog_len
decl_stmt|;
comment|/* #isns in program */
name|struct
name|bpf_insn
name|bpf_prog
index|[
literal|0
index|]
decl_stmt|;
comment|/* bpf program */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NG_BPF_HOOKPROG_SIZE
parameter_list|(
name|numInsn
parameter_list|)
define|\
value|(sizeof(struct ng_bpf_hookprog) + (numInsn) * sizeof(struct bpf_insn))
end_define

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_BPF_HOOKPROG_TYPE_INFO
parameter_list|(
name|bptype
parameter_list|)
value|{		\ 	{							\ 	  { "thisHook",&ng_parse_hookbuf_type	},	\ 	  { "ifMatch",&ng_parse_hookbuf_type	},	\ 	  { "ifNotMatch",&ng_parse_hookbuf_type	},	\ 	  { "bpf_prog_len",&ng_parse_int32_type	},	\ 	  { "bpf_prog",		(bptype)		},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Statistics structure for one hook */
end_comment

begin_struct
struct|struct
name|ng_bpf_hookstat
block|{
name|u_int64_t
name|recvFrames
decl_stmt|;
name|u_int64_t
name|recvOctets
decl_stmt|;
name|u_int64_t
name|recvMatchFrames
decl_stmt|;
name|u_int64_t
name|recvMatchOctets
decl_stmt|;
name|u_int64_t
name|xmitFrames
decl_stmt|;
name|u_int64_t
name|xmitOctets
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
name|NG_BPF_HOOKSTAT_TYPE_INFO
value|{			\ 	{							\ 	  { "recvFrames",&ng_parse_uint64_type	},	\ 	  { "recvOctets",&ng_parse_uint64_type	},	\ 	  { "recvMatchFrames",&ng_parse_uint64_type	},	\ 	  { "recvMatchOctets",&ng_parse_uint64_type	},	\ 	  { "xmitFrames",&ng_parse_uint64_type	},	\ 	  { "xmitOctets",&ng_parse_uint64_type	},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_BPF_SET_PROGRAM
init|=
literal|1
block|,
comment|/* supply a struct ng_bpf_hookprog */
name|NGM_BPF_GET_PROGRAM
block|,
comment|/* returns a struct ng_bpf_hookprog */
name|NGM_BPF_GET_STATS
block|,
comment|/* supply name as char[NG_HOOKLEN+1] */
name|NGM_BPF_CLR_STATS
block|,
comment|/* supply name as char[NG_HOOKLEN+1] */
name|NGM_BPF_GETCLR_STATS
block|,
comment|/* supply name as char[NG_HOOKLEN+1] */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_BPF_H_ */
end_comment

end_unit

