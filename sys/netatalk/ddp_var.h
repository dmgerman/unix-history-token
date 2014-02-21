begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1994 Regents of The University of Michigan.  * All Rights Reserved.  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright notice appears in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation, and that the name of The University  * of Michigan not be used in advertising or publicity pertaining to  * distribution of the software without specific, written prior  * permission. This software is supplied as is without expressed or  * implied warranties of any kind.  *  * This product includes software developed by the University of  * California, Berkeley and its contributors.  *  *	Research Systems Unix Group  *	The University of Michigan  *	c/o Wesley Craig  *	535 W. William Street  *	Ann Arbor, Michigan  *	+1-313-764-2278  *	netatalk@umich.edu  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATALK_DDP_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETATALK_DDP_VAR_H_
end_define

begin_struct
struct|struct
name|ddpcb
block|{
name|struct
name|sockaddr_at
name|ddp_fsat
decl_stmt|,
name|ddp_lsat
decl_stmt|;
name|struct
name|route
name|ddp_route
decl_stmt|;
name|struct
name|socket
modifier|*
name|ddp_socket
decl_stmt|;
name|struct
name|ddpcb
modifier|*
name|ddp_prev
decl_stmt|,
modifier|*
name|ddp_next
decl_stmt|;
name|struct
name|ddpcb
modifier|*
name|ddp_pprev
decl_stmt|,
modifier|*
name|ddp_pnext
decl_stmt|;
name|struct
name|mtx
name|ddp_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sotoddpcb
parameter_list|(
name|so
parameter_list|)
value|((struct ddpcb *)(so)->so_pcb)
end_define

begin_struct
struct|struct
name|ddpstat
block|{
name|long
name|ddps_short
decl_stmt|;
comment|/* short header packets received */
name|long
name|ddps_long
decl_stmt|;
comment|/* long header packets received */
name|long
name|ddps_nosum
decl_stmt|;
comment|/* no checksum */
name|long
name|ddps_badsum
decl_stmt|;
comment|/* bad checksum */
name|long
name|ddps_tooshort
decl_stmt|;
comment|/* packet too short */
name|long
name|ddps_toosmall
decl_stmt|;
comment|/* not enough data */
name|long
name|ddps_forward
decl_stmt|;
comment|/* packets forwarded */
name|long
name|ddps_encap
decl_stmt|;
comment|/* packets encapsulated */
name|long
name|ddps_cantforward
decl_stmt|;
comment|/* packets rcvd for unreachable dest */
name|long
name|ddps_nosockspace
decl_stmt|;
comment|/* no space in sockbuf for packet */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|ddp_cksum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ddpcb
modifier|*
name|ddpcb_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|ddp_usrreqs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|ddp_list_mtx
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETATALK_DDP_VAR_H_ */
end_comment

end_unit

