begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003, Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PMC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PMC_H_
end_define

begin_include
include|#
directive|include
file|<machine/pmc_mdep.h>
end_include

begin_define
define|#
directive|define
name|PMC_MODULE_NAME
value|"hwpmc"
end_define

begin_define
define|#
directive|define
name|PMC_NAME_MAX
value|16
end_define

begin_comment
comment|/* HW counter name size */
end_comment

begin_define
define|#
directive|define
name|PMC_CLASS_MAX
value|4
end_define

begin_comment
comment|/* #classes of PMCs in a CPU */
end_comment

begin_comment
comment|/* Kernel<->userland API version number [MMmmpppp] */
end_comment

begin_define
define|#
directive|define
name|PMC_VERSION_MAJOR
value|0x01
end_define

begin_define
define|#
directive|define
name|PMC_VERSION_MINOR
value|0x01
end_define

begin_define
define|#
directive|define
name|PMC_VERSION_PATCH
value|0x0001
end_define

begin_define
define|#
directive|define
name|PMC_VERSION
value|(PMC_VERSION_MAJOR<< 24 |		\ 	PMC_VERSION_MINOR<< 16 | PMC_VERSION_PATCH)
end_define

begin_comment
comment|/*  * Kinds of CPUs known  */
end_comment

begin_define
define|#
directive|define
name|__PMC_CPUS
parameter_list|()
define|\
value|__PMC_CPU(AMD_K7,     "AMD K7")			\ 	__PMC_CPU(AMD_K8,     "AMD K8")			\ 	__PMC_CPU(INTEL_P5,   "Intel Pentium")		\ 	__PMC_CPU(INTEL_P6,   "Intel Pentium Pro")	\ 	__PMC_CPU(INTEL_CL,   "Intel Celeron")		\ 	__PMC_CPU(INTEL_PII,  "Intel Pentium II")	\ 	__PMC_CPU(INTEL_PIII, "Intel Pentium III")	\ 	__PMC_CPU(INTEL_PM,   "Intel Pentium M")	\ 	__PMC_CPU(INTEL_PIV,  "Intel Pentium IV")
end_define

begin_enum
enum|enum
name|pmc_cputype
block|{
undef|#
directive|undef
name|__PMC_CPU
define|#
directive|define
name|__PMC_CPU
parameter_list|(
name|S
parameter_list|,
name|D
parameter_list|)
value|PMC_CPU_##S ,
name|__PMC_CPUS
argument_list|()
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PMC_CPU_FIRST
value|PMC_CPU_AMD_K7
end_define

begin_define
define|#
directive|define
name|PMC_CPU_LAST
value|PMC_CPU_INTEL_PIV
end_define

begin_comment
comment|/*  * Classes of PMCs  */
end_comment

begin_define
define|#
directive|define
name|__PMC_CLASSES
parameter_list|()
define|\
value|__PMC_CLASS(TSC)
comment|/* CPU Timestamp counter */
value|\ 	__PMC_CLASS(K7)
comment|/* AMD K7 performance counters */
value|\ 	__PMC_CLASS(K8)
comment|/* AMD K8 performance counters */
value|\ 	__PMC_CLASS(P5)
comment|/* Intel Pentium counters */
value|\ 	__PMC_CLASS(P6)
comment|/* Intel Pentium Pro counters */
value|\ 	__PMC_CLASS(P4)
end_define

begin_comment
comment|/* Intel Pentium-IV counters */
end_comment

begin_enum
enum|enum
name|pmc_class
block|{
undef|#
directive|undef
name|__PMC_CLASS
define|#
directive|define
name|__PMC_CLASS
parameter_list|(
name|N
parameter_list|)
value|PMC_CLASS_##N ,
name|__PMC_CLASSES
argument_list|()
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PMC_CLASS_FIRST
value|PMC_CLASS_TSC
end_define

begin_define
define|#
directive|define
name|PMC_CLASS_LAST
value|PMC_CLASS_P4
end_define

begin_comment
comment|/*  * A PMC can be in the following states:  *  * Hardware states:  *   DISABLED   -- administratively prohibited from being used.  *   FREE       -- HW available for use  * Software states:  *   ALLOCATED  -- allocated  *   STOPPED    -- allocated, but not counting events  *   RUNNING    -- allocated, and in operation; 'pm_runcount'  *                 holds the number of CPUs using this PMC at  *                 a given instant  *   DELETED    -- being destroyed  */
end_comment

begin_define
define|#
directive|define
name|__PMC_HWSTATES
parameter_list|()
define|\
value|__PMC_STATE(DISABLED)			\ 	__PMC_STATE(FREE)
end_define

begin_define
define|#
directive|define
name|__PMC_SWSTATES
parameter_list|()
define|\
value|__PMC_STATE(ALLOCATED)			\ 	__PMC_STATE(STOPPED)			\ 	__PMC_STATE(RUNNING)			\ 	__PMC_STATE(DELETED)
end_define

begin_define
define|#
directive|define
name|__PMC_STATES
parameter_list|()
define|\
value|__PMC_HWSTATES()			\ 	__PMC_SWSTATES()
end_define

begin_enum
enum|enum
name|pmc_state
block|{
undef|#
directive|undef
name|__PMC_STATE
define|#
directive|define
name|__PMC_STATE
parameter_list|(
name|S
parameter_list|)
value|PMC_STATE_##S,
name|__PMC_STATES
argument_list|()
name|__PMC_STATE
argument_list|(
argument|MAX
argument_list|)
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PMC_STATE_FIRST
value|PMC_STATE_DISABLED
end_define

begin_define
define|#
directive|define
name|PMC_STATE_LAST
value|PMC_STATE_DELETED
end_define

begin_comment
comment|/*  * An allocated PMC may used as a 'global' counter or as a  * 'thread-private' one.  Each such mode of use can be in either  * statistical sampling mode or in counting mode.  Thus a PMC in use  *  * SS i.e., SYSTEM STATISTICAL  -- system-wide statistical profiling  * SC i.e., SYSTEM COUNTER      -- system-wide counting mode  * TS i.e., THREAD STATISTICAL  -- thread virtual, statistical profiling  * TC i.e., THREAD COUNTER      -- thread virtual, counting mode  *  * Statistical profiling modes rely on the PMC periodically delivering  * a interrupt to the CPU (when the configured number of events have  * been measured), so the PMC must have the ability to generate  * interrupts.  *  * In counting modes, the PMC counts its configured events, with the  * value of the PMC being read whenever needed by its owner process.  *  * The thread specific modes "virtualize" the PMCs -- the PMCs appear  * to be thread private and count events only when the profiled thread  * actually executes on the CPU.  *  * The system-wide "global" modes keep the PMCs running all the time  * and are used to measure the behaviour of the whole system.  */
end_comment

begin_define
define|#
directive|define
name|__PMC_MODES
parameter_list|()
define|\
value|__PMC_MODE(SS,	0)			\ 	__PMC_MODE(SC,	1)			\ 	__PMC_MODE(TS,	2)			\ 	__PMC_MODE(TC,	3)
end_define

begin_enum
enum|enum
name|pmc_mode
block|{
undef|#
directive|undef
name|__PMC_MODE
define|#
directive|define
name|__PMC_MODE
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|)
value|PMC_MODE_##M = N,
name|__PMC_MODES
argument_list|()
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PMC_MODE_FIRST
value|PMC_MODE_SS
end_define

begin_define
define|#
directive|define
name|PMC_MODE_LAST
value|PMC_MODE_TC
end_define

begin_define
define|#
directive|define
name|PMC_IS_COUNTING_MODE
parameter_list|(
name|mode
parameter_list|)
define|\
value|((mode) == PMC_MODE_SC || (mode) == PMC_MODE_TC)
end_define

begin_define
define|#
directive|define
name|PMC_IS_SYSTEM_MODE
parameter_list|(
name|mode
parameter_list|)
define|\
value|((mode) == PMC_MODE_SS || (mode) == PMC_MODE_SC)
end_define

begin_define
define|#
directive|define
name|PMC_IS_SAMPLING_MODE
parameter_list|(
name|mode
parameter_list|)
define|\
value|((mode) == PMC_MODE_SS || (mode) == PMC_MODE_TS)
end_define

begin_define
define|#
directive|define
name|PMC_IS_VIRTUAL_MODE
parameter_list|(
name|mode
parameter_list|)
define|\
value|((mode) == PMC_MODE_TS || (mode) == PMC_MODE_TC)
end_define

begin_comment
comment|/*  * PMC row disposition  */
end_comment

begin_define
define|#
directive|define
name|__PMC_DISPOSITIONS
parameter_list|(
name|N
parameter_list|)
define|\
value|__PMC_DISP(STANDALONE)
comment|/* global/disabled counters */
value|\ 	__PMC_DISP(FREE)
comment|/* free/available */
value|\ 	__PMC_DISP(THREAD)
comment|/* thread-virtual PMCs */
value|\ 	__PMC_DISP(UNKNOWN)
end_define

begin_comment
comment|/* sentinel */
end_comment

begin_enum
enum|enum
name|pmc_disp
block|{
undef|#
directive|undef
name|__PMC_DISP
define|#
directive|define
name|__PMC_DISP
parameter_list|(
name|D
parameter_list|)
value|PMC_DISP_##D ,
name|__PMC_DISPOSITIONS
argument_list|()
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PMC_DISP_FIRST
value|PMC_DISP_STANDALONE
end_define

begin_define
define|#
directive|define
name|PMC_DISP_LAST
value|PMC_DISP_THREAD
end_define

begin_comment
comment|/*  * PMC event codes  *  * __PMC_EV(CLASS, SYMBOLIC-NAME, VALUE, READABLE-NAME)  */
end_comment

begin_comment
comment|/*  * AMD K7 Events, from "The AMD Athlon(tm) Processor x86 Code  * Optimization Guide" [Doc#22007K, Feb 2002]  */
end_comment

begin_define
define|#
directive|define
name|__PMC_EV_K7
parameter_list|()
define|\
value|__PMC_EV(K7, DC_ACCESSES,		k7-dc-accesses)			\ __PMC_EV(K7, DC_MISSES,			k7-dc-misses)			\ __PMC_EV(K7, DC_REFILLS_FROM_L2,	k7-dc-refills-from-l2)		\ __PMC_EV(K7, DC_REFILLS_FROM_SYSTEM,	k7-dc-refills-from-system)	\ __PMC_EV(K7, DC_WRITEBACKS,		k7-dc-writebacks)		\ __PMC_EV(K7, L1_DTLB_MISS_AND_L2_DTLB_HITS,				\ 			k7-l1-dtlb-miss-and-l2-dtlb-hits)		\ __PMC_EV(K7, L1_AND_L2_DTLB_MISSES,	k7-l1-and-l2-dtlb-misses)	\ __PMC_EV(K7, MISALIGNED_REFERENCES,	k7-misaligned-references)	\ __PMC_EV(K7, IC_FETCHES,		k7-ic-fetches)			\ __PMC_EV(K7, IC_MISSES,			k7-ic-misses)			\ __PMC_EV(K7, L1_ITLB_MISSES,		k7-l1-itlb-misses)		\ __PMC_EV(K7, L1_L2_ITLB_MISSES,		k7-l1-l2-itlb-misses)		\ __PMC_EV(K7, RETIRED_INSTRUCTIONS,	k7-retired-instructions)	\ __PMC_EV(K7, RETIRED_OPS,		k7-retired-ops)			\ __PMC_EV(K7, RETIRED_BRANCHES,		k7-retired-branches)		\ __PMC_EV(K7, RETIRED_BRANCHES_MISPREDICTED,				\ 			k7-retired-branches-mispredicted)		\ __PMC_EV(K7, RETIRED_TAKEN_BRANCHES,	k7-retired-taken-branches)	\ __PMC_EV(K7, RETIRED_TAKEN_BRANCHES_MISPREDICTED,			\ 			k7-retired-taken-branches-mispredicted)		\ __PMC_EV(K7, RETIRED_FAR_CONTROL_TRANSFERS,				\ 			k7-retired-far-control-transfers)		\ __PMC_EV(K7, RETIRED_RESYNC_BRANCHES, k7-retired-resync-branches)	\ __PMC_EV(K7, INTERRUPTS_MASKED_CYCLES, k7-interrupts-masked-cycles)	\ __PMC_EV(K7, INTERRUPTS_MASKED_WHILE_PENDING_CYCLES,			\ 			k7-interrupts-masked-while-pending-cycles)	\ __PMC_EV(K7, HARDWARE_INTERRUPTS,	k7-hardware-interrupts)
end_define

begin_define
define|#
directive|define
name|PMC_EV_K7_FIRST
value|PMC_EV_K7_DC_ACCESSES
end_define

begin_define
define|#
directive|define
name|PMC_EV_K7_LAST
value|PMC_EV_K7_HARDWARE_INTERRUPTS
end_define

begin_comment
comment|/*  * Intel P4 Events, from "IA-32 Intel(r) Architecture Software  * Developer's Manual, Volume 3: System Programming Guide" [245472-012]  */
end_comment

begin_define
define|#
directive|define
name|__PMC_EV_P4
parameter_list|()
define|\
value|__PMC_EV(P4, TC_DELIVER_MODE,		p4-tc-deliver-mode)		\ __PMC_EV(P4, BPU_FETCH_REQUEST,		p4-bpu-fetch-request)		\ __PMC_EV(P4, ITLB_REFERENCE,		p4-itlb-reference)		\ __PMC_EV(P4, MEMORY_CANCEL,		p4-memory-cancel)		\ __PMC_EV(P4, MEMORY_COMPLETE,		p4-memory-complete)		\ __PMC_EV(P4, LOAD_PORT_REPLAY,		p4-load-port-replay)		\ __PMC_EV(P4, STORE_PORT_REPLAY,		p4-store-port-replay)		\ __PMC_EV(P4, MOB_LOAD_REPLAY,		p4-mob-load-replay)		\ __PMC_EV(P4, PAGE_WALK_TYPE,		p4-page-walk-type)		\ __PMC_EV(P4, BSQ_CACHE_REFERENCE,	p4-bsq-cache-reference)		\ __PMC_EV(P4, IOQ_ALLOCATION,		p4-ioq-allocation)		\ __PMC_EV(P4, IOQ_ACTIVE_ENTRIES,	p4-ioq-active-entries)		\ __PMC_EV(P4, FSB_DATA_ACTIVITY,		p4-fsb-data-activity)		\ __PMC_EV(P4, BSQ_ALLOCATION,		p4-bsq-allocation)		\ __PMC_EV(P4, BSQ_ACTIVE_ENTRIES,	p4-bsq-active-entries)		\ __PMC_EV(P4, SSE_INPUT_ASSIST,		p4-sse-input-assist)		\ __PMC_EV(P4, PACKED_SP_UOP,		p4-packed-sp-uop)		\ __PMC_EV(P4, PACKED_DP_UOP,		p4-packed-dp-uop)		\ __PMC_EV(P4, SCALAR_SP_UOP,		p4-scalar-sp-uop)		\ __PMC_EV(P4, SCALAR_DP_UOP,		p4-scalar-dp-uop)		\ __PMC_EV(P4, 64BIT_MMX_UOP,		p4-64bit-mmx-uop)		\ __PMC_EV(P4, 128BIT_MMX_UOP,		p4-128bit-mmx-uop)		\ __PMC_EV(P4, X87_FP_UOP,		p4-x87-fp-uop)			\ __PMC_EV(P4, X87_SIMD_MOVES_UOP,	p4-x87-simd-moves-uop)		\ __PMC_EV(P4, GLOBAL_POWER_EVENTS,	p4-global-power-events)		\ __PMC_EV(P4, TC_MS_XFER,		p4-tc-ms-xfer)			\ __PMC_EV(P4, UOP_QUEUE_WRITES,		p4-uop-queue-writes)		\ __PMC_EV(P4, RETIRED_MISPRED_BRANCH_TYPE,				\ 			    p4-retired-mispred-branch-type)		\ __PMC_EV(P4, RETIRED_BRANCH_TYPE,	p4-retired-branch-type)		\ __PMC_EV(P4, RESOURCE_STALL,		p4-resource-stall)		\ __PMC_EV(P4, WC_BUFFER,			p4-wc-buffer)			\ __PMC_EV(P4, B2B_CYCLES,		p4-b2b-cycles)			\ __PMC_EV(P4, BNR,			p4-bnr)				\ __PMC_EV(P4, SNOOP,			p4-snoop)			\ __PMC_EV(P4, RESPONSE,			p4-response)			\ __PMC_EV(P4, FRONT_END_EVENT,		p4-front-end-event)		\ __PMC_EV(P4, EXECUTION_EVENT,		p4-execution-event)		\ __PMC_EV(P4, REPLAY_EVENT,		p4-replay-event)		\ __PMC_EV(P4, INSTR_RETIRED,		p4-instr-retired)		\ __PMC_EV(P4, UOPS_RETIRED,		p4-uops-retired)		\ __PMC_EV(P4, UOP_TYPE,			p4-uop-type)			\ __PMC_EV(P4, BRANCH_RETIRED,		p4-branch-retired)		\ __PMC_EV(P4, MISPRED_BRANCH_RETIRED,	p4-mispred-branch-retired)	\ __PMC_EV(P4, X87_ASSIST,		p4-x87-assist)			\ __PMC_EV(P4, MACHINE_CLEAR,		p4-machine-clear)
end_define

begin_define
define|#
directive|define
name|PMC_EV_P4_FIRST
value|PMC_EV_P4_TC_DELIVER_MODE
end_define

begin_define
define|#
directive|define
name|PMC_EV_P4_LAST
value|PMC_EV_P4_MACHINE_CLEAR
end_define

begin_comment
comment|/* Intel Pentium Pro, P-II, P-III and Pentium-M style events */
end_comment

begin_define
define|#
directive|define
name|__PMC_EV_P6
parameter_list|()
define|\
value|__PMC_EV(P6, DATA_MEM_REFS,		p6-data-mem-refs)		\ __PMC_EV(P6, DCU_LINES_IN,		p6-dcu-lines-in)		\ __PMC_EV(P6, DCU_M_LINES_IN,		p6-dcu-m-lines-in)		\ __PMC_EV(P6, DCU_M_LINES_OUT,		p6-dcu-m-lines-out)		\ __PMC_EV(P6, DCU_MISS_OUTSTANDING,	p6-dcu-miss-outstanding)	\ __PMC_EV(P6, IFU_FETCH,			p6-ifu-fetch)			\ __PMC_EV(P6, IFU_FETCH_MISS,		p6-ifu-fetch-miss)		\ __PMC_EV(P6, ITLB_MISS,			p6-itlb-miss)			\ __PMC_EV(P6, IFU_MEM_STALL,		p6-ifu-mem-stall)		\ __PMC_EV(P6, ILD_STALL,			p6-ild-stall)			\ __PMC_EV(P6, L2_IFETCH,			p6-l2-ifetch)			\ __PMC_EV(P6, L2_LD,			p6-l2-ld)			\ __PMC_EV(P6, L2_ST,			p6-l2-st)			\ __PMC_EV(P6, L2_LINES_IN,		p6-l2-lines-in)			\ __PMC_EV(P6, L2_LINES_OUT,		p6-l2-lines-out)		\ __PMC_EV(P6, L2_M_LINES_INM,		p6-l2-m-lines-inm)		\ __PMC_EV(P6, L2_M_LINES_OUTM,		p6-l2-m-lines-outm)		\ __PMC_EV(P6, L2_RQSTS,			p6-l2-rqsts)			\ __PMC_EV(P6, L2_ADS,			p6-l2-ads)			\ __PMC_EV(P6, L2_DBUS_BUSY,		p6-l2-dbus-busy)		\ __PMC_EV(P6, L2_DBUS_BUSY_RD,		p6-l2-dbus-busy-rd)		\ __PMC_EV(P6, BUS_DRDY_CLOCKS,		p6-bus-drdy-clocks)		\ __PMC_EV(P6, BUS_LOCK_CLOCKS,		p6-bus-lock-clocks)		\ __PMC_EV(P6, BUS_REQ_OUTSTANDING,	p6-bus-req-outstanding)		\ __PMC_EV(P6, BUS_TRAN_BRD,		p6-bus-tran-brd)		\ __PMC_EV(P6, BUS_TRAN_RFO,		p6-bus-tran-rfo)		\ __PMC_EV(P6, BUS_TRANS_WB,		p6-bus-trans-wb)		\ __PMC_EV(P6, BUS_TRAN_IFETCH,		p6-bus-tran-ifetch)		\ __PMC_EV(P6, BUS_TRAN_INVAL,		p6-bus-tran-inval)		\ __PMC_EV(P6, BUS_TRAN_PWR,		p6-bus-tran-pwr)		\ __PMC_EV(P6, BUS_TRANS_P,		p6-bus-trans-p)			\ __PMC_EV(P6, BUS_TRANS_IO,		p6-bus-trans-io)		\ __PMC_EV(P6, BUS_TRAN_DEF,		p6-bus-tran-def)		\ __PMC_EV(P6, BUS_TRAN_BURST,		p6-bus-tran-burst)		\ __PMC_EV(P6, BUS_TRAN_ANY,		p6-bus-tran-any)		\ __PMC_EV(P6, BUS_TRAN_MEM,		p6-bus-tran-mem)		\ __PMC_EV(P6, BUS_DATA_RCV,		p6-bus-data-rcv)		\ __PMC_EV(P6, BUS_BNR_DRV,		p6-bus-bnr-drv)			\ __PMC_EV(P6, BUS_HIT_DRV,		p6-bus-hit-drv)			\ __PMC_EV(P6, BUS_HITM_DRV,		p6-bus-hitm-drv)		\ __PMC_EV(P6, BUS_SNOOP_STALL,		p6-bus-snoop-stall)		\ __PMC_EV(P6, FLOPS,			p6-flops)			\ __PMC_EV(P6, FP_COMPS_OPS_EXE,		p6-fp-comps-ops-exe)		\ __PMC_EV(P6, FP_ASSIST,			p6-fp-assist)			\ __PMC_EV(P6, MUL,			p6-mul)				\ __PMC_EV(P6, DIV,			p6-div)				\ __PMC_EV(P6, CYCLES_DIV_BUSY,		p6-cycles-div-busy)		\ __PMC_EV(P6, LD_BLOCKS,			p6-ld-blocks)			\ __PMC_EV(P6, SB_DRAINS,			p6-sb-drains)			\ __PMC_EV(P6, MISALIGN_MEM_REF,		p6-misalign-mem-ref)		\ __PMC_EV(P6, EMON_KNI_PREF_DISPATCHED,	p6-emon-kni-pref-dispatched)	\ __PMC_EV(P6, EMON_KNI_PREF_MISS,	p6-emon-kni-pref-miss)		\ __PMC_EV(P6, INST_RETIRED,		p6-inst-retired)		\ __PMC_EV(P6, UOPS_RETIRED,		p6-uops-retired)		\ __PMC_EV(P6, INST_DECODED,		p6-inst-decoded)		\ __PMC_EV(P6, EMON_KNI_INST_RETIRED,	p6-emon-kni-inst-retired)	\ __PMC_EV(P6, EMON_KNI_COMP_INST_RET,	p6-emon-kni-comp-inst-ret)	\ __PMC_EV(P6, HW_INT_RX,			p6-hw-int-rx)			\ __PMC_EV(P6, CYCLES_INT_MASKED,		p6-cycles-int-masked)		\ __PMC_EV(P6, CYCLES_INT_PENDING_AND_MASKED,				\ 			    p6-cycles-in-pending-and-masked)		\ __PMC_EV(P6, BR_INST_RETIRED,		p6-br-inst-retired)		\ __PMC_EV(P6, BR_MISS_PRED_RETIRED,	p6-br-miss-pred-retired)	\ __PMC_EV(P6, BR_TAKEN_RETIRED,		p6-br-taken-retired)		\ __PMC_EV(P6, BR_MISS_PRED_TAKEN_RET,	p6-br-miss-pred-taken-ret)	\ __PMC_EV(P6, BR_INST_DECODED,		p6-br-inst-decoded)		\ __PMC_EV(P6, BTB_MISSES,		p6-btb-misses)			\ __PMC_EV(P6, BR_BOGUS,			p6-br-bogus)			\ __PMC_EV(P6, BACLEARS,			p6-baclears)			\ __PMC_EV(P6, RESOURCE_STALLS,		p6-resource-stalls)		\ __PMC_EV(P6, PARTIAL_RAT_STALLS,	p6-partial-rat-stalls)		\ __PMC_EV(P6, SEGMENT_REG_LOADS,		p6-segment-reg-loads)		\ __PMC_EV(P6, CPU_CLK_UNHALTED,		p6-cpu-clk-unhalted)		\ __PMC_EV(P6, MMX_INSTR_EXEC,		p6-mmx-instr-exec)		\ __PMC_EV(P6, MMX_SAT_INSTR_EXEC,	p6-mmx-sat-instr-exec)		\ __PMC_EV(P6, MMX_UOPS_EXEC,		p6-mmx-uops-exec)		\ __PMC_EV(P6, MMX_INSTR_TYPE_EXEC,	p6-mmx-instr-type-exec)		\ __PMC_EV(P6, FP_MMX_TRANS,		p6-fp-mmx-trans)		\ __PMC_EV(P6, MMX_ASSIST,		p6-mmx-assist)			\ __PMC_EV(P6, MMX_INSTR_RET,		p6-mmx-instr-ret)		\ __PMC_EV(P6, SEG_RENAME_STALLS,		p6-seg-rename-stalls)		\ __PMC_EV(P6, SEG_REG_RENAMES,		p6-seg-reg-renames)		\ __PMC_EV(P6, RET_SEG_RENAMES,		p6-ret-seg-renames)		\ __PMC_EV(P6, EMON_EST_TRANS,		p6-emon-est-trans)		\ __PMC_EV(P6, EMON_THERMAL_TRIP,		p6-emon-thermal-trip)		\ __PMC_EV(P6, BR_INST_EXEC,		p6-br-inst-exec)		\ __PMC_EV(P6, BR_MISSP_EXEC,		p6-br-missp-exec)		\ __PMC_EV(P6, BR_BAC_MISSP_EXEC,		p6-br-bac-missp-exec)		\ __PMC_EV(P6, BR_CND_EXEC,		p6-br-cnd-exec)			\ __PMC_EV(P6, BR_CND_MISSP_EXEC,		p6-br-cnd-missp-exec)		\ __PMC_EV(P6, BR_IND_EXEC,		p6-br-ind-exec)			\ __PMC_EV(P6, BR_IND_MISSP_EXEC,		p6-br-ind-missp-exec)		\ __PMC_EV(P6, BR_RET_EXEC,		p6-br-ret-exec)			\ __PMC_EV(P6, BR_RET_MISSP_EXEC,		p6-br-ret-missp-exec)		\ __PMC_EV(P6, BR_RET_BAC_MISSP_EXEC,	p6-br-ret-bac-missp-exec)	\ __PMC_EV(P6, BR_CALL_EXEC,		p6-br-call-exec)		\ __PMC_EV(P6, BR_CALL_MISSP_EXEC,	p6-br-call-missp-exec)		\ __PMC_EV(P6, BR_IND_CALL_EXEC,		p6-br-ind-call-exec)		\ __PMC_EV(P6, EMON_SIMD_INSTR_RETIRED,	p6-emon-simd-instr-retired)	\ __PMC_EV(P6, EMON_SYNCH_UOPS,		p6-emon-synch-uops)		\ __PMC_EV(P6, EMON_ESP_UOPS,		p6-emon-esp-uops)		\ __PMC_EV(P6, EMON_FUSED_UOPS_RET,	p6-emon-fused-uops-ret)		\ __PMC_EV(P6, EMON_UNFUSION,		p6-emon-unfusion)		\ __PMC_EV(P6, EMON_PREF_RQSTS_UP,	p6-emon-pref-rqsts-up)		\ __PMC_EV(P6, EMON_PREF_RQSTS_DN,	p6-emon-pref-rqsts-dn)		\ __PMC_EV(P6, EMON_SSE_SSE2_INST_RETIRED,				\ 				p6-emon-sse-sse2-inst-retired)		\ __PMC_EV(P6, EMON_SSE_SSE2_COMP_INST_RETIRED,				\ 				p6-emon-sse-sse2-comp-inst-retired)
end_define

begin_define
define|#
directive|define
name|PMC_EV_P6_FIRST
value|PMC_EV_P6_DATA_MEM_REFS
end_define

begin_define
define|#
directive|define
name|PMC_EV_P6_LAST
value|PMC_EV_P6_EMON_SSE_SSE2_COMP_INST_RETIRED
end_define

begin_comment
comment|/* AMD K8 PMCs */
end_comment

begin_define
define|#
directive|define
name|__PMC_EV_K8
parameter_list|()
define|\
value|__PMC_EV(K8, FP_DISPATCHED_FPU_OPS,	k8-fp-dispatched-fpu-ops)	\ __PMC_EV(K8, FP_CYCLES_WITH_NO_FPU_OPS_RETIRED,				\ 		k8-fp-cycles-with-no-fpu-ops-retired)			\ __PMC_EV(K8, FP_DISPATCHED_FPU_FAST_FLAG_OPS,				\ 		k8-fp-dispatched-fpu-fast-flag-ops)			\ __PMC_EV(K8, LS_SEGMENT_REGISTER_LOAD,	k8-ls-segment-register-load)	\ __PMC_EV(K8, LS_MICROARCHITECTURAL_RESYNC_BY_SELF_MODIFYING_CODE,	\ 		k8-ls-microarchitectural-resync-by-self-modifying-code)	\ __PMC_EV(K8, LS_MICROARCHITECTURAL_RESYNC_BY_SNOOP,			\ 		k8-ls-microarchitectural-resync-by-snoop)		\ __PMC_EV(K8, LS_BUFFER2_FULL,		k8-ls-buffer2-full)		\ __PMC_EV(K8, LS_LOCKED_OPERATION,	k8-ls-locked-operation)		\ __PMC_EV(K8, LS_MICROARCHITECTURAL_LATE_CANCEL,				\ 		k8-ls-microarchitectural-late-cancel)			\ __PMC_EV(K8, LS_RETIRED_CFLUSH_INSTRUCTIONS,				\ 		k8-ls-retired-cflush-instructions)			\ __PMC_EV(K8, LS_RETIRED_CPUID_INSTRUCTIONS,				\ 		k8-ls-retired-cpuid-instructions)			\ __PMC_EV(K8, DC_ACCESS,			k8-dc-access)			\ __PMC_EV(K8, DC_MISS,			k8-dc-miss)			\ __PMC_EV(K8, DC_REFILL_FROM_L2,		k8-dc-refill-from-l2)		\ __PMC_EV(K8, DC_REFILL_FROM_SYSTEM,	k8-dc-refill-from-system)	\ __PMC_EV(K8, DC_COPYBACK,		k8-dc-copyback)			\ __PMC_EV(K8, DC_L1_DTLB_MISS_AND_L2_DTLB_HIT,				\ 		k8-dc-l1-dtlb-miss-and-l2-dtlb-hit)			\ __PMC_EV(K8, DC_L1_DTLB_MISS_AND_L2_DTLB_MISS,				\ 		k8-dc-l1-dtlb-miss-and-l2-dtlb-miss)			\ __PMC_EV(K8, DC_MISALIGNED_DATA_REFERENCE,				\ 		k8-dc-misaligned-data-reference)			\ __PMC_EV(K8, DC_MICROARCHITECTURAL_LATE_CANCEL,				\ 		k8-dc-microarchitectural-late-cancel-of-an-access)	\ __PMC_EV(K8, DC_MICROARCHITECTURAL_EARLY_CANCEL,			\ 		k8-dc-microarchitectural-early-cancel-of-an-access)	\ __PMC_EV(K8, DC_ONE_BIT_ECC_ERROR,	k8-dc-one-bit-ecc-error)	\ __PMC_EV(K8, DC_DISPATCHED_PREFETCH_INSTRUCTIONS,			\ 		k8-dc-dispatched-prefetch-instructions)			\ __PMC_EV(K8, DC_DCACHE_ACCESSES_BY_LOCKS,				\ 		k8-dc-dcache-accesses-by-locks)				\ __PMC_EV(K8, BU_CPU_CLK_UNHALTED,	k8-bu-cpu-clk-unhalted)		\ __PMC_EV(K8, BU_INTERNAL_L2_REQUEST,	k8-bu-internal-l2-request)	\ __PMC_EV(K8, BU_FILL_REQUEST_L2_MISS,	k8-bu-fill-request-l2-miss)	\ __PMC_EV(K8, BU_FILL_INTO_L2,		k8-bu-fill-into-l2)		\ __PMC_EV(K8, IC_FETCH,			k8-ic-fetch)			\ __PMC_EV(K8, IC_MISS,			k8-ic-miss)			\ __PMC_EV(K8, IC_REFILL_FROM_L2,		k8-ic-refill-from-l2)		\ __PMC_EV(K8, IC_REFILL_FROM_SYSTEM,	k8-ic-refill-from-system)	\ __PMC_EV(K8, IC_L1_ITLB_MISS_AND_L2_ITLB_HIT,				\ 		k8-ic-l1-itlb-miss-and-l2-itlb-hit)			\ __PMC_EV(K8, IC_L1_ITLB_MISS_AND_L2_ITLB_MISS,				\ 		k8-ic-l1-itlb-miss-and-l2-itlb-miss)			\ __PMC_EV(K8, IC_MICROARCHITECTURAL_RESYNC_BY_SNOOP,			\ 		k8-ic-microarchitectural-resync-by-snoop)		\ __PMC_EV(K8, IC_INSTRUCTION_FETCH_STALL,				\ 		k8-ic-instruction-fetch-stall)				\ __PMC_EV(K8, IC_RETURN_STACK_HIT,	k8-ic-return-stack-hit)		\ __PMC_EV(K8, IC_RETURN_STACK_OVERFLOW,	k8-ic-return-stack-overflow)	\ __PMC_EV(K8, FR_RETIRED_X86_INSTRUCTIONS,				\ 		k8-fr-retired-x86-instructions)				\ __PMC_EV(K8, FR_RETIRED_UOPS,		k8-fr-retired-uops)		\ __PMC_EV(K8, FR_RETIRED_BRANCHES,	k8-fr-retired-branches)		\ __PMC_EV(K8, FR_RETIRED_BRANCHES_MISPREDICTED,				\ 		k8-fr-retired-branches-mispredicted)			\ __PMC_EV(K8, FR_RETIRED_TAKEN_BRANCHES,					\ 		k8-fr-retired-taken-branches)				\ __PMC_EV(K8, FR_RETIRED_TAKEN_BRANCHES_MISPREDICTED,			\ 		k8-fr-retired-taken-branches-mispredicted)		\ __PMC_EV(K8, FR_RETIRED_FAR_CONTROL_TRANSFERS,				\ 		k8-fr-retired-far-control-transfers)			\ __PMC_EV(K8, FR_RETIRED_RESYNCS,	k8-fr-retired-resyncs)		\ __PMC_EV(K8, FR_RETIRED_NEAR_RETURNS,	k8-fr-retired-near-returns)	\ __PMC_EV(K8, FR_RETIRED_NEAR_RETURNS_MISPREDICTED,			\ 		k8-fr-retired-near-returns-mispredicted)		\ __PMC_EV(K8,								\ 	FR_RETIRED_TAKEN_BRANCHES_MISPREDICTED_BY_ADDR_MISCOMPARE,	\ 	k8-fr-retired-taken-branches-mispredicted-by-addr-miscompare)	\ __PMC_EV(K8, FR_RETIRED_FPU_INSTRUCTIONS,				\ 		k8-fr-retired-fpu-instructions)				\ __PMC_EV(K8, FR_RETIRED_FASTPATH_DOUBLE_OP_INSTRUCTIONS,		\ 		k8-fr-retired-fastpath-double-op-instructions)		\ __PMC_EV(K8, FR_INTERRUPTS_MASKED_CYCLES,				\ 		k8-fr-interrupts-masked-cycles)				\ __PMC_EV(K8, FR_INTERRUPTS_MASKED_WHILE_PENDING_CYCLES,			\ 		k8-fr-interrupts-masked-while-pending-cycles)		\ __PMC_EV(K8, FR_TAKEN_HARDWARE_INTERRUPTS,				\ 		k8-fr-taken-hardware-interrupts)			\ __PMC_EV(K8, FR_DECODER_EMPTY,		k8-fr-decoder-empty)		\ __PMC_EV(K8, FR_DISPATCH_STALLS,	k8-fr-dispatch-stalls)		\ __PMC_EV(K8, FR_DISPATCH_STALL_FROM_BRANCH_ABORT_TO_RETIRE,		\ 		k8-fr-dispatch-stall-from-branch-abort-to-retire)	\ __PMC_EV(K8, FR_DISPATCH_STALL_FOR_SERIALIZATION,			\ 		k8-fr-dispatch-stall-for-serialization)			\ __PMC_EV(K8, FR_DISPATCH_STALL_FOR_SEGMENT_LOAD,			\ 		k8-fr-dispatch-stall-for-segment-load)			\ __PMC_EV(K8, FR_DISPATCH_STALL_WHEN_REORDER_BUFFER_IS_FULL,		\ 		k8-fr-dispatch-stall-when-reorder-buffer-is-full)	\ __PMC_EV(K8,								\ 	FR_DISPATCH_STALL_WHEN_RESERVATION_STATIONS_ARE_FULL,		\ 	k8-fr-dispatch-stall-when-reservation-stations-are-full)	\ __PMC_EV(K8, FR_DISPATCH_STALL_WHEN_FPU_IS_FULL,			\ 		k8-fr-dispatch-stall-when-fpu-is-full)			\ __PMC_EV(K8, FR_DISPATCH_STALL_WHEN_LS_IS_FULL,				\ 		k8-fr-dispatch-stall-when-ls-is-full)			\ __PMC_EV(K8, FR_DISPATCH_STALL_WHEN_WAITING_FOR_ALL_TO_BE_QUIET,	\ 		k8-fr-dispatch-stall-when-waiting-for-all-to-be-quiet)	\ __PMC_EV(K8,								\ 	FR_DISPATCH_STALL_WHEN_FAR_XFER_OR_RESYNC_BRANCH_PENDING,	\ 	k8-fr-dispatch-stall-when-far-xfer-or-resync-branch-pending)	\ __PMC_EV(K8, FR_FPU_EXCEPTIONS,		k8-fr-fpu-exceptions)		\ __PMC_EV(K8, FR_NUMBER_OF_BREAKPOINTS_FOR_DR0,				\ 		k8-fr-number-of-breakpoints-for-dr0)			\ __PMC_EV(K8, FR_NUMBER_OF_BREAKPOINTS_FOR_DR1,				\ 		k8-fr-number-of-breakpoints-for-dr1)			\ __PMC_EV(K8, FR_NUMBER_OF_BREAKPOINTS_FOR_DR2,				\ 		k8-fr-number-of-breakpoints-for-dr2)			\ __PMC_EV(K8, FR_NUMBER_OF_BREAKPOINTS_FOR_DR3,				\ 		k8-fr-number-of-breakpoints-for-dr3)			\ __PMC_EV(K8, NB_MEMORY_CONTROLLER_PAGE_ACCESS_EVENT,			\ 		k8-nb-memory-controller-page-access-event)		\ __PMC_EV(K8, NB_MEMORY_CONTROLLER_PAGE_TABLE_OVERFLOW,			\ 		k8-nb-memory-controller-page-table-overflow)		\ __PMC_EV(K8, NB_MEMORY_CONTROLLER_DRAM_COMMAND_SLOTS_MISSED,		\ 		k8-nb-memory-controller-dram-slots-missed)		\ __PMC_EV(K8, NB_MEMORY_CONTROLLER_TURNAROUND,				\ 		k8-nb-memory-controller-turnaround)			\ __PMC_EV(K8, NB_MEMORY_CONTROLLER_BYPASS_SATURATION,			\ 		k8-nb-memory-controller-bypass-saturation)		\ __PMC_EV(K8, NB_SIZED_COMMANDS,		k8-nb-sized-commands)		\ __PMC_EV(K8, NB_PROBE_RESULT,		k8-nb-probe-result)		\ __PMC_EV(K8, NB_HT_BUS0_BANDWIDTH,	k8-nb-ht-bus0-bandwidth)	\ __PMC_EV(K8, NB_HT_BUS1_BANDWIDTH,	k8-nb-ht-bus1-bandwidth)	\ __PMC_EV(K8, NB_HT_BUS2_BANDWIDTH,	k8-nb-ht-bus2-bandwidth)
end_define

begin_define
define|#
directive|define
name|PMC_EV_K8_FIRST
value|PMC_EV_K8_FP_DISPATCHED_FPU_OPS
end_define

begin_define
define|#
directive|define
name|PMC_EV_K8_LAST
value|PMC_EV_K8_NB_HT_BUS2_BANDWIDTH
end_define

begin_comment
comment|/* Intel Pentium Events */
end_comment

begin_define
define|#
directive|define
name|__PMC_EV_P5
parameter_list|()
define|\
value|__PMC_EV(P5, DATA_READ, p5-data-read)					\ __PMC_EV(P5, DATA_WRITE, p5-data-write)					\ __PMC_EV(P5, DATA_TLB_MISS, p5-data-tlb-miss)				\ __PMC_EV(P5, DATA_READ_MISS, p5-data-read-miss)				\ __PMC_EV(P5, DATA_WRITE_MISS, p5-data-write-miss)			\ __PMC_EV(P5, WRITE_HIT_TO_M_OR_E_STATE_LINES,				\     p5-write-hit-to-m-or-e-state-lines)					\ __PMC_EV(P5, DATA_CACHE_LINES_WRITTEN_BACK,				\     p4-data-cache-lines-written-back)					\ __PMC_EV(P5, EXTERNAL_SNOOPS, p5-external-snoops)			\ __PMC_EV(P5, EXTERNAL_DATA_CACHE_SNOOP_HITS,				\     p5-external-data-cache-snoop-hits)					\ __PMC_EV(P5, MEMORY_ACCESSES_IN_BOTH_PIPES,				\     p5-memory-accesses-in-both-pipes)					\ __PMC_EV(P5, BANK_CONFLICTS, p5-bank-conflicts)				\ __PMC_EV(P5, MISALIGNED_DATA_OR_IO_REFERENCES,				\     p5-misaligned-data-or-io-references)				\ __PMC_EV(P5, CODE_READ, p5-code-read)					\ __PMC_EV(P5, CODE_TLB_MISS, p5-code-tlb-miss)				\ __PMC_EV(P5, CODE_CACHE_MISS, p5-code-cache-miss)			\ __PMC_EV(P5, ANY_SEGMENT_REGISTER_LOADED,				\     p5-any-segment-register-loaded)					\ __PMC_EV(P5, BRANCHES, p5-branches)					\ __PMC_EV(P5, BTB_HITS, p5-btb-hits)					\ __PMC_EV(P5, TAKEN_BRANCH_OR_BTB_HIT,					\     p5-taken-branch-or-btb-hit)						\ __PMC_EV(P5, PIPELINE_FLUSHES, p5-pipeline-flushes)			\ __PMC_EV(P5, INSTRUCTIONS_EXECUTED, p5-instructions-executed)		\ __PMC_EV(P5, INSTRUCTIONS_EXECUTED_V_PIPE,				\     p5-instructions-executed-v-pipe)					\ __PMC_EV(P5, BUS_CYCLE_DURATION, p5-bus-cycle-duration)			\ __PMC_EV(P5, WRITE_BUFFER_FULL_STALL_DURATION,				\     p5-write-buffer-full-stall-duration)				\ __PMC_EV(P5, WAITING_FOR_DATA_MEMORY_READ_STALL_DURATION,		\     p5-waiting-for-data-memory-read-stall-duration)			\ __PMC_EV(P5, STALL_ON_WRITE_TO_AN_E_OR_M_STATE_LINE,			\     p5-stall-on-write-to-an-e-or-m-state-line)				\ __PMC_EV(P5, LOCKED_BUS_CYCLE, p5-locked-bus-cycle)			\ __PMC_EV(P5, IO_READ_OR_WRITE_CYCLE, p5-io-read-or-write-cycle)		\ __PMC_EV(P5, NONCACHEABLE_MEMORY_READS,					\     p5-noncacheable-memory-reads)					\ __PMC_EV(P5, PIPELINE_AGI_STALLS, p5-pipeline-agi-stalls)		\ __PMC_EV(P5, FLOPS, p5-flops)						\ __PMC_EV(P5, BREAKPOINT_MATCH_ON_DR0_REGISTER,				\     p5-breakpoint-match-on-dr0-register)				\ __PMC_EV(P5, BREAKPOINT_MATCH_ON_DR1_REGISTER,				\     p5-breakpoint-match-on-dr1-register)				\ __PMC_EV(P5, BREAKPOINT_MATCH_ON_DR2_REGISTER,				\     p5-breakpoint-match-on-dr2-register)				\ __PMC_EV(P5, BREAKPOINT_MATCH_ON_DR3_REGISTER,				\     p5-breakpoint-match-on-dr3-register)				\ __PMC_EV(P5, HARDWARE_INTERRUPTS, p5-hardware-interrupts)		\ __PMC_EV(P5, DATA_READ_OR_WRITE, p5-data-read-or-write)			\ __PMC_EV(P5, DATA_READ_MISS_OR_WRITE_MISS,				\     p5-data-read-miss-or-write-miss)					\ __PMC_EV(P5, BUS_OWNERSHIP_LATENCY, p5-bus-ownership-latency)		\ __PMC_EV(P5, BUS_OWNERSHIP_TRANSFERS, p5-bus-ownership-transfers)	\ __PMC_EV(P5, MMX_INSTRUCTIONS_EXECUTED_U_PIPE,				\     p5-mmx-instructions-executed-u-pipe)				\ __PMC_EV(P5, MMX_INSTRUCTIONS_EXECUTED_V_PIPE,				\     p5-mmx-instructions-executed-v-pipe)				\ __PMC_EV(P5, CACHE_M_LINE_SHARING, p5-cache-m-line-sharing)		\ __PMC_EV(P5, CACHE_LINE_SHARING, p5-cache-line-sharing)			\ __PMC_EV(P5, EMMS_INSTRUCTIONS_EXECUTED,				\     p5-emms-instructions-executed)					\ __PMC_EV(P5, TRANSITIONS_BETWEEN_MMX_AND_FP_INSTRUCTIONS,		\     p5-transitions-between-mmx-and-fp-instructions)			\ __PMC_EV(P5, BUS_UTILIZATION_DUE_TO_PROCESSOR_ACTIVITY,			\     p5-bus-utilization-due-to-processor-activity)			\ __PMC_EV(P5, WRITES_TO_NONCACHEABLE_MEMORY,				\     p5-writes-to-noncacheable-memory)					\ __PMC_EV(P5, SATURATING_MMX_INSTRUCTIONS_EXECUTED,			\     p5-saturating-mmx-instructions-executed)				\ __PMC_EV(P5, SATURATIONS_PERFORMED, p5-saturations-performed)		\ __PMC_EV(P5, NUMBER_OF_CYCLES_NOT_IN_HALT_STATE,			\     p5-number-of-cycles-not-in-halt-state)				\ __PMC_EV(P5, DATA_CACHE_TLB_MISS_STALL_DURATION,			\     p5-data-cache-tlb-miss-stall-duration)				\ __PMC_EV(P5, MMX_INSTRUCTION_DATA_READS,				\     p5-mmx-instruction-data-reads)					\ __PMC_EV(P5, MMX_INSTRUCTION_DATA_READ_MISSES,				\     p5-mmx-instruction-data-read-misses)				\ __PMC_EV(P5, FLOATING_POINT_STALLS_DURATION,				\     p5-floating-point-stalls-duration)					\ __PMC_EV(P5, TAKEN_BRANCHES, p5-taken-branches)				\ __PMC_EV(P5, D1_STARVATION_AND_FIFO_IS_EMPTY,				\     p5-d1-starvation-and-fifo-is-empty)					\ __PMC_EV(P5, D1_STARVATION_AND_ONLY_ONE_INSTRUCTION_IN_FIFO,		\     p5-d1-starvation-and-only-instruction-in-fifo)			\ __PMC_EV(P5, MMX_INSTRUCTION_DATA_WRITES,				\     p5-mmx-instruction-data-writes)					\ __PMC_EV(P5, MMX_INSTRUCTION_DATA_WRITE_MISSES,				\     p5-mmx-instruction-data-write-misses)				\ __PMC_EV(P5, PIPELINE_FLUSHES_DUE_TO_WRONG_BRANCH_PREDICTIONS,		\     p5-pipeline-flushes-due-to-wrong-branch-predictions)		\ __PMC_EV(P5,								\     PIPELINE_FLUSHES_DUE_TO_WRONG_BRANCH_PREDICTIONS_RESOLVED_IN_WB_STAGE, \     p5-pipeline-flushes-due-to-wrong-branch-predictions-resolved-in-wb-stage) \ __PMC_EV(P5, MISALIGNED_DATA_MEMORY_REFERENCE_ON_MMX_INSTRUCTIONS,	\     p5-misaligned-data-memory-reference-on-mmx-instructions)		\ __PMC_EV(P5, PIPELINE_STALL_FOR_MMX_INSTRUCTION_DATA_MEMORY_READS,	\     p5-pipeline-stall-for-mmx-instruction-data-memory-reads)		\ __PMC_EV(P5, MISPREDICTED_OR_UNPREDICTED_RETURNS,			\     p5-mispredicted-or-unpredicted-returns)				\ __PMC_EV(P5, PREDICTED_RETURNS, p5-predicted-returns)			\ __PMC_EV(P5, MMX_MULTIPLY_UNIT_INTERLOCK,				\     p5-mmx-multiply-unit-interlock)					\ __PMC_EV(P5, MOVD_MOVQ_STORE_STALL_DUE_TO_PREVIOUS_MMX_OPERATION,	\     p5-movd-movq-store-stall-due-to-previous-mmx-operation)		\ __PMC_EV(P5, RETURNS, p5-returns)					\ __PMC_EV(P5, BTB_FALSE_ENTRIES, p5-btb-false-entries)			\ __PMC_EV(P5, BTB_MISS_PREDICTION_ON_NOT_TAKEN_BRANCH,			\     p5-btb-miss-prediction-on-not-taken-branch)				\ __PMC_EV(P5,								\     FULL_WRITE_BUFFER_STALL_DURATION_WHILE_EXECUTING_MMX_INSTRUCTIONS,	\     p5-full-write-buffer-stall-duration-while-executing-mmx-instructions) \ __PMC_EV(P5, STALL_ON_MMX_INSTRUCTION_WRITE_TO_E_OR_M_STATE_LINE,	\     p5-stall-on-mmx-instruction-write-to-e-o-m-state-line)
end_define

begin_define
define|#
directive|define
name|PMC_EV_P5_FIRST
value|PMC_EV_P5_DATA_READ
end_define

begin_define
define|#
directive|define
name|PMC_EV_P5_LAST
define|\
value|PMC_EV_P5_STALL_ON_MMX_INSTRUCTION_WRITE_TO_E_OR_M_STATE_LINE
end_define

begin_comment
comment|/* timestamp counters. */
end_comment

begin_define
define|#
directive|define
name|__PMC_EV_TSC
parameter_list|()
define|\
value|__PMC_EV(TSC, TSC, tsc)
end_define

begin_comment
comment|/* All known PMC events */
end_comment

begin_define
define|#
directive|define
name|__PMC_EVENTS
parameter_list|()
define|\
value|__PMC_EV_TSC()							\ 	__PMC_EV_K7()							\ 	__PMC_EV_P6()							\ 	__PMC_EV_P4()							\ 	__PMC_EV_K8()							\ 	__PMC_EV_P5()							\    enum pmc_event {
end_define

begin_undef
undef|#
directive|undef
name|__PMC_EV
end_undef

begin_define
define|#
directive|define
name|__PMC_EV
parameter_list|(
name|C
parameter_list|,
name|N
parameter_list|,
name|D
parameter_list|)
value|PMC_EV_ ## C ## _ ## N ,
end_define

begin_macro
name|__PMC_EVENTS
argument_list|()
end_macro

begin_define
unit|};
define|#
directive|define
name|PMC_EVENT_FIRST
value|PMC_EV_TSC_TSC
end_define

begin_define
define|#
directive|define
name|PMC_EVENT_LAST
value|PMC_EV_P5_LAST
end_define

begin_comment
comment|/*  * Counter capabilities  *  * __PMC_CAPS(NAME, VALUE, DESCRIPTION)  */
end_comment

begin_define
define|#
directive|define
name|__PMC_CAPS
parameter_list|()
define|\
value|__PMC_CAP(INTERRUPT,	0, "generate interrupts")		\ 	__PMC_CAP(USER,		1, "count user-mode events")		\ 	__PMC_CAP(SYSTEM,	2, "count system-mode events")		\ 	__PMC_CAP(EDGE,		3, "do edge detection of events")	\ 	__PMC_CAP(THRESHOLD,	4, "ignore events below a threshold")	\ 	__PMC_CAP(READ,		5, "read PMC counter")			\ 	__PMC_CAP(WRITE,	6, "reprogram PMC counter")		\ 	__PMC_CAP(INVERT,	7, "invert comparision sense")		\ 	__PMC_CAP(QUALIFIER,	8, "further qualify monitored events")	\ 	__PMC_CAP(PRECISE,	9, "perform precise sampling")		\ 	__PMC_CAP(TAGGING,	10, "tag upstream events")		\ 	__PMC_CAP(CASCADE,	11, "cascade counters")
end_define

begin_enum
enum|enum
name|pmc_caps
block|{
undef|#
directive|undef
name|__PMC_CAP
define|#
directive|define
name|__PMC_CAP
parameter_list|(
name|NAME
parameter_list|,
name|VALUE
parameter_list|,
name|DESCR
parameter_list|)
value|PMC_CAP_##NAME = (1<< VALUE) ,
name|__PMC_CAPS
argument_list|()
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PMC_CAP_FIRST
value|PMC_CAP_INTERRUPT
end_define

begin_define
define|#
directive|define
name|PMC_CAP_LAST
value|PMC_CAP_CASCADE
end_define

begin_comment
comment|/*  * PMC SYSCALL INTERFACE  */
end_comment

begin_comment
comment|/*  * "PMC_OPS" -- these are the commands recognized by the kernel  * module, and are used when performing a system call from userland.  */
end_comment

begin_define
define|#
directive|define
name|__PMC_OPS
parameter_list|()
define|\
value|__PMC_OP(CONFIGURELOG, "Set log file")				\ 	__PMC_OP(GETCPUINFO, "Get system CPU information")		\ 	__PMC_OP(GETDRIVERSTATS, "Get driver statistics")		\ 	__PMC_OP(GETMODULEVERSION, "Get module version")		\ 	__PMC_OP(GETPMCINFO, "Get per-cpu PMC information")		\ 	__PMC_OP(PMCADMIN, "Set PMC state")				\ 	__PMC_OP(PMCALLOCATE, "Allocate and configure a PMC")		\ 	__PMC_OP(PMCATTACH, "Attach a PMC to a process")		\ 	__PMC_OP(PMCDETACH, "Detach a PMC from a process")		\ 	__PMC_OP(PMCRELEASE, "Release a PMC")				\ 	__PMC_OP(PMCRW, "Read/Set a PMC")				\ 	__PMC_OP(PMCSETCOUNT, "Set initial count/sampling rate")	\ 	__PMC_OP(PMCSTART, "Start a PMC")				\ 	__PMC_OP(PMCSTOP, "Start a PMC")				\ 	__PMC_OP(WRITELOG, "Write a log file entry")			\ 	__PMC_OP(PMCX86GETMSR, "(x86 architectures) retrieve MSR")
end_define

begin_enum
enum|enum
name|pmc_ops
block|{
undef|#
directive|undef
name|__PMC_OP
define|#
directive|define
name|__PMC_OP
parameter_list|(
name|N
parameter_list|,
name|D
parameter_list|)
value|PMC_OP_##N,
name|__PMC_OPS
argument_list|()
block|}
enum|;
end_enum

begin_comment
comment|/*  * Flags used in operations.  */
end_comment

begin_define
define|#
directive|define
name|PMC_F_FORCE
value|0x00000001
end_define

begin_comment
comment|/*OP ADMIN force operation */
end_comment

begin_define
define|#
directive|define
name|PMC_F_DESCENDANTS
value|0x00000002
end_define

begin_comment
comment|/*OP ALLOCATE track descendants */
end_comment

begin_define
define|#
directive|define
name|PMC_F_LOG_TC_CSW
value|0x00000004
end_define

begin_comment
comment|/*OP CONFIGURELOG ctx switches */
end_comment

begin_define
define|#
directive|define
name|PMC_F_LOG_TC_PROCEXIT
value|0x00000008
end_define

begin_comment
comment|/*OP CONFIGURELOG log proc exits */
end_comment

begin_define
define|#
directive|define
name|PMC_F_NEWVALUE
value|0x00000010
end_define

begin_comment
comment|/*OP RW write new value */
end_comment

begin_define
define|#
directive|define
name|PMC_F_OLDVALUE
value|0x00000020
end_define

begin_comment
comment|/*OP RW get old value */
end_comment

begin_comment
comment|/*  * Cookies used to denote allocated PMCs, and the values of PMCs.  */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|pmc_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|pmc_value_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PMC_ID_INVALID
value|(~ (pmc_id_t) 0)
end_define

begin_comment
comment|/*  * Data structures for system calls supported by the pmc driver.  */
end_comment

begin_comment
comment|/*  * OP PMCALLOCATE  *  * Allocate a PMC on the named CPU.  */
end_comment

begin_define
define|#
directive|define
name|PMC_CPU_ANY
value|~0
end_define

begin_struct
struct|struct
name|pmc_op_pmcallocate
block|{
name|uint32_t
name|pm_caps
decl_stmt|;
comment|/* PMC_CAP_* */
name|uint32_t
name|pm_cpu
decl_stmt|;
comment|/* CPU number or PMC_CPU_ANY */
name|enum
name|pmc_class
name|pm_class
decl_stmt|;
comment|/* class of PMC desired */
name|enum
name|pmc_event
name|pm_ev
decl_stmt|;
comment|/* [enum pmc_event] desired */
name|uint32_t
name|pm_flags
decl_stmt|;
comment|/* additional modifiers PMC_F_* */
name|enum
name|pmc_mode
name|pm_mode
decl_stmt|;
comment|/* desired mode */
name|pmc_id_t
name|pm_pmcid
decl_stmt|;
comment|/* [return] process pmc id */
comment|/* 	 * Machine dependent extensions 	 */
if|#
directive|if
name|__i386__
name|uint32_t
name|pm_config1
decl_stmt|;
name|uint32_t
name|pm_config2
decl_stmt|;
define|#
directive|define
name|pm_amd_config
value|pm_config1
define|#
directive|define
name|pm_p4_cccrconfig
value|pm_config1
define|#
directive|define
name|pm_p4_escrconfig
value|pm_config2
define|#
directive|define
name|pm_p6_config
value|pm_config1
elif|#
directive|elif
name|__amd64__
name|uint32_t
name|pm_k8_config
decl_stmt|;
define|#
directive|define
name|pm_amd_config
value|pm_k8_config
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP PMCADMIN  *  * Set the administrative state (i.e., whether enabled or disabled) of  * a PMC 'pm_pmc' on CPU 'pm_cpu'.  Note that 'pm_pmc' specifies an  * absolute PMC number and need not have been first allocated by the  * calling process.  */
end_comment

begin_struct
struct|struct
name|pmc_op_pmcadmin
block|{
name|int
name|pm_cpu
decl_stmt|;
comment|/* CPU# */
name|uint32_t
name|pm_flags
decl_stmt|;
comment|/* flags */
name|int
name|pm_pmc
decl_stmt|;
comment|/* PMC# */
name|enum
name|pmc_state
name|pm_state
decl_stmt|;
comment|/* desired state */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP PMCATTACH / OP PMCDETACH  *  * Attach/detach a PMC and a process.  */
end_comment

begin_struct
struct|struct
name|pmc_op_pmcattach
block|{
name|pmc_id_t
name|pm_pmc
decl_stmt|;
comment|/* PMC to attach to */
name|pid_t
name|pm_pid
decl_stmt|;
comment|/* target process */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP PMCSETCOUNT  *  * Set the sampling rate (i.e., the reload count) for statistical counters.  * 'pm_pmcid' need to have been previously allocated using PMCALLOCATE.  */
end_comment

begin_struct
struct|struct
name|pmc_op_pmcsetcount
block|{
name|pmc_value_t
name|pm_count
decl_stmt|;
comment|/* initial/sample count */
name|pmc_id_t
name|pm_pmcid
decl_stmt|;
comment|/* PMC id to set */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP PMCRW  *  * Read the value of a PMC named by 'pm_pmcid'.  'pm_pmcid' needs  * to have been previously allocated using PMCALLOCATE.  */
end_comment

begin_struct
struct|struct
name|pmc_op_pmcrw
block|{
name|uint32_t
name|pm_flags
decl_stmt|;
comment|/* PMC_F_{OLD,NEW}VALUE*/
name|pmc_id_t
name|pm_pmcid
decl_stmt|;
comment|/* pmc id */
name|pmc_value_t
name|pm_value
decl_stmt|;
comment|/* new&returned value */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP GETPMCINFO  *  * retrieve PMC state for a named CPU.  The caller is expected to  * allocate 'npmc' * 'struct pmc_info' bytes of space for the return  * values.  */
end_comment

begin_struct
struct|struct
name|pmc_info
block|{
name|uint32_t
name|pm_caps
decl_stmt|;
comment|/* counter capabilities */
name|enum
name|pmc_class
name|pm_class
decl_stmt|;
comment|/* enum pmc_class */
name|int
name|pm_enabled
decl_stmt|;
comment|/* whether enabled */
name|enum
name|pmc_event
name|pm_event
decl_stmt|;
comment|/* current event */
name|uint32_t
name|pm_flags
decl_stmt|;
comment|/* counter flags */
name|enum
name|pmc_mode
name|pm_mode
decl_stmt|;
comment|/* current mode [enum pmc_mode] */
name|pid_t
name|pm_ownerpid
decl_stmt|;
comment|/* owner, or -1 */
name|pmc_value_t
name|pm_reloadcount
decl_stmt|;
comment|/* sampling counters only */
name|enum
name|pmc_disp
name|pm_rowdisp
decl_stmt|;
comment|/* FREE, THREAD or STANDLONE */
name|uint32_t
name|pm_width
decl_stmt|;
comment|/* width of the PMC */
name|char
name|pm_name
index|[
name|PMC_NAME_MAX
index|]
decl_stmt|;
comment|/* pmc name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmc_op_getpmcinfo
block|{
name|int32_t
name|pm_cpu
decl_stmt|;
comment|/* 0<= cpu< mp_maxid */
name|struct
name|pmc_info
name|pm_pmcs
index|[]
decl_stmt|;
comment|/* space for 'npmc' structures */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP GETCPUINFO  *  * Retrieve system CPU information.  */
end_comment

begin_struct
struct|struct
name|pmc_op_getcpuinfo
block|{
name|enum
name|pmc_cputype
name|pm_cputype
decl_stmt|;
comment|/* what kind of CPU */
name|uint32_t
name|pm_nclass
decl_stmt|;
comment|/* #classes of PMCs */
name|uint32_t
name|pm_ncpu
decl_stmt|;
comment|/* number of CPUs */
name|uint32_t
name|pm_npmc
decl_stmt|;
comment|/* #PMCs per CPU */
name|enum
name|pmc_class
name|pm_classes
index|[
name|PMC_CLASS_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP CONFIGURELOG  *  * Configure a log file for writing system-wide statistics to.  */
end_comment

begin_struct
struct|struct
name|pmc_op_configurelog
block|{
name|int
name|pm_flags
decl_stmt|;
name|int
name|pm_logfd
decl_stmt|;
comment|/* logfile fd (or -1) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP GETDRIVERSTATS  *  * Retrieve pmc(4) driver-wide statistics.  */
end_comment

begin_struct
struct|struct
name|pmc_op_getdriverstats
block|{
name|int
name|pm_intr_ignored
decl_stmt|;
comment|/* #interrupts ignored */
name|int
name|pm_intr_processed
decl_stmt|;
comment|/* #interrupts processed */
name|int
name|pm_syscalls
decl_stmt|;
comment|/* #syscalls */
name|int
name|pm_syscall_errors
decl_stmt|;
comment|/* #syscalls with errors */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP RELEASE / OP START / OP STOP  *  * Simple operations on a PMC id.  */
end_comment

begin_struct
struct|struct
name|pmc_op_simple
block|{
name|pmc_id_t
name|pm_pmcid
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|__i386__
operator|||
name|__amd64__
end_if

begin_comment
comment|/*  * OP X86_GETMSR  *  * Retrieve the model specific register assoicated with the  * allocated PMC.  This number can be used subsequently with  * RDPMC instructions.  */
end_comment

begin_struct
struct|struct
name|pmc_op_x86_getmsr
block|{
name|uint32_t
name|pm_msr
decl_stmt|;
comment|/* MSR for the PMC */
name|pmc_id_t
name|pm_pmcid
decl_stmt|;
comment|/* allocated pmc id */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_define
define|#
directive|define
name|PMC_REQUEST_POOL_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|PMC_HASH_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|PMC_PCPU_BUFFER_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|PMC_MTXPOOL_SIZE
value|32
end_define

begin_comment
comment|/*  * PMC commands  */
end_comment

begin_struct
struct|struct
name|pmc_syscall_args
block|{
name|uint32_t
name|pmop_code
decl_stmt|;
comment|/* one of PMC_OP_* */
name|void
modifier|*
name|pmop_data
decl_stmt|;
comment|/* syscall parameter */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interface to processor specific s1tuff  */
end_comment

begin_comment
comment|/*  * struct pmc_descr  *  * Machine independent (i.e., the common parts) of a human readable  * PMC description.  */
end_comment

begin_struct
struct|struct
name|pmc_descr
block|{
specifier|const
name|char
name|pd_name
index|[
name|PMC_NAME_MAX
index|]
decl_stmt|;
comment|/* name */
name|uint32_t
name|pd_caps
decl_stmt|;
comment|/* capabilities */
name|enum
name|pmc_class
name|pd_class
decl_stmt|;
comment|/* class of the PMC */
name|uint32_t
name|pd_width
decl_stmt|;
comment|/* width in bits */
block|}
struct|;
end_struct

begin_comment
comment|/*  * struct pmc_target  *  * This structure records all the target processes associated with a  * PMC.  */
end_comment

begin_struct
struct|struct
name|pmc_target
block|{
name|LIST_ENTRY
argument_list|(
argument|pmc_target
argument_list|)
name|pt_next
expr_stmt|;
name|struct
name|pmc_process
modifier|*
name|pt_process
decl_stmt|;
comment|/* target descriptor */
block|}
struct|;
end_struct

begin_comment
comment|/*  * struct pmc  *  * Describes each allocated PMC.  *  * Each PMC has precisely one owner, namely the process that allocated  * the PMC.  *  * Multiple target process may be being monitored by a PMC.  The  * 'pm_targets' field links all the target processes being monitored  * by this PMC.  *  * The 'pm_savedvalue' field is protected by a mutex.  *  * On a multi-cpu machine, multiple target threads associated with a  * process-virtual PMC could be concurrently executing on different  * CPUs.  The 'pm_runcount' field is atomically incremented every time  * the PMC gets scheduled on a CPU and atomically decremented when it  * get descheduled.  Deletion of a PMC is only permitted when this  * field is '0'.  *  */
end_comment

begin_struct
struct|struct
name|pmc
block|{
name|LIST_HEAD
argument_list|(
argument_list|,
argument|pmc_target
argument_list|)
name|pm_targets
expr_stmt|;
comment|/* list of target processes */
comment|/* 	 * Global PMCs are allocated on a CPU and are not moved around. 	 * For global PMCs we need to record the CPU the PMC was allocated 	 * on. 	 * 	 * Virtual PMCs run on whichever CPU is currently executing 	 * their owner threads.  For these PMCs we need to save their 	 * current PMC counter values when they are taken off CPU. 	 */
union|union
block|{
name|uint32_t
name|pm_cpu
decl_stmt|;
comment|/* System-wide PMCs */
name|pmc_value_t
name|pm_savedvalue
decl_stmt|;
comment|/* Virtual PMCS */
block|}
name|pm_gv
union|;
comment|/* 	 * for sampling modes, we keep track of the PMC's "reload 	 * count", which is the counter value to be loaded in when 	 * arming the PMC for the next counting session.  For counting 	 * modes on PMCs that are read-only (e.g., the x86 TSC), we 	 * keep track of the initial value at the start of 	 * counting-mode operation. 	 */
union|union
block|{
name|pmc_value_t
name|pm_reloadcount
decl_stmt|;
comment|/* sampling PMC modes */
name|pmc_value_t
name|pm_initial
decl_stmt|;
comment|/* counting PMC modes */
block|}
name|pm_sc
union|;
name|uint32_t
name|pm_caps
decl_stmt|;
comment|/* PMC capabilities */
name|enum
name|pmc_class
name|pm_class
decl_stmt|;
comment|/* class of PMC */
name|enum
name|pmc_event
name|pm_event
decl_stmt|;
comment|/* event being measured */
name|uint32_t
name|pm_flags
decl_stmt|;
comment|/* additional flags PMC_F_... */
name|enum
name|pmc_mode
name|pm_mode
decl_stmt|;
comment|/* current mode */
name|struct
name|pmc_owner
modifier|*
name|pm_owner
decl_stmt|;
comment|/* owner thread state */
name|uint32_t
name|pm_rowindex
decl_stmt|;
comment|/* row index */
name|uint32_t
name|pm_runcount
decl_stmt|;
comment|/* #cpus currently on */
name|enum
name|pmc_state
name|pm_state
decl_stmt|;
comment|/* state (active/inactive only) */
comment|/* md extensions */
if|#
directive|if
name|__i386__
union|union
block|{
comment|/* AMD Athlon counters */
struct|struct
block|{
name|uint32_t
name|pm_amd_evsel
decl_stmt|;
block|}
name|pm_amd
struct|;
comment|/* Intel P4 counters */
struct|struct
block|{
name|uint32_t
name|pm_p4_cccrvalue
decl_stmt|;
name|uint32_t
name|pm_p4_escrvalue
decl_stmt|;
name|uint32_t
name|pm_p4_escr
decl_stmt|;
name|uint32_t
name|pm_p4_escrmsr
decl_stmt|;
block|}
name|pm_p4
struct|;
comment|/* Intel P6 counters */
struct|struct
block|{
name|uint32_t
name|pm_p6_evsel
decl_stmt|;
block|}
name|pm_p6
struct|;
block|}
name|pm_md
union|;
elif|#
directive|elif
name|__amd64__
union|union
block|{
comment|/* AMD Athlon counters */
struct|struct
block|{
name|uint32_t
name|pm_amd_evsel
decl_stmt|;
block|}
name|pm_amd
struct|;
block|}
name|pm_md
union|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * struct pmc_list  *  * Describes a list of PMCs.  */
end_comment

begin_struct
struct|struct
name|pmc_list
block|{
name|LIST_ENTRY
argument_list|(
argument|pmc_list
argument_list|)
name|pl_next
expr_stmt|;
name|struct
name|pmc
modifier|*
name|pl_pmc
decl_stmt|;
comment|/* PMC descriptor */
block|}
struct|;
end_struct

begin_comment
comment|/*  * struct pmc_process  *  * Record a 'target' process being profiled.  *  * The target process being profiled could be different from the owner  * process which allocated the PMCs.  Each target process descriptor  * is associated with NHWPMC 'struct pmc *' pointers.  Each PMC at a  * given hardware row-index 'n' will use slot 'n' of the 'pp_pmcs[]'  * array.  The size of this structure is thus PMC architecture  * dependent.  *  * TODO: Only process-private counting mode PMCs may be attached to a  * process different from the allocator process (since we do not have  * the infrastructure to make sense of an interrupted PC value from a  * 'target' process (yet)).  *  */
end_comment

begin_struct
struct|struct
name|pmc_targetstate
block|{
name|struct
name|pmc
modifier|*
name|pp_pmc
decl_stmt|;
comment|/* target PMC */
name|pmc_value_t
name|pp_pmcval
decl_stmt|;
comment|/* per-process value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmc_process
block|{
name|LIST_ENTRY
argument_list|(
argument|pmc_process
argument_list|)
name|pp_next
expr_stmt|;
comment|/* hash chain */
name|int
name|pp_refcnt
decl_stmt|;
comment|/* reference count */
name|uint32_t
name|pp_flags
decl_stmt|;
comment|/* flags */
name|struct
name|proc
modifier|*
name|pp_proc
decl_stmt|;
comment|/* target thread */
name|struct
name|pmc_targetstate
name|pp_pmcs
index|[]
decl_stmt|;
comment|/* NHWPMCs */
block|}
struct|;
end_struct

begin_comment
comment|/*  * struct pmc_owner  *  * We associate a PMC with an 'owner' process.  *  * A process can be associated with 0..NCPUS*NHWPMC PMCs during its  * lifetime, where NCPUS is the numbers of CPUS in the system and  * NHWPMC is the number of hardware PMCs per CPU.  These are  * maintained in the list headed by the 'po_pmcs' to save on space.  *  */
end_comment

begin_struct
struct|struct
name|pmc_owner
block|{
name|LIST_ENTRY
argument_list|(
argument|pmc_owner
argument_list|)
name|po_next
expr_stmt|;
comment|/* hash chain */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|pmc_list
argument_list|)
name|po_pmcs
expr_stmt|;
comment|/* list of owned PMCs */
name|uint32_t
name|po_flags
decl_stmt|;
comment|/* PMC_FLAG_* */
name|struct
name|proc
modifier|*
name|po_owner
decl_stmt|;
comment|/* owner proc */
name|int
name|po_logfd
decl_stmt|;
comment|/* XXX for now */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PMC_FLAG_IS_OWNER
value|0x01
end_define

begin_define
define|#
directive|define
name|PMC_FLAG_HAS_TS_PMC
value|0x02
end_define

begin_define
define|#
directive|define
name|PMC_FLAG_OWNS_LOGFILE
value|0x04
end_define

begin_define
define|#
directive|define
name|PMC_FLAG_ENABLE_MSR_ACCESS
value|0x08
end_define

begin_comment
comment|/*  * struct pmc_hw -- describe the state of the PMC hardware  *  * When in use, a HW PMC is associated with one allocated 'struct pmc'  * pointed to by field 'phw_pmc'.  When inactive, this field is NULL.  *  * On an SMP box, one or more HW PMC's in process virtual mode with  * the same 'phw_pmc' could be executing on different CPUs.  In order  * to handle this case correctly, we need to ensure that only  * incremental counts get added to the saved value in the associated  * 'struct pmc'.  The 'phw_save' field is used to keep the saved PMC  * value at the time the hardware is started during this context  * switch (i.e., the difference between the new (hardware) count and  * the saved count is atomically added to the count field in 'struct  * pmc' at context switch time).  *  */
end_comment

begin_struct
struct|struct
name|pmc_hw
block|{
name|uint32_t
name|phw_state
decl_stmt|;
comment|/* see PHW_* macros below */
name|struct
name|pmc
modifier|*
name|phw_pmc
decl_stmt|;
comment|/* current thread PMC */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PMC_PHW_RI_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|PMC_PHW_CPU_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PMC_PHW_CPU_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|PMC_PHW_FLAGS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PMC_PHW_FLAGS_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|PMC_PHW_INDEX_TO_STATE
parameter_list|(
name|ri
parameter_list|)
value|((ri)& PMC_PHW_RI_MASK)
end_define

begin_define
define|#
directive|define
name|PMC_PHW_STATE_TO_INDEX
parameter_list|(
name|state
parameter_list|)
value|((state)& PMC_PHW_RI_MASK)
end_define

begin_define
define|#
directive|define
name|PMC_PHW_CPU_TO_STATE
parameter_list|(
name|cpu
parameter_list|)
value|(((cpu)<< PMC_PHW_CPU_SHIFT)& \ 	PMC_PHW_CPU_MASK)
end_define

begin_define
define|#
directive|define
name|PMC_PHW_STATE_TO_CPU
parameter_list|(
name|state
parameter_list|)
value|(((state)& PMC_PHW_CPU_MASK)>> \ 	PMC_PHW_CPU_SHIFT)
end_define

begin_define
define|#
directive|define
name|PMC_PHW_FLAGS_TO_STATE
parameter_list|(
name|flags
parameter_list|)
value|(((flags)<< PMC_PHW_FLAGS_SHIFT)& \ 	PMC_PHW_FLAGS_MASK)
end_define

begin_define
define|#
directive|define
name|PMC_PHW_STATE_TO_FLAGS
parameter_list|(
name|state
parameter_list|)
value|(((state)& PMC_PHW_FLAGS_MASK)>> \ 	PMC_PHW_FLAGS_SHIFT)
end_define

begin_define
define|#
directive|define
name|PMC_PHW_FLAG_IS_ENABLED
value|(PMC_PHW_FLAGS_TO_STATE(0x01))
end_define

begin_define
define|#
directive|define
name|PMC_PHW_FLAG_IS_SHAREABLE
value|(PMC_PHW_FLAGS_TO_STATE(0x02))
end_define

begin_comment
comment|/*  * struct pmc_cpustate  *  * A CPU is modelled as a collection of HW PMCs with space for additional  * flags.  */
end_comment

begin_struct
struct|struct
name|pmc_cpu
block|{
name|uint32_t
name|pc_state
decl_stmt|;
comment|/* physical cpu number + flags */
name|struct
name|pmc_hw
modifier|*
name|pc_hwpmcs
index|[]
decl_stmt|;
comment|/* 'npmc' pointers */
comment|/* other machine dependent fields come here */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PMC_PCPU_CPU_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|PMC_PCPU_FLAGS_MASK
value|0xFFFFFF00
end_define

begin_define
define|#
directive|define
name|PMC_PCPU_FLAGS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PMC_PCPU_STATE_TO_CPU
parameter_list|(
name|S
parameter_list|)
value|((S)& PMC_PCPU_CPU_MASK)
end_define

begin_define
define|#
directive|define
name|PMC_PCPU_STATE_TO_FLAGS
parameter_list|(
name|S
parameter_list|)
value|(((S)& PMC_PCPU_FLAGS_MASK)>> PMC_PCPU_FLAGS_SHIFT)
end_define

begin_define
define|#
directive|define
name|PMC_PCPU_FLAGS_TO_STATE
parameter_list|(
name|F
parameter_list|)
value|(((F)<< PMC_PCPU_FLAGS_SHIFT)& PMC_PCPU_FLAGS_MASK)
end_define

begin_define
define|#
directive|define
name|PMC_PCPU_CPU_TO_STATE
parameter_list|(
name|C
parameter_list|)
value|((C)& PMC_PCPU_CPU_MASK)
end_define

begin_define
define|#
directive|define
name|PMC_PCPU_FLAG_HTT
value|(PMC_PCPU_FLAGS_TO_STATE(0x1))
end_define

begin_comment
comment|/*  * struct pmc_binding  *  * CPU binding information.  */
end_comment

begin_struct
struct|struct
name|pmc_binding
block|{
name|int
name|pb_bound
decl_stmt|;
comment|/* is bound? */
name|int
name|pb_cpu
decl_stmt|;
comment|/* if so, to which CPU */
block|}
struct|;
end_struct

begin_comment
comment|/*  * struct pmc_mdep  *  * Machine dependent bits needed per CPU type.  */
end_comment

begin_struct
struct|struct
name|pmc_mdep
block|{
name|enum
name|pmc_class
name|pmd_classes
index|[
name|PMC_CLASS_MAX
index|]
decl_stmt|;
name|int
name|pmd_nclasspmcs
index|[
name|PMC_CLASS_MAX
index|]
decl_stmt|;
name|uint32_t
name|pmd_cputype
decl_stmt|;
comment|/* from enum pmc_cputype */
name|uint32_t
name|pmd_nclass
decl_stmt|;
comment|/* # PMC classes supported */
name|uint32_t
name|pmd_npmc
decl_stmt|;
comment|/* max PMCs per CPU */
comment|/* 	 * Methods 	 */
name|int
function_decl|(
modifier|*
name|pmd_init
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|)
function_decl|;
comment|/* machine dependent initialization */
name|int
function_decl|(
modifier|*
name|pmd_cleanup
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|)
function_decl|;
comment|/* machine dependent cleanup  */
comment|/* thread context switch in/out */
name|int
function_decl|(
modifier|*
name|pmd_switch_in
function_decl|)
parameter_list|(
name|struct
name|pmc_cpu
modifier|*
name|_p
parameter_list|,
name|struct
name|pmc_process
modifier|*
name|_pp
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pmd_switch_out
function_decl|)
parameter_list|(
name|struct
name|pmc_cpu
modifier|*
name|_p
parameter_list|,
name|struct
name|pmc_process
modifier|*
name|_pp
parameter_list|)
function_decl|;
comment|/* configuring/reading/writing the hardware PMCs */
name|int
function_decl|(
modifier|*
name|pmd_config_pmc
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|,
name|struct
name|pmc
modifier|*
name|_pm
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pmd_read_pmc
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|,
name|pmc_value_t
modifier|*
name|_value
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pmd_write_pmc
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|,
name|pmc_value_t
name|_value
parameter_list|)
function_decl|;
comment|/* pmc allocation/release */
name|int
function_decl|(
modifier|*
name|pmd_allocate_pmc
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|,
name|struct
name|pmc
modifier|*
name|_t
parameter_list|,
specifier|const
name|struct
name|pmc_op_pmcallocate
modifier|*
name|_a
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pmd_release_pmc
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|,
name|struct
name|pmc
modifier|*
name|_pm
parameter_list|)
function_decl|;
comment|/* starting and stopping PMCs */
name|int
function_decl|(
modifier|*
name|pmd_start_pmc
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pmd_stop_pmc
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|)
function_decl|;
comment|/* handle a PMC interrupt */
name|int
function_decl|(
modifier|*
name|pmd_intr
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|uintptr_t
name|_pc
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pmd_describe
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|,
name|struct
name|pmc_info
modifier|*
name|_pi
parameter_list|,
name|struct
name|pmc
modifier|*
modifier|*
name|_ppmc
parameter_list|)
function_decl|;
comment|/* Machine dependent methods */
if|#
directive|if
name|__i386__
operator|||
name|__amd64__
name|int
function_decl|(
modifier|*
name|pmd_get_msr
function_decl|)
parameter_list|(
name|int
name|_ri
parameter_list|,
name|uint32_t
modifier|*
name|_msr
parameter_list|)
function_decl|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-CPU state.  This is an array of 'mp_ncpu' pointers  * to struct pmc_cpu descriptors.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pmc_cpu
modifier|*
modifier|*
name|pmc_pcpu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver statistics */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pmc_op_getdriverstats
name|pmc_stats
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|DEBUG
end_if

begin_comment
comment|/* debug flags */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|pmc_debugflags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* [Maj:12bits] [Min:16bits] [level:4] */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_DEFAULT_FLAGS
value|0
end_define

begin_define
define|#
directive|define
name|PMC_DEBUG_STRSIZE
value|128
end_define

begin_define
define|#
directive|define
name|__PMCDFMAJ
parameter_list|(
name|M
parameter_list|)
value|(1<< (PMC_DEBUG_MAJ_##M+20))
end_define

begin_define
define|#
directive|define
name|__PMCDFMIN
parameter_list|(
name|M
parameter_list|)
value|(1<< (PMC_DEBUG_MIN_##M+4))
end_define

begin_define
define|#
directive|define
name|__PMCDF
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|)
value|(__PMCDFMAJ(M) | __PMCDFMIN(N))
end_define

begin_define
define|#
directive|define
name|PMCDBG
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|,
name|L
parameter_list|,
name|F
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 	if (((pmc_debugflags& __PMCDF(M,N)) == __PMCDF(M,N))&&	\ 	    ((pmc_debugflags& 0xF)> (L)))				\ 		printf(#M ":" #N ": " F "\n", __VA_ARGS__);		\ } while (0)
end_define

begin_comment
comment|/* Major numbers */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MAJ_MOD
value|0
end_define

begin_comment
comment|/* misc module infrastructure */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MAJ_PMC
value|1
end_define

begin_comment
comment|/* pmc management */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MAJ_CTX
value|2
end_define

begin_comment
comment|/* context switches */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MAJ_OWN
value|3
end_define

begin_comment
comment|/* owner */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MAJ_PRC
value|4
end_define

begin_comment
comment|/* processes */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MAJ_MDP
value|5
end_define

begin_comment
comment|/* machine dependent */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MAJ_CPU
value|6
end_define

begin_comment
comment|/* cpu switches */
end_comment

begin_comment
comment|/* Minor numbers */
end_comment

begin_comment
comment|/* Common (8 bits) */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_ALL
value|0
end_define

begin_comment
comment|/* allocation */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_REL
value|1
end_define

begin_comment
comment|/* release */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_OPS
value|2
end_define

begin_comment
comment|/* ops: start, stop, ... */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_INI
value|3
end_define

begin_comment
comment|/* init */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_FND
value|4
end_define

begin_comment
comment|/* find */
end_comment

begin_comment
comment|/* MODULE */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_PMH
value|14
end_define

begin_comment
comment|/* pmc_hook */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_PMS
value|15
end_define

begin_comment
comment|/* pmc_syscall */
end_comment

begin_comment
comment|/* OWN */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_ORM
value|8
end_define

begin_comment
comment|/* owner remove */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_OMR
value|9
end_define

begin_comment
comment|/* owner maybe remove */
end_comment

begin_comment
comment|/* PROCESSES */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_TLK
value|8
end_define

begin_comment
comment|/* link target */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_TUL
value|9
end_define

begin_comment
comment|/* unlink target */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_EXT
value|10
end_define

begin_comment
comment|/* process exit */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_EXC
value|11
end_define

begin_comment
comment|/* process exec */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_FRK
value|12
end_define

begin_comment
comment|/* process fork */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_ATT
value|13
end_define

begin_comment
comment|/* attach/detach */
end_comment

begin_comment
comment|/* CONTEXT SWITCHES */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_SWI
value|8
end_define

begin_comment
comment|/* switch in */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_SWO
value|9
end_define

begin_comment
comment|/* switch out */
end_comment

begin_comment
comment|/* PMC */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_REG
value|8
end_define

begin_comment
comment|/* pmc register */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_ALR
value|9
end_define

begin_comment
comment|/* allocate row */
end_comment

begin_comment
comment|/* MACHINE DEPENDENT LAYER */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_REA
value|8
end_define

begin_comment
comment|/* read */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_WRI
value|9
end_define

begin_comment
comment|/* write */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_CFG
value|10
end_define

begin_comment
comment|/* config */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_STA
value|11
end_define

begin_comment
comment|/* start */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_STO
value|12
end_define

begin_comment
comment|/* stop */
end_comment

begin_comment
comment|/* CPU */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_BND
value|8
end_define

begin_comment
comment|/* bind */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_SEL
value|9
end_define

begin_comment
comment|/* select */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PMCDBG
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|,
name|L
parameter_list|,
name|F
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* declare a dedicated memory pool */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_PMC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Functions  */
end_comment

begin_function_decl
name|void
name|pmc_update_histogram
parameter_list|(
name|struct
name|pmc_hw
modifier|*
name|phw
parameter_list|,
name|uintptr_t
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmc_send_signal
parameter_list|(
name|struct
name|pmc
modifier|*
name|pmc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_getrowdisp
parameter_list|(
name|int
name|ri
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_PMC_H_ */
end_comment

end_unit

