begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   MCA/PMI/INIT Protocol as defined in PI Specification VOLUME 4.    This protocol provides services to handle Machine Checks (MCA),   Initialization (INIT) events, and Platform Management Interrupt (PMI) events   on an Intel Itanium Processor Family based system.    Copyright (c) 2009 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MCA_INIT_PMI_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__MCA_INIT_PMI_PROTOCOL_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the MCA/PMI/INIT Protocol.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_MCA_INIT_PMI_PROTOCOL_GUID
define|\
value|{ 0xb60dc6e8, 0x3b6f, 0x11d5, {0xaf, 0x9, 0x0, 0xa0, 0xc9, 0x44, 0xa0, 0x5b} }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Declare forward reference for the Timer Architectural Protocol
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_SAL_MCA_INIT_PMI_PROTOCOL
name|EFI_SAL_MCA_INIT_PMI_PROTOCOL
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// MCA Records Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|First
range|:
literal|1
decl_stmt|;
name|UINT64
name|Last
range|:
literal|1
decl_stmt|;
name|UINT64
name|EntryCount
range|:
literal|16
decl_stmt|;
name|UINT64
name|DispatchedCount
range|:
literal|16
decl_stmt|;
name|UINT64
name|Reserved
range|:
literal|30
decl_stmt|;
block|}
name|SAL_MCA_COUNT_STRUCTURE
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/**   Prototype of MCA handler.    @param  ModuleGlobal                The context of MCA Handler   @param  ProcessorStateParameters    The processor state parameters (PSP)   @param  MinstateBase                Base address of the min-state   @param  RendezvouseStateInformation Rendezvous state information to be passed to                                       the OS on OS MCA entry   @param  CpuIndex                    Index of the logical processor   @param  McaCountStructure           Pointer to the MCA records structure   @param  CorrectedMachineCheck       This flag is set to TRUE is the MCA has been                                       corrected by the handler or by a previous handler    @retval EFI_SUCCESS                 Handler successfully returned  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SAL_MCA_HANDLER
function_decl|)
parameter_list|(
name|IN
name|VOID
modifier|*
name|ModuleGlobal
parameter_list|,
name|IN
name|UINT64
name|ProcessorStateParameters
parameter_list|,
name|IN
name|EFI_PHYSICAL_ADDRESS
name|MinstateBase
parameter_list|,
name|IN
name|UINT64
name|RendezvouseStateInformation
parameter_list|,
name|IN
name|UINT64
name|CpuIndex
parameter_list|,
name|IN
name|SAL_MCA_COUNT_STRUCTURE
modifier|*
name|McaCountStructure
parameter_list|,
name|OUT
name|BOOLEAN
modifier|*
name|CorrectedMachineCheck
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Prototype of INIT handler.    @param  ModuleGlobal                The context of INIT Handler   @param  ProcessorStateParameters    The processor state parameters (PSP)   @param  MinstateBase                Base address of the min-state   @param  McaInProgress               This flag indicates if an MCA is in progress   @param  CpuIndex                    Index of the logical processor   @param  McaCountStructure           Pointer to the MCA records structure   @param  DumpSwitchPressed           This flag indicates the crash dump switch has been pressed    @retval EFI_SUCCESS                 Handler successfully returned  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SAL_INIT_HANDLER
function_decl|)
parameter_list|(
name|IN
name|VOID
modifier|*
name|ModuleGlobal
parameter_list|,
name|IN
name|UINT64
name|ProcessorStateParameters
parameter_list|,
name|IN
name|EFI_PHYSICAL_ADDRESS
name|MinstateBase
parameter_list|,
name|IN
name|BOOLEAN
name|McaInProgress
parameter_list|,
name|IN
name|UINT64
name|CpuIndex
parameter_list|,
name|IN
name|SAL_MCA_COUNT_STRUCTURE
modifier|*
name|McaCountStructure
parameter_list|,
name|OUT
name|BOOLEAN
modifier|*
name|DumpSwitchPressed
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Prototype of PMI handler    @param  ModuleGlobal                The context of PMI Handler   @param  CpuIndex                    Index of the logical processor   @param  PmiVector                   The PMI vector number as received from the PALE_PMI exit state (GR24)    @retval EFI_SUCCESS                 Handler successfully returned  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SAL_PMI_HANDLER
function_decl|)
parameter_list|(
name|IN
name|VOID
modifier|*
name|ModuleGlobal
parameter_list|,
name|IN
name|UINT64
name|CpuIndex
parameter_list|,
name|IN
name|UINT64
name|PmiVector
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Register a MCA handler with the MCA dispatcher.    @param  This                        The EFI_SAL_MCA_INIT_PMI_PROTOCOL instance   @param  McaHandler                  The MCA handler to register   @param  ModuleGlobal                The context of MCA Handler   @param  MakeFirst                   This flag specifies the handler should be made first in the list   @param  MakeLast                    This flag specifies the handler should be made last in the list    @retval EFI_SUCCESS                 MCA Handle was registered   @retval EFI_OUT_OF_RESOURCES        No more resources to register an MCA handler   @retval EFI_INVALID_PARAMETER       Invalid parameters were passed  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SAL_REGISTER_MCA_HANDLER
function_decl|)
parameter_list|(
name|IN
name|EFI_SAL_MCA_INIT_PMI_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SAL_MCA_HANDLER
name|McaHandler
parameter_list|,
name|IN
name|VOID
modifier|*
name|ModuleGlobal
parameter_list|,
name|IN
name|BOOLEAN
name|MakeFirst
parameter_list|,
name|IN
name|BOOLEAN
name|MakeLast
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Register an INIT handler with the INIT dispatcher.    @param  This                        The EFI_SAL_MCA_INIT_PMI_PROTOCOL instance   @param  InitHandler                 The INIT handler to register   @param  ModuleGlobal                The context of INIT Handler   @param  MakeFirst                   This flag specifies the handler should be made first in the list   @param  MakeLast                    This flag specifies the handler should be made last in the list    @retval EFI_SUCCESS                 INIT Handle was registered   @retval EFI_OUT_OF_RESOURCES        No more resources to register an INIT handler   @retval EFI_INVALID_PARAMETER       Invalid parameters were passed  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SAL_REGISTER_INIT_HANDLER
function_decl|)
parameter_list|(
name|IN
name|EFI_SAL_MCA_INIT_PMI_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SAL_INIT_HANDLER
name|InitHandler
parameter_list|,
name|IN
name|VOID
modifier|*
name|ModuleGlobal
parameter_list|,
name|IN
name|BOOLEAN
name|MakeFirst
parameter_list|,
name|IN
name|BOOLEAN
name|MakeLast
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Register a PMI handler with the PMI dispatcher.    @param  This                        The EFI_SAL_MCA_INIT_PMI_PROTOCOL instance   @param  PmiHandler                  The PMI handler to register   @param  ModuleGlobal                The context of PMI Handler   @param  MakeFirst                   This flag specifies the handler should be made first in the list   @param  MakeLast                    This flag specifies the handler should be made last in the list    @retval EFI_SUCCESS                 PMI Handle was registered   @retval EFI_OUT_OF_RESOURCES        No more resources to register an PMI handler   @retval EFI_INVALID_PARAMETER       Invalid parameters were passed  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SAL_REGISTER_PMI_HANDLER
function_decl|)
parameter_list|(
name|IN
name|EFI_SAL_MCA_INIT_PMI_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SAL_PMI_HANDLER
name|PmiHandler
parameter_list|,
name|IN
name|VOID
modifier|*
name|ModuleGlobal
parameter_list|,
name|IN
name|BOOLEAN
name|MakeFirst
parameter_list|,
name|IN
name|BOOLEAN
name|MakeLast
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol is used to register MCA, INIT and PMI handlers with their respective dispatcher
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SAL_MCA_INIT_PMI_PROTOCOL
block|{
name|EFI_SAL_REGISTER_MCA_HANDLER
name|RegisterMcaHandler
decl_stmt|;
name|EFI_SAL_REGISTER_INIT_HANDLER
name|RegisterInitHandler
decl_stmt|;
name|EFI_SAL_REGISTER_PMI_HANDLER
name|RegisterPmiHandler
decl_stmt|;
name|BOOLEAN
name|McaInProgress
decl_stmt|;
comment|///< Whether MCA handler is in progress
name|BOOLEAN
name|InitInProgress
decl_stmt|;
comment|///< Whether Init handler is in progress
name|BOOLEAN
name|PmiInProgress
decl_stmt|;
comment|///< Whether Pmi handler is in progress
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSalMcaInitPmiProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

