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
name|MV_TYPE_PCIE_AGGR_LANE
value|2
end_define

begin_comment
comment|/* Additional PCIE lane to aggregate */
end_comment

begin_struct
struct|struct
name|obio_softc
block|{
name|bus_space_tag_t
name|obio_bst
decl_stmt|;
comment|/* bus space tag */
name|struct
name|rman
name|obio_mem
decl_stmt|;
name|struct
name|rman
name|obio_irq
decl_stmt|;
name|struct
name|rman
name|obio_gpio
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|obio_device
block|{
specifier|const
name|char
modifier|*
name|od_name
decl_stmt|;
name|u_long
name|od_base
decl_stmt|;
name|u_long
name|od_size
decl_stmt|;
name|u_int
name|od_irqs
index|[
literal|7
operator|+
literal|1
index|]
decl_stmt|;
comment|/* keep additional entry for -1 sentinel */
name|u_int
name|od_gpio
index|[
literal|2
operator|+
literal|1
index|]
decl_stmt|;
comment|/* as above for IRQ */
name|u_int
name|od_pwr_mask
decl_stmt|;
name|struct
name|resource_list
name|od_resources
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|obio_pci_irq_map
block|{
name|int
name|opim_slot
decl_stmt|;
name|int
name|opim_pin
decl_stmt|;
name|int
name|opim_irq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|obio_pci
block|{
name|int
name|op_type
decl_stmt|;
name|bus_addr_t
name|op_base
decl_stmt|;
name|u_long
name|op_size
decl_stmt|;
comment|/* Note IO/MEM regions are assumed VA == PA */
name|bus_addr_t
name|op_io_base
decl_stmt|;
name|u_long
name|op_io_size
decl_stmt|;
name|int
name|op_io_win_target
decl_stmt|;
name|int
name|op_io_win_attr
decl_stmt|;
name|bus_addr_t
name|op_mem_base
decl_stmt|;
name|u_long
name|op_mem_size
decl_stmt|;
name|int
name|op_mem_win_target
decl_stmt|;
name|int
name|op_mem_win_attr
decl_stmt|;
specifier|const
name|struct
name|obio_pci_irq_map
modifier|*
name|op_pci_irq_map
decl_stmt|;
name|int
name|op_irq
decl_stmt|;
comment|/* used if IRQ map table is NULL */
block|}
struct|;
end_struct

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
name|int
name|remap
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|obio_pci
name|mv_pci_info
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
name|bus_space_tag_t
name|obio_tag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|obio_device
name|obio_devices
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
name|cpu_wins_no
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
name|int
name|mv_gpio_configure
parameter_list|(
name|uint32_t
name|pin
parameter_list|,
name|uint32_t
name|flags
parameter_list|,
name|uint32_t
name|mask
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
name|platform_pmap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_mpp_init
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
name|soc_identify
parameter_list|(
name|void
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
name|int
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
name|decode_win_idma_dump
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|decode_win_idma_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|decode_win_idma_valid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|decode_win_xor_dump
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|decode_win_xor_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|decode_win_xor_valid
parameter_list|(
name|void
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

begin_enum
enum|enum
name|mbus_device_ivars
block|{
name|MBUS_IVAR_BASE
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|MBUS_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(mbus, var, MBUS, ivar, type)
end_define

begin_macro
name|MBUS_ACCESSOR
argument_list|(
argument|base
argument_list|,
argument|BASE
argument_list|,
argument|u_long
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|MBUS_ACCESSOR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MVVAR_H_ */
end_comment

end_unit

