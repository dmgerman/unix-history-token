begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)vxreg.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Vioc hardware interface structure.  */
end_comment

begin_struct
struct|struct
name|vxdevice
block|{
name|char
name|v_vioc
decl_stmt|;
comment|/*  0 type of interrupt + vioc busy flag */
name|char
name|v_hdwre
decl_stmt|;
comment|/*  1 trap, reset, or hard interrupt */
name|char
name|v_vcbsy
decl_stmt|;
comment|/*  2 command busy (set by host) */
name|char
name|v_vcid
decl_stmt|;
comment|/*  3 command identifier */
name|short
name|v_vcp
index|[
literal|2
index|]
decl_stmt|;
comment|/*  4 command pointer (sent by host) */
name|short
name|v_unused
decl_stmt|;
comment|/*  8 unused */
name|short
name|v_rspoff
decl_stmt|;
comment|/*  a offset into vblock for response buf */
name|char
name|v_ustat
decl_stmt|;
comment|/*  c status */
name|char
name|v_uqual
decl_stmt|;
comment|/*  d interrupt qualifier */
name|char
name|v_usdata
index|[
literal|0x3E
index|]
decl_stmt|;
comment|/*  e unsolicited interrupt data */
name|short
name|v_maxxmt
decl_stmt|;
comment|/* 4C max xmit block size */
name|short
name|v_maxsilo
decl_stmt|;
comment|/* 4E max silo size */
name|char
name|v_ident
decl_stmt|;
comment|/* 50 identifies type of vioc */
name|char
name|v_fault
decl_stmt|;
comment|/* 51 denotes fault or ready after reset */
name|short
name|v_dcd
decl_stmt|;
comment|/* 52 bit mask for carr detect by port */
name|short
name|v_cts
decl_stmt|;
comment|/* 54 bit mask for cts by port */
name|short
name|v_dsr
decl_stmt|;
comment|/* 56 bit mask for dsr by port */
name|short
name|v_secrec
decl_stmt|;
comment|/* 58 bit mask for secondary receive */
name|short
name|v_badport
decl_stmt|;
comment|/* 5a bit mask of failed ports */
name|char
name|v_portyp
index|[
literal|16
index|]
decl_stmt|;
comment|/* 5c type of each port */
block|}
struct|;
end_struct

begin_comment
comment|/* control bits for v_vioc and v_hdwre */
end_comment

begin_define
define|#
directive|define
name|V_RESET
value|0x1
end_define

begin_comment
comment|/* cause a vioc reset */
end_comment

begin_define
define|#
directive|define
name|V_TRP
value|0x2
end_define

begin_comment
comment|/* cause a vioc trap */
end_comment

begin_define
define|#
directive|define
name|V_INTR
value|0x4
end_define

begin_comment
comment|/* cause a vioc interrupt */
end_comment

begin_define
define|#
directive|define
name|V_ERR
value|0x80
end_define

begin_comment
comment|/* generic error flag */
end_comment

begin_define
define|#
directive|define
name|V_BSY
value|0x80
end_define

begin_comment
comment|/* generic busy flag */
end_comment

begin_define
define|#
directive|define
name|V_UNBSY
value|0x80
end_define

begin_comment
comment|/* not busy for unsolicited interrupt */
end_comment

begin_comment
comment|/* command identifier codes */
end_comment

begin_define
define|#
directive|define
name|VXC_LIDENT
value|0x0000
end_define

begin_comment
comment|/* load ident, set int vectors */
end_comment

begin_define
define|#
directive|define
name|VXC_XMITDTA
value|0x0200
end_define

begin_comment
comment|/* transmit */
end_comment

begin_define
define|#
directive|define
name|VXC_XMITIMM
value|0x0400
end_define

begin_comment
comment|/* xmit immediate */
end_comment

begin_define
define|#
directive|define
name|VXC_FDTATOX
value|0x0300
end_define

begin_comment
comment|/* flush data */
end_comment

begin_define
define|#
directive|define
name|VXC_LPARAX
value|0x0600
end_define

begin_comment
comment|/* load params */
end_comment

begin_define
define|#
directive|define
name|VXC_SNDBRKX
value|0x0C00
end_define

begin_comment
comment|/* send break to port */
end_comment

begin_define
define|#
directive|define
name|VXC_MDMCTL
value|0x1000
end_define

begin_comment
comment|/* auto modem control */
end_comment

begin_comment
comment|/* bisync specific command identifiers */
end_comment

begin_define
define|#
directive|define
name|VXC_LPARAX1
value|0x060a
end_define

begin_define
define|#
directive|define
name|VXC_MDMCTL1
value|0x1004
end_define

begin_define
define|#
directive|define
name|VXC_HUNTMD1
value|0x0804
end_define

begin_comment
comment|/* vioc types returned during config */
end_comment

begin_define
define|#
directive|define
name|VXT_VIOCBOP
value|0x05
end_define

begin_comment
comment|/* vioc-bop */
end_comment

begin_define
define|#
directive|define
name|VXT_PVIOCX
value|0x0A
end_define

begin_comment
comment|/* old connector panel vioc-x */
end_comment

begin_define
define|#
directive|define
name|VXT_VIOCX
value|0x0B
end_define

begin_comment
comment|/* new connector panel vioc-x */
end_comment

begin_define
define|#
directive|define
name|VXT_VIOCB
value|0x0C
end_define

begin_comment
comment|/* vioc-bisync */
end_comment

begin_define
define|#
directive|define
name|VXT_NEW
value|0x10
end_define

begin_comment
comment|/* new type bit (or'd in) */
end_comment

begin_define
define|#
directive|define
name|VX_BISYNC
value|0x1
end_define

begin_comment
comment|/* bisync flag indicator for bscport */
end_comment

begin_comment
comment|/* connector panel types (per port) */
end_comment

begin_define
define|#
directive|define
name|VXT_NONE
value|0
end_define

begin_comment
comment|/* no connector panel */
end_comment

begin_define
define|#
directive|define
name|VXT_8PORT
value|1
end_define

begin_comment
comment|/* 8 port RS-232C */
end_comment

begin_define
define|#
directive|define
name|VXT_RS422
value|2
end_define

begin_comment
comment|/* 8 port RS-422 (nonexistent) */
end_comment

begin_define
define|#
directive|define
name|VXT_4PORT
value|3
end_define

begin_comment
comment|/* 4 port RS-232 (with DSR/RING) */
end_comment

begin_define
define|#
directive|define
name|VXT_PARALLEL
value|4
end_define

begin_comment
comment|/* 4 port panel parallel port */
end_comment

begin_comment
comment|/* v_fault status values */
end_comment

begin_define
define|#
directive|define
name|VXF_READY
value|0x55
end_define

begin_comment
comment|/* no err in vioc self-initializaton */
end_comment

begin_comment
comment|/* line parameters, set with VXC_LPARAX */
end_comment

begin_define
define|#
directive|define
name|BITS5
value|0x00
end_define

begin_comment
comment|/* 5 bits per character */
end_comment

begin_define
define|#
directive|define
name|BITS6
value|0x80
end_define

begin_comment
comment|/* 6 bits per character */
end_comment

begin_define
define|#
directive|define
name|BITS7
value|0x40
end_define

begin_comment
comment|/* 7 bits per character */
end_comment

begin_define
define|#
directive|define
name|BITS8
value|0xc0
end_define

begin_comment
comment|/* 8 bits per character */
end_comment

begin_define
define|#
directive|define
name|VNOPARITY
value|0x00
end_define

begin_comment
comment|/* no parity bit */
end_comment

begin_define
define|#
directive|define
name|VODDP
value|0x01
end_define

begin_comment
comment|/* odd parity bit */
end_comment

begin_define
define|#
directive|define
name|VEVENP
value|0x03
end_define

begin_comment
comment|/* even parity bit */
end_comment

begin_define
define|#
directive|define
name|VSTOP1
value|0x04
end_define

begin_comment
comment|/* 1 stop bit */
end_comment

begin_define
define|#
directive|define
name|VSTOP2
value|0x0c
end_define

begin_comment
comment|/* 2 stop bit */
end_comment

begin_define
define|#
directive|define
name|V19200
value|0x13
end_define

begin_comment
comment|/* 19.2 kbaud */
end_comment

begin_comment
comment|/* modem control flags */
end_comment

begin_define
define|#
directive|define
name|VMOD_ON
value|1
end_define

begin_define
define|#
directive|define
name|VMOD_OFF
value|0
end_define

begin_define
define|#
directive|define
name|V_AUTO
value|0x00
end_define

begin_comment
comment|/* auto control of RTS, uses CTS */
end_comment

begin_define
define|#
directive|define
name|V_MANUAL
value|0x80
end_define

begin_comment
comment|/* manual control of RTS, ignore CTS */
end_comment

begin_define
define|#
directive|define
name|V_DTR_ON
value|0x02
end_define

begin_comment
comment|/* set DTR output */
end_comment

begin_define
define|#
directive|define
name|V_DTR_OFF
value|0x00
end_define

begin_comment
comment|/* drop DTR output */
end_comment

begin_define
define|#
directive|define
name|V_RTS
value|0x01
end_define

begin_comment
comment|/* set RTS output (manual only) */
end_comment

begin_define
define|#
directive|define
name|BRK_CHR
value|040
end_define

begin_comment
comment|/* break character */
end_comment

begin_define
define|#
directive|define
name|DCD_ON
value|020
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|DCD_OFF
value|010
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|CTS_ON
value|004
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|DSR_ON
value|0200
end_define

begin_comment
comment|/* modem signal states for bisync */
end_comment

begin_define
define|#
directive|define
name|DSR_OFF
value|0100
end_define

begin_define
define|#
directive|define
name|DSR_CHG
value|(DSR_ON|DSR_OFF)
end_define

begin_define
define|#
directive|define
name|VX_SILO
value|0x800
end_define

begin_comment
comment|/* offset to base of silo */
end_comment

begin_comment
comment|/* input status bits returned in silo */
end_comment

begin_define
define|#
directive|define
name|VX_PE
value|0x40
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|VX_FE
value|0x80
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|VX_RO
value|0xc0
end_define

begin_comment
comment|/* receiver overrun */
end_comment

begin_comment
comment|/* VIOC Process Error (PROCER) codes */
end_comment

begin_define
define|#
directive|define
name|VP_SILO_OFLOW
value|0x40
end_define

begin_comment
comment|/* input silo error, non-fatal */
end_comment

begin_define
define|#
directive|define
name|VRESPLEN
value|12
end_define

begin_define
define|#
directive|define
name|VCMDLEN
value|64
end_define

begin_define
define|#
directive|define
name|VC_IQLEN
value|64
end_define

begin_comment
comment|/* Interrupt circular queue length */
end_comment

begin_define
define|#
directive|define
name|NVCXBUFS
value|16*3
end_define

begin_comment
comment|/* 3 bufs per port per viocx */
end_comment

begin_define
define|#
directive|define
name|VC_CMDBUFL
value|NVCXBUFS
end_define

begin_comment
comment|/* circular cmd (to exec) queue len*/
end_comment

begin_struct
struct|struct
name|vcmds
block|{
name|int
name|v_cmdsem
decl_stmt|;
comment|/* # cmds waiting for itrque */
name|int
name|v_curcnt
decl_stmt|;
comment|/* # cmds in itrque and executing */
name|caddr_t
name|v_curcmd
index|[
name|VCMDLEN
index|]
decl_stmt|;
comment|/* pointers to cmds being executed */
name|int
name|v_fill
decl_stmt|;
comment|/* circular fill index */
name|int
name|v_empty
decl_stmt|;
comment|/* circular empty index */
name|caddr_t
name|cmdbuf
index|[
name|VC_CMDBUFL
index|]
decl_stmt|;
comment|/* circular cmd (to exec) queue */
name|int
name|v_itrfill
decl_stmt|;
comment|/* circular intr issue queue fill */
name|int
name|v_itrempt
decl_stmt|;
comment|/* circular intr issue queue empty */
name|short
name|v_itrqueu
index|[
name|VC_IQLEN
index|]
decl_stmt|;
comment|/* circular intr issue queue */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vxcmd
block|{
name|struct
name|vxcmd
modifier|*
name|c_fwd
decl_stmt|;
name|short
name|cmd
decl_stmt|;
name|char
name|par
index|[
literal|58
index|]
decl_stmt|;
comment|/* pad to 64 total size */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vxmit
block|{
name|char
name|line
decl_stmt|;
name|char
name|bcount
decl_stmt|;
name|char
name|ostream
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SSPEED
value|13
end_define

begin_comment
comment|/* standard speed 9600 bps */
end_comment

end_unit

