begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * if_sr.h  *  * Copyright (C) 1997-1999 Whistle Communications Inc.  * All rights reserved.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_IF_SR_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_ISA_IF_SR_H_
end_define

begin_comment
comment|/* Node type name and type cookie */
end_comment

begin_define
define|#
directive|define
name|NG_SR_NODE_TYPE
value|"sync_sr"
end_define

begin_define
define|#
directive|define
name|NG_SR_COOKIE
value|860552148
end_define

begin_comment
comment|/* Netgraph hooks */
end_comment

begin_define
define|#
directive|define
name|NG_SR_HOOK_DEBUG
value|"debug"
end_define

begin_define
define|#
directive|define
name|NG_SR_HOOK_CONTROL
value|"control"
end_define

begin_define
define|#
directive|define
name|NG_SR_HOOK_RAW
value|"rawdata"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_ISA_IF_SR_H_ */
end_comment

end_unit

