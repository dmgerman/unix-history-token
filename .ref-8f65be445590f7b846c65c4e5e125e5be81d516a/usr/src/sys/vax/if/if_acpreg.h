begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *	@(#)if_acpreg.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*************************************************************************/
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*       ________________________________________________________        */
end_comment

begin_comment
comment|/*      /                                                        \       */
end_comment

begin_comment
comment|/*     |          AAA          CCCCCCCCCCCCCC    CCCCCCCCCCCCCC   |      */
end_comment

begin_comment
comment|/*     |         AAAAA        CCCCCCCCCCCCCCCC  CCCCCCCCCCCCCCCC  |      */
end_comment

begin_comment
comment|/*     |        AAAAAAA       CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |      */
end_comment

begin_comment
comment|/*     |       AAAA AAAA      CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |      AAAA   AAAA     CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |     AAAA     AAAA    CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |    AAAA       AAAA   CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |   AAAA  AAAAAAAAAAA  CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |      */
end_comment

begin_comment
comment|/*     |  AAAA    AAAAAAAAAAA CCCCCCCCCCCCCCCC  CCCCCCCCCCCCCCCC  |      */
end_comment

begin_comment
comment|/*     | AAAA      AAAAAAAAA   CCCCCCCCCCCCCC    CCCCCCCCCCCCCC   |      */
end_comment

begin_comment
comment|/*      \________________________________________________________/       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  	Copyright (c) 1986 by Advanced Computer Communications           */
end_comment

begin_comment
comment|/*  	720 Santa Barbara Street, Santa Barbara, California  93101       */
end_comment

begin_comment
comment|/*  	(805) 963-9431                                                   */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  File:		if_acpreg.h                                      */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Author:		Arthur Berggreen                                 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Project:		ACP6100 (UPB with HDLC firmware)                 */
end_comment

begin_comment
comment|/*          		ACP5100 (QPB with HDLC firmware)                 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Revision History:                                                    */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*    21-NOV-1985  Clare Russ:  add fileheader and comments              */
end_comment

begin_comment
comment|/*         Add definitions for implementatin of new Command Interface    */
end_comment

begin_comment
comment|/*         (CIF) and Access Path Allocation Protocol (APAP).             */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*************************************************************************/
end_comment

begin_escape
end_escape

begin_comment
comment|/* device registers */
end_comment

begin_struct
struct|struct
name|acpregs
block|{
name|u_short
name|csr
decl_stmt|;
comment|/* control and status register */
comment|/* I/O request mailbox */
name|u_short
name|req_chan
decl_stmt|;
comment|/*   FDX channel number */
name|u_char
name|req_adx
decl_stmt|;
comment|/*   address bits 17-16 */
name|u_char
name|req_flags
decl_stmt|;
comment|/*   mailbox flags */
name|u_short
name|req_addr
decl_stmt|;
comment|/*   address bits 15-00 */
name|u_short
name|req_cnt
decl_stmt|;
comment|/*   byte count */
name|u_char
name|req_fcn
decl_stmt|;
comment|/*   I/O function */
name|u_char
name|req_sbf
decl_stmt|;
comment|/*   I/O subfunction */
comment|/* I/O completion mailbox */
name|u_short
name|cmp_chan
decl_stmt|;
comment|/*   FDX channel number */
name|u_char
name|cmp_unused
decl_stmt|;
comment|/*   address bits 17-16 */
name|u_char
name|cmp_flags
decl_stmt|;
comment|/*   mailbox flags */
name|u_short
name|cmp_cnt
decl_stmt|;
comment|/*   byte count */
name|u_char
name|cmp_stat
decl_stmt|;
comment|/*   I/O status */
name|u_char
name|cmp_sbst
decl_stmt|;
comment|/*   I/O substatus */
comment|/* Transfer request mailbox */
name|u_short
name|xfr_chan
decl_stmt|;
comment|/*   FDX channel number */
name|u_char
name|xfr_adx
decl_stmt|;
comment|/*   address bits 17-16 */
name|u_char
name|xfr_flags
decl_stmt|;
comment|/*   mailbox flags */
name|u_short
name|xfr_addr
decl_stmt|;
comment|/*   address bits 15-00 */
name|u_short
name|xfr_cnt
decl_stmt|;
comment|/*   byte count */
comment|/* System status mailbox */
name|u_char
name|sys_vers
decl_stmt|;
comment|/*   system version number */
name|u_char
name|sys_id
decl_stmt|;
comment|/*   system identification */
name|u_char
name|sys_vect
decl_stmt|;
comment|/*   interrupt vector base */
name|u_char
name|sys_stat
decl_stmt|;
comment|/*   system status */
block|}
struct|;
end_struct

begin_comment
comment|/* defines for CSR */
end_comment

begin_define
define|#
directive|define
name|CSR_BIT15
value|0x8000
end_define

begin_define
define|#
directive|define
name|CSR_BIT14
value|0x4000
end_define

begin_define
define|#
directive|define
name|CSR_MAINT
value|0x2000
end_define

begin_define
define|#
directive|define
name|CSR_HALT
value|0x1000
end_define

begin_define
define|#
directive|define
name|CSR_IBPEND
value|0x0800
end_define

begin_define
define|#
directive|define
name|CSR_IAPEND
value|0x0400
end_define

begin_define
define|#
directive|define
name|CSR_IBREQ
value|0x0200
end_define

begin_define
define|#
directive|define
name|CSR_IAREQ
value|0x0100
end_define

begin_define
define|#
directive|define
name|CSR_BIT7
value|0x0080
end_define

begin_define
define|#
directive|define
name|CSR_BIT6
value|0x0040
end_define

begin_define
define|#
directive|define
name|CSR_INTRB
value|0x0020
end_define

begin_comment
comment|/* ACP CPU Interrupt A Request */
end_comment

begin_define
define|#
directive|define
name|CSR_INTRA
value|0x0010
end_define

begin_comment
comment|/* ACP CPU Interrupt B Request */
end_comment

begin_define
define|#
directive|define
name|CSR_IENB
value|0x0008
end_define

begin_comment
comment|/* enable UNIBUS interrupt b   */
end_comment

begin_define
define|#
directive|define
name|CSR_IENA
value|0x0004
end_define

begin_comment
comment|/* enable UNIBUS interrupt a   */
end_comment

begin_define
define|#
directive|define
name|CSR_DMAEN
value|0x0002
end_define

begin_define
define|#
directive|define
name|CSR_RESET
value|0x0001
end_define

begin_comment
comment|/* mailbox handshake flags */
end_comment

begin_define
define|#
directive|define
name|FLAGS_RDY
value|0x80
end_define

begin_define
define|#
directive|define
name|FLAGS_DON
value|0x40
end_define

begin_define
define|#
directive|define
name|FLAGS_DIR
value|0x20
end_define

begin_comment
comment|/* I/O request function code definitions */
end_comment

begin_define
define|#
directive|define
name|ACPRED
value|0x01
end_define

begin_comment
comment|/* read from ACP */
end_comment

begin_define
define|#
directive|define
name|ACPWRT
value|0x02
end_define

begin_comment
comment|/* write to ACP */
end_comment

begin_define
define|#
directive|define
name|ACPSTR
value|0x10
end_define

begin_comment
comment|/* stream flag */
end_comment

begin_define
define|#
directive|define
name|ACPEOS
value|(0x20|ACPSTR)
end_define

begin_comment
comment|/* end of stream flag */
end_comment

begin_define
define|#
directive|define
name|ACPABT
value|0x04
end_define

begin_comment
comment|/* abort flag */
end_comment

begin_define
define|#
directive|define
name|ACPXFR
value|0x40
end_define

begin_comment
comment|/* tranfer req/grant flag */
end_comment

begin_define
define|#
directive|define
name|FCN_MASK
value|0x07
end_define

end_unit

