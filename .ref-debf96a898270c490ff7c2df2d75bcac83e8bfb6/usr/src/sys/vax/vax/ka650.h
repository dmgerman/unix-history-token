begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Mt. Xinu.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)ka650.h	7.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *  * Definitions specific to the ka650 (uVAX 3600/3602) cpu card.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX650
end_ifdef

begin_comment
comment|/*  * CAER: Memory System Error Register (IPR 39)  */
end_comment

begin_define
define|#
directive|define
name|CAER_DAL
value|0x00000040
end_define

begin_comment
comment|/* CDAL or level 2 cache data parity */
end_comment

begin_define
define|#
directive|define
name|CAER_MCD
value|0x00000020
end_define

begin_comment
comment|/* mcheck due to DAL parity error */
end_comment

begin_define
define|#
directive|define
name|CAER_MCC
value|0x00000010
end_define

begin_comment
comment|/* mcheck due to 1st lev cache parity */
end_comment

begin_define
define|#
directive|define
name|CAER_DAT
value|0x00000002
end_define

begin_comment
comment|/* data parity in 1st level cache */
end_comment

begin_define
define|#
directive|define
name|CAER_TAG
value|0x00000001
end_define

begin_comment
comment|/* tag parity in 1st level cache */
end_comment

begin_comment
comment|/*  * CADR: Cache Disable Register (IPR 37)  */
end_comment

begin_define
define|#
directive|define
name|CADR_STMASK
value|0x000000f0
end_define

begin_comment
comment|/* 1st level cache state mask */
end_comment

begin_define
define|#
directive|define
name|CADR_SEN2
value|0x00000080
end_define

begin_comment
comment|/* 1st level cache set 2 enabled */
end_comment

begin_define
define|#
directive|define
name|CADR_SEN1
value|0x00000040
end_define

begin_comment
comment|/* 1st level cache set 1 enabled */
end_comment

begin_define
define|#
directive|define
name|CADR_CENI
value|0x00000020
end_define

begin_comment
comment|/* 1st level I-stream caching enabled */
end_comment

begin_define
define|#
directive|define
name|CADR_CEND
value|0x00000010
end_define

begin_comment
comment|/* 1st level D-stream caching enabled */
end_comment

begin_comment
comment|/*  * Internal State Info 2: (for mcheck recovery)  */
end_comment

begin_define
define|#
directive|define
name|IS2_VCR
value|0x00008000
end_define

begin_comment
comment|/* VAX Can't Restart flag */
end_comment

begin_comment
comment|/*  * DMA System Error Register (merr_dser)  */
end_comment

begin_define
define|#
directive|define
name|DSER_QNXM
value|0x00000080
end_define

begin_comment
comment|/* Q-22 Bus NXM */
end_comment

begin_define
define|#
directive|define
name|DSER_QPE
value|0x00000020
end_define

begin_comment
comment|/* Q-22 Bus parity Error */
end_comment

begin_define
define|#
directive|define
name|DSER_MEM
value|0x00000010
end_define

begin_comment
comment|/* Main mem err due to ext dev DMA */
end_comment

begin_define
define|#
directive|define
name|DSER_LOST
value|0x00000008
end_define

begin_comment
comment|/* Lost error: DSER<7,5,4,0> set */
end_comment

begin_define
define|#
directive|define
name|DSER_NOGRANT
value|0x00000004
end_define

begin_comment
comment|/* No Grant timeout on cpu demand R/W */
end_comment

begin_define
define|#
directive|define
name|DSER_DNXM
value|0x00000001
end_define

begin_comment
comment|/* DMA NXM */
end_comment

begin_define
define|#
directive|define
name|DSER_CLEAR
value|(DSER_QNXM | DSER_QPE | DSER_MEM |  \ 			 DSER_LOST | DSER_NOGRANT | DSER_DNXM)
end_define

begin_define
define|#
directive|define
name|DMASER_BITS
define|\
value|"\20\20BHALT\17DCNEG\10QBNXM\6QBPE\5MEMERR\4LOSTERR\3NOGRANT\1DMANXM"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Local registers (in I/O space)  * This is done in disjoint sections.  Map names are set in locore.s  * and they are mapped in routine configcpu()  */
end_comment

begin_comment
comment|/*  * memory error& configuration registers  */
end_comment

begin_struct
struct|struct
name|ka650_merr
block|{
name|u_long
name|merr_scr
decl_stmt|;
comment|/* System Config Register */
name|u_long
name|merr_dser
decl_stmt|;
comment|/* DMA System Error Register */
name|u_long
name|merr_qbear
decl_stmt|;
comment|/* QBus Error Address Register */
name|u_long
name|merr_dear
decl_stmt|;
comment|/* DMA Error Address Register */
name|u_long
name|merr_qbmbr
decl_stmt|;
comment|/* Q Bus Map Base address Register */
name|u_long
name|pad
index|[
literal|59
index|]
decl_stmt|;
name|u_long
name|merr_csr
index|[
literal|16
index|]
decl_stmt|;
comment|/* Main Memory Config Regs (16 banks) */
name|u_long
name|merr_errstat
decl_stmt|;
comment|/* Main Memory Error Status */
name|u_long
name|merr_cont
decl_stmt|;
comment|/* Main Memory Control */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KA650_MERR
value|0x20080000
end_define

begin_comment
comment|/*  * Main Memory Error Status Register (merr_errstat)  */
end_comment

begin_define
define|#
directive|define
name|MEM_EMASK
value|0xe0000180
end_define

begin_comment
comment|/* mask of all err bits */
end_comment

begin_define
define|#
directive|define
name|MEM_RDS
value|0x80000000
end_define

begin_comment
comment|/* uncorrectable main memory */
end_comment

begin_define
define|#
directive|define
name|MEM_RDSHIGH
value|0x40000000
end_define

begin_comment
comment|/* high rate RDS errors */
end_comment

begin_define
define|#
directive|define
name|MEM_CRD
value|0x20000000
end_define

begin_comment
comment|/* correctable main memory */
end_comment

begin_define
define|#
directive|define
name|MEM_DMA
value|0x00000100
end_define

begin_comment
comment|/* DMA read or write error */
end_comment

begin_define
define|#
directive|define
name|MEM_CDAL
value|0x00000080
end_define

begin_comment
comment|/* CDAL Parity error on write */
end_comment

begin_define
define|#
directive|define
name|MEM_PAGE
value|0x1ffffe00
end_define

begin_comment
comment|/* Offending Page Number */
end_comment

begin_define
define|#
directive|define
name|MEM_PAGESHFT
value|9
end_define

begin_comment
comment|/* Shift to normalize page number */
end_comment

begin_comment
comment|/*  * Main Memory Control& Diag Status Reg (merr_cont)  */
end_comment

begin_define
define|#
directive|define
name|MEM_CRDINT
value|0x00001000
end_define

begin_comment
comment|/* CRD interrupts enabled */
end_comment

begin_define
define|#
directive|define
name|MEM_REFRESH
value|0x00000800
end_define

begin_comment
comment|/* Forced memory refresh */
end_comment

begin_define
define|#
directive|define
name|MEM_ERRDIS
value|0x00000400
end_define

begin_comment
comment|/* error detect disable	*/
end_comment

begin_define
define|#
directive|define
name|MEM_DIAG
value|0x00000080
end_define

begin_comment
comment|/* Diagnostics mode */
end_comment

begin_define
define|#
directive|define
name|MEM_CHECK
value|0x0000007f
end_define

begin_comment
comment|/* check bits for diagnostic mode */
end_comment

begin_comment
comment|/*  * Main Memory Config Regs (merr_csr[0-15])  */
end_comment

begin_define
define|#
directive|define
name|MEM_BNKENBLE
value|0x80000000
end_define

begin_comment
comment|/* Bank Enable */
end_comment

begin_define
define|#
directive|define
name|MEM_BNKNUM
value|0x03c00000
end_define

begin_comment
comment|/* Physical map Bank number */
end_comment

begin_define
define|#
directive|define
name|MEM_BNKUSAGE
value|0x00000003
end_define

begin_comment
comment|/* Bank Usage */
end_comment

begin_comment
comment|/*  * Cache Control& Boot/Diag registers  */
end_comment

begin_struct
struct|struct
name|ka650_cbd
block|{
name|u_char
name|cbd_cacr
decl_stmt|;
comment|/* Low byte: Cache Enable& Parity Err detect */
name|u_char
name|cbd_cdf1
decl_stmt|;
comment|/* Cache diagnostic field (unused) */
name|u_char
name|cbd_cdf2
decl_stmt|;
comment|/* Cache diagnostic field (unused) */
name|u_char
name|pad
decl_stmt|;
name|u_long
name|cbd_bdr
decl_stmt|;
comment|/* Boot& Diagnostic Register (unused) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KA650_CBD
value|0x20084000
end_define

begin_comment
comment|/*  * CACR: Cache Control Register (2nd level cache) (cbd_cacr)  */
end_comment

begin_define
define|#
directive|define
name|CACR_CEN
value|0x00000010
end_define

begin_comment
comment|/* Cache enable */
end_comment

begin_define
define|#
directive|define
name|CACR_CPE
value|0x00000020
end_define

begin_comment
comment|/* Cache Parity Error */
end_comment

begin_comment
comment|/*  * System Support Chip (SSC) registers  */
end_comment

begin_struct
struct|struct
name|ka650_ssc
block|{
name|u_long
name|ssc_sscbr
decl_stmt|;
comment|/* SSC Base Addr Register */
name|u_long
name|pad1
index|[
literal|3
index|]
decl_stmt|;
name|u_long
name|ssc_ssccr
decl_stmt|;
comment|/* SSC Configuration Register */
name|u_long
name|pad2
index|[
literal|3
index|]
decl_stmt|;
name|u_long
name|ssc_cbtcr
decl_stmt|;
comment|/* CDAL Bus Timeout Control Register */
name|u_long
name|pad3
index|[
literal|55
index|]
decl_stmt|;
name|u_long
name|ssc_tcr0
decl_stmt|;
comment|/* timer control reg 0 */
name|u_long
name|ssc_tir0
decl_stmt|;
comment|/* timer interval reg 0 */
name|u_long
name|ssc_tnir0
decl_stmt|;
comment|/* timer next interval reg 0 */
name|u_long
name|ssc_tivr0
decl_stmt|;
comment|/* timer interrupt vector reg 0 */
name|u_long
name|ssc_tcr1
decl_stmt|;
comment|/* timer control reg 1 */
name|u_long
name|ssc_tir1
decl_stmt|;
comment|/* timer interval reg 1 */
name|u_long
name|ssc_tnir1
decl_stmt|;
comment|/* timer next interval reg 1 */
name|u_long
name|ssc_tivr1
decl_stmt|;
comment|/* timer interrupt vector reg 1 */
name|u_long
name|pad4
index|[
literal|184
index|]
decl_stmt|;
name|u_char
name|ssc_cpmbx
decl_stmt|;
comment|/* Console Program Mail Box: Lang& Hact */
name|u_char
name|ssc_terminfo
decl_stmt|;
comment|/* TTY info: Video Dev, MCS, CRT& ROM flags */
name|u_char
name|ssc_keyboard
decl_stmt|;
comment|/* Keyboard code */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KA650_SSC
value|0x20140000
end_define

begin_comment
comment|/*  * CBTCR: CDAL Bus Timeout Control Register (ssc_cbtcr)  */
end_comment

begin_define
define|#
directive|define
name|CBTCR_BTO
value|0x80000000
end_define

begin_comment
comment|/* r/w unimp IPR or unack intr */
end_comment

begin_define
define|#
directive|define
name|CBTCR_RWT
value|0x40000000
end_define

begin_comment
comment|/* CDAL Bus Timeout on CPU or DMA */
end_comment

begin_comment
comment|/*  * TCR0/TCR1: Programable Timer Control Registers (ssc_tcr[01])  * (The rest of the bits are the same as in the standard VAX  *	Interval timer and are defined in clock.h)  */
end_comment

begin_define
define|#
directive|define
name|TCR_STP
value|0x00000004
end_define

begin_comment
comment|/* Stop after time-out */
end_comment

begin_comment
comment|/*  * Flags for Console Program Mail Box  */
end_comment

begin_define
define|#
directive|define
name|CPMB650_HALTACT
value|0x03
end_define

begin_comment
comment|/* Field for halt action */
end_comment

begin_define
define|#
directive|define
name|CPMB650_RESTART
value|0x01
end_define

begin_comment
comment|/* Restart */
end_comment

begin_define
define|#
directive|define
name|CPMB650_REBOOT
value|0x02
end_define

begin_comment
comment|/* Reboot */
end_comment

begin_define
define|#
directive|define
name|CPMB650_HALT
value|0x03
end_define

begin_comment
comment|/* Halt */
end_comment

begin_define
define|#
directive|define
name|CPMB650_BIP
value|0x04
end_define

begin_comment
comment|/* Bootstrap in progress */
end_comment

begin_define
define|#
directive|define
name|CPMB650_RIP
value|0x08
end_define

begin_comment
comment|/* Restart in progress */
end_comment

begin_define
define|#
directive|define
name|CPMB650_LANG
value|0xf0
end_define

begin_comment
comment|/* Language field */
end_comment

begin_comment
comment|/*  * Inter Processor Communication Register  * To determine if memory error was from QBUS device DMA (as opposed to cpu).  */
end_comment

begin_struct
struct|struct
name|ka650_ipcr
block|{
name|u_long
name|pad
index|[
literal|80
index|]
decl_stmt|;
name|u_short
name|ipcr0
decl_stmt|;
comment|/* InterProcessor Comm Reg for arbiter */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KA650_IPCR
value|0x20001e00
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|STANDALONE
end_ifndef

begin_comment
comment|/*  * External declarations of the map names (declared in spt.s)  * for the local register space.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|KA650MERRmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ka650_merr
name|ka650merr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mem err& mem config regs */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|KA650CBDmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ka650_cbd
name|ka650cbd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cache control& boot/diag regs */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|KA650SSCmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ka650_ssc
name|ka650ssc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SSC regs (& console prog mail box) */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|KA650IPCRmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ka650_ipcr
name|ka650ipcr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* InterProcessor Com Regs */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|KA650CACHEmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ka650cache
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cache Diagnostic space (for flush) */
end_comment

begin_endif
endif|#
directive|endif
endif|STANDALONE
end_endif

begin_endif
endif|#
directive|endif
endif|LOCORE
end_endif

begin_comment
comment|/*  * Physical start address of the Qbus memory.  * The q-bus memory size is 4 meg.  * Physical start address of the I/O space (where the 8Kbyte I/O page is).  */
end_comment

begin_define
define|#
directive|define
name|KA650_QMEM
value|0x30000000
end_define

begin_define
define|#
directive|define
name|KA650_QMEMSIZE
value|(512*8192)
end_define

begin_define
define|#
directive|define
name|KA650_QDEVADDR
value|0x20000000
end_define

begin_comment
comment|/*  * Mapping info for Cache Entries, including  * Size (in bytes) of 2nd Level Cache for cache flush operation  */
end_comment

begin_define
define|#
directive|define
name|KA650_CACHE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|KA650_CACHESIZE
value|(64*1024)
end_define

begin_comment
comment|/*  * Useful ROM addresses  */
end_comment

begin_define
define|#
directive|define
name|KA650ROM_SIDEX
value|0x20060004
end_define

begin_comment
comment|/* system ID extension */
end_comment

begin_define
define|#
directive|define
name|KA650ROM_GETC
value|0x20060008
end_define

begin_comment
comment|/* (jsb) get character from console */
end_comment

begin_define
define|#
directive|define
name|KA650ROM_PUTS
value|0x2006000c
end_define

begin_comment
comment|/* (jsb) put string to console */
end_comment

begin_define
define|#
directive|define
name|KA650ROM_GETS
value|0x20060010
end_define

begin_comment
comment|/* (jsb) read string with prompt */
end_comment

begin_define
define|#
directive|define
name|KA650_CONSTYPE
value|0x20140401
end_define

begin_comment
comment|/* byte at which console type resides */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

