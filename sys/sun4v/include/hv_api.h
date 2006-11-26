begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Kip Macy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_HV_API_H
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_HV_API_H
end_define

begin_typedef
typedef|typedef
name|uint64_t
name|devhandle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|pci_device_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|pci_config_offset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|pci_config_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|tsbid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|pages_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|io_attributes
block|{
name|PCI_MAP_ATTR_READ
init|=
operator|(
name|uint32_t
operator|)
literal|0x01
block|,
name|PCI_MAP_ATTR_WRITE
init|=
operator|(
name|uint32_t
operator|)
literal|0x02
block|, }
name|io_attributes_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|io_sync_direction
block|{
name|IO_SYNC_DEVICE
init|=
operator|(
name|uint32_t
operator|)
literal|0x01
block|,
name|IO_SYNC_CPU
init|=
operator|(
name|uint32_t
operator|)
literal|0x02
block|, }
name|io_sync_direction_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|io_page_list_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|r_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|io_addr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Section 10 Domain Services  */
end_comment

begin_function_decl
specifier|extern
name|void
name|hv_mach_exit
parameter_list|(
name|uint64_t
name|exit_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_mach_desc
parameter_list|(
name|uint64_t
name|buffer_ra
parameter_list|,
name|uint64_t
modifier|*
name|buffer_sizep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_mach_watchdog
parameter_list|(
name|uint64_t
name|timeout
parameter_list|,
name|uint64_t
modifier|*
name|time_remaining
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Section 11 CPU Services  */
end_comment

begin_function_decl
specifier|extern
name|uint64_t
name|hv_cpu_yield
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_cpu_state
parameter_list|(
name|uint64_t
name|cpuid
parameter_list|,
name|uint64_t
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_cpu_mondo_send
parameter_list|(
name|int
name|ncpu
parameter_list|,
name|vm_paddr_t
name|cpulist_ra
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_cpu_qconf
parameter_list|(
name|int
name|queue
parameter_list|,
name|vm_paddr_t
name|ra
parameter_list|,
name|int
name|nentries
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Section 12 MMU Services  */
end_comment

begin_comment
comment|/*  * TSB description structure for MMU_TSB_CTX0 and MMU_TSB_CTXNON0.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hv_tsb_info
block|{
name|uint16_t
name|hti_idxpgsz
decl_stmt|;
comment|/* page size used for index shift in TSB */
name|uint16_t
name|hti_assoc
decl_stmt|;
comment|/* associativity of TSB                  */
name|uint32_t
name|hti_ntte
decl_stmt|;
comment|/* size of TSB in TTEs                   */
name|uint32_t
name|hti_ctx_index
decl_stmt|;
comment|/* context index                         */
name|uint32_t
name|hti_pgszs
decl_stmt|;
comment|/* page size bitmask                     */
name|uint64_t
name|hti_ra
decl_stmt|;
comment|/* real address of TSB base              */
name|uint64_t
name|hti_rsvd
decl_stmt|;
comment|/* reserved                              */
block|}
name|hv_tsb_info_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|uint64_t
name|hv_mmu_tsb_ctx0
parameter_list|(
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_mmu_tsb_ctxnon0
parameter_list|(
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_mmu_map_perm_addr
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|uint64_t
parameter_list|,
name|tte_t
name|tte
parameter_list|,
name|uint64_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Section 13 Cache and Memory Services  */
end_comment

begin_function_decl
specifier|extern
name|uint64_t
name|hv_mem_scrub
parameter_list|(
name|vm_paddr_t
name|ra
parameter_list|,
name|uint64_t
name|length
parameter_list|,
name|uint64_t
modifier|*
name|scrubbed
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Section 14 Device Interrupt Services  */
end_comment

begin_function_decl
specifier|extern
name|uint64_t
name|hv_intr_devino_to_sysino
parameter_list|(
name|devhandle_t
name|dev_hdl
parameter_list|,
name|uint32_t
name|devino
parameter_list|,
name|uint64_t
modifier|*
name|sysino
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_intr_getenabled
parameter_list|(
name|uint64_t
name|sysino
parameter_list|,
name|int
modifier|*
name|enabled
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_intr_setenabled
parameter_list|(
name|uint64_t
name|sysino
parameter_list|,
name|int
name|enabled
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_intr_getstate
parameter_list|(
name|uint64_t
name|sysino
parameter_list|,
name|int
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_intr_setstate
parameter_list|(
name|uint64_t
name|sysino
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_intr_gettarget
parameter_list|(
name|uint64_t
name|sysino
parameter_list|,
name|int
modifier|*
name|cpuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_intr_settarget
parameter_list|(
name|uint64_t
name|sysino
parameter_list|,
name|int
name|cpuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_vintr_getcookie
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|uint64_t
name|devino
parameter_list|,
name|uint64_t
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_vintr_setcookie
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|uint64_t
name|devino
parameter_list|,
name|uint64_t
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_vintr_getenabled
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|uint64_t
name|devino
parameter_list|,
name|int
modifier|*
name|enabled
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_vintr_setenabled
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|uint64_t
name|devino
parameter_list|,
name|int
name|enabled
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_vintr_getstate
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|uint64_t
name|devino
parameter_list|,
name|int
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_vintr_setstate
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|uint64_t
name|devino
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_vintr_gettarget
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|uint64_t
name|devino
parameter_list|,
name|int
modifier|*
name|cpuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_vintr_settarget
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|uint64_t
name|devino
parameter_list|,
name|int
name|cpuid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Section 15 Time of Day Services  */
end_comment

begin_function_decl
specifier|extern
name|uint64_t
name|hv_tod_get
parameter_list|(
name|uint64_t
modifier|*
name|seconds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_tod_set
parameter_list|(
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Section 16 Console Services  */
end_comment

begin_function_decl
specifier|extern
name|int64_t
name|hv_cons_putchar
parameter_list|(
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int64_t
name|hv_cons_getchar
parameter_list|(
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int64_t
name|hv_cons_write
parameter_list|(
name|uint64_t
name|buf_raddr
parameter_list|,
name|uint64_t
name|size
parameter_list|,
name|uint64_t
modifier|*
name|nwritten
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int64_t
name|hv_cons_read
parameter_list|(
name|uint64_t
name|buf_raddr
parameter_list|,
name|uint64_t
name|size
parameter_list|,
name|uint64_t
modifier|*
name|nread
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hv_cnputs
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Section 17 Core Dump Services  */
end_comment

begin_function_decl
specifier|extern
name|uint64_t
name|hv_dump_buf_update
parameter_list|(
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Section 18 Trap Trace Services  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|trap_trace_entry
block|{
name|uint8_t
name|tte_type
decl_stmt|;
comment|/* Hypervisor or guest entry. */
name|uint8_t
name|tte_hpstat
decl_stmt|;
comment|/* Hyper-privileged state. */
name|uint8_t
name|tte_tl
decl_stmt|;
comment|/* Trap level. */
name|uint8_t
name|tte_gl
decl_stmt|;
comment|/* Global register level. */
name|uint16_t
name|tte_tt
decl_stmt|;
comment|/* Trap type.*/
name|uint16_t
name|tte_tag
decl_stmt|;
comment|/* Extended trap identifier. */
name|uint64_t
name|tte_tstate
decl_stmt|;
comment|/* Trap state. */
name|uint64_t
name|tte_tick
decl_stmt|;
comment|/* Tick. */
name|uint64_t
name|tte_tpc
decl_stmt|;
comment|/* Trap PC. */
name|uint64_t
name|tte_f1
decl_stmt|;
comment|/* Entry specific. */
name|uint64_t
name|tte_f2
decl_stmt|;
comment|/* Entry specific. */
name|uint64_t
name|tte_f3
decl_stmt|;
comment|/* Entry specific. */
name|uint64_t
name|tte_f4
decl_stmt|;
comment|/* Entry specific. */
block|}
name|trap_trace_entry_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|uint64_t
name|hv_ttrace_buf_info
parameter_list|(
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_ttrace_buf_conf
parameter_list|(
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_ttrace_enable
parameter_list|(
name|uint64_t
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_ttrace_freeze
parameter_list|(
name|uint64_t
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_ttrace_addentry
parameter_list|(
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Section 19 Logical Domain Channel Services  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ldc_state_info
block|{
name|uint64_t
name|lsi_head_offset
decl_stmt|;
name|uint64_t
name|lsi_tail_offset
decl_stmt|;
name|uint64_t
name|lsi_channel_state
decl_stmt|;
block|}
name|ldc_state_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LDC_CHANNEL_DOWN
value|0
end_define

begin_define
define|#
directive|define
name|LDC_CHANNEL_UP
value|1
end_define

begin_function_decl
specifier|extern
name|uint64_t
name|hv_ldc_tx_qconf
parameter_list|(
name|uint64_t
name|ldc_id
parameter_list|,
name|uint64_t
name|base_raddr
parameter_list|,
name|uint64_t
name|nentries
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_ldc_tx_qinfo
parameter_list|(
name|uint64_t
name|ldc_id
parameter_list|,
name|uint64_t
modifier|*
name|base_raddr
parameter_list|,
name|uint64_t
modifier|*
name|nentries
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_ldc_tx_get_state
parameter_list|(
name|uint64_t
name|ldc_id
parameter_list|,
name|ldc_state_info_t
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_ldc_tx_set_qtail
parameter_list|(
name|uint64_t
name|ldc_id
parameter_list|,
name|uint64_t
name|tail_offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_ldc_rx_get_state
parameter_list|(
name|uint64_t
name|ldc_id
parameter_list|,
name|ldc_state_info_t
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_ldc_rx_qconf
parameter_list|(
name|uint64_t
name|ldc_id
parameter_list|,
name|uint64_t
name|base_raddr
parameter_list|,
name|uint64_t
name|nentries
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_ldc_rx_qinfo
parameter_list|(
name|uint64_t
name|ldc_id
parameter_list|,
name|uint64_t
modifier|*
name|base_raddr
parameter_list|,
name|uint64_t
modifier|*
name|nentries
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_ldc_rx_set_qhead
parameter_list|(
name|uint64_t
name|ldc_id
parameter_list|,
name|uint64_t
name|head_offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Section 20 PCI I/O Services  *  */
end_comment

begin_typedef
typedef|typedef
union|union
name|pci_cfg_data
block|{
name|uint8_t
name|b
decl_stmt|;
name|uint16_t
name|w
decl_stmt|;
name|uint32_t
name|dw
decl_stmt|;
name|uint64_t
name|qw
decl_stmt|;
block|}
name|pci_cfg_data_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|uint64_t
name|hv_pci_iommu_map
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|uint64_t
name|tsbid
parameter_list|,
name|uint64_t
name|nttes
parameter_list|,
name|io_attributes_t
name|io_attributes
parameter_list|,
name|io_page_list_t
name|io_page_list
parameter_list|,
name|pages_t
modifier|*
name|nttes_mapped
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_pci_iommu_demap
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|uint64_t
name|tsbid
parameter_list|,
name|uint64_t
name|nttes
parameter_list|,
name|pages_t
modifier|*
name|nttes_demapped
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_pci_iommu_getmap
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|uint64_t
name|tsbid
parameter_list|,
name|io_attributes_t
modifier|*
name|io_attributes
parameter_list|,
name|vm_paddr_t
modifier|*
name|ra
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_pci_iommu_getbypass
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|vm_paddr_t
name|ra
parameter_list|,
name|uint64_t
name|io_attributes
parameter_list|,
name|uint64_t
modifier|*
name|io_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_pci_config_get
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|uint64_t
name|pci_device
parameter_list|,
name|uint64_t
name|pci_config_offset
parameter_list|,
name|uint64_t
name|size
parameter_list|,
name|pci_cfg_data_t
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_pci_config_put
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|uint64_t
name|pci_device
parameter_list|,
name|uint64_t
name|pci_config_offset
parameter_list|,
name|uint64_t
name|size
parameter_list|,
name|pci_cfg_data_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_pci_peek
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|vm_paddr_t
name|ra
parameter_list|,
name|uint64_t
name|size
parameter_list|,
name|uint32_t
modifier|*
name|error_flag
parameter_list|,
name|uint64_t
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_pci_poke
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|vm_paddr_t
name|ra
parameter_list|,
name|uint64_t
name|size
parameter_list|,
name|uint64_t
name|data
parameter_list|,
name|uint64_t
name|pci_device
parameter_list|,
name|uint32_t
modifier|*
name|error_flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|hv_pci_dma_sync
parameter_list|(
name|devhandle_t
name|dh
parameter_list|,
name|vm_paddr_t
name|ra
parameter_list|,
name|uint64_t
name|size
parameter_list|,
name|uint64_t
name|io_sync_direction
parameter_list|,
name|uint64_t
modifier|*
name|nsynced
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Section 21 MSI Services  *  */
end_comment

begin_comment
comment|/*  * Section 22 UltraSPARC T1 Performance Counters  *  */
end_comment

begin_comment
comment|/*  * Section 23 UltraSPARC T1 MMU Statistics Counters  *  */
end_comment

begin_comment
comment|/*  * Simulator Services  */
end_comment

begin_function_decl
specifier|extern
name|void
name|hv_magic_trap_on
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hv_magic_trap_off
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hv_sim_read
parameter_list|(
name|uint64_t
name|offset
parameter_list|,
name|vm_paddr_t
name|buffer_ra
parameter_list|,
name|uint64_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hv_sim_write
parameter_list|(
name|uint64_t
name|offset
parameter_list|,
name|vm_paddr_t
name|buffer_ra
parameter_list|,
name|uint64_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_HV_API_H */
end_comment

end_unit

