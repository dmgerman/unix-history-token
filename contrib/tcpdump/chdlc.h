begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/chdlc.h,v 1.1 2000/09/18 05:11:43 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Copyright (c) 1990, 1991, 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_define
define|#
directive|define
name|CHDLC_HDRLEN
value|4
end_define

begin_define
define|#
directive|define
name|CHDLC_UNICAST
value|0x0f
end_define

begin_define
define|#
directive|define
name|CHDLC_BCAST
value|0x8f
end_define

begin_define
define|#
directive|define
name|CHDLC_TYPE_SLARP
value|0x8035
end_define

begin_define
define|#
directive|define
name|CHDLC_TYPE_CDP
value|0x2000
end_define

end_unit

