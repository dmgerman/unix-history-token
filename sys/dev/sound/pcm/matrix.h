begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2009 Ariff Abdullah<ariff@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SND_MATRIX_H_
end_ifndef

begin_define
define|#
directive|define
name|_SND_MATRIX_H_
end_define

begin_undef
undef|#
directive|undef
name|SND_MULTICHANNEL
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|SND_OLDSTEREO
end_ifndef

begin_define
define|#
directive|define
name|SND_MULTICHANNEL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX = unused, but part of the definition (will be used someday, maybe).  */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_FL
value|0
end_define

begin_comment
comment|/* Front Left         */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_FR
value|1
end_define

begin_comment
comment|/* Front Right        */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_FC
value|2
end_define

begin_comment
comment|/* Front Center       */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_LF
value|3
end_define

begin_comment
comment|/* Low Frequency      */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_BL
value|4
end_define

begin_comment
comment|/* Back Left          */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_BR
value|5
end_define

begin_comment
comment|/* Back Right         */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_FLC
value|6
end_define

begin_comment
comment|/* Front Left Center  XXX */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_FRC
value|7
end_define

begin_comment
comment|/* Front Right Center XXX */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_BC
value|8
end_define

begin_comment
comment|/* Back Center        */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_SL
value|9
end_define

begin_comment
comment|/* Side Left          */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_SR
value|10
end_define

begin_comment
comment|/* Side Right         */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_TC
value|11
end_define

begin_comment
comment|/* Top Center         XXX */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_TFL
value|12
end_define

begin_comment
comment|/* Top Front Left     XXX */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_TFC
value|13
end_define

begin_comment
comment|/* Top Front Center   XXX */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_TFR
value|14
end_define

begin_comment
comment|/* Top Front Right    XXX */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_TBL
value|15
end_define

begin_comment
comment|/* Top Back Left      XXX */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_TBC
value|16
end_define

begin_comment
comment|/* Top Back Center    XXX */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_TBR
value|17
end_define

begin_comment
comment|/* Top Back Right     XXX */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_MAX
value|18
end_define

begin_comment
comment|/* Maximum channels   */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_ZERO
value|(SND_CHN_T_MAX + 1)
end_define

begin_comment
comment|/* Zero samples */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_LABELS
value|{					\ 	 "fl",  "fr",  "fc",  "lf",  "bl",  "br",			\ 	"flc", "frc",  "bc",  "sl",  "sr",  "tc",			\ 	"tfl", "tfc", "tfr", "tbl", "tbc", "tbr"			\ }
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_NAMES
value|{						\ 	"Front Left", "Front Right", "Front Center",			\ 	"Low Frequency Effects",					\ 	"Back Left", "Back Right",					\ 	"Front Left Center", "Front Right Center",			\ 	"Back Center",							\ 	"Side Left", "Side Right",					\ 	"Top Center",							\ 	"Top Front Left", "Top Front Center", "Top Front Right",	\ 	"Top Back Left", "Top Back Center", "Top Back Right"		\ }
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_FL
value|(1<< SND_CHN_T_FL)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_FR
value|(1<< SND_CHN_T_FR)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_FC
value|(1<< SND_CHN_T_FC)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_LF
value|(1<< SND_CHN_T_LF)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_BL
value|(1<< SND_CHN_T_BL)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_BR
value|(1<< SND_CHN_T_BR)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_FLC
value|(1<< SND_CHN_T_FLC)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_FRC
value|(1<< SND_CHN_T_FRC)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_BC
value|(1<< SND_CHN_T_BC)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_SL
value|(1<< SND_CHN_T_SL)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_SR
value|(1<< SND_CHN_T_SR)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_TC
value|(1<< SND_CHN_T_TC)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_TFL
value|(1<< SND_CHN_T_TFL)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_TFC
value|(1<< SND_CHN_T_TFC)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_TFR
value|(1<< SND_CHN_T_TFR)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_TBL
value|(1<< SND_CHN_T_TBL)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_TBC
value|(1<< SND_CHN_T_TBC)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_MASK_TBR
value|(1<< SND_CHN_T_TBR)
end_define

begin_define
define|#
directive|define
name|SND_CHN_LEFT_MASK
value|(SND_CHN_T_MASK_FL  |			\ 				 SND_CHN_T_MASK_BL  |			\ 				 SND_CHN_T_MASK_FLC |			\ 				 SND_CHN_T_MASK_SL  |			\ 				 SND_CHN_T_MASK_TFL |			\ 				 SND_CHN_T_MASK_TBL)
end_define

begin_define
define|#
directive|define
name|SND_CHN_RIGHT_MASK
value|(SND_CHN_T_MASK_FR  |			\ 				 SND_CHN_T_MASK_BR  |			\ 				 SND_CHN_T_MASK_FRC |			\ 				 SND_CHN_T_MASK_SR  |			\ 				 SND_CHN_T_MASK_TFR |			\ 				 SND_CHN_T_MASK_TBR)
end_define

begin_define
define|#
directive|define
name|SND_CHN_CENTER_MASK
value|(SND_CHN_T_MASK_FC  |			\ 				 SND_CHN_T_MASK_BC  |			\ 				 SND_CHN_T_MASK_TC  |			\ 				 SND_CHN_T_MASK_TFC |			\ 				 SND_CHN_T_MASK_TBC |			\ 				 SND_CHN_T_MASK_LF)
end_define

begin_comment
comment|/* XXX what?!? */
end_comment

begin_comment
comment|/*  * Matrix identity.  */
end_comment

begin_comment
comment|/* 1 @ Mono 1.0 */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_1_0
value|0
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_1
value|SND_CHN_MATRIX_1_0
end_define

begin_comment
comment|/* 2 @ Stereo 2.0 */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_2_0
value|1
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_2
value|SND_CHN_MATRIX_2_0
end_define

begin_comment
comment|/* 3 @ 2.1 (lfe), 3.0 (rear center, DEFAULT) */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_2_1
value|2
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_3_0
value|3
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_3
value|SND_CHN_MATRIX_3_0
end_define

begin_comment
comment|/* 4 @ 3.1 (lfe), 4.0 (Quadraphonic, DEFAULT) */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_3_1
value|4
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_4_0
value|5
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_4
value|SND_CHN_MATRIX_4_0
end_define

begin_comment
comment|/* 5 @ 4.1 (lfe), 5.0 (center, DEFAULT) */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_4_1
value|6
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_5_0
value|7
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_5
value|SND_CHN_MATRIX_5_0
end_define

begin_comment
comment|/* 6 @ 5.1 (lfe, DEFAULT), 6.0 (rear center) */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_5_1
value|8
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_6_0
value|9
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_6
value|SND_CHN_MATRIX_5_1
end_define

begin_comment
comment|/* 7 @ 6.1 (lfe, DEFAULT), 7.0 */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_6_1
value|10
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_7_0
value|11
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_7
value|SND_CHN_MATRIX_6_1
end_define

begin_comment
comment|/* 8 @ 7.1 (lfe) */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_7_1
value|12
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_8
value|SND_CHN_MATRIX_7_1
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_MAX
value|13
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_BEGIN
value|SND_CHN_MATRIX_1_0
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_END
value|SND_CHN_MATRIX_7_1
end_define

begin_comment
comment|/* Custom matrix identity */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_DRV
value|-4
end_define

begin_comment
comment|/* driver own identity   */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_PCMCHANNEL
value|-3
end_define

begin_comment
comment|/* PCM channel identity  */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_MISC
value|-2
end_define

begin_comment
comment|/* misc, custom defined  */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_UNKNOWN
value|-1
end_define

begin_comment
comment|/* unknown               */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_T_VOL_0DB
value|SND_CHN_T_MAX
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_VOL_MAX
value|(SND_CHN_T_VOL_0DB + 1)
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_BEGIN
value|SND_CHN_T_FL
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_END
value|SND_CHN_T_TBR
end_define

begin_define
define|#
directive|define
name|SND_CHN_T_STEP
value|1
end_define

begin_define
define|#
directive|define
name|SND_CHN_MIN
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SND_MULTICHANNEL
end_ifdef

begin_define
define|#
directive|define
name|SND_CHN_MAX
value|8
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SND_CHN_MAX
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Multichannel interleaved volume matrix. Each calculated value relative  * to master and 0db will be stored in each CLASS + 1 as long as  * chn_setvolume_matrix() or the equivalent CHN_SETVOLUME() macros is  * used (see channel.c).  */
end_comment

begin_define
define|#
directive|define
name|SND_VOL_C_MASTER
value|0
end_define

begin_define
define|#
directive|define
name|SND_VOL_C_PCM
value|1
end_define

begin_define
define|#
directive|define
name|SND_VOL_C_PCM_VAL
value|2
end_define

begin_define
define|#
directive|define
name|SND_VOL_C_MAX
value|3
end_define

begin_define
define|#
directive|define
name|SND_VOL_C_BEGIN
value|SND_VOL_C_PCM
end_define

begin_define
define|#
directive|define
name|SND_VOL_C_END
value|SND_VOL_C_PCM
end_define

begin_define
define|#
directive|define
name|SND_VOL_C_STEP
value|2
end_define

begin_define
define|#
directive|define
name|SND_VOL_C_VAL
parameter_list|(
name|x
parameter_list|)
value|((x) + 1)
end_define

begin_define
define|#
directive|define
name|SND_VOL_0DB_MIN
value|1
end_define

begin_define
define|#
directive|define
name|SND_VOL_0DB_MAX
value|100
end_define

begin_define
define|#
directive|define
name|SND_VOL_0DB_MASTER
value|100
end_define

begin_define
define|#
directive|define
name|SND_VOL_0DB_PCM
value|45
end_define

begin_define
define|#
directive|define
name|SND_VOL_RESOLUTION
value|8
end_define

begin_define
define|#
directive|define
name|SND_VOL_FLAT
value|(1<< SND_VOL_RESOLUTION)
end_define

begin_define
define|#
directive|define
name|SND_VOL_CALC_SAMPLE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x) * (y))>> SND_VOL_RESOLUTION)
end_define

begin_define
define|#
directive|define
name|SND_VOL_CALC_VAL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|(((((x)[y][z]<< SND_VOL_RESOLUTION) /		\ 			 (x)[y][SND_CHN_T_VOL_0DB]) *			\ 			 (x)[SND_VOL_C_MASTER][z]) /			\ 			 (x)[SND_VOL_C_MASTER][SND_CHN_T_VOL_0DB])	\  #endif
end_define

begin_comment
comment|/* !_SND_MATRIX_H_ */
end_comment

end_unit

