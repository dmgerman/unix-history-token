begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Stephane E. Potvin<sepotvin@videotron.ca>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HDA_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_HDA_REG_H_
end_define

begin_comment
comment|/****************************************************************************  * HDA Device Verbs  ****************************************************************************/
end_comment

begin_comment
comment|/* HDA Command */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_MASK
value|0x000fffff
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_CMD_NID_MASK
value|0x0ff00000
end_define

begin_define
define|#
directive|define
name|HDA_CMD_NID_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|HDA_CMD_CAD_MASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|HDA_CMD_CAD_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_4BIT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_12BIT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_4BIT
parameter_list|(
name|verb
parameter_list|,
name|payload
parameter_list|)
define|\
value|(((verb)<< HDA_CMD_VERB_4BIT_SHIFT) | (payload))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_4BIT
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|verb
parameter_list|,
name|payload
parameter_list|)
define|\
value|(((cad)<< HDA_CMD_CAD_SHIFT) |					\     ((nid)<< HDA_CMD_NID_SHIFT) |					\     (HDA_CMD_VERB_4BIT((verb), (payload))))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_12BIT
parameter_list|(
name|verb
parameter_list|,
name|payload
parameter_list|)
define|\
value|(((verb)<< HDA_CMD_VERB_12BIT_SHIFT) | (payload))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_12BIT
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|verb
parameter_list|,
name|payload
parameter_list|)
define|\
value|(((cad)<< HDA_CMD_CAD_SHIFT) |					\     ((nid)<< HDA_CMD_NID_SHIFT) |					\     (HDA_CMD_VERB_12BIT((verb), (payload))))
end_define

begin_comment
comment|/* Get Parameter */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_PARAMETER
value|0xf00
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PARAMETER
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_PARAMETER, (payload)))
end_define

begin_comment
comment|/* Connection Select Control */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_CONN_SELECT_CONTROL
value|0xf01
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_CONN_SELECT_CONTROL
value|0x701
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_CONN_SELECT_CONTROL
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_CONN_SELECT_CONTROL, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_CONNECTION_SELECT_CONTROL
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_CONN_SELECT_CONTROL, (payload)))
end_define

begin_comment
comment|/* Connection List Entry */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_CONN_LIST_ENTRY
value|0xf02
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_CONN_LIST_ENTRY
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_CONN_LIST_ENTRY, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_CONN_LIST_ENTRY_SIZE_SHORT
value|1
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_CONN_LIST_ENTRY_SIZE_LONG
value|2
end_define

begin_comment
comment|/* Processing State */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_PROCESSING_STATE
value|0xf03
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_PROCESSING_STATE
value|0x703
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PROCESSING_STATE
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_PROCESSING_STATE, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_PROCESSING_STATE
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_PROCESSING_STATE, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PROCESSING_STATE_STATE_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PROCESSING_STATE_STATE_ON
value|0x01
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PROCESSING_STATE_STATE_BENIGN
value|0x02
end_define

begin_comment
comment|/* Coefficient Index */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_COEFF_INDEX
value|0xd
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_COEFF_INDEX
value|0x5
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_COEFF_INDEX
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_4BIT((cad), (nid),						\     HDA_CMD_VERB_GET_COEFF_INDEX, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_COEFF_INDEX
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_4BIT((cad), (nid),						\     HDA_CMD_VERB_SET_COEFF_INDEX, (payload)))
end_define

begin_comment
comment|/* Processing Coefficient */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_PROCESSING_COEFF
value|0xc
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_PROCESSING_COEFF
value|0x4
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PROCESSING_COEFF
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_4BIT((cad), (nid),						\     HDA_CMD_VERB_GET_PROCESSING_COEFF, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_PROCESSING_COEFF
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_4BIT((cad), (nid),						\     HDA_CMD_VERB_SET_PROCESSING_COEFF, (payload)))
end_define

begin_comment
comment|/* Amplifier Gain/Mute */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_AMP_GAIN_MUTE
value|0xb
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_AMP_GAIN_MUTE
value|0x3
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_AMP_GAIN_MUTE
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_4BIT((cad), (nid),						\     HDA_CMD_VERB_GET_AMP_GAIN_MUTE, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_AMP_GAIN_MUTE
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_4BIT((cad), (nid),						\     HDA_CMD_VERB_SET_AMP_GAIN_MUTE, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_AMP_GAIN_MUTE_INPUT
value|0x0000
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_AMP_GAIN_MUTE_OUTPUT
value|0x8000
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_AMP_GAIN_MUTE_RIGHT
value|0x0000
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_AMP_GAIN_MUTE_LEFT
value|0x2000
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_AMP_GAIN_MUTE_MUTE_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_AMP_GAIN_MUTE_MUTE_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_AMP_GAIN_MUTE_GAIN_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_AMP_GAIN_MUTE_GAIN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_AMP_GAIN_MUTE_MUTE
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_AMP_GAIN_MUTE_MUTE_MASK)>>			\     HDA_CMD_GET_AMP_GAIN_MUTE_MUTE_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_AMP_GAIN_MUTE_GAIN
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_AMP_GAIN_MUTE_GAIN_MASK)>>			\     HDA_CMD_GET_AMP_GAIN_MUTE_GAIN_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_AMP_GAIN_MUTE_OUTPUT
value|0x8000
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_AMP_GAIN_MUTE_INPUT
value|0x4000
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_AMP_GAIN_MUTE_LEFT
value|0x2000
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_AMP_GAIN_MUTE_RIGHT
value|0x1000
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_AMP_GAIN_MUTE_INDEX_MASK
value|0x0f00
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_AMP_GAIN_MUTE_INDEX_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_AMP_GAIN_MUTE_MUTE
value|0x0080
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_AMP_GAIN_MUTE_GAIN_MASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_AMP_GAIN_MUTE_GAIN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_AMP_GAIN_MUTE_INDEX
parameter_list|(
name|index
parameter_list|)
define|\
value|(((index)<< HDA_CMD_SET_AMP_GAIN_MUTE_INDEX_SHIFT)&		\     HDA_CMD_SET_AMP_GAIN_MUTE_INDEX_MASK)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_AMP_GAIN_MUTE_GAIN
parameter_list|(
name|index
parameter_list|)
define|\
value|(((index)<< HDA_CMD_SET_AMP_GAIN_MUTE_GAIN_SHIFT)&		\     HDA_CMD_SET_AMP_GAIN_MUTE_GAIN_MASK)
end_define

begin_comment
comment|/* Converter format */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_CONV_FMT
value|0xa
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_CONV_FMT
value|0x2
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_CONV_FMT
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_4BIT((cad), (nid),						\     HDA_CMD_VERB_GET_CONV_FMT, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_CONV_FMT
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_4BIT((cad), (nid),						\     HDA_CMD_VERB_SET_CONV_FMT, (payload)))
end_define

begin_comment
comment|/* Digital Converter Control */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_DIGITAL_CONV_FMT
value|0xf0d
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_DIGITAL_CONV_FMT1
value|0x70d
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_DIGITAL_CONV_FMT2
value|0x70e
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_DIGITAL_CONV_FMTT, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_DIGITAL_CONV_FMT1
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_DIGITAL_CONV_FMT1, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_DIGITAL_CONV_FMT2
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_DIGITAL_CONV_FMT2, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_CC_MASK
value|0x7f00
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_CC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_L_MASK
value|0x0080
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_L_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_PRO_MASK
value|0x0040
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_PRO_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_NAUDIO_MASK
value|0x0020
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_NAUDIO_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_COPY_MASK
value|0x0010
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_COPY_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_PRE_MASK
value|0x0008
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_PRE_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_VCFG_MASK
value|0x0004
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_VCFG_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_V_MASK
value|0x0002
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_V_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_DIGEN_MASK
value|0x0001
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_DIGEN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_CC
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_DIGITAL_CONV_FMT_CC_MASK)>>			\     HDA_CMD_GET_DIGITAL_CONV_FMT_CC_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_L
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_DIGITAL_CONV_FMT_L_MASK)>>			\     HDA_CMD_GET_DIGITAL_CONV_FMT_L_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_PRO
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_DIGITAL_CONV_FMT_PRO_MASK)>>			\     HDA_CMD_GET_DIGITAL_CONV_FMT_PRO_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_NAUDIO
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_DIGITAL_CONV_FMT_NAUDIO_MASK)>>		\     HDA_CMD_GET_DIGITAL_CONV_FMT_NAUDIO_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_COPY
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_DIGITAL_CONV_FMT_COPY_MASK)>>		\     HDA_CMD_GET_DIGITAL_CONV_FMT_COPY_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_PRE
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_DIGITAL_CONV_FMT_PRE_MASK)>>			\     HDA_CMD_GET_DIGITAL_CONV_FMT_PRE_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_VCFG
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_DIGITAL_CONV_FMT_VCFG_MASK)>>		\     HDA_CMD_GET_DIGITAL_CONV_FMT_VCFG_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_V
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_DIGITAL_CONV_FMT_V_MASK)>>			\     HDA_CMD_GET_DIGITAL_CONV_FMT_V_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_DIGITAL_CONV_FMT_DIGEN
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_DIGITAL_CONV_FMT_DIGEN_MASK)>>		\     HDA_CMD_GET_DIGITAL_CONV_FMT_DIGEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_DIGITAL_CONV_FMT1_L
value|0x80
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_DIGITAL_CONV_FMT1_PRO
value|0x40
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_DIGITAL_CONV_FMT1_NAUDIO
value|0x20
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_DIGITAL_CONV_FMT1_COPY
value|0x10
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_DIGITAL_CONV_FMT1_PRE
value|0x08
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_DIGITAL_CONV_FMT1_VCFG
value|0x04
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_DIGITAL_CONV_FMT1_V
value|0x02
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_DIGITAL_CONV_FMT1_DIGEN
value|0x01
end_define

begin_comment
comment|/* Power State */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_POWER_STATE
value|0xf05
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_POWER_STATE
value|0x705
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_POWER_STATE
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_POWER_STATE, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_POWER_STATE
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_POWER_STATE, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_POWER_STATE_D0
value|0x00
end_define

begin_define
define|#
directive|define
name|HDA_CMD_POWER_STATE_D1
value|0x01
end_define

begin_define
define|#
directive|define
name|HDA_CMD_POWER_STATE_D2
value|0x02
end_define

begin_define
define|#
directive|define
name|HDA_CMD_POWER_STATE_D3
value|0x03
end_define

begin_define
define|#
directive|define
name|HDA_CMD_POWER_STATE_ACT_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|HDA_CMD_POWER_STATE_ACT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HDA_CMD_POWER_STATE_SET_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|HDA_CMD_POWER_STATE_SET_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_POWER_STATE_ACT
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_POWER_STATE_ACT_MASK)>>				\     HDA_CMD_POWER_STATE_ACT_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_POWER_STATE_SET
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_POWER_STATE_SET_MASK)>>				\     HDA_CMD_POWER_STATE_SET_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_POWER_STATE_ACT
parameter_list|(
name|ps
parameter_list|)
define|\
value|(((ps)<< HDA_CMD_POWER_STATE_ACT_SHIFT)&				\     HDA_CMD_POWER_STATE_ACT_MASK)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_POWER_STATE_SET
parameter_list|(
name|ps
parameter_list|)
define|\
value|(((ps)<< HDA_CMD_POWER_STATE_SET_SHIFT)&				\     HDA_CMD_POWER_STATE_ACT_MASK)
end_define

begin_comment
comment|/* Converter Stream, Channel */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_CONV_STREAM_CHAN
value|0xf06
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_CONV_STREAM_CHAN
value|0x706
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_CONV_STREAM_CHAN
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_CONV_STREAM_CHAN, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_CONV_STREAM_CHAN
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_CONV_STREAM_CHAN, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_CONV_STREAM_CHAN_STREAM_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|HDA_CMD_CONV_STREAM_CHAN_STREAM_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HDA_CMD_CONV_STREAM_CHAN_CHAN_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|HDA_CMD_CONV_STREAM_CHAN_CHAN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_CONV_STREAM_CHAN_STREAM
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_CONV_STREAM_CHAN_STREAM_MASK)>>			\     HDA_CMD_CONV_STREAM_CHAN_STREAM_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_CONV_STREAM_CHAN_CHAN
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_CONV_STREAM_CHAN_CHAN_MASK)>>			\     HDA_CMD_CONV_STREAM_CHAN_CHAN_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_CONV_STREAM_CHAN_STREAM
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)<< HDA_CMD_CONV_STREAM_CHAN_STREAM_SHIFT)&		\     HDA_CMD_CONV_STREAM_CHAN_STREAM_MASK)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_CONV_STREAM_CHAN_CHAN
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)<< HDA_CMD_CONV_STREAM_CHAN_CHAN_SHIFT)&			\     HDA_CMD_CONV_STREAM_CHAN_CHAN_MASK)
end_define

begin_comment
comment|/* Input Converter SDI Select */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_INPUT_CONVERTER_SDI_SELECT
value|0xf04
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_INPUT_CONVERTER_SDI_SELECT
value|0x704
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_INPUT_CONVERTER_SDI_SELECT
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_INPUT_CONVERTER_SDI_SELECT, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_INPUT_CONVERTER_SDI_SELECT
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_INPUT_CONVERTER_SDI_SELECT, (payload)))
end_define

begin_comment
comment|/* Pin Widget Control */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_PIN_WIDGET_CTRL
value|0xf07
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_PIN_WIDGET_CTRL
value|0x707
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_WIDGET_CTRL
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_PIN_WIDGET_CTRL, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_PIN_WIDGET_CTRL
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_PIN_WIDGET_CTRL, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_WIDGET_CTRL_HPHN_ENABLE_MASK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_WIDGET_CTRL_HPHN_ENABLE_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_WIDGET_CTRL_OUT_ENABLE_MASK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_WIDGET_CTRL_OUT_ENABLE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_WIDGET_CTRL_IN_ENABLE_MASK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_WIDGET_CTRL_IN_ENABLE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_WIDGET_CTRL_VREF_ENABLE_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_WIDGET_CTRL_VREF_ENABLE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_WIDGET_CTRL_HPHN_ENABLE
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_PIN_WIDGET_CTRL_HPHN_ENABLE_MASK)>>		\     HDA_CMD_GET_PIN_WIDGET_CTRL_HPHN_ENABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_WIDGET_CTRL_OUT_ENABLE
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_PIN_WIDGET_CTRL_OUT_ENABLE_MASK)>>		\     HDA_GET_CMD_PIN_WIDGET_CTRL_OUT_ENABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_WIDGET_CTRL_IN_ENABLE
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_PIN_WIDGET_CTRL_IN_ENABLE_MASK)>>		\     HDA_CMD_GET_PIN_WIDGET_CTRL_IN_ENABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_WIDGET_CTRL_VREF_ENABLE
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_PIN_WIDGET_CTRL_VREF_ENABLE_MASK)>>		\     HDA_CMD_GET_PIN_WIDGET_CTRL_VREF_ENABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_PIN_WIDGET_CTRL_HPHN_ENABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_PIN_WIDGET_CTRL_OUT_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_PIN_WIDGET_CTRL_IN_ENABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_PIN_WIDGET_CTRL_VREF_ENABLE_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_PIN_WIDGET_CTRL_VREF_ENABLE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_PIN_WIDGET_CTRL_VREF_ENABLE
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)<< HDA_CMD_SET_PIN_WIDGET_CTRL_VREF_ENABLE_SHIFT)&	\     HDA_CMD_SET_PIN_WIDGET_CTRL_VREF_ENABLE_MASK)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_PIN_WIDGET_CTRL_VREF_ENABLE_HIZ
value|0
end_define

begin_define
define|#
directive|define
name|HDA_CMD_PIN_WIDGET_CTRL_VREF_ENABLE_50
value|1
end_define

begin_define
define|#
directive|define
name|HDA_CMD_PIN_WIDGET_CTRL_VREF_ENABLE_GROUND
value|2
end_define

begin_define
define|#
directive|define
name|HDA_CMD_PIN_WIDGET_CTRL_VREF_ENABLE_80
value|4
end_define

begin_define
define|#
directive|define
name|HDA_CMD_PIN_WIDGET_CTRL_VREF_ENABLE_100
value|5
end_define

begin_comment
comment|/* Unsolicited Response */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_UNSOLICITED_RESPONSE
value|0xf08
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_UNSOLICITED_RESPONSE
value|0x708
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_UNSOLICITED_RESPONSE
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_UNSOLICITED_RESPONSE, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_UNSOLICITED_RESPONSE
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_UNSOLICITED_RESPONSE, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_UNSOLICITED_RESPONSE_ENABLE_MASK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_UNSOLICITED_RESPONSE_ENABLE_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_UNSOLICITED_RESPONSE_TAG_MASK
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_UNSOLICITED_RESPONSE_TAG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_UNSOLICITED_RESPONSE_ENABLE
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_UNSOLICITED_RESPONSE_ENABLE_MASK)>>		\     HDA_CMD_GET_UNSOLICITED_RESPONSE_ENABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_UNSOLICITED_RESPONSE_TAG
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_UNSOLICITED_RESPONSE_TAG_MASK)>>		\     HDA_CMD_GET_UNSOLICITED_RESPONSE_TAG_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_UNSOLICITED_RESPONSE_ENABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_UNSOLICITED_RESPONSE_TAG_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_UNSOLICITED_RESPONSE_TAG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_UNSOLICITED_RESPONSE_TAG
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)<< HDA_CMD_SET_UNSOLICITED_RESPONSE_TAG_SHIFT)&		\     HDA_CMD_SET_UNSOLICITED_RESPONSE_TAG_MASK)
end_define

begin_comment
comment|/* Pin Sense */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_PIN_SENSE
value|0xf09
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_PIN_SENSE
value|0x709
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_SENSE
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_PIN_SENSE, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_PIN_SENSE
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_PIN_SENSE, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_SENSE_PRESENCE_DETECT_MASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_SENSE_PRESENCE_DETECT_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_SENSE_IMP_SENSE_MASK
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_SENSE_IMP_SENSE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_SENSE_PRESENCE_DETECT
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_PIN_SENSE_PRESENCE_DETECT_MASK)>>		\     HDA_CMD_GET_PIN_SENSE_PRESENCE_DETECT_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_SENSE_IMP_SENSE
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_PIN_SENSE_IMP_SENSE_MASK)>>			\     HDA_CMD_GET_PIN_SENSE_IMP_SENSE_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_PIN_SENSE_IMP_SENSE_INVALID
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_PIN_SENSE_LEFT_CHANNEL
value|0x00
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_PIN_SENSE_RIGHT_CHANNEL
value|0x01
end_define

begin_comment
comment|/* EAPD/BTL Enable */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_EAPD_BTL_ENABLE
value|0xf0c
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_EAPD_BTL_ENABLE
value|0x70c
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_EAPD_BTL_ENABLE
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_EAPD_BTL_ENABLE, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_EAPD_BTL_ENABLE
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_EAPD_BTL_ENABLE, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_EAPD_BTL_ENABLE_LR_SWAP_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_EAPD_BTL_ENABLE_LR_SWAP_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_EAPD_BTL_ENABLE_EAPD_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_EAPD_BTL_ENABLE_EAPD_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_EAPD_BTL_ENABLE_BTL_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_EAPD_BTL_ENABLE_BTL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_EAPD_BTL_ENABLE_LR_SWAP
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_EAPD_BTL_ENABLE_LR_SWAP_MASK)>>		\     HDA_CMD_GET_EAPD_BTL_ENABLE_LR_SWAP_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_EAPD_BTL_ENABLE_EAPD
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_EAPD_BTL_ENABLE_EAPD_MASK)>>			\     HDA_CMD_GET_EAPD_BTL_ENABLE_EAPD_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_EAPD_BTL_ENABLE_BTL
parameter_list|(
name|rsp
parameter_list|)
define|\
value|(((rsp)& HDA_CMD_GET_EAPD_BTL_ENABLE_BTL_MASK)>>			\     HDA_CMD_GET_EAPD_BTL_ENABLE_BTL_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_EAPD_BTL_ENABLE_LR_SWAP
value|0x04
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_EAPD_BTL_ENABLE_EAPD
value|0x02
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_EAPD_BTL_ENABLE_BTL
value|0x01
end_define

begin_comment
comment|/* GPI Data */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_GPI_DATA
value|0xf10
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_GPI_DATA
value|0x710
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_GPI_DATA
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_GPI_DATA, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_GPI_DATA
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_GPI_DATA, (payload)))
end_define

begin_comment
comment|/* GPI Wake Enable Mask */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_GPI_WAKE_ENABLE_MASK
value|0xf11
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_GPI_WAKE_ENABLE_MASK
value|0x711
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_GPI_WAKE_ENABLE_MASK
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_GPI_WAKE_ENABLE_MASK, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_GPI_WAKE_ENABLE_MASK
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_GPI_WAKE_ENABLE_MASK, (payload)))
end_define

begin_comment
comment|/* GPI Unsolicited Enable Mask */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_GPI_UNSOLICITED_ENABLE_MASK
value|0xf12
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_GPI_UNSOLICITED_ENABLE_MASK
value|0x712
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_GPI_UNSOLICITED_ENABLE_MASK
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_GPI_UNSOLICITED_ENABLE_MASK, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_GPI_UNSOLICITED_ENABLE_MASK
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_GPI_UNSOLICITED_ENABLE_MASK, (payload)))
end_define

begin_comment
comment|/* GPI Sticky Mask */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_GPI_STICKY_MASK
value|0xf13
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_GPI_STICKY_MASK
value|0x713
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_GPI_STICKY_MASK
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_GPI_STICKY_MASK, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_GPI_STICKY_MASK
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_GPI_STICKY_MASK, (payload)))
end_define

begin_comment
comment|/* GPO Data */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_GPO_DATA
value|0xf14
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_GPO_DATA
value|0x714
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_GPO_DATA
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_GPO_DATA, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_GPO_DATA
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_GPO_DATA, (payload)))
end_define

begin_comment
comment|/* GPIO Data */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_GPIO_DATA
value|0xf15
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_GPIO_DATA
value|0x715
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_GPIO_DATA
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_GPIO_DATA, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_GPIO_DATA
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_GPIO_DATA, (payload)))
end_define

begin_comment
comment|/* GPIO Enable Mask */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_GPIO_ENABLE_MASK
value|0xf16
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_GPIO_ENABLE_MASK
value|0x716
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_GPIO_ENABLE_MASK
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_GPIO_ENABLE_MASK, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_GPIO_ENABLE_MASK
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_GPIO_ENABLE_MASK, (payload)))
end_define

begin_comment
comment|/* GPIO Direction */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_GPIO_DIRECTION
value|0xf17
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_GPIO_DIRECTION
value|0x717
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_GPIO_DIRECTION
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_GPIO_DIRECTION, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_GPIO_DIRECTION
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_GPIO_DIRECTION, (payload)))
end_define

begin_comment
comment|/* GPIO Wake Enable Mask */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_GPIO_WAKE_ENABLE_MASK
value|0xf18
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_GPIO_WAKE_ENABLE_MASK
value|0x718
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_GPIO_WAKE_ENABLE_MASK
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_GPIO_WAKE_ENABLE_MASK, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_GPIO_WAKE_ENABLE_MASK
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_GPIO_WAKE_ENABLE_MASK, (payload)))
end_define

begin_comment
comment|/* GPIO Unsolicited Enable Mask */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_GPIO_UNSOLICITED_ENABLE_MASK
value|0xf19
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_GPIO_UNSOLICITED_ENABLE_MASK
value|0x719
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_GPIO_UNSOLICITED_ENABLE_MASK
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_GPIO_UNSOLICITED_ENABLE_MASK, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_GPIO_UNSOLICITED_ENABLE_MASK
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_GPIO_UNSOLICITED_ENABLE_MASK, (payload)))
end_define

begin_comment
comment|/* GPIO_STICKY_MASK */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_GPIO_STICKY_MASK
value|0xf1a
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_GPIO_STICKY_MASK
value|0x71a
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_GPIO_STICKY_MASK
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_GPIO_STICKY_MASK, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_GPIO_STICKY_MASK
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_GPIO_STICKY_MASK, (payload)))
end_define

begin_comment
comment|/* Beep Generation */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_BEEP_GENERATION
value|0xf0a
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_BEEP_GENERATION
value|0x70a
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_BEEP_GENERATION
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_BEEP_GENERATION, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_BEEP_GENERATION
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_BEEP_GENERATION, (payload)))
end_define

begin_comment
comment|/* Volume Knob */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_VOLUME_KNOB
value|0xf0f
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_VOLUME_KNOB
value|0x70f
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_VOLUME_KNOB
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_VOLUME_KNOB, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_VOLUME_KNOB
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_VOLUME_KNOB, (payload)))
end_define

begin_comment
comment|/* Subsystem ID */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_SUBSYSTEM_ID
value|0xf20
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_SUSBYSTEM_ID1
value|0x720
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_SUBSYSTEM_ID2
value|0x721
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_SUBSYSTEM_ID3
value|0x722
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_SUBSYSTEM_ID4
value|0x723
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_SUBSYSTEM_ID
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_SUBSYSTEM_ID, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_SUBSYSTEM_ID1
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_SUSBYSTEM_ID1, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_SUBSYSTEM_ID2
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_SUSBYSTEM_ID2, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_SUBSYSTEM_ID3
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_SUSBYSTEM_ID3, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_SUBSYSTEM_ID4
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_SUSBYSTEM_ID4, (payload)))
end_define

begin_comment
comment|/* Configuration Default */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_CONFIGURATION_DEFAULT
value|0xf1c
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_CONFIGURATION_DEFAULT1
value|0x71c
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_CONFIGURATION_DEFAULT2
value|0x71d
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_CONFIGURATION_DEFAULT3
value|0x71e
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_CONFIGURATION_DEFAULT4
value|0x71f
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_CONFIGURATION_DEFAULT
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_CONFIGURATION_DEFAULT, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_CONFIGURATION_DEFAULT1
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_CONFIGURATION_DEFAULT1, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_CONFIGURATION_DEFAULT2
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_CONFIGURATION_DEFAULT2, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_CONFIGURATION_DEFAULT3
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_CONFIGURATION_DEFAULT3, (payload)))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_CONFIGURATION_DEFAULT4
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_CONFIGURATION_DEFAULT4, (payload)))
end_define

begin_comment
comment|/* Stripe Control */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_GET_STRIPE_CONTROL
value|0xf24
end_define

begin_define
define|#
directive|define
name|HDA_CMD_VERB_SET_STRIPE_CONTROL
value|0x724
end_define

begin_define
define|#
directive|define
name|HDA_CMD_SET_STRIPE_CONTROL
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_GET_STRIPE_CONTROL, 0x0))
end_define

begin_define
define|#
directive|define
name|HDA_CMD_GET_STRIPE_CONTROL
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|,
name|payload
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_SET_STRIPE_CONTROL, (payload)))
end_define

begin_comment
comment|/* Function Reset */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_VERB_FUNCTION_RESET
value|0x7ff
end_define

begin_define
define|#
directive|define
name|HDA_CMD_FUNCTION_RESET
parameter_list|(
name|cad
parameter_list|,
name|nid
parameter_list|)
define|\
value|(HDA_CMD_12BIT((cad), (nid),					\     HDA_CMD_VERB_FUNCTION_RESET, 0x0))
end_define

begin_comment
comment|/****************************************************************************  * HDA Device Parameters  ****************************************************************************/
end_comment

begin_comment
comment|/* Vendor ID */
end_comment

begin_define
define|#
directive|define
name|HDA_PARAM_VENDOR_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_VENDOR_ID_VENDOR_ID_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_VENDOR_ID_VENDOR_ID_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_VENDOR_ID_DEVICE_ID_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_VENDOR_ID_DEVICE_ID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_VENDOR_ID_VENDOR_ID
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_VENDOR_ID_VENDOR_ID_MASK)>>			\     HDA_PARAM_VENDOR_ID_VENDOR_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_VENDOR_ID_DEVICE_ID
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_VENDOR_ID_DEVICE_ID_MASK)>>			\     HDA_PARAM_VENDOR_ID_DEVICE_ID_SHIFT)
end_define

begin_comment
comment|/* Revision ID */
end_comment

begin_define
define|#
directive|define
name|HDA_PARAM_REVISION_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_REVISION_ID_MAJREV_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_REVISION_ID_MAJREV_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_REVISION_ID_MINREV_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_REVISION_ID_MINREV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_REVISION_ID_REVISION_ID_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_REVISION_ID_REVISION_ID_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_REVISION_ID_STEPPING_ID_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_REVISION_ID_STEPPING_ID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_REVISION_ID_MAJREV
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_REVISION_ID_MAJREV_MASK)>>			\     HDA_PARAM_REVISION_ID_MAJREV_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_REVISION_ID_MINREV
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_REVISION_ID_MINREV_MASK)>>			\     HDA_PARAM_REVISION_ID_MINREV_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_REVISION_ID_REVISION_ID
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_REVISION_ID_REVISION_ID_MASK)>>		\     HDA_PARAM_REVISION_ID_REVISION_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_REVISION_ID_STEPPING_ID
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_REVISION_ID_STEPPING_ID_MASK)>>		\     HDA_PARAM_REVISION_ID_STEPPING_ID_SHIFT)
end_define

begin_comment
comment|/* Subordinate Node Cound */
end_comment

begin_define
define|#
directive|define
name|HDA_PARAM_SUB_NODE_COUNT
value|0x04
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUB_NODE_COUNT_START_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUB_NODE_COUNT_START_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUB_NODE_COUNT_TOTAL_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUB_NODE_COUNT_TOTAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUB_NODE_COUNT_START
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUB_NODE_COUNT_START_MASK)>>			\     HDA_PARAM_SUB_NODE_COUNT_START_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUB_NODE_COUNT_TOTAL
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUB_NODE_COUNT_TOTAL_MASK)>>			\     HDA_PARAM_SUB_NODE_COUNT_TOTAL_SHIFT)
end_define

begin_comment
comment|/* Function Group Type */
end_comment

begin_define
define|#
directive|define
name|HDA_PARAM_FCT_GRP_TYPE
value|0x05
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_FCT_GRP_TYPE_UNSOL_MASK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_FCT_GRP_TYPE_UNSOL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_FCT_GRP_TYPE_NODE_TYPE_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_FCT_GRP_TYPE_NODE_TYPE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_FCT_GRP_TYPE_UNSOL
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_FCT_GRP_TYPE_UNSOL_MASK)>>			\     HDA_PARAM_FCT_GROUP_TYPE_UNSOL_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_FCT_GRP_TYPE_NODE_TYPE
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_FCT_GRP_TYPE_NODE_TYPE_MASK)>>		\     HDA_PARAM_FCT_GRP_TYPE_NODE_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_FCT_GRP_TYPE_NODE_TYPE_AUDIO
value|0x01
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_FCT_GRP_TYPE_NODE_TYPE_MODEM
value|0x02
end_define

begin_comment
comment|/* Audio Function Group Capabilities */
end_comment

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_FCT_GRP_CAP
value|0x08
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_FCT_GRP_CAP_BEEP_GEN_MASK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_FCT_GRP_CAP_BEEP_GEN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_FCT_GRP_CAP_INPUT_DELAY_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_FCT_GRP_CAP_INPUT_DELAY_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_FCT_GRP_CAP_OUTPUT_DELAY_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_FCT_GRP_CAP_OUTPUT_DELAY_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_FCT_GRP_CAP_BEEP_GEN
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_FCT_GRP_CAP_BEEP_GEN_MASK)>>		\     HDA_PARAM_AUDIO_FCT_GRP_CAP_BEEP_GEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_FCT_GRP_CAP_INPUT_DELAY
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_FCT_GRP_CAP_INPUT_DELAY_MASK)>>	\     HDA_PARAM_AUDIO_FCT_GRP_CAP_INPUT_DELAY_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_FCT_GRP_CAP_OUTPUT_DELAY
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_FCT_GRP_CAP_OUTPUT_DELAY_MASK)>>	\     HDA_PARAM_AUDIO_FCT_GRP_CAP_OUTPUT_DELAY_SHIFT)
end_define

begin_comment
comment|/* Audio Widget Capabilities */
end_comment

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP
value|0x09
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_DELAY_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_DELAY_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_LR_SWAP_MASK
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_LR_SWAP_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_POWER_CTRL_MASK
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_POWER_CTRL_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_DIGITAL_MASK
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_DIGITAL_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_CONN_LIST_MASK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_CONN_LIST_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_UNSOL_CAP_MASK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_UNSOL_CAP_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_PROC_WIDGET_MASK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_PROC_WIDGET_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_STRIPE_MASK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_STRIPE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_FORMAT_OVR_MASK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_FORMAT_OVR_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_AMP_OVR_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_AMP_OVR_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_OUT_AMP_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_OUT_AMP_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_IN_AMP_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_IN_AMP_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_STEREO_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_STEREO_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_TYPE
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_MASK)>>		\     HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_DELAY
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_WIDGET_CAP_DELAY_MASK)>>		\     HDA_PARAM_AUDIO_WIDGET_CAP_DELAY_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_LR_SWAP
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_WIDGET_CAP_LR_SWAP_MASK)>>		\     HDA_PARAM_AUDIO_WIDGET_CAP_LR_SWAP_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_POWER_CTRL
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_WIDGET_CAP_POWER_CTRL_MASK)>>		\     HDA_PARAM_AUDIO_WIDGET_CAP_POWER_CTRL_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_DIGITAL
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_WIDGET_CAP_DIGITAL_MASK)>>		\     HDA_PARAM_AUDIO_WIDGET_CAP_DIGITAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_CONN_LIST
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_WIDGET_CAP_CONN_LIST_MASK)>>		\     HDA_PARAM_AUDIO_WIDGET_CAP_CONN_LIST_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_UNSOL_CAP
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_WIDGET_CAP_UNSOL_CAP_MASK)>>		\     HDA_PARAM_AUDIO_WIDGET_CAP_UNSOL_CAP_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_PROC_WIDGET
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_WIDGET_CAP_PROC_WIDGET_MASK)>>		\     HDA_PARAM_AUDIO_WIDGET_CAP_PROC_WIDGET_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_STRIPE
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_WIDGET_CAP_STRIPE_MASK)>>		\     HDA_PARAM_AUDIO_WIDGET_CAP_STRIPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_FORMAT_OVR
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_WIDGET_CAP_FORMAT_OVR_MASK)>>		\     HDA_PARAM_AUDIO_WIDGET_CAP_FORMAT_OVR_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_AMP_OVR
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_WIDGET_CAP_AMP_OVR_MASK)>>		\     HDA_PARAM_AUDIO_WIDGET_CAP_AMP_OVR_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_OUT_AMP
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_WIDGET_CAP_OUT_AMP_MASK)>>		\     HDA_PARAM_AUDIO_WIDGET_CAP_OUT_AMP_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_IN_AMP
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_WIDGET_CAP_IN_AMP_MASK)>>		\     HDA_PARAM_AUDIO_WIDGET_CAP_IN_AMP_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_STEREO
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_AUDIO_WIDGET_CAP_STEREO_MASK)>>		\     HDA_PARAM_AUDIO_WIDGET_CAP_STEREO_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_AUDIO_OUTPUT
value|0x0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_AUDIO_INPUT
value|0x1
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_AUDIO_MIXER
value|0x2
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_AUDIO_SELECTOR
value|0x3
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_PIN_COMPLEX
value|0x4
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_POWER_WIDGET
value|0x5
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_VOLUME_WIDGET
value|0x6
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_BEEP_WIDGET
value|0x7
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_VENDOR_WIDGET
value|0xf
end_define

begin_comment
comment|/* Supported PCM Size, Rates */
end_comment

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE
value|0x0a
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_32BIT_MASK
value|0x00100000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_32BIT_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_24BIT_MASK
value|0x00080000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_24BIT_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_20BIT_MASK
value|0x00040000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_20BIT_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_16BIT_MASK
value|0x00020000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_16BIT_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_8BIT_MASK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_8BIT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_8KHZ_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_8KHZ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_11KHZ_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_11KHZ_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_16KHZ_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_16KHZ_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_22KHZ_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_22KHZ_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_32KHZ_MASK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_32KHZ_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_44KHZ_MASK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_44KHZ_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_48KHZ_MASK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_48KHZ_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_88KHZ_MASK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_88KHZ_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_96KHZ_MASK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_96KHZ_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_176KHZ_MASK
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_176KHZ_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_192KHZ_MASK
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_192KHZ_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_384KHZ_MASK
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_384KHZ_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_32BIT
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_32BIT_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_32BIT_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_24BIT
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_24BIT_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_24BIT_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_20BIT
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_20BIT_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_20BIT_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_16BIT
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_16BIT_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_16BIT_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_8BIT
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_8BIT_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_8BIT_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_8KHZ
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_8KHZ_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_8KHZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_11KHZ
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_11KHZ_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_11KHZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_16KHZ
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_16KHZ_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_16KHZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_22KHZ
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_22KHZ_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_22KHZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_32KHZ
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_32KHZ_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_32KHZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_44KHZ
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_44KHZ_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_44KHZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_48KHZ
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_48KHZ_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_48KHZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_88KHZ
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_88KHZ_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_88KHZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_96KHZ
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_96KHZ_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_96KHZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_176KHZ
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_176KHZ_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_176KHZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_192KHZ
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_192KHZ_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_192KHZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_PCM_SIZE_RATE_384KHZ
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_PCM_SIZE_RATE_384KHZ_MASK)>>		\     HDA_PARAM_SUPP_PCM_SIZE_RATE_384KHZ_SHIFT)
end_define

begin_comment
comment|/* Supported Stream Formats */
end_comment

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_STREAM_FORMATS
value|0x0b
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_STREAM_FORMATS_AC3_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_STREAM_FORMATS_AC3_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_STREAM_FORMATS_FLOAT32_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_STREAM_FORMATS_FLOAT32_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_STREAM_FORMATS_PCM_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_STREAM_FORMATS_PCM_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_STREAM_FORMATS_AC3
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_STREAM_FORMATS_AC3_MASK)>>		\     HDA_PARAM_SUPP_STREAM_FORMATS_AC3_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_STREAM_FORMATS_FLOAT32
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_STREAM_FORMATS_FLOAT32_MASK)>>		\     HDA_PARAM_SUPP_STREAM_FORMATS_FLOAT32_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_STREAM_FORMATS_PCM
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_STREAM_FORMATS_PCM_MASK)>>		\     HDA_PARAM_SUPP_STREAM_FORMATS_PCM_SHIFT)
end_define

begin_comment
comment|/* Pin Capabilities */
end_comment

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP
value|0x0c
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_EAPD_CAP_MASK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_EAPD_CAP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_100_MASK
value|0x00002000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_100_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_80_MASK
value|0x00001000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_80_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_GROUND_MASK
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_GROUND_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_50_MASK
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_50_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_HIZ_MASK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_HIZ_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_BALANCED_IO_PINS_MASK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_BALANCED_IO_PINS_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_INPUT_CAP_MASK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_INPUT_CAP_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_OUTPUT_CAP_MASK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_OUTPUT_CAP_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_HEADPHONE_CAP_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_HEADPHONE_CAP_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_PRESENCE_DETECT_CAP_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_PRESENCE_DETECT_CAP_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_TRIGGER_REQD_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_TRIGGER_REQD_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_IMP_SENSE_CAP_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_IMP_SENSE_CAP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_EAPD_CAP
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_PIN_CAP_EAPD_CAP_MASK)>>			\     HDA_PARAM_PIN_CAP_EAPD_CAP_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_PIN_CAP_VREF_CTRL_MASK)>>			\     HDA_PARAM_PIN_CAP_VREF_CTRL_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_100
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_PIN_CAP_VREF_CTRL_100_MASK)>>		\     HDA_PARAM_PIN_CAP_VREF_CTRL_100_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_80
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_PIN_CAP_VREF_CTRL_80_MASK)>>			\     HDA_PARAM_PIN_CAP_VREF_CTRL_80_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_GROUND
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_PIN_CAP_VREF_CTRL_GROUND_MASK)>>		\     HDA_PARAM_PIN_CAP_VREF_CTRL_GROUND_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_50
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_PIN_CAP_VREF_CTRL_50_MASK)>>			\     HDA_PARAM_PIN_CAP_VREF_CTRL_50_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_VREF_CTRL_HIZ
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_PIN_CAP_VREF_CTRL_HIZ_MASK)>>		\     HDA_PARAM_PIN_CAP_VREF_CTRL_HIZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_BALANCED_IO_PINS
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_PIN_CAP_BALANCED_IO_PINS_MASK)>>		\     HDA_PARAM_PIN_CAP_BALANCED_IO_PINS_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_INPUT_CAP
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_PIN_CAP_INPUT_CAP_MASK)>>			\     HDA_PARAM_PIN_CAP_INPUT_CAP_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_OUTPUT_CAP
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_PIN_CAP_OUTPUT_CAP_MASK)>>			\     HDA_PARAM_PIN_CAP_OUTPUT_CAP_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_HEADPHONE_CAP
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_PIN_CAP_HEADPHONE_CAP_MASK)>>		\     HDA_PARAM_PIN_CAP_HEADPHONE_CAP_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_PRESENCE_DETECT_CAP
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_PIN_CAP_PRESENCE_DETECT_CAP_MASK)>>		\     HDA_PARAM_PIN_CAP_PRESENCE_DETECT_CAP_MASK)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_TRIGGER_REQD
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_PIN_CAP_TRIGGER_REQD_MASK)>>			\     HDA_PARAM_PIN_CAP_TRIGGER_REQD_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PIN_CAP_IMP_SENSE_CAP
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_PIN_CAP_IMP_SENSE_CAP_MASK)>>		\     HDA_PARAM_PIN_CAP_IMP_SENSE_CAP_SHIFT)
end_define

begin_comment
comment|/* Input Amplifier Capabilities */
end_comment

begin_define
define|#
directive|define
name|HDA_PARAM_INPUT_AMP_CAP
value|0x0d
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_INPUT_AMP_CAP_MUTE_CAP_MASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_INPUT_AMP_CAP_MUTE_CAP_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_INPUT_AMP_CAP_STEPSIZE_MASK
value|0x007f0000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_INPUT_AMP_CAP_STEPSIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_INPUT_AMP_CAP_NUMSTEPS_MASK
value|0x00007f00
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_INPUT_AMP_CAP_NUMSTEPS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_INPUT_AMP_CAP_OFFSET_MASK
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_INPUT_AMP_CAP_OFFSET_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_INPUT_AMP_CAP_MUTE_CAP
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_INPUT_AMP_CAP_MUTE_CAP_MASK)>>		\     HDA_PARAM_INPUT_AMP_CAP_MUTE_CAP_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_INPUT_AMP_CAP_STEPSIZE
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_INPUT_AMP_CAP_STEPSIZE_MASK)>>		\     HDA_PARAM_INPUT_AMP_CAP_STEPSIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_INPUT_AMP_CAP_NUMSTEPS
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_INPUT_AMP_CAP_NUMSTEPS_MASK)>>		\     HDA_PARAM_INPUT_AMP_CAP_NUMSTEPS_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_INPUT_AMP_CAP_OFFSET
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_INPUT_AMP_CAP_OFFSET_MASK)>>			\     HDA_PARAM_INPUT_AMP_CAP_OFFSET_SHIFT)
end_define

begin_comment
comment|/* Output Amplifier Capabilities */
end_comment

begin_define
define|#
directive|define
name|HDA_PARAM_OUTPUT_AMP_CAP
value|0x12
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_OUTPUT_AMP_CAP_MUTE_CAP_MASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_OUTPUT_AMP_CAP_MUTE_CAP_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_OUTPUT_AMP_CAP_STEPSIZE_MASK
value|0x007f0000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_OUTPUT_AMP_CAP_STEPSIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_OUTPUT_AMP_CAP_NUMSTEPS_MASK
value|0x00007f00
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_OUTPUT_AMP_CAP_NUMSTEPS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_OUTPUT_AMP_CAP_OFFSET_MASK
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_OUTPUT_AMP_CAP_OFFSET_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_OUTPUT_AMP_CAP_MUTE_CAP
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_OUTPUT_AMP_CAP_MUTE_CAP_MASK)>>		\     HDA_PARAM_OUTPUT_AMP_CAP_MUTE_CAP_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_OUTPUT_AMP_CAP_STEPSIZE
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_OUTPUT_AMP_CAP_STEPSIZE_MASK)>>		\     HDA_PARAM_OUTPUT_AMP_CAP_STEPSIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_OUTPUT_AMP_CAP_NUMSTEPS
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_OUTPUT_AMP_CAP_NUMSTEPS_MASK)>>		\     HDA_PARAM_OUTPUT_AMP_CAP_NUMSTEPS_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_OUTPUT_AMP_CAP_OFFSET
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_OUTPUT_AMP_CAP_OFFSET_MASK)>>		\     HDA_PARAM_OUTPUT_AMP_CAP_OFFSET_SHIFT)
end_define

begin_comment
comment|/* Connection List Length */
end_comment

begin_define
define|#
directive|define
name|HDA_PARAM_CONN_LIST_LENGTH
value|0x0e
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_CONN_LIST_LENGTH_LONG_FORM_MASK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_CONN_LIST_LENGTH_LONG_FORM_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_CONN_LIST_LENGTH_LIST_LENGTH_MASK
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_CONN_LIST_LENGTH_LIST_LENGTH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_CONN_LIST_LENGTH_LONG_FORM
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_CONN_LIST_LENGTH_LONG_FORM_MASK)>>		\     HDA_PARAM_CONN_LIST_LENGTH_LONG_FORM_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_CONN_LIST_LENGTH_LIST_LENGTH
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_CONN_LIST_LENGTH_LIST_LENGTH_MASK)>>		\     HDA_PARAM_CONN_LIST_LENGTH_LIST_LENGTH_SHIFT)
end_define

begin_comment
comment|/* Supported Power States */
end_comment

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_POWER_STATES
value|0x0f
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_POWER_STATES_D3_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_POWER_STATES_D3_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_POWER_STATES_D2_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_POWER_STATES_D2_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_POWER_STATES_D1_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_POWER_STATES_D1_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_POWER_STATES_D0_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_POWER_STATES_D0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_POWER_STATES_D3
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_POWER_STATES_D3_MASK)>>			\     HDA_PARAM_SUPP_POWER_STATES_D3_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_POWER_STATES_D2
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_POWER_STATES_D2_MASK)>>			\     HDA_PARAM_SUPP_POWER_STATES_D2_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_POWER_STATES_D1
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_POWER_STATES_D1_MASK)>>			\     HDA_PARAM_SUPP_POWER_STATES_D1_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_SUPP_POWER_STATES_D0
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_SUPP_POWER_STATES_D0_MASK)>>			\     HDA_PARAM_SUPP_POWER_STATES_D0_SHIFT)
end_define

begin_comment
comment|/* Processing Capabilities */
end_comment

begin_define
define|#
directive|define
name|HDA_PARAM_PROCESSING_CAP
value|0x10
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PROCESSING_CAP_NUMCOEFF_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PROCESSING_CAP_NUMCOEFF_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PROCESSING_CAP_BENIGN_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PROCESSING_CAP_BENIGN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PROCESSING_CAP_NUMCOEFF
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_PROCESSING_CAP_NUMCOEFF_MASK)>>		\     HDA_PARAM_PROCESSING_CAP_NUMCOEFF_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_PROCESSING_CAP_BENIGN
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_PROCESSING_CAP_BENIGN_MASK)>>		\     HDA_PARAM_PROCESSING_CAP_BENIGN_SHIFT)
end_define

begin_comment
comment|/* GPIO Count */
end_comment

begin_define
define|#
directive|define
name|HDA_PARAM_GPIO_COUNT
value|0x11
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_GPIO_COUNT_GPI_WAKE_MASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_GPIO_COUNT_GPI_WAKE_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_GPIO_COUNT_GPI_UNSOL_MASK
value|0x40000000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_GPIO_COUNT_GPI_UNSOL_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_GPIO_COUNT_NUM_GPI_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_GPIO_COUNT_NUM_GPI_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_GPIO_COUNT_NUM_GPO_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_GPIO_COUNT_NUM_GPO_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_GPIO_COUNT_NUM_GPIO_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_GPIO_COUNT_NUM_GPIO_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_GPIO_COUNT_GPI_WAKE
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_GPIO_COUNT_GPI_WAKE_MASK)>>			\     HDA_PARAM_GPIO_COUNT_GPI_WAKE_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_GPIO_COUNT_GPI_UNSOL
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_GPIO_COUNT_GPI_UNSOL_MASK)>>			\     HDA_PARAM_GPIO_COUNT_GPI_UNSOL_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_GPIO_COUNT_NUM_GPI
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_GPIO_COUNT_NUM_GPI_MASK)>>			\     HDA_PARAM_GPIO_COUNT_NUM_GPI_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_GPIO_COUNT_NUM_GPO
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_GPIO_COUNT_NUM_GPO_MASK)>>			\     HDA_PARAM_GPIO_COUNT_NUM_GPO_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_GPIO_COUNT_NUM_GPIO
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_GPIO_COUNT_NUM_GPIO_MASK)>>			\     HDA_PARAM_GPIO_COUNT_NUM_GPIO_SHIFT)
end_define

begin_comment
comment|/* Volume Knob Capabilities */
end_comment

begin_define
define|#
directive|define
name|HDA_PARAM_VOLUME_KNOB_CAP
value|0x13
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_VOLUME_KNOB_CAP_DELTA_MASK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_VOLUME_KNOB_CAP_DELTA_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_VOLUME_KNOB_CAP_NUM_STEPS_MASK
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_VOLUME_KNOB_CAP_NUM_STEPS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_VOLUME_KNOB_CAP_DELTA
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_VOLUME_KNOB_CAP_DELTA_MASK)>>		\     HDA_PARAM_VOLUME_KNOB_CAP_DELTA_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_PARAM_VOLUME_KNOB_CAP_NUM_STEPS
parameter_list|(
name|param
parameter_list|)
define|\
value|(((param)& HDA_PARAM_VOLUME_KNOB_CAP_NUM_STEPS_MASK)>>		\     HDA_PARAM_VOLUME_KNOB_CAP_NUM_STEPS_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_SEQUENCE_MASK
value|0x00000000f
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_ASSOCIATION_MASK
value|0x0000000f0
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_MISC_MASK
value|0x000000f00
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_COLOR_MASK
value|0x00000f000
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_CONNECTION_TYPE_MASK
value|0x000f00000
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_DEVICE_MASK
value|0x000f00000
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_LOCATION_MASK
value|0x03f000000
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_CONNECTIVITY_MASK
value|0x0c0000000
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_CONNECTIVITY_JACK
value|(0<<30)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_CONNECTIVITY_NONE
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_CONNECTIVITY_FIXED
value|(2<<30)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_CONNECTIVITY_BOTH
value|(3<<30)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_DEVICE_LINE_OUT
value|(0<<20)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_DEVICE_SPEAKER
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_DEVICE_HP_OUT
value|(2<<20)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_DEVICE_CD
value|(3<<20)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_DEVICE_SPDIF_OUT
value|(4<<20)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_DEVICE_DIGITAL_OTHER_OUT
value|(5<<20)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_DEVICE_MODEM_LINE
value|(6<<20)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_DEVICE_MODEM_HANDSET
value|(7<<20)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_DEVICE_LINE_IN
value|(8<<20)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_DEVICE_AUX
value|(9<<20)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_DEVICE_MIC_IN
value|(10<<20)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_DEVICE_TELEPHONY
value|(11<<20)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_DEVICE_SPDIF_IN
value|(12<<20)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_DEVICE_DIGITAL_OTHER_IN
value|(13<<20)
end_define

begin_define
define|#
directive|define
name|HDA_CONFIG_DEFAULTCONF_DEVICE_OTHER
value|(15<<20)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

