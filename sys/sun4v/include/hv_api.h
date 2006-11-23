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

begin_comment
comment|/*  * Section 10 Domain Services  */
end_comment

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
comment|/* page size bitmasx                     */
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
name|hv_tsb_ctx0
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
name|hv_tsb_ctxnon0
parameter_list|(
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Section 13 Cache and Memory Services  */
end_comment

begin_comment
comment|/*  * Section 14 Device Interrupt Services  */
end_comment

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
name|hvio_ldc_tx_qconf
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
name|hvio_ldc_tx_qinfo
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
name|hvio_ldc_tx_get_state
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
name|hvio_ldc_tx_set_qtail
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
name|hvio_ldc_rx_get_state
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
name|hvio_ldc_rx_qconf
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
name|hvio_ldc_rx_qinfo
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
name|hvio_ldc_rx_set_qhead
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

end_unit

