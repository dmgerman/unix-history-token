begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * file: mss.h  *  * (C) 1997 Luigi Rizzo (luigi@iet.unipi.it)  *  * This file contains information and macro definitions for  * AD1848-compatible devices, used in the MSS/WSS compatible boards.  *  */
end_comment

begin_comment
comment|/*  *  The codec part of the board is seen as a set of 4 registers mapped at the base address for the board (default 0x534). Note that some (early) boards implemented 4 additional registers 4 location before (usually 0x530) to store configuration information. This is a source of confusion in that one never knows what address to specify. The (current) convention is to use the old address (0x530) in the kernel configuration file and consider MSS registers start four location ahead.   *  */
end_comment

begin_comment
comment|/*  * The four visible registers of the MSS :  *  */
end_comment

begin_define
define|#
directive|define
name|io_Index_Addr
parameter_list|(
name|d
parameter_list|)
value|((d)->io_base + 4)
end_define

begin_define
define|#
directive|define
name|IA_BUSY
value|0x80
end_define

begin_comment
comment|/* readonly, set when busy */
end_comment

begin_define
define|#
directive|define
name|IA_MCE
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
name|IA_TRD
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
name|IA_AMASK
value|0x1f
end_define

begin_comment
comment|/* mask for indirect address */
end_comment

begin_define
define|#
directive|define
name|io_Indexed_Data
parameter_list|(
name|d
parameter_list|)
value|((d)->io_base+1+4)
end_define

begin_comment
comment|/* 	 * data to be transferred to the indirect register addressed 	 * by index addr. During init and sw. powerdown, cannot be 	 * written to, and is always read as 0x80 (consistent with the 	 * busy flag). 	 */
end_comment

begin_define
define|#
directive|define
name|io_Status
parameter_list|(
name|d
parameter_list|)
value|((d)->io_base+2+4)
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

begin_comment
comment|/*  * sound/ad1848_mixer.h  *   * Definitions for the mixer of AD1848 and compatible codecs.  *   * Copyright by Hannu Savolainen 1994  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met: 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer. 2.  * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
comment|/*  * Table of mixer registers. There is a default table for the  * AD1848/CS423x clones, and one for the OPTI931. As more WSS  * clones come out, there ought to be more tables.  *  * Fields in the table are : polarity, register, offset, bits  *  * The channel numbering used by individual soundcards is not fixed.  * Some cards have assigned different meanings for the AUX1, AUX2  * and LINE inputs. Some have different features...  *  * Following there is a macro ...MIXER_DEVICES which is a bitmap  * of all non-zero fields in the table.  * MODE1_MIXER_DEVICES is the basic mixer of the 1848 in mode 1  * registers I0..I15)  *  */
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

begin_decl_stmt
specifier|static
name|u_short
name|default_mixer_levels
index|[
name|SOUND_MIXER_NRDEVICES
index|]
init|=
block|{
literal|0x5a5a
block|,
comment|/* Master Volume */
literal|0x3232
block|,
comment|/* Bass */
literal|0x3232
block|,
comment|/* Treble */
literal|0x4b4b
block|,
comment|/* FM */
literal|0x4040
block|,
comment|/* PCM */
literal|0x4b4b
block|,
comment|/* PC Speaker */
literal|0x2020
block|,
comment|/* Ext Line */
literal|0x4040
block|,
comment|/* Mic */
literal|0x4b4b
block|,
comment|/* CD */
literal|0x0000
block|,
comment|/* Recording monitor */
literal|0x4b4b
block|,
comment|/* SB PCM */
literal|0x4b4b
block|,
comment|/* Recording level */
literal|0x2525
block|,
comment|/* Input gain */
literal|0x0000
block|,
comment|/* Output gain */
comment|/*  0x4040,			Line1 */
literal|0x0000
block|,
comment|/* Line1 */
literal|0x0000
block|,
comment|/* Line2 */
literal|0x1515
comment|/* Line3 (usually line in)*/
block|}
decl_stmt|;
end_decl_stmt

end_unit

