begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Defines for Cronyx-Tau adapter driver.  *  * Copyright (C) 1999 Cronyx Engineering.  * Author: Kurakin Roman,<rik@cronyx.ru>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organisations a permission to use,  * modify and redistribute this software in source and binary forms,  * as long as this message is kept with the software, all derivative  * works or modified versions.  *  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NETGRAPH
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_CX_NETGRAPH_H_
end_ifndef

begin_define
define|#
directive|define
name|_CX_NETGRAPH_H_
end_define

begin_define
define|#
directive|define
name|NG_CX_NODE_TYPE
value|"cx"
end_define

begin_define
define|#
directive|define
name|NGM_CX_COOKIE
value|942763600
end_define

begin_define
define|#
directive|define
name|NG_CX_HOOK_RAW
value|"rawdata"
end_define

begin_define
define|#
directive|define
name|NG_CX_HOOK_DEBUG
value|"debug"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CX_NETGRAPH_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH */
end_comment

end_unit

