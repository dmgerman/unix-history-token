begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994, 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: /tcpdump/master/libpcap/ethertype.h,v 1.11 2000/10/22 04:15:55 guy Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Ethernet types.  *  * We wrap the declarations with #ifdef, so that if a file includes  *<netinet/if_ether.h>, which may declare some of these, we don't  * get a bunch of complaints from the C compiler about redefinitions  * of these values.  *  * We declare all of them here so that no file has to include  *<netinet/if_ether.h> if all it needs are ETHERTYPE_ values.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_PUP
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_PUP
value|0x0200
end_define

begin_comment
comment|/* PUP protocol */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_IP
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_IP
value|0x0800
end_define

begin_comment
comment|/* IP protocol */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_ARP
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_ARP
value|0x0806
end_define

begin_comment
comment|/* Addr. resolution protocol */
end_comment

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

begin_comment
comment|/* reverse Addr. resolution protocol */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
name|ETHERTYPE_IPV6
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_IPV6
value|0x86dd
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_8021Q
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_8021Q
value|0x8100
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

