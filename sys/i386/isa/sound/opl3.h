begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	opl3.h	- Definitions of the OPL-3 registers  *  * Copyright by Hannu Savolainen 1993  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  *	The OPL-3 mode is switched on by writing 0x01, to the offset 5  *	of the right side.  *  *	Another special register at the right side is at offset 4. It contains  *	a bit mask defining which voices are used as 4 OP voices.  *  *	The percussive mode is implemented in the left side only.  *  *	With the above exeptions the both sides can be operated independently.  *	  *	A 4 OP voice can be created by setting the corresponding  *	bit at offset 4 of the right side.  *  *	For example setting the rightmost bit (0x01) changes the  *	first voice on the right side to the 4 OP mode. The fourth  *	voice is made inaccessible.  *  *	If a voice is set to the 2 OP mode, it works like 2 OP modes  *	of the original YM3812 (AdLib). In addition the voice can   *	be connected the left, right or both stereo channels. It can  *	even be left unconnected. This works with 4 OP voices also.  *  *	The stereo connection bits are located in the FEEDBACK_CONNECTION  *	register of the voice (0xC0-0xC8). In 4 OP voices these bits are  *	in the second half of the voice.  */
end_comment

begin_comment
comment|/*  *	Register numbers for the global registers  */
end_comment

begin_define
define|#
directive|define
name|TEST_REGISTER
value|0x01
end_define

begin_define
define|#
directive|define
name|ENABLE_WAVE_SELECT
value|0x20
end_define

begin_define
define|#
directive|define
name|TIMER1_REGISTER
value|0x02
end_define

begin_define
define|#
directive|define
name|TIMER2_REGISTER
value|0x03
end_define

begin_define
define|#
directive|define
name|TIMER_CONTROL_REGISTER
value|0x04
end_define

begin_comment
comment|/* Left side */
end_comment

begin_define
define|#
directive|define
name|IRQ_RESET
value|0x80
end_define

begin_define
define|#
directive|define
name|TIMER1_MASK
value|0x40
end_define

begin_define
define|#
directive|define
name|TIMER2_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|TIMER1_START
value|0x01
end_define

begin_define
define|#
directive|define
name|TIMER2_START
value|0x02
end_define

begin_define
define|#
directive|define
name|CONNECTION_SELECT_REGISTER
value|0x04
end_define

begin_comment
comment|/* Right side */
end_comment

begin_define
define|#
directive|define
name|RIGHT_4OP_0
value|0x01
end_define

begin_define
define|#
directive|define
name|RIGHT_4OP_1
value|0x02
end_define

begin_define
define|#
directive|define
name|RIGHT_4OP_2
value|0x04
end_define

begin_define
define|#
directive|define
name|LEFT_4OP_0
value|0x08
end_define

begin_define
define|#
directive|define
name|LEFT_4OP_1
value|0x10
end_define

begin_define
define|#
directive|define
name|LEFT_4OP_2
value|0x20
end_define

begin_define
define|#
directive|define
name|OPL3_MODE_REGISTER
value|0x05
end_define

begin_comment
comment|/* Right side */
end_comment

begin_define
define|#
directive|define
name|OPL3_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|OPL4_ENABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|KBD_SPLIT_REGISTER
value|0x08
end_define

begin_comment
comment|/* Left side */
end_comment

begin_define
define|#
directive|define
name|COMPOSITE_SINE_WAVE_MODE
value|0x80
end_define

begin_comment
comment|/* Don't use with OPL-3? */
end_comment

begin_define
define|#
directive|define
name|KEYBOARD_SPLIT
value|0x40
end_define

begin_define
define|#
directive|define
name|PERCUSSION_REGISTER
value|0xbd
end_define

begin_comment
comment|/* Left side only */
end_comment

begin_define
define|#
directive|define
name|TREMOLO_DEPTH
value|0x80
end_define

begin_define
define|#
directive|define
name|VIBRATO_DEPTH
value|0x40
end_define

begin_define
define|#
directive|define
name|PERCUSSION_ENABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|BASSDRUM_ON
value|0x10
end_define

begin_define
define|#
directive|define
name|SNAREDRUM_ON
value|0x08
end_define

begin_define
define|#
directive|define
name|TOMTOM_ON
value|0x04
end_define

begin_define
define|#
directive|define
name|CYMBAL_ON
value|0x02
end_define

begin_define
define|#
directive|define
name|HIHAT_ON
value|0x01
end_define

begin_comment
comment|/*  *	Offsets to the register banks for operators. To get the  *	register number just add the operator offset to the bank offset  *  *	AM/VIB/EG/KSR/Multiple (0x20 to 0x35)  */
end_comment

begin_define
define|#
directive|define
name|AM_VIB
value|0x20
end_define

begin_define
define|#
directive|define
name|TREMOLO_ON
value|0x80
end_define

begin_define
define|#
directive|define
name|VIBRATO_ON
value|0x40
end_define

begin_define
define|#
directive|define
name|SUSTAIN_ON
value|0x20
end_define

begin_define
define|#
directive|define
name|KSR
value|0x10
end_define

begin_comment
comment|/* Key scaling rate */
end_comment

begin_define
define|#
directive|define
name|MULTIPLE_MASK
value|0x0f
end_define

begin_comment
comment|/* Frequency multiplier */
end_comment

begin_comment
comment|/*   *	KSL/Total level (0x40 to 0x55)   */
end_comment

begin_define
define|#
directive|define
name|KSL_LEVEL
value|0x40
end_define

begin_define
define|#
directive|define
name|KSL_MASK
value|0xc0
end_define

begin_comment
comment|/* Envelope scaling bits */
end_comment

begin_define
define|#
directive|define
name|TOTAL_LEVEL_MASK
value|0x3f
end_define

begin_comment
comment|/* Strength (volume) of OP */
end_comment

begin_comment
comment|/*  *	Attack / Decay rate (0x60 to 0x75)  */
end_comment

begin_define
define|#
directive|define
name|ATTACK_DECAY
value|0x60
end_define

begin_define
define|#
directive|define
name|ATTACK_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|DECAY_MASK
value|0x0f
end_define

begin_comment
comment|/*  * Sustain level / Release rate (0x80 to 0x95)  */
end_comment

begin_define
define|#
directive|define
name|SUSTAIN_RELEASE
value|0x80
end_define

begin_define
define|#
directive|define
name|SUSTAIN_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|RELEASE_MASK
value|0x0f
end_define

begin_comment
comment|/*  * Wave select (0xE0 to 0xF5)  */
end_comment

begin_define
define|#
directive|define
name|WAVE_SELECT
value|0xe0
end_define

begin_comment
comment|/*  *	Offsets to the register banks for voices. Just add to the  *	voice number to get the register number.  *  *	F-Number low bits (0xA0 to 0xA8).  */
end_comment

begin_define
define|#
directive|define
name|FNUM_LOW
value|0xa0
end_define

begin_comment
comment|/*  *	F-number high bits / Key on / Block (octave) (0xB0 to 0xB8)  */
end_comment

begin_define
define|#
directive|define
name|KEYON_BLOCK
value|0xb0
end_define

begin_define
define|#
directive|define
name|KEYON_BIT
value|0x20
end_define

begin_define
define|#
directive|define
name|BLOCKNUM_MASK
value|0x1c
end_define

begin_define
define|#
directive|define
name|FNUM_HIGH_MASK
value|0x03
end_define

begin_comment
comment|/*  *	Feedback / Connection (0xc0 to 0xc8)  *  *	These registers have two new bits when the OPL-3 mode  *	is selected. These bits controls connecting the voice  *	to the stereo channels. For 4 OP voices this bit is  *	defined in the second half of the voice (add 3 to the  *	register offset).  *  *	For 4 OP voices the connection bit is used in the  *	both halfs (gives 4 ways to connect the operators).  */
end_comment

begin_define
define|#
directive|define
name|FEEDBACK_CONNECTION
value|0xc0
end_define

begin_define
define|#
directive|define
name|FEEDBACK_MASK
value|0x0e
end_define

begin_comment
comment|/* Valid just for 1st OP of a voice */
end_comment

begin_define
define|#
directive|define
name|CONNECTION_BIT
value|0x01
end_define

begin_comment
comment|/*  *	In the 4 OP mode there is four possible configurations how the  *	operators can be connected together (in 2 OP modes there is just  *	AM or FM). The 4 OP connection mode is defined by the rightmost  *	bit of the FEEDBACK_CONNECTION (0xC0-0xC8) on the both halfs.  *  *	First half	Second half	Mode  *  *					 +---+  *					 v   |  *	0		0>+-1-+--2--3--4-->  *  *  *					  *					 +---+  *					 |   |  *	0		1>+-1-+--2-+  *						  |->  *>--3----4-+  *					  *					 +---+  *					 |   |  *	1		0>+-1-+-----+  *						   |->  *>--2--3--4-+  *  *					 +---+  *					 |   |  *	1		1>+-1-+--+  *						|  *>--2--3-+->  *						|  *>--4----+  */
end_comment

begin_define
define|#
directive|define
name|STEREO_BITS
value|0x30
end_define

begin_comment
comment|/* OPL-3 only */
end_comment

begin_define
define|#
directive|define
name|VOICE_TO_LEFT
value|0x10
end_define

begin_define
define|#
directive|define
name|VOICE_TO_RIGHT
value|0x20
end_define

begin_comment
comment|/*  * 	Definition table for the physical voices  */
end_comment

begin_struct
struct|struct
name|physical_voice_info
block|{
name|unsigned
name|char
name|voice_num
decl_stmt|;
name|unsigned
name|char
name|voice_mode
decl_stmt|;
comment|/* 0=unavailable, 2=2 OP, 4=4 OP */
name|unsigned
name|short
name|ioaddr
decl_stmt|;
comment|/* I/O port (left or right side) */
name|unsigned
name|char
name|op
index|[
literal|4
index|]
decl_stmt|;
comment|/* Operator offsets */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	There is 18 possible 2 OP voices  *	(9 in the left and 9 in the right).  *	The first OP is the modulator and 2nd is the carrier.  *  *	The first three voices in the both sides may be connected  *	with another voice to a 4 OP voice. For example voice 0  *	can be connected with voice 3. The operators of voice 3 are  *	used as operators 3 and 4 of the new 4 OP voice.  *	In this case the 2 OP voice number 0 is the 'first half' and  *	voice 3 is the second.  */
end_comment

begin_define
define|#
directive|define
name|USE_LEFT
value|0
end_define

begin_define
define|#
directive|define
name|USE_RIGHT
value|1
end_define

begin_decl_stmt
specifier|static
name|struct
name|physical_voice_info
name|pv_map
index|[
literal|18
index|]
init|=
block|{
comment|/*       No Mode Side		OP1	OP2	OP3   OP4	*/
comment|/*	---------------------------------------------------	*/
block|{
literal|0
block|,
literal|2
block|,
name|USE_LEFT
block|,
block|{
literal|0x00
block|,
literal|0x03
block|,
literal|0x08
block|,
literal|0x0b
block|}
block|}
block|,
block|{
literal|1
block|,
literal|2
block|,
name|USE_LEFT
block|,
block|{
literal|0x01
block|,
literal|0x04
block|,
literal|0x09
block|,
literal|0x0c
block|}
block|}
block|,
block|{
literal|2
block|,
literal|2
block|,
name|USE_LEFT
block|,
block|{
literal|0x02
block|,
literal|0x05
block|,
literal|0x0a
block|,
literal|0x0d
block|}
block|}
block|,
block|{
literal|3
block|,
literal|2
block|,
name|USE_LEFT
block|,
block|{
literal|0x08
block|,
literal|0x0b
block|,
literal|0x00
block|,
literal|0x00
block|}
block|}
block|,
block|{
literal|4
block|,
literal|2
block|,
name|USE_LEFT
block|,
block|{
literal|0x09
block|,
literal|0x0c
block|,
literal|0x00
block|,
literal|0x00
block|}
block|}
block|,
block|{
literal|5
block|,
literal|2
block|,
name|USE_LEFT
block|,
block|{
literal|0x0a
block|,
literal|0x0d
block|,
literal|0x00
block|,
literal|0x00
block|}
block|}
block|,
block|{
literal|6
block|,
literal|2
block|,
name|USE_LEFT
block|,
block|{
literal|0x10
block|,
literal|0x13
block|,
literal|0x00
block|,
literal|0x00
block|}
block|}
block|,
comment|/* Used by percussive voices */
block|{
literal|7
block|,
literal|2
block|,
name|USE_LEFT
block|,
block|{
literal|0x11
block|,
literal|0x14
block|,
literal|0x00
block|,
literal|0x00
block|}
block|}
block|,
comment|/* if the percussive mode */
block|{
literal|8
block|,
literal|2
block|,
name|USE_LEFT
block|,
block|{
literal|0x12
block|,
literal|0x15
block|,
literal|0x00
block|,
literal|0x00
block|}
block|}
block|,
comment|/* is selected */
block|{
literal|0
block|,
literal|2
block|,
name|USE_RIGHT
block|,
block|{
literal|0x00
block|,
literal|0x03
block|,
literal|0x08
block|,
literal|0x0b
block|}
block|}
block|,
block|{
literal|1
block|,
literal|2
block|,
name|USE_RIGHT
block|,
block|{
literal|0x01
block|,
literal|0x04
block|,
literal|0x09
block|,
literal|0x0c
block|}
block|}
block|,
block|{
literal|2
block|,
literal|2
block|,
name|USE_RIGHT
block|,
block|{
literal|0x02
block|,
literal|0x05
block|,
literal|0x0a
block|,
literal|0x0d
block|}
block|}
block|,
block|{
literal|3
block|,
literal|2
block|,
name|USE_RIGHT
block|,
block|{
literal|0x08
block|,
literal|0x0b
block|,
literal|0x00
block|,
literal|0x00
block|}
block|}
block|,
block|{
literal|4
block|,
literal|2
block|,
name|USE_RIGHT
block|,
block|{
literal|0x09
block|,
literal|0x0c
block|,
literal|0x00
block|,
literal|0x00
block|}
block|}
block|,
block|{
literal|5
block|,
literal|2
block|,
name|USE_RIGHT
block|,
block|{
literal|0x0a
block|,
literal|0x0d
block|,
literal|0x00
block|,
literal|0x00
block|}
block|}
block|,
block|{
literal|6
block|,
literal|2
block|,
name|USE_RIGHT
block|,
block|{
literal|0x10
block|,
literal|0x13
block|,
literal|0x00
block|,
literal|0x00
block|}
block|}
block|,
block|{
literal|7
block|,
literal|2
block|,
name|USE_RIGHT
block|,
block|{
literal|0x11
block|,
literal|0x14
block|,
literal|0x00
block|,
literal|0x00
block|}
block|}
block|,
block|{
literal|8
block|,
literal|2
block|,
name|USE_RIGHT
block|,
block|{
literal|0x12
block|,
literal|0x15
block|,
literal|0x00
block|,
literal|0x00
block|}
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

