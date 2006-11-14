begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: iq31244_7seg.c,v 1.2 2003/07/15 00:25:01 lukem Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001, 2002, 2003 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Support for the 7-segment display on the Intel IQ31244.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

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
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/i80321/iq80321reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/i80321/iq80321var.h>
end_include

begin_define
define|#
directive|define
name|WRITE
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|*((__volatile uint8_t *) (x)) = (v)
end_define

begin_decl_stmt
specifier|static
name|int
name|snakestate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The 7-segment display looks like so:  *  *         A  *	+-----+  *	|     |  *    F	|     | B  *	|  G  |  *	+-----+  *	|     |  *    E	|     | C  *	|  D  |  *	+-----+ o  DP  *  * Setting a bit clears the corresponding segment on the  * display.  */
end_comment

begin_define
define|#
directive|define
name|SEG_A
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SEG_B
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SEG_C
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SEG_D
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SEG_E
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SEG_F
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SEG_G
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SEG_DP
value|(1<< 7)
end_define

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|digitmap
index|[]
init|=
block|{
comment|/*	+#####+  *	#     #  *	#     #  *	#     #  *	+-----+  *	#     #  *	#     #  *	#     #  *	+#####+  */
name|SEG_G
block|,
comment|/*	+-----+  *	|     #  *	|     #  *	|     #  *	+-----+  *	|     #  *	|     #  *	|     #  *	+-----+  */
name|SEG_A
operator||
name|SEG_D
operator||
name|SEG_E
operator||
name|SEG_F
operator||
name|SEG_G
block|,
comment|/*	+#####+  *	|     #  *	|     #  *	|     #  *	+#####+  *	#     |  *	#     |  *	#     |  *	+#####+  */
name|SEG_C
operator||
name|SEG_F
block|,
comment|/*	+#####+  *	|     #  *	|     #  *	|     #  *	+#####+  *	|     #  *	|     #  *	|     #  *	+#####+  */
name|SEG_E
operator||
name|SEG_F
block|,
comment|/*	+-----+  *	#     #  *	#     #  *	#     #  *	+#####+  *	|     #  *	|     #  *	|     #  *	+-----+  */
name|SEG_A
operator||
name|SEG_D
operator||
name|SEG_E
block|,
comment|/*	+#####+  *	#     |  *	#     |  *	#     |  *	+#####+  *	|     #  *	|     #  *	|     #  *	+#####+  */
name|SEG_B
operator||
name|SEG_E
block|,
comment|/*	+#####+  *	#     |  *	#     |  *	#     |  *	+#####+  *	#     #  *	#     #  *	#     #  *	+#####+  */
name|SEG_B
block|,
comment|/*	+#####+  *	|     #  *	|     #  *	|     #  *	+-----+  *	|     #  *	|     #  *	|     #  *	+-----+  */
name|SEG_D
operator||
name|SEG_E
operator||
name|SEG_F
block|,
comment|/*	+#####+  *	#     #  *	#     #  *	#     #  *	+#####+  *	#     #  *	#     #  *	#     #  *	+#####+  */
literal|0
block|,
comment|/*	+#####+  *	#     #  *	#     #  *	#     #  *	+#####+  *	|     #  *	|     #  *	|     #  *	+-----+  */
name|SEG_D
operator||
name|SEG_E
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|uint8_t
name|iq80321_7seg_xlate
parameter_list|(
name|char
name|c
parameter_list|)
block|{
name|uint8_t
name|rv
decl_stmt|;
if|if
condition|(
name|c
operator|>=
literal|'0'
operator|&&
name|c
operator|<=
literal|'9'
condition|)
name|rv
operator|=
name|digitmap
index|[
name|c
operator|-
literal|'0'
index|]
expr_stmt|;
elseif|else
if|if
condition|(
name|c
operator|==
literal|'.'
condition|)
name|rv
operator|=
operator|(
name|uint8_t
operator|)
operator|~
name|SEG_DP
expr_stmt|;
else|else
name|rv
operator|=
literal|0xff
expr_stmt|;
return|return
operator|(
name|rv
operator|)
return|;
block|}
end_function

begin_function
name|void
name|iq80321_7seg
parameter_list|(
name|char
name|a
parameter_list|,
name|char
name|b
parameter_list|)
block|{
name|uint8_t
name|msb
decl_stmt|,
name|lsb
decl_stmt|;
name|msb
operator|=
name|iq80321_7seg_xlate
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|lsb
operator|=
name|iq80321_7seg_xlate
argument_list|(
name|b
argument_list|)
expr_stmt|;
name|snakestate
operator|=
literal|0
expr_stmt|;
name|WRITE
argument_list|(
name|IQ80321_7SEG_MSB
argument_list|,
name|msb
argument_list|)
expr_stmt|;
name|WRITE
argument_list|(
name|IQ80321_7SEG_LSB
argument_list|,
name|lsb
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|snakemap
index|[]
index|[
literal|2
index|]
init|=
block|{
comment|/*	+#####+		+#####+  *	|     |		|     |  *	|     |		|     |  *	|     |		|     |  *	+-----+		+-----+  *	|     |		|     |  *	|     |		|     |  *	|     |		|     |  *	+-----+		+-----+  */
block|{
operator|~
name|SEG_A
block|,
operator|~
name|SEG_A
block|}
block|,
comment|/*	+-----+		+-----+  *	#     |		|     #  *	#     |		|     #  *	#     |		|     #  *	+-----+		+-----+  *	|     |		|     |  *	|     |		|     |  *	|     |		|     |  *	+-----+		+-----+  */
block|{
operator|~
name|SEG_F
block|,
operator|~
name|SEG_B
block|}
block|,
comment|/*	+-----+		+-----+  *	|     |		|     |  *	|     |		|     |  *	|     |		|     |  *	+#####+		+#####+  *	|     |		|     |  *	|     |		|     |  *	|     |		|     |  *	+-----+		+-----+  */
block|{
operator|~
name|SEG_G
block|,
operator|~
name|SEG_G
block|}
block|,
comment|/*	+-----+		+-----+  *	|     |		|     |  *	|     |		|     |  *	|     |		|     |  *	+-----+		+-----+  *	|     #		#     |  *	|     #		#     |  *	|     #		#     |  *	+-----+		+-----+  */
block|{
operator|~
name|SEG_C
block|,
operator|~
name|SEG_E
block|}
block|,
comment|/*	+-----+		+-----+  *	|     |		|     |  *	|     |		|     |  *	|     |		|     |  *	+-----+		+-----+  *	|     |		|     |  *	|     |		|     |  *	|     |		|     |  *	+#####+		+#####+  */
block|{
operator|~
name|SEG_D
block|,
operator|~
name|SEG_D
block|}
block|,
comment|/*	+-----+		+-----+  *	|     |		|     |  *	|     |		|     |  *	|     |		|     |  *	+-----+		+-----+  *	#     |		|     #  *	#     |		|     #  *	#     |		|     #  *	+-----+		+-----+  */
block|{
operator|~
name|SEG_E
block|,
operator|~
name|SEG_C
block|}
block|,
comment|/*	+-----+		+-----+  *	|     |		|     |  *	|     |		|     |  *	|     |		|     |  *	+#####+		+#####+  *	|     |		|     |  *	|     |		|     |  *	|     |		|     |  *	+-----+		+-----+  */
block|{
operator|~
name|SEG_G
block|,
operator|~
name|SEG_G
block|}
block|,
comment|/*	+-----+		+-----+  *	|     #		#     |  *	|     #		#     |  *	|     #		#     |  *	+-----+		+-----+  *	|     |		|     |  *	|     |		|     |  *	|     |		|     |  *	+-----+		+-----+  */
block|{
operator|~
name|SEG_B
block|,
operator|~
name|SEG_F
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_hw
argument_list|,
name|OID_AUTO
argument_list|,
name|sevenseg
argument_list|,
name|CTLFLAG_RD
argument_list|,
literal|0
argument_list|,
literal|"7 seg"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|int
name|freq
init|=
literal|20
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw_sevenseg
argument_list|,
name|OID_AUTO
argument_list|,
name|freq
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|freq
argument_list|,
literal|0
argument_list|,
literal|"7 Seg update frequency"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|void
name|iq31244_7seg_snake
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|int
name|snakefreq
decl_stmt|;
name|int
name|cur
init|=
name|snakestate
decl_stmt|;
name|snakefreq
operator|++
expr_stmt|;
if|if
condition|(
operator|(
name|snakefreq
operator|%
name|freq
operator|)
condition|)
return|return;
name|WRITE
argument_list|(
name|IQ80321_7SEG_MSB
argument_list|,
name|snakemap
index|[
name|cur
index|]
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|WRITE
argument_list|(
name|IQ80321_7SEG_LSB
argument_list|,
name|snakemap
index|[
name|cur
index|]
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|snakestate
operator|=
operator|(
name|cur
operator|+
literal|1
operator|)
operator|&
literal|7
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|iq31244_7seg_softc
block|{
name|device_t
name|dev
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|int
name|iq31244_7seg_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"IQ31244 7seg"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|i80321_hardclock_hook
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|int
name|iq31244_7seg_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|i80321_hardclock_hook
operator|=
name|iq31244_7seg_snake
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|iq31244_7seg_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|iq31244_7seg_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|iq31244_7seg_attach
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|iq31244_7seg_driver
init|=
block|{
literal|"iqseg"
block|,
name|iq31244_7seg_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|iq31244_7seg_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|iq31244_7seg_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|iqseg
argument_list|,
name|iq
argument_list|,
name|iq31244_7seg_driver
argument_list|,
name|iq31244_7seg_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

