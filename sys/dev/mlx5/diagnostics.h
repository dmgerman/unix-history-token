begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2017, Mellanox Technologies, Ltd.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS `AS IS' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MLX5_CORE_DIAGNOSTICS_H
end_ifndef

begin_define
define|#
directive|define
name|MLX5_CORE_DIAGNOSTICS_H
end_define

begin_define
define|#
directive|define
name|MLX5_CORE_DIAGNOSTICS_NUM
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|,
name|t
parameter_list|)
value|n
end_define

begin_define
define|#
directive|define
name|MLX5_CORE_DIAGNOSTICS_STRUCT
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|,
name|t
parameter_list|)
value|s,
end_define

begin_define
define|#
directive|define
name|MLX5_CORE_DIAGNOSTICS_ENTRY
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|,
name|t
parameter_list|)
value|{ #s, (t) },
end_define

begin_struct
struct|struct
name|mlx5_core_diagnostics_entry
block|{
specifier|const
name|char
modifier|*
specifier|const
name|desc
decl_stmt|;
name|u16
name|counter_id
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MLX5_CORE_PCI_DIAGNOSTICS
parameter_list|(
name|m
parameter_list|)
define|\
value|m(+1, pxd_ready_bp, 0x0401) \ m(+1, pci_write_bp, 0x0402) \ m(+1, pci_read_bp, 0x0403) \ m(+1, pci_read_stuck_no_completion_buffer, 0x0404) \ m(+1, max_pci_bw, 0x0405) \ m(+1, used_pci_bw, 0x0406) \ m(+1, rx_pci_errors, 0) \ m(+1, tx_pci_errors, 0) \ m(+1, tx_pci_correctable_errors, 0) \ m(+1, tx_pci_non_fatal_errors, 0) \ m(+1, tx_pci_fatal_errors, 0)
end_define

begin_define
define|#
directive|define
name|MLX5_CORE_PCI_DIAGNOSTICS_NUM
define|\
value|(0 MLX5_CORE_PCI_DIAGNOSTICS(MLX5_CORE_DIAGNOSTICS_NUM))
end_define

begin_union
union|union
name|mlx5_core_pci_diagnostics
block|{
name|u64
name|array
index|[
name|MLX5_CORE_PCI_DIAGNOSTICS_NUM
index|]
decl_stmt|;
struct|struct
block|{
name|u64
name|MLX5_CORE_PCI_DIAGNOSTICS
argument_list|(
name|MLX5_CORE_DIAGNOSTICS_STRUCT
argument_list|)
name|dummy
index|[
literal|0
index|]
decl_stmt|;
block|}
name|counter
struct|;
block|}
union|;
end_union

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|mlx5_core_diagnostics_entry
name|mlx5_core_pci_diagnostics_table
index|[
name|MLX5_CORE_PCI_DIAGNOSTICS_NUM
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MLX5_CORE_GENERAL_DIAGNOSTICS
parameter_list|(
name|m
parameter_list|)
define|\
value|m(+1, l0_mtt_miss, 0x0801) \ m(+1, l0_mtt_hit, 0x0802) \ m(+1, l1_mtt_miss, 0x0803) \ m(+1, l1_mtt_hit, 0x0804) \ m(+1, l0_mpt_miss, 0x0805) \ m(+1, l0_mpt_hit, 0x0806) \ m(+1, l1_mpt_miss, 0x0807) \ m(+1, l1_mpt_hit, 0x0808) \ m(+1, rxb_no_slow_path_credits, 0x0c01) \ m(+1, rxb_no_fast_path_credits, 0x0c02) \ m(+1, rxb_rxt_no_slow_path_cred_perf_count, 0x0c03) \ m(+1, rxb_rxt_no_fast_path_cred_perf_count, 0x0c04) \ m(+1, rxt_ctrl_perf_slice_load_slow, 0x1001) \ m(+1, rxt_ctrl_perf_slice_load_fast, 0x1002) \ m(+1, rxt_steering_perf_count_steering0_rse_work_rate, 0x1003) \ m(+1, rxt_steering_perf_count_steering1_rse_work_rate, 0x1004) \ m(+1, perf_count_tpt_credit, 0x1401) \ m(+1, perf_wb_miss, 0x1402) \ m(+1, perf_wb_hit, 0x1403) \ m(+1, rxw_perf_rx_l1_slow_miss_ldb, 0x1404) \ m(+1, rxw_perf_rx_l1_slow_hit_ldb, 0x1405) \ m(+1, rxw_perf_rx_l1_fast_miss_ldb, 0x1406) \ m(+1, rxw_perf_rx_l1_fast_hit_ldb, 0x1407) \ m(+1, rxw_perf_l2_cache_read_miss_ldb, 0x1408) \ m(+1, rxw_perf_l2_cache_read_hit_ldb, 0x1409) \ m(+1, rxw_perf_rx_l1_slow_miss_reqsl, 0x140a) \ m(+1, rxw_perf_rx_l1_slow_hit_reqsl, 0x140b) \ m(+1, rxw_perf_rx_l1_fast_miss_reqsl, 0x140c) \ m(+1, rxw_perf_rx_l1_fast_hit_reqsl, 0x140d) \ m(+1, rxw_perf_l2_cache_read_miss_reqsl, 0x140e) \ m(+1, rxw_perf_l2_cache_read_hit_reqsl, 0x140f) \ m(+1, rxs_no_pxt_credits, 0x1801) \ m(+1, rxc_eq_all_slices_busy, 0x1c01) \ m(+1, rxc_cq_all_slices_busy, 0x1c02) \ m(+1, rxc_msix_all_slices_busy, 0x1c03) \ m(+1, sxw_qp_done_due_to_vl_limited, 0x2001) \ m(+1, sxw_qp_done_due_to_desched, 0x2002) \ m(+1, sxw_qp_done_due_to_work_done, 0x2003) \ m(+1, sxw_qp_done_due_to_limited, 0x2004) \ m(+1, sxw_qp_done_due_to_e2e_credits, 0x2005) \ m(+1, sxw_packet_send_sxw2sxp_go_vld, 0x2006) \ m(+1, sxw_perf_count_steering_hit, 0x2007) \ m(+1, sxw_perf_count_steering_miss, 0x2008) \ m(+1, sxw_perf_count_steering_rse_0, 0x2009) \ m(+1, sxd_no_sched_credits, 0x2401) \ m(+1, sxd_no_slow_path_sched_credits, 0x2402) \ m(+1, tpt_indirect_mem_key, 0x2801)
end_define

begin_define
define|#
directive|define
name|MLX5_CORE_GENERAL_DIAGNOSTICS_NUM
define|\
value|(0 MLX5_CORE_GENERAL_DIAGNOSTICS(MLX5_CORE_DIAGNOSTICS_NUM))
end_define

begin_union
union|union
name|mlx5_core_general_diagnostics
block|{
name|u64
name|array
index|[
name|MLX5_CORE_GENERAL_DIAGNOSTICS_NUM
index|]
decl_stmt|;
struct|struct
block|{
name|u64
name|MLX5_CORE_GENERAL_DIAGNOSTICS
argument_list|(
name|MLX5_CORE_DIAGNOSTICS_STRUCT
argument_list|)
name|dummy
index|[
literal|0
index|]
decl_stmt|;
block|}
name|counter
struct|;
block|}
union|;
end_union

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|mlx5_core_diagnostics_entry
name|mlx5_core_general_diagnostics_table
index|[
name|MLX5_CORE_GENERAL_DIAGNOSTICS_NUM
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* function prototypes */
end_comment

begin_function_decl
name|int
name|mlx5_core_set_diagnostics_full
parameter_list|(
name|struct
name|mlx5_core_dev
modifier|*
name|mdev
parameter_list|,
name|u8
name|enable_pci
parameter_list|,
name|u8
name|enable_general
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5_core_get_diagnostics_full
parameter_list|(
name|struct
name|mlx5_core_dev
modifier|*
name|mdev
parameter_list|,
name|union
name|mlx5_core_pci_diagnostics
modifier|*
name|ppci
parameter_list|,
name|union
name|mlx5_core_general_diagnostics
modifier|*
name|pgen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5_core_supports_diagnostics
parameter_list|(
name|struct
name|mlx5_core_dev
modifier|*
name|mdev
parameter_list|,
name|u16
name|counter_id
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MLX5_CORE_DIAGNOSTICS_H */
end_comment

end_unit

