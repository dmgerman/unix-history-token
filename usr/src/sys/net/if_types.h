begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)if_types.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* interface types for benefit of parsing media address headers */
end_comment

begin_define
define|#
directive|define
name|IFT_LOOP
value|0x1
end_define

begin_comment
comment|/* loopback */
end_comment

begin_define
define|#
directive|define
name|IFT_XETHER
value|0x2
end_define

begin_comment
comment|/* old 3MBaud experimental ethernet */
end_comment

begin_define
define|#
directive|define
name|IFT_ETHER
value|0x3
end_define

begin_comment
comment|/* 802.3 */
end_comment

begin_define
define|#
directive|define
name|IFT_IMP
value|0x4
end_define

begin_comment
comment|/* Arpanet imp interface */
end_comment

begin_define
define|#
directive|define
name|IFT_P8010
value|0x5
end_define

begin_comment
comment|/* Pronet 10/Pronet 80 */
end_comment

begin_define
define|#
directive|define
name|IFT_EON
value|0x6
end_define

begin_comment
comment|/* ISO over IP */
end_comment

begin_define
define|#
directive|define
name|IFT_HY
value|0x7
end_define

begin_comment
comment|/* Hyperchannel */
end_comment

end_unit

