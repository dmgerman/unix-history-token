begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *  Copyright (c) by James Courtier-Dutton<James@superbug.demon.co.uk>  *  Driver p16v chips  *  Version: 0.21  *  *  FEATURES currently supported:  *    Output fixed at S32_LE, 2 channel to hw:0,0  *    Rates: 44.1, 48, 96, 192.  *  *  Changelog:  *  0.8  *    Use separate card based buffer for periods table.  *  0.9  *    Use 2 channel output streams instead of 8 channel.  *       (8 channel output streams might be good for ASIO type output)  *    Corrected speaker output, so Front -> Front etc.  *  0.10  *    Fixed missed interrupts.  *  0.11  *    Add Sound card model number and names.  *    Add Analog volume controls.  *  0.12  *    Corrected playback interrupts. Now interrupt per period, instead of half period.  *  0.13  *    Use single trigger for multichannel.  *  0.14  *    Mic capture now works at fixed: S32_LE, 96000Hz, Stereo.  *  0.15  *    Force buffer_size / period_size == INTEGER.  *  0.16  *    Update p16v.c to work with changed alsa api.  *  0.17  *    Update p16v.c to work with changed alsa api. Removed boot_devs.  *  0.18  *    Merging with snd-emu10k1 driver.  *  0.19  *    One stereo channel at 24bit now works.  *  0.20  *    Added better register defines.  *  0.21  *    Split from p16v.c  *  *  *  BUGS:  *    Some stability problems when unloading the snd-p16v kernel module.  *    --  *  *  TODO:  *    SPDIF out.  *    Find out how to change capture sample rates. E.g. To record SPDIF at 48000Hz.  *    Currently capture fixed at 48000Hz.  *  *    --  *  GENERAL INFO:  *    Model: SB0240  *    P16V Chip: CA0151-DBS  *    Audigy 2 Chip: CA0102-IAT  *    AC97 Codec: STAC 9721  *    ADC: Philips 1361T (Stereo 24bit)  *    DAC: CS4382-K (8-channel, 24bit, 192Khz)  *  *  This code was initally based on code from ALSA's emu10k1x.c which is:  *  Copyright (c) by Francisco Moraes<fmoraes@nc.rr.com>  *  *   This program is free software; you can redistribute it and/or modify  *   it under the terms of the GNU General Public License as published by  *   the Free Software Foundation; either version 2 of the License, or  *   (at your option) any later version.  *  *   This program is distributed in the hope that it will be useful,  *   but WITHOUT ANY WARRANTY; without even the implied warranty of  *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *   GNU General Public License for more details.  *  *   You should have received a copy of the GNU General Public License  *   along with this program; if not, write to the Free Software  *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA  *  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/********************************************************************************************************/
end_comment

begin_comment
comment|/* Audigy2 P16V pointer-offset register set, accessed through the PTR2 and DATA2 registers                     */
end_comment

begin_comment
comment|/********************************************************************************************************/
end_comment

begin_comment
comment|/* The sample rate of the SPDIF outputs is set by modifying a register in the EMU10K2 PTR register A_SPDIF_SAMPLERATE.  * The sample rate is also controlled by the same registers that control the rate of the EMU10K2 sample rate converters.  */
end_comment

begin_comment
comment|/* Initally all registers from 0x00 to 0x3f have zero contents. */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_LIST_ADDR
value|0x00
end_define

begin_comment
comment|/* Base DMA address of a list of pointers to each period/size */
end_comment

begin_comment
comment|/* One list entry: 4 bytes for DMA address,  						 * 4 bytes for period_size<< 16. 						 * One list entry is 8 bytes long. 						 * One list entry for each period in the buffer. 						 */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_LIST_SIZE
value|0x01
end_define

begin_comment
comment|/* Size of list in bytes<< 16. E.g. 8 periods -> 0x00380000  */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_LIST_PTR
value|0x02
end_define

begin_comment
comment|/* Pointer to the current period being played */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_UNKNOWN3
value|0x03
end_define

begin_comment
comment|/* Not used */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_DMA_ADDR
value|0x04
end_define

begin_comment
comment|/* Playback DMA addresss */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_PERIOD_SIZE
value|0x05
end_define

begin_comment
comment|/* Playback period size. win2000 uses 0x04000000 */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_POINTER
value|0x06
end_define

begin_comment
comment|/* Playback period pointer. Used with PLAYBACK_LIST_PTR to determine buffer position currently in DAC */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_FIFO_END_ADDRESS
value|0x07
end_define

begin_comment
comment|/* Playback FIFO end address */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_FIFO_POINTER
value|0x08
end_define

begin_comment
comment|/* Playback FIFO pointer and number of valid sound samples in cache */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_UNKNOWN9
value|0x09
end_define

begin_comment
comment|/* Not used */
end_comment

begin_define
define|#
directive|define
name|CAPTURE_DMA_ADDR
value|0x10
end_define

begin_comment
comment|/* Capture DMA address */
end_comment

begin_define
define|#
directive|define
name|CAPTURE_BUFFER_SIZE
value|0x11
end_define

begin_comment
comment|/* Capture buffer size */
end_comment

begin_define
define|#
directive|define
name|CAPTURE_POINTER
value|0x12
end_define

begin_comment
comment|/* Capture buffer pointer. Sample currently in ADC */
end_comment

begin_define
define|#
directive|define
name|CAPTURE_FIFO_POINTER
value|0x13
end_define

begin_comment
comment|/* Capture FIFO pointer and number of valid sound samples in cache */
end_comment

begin_define
define|#
directive|define
name|CAPTURE_P16V_VOLUME1
value|0x14
end_define

begin_comment
comment|/* Low: Capture volume 0xXXXX3030 */
end_comment

begin_define
define|#
directive|define
name|CAPTURE_P16V_VOLUME2
value|0x15
end_define

begin_comment
comment|/* High:Has no effect on capture volume */
end_comment

begin_define
define|#
directive|define
name|CAPTURE_P16V_SOURCE
value|0x16
end_define

begin_comment
comment|/* P16V source select. Set to 0x0700E4E5 for AC97 CAPTURE */
end_comment

begin_comment
comment|/* [0:1] Capture input 0 channel select. 0 = Capture output 0. 						 *                                       1 = Capture output 1. 						 *                                       2 = Capture output 2. 						 *                                       3 = Capture output 3. 						 * [3:2] Capture input 1 channel select. 0 = Capture output 0. 						 *                                       1 = Capture output 1. 						 *                                       2 = Capture output 2. 						 *                                       3 = Capture output 3. 						 * [5:4] Capture input 2 channel select. 0 = Capture output 0. 						 *                                       1 = Capture output 1. 						 *                                       2 = Capture output 2. 						 *                                       3 = Capture output 3. 						 * [7:6] Capture input 3 channel select. 0 = Capture output 0. 						 *                                       1 = Capture output 1. 						 *                                       2 = Capture output 2. 						 *                                       3 = Capture output 3. 						 * [9:8] Playback input 0 channel select. 0 = Play output 0. 						 *                                        1 = Play output 1. 						 *                                        2 = Play output 2. 						 *                                        3 = Play output 3. 						 * [11:10] Playback input 1 channel select. 0 = Play output 0. 						 *                                          1 = Play output 1. 						 *                                          2 = Play output 2. 						 *                                          3 = Play output 3. 						 * [13:12] Playback input 2 channel select. 0 = Play output 0. 						 *                                          1 = Play output 1. 						 *                                          2 = Play output 2. 						 *                                          3 = Play output 3. 						 * [15:14] Playback input 3 channel select. 0 = Play output 0. 						 *                                          1 = Play output 1. 						 *                                          2 = Play output 2. 						 *                                          3 = Play output 3. 						 * [19:16] Playback mixer output enable. 1 bit per channel. 						 * [23:20] Capture mixer output enable. 1 bit per channel. 						 * [26:24] FX engine channel capture 0 = 0x60-0x67. 						 *                                   1 = 0x68-0x6f. 						 *                                   2 = 0x70-0x77. 						 *                                   3 = 0x78-0x7f. 						 *                                   4 = 0x80-0x87. 						 *                                   5 = 0x88-0x8f. 						 *                                   6 = 0x90-0x97. 						 *                                   7 = 0x98-0x9f. 						 * [31:27] Not used. 						 */
end_comment

begin_comment
comment|/* 0x1 = capture on. 						 * 0x100 = capture off. 						 * 0x200 = capture off. 						 * 0x1000 = capture off. 						 */
end_comment

begin_define
define|#
directive|define
name|CAPTURE_RATE_STATUS
value|0x17
end_define

begin_comment
comment|/* Capture sample rate. Read only */
end_comment

begin_comment
comment|/* [15:0] Not used. 						 * [18:16] Channel 0 Detected sample rate. 0 - 44.1khz 						 *                               1 - 48 khz 						 *                               2 - 96 khz 						 *                               3 - 192 khz 						 *                               7 - undefined rate. 						 * [19] Channel 0. 1 - Valid, 0 - Not Valid. 						 * [22:20] Channel 1 Detected sample rate.  						 * [23] Channel 1. 1 - Valid, 0 - Not Valid. 						 * [26:24] Channel 2 Detected sample rate.  						 * [27] Channel 2. 1 - Valid, 0 - Not Valid. 						 * [30:28] Channel 3 Detected sample rate.  						 * [31] Channel 3. 1 - Valid, 0 - Not Valid. 						 */
end_comment

begin_comment
comment|/* 0x18 - 0x1f unused */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_LAST_SAMPLE
value|0x20
end_define

begin_comment
comment|/* The sample currently being played. Read only */
end_comment

begin_comment
comment|/* 0x21 - 0x3f unused */
end_comment

begin_define
define|#
directive|define
name|BASIC_INTERRUPT
value|0x40
end_define

begin_comment
comment|/* Used by both playback and capture interrupt handler */
end_comment

begin_comment
comment|/* Playback (0x1<<channel_id) Don't touch high 16bits. */
end_comment

begin_comment
comment|/* Capture  (0x100<<channel_id). not tested */
end_comment

begin_comment
comment|/* Start Playback [3:0] (one bit per channel) 						 * Start Capture [11:8] (one bit per channel) 						 * Record source select for channel 0 [18:16] 						 * Record source select for channel 1 [22:20] 						 * Record source select for channel 2 [26:24] 						 * Record source select for channel 3 [30:28] 						 * 0 - SPDIF channel. 						 * 1 - I2S channel. 						 * 2 - SRC48 channel. 						 * 3 - SRCMulti_SPDIF channel. 						 * 4 - SRCMulti_I2S channel. 						 * 5 - SPDIF channel. 						 * 6 - fxengine capture. 						 * 7 - AC97 capture. 						 */
end_comment

begin_comment
comment|/* Default 41110000. 						 * Writing 0xffffffff hangs the PC. 						 * Writing 0xffff0000 -> 77770000 so it must be some sort of route. 						 * bit 0x1 starts DMA playback on channel_id 0 						 */
end_comment

begin_comment
comment|/* 0x41,42 take values from 0 - 0xffffffff, but have no effect on playback */
end_comment

begin_comment
comment|/* 0x43,0x48 do not remember settings */
end_comment

begin_comment
comment|/* 0x41-45 unused */
end_comment

begin_define
define|#
directive|define
name|WATERMARK
value|0x46
end_define

begin_comment
comment|/* Test bit to indicate cache level usage */
end_comment

begin_comment
comment|/* Values it can have while playing on channel 0.  						 * 0000f000, 0000f004, 0000f008, 0000f00c. 						 * Readonly. 						 */
end_comment

begin_comment
comment|/* 0x47-0x4f unused */
end_comment

begin_comment
comment|/* 0x50-0x5f Capture cache data */
end_comment

begin_define
define|#
directive|define
name|SRCSel
value|0x60
end_define

begin_comment
comment|/* SRCSel. Default 0x4. Bypass P16V 0x14 */
end_comment

begin_comment
comment|/* [0] 0 = 10K2 audio, 1 = SRC48 mixer output. 						 * [2] 0 = 10K2 audio, 1 = SRCMulti SPDIF mixer output. 						 * [4] 0 = 10K2 audio, 1 = SRCMulti I2S mixer output. 						 */
end_comment

begin_comment
comment|/* SRC48 converts samples rates 44.1, 48, 96, 192 to 48 khz. */
end_comment

begin_comment
comment|/* SRCMulti converts 48khz samples rates to 44.1, 48, 96, 192 to 48. */
end_comment

begin_comment
comment|/* SRC48 and SRCMULTI sample rate select and output select. */
end_comment

begin_comment
comment|/* 0xffffffff -> 0xC0000015 						 * 0xXXXXXXX4 = Enable Front Left/Right 						 * Enable PCMs 						 */
end_comment

begin_comment
comment|/* 0x61 -> 0x6c are Volume controls */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_VOLUME_MIXER1
value|0x61
end_define

begin_comment
comment|/* SRC48 Low to mixer input volume control. */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_VOLUME_MIXER2
value|0x62
end_define

begin_comment
comment|/* SRC48 High to mixer input volume control. */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_VOLUME_MIXER3
value|0x63
end_define

begin_comment
comment|/* SRCMULTI SPDIF Low to mixer input volume control. */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_VOLUME_MIXER4
value|0x64
end_define

begin_comment
comment|/* SRCMULTI SPDIF High to mixer input volume control. */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_VOLUME_MIXER5
value|0x65
end_define

begin_comment
comment|/* SRCMULTI I2S Low to mixer input volume control. */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_VOLUME_MIXER6
value|0x66
end_define

begin_comment
comment|/* SRCMULTI I2S High to mixer input volume control. */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_VOLUME_MIXER7
value|0x67
end_define

begin_comment
comment|/* P16V Low to SRCMULTI SPDIF mixer input volume control. */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_VOLUME_MIXER8
value|0x68
end_define

begin_comment
comment|/* P16V High to SRCMULTI SPDIF mixer input volume control. */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_VOLUME_MIXER9
value|0x69
end_define

begin_comment
comment|/* P16V Low to SRCMULTI I2S mixer input volume control. */
end_comment

begin_comment
comment|/* 0xXXXX3030 = PCM0 Volume (Front). 						 * 0x3030XXXX = PCM1 Volume (Center) 						 */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_VOLUME_MIXER10
value|0x6a
end_define

begin_comment
comment|/* P16V High to SRCMULTI I2S mixer input volume control. */
end_comment

begin_comment
comment|/* 0x3030XXXX = PCM3 Volume (Rear). */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_VOLUME_MIXER11
value|0x6b
end_define

begin_comment
comment|/* E10K2 Low to SRC48 mixer input volume control. */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_VOLUME_MIXER12
value|0x6c
end_define

begin_comment
comment|/* E10K2 High to SRC48 mixer input volume control. */
end_comment

begin_define
define|#
directive|define
name|SRC48_ENABLE
value|0x6d
end_define

begin_comment
comment|/* SRC48 input audio enable */
end_comment

begin_comment
comment|/* SRC48 converts samples rates 44.1, 48, 96, 192 to 48 khz. */
end_comment

begin_comment
comment|/* [23:16] The corresponding P16V channel to SRC48 enabled if == 1. 						 * [31:24] The corresponding E10K2 channel to SRC48 enabled. 						 */
end_comment

begin_define
define|#
directive|define
name|SRCMULTI_ENABLE
value|0x6e
end_define

begin_comment
comment|/* SRCMulti input audio enable. Default 0xffffffff */
end_comment

begin_comment
comment|/* SRCMulti converts 48khz samples rates to 44.1, 48, 96, 192 to 48. */
end_comment

begin_comment
comment|/* [7:0] The corresponding P16V channel to SRCMulti_I2S enabled if == 1. 						 * [15:8] The corresponding E10K2 channel to SRCMulti I2S enabled. 						 * [23:16] The corresponding P16V channel to SRCMulti SPDIF enabled. 						 * [31:24] The corresponding E10K2 channel to SRCMulti SPDIF enabled. 						 */
end_comment

begin_comment
comment|/* Bypass P16V 0xff00ff00  						 * Bitmap. 0 = Off, 1 = On. 						 * P16V playback outputs: 						 * 0xXXXXXXX1 = PCM0 Left. (Front) 						 * 0xXXXXXXX2 = PCM0 Right. 						 * 0xXXXXXXX4 = PCM1 Left. (Center/LFE) 						 * 0xXXXXXXX8 = PCM1 Right. 						 * 0xXXXXXX1X = PCM2 Left. (Unknown) 						 * 0xXXXXXX2X = PCM2 Right. 						 * 0xXXXXXX4X = PCM3 Left. (Rear) 						 * 0xXXXXXX8X = PCM3 Right. 						 */
end_comment

begin_define
define|#
directive|define
name|AUDIO_OUT_ENABLE
value|0x6f
end_define

begin_comment
comment|/* Default: 000100FF */
end_comment

begin_comment
comment|/* [3:0] Does something, but not documented. Probably capture enable. 						 * [7:4] Playback channels enable. not documented. 						 * [16] AC97 output enable if == 1 						 * [30] 0 = SRCMulti_I2S input from fxengine 0x68-0x6f. 						 *      1 = SRCMulti_I2S input from SRC48 output. 						 * [31] 0 = SRCMulti_SPDIF input from fxengine 0x60-0x67. 						 *      1 = SRCMulti_SPDIF input from SRC48 output. 						 */
end_comment

begin_comment
comment|/* 0xffffffff -> C00100FF */
end_comment

begin_comment
comment|/* 0 -> Not playback sound, irq still running */
end_comment

begin_comment
comment|/* 0xXXXXXX10 = PCM0 Left/Right On. (Front) 						 * 0xXXXXXX20 = PCM1 Left/Right On. (Center/LFE) 						 * 0xXXXXXX40 = PCM2 Left/Right On. (Unknown) 						 * 0xXXXXXX80 = PCM3 Left/Right On. (Rear) 						 */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_SPDIF_SELECT
value|0x70
end_define

begin_comment
comment|/* Default: 12030F00 */
end_comment

begin_comment
comment|/* 0xffffffff -> 3FF30FFF */
end_comment

begin_comment
comment|/* 0x00000001 pauses stream/irq fail. */
end_comment

begin_comment
comment|/* All other bits do not effect playback */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_SPDIF_SRC_SELECT
value|0x71
end_define

begin_comment
comment|/* Default: 0000E4E4 */
end_comment

begin_comment
comment|/* 0xffffffff -> F33FFFFF */
end_comment

begin_comment
comment|/* All bits do not effect playback */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_SPDIF_USER_DATA0
value|0x72
end_define

begin_comment
comment|/* SPDIF out user data 0 */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_SPDIF_USER_DATA1
value|0x73
end_define

begin_comment
comment|/* SPDIF out user data 1 */
end_comment

begin_comment
comment|/* 0x74-0x75 unknown */
end_comment

begin_define
define|#
directive|define
name|CAPTURE_SPDIF_CONTROL
value|0x76
end_define

begin_comment
comment|/* SPDIF in control setting */
end_comment

begin_define
define|#
directive|define
name|CAPTURE_SPDIF_STATUS
value|0x77
end_define

begin_comment
comment|/* SPDIF in status */
end_comment

begin_define
define|#
directive|define
name|CAPURE_SPDIF_USER_DATA0
value|0x78
end_define

begin_comment
comment|/* SPDIF in user data 0 */
end_comment

begin_define
define|#
directive|define
name|CAPURE_SPDIF_USER_DATA1
value|0x79
end_define

begin_comment
comment|/* SPDIF in user data 1 */
end_comment

begin_define
define|#
directive|define
name|CAPURE_SPDIF_USER_DATA2
value|0x7a
end_define

begin_comment
comment|/* SPDIF in user data 2 */
end_comment

end_unit

