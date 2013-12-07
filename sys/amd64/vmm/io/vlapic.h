begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VLAPIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_VLAPIC_H_
end_define

begin_struct_decl
struct_decl|struct
name|vm
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Map of APIC Registers:       Offset  Description          		 	Access  */
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ID
value|0x20
end_define

begin_comment
comment|// Local APIC ID               		R/W
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_VER
value|0x30
end_define

begin_comment
comment|// Local APIC Version              	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_TPR
value|0x80
end_define

begin_comment
comment|// Task Priority Register          	R/W
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_APR
value|0x90
end_define

begin_comment
comment|// Arbitration Priority Register   	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_PPR
value|0xA0
end_define

begin_comment
comment|// Processor Priority Register     	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_EOI
value|0xB0
end_define

begin_comment
comment|// EOI Register                    	W
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_RRR
value|0xC0
end_define

begin_comment
comment|// Remote read                     	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_LDR
value|0xD0
end_define

begin_comment
comment|// Logical Destination             	R/W
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_DFR
value|0xE0
end_define

begin_comment
comment|// Destination Format Register     	0..27 R;  28..31 R/W
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_SVR
value|0xF0
end_define

begin_comment
comment|// Spurious Interrupt Vector Reg.  	0..3  R;  4..9   R/W
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ISR0
value|0x100
end_define

begin_comment
comment|// ISR  000-031                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ISR1
value|0x110
end_define

begin_comment
comment|// ISR  032-063                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ISR2
value|0x120
end_define

begin_comment
comment|// ISR  064-095                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ISR3
value|0x130
end_define

begin_comment
comment|// ISR  095-128                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ISR4
value|0x140
end_define

begin_comment
comment|// ISR  128-159                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ISR5
value|0x150
end_define

begin_comment
comment|// ISR  160-191                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ISR6
value|0x160
end_define

begin_comment
comment|// ISR  192-223                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ISR7
value|0x170
end_define

begin_comment
comment|// ISR  224-255                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_TMR0
value|0x180
end_define

begin_comment
comment|// TMR  000-031                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_TMR1
value|0x190
end_define

begin_comment
comment|// TMR  032-063                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_TMR2
value|0x1A0
end_define

begin_comment
comment|// TMR  064-095                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_TMR3
value|0x1B0
end_define

begin_comment
comment|// TMR  095-128                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_TMR4
value|0x1C0
end_define

begin_comment
comment|// TMR  128-159                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_TMR5
value|0x1D0
end_define

begin_comment
comment|// TMR  160-191                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_TMR6
value|0x1E0
end_define

begin_comment
comment|// TMR  192-223                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_TMR7
value|0x1F0
end_define

begin_comment
comment|// TMR  224-255                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_IRR0
value|0x200
end_define

begin_comment
comment|// IRR  000-031                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_IRR1
value|0x210
end_define

begin_comment
comment|// IRR  032-063                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_IRR2
value|0x220
end_define

begin_comment
comment|// IRR  064-095                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_IRR3
value|0x230
end_define

begin_comment
comment|// IRR  095-128                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_IRR4
value|0x240
end_define

begin_comment
comment|// IRR  128-159                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_IRR5
value|0x250
end_define

begin_comment
comment|// IRR  160-191                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_IRR6
value|0x260
end_define

begin_comment
comment|// IRR  192-223                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_IRR7
value|0x270
end_define

begin_comment
comment|// IRR  224-255                    	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ESR
value|0x280
end_define

begin_comment
comment|// Error Status Register           	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ICR_LOW
value|0x300
end_define

begin_comment
comment|// Interrupt Command Reg. (0-31)   	R/W
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ICR_HI
value|0x310
end_define

begin_comment
comment|// Interrupt Command Reg. (32-63)  	R/W
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_TIMER_LVT
value|0x320
end_define

begin_comment
comment|// Local Vector Table (Timer)      	R/W
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_THERM_LVT
value|0x330
end_define

begin_comment
comment|// Local Vector Table (Thermal)    	R/W (PIV+)
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_PERF_LVT
value|0x340
end_define

begin_comment
comment|// Local Vector Table (Performance) 	R/W (P6+)
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_LINT0_LVT
value|0x350
end_define

begin_comment
comment|// Local Vector Table (LINT0)      	R/W
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_LINT1_LVT
value|0x360
end_define

begin_comment
comment|// Local Vector Table (LINT1)      	R/W
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ERROR_LVT
value|0x370
end_define

begin_comment
comment|// Local Vector Table (ERROR)      	R/W
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_ICR
value|0x380
end_define

begin_comment
comment|// Initial Count Reg. for Timer    	R/W
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_CCR
value|0x390
end_define

begin_comment
comment|// Current Count of Timer          	R
end_comment

begin_define
define|#
directive|define
name|APIC_OFFSET_DCR
value|0x3E0
end_define

begin_comment
comment|// Timer Divide Configuration Reg. 	R/W
end_comment

begin_comment
comment|/*  * 16 priority levels with at most one vector injected per level.  */
end_comment

begin_define
define|#
directive|define
name|ISRVEC_STK_SIZE
value|(16 + 1)
end_define

begin_enum_decl
enum_decl|enum
name|x2apic_state
enum_decl|;
end_enum_decl

begin_function_decl
name|struct
name|vlapic
modifier|*
name|vlapic_init
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|int
name|vcpuid
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

begin_function_decl
name|int
name|vlapic_write
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|uint64_t
name|offset
parameter_list|,
name|uint64_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vlapic_read
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|uint64_t
name|offset
parameter_list|,
name|uint64_t
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vlapic_pending_intr
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
name|vlapic_intr_accepted
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|int
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vlapic_set_intr_ready
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|int
name|vector
parameter_list|,
name|bool
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|vlapic_get_apicbase
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
name|vlapic_set_apicbase
parameter_list|(
name|struct
name|vlapic
modifier|*
name|vlapic
parameter_list|,
name|uint64_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vlapic_set_x2apic_state
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|int
name|vcpuid
parameter_list|,
name|enum
name|x2apic_state
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|vlapic_enabled
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
comment|/* _VLAPIC_H_ */
end_comment

end_unit

