begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Orion Hodson<O.Hodson@cs.ucl.ac.uk>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHERIN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THEPOSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|ALS_PCI_ID0
value|0x40004005
end_define

begin_define
define|#
directive|define
name|ALS_PCI_POWERREG
value|0xe0
end_define

begin_define
define|#
directive|define
name|ALS_CONFIG_SPACE_BYTES
value|128
end_define

begin_define
define|#
directive|define
name|ALS_BUFFER_SIZE
value|8192
end_define

begin_define
define|#
directive|define
name|ALS_GCR_DATA
value|0x08
end_define

begin_define
define|#
directive|define
name|ALS_GCR_INDEX
value|0x0c
end_define

begin_define
define|#
directive|define
name|ALS_GCR_MISC
value|0x8c
end_define

begin_define
define|#
directive|define
name|ALS_GCR_TEST
value|0x90
end_define

begin_define
define|#
directive|define
name|ALS_GCR_DMA0_START
value|0x91
end_define

begin_define
define|#
directive|define
name|ALS_GCR_DMA0_MODE
value|0x92
end_define

begin_define
define|#
directive|define
name|ALS_GCR_DMA1_START
value|0x93
end_define

begin_define
define|#
directive|define
name|ALS_GCR_DMA1_MODE
value|0x94
end_define

begin_define
define|#
directive|define
name|ALS_GCR_DMA3_START
value|0x95
end_define

begin_define
define|#
directive|define
name|ALS_GCR_DMA3_MODE
value|0x96
end_define

begin_define
define|#
directive|define
name|ALS_GCR_DMA_EMULATION
value|0x99
end_define

begin_define
define|#
directive|define
name|ALS_GCR_FIFO0_CURRENT
value|0xa0
end_define

begin_define
define|#
directive|define
name|ALS_GCR_FIFO0_STATUS
value|0xa1
end_define

begin_define
define|#
directive|define
name|ALS_GCR_FIFO1_START
value|0xa2
end_define

begin_define
define|#
directive|define
name|ALS_GCR_FIFO1_COUNT
value|0xa3
end_define

begin_define
define|#
directive|define
name|ALS_GCR_FIFO1_CURRENT
value|0xa4
end_define

begin_define
define|#
directive|define
name|ALS_GCR_FIFO1_STATUS
value|0xa5
end_define

begin_define
define|#
directive|define
name|ALS_GCR_POWER
value|0xa6
end_define

begin_define
define|#
directive|define
name|ALS_GCR_PIC_ACCESS
value|0xa7
end_define

begin_define
define|#
directive|define
name|ALS_SB_MPU_IRQ
value|0x0e
end_define

begin_define
define|#
directive|define
name|ALS_MIXER_DATA
value|0x15
end_define

begin_define
define|#
directive|define
name|ALS_MIXER_INDEX
value|0x14
end_define

begin_define
define|#
directive|define
name|ALS_SB16_RESET
value|0x00
end_define

begin_define
define|#
directive|define
name|ALS_SB16_DMA_SETUP
value|0x81
end_define

begin_define
define|#
directive|define
name|ALS_CONTROL
value|0xc0
end_define

begin_define
define|#
directive|define
name|ALS_SB16_CONFIG
value|ALS_CONTROL + 0x00
end_define

begin_define
define|#
directive|define
name|ALS_MISC_CONTROL
value|ALS_CONTROL + 0x02
end_define

begin_define
define|#
directive|define
name|ALS_FIFO1_LENGTH_LO
value|ALS_CONTROL + 0x1c
end_define

begin_define
define|#
directive|define
name|ALS_FIFO1_LENGTH_HI
value|ALS_CONTROL + 0x1d
end_define

begin_define
define|#
directive|define
name|ALS_FIFO1_CONTROL
value|ALS_CONTROL + 0x1e
end_define

begin_define
define|#
directive|define
name|ALS_FIFO1_STOP
value|0x00
end_define

begin_define
define|#
directive|define
name|ALS_FIFO1_RUN
value|0x80
end_define

begin_define
define|#
directive|define
name|ALS_FIFO1_PAUSE
value|0x40
end_define

begin_define
define|#
directive|define
name|ALS_FIFO1_STEREO
value|0x20
end_define

begin_define
define|#
directive|define
name|ALS_FIFO1_SIGNED
value|0x10
end_define

begin_define
define|#
directive|define
name|ALS_FIFO1_8BIT
value|0x04
end_define

begin_define
define|#
directive|define
name|ALS_ESP_RST
value|0x16
end_define

begin_define
define|#
directive|define
name|ALS_CR1E_ACK_PORT
value|0x16
end_define

begin_define
define|#
directive|define
name|ALS_ESP_RD_DATA
value|0x1a
end_define

begin_define
define|#
directive|define
name|ALS_ESP_WR_DATA
value|0x1c
end_define

begin_define
define|#
directive|define
name|ALS_ESP_WR_STATUS
value|0x1c
end_define

begin_define
define|#
directive|define
name|ALS_ESP_RD_STATUS8
value|0x1e
end_define

begin_define
define|#
directive|define
name|ALS_ESP_RD_STATUS16
value|0x1f
end_define

begin_define
define|#
directive|define
name|ALS_ESP_SAMPLE_RATE
value|0x41
end_define

begin_define
define|#
directive|define
name|ALS_MIDI_DATA
value|0x30
end_define

begin_define
define|#
directive|define
name|ALS_MIDI_STATUS
value|0x31
end_define

begin_comment
comment|/* Interrupt masks */
end_comment

begin_define
define|#
directive|define
name|ALS_IRQ_STATUS8
value|0x01
end_define

begin_define
define|#
directive|define
name|ALS_IRQ_STATUS16
value|0x02
end_define

begin_define
define|#
directive|define
name|ALS_IRQ_MPUIN
value|0x04
end_define

begin_define
define|#
directive|define
name|ALS_IRQ_CR1E
value|0x20
end_define

begin_comment
comment|/* Sample Rate Locks */
end_comment

begin_define
define|#
directive|define
name|ALS_RATE_LOCK_PLAYBACK
value|0x01
end_define

begin_define
define|#
directive|define
name|ALS_RATE_LOCK_CAPTURE
value|0x02
end_define

begin_define
define|#
directive|define
name|ALS_RATE_LOCK
value|0x03
end_define

end_unit

