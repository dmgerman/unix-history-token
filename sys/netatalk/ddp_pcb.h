begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Robert N. M. Watson  * Copyright (c) 1990,1994 Regents of The University of Michigan.  * All Rights Reserved.  See COPYRIGHT.  *  * $FreeBSD$  */
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

end_unit

