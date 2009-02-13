begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Robert N. M. Watson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Copyright (c) 1990, 1994 Regents of The University of Michigan.  * All Rights Reserved.  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright notice appears in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation, and that the name of The University  * of Michigan not be used in advertising or publicity pertaining to  * distribution of the software without specific, written prior  * permission. This software is supplied as is without expressed or  * implied warranties of any kind.  *  * This product includes software developed by the University of  * California, Berkeley and its contributors.  *  *	Research Systems Unix Group  *	The University of Michigan  *	c/o Wesley Craig  *	535 W. William Street  *	Ann Arbor, Michigan  *	+1-313-764-2278  *	netatalk@umich.edu  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATALK_DDP_PCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETATALK_DDP_PCB_H_
end_define

begin_function_decl
name|int
name|at_pcballoc
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|at_pcbconnect
parameter_list|(
name|struct
name|ddpcb
modifier|*
name|ddp
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at_pcbdetach
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|ddpcb
modifier|*
name|ddp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at_pcbdisconnect
parameter_list|(
name|struct
name|ddpcb
modifier|*
name|ddp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|at_pcbsetaddr
parameter_list|(
name|struct
name|ddpcb
modifier|*
name|ddp
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at_sockaddr
parameter_list|(
name|struct
name|ddpcb
modifier|*
name|ddp
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Lock macros for per-pcb locks. */
end_comment

begin_define
define|#
directive|define
name|DDP_LOCK_INIT
parameter_list|(
name|ddp
parameter_list|)
value|mtx_init(&(ddp)->ddp_mtx, "ddp_mtx",	\ 				    NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|DDP_LOCK_DESTROY
parameter_list|(
name|ddp
parameter_list|)
value|mtx_destroy(&(ddp)->ddp_mtx)
end_define

begin_define
define|#
directive|define
name|DDP_LOCK
parameter_list|(
name|ddp
parameter_list|)
value|mtx_lock(&(ddp)->ddp_mtx)
end_define

begin_define
define|#
directive|define
name|DDP_UNLOCK
parameter_list|(
name|ddp
parameter_list|)
value|mtx_unlock(&(ddp)->ddp_mtx)
end_define

begin_define
define|#
directive|define
name|DDP_LOCK_ASSERT
parameter_list|(
name|ddp
parameter_list|)
value|mtx_assert(&(ddp)->ddp_mtx, MA_OWNED)
end_define

begin_comment
comment|/* Lock macros for global pcb list lock. */
end_comment

begin_define
define|#
directive|define
name|DDP_LIST_LOCK_INIT
parameter_list|()
value|mtx_init(&ddp_list_mtx, "ddp_list_mtx",	\ 				    NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|DDP_LIST_LOCK_DESTROY
parameter_list|()
value|mtx_destroy(&ddp_list_mtx)
end_define

begin_define
define|#
directive|define
name|DDP_LIST_XLOCK
parameter_list|()
value|mtx_lock(&ddp_list_mtx)
end_define

begin_define
define|#
directive|define
name|DDP_LIST_XUNLOCK
parameter_list|()
value|mtx_unlock(&ddp_list_mtx)
end_define

begin_define
define|#
directive|define
name|DDP_LIST_XLOCK_ASSERT
parameter_list|()
value|mtx_assert(&ddp_list_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|DDP_LIST_SLOCK
parameter_list|()
value|mtx_lock(&ddp_list_mtx)
end_define

begin_define
define|#
directive|define
name|DDP_LIST_SUNLOCK
parameter_list|()
value|mtx_unlock(&ddp_list_mtx)
end_define

begin_define
define|#
directive|define
name|DDP_LIST_SLOCK_ASSERT
parameter_list|()
value|mtx_assert(&ddp_list_mtx, MA_OWNED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETATALK_DDP_PCB_H_ */
end_comment

end_unit

