begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)idp.h	7.4 (Berkeley) %G%  */
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

