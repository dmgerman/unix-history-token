begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)sp.h	7.3 (Berkeley) 6/29/88  */
end_comment

begin_comment
comment|/*  * Definitions for Xerox NS style sequenced packet protocol  */
end_comment

begin_struct
struct|struct
name|sphdr
block|{
name|u_char
name|sp_cc
decl_stmt|;
comment|/* connection control */
name|u_char
name|sp_dt
decl_stmt|;
comment|/* datastream type */
define|#
directive|define
name|SP_SP
value|0x80
comment|/* system packet */
define|#
directive|define
name|SP_SA
value|0x40
comment|/* send acknowledgement */
define|#
directive|define
name|SP_OB
value|0x20
comment|/* attention (out of band data) */
define|#
directive|define
name|SP_EM
value|0x10
comment|/* end of message */
name|u_short
name|sp_sid
decl_stmt|;
comment|/* source connection identifier */
name|u_short
name|sp_did
decl_stmt|;
comment|/* destination connection identifier */
name|u_short
name|sp_seq
decl_stmt|;
comment|/* sequence number */
name|u_short
name|sp_ack
decl_stmt|;
comment|/* acknowledge number */
name|u_short
name|sp_alo
decl_stmt|;
comment|/* allocation number */
block|}
struct|;
end_struct

end_unit

