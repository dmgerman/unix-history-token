begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ipxcp.h - IPX Control Protocol definitions.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Options.  */
end_comment

begin_define
define|#
directive|define
name|IPX_NETWORK_NUMBER
value|1
end_define

begin_comment
comment|/* IPX Network Number */
end_comment

begin_define
define|#
directive|define
name|IPX_NODE_NUMBER
value|2
end_define

begin_define
define|#
directive|define
name|IPX_COMPRESSION_PROTOCOL
value|3
end_define

begin_define
define|#
directive|define
name|IPX_ROUTER_PROTOCOL
value|4
end_define

begin_define
define|#
directive|define
name|IPX_ROUTER_NAME
value|5
end_define

begin_define
define|#
directive|define
name|IPX_COMPLETE
value|6
end_define

begin_comment
comment|/* Values for the router protocol */
end_comment

begin_define
define|#
directive|define
name|IPX_NONE
value|0
end_define

begin_define
define|#
directive|define
name|RIP_SAP
value|2
end_define

begin_define
define|#
directive|define
name|NLSP
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|ipxcp_options
block|{
name|int
name|neg_node
range|:
literal|1
decl_stmt|;
comment|/* Negotiate IPX node number? */
name|int
name|req_node
range|:
literal|1
decl_stmt|;
comment|/* Ask peer to send IPX node number? */
name|int
name|neg_nn
range|:
literal|1
decl_stmt|;
comment|/* Negotiate IPX network number? */
name|int
name|req_nn
range|:
literal|1
decl_stmt|;
comment|/* Ask peer to send IPX network number */
name|int
name|neg_name
range|:
literal|1
decl_stmt|;
comment|/* Negotiate IPX router name */
name|int
name|neg_complete
range|:
literal|1
decl_stmt|;
comment|/* Negotiate completion */
name|int
name|neg_router
range|:
literal|1
decl_stmt|;
comment|/* Negotiate IPX router number */
name|int
name|accept_local
range|:
literal|1
decl_stmt|;
comment|/* accept peer's value for ournode */
name|int
name|accept_remote
range|:
literal|1
decl_stmt|;
comment|/* accept peer's value for hisnode */
name|int
name|accept_network
range|:
literal|1
decl_stmt|;
comment|/* accept network number */
name|int
name|tried_nlsp
range|:
literal|1
decl_stmt|;
comment|/* I have suggested NLSP already */
name|int
name|tried_rip
range|:
literal|1
decl_stmt|;
comment|/* I have suggested RIP/SAP already */
name|u_int32_t
name|his_network
decl_stmt|;
comment|/* base network number */
name|u_int32_t
name|our_network
decl_stmt|;
comment|/* our value for network number */
name|u_int32_t
name|network
decl_stmt|;
comment|/* the final network number */
name|u_char
name|his_node
index|[
literal|6
index|]
decl_stmt|;
comment|/* peer's node number */
name|u_char
name|our_node
index|[
literal|6
index|]
decl_stmt|;
comment|/* our node number */
name|u_char
name|name
index|[
literal|48
index|]
decl_stmt|;
comment|/* name of the router */
name|int
name|router
decl_stmt|;
comment|/* routing protocol */
block|}
name|ipxcp_options
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|fsm
name|ipxcp_fsm
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipxcp_options
name|ipxcp_wantoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipxcp_options
name|ipxcp_gotoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipxcp_options
name|ipxcp_allowoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipxcp_options
name|ipxcp_hisoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|protent
name|ipxcp_protent
decl_stmt|;
end_decl_stmt

end_unit

