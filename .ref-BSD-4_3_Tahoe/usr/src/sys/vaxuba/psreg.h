begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)psreg.h	7.2 (Berkeley) 12/22/87  */
end_comment

begin_comment
comment|/*  *	The Real Nitty Gritty Device Registers  */
end_comment

begin_struct
struct|struct
name|psdevice
block|{
name|short
name|int
name|ps_data
decl_stmt|;
comment|/* data register */
name|short
name|int
name|ps_addr
decl_stmt|;
comment|/* address register */
name|short
name|int
name|ps_wcount
decl_stmt|;
comment|/* word count register */
name|short
name|int
name|ps_busaddr
decl_stmt|;
comment|/* unibus address register */
name|short
name|int
name|ps_iostat
decl_stmt|;
comment|/* io status register */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Possible ioctl's  */
end_comment

begin_define
define|#
directive|define
name|PSIOAUTOREFRESH
value|_IO('p', 0)
end_define

begin_comment
comment|/* auto refresh */
end_comment

begin_define
define|#
directive|define
name|PSIOSINGLEREFRESH
value|_IO('p', 1)
end_define

begin_comment
comment|/* single refresh */
end_comment

begin_define
define|#
directive|define
name|PSIOAUTOMAP
value|_IO('p', 2)
end_define

begin_comment
comment|/* auto map */
end_comment

begin_define
define|#
directive|define
name|PSIOSINGLEMAP
value|_IO('p', 3)
end_define

begin_comment
comment|/* single map */
end_comment

begin_define
define|#
directive|define
name|PSIODOUBLEBUFFER
value|_IO('p', 4)
end_define

begin_comment
comment|/* double buffer */
end_comment

begin_define
define|#
directive|define
name|PSIOSINGLEBUFFER
value|_IO('p', 5)
end_define

begin_comment
comment|/* single buffer */
end_comment

begin_define
define|#
directive|define
name|PSIOWAITREFRESH
value|_IO('p', 6)
end_define

begin_comment
comment|/* await refresh */
end_comment

begin_define
define|#
directive|define
name|PSIOWAITMAP
value|_IO('p', 7)
end_define

begin_comment
comment|/* await map */
end_comment

begin_define
define|#
directive|define
name|PSIOWAITHIT
value|_IO('p', 8)
end_define

begin_comment
comment|/* await hit */
end_comment

begin_define
define|#
directive|define
name|PSIOSTOPREFRESH
value|_IO('p', 9)
end_define

begin_comment
comment|/* stop refresh */
end_comment

begin_define
define|#
directive|define
name|PSIOSTOPMAP
value|_IO('p',10)
end_define

begin_comment
comment|/* stop map */
end_comment

begin_define
define|#
directive|define
name|PSIOGETADDR
value|_IOR('p',11, int)
end_define

begin_comment
comment|/* get Unibus address */
end_comment

begin_define
define|#
directive|define
name|PSIOTIMEREFRESH
value|_IO('p',12)
end_define

begin_comment
comment|/* time refresh */
end_comment

begin_comment
comment|/*  *	Picture system io status register bits  */
end_comment

begin_define
define|#
directive|define
name|DIOREADY
value|0100000
end_define

begin_define
define|#
directive|define
name|PSAHOLD
value|040000
end_define

begin_define
define|#
directive|define
name|PSRESET
value|020000
end_define

begin_define
define|#
directive|define
name|DIORESET
value|010000
end_define

begin_define
define|#
directive|define
name|DMARESET
value|04000
end_define

begin_define
define|#
directive|define
name|PSIE
value|0400
end_define

begin_define
define|#
directive|define
name|DMAREADY
value|0200
end_define

begin_define
define|#
directive|define
name|DMAIE
value|0100
end_define

begin_define
define|#
directive|define
name|PASSIVE
value|010
end_define

begin_define
define|#
directive|define
name|DMAIN
value|04
end_define

begin_define
define|#
directive|define
name|NEXEM
value|02
end_define

begin_define
define|#
directive|define
name|GO
value|01
end_define

begin_comment
comment|/*  *	Picture system memory mapping control registers: SCB 0177400-0177410  */
end_comment

begin_define
define|#
directive|define
name|EXMMR_DMA
value|0177400
end_define

begin_define
define|#
directive|define
name|EXMMR_DIO
value|0177404
end_define

begin_define
define|#
directive|define
name|EXMMR_RC
value|0177405
end_define

begin_define
define|#
directive|define
name|EXMMR_MAPOUT
value|0177406
end_define

begin_define
define|#
directive|define
name|EXMMR_MAPIN
value|0177407
end_define

begin_define
define|#
directive|define
name|EXMSR
value|0177410
end_define

begin_comment
comment|/*  *	Extended memory status register bits  */
end_comment

begin_define
define|#
directive|define
name|DBERROR
value|0100000
end_define

begin_define
define|#
directive|define
name|SBERROR
value|040000
end_define

begin_define
define|#
directive|define
name|MEMREADY
value|0200
end_define

begin_define
define|#
directive|define
name|DBIE
value|0100
end_define

begin_define
define|#
directive|define
name|MMENBL
value|02
end_define

begin_define
define|#
directive|define
name|INITMEM
value|01
end_define

begin_comment
comment|/*  *	Size of extended memory  */
end_comment

begin_define
define|#
directive|define
name|NEXMPAGES
value|(256*2)
end_define

begin_define
define|#
directive|define
name|WORDSPERPAGE
value|(256)
end_define

begin_comment
comment|/*  *	MAP picture processor registers: SCB 0177750-0177753  */
end_comment

begin_define
define|#
directive|define
name|MAOL
value|0177750
end_define

begin_define
define|#
directive|define
name|MAOA
value|0177751
end_define

begin_define
define|#
directive|define
name|MAIA
value|0177752
end_define

begin_define
define|#
directive|define
name|MASR
value|0177753
end_define

begin_define
define|#
directive|define
name|MAMSR
value|0177754
end_define

begin_comment
comment|/*  *	MAP status register bits  */
end_comment

begin_define
define|#
directive|define
name|PPDONE
value|0100000
end_define

begin_define
define|#
directive|define
name|FIFOFULL
value|040000
end_define

begin_define
define|#
directive|define
name|FIFOEMPTY
value|020000
end_define

begin_define
define|#
directive|define
name|HIT
value|010000
end_define

begin_define
define|#
directive|define
name|IB
value|04000
end_define

begin_define
define|#
directive|define
name|TAKE
value|02000
end_define

begin_define
define|#
directive|define
name|MMODE
value|01400
end_define

begin_define
define|#
directive|define
name|MOSTOPPED
value|0200
end_define

begin_define
define|#
directive|define
name|IOUT
value|0100
end_define

begin_define
define|#
directive|define
name|MAO
value|040
end_define

begin_define
define|#
directive|define
name|MAI
value|020
end_define

begin_define
define|#
directive|define
name|HIT_HOLD
value|010
end_define

begin_define
define|#
directive|define
name|RSR_HOLD
value|04
end_define

begin_define
define|#
directive|define
name|VEC_HOLD
value|02
end_define

begin_define
define|#
directive|define
name|MAP_RESET
value|01
end_define

begin_comment
comment|/*  *	Refresh controller registers: SCB 0177730-0177737  */
end_comment

begin_define
define|#
directive|define
name|RFCSN
value|0177730
end_define

begin_define
define|#
directive|define
name|RFSN
value|0177731
end_define

begin_define
define|#
directive|define
name|RFAWA
value|0177732
end_define

begin_define
define|#
directive|define
name|RFAWL
value|0177733
end_define

begin_define
define|#
directive|define
name|RFAIA
value|0177734
end_define

begin_define
define|#
directive|define
name|RFASA
value|0177735
end_define

begin_define
define|#
directive|define
name|RFAIL
value|0177736
end_define

begin_define
define|#
directive|define
name|RFSR
value|0177737
end_define

begin_comment
comment|/*  *	Refresh controller status register bits  */
end_comment

begin_define
define|#
directive|define
name|RFSTOPPED
value|0100000
end_define

begin_define
define|#
directive|define
name|RFHOLD
value|040000
end_define

begin_define
define|#
directive|define
name|RFSTART
value|020000
end_define

begin_define
define|#
directive|define
name|AUTOREF
value|010000
end_define

begin_define
define|#
directive|define
name|RFBLANK
value|04000
end_define

begin_define
define|#
directive|define
name|RIGHT
value|02000
end_define

begin_define
define|#
directive|define
name|LGFIFO_FULL
value|01000
end_define

begin_define
define|#
directive|define
name|NOT_EXEC
value|0200
end_define

begin_define
define|#
directive|define
name|SKIPSEG
value|0100
end_define

begin_define
define|#
directive|define
name|WRITEBACK
value|040
end_define

begin_define
define|#
directive|define
name|SEARCH
value|020
end_define

begin_define
define|#
directive|define
name|MATCH_HOLD
value|010
end_define

begin_define
define|#
directive|define
name|MATCH_DEC
value|04
end_define

begin_define
define|#
directive|define
name|SEARCH_MODE
value|03
end_define

begin_comment
comment|/*  *	Interrupt control  */
end_comment

begin_define
define|#
directive|define
name|RTCREQ
value|0177760
end_define

begin_define
define|#
directive|define
name|RTCIE
value|0177761
end_define

begin_define
define|#
directive|define
name|SYSREQ
value|0177762
end_define

begin_define
define|#
directive|define
name|SYSIE
value|0177763
end_define

begin_define
define|#
directive|define
name|DEVREQ
value|0177764
end_define

begin_define
define|#
directive|define
name|DEVIE
value|0177765
end_define

begin_comment
comment|/*  *	System interrupt request bits  */
end_comment

begin_define
define|#
directive|define
name|LPEN_REQ
value|0200
end_define

begin_define
define|#
directive|define
name|MATCH_REQ
value|0100
end_define

begin_define
define|#
directive|define
name|WBSTOP_REQ
value|040
end_define

begin_define
define|#
directive|define
name|RFSTOP_REQ
value|020
end_define

begin_define
define|#
directive|define
name|MOSTOP_REQ
value|010
end_define

begin_define
define|#
directive|define
name|JUMP_REQ
value|04
end_define

begin_define
define|#
directive|define
name|HIT_REQ
value|02
end_define

begin_define
define|#
directive|define
name|HALT_REQ
value|01
end_define

begin_comment
comment|/*  *	Real-Time Clock registers  */
end_comment

begin_define
define|#
directive|define
name|RTCCNT
value|0177744
end_define

begin_define
define|#
directive|define
name|RTCSR
value|0177745
end_define

begin_comment
comment|/*  *	Real-Time Clock status register bits  */
end_comment

begin_define
define|#
directive|define
name|HZ120
value|040
end_define

begin_define
define|#
directive|define
name|EXT
value|020
end_define

begin_define
define|#
directive|define
name|SYNC
value|010
end_define

begin_define
define|#
directive|define
name|EXTSEL2
value|04
end_define

begin_define
define|#
directive|define
name|EXTSEL1
value|02
end_define

begin_define
define|#
directive|define
name|RUN
value|01
end_define

begin_comment
comment|/*  *	Control dials a/d registers  */
end_comment

begin_define
define|#
directive|define
name|ADDR0
value|0177500
end_define

begin_define
define|#
directive|define
name|ADDR1
value|0177501
end_define

begin_define
define|#
directive|define
name|ADDR2
value|0177502
end_define

begin_define
define|#
directive|define
name|ADDR3
value|0177503
end_define

begin_define
define|#
directive|define
name|ADDR4
value|0177504
end_define

begin_define
define|#
directive|define
name|ADDR5
value|0177505
end_define

begin_define
define|#
directive|define
name|ADDR6
value|0177506
end_define

begin_define
define|#
directive|define
name|ADDR7
value|0177507
end_define

begin_comment
comment|/*  *	Function switches and lights  */
end_comment

begin_define
define|#
directive|define
name|FSWR
value|0177626
end_define

begin_define
define|#
directive|define
name|FSLR
value|0177627
end_define

end_unit

