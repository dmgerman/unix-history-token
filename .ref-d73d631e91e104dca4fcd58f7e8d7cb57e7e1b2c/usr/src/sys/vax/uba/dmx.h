begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)dmx.h	7.1 (Berkeley) %G%  *  * Common structures and definitions  * for merged DMF and DMZ drivers.  */
end_comment

begin_comment
comment|/*  * Software status per octet  */
end_comment

begin_struct
struct|struct
name|dmx_softc
block|{
name|char
name|dmx_flags
decl_stmt|;
comment|/* flags, below */
name|char
name|dmx_type
decl_stmt|;
comment|/* hardware type as character */
name|char
name|dmx_softCAR
decl_stmt|;
comment|/* softCAR flags per octet */
name|char
name|dmx_ubanum
decl_stmt|;
comment|/* uba number */
name|short
name|dmx_unit
decl_stmt|;
comment|/* board unit number */
name|short
name|dmx_unit0
decl_stmt|;
comment|/* line number of first line */
name|struct
name|dmx_octet
modifier|*
name|dmx_octet
decl_stmt|;
comment|/* hardware registers */
name|struct
name|tty
modifier|*
name|dmx_tty
decl_stmt|;
comment|/* base of ttys for octet */
name|int
name|dmx_dmacount
index|[
literal|8
index|]
decl_stmt|;
comment|/* output dma count, per line */
block|}
struct|;
end_struct

begin_comment
comment|/*  * flags  */
end_comment

begin_define
define|#
directive|define
name|DMX_ACTIVE
value|0x01
end_define

begin_comment
comment|/* has been opened */
end_comment

end_unit

