begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2011 Monthadar Al Jaberi, TerraNet AB  * All rights reserved.  *  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DEV_WTAP_MEDIUM_H__
end_ifndef

begin_define
define|#
directive|define
name|__DEV_WTAP_MEDIUM_H__
end_define

begin_include
include|#
directive|include
file|"if_wtapvar.h"
end_include

begin_include
include|#
directive|include
file|"wtap_hal/handler.h"
end_include

begin_struct
struct|struct
name|packet
block|{
name|STAILQ_ENTRY
argument_list|(
argument|packet
argument_list|)
name|pf_list
expr_stmt|;
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|int
name|id
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|packet
argument_list|)
name|md_pkthead
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|wtap_medium
block|{
name|struct
name|mtx
name|md_mtx
decl_stmt|;
if|#
directive|if
literal|0
block|int				visibility[MAX_NBR_WTAP]; 	struct stailhead 		*headp; 	packet_head			pktbuf; 	STAILQ_HEAD(stailhead, packet) pktbuf; 	STAILQ_HEAD(stailhead, packet) pktbuf;
comment|/* = STAILQ_HEAD_INITIALIZER(head); */
endif|#
directive|endif
comment|/* 0 means we drop packets, 1 we queue them */
name|int
name|open
decl_stmt|;
name|md_pkthead
name|md_pktbuf
decl_stmt|;
comment|/* master queue */
name|struct
name|eventhandler
modifier|*
name|tx_handler
decl_stmt|;
name|struct
name|timehandler
modifier|*
name|bc_handler
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|init_medium
parameter_list|(
name|struct
name|wtap_medium
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|deinit_medium
parameter_list|(
name|struct
name|wtap_medium
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|medium_open
parameter_list|(
name|struct
name|wtap_medium
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|medium_close
parameter_list|(
name|struct
name|wtap_medium
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|medium_transmit
parameter_list|(
name|struct
name|wtap_medium
modifier|*
parameter_list|,
name|int
name|id
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|packet
modifier|*
name|medium_get_next_packet
parameter_list|(
name|struct
name|wtap_medium
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DEV_WTAP_MEDIUM_H__ */
end_comment

end_unit

