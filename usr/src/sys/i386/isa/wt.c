begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"wt.h"
end_include

begin_if
if|#
directive|if
name|NWT
operator|>
literal|0
end_if

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1989 Carnegie-Mellon University  * All rights reserved.  The CMU software License Agreement specifies  * the terms and conditions for use and redistribution.  *	@(#)wt.c	1.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   * HISTORY  * $Log:	wt.c,v $  * Revision 2.2.1.3  90/01/08  13:29:38  rvb  * 	Add Intel copyright.  * 	[90/01/08            rvb]  *   * Revision 2.2.1.2  89/12/21  18:00:09  rvb  * 	Change WTPRI to make the streamer tape read/write  * 	interruptible. 		[lin]  *   * Revision 2.2.1.1  89/11/10  09:49:49  rvb  * 	ORC likes their streamer port at 0x288.  * 	[89/11/08            rvb]  *   * Revision 2.2  89/09/25  12:33:02  rvb  * 	Driver was provided by Intel 9/18/89.  * 	[89/09/23            rvb]  *   */
end_comment

begin_comment
comment|/*  *  *  Copyright 1988, 1989 by Intel Corporation  *  *	Support Bell Tech QIC-02 and WANGTEK QIC-36 or QIC-02  */
end_comment

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<machine/isa/wtreg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ORC
end_ifdef

begin_decl_stmt
name|unsigned
name|wtport
init|=
literal|0x288
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base I/O port of controller	*/
end_comment

begin_else
else|#
directive|else
else|ORC
end_else

begin_decl_stmt
name|unsigned
name|wtport
init|=
literal|0x300
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base I/O port of controller	*/
end_comment

begin_endif
endif|#
directive|endif
endif|ORC
end_endif

begin_comment
comment|/* standard = 0x300		*/
end_comment

begin_comment
comment|/* alternate = 0x338		*/
end_comment

begin_decl_stmt
name|unsigned
name|wtchan
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DMA channel number		*/
end_comment

begin_comment
comment|/* stardard = 1			*/
end_comment

begin_comment
comment|/* hardware permits 1, 2 or 3.	*/
end_comment

begin_comment
comment|/* (Avoid DMA 2: used by disks) */
end_comment

begin_decl_stmt
name|int
name|first_wtopen_ever
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ERROR
value|1
end_define

begin_comment
comment|/* return from tape routines */
end_comment

begin_define
define|#
directive|define
name|SUCCESS
value|0
end_define

begin_comment
comment|/* return from tape routines */
end_comment

begin_decl_stmt
name|int
name|wci
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|exflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bytes
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|eqdma
init|=
literal|0x8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|pagereg
init|=
literal|0x83
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|dmareg
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|dma_write
init|=
literal|0x49
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|dma_read
init|=
literal|0x45
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|dma_done
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|mode
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|mbits
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* map bits into each other */
end_comment

begin_decl_stmt
specifier|static
name|long
name|bufptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|numbytes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* _wci		dw	0	; interrupt chain finished normally _exflag		dw	0	; exception variable _bytes		dw	0	; current bytes  eqdma		db	8h	; enable dma command: ch1,ch2=8h, ch3=10h pagereg		db	83h	; ch1=83h, ch2=81h, ch3=82h dmareg		db	2	; ch1=2, ch2=4, ch3=6 dma_write	db	49h	; write dma command: 48h+_wtchan dma_read	db	45h	; read dma command: 44h+_wtchan dma_done	db	2	; dma done flag: 1<<_wtchan mode		db	0	; dma operation mode lbufptr		dw	0	; buffer pointer to data buffers, low word hbufptr		dw	0	; buffer pointer to data buffers, high word numbytes	dw	0	; number of bytes to read or write (new) */
end_comment

begin_define
define|#
directive|define
name|PAGESIZ
value|4096
end_define

begin_define
define|#
directive|define
name|HZ
value|60
end_define

begin_comment
comment|/* tape controller ports */
end_comment

begin_define
define|#
directive|define
name|STATPORT
value|wtport
end_define

begin_define
define|#
directive|define
name|CTLPORT
value|STATPORT
end_define

begin_define
define|#
directive|define
name|CMDPORT
value|(wtport+1)
end_define

begin_define
define|#
directive|define
name|DATAPORT
value|CMDPORT
end_define

begin_comment
comment|/* defines for reading out status from wangtek tape controller */
end_comment

begin_define
define|#
directive|define
name|READY
value|0x01
end_define

begin_comment
comment|/* ready bit define        */
end_comment

begin_define
define|#
directive|define
name|EXCEP
value|0x02
end_define

begin_comment
comment|/* exception bit define    */
end_comment

begin_define
define|#
directive|define
name|STAT
value|(READY|EXCEP)
end_define

begin_define
define|#
directive|define
name|RESETMASK
value|0x7
end_define

begin_define
define|#
directive|define
name|RESETVAL
value|(RESETMASK& ~EXCEP)
end_define

begin_comment
comment|/* tape controller control bits (CTLPORT) */
end_comment

begin_define
define|#
directive|define
name|ONLINE
value|0x01
end_define

begin_define
define|#
directive|define
name|RESET
value|0x02
end_define

begin_define
define|#
directive|define
name|REQUEST
value|0x04
end_define

begin_comment
comment|/* request command */
end_comment

begin_define
define|#
directive|define
name|CMDOFF
value|0xC0
end_define

begin_comment
comment|/* QIC-02 commands (CMDPORT) */
end_comment

begin_define
define|#
directive|define
name|RDDATA
value|0x80
end_define

begin_comment
comment|/* read data */
end_comment

begin_define
define|#
directive|define
name|READFM
value|0xA0
end_define

begin_comment
comment|/* read file mark */
end_comment

begin_define
define|#
directive|define
name|WRTDATA
value|0x40
end_define

begin_comment
comment|/* write data */
end_comment

begin_define
define|#
directive|define
name|WRITEFM
value|0x60
end_define

begin_comment
comment|/* write file mark */
end_comment

begin_define
define|#
directive|define
name|RDSTAT
value|0xC0
end_define

begin_comment
comment|/* read status command */
end_comment

begin_define
define|#
directive|define
name|REWIND
value|0x21
end_define

begin_comment
comment|/* rewind command (position+bot) */
end_comment

begin_comment
comment|/* 8237 DMA controller regs */
end_comment

begin_define
define|#
directive|define
name|STATUSREG
value|0x8
end_define

begin_define
define|#
directive|define
name|MASKREG
value|0xA
end_define

begin_define
define|#
directive|define
name|MODEREG
value|0xB
end_define

begin_define
define|#
directive|define
name|CLEARFF
value|0xC
end_define

begin_comment
comment|/* streamer tape block size */
end_comment

begin_define
define|#
directive|define
name|BLKSIZE
value|512
end_define

begin_comment
comment|/* Tape characteristics */
end_comment

begin_define
define|#
directive|define
name|NBPS
value|512
end_define

begin_comment
comment|/* 512-byte blocks */
end_comment

begin_define
define|#
directive|define
name|ERROR
value|1
end_define

begin_comment
comment|/* return from tape routines */
end_comment

begin_define
define|#
directive|define
name|SUCCESS
value|0
end_define

begin_comment
comment|/* return from tape routines */
end_comment

begin_comment
comment|/* Minor devs */
end_comment

begin_define
define|#
directive|define
name|TP_REWCLOSE
parameter_list|(
name|d
parameter_list|)
value|((minor(d)&04) == 0)
end_define

begin_comment
comment|/* Rewind tape on close if read/write */
end_comment

begin_define
define|#
directive|define
name|TP_DENS
parameter_list|(
name|dev
parameter_list|)
value|((minor(dev)>> 3)& 03)
end_define

begin_comment
comment|/* set density */
end_comment

begin_define
define|#
directive|define
name|TPHOG
parameter_list|(
name|d
parameter_list|)
value|0
end_define

begin_comment
comment|/* use Hogproc during tape I/O	*/
end_comment

begin_comment
comment|/* defines for wtflags */
end_comment

begin_define
define|#
directive|define
name|TPINUSE
value|0x0001
end_define

begin_comment
comment|/* tape is already open */
end_comment

begin_define
define|#
directive|define
name|TPREAD
value|0x0002
end_define

begin_comment
comment|/* tape is only open for reading */
end_comment

begin_define
define|#
directive|define
name|TPWRITE
value|0x0004
end_define

begin_comment
comment|/* tape is only open for writing */
end_comment

begin_define
define|#
directive|define
name|TPSTART
value|0x0008
end_define

begin_comment
comment|/* tape must be rewound and reset */
end_comment

begin_define
define|#
directive|define
name|TPDEAD
value|0x0010
end_define

begin_comment
comment|/* tape drive does not work or driver error */
end_comment

begin_define
define|#
directive|define
name|TPSESS
value|0x0020
end_define

begin_comment
comment|/* no more reads or writes allowed in session */
end_comment

begin_comment
comment|/* for example, when tape has to be changed */
end_comment

begin_define
define|#
directive|define
name|TPSTOP
value|0x0040
end_define

begin_comment
comment|/* Stop command outstanding */
end_comment

begin_define
define|#
directive|define
name|TPREW
value|0x0080
end_define

begin_comment
comment|/* Rewind command outstanding, see wtdsl2() */
end_comment

begin_define
define|#
directive|define
name|TPVOL
value|0x0100
end_define

begin_comment
comment|/* Read file mark, or hit end of tape */
end_comment

begin_define
define|#
directive|define
name|TPWO
value|0x0200
end_define

begin_comment
comment|/* write command outstanding */
end_comment

begin_define
define|#
directive|define
name|TPRO
value|0x0400
end_define

begin_comment
comment|/* read command outstanding */
end_comment

begin_define
define|#
directive|define
name|TPWANY
value|0x0800
end_define

begin_comment
comment|/* write command requested */
end_comment

begin_define
define|#
directive|define
name|TPRANY
value|0x1000
end_define

begin_comment
comment|/* read command requested */
end_comment

begin_define
define|#
directive|define
name|TPWP
value|0x2000
end_define

begin_comment
comment|/* write protect error seen */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|wtflags
init|=
name|TPSTART
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* state of tape drive */
end_comment

begin_decl_stmt
name|struct
name|buf
name|rwtbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* header for raw i/o */
end_comment

begin_decl_stmt
name|struct
name|proc
modifier|*
name|myproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* process which opened tape driver */
end_comment

begin_decl_stmt
name|char
name|wtimeron
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* wtimer() active flag */
end_comment

begin_decl_stmt
name|char
name|wtio
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dma (i/o) active flag */
end_comment

begin_decl_stmt
name|char
name|isrlock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* isr() flag */
end_comment

begin_decl_stmt
name|struct
name|proc
modifier|*
name|Hogproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no Hogproc on Microport */
end_comment

begin_define
define|#
directive|define
name|ftoseg
parameter_list|(
name|x
parameter_list|)
value|((unsigned) (x>> 16))
end_define

begin_define
define|#
directive|define
name|seterror
parameter_list|(
name|err
parameter_list|)
value|u.u_error = err
end_define

begin_struct
struct|struct
name|wtstatus
block|{
name|ushort
name|wt_err
decl_stmt|;
comment|/* code for error encountered */
name|ushort
name|wt_ercnt
decl_stmt|;
comment|/* number of error blocks */
name|ushort
name|wt_urcnt
decl_stmt|;
comment|/* number of underruns */
block|}
name|wterror
struct|;
end_struct

begin_comment
comment|/* defines for wtstatus.wt_err */
end_comment

begin_define
define|#
directive|define
name|TP_POR
value|0x100
end_define

begin_comment
comment|/* Power on/reset occurred */
end_comment

begin_define
define|#
directive|define
name|TP_RES1
value|0x200
end_define

begin_comment
comment|/* Reserved for end of media */
end_comment

begin_define
define|#
directive|define
name|TP_RES2
value|0x400
end_define

begin_comment
comment|/* Reserved for bus parity */
end_comment

begin_define
define|#
directive|define
name|TP_BOM
value|0x800
end_define

begin_comment
comment|/* Beginning of media */
end_comment

begin_define
define|#
directive|define
name|TP_MBD
value|0x1000
end_define

begin_comment
comment|/* Marginal block detected */
end_comment

begin_define
define|#
directive|define
name|TP_NDT
value|0x2000
end_define

begin_comment
comment|/* No data detected */
end_comment

begin_define
define|#
directive|define
name|TP_ILL
value|0x4000
end_define

begin_comment
comment|/* Illegal command */
end_comment

begin_define
define|#
directive|define
name|TP_ST1
value|0x8000
end_define

begin_comment
comment|/* Status byte 1 bits */
end_comment

begin_define
define|#
directive|define
name|TP_FIL
value|0x01
end_define

begin_comment
comment|/* File mark detected */
end_comment

begin_define
define|#
directive|define
name|TP_BNL
value|0x02
end_define

begin_comment
comment|/* Bad block not located */
end_comment

begin_define
define|#
directive|define
name|TP_UDA
value|0x04
end_define

begin_comment
comment|/* Unrecoverable data error */
end_comment

begin_define
define|#
directive|define
name|TP_EOM
value|0x08
end_define

begin_comment
comment|/* End of media */
end_comment

begin_define
define|#
directive|define
name|TP_WRP
value|0x10
end_define

begin_comment
comment|/* Write protected cartridge */
end_comment

begin_define
define|#
directive|define
name|TP_USL
value|0x20
end_define

begin_comment
comment|/* Unselected drive */
end_comment

begin_define
define|#
directive|define
name|TP_CNI
value|0x40
end_define

begin_comment
comment|/* Cartridge not in place */
end_comment

begin_define
define|#
directive|define
name|TP_ST0
value|0x80
end_define

begin_comment
comment|/* Status byte 0 bits */
end_comment

begin_comment
comment|/* Grounds for reporting I/O error to user */
end_comment

begin_define
define|#
directive|define
name|TP_ERR0
value|(TP_BNL|TP_UDA|TP_WRP|TP_CNI|TP_FIL|TP_EOM|TP_USL)
end_define

begin_define
define|#
directive|define
name|TP_ERR1
value|(TP_MBD|TP_NDT|TP_ILL)
end_define

begin_comment
comment|/* TP_ILL should never happen! */
end_comment

begin_comment
comment|/* #define	TP_ERR0		0x7f #define	TP_ERR1		0x7700 */
end_comment

begin_comment
comment|/* defines for reading out status from wangtek tape controller */
end_comment

begin_define
define|#
directive|define
name|READY
value|0x01
end_define

begin_comment
comment|/* ready bit define        */
end_comment

begin_define
define|#
directive|define
name|EXCEP
value|0x02
end_define

begin_comment
comment|/* exception bit define    */
end_comment

begin_comment
comment|/* sleep priority */
end_comment

begin_define
define|#
directive|define
name|WTPRI
value|(PZERO+10)
end_define

begin_decl_stmt
name|char
name|pagebuf
index|[
name|NBPS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer of size NBPS */
end_comment

begin_decl_stmt
name|unsigned
name|long
name|pageaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical addr of pagebuf */
end_comment

begin_comment
comment|/* pageaddr is used with DMA controller */
end_comment

begin_decl_stmt
name|time_t
name|Hogtime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lbolt when Hog timer started */
end_comment

begin_decl_stmt
specifier|extern
name|time_t
name|lbolt
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|debug
value|printf
end_define

begin_comment
comment|/*  * Strategy routine.  *  * Arguments:  *  Pointer to buffer structure  * Function:  *  Start transfer.  *  * It would be nice to have this multiple-threaded.  * There is a version of dump from Berkeley that works with multiple processes  * trading off with disk& tape I/O.  */
end_comment

begin_function
name|int
name|wtstrategy
parameter_list|(
name|bp
parameter_list|)
specifier|register
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
block|{
name|unsigned
name|ucnt1
decl_stmt|,
name|ucnt2
decl_stmt|,
name|finished
decl_stmt|;
name|unsigned
name|long
name|adr1
decl_stmt|,
name|adr2
decl_stmt|;
name|adr1
operator|=
name|kvtop
argument_list|(
name|bp
operator|->
name|b_un
operator|.
name|b_addr
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"bpaddr %x\n"
argument_list|,
name|adr1
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ucnt1
operator|=
name|bp
operator|->
name|b_bcount
expr_stmt|;
name|ucnt2
operator|=
literal|0
expr_stmt|;
name|adr2
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"WTstart: adr1 %lx cnt %x\n"
argument_list|,
name|adr1
argument_list|,
name|ucnt1
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|ftoseg
argument_list|(
name|adr1
argument_list|)
operator|!=
name|ftoseg
argument_list|(
name|adr1
operator|+
operator|(
name|unsigned
operator|)
name|ucnt1
operator|-
literal|1
argument_list|)
condition|)
block|{
name|adr2
operator|=
operator|(
name|adr1
operator|&
literal|0xffff0000L
operator|)
operator|+
literal|0x10000L
expr_stmt|;
name|ucnt2
operator|=
operator|(
name|adr1
operator|+
name|ucnt1
operator|)
operator|-
name|adr2
expr_stmt|;
name|ucnt1
operator|-=
name|ucnt2
expr_stmt|;
block|}
comment|/* at file marks and end of tape, we just return '0 bytes available' */
if|if
condition|(
name|wtflags
operator|&
name|TPVOL
condition|)
block|{
name|bp
operator|->
name|b_resid
operator|=
name|bp
operator|->
name|b_bcount
expr_stmt|;
goto|goto
name|xit
goto|;
block|}
if|if
condition|(
operator|(
name|Hogproc
operator|==
operator|(
expr|struct
name|proc
operator|*
operator|)
literal|0
operator|)
operator|&&
name|TPHOG
argument_list|(
name|bp
operator|->
name|b_dev
argument_list|)
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|printf
argument_list|(
literal|"setting Hogproc\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|Hogtime
operator|=
literal|0
expr_stmt|;
name|Hogproc
operator|=
name|myproc
expr_stmt|;
block|}
if|if
condition|(
name|bp
operator|->
name|b_flags
operator|&
name|B_READ
condition|)
block|{
name|int
name|bad
init|=
literal|0
decl_stmt|;
comment|/* For now, we assume that all data will be copied out */
comment|/* If read command outstanding, just skip down */
if|if
condition|(
operator|!
operator|(
name|wtflags
operator|&
name|TPRO
operator|)
condition|)
block|{
if|if
condition|(
name|ERROR
operator|==
name|wtsense
argument_list|(
name|TP_WRP
argument_list|)
condition|)
comment|/* clear status */
goto|goto
name|errxit
goto|;
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"WTread: Start read\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
operator|(
name|wtflags
operator|&
name|TPREAD
operator|)
operator|||
operator|(
name|wtflags
operator|&
name|TPWANY
operator|)
operator|||
operator|(
name|rstart
argument_list|()
operator|==
name|ERROR
operator|)
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"Tpstart: read init error\n"
argument_list|)
expr_stmt|;
comment|/* */
endif|#
directive|endif
goto|goto
name|errxit
goto|;
block|}
name|wtflags
operator||=
name|TPRO
operator||
name|TPRANY
expr_stmt|;
block|}
name|finished
operator|=
literal|0
expr_stmt|;
comment|/* Take a deep breath */
if|if
condition|(
name|ucnt1
condition|)
block|{
if|if
condition|(
operator|(
name|rtape
argument_list|(
name|adr1
argument_list|,
name|ucnt1
argument_list|)
operator|==
name|ERROR
operator|)
operator|&&
operator|(
name|wtsense
argument_list|(
name|TP_WRP
argument_list|)
operator|==
name|ERROR
operator|)
condition|)
goto|goto
name|endio
goto|;
comment|/* wait for it */
name|bad
operator|=
name|pollrdy
argument_list|()
expr_stmt|;
name|finished
operator|=
name|bytes
expr_stmt|;
if|if
condition|(
name|bad
condition|)
goto|goto
name|endio
goto|;
block|}
comment|/* if a second I/O region, start it */
if|if
condition|(
name|ucnt2
condition|)
block|{
if|if
condition|(
operator|(
name|rtape
argument_list|(
name|adr2
argument_list|,
name|ucnt2
argument_list|)
operator|==
name|ERROR
operator|)
operator|&&
operator|(
name|wtsense
argument_list|(
name|TP_WRP
argument_list|)
operator|==
name|ERROR
operator|)
condition|)
name|ucnt2
operator|=
literal|0
expr_stmt|;
comment|/* don't poll for me */
block|}
comment|/* if second i/o pending wait for it */
if|if
condition|(
name|ucnt2
condition|)
block|{
name|pollrdy
argument_list|()
expr_stmt|;
comment|/* whether pollrdy is ok or not */
name|finished
operator|+=
name|bytes
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|wtflags
operator|&
name|TPWP
condition|)
comment|/* write protected */
goto|goto
name|errxit
goto|;
comment|/* If write command outstanding, just skip down */
if|if
condition|(
operator|!
operator|(
name|wtflags
operator|&
name|TPWO
operator|)
condition|)
block|{
if|if
condition|(
name|ERROR
operator|==
name|wtsense
argument_list|(
literal|0
argument_list|)
condition|)
comment|/* clear status */
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"TPstart: sense 0\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
goto|goto
name|errxit
goto|;
block|}
if|if
condition|(
operator|!
operator|(
name|wtflags
operator|&
name|TPWRITE
operator|)
operator|||
operator|(
name|wtflags
operator|&
name|TPRANY
operator|)
operator|||
operator|(
name|wstart
argument_list|()
operator|==
name|ERROR
operator|)
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"Tpstart: write init error\n"
argument_list|)
expr_stmt|;
comment|/* */
endif|#
directive|endif
name|wtsense
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|errxit
label|:
name|bp
operator|->
name|b_flags
operator||=
name|B_ERROR
expr_stmt|;
name|bp
operator|->
name|b_resid
operator|=
name|bp
operator|->
name|b_bcount
expr_stmt|;
goto|goto
name|xit
goto|;
block|}
name|wtflags
operator||=
name|TPWO
operator||
name|TPWANY
expr_stmt|;
block|}
comment|/* and hold your nose */
if|if
condition|(
name|ucnt1
operator|&&
operator|(
operator|(
name|wtape
argument_list|(
name|adr1
argument_list|,
name|ucnt1
argument_list|)
operator|==
name|ERROR
operator|)
operator|&&
operator|(
name|wtsense
argument_list|(
literal|0
argument_list|)
operator|==
name|ERROR
operator|)
operator|)
condition|)
name|finished
operator|=
name|bytes
expr_stmt|;
elseif|else
if|if
condition|(
name|ucnt2
operator|&&
operator|(
operator|(
operator|(
name|ucnt1
operator|&&
name|pollrdy
argument_list|()
operator|)
operator|||
operator|(
name|wtape
argument_list|(
name|adr2
argument_list|,
name|ucnt2
argument_list|)
operator|==
name|ERROR
operator|)
operator|)
operator|&&
operator|(
name|wtsense
argument_list|(
literal|0
argument_list|)
operator|==
name|ERROR
operator|)
operator|)
condition|)
name|finished
operator|=
name|ucnt1
operator|+
name|NBPS
operator|+
name|bytes
expr_stmt|;
comment|/* All writes and/or copyins were fine! */
else|else
name|finished
operator|=
name|bp
operator|->
name|b_bcount
expr_stmt|;
name|pollrdy
argument_list|()
expr_stmt|;
block|}
name|endio
label|:
name|wterror
operator|.
name|wt_err
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|exflag
operator|&&
name|wtsense
argument_list|(
operator|(
name|bp
operator|->
name|b_flags
operator|&
name|B_READ
operator|)
condition|?
name|TP_WRP
else|:
literal|0
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
name|wterror
operator|.
name|wt_err
operator|&
name|TP_ST0
operator|)
operator|&&
operator|(
name|wterror
operator|.
name|wt_err
operator|&
operator|(
name|TP_FIL
operator||
name|TP_EOM
operator|)
operator|)
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"WTsta: Hit end of tape\n"
argument_list|)
expr_stmt|;
comment|/* */
endif|#
directive|endif
name|wtflags
operator||=
name|TPVOL
expr_stmt|;
if|if
condition|(
name|wterror
operator|.
name|wt_err
operator|&
name|TP_FIL
condition|)
block|{
if|if
condition|(
name|wtflags
operator|&
name|TPRO
condition|)
comment|/* interrupter is bogus */
name|rstart
argument_list|()
expr_stmt|;
comment|/* restart read command */
else|else
name|wtflags
operator|&=
operator|~
name|TPWO
expr_stmt|;
name|finished
operator|+=
name|NBPS
expr_stmt|;
block|}
comment|/* Reading file marks or writing end of tape return 0 bytes */
block|}
else|else
block|{
name|bp
operator|->
name|b_flags
operator||=
name|B_ERROR
expr_stmt|;
name|wtflags
operator|&=
operator|~
operator|(
name|TPWO
operator||
name|TPRO
operator|)
expr_stmt|;
block|}
block|}
name|bp
operator|->
name|b_resid
operator|=
name|bp
operator|->
name|b_bcount
operator|-
name|finished
expr_stmt|;
name|xit
label|:
name|biodone
argument_list|(
name|bp
argument_list|)
expr_stmt|;
if|if
condition|(
name|wtimeron
condition|)
name|Hogtime
operator|=
name|lbolt
expr_stmt|;
elseif|else
if|if
condition|(
name|Hogproc
operator|==
name|myproc
condition|)
name|Hogproc
operator|=
operator|(
expr|struct
name|proc
operator|*
operator|)
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * simulate an interrupt periodically while I/O is going  * this is necessary in case interrupts get eaten due to  * multiple devices on a single IRQ line  */
end_comment

begin_macro
name|wtimer
argument_list|()
end_macro

begin_block
block|{
comment|/* If I/O going and not in isr(), simulate interrupt 	 * If no I/O for at least 1 second, stop being a Hog 	 * If I/O done and not a Hog, turn off wtimer() 	 */
if|if
condition|(
name|wtio
operator|&&
operator|!
name|isrlock
condition|)
name|isr
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|Hogproc
operator|==
name|myproc
operator|)
operator|&&
name|Hogtime
operator|&&
operator|(
name|lbolt
operator|-
name|Hogtime
operator|>
name|HZ
operator|)
condition|)
name|Hogproc
operator|=
operator|(
expr|struct
name|proc
operator|*
operator|)
literal|0
expr_stmt|;
if|if
condition|(
name|wtio
operator|||
operator|(
name|Hogproc
operator|==
name|myproc
operator|)
condition|)
name|timeout
argument_list|(
name|wtimer
argument_list|,
operator|(
name|caddr_t
operator|)
literal|0
argument_list|,
name|HZ
argument_list|)
expr_stmt|;
else|else
name|wtimeron
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_macro
name|wtrawio
argument_list|(
argument|bp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|wtstrategy
argument_list|(
name|bp
argument_list|)
expr_stmt|;
name|biowait
argument_list|(
name|bp
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|wt_minphys
argument_list|(
argument|bp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|bp
operator|->
name|b_bcount
operator|>
name|PAGESIZ
condition|)
name|bp
operator|->
name|b_bcount
operator|=
name|PAGESIZ
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * raw read routine  */
end_comment

begin_macro
name|wtread
argument_list|(
argument|dev
argument_list|,
argument|uio
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|uio
modifier|*
name|uio
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|wtflags
operator|&
name|TPSESS
condition|)
block|{
name|seterror
argument_list|(
name|EIO
argument_list|)
expr_stmt|;
return|return
operator|(
name|EIO
operator|)
return|;
block|}
name|physio
argument_list|(
name|wtrawio
argument_list|,
operator|&
name|rwtbuf
argument_list|,
name|dev
argument_list|,
name|B_READ
argument_list|,
name|wt_minphys
argument_list|,
name|uio
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * raw write routine  */
end_comment

begin_macro
name|wtwrite
argument_list|(
argument|dev
argument_list|,
argument|uio
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|uio
modifier|*
name|uio
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|wtflags
operator|&
name|TPSESS
condition|)
block|{
name|seterror
argument_list|(
name|EIO
argument_list|)
expr_stmt|;
return|return
operator|(
name|EIO
operator|)
return|;
block|}
name|physio
argument_list|(
name|wtrawio
argument_list|,
operator|&
name|rwtbuf
argument_list|,
name|dev
argument_list|,
name|B_WRITE
argument_list|,
name|wt_minphys
argument_list|,
name|uio
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * ioctl routine  *  for user level QIC commands only  */
end_comment

begin_macro
name|wtioctl
argument_list|(
argument|dev
argument_list|,
argument|cmd
argument_list|,
argument|arg
argument_list|,
argument|mode
argument_list|)
end_macro

begin_decl_stmt
name|int
name|dev
decl_stmt|,
name|cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|arg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|cmd
operator|==
name|WTQICMD
condition|)
block|{
if|if
condition|(
operator|(
name|qicmd
argument_list|(
operator|(
name|int
operator|)
name|arg
argument_list|)
operator|==
name|ERROR
operator|)
operator|||
operator|(
name|rdyexc
argument_list|(
name|HZ
argument_list|)
operator|==
name|ERROR
operator|)
condition|)
block|{
name|wtsense
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|seterror
argument_list|(
name|EIO
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
name|seterror
argument_list|(
name|EINVAL
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * open routine  * called on every device open  */
end_comment

begin_macro
name|wtopen
argument_list|(
argument|dev
argument_list|,
argument|flag
argument_list|)
end_macro

begin_decl_stmt
name|int
name|dev
decl_stmt|,
name|flag
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|first_wtopen_ever
condition|)
block|{
name|wtinit
argument_list|()
expr_stmt|;
name|first_wtopen_ever
operator|=
literal|0
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|DEBUG
name|printf
argument_list|(
literal|"wtopen ...\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|pageaddr
condition|)
block|{
name|nodev
argument_list|()
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
if|if
condition|(
name|wtflags
operator|&
operator|(
name|TPINUSE
operator|)
condition|)
block|{
name|seterror
argument_list|(
name|ENXIO
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
if|if
condition|(
name|wtflags
operator|&
operator|(
name|TPDEAD
operator|)
condition|)
block|{
name|seterror
argument_list|(
name|EIO
argument_list|)
expr_stmt|;
return|return
operator|(
name|EIO
operator|)
return|;
block|}
comment|/* If a rewind from the last session is going on, wait */
while|while
condition|(
name|wtflags
operator|&
name|TPREW
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"Waiting for rew to finish\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|delay
argument_list|(
literal|1000000
argument_list|)
expr_stmt|;
comment|/* delay one second */
block|}
comment|/* Only do reset and select when tape light is off, and tape is rewound. 	 * This allows multiple volumes. */
if|if
condition|(
name|wtflags
operator|&
name|TPSTART
condition|)
block|{
if|if
condition|(
name|t_reset
argument_list|()
operator|!=
name|SUCCESS
condition|)
block|{
name|nodev
argument_list|()
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"reset done. calling wtsense\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|wtsense
argument_list|(
name|TP_WRP
argument_list|)
operator|==
name|ERROR
condition|)
block|{
name|seterror
argument_list|(
name|EIO
argument_list|)
expr_stmt|;
return|return
operator|(
name|EIO
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"wtsense done\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|wtflags
operator|&=
operator|~
name|TPSTART
expr_stmt|;
block|}
name|wtflags
operator|=
name|TPINUSE
expr_stmt|;
if|if
condition|(
name|flag
operator|&
name|FREAD
condition|)
name|wtflags
operator||=
name|TPREAD
expr_stmt|;
if|if
condition|(
name|flag
operator|&
name|FWRITE
condition|)
name|wtflags
operator||=
name|TPWRITE
expr_stmt|;
name|rwtbuf
operator|.
name|b_flags
operator|=
literal|0
expr_stmt|;
name|myproc
operator|=
name|u
operator|.
name|u_procp
expr_stmt|;
comment|/* for comparison */
switch|switch
condition|(
name|TP_DENS
argument_list|(
name|dev
argument_list|)
condition|)
block|{
case|case
literal|0
case|:
name|cmds
argument_list|(
literal|0x28
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|cmds
argument_list|(
literal|0x29
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|cmds
argument_list|(
literal|0x27
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|cmds
argument_list|(
literal|0x24
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * close routine  * called on last device close  * If not rewind-on-close, leave read or write command intact.  */
end_comment

begin_macro
name|wtclose
argument_list|(
argument|dev
argument_list|)
end_macro

begin_block
block|{
name|int
name|wtdsl2
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"WTclose:\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|Hogproc
operator|==
name|myproc
condition|)
name|Hogproc
operator|=
operator|(
expr|struct
name|proc
operator|*
operator|)
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|exflag
operator|&&
operator|(
name|wtflags
operator|&
name|TPWANY
operator|)
operator|&&
operator|!
operator|(
name|wtflags
operator|&
operator|(
name|TPSESS
operator||
name|TPDEAD
operator|)
operator|)
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|wtflags
operator|&
name|TPWO
operator|)
condition|)
name|wstart
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"WT: Writing file mark\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|wmark
argument_list|()
expr_stmt|;
comment|/* write file mark */
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"WT: Wrote file mark, going to wait\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|rdyexc
argument_list|(
name|HZ
operator|/
literal|10
argument_list|)
operator|==
name|ERROR
condition|)
block|{
name|wtsense
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|TP_REWCLOSE
argument_list|(
name|dev
argument_list|)
operator|||
operator|(
name|wtflags
operator|&
operator|(
name|TPSESS
operator||
name|TPDEAD
operator|)
operator|)
condition|)
block|{
comment|/* rewind tape to beginning of tape, deselect tape, and make a note */
comment|/* don't wait until rewind, though */
comment|/* Ending read or write causes rewind to happen, if no error, 		 * and READY and EXCEPTION stay up until it finishes */
if|if
condition|(
name|wtflags
operator|&
operator|(
name|TPRO
operator||
name|TPWO
operator|)
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"End read or write\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|rdyexc
argument_list|(
name|HZ
operator|/
literal|10
argument_list|)
expr_stmt|;
name|ioend
argument_list|()
expr_stmt|;
name|wtflags
operator|&=
operator|~
operator|(
name|TPRO
operator||
name|TPWO
operator|)
expr_stmt|;
block|}
else|else
name|wtwind
argument_list|()
expr_stmt|;
name|wtflags
operator||=
name|TPSTART
operator||
name|TPREW
expr_stmt|;
name|timeout
argument_list|(
name|wtdsl2
argument_list|,
literal|0
argument_list|,
name|HZ
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
operator|(
name|wtflags
operator|&
operator|(
name|TPVOL
operator||
name|TPWANY
operator|)
operator|)
condition|)
block|{
comment|/* space forward to after next file mark no writing done */
comment|/* This allows skipping data without reading it.*/
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"Reading past file mark\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
operator|(
name|wtflags
operator|&
name|TPRO
operator|)
condition|)
name|rstart
argument_list|()
expr_stmt|;
name|rmark
argument_list|()
expr_stmt|;
if|if
condition|(
name|rdyexc
argument_list|(
name|HZ
operator|/
literal|10
argument_list|)
condition|)
block|{
name|wtsense
argument_list|(
name|TP_WRP
argument_list|)
expr_stmt|;
block|}
block|}
name|wtflags
operator|&=
name|TPREW
operator||
name|TPDEAD
operator||
name|TPSTART
operator||
name|TPRO
operator||
name|TPWO
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/* return ERROR if user I/O request should receive an I/O error code */
end_comment

begin_macro
name|wtsense
argument_list|(
argument|ignor
argument_list|)
end_macro

begin_block
block|{
name|wtflags
operator|&=
operator|~
operator|(
name|TPRO
operator||
name|TPWO
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUGx
name|debug
argument_list|(
literal|"WTsense: start "
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|rdstatus
argument_list|(
operator|&
name|wterror
argument_list|)
operator|==
name|ERROR
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"WTsense: Can't read status\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|ERROR
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|wterror
operator|.
name|wt_err
operator|&
operator|(
name|TP_ST0
operator||
name|TP_ST1
operator|)
condition|)
block|{
name|debug
argument_list|(
literal|"Tperror: status %x error %d underruns %d\n"
argument_list|,
name|wterror
operator|.
name|wt_err
argument_list|,
name|wterror
operator|.
name|wt_ercnt
argument_list|,
name|wterror
operator|.
name|wt_urcnt
argument_list|)
expr_stmt|;
block|}
else|else
name|debug
argument_list|(
literal|"done. no error\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|wterror
operator|.
name|wt_err
operator|&=
operator|~
name|ignor
expr_stmt|;
comment|/* ignore certain errors */
name|reperr
argument_list|(
name|wterror
operator|.
name|wt_err
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|wterror
operator|.
name|wt_err
operator|&
name|TP_ST0
operator|)
operator|&&
operator|(
name|wterror
operator|.
name|wt_err
operator|&
name|TP_ERR0
operator|)
operator|)
operator|||
operator|(
operator|(
name|wterror
operator|.
name|wt_err
operator|&
name|TP_ST1
operator|)
operator|&&
operator|(
name|wterror
operator|.
name|wt_err
operator|&
name|TP_ERR1
operator|)
operator|)
condition|)
return|return
name|ERROR
return|;
return|return
name|SUCCESS
return|;
block|}
end_block

begin_comment
comment|/* lifted from tdriver.c from Wangtek */
end_comment

begin_macro
name|reperr
argument_list|(
argument|srb0
argument_list|)
end_macro

begin_decl_stmt
name|int
name|srb0
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|s0
init|=
name|srb0
operator|&
operator|(
name|TP_ERR0
operator||
name|TP_ERR1
operator|)
decl_stmt|;
comment|/* find out which exception to report */
if|if
condition|(
name|s0
condition|)
block|{
if|if
condition|(
name|s0
operator|&
name|TP_USL
condition|)
name|sterr
argument_list|(
literal|"Drive not online"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|s0
operator|&
name|TP_CNI
condition|)
name|sterr
argument_list|(
literal|"No cartridge"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|s0
operator|&
name|TP_WRP
operator|)
operator|&&
operator|!
operator|(
name|wtflags
operator|&
name|TPWP
operator|)
condition|)
block|{
name|sterr
argument_list|(
literal|"Tape is write protected"
argument_list|)
expr_stmt|;
name|wtflags
operator||=
name|TPWP
expr_stmt|;
block|}
comment|/* 		if (s0& TP_FIL) 			sterr("Filemark detected"); 		*/
elseif|else
if|if
condition|(
name|s0
operator|&
name|TP_BNL
condition|)
name|sterr
argument_list|(
literal|"Block in error not located"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|s0
operator|&
name|TP_UDA
condition|)
name|sterr
argument_list|(
literal|"Unrecoverable data error"
argument_list|)
expr_stmt|;
comment|/* 		else if (s0& TP_EOM) 			sterr("End of tape"); 		*/
elseif|else
if|if
condition|(
name|s0
operator|&
name|TP_NDT
condition|)
name|sterr
argument_list|(
literal|"No data detected"
argument_list|)
expr_stmt|;
comment|/* 		if (s0& TP_POR) 			sterr("Reset occured"); 		*/
elseif|else
if|if
condition|(
name|s0
operator|&
name|TP_BOM
condition|)
name|sterr
argument_list|(
literal|"Beginning of tape"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|s0
operator|&
name|TP_ILL
condition|)
name|sterr
argument_list|(
literal|"Illegal command"
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|sterr
argument_list|(
argument|errstr
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|errstr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"Streamer: %s\n"
argument_list|,
name|errstr
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Wait until rewind finishes, and deselect drive */
end_comment

begin_macro
name|wtdsl2
argument_list|()
end_macro

begin_block
block|{
name|int
name|stat
decl_stmt|;
name|stat
operator|=
name|inb
argument_list|(
name|wtport
argument_list|)
operator|&
operator|(
name|READY
operator||
name|EXCEP
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"Timeout: Waiting for rewind to finish: stat %x\n"
argument_list|,
name|stat
argument_list|)
expr_stmt|;
endif|#
directive|endif
switch|switch
condition|(
name|stat
condition|)
block|{
comment|/* They're active low, ya'know */
case|case
name|READY
operator||
name|EXCEP
case|:
name|timeout
argument_list|(
name|wtdsl2
argument_list|,
operator|(
name|caddr_t
operator|)
literal|0
argument_list|,
name|HZ
argument_list|)
expr_stmt|;
return|return;
case|case
name|EXCEP
case|:
name|wtflags
operator|&=
operator|~
name|TPREW
expr_stmt|;
return|return;
case|case
name|READY
case|:
case|case
literal|0
case|:
name|wtflags
operator|&=
operator|~
name|TPREW
expr_stmt|;
name|sterr
argument_list|(
literal|"Rewind failed"
argument_list|)
expr_stmt|;
name|wtsense
argument_list|(
name|TP_WRP
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
end_block

begin_macro
name|wtwind
argument_list|()
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"WT: About to rewind\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|rwind
argument_list|()
expr_stmt|;
comment|/* actually start rewind */
block|}
end_block

begin_macro
name|wtintr
argument_list|(
argument|vec
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|wtflags
operator|&
operator|(
name|TPWO
operator||
name|TPRO
operator|)
condition|)
block|{
name|isrlock
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|wtio
condition|)
name|isr
argument_list|()
expr_stmt|;
name|isrlock
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|wtinit
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|wtchan
operator|<
literal|1
operator|||
name|wtchan
operator|>
literal|3
condition|)
block|{
name|sterr
argument_list|(
literal|"Bad DMA channel, cannot init driver"
argument_list|)
expr_stmt|;
return|return;
block|}
name|wtlinit
argument_list|()
expr_stmt|;
comment|/* init assembly language variables */
name|pageset
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|rdyexc
argument_list|(
argument|ticks
argument_list|)
end_macro

begin_block
block|{
name|int
name|s
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|int
name|os
init|=
literal|0xffff
decl_stmt|;
comment|/* force printout first time */
endif|#
directive|endif
for|for
control|(
init|;
condition|;
control|)
block|{
comment|/* loop until ready or exception */
name|s
operator|=
operator|(
name|inb
argument_list|(
name|wtport
argument_list|)
operator|&
literal|0xff
operator|)
expr_stmt|;
comment|/* read the status register */
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|os
operator|!=
name|s
condition|)
block|{
name|debug
argument_list|(
literal|"Status reg = %x\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|/* */
name|os
operator|=
name|s
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
operator|!
operator|(
name|s
operator|&
name|EXCEP
operator|)
condition|)
comment|/* check if exception have occured */
break|break;
if|if
condition|(
operator|!
operator|(
name|s
operator|&
name|READY
operator|)
condition|)
comment|/* check if controller is ready */
break|break;
name|s
operator|=
name|splbio
argument_list|()
expr_stmt|;
name|delay
argument_list|(
operator|(
name|ticks
operator|/
name|HZ
operator|)
operator|*
literal|1000000
argument_list|)
expr_stmt|;
comment|/* */
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"Status reg = %x on return\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|/* */
endif|#
directive|endif
return|return
operator|(
operator|(
name|s
operator|&
name|EXCEP
operator|)
condition|?
name|SUCCESS
else|:
name|ERROR
operator|)
return|;
comment|/* return exception if it occured */
block|}
end_block

begin_macro
name|pollrdy
argument_list|()
end_macro

begin_block
block|{
name|int
name|sps
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"Pollrdy\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|sps
operator|=
name|splbio
argument_list|()
expr_stmt|;
while|while
condition|(
name|wtio
condition|)
name|sleep
argument_list|(
operator|&
name|wci
argument_list|,
name|WTPRI
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|sps
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"Finish poll, wci %d exflag %d\n"
argument_list|,
name|wci
argument_list|,
name|exflag
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|exflag
return|;
block|}
end_block

begin_macro
name|wtdma
argument_list|()
end_macro

begin_comment
comment|/* start up i/o operation, called from dma() in wtlib1.s */
end_comment

begin_block
block|{
name|wtio
operator|=
literal|1
expr_stmt|;
if|if
condition|(
operator|!
name|wtimeron
condition|)
block|{
name|wtimeron
operator|=
literal|1
expr_stmt|;
name|timeout
argument_list|(
name|wtimer
argument_list|,
operator|(
name|caddr_t
operator|)
literal|0
argument_list|,
name|HZ
operator|/
literal|2
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|wtwake
argument_list|()
end_macro

begin_comment
comment|/* end i/o operation, called from isr() in wtlib1.s */
end_comment

begin_block
block|{
name|wtio
operator|=
literal|0
expr_stmt|;
name|wakeup
argument_list|(
operator|&
name|wci
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|pageset
argument_list|()
end_macro

begin_block
block|{
name|unsigned
name|long
name|pp
decl_stmt|;
name|pp
operator|=
operator|(
name|unsigned
name|long
operator|)
name|pagebuf
expr_stmt|;
name|pageaddr
operator|=
name|kvtop
argument_list|(
name|pp
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
literal|"pageset: addr %lx\n"
argument_list|,
name|pageaddr
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_define
define|#
directive|define
name|near
end_define

begin_function
specifier|static
name|near
name|sendcmd
parameter_list|()
block|{
comment|/* desired command in global mbits */
name|outb
argument_list|(
name|CTLPORT
argument_list|,
name|mbits
operator||
name|REQUEST
argument_list|)
expr_stmt|;
comment|/* set request */
while|while
condition|(
name|inb
argument_list|(
name|STATPORT
argument_list|)
operator|&
name|READY
condition|)
empty_stmt|;
comment|/* wait for ready */
name|outb
argument_list|(
name|CTLPORT
argument_list|,
name|mbits
operator|&
operator|~
name|REQUEST
argument_list|)
expr_stmt|;
comment|/* reset request */
while|while
condition|(
operator|(
name|inb
argument_list|(
name|STATPORT
argument_list|)
operator|&
name|READY
operator|)
operator|==
literal|0
condition|)
empty_stmt|;
comment|/* wait for not ready */
block|}
end_function

begin_function
specifier|static
name|near
comment|/* execute command */
name|cmds
parameter_list|(
name|cmd
parameter_list|)
block|{
specifier|register
name|s
expr_stmt|;
do|do
name|s
operator|=
name|inb
argument_list|(
name|STATPORT
argument_list|)
expr_stmt|;
do|while
condition|(
operator|(
name|s
operator|&
name|STAT
operator|)
operator|==
name|STAT
condition|)
do|;
comment|/* wait for ready */
if|if
condition|(
operator|(
name|s
operator|&
name|EXCEP
operator|)
operator|==
literal|0
condition|)
comment|/* if exception */
return|return
name|ERROR
return|;
comment|/* error */
name|outb
argument_list|(
name|CMDPORT
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
comment|/* output the command	*/
name|outb
argument_list|(
name|CTLPORT
argument_list|,
name|mbits
operator|=
name|ONLINE
argument_list|)
expr_stmt|;
comment|/* set& send ONLINE	*/
name|sendcmd
argument_list|()
expr_stmt|;
return|return
name|SUCCESS
return|;
block|}
end_function

begin_macro
name|qicmd
argument_list|(
argument|cmd
argument_list|)
end_macro

begin_block
block|{
return|return
name|cmds
argument_list|(
name|cmd
argument_list|)
return|;
block|}
end_block

begin_macro
name|rstart
argument_list|()
end_macro

begin_block
block|{
return|return
name|cmds
argument_list|(
name|RDDATA
argument_list|)
return|;
block|}
end_block

begin_macro
name|rmark
argument_list|()
end_macro

begin_block
block|{
return|return
name|cmds
argument_list|(
name|READFM
argument_list|)
return|;
block|}
end_block

begin_macro
name|wstart
argument_list|()
end_macro

begin_block
block|{
return|return
name|cmds
argument_list|(
name|WRTDATA
argument_list|)
return|;
block|}
end_block

begin_macro
name|ioend
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|s
expr_stmt|;
specifier|register
name|rval
operator|=
name|SUCCESS
expr_stmt|;
do|do
name|s
operator|=
name|inb
argument_list|(
name|STATPORT
argument_list|)
expr_stmt|;
do|while
condition|(
operator|(
name|s
operator|&
name|STAT
operator|)
operator|==
name|STAT
condition|)
do|;
comment|/* wait for ready */
if|if
condition|(
operator|(
name|s
operator|&
name|EXCEP
operator|)
operator|==
literal|0
condition|)
comment|/* if exception */
name|rval
operator|=
name|ERROR
expr_stmt|;
comment|/* error */
name|mbits
operator|&=
operator|~
name|ONLINE
expr_stmt|;
name|outb
argument_list|(
name|CTLPORT
argument_list|,
name|mbits
argument_list|)
expr_stmt|;
comment|/* reset ONLINE */
name|outb
argument_list|(
name|MASKREG
argument_list|,
name|wtchan
operator|+
literal|4
argument_list|)
expr_stmt|;
comment|/* turn off dma */
name|outb
argument_list|(
name|CLEARFF
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* reset direction flag */
return|return
name|rval
return|;
block|}
end_block

begin_macro
name|wmark
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|s
expr_stmt|;
if|if
condition|(
name|cmds
argument_list|(
name|WRITEFM
argument_list|)
operator|==
name|ERROR
condition|)
return|return
name|ERROR
return|;
do|do
name|s
operator|=
name|inb
argument_list|(
name|STATPORT
argument_list|)
expr_stmt|;
do|while
condition|(
operator|(
name|s
operator|&
name|STAT
operator|)
operator|==
name|STAT
condition|)
do|;
comment|/* wait for ready */
if|if
condition|(
operator|(
name|s
operator|&
name|EXCEP
operator|)
operator|==
literal|0
condition|)
comment|/* if exception */
return|return
name|ERROR
return|;
comment|/* error */
return|return
name|SUCCESS
return|;
block|}
end_block

begin_macro
name|rwind
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|s
expr_stmt|;
name|mbits
operator|=
name|CMDOFF
expr_stmt|;
do|do
name|s
operator|=
name|inb
argument_list|(
name|STATPORT
argument_list|)
expr_stmt|;
do|while
condition|(
operator|(
name|s
operator|&
name|STAT
operator|)
operator|==
name|STAT
condition|)
do|;
comment|/* wait for ready */
name|outb
argument_list|(
name|CMDPORT
argument_list|,
name|REWIND
argument_list|)
expr_stmt|;
name|sendcmd
argument_list|()
expr_stmt|;
return|return
name|SUCCESS
return|;
block|}
end_block

begin_macro
name|rdstatus
argument_list|(
argument|stp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|stp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to 6 byte buffer */
end_comment

begin_block
block|{
specifier|register
name|s
expr_stmt|;
name|int
name|n
decl_stmt|;
do|do
name|s
operator|=
name|inb
argument_list|(
name|STATPORT
argument_list|)
expr_stmt|;
do|while
condition|(
operator|(
name|s
operator|&
name|STAT
operator|)
operator|==
name|STAT
condition|)
do|;
comment|/* wait for ready or exception */
name|outb
argument_list|(
name|CMDPORT
argument_list|,
name|RDSTAT
argument_list|)
expr_stmt|;
name|sendcmd
argument_list|()
expr_stmt|;
comment|/* send read status command */
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
literal|6
condition|;
name|n
operator|++
control|)
block|{
ifdef|#
directive|ifdef
name|DEBUGx
name|debug
argument_list|(
literal|"rdstatus: waiting, byte %d\n"
argument_list|,
name|n
argument_list|)
expr_stmt|;
endif|#
directive|endif
do|do
name|s
operator|=
name|inb
argument_list|(
name|STATPORT
argument_list|)
expr_stmt|;
do|while
condition|(
operator|(
name|s
operator|&
name|STAT
operator|)
operator|==
name|STAT
condition|)
do|;
comment|/* wait for ready */
ifdef|#
directive|ifdef
name|DEBUGx
name|debug
argument_list|(
literal|"rdstatus: done\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|(
name|s
operator|&
name|EXCEP
operator|)
operator|==
literal|0
condition|)
comment|/* if exception */
return|return
name|ERROR
return|;
comment|/* error */
operator|*
name|stp
operator|++
operator|=
name|inb
argument_list|(
name|DATAPORT
argument_list|)
expr_stmt|;
comment|/* read status byte */
name|outb
argument_list|(
name|CTLPORT
argument_list|,
name|mbits
operator||
name|REQUEST
argument_list|)
expr_stmt|;
comment|/* set request */
ifdef|#
directive|ifdef
name|DEBUGx
name|debug
argument_list|(
literal|"rdstatus: waiting after request, byte %d\n"
argument_list|,
name|n
argument_list|)
expr_stmt|;
endif|#
directive|endif
while|while
condition|(
operator|(
name|inb
argument_list|(
name|STATPORT
argument_list|)
operator|&
name|READY
operator|)
operator|==
literal|0
condition|)
empty_stmt|;
comment|/* wait for not ready */
for|for
control|(
name|s
operator|=
literal|100
init|;
name|s
operator|>
literal|0
condition|;
name|s
operator|--
control|)
empty_stmt|;
comment|/* wait an additional time */
name|outb
argument_list|(
name|CTLPORT
argument_list|,
name|mbits
operator|&
operator|~
name|REQUEST
argument_list|)
expr_stmt|;
comment|/* unset request */
ifdef|#
directive|ifdef
name|DEBUGx
name|debug
argument_list|(
literal|"rdstatus: done\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
return|return
name|SUCCESS
return|;
block|}
end_block

begin_macro
name|t_reset
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|i
expr_stmt|;
name|mbits
operator||=
name|RESET
expr_stmt|;
name|outb
argument_list|(
name|CTLPORT
argument_list|,
name|mbits
argument_list|)
expr_stmt|;
comment|/* send reset */
name|delay
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|mbits
operator|&=
operator|~
name|RESET
expr_stmt|;
name|outb
argument_list|(
name|CTLPORT
argument_list|,
name|mbits
argument_list|)
expr_stmt|;
comment|/* turn off reset */
if|if
condition|(
operator|(
name|inb
argument_list|(
name|STATPORT
argument_list|)
operator|&
name|RESETMASK
operator|)
operator|==
name|RESETVAL
condition|)
return|return
name|SUCCESS
return|;
return|return
name|ERROR
return|;
block|}
end_block

begin_expr_stmt
specifier|static
name|dma
argument_list|()
block|{
name|int
name|x
operator|=
name|splbio
argument_list|()
block|;
name|wtdma
argument_list|()
block|;
name|outb
argument_list|(
name|CLEARFF
argument_list|,
literal|0
argument_list|)
block|;
name|outb
argument_list|(
name|MODEREG
argument_list|,
name|mode
argument_list|)
block|;
comment|/* set dma mode */
name|outb
argument_list|(
name|dmareg
argument_list|,
name|bufptr
operator|&
literal|0xFF
argument_list|)
block|;
name|outb
argument_list|(
name|dmareg
argument_list|,
operator|(
name|bufptr
operator|>>
literal|8
operator|)
operator|&
literal|0xFF
argument_list|)
block|;
name|outb
argument_list|(
name|pagereg
argument_list|,
operator|(
name|bufptr
operator|>>
literal|16
operator|)
operator|&
literal|0xFF
argument_list|)
block|;
name|outb
argument_list|(
name|dmareg
operator|+
literal|1
argument_list|,
operator|(
name|BLKSIZE
operator|-
literal|1
operator|)
operator|&
literal|0xFF
argument_list|)
block|;
name|outb
argument_list|(
name|dmareg
operator|+
literal|1
argument_list|,
operator|(
name|BLKSIZE
operator|-
literal|1
operator|)
operator|>>
literal|8
argument_list|)
block|;
name|outb
argument_list|(
name|wtport
argument_list|,
name|eqdma
operator|+
name|ONLINE
argument_list|)
block|;
name|outb
argument_list|(
name|MASKREG
argument_list|,
name|wtchan
argument_list|)
block|;
comment|/* enable command to 8237, start dma */
name|splx
argument_list|(
name|x
argument_list|)
block|; }
specifier|static
name|near
name|wtstart
argument_list|(
argument|buf
argument_list|,
argument|cnt
argument_list|)
name|long
name|buf
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|cnt
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|s
expr_stmt|;
name|bufptr
operator|=
name|buf
expr_stmt|;
comment|/* init statics */
name|numbytes
operator|=
name|cnt
expr_stmt|;
name|wci
operator|=
literal|0
expr_stmt|;
comment|/* init flags */
name|exflag
operator|=
literal|0
expr_stmt|;
name|bytes
operator|=
literal|0
expr_stmt|;
comment|/* init counter */
do|do
name|s
operator|=
name|inb
argument_list|(
name|STATPORT
argument_list|)
operator|&
name|STAT
expr_stmt|;
do|while
condition|(
name|s
operator|==
name|STAT
condition|)
do|;
comment|/* wait for ready or error */
if|if
condition|(
name|s
operator|&
name|EXCEP
condition|)
comment|/* no error */
block|{
name|dma
argument_list|()
expr_stmt|;
return|return
name|SUCCESS
return|;
block|}
return|return
name|ERROR
return|;
comment|/* error */
block|}
end_block

begin_macro
name|rtape
argument_list|(
argument|buf
argument_list|,
argument|cnt
argument_list|)
end_macro

begin_decl_stmt
name|long
name|buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical address */
end_comment

begin_decl_stmt
name|int
name|cnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of bytes */
end_comment

begin_block
block|{
name|mode
operator|=
name|dma_read
expr_stmt|;
return|return
name|wtstart
argument_list|(
name|buf
argument_list|,
name|cnt
argument_list|)
return|;
block|}
end_block

begin_macro
name|wtape
argument_list|(
argument|buf
argument_list|,
argument|cnt
argument_list|)
end_macro

begin_decl_stmt
name|long
name|buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical address */
end_comment

begin_decl_stmt
name|int
name|cnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of bytes */
end_comment

begin_block
block|{
name|mode
operator|=
name|dma_write
expr_stmt|;
return|return
name|wtstart
argument_list|(
name|buf
argument_list|,
name|cnt
argument_list|)
return|;
block|}
end_block

begin_macro
name|isr
argument_list|()
end_macro

begin_block
block|{
name|int
name|stat
init|=
name|inb
argument_list|(
name|wtport
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|stat
operator|&
name|EXCEP
operator|)
condition|)
comment|/* exception during I/O */
block|{
if|if
condition|(
name|bytes
operator|+
name|BLKSIZE
operator|>=
name|numbytes
condition|)
name|wci
operator|=
literal|1
expr_stmt|;
name|exflag
operator|=
literal|1
expr_stmt|;
goto|goto
name|isrwake
goto|;
block|}
if|if
condition|(
operator|(
name|stat
operator|&
name|READY
operator|)
operator|||
operator|!
operator|(
name|inb
argument_list|(
name|STATUSREG
argument_list|)
operator|&
name|dma_done
operator|)
condition|)
return|return;
name|exflag
operator|=
literal|0
expr_stmt|;
name|outb
argument_list|(
name|wtport
argument_list|,
name|ONLINE
argument_list|)
expr_stmt|;
name|bytes
operator|+=
name|BLKSIZE
expr_stmt|;
if|if
condition|(
name|bytes
operator|>=
name|numbytes
condition|)
comment|/* normal completion of I/O */
block|{
name|wci
operator|=
literal|1
expr_stmt|;
name|isrwake
label|:
name|outb
argument_list|(
name|MASKREG
argument_list|,
literal|4
operator|+
name|wtchan
argument_list|)
expr_stmt|;
comment|/* turn off dma */
name|wtwake
argument_list|()
expr_stmt|;
comment|/* wake up user level */
block|}
else|else
block|{
comment|/* continue I/O */
name|bufptr
operator|+=
name|BLKSIZE
expr_stmt|;
name|dma
argument_list|()
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|wtlinit
argument_list|()
end_macro

begin_block
block|{
switch|switch
condition|(
name|wtchan
condition|)
block|{
case|case
literal|1
case|:
return|return;
case|case
literal|2
case|:
name|pagereg
operator|=
literal|0x81
expr_stmt|;
name|dma_done
operator|=
literal|4
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|eqdma
operator|=
literal|0x10
expr_stmt|;
name|pagereg
operator|=
literal|0x82
expr_stmt|;
name|dma_done
operator|=
literal|8
expr_stmt|;
break|break;
block|}
name|dma_write
operator|=
name|wtchan
operator|+
literal|0x48
expr_stmt|;
name|dma_read
operator|=
name|wtchan
operator|+
literal|0x44
expr_stmt|;
name|dmareg
operator|=
name|wtchan
operator|+
name|wtchan
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * delay i microseconds  */
end_comment

begin_expr_stmt
name|delay
argument_list|(
name|i
argument_list|)
specifier|register
name|int
name|i
expr_stmt|;
end_expr_stmt

begin_block
block|{
while|while
condition|(
name|i
operator|--
operator|>
literal|0
condition|)
name|DELAY
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|wtsize
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|wtdump
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_include
include|#
directive|include
file|"machine/isa/isa_device.h"
end_include

begin_include
include|#
directive|include
file|"machine/isa/icu.h"
end_include

begin_decl_stmt
name|int
name|wtprobe
argument_list|()
decl_stmt|,
name|wtattach
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|isa_driver
name|wtdriver
init|=
block|{
name|wtprobe
block|,
name|wtattach
block|,
literal|"wt"
block|, }
decl_stmt|;
end_decl_stmt

begin_macro
name|wtprobe
argument_list|(
argument|dvp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|isa_device
modifier|*
name|dvp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|val
decl_stmt|,
name|i
decl_stmt|,
name|s
decl_stmt|;
ifdef|#
directive|ifdef
name|lint
name|wtintr
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|wtport
operator|=
name|dvp
operator|->
name|id_iobase
expr_stmt|;
if|if
condition|(
name|t_reset
argument_list|()
operator|!=
name|SUCCESS
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_macro
name|wtattach
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_endif
endif|#
directive|endif
endif|NWT
end_endif

end_unit

