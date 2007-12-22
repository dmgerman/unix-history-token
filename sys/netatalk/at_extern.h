begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990,1994 Regents of The University of Michigan.  * All Rights Reserved.  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright notice appears in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation, and that the name of The University  * of Michigan not be used in advertising or publicity pertaining to  * distribution of the software without specific, written prior  * permission. This software is supplied as is without expressed or  * implied warranties of any kind.  *  * This product includes software developed by the University of  * California, Berkeley and its contributors.  *  *	Research Systems Unix Group  *	The University of Michigan  *	c/o Wesley Craig  *	535 W. William Street  *	Ann Arbor, Michigan  *	+1-313-764-2278  *	netatalk@umich.edu  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATALK_AT_EXTERN_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETATALK_AT_EXTERN_H_
end_define

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|aarptab_mtx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AARPTAB_LOCK
parameter_list|()
value|mtx_lock(&aarptab_mtx)
end_define

begin_define
define|#
directive|define
name|AARPTAB_UNLOCK
parameter_list|()
value|mtx_unlock(&aarptab_mtx)
end_define

begin_define
define|#
directive|define
name|AARPTAB_LOCK_ASSERT
parameter_list|()
value|mtx_assert(&aarptab_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|AARPTAB_UNLOCK_ASSERT
parameter_list|()
value|mtx_assert(&aarptab_mtx, MA_NOTOWNED)
end_define

begin_struct_decl
struct_decl|struct
name|at_ifaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|route
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_at
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|aarpintr
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aarpprobe
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aarpresolve
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockaddr_at
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aarp_clean
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at1intr
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at2intr
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|at_broadcast
parameter_list|(
name|struct
name|sockaddr_at
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|at_cksum
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|skip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|at_control
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|at_ifaddr
modifier|*
name|at_ifawithnet
parameter_list|(
name|struct
name|sockaddr_at
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ddp_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ddp_output
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ddp_route
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|route
modifier|*
name|ro
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ddpcb
modifier|*
name|ddp_search
parameter_list|(
name|struct
name|sockaddr_at
modifier|*
parameter_list|,
name|struct
name|sockaddr_at
modifier|*
parameter_list|,
name|struct
name|at_ifaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETATALK_AT_EXTERN_H_ */
end_comment

end_unit

