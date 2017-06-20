begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Olivier Houchard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PL310_H_
end_ifndef

begin_define
define|#
directive|define
name|PL310_H_
end_define

begin_comment
comment|/**  *	PL310 - L2 Cache Controller register offsets.  *  */
end_comment

begin_define
define|#
directive|define
name|PL310_CACHE_ID
value|0x000
end_define

begin_define
define|#
directive|define
name|CACHE_ID_RELEASE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CACHE_ID_RELEASE_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|CACHE_ID_RELEASE_r0p0
value|0x00
end_define

begin_define
define|#
directive|define
name|CACHE_ID_RELEASE_r1p0
value|0x02
end_define

begin_define
define|#
directive|define
name|CACHE_ID_RELEASE_r2p0
value|0x04
end_define

begin_define
define|#
directive|define
name|CACHE_ID_RELEASE_r3p0
value|0x05
end_define

begin_define
define|#
directive|define
name|CACHE_ID_RELEASE_r3p1
value|0x06
end_define

begin_define
define|#
directive|define
name|CACHE_ID_RELEASE_r3p2
value|0x08
end_define

begin_define
define|#
directive|define
name|CACHE_ID_RELEASE_r3p3
value|0x09
end_define

begin_define
define|#
directive|define
name|CACHE_ID_PARTNUM_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|CACHE_ID_PARTNUM_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|CACHE_ID_PARTNUM_VALUE
value|0x3
end_define

begin_define
define|#
directive|define
name|PL310_CACHE_TYPE
value|0x004
end_define

begin_define
define|#
directive|define
name|PL310_CTRL
value|0x100
end_define

begin_define
define|#
directive|define
name|CTRL_ENABLED
value|0x01
end_define

begin_define
define|#
directive|define
name|CTRL_DISABLED
value|0x00
end_define

begin_define
define|#
directive|define
name|PL310_AUX_CTRL
value|0x104
end_define

begin_define
define|#
directive|define
name|AUX_CTRL_MASK
value|0xc0000fff
end_define

begin_define
define|#
directive|define
name|AUX_CTRL_ASSOCIATIVITY_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AUX_CTRL_WAY_SIZE_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|AUX_CTRL_WAY_SIZE_MASK
value|(0x7<< 17)
end_define

begin_define
define|#
directive|define
name|AUX_CTRL_SHARE_OVERRIDE
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|AUX_CTRL_NS_LOCKDOWN
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|AUX_CTRL_NS_INT_CTRL
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|AUX_CTRL_DATA_PREFETCH
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AUX_CTRL_INSTR_PREFETCH
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|AUX_CTRL_EARLY_BRESP
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|PL310_TAG_RAM_CTRL
value|0x108
end_define

begin_define
define|#
directive|define
name|PL310_DATA_RAM_CTRL
value|0x10C
end_define

begin_define
define|#
directive|define
name|RAM_CTRL_WRITE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RAM_CTRL_WRITE_MASK
value|(0x7<< 8)
end_define

begin_define
define|#
directive|define
name|RAM_CTRL_READ_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|RAM_CTRL_READ_MASK
value|(0x7<< 4)
end_define

begin_define
define|#
directive|define
name|RAM_CTRL_SETUP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RAM_CTRL_SETUP_MASK
value|(0x7<< 0)
end_define

begin_define
define|#
directive|define
name|PL310_EVENT_COUNTER_CTRL
value|0x200
end_define

begin_define
define|#
directive|define
name|EVENT_COUNTER_CTRL_ENABLED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EVENT_COUNTER_CTRL_C0_RESET
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|EVENT_COUNTER_CTRL_C1_RESET
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|PL310_EVENT_COUNTER1_CONF
value|0x204
end_define

begin_define
define|#
directive|define
name|PL310_EVENT_COUNTER0_CONF
value|0x208
end_define

begin_define
define|#
directive|define
name|EVENT_COUNTER_CONF_NOINTR
value|0
end_define

begin_define
define|#
directive|define
name|EVENT_COUNTER_CONF_INCR
value|1
end_define

begin_define
define|#
directive|define
name|EVENT_COUNTER_CONF_OVFW
value|2
end_define

begin_define
define|#
directive|define
name|EVENT_COUNTER_CONF_NOEV
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|EVENT_COUNTER_CONF_CO
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|EVENT_COUNTER_CONF_DRHIT
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|EVENT_COUNTER_CONF_DRREQ
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|EVENT_COUNTER_CONF_DWHIT
value|(4<< 2)
end_define

begin_define
define|#
directive|define
name|EVENT_COUNTER_CONF_DWREQ
value|(5<< 2)
end_define

begin_define
define|#
directive|define
name|EVENT_COUNTER_CONF_DWTREQ
value|(6<< 2)
end_define

begin_define
define|#
directive|define
name|EVENT_COUNTER_CONF_DIRHIT
value|(7<< 2)
end_define

begin_define
define|#
directive|define
name|EVENT_COUNTER_CONF_DIRREQ
value|(8<< 2)
end_define

begin_define
define|#
directive|define
name|EVENT_COUNTER_CONF_WA
value|(9<< 2)
end_define

begin_define
define|#
directive|define
name|PL310_EVENT_COUNTER1_VAL
value|0x20C
end_define

begin_define
define|#
directive|define
name|PL310_EVENT_COUNTER0_VAL
value|0x210
end_define

begin_define
define|#
directive|define
name|PL310_INTR_MASK
value|0x214
end_define

begin_define
define|#
directive|define
name|PL310_MASKED_INTR_STAT
value|0x218
end_define

begin_define
define|#
directive|define
name|PL310_RAW_INTR_STAT
value|0x21C
end_define

begin_define
define|#
directive|define
name|PL310_INTR_CLEAR
value|0x220
end_define

begin_define
define|#
directive|define
name|INTR_MASK_ALL
value|((1<< 9) - 1)
end_define

begin_define
define|#
directive|define
name|INTR_MASK_ECNTR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|INTR_MASK_PARRT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|INTR_MASK_PARRD
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|INTR_MASK_ERRWT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|INTR_MASK_ERRWD
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|INTR_MASK_ERRRT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|INTR_MASK_ERRRD
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|INTR_MASK_SLVERR
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|INTR_MASK_DECERR
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|PL310_CACHE_SYNC
value|0x730
end_define

begin_define
define|#
directive|define
name|PL310_INV_LINE_PA
value|0x770
end_define

begin_define
define|#
directive|define
name|PL310_INV_WAY
value|0x77C
end_define

begin_define
define|#
directive|define
name|PL310_CLEAN_LINE_PA
value|0x7B0
end_define

begin_define
define|#
directive|define
name|PL310_CLEAN_LINE_IDX
value|0x7B8
end_define

begin_define
define|#
directive|define
name|PL310_CLEAN_WAY
value|0x7BC
end_define

begin_define
define|#
directive|define
name|PL310_CLEAN_INV_LINE_PA
value|0x7F0
end_define

begin_define
define|#
directive|define
name|PL310_CLEAN_INV_LINE_IDX
value|0x7F8
end_define

begin_define
define|#
directive|define
name|PL310_CLEAN_INV_WAY
value|0x7FC
end_define

begin_define
define|#
directive|define
name|PL310_LOCKDOWN_D_WAY
parameter_list|(
name|x
parameter_list|)
value|(0x900 + ((x) * 8))
end_define

begin_define
define|#
directive|define
name|PL310_LOCKDOWN_I_WAY
parameter_list|(
name|x
parameter_list|)
value|(0x904 + ((x) * 8))
end_define

begin_define
define|#
directive|define
name|PL310_LOCKDOWN_LINE_ENABLE
value|0x950
end_define

begin_define
define|#
directive|define
name|PL310_UNLOCK_ALL_LINES_WAY
value|0x954
end_define

begin_define
define|#
directive|define
name|PL310_ADDR_FILTER_STAR
value|0xC00
end_define

begin_define
define|#
directive|define
name|PL310_ADDR_FILTER_END
value|0xC04
end_define

begin_define
define|#
directive|define
name|PL310_DEBUG_CTRL
value|0xF40
end_define

begin_define
define|#
directive|define
name|DEBUG_CTRL_DISABLE_LINEFILL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DEBUG_CTRL_DISABLE_WRITEBACK
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DEBUG_CTRL_SPNIDEN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|PL310_PREFETCH_CTRL
value|0xF60
end_define

begin_define
define|#
directive|define
name|PREFETCH_CTRL_OFFSET_MASK
value|(0x1f)
end_define

begin_define
define|#
directive|define
name|PREFETCH_CTRL_NOTSAMEID
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|PREFETCH_CTRL_INCR_DL
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|PREFETCH_CTRL_PREFETCH_DROP
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|PREFETCH_CTRL_DL_ON_WRAP
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|PREFETCH_CTRL_DATA_PREFETCH
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|PREFETCH_CTRL_INSTR_PREFETCH
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|PREFETCH_CTRL_DL
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|PL310_POWER_CTRL
value|0xF80
end_define

begin_define
define|#
directive|define
name|POWER_CTRL_ENABLE_GATING
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|POWER_CTRL_ENABLE_STANDBY
value|(1<< 0)
end_define

begin_struct_decl
struct_decl|struct
name|intr_config_hook
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|pl310_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_mem_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq_res
decl_stmt|;
name|void
modifier|*
name|sc_irq_h
decl_stmt|;
name|int
name|sc_enabled
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|u_int
name|sc_rtl_revision
decl_stmt|;
name|struct
name|intr_config_hook
modifier|*
name|sc_ich
decl_stmt|;
name|boolean_t
name|sc_io_coherent
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  *	pl310_read4 - read a 32-bit value from the PL310 registers  *	pl310_write4 - write a 32-bit value from the PL310 registers  *	@off: byte offset within the register set to read from  *	@val: the value to write into the register  *  *  *	LOCKING:  *	None  *  *	RETURNS:  *	nothing in case of write function, if read function returns the value read.  */
end_comment

begin_function
specifier|static
name|__inline
name|uint32_t
name|pl310_read4
parameter_list|(
name|struct
name|pl310_softc
modifier|*
name|sc
parameter_list|,
name|bus_size_t
name|off
parameter_list|)
block|{
return|return
name|bus_read_4
argument_list|(
name|sc
operator|->
name|sc_mem_res
argument_list|,
name|off
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|pl310_write4
parameter_list|(
name|struct
name|pl310_softc
modifier|*
name|sc
parameter_list|,
name|bus_size_t
name|off
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|bus_write_4
argument_list|(
name|sc
operator|->
name|sc_mem_res
argument_list|,
name|off
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|pl310_set_ram_latency
parameter_list|(
name|struct
name|pl310_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|which_reg
parameter_list|,
name|uint32_t
name|read
parameter_list|,
name|uint32_t
name|write
parameter_list|,
name|uint32_t
name|setup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_pl310_init
parameter_list|(
name|struct
name|pl310_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_pl310_write_ctrl
parameter_list|(
name|struct
name|pl310_softc
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_pl310_write_debug
parameter_list|(
name|struct
name|pl310_softc
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PL310_H_ */
end_comment

end_unit

