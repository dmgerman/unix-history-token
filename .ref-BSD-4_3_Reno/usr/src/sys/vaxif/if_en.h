begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)if_en.h	7.3 (Berkeley) 6/28/90  */
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

