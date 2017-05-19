begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 M. Warner Losh  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*-  * Copyright 1992 by the University of Guelph  *  * Permission to use, copy and modify this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appear in all copies and that both that copyright  * notice and this permission notice appear in supporting  * documentation.  * University of Guelph makes no representations about the suitability of  * this software for any purpose.  It is provided "as is"  * without express or implied warranty.  */
end_comment

begin_comment
comment|/*  * Driver for the Logitech and ATI Inport Bus mice for use with 386bsd and  * the X386 port, courtesy of  * Rick Macklem, rick@snowhite.cis.uoguelph.ca  * Caveats: The driver currently uses spltty(), but doesn't use any  * generic tty code. It could use splmse() (that only masks off the  * bus mouse interrupt, but that would require hacking in i386/isa/icu.s.  * (This may be worth the effort, since the Logitech generates 30/60  * interrupts/sec continuously while it is open.)  * NB: The ATI has NOT been tested yet!  */
end_comment

begin_comment
comment|/*  * Modification history:  * Sep 6, 1994 -- Lars Fredriksen(fredriks@mcs.com)  *   improved probe based on input from Logitech.  *  * Oct 19, 1992 -- E. Stark (stark@cs.sunysb.edu)  *   fixes to make it work with Microsoft InPort busmouse  *  * Jan, 1993 -- E. Stark (stark@cs.sunysb.edu)  *   added patches for new "select" interface  *  * May 4, 1993 -- E. Stark (stark@cs.sunysb.edu)  *   changed position of some spl()'s in mseread  *  * October 8, 1993 -- E. Stark (stark@cs.sunysb.edu)  *   limit maximum negative x/y value to -127 to work around XFree problem  *   that causes spurious button pushes.  */
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
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/mouse.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<isa/isavar.h>
end_include

begin_include
include|#
directive|include
file|<dev/mse/msevar.h>
end_include

begin_function_decl
specifier|static
name|int
name|mse_isa_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|mse_isa_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|mse_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|mse_isa_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|mse_isa_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|mse_detach
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|mse_driver
init|=
block|{
literal|"mse"
block|,
name|mse_methods
block|,
sizeof|sizeof
argument_list|(
name|mse_softc_t
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|mse
argument_list|,
name|isa
argument_list|,
name|mse_driver
argument_list|,
name|mse_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|struct
name|isa_pnp_id
name|mse_ids
index|[]
init|=
block|{
block|{
literal|0x000fd041
block|,
literal|"Bus mouse"
block|}
block|,
comment|/* PNP0F00 */
block|{
literal|0x020fd041
block|,
literal|"InPort mouse"
block|}
block|,
comment|/* PNP0F02 */
block|{
literal|0x0d0fd041
block|,
literal|"InPort mouse compatible"
block|}
block|,
comment|/* PNP0F0D */
block|{
literal|0x110fd041
block|,
literal|"Bus mouse compatible"
block|}
block|,
comment|/* PNP0F11 */
block|{
literal|0x150fd041
block|,
literal|"Logitech bus mouse"
block|}
block|,
comment|/* PNP0F15 */
block|{
literal|0x180fd041
block|,
literal|"Logitech bus mouse compatible"
block|}
block|,
comment|/* PNP0F18 */
block|{
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Logitech bus mouse definitions  */
end_comment

begin_define
define|#
directive|define
name|MSE_SETUP
value|0x91
end_define

begin_comment
comment|/* What does this mean? */
end_comment

begin_comment
comment|/* The definition for the control port */
end_comment

begin_comment
comment|/* is as follows: */
end_comment

begin_comment
comment|/* D7 	 =  Mode set flag (1 = active) 	*/
end_comment

begin_comment
comment|/* D6,D5 =  Mode selection (port A) 	*/
end_comment

begin_comment
comment|/* 	    00 = Mode 0 = Basic I/O 	*/
end_comment

begin_comment
comment|/* 	    01 = Mode 1 = Strobed I/O 	*/
end_comment

begin_comment
comment|/* 	    10 = Mode 2 = Bi-dir bus 	*/
end_comment

begin_comment
comment|/* D4	 =  Port A direction (1 = input)*/
end_comment

begin_comment
comment|/* D3	 =  Port C (upper 4 bits) 	*/
end_comment

begin_comment
comment|/*	    direction. (1 = input)	*/
end_comment

begin_comment
comment|/* D2	 =  Mode selection (port B& C) */
end_comment

begin_comment
comment|/*	    0 = Mode 0 = Basic I/O	*/
end_comment

begin_comment
comment|/*	    1 = Mode 1 = Strobed I/O	*/
end_comment

begin_comment
comment|/* D1	 =  Port B direction (1 = input)*/
end_comment

begin_comment
comment|/* D0	 =  Port C (lower 4 bits)	*/
end_comment

begin_comment
comment|/*	    direction. (1 = input)	*/
end_comment

begin_comment
comment|/* So 91 means Basic I/O on all 3 ports,*/
end_comment

begin_comment
comment|/* Port A is an input port, B is an 	*/
end_comment

begin_comment
comment|/* output port, C is split with upper	*/
end_comment

begin_comment
comment|/* 4 bits being an output port and lower*/
end_comment

begin_comment
comment|/* 4 bits an input port, and enable the */
end_comment

begin_comment
comment|/* sucker.				*/
end_comment

begin_comment
comment|/* Courtesy Intel 8255 databook. Lars   */
end_comment

begin_define
define|#
directive|define
name|MSE_HOLD
value|0x80
end_define

begin_define
define|#
directive|define
name|MSE_RXLOW
value|0x00
end_define

begin_define
define|#
directive|define
name|MSE_RXHIGH
value|0x20
end_define

begin_define
define|#
directive|define
name|MSE_RYLOW
value|0x40
end_define

begin_define
define|#
directive|define
name|MSE_RYHIGH
value|0x60
end_define

begin_define
define|#
directive|define
name|MSE_DISINTR
value|0x10
end_define

begin_define
define|#
directive|define
name|MSE_INTREN
value|0x00
end_define

begin_function_decl
specifier|static
name|int
name|mse_probelogi
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|mse_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mse_disablelogi
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mse_getlogi
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|,
name|int
modifier|*
name|dx
parameter_list|,
name|int
modifier|*
name|dy
parameter_list|,
name|int
modifier|*
name|but
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mse_enablelogi
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ATI Inport mouse definitions  */
end_comment

begin_define
define|#
directive|define
name|MSE_INPORT_RESET
value|0x80
end_define

begin_define
define|#
directive|define
name|MSE_INPORT_STATUS
value|0x00
end_define

begin_define
define|#
directive|define
name|MSE_INPORT_DX
value|0x01
end_define

begin_define
define|#
directive|define
name|MSE_INPORT_DY
value|0x02
end_define

begin_define
define|#
directive|define
name|MSE_INPORT_MODE
value|0x07
end_define

begin_define
define|#
directive|define
name|MSE_INPORT_HOLD
value|0x20
end_define

begin_define
define|#
directive|define
name|MSE_INPORT_INTREN
value|0x09
end_define

begin_function_decl
specifier|static
name|int
name|mse_probeati
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|mse_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mse_enableati
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mse_disableati
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mse_getati
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|,
name|int
modifier|*
name|dx
parameter_list|,
name|int
modifier|*
name|dy
parameter_list|,
name|int
modifier|*
name|but
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|struct
name|mse_types
name|mse_types
index|[]
init|=
block|{
block|{
name|MSE_ATIINPORT
block|,
name|mse_probeati
block|,
name|mse_enableati
block|,
name|mse_disableati
block|,
name|mse_getati
block|,
block|{
literal|2
block|,
name|MOUSE_IF_INPORT
block|,
name|MOUSE_MOUSE
block|,
name|MOUSE_MODEL_GENERIC
block|,
literal|0
block|, }
block|,
block|{
name|MOUSE_PROTO_INPORT
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|0
block|,
name|MOUSE_MSC_PACKETSIZE
block|,
block|{
name|MOUSE_MSC_SYNCMASK
block|,
name|MOUSE_MSC_SYNC
block|, }
block|, }
block|, }
block|,
block|{
name|MSE_LOGITECH
block|,
name|mse_probelogi
block|,
name|mse_enablelogi
block|,
name|mse_disablelogi
block|,
name|mse_getlogi
block|,
block|{
literal|2
block|,
name|MOUSE_IF_BUS
block|,
name|MOUSE_MOUSE
block|,
name|MOUSE_MODEL_GENERIC
block|,
literal|0
block|, }
block|,
block|{
name|MOUSE_PROTO_BUS
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|0
block|,
name|MOUSE_MSC_PACKETSIZE
block|,
block|{
name|MOUSE_MSC_SYNCMASK
block|,
name|MOUSE_MSC_SYNC
block|, }
block|, }
block|, }
block|,
block|{
literal|0
block|, }
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|mse_isa_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|mse_softc_t
modifier|*
name|sc
decl_stmt|;
name|int
name|error
decl_stmt|;
name|int
name|rid
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|/* check PnP IDs */
name|error
operator|=
name|ISA_PNP_PROBE
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|mse_ids
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
name|ENXIO
condition|)
return|return
name|error
return|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|rid
operator|=
literal|0
expr_stmt|;
name|sc
operator|->
name|sc_port
operator|=
name|bus_alloc_resource_anywhere
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IOPORT
argument_list|,
operator|&
name|rid
argument_list|,
name|MSE_IOSIZE
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|sc_port
operator|==
name|NULL
condition|)
return|return
name|ENXIO
return|;
comment|/* 	 * Check for each mouse type in the table. 	 */
name|i
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|mse_types
index|[
name|i
index|]
operator|.
name|m_type
condition|)
block|{
if|if
condition|(
operator|(
operator|*
name|mse_types
index|[
name|i
index|]
operator|.
name|m_probe
operator|)
operator|(
name|dev
operator|,
name|sc
operator|)
condition|)
block|{
name|sc
operator|->
name|sc_mousetype
operator|=
name|mse_types
index|[
name|i
index|]
operator|.
name|m_type
expr_stmt|;
name|sc
operator|->
name|sc_enablemouse
operator|=
name|mse_types
index|[
name|i
index|]
operator|.
name|m_enable
expr_stmt|;
name|sc
operator|->
name|sc_disablemouse
operator|=
name|mse_types
index|[
name|i
index|]
operator|.
name|m_disable
expr_stmt|;
name|sc
operator|->
name|sc_getmouse
operator|=
name|mse_types
index|[
name|i
index|]
operator|.
name|m_get
expr_stmt|;
name|sc
operator|->
name|hw
operator|=
name|mse_types
index|[
name|i
index|]
operator|.
name|m_hw
expr_stmt|;
name|sc
operator|->
name|mode
operator|=
name|mse_types
index|[
name|i
index|]
operator|.
name|m_mode
expr_stmt|;
name|bus_release_resource
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IOPORT
argument_list|,
name|rid
argument_list|,
name|sc
operator|->
name|sc_port
argument_list|)
expr_stmt|;
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"Bus/InPort Mouse"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|i
operator|++
expr_stmt|;
block|}
name|bus_release_resource
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IOPORT
argument_list|,
name|rid
argument_list|,
name|sc
operator|->
name|sc_port
argument_list|)
expr_stmt|;
return|return
name|ENXIO
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|mse_isa_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|mse_softc_t
modifier|*
name|sc
decl_stmt|;
name|int
name|rid
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|rid
operator|=
literal|0
expr_stmt|;
name|sc
operator|->
name|sc_port
operator|=
name|bus_alloc_resource_anywhere
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IOPORT
argument_list|,
operator|&
name|rid
argument_list|,
name|MSE_IOSIZE
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|sc_port
operator|==
name|NULL
condition|)
return|return
name|ENXIO
return|;
return|return
operator|(
name|mse_common_attach
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Routines for the Logitech mouse.  */
end_comment

begin_comment
comment|/*  * Test for a Logitech bus mouse and return 1 if it is.  * (until I know how to use the signature port properly, just disable  *  interrupts and return 1)  */
end_comment

begin_function
specifier|static
name|int
name|mse_probelogi
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|mse_softc_t
modifier|*
name|sc
parameter_list|)
block|{
name|int
name|sig
decl_stmt|;
name|bus_write_1
argument_list|(
name|sc
operator|->
name|sc_port
argument_list|,
name|MSE_PORTD
argument_list|,
name|MSE_SETUP
argument_list|)
expr_stmt|;
comment|/* set the signature port */
name|bus_write_1
argument_list|(
name|sc
operator|->
name|sc_port
argument_list|,
name|MSE_PORTB
argument_list|,
name|MSE_LOGI_SIG
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|30000
argument_list|)
expr_stmt|;
comment|/* 30 ms delay */
name|sig
operator|=
name|bus_read_1
argument_list|(
name|sc
operator|->
name|sc_port
argument_list|,
name|MSE_PORTB
argument_list|)
operator|&
literal|0xFF
expr_stmt|;
if|if
condition|(
name|sig
operator|==
name|MSE_LOGI_SIG
condition|)
block|{
name|bus_write_1
argument_list|(
name|sc
operator|->
name|sc_port
argument_list|,
name|MSE_PORTC
argument_list|,
name|MSE_DISINTR
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
else|else
block|{
if|if
condition|(
name|bootverbose
condition|)
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"wrong signature %x\n"
argument_list|,
name|sig
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
end_function

begin_comment
comment|/*  * Initialize Logitech mouse and enable interrupts.  */
end_comment

begin_function
specifier|static
name|void
name|mse_enablelogi
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|)
block|{
name|int
name|dx
decl_stmt|,
name|dy
decl_stmt|,
name|but
decl_stmt|;
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTD
argument_list|,
name|MSE_SETUP
argument_list|)
expr_stmt|;
name|mse_getlogi
argument_list|(
name|port
argument_list|,
operator|&
name|dx
argument_list|,
operator|&
name|dy
argument_list|,
operator|&
name|but
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Disable interrupts for Logitech mouse.  */
end_comment

begin_function
specifier|static
name|void
name|mse_disablelogi
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|)
block|{
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTC
argument_list|,
name|MSE_DISINTR
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Get the current dx, dy and button up/down state.  */
end_comment

begin_function
specifier|static
name|void
name|mse_getlogi
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|,
name|int
modifier|*
name|dx
parameter_list|,
name|int
modifier|*
name|dy
parameter_list|,
name|int
modifier|*
name|but
parameter_list|)
block|{
name|char
name|x
decl_stmt|,
name|y
decl_stmt|;
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTC
argument_list|,
name|MSE_HOLD
operator||
name|MSE_RXLOW
argument_list|)
expr_stmt|;
name|x
operator|=
name|bus_read_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTA
argument_list|)
expr_stmt|;
operator|*
name|but
operator|=
operator|(
name|x
operator|>>
literal|5
operator|)
operator|&
name|MOUSE_MSC_BUTTONS
expr_stmt|;
name|x
operator|&=
literal|0xf
expr_stmt|;
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTC
argument_list|,
name|MSE_HOLD
operator||
name|MSE_RXHIGH
argument_list|)
expr_stmt|;
name|x
operator||=
operator|(
name|bus_read_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTA
argument_list|)
operator|<<
literal|4
operator|)
expr_stmt|;
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTC
argument_list|,
name|MSE_HOLD
operator||
name|MSE_RYLOW
argument_list|)
expr_stmt|;
name|y
operator|=
operator|(
name|bus_read_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTA
argument_list|)
operator|&
literal|0xf
operator|)
expr_stmt|;
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTC
argument_list|,
name|MSE_HOLD
operator||
name|MSE_RYHIGH
argument_list|)
expr_stmt|;
name|y
operator||=
operator|(
name|bus_read_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTA
argument_list|)
operator|<<
literal|4
operator|)
expr_stmt|;
operator|*
name|dx
operator|=
name|x
expr_stmt|;
operator|*
name|dy
operator|=
name|y
expr_stmt|;
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTC
argument_list|,
name|MSE_INTREN
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Routines for the ATI Inport bus mouse.  */
end_comment

begin_comment
comment|/*  * Test for an ATI Inport bus mouse and return 1 if it is.  * (do not enable interrupts)  */
end_comment

begin_function
specifier|static
name|int
name|mse_probeati
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|mse_softc_t
modifier|*
name|sc
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|2
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|bus_read_1
argument_list|(
name|sc
operator|->
name|sc_port
argument_list|,
name|MSE_PORTC
argument_list|)
operator|==
literal|0xde
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Initialize ATI Inport mouse and enable interrupts.  */
end_comment

begin_function
specifier|static
name|void
name|mse_enableati
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|)
block|{
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTA
argument_list|,
name|MSE_INPORT_RESET
argument_list|)
expr_stmt|;
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTA
argument_list|,
name|MSE_INPORT_MODE
argument_list|)
expr_stmt|;
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTB
argument_list|,
name|MSE_INPORT_INTREN
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Disable interrupts for ATI Inport mouse.  */
end_comment

begin_function
specifier|static
name|void
name|mse_disableati
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|)
block|{
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTA
argument_list|,
name|MSE_INPORT_MODE
argument_list|)
expr_stmt|;
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTB
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Get current dx, dy and up/down button state.  */
end_comment

begin_function
specifier|static
name|void
name|mse_getati
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|,
name|int
modifier|*
name|dx
parameter_list|,
name|int
modifier|*
name|dy
parameter_list|,
name|int
modifier|*
name|but
parameter_list|)
block|{
name|char
name|byte
decl_stmt|;
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTA
argument_list|,
name|MSE_INPORT_MODE
argument_list|)
expr_stmt|;
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTB
argument_list|,
name|MSE_INPORT_HOLD
argument_list|)
expr_stmt|;
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTA
argument_list|,
name|MSE_INPORT_STATUS
argument_list|)
expr_stmt|;
operator|*
name|but
operator|=
operator|~
name|bus_read_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTB
argument_list|)
operator|&
name|MOUSE_MSC_BUTTONS
expr_stmt|;
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTA
argument_list|,
name|MSE_INPORT_DX
argument_list|)
expr_stmt|;
name|byte
operator|=
name|bus_read_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTB
argument_list|)
expr_stmt|;
operator|*
name|dx
operator|=
name|byte
expr_stmt|;
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTA
argument_list|,
name|MSE_INPORT_DY
argument_list|)
expr_stmt|;
name|byte
operator|=
name|bus_read_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTB
argument_list|)
expr_stmt|;
operator|*
name|dy
operator|=
name|byte
expr_stmt|;
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTA
argument_list|,
name|MSE_INPORT_MODE
argument_list|)
expr_stmt|;
name|bus_write_1
argument_list|(
name|port
argument_list|,
name|MSE_PORTB
argument_list|,
name|MSE_INPORT_INTREN
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

