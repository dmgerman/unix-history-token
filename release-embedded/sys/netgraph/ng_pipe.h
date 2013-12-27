begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004-2008 University of Zagreb  * Copyright (c) 2007-2008 FreeBSD Foundation  *  * This software was developed by the University of Zagreb and the  * FreeBSD Foundation under sponsorship by the Stichting NLnet and the  * FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_PIPE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_PIPE_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_PIPE_NODE_TYPE
value|"pipe"
end_define

begin_define
define|#
directive|define
name|NGM_PIPE_COOKIE
value|200708191
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_PIPE_HOOK_UPPER
value|"upper"
end_define

begin_define
define|#
directive|define
name|NG_PIPE_HOOK_LOWER
value|"lower"
end_define

begin_define
define|#
directive|define
name|MAX_FSIZE
value|16384
end_define

begin_comment
comment|/* Largest supported frame size, in bytes, for BER */
end_comment

begin_define
define|#
directive|define
name|MAX_OHSIZE
value|256
end_define

begin_comment
comment|/* Largest supported dummy-framing size, in bytes */
end_comment

begin_comment
comment|/* Statistics structure for one hook */
end_comment

begin_struct
struct|struct
name|ng_pipe_hookstat
block|{
name|u_int64_t
name|fwd_octets
decl_stmt|;
name|u_int64_t
name|fwd_frames
decl_stmt|;
name|u_int64_t
name|in_disc_octets
decl_stmt|;
name|u_int64_t
name|in_disc_frames
decl_stmt|;
name|u_int64_t
name|out_disc_octets
decl_stmt|;
name|u_int64_t
name|out_disc_frames
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
name|NG_PIPE_HOOKSTAT_INFO
value|{					\ 	{ "FwdOctets",&ng_parse_uint64_type	},		\ 	{ "FwdFrames",&ng_parse_uint64_type	},		\ 	{ "queueDropOctets",&ng_parse_uint64_type	},		\ 	{ "queueDropFrames",&ng_parse_uint64_type	},		\ 	{ "delayDropOctets",&ng_parse_uint64_type	},		\ 	{ "delayDropFrames",&ng_parse_uint64_type	},		\ 	{ NULL },							\ }
end_define

begin_comment
comment|/* Statistics structure returned by NGM_PIPE_GET_STATS */
end_comment

begin_struct
struct|struct
name|ng_pipe_stats
block|{
name|struct
name|ng_pipe_hookstat
name|downstream
decl_stmt|;
name|struct
name|ng_pipe_hookstat
name|upstream
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
name|NG_PIPE_STATS_INFO
parameter_list|(
name|hstype
parameter_list|)
value|{				\ 	{ "downstream",		(hstype) },				\ 	{ "upstream",		(hstype) },				\ 	{ NULL },							\ }
end_define

begin_comment
comment|/* Runtime structure for one hook */
end_comment

begin_struct
struct|struct
name|ng_pipe_hookrun
block|{
name|u_int32_t
name|fifo_queues
decl_stmt|;
name|u_int32_t
name|qin_octets
decl_stmt|;
name|u_int32_t
name|qin_frames
decl_stmt|;
name|u_int32_t
name|qout_octets
decl_stmt|;
name|u_int32_t
name|qout_frames
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
name|NG_PIPE_HOOKRUN_INFO
value|{					\ 	{ "queues",&ng_parse_uint32_type	},		\ 	{ "queuedOctets",&ng_parse_uint32_type	},		\ 	{ "queuedFrames",&ng_parse_uint32_type	},		\ 	{ "delayedOctets",&ng_parse_uint32_type	},		\ 	{ "delayedFrames",&ng_parse_uint32_type	},		\ 	{ NULL },							\ }
end_define

begin_comment
comment|/* Runtime structure returned by NGM_PIPE_GET_RUN */
end_comment

begin_struct
struct|struct
name|ng_pipe_run
block|{
name|struct
name|ng_pipe_hookrun
name|downstream
decl_stmt|;
name|struct
name|ng_pipe_hookrun
name|upstream
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
name|NG_PIPE_RUN_INFO
parameter_list|(
name|hstype
parameter_list|)
value|{				\ 	{ "downstream",		(hstype) },				\ 	{ "upstream",		(hstype) },				\ 	{ NULL },							\ }
end_define

begin_comment
comment|/* Config structure for one hook */
end_comment

begin_struct
struct|struct
name|ng_pipe_hookcfg
block|{
name|u_int64_t
name|bandwidth
decl_stmt|;
name|u_int64_t
name|ber
decl_stmt|;
name|u_int32_t
name|qin_size_limit
decl_stmt|;
name|u_int32_t
name|qout_size_limit
decl_stmt|;
name|u_int32_t
name|duplicate
decl_stmt|;
name|u_int32_t
name|fifo
decl_stmt|;
name|u_int32_t
name|drr
decl_stmt|;
name|u_int32_t
name|wfq
decl_stmt|;
name|u_int32_t
name|droptail
decl_stmt|;
name|u_int32_t
name|drophead
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
name|NG_PIPE_HOOKCFG_INFO
value|{					\ 	{ "bandwidth",&ng_parse_uint64_type	},		\ 	{ "BER",&ng_parse_uint64_type	},		\ 	{ "queuelen",&ng_parse_uint32_type	},		\ 	{ "delaylen",&ng_parse_uint32_type	},		\ 	{ "duplicate",&ng_parse_uint32_type	},		\ 	{ "fifo",&ng_parse_uint32_type	},		\ 	{ "drr",&ng_parse_uint32_type	},		\ 	{ "wfq",&ng_parse_uint32_type	},		\ 	{ "droptail",&ng_parse_uint32_type	},		\ 	{ "drophead",&ng_parse_uint32_type	},		\ 	{ NULL },							\ }
end_define

begin_comment
comment|/* Config structure returned by NGM_PIPE_GET_CFG */
end_comment

begin_struct
struct|struct
name|ng_pipe_cfg
block|{
name|u_int64_t
name|bandwidth
decl_stmt|;
name|u_int64_t
name|delay
decl_stmt|;
name|u_int32_t
name|header_offset
decl_stmt|;
name|u_int32_t
name|overhead
decl_stmt|;
name|struct
name|ng_pipe_hookcfg
name|downstream
decl_stmt|;
name|struct
name|ng_pipe_hookcfg
name|upstream
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
name|NG_PIPE_CFG_INFO
parameter_list|(
name|hstype
parameter_list|)
value|{				\ 	{ "bandwidth",&ng_parse_uint64_type	},		\ 	{ "delay",&ng_parse_uint64_type	},		\ 	{ "header_offset",&ng_parse_uint32_type	},		\ 	{ "overhead",&ng_parse_uint32_type	},		\ 	{ "downstream",		(hstype)		},		\ 	{ "upstream",		(hstype)		},		\ 	{ NULL },							\ }
end_define

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_PIPE_GET_STATS
init|=
literal|1
block|,
comment|/* get stats */
name|NGM_PIPE_CLR_STATS
block|,
comment|/* clear stats */
name|NGM_PIPE_GETCLR_STATS
block|,
comment|/* atomically get and clear stats */
name|NGM_PIPE_GET_RUN
block|,
comment|/* get current runtime status */
name|NGM_PIPE_GET_CFG
block|,
comment|/* get configurable parameters */
name|NGM_PIPE_SET_CFG
block|,
comment|/* set configurable parameters */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_PIPE_H_ */
end_comment

end_unit

