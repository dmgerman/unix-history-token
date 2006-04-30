begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996  *	Juniper Networks, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution.  The name of Juniper Networks may not  * be used to endorse or promote products derived from this software  * without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  * @(#) $Header: /tcpdump/master/libpcap/nlpid.h,v 1.2 2002/12/06 00:01:34 hannes Exp $ (Juniper)  */
end_comment

begin_comment
comment|/* Types missing from some systems */
end_comment

begin_comment
comment|/*  * Network layer prototocol identifiers  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISO8473_CLNP
end_ifndef

begin_define
define|#
directive|define
name|ISO8473_CLNP
value|0x81
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISO9542_ESIS
end_ifndef

begin_define
define|#
directive|define
name|ISO9542_ESIS
value|0x82
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISO9542X25_ESIS
end_ifndef

begin_define
define|#
directive|define
name|ISO9542X25_ESIS
value|0x8a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISO10589_ISIS
end_ifndef

begin_define
define|#
directive|define
name|ISO10589_ISIS
value|0x83
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * this does not really belong in the nlpid.h file  * however we need it for generating nice  * IS-IS related BPF filters  */
end_comment

begin_define
define|#
directive|define
name|ISIS_L1_LAN_IIH
value|15
end_define

begin_define
define|#
directive|define
name|ISIS_L2_LAN_IIH
value|16
end_define

begin_define
define|#
directive|define
name|ISIS_PTP_IIH
value|17
end_define

begin_define
define|#
directive|define
name|ISIS_L1_LSP
value|18
end_define

begin_define
define|#
directive|define
name|ISIS_L2_LSP
value|20
end_define

begin_define
define|#
directive|define
name|ISIS_L1_CSNP
value|24
end_define

begin_define
define|#
directive|define
name|ISIS_L2_CSNP
value|25
end_define

begin_define
define|#
directive|define
name|ISIS_L1_PSNP
value|26
end_define

begin_define
define|#
directive|define
name|ISIS_L2_PSNP
value|27
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ISO8878A_CONS
end_ifndef

begin_define
define|#
directive|define
name|ISO8878A_CONS
value|0x84
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISO10747_IDRP
end_ifndef

begin_define
define|#
directive|define
name|ISO10747_IDRP
value|0x85
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

