begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)idp.h	7.4 (Berkeley) 6/28/90  */
end_comment

begin_comment
comment|/*  * Definitions for NS(tm) Internet Datagram Protocol  */
end_comment

begin_struct
struct|struct
name|idp
block|{
name|u_short
name|idp_sum
decl_stmt|;
comment|/* Checksum */
name|u_short
name|idp_len
decl_stmt|;
comment|/* Length, in bytes, including header */
name|u_char
name|idp_tc
decl_stmt|;
comment|/* Transport Crontrol (i.e. hop count) */
name|u_char
name|idp_pt
decl_stmt|;
comment|/* Packet Type (i.e. level 2 protocol) */
name|struct
name|ns_addr
name|idp_dna
decl_stmt|;
comment|/* Destination Network Address */
name|struct
name|ns_addr
name|idp_sna
decl_stmt|;
comment|/* Source Network Address */
block|}
struct|;
end_struct

end_unit

