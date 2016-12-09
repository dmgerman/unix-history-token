begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract FA8750-10-C-0237  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|AICFR
value|0x00
end_define

begin_comment
comment|/* AIC Configuration Register */
end_comment

begin_define
define|#
directive|define
name|AICFR_TFTH_S
value|16
end_define

begin_comment
comment|/* Transmit FIFO threshold for interrupt or DMA request. */
end_comment

begin_define
define|#
directive|define
name|AICFR_TFTH_M
value|(0x1f<< AICFR_TFTH_S)
end_define

begin_define
define|#
directive|define
name|AICFR_TFTH
parameter_list|(
name|x
parameter_list|)
value|((x)<< AICFR_TFTH_S)
end_define

begin_define
define|#
directive|define
name|AICFR_RFTH_S
value|24
end_define

begin_comment
comment|/* Receive FIFO threshold for interrupt or DMA request. */
end_comment

begin_define
define|#
directive|define
name|AICFR_RFTH_M
value|(0x0f<< AICFR_RFTH_S)
end_define

begin_define
define|#
directive|define
name|AICFR_RFTH
parameter_list|(
name|x
parameter_list|)
value|((x)<< AICFR_RFTH_S)
end_define

begin_define
define|#
directive|define
name|AICFR_ICDC
value|(1<< 5)
end_define

begin_comment
comment|/* Internal CODEC used. */
end_comment

begin_define
define|#
directive|define
name|AICFR_AUSEL
value|(1<< 4)
end_define

begin_comment
comment|/* Audio Unit Select */
end_comment

begin_define
define|#
directive|define
name|AICFR_RST
value|(1<< 3)
end_define

begin_comment
comment|/* Reset AIC. */
end_comment

begin_define
define|#
directive|define
name|AICFR_BCKD
value|(1<< 2)
end_define

begin_comment
comment|/* BIT_CLK Direction. */
end_comment

begin_define
define|#
directive|define
name|AICFR_SYNCD
value|(1<< 1)
end_define

begin_comment
comment|/* SYNC is generated internally and driven out to the CODEC. */
end_comment

begin_define
define|#
directive|define
name|AICFR_ENB
value|(1<< 0)
end_define

begin_comment
comment|/* Enable AIC Controller. */
end_comment

begin_define
define|#
directive|define
name|AICCR
value|0x04
end_define

begin_comment
comment|/* AIC Common Control Register */
end_comment

begin_define
define|#
directive|define
name|AICCR_TFLUSH
value|(1<< 8)
end_define

begin_comment
comment|/* Transmit FIFO Flush. */
end_comment

begin_define
define|#
directive|define
name|AICCR_RFLUSH
value|(1<< 7)
end_define

begin_comment
comment|/* Receive FIFO Flush. */
end_comment

begin_define
define|#
directive|define
name|AICCR_CHANNEL_S
value|24
end_define

begin_define
define|#
directive|define
name|AICCR_CHANNEL_M
value|(0x7<< AICCR_CHANNEL_S)
end_define

begin_define
define|#
directive|define
name|AICCR_CHANNEL_2
value|(0x1<< AICCR_CHANNEL_S)
end_define

begin_comment
comment|/* 2 channels, stereo */
end_comment

begin_define
define|#
directive|define
name|AICCR_ISS_S
value|16
end_define

begin_comment
comment|/* Input Sample Size. */
end_comment

begin_define
define|#
directive|define
name|AICCR_ISS_M
value|(0x7<< AICCR_ISS_S)
end_define

begin_define
define|#
directive|define
name|AICCR_ISS_16
value|(0x1<< AICCR_ISS_S)
end_define

begin_define
define|#
directive|define
name|AICCR_OSS_S
value|19
end_define

begin_comment
comment|/* Output Sample Size. */
end_comment

begin_define
define|#
directive|define
name|AICCR_OSS_M
value|(0x7<< AICCR_OSS_S)
end_define

begin_define
define|#
directive|define
name|AICCR_OSS_16
value|(0x1<< AICCR_OSS_S)
end_define

begin_define
define|#
directive|define
name|AICCR_RDMS
value|(1<< 15)
end_define

begin_comment
comment|/* Receive DMA enable. */
end_comment

begin_define
define|#
directive|define
name|AICCR_TDMS
value|(1<< 14)
end_define

begin_comment
comment|/* Transmit DMA enable. */
end_comment

begin_define
define|#
directive|define
name|AICCR_ENLBF
value|(1<< 2)
end_define

begin_comment
comment|/* Enable AIC Loop Back Function. */
end_comment

begin_define
define|#
directive|define
name|AICCR_ERPL
value|(1<< 1)
end_define

begin_comment
comment|/* Enable Playing Back function. */
end_comment

begin_define
define|#
directive|define
name|I2SCR
value|0x10
end_define

begin_comment
comment|/* AIC I2S/MSB-justified Control */
end_comment

begin_define
define|#
directive|define
name|I2SCR_ESCLK
value|(1<< 4)
end_define

begin_comment
comment|/* Enable SYSCLK output. */
end_comment

begin_define
define|#
directive|define
name|I2SCR_AMSL
value|(1<< 0)
end_define

begin_comment
comment|/* Select MSB-Justified Operation Mode. */
end_comment

begin_define
define|#
directive|define
name|AICSR
value|0x14
end_define

begin_comment
comment|/* AIC FIFO Status Register Register */
end_comment

begin_define
define|#
directive|define
name|I2SSR
value|0x1C
end_define

begin_comment
comment|/* AIC I2S/MSB-justified Status Register */
end_comment

begin_define
define|#
directive|define
name|I2SDIV
value|0x30
end_define

begin_comment
comment|/* AIC I2S/MSB-justified Clock Divider Register */
end_comment

begin_define
define|#
directive|define
name|AICDR
value|0x34
end_define

begin_comment
comment|/* AIC FIFO Data Port Register */
end_comment

begin_define
define|#
directive|define
name|SPENA
value|0x80
end_define

begin_comment
comment|/* SPDIF Enable Register */
end_comment

begin_define
define|#
directive|define
name|SPCTRL
value|0x84
end_define

begin_comment
comment|/* SPDIF Control Register */
end_comment

begin_define
define|#
directive|define
name|SPSTATE
value|0x88
end_define

begin_comment
comment|/* SPDIF Status Register */
end_comment

begin_define
define|#
directive|define
name|SPCFG1
value|0x8C
end_define

begin_comment
comment|/* SPDIF Configure 1 Register */
end_comment

begin_define
define|#
directive|define
name|SPCFG2
value|0x90
end_define

begin_comment
comment|/* SPDIF Configure 2 Register */
end_comment

begin_define
define|#
directive|define
name|SPFIFO
value|0x94
end_define

begin_comment
comment|/* SPDIF FIFO Register */
end_comment

end_unit

