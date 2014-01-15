begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: achware.h -- hardware specific interfaces  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACHWARE_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACHWARE_H__
end_define

begin_comment
comment|/* Values for the _SST predefined method */
end_comment

begin_define
define|#
directive|define
name|ACPI_SST_INDICATOR_OFF
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_SST_WORKING
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_SST_WAKING
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_SST_SLEEPING
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_SST_SLEEP_CONTEXT
value|4
end_define

begin_comment
comment|/*  * hwacpi - high level functions  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiHwSetMode
parameter_list|(
name|UINT32
name|Mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiHwGetMode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * hwregs - ACPI Register I/O  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiHwValidateRegister
parameter_list|(
name|ACPI_GENERIC_ADDRESS
modifier|*
name|Reg
parameter_list|,
name|UINT8
name|MaxBitWidth
parameter_list|,
name|UINT64
modifier|*
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwRead
parameter_list|(
name|UINT32
modifier|*
name|Value
parameter_list|,
name|ACPI_GENERIC_ADDRESS
modifier|*
name|Reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwWrite
parameter_list|(
name|UINT32
name|Value
parameter_list|,
name|ACPI_GENERIC_ADDRESS
modifier|*
name|Reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_BIT_REGISTER_INFO
modifier|*
name|AcpiHwGetBitRegisterInfo
parameter_list|(
name|UINT32
name|RegisterId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwWritePm1Control
parameter_list|(
name|UINT32
name|Pm1aControl
parameter_list|,
name|UINT32
name|Pm1bControl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwRegisterRead
parameter_list|(
name|UINT32
name|RegisterId
parameter_list|,
name|UINT32
modifier|*
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwRegisterWrite
parameter_list|(
name|UINT32
name|RegisterId
parameter_list|,
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwClearAcpiStatus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * hwsleep - sleep/wake support (Legacy sleep registers)  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiHwLegacySleep
parameter_list|(
name|UINT8
name|SleepState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwLegacyWakePrep
parameter_list|(
name|UINT8
name|SleepState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwLegacyWake
parameter_list|(
name|UINT8
name|SleepState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * hwesleep - sleep/wake support (Extended FADT-V5 sleep registers)  */
end_comment

begin_function_decl
name|void
name|AcpiHwExecuteSleepMethod
parameter_list|(
name|char
modifier|*
name|MethodName
parameter_list|,
name|UINT32
name|IntegerArgument
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwExtendedSleep
parameter_list|(
name|UINT8
name|SleepState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwExtendedWakePrep
parameter_list|(
name|UINT8
name|SleepState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwExtendedWake
parameter_list|(
name|UINT8
name|SleepState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * hwvalid - Port I/O with validation  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiHwReadPort
parameter_list|(
name|ACPI_IO_ADDRESS
name|Address
parameter_list|,
name|UINT32
modifier|*
name|Value
parameter_list|,
name|UINT32
name|Width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwWritePort
parameter_list|(
name|ACPI_IO_ADDRESS
name|Address
parameter_list|,
name|UINT32
name|Value
parameter_list|,
name|UINT32
name|Width
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * hwgpe - GPE support  */
end_comment

begin_function_decl
name|UINT32
name|AcpiHwGetGpeRegisterBit
parameter_list|(
name|ACPI_GPE_EVENT_INFO
modifier|*
name|GpeEventInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwLowSetGpe
parameter_list|(
name|ACPI_GPE_EVENT_INFO
modifier|*
name|GpeEventInfo
parameter_list|,
name|UINT32
name|Action
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwDisableGpeBlock
parameter_list|(
name|ACPI_GPE_XRUPT_INFO
modifier|*
name|GpeXruptInfo
parameter_list|,
name|ACPI_GPE_BLOCK_INFO
modifier|*
name|GpeBlock
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwClearGpe
parameter_list|(
name|ACPI_GPE_EVENT_INFO
modifier|*
name|GpeEventInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwClearGpeBlock
parameter_list|(
name|ACPI_GPE_XRUPT_INFO
modifier|*
name|GpeXruptInfo
parameter_list|,
name|ACPI_GPE_BLOCK_INFO
modifier|*
name|GpeBlock
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwGetGpeStatus
parameter_list|(
name|ACPI_GPE_EVENT_INFO
modifier|*
name|GpeEventInfo
parameter_list|,
name|ACPI_EVENT_STATUS
modifier|*
name|EventStatus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwDisableAllGpes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwEnableAllRuntimeGpes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwEnableAllWakeupGpes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwEnableRuntimeGpeBlock
parameter_list|(
name|ACPI_GPE_XRUPT_INFO
modifier|*
name|GpeXruptInfo
parameter_list|,
name|ACPI_GPE_BLOCK_INFO
modifier|*
name|GpeBlock
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * hwpci - PCI configuration support  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiHwDerivePciId
parameter_list|(
name|ACPI_PCI_ID
modifier|*
name|PciId
parameter_list|,
name|ACPI_HANDLE
name|RootPciDevice
parameter_list|,
name|ACPI_HANDLE
name|PciRegion
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACHWARE_H__ */
end_comment

end_unit

