begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1996 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby  * granted, provided that both the above copyright notice and this  * permission notice appear in all copies, that both the above  * copyright notice and this permission notice appear in all  * supporting documentation, and that the name of M.I.T. not be used  * in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.  M.I.T. makes  * no representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied  * warranty.  *   * THIS SOFTWARE IS PROVIDED BY M.I.T. ``AS IS''.  M.I.T. DISCLAIMS  * ALL EXPRESS OR IMPLIED WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT  * SHALL M.I.T. BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Interface to performance-monitoring counters for Intel Pentium and  * Pentium Pro CPUs.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PERFMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PERFMON_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|NPMC
value|2
end_define

begin_define
define|#
directive|define
name|PMIOSETUP
value|_IOW('5', 1, struct pmc)
end_define

begin_define
define|#
directive|define
name|PMIOGET
value|_IOWR('5', 7, struct pmc)
end_define

begin_define
define|#
directive|define
name|PMIOSTART
value|_IOW('5', 2, int)
end_define

begin_define
define|#
directive|define
name|PMIOSTOP
value|_IOW('5', 3, int)
end_define

begin_define
define|#
directive|define
name|PMIOREAD
value|_IOWR('5', 4, struct pmc_data)
end_define

begin_define
define|#
directive|define
name|PMIORESET
value|_IOW('5', 5, int)
end_define

begin_define
define|#
directive|define
name|PMIOTSTAMP
value|_IOR('5', 6, struct pmc_tstamp)
end_define

begin_struct
struct|struct
name|pmc
block|{
name|int
name|pmc_num
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|unsigned
name|char
name|pmcus_event
decl_stmt|;
name|unsigned
name|char
name|pmcus_unit
decl_stmt|;
name|unsigned
name|char
name|pmcus_flags
decl_stmt|;
name|unsigned
name|char
name|pmcus_mask
decl_stmt|;
block|}
name|pmcu_s
struct|;
name|unsigned
name|int
name|pmcu_val
decl_stmt|;
block|}
name|pmc_pmcu
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PMC_ALL
value|(-1)
end_define

begin_define
define|#
directive|define
name|pmc_event
value|pmc_pmcu.pmcu_s.pmcus_event
end_define

begin_define
define|#
directive|define
name|pmc_unit
value|pmc_pmcu.pmcu_s.pmcus_unit
end_define

begin_define
define|#
directive|define
name|pmc_flags
value|pmc_pmcu.pmcu_s.pmcus_flags
end_define

begin_define
define|#
directive|define
name|pmc_mask
value|pmc_pmcu.pmcu_s.pmcus_mask
end_define

begin_define
define|#
directive|define
name|pmc_val
value|pmc_pmcu.pmcu_val
end_define

begin_define
define|#
directive|define
name|PMCF_USR
value|0x01
end_define

begin_comment
comment|/* count events in user mode */
end_comment

begin_define
define|#
directive|define
name|PMCF_OS
value|0x02
end_define

begin_comment
comment|/* count events in kernel mode */
end_comment

begin_define
define|#
directive|define
name|PMCF_E
value|0x04
end_define

begin_comment
comment|/* use edge-detection mode */
end_comment

begin_define
define|#
directive|define
name|PMCF_PC
value|0x08
end_define

begin_comment
comment|/* PMx output pin control */
end_comment

begin_define
define|#
directive|define
name|PMCF_INT
value|0x10
end_define

begin_comment
comment|/* APIC interrupt enable (do not use) */
end_comment

begin_define
define|#
directive|define
name|PMCF_EN
value|0x40
end_define

begin_comment
comment|/* enable counters */
end_comment

begin_define
define|#
directive|define
name|PMCF_INV
value|0x80
end_define

begin_comment
comment|/* invert counter mask comparison */
end_comment

begin_define
define|#
directive|define
name|PMCF_SYS_FLAGS
value|(PMCF_INT | PMCF_EN)
end_define

begin_comment
comment|/* user cannot set */
end_comment

begin_struct
struct|struct
name|pmc_data
block|{
name|int
name|pmcd_num
decl_stmt|;
name|quad_t
name|pmcd_value
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmc_tstamp
block|{
name|int
name|pmct_rate
decl_stmt|;
name|quad_t
name|pmct_value
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_PERFMON
value|"/dev/perfmon"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Intra-kernel interface to performance monitoring counters  */
end_comment

begin_function_decl
name|void
name|perfmon_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|perfmon_avail
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|perfmon_setup
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|perfmon_get
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|perfmon_fini
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|perfmon_start
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|perfmon_stop
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|perfmon_read
parameter_list|(
name|int
parameter_list|,
name|quad_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|perfmon_reset
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Pentium Pro performance counters, from Appendix B.  */
end_comment

begin_comment
comment|/* Data Cache Unit */
end_comment

begin_define
define|#
directive|define
name|PMC6_DATA_MEM_REFS
value|0x43
end_define

begin_define
define|#
directive|define
name|PMC6_DCU_LINES_IN
value|0x45
end_define

begin_define
define|#
directive|define
name|PMC6_DCU_M_LINES_IN
value|0x46
end_define

begin_define
define|#
directive|define
name|PMC6_DCU_M_LINES_OUT
value|0x47
end_define

begin_define
define|#
directive|define
name|PMC6_DCU_MISS_OUTSTANDING
value|0x48
end_define

begin_comment
comment|/* Instruction Fetch Unit */
end_comment

begin_define
define|#
directive|define
name|PMC6_IFU_IFETCH
value|0x80
end_define

begin_define
define|#
directive|define
name|PMC6_IFU_IFETCH_MISS
value|0x81
end_define

begin_define
define|#
directive|define
name|PMC6_ITLB_MISS
value|0x85
end_define

begin_define
define|#
directive|define
name|PMC6_IFU_MEM_STALL
value|0x86
end_define

begin_define
define|#
directive|define
name|PMC6_ILD_STALL
value|0x87
end_define

begin_comment
comment|/* L2 Cache */
end_comment

begin_define
define|#
directive|define
name|PMC6_L2_IFETCH
value|0x28
end_define

begin_comment
comment|/* MESI */
end_comment

begin_define
define|#
directive|define
name|PMC6_L2_LD
value|0x29
end_define

begin_comment
comment|/* MESI */
end_comment

begin_define
define|#
directive|define
name|PMC6_L2_ST
value|0x2a
end_define

begin_comment
comment|/* MESI */
end_comment

begin_define
define|#
directive|define
name|PMC6_L2_LINES_IN
value|0x24
end_define

begin_define
define|#
directive|define
name|PMC6_L2_LINES_OUT
value|0x26
end_define

begin_define
define|#
directive|define
name|PMC6_L2_M_LINES_INM
value|0x25
end_define

begin_define
define|#
directive|define
name|PMC6_L2_M_LINES_OUTM
value|0x27
end_define

begin_define
define|#
directive|define
name|PMC6_L2_RQSTS
value|0x2e
end_define

begin_comment
comment|/* MESI */
end_comment

begin_define
define|#
directive|define
name|PMC6_L2_ADS
value|0x21
end_define

begin_define
define|#
directive|define
name|PMC6_L2_DBUS_BUSY
value|0x22
end_define

begin_define
define|#
directive|define
name|PMC6_L2_DBUS_BUSY_RD
value|0x23
end_define

begin_comment
comment|/* External Bus Logic */
end_comment

begin_define
define|#
directive|define
name|PMC6_BUS_DRDY_CLOCKS
value|0x62
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_LOCK_CLOCKS
value|0x63
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_REQ_OUTSTANDING
value|0x60
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_TRAN_BRD
value|0x65
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_TRAN_RFO
value|0x66
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_TRAN_WB
value|0x67
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_TRAN_IFETCH
value|0x68
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_TRAN_INVAL
value|0x69
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_TRAN_PWR
value|0x6a
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_TRAN_P
value|0x6b
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_TRAN_IO
value|0x6c
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_TRAN_DEF
value|0x6d
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_TRAN_BURST
value|0x6e
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_TRAN_ANY
value|0x70
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_TRAN_MEM
value|0x6f
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_DATA_RCV
value|0x64
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_BNR_DRV
value|0x61
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_HIT_DRV
value|0x7a
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_HITM_DRV
value|0x7b
end_define

begin_define
define|#
directive|define
name|PMC6_BUS_SNOOP_STALL
value|0x7e
end_define

begin_comment
comment|/* Floating Point Unit */
end_comment

begin_define
define|#
directive|define
name|PMC6_FLOPS
value|0xc1
end_define

begin_comment
comment|/* counter 0 only */
end_comment

begin_define
define|#
directive|define
name|PMC6_FP_COMP_OPS_EXE
value|0x10
end_define

begin_comment
comment|/* counter 0 only */
end_comment

begin_define
define|#
directive|define
name|PMC6_FP_ASSIST
value|0x11
end_define

begin_comment
comment|/* counter 1 only */
end_comment

begin_define
define|#
directive|define
name|PMC6_MUL
value|0x12
end_define

begin_comment
comment|/* counter 1 only */
end_comment

begin_define
define|#
directive|define
name|PMC6_DIV
value|0x13
end_define

begin_comment
comment|/* counter 1 only */
end_comment

begin_define
define|#
directive|define
name|PMC6_CYCLES_DIV_BUSY
value|0x14
end_define

begin_comment
comment|/* counter 0 only */
end_comment

begin_comment
comment|/* Memory Ordering */
end_comment

begin_define
define|#
directive|define
name|PMC6_LD_BLOCKS
value|0x03
end_define

begin_define
define|#
directive|define
name|PMC6_SB_DRAINS
value|0x04
end_define

begin_define
define|#
directive|define
name|PMC6_MISALIGN_MEM_REF
value|0x05
end_define

begin_comment
comment|/* Instruction Decoding and Retirement */
end_comment

begin_define
define|#
directive|define
name|PMC6_INST_RETIRED
value|0xc0
end_define

begin_define
define|#
directive|define
name|PMC6_UOPS_RETIRED
value|0xc2
end_define

begin_define
define|#
directive|define
name|PMC6_INST_DECODER
value|0xd0
end_define

begin_comment
comment|/* (sic) */
end_comment

begin_comment
comment|/* Interrupts */
end_comment

begin_define
define|#
directive|define
name|PMC6_HW_INT_RX
value|0xc8
end_define

begin_define
define|#
directive|define
name|PMC6_CYCLES_INT_MASKED
value|0xc6
end_define

begin_define
define|#
directive|define
name|PMC6_CYCLES_INT_PENDING_AND_MASKED
value|0xc7
end_define

begin_comment
comment|/* Branches */
end_comment

begin_define
define|#
directive|define
name|PMC6_BR_INST_RETIRED
value|0xc4
end_define

begin_define
define|#
directive|define
name|PMC6_BR_MISS_PRED_RETIRED
value|0xc5
end_define

begin_define
define|#
directive|define
name|PMC6_BR_TAKEN_RETIRED
value|0xc9
end_define

begin_define
define|#
directive|define
name|PMC6_BR_MISS_PRED_TAKEN_RET
value|0xca
end_define

begin_define
define|#
directive|define
name|PMC6_BR_INST_DECODED
value|0xe0
end_define

begin_define
define|#
directive|define
name|PMC6_BTB_MISSES
value|0xe2
end_define

begin_define
define|#
directive|define
name|PMC6_BR_BOGUS
value|0xe4
end_define

begin_define
define|#
directive|define
name|PMC6_BACLEARS
value|0xe6
end_define

begin_comment
comment|/* Stalls */
end_comment

begin_define
define|#
directive|define
name|PMC6_RESOURCE_STALLS
value|0xa2
end_define

begin_define
define|#
directive|define
name|PMC6_PARTIAL_RAT_STALLS
value|0xd2
end_define

begin_comment
comment|/* Segment Register Loads */
end_comment

begin_define
define|#
directive|define
name|PMC6_SEGMENT_REG_LOADS
value|0x06
end_define

begin_comment
comment|/* Clocks */
end_comment

begin_define
define|#
directive|define
name|PMC6_CPU_CLK_UNHALTED
value|0x79
end_define

begin_comment
comment|/*  * Pentium Performance Counters  * This list comes from the Harvard people, not Intel.  */
end_comment

begin_define
define|#
directive|define
name|PMC5_DATA_READ
value|0
end_define

begin_define
define|#
directive|define
name|PMC5_DATA_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|PMC5_DATA_TLB_MISS
value|2
end_define

begin_define
define|#
directive|define
name|PMC5_DATA_READ_MISS
value|3
end_define

begin_define
define|#
directive|define
name|PMC5_DATA_WRITE_MISS
value|4
end_define

begin_define
define|#
directive|define
name|PMC5_WRITE_M_E
value|5
end_define

begin_define
define|#
directive|define
name|PMC5_DATA_LINES_WBACK
value|6
end_define

begin_define
define|#
directive|define
name|PMC5_DATA_CACHE_SNOOP
value|7
end_define

begin_define
define|#
directive|define
name|PMC5_DATA_CACHE_SNOOP_HIT
value|8
end_define

begin_define
define|#
directive|define
name|PMC5_MEM_ACCESS_BOTH
value|9
end_define

begin_define
define|#
directive|define
name|PMC5_BANK_CONFLICTS
value|10
end_define

begin_define
define|#
directive|define
name|PMC5_MISALIGNED_DATA
value|11
end_define

begin_define
define|#
directive|define
name|PMC5_INST_READ
value|12
end_define

begin_define
define|#
directive|define
name|PMC5_INST_TLB_MISS
value|13
end_define

begin_define
define|#
directive|define
name|PMC5_INST_CACHE_MISS
value|14
end_define

begin_define
define|#
directive|define
name|PMC5_SEGMENT_REG_LOAD
value|15
end_define

begin_define
define|#
directive|define
name|PMC5_BRANCHES
value|18
end_define

begin_define
define|#
directive|define
name|PMC5_BTB_HITS
value|19
end_define

begin_define
define|#
directive|define
name|PMC5_BRANCH_TAKEN
value|20
end_define

begin_define
define|#
directive|define
name|PMC5_PIPELINE_FLUSH
value|21
end_define

begin_define
define|#
directive|define
name|PMC5_INST_EXECUTED
value|22
end_define

begin_define
define|#
directive|define
name|PMC5_INST_EXECUTED_V
value|23
end_define

begin_define
define|#
directive|define
name|PMC5_BUS_UTILIZATION
value|24
end_define

begin_define
define|#
directive|define
name|PMC5_WRITE_BACKUP_STALL
value|25
end_define

begin_define
define|#
directive|define
name|PMC5_DATA_READ_STALL
value|26
end_define

begin_define
define|#
directive|define
name|PMC5_WRITE_E_M_STALL
value|27
end_define

begin_define
define|#
directive|define
name|PMC5_LOCKED_BUS
value|28
end_define

begin_define
define|#
directive|define
name|PMC5_IO_CYCLE
value|29
end_define

begin_define
define|#
directive|define
name|PMC5_NONCACHE_MEMORY
value|30
end_define

begin_define
define|#
directive|define
name|PMC5_ADDR_GEN_INTERLOCK
value|31
end_define

begin_define
define|#
directive|define
name|PMC5_FLOPS
value|34
end_define

begin_define
define|#
directive|define
name|PMC5_BP0_MATCH
value|35
end_define

begin_define
define|#
directive|define
name|PMC5_BP1_MATCH
value|36
end_define

begin_define
define|#
directive|define
name|PMC5_BP2_MATCH
value|37
end_define

begin_define
define|#
directive|define
name|PMC5_BP3_MATCH
value|38
end_define

begin_define
define|#
directive|define
name|PMC5_HW_INTR
value|39
end_define

begin_define
define|#
directive|define
name|PMC5_DATA_RW
value|40
end_define

begin_define
define|#
directive|define
name|PMC5_DATA_RW_MISS
value|41
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PERFMON_H_ */
end_comment

end_unit

