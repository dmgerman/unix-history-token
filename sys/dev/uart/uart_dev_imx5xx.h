begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Oleksandr Rybalko under sponsorship  * from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.	Redistributions of source code must retain the above copyright  *	notice, this list of conditions and the following disclaimer.  * 2.	Redistributions in binary form must reproduce the above copyright  *	notice, this list of conditions and the following disclaimer in the  *	documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UART_DEV_IMX5XX_H
end_ifndef

begin_define
define|#
directive|define
name|_UART_DEV_IMX5XX_H
end_define

begin_define
define|#
directive|define
name|IMXUART_URXD_REG
value|0x0000
end_define

begin_comment
comment|/* UART Receiver Register */
end_comment

begin_define
define|#
directive|define
name|IMXUART_URXD_CHARRDY
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|IMXUART_URXD_ERR
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|IMXUART_URXD_OVRRUN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|IMXUART_URXD_FRMERR
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|IMXUART_URXD_BRK
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|IMXUART_URXD_PRERR
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|IMXUART_URXD_RX_DATA_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|IMXUART_UTXD_REG
value|0x0040
end_define

begin_comment
comment|/* UART Transmitter Register */
end_comment

begin_define
define|#
directive|define
name|IMXUART_UTXD_TX_DATA_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_REG
value|0x0080
end_define

begin_comment
comment|/* UART Control Register 1 */
end_comment

begin_define
define|#
directive|define
name|IMXUART_UCR1_ADEN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_ADBR
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_TRDYEN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_IDEN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_ICD_MASK
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_ICD_IDLE4
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_ICD_IDLE8
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_ICD_IDLE16
value|(2<< 10)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_ICD_IDLE32
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_RRDYEN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_RXDMAEN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_IREN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_TXMPTYEN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_RTSDEN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_SNDBRK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_TXDMAEN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_ATDMAEN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_DOZE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR1_UARTEN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_REG
value|0x0084
end_define

begin_comment
comment|/* UART Control Register 2 */
end_comment

begin_define
define|#
directive|define
name|IMXUART_UCR2_ESCI
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_IRTS
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_CTSC
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_CTS
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_ESCEN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_RTEC_MASK
value|(3<< 9)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_RTEC_REDGE
value|(0<< 9)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_RTEC_FEDGE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_RTEC_EDGE
value|(2<< 9)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_PREN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_PROE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_STPB
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_WS
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_RTSEN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_ATEN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_TXEN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_RXEN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR2_N_SRST
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_REG
value|0x0088
end_define

begin_comment
comment|/* UART Control Register 3 */
end_comment

begin_define
define|#
directive|define
name|IMXUART_UCR3_DPEC_MASK
value|(3<< 14)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_DPEC_REDGE
value|(0<< 14)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_DPEC_FEDGE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_DPEC_EDGE
value|(2<< 14)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_DTREN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_PARERREN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_FRAERREN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_DSR
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_DCD
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_RI
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_ADNIMP
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_RXDSEN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_AIRINTEN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_AWAKEN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_DTRDEN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_RXDMUXSEL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_INVT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR3_ACIEN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR4_REG
value|0x008c
end_define

begin_comment
comment|/* UART Control Register 4 */
end_comment

begin_define
define|#
directive|define
name|IMXUART_UCR4_CTSTL_MASK
value|(0x3f<< 10)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR4_CTSTL_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR4_INVR
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR4_ENIRI
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR4_WKEN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR4_IDDMAEN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR4_IRSC
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR4_LPBYP
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR4_TCEN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR4_BKEN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR4_OREN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IMXUART_UCR4_DREN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IMXUART_UFCR_REG
value|0x0090
end_define

begin_comment
comment|/* UART FIFO Control Register */
end_comment

begin_define
define|#
directive|define
name|IMXUART_UFCR_TXTL_MASK
value|(0x3f<< 10)
end_define

begin_define
define|#
directive|define
name|IMXUART_UFCR_TXTL_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|IMXUART_UFCR_RFDIV_MASK
value|(0x07<< 7)
end_define

begin_define
define|#
directive|define
name|IMXUART_UFCR_RFDIV_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|IMXUART_UFCR_RFDIV_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|IMXUART_UFCR_RFDIV_DIV6
value|(0<< 7)
end_define

begin_define
define|#
directive|define
name|IMXUART_UFCR_RFDIV_DIV5
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|IMXUART_UFCR_RFDIV_DIV4
value|(2<< 7)
end_define

begin_define
define|#
directive|define
name|IMXUART_UFCR_RFDIV_DIV3
value|(3<< 7)
end_define

begin_define
define|#
directive|define
name|IMXUART_UFCR_RFDIV_DIV2
value|(4<< 7)
end_define

begin_define
define|#
directive|define
name|IMXUART_UFCR_RFDIV_DIV1
value|(5<< 7)
end_define

begin_define
define|#
directive|define
name|IMXUART_UFCR_RFDIV_DIV7
value|(6<< 7)
end_define

begin_define
define|#
directive|define
name|IMXUART_UFCR_DCEDTE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|IMXUART_UFCR_RXTL_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|IMXUART_UFCR_RXTL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IMXUART_USR1_REG
value|0x0094
end_define

begin_comment
comment|/* UART Status Register 1 */
end_comment

begin_define
define|#
directive|define
name|IMXUART_USR1_PARITYERR
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR1_RTSS
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR1_TRDY
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR1_RTSD
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR1_ESCF
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR1_FRAMERR
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR1_RRDY
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR1_AGTIM
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR1_DTRD
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR1_RXDS
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR1_AIRINT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR1_AWAKE
value|(1<< 4)
end_define

begin_comment
comment|/* 6040 5008 XXX */
end_comment

begin_define
define|#
directive|define
name|IMXUART_USR2_REG
value|0x0098
end_define

begin_comment
comment|/* UART Status Register 2 */
end_comment

begin_define
define|#
directive|define
name|IMXUART_USR2_ADET
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR2_TXFE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR2_DTRF
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR2_IDLE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR2_ACST
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR2_RIDELT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR2_RIIN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR2_IRINT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR2_WAKE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR2_DCDDELT
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR2_DCDIN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR2_RTSF
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR2_TXDC
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR2_BRCD
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR2_ORE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IMXUART_USR2_RDR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IMXUART_UESC_REG
value|0x009c
end_define

begin_comment
comment|/* UART Escape Character Register */
end_comment

begin_define
define|#
directive|define
name|IMXUART_UESC_ESC_CHAR_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|IMXUART_UTIM_REG
value|0x00a0
end_define

begin_comment
comment|/* UART Escape Timer Register */
end_comment

begin_define
define|#
directive|define
name|IMXUART_UTIM_TIM_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|IMXUART_UBIR_REG
value|0x00a4
end_define

begin_comment
comment|/* UART BRM Incremental Register */
end_comment

begin_define
define|#
directive|define
name|IMXUART_UBIR_INC_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|IMXUART_UBMR_REG
value|0x00a8
end_define

begin_comment
comment|/* UART BRM Modulator Register */
end_comment

begin_define
define|#
directive|define
name|IMXUART_UBMR_MOD_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|IMXUART_UBRC_REG
value|0x00ac
end_define

begin_comment
comment|/* UART Baud Rate Count Register */
end_comment

begin_define
define|#
directive|define
name|IMXUART_UBRC_BCNT_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|IMXUART_ONEMS_REG
value|0x00b0
end_define

begin_comment
comment|/* UART One Millisecond Register */
end_comment

begin_define
define|#
directive|define
name|IMXUART_ONEMS_ONEMS_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|IMXUART_UTS_REG
value|0x00b4
end_define

begin_comment
comment|/* UART Test Register */
end_comment

begin_define
define|#
directive|define
name|IMXUART_UTS_FRCPERR
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|IMXUART_UTS_LOOP
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|IMXUART_UTS_DBGEN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|IMXUART_UTS_LOOPIR
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|IMXUART_UTS_RXDBG
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|IMXUART_UTS_TXEMPTY
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|IMXUART_UTS_RXEMPTY
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|IMXUART_UTS_TXFULL
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|IMXUART_UTS_RXFULL
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|IMXUART_UTS_SOFTRST
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|REG
parameter_list|(
name|_r
parameter_list|)
value|IMXUART_ ## _r ## _REG
end_define

begin_define
define|#
directive|define
name|FLD
parameter_list|(
name|_r
parameter_list|,
name|_v
parameter_list|)
value|IMXUART_ ## _r ## _ ## _v
end_define

begin_define
define|#
directive|define
name|GETREG
parameter_list|(
name|bas
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((bas)->bst, (bas)->bsh, (reg))
end_define

begin_define
define|#
directive|define
name|SETREG
parameter_list|(
name|bas
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_4((bas)->bst, (bas)->bsh, (reg), (value))
end_define

begin_define
define|#
directive|define
name|CLR
parameter_list|(
name|_bas
parameter_list|,
name|_r
parameter_list|,
name|_b
parameter_list|)
define|\
value|SETREG((_bas), (_r), GETREG((_bas), (_r))& ~(_b))
end_define

begin_define
define|#
directive|define
name|SET
parameter_list|(
name|_bas
parameter_list|,
name|_r
parameter_list|,
name|_b
parameter_list|)
define|\
value|SETREG((_bas), (_r), GETREG((_bas), (_r)) | (_b))
end_define

begin_define
define|#
directive|define
name|IS_SET
parameter_list|(
name|_bas
parameter_list|,
name|_r
parameter_list|,
name|_b
parameter_list|)
define|\
value|((GETREG((_bas), (_r))& (_b)) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|ENA
parameter_list|(
name|_bas
parameter_list|,
name|_r
parameter_list|,
name|_b
parameter_list|)
value|SET((_bas), REG(_r), FLD(_r, _b))
end_define

begin_define
define|#
directive|define
name|DIS
parameter_list|(
name|_bas
parameter_list|,
name|_r
parameter_list|,
name|_b
parameter_list|)
value|CLR((_bas), REG(_r), FLD(_r, _b))
end_define

begin_define
define|#
directive|define
name|IS
parameter_list|(
name|_bas
parameter_list|,
name|_r
parameter_list|,
name|_b
parameter_list|)
value|IS_SET((_bas), REG(_r), FLD(_r, _b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UART_DEV_IMX5XX_H */
end_comment

end_unit

