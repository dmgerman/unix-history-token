begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)fhpibreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|vu_char
value|volatile u_char
end_define

begin_struct
struct|struct
name|fhpibdevice
block|{
name|u_char
name|hpib_pad0
decl_stmt|;
name|vu_char
name|hpib_cid
decl_stmt|;
name|u_char
name|hpib_pad1
decl_stmt|;
define|#
directive|define
name|hpib_ie
value|hpib_ids
name|vu_char
name|hpib_ids
decl_stmt|;
name|u_char
name|hpib_pad2
decl_stmt|;
name|vu_char
name|hpib_ctrl2
decl_stmt|;
name|u_char
name|hpib_pad3
decl_stmt|;
name|vu_char
name|hpib_latch
decl_stmt|;
name|u_char
name|hpib_pad4
index|[
literal|9
index|]
decl_stmt|;
name|vu_char
name|hpib_intr
decl_stmt|;
name|u_char
name|hpib_pad5
decl_stmt|;
name|vu_char
name|hpib_imask
decl_stmt|;
name|u_char
name|hpib_pad6
decl_stmt|;
name|vu_char
name|hpib_data
decl_stmt|;
name|u_char
name|hpib_pad7
decl_stmt|;
name|vu_char
name|hpib_stat
decl_stmt|;
name|u_char
name|hpib_pad8
decl_stmt|;
name|vu_char
name|hpib_cmd
decl_stmt|;
name|u_char
name|hpib_pad9
decl_stmt|;
name|vu_char
name|hpib_ar
decl_stmt|;
name|u_char
name|hpib_pad10
decl_stmt|;
name|vu_char
name|hpib_pmask
decl_stmt|;
name|u_char
name|hpib_pad11
decl_stmt|;
name|vu_char
name|hpib_psense
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* status bits */
end_comment

begin_define
define|#
directive|define
name|ST_READ0
value|0xC0
end_define

begin_define
define|#
directive|define
name|ST_READ1
value|0x80
end_define

begin_define
define|#
directive|define
name|ST_IENAB
value|0x80
end_define

begin_define
define|#
directive|define
name|ST_EOI
value|0x80
end_define

begin_define
define|#
directive|define
name|ST_ATN
value|0x40
end_define

begin_define
define|#
directive|define
name|ST_WRITE
value|0x00
end_define

begin_comment
comment|/* control bits */
end_comment

begin_define
define|#
directive|define
name|CT_8BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|CT_REN
value|0x20
end_define

begin_define
define|#
directive|define
name|CT_IFC
value|0x10
end_define

begin_define
define|#
directive|define
name|CT_FIFOSEL
value|0x02
end_define

begin_define
define|#
directive|define
name|CT_INITFIFO
value|0x01
end_define

begin_define
define|#
directive|define
name|IM_PABORT
value|0x40
end_define

begin_define
define|#
directive|define
name|IM_PPRESP
value|0x20
end_define

begin_define
define|#
directive|define
name|IM_ROOM
value|0x08
end_define

begin_define
define|#
directive|define
name|IM_BYTE
value|0x04
end_define

begin_define
define|#
directive|define
name|IM_IDLE
value|0x02
end_define

begin_define
define|#
directive|define
name|AR_ARONC
value|0x80
end_define

end_unit

