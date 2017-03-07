begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file    Defines library APIs used by modules to save EFI Boot Script Opcodes.     These OpCode will be restored by S3 related modules.    Note that some of the API defined in the Library class may not    be provided in the Framework version library instance, which means some of these    APIs cannot be used if the underlying firmware is Framework and not PI.    Copyright (c) 2006 - 2014, Intel Corporation. All rights reserved.<BR>    This program and the accompanying materials   are licensed and made available under the terms and conditions   of the BSD License which accompanies this distribution.  The   full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_S3_BOOT_SCRIPT_LIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_S3_BOOT_SCRIPT_LIB_H_
end_define

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/SmBus.h>
end_include

begin_comment
comment|/**   Macro that converts PCI Bus, PCI Device, PCI Function and PCI Register to an   address that can be passed to the S3 Boot Script Library PCI functions.    @param  Bus       PCI Bus number. Range 0..255.   @param  Device    PCI Device number. Range 0..31.   @param  Function  PCI Function number. Range 0..7.   @param  Register  PCI Register number. Range 0..255 for PCI. Range 0..4095                     for PCI Express.    @return The encoded PCI address.  **/
end_comment

begin_define
define|#
directive|define
name|S3_BOOT_SCRIPT_LIB_PCI_ADDRESS
parameter_list|(
name|Bus
parameter_list|,
name|Device
parameter_list|,
name|Function
parameter_list|,
name|Register
parameter_list|)
define|\
value|(UINT64) ( \   (((UINTN) Bus)<< 24) | \   (((UINTN) Device)<< 16) | \   (((UINTN) Function)<< 8) | \   (((UINTN) (Register))< 256 ? ((UINTN) (Register)) : (UINT64) (LShiftU64 ((UINT64) (Register), 32))))
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// S3 Boot Script Width.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|S3BootScriptWidthUint8
block|,
comment|///< 8-bit operation.
name|S3BootScriptWidthUint16
block|,
comment|///< 16-bit operation.
name|S3BootScriptWidthUint32
block|,
comment|///< 32-bit operation.
name|S3BootScriptWidthUint64
block|,
comment|///< 64-bit operation.
name|S3BootScriptWidthFifoUint8
block|,
comment|///< 8-bit FIFO operation.
name|S3BootScriptWidthFifoUint16
block|,
comment|///< 16-bit FIFO operation.
name|S3BootScriptWidthFifoUint32
block|,
comment|///< 32-bit FIFO operation.
name|S3BootScriptWidthFifoUint64
block|,
comment|///< 64-bit FIFO operation.
name|S3BootScriptWidthFillUint8
block|,
comment|///< 8-bit Fill operation.
name|S3BootScriptWidthFillUint16
block|,
comment|///< 16-bit Fill operation.
name|S3BootScriptWidthFillUint32
block|,
comment|///< 32-bit Fill operation.
name|S3BootScriptWidthFillUint64
block|,
comment|///< 64-bit Fill operation.
name|S3BootScriptWidthMaximum
block|}
name|S3_BOOT_SCRIPT_LIB_WIDTH
typedef|;
end_typedef

begin_comment
comment|/**   Save I/O write to boot script.    @param[in] Width     The width of the I/O operations.   @param[in] Address   The base address of the I/O operations.   @param[in] Count     The number of I/O operations to perform.   @param[in] Buffer    The source buffer from which to write data.    @retval RETURN_OUT_OF_RESOURCES   Not enough memory for the table to perform                                      the operation.   @retval RETURN_SUCCESS            The opcode was added.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSaveIoWrite
parameter_list|(
name|IN
name|S3_BOOT_SCRIPT_LIB_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a record for an I/O modify operation into a S3 boot script table.    @param[in] Width      The width of the I/O operations.   @param[in] Address    The base address of the I/O operations.   @param[in] Data       A pointer to the data to be OR-ed.   @param[in] DataMask   A pointer to the data mask to be AND-ed with the data                         read from the register.    @retval RETURN_OUT_OF_RESOURCES   Not enough memory for the table to perform                                      the operation.   @retval RETURN_SUCCESS            The opcode was added.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSaveIoReadWrite
parameter_list|(
name|IN
name|S3_BOOT_SCRIPT_LIB_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|VOID
modifier|*
name|DataMask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a record for a memory write operation into a specified boot script table.    @param[in] Width     The width of the I/O operations.   @param[in] Address   The base address of the memory operations   @param[in] Count     The number of memory operations to perform.   @param[in] Buffer    The source buffer from which to write the data.    @retval RETURN_OUT_OF_RESOURCES   Not enough memory for the table to perform                                      the operation.   @retval RETURN_SUCCESS            The opcode was added. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSaveMemWrite
parameter_list|(
name|IN
name|S3_BOOT_SCRIPT_LIB_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a record for a memory modify operation into a specified boot script table.    @param[in] Width      The width of the I/O operations.   @param[in] Address    The base address of the memory operations. Address needs                          alignment, if required   @param[in] Data       A pointer to the data to be OR-ed.   @param[in] DataMask   A pointer to the data mask to be AND-ed with the data                          read from the register.    @retval RETURN_OUT_OF_RESOURCES   Not enough memory for the table to perform                                      the operation.   @retval RETURN_SUCCESS            The opcode was added. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSaveMemReadWrite
parameter_list|(
name|IN
name|S3_BOOT_SCRIPT_LIB_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|VOID
modifier|*
name|DataMask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a record for a PCI configuration space write operation into a specified boot script table.    @param[in] Width     The width of the I/O operations.   @param[in] Address   The address within the PCI configuration space.   @param[in] Count     The number of PCI operations to perform.   @param[in] Buffer    The source buffer from which to write the data.    @retval RETURN_OUT_OF_RESOURCES  Not enough memory for the table to perform                                     the operation.   @retval RETURN_SUCCESS           The opcode was added. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSavePciCfgWrite
parameter_list|(
name|IN
name|S3_BOOT_SCRIPT_LIB_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a record for a PCI configuration space modify operation into a specified boot script table.    @param[in] Width      The width of the I/O operations.   @param[in] Address    The address within the PCI configuration space.   @param[in] Data       A pointer to the data to be OR-ed.The size depends on Width.   @param[in] DataMask   A pointer to the data mask to be AND-ed.    @retval RETURN_OUT_OF_RESOURCES   Not enough memory for the table to perform                                      the operation.   @retval RETURN__SUCCESS           The opcode was added. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSavePciCfgReadWrite
parameter_list|(
name|IN
name|S3_BOOT_SCRIPT_LIB_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|VOID
modifier|*
name|DataMask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a record for a PCI configuration space modify operation into a specified boot script table.    @param[in] Width     The width of the I/O operations.   @param[in] Segment   The PCI segment number for Address.   @param[in] Address   The address within the PCI configuration space.   @param[in] Count     The number of PCI operations to perform.   @param[in] Buffer    The source buffer from which to write the data.    @retval RETURN_OUT_OF_RESOURCES   Not enough memory for the table to perform                                      the operation.   @retval RETURN_SUCCESS            The opcode was added. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSavePciCfg2Write
parameter_list|(
name|IN
name|S3_BOOT_SCRIPT_LIB_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT16
name|Segment
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a record for a PCI configuration space modify operation into a specified boot script table.    @param[in] Width      The width of the I/O operations.   @param[in] Segment    The PCI segment number for Address.   @param[in] Address    The address within the PCI configuration space.   @param[in] Data       A pointer to the data to be OR-ed. The size depends on Width.   @param[in] DataMask   A pointer to the data mask to be AND-ed.    @retval RETURN_OUT_OF_RESOURCES   Not enough memory for the table to perform                                      the operation.   @retval RETURN_SUCCESS            The opcode was added. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSavePciCfg2ReadWrite
parameter_list|(
name|IN
name|S3_BOOT_SCRIPT_LIB_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT16
name|Segment
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|VOID
modifier|*
name|DataMask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a record for an SMBus command execution into a specified boot script table.    @param[in] SmBusAddress   Address that encodes the SMBUS Slave Address, SMBUS                              Command, SMBUS Data Length, and PEC.   @param[in] Operation      Indicates which particular SMBus protocol it will use                              to execute the SMBus transactions.   @param[in] Length         A pointer to signify the number of bytes that this                              operation will do.   @param[in] Buffer         Contains the value of data to execute to the SMBUS                              slave device.      @retval RETURN_OUT_OF_RESOURCES   Not enough memory for the table to perform                                      the operation.   @retval RETURN_SUCCESS            The opcode was added. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSaveSmbusExecute
parameter_list|(
name|IN
name|UINTN
name|SmBusAddress
parameter_list|,
name|IN
name|EFI_SMBUS_OPERATION
name|Operation
parameter_list|,
name|IN
name|UINTN
modifier|*
name|Length
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a record for an execution stall on the processor into a specified boot script table.    @param[in] Duration   The duration in microseconds of the stall.      @retval RETURN_OUT_OF_RESOURCES   Not enough memory for the table to perform                                      the operation.   @retval RETURN_SUCCESS            The opcode was added. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSaveStall
parameter_list|(
name|IN
name|UINTN
name|Duration
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a record for dispatching specified arbitrary code into a specified boot script table.    @param[in] EntryPoint   The entry point of the code to be dispatched.   @param[in] Context      The argument to be passed into the EntryPoint of the code                            to be dispatched.      @retval RETURN_OUT_OF_RESOURCES   Not enough memory for the table to perform                                      the operation.   @retval RETURN_SUCCESS            The opcode was added. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSaveDispatch2
parameter_list|(
name|IN
name|VOID
modifier|*
name|EntryPoint
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a record for dispatching specified arbitrary code into a specified boot script table.    @param[in] EntryPoint   The entry point of the code to be dispatched.      @retval RETURN_OUT_OF_RESOURCES   Not enough memory for the table to perform                                      the operation.   @retval RETURN_SUCCESS            The opcode was added. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSaveDispatch
parameter_list|(
name|IN
name|VOID
modifier|*
name|EntryPoint
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a record for memory reads of the memory location and continues when the exit    criteria is satisfied, or after a defined duration.    Please aware, below interface is different with PI specification, Vol 5:   EFI_S3_SAVE_STATE_PROTOCOL.Write() for EFI_BOOT_SCRIPT_MEM_POLL_OPCODE.   "Duration" below is microseconds, while "Delay" in PI specification means   the number of 100ns units to poll.    @param[in] Width       The width of the memory operations.   @param[in] Address     The base address of the memory operations.   @param[in] BitMask     A pointer to the bit mask to be AND-ed with the data read                           from the register.   @param[in] BitValue    A pointer to the data value after to be Masked.   @param[in] Duration    The duration in microseconds of the stall.   @param[in] LoopTimes   The times of the register polling.    @retval RETURN_OUT_OF_RESOURCES   Not enough memory for the table to perform                                      the operation.   @retval RETURN_SUCCESS            The opcode was added.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSaveMemPoll
parameter_list|(
name|IN
name|S3_BOOT_SCRIPT_LIB_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|VOID
modifier|*
name|BitMask
parameter_list|,
name|IN
name|VOID
modifier|*
name|BitValue
parameter_list|,
name|IN
name|UINTN
name|Duration
parameter_list|,
name|IN
name|UINT64
name|LoopTimes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Store arbitrary information in the boot script table. This opcode is a no-op on    dispatch and is only used for debugging script issues.      @param[in] InformationLength   Length of the data in bytes   @param[in] Information        Information to be logged in the boot scrpit     @retval RETURN_OUT_OF_RESOURCES   Not enough memory for the table to perform                                      the operation.   @retval RETURN_SUCCESS            The opcode was added.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSaveInformation
parameter_list|(
name|IN
name|UINT32
name|InformationLength
parameter_list|,
name|IN
name|VOID
modifier|*
name|Information
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a record for I/O reads the I/O location and continues when the exit criteria    is satisfied, or after a defined duration.      @param  Width                 The width of the I/O operations.    @param  Address               The base address of the I/O operations.   @param  Data                  The comparison value used for the polling exit criteria.   @param  DataMask              The mask used for the polling criteria. The bits in                                  the bytes below Width which are zero in Data are                                  ignored when polling the memory address.   @param  Delay                 The number of 100ns units to poll. Note that timer                                  available may be of insufficient granularity, so the                                  delay may be longer.   @retval RETURN_OUT_OF_RESOURCES  Not enough memory for the table to perform the                                    operation.  @retval RETURN_SUCCESS           The opcode was added.  @note   The FRAMEWORK version implementation does not support this API  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSaveIoPoll
parameter_list|(
name|IN
name|S3_BOOT_SCRIPT_LIB_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|VOID
modifier|*
name|DataMask
parameter_list|,
name|IN
name|UINT64
name|Delay
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a record for PCI configuration space reads and continues when the exit    criteria is satisfied ,or after a defined duration.    @param  Width                 The width of the I/O operations.    @param  Address               The address within the PCI configuration space.   @param  Data                  The comparison value used for the polling exit                                  criteria.   @param  DataMask              Mask used for the polling criteria. The bits in                                  the bytes below Width which are zero in Data are                                 ignored when polling the memory address.   @param  Delay                 The number of 100ns units to poll. Note that timer                                  available may be of insufficient granularity, so the                                  delay may be longer.   @retval RETURN_OUT_OF_RESOURCES  Not enough memory for the table to perform the                                   operation.  @retval RETURN_SUCCESS           The opcode was added.  @note   The FRAMEWORK version implementation does not support this API  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSavePciPoll
parameter_list|(
name|IN
name|S3_BOOT_SCRIPT_LIB_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|VOID
modifier|*
name|DataMask
parameter_list|,
name|IN
name|UINT64
name|Delay
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Adds a record for PCI configuration space reads and continues when the exit criteria    is satisfied, or after a defined duration.    @param  Width                 The width of the I/O operations.    @param  Segment               The PCI segment number for Address.   @param  Address               The address within the PCI configuration space.   @param  Data                  The comparison value used for the polling exit                                  criteria.   @param  DataMask              Mask used for the polling criteria. The bits in                                  the bytes below Width which are zero                                 in Data are ignored when polling the memory address   @param  Delay                 The number of 100ns units to poll. Note that timer                                  available may be of insufficient granularity so the delay                                  may be longer.    @retval RETURN_OUT_OF_RESOURCES  Not enough memory for the table to perform the                                     operation.   @retval RETURN_SUCCESS           The opcode was added.   @note  A known Limitations in the implementation: When interpreting the opcode            EFI_BOOT_SCRIPT_PCI_CONFIG2_WRITE_OPCODE, EFI_BOOT_SCRIPT_PCI_CONFIG2_READ_WRITE_OPCODE          and EFI_BOOT_SCRIPT_PCI_CONFIG2_POLL_OPCODE, the 'Segment' parameter is assumed as           Zero, or else, assert.          The FRAMEWORK version implementation does not support this API.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSavePci2Poll
parameter_list|(
name|IN
name|S3_BOOT_SCRIPT_LIB_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT16
name|Segment
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|VOID
modifier|*
name|DataMask
parameter_list|,
name|IN
name|UINT64
name|Delay
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Save ASCII string information specified by Buffer to boot script with opcode    EFI_BOOT_SCRIPT_INFORMATION_OPCODE.    @param[in] String   The Null-terminated ASCII string to store into the S3 boot                        script table.    @retval RETURN_OUT_OF_RESOURCES   Not enough memory for the table to perform                                      the operation.   @retval RETURN_SUCCESS            The opcode was added.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptSaveInformationAsciiString
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This is an function to close the S3 boot script table. The function could only    be called in BOOT time phase. To comply with the Framework spec definition on    EFI_BOOT_SCRIPT_SAVE_PROTOCOL.CloseTable(), this function will fulfill following things:   1. Closes the specified boot script table   2. It allocates a new memory pool to duplicate all the boot scripts in the specified table.       Once this function is called, the table maintained by the library will be destroyed       after it is copied into the allocated pool.   3. Any attempts to add a script record after calling this function will cause a       new table to be created by the library.   4. The base address of the allocated pool will be returned in Address. Note that       after using the boot script table, the CALLER is responsible for freeing the       pool that is allocated by this function.     In Spec PI1.1, this EFI_BOOT_SCRIPT_SAVE_PROTOCOL.CloseTable() is retired. This    API is supplied here to meet the requirements of the Framework Spec.      If anyone does call CloseTable() on a real platform, then the caller is responsible   for figuring out how to get the script to run on an S3 resume because the boot script    maintained by the lib will be destroyed.     @return the base address of the new copy of the boot script table.     **/
end_comment

begin_function_decl
name|UINT8
modifier|*
name|EFIAPI
name|S3BootScriptCloseTable
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes the S3 boot script table.    @retval RETURN_SUCCESS       The boot script table was executed successfully.   @retval RETURN_UNSUPPORTED   Invalid script table or opcode.    **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptExecute
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Move the last boot script entry to the position     @param  BeforeOrAfter         Specifies whether the opcode is stored before                                  (TRUE) or after (FALSE) the positionin the boot                                  script table specified by Position. If Position                                  is NULL or points to NULL then the new opcode is                                  inserted at the beginning of the table (if TRUE)                                  or end of the table (if FALSE).   @param  Position              On entry, specifies the position in the boot script                                  table where the opcode will be inserted, either                                  before or after, depending on BeforeOrAfter. On                                  exit, specifies the position of the inserted opcode                                  in the boot script table.    @retval RETURN_OUT_OF_RESOURCES  The table is not available.   @retval RETURN_INVALID_PARAMETER The Position is not a valid position in the                                     boot script table.   @retval RETURN_SUCCESS           The opcode was inserted.   @note   The FRAMEWORK version implementation does not support this API.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptMoveLastOpcode
parameter_list|(
name|IN
name|BOOLEAN
name|BeforeOrAfter
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
modifier|*
name|Position
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Find a label within the boot script table and, if not present, optionally create it.    @param  BeforeOrAfter         Specifies whether the opcode is stored before (TRUE)                                 or after (FALSE) the position in the boot script table                                  specified by Position.   @param  CreateIfNotFound      Specifies whether the label will be created if the                                   label does not exists (TRUE) or not (FALSE).   @param  Position              On entry, specifies the position in the boot script                                  table where the opcode will be inserted, either                                  before or after, depending on BeforeOrAfter. On exit,                                  specifies the positionof the inserted opcode in                                  the boot script table.   @param  Label                 Points to the label which will be inserted in the                                  boot script table.   @retval EFI_SUCCESS           The operation succeeded. A record was added into                                  the specified script table.   @retval EFI_INVALID_PARAMETER The parameter is illegal or the given boot script                                  is not supported. If the opcode is unknow or not                                  supported because of the PCD Feature Flags.   @retval EFI_OUT_OF_RESOURCES  There is insufficient memory to store the boot script.   @note   The FRAMEWORK version implementation does not support this API   **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptLabel
parameter_list|(
name|IN
name|BOOLEAN
name|BeforeOrAfter
parameter_list|,
name|IN
name|BOOLEAN
name|CreateIfNotFound
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
modifier|*
name|Position
name|OPTIONAL
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|Label
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Compare two positions in the boot script table and return their relative position.   @param  Position1             The positions in the boot script table to compare   @param  Position2             The positions in the boot script table to compare   @param  RelativePosition      On return, points to the result of the comparison    @retval EFI_SUCCESS           The operation succeeded. A record was added into the                                 specified script table.   @retval EFI_INVALID_PARAMETER The parameter is illegal or the given boot script                                  is not supported. If the opcode is unknow or not s                                 upported because of the PCD Feature Flags.   @retval EFI_OUT_OF_RESOURCES  There is insufficient memory to store the boot script.   @note   The FRAMEWORK version implementation does not support this API  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|S3BootScriptCompare
parameter_list|(
name|IN
name|UINT8
modifier|*
name|Position1
parameter_list|,
name|IN
name|UINT8
modifier|*
name|Position2
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|RelativePosition
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

