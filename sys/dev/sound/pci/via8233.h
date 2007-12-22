begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Orion Hodson<orion@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHERIN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THEPOSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SOUND_PCI_VIA8233_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SOUND_PCI_VIA8233_H_
end_define

begin_comment
comment|/*  * VIA Technologies VT8233 Southbridge Audio Driver  *  * Documentation sources:  *  * o V8233C specs. from VIA, gratefully received under NDA.  * o AC97 R2.2 specs.  * o ALSA driver (very useful comments)  */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_SPDIF
value|0x49
end_define

begin_define
define|#
directive|define
name|VIA_SPDIF_EN
value|0x08
end_define

begin_define
define|#
directive|define
name|VIA_DXS0_BASE
value|0x00
end_define

begin_define
define|#
directive|define
name|VIA_DXS1_BASE
value|0x10
end_define

begin_define
define|#
directive|define
name|VIA_DXS2_BASE
value|0x20
end_define

begin_define
define|#
directive|define
name|VIA_DXS3_BASE
value|0x30
end_define

begin_define
define|#
directive|define
name|VIA_DXS_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n))
end_define

begin_define
define|#
directive|define
name|BASE_IS_VIA_DXS_REG
parameter_list|(
name|x
parameter_list|)
value|((x)<= VIA_DXS3_BASE)
end_define

begin_define
define|#
directive|define
name|VIA8233_RP_DXS_LVOL
value|0x02
end_define

begin_define
define|#
directive|define
name|VIA8233_RP_DXS_RVOL
value|0x03
end_define

begin_define
define|#
directive|define
name|VIA8233_DXS_MUTE
value|0x3f
end_define

begin_define
define|#
directive|define
name|VIA8233_RP_DXS_RATEFMT
value|0x08
end_define

begin_define
define|#
directive|define
name|VIA8233_DXS_STOP_INDEX
value|0xff000000
end_define

begin_define
define|#
directive|define
name|VIA8233_DXS_RATEFMT_48K
value|0x000fffff
end_define

begin_define
define|#
directive|define
name|VIA8233_DXS_RATEFMT_STEREO
value|0x00100000
end_define

begin_define
define|#
directive|define
name|VIA8233_DXS_RATEFMT_16BIT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|VIA_PCI_ACLINK_STAT
value|0x40
end_define

begin_define
define|#
directive|define
name|VIA_PCI_ACLINK_C11_READY
value|0x20
end_define

begin_define
define|#
directive|define
name|VIA_PCI_ACLINK_C10_READY
value|0x10
end_define

begin_define
define|#
directive|define
name|VIA_PCI_ACLINK_C01_READY
value|0x04
end_define

begin_define
define|#
directive|define
name|VIA_PCI_ACLINK_LOW_POWER
value|0x02
end_define

begin_define
define|#
directive|define
name|VIA_PCI_ACLINK_C00_READY
value|0x01
end_define

begin_define
define|#
directive|define
name|VIA_PCI_ACLINK_CTRL
value|0x41
end_define

begin_define
define|#
directive|define
name|VIA_PCI_ACLINK_EN
value|0x80
end_define

begin_define
define|#
directive|define
name|VIA_PCI_ACLINK_NRST
value|0x40
end_define

begin_define
define|#
directive|define
name|VIA_PCI_ACLINK_SYNC
value|0x20
end_define

begin_define
define|#
directive|define
name|VIA_PCI_ACLINK_SERIAL
value|0x10
end_define

begin_define
define|#
directive|define
name|VIA_PCI_ACLINK_VRATE
value|0x08
end_define

begin_define
define|#
directive|define
name|VIA_PCI_ACLINK_SGD
value|0x04
end_define

begin_define
define|#
directive|define
name|VIA_PCI_ACLINK_DESIRED
value|(VIA_PCI_ACLINK_EN | 		      \ 					 VIA_PCI_ACLINK_NRST |		      \ 					 VIA_PCI_ACLINK_VRATE | 	      \ 					 VIA_PCI_ACLINK_SGD)
end_define

begin_define
define|#
directive|define
name|VIA_MC_SGD_STATUS
value|0x40
end_define

begin_define
define|#
directive|define
name|VIA_WR0_SGD_STATUS
value|0x60
end_define

begin_define
define|#
directive|define
name|VIA_WR1_SGD_STATUS
value|0x70
end_define

begin_define
define|#
directive|define
name|SGD_STATUS_ACTIVE
value|0x80
end_define

begin_define
define|#
directive|define
name|SGD_STATUS_AT_STOP
value|0x40
end_define

begin_define
define|#
directive|define
name|SGD_STATUS_TRIGGER_Q
value|0x08
end_define

begin_define
define|#
directive|define
name|SGD_STATUS_STOP_I_S
value|0x04
end_define

begin_define
define|#
directive|define
name|SGD_STATUS_EOL
value|0x02
end_define

begin_define
define|#
directive|define
name|SGD_STATUS_FLAG
value|0x01
end_define

begin_define
define|#
directive|define
name|SGD_STATUS_INTR
value|(SGD_STATUS_EOL | SGD_STATUS_FLAG)
end_define

begin_define
define|#
directive|define
name|VIA_WR_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x60 + (n) * 0x10)
end_define

begin_define
define|#
directive|define
name|VIA_MC_SGD_CONTROL
value|0x41
end_define

begin_define
define|#
directive|define
name|VIA_WR0_SGD_CONTROL
value|0x61
end_define

begin_define
define|#
directive|define
name|VIA_WR1_SGD_CONTROL
value|0x71
end_define

begin_define
define|#
directive|define
name|SGD_CONTROL_START
value|0x80
end_define

begin_define
define|#
directive|define
name|SGD_CONTROL_STOP
value|0x40
end_define

begin_define
define|#
directive|define
name|SGD_CONTROL_AUTOSTART
value|0x20
end_define

begin_define
define|#
directive|define
name|SGD_CONTROL_PAUSE
value|0x08
end_define

begin_define
define|#
directive|define
name|SGD_CONTROL_I_STOP
value|0x04
end_define

begin_define
define|#
directive|define
name|SGD_CONTROL_I_EOL
value|0x02
end_define

begin_define
define|#
directive|define
name|SGD_CONTROL_I_FLAG
value|0x01
end_define

begin_define
define|#
directive|define
name|VIA_MC_SGD_FORMAT
value|0x42
end_define

begin_define
define|#
directive|define
name|MC_SGD_16BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|MC_SGD_8BIT
value|0x00
end_define

begin_define
define|#
directive|define
name|MC_SGD_CHANNELS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x07)<< 4)
end_define

begin_define
define|#
directive|define
name|VIA_WR0_SGD_FORMAT
value|0x62
end_define

begin_define
define|#
directive|define
name|VIA_WR1_SGD_FORMAT
value|0x72
end_define

begin_define
define|#
directive|define
name|VIA_WR_RP_SGD_FORMAT
value|0x02
end_define

begin_define
define|#
directive|define
name|WR_FIFO_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|VIA_WR0_SGD_INPUT
value|0x63
end_define

begin_define
define|#
directive|define
name|VIA_WR1_SGD_INPUT
value|0x73
end_define

begin_define
define|#
directive|define
name|WR_LINE_IN
value|0x00
end_define

begin_define
define|#
directive|define
name|WR_MIC_IN
value|0x04
end_define

begin_define
define|#
directive|define
name|WR_PRIMARY_CODEC
value|0x00
end_define

begin_define
define|#
directive|define
name|WR_SECONDARY_CODEC1
value|0x01
end_define

begin_define
define|#
directive|define
name|WR_SECONDARY_CODEC2
value|0x02
end_define

begin_define
define|#
directive|define
name|WR_SECONDARY_CODEC3
value|0x03
end_define

begin_define
define|#
directive|define
name|VIA_MC_TABLE_PTR_BASE
value|0x44
end_define

begin_define
define|#
directive|define
name|VIA_WR0_TABLE_PTR_BASE
value|0x64
end_define

begin_define
define|#
directive|define
name|VIA_WR1_TABLE_PTR_BASE
value|0x74
end_define

begin_define
define|#
directive|define
name|VIA_MC_SLOT_SELECT
value|0x48
end_define

begin_define
define|#
directive|define
name|SLOT3
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|SLOT4
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_define
define|#
directive|define
name|SLOT7
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|SLOT8
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_define
define|#
directive|define
name|SLOT6
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|SLOT9
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|VIA_MC_CURRENT_COUNT
value|0x4c
end_define

begin_define
define|#
directive|define
name|VIA_WR0_FORMAT
value|0x68
end_define

begin_define
define|#
directive|define
name|VIA_WR1_FORMAT
value|0x78
end_define

begin_define
define|#
directive|define
name|WR_FORMAT_STOP_INDEX
value|0xff000000
end_define

begin_define
define|#
directive|define
name|WR_FORMAT_STEREO
value|0x00100000
end_define

begin_define
define|#
directive|define
name|WR_FORMAT_16BIT
value|0x00200000
end_define

begin_comment
comment|/* Relative offsets */
end_comment

begin_define
define|#
directive|define
name|VIA_RP_STATUS
value|0x00
end_define

begin_define
define|#
directive|define
name|VIA_RP_CONTROL
value|0x01
end_define

begin_define
define|#
directive|define
name|VIA_RP_TABLE_PTR
value|0x04
end_define

begin_define
define|#
directive|define
name|VIA_RP_CURRENT_COUNT
value|0x0c
end_define

begin_define
define|#
directive|define
name|VIA_AC97_CONTROL
value|0x80
end_define

begin_define
define|#
directive|define
name|VIA_AC97_CODECID11
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|VIA_AC97_CODECID10
value|0x80000000
end_define

begin_define
define|#
directive|define
name|VIA_AC97_CODECID01
value|0x40000000
end_define

begin_define
define|#
directive|define
name|VIA_AC97_CODEC11_VALID
value|0x20000000
end_define

begin_define
define|#
directive|define
name|VIA_AC97_CODEC10_VALID
value|0x10000000
end_define

begin_define
define|#
directive|define
name|VIA_AC97_CODEC01_VALID
value|0x08000000
end_define

begin_define
define|#
directive|define
name|VIA_AC97_CODEC00_VALID
value|0x02000000
end_define

begin_define
define|#
directive|define
name|VIA_AC97_BUSY
value|0x01000000
end_define

begin_define
define|#
directive|define
name|VIA_AC97_READ
value|0x00800000
end_define

begin_define
define|#
directive|define
name|VIA_AC97_INDEX
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|VIA_AC97_DATA
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xffff)
end_define

begin_define
define|#
directive|define
name|VIA_CODEC_BUSY
value|0x01000000
end_define

begin_define
define|#
directive|define
name|VIA_CODEC_PRIVALID
value|0x02000000
end_define

begin_define
define|#
directive|define
name|VIA_CODEC_INDEX
parameter_list|(
name|x
parameter_list|)
value|((x)<<16)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_SOUND_PCI_VIA8233_H_ */
end_comment

end_unit

