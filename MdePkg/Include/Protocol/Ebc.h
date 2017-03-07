begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Describes the protocol interface to the EBC interpreter.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_EBC_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_EBC_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_EBC_INTERPRETER_PROTOCOL_GUID
define|\
value|{ \     0x13AC6DD1, 0x73D0, 0x11D4, {0xB0, 0x6B, 0x00, 0xAA, 0x00, 0xBD, 0x6D, 0xE7 } \   }
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Define OPCODES
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|OPCODE_BREAK
value|0x00
end_define

begin_define
define|#
directive|define
name|OPCODE_JMP
value|0x01
end_define

begin_define
define|#
directive|define
name|OPCODE_JMP8
value|0x02
end_define

begin_define
define|#
directive|define
name|OPCODE_CALL
value|0x03
end_define

begin_define
define|#
directive|define
name|OPCODE_RET
value|0x04
end_define

begin_define
define|#
directive|define
name|OPCODE_CMPEQ
value|0x05
end_define

begin_define
define|#
directive|define
name|OPCODE_CMPLTE
value|0x06
end_define

begin_define
define|#
directive|define
name|OPCODE_CMPGTE
value|0x07
end_define

begin_define
define|#
directive|define
name|OPCODE_CMPULTE
value|0x08
end_define

begin_define
define|#
directive|define
name|OPCODE_CMPUGTE
value|0x09
end_define

begin_define
define|#
directive|define
name|OPCODE_NOT
value|0x0A
end_define

begin_define
define|#
directive|define
name|OPCODE_NEG
value|0x0B
end_define

begin_define
define|#
directive|define
name|OPCODE_ADD
value|0x0C
end_define

begin_define
define|#
directive|define
name|OPCODE_SUB
value|0x0D
end_define

begin_define
define|#
directive|define
name|OPCODE_MUL
value|0x0E
end_define

begin_define
define|#
directive|define
name|OPCODE_MULU
value|0x0F
end_define

begin_define
define|#
directive|define
name|OPCODE_DIV
value|0x10
end_define

begin_define
define|#
directive|define
name|OPCODE_DIVU
value|0x11
end_define

begin_define
define|#
directive|define
name|OPCODE_MOD
value|0x12
end_define

begin_define
define|#
directive|define
name|OPCODE_MODU
value|0x13
end_define

begin_define
define|#
directive|define
name|OPCODE_AND
value|0x14
end_define

begin_define
define|#
directive|define
name|OPCODE_OR
value|0x15
end_define

begin_define
define|#
directive|define
name|OPCODE_XOR
value|0x16
end_define

begin_define
define|#
directive|define
name|OPCODE_SHL
value|0x17
end_define

begin_define
define|#
directive|define
name|OPCODE_SHR
value|0x18
end_define

begin_define
define|#
directive|define
name|OPCODE_ASHR
value|0x19
end_define

begin_define
define|#
directive|define
name|OPCODE_EXTNDB
value|0x1A
end_define

begin_define
define|#
directive|define
name|OPCODE_EXTNDW
value|0x1B
end_define

begin_define
define|#
directive|define
name|OPCODE_EXTNDD
value|0x1C
end_define

begin_define
define|#
directive|define
name|OPCODE_MOVBW
value|0x1D
end_define

begin_define
define|#
directive|define
name|OPCODE_MOVWW
value|0x1E
end_define

begin_define
define|#
directive|define
name|OPCODE_MOVDW
value|0x1F
end_define

begin_define
define|#
directive|define
name|OPCODE_MOVQW
value|0x20
end_define

begin_define
define|#
directive|define
name|OPCODE_MOVBD
value|0x21
end_define

begin_define
define|#
directive|define
name|OPCODE_MOVWD
value|0x22
end_define

begin_define
define|#
directive|define
name|OPCODE_MOVDD
value|0x23
end_define

begin_define
define|#
directive|define
name|OPCODE_MOVQD
value|0x24
end_define

begin_define
define|#
directive|define
name|OPCODE_MOVSNW
value|0x25
end_define

begin_comment
comment|// Move signed natural with word index
end_comment

begin_define
define|#
directive|define
name|OPCODE_MOVSND
value|0x26
end_define

begin_comment
comment|// Move signed natural with dword index
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// #define OPCODE_27         0x27
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|OPCODE_MOVQQ
value|0x28
end_define

begin_comment
comment|// Does this go away?
end_comment

begin_define
define|#
directive|define
name|OPCODE_LOADSP
value|0x29
end_define

begin_define
define|#
directive|define
name|OPCODE_STORESP
value|0x2A
end_define

begin_define
define|#
directive|define
name|OPCODE_PUSH
value|0x2B
end_define

begin_define
define|#
directive|define
name|OPCODE_POP
value|0x2C
end_define

begin_define
define|#
directive|define
name|OPCODE_CMPIEQ
value|0x2D
end_define

begin_define
define|#
directive|define
name|OPCODE_CMPILTE
value|0x2E
end_define

begin_define
define|#
directive|define
name|OPCODE_CMPIGTE
value|0x2F
end_define

begin_define
define|#
directive|define
name|OPCODE_CMPIULTE
value|0x30
end_define

begin_define
define|#
directive|define
name|OPCODE_CMPIUGTE
value|0x31
end_define

begin_define
define|#
directive|define
name|OPCODE_MOVNW
value|0x32
end_define

begin_define
define|#
directive|define
name|OPCODE_MOVND
value|0x33
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// #define OPCODE_34         0x34
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|OPCODE_PUSHN
value|0x35
end_define

begin_define
define|#
directive|define
name|OPCODE_POPN
value|0x36
end_define

begin_define
define|#
directive|define
name|OPCODE_MOVI
value|0x37
end_define

begin_define
define|#
directive|define
name|OPCODE_MOVIN
value|0x38
end_define

begin_define
define|#
directive|define
name|OPCODE_MOVREL
value|0x39
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit masks for opcode encodings
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|OPCODE_M_OPCODE
value|0x3F
end_define

begin_comment
comment|// bits of interest for first level decode
end_comment

begin_define
define|#
directive|define
name|OPCODE_M_IMMDATA
value|0x80
end_define

begin_define
define|#
directive|define
name|OPCODE_M_IMMDATA64
value|0x40
end_define

begin_define
define|#
directive|define
name|OPCODE_M_64BIT
value|0x40
end_define

begin_comment
comment|// for CMP
end_comment

begin_define
define|#
directive|define
name|OPCODE_M_RELADDR
value|0x10
end_define

begin_comment
comment|// for CALL instruction
end_comment

begin_define
define|#
directive|define
name|OPCODE_M_CMPI32_DATA
value|0x80
end_define

begin_comment
comment|// for CMPI
end_comment

begin_define
define|#
directive|define
name|OPCODE_M_CMPI64
value|0x40
end_define

begin_comment
comment|// for CMPI 32 or 64 bit comparison
end_comment

begin_define
define|#
directive|define
name|OPERAND_M_MOVIN_N
value|0x80
end_define

begin_define
define|#
directive|define
name|OPERAND_M_CMPI_INDEX
value|0x10
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Masks for instructions that encode presence of indexes for operand1 and/or
end_comment

begin_comment
comment|// operand2.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|OPCODE_M_IMMED_OP1
value|0x80
end_define

begin_define
define|#
directive|define
name|OPCODE_M_IMMED_OP2
value|0x40
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit masks for operand encodings
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|OPERAND_M_INDIRECT1
value|0x08
end_define

begin_define
define|#
directive|define
name|OPERAND_M_INDIRECT2
value|0x80
end_define

begin_define
define|#
directive|define
name|OPERAND_M_OP1
value|0x07
end_define

begin_define
define|#
directive|define
name|OPERAND_M_OP2
value|0x70
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Masks for data manipulation instructions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|DATAMANIP_M_64
value|0x40
end_define

begin_comment
comment|// 64-bit width operation
end_comment

begin_define
define|#
directive|define
name|DATAMANIP_M_IMMDATA
value|0x80
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// For MOV instructions, need a mask for the opcode when immediate
end_comment

begin_comment
comment|// data applies to R2.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|OPCODE_M_IMMED_OP2
value|0x40
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// The MOVI/MOVIn instructions use bit 6 of operands byte to indicate
end_comment

begin_comment
comment|// if an index is present. Then bits 4 and 5 are used to indicate the width
end_comment

begin_comment
comment|// of the move.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|MOVI_M_IMMDATA
value|0x40
end_define

begin_define
define|#
directive|define
name|MOVI_M_DATAWIDTH
value|0xC0
end_define

begin_define
define|#
directive|define
name|MOVI_DATAWIDTH16
value|0x40
end_define

begin_define
define|#
directive|define
name|MOVI_DATAWIDTH32
value|0x80
end_define

begin_define
define|#
directive|define
name|MOVI_DATAWIDTH64
value|0xC0
end_define

begin_define
define|#
directive|define
name|MOVI_M_MOVEWIDTH
value|0x30
end_define

begin_define
define|#
directive|define
name|MOVI_MOVEWIDTH8
value|0x00
end_define

begin_define
define|#
directive|define
name|MOVI_MOVEWIDTH16
value|0x10
end_define

begin_define
define|#
directive|define
name|MOVI_MOVEWIDTH32
value|0x20
end_define

begin_define
define|#
directive|define
name|MOVI_MOVEWIDTH64
value|0x30
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Masks for CALL instruction encodings
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|OPERAND_M_RELATIVE_ADDR
value|0x10
end_define

begin_define
define|#
directive|define
name|OPERAND_M_NATIVE_CALL
value|0x20
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Masks for decoding push/pop instructions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PUSHPOP_M_IMMDATA
value|0x80
end_define

begin_comment
comment|// opcode bit indicating immediate data
end_comment

begin_define
define|#
directive|define
name|PUSHPOP_M_64
value|0x40
end_define

begin_comment
comment|// opcode bit indicating 64-bit operation
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Mask for operand of JMP instruction
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|JMP_M_RELATIVE
value|0x10
end_define

begin_define
define|#
directive|define
name|JMP_M_CONDITIONAL
value|0x80
end_define

begin_define
define|#
directive|define
name|JMP_M_CS
value|0x40
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Macros to determine if a given operand is indirect
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|OPERAND1_INDIRECT
parameter_list|(
name|op
parameter_list|)
value|((op)& OPERAND_M_INDIRECT1)
end_define

begin_define
define|#
directive|define
name|OPERAND2_INDIRECT
parameter_list|(
name|op
parameter_list|)
value|((op)& OPERAND_M_INDIRECT2)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Macros to extract the operands from second byte of instructions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|OPERAND1_REGNUM
parameter_list|(
name|op
parameter_list|)
value|((op)& OPERAND_M_OP1)
end_define

begin_define
define|#
directive|define
name|OPERAND2_REGNUM
parameter_list|(
name|op
parameter_list|)
value|(((op)& OPERAND_M_OP2)>> 4)
end_define

begin_define
define|#
directive|define
name|OPERAND1_CHAR
parameter_list|(
name|op
parameter_list|)
value|('0' + OPERAND1_REGNUM (op))
end_define

begin_define
define|#
directive|define
name|OPERAND2_CHAR
parameter_list|(
name|op
parameter_list|)
value|('0' + OPERAND2_REGNUM (op))
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Condition masks usually for byte 1 encodings of code
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|CONDITION_M_CONDITIONAL
value|0x80
end_define

begin_define
define|#
directive|define
name|CONDITION_M_CS
value|0x40
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol Guid Name defined in spec.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_EBC_PROTOCOL_GUID
value|EFI_EBC_INTERPRETER_PROTOCOL_GUID
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Define for forward reference.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_EBC_PROTOCOL
name|EFI_EBC_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Creates a thunk for an EBC entry point, returning the address of the thunk.      A PE32+ EBC image, like any other PE32+ image, contains an optional header that specifies the   entry point for image execution. However, for EBC images, this is the entry point of EBC   instructions, so is not directly executable by the native processor. Therefore, when an EBC image is   loaded, the loader must call this service to get a pointer to native code (thunk) that can be executed,   which will invoke the interpreter to begin execution at the original EBC entry point.    @param  This          A pointer to the EFI_EBC_PROTOCOL instance.   @param  ImageHandle   Handle of image for which the thunk is being created.   @param  EbcEntryPoint Address of the actual EBC entry point or protocol service the thunk should call.   @param  Thunk         Returned pointer to a thunk created.    @retval EFI_SUCCESS            The function completed successfully.   @retval EFI_INVALID_PARAMETER  Image entry point is not 2-byte aligned.   @retval EFI_OUT_OF_RESOURCES   Memory could not be allocated for the thunk. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EBC_CREATE_THUNK
function_decl|)
parameter_list|(
name|IN
name|EFI_EBC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ImageHandle
parameter_list|,
name|IN
name|VOID
modifier|*
name|EbcEntryPoint
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Thunk
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Called prior to unloading an EBC image from memory.    This function is called after an EBC image has exited, but before the image is actually unloaded. It   is intended to provide the interpreter with the opportunity to perform any cleanup that may be   necessary as a result of loading and executing the image.    @param  This          A pointer to the EFI_EBC_PROTOCOL instance.   @param  ImageHandle   Image handle of the EBC image that is being unloaded from memory.    @retval EFI_SUCCESS            The function completed successfully.   @retval EFI_INVALID_PARAMETER  Image handle is not recognized as belonging                                   to an EBC image that has been executed. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EBC_UNLOAD_IMAGE
function_decl|)
parameter_list|(
name|IN
name|EFI_EBC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ImageHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This is the prototype for the Flush callback routine. A pointer to a routine    of this type is passed to the EBC EFI_EBC_REGISTER_ICACHE_FLUSH protocol service.    @param  Start  The beginning physical address to flush from the processor's instruction cache.   @param  Length The number of bytes to flush from the processor's instruction cache.    @retval EFI_SUCCESS            The function completed successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EBC_ICACHE_FLUSH
function_decl|)
parameter_list|(
name|IN
name|EFI_PHYSICAL_ADDRESS
name|Start
parameter_list|,
name|IN
name|UINT64
name|Length
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Registers a callback function that the EBC interpreter calls to flush    the processor instruction cache following creation of thunks.    @param  This       A pointer to the EFI_EBC_PROTOCOL instance.   @param  Flush      Pointer to a function of type EBC_ICACH_FLUSH.    @retval EFI_SUCCESS            The function completed successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EBC_REGISTER_ICACHE_FLUSH
function_decl|)
parameter_list|(
name|IN
name|EFI_EBC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EBC_ICACHE_FLUSH
name|Flush
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Called to get the version of the interpreter.    This function is called to get the version of the loaded EBC interpreter. The value and format of the   returned version is identical to that returned by the EBC BREAK 1 instruction.    @param  This       A pointer to the EFI_EBC_PROTOCOL instance.     @param  Version    Pointer to where to store the returned version of the interpreter.    @retval EFI_SUCCESS            The function completed successfully.   @retval EFI_INVALID_PARAMETER  Version pointer is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EBC_GET_VERSION
function_decl|)
parameter_list|(
name|IN
name|EFI_EBC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINT64
modifier|*
name|Version
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI EBC protocol provides services to load and execute EBC images, which will typically be
end_comment

begin_comment
comment|/// loaded into option ROMs. The image loader will load the EBC image, perform standard relocations,
end_comment

begin_comment
comment|/// and invoke the CreateThunk() service to create a thunk for the EBC image's entry point. The
end_comment

begin_comment
comment|/// image can then be run using the standard EFI start image services.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_EBC_PROTOCOL
block|{
name|EFI_EBC_CREATE_THUNK
name|CreateThunk
decl_stmt|;
name|EFI_EBC_UNLOAD_IMAGE
name|UnloadImage
decl_stmt|;
name|EFI_EBC_REGISTER_ICACHE_FLUSH
name|RegisterICacheFlush
decl_stmt|;
name|EFI_EBC_GET_VERSION
name|GetVersion
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|//
end_comment

begin_comment
comment|// Extern the global EBC protocol GUID
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEbcProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

