begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)x25_var.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Device-independent x25 driver data.  */
end_comment

begin_struct
struct|struct
name|x25com
block|{
name|struct
name|ifnet
name|xc_if
decl_stmt|;
comment|/* network-visible interface */
comment|/*	int	(*xc_if.if_start)()	/* connect, confirm procedure */
name|u_char
name|xc_addrlen
decl_stmt|;
comment|/* length of X.121 address */
name|u_char
name|xc_addr
index|[
literal|16
index|]
decl_stmt|;
comment|/* X.121 address */
name|u_short
name|xc_flags
decl_stmt|;
comment|/* X.25 specific flags */
name|u_short
name|xc_nchan
decl_stmt|;
comment|/* number of logical channels */
name|u_short
name|xc_nactive
decl_stmt|;
comment|/* number of live logical channels */
name|u_short
name|xc_npvc
decl_stmt|;
comment|/* # of permanent virt. circuits */
name|u_short
name|xc_pvcx
decl_stmt|;
comment|/* index of first pcv */
name|u_short
name|xc_svcx
decl_stmt|;
comment|/* index of first svc */
name|u_short
name|xc_dg_idletimo
decl_stmt|;
comment|/* timeout to close idle dg channel */
name|u_short
name|xc_rslvtimo
decl_stmt|;
comment|/* if name translation fails, rid */
name|struct
name|x25lcb
modifier|*
modifier|*
name|xc_lcbvec
decl_stmt|;
comment|/* where to dispatch data */
name|int
function_decl|(
modifier|*
name|xc_disconnect
function_decl|)
parameter_list|()
function_decl|;
comment|/* to delete idle dg circuits */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XCF_HSL3
value|0x1
end_define

begin_comment
comment|/* Hardware support for level 3 */
end_comment

begin_define
define|#
directive|define
name|XCF_HSL2
value|0x2
end_define

begin_comment
comment|/* Hardware support for level 2 */
end_comment

begin_comment
comment|/*  * Local Connection Block.  */
end_comment

begin_struct
struct|struct
name|x25lcb
block|{
struct|struct
name|xq
block|{
name|int
function_decl|(
modifier|*
name|xq_put
function_decl|)
parameter_list|()
function_decl|;
comment|/* How to process data */
name|struct
name|mbuf
modifier|*
name|xq_data
decl_stmt|;
comment|/* Queued data */
name|int
name|xq_space
decl_stmt|;
comment|/* For accounting */
name|int
name|xq_flags
decl_stmt|;
name|int
function_decl|(
modifier|*
name|xq_unblock
function_decl|)
parameter_list|()
function_decl|;
comment|/* called& cleared when unblocking */
name|caddr_t
name|xq_proto
decl_stmt|;
comment|/* for other service entries */
name|caddr_t
name|xq_next
decl_stmt|;
comment|/* next q, or route, or pcb */
block|}
name|xl_downq
struct|,
name|xl_upq
struct|;
comment|/*	(*xl_downq.xq_next->xq_put)()	/* LAPB put when using pk_output() */
name|int
name|xl_flags
decl_stmt|;
comment|/* valid, c-o versus dg */
name|int
name|xl_timer
decl_stmt|;
comment|/* figure out what to close */
name|int
name|xl_state
decl_stmt|;
comment|/* connecting, connected, resolving */
name|int
name|xl_index
decl_stmt|;
comment|/* which entry we are in device table */
name|struct
name|x25com
modifier|*
name|xl_xc
decl_stmt|;
comment|/* back pointer to device */
comment|/* 	 * x25pkb (packet-level control block) would follow immediately 	 * for devices only supplying LAPB or less. 	 */
block|}
struct|;
end_struct

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|XL_VALID
value|0x1
end_define

begin_comment
comment|/* Circuit is live, etc. */
end_comment

begin_define
define|#
directive|define
name|XL_DGRAM
value|0x2
end_define

begin_comment
comment|/* not connection oriented, can close */
end_comment

begin_define
define|#
directive|define
name|XL_RTHELD
value|0x4
end_define

begin_comment
comment|/* this lcb references rtentry */
end_comment

begin_define
define|#
directive|define
name|XQ_UP
value|0x1
end_define

begin_comment
comment|/* I am an up queue */
end_comment

begin_define
define|#
directive|define
name|XQ_DOWN
value|0x2
end_define

begin_comment
comment|/* I am a down queue */
end_comment

begin_comment
comment|/* states for LCB */
end_comment

begin_define
define|#
directive|define
name|XLS_NEWBORN
value|0x0
end_define

begin_define
define|#
directive|define
name|XLS_CONNECTED
value|0x1
end_define

begin_define
define|#
directive|define
name|XLS_CONNECTING
value|0x2
end_define

begin_define
define|#
directive|define
name|XLS_RESOLVING
value|0x3
end_define

begin_define
define|#
directive|define
name|XLS_DISCONNECTING
value|0x4
end_define

begin_define
define|#
directive|define
name|XLS_FREE
value|0x5
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|int
name|x25_ifinput
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

