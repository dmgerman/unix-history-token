begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*------------------------------------------------------------------  * octeon_ipd.h      Input Packet Unit  *  *------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|___OCTEON_IPD__H___
end_ifndef

begin_define
define|#
directive|define
name|___OCTEON_IPD__H___
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|OCTEON_IPD_OPC_MODE_STT
init|=
literal|0LL
block|,
comment|/* All blocks DRAM, not cached in L2 */
name|OCTEON_IPD_OPC_MODE_STF
init|=
literal|1LL
block|,
comment|/* All blocks into  L2 */
name|OCTEON_IPD_OPC_MODE_STF1_STT
init|=
literal|2LL
block|,
comment|/* 1st block L2, rest DRAM */
name|OCTEON_IPD_OPC_MODE_STF2_STT
init|=
literal|3LL
comment|/* 1st, 2nd blocks L2, rest DRAM */
block|}
name|octeon_ipd_mode_t
typedef|;
end_typedef

begin_comment
comment|/*  * IPD_CTL_STATUS = IPS'd Control Status Register  *  The number of words in a MBUFF used for packet data store.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|reserved
range|:
literal|58
decl_stmt|;
comment|/* Reserved */
name|uint64_t
name|pkt_lend
range|:
literal|1
decl_stmt|;
comment|/* Pkt Lil-Endian Writes to L2C */
name|uint64_t
name|wqe_lend
range|:
literal|1
decl_stmt|;
comment|/* WQE Lik-Endian Writes to L2C */
name|uint64_t
name|pbp_en
range|:
literal|1
decl_stmt|;
comment|/* Enable Back-Pressure */
name|octeon_ipd_mode_t
name|opc_mode
range|:
literal|2
decl_stmt|;
comment|/* Pkt data in Mem/L2-cache ? */
name|uint64_t
name|ipd_en
range|:
literal|1
decl_stmt|;
comment|/* Enable IPD */
block|}
name|bits
struct|;
block|}
name|octeon_ipd_ctl_status_t
typedef|;
end_typedef

begin_comment
comment|/*  * IPD_1ST_NEXT_PTR_BACK = IPD First Next Pointer Back Values  *  * Contains the Back Field for use in creating the Next Pointer Header  *    for the First MBUF  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|reserved
range|:
literal|60
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|back
range|:
literal|4
decl_stmt|;
comment|/* Used to find head of buffer from the nxt-hdr-ptr. */
block|}
name|bits
struct|;
block|}
name|octeon_ipd_first_next_ptr_back_t
typedef|;
end_typedef

begin_comment
comment|/*  * IPD_INTERRUPT_ENB = IPD Interrupt Enable Register  *  * Used to enable the various interrupting conditions of IPD  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|reserved
range|:
literal|59
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|bp_sub
range|:
literal|1
decl_stmt|;
comment|/* BP subtract is illegal val */
name|uint64_t
name|prc_par3
range|:
literal|1
decl_stmt|;
comment|/* PBM Bits [127:96] Parity Err */
name|uint64_t
name|prc_par2
range|:
literal|1
decl_stmt|;
comment|/* PBM Bits [ 95:64] Parity Err */
name|uint64_t
name|prc_par1
range|:
literal|1
decl_stmt|;
comment|/* PBM Bits [ 63:32] Parity Err */
name|uint64_t
name|prc_par0
range|:
literal|1
decl_stmt|;
comment|/* PBM Bits [ 31:0 ] Parity Err */
block|}
name|bits
struct|;
block|}
name|octeon_ipd_int_enb_t
typedef|;
end_typedef

begin_comment
comment|/*  * IPD_INTERRUPT_SUM = IPD Interrupt Summary Register  *  * Set when an interrupt condition occurs, write '1' to clear.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|reserved
range|:
literal|59
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|bp_sub
range|:
literal|1
decl_stmt|;
comment|/* BP subtract is illegal val */
name|uint64_t
name|prc_par3
range|:
literal|1
decl_stmt|;
comment|/* PBM Bits [127:96] Parity Err */
name|uint64_t
name|prc_par2
range|:
literal|1
decl_stmt|;
comment|/* PBM Bits [ 95:64] Parity Err */
name|uint64_t
name|prc_par1
range|:
literal|1
decl_stmt|;
comment|/* PBM Bits [ 63:32] Parity Err */
name|uint64_t
name|prc_par0
range|:
literal|1
decl_stmt|;
comment|/* PBM Bits [ 31:0 ] Parity Err */
block|}
name|bits
struct|;
block|}
name|octeon_ipd_int_sum_t
typedef|;
end_typedef

begin_comment
comment|/**  * IPD_1ST_MBUFF_SKIP = IPD First MBUFF Word Skip Size  *  * The number of words that the IPD will skip when writing the first MBUFF.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|reserved
range|:
literal|58
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|skip_sz
range|:
literal|6
decl_stmt|;
comment|/* 64bit words from the top of */
comment|/*  1st MBUFF that the IPD will */
comment|/*  store the next-pointer. */
comment|/*  [0..32]&&             */
comment|/*    (skip_sz + 16)<= IPD_PACKET_MBUFF_SIZE[MB_SIZE]. */
block|}
name|bits
struct|;
block|}
name|octeon_ipd_mbuff_first_skip_t
typedef|;
end_typedef

begin_comment
comment|/*  * IPD_PACKET_MBUFF_SIZE = IPD's PACKET MUBUF Size In Words  *  * The number of words in a MBUFF used for packet data store.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|reserved
range|:
literal|52
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|mb_size
range|:
literal|12
decl_stmt|;
comment|/* 64bit words in a MBUF. */
comment|/* Must be [32..2048] */
comment|/* Is also the size of the FPA's */
comment|/*   Queue-0 Free-Page */
block|}
name|bits
struct|;
block|}
name|octeon_ipd_mbuff_size_t
typedef|;
end_typedef

begin_comment
comment|/*  * IPD_WQE_FPA_QUEUE = IPD Work-Queue-Entry FPA Page Size  *  * Which FPA Queue (0-7) to fetch page-pointers from for WQE's  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|reserved
range|:
literal|61
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|wqe_pool
range|:
literal|3
decl_stmt|;
comment|/* FPA Pool to fetch WQE Page-ptrs */
block|}
name|bits
struct|;
block|}
name|octeon_ipd_wqe_fpa_pool_t
typedef|;
end_typedef

begin_comment
comment|/* End of Control and Status Register (CSR) definitions */
end_comment

begin_typedef
typedef|typedef
name|octeon_ipd_mbuff_first_skip_t
name|octeon_ipd_mbuff_not_first_skip_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|octeon_ipd_first_next_ptr_back_t
name|octeon_ipd_second_next_ptr_back_t
typedef|;
end_typedef

begin_comment
comment|/*  * Externs  */
end_comment

begin_function_decl
specifier|extern
name|void
name|octeon_ipd_enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_ipd_disable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_ipd_config
parameter_list|(
name|u_int
name|mbuff_size
parameter_list|,
name|u_int
name|first_mbuff_skip
parameter_list|,
name|u_int
name|not_first_mbuff_skip
parameter_list|,
name|u_int
name|first_back
parameter_list|,
name|u_int
name|second_back
parameter_list|,
name|u_int
name|wqe_fpa_pool
parameter_list|,
name|octeon_ipd_mode_t
name|cache_mode
parameter_list|,
name|u_int
name|back_pres_enable_flag
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  ___OCTEON_IPD__H___ */
end_comment

end_unit

