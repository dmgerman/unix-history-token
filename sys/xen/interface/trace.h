begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * include/public/trace.h  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Mark Williamson, (C) 2004 Intel Research Cambridge  * Copyright (C) 2005 Bin Ren  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_TRACE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_TRACE_H__
end_define

begin_comment
comment|/* Trace classes */
end_comment

begin_define
define|#
directive|define
name|TRC_CLS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TRC_GEN
value|0x0001f000
end_define

begin_comment
comment|/* General trace            */
end_comment

begin_define
define|#
directive|define
name|TRC_SCHED
value|0x0002f000
end_define

begin_comment
comment|/* Xen Scheduler trace      */
end_comment

begin_define
define|#
directive|define
name|TRC_DOM0OP
value|0x0004f000
end_define

begin_comment
comment|/* Xen DOM0 operation trace */
end_comment

begin_define
define|#
directive|define
name|TRC_HVM
value|0x0008f000
end_define

begin_comment
comment|/* Xen HVM trace            */
end_comment

begin_define
define|#
directive|define
name|TRC_MEM
value|0x0010f000
end_define

begin_comment
comment|/* Xen memory trace         */
end_comment

begin_define
define|#
directive|define
name|TRC_ALL
value|0xfffff000
end_define

begin_comment
comment|/* Trace subclasses */
end_comment

begin_define
define|#
directive|define
name|TRC_SUBCLS_SHIFT
value|12
end_define

begin_comment
comment|/* trace subclasses for SVM */
end_comment

begin_define
define|#
directive|define
name|TRC_HVM_ENTRYEXIT
value|0x00081000
end_define

begin_comment
comment|/* VMENTRY and #VMEXIT       */
end_comment

begin_define
define|#
directive|define
name|TRC_HVM_HANDLER
value|0x00082000
end_define

begin_comment
comment|/* various HVM handlers      */
end_comment

begin_comment
comment|/* Trace events per class */
end_comment

begin_define
define|#
directive|define
name|TRC_LOST_RECORDS
value|(TRC_GEN + 1)
end_define

begin_define
define|#
directive|define
name|TRC_SCHED_DOM_ADD
value|(TRC_SCHED +  1)
end_define

begin_define
define|#
directive|define
name|TRC_SCHED_DOM_REM
value|(TRC_SCHED +  2)
end_define

begin_define
define|#
directive|define
name|TRC_SCHED_SLEEP
value|(TRC_SCHED +  3)
end_define

begin_define
define|#
directive|define
name|TRC_SCHED_WAKE
value|(TRC_SCHED +  4)
end_define

begin_define
define|#
directive|define
name|TRC_SCHED_YIELD
value|(TRC_SCHED +  5)
end_define

begin_define
define|#
directive|define
name|TRC_SCHED_BLOCK
value|(TRC_SCHED +  6)
end_define

begin_define
define|#
directive|define
name|TRC_SCHED_SHUTDOWN
value|(TRC_SCHED +  7)
end_define

begin_define
define|#
directive|define
name|TRC_SCHED_CTL
value|(TRC_SCHED +  8)
end_define

begin_define
define|#
directive|define
name|TRC_SCHED_ADJDOM
value|(TRC_SCHED +  9)
end_define

begin_define
define|#
directive|define
name|TRC_SCHED_SWITCH
value|(TRC_SCHED + 10)
end_define

begin_define
define|#
directive|define
name|TRC_SCHED_S_TIMER_FN
value|(TRC_SCHED + 11)
end_define

begin_define
define|#
directive|define
name|TRC_SCHED_T_TIMER_FN
value|(TRC_SCHED + 12)
end_define

begin_define
define|#
directive|define
name|TRC_SCHED_DOM_TIMER_FN
value|(TRC_SCHED + 13)
end_define

begin_define
define|#
directive|define
name|TRC_SCHED_SWITCH_INFPREV
value|(TRC_SCHED + 14)
end_define

begin_define
define|#
directive|define
name|TRC_SCHED_SWITCH_INFNEXT
value|(TRC_SCHED + 15)
end_define

begin_define
define|#
directive|define
name|TRC_MEM_PAGE_GRANT_MAP
value|(TRC_MEM + 1)
end_define

begin_define
define|#
directive|define
name|TRC_MEM_PAGE_GRANT_UNMAP
value|(TRC_MEM + 2)
end_define

begin_define
define|#
directive|define
name|TRC_MEM_PAGE_GRANT_TRANSFER
value|(TRC_MEM + 3)
end_define

begin_comment
comment|/* trace events per subclass */
end_comment

begin_define
define|#
directive|define
name|TRC_HVM_VMENTRY
value|(TRC_HVM_ENTRYEXIT + 0x01)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_VMEXIT
value|(TRC_HVM_ENTRYEXIT + 0x02)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_PF_XEN
value|(TRC_HVM_HANDLER + 0x01)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_PF_INJECT
value|(TRC_HVM_HANDLER + 0x02)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_INJ_EXC
value|(TRC_HVM_HANDLER + 0x03)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_INJ_VIRQ
value|(TRC_HVM_HANDLER + 0x04)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_REINJ_VIRQ
value|(TRC_HVM_HANDLER + 0x05)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_IO_READ
value|(TRC_HVM_HANDLER + 0x06)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_IO_WRITE
value|(TRC_HVM_HANDLER + 0x07)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_CR_READ
value|(TRC_HVM_HANDLER + 0x08)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_CR_WRITE
value|(TRC_HVM_HANDLER + 0x09)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_DR_READ
value|(TRC_HVM_HANDLER + 0x0A)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_DR_WRITE
value|(TRC_HVM_HANDLER + 0x0B)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_MSR_READ
value|(TRC_HVM_HANDLER + 0x0C)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_MSR_WRITE
value|(TRC_HVM_HANDLER + 0x0D)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_CPUID
value|(TRC_HVM_HANDLER + 0x0E)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_INTR
value|(TRC_HVM_HANDLER + 0x0F)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_NMI
value|(TRC_HVM_HANDLER + 0x10)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_SMI
value|(TRC_HVM_HANDLER + 0x11)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_VMMCALL
value|(TRC_HVM_HANDLER + 0x12)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_HLT
value|(TRC_HVM_HANDLER + 0x13)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_INVLPG
value|(TRC_HVM_HANDLER + 0x14)
end_define

begin_define
define|#
directive|define
name|TRC_HVM_MCE
value|(TRC_HVM_HANDLER + 0x15)
end_define

begin_comment
comment|/* This structure represents a single trace buffer record. */
end_comment

begin_struct
struct|struct
name|t_rec
block|{
name|uint64_t
name|cycles
decl_stmt|;
comment|/* cycle counter timestamp */
name|uint32_t
name|event
decl_stmt|;
comment|/* event ID                */
name|unsigned
name|long
name|data
index|[
literal|5
index|]
decl_stmt|;
comment|/* event data items        */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure contains the metadata for a single trace buffer.  The head  * field, indexes into an array of struct t_rec's.  */
end_comment

begin_struct
struct|struct
name|t_buf
block|{
name|uint32_t
name|cons
decl_stmt|;
comment|/* Next item to be consumed by control tools. */
name|uint32_t
name|prod
decl_stmt|;
comment|/* Next item to be produced by Xen.           */
comment|/* 'nr_recs' records follow immediately after the meta-data header.    */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_TRACE_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

