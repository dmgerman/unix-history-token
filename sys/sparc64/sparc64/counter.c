begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 by Thomas Moestl<tmm@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/timetc.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus_common.h>
end_include

begin_define
define|#
directive|define
name|COUNTER_MASK
value|((1<< 29) - 1)
end_define

begin_define
define|#
directive|define
name|COUNTER_FREQ
value|1000000
end_define

begin_comment
comment|/* Bits in the limit register. */
end_comment

begin_define
define|#
directive|define
name|CTLR_INTEN
value|(1U<< 31)
end_define

begin_comment
comment|/* Enable timer interrupts */
end_comment

begin_define
define|#
directive|define
name|CTLR_RELOAD
value|(1U<< 30)
end_define

begin_comment
comment|/* Zero counter on write to limit reg */
end_comment

begin_define
define|#
directive|define
name|CTLR_PERIODIC
value|(1U<< 29)
end_define

begin_comment
comment|/* Wrap to 0 if limit is reached */
end_comment

begin_comment
comment|/* Offsets of the registers for the two counters. */
end_comment

begin_define
define|#
directive|define
name|CTR_CT0
value|0x00
end_define

begin_define
define|#
directive|define
name|CTR_CT1
value|0x10
end_define

begin_comment
comment|/* Register offsets from the base address. */
end_comment

begin_define
define|#
directive|define
name|CTR_COUNT
value|0x00
end_define

begin_define
define|#
directive|define
name|CTR_LIMIT
value|0x08
end_define

begin_function_decl
specifier|static
name|unsigned
name|counter_get_timecount
parameter_list|(
name|struct
name|timecounter
modifier|*
name|tc
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|ct_softc
block|{
name|bus_space_tag_t
name|sc_tag
decl_stmt|;
name|bus_space_handle_t
name|sc_handle
decl_stmt|;
name|bus_addr_t
name|sc_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is called from the psycho and sbus drivers. It does not directly attach  * to the nexus because it shares register space with the bridge in question.  */
end_comment

begin_function
name|void
name|sparc64_counter_init
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|handle
parameter_list|,
name|bus_addr_t
name|offset
parameter_list|)
block|{
name|struct
name|timecounter
modifier|*
name|tc
decl_stmt|;
name|struct
name|ct_softc
modifier|*
name|sc
decl_stmt|;
name|printf
argument_list|(
literal|"initialializing counter-timer\n"
argument_list|)
expr_stmt|;
comment|/* 	 * Turn off interrupts from both counters. Set the limit to the maximum 	 * value (although that should not change anything with CTLR_INTEN and 	 * CTLR_PERIODIC off). 	 */
name|bus_space_write_8
argument_list|(
name|tag
argument_list|,
name|handle
argument_list|,
name|offset
operator|+
name|CTR_CT0
operator|+
name|CTR_LIMIT
argument_list|,
name|COUNTER_MASK
argument_list|)
expr_stmt|;
name|bus_space_write_8
argument_list|(
name|tag
argument_list|,
name|handle
argument_list|,
name|offset
operator|+
name|CTR_CT1
operator|+
name|CTR_LIMIT
argument_list|,
name|COUNTER_MASK
argument_list|)
expr_stmt|;
comment|/* Register as a time counter. */
name|tc
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|tc
argument_list|)
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
name|sc
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|sc
argument_list|)
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_tag
operator|=
name|tag
expr_stmt|;
name|sc
operator|->
name|sc_handle
operator|=
name|handle
expr_stmt|;
name|sc
operator|->
name|sc_offset
operator|=
name|offset
operator|+
name|CTR_CT0
expr_stmt|;
name|tc
operator|->
name|tc_get_timecount
operator|=
name|counter_get_timecount
expr_stmt|;
name|tc
operator|->
name|tc_poll_pps
operator|=
name|NULL
expr_stmt|;
name|tc
operator|->
name|tc_counter_mask
operator|=
name|COUNTER_MASK
expr_stmt|;
name|tc
operator|->
name|tc_frequency
operator|=
name|COUNTER_FREQ
expr_stmt|;
name|tc
operator|->
name|tc_name
operator|=
literal|"counter-timer"
expr_stmt|;
name|tc
operator|->
name|tc_priv
operator|=
name|sc
expr_stmt|;
name|tc_init
argument_list|(
name|tc
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|counter_get_timecount
parameter_list|(
name|struct
name|timecounter
modifier|*
name|tc
parameter_list|)
block|{
name|struct
name|ct_softc
modifier|*
name|sc
decl_stmt|;
name|sc
operator|=
name|tc
operator|->
name|tc_priv
expr_stmt|;
return|return
operator|(
name|bus_space_read_8
argument_list|(
name|sc
operator|->
name|sc_tag
argument_list|,
name|sc
operator|->
name|sc_handle
argument_list|,
name|sc
operator|->
name|sc_offset
argument_list|)
operator|&
name|COUNTER_MASK
operator|)
return|;
block|}
end_function

end_unit

