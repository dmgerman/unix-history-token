begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *  Copyright (c) by James Courtier-Dutton<James@superbug.demon.co.uk>  *  Driver p17v chips  *  Version: 0.01  *  *   This program is free software; you can redistribute it and/or modify  *   it under the terms of the GNU General Public License as published by  *   the Free Software Foundation; either version 2 of the License, or  *   (at your option) any later version.  *  *   This program is distributed in the hope that it will be useful,  *   but WITHOUT ANY WARRANTY; without even the implied warranty of  *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *   GNU General Public License for more details.  *  *   You should have received a copy of the GNU General Public License  *   along with this program; if not, write to the Free Software  *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA  *  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/* Audigy2Value Tina (P17V) pointer-offset register set,  * accessed through the PTR20 and DATA24 registers  */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/* 00 - 07: Not used */
end_comment

begin_define
define|#
directive|define
name|P17V_PLAYBACK_FIFO_PTR
value|0x08
end_define

begin_comment
comment|/* Current playback fifo pointer 					 * and number of sound samples in cache. 					 */
end_comment

begin_comment
comment|/* 09 - 12: Not used */
end_comment

begin_define
define|#
directive|define
name|P17V_CAPTURE_FIFO_PTR
value|0x13
end_define

begin_comment
comment|/* Current capture fifo pointer 					 * and number of sound samples in cache. 					 */
end_comment

begin_comment
comment|/* 14 - 17: Not used */
end_comment

begin_define
define|#
directive|define
name|P17V_PB_CHN_SEL
value|0x18
end_define

begin_comment
comment|/* P17v playback channel select */
end_comment

begin_define
define|#
directive|define
name|P17V_SE_SLOT_SEL_L
value|0x19
end_define

begin_comment
comment|/* Sound Engine slot select low */
end_comment

begin_define
define|#
directive|define
name|P17V_SE_SLOT_SEL_H
value|0x1a
end_define

begin_comment
comment|/* Sound Engine slot select high */
end_comment

begin_comment
comment|/* 1b - 1f: Not used */
end_comment

begin_comment
comment|/* 20 - 2f: Not used */
end_comment

begin_comment
comment|/* 30 - 3b: Not used */
end_comment

begin_define
define|#
directive|define
name|P17V_SPI
value|0x3c
end_define

begin_comment
comment|/* SPI interface register */
end_comment

begin_define
define|#
directive|define
name|P17V_I2C_ADDR
value|0x3d
end_define

begin_comment
comment|/* I2C Address */
end_comment

begin_define
define|#
directive|define
name|P17V_I2C_0
value|0x3e
end_define

begin_comment
comment|/* I2C Data */
end_comment

begin_define
define|#
directive|define
name|P17V_I2C_1
value|0x3f
end_define

begin_comment
comment|/* I2C Data */
end_comment

begin_define
define|#
directive|define
name|P17V_START_AUDIO
value|0x40
end_define

begin_comment
comment|/* Start Audio bit */
end_comment

begin_comment
comment|/* 41 - 47: Reserved */
end_comment

begin_define
define|#
directive|define
name|P17V_START_CAPTURE
value|0x48
end_define

begin_comment
comment|/* Start Capture bit */
end_comment

begin_define
define|#
directive|define
name|P17V_CAPTURE_FIFO_BASE
value|0x49
end_define

begin_comment
comment|/* Record FIFO base address */
end_comment

begin_define
define|#
directive|define
name|P17V_CAPTURE_FIFO_SIZE
value|0x4a
end_define

begin_comment
comment|/* Record FIFO buffer size */
end_comment

begin_define
define|#
directive|define
name|P17V_CAPTURE_FIFO_INDEX
value|0x4b
end_define

begin_comment
comment|/* Record FIFO capture index */
end_comment

begin_define
define|#
directive|define
name|P17V_CAPTURE_VOL_H
value|0x4c
end_define

begin_comment
comment|/* P17v capture volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_CAPTURE_VOL_L
value|0x4d
end_define

begin_comment
comment|/* P17v capture volume control */
end_comment

begin_comment
comment|/* 4e - 4f: Not used */
end_comment

begin_comment
comment|/* 50 - 5f: Not used */
end_comment

begin_define
define|#
directive|define
name|P17V_SRCSel
value|0x60
end_define

begin_comment
comment|/* SRC48 and SRCMulti sample rate select 					 * and output select 					 */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_AC97_10K1_VOL_L
value|0x61
end_define

begin_comment
comment|/* 10K to Mixer_AC97 input volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_AC97_10K1_VOL_H
value|0x62
end_define

begin_comment
comment|/* 10K to Mixer_AC97 input volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_AC97_P17V_VOL_L
value|0x63
end_define

begin_comment
comment|/* P17V to Mixer_AC97 input volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_AC97_P17V_VOL_H
value|0x64
end_define

begin_comment
comment|/* P17V to Mixer_AC97 input volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_AC97_SRP_REC_VOL_L
value|0x65
end_define

begin_comment
comment|/* SRP Record to Mixer_AC97 input volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_AC97_SRP_REC_VOL_H
value|0x66
end_define

begin_comment
comment|/* SRP Record to Mixer_AC97 input volume control */
end_comment

begin_comment
comment|/* 67 - 68: Reserved */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_Spdif_10K1_VOL_L
value|0x69
end_define

begin_comment
comment|/* 10K to Mixer_Spdif input volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_Spdif_10K1_VOL_H
value|0x6A
end_define

begin_comment
comment|/* 10K to Mixer_Spdif input volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_Spdif_P17V_VOL_L
value|0x6B
end_define

begin_comment
comment|/* P17V to Mixer_Spdif input volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_Spdif_P17V_VOL_H
value|0x6C
end_define

begin_comment
comment|/* P17V to Mixer_Spdif input volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_Spdif_SRP_REC_VOL_L
value|0x6D
end_define

begin_comment
comment|/* SRP Record to Mixer_Spdif input volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_Spdif_SRP_REC_VOL_H
value|0x6E
end_define

begin_comment
comment|/* SRP Record to Mixer_Spdif input volume control */
end_comment

begin_comment
comment|/* 6f - 70: Reserved */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_I2S_10K1_VOL_L
value|0x71
end_define

begin_comment
comment|/* 10K to Mixer_I2S input volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_I2S_10K1_VOL_H
value|0x72
end_define

begin_comment
comment|/* 10K to Mixer_I2S input volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_I2S_P17V_VOL_L
value|0x73
end_define

begin_comment
comment|/* P17V to Mixer_I2S input volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_I2S_P17V_VOL_H
value|0x74
end_define

begin_comment
comment|/* P17V to Mixer_I2S input volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_I2S_SRP_REC_VOL_L
value|0x75
end_define

begin_comment
comment|/* SRP Record to Mixer_I2S input volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_I2S_SRP_REC_VOL_H
value|0x76
end_define

begin_comment
comment|/* SRP Record to Mixer_I2S input volume control */
end_comment

begin_comment
comment|/* 77 - 78: Reserved */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_AC97_ENABLE
value|0x79
end_define

begin_comment
comment|/* Mixer AC97 input audio enable */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_SPDIF_ENABLE
value|0x7A
end_define

begin_comment
comment|/* Mixer SPDIF input audio enable */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_I2S_ENABLE
value|0x7B
end_define

begin_comment
comment|/* Mixer I2S input audio enable */
end_comment

begin_define
define|#
directive|define
name|P17V_AUDIO_OUT_ENABLE
value|0x7C
end_define

begin_comment
comment|/* Audio out enable */
end_comment

begin_define
define|#
directive|define
name|P17V_MIXER_ATT
value|0x7D
end_define

begin_comment
comment|/* SRP Mixer Attenuation Select */
end_comment

begin_define
define|#
directive|define
name|P17V_SRP_RECORD_SRR
value|0x7E
end_define

begin_comment
comment|/* SRP Record channel source Select */
end_comment

begin_define
define|#
directive|define
name|P17V_SOFT_RESET_SRP_MIXER
value|0x7F
end_define

begin_comment
comment|/* SRP and mixer soft reset */
end_comment

begin_define
define|#
directive|define
name|P17V_AC97_OUT_MASTER_VOL_L
value|0x80
end_define

begin_comment
comment|/* AC97 Output master volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_AC97_OUT_MASTER_VOL_H
value|0x81
end_define

begin_comment
comment|/* AC97 Output master volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_SPDIF_OUT_MASTER_VOL_L
value|0x82
end_define

begin_comment
comment|/* SPDIF Output master volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_SPDIF_OUT_MASTER_VOL_H
value|0x83
end_define

begin_comment
comment|/* SPDIF Output master volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_I2S_OUT_MASTER_VOL_L
value|0x84
end_define

begin_comment
comment|/* I2S Output master volume control */
end_comment

begin_define
define|#
directive|define
name|P17V_I2S_OUT_MASTER_VOL_H
value|0x85
end_define

begin_comment
comment|/* I2S Output master volume control */
end_comment

begin_comment
comment|/* 86 - 87: Not used */
end_comment

begin_define
define|#
directive|define
name|P17V_I2S_CHANNEL_SWAP_PHASE_INVERSE
value|0x88
end_define

begin_comment
comment|/* I2S out mono channel swap 							 * and phase inverse */
end_comment

begin_define
define|#
directive|define
name|P17V_SPDIF_CHANNEL_SWAP_PHASE_INVERSE
value|0x89
end_define

begin_comment
comment|/* SPDIF out mono channel swap 							 * and phase inverse */
end_comment

begin_comment
comment|/* 8A: Not used */
end_comment

begin_define
define|#
directive|define
name|P17V_SRP_P17V_ESR
value|0x8B
end_define

begin_comment
comment|/* SRP_P17V estimated sample rate and rate lock */
end_comment

begin_define
define|#
directive|define
name|P17V_SRP_REC_ESR
value|0x8C
end_define

begin_comment
comment|/* SRP_REC estimated sample rate and rate lock */
end_comment

begin_define
define|#
directive|define
name|P17V_SRP_BYPASS
value|0x8D
end_define

begin_comment
comment|/* srps channel bypass and srps bypass */
end_comment

begin_comment
comment|/* 8E - 92: Not used */
end_comment

begin_define
define|#
directive|define
name|P17V_I2S_SRC_SEL
value|0x93
end_define

begin_comment
comment|/* I2SIN mode sel */
end_comment

end_unit

