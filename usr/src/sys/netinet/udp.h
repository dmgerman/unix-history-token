begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)udp.h	7.2 (Berkeley) %G%  */
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

