begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)table.h	5.1 (Berkeley) 6/4/85 (routed/table.h)  *  *	@(#)table.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Routing table management daemon.  */
end_comment

begin_comment
comment|/*  * Routing table structure; differs a bit from kernel tables.  *  * Note: the union below must agree in the first 4 members  * so the ioctl's will work.  */
end_comment

begin_struct
struct|struct
name|rthash
block|{
name|struct
name|rt_entry
modifier|*
name|rt_forw
decl_stmt|;
name|struct
name|rt_entry
modifier|*
name|rt_back
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|RTM_ADD
end_ifdef

begin_define
define|#
directive|define
name|rtentry
value|ortentry
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|rt_entry
block|{
name|struct
name|rt_entry
modifier|*
name|rt_forw
decl_stmt|;
name|struct
name|rt_entry
modifier|*
name|rt_back
decl_stmt|;
union|union
block|{
name|struct
name|rtentry
name|rtu_rt
decl_stmt|;
struct|struct
block|{
name|u_long
name|rtu_hash
decl_stmt|;
name|struct
name|sockaddr
name|rtu_dst
decl_stmt|;
name|struct
name|sockaddr
name|rtu_router
decl_stmt|;
name|short
name|rtu_flags
decl_stmt|;
name|short
name|rtu_state
decl_stmt|;
name|int
name|rtu_timer
decl_stmt|;
name|int
name|rtu_metric
decl_stmt|;
name|struct
name|interface
modifier|*
name|rtu_ifp
decl_stmt|;
block|}
name|rtu_entry
struct|;
block|}
name|rt_rtu
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rt_rt
value|rt_rtu.rtu_rt
end_define

begin_comment
comment|/* pass to ioctl */
end_comment

begin_define
define|#
directive|define
name|rt_hash
value|rt_rtu.rtu_entry.rtu_hash
end_define

begin_comment
comment|/* for net or host */
end_comment

begin_define
define|#
directive|define
name|rt_dst
value|rt_rtu.rtu_entry.rtu_dst
end_define

begin_comment
comment|/* match value */
end_comment

begin_define
define|#
directive|define
name|rt_router
value|rt_rtu.rtu_entry.rtu_router
end_define

begin_comment
comment|/* who to forward to */
end_comment

begin_define
define|#
directive|define
name|rt_flags
value|rt_rtu.rtu_entry.rtu_flags
end_define

begin_comment
comment|/* kernel flags */
end_comment

begin_define
define|#
directive|define
name|rt_timer
value|rt_rtu.rtu_entry.rtu_timer
end_define

begin_comment
comment|/* for invalidation */
end_comment

begin_define
define|#
directive|define
name|rt_state
value|rt_rtu.rtu_entry.rtu_state
end_define

begin_comment
comment|/* see below */
end_comment

begin_define
define|#
directive|define
name|rt_metric
value|rt_rtu.rtu_entry.rtu_metric
end_define

begin_comment
comment|/* cost of route */
end_comment

begin_define
define|#
directive|define
name|rt_ifp
value|rt_rtu.rtu_entry.rtu_ifp
end_define

begin_comment
comment|/* interface to take */
end_comment

begin_define
define|#
directive|define
name|ROUTEHASHSIZ
value|32
end_define

begin_comment
comment|/* must be a power of 2 */
end_comment

begin_define
define|#
directive|define
name|ROUTEHASHMASK
value|(ROUTEHASHSIZ - 1)
end_define

begin_comment
comment|/*  * "State" of routing table entry.  */
end_comment

begin_define
define|#
directive|define
name|RTS_CHANGED
value|0x1
end_define

begin_comment
comment|/* route has been altered recently */
end_comment

begin_define
define|#
directive|define
name|RTS_PASSIVE
value|IFF_PASSIVE
end_define

begin_comment
comment|/* don't time out route */
end_comment

begin_define
define|#
directive|define
name|RTS_INTERFACE
value|IFF_INTERFACE
end_define

begin_comment
comment|/* route is for network interface */
end_comment

begin_define
define|#
directive|define
name|RTS_REMOTE
value|IFF_REMOTE
end_define

begin_comment
comment|/* route is for ``remote'' entity */
end_comment

begin_decl_stmt
name|struct
name|rthash
name|nethash
index|[
name|ROUTEHASHSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rthash
name|hosthash
index|[
name|ROUTEHASHSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|rt_entry
modifier|*
name|rtlookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|rt_entry
modifier|*
name|rtfind
parameter_list|()
function_decl|;
end_function_decl

end_unit

