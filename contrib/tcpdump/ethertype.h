begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994, 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: ethertype.h,v 1.6 96/07/14 18:21:49 leres Exp $ (LBL)  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Types missing from some systems */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_NS
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_NS
value|0x0600
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_SPRITE
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_SPRITE
value|0x0500
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_TRAIL
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_TRAIL
value|0x1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_MOPDL
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_MOPDL
value|0x6001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_MOPRC
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_MOPRC
value|0x6002
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_DN
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_DN
value|0x6003
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_LAT
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_LAT
value|0x6004
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_SCA
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_SCA
value|0x6007
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|ETHERTYPE_LANBRIDGE
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_LANBRIDGE
value|0x8038
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_DECDNS
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_DECDNS
value|0x803c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_DECDTS
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_DECDTS
value|0x803e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_VEXP
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_VEXP
value|0x805b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_VPROD
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_VPROD
value|0x805c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_ATALK
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_ATALK
value|0x809b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_AARP
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_AARP
value|0x80f3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_IPX
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_IPX
value|0x8137
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_PPPOE_DISC
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_PPPOE_DISC
value|0x8863
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_PPPOE_SESS
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_PPPOE_SESS
value|0x8864
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_LOOPBACK
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_LOOPBACK
value|0x9000
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

