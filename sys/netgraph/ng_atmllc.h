begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2004 Benno Rice<benno@FreeBSD.org>  * All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR  ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR  BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_ATMLLC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_ATMLLC_H_
end_define

begin_comment
comment|/* Node type name and magic cookie. */
end_comment

begin_define
define|#
directive|define
name|NG_ATMLLC_NODE_TYPE
value|"atmllc"
end_define

begin_define
define|#
directive|define
name|NGM_ATMLLC_COOKIE
value|1065246274
end_define

begin_comment
comment|/* Hook names. */
end_comment

begin_define
define|#
directive|define
name|NG_ATMLLC_HOOK_ATM
value|"atm"
end_define

begin_define
define|#
directive|define
name|NG_ATMLLC_HOOK_ETHER
value|"ether"
end_define

begin_define
define|#
directive|define
name|NG_ATMLLC_HOOK_802_4
value|"ieee8024"
end_define

begin_define
define|#
directive|define
name|NG_ATMLLC_HOOK_802_5
value|"ieee8025"
end_define

begin_define
define|#
directive|define
name|NG_ATMLLC_HOOK_802_6
value|"ieee8026"
end_define

begin_define
define|#
directive|define
name|NG_ATMLLC_HOOK_FDDI
value|"fddi"
end_define

begin_define
define|#
directive|define
name|NG_ATMLLC_HOOK_BPDU
value|"bpdu"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_ATMLLC_H_ */
end_comment

end_unit

