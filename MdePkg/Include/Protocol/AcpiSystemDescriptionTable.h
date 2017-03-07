begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This protocol provides services for creating ACPI system description tables.      Copyright (c) 2006 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACPI_SYSTEM_DESCRIPTION_TABLE_H___
end_ifndef

begin_define
define|#
directive|define
name|__ACPI_SYSTEM_DESCRIPTION_TABLE_H___
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_SDT_PROTOCOL_GUID
define|\
value|{ 0xeb97088e, 0xcfdf, 0x49c6, { 0xbe, 0x4b, 0xd9, 0x6, 0xa5, 0xb2, 0xe, 0x86 }}
end_define

begin_typedef
typedef|typedef
name|UINT32
name|EFI_ACPI_TABLE_VERSION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|EFI_ACPI_HANDLE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_ACPI_TABLE_VERSION_NONE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_TABLE_VERSION_1_0B
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_TABLE_VERSION_2_0
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_TABLE_VERSION_3_0
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_TABLE_VERSION_4_0
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_TABLE_VERSION_5_0
value|(1<< 5)
end_define

begin_typedef
typedef|typedef
name|UINT32
name|EFI_ACPI_DATA_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_ACPI_DATA_TYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DATA_TYPE_OPCODE
value|1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DATA_TYPE_NAME_STRING
value|2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DATA_TYPE_OP
value|3
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DATA_TYPE_UINT
value|4
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DATA_TYPE_STRING
value|5
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DATA_TYPE_CHILD
value|6
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Signature
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|UINT8
name|Revision
decl_stmt|;
name|UINT8
name|Checksum
decl_stmt|;
name|CHAR8
name|OemId
index|[
literal|6
index|]
decl_stmt|;
name|CHAR8
name|OemTableId
index|[
literal|8
index|]
decl_stmt|;
name|UINT32
name|OemRevision
decl_stmt|;
name|UINT32
name|CreatorId
decl_stmt|;
name|UINT32
name|CreatorRevision
decl_stmt|;
block|}
name|EFI_ACPI_SDT_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ACPI_NOTIFICATION_FN
function_decl|)
parameter_list|(
name|IN
name|EFI_ACPI_SDT_HEADER
modifier|*
name|Table
parameter_list|,
comment|///< A pointer to the ACPI table header.
name|IN
name|EFI_ACPI_TABLE_VERSION
name|Version
parameter_list|,
comment|///< The ACPI table's version.
name|IN
name|UINTN
name|TableKey
comment|///< The table key for this ACPI table.
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns a requested ACPI table.      The GetAcpiTable() function returns a pointer to a buffer containing the ACPI table associated   with the Index that was input. The following structures are not considered elements in the list of   ACPI tables:   - Root System Description Pointer (RSD_PTR)   - Root System Description Table (RSDT)   - Extended System Description Table (XSDT)   Version is updated with a bit map containing all the versions of ACPI of which the table is a   member. For tables installed via the EFI_ACPI_TABLE_PROTOCOL.InstallAcpiTable() interface,   the function returns the value of EFI_ACPI_STD_PROTOCOL.AcpiVersion.      @param[in]    Index       The zero-based index of the table to retrieve.   @param[out]   Table       Pointer for returning the table buffer.   @param[out]   Version     On return, updated with the ACPI versions to which this table belongs. Type                             EFI_ACPI_TABLE_VERSION is defined in "Related Definitions" in the                             EFI_ACPI_SDT_PROTOCOL.       @param[out]   TableKey    On return, points to the table key for the specified ACPI system definition table.                             This is identical to the table key used in the EFI_ACPI_TABLE_PROTOCOL.                             The TableKey can be passed to EFI_ACPI_TABLE_PROTOCOL.UninstallAcpiTable()                             to uninstall the table.    @retval EFI_SUCCESS       The function completed successfully.   @retval EFI_NOT_FOUND     The requested index is too large and a table was not found.                                   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ACPI_GET_ACPI_TABLE2
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|Index
parameter_list|,
name|OUT
name|EFI_ACPI_SDT_HEADER
modifier|*
modifier|*
name|Table
parameter_list|,
name|OUT
name|EFI_ACPI_TABLE_VERSION
modifier|*
name|Version
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|TableKey
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Register or unregister a callback when an ACPI table is installed.      This function registers or unregisters a function which will be called whenever a new ACPI table is   installed.      @param[in]    Register        If TRUE, then the specified function will be registered. If FALSE, then the specified                                 function will be unregistered.   @param[in]    Notification    Points to the callback function to be registered or unregistered.      @retval EFI_SUCCESS           Callback successfully registered or unregistered.   @retval EFI_INVALID_PARAMETER Notification is NULL   @retval EFI_INVALID_PARAMETER Register is FALSE and Notification does not match a known registration function.                         **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ACPI_REGISTER_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|BOOLEAN
name|Register
parameter_list|,
name|IN
name|EFI_ACPI_NOTIFICATION_FN
name|Notification
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Create a handle from an ACPI opcode      @param[in]  Buffer                 Points to the ACPI opcode.   @param[out] Handle                 Upon return, holds the handle.      @retval   EFI_SUCCESS             Success   @retval   EFI_INVALID_PARAMETER   Buffer is NULL or Handle is NULL or Buffer points to an                                     invalid opcode.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ACPI_OPEN
function_decl|)
parameter_list|(
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|OUT
name|EFI_ACPI_HANDLE
modifier|*
name|Handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Create a handle for the first ACPI opcode in an ACPI system description table.      @param[in]    TableKey    The table key for the ACPI table, as returned by GetTable().   @param[out]   Handle      On return, points to the newly created ACPI handle.    @retval EFI_SUCCESS       Handle created successfully.   @retval EFI_NOT_FOUND     TableKey does not refer to a valid ACPI table.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ACPI_OPEN_SDT
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|TableKey
parameter_list|,
name|OUT
name|EFI_ACPI_HANDLE
modifier|*
name|Handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Close an ACPI handle.      @param[in] Handle Returns the handle.      @retval EFI_SUCCESS           Success   @retval EFI_INVALID_PARAMETER Handle is NULL or does not refer to a valid ACPI object.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ACPI_CLOSE
function_decl|)
parameter_list|(
name|IN
name|EFI_ACPI_HANDLE
name|Handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Return the child ACPI objects.      @param[in]        ParentHandle    Parent handle.   @param[in, out]   Handle          On entry, points to the previously returned handle or NULL to start with the first                                     handle. On return, points to the next returned ACPI handle or NULL if there are no                                     child objects.    @retval EFI_SUCCESS               Success   @retval EFI_INVALID_PARAMETER     ParentHandle is NULL or does not refer to a valid ACPI object.                                 **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ACPI_GET_CHILD
function_decl|)
parameter_list|(
name|IN
name|EFI_ACPI_HANDLE
name|ParentHandle
parameter_list|,
name|IN
name|OUT
name|EFI_ACPI_HANDLE
modifier|*
name|Handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieve information about an ACPI object.      @param[in]    Handle      ACPI object handle.   @param[in]    Index       Index of the data to retrieve from the object. In general, indexes read from left-to-right                             in the ACPI encoding, with index 0 always being the ACPI opcode.   @param[out]   DataType    Points to the returned data type or EFI_ACPI_DATA_TYPE_NONE if no data exists                             for the specified index.   @param[out]   Data        Upon return, points to the pointer to the data.   @param[out]   DataSize    Upon return, points to the size of Data.      @retval               **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ACPI_GET_OPTION
function_decl|)
parameter_list|(
name|IN
name|EFI_ACPI_HANDLE
name|Handle
parameter_list|,
name|IN
name|UINTN
name|Index
parameter_list|,
name|OUT
name|EFI_ACPI_DATA_TYPE
modifier|*
name|DataType
parameter_list|,
name|OUT
name|CONST
name|VOID
modifier|*
modifier|*
name|Data
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|DataSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Change information about an ACPI object.      @param[in]  Handle    ACPI object handle.   @param[in]  Index     Index of the data to retrieve from the object. In general, indexes read from left-to-right                         in the ACPI encoding, with index 0 always being the ACPI opcode.   @param[in]  Data      Points to the data.   @param[in]  DataSize  The size of the Data.    @retval EFI_SUCCESS           Success   @retval EFI_INVALID_PARAMETER Handle is NULL or does not refer to a valid ACPI object.   @retval EFI_BAD_BUFFER_SIZE   Data cannot be accommodated in the space occupied by                                 the option.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ACPI_SET_OPTION
function_decl|)
parameter_list|(
name|IN
name|EFI_ACPI_HANDLE
name|Handle
parameter_list|,
name|IN
name|UINTN
name|Index
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|UINTN
name|DataSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the handle of the ACPI object representing the specified ACPI path      @param[in]    HandleIn    Points to the handle of the object representing the starting point for the path search.   @param[in]    AcpiPath    Points to the ACPI path, which conforms to the ACPI encoded path format.   @param[out]   HandleOut   On return, points to the ACPI object which represents AcpiPath, relative to                             HandleIn.                                @retval EFI_SUCCESS           Success   @retval EFI_INVALID_PARAMETER HandleIn is NULL or does not refer to a valid ACPI object.                             **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ACPI_FIND_PATH
function_decl|)
parameter_list|(
name|IN
name|EFI_ACPI_HANDLE
name|HandleIn
parameter_list|,
name|IN
name|VOID
modifier|*
name|AcpiPath
parameter_list|,
name|OUT
name|EFI_ACPI_HANDLE
modifier|*
name|HandleOut
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_ACPI_SDT_PROTOCOL
block|{
comment|///
comment|/// A bit map containing all the ACPI versions supported by this protocol.
comment|///
name|EFI_ACPI_TABLE_VERSION
name|AcpiVersion
decl_stmt|;
name|EFI_ACPI_GET_ACPI_TABLE2
name|GetAcpiTable
decl_stmt|;
name|EFI_ACPI_REGISTER_NOTIFY
name|RegisterNotify
decl_stmt|;
name|EFI_ACPI_OPEN
name|Open
decl_stmt|;
name|EFI_ACPI_OPEN_SDT
name|OpenSdt
decl_stmt|;
name|EFI_ACPI_CLOSE
name|Close
decl_stmt|;
name|EFI_ACPI_GET_CHILD
name|GetChild
decl_stmt|;
name|EFI_ACPI_GET_OPTION
name|GetOption
decl_stmt|;
name|EFI_ACPI_SET_OPTION
name|SetOption
decl_stmt|;
name|EFI_ACPI_FIND_PATH
name|FindPath
decl_stmt|;
block|}
name|EFI_ACPI_SDT_PROTOCOL
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiAcpiSdtProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __ACPI_SYSTEM_DESCRIPTION_TABLE_H___
end_comment

end_unit

