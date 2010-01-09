begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*------------------------------------------------------------------  * octeon_fpa.h      Free Pool Allocator  *  *------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|___OCTEON_FPA__H___
end_ifndef

begin_define
define|#
directive|define
name|___OCTEON_FPA__H___
end_define

begin_define
define|#
directive|define
name|OCTEON_FPA_FPA_OUTPUT_BUFFER_POOL
value|2
end_define

begin_comment
comment|/* Same in octeon_rgmx.h */
end_comment

begin_comment
comment|/*  * OCTEON_FPA_FPF_MARKS = FPA's Queue Free Page FIFO Read Write Marks  *  * The high and low watermark register that determines when we write and  * read free pages from L2C for Queue.  */
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
literal|42
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|fpf_wr
range|:
literal|11
decl_stmt|;
comment|/* Write Hi Water mark */
name|uint64_t
name|fpf_rd
range|:
literal|11
decl_stmt|;
comment|/* Read Lo Water mark */
block|}
name|bits
struct|;
block|}
name|octeon_fpa_fpf_marks_t
typedef|;
end_typedef

begin_comment
comment|/*  * OCTEON_FPA_CTL_STATUS = FPA's Control/Status Register  *  * The FPA's interrupt enable register.  * - Use with the CVMX_FPA_CTL_STATUS CSR.  */
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
literal|49
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|enb
range|:
literal|1
decl_stmt|;
comment|/* Enable */
name|uint64_t
name|mem1_err
range|:
literal|7
decl_stmt|;
comment|/* ECC flip 1 */
name|uint64_t
name|mem0_err
range|:
literal|7
decl_stmt|;
comment|/* ECC flip 0 */
block|}
name|bits
struct|;
block|}
name|octeon_fpa_ctl_status_t
typedef|;
end_typedef

begin_comment
comment|/*  * OCTEON_FPA_FPF_SIZE = FPA's Queue N Free Page FIFO Size  *  * The number of page pointers that will be kept local to the FPA for  *  this Queue. FPA Queues are assigned in order from Queue 0 to  *  Queue 7, though only Queue 0 through Queue x can be used.  * The sum of the 8 (0-7)OCTEON_FPA_FPF#_SIZE registers must be limited to 2048.  * - Use with the CVMX_FPA_FPF0_SIZE CSR.  */
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
comment|/*        * The number of entries assigned in the FPA FIFO (used to hold        * page-pointers) for this Queue.        * The value of this register must divisable by 2, and the FPA will        * ignore bit [0] of this register.        * The total of the FPF_SIZ field of the 8 (0-7)OCTEON_FPA_FPF#_MARKS        * registers must not exceed 2048.        * After writing this field the FPA will need 10 core clock cycles        * to be ready for operation. The assignment of location in        * the FPA FIFO must start with Queue 0, then 1, 2, etc.        * The number of useable entries will be FPF_SIZ-2.        */
name|uint64_t
name|fpf_siz
range|:
literal|12
decl_stmt|;
block|}
name|bits
struct|;
block|}
name|octeon_fpa_fpf_size_t
typedef|;
end_typedef

begin_comment
comment|/*  *OCTEON_FPA_INT_ENB = FPA's Interrupt Enable  *  * The FPA's interrupt enable register.  * - Use with the CVMX_FPA_INT_ENB CSR.  */
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
name|fed1_dbe
range|:
literal|1
decl_stmt|;
comment|/* Int iff bit3 Int-Sum set */
name|uint64_t
name|fed1_sbe
range|:
literal|1
decl_stmt|;
comment|/* Int iff bit2 Int-Sum set */
name|uint64_t
name|fed0_dbe
range|:
literal|1
decl_stmt|;
comment|/* Int iff bit1 Int-Sum set */
name|uint64_t
name|fed0_sbe
range|:
literal|1
decl_stmt|;
comment|/* Int iff bit0 Int-Sum set */
block|}
name|bits
struct|;
block|}
name|octeon_fpa_int_enb_t
typedef|;
end_typedef

begin_comment
comment|/**  *OCTEON_FPA_INT_SUM = FPA's Interrupt Summary Register  *  * Contains the diffrent interrupt summary bits of the FPA.  * - Use with the CVMX_FPA_INT_SUM CSR.  */
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
comment|/**< Must be zero */
name|uint64_t
name|fed1_dbe
range|:
literal|1
decl_stmt|;
name|uint64_t
name|fed1_sbe
range|:
literal|1
decl_stmt|;
name|uint64_t
name|fed0_dbe
range|:
literal|1
decl_stmt|;
name|uint64_t
name|fed0_sbe
range|:
literal|1
decl_stmt|;
block|}
name|bits
struct|;
block|}
name|octeon_fpa_int_sum_t
typedef|;
end_typedef

begin_comment
comment|/*  *OCTEON_FPA_QUEUE_PAGES_AVAILABLE = FPA's Queue 0-7 Free Page Available Register  *  * The number of page pointers that are available in the FPA and local DRAM.  * - Use with the CVMX_FPA_QUEX_AVAILABLE(0..7) CSR.  */
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
literal|38
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|queue_size
range|:
literal|26
decl_stmt|;
comment|/* free pages available */
block|}
name|bits
struct|;
block|}
name|octeon_fpa_queue_available_t
typedef|;
end_typedef

begin_comment
comment|/*  *OCTEON_FPA_QUEUE_PAGE_INDEX  *  */
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
literal|39
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|page_index
range|:
literal|25
decl_stmt|;
comment|/* page_index */
block|}
name|bits
struct|;
block|}
name|octeon_fpa_queue_page_index_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OCTEON_DID_FPA
value|5ULL
end_define

begin_define
define|#
directive|define
name|OCTEON_FPA_POOL_ALIGNMENT
value|(OCTEON_CACHE_LINE_SIZE)
end_define

begin_comment
comment|/*  * Externs  */
end_comment

begin_function_decl
specifier|extern
name|void
name|octeon_dump_fpa
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_dump_fpa_pool
parameter_list|(
name|u_int
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int
name|octeon_fpa_pool_size
parameter_list|(
name|u_int
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_enable_fpa
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_fpa_fill_pool_mem
parameter_list|(
name|u_int
name|pool
parameter_list|,
name|u_int
name|block_size_words
parameter_list|,
name|u_int
name|block_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * octeon_fpa_free  *  * Free a mem-block to FPA pool.  *  * Takes away this 'buffer' from SW and passes it to FPA for management.  *  *  pool is FPA pool num, ptr is block ptr, num_cache_lines is number of  *  cache lines to invalidate (not written back).  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|octeon_fpa_free
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|u_int
name|pool
parameter_list|,
name|u_int
name|num_cache_lines
parameter_list|)
block|{
name|octeon_addr_t
name|free_ptr
decl_stmt|;
name|free_ptr
operator|.
name|word64
operator|=
operator|(
name|uint64_t
operator|)
name|OCTEON_PTR2PHYS
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
name|free_ptr
operator|.
name|sfilldidspace
operator|.
name|didspace
operator|=
name|OCTEON_ADDR_DIDSPACE
argument_list|(
name|OCTEON_ADDR_FULL_DID
argument_list|(
name|OCTEON_DID_FPA
argument_list|,
name|pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/*      * Do not 'sync'      *     asm volatile ("sync\n");      */
name|oct_write64
argument_list|(
name|free_ptr
operator|.
name|word64
argument_list|,
name|num_cache_lines
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * octeon_fpa_alloc  *  * Allocate a new block from the FPA  *  * Buffer passes away from FPA management to SW control  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|octeon_fpa_alloc
parameter_list|(
name|u_int
name|pool
parameter_list|)
block|{
name|uint64_t
name|address
decl_stmt|;
name|address
operator|=
name|oct_read64
argument_list|(
name|OCTEON_ADDR_DID
argument_list|(
name|OCTEON_ADDR_FULL_DID
argument_list|(
name|OCTEON_DID_FPA
argument_list|,
name|pool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|address
condition|)
block|{
comment|/*  * 32 bit FPA pointers only  */
comment|/*          * We only use 32 bit pointers at this time          */
comment|/*XXX mips64 issue */
return|return
operator|(
operator|(
name|void
operator|*
operator|)
name|MIPS_PHYS_TO_KSEG0
argument_list|(
name|address
operator|&
literal|0xffffffff
argument_list|)
operator|)
return|;
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|octeon_fpa_alloc_phys
parameter_list|(
name|u_int
name|pool
parameter_list|)
block|{
return|return
operator|(
name|oct_read64
argument_list|(
name|OCTEON_ADDR_DID
argument_list|(
name|OCTEON_ADDR_FULL_DID
argument_list|(
name|OCTEON_DID_FPA
argument_list|,
name|pool
argument_list|)
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ___OCTEON_FPA__H___ */
end_comment

end_unit

