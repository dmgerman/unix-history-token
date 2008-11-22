begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: i80321var.h,v 1.8 2003/10/06 16:06:06 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002, 2003 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_XSCALE_I80321VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARM_XSCALE_I80321VAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_comment
comment|/*  * There are roughly 32 interrupt sources.  */
end_comment

begin_define
define|#
directive|define
name|NIRQ
value|32
end_define

begin_decl_stmt
specifier|extern
name|struct
name|bus_space
name|i80321_bs_tag
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|i80321_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|bus_space_tag_t
name|sc_st
decl_stmt|;
name|bus_space_handle_t
name|sc_sh
decl_stmt|;
comment|/* Handles for the various subregions. */
name|bus_space_handle_t
name|sc_atu_sh
decl_stmt|;
name|bus_space_handle_t
name|sc_mcu_sh
decl_stmt|;
name|int
name|sc_is_host
decl_stmt|;
comment|/* 	 * We expect the board-specific front-end to have already mapped 	 * the PCI I/O space .. it is only 64K, and I/O mappings tend to 	 * be smaller than a page size, so it's generally more efficient 	 * to map them all into virtual space in one fell swoop. 	 */
name|vm_offset_t
name|sc_iow_vaddr
decl_stmt|;
comment|/* I/O window vaddr */
comment|/* 	 * Variables that define the Inbound windows.  The base address of 	 * 0-2 are configured by a host via BARs.  The xlate variable 	 * defines the start of the local address space that it maps to. 	 * The size variable defines the byte size. 	 * 	 * The first 3 windows are for incoming PCI memory read/write 	 * cycles from a host.  The 4th window, not configured by the 	 * host (as it outside the normal BAR range) is the inbound 	 * window for PCI devices controlled by the i80321. 	 */
struct|struct
block|{
name|uint32_t
name|iwin_base_hi
decl_stmt|;
name|uint32_t
name|iwin_base_lo
decl_stmt|;
name|uint32_t
name|iwin_xlate
decl_stmt|;
name|uint32_t
name|iwin_size
decl_stmt|;
block|}
name|sc_iwin
index|[
literal|4
index|]
struct|;
comment|/* 	 * Variables that define the Outbound windows. 	 */
struct|struct
block|{
name|uint32_t
name|owin_xlate_lo
decl_stmt|;
name|uint32_t
name|owin_xlate_hi
decl_stmt|;
block|}
name|sc_owin
index|[
literal|2
index|]
struct|;
comment|/* 	 * This is the PCI address that the Outbound I/O 	 * window maps to. 	 */
name|uint32_t
name|sc_ioout_xlate
decl_stmt|;
comment|/* Bus space, DMA, and PCI tags for the PCI bus (private devices). */
name|struct
name|bus_space
name|sc_pci_iot
decl_stmt|;
name|struct
name|bus_space
name|sc_pci_memt
decl_stmt|;
comment|/* GPIO state */
name|uint8_t
name|sc_gpio_dir
decl_stmt|;
comment|/* GPIO pin direction (1 == output) */
name|uint8_t
name|sc_gpio_val
decl_stmt|;
comment|/* GPIO output pin value */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|i80321_sdram_bounds
parameter_list|(
name|bus_space_tag_t
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|vm_paddr_t
modifier|*
parameter_list|,
name|vm_size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i80321_attach
parameter_list|(
name|struct
name|i80321_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i80321_calibrate_delay
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i80321_bs_init
parameter_list|(
name|bus_space_tag_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i80321_io_bs_init
parameter_list|(
name|bus_space_tag_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i80321_mem_bs_init
parameter_list|(
name|bus_space_tag_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_XSCALE_I80321VAR_H_ */
end_comment

end_unit

