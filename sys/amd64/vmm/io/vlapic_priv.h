begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Neel Natu<neel@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VLAPIC_PRIV_H_
end_ifndef

begin_define
define|#
directive|define
name|_VLAPIC_PRIV_H_
end_define

begin_comment
comment|/*  * APIC Register:		Offset	   Description  */
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ID
value|0x20
end_define

begin_comment
comment|/* Local APIC ID		*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_VER
value|0x30
end_define

begin_comment
comment|/* Local APIC Version		*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_TPR
value|0x80
end_define

begin_comment
comment|/* Task Priority Register	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_APR
value|0x90
end_define

begin_comment
comment|/* Arbitration Priority		*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_PPR
value|0xA0
end_define

begin_comment
comment|/* Processor Priority Register	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_EOI
value|0xB0
end_define

begin_comment
comment|/* EOI Register			*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_RRR
value|0xC0
end_define

begin_comment
comment|/* Remote read			*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_LDR
value|0xD0
end_define

begin_comment
comment|/* Logical Destination		*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_DFR
value|0xE0
end_define

begin_comment
comment|/* Destination Format Register	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_SVR
value|0xF0
end_define

begin_comment
comment|/* Spurious Vector Register	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ISR0
value|0x100
end_define

begin_comment
comment|/* In Service Register		*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ISR1
value|0x110
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_ISR2
value|0x120
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_ISR3
value|0x130
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_ISR4
value|0x140
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_ISR5
value|0x150
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_ISR6
value|0x160
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_ISR7
value|0x170
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_TMR0
value|0x180
end_define

begin_comment
comment|/* Trigger Mode Register	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_TMR1
value|0x190
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_TMR2
value|0x1A0
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_TMR3
value|0x1B0
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_TMR4
value|0x1C0
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_TMR5
value|0x1D0
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_TMR6
value|0x1E0
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_TMR7
value|0x1F0
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_IRR0
value|0x200
end_define

begin_comment
comment|/* Interrupt Request Register	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_IRR1
value|0x210
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_IRR2
value|0x220
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_IRR3
value|0x230
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_IRR4
value|0x240
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_IRR5
value|0x250
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_IRR6
value|0x260
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_IRR7
value|0x270
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_ESR
value|0x280
end_define

begin_comment
comment|/* Error Status Register	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_CMCI_LVT
value|0x2F0
end_define

begin_comment
comment|/* Local Vector Table (CMCI)	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ICR_LOW
value|0x300
end_define

begin_comment
comment|/* Interrupt Command Register	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ICR_HI
value|0x310
end_define

begin_define
define|#
directive|define
name|APIC_OFFSET_TIMER_LVT
value|0x320
end_define

begin_comment
comment|/* Local Vector Table (Timer)	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_THERM_LVT
value|0x330
end_define

begin_comment
comment|/* Local Vector Table (Thermal)	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_PERF_LVT
value|0x340
end_define

begin_comment
comment|/* Local Vector Table (PMC)	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_LINT0_LVT
value|0x350
end_define

begin_comment
comment|/* Local Vector Table (LINT0)	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_LINT1_LVT
value|0x360
end_define

begin_comment
comment|/* Local Vector Table (LINT1)	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ERROR_LVT
value|0x370
end_define

begin_comment
comment|/* Local Vector Table (ERROR)	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_TIMER_ICR
value|0x380
end_define

begin_comment
comment|/* Timer's Initial Count	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_TIMER_CCR
value|0x390
end_define

begin_comment
comment|/* Timer's Current Count	*/
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_TIMER_DCR
value|0x3E0
end_define

begin_comment
comment|/* Timer's Divide Configuration	*/
end_comment

begin_enum
enum|enum
name|boot_state
block|{
name|BS_INIT
block|,
name|BS_SIPI
block|,
name|BS_RUNNING
block|}
enum|;
end_enum

begin_comment
comment|/*  * 16 priority levels with at most one vector injected per level.  */
end_comment

begin_define
define|#
directive|define
name|ISRVEC_STK_SIZE
value|(16 + 1)
end_define

begin_struct
struct|struct
name|vlapic
block|{
name|struct
name|vm
modifier|*
name|vm
decl_stmt|;
name|int
name|vcpuid
decl_stmt|;
name|struct
name|LAPIC
modifier|*
name|apic_page
decl_stmt|;
name|uint32_t
name|esr_pending
decl_stmt|;
name|int
name|esr_firing
decl_stmt|;
name|struct
name|callout
name|callout
decl_stmt|;
comment|/* vlapic timer */
name|struct
name|bintime
name|timer_fire_bt
decl_stmt|;
comment|/* callout expiry time */
name|struct
name|bintime
name|timer_freq_bt
decl_stmt|;
comment|/* timer frequency */
name|struct
name|bintime
name|timer_period_bt
decl_stmt|;
comment|/* timer period */
name|struct
name|mtx
name|timer_mtx
decl_stmt|;
comment|/* 	 * The 'isrvec_stk' is a stack of vectors injected by the local apic. 	 * A vector is popped from the stack when the processor does an EOI. 	 * The vector on the top of the stack is used to compute the 	 * Processor Priority in conjunction with the TPR. 	 */
name|uint8_t
name|isrvec_stk
index|[
name|ISRVEC_STK_SIZE
index|]
decl_stmt|;
name|int
name|isrvec_stk_top
decl_stmt|;
name|uint64_t
name|msr_apicbase
decl_stmt|;
name|enum
name|boot_state
name|boot_state
decl_stmt|;
name|uint32_t
name|svr_last
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|vlapic_init
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vlapic_cleanup
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VLAPIC_PRIV_H_ */
end_comment

end_unit

