begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: /tcpdump/master/libpcap/llc.h,v 1.1 2001/01/14 21:26:53 guy Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * 802.2 LLC SAP values.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_NULL
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_NULL
value|0x00
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_GLOBAL
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_GLOBAL
value|0xff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_8021B
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_8021B_I
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_8021B
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_8021B_G
value|0x03
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_IP
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_IP
value|0x06
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_PROWAYNM
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_PROWAYNM
value|0x0e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_8021D
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_8021D
value|0x42
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_RS511
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_RS511
value|0x4e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_ISO8208
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_ISO8208
value|0x7e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_PROWAY
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_PROWAY
value|0x8e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_SNAP
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_SNAP
value|0xaa
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_ISONS
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_ISONS
value|0xfe
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLCSAP_IPX
end_ifndef

begin_define
define|#
directive|define
name|LLCSAP_IPX
value|0xe0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

