begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)udp.h	7.4 (Berkeley) 6/28/90  */
end_comment

begin_comment
comment|/*  * Udp protocol header.  * Per RFC 768, September, 1981.  */
end_comment

begin_struct
struct|struct
name|udphdr
block|{
name|u_short
name|uh_sport
decl_stmt|;
comment|/* source port */
name|u_short
name|uh_dport
decl_stmt|;
comment|/* destination port */
name|short
name|uh_ulen
decl_stmt|;
comment|/* udp length */
name|u_short
name|uh_sum
decl_stmt|;
comment|/* udp checksum */
block|}
struct|;
end_struct

end_unit

