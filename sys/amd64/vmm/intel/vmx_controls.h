begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMX_CONTROLS_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMX_CONTROLS_H_
end_define

begin_comment
comment|/* Pin-Based VM-Execution Controls */
end_comment

begin_define
define|#
directive|define
name|PINBASED_EXTINT_EXITING
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PINBASED_NMI_EXITING
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|PINBASED_VIRTUAL_NMI
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PINBASED_PREMPTION_TIMER
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|PINBASED_POSTED_INTERRUPT
value|(1<< 7)
end_define

begin_comment
comment|/* Primary Processor-Based VM-Execution Controls */
end_comment

begin_define
define|#
directive|define
name|PROCBASED_INT_WINDOW_EXITING
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|PROCBASED_TSC_OFFSET
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|PROCBASED_HLT_EXITING
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|PROCBASED_INVLPG_EXITING
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|PROCBASED_MWAIT_EXITING
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|PROCBASED_RDPMC_EXITING
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|PROCBASED_RDTSC_EXITING
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|PROCBASED_CR3_LOAD_EXITING
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|PROCBASED_CR3_STORE_EXITING
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|PROCBASED_CR8_LOAD_EXITING
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|PROCBASED_CR8_STORE_EXITING
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|PROCBASED_USE_TPR_SHADOW
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|PROCBASED_NMI_WINDOW_EXITING
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|PROCBASED_MOV_DR_EXITING
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|PROCBASED_IO_EXITING
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|PROCBASED_IO_BITMAPS
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|PROCBASED_MTF
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|PROCBASED_MSR_BITMAPS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|PROCBASED_MONITOR_EXITING
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|PROCBASED_PAUSE_EXITING
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|PROCBASED_SECONDARY_CONTROLS
value|(1U<< 31)
end_define

begin_comment
comment|/* Secondary Processor-Based VM-Execution Controls */
end_comment

begin_define
define|#
directive|define
name|PROCBASED2_VIRTUALIZE_APIC_ACCESSES
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PROCBASED2_ENABLE_EPT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|PROCBASED2_DESC_TABLE_EXITING
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|PROCBASED2_ENABLE_RDTSCP
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|PROCBASED2_VIRTUALIZE_X2APIC_MODE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|PROCBASED2_ENABLE_VPID
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PROCBASED2_WBINVD_EXITING
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|PROCBASED2_UNRESTRICTED_GUEST
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|PROCBASED2_APIC_REGISTER_VIRTUALIZATION
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|PROCBASED2_VIRTUAL_INTERRUPT_DELIVERY
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|PROCBASED2_PAUSE_LOOP_EXITING
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|PROCBASED2_ENABLE_INVPCID
value|(1<< 12)
end_define

begin_comment
comment|/* VM Exit Controls */
end_comment

begin_define
define|#
directive|define
name|VM_EXIT_SAVE_DEBUG_CONTROLS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|VM_EXIT_HOST_LMA
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|VM_EXIT_LOAD_PERF_GLOBAL_CTRL
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|VM_EXIT_ACKNOWLEDGE_INTERRUPT
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|VM_EXIT_SAVE_PAT
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|VM_EXIT_LOAD_PAT
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|VM_EXIT_SAVE_EFER
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|VM_EXIT_LOAD_EFER
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|VM_EXIT_SAVE_PREEMPTION_TIMER
value|(1<< 22)
end_define

begin_comment
comment|/* VM Entry Controls */
end_comment

begin_define
define|#
directive|define
name|VM_ENTRY_LOAD_DEBUG_CONTROLS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|VM_ENTRY_GUEST_LMA
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|VM_ENTRY_INTO_SMM
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|VM_ENTRY_DEACTIVATE_DUAL_MONITOR
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|VM_ENTRY_LOAD_PERF_GLOBAL_CTRL
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|VM_ENTRY_LOAD_PAT
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|VM_ENTRY_LOAD_EFER
value|(1<< 15)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

