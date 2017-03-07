begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Definition of Extended SAL Boot Service Protocol    The Extended SAL Boot Service Protocol provides a mechanisms for platform specific    drivers to update the SAL System Table and register Extended SAL Procedures that are   callable in physical or virtual mode using the SAL calling convention.    Copyright (c) 2009 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EXTENDED_SAL_BOOT_SERVICE_PROTOCOL_H_
end_ifndef

begin_define
define|#
directive|define
name|_EXTENDED_SAL_BOOT_SERVICE_PROTOCOL_H_
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Sal.h>
end_include

begin_define
define|#
directive|define
name|EXTENDED_SAL_BOOT_SERVICE_PROTOCOL_GUID
define|\
value|{ 0xde0ee9a4, 0x3c7a, 0x44f2, {0xb7, 0x8b, 0xe3, 0xcc, 0xd6, 0x9c, 0x3a, 0xf7 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EXTENDED_SAL_BOOT_SERVICE_PROTOCOL
name|EXTENDED_SAL_BOOT_SERVICE_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Adds platform specific information to the to the header of the SAL System Table.    @param  This                  A pointer to the EXTENDED_SAL_BOOT_SERVICE_PROTOCOL instance.   @param  SalAVersion           Version of recovery SAL PEIM(s) in BCD format. Higher byte contains                                 the major revision and the lower byte contains the minor revision.   @param  SalBVersion           Version of DXE SAL Driver in BCD format. Higher byte contains                                 the major revision and the lower byte contains the minor revision.   @param  OemId                 A pointer to a Null-terminated ASCII string that contains OEM unique string.                                 The string cannot be longer than 32 bytes in total length   @param  ProductId             A pointer to a Null-terminated ASCII string that uniquely identifies a family of                                  compatible products. The string cannot be longer than 32 bytes in total length.    @retval EFI_SUCCESS           The SAL System Table header was updated successfully.   @retval EFI_INVALID_PARAMETER OemId is NULL.   @retval EFI_INVALID_PARAMETER ProductId is NULL.   @retval EFI_INVALID_PARAMETER The length of OemId is greater than 32 characters.   @retval EFI_INVALID_PARAMETER The length of ProductId is greater than 32 characters.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EXTENDED_SAL_ADD_SST_INFO
function_decl|)
parameter_list|(
name|IN
name|EXTENDED_SAL_BOOT_SERVICE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT16
name|SalAVersion
parameter_list|,
name|IN
name|UINT16
name|SalBVersion
parameter_list|,
name|IN
name|CHAR8
modifier|*
name|OemId
parameter_list|,
name|IN
name|CHAR8
modifier|*
name|ProductId
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Adds an entry to the SAL System Table.    This function adds the SAL System Table Entry specified by TableEntry and EntrySize   to the SAL System Table.    @param  This         A pointer to the EXTENDED_SAL_BOOT_SERVICE_PROTOCOL instance.   @param  TableEntry   Pointer to a buffer containing a SAL System Table entry that is EntrySize bytes                         in length. The first byte of the TableEntry describes the type of entry.   @param  EntrySize    The size, in bytes, of TableEntry.    @retval EFI_SUCCESSThe        SAL System Table was updated successfully.   @retval EFI_INVALID_PARAMETER TableEntry is NULL.   @retval EFI_INVALID_PARAMETER TableEntry specifies an invalid entry type.   @retval EFI_INVALID_PARAMETER EntrySize is not valid for this type of entry.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EXTENDED_SAL_ADD_SST_ENTRY
function_decl|)
parameter_list|(
name|IN
name|EXTENDED_SAL_BOOT_SERVICE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
modifier|*
name|TableEntry
parameter_list|,
name|IN
name|UINTN
name|EntrySize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Internal ESAL procedures.    This is prototype of internal Extended SAL procedures, which is registerd by   EXTENDED_SAL_REGISTER_INTERNAL_PROC service.    @param  FunctionId         The Function ID associated with this Extended SAL Procedure.   @param  Arg2               Second argument to the Extended SAL procedure.   @param  Arg3               Third argument to the Extended SAL procedure.   @param  Arg4               Fourth argument to the Extended SAL procedure.   @param  Arg5               Fifth argument to the Extended SAL procedure.   @param  Arg6               Sixth argument to the Extended SAL procedure.   @param  Arg7               Seventh argument to the Extended SAL procedure.   @param  Arg8               Eighth argument to the Extended SAL procedure.   @param  VirtualMode        TRUE if the Extended SAL Procedure is being invoked in virtual mode.                              FALSE if the Extended SAL Procedure is being invoked in physical mode.   @param  ModuleGlobal       A pointer to the global context associated with this Extended SAL Procedure.     @return The result returned from the specified Extended SAL Procedure  **/
end_comment

begin_typedef
typedef|typedef
name|SAL_RETURN_REGS
function_decl|(
name|EFIAPI
modifier|*
name|SAL_INTERNAL_EXTENDED_SAL_PROC
function_decl|)
parameter_list|(
name|IN
name|UINT64
name|FunctionId
parameter_list|,
name|IN
name|UINT64
name|Arg2
parameter_list|,
name|IN
name|UINT64
name|Arg3
parameter_list|,
name|IN
name|UINT64
name|Arg4
parameter_list|,
name|IN
name|UINT64
name|Arg5
parameter_list|,
name|IN
name|UINT64
name|Arg6
parameter_list|,
name|IN
name|UINT64
name|Arg7
parameter_list|,
name|IN
name|UINT64
name|Arg8
parameter_list|,
name|IN
name|BOOLEAN
name|VirtualMode
parameter_list|,
name|IN
name|VOID
modifier|*
name|ModuleGlobal
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Registers an Extended SAL Procedure.    The Extended SAL Procedure specified by InternalSalProc and named by ClassGuidLo,   ClassGuidHi, and FunctionId is added to the set of available Extended SAL Procedures.    @param  This                   A pointer to the EXTENDED_SAL_BOOT_SERVICE_PROTOCOL instance.   @param  ClassGuidLo            The lower 64-bits of  the class GUID for the Extended SAL Procedure being added.                                    Each class GUID contains one or more functions specified by a Function ID.   @param  ClassGuidHi            The upper 64-bits of  the class GUID for the Extended SAL Procedure being added.                                    Each class GUID contains one or more functions specified by a Function ID.   @param  FunctionId             The Function ID for the Extended SAL Procedure that is being added.  This Function                                   ID is a member of the Extended SAL Procedure class specified by ClassGuidLo                                   and ClassGuidHi.   @param  InternalSalProc        A pointer to the Extended SAL Procedure being added.   @param  PhysicalModuleGlobal   Pointer to a  module global structure. This is a physical mode pointer.                                  This pointer is passed to the Extended SAL Procedure specified by ClassGuidLo,                                   ClassGuidHi, FunctionId, and InternalSalProc.  If the system is in physical mode,                                  then this pointer is passed unmodified to InternalSalProc.  If the system is in                                  virtual mode, then the virtual address associated with this pointer is passed to                                  InternalSalProc.    @retval EFI_SUCCESS            The Extended SAL Procedure was added.   @retval EFI_OUT_OF_RESOURCES   There are not enough resources available to add the Extended SAL Procedure.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EXTENDED_SAL_REGISTER_INTERNAL_PROC
function_decl|)
parameter_list|(
name|IN
name|EXTENDED_SAL_BOOT_SERVICE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|ClassGuidLo
parameter_list|,
name|IN
name|UINT64
name|ClassGuidHi
parameter_list|,
name|IN
name|UINT64
name|FunctionId
parameter_list|,
name|IN
name|SAL_INTERNAL_EXTENDED_SAL_PROC
name|InternalSalProc
parameter_list|,
name|IN
name|VOID
modifier|*
name|PhysicalModuleGlobal
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Calls a previously registered Extended SAL Procedure.    This function calls the Extended SAL Procedure specified by ClassGuidLo, ClassGuidHi,    and FunctionId.  The set of previously registered Extended SAL Procedures is searched for a    matching ClassGuidLo, ClassGuidHi, and FunctionId.  If a match is not found, then    EFI_SAL_NOT_IMPLEMENTED is returned.    @param  ClassGuidLo        The lower 64-bits of the class GUID for the Extended SAL Procedure                              that is being called.   @param  ClassGuidHi        The upper 64-bits of the class GUID for the Extended SAL Procedure                              that is being called.   @param  FunctionId         Function ID for the Extended SAL Procedure being called.   @param  Arg2               Second argument to the Extended SAL procedure.   @param  Arg3               Third argument to the Extended SAL procedure.   @param  Arg4               Fourth argument to the Extended SAL procedure.   @param  Arg5               Fifth argument to the Extended SAL procedure.   @param  Arg6               Sixth argument to the Extended SAL procedure.   @param  Arg7               Seventh argument to the Extended SAL procedure.   @param  Arg8               Eighth argument to the Extended SAL procedure.    @retval EFI_SAL_NOT_IMPLEMENTED        The Extended SAL Procedure specified by ClassGuidLo,                                           ClassGuidHi, and FunctionId has not been registered.   @retval EFI_SAL_VIRTUAL_ADDRESS_ERROR  This function was called in virtual mode before virtual mappings                                           for the specified Extended SAL Procedure are available.   @retval Other                          The result returned from the specified Extended SAL Procedure  **/
end_comment

begin_typedef
typedef|typedef
name|SAL_RETURN_REGS
function_decl|(
name|EFIAPI
modifier|*
name|EXTENDED_SAL_PROC
function_decl|)
parameter_list|(
name|IN
name|UINT64
name|ClassGuidLo
parameter_list|,
name|IN
name|UINT64
name|ClassGuidHi
parameter_list|,
name|IN
name|UINT64
name|FunctionId
parameter_list|,
name|IN
name|UINT64
name|Arg2
parameter_list|,
name|IN
name|UINT64
name|Arg3
parameter_list|,
name|IN
name|UINT64
name|Arg4
parameter_list|,
name|IN
name|UINT64
name|Arg5
parameter_list|,
name|IN
name|UINT64
name|Arg6
parameter_list|,
name|IN
name|UINT64
name|Arg7
parameter_list|,
name|IN
name|UINT64
name|Arg8
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EXTENDED_SAL_BOOT_SERVICE_PROTOCOL provides a mechanisms for platform specific
end_comment

begin_comment
comment|/// drivers to update the SAL System Table and register Extended SAL Procedures that are
end_comment

begin_comment
comment|/// callable in physical or virtual mode using the SAL calling convention.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EXTENDED_SAL_BOOT_SERVICE_PROTOCOL
block|{
name|EXTENDED_SAL_ADD_SST_INFO
name|AddSalSystemTableInfo
decl_stmt|;
name|EXTENDED_SAL_ADD_SST_ENTRY
name|AddSalSystemTableEntry
decl_stmt|;
name|EXTENDED_SAL_REGISTER_INTERNAL_PROC
name|RegisterExtendedSalProc
decl_stmt|;
name|EXTENDED_SAL_PROC
name|ExtendedSalProc
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiExtendedSalBootServiceProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

