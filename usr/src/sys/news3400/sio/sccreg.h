begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: sccreg.h,v 4.300 91/06/09 06:44:58 root Rel41 $ SONY  *  *	@(#)sccreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCCREG_
end_ifndef

begin_define
define|#
directive|define
name|_SCCREG_
end_define

begin_comment
comment|/*  *	SCC register  */
end_comment

begin_struct
struct|struct
name|scc_reg
block|{
name|u_char
name|ctrl
decl_stmt|;
comment|/* control register	*/
name|u_char
name|data
decl_stmt|;
comment|/* data    register	*/
block|}
struct|;
end_struct

begin_comment
comment|/*  *	SCC read register  */
end_comment

begin_define
define|#
directive|define
name|RR0
value|0
end_define

begin_define
define|#
directive|define
name|RR1
value|1
end_define

begin_define
define|#
directive|define
name|RR2
value|2
end_define

begin_define
define|#
directive|define
name|RR3
value|3
end_define

begin_define
define|#
directive|define
name|RR10
value|10
end_define

begin_define
define|#
directive|define
name|RR12
value|12
end_define

begin_define
define|#
directive|define
name|RR13
value|13
end_define

begin_define
define|#
directive|define
name|RR15
value|15
end_define

begin_define
define|#
directive|define
name|R0_BREAK
value|0x80
end_define

begin_comment
comment|/* Break/Abort		*/
end_comment

begin_define
define|#
directive|define
name|R0_UDRUN
value|0x40
end_define

begin_comment
comment|/* Tx Underrun/EOM	*/
end_comment

begin_define
define|#
directive|define
name|R0_CTS
value|0x20
end_define

begin_comment
comment|/* CTS			*/
end_comment

begin_define
define|#
directive|define
name|R0_SYNC
value|0x10
end_define

begin_comment
comment|/* Sync/Hunt		*/
end_comment

begin_define
define|#
directive|define
name|R0_DCD
value|0x08
end_define

begin_comment
comment|/* DCD			*/
end_comment

begin_define
define|#
directive|define
name|R0_TxBE
value|0x04
end_define

begin_comment
comment|/* Tx buffer empty	*/
end_comment

begin_define
define|#
directive|define
name|R0_ZERO
value|0x02
end_define

begin_comment
comment|/* Zero count		*/
end_comment

begin_define
define|#
directive|define
name|R0_RxCA
value|0x01
end_define

begin_comment
comment|/* Rx char. available	*/
end_comment

begin_define
define|#
directive|define
name|R1_EOF
value|0x80
end_define

begin_comment
comment|/* End Of Frame (SDLC)	*/
end_comment

begin_define
define|#
directive|define
name|R1_CRC
value|0x40
end_define

begin_comment
comment|/* CRC/Framing Error	*/
end_comment

begin_define
define|#
directive|define
name|R1_OVRUN
value|0x20
end_define

begin_comment
comment|/* Rx Overrun		*/
end_comment

begin_define
define|#
directive|define
name|R1_PARITY
value|0x10
end_define

begin_comment
comment|/* Parity Error		*/
end_comment

begin_define
define|#
directive|define
name|R1_RESID
value|0x0e
end_define

begin_comment
comment|/* Residue code		*/
end_comment

begin_define
define|#
directive|define
name|R1_SENT
value|0x01
end_define

begin_comment
comment|/* All sent		*/
end_comment

begin_define
define|#
directive|define
name|R3_RxA
value|0x20
end_define

begin_comment
comment|/* Channel A Rx IP	*/
end_comment

begin_define
define|#
directive|define
name|R3_TxA
value|0x10
end_define

begin_comment
comment|/* Channel A Tx IP	*/
end_comment

begin_define
define|#
directive|define
name|R3_EXTA
value|0x08
end_define

begin_comment
comment|/* Channel A EXT/STAT	*/
end_comment

begin_define
define|#
directive|define
name|R3_RxB
value|0x20
end_define

begin_comment
comment|/* Channel B Rx IP	*/
end_comment

begin_define
define|#
directive|define
name|R3_TxB
value|0x10
end_define

begin_comment
comment|/* Channel B Tx IP	*/
end_comment

begin_define
define|#
directive|define
name|R3_EXTB
value|0x08
end_define

begin_comment
comment|/* Channel B EXT/STAT	*/
end_comment

begin_define
define|#
directive|define
name|R10_ONEC
value|0x80
end_define

begin_comment
comment|/* One clock missing	*/
end_comment

begin_define
define|#
directive|define
name|R10_TWOC
value|0x40
end_define

begin_comment
comment|/* Two clock missing	*/
end_comment

begin_define
define|#
directive|define
name|R10_LOOP
value|0x10
end_define

begin_comment
comment|/* Loop Sending		*/
end_comment

begin_define
define|#
directive|define
name|R10_ONLOOP
value|0x02
end_define

begin_comment
comment|/* On Loop		*/
end_comment

begin_define
define|#
directive|define
name|R15_BREAK
value|0x80
end_define

begin_comment
comment|/* Break/Abort IE	*/
end_comment

begin_define
define|#
directive|define
name|R15_UDRUN
value|0x40
end_define

begin_comment
comment|/* Tx Underrun IE	*/
end_comment

begin_define
define|#
directive|define
name|R15_CTS
value|0x20
end_define

begin_comment
comment|/* CTS IE		*/
end_comment

begin_define
define|#
directive|define
name|R15_SYNC
value|0x10
end_define

begin_comment
comment|/* Sync/Hunt IE		*/
end_comment

begin_define
define|#
directive|define
name|R15_DCD
value|0x08
end_define

begin_comment
comment|/* DCD IE		*/
end_comment

begin_define
define|#
directive|define
name|R15_ZERO
value|0x02
end_define

begin_comment
comment|/* Zero count IE	*/
end_comment

begin_comment
comment|/*  *	SCC write register  */
end_comment

begin_define
define|#
directive|define
name|WR0
value|0
end_define

begin_define
define|#
directive|define
name|WR1
value|1
end_define

begin_define
define|#
directive|define
name|WR2
value|2
end_define

begin_define
define|#
directive|define
name|WR3
value|3
end_define

begin_define
define|#
directive|define
name|WR4
value|4
end_define

begin_define
define|#
directive|define
name|WR5
value|5
end_define

begin_define
define|#
directive|define
name|WR6
value|6
end_define

begin_define
define|#
directive|define
name|WR7
value|7
end_define

begin_define
define|#
directive|define
name|WR9
value|9
end_define

begin_define
define|#
directive|define
name|WR10
value|10
end_define

begin_define
define|#
directive|define
name|WR11
value|11
end_define

begin_define
define|#
directive|define
name|WR12
value|12
end_define

begin_define
define|#
directive|define
name|WR13
value|13
end_define

begin_define
define|#
directive|define
name|WR14
value|14
end_define

begin_define
define|#
directive|define
name|WR15
value|15
end_define

begin_define
define|#
directive|define
name|W0_RES_UDRUN
value|0xc0
end_define

begin_comment
comment|/* Reset Tx Underrun/EOM	*/
end_comment

begin_define
define|#
directive|define
name|W0_RES_TxCRC
value|0x80
end_define

begin_comment
comment|/* Reset Tx CRC generator	*/
end_comment

begin_define
define|#
directive|define
name|W0_RES_RxCRC
value|0x40
end_define

begin_comment
comment|/* Reset Rx CRC checker		*/
end_comment

begin_define
define|#
directive|define
name|W0_RES_IUS
value|0x38
end_define

begin_comment
comment|/* Reset Highest IUS		*/
end_comment

begin_define
define|#
directive|define
name|W0_RES_ERROR
value|0x30
end_define

begin_comment
comment|/* Error reset			*/
end_comment

begin_define
define|#
directive|define
name|W0_RES_TxINT
value|0x28
end_define

begin_comment
comment|/* Reset TxINT pending		*/
end_comment

begin_define
define|#
directive|define
name|W0_RxINTE
value|0x20
end_define

begin_comment
comment|/* Enable RxINT on next char.	*/
end_comment

begin_define
define|#
directive|define
name|W0_SND_ABORT
value|0x18
end_define

begin_comment
comment|/* Send Abort (SDLC)		*/
end_comment

begin_define
define|#
directive|define
name|W0_RES_EXT
value|0x10
end_define

begin_comment
comment|/* Reset EXT/STAT interrupts	*/
end_comment

begin_define
define|#
directive|define
name|W1_EN_WAIT
value|0x80
end_define

begin_comment
comment|/* WAIT/DMA request enable	*/
end_comment

begin_define
define|#
directive|define
name|W1_WAIT_FUNC
value|0x40
end_define

begin_comment
comment|/* WAIT/DMA request function	*/
end_comment

begin_define
define|#
directive|define
name|W1_WAIT_REQ
value|0x20
end_define

begin_comment
comment|/* WAIT/DMA request on Rx/Tx	*/
end_comment

begin_define
define|#
directive|define
name|W1_RxINT_SC
value|0x18
end_define

begin_comment
comment|/* Rx INT on special condition	*/
end_comment

begin_define
define|#
directive|define
name|W1_RxINT_ALL
value|0x10
end_define

begin_comment
comment|/* Rx INT on all character	*/
end_comment

begin_define
define|#
directive|define
name|W1_RxINT_FRST
value|0x08
end_define

begin_comment
comment|/* Rx INT on first character	*/
end_comment

begin_define
define|#
directive|define
name|W1_PARITY
value|0x04
end_define

begin_comment
comment|/* Parity is special condition	*/
end_comment

begin_define
define|#
directive|define
name|W1_TxINTE
value|0x02
end_define

begin_comment
comment|/* Tx INT enable		*/
end_comment

begin_define
define|#
directive|define
name|W1_EXTINTE
value|0x01
end_define

begin_comment
comment|/* EXT INT enable		*/
end_comment

begin_define
define|#
directive|define
name|W3_Rx8BIT
value|0xc0
end_define

begin_comment
comment|/* Rx 8 bits/character		*/
end_comment

begin_define
define|#
directive|define
name|W3_Rx6BIT
value|0x80
end_define

begin_comment
comment|/* Rx 6 bits/character		*/
end_comment

begin_define
define|#
directive|define
name|W3_Rx7BIT
value|0x40
end_define

begin_comment
comment|/* Rx 7 bits/character		*/
end_comment

begin_define
define|#
directive|define
name|W3_Rx5BIT
value|0x00
end_define

begin_comment
comment|/* Rx 5 bits/character		*/
end_comment

begin_define
define|#
directive|define
name|W3_AUTO
value|0x20
end_define

begin_comment
comment|/* Auto enable			*/
end_comment

begin_define
define|#
directive|define
name|W3_HUNT
value|0x10
end_define

begin_comment
comment|/* Enter Hunt mode		*/
end_comment

begin_define
define|#
directive|define
name|W3_RxCRC
value|0x08
end_define

begin_comment
comment|/* Rx CRC enable		*/
end_comment

begin_define
define|#
directive|define
name|W3_ADDR
value|0x04
end_define

begin_comment
comment|/* Address search mode (SDLC)	*/
end_comment

begin_define
define|#
directive|define
name|W3_SYNCI
value|0x02
end_define

begin_comment
comment|/* Sync char. load inhibit	*/
end_comment

begin_define
define|#
directive|define
name|W3_RxE
value|0x01
end_define

begin_comment
comment|/* Rx enable			*/
end_comment

begin_define
define|#
directive|define
name|W4_X64
value|0xc0
end_define

begin_comment
comment|/* X64 clock mode		*/
end_comment

begin_define
define|#
directive|define
name|W4_X32
value|0x80
end_define

begin_comment
comment|/* X32 clock mode		*/
end_comment

begin_define
define|#
directive|define
name|W4_X16
value|0x40
end_define

begin_comment
comment|/* X16 clock mode		*/
end_comment

begin_define
define|#
directive|define
name|W4_X1
value|0x00
end_define

begin_comment
comment|/* X1 clock mode		*/
end_comment

begin_define
define|#
directive|define
name|W4_EXTSYNC
value|0x30
end_define

begin_comment
comment|/* External Sync mode		*/
end_comment

begin_define
define|#
directive|define
name|W4_SDLC
value|0x20
end_define

begin_comment
comment|/* SDLC mode			*/
end_comment

begin_define
define|#
directive|define
name|W4_SYNC16
value|0x10
end_define

begin_comment
comment|/* 16 bit sync character	*/
end_comment

begin_define
define|#
directive|define
name|W4_SYNC8
value|0x00
end_define

begin_comment
comment|/* 8 bit sync character		*/
end_comment

begin_define
define|#
directive|define
name|W4_STOP2
value|0x0c
end_define

begin_comment
comment|/* 2 stop bits/character	*/
end_comment

begin_define
define|#
directive|define
name|W4_STOP1_5
value|0x08
end_define

begin_comment
comment|/* 1.5 stop bits/character	*/
end_comment

begin_define
define|#
directive|define
name|W4_STOP1
value|0x04
end_define

begin_comment
comment|/* 1 stop bit/character		*/
end_comment

begin_define
define|#
directive|define
name|W4_SYNC
value|0x00
end_define

begin_comment
comment|/* Sync mode enable		*/
end_comment

begin_define
define|#
directive|define
name|W4_EVEN
value|0x02
end_define

begin_comment
comment|/* Parity Even			*/
end_comment

begin_define
define|#
directive|define
name|W4_PARITY
value|0x01
end_define

begin_comment
comment|/* Parity enable		*/
end_comment

begin_define
define|#
directive|define
name|W5_DTR
value|0x80
end_define

begin_comment
comment|/* DTR				*/
end_comment

begin_define
define|#
directive|define
name|W5_Tx8BIT
value|0x60
end_define

begin_comment
comment|/* Tx 8 bits/character		*/
end_comment

begin_define
define|#
directive|define
name|W5_Tx6BIT
value|0x40
end_define

begin_comment
comment|/* Tx 6 bits/character		*/
end_comment

begin_define
define|#
directive|define
name|W5_Tx7BIT
value|0x20
end_define

begin_comment
comment|/* Tx 7 bits/character		*/
end_comment

begin_define
define|#
directive|define
name|W5_Tx5BIT
value|0x00
end_define

begin_comment
comment|/* Tx 5 bits/character		*/
end_comment

begin_define
define|#
directive|define
name|W5_BREAK
value|0x10
end_define

begin_comment
comment|/* Send Break			*/
end_comment

begin_define
define|#
directive|define
name|W5_TxE
value|0x08
end_define

begin_comment
comment|/* Tx enable			*/
end_comment

begin_define
define|#
directive|define
name|W5_CRC16
value|0x04
end_define

begin_comment
comment|/* SDLC/CRC-16			*/
end_comment

begin_define
define|#
directive|define
name|W5_RTS
value|0x02
end_define

begin_comment
comment|/* RTS				*/
end_comment

begin_define
define|#
directive|define
name|W5_TxCRC
value|0x01
end_define

begin_comment
comment|/* Tx CRC enable		*/
end_comment

begin_define
define|#
directive|define
name|W9_RESET
value|0xc0
end_define

begin_comment
comment|/* Force hardware reset		*/
end_comment

begin_define
define|#
directive|define
name|W9_RES_A
value|0x80
end_define

begin_comment
comment|/* Channel reset A		*/
end_comment

begin_define
define|#
directive|define
name|W9_RES_B
value|0x40
end_define

begin_comment
comment|/* Channel reset B		*/
end_comment

begin_define
define|#
directive|define
name|W9_STAT_HIGH
value|0x10
end_define

begin_comment
comment|/* Staus High/Low		*/
end_comment

begin_define
define|#
directive|define
name|W9_MIE
value|0x08
end_define

begin_comment
comment|/* Master Int. enable		*/
end_comment

begin_define
define|#
directive|define
name|W9_DLC
value|0x04
end_define

begin_comment
comment|/* Disable lower chain		*/
end_comment

begin_define
define|#
directive|define
name|W9_NV
value|0x02
end_define

begin_comment
comment|/* Non Vector			*/
end_comment

begin_define
define|#
directive|define
name|W9_VIS
value|0x01
end_define

begin_comment
comment|/* Vector Include Status	*/
end_comment

begin_define
define|#
directive|define
name|W10_CRC_PRESET
value|0x80
end_define

begin_comment
comment|/* CRC preset I/O		*/
end_comment

begin_define
define|#
directive|define
name|W10_FM0
value|0x60
end_define

begin_comment
comment|/* FM0 (transition = 0)		*/
end_comment

begin_define
define|#
directive|define
name|W10_FM1
value|0x40
end_define

begin_comment
comment|/* FM1 (transition = 1)		*/
end_comment

begin_define
define|#
directive|define
name|W10_NRZI
value|0x20
end_define

begin_comment
comment|/* NRZI				*/
end_comment

begin_define
define|#
directive|define
name|W10_NRZ
value|0x00
end_define

begin_comment
comment|/* NRZ				*/
end_comment

begin_define
define|#
directive|define
name|W10_POLL
value|0x10
end_define

begin_comment
comment|/* Go active on poll		*/
end_comment

begin_define
define|#
directive|define
name|W10_MARK
value|0x08
end_define

begin_comment
comment|/* Mark/Flag idle		*/
end_comment

begin_define
define|#
directive|define
name|W10_ABORT
value|0x04
end_define

begin_comment
comment|/* Abort/Flag on underrun	*/
end_comment

begin_define
define|#
directive|define
name|W10_LOOP
value|0x02
end_define

begin_comment
comment|/* Loop mode			*/
end_comment

begin_define
define|#
directive|define
name|W10_SYNC6
value|0x01
end_define

begin_comment
comment|/* 6 bit/8 bit sync		*/
end_comment

begin_define
define|#
directive|define
name|W11_RTxC_XTAL
value|0x80
end_define

begin_comment
comment|/* RTxC Xtal			*/
end_comment

begin_define
define|#
directive|define
name|W11_RxC_DPLL
value|0x60
end_define

begin_comment
comment|/* RxC = DPLL output		*/
end_comment

begin_define
define|#
directive|define
name|W11_RxC_BRG
value|0x40
end_define

begin_comment
comment|/* RxC = BR Gen. output		*/
end_comment

begin_define
define|#
directive|define
name|W11_RxC_TRxC
value|0x20
end_define

begin_comment
comment|/* RxC = TRxC pin		*/
end_comment

begin_define
define|#
directive|define
name|W11_RxC_RTxC
value|0x00
end_define

begin_comment
comment|/* RxC = RTxC pin		*/
end_comment

begin_define
define|#
directive|define
name|W11_TxC_DPLL
value|0x18
end_define

begin_comment
comment|/* TxC = DPLL output		*/
end_comment

begin_define
define|#
directive|define
name|W11_TxC_BRG
value|0x10
end_define

begin_comment
comment|/* TxC = BR Gen. output		*/
end_comment

begin_define
define|#
directive|define
name|W11_TxC_TRxC
value|0x08
end_define

begin_comment
comment|/* TxC = TRxC pin		*/
end_comment

begin_define
define|#
directive|define
name|W11_TxC_RTxC
value|0x00
end_define

begin_comment
comment|/* TxC = RTxC pin		*/
end_comment

begin_define
define|#
directive|define
name|W11_TRxC_O
value|0x04
end_define

begin_comment
comment|/* TRxC O/I			*/
end_comment

begin_define
define|#
directive|define
name|W11_TRxC_DPLL
value|0x03
end_define

begin_comment
comment|/* TRxC = DPLL output		*/
end_comment

begin_define
define|#
directive|define
name|W11_TRxC_BRG
value|0x02
end_define

begin_comment
comment|/* TRxC = BR Gen output		*/
end_comment

begin_define
define|#
directive|define
name|W11_TRxC_TxC
value|0x01
end_define

begin_comment
comment|/* TRxC = Transmit clock	*/
end_comment

begin_define
define|#
directive|define
name|W11_TRxC_XTAL
value|0x00
end_define

begin_comment
comment|/* TRxC = Xtal output		*/
end_comment

begin_define
define|#
directive|define
name|W14_NRZI
value|0xe0
end_define

begin_comment
comment|/* Set NRZI mode		*/
end_comment

begin_define
define|#
directive|define
name|W14_FM
value|0xc0
end_define

begin_comment
comment|/* Set FM mode			*/
end_comment

begin_define
define|#
directive|define
name|W14_RTxC
value|0xa0
end_define

begin_comment
comment|/* Set source = RTxC		*/
end_comment

begin_define
define|#
directive|define
name|W14_BRG
value|0x80
end_define

begin_comment
comment|/* Set source = BR Gen.		*/
end_comment

begin_define
define|#
directive|define
name|W14_DIS_DPLL
value|0x60
end_define

begin_comment
comment|/* Disable DPLL			*/
end_comment

begin_define
define|#
directive|define
name|W14_RES_CLK
value|0x40
end_define

begin_comment
comment|/* Reset missing clock		*/
end_comment

begin_define
define|#
directive|define
name|W14_SEARCH
value|0x20
end_define

begin_comment
comment|/* Enter search mode		*/
end_comment

begin_define
define|#
directive|define
name|W14_LOCAL
value|0x10
end_define

begin_comment
comment|/* Local loopback mode		*/
end_comment

begin_define
define|#
directive|define
name|W14_ECHO
value|0x08
end_define

begin_comment
comment|/* Auto echo			*/
end_comment

begin_define
define|#
directive|define
name|W14_DTR
value|0x04
end_define

begin_comment
comment|/* DTR/Request function		*/
end_comment

begin_define
define|#
directive|define
name|W14_BRG_SRC
value|0x02
end_define

begin_comment
comment|/* BR Gen. source		*/
end_comment

begin_define
define|#
directive|define
name|W14_BRGE
value|0x01
end_define

begin_comment
comment|/* BR Gen. enable		*/
end_comment

begin_define
define|#
directive|define
name|W15_BREAK
value|0x80
end_define

begin_comment
comment|/* Break/Abort IE		*/
end_comment

begin_define
define|#
directive|define
name|W15_UDRUN
value|0x40
end_define

begin_comment
comment|/* Tx underrun/EOM IE		*/
end_comment

begin_define
define|#
directive|define
name|W15_CTS
value|0x20
end_define

begin_comment
comment|/* CTS IE			*/
end_comment

begin_define
define|#
directive|define
name|W15_SYNC
value|0x10
end_define

begin_comment
comment|/* Sync/Hunt IE			*/
end_comment

begin_define
define|#
directive|define
name|W15_DCD
value|0x08
end_define

begin_comment
comment|/* DCD IE			*/
end_comment

begin_define
define|#
directive|define
name|W15_ZERO
value|0x02
end_define

begin_comment
comment|/* Zero count IE		*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCCREG_ */
end_comment

end_unit

