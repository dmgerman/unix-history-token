begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)if_en.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Structure of a Ethernet header.  */
end_comment

begin_struct
struct|struct
name|en_header
block|{
name|u_char
name|en_shost
decl_stmt|;
name|u_char
name|en_dhost
decl_stmt|;
name|u_short
name|en_type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ENTYPE_PUP
value|0x0200
end_define

begin_comment
comment|/* PUP protocol */
end_comment

begin_define
define|#
directive|define
name|ENTYPE_IP
value|0x0201
end_define

begin_comment
comment|/* IP protocol */
end_comment

begin_comment
comment|/*  * The ENTYPE_NTRAILER packet types starting at  * ENTYPE_TRAIL have (type-ENTYPE_TRAIL)*512 bytes  * of data followed by an Ethernet type (as given above)  * and then the (variable-length) header.  */
end_comment

begin_define
define|#
directive|define
name|ENTYPE_TRAIL
value|0x1000
end_define

begin_comment
comment|/* Trailer type */
end_comment

begin_define
define|#
directive|define
name|ENTYPE_NTRAILER
value|16
end_define

begin_define
define|#
directive|define
name|EN_BROADCAST
value|0
end_define

begin_comment
comment|/* Hardware broadcast address */
end_comment

end_unit

