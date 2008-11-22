begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Defines for Cronyx Tau32-PCI adapter driver.  *  * Copyright (C) 2004 Cronyx Engineering.  * Copyright (C) 2004 Kurakin Roman,<rik@FreeBSD.org>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organisations a permission to use,  * modify and redistribute this software in source and binary forms,  * as long as this message is kept with the software, all derivative  * works or modified versions.  *  * $Cronyx: ng_ce.h,v 1.2 2005/04/23 20:11:57 rik Exp $  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NETGRAPH
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_CE_NETGRAPH_H_
end_ifndef

begin_define
define|#
directive|define
name|_CE_NETGRAPH_H_
end_define

begin_define
define|#
directive|define
name|NG_CE_NODE_TYPE
value|"ce"
end_define

begin_define
define|#
directive|define
name|NGM_CE_COOKIE
value|1083172653
end_define

begin_define
define|#
directive|define
name|NG_CE_HOOK_RAW
value|"rawdata"
end_define

begin_define
define|#
directive|define
name|NG_CE_HOOK_DEBUG
value|"debug"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CE_NETGRAPH_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH */
end_comment

end_unit

