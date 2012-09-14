begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002, 2003 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * from: FreeBSD: //depot/projects/arm/src/sys/arm/xscale/pxa2x0/pxa2x0var.h, rev 1  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MVVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MVVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/vm.h>
end_include

begin_define
define|#
directive|define
name|MV_TYPE_PCI
value|0
end_define

begin_define
define|#
directive|define
name|MV_TYPE_PCIE
value|1
end_define

begin_define
define|#
directive|define
name|MV_MODE_ENDPOINT
value|0
end_define

begin_define
define|#
directive|define
name|MV_MODE_ROOT
value|1
end_define

begin_struct
struct|struct
name|gpio_config
block|{
name|int
name|gc_gpio
decl_stmt|;
comment|/* GPIO number */
name|uint32_t
name|gc_flags
decl_stmt|;
comment|/* GPIO flags */
name|int
name|gc_output
decl_stmt|;
comment|/* GPIO output value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|decode_win
block|{
name|int
name|target
decl_stmt|;
comment|/* Mbus unit ID */
name|int
name|attr
decl_stmt|;
comment|/* Attributes of the target interface */
name|vm_paddr_t
name|base
decl_stmt|;
comment|/* Physical base addr */
name|uint32_t
name|size
decl_stmt|;
name|vm_paddr_t
name|remap
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|pmap_devmap
name|pmap_devmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|gpio_config
name|mv_gpio_config
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|decode_win
modifier|*
name|cpu_wins
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|decode_win
modifier|*
name|idma_wins
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|decode_win
modifier|*
name|xor_wins
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|idma_wins_no
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xor_wins_no
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function prototypes */
end_comment

begin_function_decl
name|int
name|mv_gpio_setup_intrhandler
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|driver_filter_t
modifier|*
name|filt
parameter_list|,
name|void
function_decl|(
modifier|*
name|hand
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|pin
parameter_list|,
name|int
name|flags
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mv_gpio_intr_mask
parameter_list|(
name|int
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mv_gpio_intr_unmask
parameter_list|(
name|int
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mv_gpio_out
parameter_list|(
name|uint32_t
name|pin
parameter_list|,
name|uint8_t
name|val
parameter_list|,
name|uint8_t
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|mv_gpio_in
parameter_list|(
name|uint32_t
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|platform_gpio_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|soc_decode_win
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soc_id
parameter_list|(
name|uint32_t
modifier|*
name|dev
parameter_list|,
name|uint32_t
modifier|*
name|rev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soc_dump_decode_win
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|soc_power_ctrl_get
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soc_power_ctrl_set
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|get_sar_value
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|decode_win_cpu_set
parameter_list|(
name|int
name|target
parameter_list|,
name|int
name|attr
parameter_list|,
name|vm_paddr_t
name|base
parameter_list|,
name|uint32_t
name|size
parameter_list|,
name|vm_paddr_t
name|remap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|decode_win_overlap
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|decode_win
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|win_cpu_can_remap
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|decode_win_pcie_setup
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ddr_is_active
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ddr_base
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ddr_size
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ddr_attr
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ddr_target
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|cpu_extra_feat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|get_tclk
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|get_l2clk
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|read_cpu_ctrl
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_cpu_ctrl
parameter_list|(
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_ARMADAXP
argument_list|)
end_if

begin_function_decl
name|uint32_t
name|read_cpu_mp_clocks
parameter_list|(
name|uint32_t
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_cpu_mp_clocks
parameter_list|(
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|read_cpu_misc
parameter_list|(
name|uint32_t
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_cpu_misc
parameter_list|(
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|mv_pcib_bar_win_set
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|base
parameter_list|,
name|uint32_t
name|size
parameter_list|,
name|uint32_t
name|remap
parameter_list|,
name|int
name|winno
parameter_list|,
name|int
name|busno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mv_pcib_cpu_win_remap
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|remap
parameter_list|,
name|uint32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mv_mask_endpoint_irq
parameter_list|(
name|uintptr_t
name|nb
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mv_unmask_endpoint_irq
parameter_list|(
name|uintptr_t
name|nb
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mv_drbl_get_next_irq
parameter_list|(
name|int
name|dir
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mv_drbl_mask_all
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mv_drbl_mask_irq
parameter_list|(
name|uint32_t
name|irq
parameter_list|,
name|int
name|dir
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mv_drbl_unmask_irq
parameter_list|(
name|uint32_t
name|irq
parameter_list|,
name|int
name|dir
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mv_drbl_set_mask
parameter_list|(
name|uint32_t
name|val
parameter_list|,
name|int
name|dir
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|mv_drbl_get_mask
parameter_list|(
name|int
name|dir
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mv_drbl_set_cause
parameter_list|(
name|uint32_t
name|val
parameter_list|,
name|int
name|dir
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|mv_drbl_get_cause
parameter_list|(
name|int
name|dir
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mv_drbl_set_msg
parameter_list|(
name|uint32_t
name|val
parameter_list|,
name|int
name|mnr
parameter_list|,
name|int
name|dir
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|mv_drbl_get_msg
parameter_list|(
name|int
name|mnr
parameter_list|,
name|int
name|dir
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MVVAR_H_ */
end_comment

end_unit

