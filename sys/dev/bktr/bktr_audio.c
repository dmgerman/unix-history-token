begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * This is part of the Driver for Video Capture Cards (Frame grabbers)  * and TV Tuner cards using the Brooktree Bt848, Bt848A, Bt849A, Bt878, Bt879  * chipset.  * Copyright Roger Hardiman and Amancio Hasty.  *  * bktr_audio : This deals with controlling the audio on TV cards,  *                controlling the Audio Multiplexer (audio source selector).  *                controlling any MSP34xx stereo audio decoders.  *                controlling any DPL35xx dolby surroud sound audio decoders.      *                initialising TDA98xx audio devices.  *  */
end_comment

begin_comment
comment|/*  * 1. Redistributions of source code must retain the  * Copyright (c) 1997 Amancio Hasty, 1999 Roger Hardiman  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Amancio Hasty and  *      Roger Hardiman  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|bootverbose
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_comment
comment|/* for DELAY */
end_comment

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|300000
operator|)
end_if

begin_include
include|#
directive|include
file|<machine/bus_memio.h>
end_include

begin_comment
comment|/* for bus space */
end_comment

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_include
include|#
directive|include
file|<dev/ic/ioctl_meteor.h>
end_include

begin_comment
comment|/* NetBSD location of .h files */
end_comment

begin_include
include|#
directive|include
file|<dev/ic/ioctl_bt848.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/ioctl_meteor.h>
end_include

begin_comment
comment|/* Traditional location of .h files */
end_comment

begin_include
include|#
directive|include
file|<machine/ioctl_bt848.h>
end_include

begin_comment
comment|/* extensions to ioctl_meteor.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dev/bktr/bktr_reg.h>
end_include

begin_include
include|#
directive|include
file|<dev/bktr/bktr_core.h>
end_include

begin_include
include|#
directive|include
file|<dev/bktr/bktr_tuner.h>
end_include

begin_include
include|#
directive|include
file|<dev/bktr/bktr_card.h>
end_include

begin_include
include|#
directive|include
file|<dev/bktr/bktr_audio.h>
end_include

begin_comment
comment|/*  * Prototypes for the GV_BCTV specific functions.  */
end_comment

begin_function_decl
name|void
name|set_bctv_audio
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bctv_gpio_write
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|port
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*int   bctv_gpio_read( bktr_ptr_t bktr, int port );*/
end_comment

begin_comment
comment|/* Not used */
end_comment

begin_comment
comment|/*  * init_audio_devices  * Reset any MSP34xx or TDA98xx audio devices.  */
end_comment

begin_function
name|void
name|init_audio_devices
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|)
block|{
comment|/* enable stereo if appropriate on TDA audio chip */
if|if
condition|(
name|bktr
operator|->
name|card
operator|.
name|dbx
condition|)
name|init_BTSC
argument_list|(
name|bktr
argument_list|)
expr_stmt|;
comment|/* reset the MSP34xx stereo audio chip */
if|if
condition|(
name|bktr
operator|->
name|card
operator|.
name|msp3400c
condition|)
name|msp_dpl_reset
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|)
expr_stmt|;
comment|/* reset the DPL35xx dolby audio chip */
if|if
condition|(
name|bktr
operator|->
name|card
operator|.
name|dpl3518a
condition|)
name|msp_dpl_reset
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|dpl_addr
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *   */
end_comment

begin_define
define|#
directive|define
name|AUDIOMUX_DISCOVER_NOT
end_define

begin_function
name|int
name|set_audio
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|cmd
parameter_list|)
block|{
name|u_long
name|temp
decl_stmt|;
specifier|volatile
name|u_char
name|idx
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|AUDIOMUX_DISCOVER
argument_list|)
if|if
condition|(
name|cmd
operator|>=
literal|200
condition|)
name|cmd
operator|-=
literal|200
expr_stmt|;
elseif|else
endif|#
directive|endif
comment|/* AUDIOMUX_DISCOVER */
comment|/* check for existance of audio MUXes */
if|if
condition|(
operator|!
name|bktr
operator|->
name|card
operator|.
name|audiomuxs
index|[
literal|4
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|AUDIO_TUNER
case|:
ifdef|#
directive|ifdef
name|BKTR_REVERSEMUTE
name|bktr
operator|->
name|audio_mux_select
operator|=
literal|3
expr_stmt|;
else|#
directive|else
name|bktr
operator|->
name|audio_mux_select
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|bktr
operator|->
name|reverse_mute
condition|)
name|bktr
operator|->
name|audio_mux_select
operator|=
literal|0
expr_stmt|;
else|else
name|bktr
operator|->
name|audio_mux_select
operator|=
literal|3
expr_stmt|;
break|break;
case|case
name|AUDIO_EXTERN
case|:
name|bktr
operator|->
name|audio_mux_select
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|AUDIO_INTERN
case|:
name|bktr
operator|->
name|audio_mux_select
operator|=
literal|2
expr_stmt|;
break|break;
case|case
name|AUDIO_MUTE
case|:
name|bktr
operator|->
name|audio_mute_state
operator|=
name|TRUE
expr_stmt|;
comment|/* set mute */
break|break;
case|case
name|AUDIO_UNMUTE
case|:
name|bktr
operator|->
name|audio_mute_state
operator|=
name|FALSE
expr_stmt|;
comment|/* clear mute */
break|break;
default|default:
name|printf
argument_list|(
literal|"bktr: audio cmd error %02x\n"
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* Most cards have a simple audio multiplexer to select the 	 * audio source. The I/O_GV card has a more advanced multiplexer 	 * and requires special handling. 	 */
if|if
condition|(
name|bktr
operator|->
name|bt848_card
operator|==
name|CARD_IO_GV
condition|)
block|{
name|set_bctv_audio
argument_list|(
name|bktr
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* Proceed with the simpler audio multiplexer code for the majority 	 * of Bt848 cards. 	 */
comment|/* 	 * Leave the upper bits of the GPIO port alone in case they control 	 * something like the dbx or teletext chips.  This doesn't guarantee 	 * success, but follows the rule of least astonishment. 	 */
if|if
condition|(
name|bktr
operator|->
name|audio_mute_state
operator|==
name|TRUE
condition|)
block|{
ifdef|#
directive|ifdef
name|BKTR_REVERSEMUTE
name|idx
operator|=
literal|0
expr_stmt|;
else|#
directive|else
name|idx
operator|=
literal|3
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|bktr
operator|->
name|reverse_mute
condition|)
name|idx
operator|=
literal|3
expr_stmt|;
else|else
name|idx
operator|=
literal|0
expr_stmt|;
block|}
else|else
name|idx
operator|=
name|bktr
operator|->
name|audio_mux_select
expr_stmt|;
name|temp
operator|=
name|INL
argument_list|(
name|bktr
argument_list|,
name|BKTR_GPIO_DATA
argument_list|)
operator|&
operator|~
name|bktr
operator|->
name|card
operator|.
name|gpio_mux_bits
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|AUDIOMUX_DISCOVER
argument_list|)
name|OUTL
argument_list|(
name|bktr
argument_list|,
name|BKTR_GPIO_DATA
argument_list|,
name|temp
operator||
operator|(
name|cmd
operator|&
literal|0xff
operator|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"cmd: %d audio mux %x temp %x \n"
argument_list|,
name|cmd
argument_list|,
name|bktr
operator|->
name|card
operator|.
name|audiomuxs
index|[
name|idx
index|]
argument_list|,
name|temp
argument_list|)
expr_stmt|;
else|#
directive|else
name|OUTL
argument_list|(
name|bktr
argument_list|,
name|BKTR_GPIO_DATA
argument_list|,
name|temp
operator||
name|bktr
operator|->
name|card
operator|.
name|audiomuxs
index|[
name|idx
index|]
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* AUDIOMUX_DISCOVER */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *   */
end_comment

begin_function
name|void
name|temp_mute
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|flag
parameter_list|)
block|{
specifier|static
name|int
name|muteState
init|=
name|FALSE
decl_stmt|;
if|if
condition|(
name|flag
operator|==
name|TRUE
condition|)
block|{
name|muteState
operator|=
name|bktr
operator|->
name|audio_mute_state
expr_stmt|;
name|set_audio
argument_list|(
name|bktr
argument_list|,
name|AUDIO_MUTE
argument_list|)
expr_stmt|;
comment|/* prevent 'click' */
block|}
else|else
block|{
name|tsleep
argument_list|(
name|BKTR_SLEEP
argument_list|,
name|PZERO
argument_list|,
literal|"tuning"
argument_list|,
name|hz
operator|/
literal|8
argument_list|)
expr_stmt|;
if|if
condition|(
name|muteState
operator|==
name|FALSE
condition|)
name|set_audio
argument_list|(
name|bktr
argument_list|,
name|AUDIO_UNMUTE
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* address of BTSC/SAP decoder chip */
end_comment

begin_define
define|#
directive|define
name|TDA9850_WADDR
value|0xb6
end_define

begin_define
define|#
directive|define
name|TDA9850_RADDR
value|0xb7
end_define

begin_comment
comment|/* registers in the TDA9850 BTSC/dbx chip */
end_comment

begin_define
define|#
directive|define
name|CON1ADDR
value|0x04
end_define

begin_define
define|#
directive|define
name|CON2ADDR
value|0x05
end_define

begin_define
define|#
directive|define
name|CON3ADDR
value|0x06
end_define

begin_define
define|#
directive|define
name|CON4ADDR
value|0x07
end_define

begin_define
define|#
directive|define
name|ALI1ADDR
value|0x08
end_define

begin_define
define|#
directive|define
name|ALI2ADDR
value|0x09
end_define

begin_define
define|#
directive|define
name|ALI3ADDR
value|0x0a
end_define

begin_comment
comment|/*  * initialise the dbx chip  * taken from the Linux bttv driver TDA9850 initialisation code  */
end_comment

begin_function
name|void
name|init_BTSC
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|)
block|{
name|i2cWrite
argument_list|(
name|bktr
argument_list|,
name|TDA9850_WADDR
argument_list|,
name|CON1ADDR
argument_list|,
literal|0x08
argument_list|)
expr_stmt|;
comment|/* noise threshold st */
name|i2cWrite
argument_list|(
name|bktr
argument_list|,
name|TDA9850_WADDR
argument_list|,
name|CON2ADDR
argument_list|,
literal|0x08
argument_list|)
expr_stmt|;
comment|/* noise threshold sap */
name|i2cWrite
argument_list|(
name|bktr
argument_list|,
name|TDA9850_WADDR
argument_list|,
name|CON3ADDR
argument_list|,
literal|0x40
argument_list|)
expr_stmt|;
comment|/* stereo mode */
name|i2cWrite
argument_list|(
name|bktr
argument_list|,
name|TDA9850_WADDR
argument_list|,
name|CON4ADDR
argument_list|,
literal|0x07
argument_list|)
expr_stmt|;
comment|/* 0 dB input gain? */
name|i2cWrite
argument_list|(
name|bktr
argument_list|,
name|TDA9850_WADDR
argument_list|,
name|ALI1ADDR
argument_list|,
literal|0x10
argument_list|)
expr_stmt|;
comment|/* wideband alignment? */
name|i2cWrite
argument_list|(
name|bktr
argument_list|,
name|TDA9850_WADDR
argument_list|,
name|ALI2ADDR
argument_list|,
literal|0x10
argument_list|)
expr_stmt|;
comment|/* spectral alignment? */
name|i2cWrite
argument_list|(
name|bktr
argument_list|,
name|TDA9850_WADDR
argument_list|,
name|ALI3ADDR
argument_list|,
literal|0x03
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * setup the dbx chip  * XXX FIXME: alot of work to be done here, this merely unmutes it.  */
end_comment

begin_function
name|int
name|set_BTSC
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|control
parameter_list|)
block|{
return|return
operator|(
name|i2cWrite
argument_list|(
name|bktr
argument_list|,
name|TDA9850_WADDR
argument_list|,
name|CON3ADDR
argument_list|,
name|control
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * CARD_GV_BCTV specific functions.  */
end_comment

begin_define
define|#
directive|define
name|BCTV_AUDIO_MAIN
value|0x10
end_define

begin_comment
comment|/* main audio program */
end_comment

begin_define
define|#
directive|define
name|BCTV_AUDIO_SUB
value|0x20
end_define

begin_comment
comment|/* sub audio program */
end_comment

begin_define
define|#
directive|define
name|BCTV_AUDIO_BOTH
value|0x30
end_define

begin_comment
comment|/* main(L) + sub(R) program */
end_comment

begin_define
define|#
directive|define
name|BCTV_GPIO_REG0
value|1
end_define

begin_define
define|#
directive|define
name|BCTV_GPIO_REG1
value|3
end_define

begin_define
define|#
directive|define
name|BCTV_GR0_AUDIO_MODE
value|3
end_define

begin_define
define|#
directive|define
name|BCTV_GR0_AUDIO_MAIN
value|0
end_define

begin_comment
comment|/* main program */
end_comment

begin_define
define|#
directive|define
name|BCTV_GR0_AUDIO_SUB
value|3
end_define

begin_comment
comment|/* sub program */
end_comment

begin_define
define|#
directive|define
name|BCTV_GR0_AUDIO_BOTH
value|1
end_define

begin_comment
comment|/* main(L) + sub(R) */
end_comment

begin_define
define|#
directive|define
name|BCTV_GR0_AUDIO_MUTE
value|4
end_define

begin_comment
comment|/* audio mute */
end_comment

begin_define
define|#
directive|define
name|BCTV_GR0_AUDIO_MONO
value|8
end_define

begin_comment
comment|/* force mono */
end_comment

begin_function
name|void
name|set_bctv_audio
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|)
block|{
name|int
name|data
decl_stmt|;
switch|switch
condition|(
name|bktr
operator|->
name|audio_mux_select
condition|)
block|{
case|case
literal|1
case|:
comment|/* external */
case|case
literal|2
case|:
comment|/* internal */
name|bctv_gpio_write
argument_list|(
name|bktr
argument_list|,
name|BCTV_GPIO_REG1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|/* tuner */
name|bctv_gpio_write
argument_list|(
name|bktr
argument_list|,
name|BCTV_GPIO_REG1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/*      switch (bktr->audio_sap_select) { */
switch|switch
condition|(
name|BCTV_AUDIO_BOTH
condition|)
block|{
case|case
name|BCTV_AUDIO_SUB
case|:
name|data
operator|=
name|BCTV_GR0_AUDIO_SUB
expr_stmt|;
break|break;
case|case
name|BCTV_AUDIO_BOTH
case|:
name|data
operator|=
name|BCTV_GR0_AUDIO_BOTH
expr_stmt|;
break|break;
case|case
name|BCTV_AUDIO_MAIN
case|:
default|default:
name|data
operator|=
name|BCTV_GR0_AUDIO_MAIN
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|bktr
operator|->
name|audio_mute_state
operator|==
name|TRUE
condition|)
name|data
operator||=
name|BCTV_GR0_AUDIO_MUTE
expr_stmt|;
name|bctv_gpio_write
argument_list|(
name|bktr
argument_list|,
name|BCTV_GPIO_REG0
argument_list|,
name|data
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/* gpio_data bit assignment */
end_comment

begin_define
define|#
directive|define
name|BCTV_GPIO_ADDR_MASK
value|0x000300
end_define

begin_define
define|#
directive|define
name|BCTV_GPIO_WE
value|0x000400
end_define

begin_define
define|#
directive|define
name|BCTV_GPIO_OE
value|0x000800
end_define

begin_define
define|#
directive|define
name|BCTV_GPIO_VAL_MASK
value|0x00f000
end_define

begin_define
define|#
directive|define
name|BCTV_GPIO_PORT_MASK
value|3
end_define

begin_define
define|#
directive|define
name|BCTV_GPIO_ADDR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BCTV_GPIO_VAL_SHIFT
value|12
end_define

begin_comment
comment|/* gpio_out_en value for read/write */
end_comment

begin_define
define|#
directive|define
name|BCTV_GPIO_OUT_RMASK
value|0x000f00
end_define

begin_define
define|#
directive|define
name|BCTV_GPIO_OUT_WMASK
value|0x00ff00
end_define

begin_define
define|#
directive|define
name|BCTV_BITS
value|100
end_define

begin_function
name|void
name|bctv_gpio_write
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|port
parameter_list|,
name|int
name|val
parameter_list|)
block|{
name|u_long
name|data
decl_stmt|,
name|outbits
decl_stmt|;
name|port
operator|&=
name|BCTV_GPIO_PORT_MASK
expr_stmt|;
switch|switch
condition|(
name|port
condition|)
block|{
case|case
literal|1
case|:
case|case
literal|3
case|:
name|data
operator|=
operator|(
operator|(
name|val
operator|<<
name|BCTV_GPIO_VAL_SHIFT
operator|)
operator|&
name|BCTV_GPIO_VAL_MASK
operator|)
operator||
operator|(
operator|(
name|port
operator|<<
name|BCTV_GPIO_ADDR_SHIFT
operator|)
operator|&
name|BCTV_GPIO_ADDR_MASK
operator|)
operator||
name|BCTV_GPIO_WE
operator||
name|BCTV_GPIO_OE
expr_stmt|;
name|outbits
operator|=
name|BCTV_GPIO_OUT_WMASK
expr_stmt|;
break|break;
default|default:
return|return;
block|}
name|OUTL
argument_list|(
name|bktr
argument_list|,
name|BKTR_GPIO_OUT_EN
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|OUTL
argument_list|(
name|bktr
argument_list|,
name|BKTR_GPIO_DATA
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|OUTL
argument_list|(
name|bktr
argument_list|,
name|BKTR_GPIO_OUT_EN
argument_list|,
name|outbits
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
name|BCTV_BITS
argument_list|)
expr_stmt|;
name|OUTL
argument_list|(
name|bktr
argument_list|,
name|BKTR_GPIO_DATA
argument_list|,
name|data
operator|&
operator|~
name|BCTV_GPIO_WE
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
name|BCTV_BITS
argument_list|)
expr_stmt|;
name|OUTL
argument_list|(
name|bktr
argument_list|,
name|BKTR_GPIO_DATA
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
name|BCTV_BITS
argument_list|)
expr_stmt|;
name|OUTL
argument_list|(
name|bktr
argument_list|,
name|BKTR_GPIO_DATA
argument_list|,
operator|~
literal|0
argument_list|)
expr_stmt|;
name|OUTL
argument_list|(
name|bktr
argument_list|,
name|BKTR_GPIO_OUT_EN
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Not yet used int bctv_gpio_read( bktr_ptr_t bktr, int port ) {         u_long data, outbits, ret;          port&= BCTV_GPIO_PORT_MASK;         switch (port) {         case 1:         case 3:                 data = ((port<< BCTV_GPIO_ADDR_SHIFT)& BCTV_GPIO_ADDR_MASK) |                        BCTV_GPIO_WE | BCTV_GPIO_OE;                 outbits = BCTV_GPIO_OUT_RMASK;                 break;         default:                 return( -1 );         }         OUTL(bktr, BKTR_GPIO_OUT_EN, 0);         OUTL(bktr, BKTR_GPIO_DATA, data);         OUTL(bktr, BKTR_GPIO_OUT_EN, outbits);         DELAY(BCTV_BITS);         OUTL(bktr, BKTR_GPIO_DATA, data& ~BCTV_GPIO_OE);         DELAY(BCTV_BITS);         ret = INL(bktr, BKTR_GPIO_DATA);         DELAY(BCTV_BITS);         OUTL(bktr, BKTR_GPIO_DATA, data);         DELAY(BCTV_BITS);         OUTL(bktr, BKTR_GPIO_DATA, ~0);         OUTL(bktr, BKTR_GPIO_OUT_EN, 0);         return( (ret& BCTV_GPIO_VAL_MASK)>> BCTV_GPIO_VAL_SHIFT ); } */
end_comment

begin_comment
comment|/*  * setup the MSP34xx Stereo Audio Chip  * This uses the Auto Configuration Option on MSP3410D and MSP3415D chips  * and DBX mode selection for MSP3430G chips.  * For MSP3400C support, the full programming sequence is required and is  * not yet supported.  */
end_comment

begin_comment
comment|/* Read the MSP version string */
end_comment

begin_function
name|void
name|msp_read_id
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|)
block|{
name|int
name|rev1
init|=
literal|0
decl_stmt|,
name|rev2
init|=
literal|0
decl_stmt|;
name|rev1
operator|=
name|msp_dpl_read
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x001e
argument_list|)
expr_stmt|;
name|rev2
operator|=
name|msp_dpl_read
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x001f
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|bktr
operator|->
name|msp_version_string
argument_list|,
literal|"34%02d%c-%c%d"
argument_list|,
operator|(
name|rev2
operator|>>
literal|8
operator|)
operator|&
literal|0xff
argument_list|,
operator|(
name|rev1
operator|&
literal|0xff
operator|)
operator|+
literal|'@'
argument_list|,
operator|(
operator|(
name|rev1
operator|>>
literal|8
operator|)
operator|&
literal|0xff
operator|)
operator|+
literal|'@'
argument_list|,
name|rev2
operator|&
literal|0x1f
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Configure the MSP chip to Auto-detect the audio format.  * For the MSP3430G, we use fast autodetect mode  * For the MSP3410/3415 there are two schemes for this  *  a) Fast autodetection - the chip is put into autodetect mode, and the function  *     returns immediatly. This works in most cases and is the Default Mode.  *  b) Slow mode. The function sets the MSP3410/3415 chip, then waits for feedback from   *     the chip and re-programs it if needed.  */
end_comment

begin_function
name|void
name|msp_autodetect
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|)
block|{
name|int
name|auto_detect
decl_stmt|,
name|loops
decl_stmt|;
name|int
name|stereo
decl_stmt|;
comment|/* MSP3430G - countries with mono and DBX stereo */
if|if
condition|(
name|strncmp
argument_list|(
literal|"3430G"
argument_list|,
name|bktr
operator|->
name|msp_version_string
argument_list|,
literal|5
argument_list|)
operator|==
literal|0
condition|)
block|{
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x10
argument_list|,
literal|0x0030
argument_list|,
literal|0x2003
argument_list|)
expr_stmt|;
comment|/* Enable Auto format detection */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x10
argument_list|,
literal|0x0020
argument_list|,
literal|0x0020
argument_list|)
expr_stmt|;
comment|/* Standard Select Reg. = BTSC-Stereo*/
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x000E
argument_list|,
literal|0x2403
argument_list|)
expr_stmt|;
comment|/* darned if I know */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0008
argument_list|,
literal|0x0320
argument_list|)
expr_stmt|;
comment|/* Source select = (St or A) */
comment|/*& Ch. Matrix = St */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0000
argument_list|,
literal|0x7300
argument_list|)
expr_stmt|;
comment|/* Set volume to 0db gain */
block|}
comment|/* MSP3410/MSP3415 - countries with mono, stereo using 2 FM channels and NICAM */
comment|/* FAST sound scheme */
if|if
condition|(
operator|(
name|strncmp
argument_list|(
literal|"3430G"
argument_list|,
name|bktr
operator|->
name|msp_version_string
argument_list|,
literal|5
argument_list|)
operator|!=
literal|0
operator|)
operator|&&
operator|(
name|bktr
operator|->
name|slow_msp_audio
operator|==
literal|0
operator|)
condition|)
block|{
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"inside fast MSP autodetect code\n"
argument_list|)
expr_stmt|;
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0000
argument_list|,
literal|0x7300
argument_list|)
expr_stmt|;
comment|/* Set volume to 0db gain */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x10
argument_list|,
literal|0x0020
argument_list|,
literal|0x0001
argument_list|)
expr_stmt|;
comment|/* Enable Auto format detection */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x10
argument_list|,
literal|0x0021
argument_list|,
literal|0x0001
argument_list|)
expr_stmt|;
comment|/* Auto selection of NICAM/MONO mode */
block|}
comment|/* MSP3410/MSP3415 - European Countries where the fast MSP3410/3415 programming fails */
comment|/* SLOW sound scheme */
if|if
condition|(
operator|(
name|strncmp
argument_list|(
literal|"3430G"
argument_list|,
name|bktr
operator|->
name|msp_version_string
argument_list|,
literal|5
argument_list|)
operator|!=
literal|0
operator|)
operator|&&
operator|(
name|bktr
operator|->
name|slow_msp_audio
operator|==
literal|1
operator|)
condition|)
block|{
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"inside slow MSP autodetect code\n"
argument_list|)
expr_stmt|;
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0000
argument_list|,
literal|0x7300
argument_list|)
expr_stmt|;
comment|/* Set volume to 0db gain */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x10
argument_list|,
literal|0x0020
argument_list|,
literal|0x0001
argument_list|)
expr_stmt|;
comment|/* Enable Auto format detection */
comment|/* wait for 0.5s max for terrestrial sound autodetection */
name|loops
operator|=
literal|10
expr_stmt|;
do|do
block|{
name|DELAY
argument_list|(
literal|100000
argument_list|)
expr_stmt|;
name|auto_detect
operator|=
name|msp_dpl_read
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x10
argument_list|,
literal|0x007e
argument_list|)
expr_stmt|;
name|loops
operator|++
expr_stmt|;
block|}
do|while
condition|(
name|auto_detect
operator|>
literal|0xff
operator|&&
name|loops
operator|<
literal|50
condition|)
do|;
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"Result of autodetect after %dms: %d\n"
argument_list|,
name|loops
operator|*
literal|10
argument_list|,
name|auto_detect
argument_list|)
expr_stmt|;
comment|/* Now set the audio baseband processing */
switch|switch
condition|(
name|auto_detect
condition|)
block|{
case|case
literal|0
case|:
comment|/* no TV sound standard detected */
break|break;
case|case
literal|2
case|:
comment|/* M Dual FM */
break|break;
case|case
literal|3
case|:
comment|/* B/G Dual FM; German stereo */
comment|/* Read the stereo detection value from DSP reg 0x0018 */
name|DELAY
argument_list|(
literal|20000
argument_list|)
expr_stmt|;
name|stereo
operator|=
name|msp_dpl_read
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0018
argument_list|)
expr_stmt|;
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"Stereo reg 0x18 a: %d\n"
argument_list|,
name|stereo
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|20000
argument_list|)
expr_stmt|;
name|stereo
operator|=
name|msp_dpl_read
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0018
argument_list|)
expr_stmt|;
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"Stereo reg 0x18 b: %d\n"
argument_list|,
name|stereo
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|20000
argument_list|)
expr_stmt|;
name|stereo
operator|=
name|msp_dpl_read
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0018
argument_list|)
expr_stmt|;
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"Stereo reg 0x18 c: %d\n"
argument_list|,
name|stereo
argument_list|)
expr_stmt|;
if|if
condition|(
name|stereo
operator|>
literal|0x0100
operator|&&
name|stereo
operator|<
literal|0x8000
condition|)
block|{
comment|/* Seems to be stereo */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0008
argument_list|,
literal|0x0020
argument_list|)
expr_stmt|;
comment|/* Loudspeaker set stereo*/
comment|/*           set spatial effect strength to 50% enlargement           set spatial effect mode b, stereo basewidth enlargment only         */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0005
argument_list|,
literal|0x3f28
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|stereo
operator|>
literal|0x8000
condition|)
block|{
comment|/* bilingual mode */
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"Bilingual mode detected\n"
argument_list|)
expr_stmt|;
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0008
argument_list|,
literal|0x0000
argument_list|)
expr_stmt|;
comment|/* Loudspeaker */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0005
argument_list|,
literal|0x0000
argument_list|)
expr_stmt|;
comment|/* all spatial effects off */
block|}
else|else
block|{
comment|/* must be mono */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0008
argument_list|,
literal|0x0030
argument_list|)
expr_stmt|;
comment|/* Loudspeaker */
comment|/*           set spatial effect strength to 50% enlargement           set spatial effect mode a, stereo basewidth enlargment           and pseudo stereo effect with automatic high-pass filter         */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0005
argument_list|,
literal|0x3f08
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
literal|0
comment|/* The reset value for Channel matrix mode is FM/AM and SOUNDA/LEFT */
comment|/* We would like STEREO instead val: 0x0020 */
block|msp_dpl_write(bktr, bktr->msp_addr, 0x12, 0x0008,0x0020);
comment|/* Loudspeaker */
block|msp_dpl_write(bktr, bktr->msp_addr, 0x12, 0x0009,0x0020);
comment|/* Headphone */
block|msp_dpl_write(bktr, bktr->msp_addr, 0x12, 0x000a,0x0020);
comment|/* SCART1 */
block|msp_dpl_write(bktr, bktr->msp_addr, 0x12, 0x0041,0x0020);
comment|/* SCART2 */
block|msp_dpl_write(bktr, bktr->msp_addr, 0x12, 0x000b,0x0020);
comment|/* I2S */
block|msp_dpl_write(bktr, bktr->msp_addr, 0x12, 0x000c,0x0020);
comment|/* Quasi-Peak Detector Source */
block|msp_dpl_write(bktr, bktr->msp_addr, 0x12, 0x000e,0x0001);
endif|#
directive|endif
break|break;
case|case
literal|8
case|:
comment|/* B/G FM NICAM */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|msp_addr
argument_list|,
literal|0x10
argument_list|,
literal|0x0021
argument_list|,
literal|0x0001
argument_list|)
expr_stmt|;
comment|/* Auto selection of NICAM/MONO mode */
break|break;
case|case
literal|9
case|:
comment|/* L_AM NICAM or D/K*/
case|case
literal|10
case|:
comment|/* i-FM NICAM */
break|break;
default|default:
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"Unkown autodetection result value: %d\n"
argument_list|,
name|auto_detect
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* uncomment the following line to enable the MSP34xx 1Khz Tone Generator */
comment|/* turn your speaker volume down low before trying this */
comment|/* msp_dpl_write(bktr, bktr->msp_addr, 0x12, 0x0014, 0x7f40); */
block|}
end_function

begin_comment
comment|/* Read the DPL version string */
end_comment

begin_function
name|void
name|dpl_read_id
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|)
block|{
name|int
name|rev1
init|=
literal|0
decl_stmt|,
name|rev2
init|=
literal|0
decl_stmt|;
name|rev1
operator|=
name|msp_dpl_read
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|dpl_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x001e
argument_list|)
expr_stmt|;
name|rev2
operator|=
name|msp_dpl_read
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|dpl_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x001f
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|bktr
operator|->
name|dpl_version_string
argument_list|,
literal|"34%02d%c-%c%d"
argument_list|,
operator|(
operator|(
name|rev2
operator|>>
literal|8
operator|)
operator|&
literal|0xff
operator|)
operator|-
literal|1
argument_list|,
operator|(
name|rev1
operator|&
literal|0xff
operator|)
operator|+
literal|'@'
argument_list|,
operator|(
operator|(
name|rev1
operator|>>
literal|8
operator|)
operator|&
literal|0xff
operator|)
operator|+
literal|'@'
argument_list|,
name|rev2
operator|&
literal|0x1f
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Configure the DPL chip to Auto-detect the audio format */
end_comment

begin_function
name|void
name|dpl_autodetect
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|)
block|{
comment|/* The following are empiric values tried from the DPL35xx data sheet */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|dpl_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x000c
argument_list|,
literal|0x0320
argument_list|)
expr_stmt|;
comment|/* quasi peak detector source dolby 								lr 0x03xx; quasi peak detector matrix 								stereo 0xXX20 */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|dpl_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0040
argument_list|,
literal|0x0060
argument_list|)
expr_stmt|;
comment|/* Surround decoder mode; 								ADAPTIVE/3D-PANORAMA, that means two 								speakers and no center speaker, all 								channels L/R/C/S mixed to L and R */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|dpl_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0041
argument_list|,
literal|0x0620
argument_list|)
expr_stmt|;
comment|/* surround source matrix;I2S2/STEREO*/
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|dpl_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0042
argument_list|,
literal|0x1F00
argument_list|)
expr_stmt|;
comment|/* surround delay 31ms max */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|dpl_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0043
argument_list|,
literal|0x0000
argument_list|)
expr_stmt|;
comment|/* automatic surround input balance */
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|dpl_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0044
argument_list|,
literal|0x4000
argument_list|)
expr_stmt|;
comment|/* surround spatial effect 50% 								recommended*/
name|msp_dpl_write
argument_list|(
name|bktr
argument_list|,
name|bktr
operator|->
name|dpl_addr
argument_list|,
literal|0x12
argument_list|,
literal|0x0045
argument_list|,
literal|0x5400
argument_list|)
expr_stmt|;
comment|/* surround panorama effect 66% 								recommended with PANORAMA mode 								in 0x0040 set to panorama */
block|}
end_function

end_unit

