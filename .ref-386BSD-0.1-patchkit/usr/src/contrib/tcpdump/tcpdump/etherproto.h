begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988-1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: etherproto.h,v 1.7 90/10/10 15:04:04 mccanne Exp $ (LBL)  */
end_comment

begin_comment
comment|/* Map between Ethernet protocol types and names */
end_comment

begin_comment
comment|/* Add other Ethernet packet types here */
end_comment

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

begin_comment
comment|/* XXX */
end_comment

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

begin_struct
struct|struct
name|eproto
block|{
name|char
modifier|*
name|s
decl_stmt|;
name|u_short
name|p
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|eproto
name|eproto_db
index|[]
decl_stmt|;
end_decl_stmt

end_unit

