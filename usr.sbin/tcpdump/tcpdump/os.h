begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $FreeBSD$ (LBL)  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|BSD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SHA
parameter_list|(
name|ap
parameter_list|)
value|((ap)->arp_sha)
end_define

begin_define
define|#
directive|define
name|SPA
parameter_list|(
name|ap
parameter_list|)
value|((ap)->arp_spa)
end_define

begin_define
define|#
directive|define
name|THA
parameter_list|(
name|ap
parameter_list|)
value|((ap)->arp_tha)
end_define

begin_define
define|#
directive|define
name|TPA
parameter_list|(
name|ap
parameter_list|)
value|((ap)->arp_tpa)
end_define

begin_define
define|#
directive|define
name|EDST
parameter_list|(
name|ep
parameter_list|)
value|((ep)->ether_dhost)
end_define

begin_define
define|#
directive|define
name|ESRC
parameter_list|(
name|ep
parameter_list|)
value|((ep)->ether_shost)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_REVARP
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_REVARP
value|0x8035
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_ND
end_ifndef

begin_comment
comment|/* From<netinet/in.h> on a Sun somewhere. */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_ND
value|77
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|REVARP_REQUEST
end_ifndef

begin_define
define|#
directive|define
name|REVARP_REQUEST
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|REVARP_REPLY
end_ifndef

begin_define
define|#
directive|define
name|REVARP_REPLY
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* newish RIP commands */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RIPCMD_POLL
end_ifndef

begin_define
define|#
directive|define
name|RIPCMD_POLL
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RIPCMD_POLLENTRY
end_ifndef

begin_define
define|#
directive|define
name|RIPCMD_POLLENTRY
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

