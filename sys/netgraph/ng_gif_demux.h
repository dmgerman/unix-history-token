begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_gif_demux.h  */
end_comment

begin_comment
comment|/*-  * Copyright 2001 The Aerospace Corporation.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions, and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of The Aerospace Corporation may not be used to endorse or  *    promote products derived from this software.  *  * THIS SOFTWARE IS PROVIDED BY THE AEROSPACE CORPORATION ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AEROSPACE CORPORATION BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_GIF_DEMUX_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_GIF_DEMUX_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_GIF_DEMUX_NODE_TYPE
value|"gif_demux"
end_define

begin_define
define|#
directive|define
name|NGM_GIF_DEMUX_COOKIE
value|995567329
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_GIF_DEMUX_HOOK_GIF
value|"gif"
end_define

begin_define
define|#
directive|define
name|NG_GIF_DEMUX_HOOK_INET
value|"inet"
end_define

begin_define
define|#
directive|define
name|NG_GIF_DEMUX_HOOK_INET6
value|"inet6"
end_define

begin_define
define|#
directive|define
name|NG_GIF_DEMUX_HOOK_ATALK
value|"atalk"
end_define

begin_define
define|#
directive|define
name|NG_GIF_DEMUX_HOOK_IPX
value|"ipx"
end_define

begin_define
define|#
directive|define
name|NG_GIF_DEMUX_HOOK_ATM
value|"atm"
end_define

begin_define
define|#
directive|define
name|NG_GIF_DEMUX_HOOK_NATM
value|"natm"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_GIF_DEMUX_H_ */
end_comment

end_unit

