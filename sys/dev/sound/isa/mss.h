begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Doug Rabson  * Copyright (c) 1997 Luigi Rizzo (luigi@iet.unipi.it)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This file contains information and macro definitions for  * AD1848-compatible devices, used in the MSS/WSS compatible boards.  */
end_comment

begin_comment
comment|/*  *  The codec part of the board is seen as a set of 4 registers mapped at the base address for the board (default 0x534). Note that some (early) boards implemented 4 additional registers 4 location before (usually 0x530) to store configuration information. This is a source of confusion in that one never knows what address to specify. The (current) convention is to use the old address (0x530) in the kernel configuration file and consider MSS registers start four location ahead.   *  */
end_comment

begin_struct
struct|struct
name|mixer_def
block|{
name|u_int
name|regno
range|:
literal|7
decl_stmt|;
name|u_int
name|polarity
range|:
literal|1
decl_stmt|;
comment|/* 1 means reversed */
name|u_int
name|bitoffs
range|:
literal|4
decl_stmt|;
name|u_int
name|nbits
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mixer_def
name|mixer_ent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mixer_def
name|mixer_tab
index|[
literal|32
index|]
index|[
literal|2
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MIX_ENT
parameter_list|(
name|name
parameter_list|,
name|reg_l
parameter_list|,
name|pol_l
parameter_list|,
name|pos_l
parameter_list|,
name|len_l
parameter_list|,
name|reg_r
parameter_list|,
name|pol_r
parameter_list|,
name|pos_r
parameter_list|,
name|len_r
parameter_list|)
define|\
value|{{reg_l, pol_l, pos_l, len_l}, {reg_r, pol_r, pos_r, len_r}}
end_define

begin_define
define|#
directive|define
name|PMIX_ENT
parameter_list|(
name|name
parameter_list|,
name|reg_l
parameter_list|,
name|pos_l
parameter_list|,
name|len_l
parameter_list|,
name|reg_r
parameter_list|,
name|pos_r
parameter_list|,
name|len_r
parameter_list|)
define|\
value|{{reg_l, 0, pos_l, len_l}, {reg_r, 0, pos_r, len_r}}
end_define

begin_define
define|#
directive|define
name|MIX_NONE
parameter_list|(
name|name
parameter_list|)
value|MIX_ENT(name, 0,0,0,0, 0,0,0,0)
end_define

begin_comment
comment|/*  * The four visible registers of the MSS :  *  */
end_comment

begin_define
define|#
directive|define
name|MSS_INDEX
value|(0 + 4)
end_define

begin_define
define|#
directive|define
name|MSS_IDXBUSY
value|0x80
end_define

begin_comment
comment|/* readonly, set when busy */
end_comment

begin_define
define|#
directive|define
name|MSS_MCE
value|0x40
end_define

begin_comment
comment|/* the MCE bit. */
end_comment

begin_comment
comment|/* 	 * the MCE bit must be set whenever the current mode of the 	 * codec is changed; this in particular is true for the 	 * Data Format (I8, I28) and Interface Config(I9) registers. 	 * Only exception are CEN and PEN which can be changed on the fly. 	 * The DAC output is muted when MCE is set. 	 */
end_comment

begin_define
define|#
directive|define
name|MSS_TRD
value|0x20
end_define

begin_comment
comment|/* Transfer request disable */
end_comment

begin_comment
comment|/* 	 * When TRD is set, DMA transfers cease when the INT bit in 	 * the MSS status reg is set. Must be cleared for automode 	 * DMA, set otherwise. 	 */
end_comment

begin_define
define|#
directive|define
name|MSS_IDXMASK
value|0x1f
end_define

begin_comment
comment|/* mask for indirect address */
end_comment

begin_define
define|#
directive|define
name|MSS_IDATA
value|(1 + 4)
end_define

begin_comment
comment|/* 	 * data to be transferred to the indirect register addressed 	 * by index addr. During init and sw. powerdown, cannot be 	 * written to, and is always read as 0x80 (consistent with the 	 * busy flag). 	 */
end_comment

begin_define
define|#
directive|define
name|MSS_STATUS
value|(2 + 4)
end_define

begin_define
define|#
directive|define
name|IS_CUL
value|0x80
end_define

begin_comment
comment|/* capture upper/lower */
end_comment

begin_define
define|#
directive|define
name|IS_CLR
value|0x40
end_define

begin_comment
comment|/* capture left/right */
end_comment

begin_define
define|#
directive|define
name|IS_CRDY
value|0x20
end_define

begin_comment
comment|/* capture ready for programmed i/o */
end_comment

begin_define
define|#
directive|define
name|IS_SER
value|0x10
end_define

begin_comment
comment|/* sample error (overrun/underrun) */
end_comment

begin_define
define|#
directive|define
name|IS_PUL
value|0x08
end_define

begin_comment
comment|/* playback upper/lower */
end_comment

begin_define
define|#
directive|define
name|IS_PLR
value|0x04
end_define

begin_comment
comment|/* playback left/right */
end_comment

begin_define
define|#
directive|define
name|IS_PRDY
value|0x02
end_define

begin_comment
comment|/* playback ready for programmed i/o */
end_comment

begin_define
define|#
directive|define
name|IS_INT
value|0x01
end_define

begin_comment
comment|/* int status (1 = active) */
end_comment

begin_comment
comment|/* 	 * IS_INT is clreared by any write to the status register. 	 */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|io_Polled_IO
parameter_list|(
name|d
parameter_list|)
value|((d)->io_base+3+4)
end_define

begin_comment
comment|/* 	 * this register is used in case of polled i/o 	 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The MSS has a set of 16 (or 32 depending on the model) indirect  * registers accessible through the data port by specifying the  * appropriate address in the address register.  *  * The 16 low registers are uniformly handled in AD1848/CS4248 compatible  * mode (often called MODE1). For the upper 16 registers there are  * some differences among different products, mainly Crystal uses them  * differently from OPTi.  *  */
end_comment

begin_comment
comment|/*  * volume registers  */
end_comment

begin_define
define|#
directive|define
name|I6_MUTE
value|0x80
end_define

begin_comment
comment|/*  * register I9 -- interface configuration.  */
end_comment

begin_define
define|#
directive|define
name|I9_PEN
value|0x01
end_define

begin_comment
comment|/* playback enable */
end_comment

begin_define
define|#
directive|define
name|I9_CEN
value|0x02
end_define

begin_comment
comment|/* capture enable */
end_comment

begin_comment
comment|/*  * values used in bd_flags  */
end_comment

begin_define
define|#
directive|define
name|BD_F_MCE_BIT
value|0x0001
end_define

begin_define
define|#
directive|define
name|BD_F_IRQ_OK
value|0x0002
end_define

begin_define
define|#
directive|define
name|BD_F_TMR_RUN
value|0x0004
end_define

begin_define
define|#
directive|define
name|BD_F_MSS_OFFSET
value|0x0008
end_define

begin_comment
comment|/* offset mss writes by -4 */
end_comment

begin_define
define|#
directive|define
name|BD_F_DUPLEX
value|0x0010
end_define

begin_define
define|#
directive|define
name|BD_F_924PNP
value|0x0020
end_define

begin_comment
comment|/* OPTi924 is in PNP mode */
end_comment

begin_comment
comment|/*  * sound/ad1848_mixer.h  *  * Definitions for the mixer of AD1848 and compatible codecs.  *  * Copyright by Hannu Savolainen 1994  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met: 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer. 2.  * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * The AD1848 codec has generic input lines called Line, Aux1 and Aux2.  * Soundcard manufacturers have connected actual inputs (CD, synth, line,  * etc) to these inputs in different order. Therefore it's difficult  * to assign mixer channels to to these inputs correctly. The following  * contains two alternative mappings. The first one is for GUS MAX and  * the second is just a generic one (line1, line2 and line3).  * (Actually this is not a mapping but rather some kind of interleaving  * solution).  */
end_comment

begin_define
define|#
directive|define
name|MSS_REC_DEVICES
define|\
value|(SOUND_MASK_LINE | SOUND_MASK_MIC | SOUND_MASK_CD|SOUND_MASK_IMIX)
end_define

begin_comment
comment|/*  * Table of mixer registers. There is a default table for the  * AD1848/CS423x clones, one for the OPTI931 and one for the  * OPTi930. As more MSS clones come out, there ought to be  * more tables.  *  * Fields in the table are : polarity, register, offset, bits  *  * The channel numbering used by individual soundcards is not fixed.  * Some cards have assigned different meanings for the AUX1, AUX2  * and LINE inputs. Some have different features...  *  * Following there is a macro ...MIXER_DEVICES which is a bitmap  * of all non-zero fields in the table.  * MODE1_MIXER_DEVICES is the basic mixer of the 1848 in mode 1  * registers I0..I15)  *  */
end_comment

begin_decl_stmt
name|mixer_ent
name|mix_devices
index|[
literal|32
index|]
index|[
literal|2
index|]
init|=
block|{
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_VOLUME
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_BASS
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_TREBLE
argument_list|)
block|,
ifdef|#
directive|ifdef
name|PC98
comment|/* PC98's synth is assigned to AUX#2 */
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_SYNTH
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|)
block|,
else|#
directive|else
comment|/* AT386's synth is assigned to AUX#1 */
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_SYNTH
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|)
block|,
endif|#
directive|endif
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_PCM
argument_list|,
literal|6
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|6
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_SPEAKER
argument_list|,
literal|26
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_LINE
argument_list|,
literal|18
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|19
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_MIC
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|)
block|,
ifdef|#
directive|ifdef
name|PC98
comment|/* PC98's cd-audio is assigned to AUX#1 */
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_CD
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|)
block|,
else|#
directive|else
comment|/* AT386's cd-audio is assigned to AUX#2 */
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_CD
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|)
block|,
endif|#
directive|endif
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_IMIX
argument_list|,
literal|13
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|6
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_ALTPCM
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_RECLEV
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_IGAIN
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_OGAIN
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_LINE1
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_LINE2
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_LINE3
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MODE2_MIXER_DEVICES
define|\
value|(SOUND_MASK_SYNTH | SOUND_MASK_PCM    | SOUND_MASK_SPEAKER | \      SOUND_MASK_LINE  | SOUND_MASK_MIC    | SOUND_MASK_CD      | \      SOUND_MASK_IMIX  | SOUND_MASK_IGAIN                         )
end_define

begin_define
define|#
directive|define
name|MODE1_MIXER_DEVICES
define|\
value|(SOUND_MASK_SYNTH | SOUND_MASK_PCM    | SOUND_MASK_MIC     | \      SOUND_MASK_CD    | SOUND_MASK_IMIX   | SOUND_MASK_IGAIN     )
end_define

begin_decl_stmt
name|mixer_ent
name|opti930_devices
index|[
literal|32
index|]
index|[
literal|2
index|]
init|=
block|{
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_VOLUME
argument_list|,
literal|22
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|,
literal|23
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_BASS
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_TREBLE
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_SYNTH
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_PCM
argument_list|,
literal|6
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|5
argument_list|,
literal|7
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|5
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_LINE
argument_list|,
literal|18
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|,
literal|19
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_SPEAKER
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_MIC
argument_list|,
literal|21
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|,
literal|22
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_CD
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_IMIX
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_ALTPCM
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_RECLEV
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_IGAIN
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_OGAIN
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_LINE1
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_LINE2
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_LINE3
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|OPTI930_MIXER_DEVICES
define|\
value|(SOUND_MASK_VOLUME | SOUND_MASK_SYNTH | SOUND_MASK_PCM | \      SOUND_MASK_LINE   | SOUND_MASK_MIC   | SOUND_MASK_CD )
end_define

begin_comment
comment|/*  * entries for the opti931...  */
end_comment

begin_decl_stmt
name|mixer_ent
name|opti931_devices
index|[
literal|32
index|]
index|[
literal|2
index|]
init|=
block|{
comment|/* for the opti931 */
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_VOLUME
argument_list|,
literal|22
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|5
argument_list|,
literal|23
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|5
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_BASS
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_TREBLE
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_SYNTH
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_PCM
argument_list|,
literal|6
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|7
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_SPEAKER
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_LINE
argument_list|,
literal|18
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|,
literal|19
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_MIC
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_CD
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_IMIX
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_ALTPCM
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_RECLEV
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_IGAIN
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_OGAIN
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_LINE1
argument_list|,
literal|16
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|,
literal|17
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_LINE2
argument_list|)
block|,
name|MIX_NONE
argument_list|(
name|SOUND_MIXER_LINE3
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|OPTI931_MIXER_DEVICES
define|\
value|(SOUND_MASK_VOLUME | SOUND_MASK_SYNTH | SOUND_MASK_PCM | \      SOUND_MASK_LINE   | SOUND_MASK_MIC   | SOUND_MASK_CD  | \      SOUND_MASK_IGAIN  | SOUND_MASK_LINE1                    )
end_define

begin_comment
comment|/*  * Register definitions for the Yamaha OPL3-SA[23x].  */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_POWER
value|0x01
end_define

begin_comment
comment|/* Power Management (R/W) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_POWER_PDX
value|0x01
end_define

begin_comment
comment|/* Set to 1 to halt oscillator */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_POWER_PDN
value|0x02
end_define

begin_comment
comment|/* Set to 1 to power down */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_POWER_PSV
value|0x04
end_define

begin_comment
comment|/* Set to 1 to power save */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_POWER_ADOWN
value|0x20
end_define

begin_comment
comment|/* Analog power (?) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_SYSTEM
value|0x02
end_define

begin_comment
comment|/* System control (R/W) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_SYSTEM_VZE
value|0x01
end_define

begin_comment
comment|/* I2S audio routing */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_SYSTEM_IDSEL
value|0x03
end_define

begin_comment
comment|/* SB compat version select */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_SYSTEM_SBHE
value|0x80
end_define

begin_comment
comment|/* 0 for AT bus, 1 for XT bus */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQCONF
value|0x03
end_define

begin_comment
comment|/* Interrupt configuration (R/W */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQCONF_WSSA
value|0x01
end_define

begin_comment
comment|/* WSS interrupts through IRQA */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQCONF_SBA
value|0x02
end_define

begin_comment
comment|/* WSS interrupts through IRQA */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQCONF_MPUA
value|0x04
end_define

begin_comment
comment|/* WSS interrupts through IRQA */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQCONF_OPL3A
value|0x08
end_define

begin_comment
comment|/* WSS interrupts through IRQA */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQCONF_WSSB
value|0x10
end_define

begin_comment
comment|/* WSS interrupts through IRQB */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQCONF_SBB
value|0x20
end_define

begin_comment
comment|/* WSS interrupts through IRQB */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQCONF_MPUB
value|0x40
end_define

begin_comment
comment|/* WSS interrupts through IRQB */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQCONF_OPL3B
value|0x80
end_define

begin_comment
comment|/* WSS interrupts through IRQB */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQSTATUSA
value|0x04
end_define

begin_comment
comment|/* Interrupt (IRQ-A) Status (RO) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQSTATUSB
value|0x05
end_define

begin_comment
comment|/* Interrupt (IRQ-B) Status (RO) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQSTATUS_PI
value|0x01
end_define

begin_comment
comment|/* Playback Flag of CODEC */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQSTATUS_CI
value|0x02
end_define

begin_comment
comment|/* Recording Flag of CODEC */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQSTATUS_TI
value|0x04
end_define

begin_comment
comment|/* Timer Flag of CODEC */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQSTATUS_SB
value|0x08
end_define

begin_comment
comment|/* SB compat Playback Interrupt Flag */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQSTATUS_MPU
value|0x10
end_define

begin_comment
comment|/* MPU401 Interrupt Flag */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQSTATUS_OPL3
value|0x20
end_define

begin_comment
comment|/* Internal FM Timer Flag */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQSTATUS_MV
value|0x40
end_define

begin_comment
comment|/* HW Volume Interrupt Flag */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQSTATUS_PI
value|0x01
end_define

begin_comment
comment|/* Playback Flag of CODEC */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQSTATUS_CI
value|0x02
end_define

begin_comment
comment|/* Recording Flag of CODEC */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQSTATUS_TI
value|0x04
end_define

begin_comment
comment|/* Timer Flag of CODEC */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQSTATUS_SB
value|0x08
end_define

begin_comment
comment|/* SB compat Playback Interrupt Flag */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQSTATUS_MPU
value|0x10
end_define

begin_comment
comment|/* MPU401 Interrupt Flag */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQSTATUS_OPL3
value|0x20
end_define

begin_comment
comment|/* Internal FM Timer Flag */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_IRQSTATUS_MV
value|0x40
end_define

begin_comment
comment|/* HW Volume Interrupt Flag */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_DMACONF
value|0x06
end_define

begin_comment
comment|/* DMA configuration (R/W) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_DMACONF_WSSPA
value|0x01
end_define

begin_comment
comment|/* WSS Playback on DMA-A */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_DMACONF_WSSRA
value|0x02
end_define

begin_comment
comment|/* WSS Recording on DMA-A */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_DMACONF_SBA
value|0x02
end_define

begin_comment
comment|/* SB Playback on DMA-A */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_DMACONF_WSSPB
value|0x10
end_define

begin_comment
comment|/* WSS Playback on DMA-A */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_DMACONF_WSSRB
value|0x20
end_define

begin_comment
comment|/* WSS Recording on DMA-A */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_DMACONF_SBB
value|0x20
end_define

begin_comment
comment|/* SB Playback on DMA-A */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_VOLUMEL
value|0x07
end_define

begin_comment
comment|/* Master Volume Left (R/W) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_VOLUMEL_MVL
value|0x0f
end_define

begin_comment
comment|/* Attenuation level */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_VOLUMEL_MVLM
value|0x80
end_define

begin_comment
comment|/* Mute */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_VOLUMER
value|0x08
end_define

begin_comment
comment|/* Master Volume Right (R/W) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_VOLUMER_MVR
value|0x0f
end_define

begin_comment
comment|/* Attenuation level */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_VOLUMER_MVRM
value|0x80
end_define

begin_comment
comment|/* Mute */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_MIC
value|0x09
end_define

begin_comment
comment|/* MIC Volume (R/W) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_VOLUMER_MCV
value|0x1f
end_define

begin_comment
comment|/* Attenuation level */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_VOLUMER_MICM
value|0x80
end_define

begin_comment
comment|/* Mute */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_MISC
value|0x0a
end_define

begin_comment
comment|/* Miscellaneous */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_MISC_VER
value|0x07
end_define

begin_comment
comment|/* Version */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_MISC_MODE
value|0x08
end_define

begin_comment
comment|/* SB or WSS mode */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_MISC_MCSW
value|0x10
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_MISC_VEN
value|0x80
end_define

begin_comment
comment|/* Enable hardware volume control */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_WSSDMA
value|0x0b
end_define

begin_comment
comment|/* WSS DMA Counter (RW) (4 regs) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_WSSIRQSCAN
value|0x0f
end_define

begin_comment
comment|/* WSS Interrupt Scan out/in (R/W) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_WSSIRQSCAN_SPI
value|0x01
end_define

begin_define
define|#
directive|define
name|OPL3SAx_WSSIRQSCAN_SCI
value|0x02
end_define

begin_define
define|#
directive|define
name|OPL3SAx_WSSIRQSCAN_STI
value|0x04
end_define

begin_define
define|#
directive|define
name|OPL3SAx_SBSTATE
value|0x10
end_define

begin_comment
comment|/* SB compat Internal State (R/W) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_SBSTATE_SBPDR
value|0x01
end_define

begin_comment
comment|/* SB Power Down Request */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_SBSTATE_SE
value|0x02
end_define

begin_comment
comment|/* Scan Enable */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_SBSTATE_SM
value|0x04
end_define

begin_comment
comment|/* Scan Mode */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_SBSTATE_SS
value|0x08
end_define

begin_comment
comment|/* Scan Select */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_SBSTATE_SBPDA
value|0x80
end_define

begin_comment
comment|/* SB Power Down Acknowledge */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_SBDATA
value|0x11
end_define

begin_comment
comment|/* SB compat State Scan Data (R/W) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_DIGITALPOWER
value|0x12
end_define

begin_comment
comment|/* Digital Partial Power Down (R/W) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_DIGITALPOWER_PnP
value|0x01
end_define

begin_define
define|#
directive|define
name|OPL3SAx_DIGITALPOWER_SB
value|0x02
end_define

begin_define
define|#
directive|define
name|OPL3SAx_DIGITALPOWER_WSSP
value|0x04
end_define

begin_define
define|#
directive|define
name|OPL3SAx_DIGITALPOWER_WSSR
value|0x08
end_define

begin_define
define|#
directive|define
name|OPL3SAx_DIGITALPOWER_FM
value|0x10
end_define

begin_define
define|#
directive|define
name|OPL3SAx_DIGITALPOWER_MCLK0
value|0x20
end_define

begin_define
define|#
directive|define
name|OPL3SAx_DIGITALPOWER_MPU
value|0x40
end_define

begin_define
define|#
directive|define
name|OPL3SAx_DIGITALPOWER_JOY
value|0x80
end_define

begin_define
define|#
directive|define
name|OPL3SAx_ANALOGPOWER
value|0x13
end_define

begin_comment
comment|/* Analog Partial Power Down (R/W) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_ANALOGPOWER_WIDE
value|0x01
end_define

begin_define
define|#
directive|define
name|OPL3SAx_ANALOGPOWER_SBDAC
value|0x02
end_define

begin_define
define|#
directive|define
name|OPL3SAx_ANALOGPOWER_DA
value|0x04
end_define

begin_define
define|#
directive|define
name|OPL3SAx_ANALOGPOWER_AD
value|0x08
end_define

begin_define
define|#
directive|define
name|OPL3SAx_ANALOGPOWER_FMDAC
value|0x10
end_define

begin_define
define|#
directive|define
name|OPL3SAx_WIDE
value|0x14
end_define

begin_comment
comment|/* Enhanced control(WIDE) (R/W) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_WIDE_WIDEL
value|0x07
end_define

begin_comment
comment|/* Wide level on Left Channel */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_WIDE_WIDER
value|0x70
end_define

begin_comment
comment|/* Wide level on Right Channel */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_BASS
value|0x15
end_define

begin_comment
comment|/* Enhanced control(BASS) (R/W) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_BASS_BASSL
value|0x07
end_define

begin_comment
comment|/* Bass level on Left Channel */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_BASS_BASSR
value|0x70
end_define

begin_comment
comment|/* Bass level on Right Channel */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_TREBLE
value|0x16
end_define

begin_comment
comment|/* Enhanced control(TREBLE) (R/W) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_TREBLE_TREBLEL
value|0x07
end_define

begin_comment
comment|/* Treble level on Left Channel */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_TREBLE_TREBLER
value|0x70
end_define

begin_comment
comment|/* Treble level on Right Channel */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_HWVOL
value|0x17
end_define

begin_comment
comment|/* HW Volume IRQ Configuration (R/W) */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_HWVOL_IRQA
value|0x10
end_define

begin_comment
comment|/* HW Volume IRQ on IRQ-A */
end_comment

begin_define
define|#
directive|define
name|OPL3SAx_HWVOL_IRQB
value|0x20
end_define

begin_comment
comment|/* HW Volume IRQ on IRQ-B */
end_comment

end_unit

