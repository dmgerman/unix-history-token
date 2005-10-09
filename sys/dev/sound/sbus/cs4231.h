begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Ken Hornstein and John Kohl.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD   *	  Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its   *    contributors may be used to endorse or promote products derived   *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * Register defs for Crystal Semiconductor CS4231 Audio Codec/mixer  * chip, used on Gravis UltraSound MAX cards.  *  * Block diagram:  *             +----------------------------------------------------+  *             |						    |  *             |   +----------------------------------------------+ |  *	       |   |mixed in       +-+  		          | |  *	       |   +------------>--| |  		          | |  *             | mic in            | |			          | |  *   Mic --+-->| --------- GAIN ->-| |			          | |  *         |   | AUX 1 in          |M|				  | |  *   GF1 --)-->| -------------+-->-|U|				  | |  *	   |   | Line in      |	   |X|---- GAIN ----------+	  | |  *  Line --)-->| ---------+---)-->-| |			  |	  | |  *	   |   |	  |   |    | |			  |	  | |  *	   |   |	  |   |    +-+		         ADC 	  | |  *	   |   |	  |   |      		          | 	  | |  *	   |   |	  |   |				  |	  | |  *	   |   |	  |   +--- L/M --\		  |	  | | AMP-->  *	   |   |	  |   	   	  \		  |	  | |  |  *	   |   |	  |   	   	   \	          |	  | |  |  *	   |   |	  +---- L/M -------O-->--+--------)-------+-|--+-> line  *	   |   |   mono in	       	  /|     |        |	    |  *	   +---|-->------------ L/M -----/ |     |        |	    |  *	       |   AUX 2 in		   |     |        |	    |  *  CD --------|-->------------ L/M -------+    L/M       |	    |  *	       |				 |        v	    |  *	       |				 |        |	    |  *	       |				DAC       |	    |  *	       |				 |        |	    |  *             +----------------------------------------------------+  *	       					 |        |  *						 |        |  *						 v        v  *     	       	       	       	       	       	  Pc BUS (DISK) ???  *  * Documentation for this chip can be found at:  *	http://www.cirrus.com/products/overviews/cs4231.html  */
end_comment

begin_comment
comment|/*  * This file was merged from two header files.(ad1848reg.h and cs4231reg.h)  * And the suffix AD1848 and SP was changed to CS4231 and CS respectively.  */
end_comment

begin_comment
comment|/* CS4231 direct registers */
end_comment

begin_define
define|#
directive|define
name|CS4231_IADDR
value|0x00
end_define

begin_define
define|#
directive|define
name|CS4231_IDATA
value|0x01
end_define

begin_define
define|#
directive|define
name|CS4231_STATUS
value|0x02
end_define

begin_define
define|#
directive|define
name|CS4231_PIO
value|0x03
end_define

begin_comment
comment|/* Index address register */
end_comment

begin_define
define|#
directive|define
name|CS_IN_INIT
value|0x80
end_define

begin_define
define|#
directive|define
name|MODE_CHANGE_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|TRANSFER_DISABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|ADDRESS_MASK
value|0xe0
end_define

begin_comment
comment|/* Status bits */
end_comment

begin_define
define|#
directive|define
name|INTERRUPT_STATUS
value|0x01
end_define

begin_define
define|#
directive|define
name|PLAYBACK_READY
value|0x02
end_define

begin_define
define|#
directive|define
name|PLAYBACK_LEFT
value|0x04
end_define

begin_comment
comment|/* pbright is not left */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_UPPER
value|0x08
end_define

begin_comment
comment|/* bplower is not upper */
end_comment

begin_define
define|#
directive|define
name|SAMPLE_ERROR
value|0x10
end_define

begin_define
define|#
directive|define
name|CAPTURE_READY
value|0x20
end_define

begin_define
define|#
directive|define
name|CAPTURE_LEFT
value|0x40
end_define

begin_comment
comment|/* cpright is not left */
end_comment

begin_define
define|#
directive|define
name|CAPTURE_UPPER
value|0x80
end_define

begin_comment
comment|/* cplower is not upper */
end_comment

begin_comment
comment|/* CS4231 indirect mapped registers */
end_comment

begin_define
define|#
directive|define
name|CS_LEFT_INPUT_CONTROL
value|0x00
end_define

begin_define
define|#
directive|define
name|CS_RIGHT_INPUT_CONTROL
value|0x01
end_define

begin_define
define|#
directive|define
name|CS_LEFT_AUX1_CONTROL
value|0x02
end_define

begin_define
define|#
directive|define
name|CS_RIGHT_AUX1_CONTROL
value|0x03
end_define

begin_define
define|#
directive|define
name|CS_LEFT_AUX2_CONTROL
value|0x04
end_define

begin_define
define|#
directive|define
name|CS_RIGHT_AUX2_CONTROL
value|0x05
end_define

begin_define
define|#
directive|define
name|CS_LEFT_OUTPUT_CONTROL
value|0x06
end_define

begin_define
define|#
directive|define
name|CS_RIGHT_OUTPUT_CONTROL
value|0x07
end_define

begin_define
define|#
directive|define
name|CS_CLOCK_DATA_FORMAT
value|0x08
end_define

begin_define
define|#
directive|define
name|CS_INTERFACE_CONFIG
value|0x09
end_define

begin_define
define|#
directive|define
name|CS_PIN_CONTROL
value|0x0a
end_define

begin_define
define|#
directive|define
name|CS_TEST_AND_INIT
value|0x0b
end_define

begin_define
define|#
directive|define
name|CS_MISC_INFO
value|0x0c
end_define

begin_define
define|#
directive|define
name|CS_DIGITAL_MIX
value|0x0d
end_define

begin_define
define|#
directive|define
name|CS_UPPER_BASE_COUNT
value|0x0e
end_define

begin_define
define|#
directive|define
name|CS_LOWER_BASE_COUNT
value|0x0f
end_define

begin_comment
comment|/* CS4231/AD1845 mode2 registers; added to AD1848 registers */
end_comment

begin_define
define|#
directive|define
name|CS_ALT_FEATURE1
value|0x10
end_define

begin_define
define|#
directive|define
name|CS_ALT_FEATURE2
value|0x11
end_define

begin_define
define|#
directive|define
name|CS_LEFT_LINE_CONTROL
value|0x12
end_define

begin_define
define|#
directive|define
name|CS_RIGHT_LINE_CONTROL
value|0x13
end_define

begin_define
define|#
directive|define
name|CS_TIMER_LOW
value|0x14
end_define

begin_define
define|#
directive|define
name|CS_TIMER_HIGH
value|0x15
end_define

begin_define
define|#
directive|define
name|CS_UPPER_FREQUENCY_SEL
value|0x16
end_define

begin_define
define|#
directive|define
name|CS_LOWER_FREQUENCY_SEL
value|0x17
end_define

begin_define
define|#
directive|define
name|CS_IRQ_STATUS
value|0x18
end_define

begin_define
define|#
directive|define
name|CS_VERSION_ID
value|0x19
end_define

begin_define
define|#
directive|define
name|CS_MONO_IO_CONTROL
value|0x1a
end_define

begin_define
define|#
directive|define
name|CS_POWERDOWN_CONTROL
value|0x1b
end_define

begin_define
define|#
directive|define
name|CS_REC_FORMAT
value|0x1c
end_define

begin_define
define|#
directive|define
name|CS_XTAL_SELECT
value|0x1d
end_define

begin_define
define|#
directive|define
name|CS_UPPER_REC_CNT
value|0x1e
end_define

begin_define
define|#
directive|define
name|CS_LOWER_REC_CNT
value|0x1f
end_define

begin_define
define|#
directive|define
name|CS_REG_NONE
value|0xff
end_define

begin_define
define|#
directive|define
name|CS_IN_MASK
value|0x2f
end_define

begin_define
define|#
directive|define
name|CS_IN_LINE
value|0x00
end_define

begin_define
define|#
directive|define
name|CS_IN_AUX1
value|0x40
end_define

begin_define
define|#
directive|define
name|CS_IN_MIC
value|0x80
end_define

begin_define
define|#
directive|define
name|CS_IN_DAC
value|0xc0
end_define

begin_define
define|#
directive|define
name|CS_MIC_GAIN_ENABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|CS_IN_GAIN_MASK
value|0xf0
end_define

begin_comment
comment|/* ADC input control - registers I0 (channel 1,left); I1 (channel 1,right) */
end_comment

begin_define
define|#
directive|define
name|ADC_INPUT_ATTEN_BITS
value|0x0f
end_define

begin_define
define|#
directive|define
name|ADC_INPUT_GAIN_ENABLE
value|0x20
end_define

begin_comment
comment|/* Aux input control - registers I2 (channel 1,left); I3 (channel 1,right) 				 I4 (channel 2,left); I5 (channel 2,right) */
end_comment

begin_define
define|#
directive|define
name|AUX_INPUT_ATTEN_BITS
value|0x1f
end_define

begin_define
define|#
directive|define
name|AUX_INPUT_ATTEN_MASK
value|0xe0
end_define

begin_define
define|#
directive|define
name|AUX_INPUT_MUTE
value|0x80
end_define

begin_comment
comment|/* Output bits - registers I6,I7*/
end_comment

begin_define
define|#
directive|define
name|OUTPUT_MUTE
value|0x80
end_define

begin_define
define|#
directive|define
name|OUTPUT_ATTEN_BITS
value|0x3f
end_define

begin_define
define|#
directive|define
name|OUTPUT_ATTEN_MASK
value|(~OUTPUT_ATTEN_BITS& 0xff)
end_define

begin_comment
comment|/* Clock and Data format reg bits (some also Capture Data format) - reg I8 */
end_comment

begin_define
define|#
directive|define
name|CS_CLOCK_DATA_FORMAT_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|CLOCK_XTAL1
value|0x00
end_define

begin_define
define|#
directive|define
name|CLOCK_XTAL2
value|0x01
end_define

begin_define
define|#
directive|define
name|CLOCK_FREQ_MASK
value|0xf1
end_define

begin_define
define|#
directive|define
name|CS_AFMT_STEREO
value|0x10
end_define

begin_define
define|#
directive|define
name|CS_AFMT_U8
value|0x00
end_define

begin_define
define|#
directive|define
name|CS_AFMT_MU_LAW
value|0x20
end_define

begin_define
define|#
directive|define
name|CS_AFMT_S16_LE
value|0x40
end_define

begin_define
define|#
directive|define
name|CS_AFMT_A_LAW
value|0x60
end_define

begin_define
define|#
directive|define
name|CS_AFMT_IMA_ADPCM
value|0xa0
end_define

begin_define
define|#
directive|define
name|CS_AFMT_S16_BE
value|0xc0
end_define

begin_comment
comment|/* Interface Configuration reg bits - register I9 */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|CAPTURE_ENABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|DUAL_DMA
value|0x00
end_define

begin_define
define|#
directive|define
name|SINGLE_DMA
value|0x04
end_define

begin_define
define|#
directive|define
name|AUTO_CAL_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|PLAYBACK_PIO_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|CAPTURE_PIO_ENABLE
value|0x80
end_define

begin_comment
comment|/* Pin control bits - register I10 */
end_comment

begin_define
define|#
directive|define
name|INTERRUPT_ENABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|XCTL0_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|XCTL1_ENABLE
value|0x80
end_define

begin_comment
comment|/* Test and init reg bits - register I11 (read-only) */
end_comment

begin_define
define|#
directive|define
name|OVERRANGE_LEFT_MASK
value|0xfc
end_define

begin_define
define|#
directive|define
name|OVERRANGE_RIGHT_MASK
value|0xf3
end_define

begin_define
define|#
directive|define
name|DATA_REQUEST_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|AUTO_CAL_IN_PROG
value|0x20
end_define

begin_define
define|#
directive|define
name|PLAYBACK_UNDERRUN
value|0x40
end_define

begin_define
define|#
directive|define
name|CAPTURE_OVERRUN
value|0x80
end_define

begin_comment
comment|/* Miscellaneous Control reg bits - register I12 */
end_comment

begin_define
define|#
directive|define
name|CS_ID_MASK
value|0x70
end_define

begin_define
define|#
directive|define
name|CS_MODE2
value|0x40
end_define

begin_define
define|#
directive|define
name|CS_CODEC_ID_MASK
value|0x0f
end_define

begin_comment
comment|/* Digital Mix Control reg bits - register I13 */
end_comment

begin_define
define|#
directive|define
name|DIGITAL_MIX1_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|MIX_ATTEN_MASK
value|0x03
end_define

begin_comment
comment|/* Alternate Feature Enable I - register I16 */
end_comment

begin_define
define|#
directive|define
name|CS_DAC_ZERO
value|0x01
end_define

begin_define
define|#
directive|define
name|CS_PMC_ENABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|CS_CMC_ENABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|CS_OUTPUT_LVL
value|0x80
end_define

begin_comment
comment|/* Alternate Feature Enable II - register I17 */
end_comment

begin_define
define|#
directive|define
name|CS_HPF_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|DUAL_XTAL_ENABLE
value|0x02
end_define

begin_comment
comment|/* alternate feature status(I24) */
end_comment

begin_define
define|#
directive|define
name|CS_AFS_TI
value|0x40
end_define

begin_comment
comment|/* timer interrupt */
end_comment

begin_define
define|#
directive|define
name|CS_AFS_CI
value|0x20
end_define

begin_comment
comment|/* capture interrupt */
end_comment

begin_define
define|#
directive|define
name|CS_AFS_PI
value|0x10
end_define

begin_comment
comment|/* playback interrupt */
end_comment

begin_define
define|#
directive|define
name|CS_AFS_CU
value|0x08
end_define

begin_comment
comment|/* capture underrun */
end_comment

begin_define
define|#
directive|define
name|CS_AFS_CO
value|0x04
end_define

begin_comment
comment|/* capture overrun */
end_comment

begin_define
define|#
directive|define
name|CS_AFS_PO
value|0x02
end_define

begin_comment
comment|/* playback overrun */
end_comment

begin_define
define|#
directive|define
name|CS_AFS_PU
value|0x01
end_define

begin_comment
comment|/* playback underrun */
end_comment

begin_comment
comment|/* Version - register I25 */
end_comment

begin_define
define|#
directive|define
name|CS_VERSION_NUMBER
value|0xe0
end_define

begin_define
define|#
directive|define
name|CS_VERSION_CHIPID
value|0x07
end_define

begin_comment
comment|/* Miscellaneous Control reg bits */
end_comment

begin_define
define|#
directive|define
name|CS_MODE2
value|0x40
end_define

begin_define
define|#
directive|define
name|MONO_INPUT_ATTEN_BITS
value|0x0f
end_define

begin_define
define|#
directive|define
name|MONO_INPUT_ATTEN_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|MONO_OUTPUT_MUTE
value|0x40
end_define

begin_define
define|#
directive|define
name|MONO_INPUT_MUTE
value|0x80
end_define

begin_define
define|#
directive|define
name|MONO_INPUT_MUTE_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|LINE_INPUT_ATTEN_BITS
value|0x1f
end_define

begin_define
define|#
directive|define
name|LINE_INPUT_ATTEN_MASK
value|0xe0
end_define

begin_define
define|#
directive|define
name|LINE_INPUT_MUTE
value|0x80
end_define

begin_define
define|#
directive|define
name|LINE_INPUT_MUTE_MASK
value|0x7f
end_define

end_unit

