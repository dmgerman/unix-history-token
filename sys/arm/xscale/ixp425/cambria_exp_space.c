begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Sam Leffler.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Hack bus space tag for slow devices on the Cambria expansion bus;  * we slow the timing and add a 2us delay between r/w ops.  */
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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/ixp425/ixp425reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/ixp425/ixp425var.h>
end_include

begin_comment
comment|/* Prototypes for all the bus_space structure functions */
end_comment

begin_expr_stmt
name|bs_protos
argument_list|(
name|exp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bs_protos
argument_list|(
name|generic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bs_protos
argument_list|(
name|generic_armv4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|uint8_t
name|cambria_bs_r_1
parameter_list|(
name|void
modifier|*
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|)
block|{
name|DELAY
argument_list|(
literal|2
argument_list|)
expr_stmt|;
return|return
name|bus_space_read_1
argument_list|(
operator|(
expr|struct
name|bus_space
operator|*
operator|)
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|cambria_bs_w_1
parameter_list|(
name|void
modifier|*
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
name|u_int8_t
name|v
parameter_list|)
block|{
name|DELAY
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|bus_space_write_1
argument_list|(
operator|(
expr|struct
name|bus_space
operator|*
operator|)
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* NB: we only define what's needed by uart */
end_comment

begin_decl_stmt
name|struct
name|bus_space
name|cambria_exp_bs_tag
init|=
block|{
comment|/* mapping/unmapping */
operator|.
name|bs_map
operator|=
name|generic_bs_map
block|,
operator|.
name|bs_unmap
operator|=
name|generic_bs_unmap
block|,
comment|/* barrier */
operator|.
name|bs_barrier
operator|=
name|generic_bs_barrier
block|,
comment|/* read (single) */
operator|.
name|bs_r_1
operator|=
name|cambria_bs_r_1
block|,
comment|/* write (single) */
operator|.
name|bs_w_1
operator|=
name|cambria_bs_w_1
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|cambria_exp_bus_init
parameter_list|(
name|struct
name|ixp425_softc
modifier|*
name|sc
parameter_list|)
block|{
name|uint32_t
name|cs3
decl_stmt|;
name|KASSERT
argument_list|(
name|cpu_is_ixp43x
argument_list|()
argument_list|,
operator|(
literal|"wrong cpu type"
operator|)
argument_list|)
expr_stmt|;
name|cambria_exp_bs_tag
operator|.
name|bs_cookie
operator|=
name|sc
operator|->
name|sc_iot
expr_stmt|;
name|cs3
operator|=
name|EXP_BUS_READ_4
argument_list|(
name|sc
argument_list|,
name|EXP_TIMING_CS3_OFFSET
argument_list|)
expr_stmt|;
comment|/* XXX force slowest possible timings and byte mode */
name|EXP_BUS_WRITE_4
argument_list|(
name|sc
argument_list|,
name|EXP_TIMING_CS3_OFFSET
argument_list|,
name|cs3
operator||
operator|(
name|EXP_T1
operator||
name|EXP_T2
operator||
name|EXP_T3
operator||
name|EXP_T4
operator||
name|EXP_T5
operator|)
operator||
name|EXP_BYTE_EN
argument_list|)
expr_stmt|;
comment|/* XXX force GPIO 3+4 for GPS+RS485 uarts */
name|ixp425_set_gpio
argument_list|(
name|sc
argument_list|,
literal|3
argument_list|,
name|GPIO_TYPE_EDG_RISING
argument_list|)
expr_stmt|;
name|ixp425_set_gpio
argument_list|(
name|sc
argument_list|,
literal|4
argument_list|,
name|GPIO_TYPE_EDG_RISING
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

