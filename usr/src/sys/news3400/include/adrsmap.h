begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: adrsmap.h,v 4.300 91/06/09 06:34:29 root Rel41 $ SONY  *  *	@(#)adrsmap.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * adrsmap.h  *  * Define all hardware address map.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ADRSMAP__
end_ifndef

begin_define
define|#
directive|define
name|__ADRSMAP__
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|news3400
end_ifdef

begin_comment
comment|/*----------------------------------------------------------------------  *	news3400  *----------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*  * timer  */
end_comment

begin_define
define|#
directive|define
name|RTC_PORT
value|0xbff407f8
end_define

begin_define
define|#
directive|define
name|DATA_PORT
value|0xbff407f9
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_define
define|#
directive|define
name|EN_ITIMER
value|0xb8000004
end_define

begin_comment
comment|/*XXX:???*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INTEN0
value|0xbfc80000
end_define

begin_define
define|#
directive|define
name|INTEN0_PERR
value|0x80
end_define

begin_define
define|#
directive|define
name|INTEN0_ABORT
value|0x40
end_define

begin_define
define|#
directive|define
name|INTEN0_BERR
value|0x20
end_define

begin_define
define|#
directive|define
name|INTEN0_TIMINT
value|0x10
end_define

begin_define
define|#
directive|define
name|INTEN0_KBDINT
value|0x08
end_define

begin_define
define|#
directive|define
name|INTEN0_MSINT
value|0x04
end_define

begin_define
define|#
directive|define
name|INTEN0_CFLT
value|0x02
end_define

begin_define
define|#
directive|define
name|INTEN0_CBSY
value|0x01
end_define

begin_define
define|#
directive|define
name|INTEN1
value|0xbfc80001
end_define

begin_define
define|#
directive|define
name|INTEN1_BEEP
value|0x80
end_define

begin_define
define|#
directive|define
name|INTEN1_SCC
value|0x40
end_define

begin_define
define|#
directive|define
name|INTEN1_LANCE
value|0x20
end_define

begin_define
define|#
directive|define
name|INTEN1_DMA
value|0x10
end_define

begin_define
define|#
directive|define
name|INTEN1_SLOT1
value|0x08
end_define

begin_define
define|#
directive|define
name|INTEN1_SLOT3
value|0x04
end_define

begin_define
define|#
directive|define
name|INTEN1_EXT1
value|0x02
end_define

begin_define
define|#
directive|define
name|INTEN1_EXT3
value|0x01
end_define

begin_define
define|#
directive|define
name|INTST0
value|0xbfc80002
end_define

begin_define
define|#
directive|define
name|INTST0_PERR
value|0x80
end_define

begin_define
define|#
directive|define
name|INTST0_ABORT
value|0x40
end_define

begin_define
define|#
directive|define
name|INTST0_BERR
value|0x00
end_define

begin_comment
comment|/* N/A */
end_comment

begin_define
define|#
directive|define
name|INTST0_TIMINT
value|0x10
end_define

begin_define
define|#
directive|define
name|INTST0_KBDINT
value|0x08
end_define

begin_define
define|#
directive|define
name|INTST0_MSINT
value|0x04
end_define

begin_define
define|#
directive|define
name|INTST0_CFLT
value|0x02
end_define

begin_define
define|#
directive|define
name|INTST0_CBSY
value|0x01
end_define

begin_define
define|#
directive|define
name|INTST0_PERR_BIT
value|7
end_define

begin_define
define|#
directive|define
name|INTST0_ABORT_BIT
value|6
end_define

begin_define
define|#
directive|define
name|INTST0_BERR_BIT
value|5
end_define

begin_comment
comment|/* N/A */
end_comment

begin_define
define|#
directive|define
name|INTST0_TIMINT_BIT
value|4
end_define

begin_define
define|#
directive|define
name|INTST0_KBDINT_BIT
value|3
end_define

begin_define
define|#
directive|define
name|INTST0_MSINT_BIT
value|2
end_define

begin_define
define|#
directive|define
name|INTST0_CFLT_BIT
value|1
end_define

begin_define
define|#
directive|define
name|INTST0_CBSY_BIT
value|0
end_define

begin_define
define|#
directive|define
name|INTST1
value|0xbfc80003
end_define

begin_define
define|#
directive|define
name|INTST1_BEEP
value|0x80
end_define

begin_define
define|#
directive|define
name|INTST1_SCC
value|0x40
end_define

begin_define
define|#
directive|define
name|INTST1_LANCE
value|0x20
end_define

begin_define
define|#
directive|define
name|INTST1_DMA
value|0x10
end_define

begin_define
define|#
directive|define
name|INTST1_SLOT1
value|0x08
end_define

begin_define
define|#
directive|define
name|INTST1_SLOT3
value|0x04
end_define

begin_define
define|#
directive|define
name|INTST1_EXT1
value|0x02
end_define

begin_define
define|#
directive|define
name|INTST1_EXT3
value|0x01
end_define

begin_define
define|#
directive|define
name|INTST1_BEEP_BIT
value|7
end_define

begin_define
define|#
directive|define
name|INTST1_SCC_BIT
value|6
end_define

begin_define
define|#
directive|define
name|INTST1_LANCE_BIT
value|5
end_define

begin_define
define|#
directive|define
name|INTST1_DMA_BIT
value|4
end_define

begin_define
define|#
directive|define
name|INTST1_SLOT1_BIT
value|3
end_define

begin_define
define|#
directive|define
name|INTST1_SLOT3_BIT
value|2
end_define

begin_define
define|#
directive|define
name|INTST1_EXT1_BIT
value|1
end_define

begin_define
define|#
directive|define
name|INTST1_EXT3_BIT
value|0
end_define

begin_define
define|#
directive|define
name|INTCLR0
value|0xbfc80004
end_define

begin_define
define|#
directive|define
name|INTCLR0_PERR
value|0x80
end_define

begin_define
define|#
directive|define
name|INTCLR0_ABORT
value|0x40
end_define

begin_define
define|#
directive|define
name|INTCLR0_BERR
value|0x20
end_define

begin_define
define|#
directive|define
name|INTCLR0_TIMINT
value|0x10
end_define

begin_define
define|#
directive|define
name|INTCLR0_KBDINT
value|0x00
end_define

begin_comment
comment|/* N/A */
end_comment

begin_define
define|#
directive|define
name|INTCLR0_MSINT
value|0x00
end_define

begin_comment
comment|/* N/A */
end_comment

begin_define
define|#
directive|define
name|INTCLR0_CFLT
value|0x02
end_define

begin_define
define|#
directive|define
name|INTCLR0_CBSY
value|0x01
end_define

begin_define
define|#
directive|define
name|INTCLR1
value|0xbfc80005
end_define

begin_define
define|#
directive|define
name|INTCLR1_BEEP
value|0x80
end_define

begin_define
define|#
directive|define
name|INTCLR1_SCC
value|0x00
end_define

begin_comment
comment|/* N/A */
end_comment

begin_define
define|#
directive|define
name|INTCLR1_LANCE
value|0x00
end_define

begin_comment
comment|/* N/A */
end_comment

begin_define
define|#
directive|define
name|INTCLR1_DMA
value|0x00
end_define

begin_comment
comment|/* N/A */
end_comment

begin_define
define|#
directive|define
name|INTCLR1_SLOT1
value|0x00
end_define

begin_comment
comment|/* N/A */
end_comment

begin_define
define|#
directive|define
name|INTCLR1_SLOT3
value|0x00
end_define

begin_comment
comment|/* N/A */
end_comment

begin_define
define|#
directive|define
name|INTCLR1_EXT1
value|0x00
end_define

begin_comment
comment|/* N/A */
end_comment

begin_define
define|#
directive|define
name|INTCLR1_EXT3
value|0x00
end_define

begin_comment
comment|/* N/A */
end_comment

begin_define
define|#
directive|define
name|ITIMER
value|0xbfc80006
end_define

begin_define
define|#
directive|define
name|IOCLOCK
value|4915200
end_define

begin_define
define|#
directive|define
name|DIP_SWITCH
value|0xbfe40000
end_define

begin_define
define|#
directive|define
name|IDROM
value|0xbfe80000
end_define

begin_define
define|#
directive|define
name|DEBUG_PORT
value|0xbfcc0003
end_define

begin_define
define|#
directive|define
name|DP_READ
value|0x00
end_define

begin_define
define|#
directive|define
name|DP_WRITE
value|0xf0
end_define

begin_define
define|#
directive|define
name|DP_LED0
value|0x01
end_define

begin_define
define|#
directive|define
name|DP_LED1
value|0x02
end_define

begin_define
define|#
directive|define
name|DP_LED2
value|0x04
end_define

begin_define
define|#
directive|define
name|DP_LED3
value|0x08
end_define

begin_define
define|#
directive|define
name|LANCE_PORT
value|0xbff80000
end_define

begin_define
define|#
directive|define
name|LANCE_MEMORY
value|0xbffc0000
end_define

begin_define
define|#
directive|define
name|ETHER_ID
value|IDROM_PORT
end_define

begin_define
define|#
directive|define
name|LANCE_PORT1
value|0xb8c30000
end_define

begin_comment
comment|/* expansion lance #1 */
end_comment

begin_define
define|#
directive|define
name|LANCE_MEMORY1
value|0xb8c20000
end_define

begin_define
define|#
directive|define
name|ETHER_ID1
value|0xb8c38000
end_define

begin_define
define|#
directive|define
name|LANCE_PORT2
value|0xb8c70000
end_define

begin_comment
comment|/* expansion lance #2 */
end_comment

begin_define
define|#
directive|define
name|LANCE_MEMORY2
value|0xb8c60000
end_define

begin_define
define|#
directive|define
name|ETHER_ID2
value|0xb8c78000
end_define

begin_define
define|#
directive|define
name|IDROM_PORT
value|0xbfe80000
end_define

begin_define
define|#
directive|define
name|SCCPORT0B
value|0xbfec0000
end_define

begin_define
define|#
directive|define
name|SCCPORT0A
value|0xbfec0002
end_define

begin_define
define|#
directive|define
name|SCCPORT1B
value|0xb8c40100
end_define

begin_define
define|#
directive|define
name|SCCPORT1A
value|0xb8c40102
end_define

begin_define
define|#
directive|define
name|SCCPORT2B
value|0xb8c40104
end_define

begin_define
define|#
directive|define
name|SCCPORT2A
value|0xb8c40106
end_define

begin_define
define|#
directive|define
name|SCCPORT3B
value|0xb8c40110
end_define

begin_define
define|#
directive|define
name|SCCPORT3A
value|0xb8c40112
end_define

begin_define
define|#
directive|define
name|SCCPORT4B
value|0xb8c40114
end_define

begin_define
define|#
directive|define
name|SCCPORT4A
value|0xb8c40116
end_define

begin_define
define|#
directive|define
name|SCC_STATUS0
value|0xbfcc0002
end_define

begin_define
define|#
directive|define
name|SCC_STATUS1
value|0xb8c40108
end_define

begin_define
define|#
directive|define
name|SCC_STATUS2
value|0xb8c40118
end_define

begin_define
define|#
directive|define
name|SCCVECT
value|(0x1fcc0007 | MACH_UNCACHED_MEMORY_ADDR)
end_define

begin_define
define|#
directive|define
name|SCC_RECV
value|2
end_define

begin_define
define|#
directive|define
name|SCC_XMIT
value|0
end_define

begin_define
define|#
directive|define
name|SCC_CTRL
value|3
end_define

begin_define
define|#
directive|define
name|SCC_STAT
value|1
end_define

begin_define
define|#
directive|define
name|SCC_INT_MASK
value|0x6
end_define

begin_comment
comment|/*XXX: SHOULD BE FIX*/
end_comment

begin_define
define|#
directive|define
name|KEYB_DATA
value|0xbfd00000
end_define

begin_comment
comment|/* keyboard data port */
end_comment

begin_define
define|#
directive|define
name|KEYB_STAT
value|0xbfd00001
end_define

begin_comment
comment|/* keyboard status port */
end_comment

begin_define
define|#
directive|define
name|KEYB_INTE
value|INTEN0
end_define

begin_comment
comment|/* keyboard interrupt enable */
end_comment

begin_define
define|#
directive|define
name|KEYB_RESET
value|0xbfd00002
end_define

begin_comment
comment|/* keyboard reset port*/
end_comment

begin_define
define|#
directive|define
name|KEYB_INIT1
value|0xbfd00003
end_define

begin_comment
comment|/* keyboard speed */
end_comment

begin_define
define|#
directive|define
name|KEYB_INIT2
value|KEYB_INIT1
end_define

begin_comment
comment|/* keyboard clock */
end_comment

begin_define
define|#
directive|define
name|KEYB_BUZZ
value|0xbfd40001
end_define

begin_comment
comment|/* keyboard buzzer (length) */
end_comment

begin_define
define|#
directive|define
name|KEYB_BUZZF
value|0xbfd40000
end_define

begin_comment
comment|/* keyboard buzzer frequency */
end_comment

begin_define
define|#
directive|define
name|MOUSE_DATA
value|0xbfd00004
end_define

begin_comment
comment|/* mouse data port */
end_comment

begin_define
define|#
directive|define
name|MOUSE_STAT
value|0xbfd00005
end_define

begin_comment
comment|/* mouse status port */
end_comment

begin_define
define|#
directive|define
name|MOUSE_INTE
value|INTEN0
end_define

begin_comment
comment|/* mouse interrupt enable */
end_comment

begin_define
define|#
directive|define
name|MOUSE_RESET
value|0xbfd00006
end_define

begin_comment
comment|/* mouse reset port */
end_comment

begin_define
define|#
directive|define
name|MOUSE_INIT1
value|0xbfd00007
end_define

begin_comment
comment|/* mouse speed */
end_comment

begin_define
define|#
directive|define
name|MOUSE_INIT2
value|MOUSE_INIT1
end_define

begin_comment
comment|/* mouse clock */
end_comment

begin_define
define|#
directive|define
name|RX_MSINTE
value|0x04
end_define

begin_comment
comment|/* Mouse Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|RX_KBINTE
value|0x08
end_define

begin_comment
comment|/* Keyboard Intr. Enable */
end_comment

begin_define
define|#
directive|define
name|RX_MSINT
value|0x04
end_define

begin_comment
comment|/* Mouse Interrupted */
end_comment

begin_define
define|#
directive|define
name|RX_KBINT
value|0x08
end_define

begin_comment
comment|/* Keyboard Interrupted */
end_comment

begin_define
define|#
directive|define
name|RX_MSBUF
value|0x01
end_define

begin_comment
comment|/* Mouse data buffer Full */
end_comment

begin_define
define|#
directive|define
name|RX_KBBUF
value|0x01
end_define

begin_comment
comment|/* Keyboard data Full */
end_comment

begin_define
define|#
directive|define
name|RX_MSRDY
value|0x02
end_define

begin_comment
comment|/* Mouse data ready */
end_comment

begin_define
define|#
directive|define
name|RX_KBRDY
value|0x02
end_define

begin_comment
comment|/* Keyboard data ready */
end_comment

begin_comment
comment|/*XXX: SHOULD BE FIX*/
end_comment

begin_define
define|#
directive|define
name|ABEINT_BADDR
value|0xbfdc0038
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* news3400 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__ADRSMAP__ */
end_comment

end_unit

