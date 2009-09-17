begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_HVM_PARAMS_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_HVM_PARAMS_H__
end_define

begin_include
include|#
directive|include
file|<xen/interface/hvm/hvm_op.h>
end_include

begin_comment
comment|/*  * Parameter space for HVMOP_{set,get}_param.  */
end_comment

begin_comment
comment|/*  * How should CPU0 event-channel notifications be delivered?  * val[63:56] == 0: val[55:0] is a delivery GSI (Global System Interrupt).  * val[63:56] == 1: val[55:0] is a delivery PCI INTx line, as follows:  *                  Domain = val[47:32], Bus  = val[31:16],  *                  DevFn  = val[15: 8], IntX = val[ 1: 0]  * If val == 0 then CPU0 event-channel notifications are not delivered.  */
end_comment

begin_define
define|#
directive|define
name|HVM_PARAM_CALLBACK_IRQ
value|0
end_define

begin_comment
comment|/*  * These are not used by Xen. They are here for convenience of HVM-guest  * xenbus implementations.  */
end_comment

begin_define
define|#
directive|define
name|HVM_PARAM_STORE_PFN
value|1
end_define

begin_define
define|#
directive|define
name|HVM_PARAM_STORE_EVTCHN
value|2
end_define

begin_define
define|#
directive|define
name|HVM_PARAM_PAE_ENABLED
value|4
end_define

begin_define
define|#
directive|define
name|HVM_PARAM_IOREQ_PFN
value|5
end_define

begin_define
define|#
directive|define
name|HVM_PARAM_BUFIOREQ_PFN
value|6
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__ia64__
end_ifdef

begin_define
define|#
directive|define
name|HVM_PARAM_NVRAM_FD
value|7
end_define

begin_define
define|#
directive|define
name|HVM_PARAM_VHPT_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|HVM_PARAM_BUFPIOREQ_PFN
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Set mode for virtual timers (currently x86 only):  *  delay_for_missed_ticks (default):  *   Do not advance a vcpu's time beyond the correct delivery time for  *   interrupts that have been missed due to preemption. Deliver missed  *   interrupts when the vcpu is rescheduled and advance the vcpu's virtual  *   time stepwise for each one.  *  no_delay_for_missed_ticks:  *   As above, missed interrupts are delivered, but guest time always tracks  *   wallclock (i.e., real) time while doing so.  *  no_missed_ticks_pending:  *   No missed interrupts are held pending. Instead, to ensure ticks are  *   delivered at some non-zero rate, if we detect missed ticks then the  *   internal tick alarm is not disabled if the VCPU is preempted during the  *   next tick period.  *  one_missed_tick_pending:  *   Missed interrupts are collapsed together and delivered as one 'late tick'.  *   Guest time always tracks wallclock (i.e., real) time.  */
end_comment

begin_define
define|#
directive|define
name|HVM_PARAM_TIMER_MODE
value|10
end_define

begin_define
define|#
directive|define
name|HVMPTM_delay_for_missed_ticks
value|0
end_define

begin_define
define|#
directive|define
name|HVMPTM_no_delay_for_missed_ticks
value|1
end_define

begin_define
define|#
directive|define
name|HVMPTM_no_missed_ticks_pending
value|2
end_define

begin_define
define|#
directive|define
name|HVMPTM_one_missed_tick_pending
value|3
end_define

begin_comment
comment|/* Boolean: Enable virtual HPET (high-precision event timer)? (x86-only) */
end_comment

begin_define
define|#
directive|define
name|HVM_PARAM_HPET_ENABLED
value|11
end_define

begin_comment
comment|/* Identity-map page directory used by Intel EPT when CR0.PG=0. */
end_comment

begin_define
define|#
directive|define
name|HVM_PARAM_IDENT_PT
value|12
end_define

begin_comment
comment|/* Device Model domain, defaults to 0. */
end_comment

begin_define
define|#
directive|define
name|HVM_PARAM_DM_DOMAIN
value|13
end_define

begin_comment
comment|/* ACPI S state: currently support S0 and S3 on x86. */
end_comment

begin_define
define|#
directive|define
name|HVM_PARAM_ACPI_S_STATE
value|14
end_define

begin_define
define|#
directive|define
name|HVM_NR_PARAMS
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_HVM_PARAMS_H__ */
end_comment

end_unit

