begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************/
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	 ________________________________________________________	 */
end_comment

begin_comment
comment|/*	/							 \	 */
end_comment

begin_comment
comment|/*     |	  AAA	       CCCCCCCCCCCCCC	 CCCCCCCCCCCCCC	  |	 */
end_comment

begin_comment
comment|/*     |	 AAAAA	      CCCCCCCCCCCCCCCC	CCCCCCCCCCCCCCCC  |	 */
end_comment

begin_comment
comment|/*     |	AAAAAAA	      CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |	 */
end_comment

begin_comment
comment|/*     |       AAAA AAAA      CCCC		CCCC		  |	 */
end_comment

begin_comment
comment|/*     |      AAAA   AAAA     CCCC		CCCC		  |	 */
end_comment

begin_comment
comment|/*     |     AAAA     AAAA    CCCC		CCCC		  |	 */
end_comment

begin_comment
comment|/*     |    AAAA       AAAA   CCCC		CCCC		  |	 */
end_comment

begin_comment
comment|/*     |   AAAA	 AAAAAAAAAAA  CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |	 */
end_comment

begin_comment
comment|/*     |  AAAA	  AAAAAAAAAAA CCCCCCCCCCCCCCCC	CCCCCCCCCCCCCCCC  |	 */
end_comment

begin_comment
comment|/*     | AAAA	   AAAAAAAAA   CCCCCCCCCCCCCC	 CCCCCCCCCCCCCC	  |	 */
end_comment

begin_comment
comment|/*	\________________________________________________________/	 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	Copyright (c) 1986 by Advanced Computer Communications		 */
end_comment

begin_comment
comment|/*	720 Santa Barbara Street, Santa Barbara, California  93101	 */
end_comment

begin_comment
comment|/*	(805) 963-9431							 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  File:		ddareg.h					 */
end_comment

begin_comment
comment|/*			When this file is copied to the /sys/vaxif	 */
end_comment

begin_comment
comment|/*			directory, it is renamed 'if_ddareg.h'.		 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Project:		UNIX 4.n BSD DDA-X.25 Network Interface Driver	 */
end_comment

begin_comment
comment|/*			for ACP 5250 and ACP 6250			 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Function:		This file contains definitions of the hardware	 */
end_comment

begin_comment
comment|/*			interface of the ACP 5250/6250.			 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Revision History at end of file					 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*************************************************************************/
end_comment

begin_escape
end_escape

begin_comment
comment|/* ACP device Communication Register layout */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIMULATION
end_ifdef

begin_comment
comment|/* device registers */
end_comment

begin_struct
struct|struct
name|ddaregs
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
name|req_flags
decl_stmt|;
comment|/*   mailbox flags */
name|u_char
name|req_adx
decl_stmt|;
comment|/*   address bits 17-16 */
name|u_short
name|req_addr
decl_stmt|;
comment|/*   address bits 15-00 */
name|u_short
name|req_cnt
decl_stmt|;
comment|/*   byte count */
name|u_char
name|req_sbf
decl_stmt|;
comment|/*   I/O subfunction */
name|u_char
name|req_fcn
decl_stmt|;
comment|/*   I/O function */
comment|/* I/O completion mailbox */
name|u_short
name|cmp_chan
decl_stmt|;
comment|/*   FDX channel number */
name|u_char
name|cmp_flags
decl_stmt|;
comment|/*   mailbox flags */
name|u_char
name|cmp_unused
decl_stmt|;
comment|/*   address bits 17-16 */
name|u_short
name|cmp_cnt
decl_stmt|;
comment|/*   byte count */
name|u_char
name|cmp_sbst
decl_stmt|;
comment|/*   I/O substatus */
name|u_char
name|cmp_stat
decl_stmt|;
comment|/*   I/O status */
comment|/* Transfer request mailbox */
name|u_short
name|xfr_chan
decl_stmt|;
comment|/*   FDX channel number */
name|u_char
name|xfr_flags
decl_stmt|;
comment|/*   mailbox flags */
name|u_char
name|xfr_adx
decl_stmt|;
comment|/*   address bits 17-16 */
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
name|sys_id
decl_stmt|;
comment|/*   system identification */
name|u_char
name|sys_vers
decl_stmt|;
comment|/*   system version number */
name|u_char
name|sys_stat
decl_stmt|;
comment|/*   system status */
name|u_char
name|sys_vect
decl_stmt|;
comment|/*   interrupt vector base */
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* device registers */
end_comment

begin_struct
struct|struct
name|ddaregs
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

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* mailbox handshake flags, these flags are used with the req_flags, */
end_comment

begin_comment
comment|/* cmp_flags, and xfr_flags to indicate current state of events      */
end_comment

begin_define
define|#
directive|define
name|FLAGS_RDY
value|0x80
end_define

begin_comment
comment|/* indicates ready */
end_comment

begin_define
define|#
directive|define
name|FLAGS_DON
value|0x40
end_define

begin_comment
comment|/* indicates done */
end_comment

begin_define
define|#
directive|define
name|FLAGS_DIR
value|0x20
end_define

begin_comment
comment|/* indicates write (host to ACP) */
end_comment

begin_comment
comment|/* I/O request function code definitions */
end_comment

begin_define
define|#
directive|define
name|DDARDB
value|0x01
end_define

begin_comment
comment|/* read from ACP */
end_comment

begin_define
define|#
directive|define
name|DDAWRT
value|0x02
end_define

begin_comment
comment|/* write to ACP */
end_comment

begin_define
define|#
directive|define
name|DDASTR
value|0x10
end_define

begin_comment
comment|/* stream flag */
end_comment

begin_define
define|#
directive|define
name|DDAEOS
value|(0x20|DDASTR)
end_define

begin_comment
comment|/* end of stream flag */
end_comment

begin_define
define|#
directive|define
name|DDAABT
value|0x04
end_define

begin_comment
comment|/* abort flag */
end_comment

begin_define
define|#
directive|define
name|DDAXFR
value|0x40
end_define

begin_comment
comment|/* indicates transfer request   */
end_comment

begin_comment
comment|/* The UNIBUS address in req_addr is    */
end_comment

begin_comment
comment|/* invalid.  The ACP device must issue  */
end_comment

begin_comment
comment|/* a Transfer Request in order to       */
end_comment

begin_comment
comment|/* obtain the UNIBUS address            */
end_comment

begin_define
define|#
directive|define
name|DDASWP
value|0x80
end_define

begin_comment
comment|/* Swap host high/low bytes     */
end_comment

begin_comment
comment|/* The ACP device views UNIBUS memory   */
end_comment

begin_comment
comment|/* as if it were MC68000 memory:  the   */
end_comment

begin_comment
comment|/* MS byte of a word is even-addressed  */
end_comment

begin_comment
comment|/* byte and the LS byte is the odd-     */
end_comment

begin_comment
comment|/* addressed byte.                      */
end_comment

begin_define
define|#
directive|define
name|FCN_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|DDA_BITS
define|\
value|"\10\20UER\17NXM\16PER\15ZRUN\14ZGO\10MBLK\7SRV\6MAIN\5DMA\4WRT\3IEN\2RST\1NMI"
end_define

begin_comment
comment|/*  Host Request Mailbox Completion Status  */
end_comment

begin_define
define|#
directive|define
name|DDAIOCOK
value|0x01
end_define

begin_comment
comment|/* successful completion */
end_comment

begin_define
define|#
directive|define
name|DDAIOCOKP
value|0x02
end_define

begin_comment
comment|/* successful completion, more data pending */
end_comment

begin_define
define|#
directive|define
name|DDAIOCABT
value|0xff
end_define

begin_comment
comment|/* i/o aborted */
end_comment

begin_define
define|#
directive|define
name|DDAIOCERR
value|0xfe
end_define

begin_comment
comment|/* program error */
end_comment

begin_define
define|#
directive|define
name|DDAIOCOVR
value|0xfd
end_define

begin_comment
comment|/* overrun error */
end_comment

begin_define
define|#
directive|define
name|DDAIOCUBE
value|0xfc
end_define

begin_comment
comment|/* Transfer count = 0 */
end_comment

begin_comment
comment|/* Either program error (byte count on I/O   */
end_comment

begin_comment
comment|/* request equals 0) or driver error (driver */
end_comment

begin_comment
comment|/* granted byte count = 0 in response to     */
end_comment

begin_comment
comment|/* Transfer Request)                         */
end_comment

begin_define
define|#
directive|define
name|DDAIODMAE
value|0xfb
end_define

begin_comment
comment|/* DMA completion error:  Completion sub-    */
end_comment

begin_comment
comment|/* status equals error bits from the ACP DMA */
end_comment

begin_comment
comment|/* status register                           */
end_comment

begin_define
define|#
directive|define
name|DDAIOLCOL
value|0xf9
end_define

begin_comment
comment|/* Listen Collision:  Both sides of a DPN in */
end_comment

begin_comment
comment|/* the same direction have Listen requests   */
end_comment

begin_comment
comment|/* pending.  Both requests are terminated    */
end_comment

begin_comment
comment|/* with this status code.                    */
end_comment

begin_define
define|#
directive|define
name|DDAIOFUNC
value|0xf8
end_define

begin_comment
comment|/* Invalid function:  The function specified */
end_comment

begin_comment
comment|/* in a request is invalid.                  */
end_comment

begin_define
define|#
directive|define
name|DDAIODPN
value|0xf7
end_define

begin_comment
comment|/* Invalid DPN:  The DPN specified in a      */
end_comment

begin_comment
comment|/* request is out of the range handled by    */
end_comment

begin_comment
comment|/* CRI (Communications Register Interface)   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNU__
end_ifdef

begin_define
define|#
directive|define
name|ddaregs
value|ddaregs volatile
end_define

begin_endif
endif|#
directive|endif
endif|__GNU__
end_endif

begin_escape
end_escape

begin_comment
comment|/* Revision History:  26-Mar-1986: V1.0 Clair Russ 		First generated. ??-???-1988: V1.1 Steve Johnson 		Added code for simulation 19-Mar-1989: V4.3.1 Paul Traina 		Added Multinet / GCC support for structure padding 28-May-1989: V4.3.6 Paul Traina 		Cosmetic changes only */
end_comment

end_unit

