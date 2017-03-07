begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI SMM CPU Protocol as defined in the PI 1.2 specification.    This protocol allows SMM drivers to access architecture-standard registers from any of the CPU    save state areas. In some cases, difference processors provide the same information in the save state,    but not in the same format. These so-called pseudo-registers provide this information in a standard    format.      Copyright (c) 2009 - 2012, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMM_CPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMM_CPU_H_
end_define

begin_define
define|#
directive|define
name|EFI_SMM_CPU_PROTOCOL_GUID
define|\
value|{ \     0xeb346b97, 0x975f, 0x4a9f, { 0x8b, 0x22, 0xf8, 0xe9, 0x2b, 0xb3, 0xd5, 0x69 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Save State register index
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// x86/X64 standard registers
comment|///
name|EFI_SMM_SAVE_STATE_REGISTER_GDTBASE
init|=
literal|4
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_IDTBASE
init|=
literal|5
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_LDTBASE
init|=
literal|6
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_GDTLIMIT
init|=
literal|7
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_IDTLIMIT
init|=
literal|8
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_LDTLIMIT
init|=
literal|9
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_LDTINFO
init|=
literal|10
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_ES
init|=
literal|20
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_CS
init|=
literal|21
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_SS
init|=
literal|22
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_DS
init|=
literal|23
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_FS
init|=
literal|24
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_GS
init|=
literal|25
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_LDTR_SEL
init|=
literal|26
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_TR_SEL
init|=
literal|27
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_DR7
init|=
literal|28
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_DR6
init|=
literal|29
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_R8
init|=
literal|30
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_R9
init|=
literal|31
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_R10
init|=
literal|32
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_R11
init|=
literal|33
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_R12
init|=
literal|34
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_R13
init|=
literal|35
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_R14
init|=
literal|36
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_R15
init|=
literal|37
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_RAX
init|=
literal|38
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_RBX
init|=
literal|39
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_RCX
init|=
literal|40
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_RDX
init|=
literal|41
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_RSP
init|=
literal|42
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_RBP
init|=
literal|43
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_RSI
init|=
literal|44
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_RDI
init|=
literal|45
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_RIP
init|=
literal|46
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_RFLAGS
init|=
literal|51
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_CR0
init|=
literal|52
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_CR3
init|=
literal|53
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_CR4
init|=
literal|54
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_FCW
init|=
literal|256
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_FSW
init|=
literal|257
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_FTW
init|=
literal|258
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_OPCODE
init|=
literal|259
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_FP_EIP
init|=
literal|260
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_FP_CS
init|=
literal|261
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_DATAOFFSET
init|=
literal|262
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_FP_DS
init|=
literal|263
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_MM0
init|=
literal|264
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_MM1
init|=
literal|265
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_MM2
init|=
literal|266
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_MM3
init|=
literal|267
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_MM4
init|=
literal|268
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_MM5
init|=
literal|269
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_MM6
init|=
literal|270
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_MM7
init|=
literal|271
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_XMM0
init|=
literal|272
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_XMM1
init|=
literal|273
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_XMM2
init|=
literal|274
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_XMM3
init|=
literal|275
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_XMM4
init|=
literal|276
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_XMM5
init|=
literal|277
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_XMM6
init|=
literal|278
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_XMM7
init|=
literal|279
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_XMM8
init|=
literal|280
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_XMM9
init|=
literal|281
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_XMM10
init|=
literal|282
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_XMM11
init|=
literal|283
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_XMM12
init|=
literal|284
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_XMM13
init|=
literal|285
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_XMM14
init|=
literal|286
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_XMM15
init|=
literal|287
block|,
comment|///
comment|/// Pseudo-Registers
comment|///
name|EFI_SMM_SAVE_STATE_REGISTER_IO
init|=
literal|512
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_LMA
init|=
literal|513
block|,
name|EFI_SMM_SAVE_STATE_REGISTER_PROCESSOR_ID
init|=
literal|514
block|}
name|EFI_SMM_SAVE_STATE_REGISTER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_SMM_SAVE_STATE_REGISTER_LMA pseudo-register values
end_comment

begin_comment
comment|/// If the processor acts in 32-bit mode at the time the SMI occurred, the pseudo register value
end_comment

begin_comment
comment|/// EFI_SMM_SAVE_STATE_REGISTER_LMA_32BIT is returned in Buffer. Otherwise,
end_comment

begin_comment
comment|/// EFI_SMM_SAVE_STATE_REGISTER_LMA_64BIT is returned in Buffer.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SMM_SAVE_STATE_REGISTER_LMA_32BIT
value|32
end_define

begin_define
define|#
directive|define
name|EFI_SMM_SAVE_STATE_REGISTER_LMA_64BIT
value|64
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Size width of I/O instruction
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EFI_SMM_SAVE_STATE_IO_WIDTH_UINT8
init|=
literal|0
block|,
name|EFI_SMM_SAVE_STATE_IO_WIDTH_UINT16
init|=
literal|1
block|,
name|EFI_SMM_SAVE_STATE_IO_WIDTH_UINT32
init|=
literal|2
block|,
name|EFI_SMM_SAVE_STATE_IO_WIDTH_UINT64
init|=
literal|3
block|}
name|EFI_SMM_SAVE_STATE_IO_WIDTH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Types of I/O instruction
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EFI_SMM_SAVE_STATE_IO_TYPE_INPUT
init|=
literal|1
block|,
name|EFI_SMM_SAVE_STATE_IO_TYPE_OUTPUT
init|=
literal|2
block|,
name|EFI_SMM_SAVE_STATE_IO_TYPE_STRING
init|=
literal|4
block|,
name|EFI_SMM_SAVE_STATE_IO_TYPE_REP_PREFIX
init|=
literal|8
block|}
name|EFI_SMM_SAVE_STATE_IO_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Structure of the data which is returned when ReadSaveState() is called with
end_comment

begin_comment
comment|/// EFI_SMM_SAVE_STATE_REGISTER_IO. If there was no I/O then ReadSaveState() will
end_comment

begin_comment
comment|/// return EFI_NOT_FOUND.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure describes the I/O operation which was in process when the SMI was generated.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_SMM_SAVE_STATE_IO_INFO
block|{
comment|///
comment|/// For input instruction (IN, INS), this is data read before the SMI occurred. For output
comment|/// instructions (OUT, OUTS) this is data that was written before the SMI occurred. The
comment|/// width of the data is specified by IoWidth.
comment|///
name|UINT64
name|IoData
decl_stmt|;
comment|///
comment|/// The I/O port that was being accessed when the SMI was triggered.
comment|///
name|UINT16
name|IoPort
decl_stmt|;
comment|///
comment|/// Defines the size width (UINT8, UINT16, UINT32, UINT64) for IoData.
comment|///
name|EFI_SMM_SAVE_STATE_IO_WIDTH
name|IoWidth
decl_stmt|;
comment|///
comment|/// Defines type of I/O instruction.
comment|///
name|EFI_SMM_SAVE_STATE_IO_TYPE
name|IoType
decl_stmt|;
block|}
name|EFI_SMM_SAVE_STATE_IO_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_SMM_CPU_PROTOCOL
name|EFI_SMM_CPU_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Read data from the CPU save state.    This function is used to read the specified number of bytes of the specified register from the CPU    save state of the specified CPU and place the value into the buffer. If the CPU does not support the   specified register Register, then EFI_NOT_FOUND  should be returned. If the CPU does not    support the specified register width Width, then EFI_INVALID_PARAMETER is returned.    @param[in]  This               The EFI_SMM_CPU_PROTOCOL instance.   @param[in]  Width              The number of bytes to read from the CPU save state.   @param[in]  Register           Specifies the CPU register to read form the save state.   @param[in]  CpuIndex           Specifies the zero-based index of the CPU save state.   @param[out] Buffer             Upon return, this holds the CPU register value read from the save state.        @retval EFI_SUCCESS            The register was read from Save State.   @retval EFI_NOT_FOUND          The register is not defined for the Save State of Processor.   @retval EFI_INVALID_PARAMETER  Input parameters are not valid, for example, Processor No or register width                                   is not correct.This or Buffer is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_READ_SAVE_STATE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_CPU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|Width
parameter_list|,
name|IN
name|EFI_SMM_SAVE_STATE_REGISTER
name|Register
parameter_list|,
name|IN
name|UINTN
name|CpuIndex
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Write data to the CPU save state.    This function is used to write the specified number of bytes of the specified register to the CPU save    state of the specified CPU and place the value into the buffer. If the CPU does not support the    specified register Register, then EFI_UNSUPPORTED should be returned. If the CPU does not    support the specified register width Width, then EFI_INVALID_PARAMETER is returned.    @param[in]  This               The EFI_SMM_CPU_PROTOCOL instance.   @param[in]  Width              The number of bytes to write to the CPU save state.   @param[in]  Register           Specifies the CPU register to write to the save state.   @param[in]  CpuIndex           Specifies the zero-based index of the CPU save state.   @param[in]  Buffer             Upon entry, this holds the new CPU register value.      @retval EFI_SUCCESS            The register was written to Save State.   @retval EFI_NOT_FOUND          The register is not defined for the Save State of Processor.   @retval EFI_INVALID_PARAMETER  Input parameters are not valid. For example:                                   ProcessorIndex or Width is not correct. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_WRITE_SAVE_STATE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_CPU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|Width
parameter_list|,
name|IN
name|EFI_SMM_SAVE_STATE_REGISTER
name|Register
parameter_list|,
name|IN
name|UINTN
name|CpuIndex
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI SMM CPU Protocol provides access to CPU-related information while in SMM.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol allows SMM drivers to access architecture-standard registers from any of the CPU
end_comment

begin_comment
comment|/// save state areas. In some cases, difference processors provide the same information in the save state,
end_comment

begin_comment
comment|/// but not in the same format. These so-called pseudo-registers provide this information in a standard
end_comment

begin_comment
comment|/// format.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SMM_CPU_PROTOCOL
block|{
name|EFI_SMM_READ_SAVE_STATE
name|ReadSaveState
decl_stmt|;
name|EFI_SMM_WRITE_SAVE_STATE
name|WriteSaveState
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmmCpuProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

