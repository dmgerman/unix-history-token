begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sound/awe_hw.h  *  * Access routines and definitions for the low level driver for the   * AWE32/Sound Blaster 32 wave table synth.  *   version 0.4.2; Sep. 15, 1997  *  * Copyright (C) 1996,1997 Takashi Iwai  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AWE_HW_H_DEF
end_ifndef

begin_define
define|#
directive|define
name|AWE_HW_H_DEF
end_define

begin_comment
comment|/*  * Emu-8000 control registers  * name(channel)	reg, port  */
end_comment

begin_define
define|#
directive|define
name|awe_cmd_idx
parameter_list|(
name|reg
parameter_list|,
name|ch
parameter_list|)
value|(((reg)<< 5) | (ch))
end_define

begin_define
define|#
directive|define
name|Data0
value|0x620
end_define

begin_comment
comment|/* doubleword r/w */
end_comment

begin_define
define|#
directive|define
name|Data1
value|0xA20
end_define

begin_comment
comment|/* doubleword r/w */
end_comment

begin_define
define|#
directive|define
name|Data2
value|0xA22
end_define

begin_comment
comment|/* word r/w */
end_comment

begin_define
define|#
directive|define
name|Data3
value|0xE20
end_define

begin_comment
comment|/* word r/w */
end_comment

begin_define
define|#
directive|define
name|Pointer
value|0xE22
end_define

begin_comment
comment|/* register pointer r/w */
end_comment

begin_define
define|#
directive|define
name|AWE_CPF
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(0,ch), Data0
end_define

begin_comment
comment|/* DW: current pitch and fractional address */
end_comment

begin_define
define|#
directive|define
name|AWE_PTRX
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(1,ch), Data0
end_define

begin_comment
comment|/* DW: pitch target and reverb send */
end_comment

begin_define
define|#
directive|define
name|AWE_CVCF
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(2,ch), Data0
end_define

begin_comment
comment|/* DW: current volume and filter cutoff */
end_comment

begin_define
define|#
directive|define
name|AWE_VTFT
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(3,ch), Data0
end_define

begin_comment
comment|/* DW: volume and filter cutoff targets */
end_comment

begin_define
define|#
directive|define
name|AWE_PSST
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(6,ch), Data0
end_define

begin_comment
comment|/* DW: pan send and loop start address */
end_comment

begin_define
define|#
directive|define
name|AWE_CSL
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(7,ch), Data0
end_define

begin_comment
comment|/* DW: chorus send and loop end address */
end_comment

begin_define
define|#
directive|define
name|AWE_CCCA
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(0,ch), Data1
end_define

begin_comment
comment|/* DW: Q, control bits, and current address */
end_comment

begin_define
define|#
directive|define
name|AWE_HWCF4
value|awe_cmd_idx(1,9),  Data1
end_define

begin_comment
comment|/* DW: config dw 4 */
end_comment

begin_define
define|#
directive|define
name|AWE_HWCF5
value|awe_cmd_idx(1,10), Data1
end_define

begin_comment
comment|/* DW: config dw 5 */
end_comment

begin_define
define|#
directive|define
name|AWE_HWCF6
value|awe_cmd_idx(1,13), Data1
end_define

begin_comment
comment|/* DW: config dw 6 */
end_comment

begin_define
define|#
directive|define
name|AWE_HWCF7
value|awe_cmd_idx(1,14), Data1
end_define

begin_comment
comment|/* DW: config dw 7? (not documented) */
end_comment

begin_define
define|#
directive|define
name|AWE_SMALR
value|awe_cmd_idx(1,20), Data1
end_define

begin_comment
comment|/* DW: sound memory address for left read */
end_comment

begin_define
define|#
directive|define
name|AWE_SMARR
value|awe_cmd_idx(1,21), Data1
end_define

begin_comment
comment|/* DW:    for right read */
end_comment

begin_define
define|#
directive|define
name|AWE_SMALW
value|awe_cmd_idx(1,22), Data1
end_define

begin_comment
comment|/* DW: sound memory address for left write */
end_comment

begin_define
define|#
directive|define
name|AWE_SMARW
value|awe_cmd_idx(1,23), Data1
end_define

begin_comment
comment|/* DW:    for right write */
end_comment

begin_define
define|#
directive|define
name|AWE_SMLD
value|awe_cmd_idx(1,26), Data1
end_define

begin_comment
comment|/* W: sound memory left data */
end_comment

begin_define
define|#
directive|define
name|AWE_SMRD
value|awe_cmd_idx(1,26), Data2
end_define

begin_comment
comment|/* W:    right data */
end_comment

begin_define
define|#
directive|define
name|AWE_WC
value|awe_cmd_idx(1,27), Data2
end_define

begin_comment
comment|/* W: sample counter */
end_comment

begin_define
define|#
directive|define
name|AWE_WC_Cmd
value|awe_cmd_idx(1,27)
end_define

begin_define
define|#
directive|define
name|AWE_WC_Port
value|Data2
end_define

begin_define
define|#
directive|define
name|AWE_HWCF1
value|awe_cmd_idx(1,29), Data1
end_define

begin_comment
comment|/* W: config w 1 */
end_comment

begin_define
define|#
directive|define
name|AWE_HWCF2
value|awe_cmd_idx(1,30), Data1
end_define

begin_comment
comment|/* W: config w 2 */
end_comment

begin_define
define|#
directive|define
name|AWE_HWCF3
value|awe_cmd_idx(1,31), Data1
end_define

begin_comment
comment|/* W: config w 3 */
end_comment

begin_define
define|#
directive|define
name|AWE_INIT1
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(2,ch), Data1
end_define

begin_comment
comment|/* W: init array 1 */
end_comment

begin_define
define|#
directive|define
name|AWE_INIT2
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(2,ch), Data2
end_define

begin_comment
comment|/* W: init array 2 */
end_comment

begin_define
define|#
directive|define
name|AWE_INIT3
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(3,ch), Data1
end_define

begin_comment
comment|/* W: init array 3 */
end_comment

begin_define
define|#
directive|define
name|AWE_INIT4
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(3,ch), Data2
end_define

begin_comment
comment|/* W: init array 4 */
end_comment

begin_define
define|#
directive|define
name|AWE_ENVVOL
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(4,ch), Data1
end_define

begin_comment
comment|/* W: volume envelope delay */
end_comment

begin_define
define|#
directive|define
name|AWE_DCYSUSV
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(5,ch), Data1
end_define

begin_comment
comment|/* W: volume envelope sustain and decay */
end_comment

begin_define
define|#
directive|define
name|AWE_ENVVAL
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(6,ch), Data1
end_define

begin_comment
comment|/* W: modulation envelope delay */
end_comment

begin_define
define|#
directive|define
name|AWE_DCYSUS
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(7,ch), Data1
end_define

begin_comment
comment|/* W: modulation envelope sustain and decay */
end_comment

begin_define
define|#
directive|define
name|AWE_ATKHLDV
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(4,ch), Data2
end_define

begin_comment
comment|/* W: volume envelope attack and hold */
end_comment

begin_define
define|#
directive|define
name|AWE_LFO1VAL
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(5,ch), Data2
end_define

begin_comment
comment|/* W: LFO#1 Delay */
end_comment

begin_define
define|#
directive|define
name|AWE_ATKHLD
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(6,ch), Data2
end_define

begin_comment
comment|/* W: modulation envelope attack and hold */
end_comment

begin_define
define|#
directive|define
name|AWE_LFO2VAL
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(7,ch), Data2
end_define

begin_comment
comment|/* W: LFO#2 Delay */
end_comment

begin_define
define|#
directive|define
name|AWE_IP
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(0,ch), Data3
end_define

begin_comment
comment|/* W: initial pitch */
end_comment

begin_define
define|#
directive|define
name|AWE_IFATN
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(1,ch), Data3
end_define

begin_comment
comment|/* W: initial filter cutoff and attenuation */
end_comment

begin_define
define|#
directive|define
name|AWE_PEFE
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(2,ch), Data3
end_define

begin_comment
comment|/* W: pitch and filter envelope heights */
end_comment

begin_define
define|#
directive|define
name|AWE_FMMOD
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(3,ch), Data3
end_define

begin_comment
comment|/* W: vibrato and filter modulation freq */
end_comment

begin_define
define|#
directive|define
name|AWE_TREMFRQ
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(4,ch), Data3
end_define

begin_comment
comment|/* W: LFO#1 tremolo amount and freq */
end_comment

begin_define
define|#
directive|define
name|AWE_FM2FRQ2
parameter_list|(
name|ch
parameter_list|)
value|awe_cmd_idx(5,ch), Data3
end_define

begin_comment
comment|/* W: LFO#2 vibrato amount and freq */
end_comment

begin_comment
comment|/* used during detection (returns ROM version?; not documented in ADIP) */
end_comment

begin_define
define|#
directive|define
name|AWE_U1
value|0xE0, Data3
end_define

begin_comment
comment|/* (R)(W) used in initialization */
end_comment

begin_define
define|#
directive|define
name|AWE_U2
parameter_list|(
name|ch
parameter_list|)
value|0xC0+(ch), Data3
end_define

begin_comment
comment|/* (W)(W) used in init envelope  */
end_comment

begin_define
define|#
directive|define
name|AWE_MAX_VOICES
value|32
end_define

begin_define
define|#
directive|define
name|AWE_NORMAL_VOICES
value|30
end_define

begin_comment
comment|/*30&31 are reserved for DRAM refresh*/
end_comment

begin_define
define|#
directive|define
name|AWE_MAX_CHANNELS
value|32
end_define

begin_comment
comment|/* max midi channels (must>= voices) */
end_comment

begin_define
define|#
directive|define
name|AWE_MAX_LAYERS
value|AWE_MAX_VOICES
end_define

begin_comment
comment|/* maximum number of multiple layers */
end_comment

begin_define
define|#
directive|define
name|AWE_DRAM_OFFSET
value|0x200000
end_define

begin_define
define|#
directive|define
name|AWE_MAX_DRAM_SIZE
value|(28 * 1024)
end_define

begin_comment
comment|/* 28 MB is max onboard memory */
end_comment

begin_define
define|#
directive|define
name|AWE_DEFAULT_ATTENUATION
value|32
end_define

begin_comment
comment|/* 12dB below */
end_comment

begin_define
define|#
directive|define
name|AWE_DEFAULT_MOD_SENSE
value|18
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

