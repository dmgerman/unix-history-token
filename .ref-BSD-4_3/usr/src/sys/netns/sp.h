begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)sp.h	7.1 (Berkeley) 6/5/86  */
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

