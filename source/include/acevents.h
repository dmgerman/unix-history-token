begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acevents.h - Event subcomponent prototypes and defines  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACEVENTS_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACEVENTS_H__
end_define

begin_comment
comment|/*  * evevent  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiEvInitializeEvents
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvInstallXruptHandlers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiEvFixedEventDetect
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * evmisc  */
end_comment

begin_function_decl
name|BOOLEAN
name|AcpiEvIsNotifyObject
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiEvGetGpeNumberIndex
parameter_list|(
name|UINT32
name|GpeNumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvQueueNotifyRequest
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|UINT32
name|NotifyValue
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * evglock - Global Lock support  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiEvInitGlobalLockHandler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_OK
argument_list|(
argument|ACPI_STATUS AcpiEvAcquireGlobalLock(     UINT16                  Timeout)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_OK
argument_list|(
argument|ACPI_STATUS AcpiEvReleaseGlobalLock(     void)
argument_list|)
end_macro

begin_function_decl
name|ACPI_STATUS
name|AcpiEvRemoveGlobalLockHandler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * evgpe - Low-level GPE support  */
end_comment

begin_function_decl
name|UINT32
name|AcpiEvGpeDetect
parameter_list|(
name|ACPI_GPE_XRUPT_INFO
modifier|*
name|GpeXruptList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvUpdateGpeEnableMask
parameter_list|(
name|ACPI_GPE_EVENT_INFO
modifier|*
name|GpeEventInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvEnableGpe
parameter_list|(
name|ACPI_GPE_EVENT_INFO
modifier|*
name|GpeEventInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvAddGpeReference
parameter_list|(
name|ACPI_GPE_EVENT_INFO
modifier|*
name|GpeEventInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvRemoveGpeReference
parameter_list|(
name|ACPI_GPE_EVENT_INFO
modifier|*
name|GpeEventInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_GPE_EVENT_INFO
modifier|*
name|AcpiEvGetGpeEventInfo
parameter_list|(
name|ACPI_HANDLE
name|GpeDevice
parameter_list|,
name|UINT32
name|GpeNumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_GPE_EVENT_INFO
modifier|*
name|AcpiEvLowGetGpeInfo
parameter_list|(
name|UINT32
name|GpeNumber
parameter_list|,
name|ACPI_GPE_BLOCK_INFO
modifier|*
name|GpeBlock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvFinishGpe
parameter_list|(
name|ACPI_GPE_EVENT_INFO
modifier|*
name|GpeEventInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * evgpeblk - Upper-level GPE block support  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiEvCreateGpeBlock
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|GpeDevice
parameter_list|,
name|UINT64
name|Address
parameter_list|,
name|UINT8
name|SpaceId
parameter_list|,
name|UINT32
name|RegisterCount
parameter_list|,
name|UINT16
name|GpeBlockBaseNumber
parameter_list|,
name|UINT32
name|InterruptNumber
parameter_list|,
name|ACPI_GPE_BLOCK_INFO
modifier|*
modifier|*
name|ReturnGpeBlock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvInitializeGpeBlock
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

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_OK
argument_list|(
argument|ACPI_STATUS AcpiEvDeleteGpeBlock (     ACPI_GPE_BLOCK_INFO     *GpeBlock)
argument_list|)
end_macro

begin_function_decl
name|UINT32
name|AcpiEvGpeDispatch
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|GpeDevice
parameter_list|,
name|ACPI_GPE_EVENT_INFO
modifier|*
name|GpeEventInfo
parameter_list|,
name|UINT32
name|GpeNumber
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * evgpeinit - GPE initialization and update  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiEvGpeInitialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_VOID
argument_list|(
argument|void AcpiEvUpdateGpes (     ACPI_OWNER_ID           TableOwnerId)
argument_list|)
end_macro

begin_function_decl
name|ACPI_STATUS
name|AcpiEvMatchGpeMethod
parameter_list|(
name|ACPI_HANDLE
name|ObjHandle
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|,
name|void
modifier|*
modifier|*
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * evgpeutil - GPE utilities  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiEvWalkGpeList
parameter_list|(
name|ACPI_GPE_CALLBACK
name|GpeWalkCallback
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiEvValidGpeEvent
parameter_list|(
name|ACPI_GPE_EVENT_INFO
modifier|*
name|GpeEventInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvGetGpeDevice
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
name|AcpiEvGetGpeXruptBlock
parameter_list|(
name|UINT32
name|InterruptNumber
parameter_list|,
name|ACPI_GPE_XRUPT_INFO
modifier|*
modifier|*
name|GpeXruptBlock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvDeleteGpeXrupt
parameter_list|(
name|ACPI_GPE_XRUPT_INFO
modifier|*
name|GpeXrupt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvDeleteGpeHandlers
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
comment|/*  * evhandler - Address space handling  */
end_comment

begin_function_decl
name|BOOLEAN
name|AcpiEvHasDefaultHandler
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_ADR_SPACE_TYPE
name|SpaceId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvInstallRegionHandlers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvInstallSpaceHandler
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_ADR_SPACE_TYPE
name|SpaceId
parameter_list|,
name|ACPI_ADR_SPACE_HANDLER
name|Handler
parameter_list|,
name|ACPI_ADR_SPACE_SETUP
name|Setup
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * evregion - Operation region support  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiEvInitializeOpRegions
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvAddressSpaceDispatch
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|RegionObj
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|FieldObj
parameter_list|,
name|UINT32
name|Function
parameter_list|,
name|UINT32
name|RegionOffset
parameter_list|,
name|UINT32
name|BitWidth
parameter_list|,
name|UINT64
modifier|*
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvAttachRegion
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|HandlerObj
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|RegionObj
parameter_list|,
name|BOOLEAN
name|AcpiNsIsLocked
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiEvDetachRegion
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|RegionObj
parameter_list|,
name|BOOLEAN
name|AcpiNsIsLocked
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvExecuteRegMethods
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_ADR_SPACE_TYPE
name|SpaceId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvExecuteRegMethod
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|RegionObj
parameter_list|,
name|UINT32
name|Function
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * evregini - Region initialization and setup  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiEvSystemMemoryRegionSetup
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|,
name|UINT32
name|Function
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvIoSpaceRegionSetup
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|,
name|UINT32
name|Function
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvPciConfigRegionSetup
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|,
name|UINT32
name|Function
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvCmosRegionSetup
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|,
name|UINT32
name|Function
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvPciBarRegionSetup
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|,
name|UINT32
name|Function
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvDefaultRegionSetup
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|,
name|UINT32
name|Function
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvInitializeRegion
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|RegionObj
parameter_list|,
name|BOOLEAN
name|AcpiNsLocked
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * evsci - SCI (System Control Interrupt) handling/dispatch  */
end_comment

begin_function_decl
name|UINT32
name|ACPI_SYSTEM_XFACE
name|AcpiEvGpeXruptHandler
parameter_list|(
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiEvSciDispatch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiEvInstallSciHandler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvRemoveAllSciHandlers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_VOID
argument_list|(
argument|void AcpiEvTerminate (     void)
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACEVENTS_H__  */
end_comment

end_unit

