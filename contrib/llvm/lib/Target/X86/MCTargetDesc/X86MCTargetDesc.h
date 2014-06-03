begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86MCTargetDesc.h - X86 Target Descriptions -------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file provides X86 specific target descriptions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|X86MCTARGETDESC_H
end_ifndef

begin_define
define|#
directive|define
name|X86MCTARGETDESC_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmBackend
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCInstrInfo
decl_stmt|;
name|class
name|MCObjectWriter
decl_stmt|;
name|class
name|MCRegisterInfo
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|MCRelocationInfo
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
specifier|extern
name|Target
name|TheX86_32Target
decl_stmt|,
name|TheX86_64Target
decl_stmt|;
comment|/// DWARFFlavour - Flavour of dwarf regnumbers
comment|///
name|namespace
name|DWARFFlavour
block|{
enum|enum
block|{
name|X86_64
init|=
literal|0
block|,
name|X86_32_DarwinEH
init|=
literal|1
block|,
name|X86_32_Generic
init|=
literal|2
block|}
enum|;
block|}
comment|/// N86 namespace - Native X86 register numbers
comment|///
name|namespace
name|N86
block|{
enum|enum
block|{
name|EAX
init|=
literal|0
block|,
name|ECX
init|=
literal|1
block|,
name|EDX
init|=
literal|2
block|,
name|EBX
init|=
literal|3
block|,
name|ESP
init|=
literal|4
block|,
name|EBP
init|=
literal|5
block|,
name|ESI
init|=
literal|6
block|,
name|EDI
init|=
literal|7
block|}
enum|;
block|}
name|namespace
name|X86_MC
block|{
name|std
operator|::
name|string
name|ParseX86Triple
argument_list|(
argument|StringRef TT
argument_list|)
expr_stmt|;
comment|/// GetCpuIDAndInfo - Execute the specified cpuid and return the 4 values in
comment|/// the specified arguments.  If we can't run cpuid on the host, return true.
name|bool
name|GetCpuIDAndInfo
parameter_list|(
name|unsigned
name|value
parameter_list|,
name|unsigned
modifier|*
name|rEAX
parameter_list|,
name|unsigned
modifier|*
name|rEBX
parameter_list|,
name|unsigned
modifier|*
name|rECX
parameter_list|,
name|unsigned
modifier|*
name|rEDX
parameter_list|)
function_decl|;
comment|/// GetCpuIDAndInfoEx - Execute the specified cpuid with subleaf and return
comment|/// the 4 values in the specified arguments.  If we can't run cpuid on the
comment|/// host, return true.
name|bool
name|GetCpuIDAndInfoEx
parameter_list|(
name|unsigned
name|value
parameter_list|,
name|unsigned
name|subleaf
parameter_list|,
name|unsigned
modifier|*
name|rEAX
parameter_list|,
name|unsigned
modifier|*
name|rEBX
parameter_list|,
name|unsigned
modifier|*
name|rECX
parameter_list|,
name|unsigned
modifier|*
name|rEDX
parameter_list|)
function_decl|;
name|void
name|DetectFamilyModel
parameter_list|(
name|unsigned
name|EAX
parameter_list|,
name|unsigned
modifier|&
name|Family
parameter_list|,
name|unsigned
modifier|&
name|Model
parameter_list|)
function_decl|;
name|unsigned
name|getDwarfRegFlavour
parameter_list|(
name|StringRef
name|TT
parameter_list|,
name|bool
name|isEH
parameter_list|)
function_decl|;
name|void
name|InitLLVM2SEHRegisterMapping
parameter_list|(
name|MCRegisterInfo
modifier|*
name|MRI
parameter_list|)
function_decl|;
comment|/// createX86MCSubtargetInfo - Create a X86 MCSubtargetInfo instance.
comment|/// This is exposed so Asm parser, etc. do not need to go through
comment|/// TargetRegistry.
name|MCSubtargetInfo
modifier|*
name|createX86MCSubtargetInfo
parameter_list|(
name|StringRef
name|TT
parameter_list|,
name|StringRef
name|CPU
parameter_list|,
name|StringRef
name|FS
parameter_list|)
function_decl|;
block|}
name|MCCodeEmitter
modifier|*
name|createX86MCCodeEmitter
parameter_list|(
specifier|const
name|MCInstrInfo
modifier|&
name|MCII
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|&
name|MRI
parameter_list|,
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|,
name|MCContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
name|MCAsmBackend
modifier|*
name|createX86_32AsmBackend
parameter_list|(
specifier|const
name|Target
modifier|&
name|T
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|&
name|MRI
parameter_list|,
name|StringRef
name|TT
parameter_list|,
name|StringRef
name|CPU
parameter_list|)
function_decl|;
name|MCAsmBackend
modifier|*
name|createX86_64AsmBackend
parameter_list|(
specifier|const
name|Target
modifier|&
name|T
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|&
name|MRI
parameter_list|,
name|StringRef
name|TT
parameter_list|,
name|StringRef
name|CPU
parameter_list|)
function_decl|;
comment|/// createX86MachObjectWriter - Construct an X86 Mach-O object writer.
name|MCObjectWriter
modifier|*
name|createX86MachObjectWriter
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|bool
name|Is64Bit
parameter_list|,
name|uint32_t
name|CPUType
parameter_list|,
name|uint32_t
name|CPUSubtype
parameter_list|)
function_decl|;
comment|/// createX86ELFObjectWriter - Construct an X86 ELF object writer.
name|MCObjectWriter
modifier|*
name|createX86ELFObjectWriter
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|bool
name|IsELF64
parameter_list|,
name|uint8_t
name|OSABI
parameter_list|,
name|uint16_t
name|EMachine
parameter_list|)
function_decl|;
comment|/// createX86WinCOFFObjectWriter - Construct an X86 Win COFF object writer.
name|MCObjectWriter
modifier|*
name|createX86WinCOFFObjectWriter
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|bool
name|Is64Bit
parameter_list|)
function_decl|;
comment|/// createX86_64MachORelocationInfo - Construct X86-64 Mach-O relocation info.
name|MCRelocationInfo
modifier|*
name|createX86_64MachORelocationInfo
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
comment|/// createX86_64ELFORelocationInfo - Construct X86-64 ELF relocation info.
name|MCRelocationInfo
modifier|*
name|createX86_64ELFRelocationInfo
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_comment
comment|// Defines symbolic names for X86 registers.  This defines a mapping from
end_comment

begin_comment
comment|// register name to register number.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|GET_REGINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"X86GenRegisterInfo.inc"
end_include

begin_comment
comment|// Defines symbolic names for the X86 instructions.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|GET_INSTRINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"X86GenInstrInfo.inc"
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"X86GenSubtargetInfo.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

