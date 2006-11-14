begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_sppp.h Netgraph to Sppp module.  */
end_comment

begin_comment
comment|/*-  * Copyright (C) 2002-2004 Cronyx Engineering.  * Copyright (C) 2002-2004 Roman Kurakin<rik@cronyx.ru>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organisations a permission to use,  * modify and redistribute this software in source and binary forms,  * as long as this message is kept with the software, all derivative  * works or modified versions.  *  * $FreeBSD$  * Cronyx Id: ng_sppp.h,v 1.1.2.6 2004/03/01 15:17:21 rik Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_SPPP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_SPPP_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_SPPP_NODE_TYPE
value|"sppp"
end_define

begin_define
define|#
directive|define
name|NGM_SPPP_COOKIE
value|1040804655
end_define

begin_comment
comment|/* Interface base name */
end_comment

begin_define
define|#
directive|define
name|NG_SPPP_IFACE_NAME
value|"sppp"
end_define

begin_comment
comment|/* My hook names */
end_comment

begin_define
define|#
directive|define
name|NG_SPPP_HOOK_DOWNSTREAM
value|"downstream"
end_define

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_SPPP_GET_IFNAME
init|=
literal|1
block|,
comment|/* returns struct ng_sppp_ifname */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_SPPP_H_ */
end_comment

end_unit

