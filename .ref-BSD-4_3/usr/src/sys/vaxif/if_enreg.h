begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)if_enreg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * Xerox experimental ethernet registers.  *  * N.B.: status register and device address are read/write,  * device address is read-only, rest are WRITE ONLY!  */
end_comment

begin_struct
struct|struct
name|endevice
block|{
name|short
name|en_owc
decl_stmt|;
comment|/* output word count (10 bits) */
name|short
name|en_oba
decl_stmt|;
comment|/* output buffer address */
name|short
name|en_ostat
decl_stmt|;
comment|/* output control and status */
name|short
name|en_odelay
decl_stmt|;
comment|/* output start delay, 25usec units  */
name|short
name|en_iwc
decl_stmt|;
comment|/* input word count */
name|short
name|en_iba
decl_stmt|;
comment|/* input buffer address */
name|short
name|en_istat
decl_stmt|;
comment|/* input csr */
name|short
name|en_addr
decl_stmt|;
comment|/* ~device address (low 8 bits) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Control and status bits.  */
end_comment

begin_define
define|#
directive|define
name|EN_IERROR
value|0x8000
end_define

begin_comment
comment|/* CRC error, buf ovflo or overrun */
end_comment

begin_define
define|#
directive|define
name|EN_OERROR
value|0x8000
end_define

begin_comment
comment|/* collision or output underrun */
end_comment

begin_define
define|#
directive|define
name|EN_OPDONE
value|0x0080
end_define

begin_comment
comment|/* previous operation completed */
end_comment

begin_define
define|#
directive|define
name|EN_IEN
value|0x0040
end_define

begin_comment
comment|/* enable interrupt when DONE */
end_comment

begin_define
define|#
directive|define
name|EN_PROMISCUOUS
value|0x0002
end_define

begin_comment
comment|/* promiscuous, input any packet */
end_comment

begin_define
define|#
directive|define
name|EN_GO
value|0x0001
end_define

begin_comment
comment|/* start op bit */
end_comment

begin_define
define|#
directive|define
name|EN_BITS
value|"\10\20ERR\10OPDONE\7IEN\2PROM\1GO"
end_define

begin_define
define|#
directive|define
name|spl_enet
parameter_list|()
value|spl5()
end_define

end_unit

