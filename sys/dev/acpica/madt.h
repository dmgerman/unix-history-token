begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MADT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MADT_H_
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_define
define|#
directive|define
name|APIC_INTERRUPT_SOURCE_OVERRIDE
value|2
end_define

begin_define
define|#
directive|define
name|APIC_NMI
value|3
end_define

begin_define
define|#
directive|define
name|APIC_LOCAL_APIC_NMI
value|4
end_define

begin_define
define|#
directive|define
name|APIC_LOCAL_APIC_OVERRIDE
value|5
end_define

begin_define
define|#
directive|define
name|APIC_IO_SAPIC
value|6
end_define

begin_define
define|#
directive|define
name|APIC_LOCAL_SAPIC
value|7
end_define

begin_define
define|#
directive|define
name|APIC_PLATFORM_INTERRUPT
value|8
end_define

begin_define
define|#
directive|define
name|APIC_POLARITY_CONFORM
value|0
end_define

begin_define
define|#
directive|define
name|APIC_POLARITY_ACTIVEHI
value|1
end_define

begin_define
define|#
directive|define
name|APIC_POLARITY_ACTIVELO
value|3
end_define

begin_define
define|#
directive|define
name|APIC_TRIGGER_CONFORM
value|0
end_define

begin_define
define|#
directive|define
name|APIC_TRIGGER_EDGE
value|1
end_define

begin_define
define|#
directive|define
name|APIC_TRIGGER_LEVEL
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
comment|/* Interrupt Source Override */
block|{
name|APIC_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Bus
decl_stmt|;
name|UINT8
name|Source
decl_stmt|;
name|UINT32
name|GlobalSystemInterrupt
decl_stmt|;
name|UINT16
name|Polarity
range|:
literal|2
decl_stmt|;
comment|/* Polarity of input signal */
name|UINT16
name|TriggerMode
range|:
literal|2
decl_stmt|;
comment|/* Trigger mode of input signal */
name|UINT16
name|Reserved1
range|:
literal|12
decl_stmt|;
block|}
name|INTERRUPT_SOURCE_OVERRIDE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* NMI */
block|{
name|APIC_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Polarity
range|:
literal|2
decl_stmt|;
comment|/* Polarity of input signal */
name|UINT16
name|TriggerMode
range|:
literal|2
decl_stmt|;
comment|/* Trigger mode of input signal */
name|UINT16
name|Reserved1
range|:
literal|12
decl_stmt|;
name|UINT32
name|GlobalSystemInterrupt
decl_stmt|;
block|}
name|NMI
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* LOCAL APIC NMI */
block|{
name|APIC_HEADER
name|Header
decl_stmt|;
name|UINT8
name|ProcessorApicId
decl_stmt|;
comment|/* ACPI processor id */
name|UINT16
name|Polarity
range|:
literal|2
decl_stmt|;
comment|/* Polarity of input signal */
name|UINT16
name|TriggerMode
range|:
literal|2
decl_stmt|;
comment|/* Trigger mode of input signal */
name|UINT16
name|Reserved1
range|:
literal|12
decl_stmt|;
name|UINT8
name|LINTPin
decl_stmt|;
block|}
name|LAPIC_NMI
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* LOCAL APIC OVERRIDE */
block|{
name|APIC_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT64
name|LocalApicAddress
decl_stmt|;
block|}
name|LAPIC_OVERRIDE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* IO SAPIC */
block|{
name|APIC_HEADER
name|Header
decl_stmt|;
name|UINT8
name|IoSapicId
decl_stmt|;
comment|/* I/O SAPIC ID */
name|UINT8
name|Reserved
decl_stmt|;
comment|/* reserved - must be zero */
name|UINT32
name|Vector
decl_stmt|;
comment|/* interrupt base */
name|UINT64
name|IoSapicAddress
decl_stmt|;
comment|/* SAPIC's physical address */
block|}
name|IO_SAPIC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* LOCAL SAPIC */
block|{
name|APIC_HEADER
name|Header
decl_stmt|;
name|UINT8
name|ProcessorId
decl_stmt|;
comment|/* ACPI processor id */
name|UINT8
name|LocalSapicId
decl_stmt|;
comment|/* Processor local SAPIC id */
name|UINT8
name|LocalSapicEid
decl_stmt|;
comment|/* Processor local SAPIC eid */
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
name|UINT32
name|ProcessorEnabled
range|:
literal|1
decl_stmt|;
name|UINT32
name|FlagsReserved
range|:
literal|31
decl_stmt|;
block|}
name|LOCAL_SAPIC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* PLATFORM INTERRUPT SOURCE */
block|{
name|APIC_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Polarity
range|:
literal|2
decl_stmt|;
comment|/* Polarity of input signal */
name|UINT16
name|TriggerMode
range|:
literal|2
decl_stmt|;
comment|/* Trigger mode of input signal */
name|UINT16
name|Reserved1
range|:
literal|12
decl_stmt|;
name|UINT8
name|InterruptType
decl_stmt|;
comment|/* 1-PMI, 2-INIT, 3-Error */
name|UINT8
name|ProcessorId
decl_stmt|;
comment|/* Processor ID of destination */
name|UINT8
name|ProcessorEid
decl_stmt|;
comment|/* Processor EID of destination */
name|UINT8
name|IoSapicVector
decl_stmt|;
comment|/* Value for redirection table */
name|UINT32
name|GlobalSystemInterrupt
decl_stmt|;
comment|/* Global System Interrupt */
name|UINT32
name|Reserved2
decl_stmt|;
block|}
name|PLATFORM_INTERRUPT_SOURCE
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MADT_H_ */
end_comment

end_unit

