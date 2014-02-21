begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMMCTargetDesc.h - ARM Target Descriptions -------------*- C++ -*-===//
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
comment|// This file provides ARM specific target descriptions.
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
name|ARMMCTARGETDESC_H
end_ifndef

begin_define
define|#
directive|define
name|ARMMCTARGETDESC_H
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
name|formatted_raw_ostream
decl_stmt|;
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
name|MCInstPrinter
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
name|MCStreamer
decl_stmt|;
name|class
name|MCRelocationInfo
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
specifier|extern
name|Target
name|TheARMTarget
decl_stmt|,
name|TheThumbTarget
decl_stmt|;
name|namespace
name|ARM_MC
block|{
name|std
operator|::
name|string
name|ParseARMTriple
argument_list|(
argument|StringRef TT
argument_list|,
argument|StringRef CPU
argument_list|)
expr_stmt|;
comment|/// createARMMCSubtargetInfo - Create a ARM MCSubtargetInfo instance.
comment|/// This is exposed so Asm parser, etc. do not need to go through
comment|/// TargetRegistry.
name|MCSubtargetInfo
modifier|*
name|createARMMCSubtargetInfo
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
name|MCStreamer
modifier|*
name|createMCAsmStreamer
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|,
name|formatted_raw_ostream
modifier|&
name|OS
parameter_list|,
name|bool
name|isVerboseAsm
parameter_list|,
name|bool
name|useLoc
parameter_list|,
name|bool
name|useCFI
parameter_list|,
name|bool
name|useDwarfDirectory
parameter_list|,
name|MCInstPrinter
modifier|*
name|InstPrint
parameter_list|,
name|MCCodeEmitter
modifier|*
name|CE
parameter_list|,
name|MCAsmBackend
modifier|*
name|TAB
parameter_list|,
name|bool
name|ShowInst
parameter_list|)
function_decl|;
name|MCCodeEmitter
modifier|*
name|createARMMCCodeEmitter
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
name|createARMAsmBackend
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
comment|/// createARMELFObjectWriter - Construct an ELF Mach-O object writer.
name|MCObjectWriter
modifier|*
name|createARMELFObjectWriter
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|uint8_t
name|OSABI
parameter_list|)
function_decl|;
comment|/// createARMMachObjectWriter - Construct an ARM Mach-O object writer.
name|MCObjectWriter
modifier|*
name|createARMMachObjectWriter
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
comment|/// createARMMachORelocationInfo - Construct ARM Mach-O relocation info.
name|MCRelocationInfo
modifier|*
name|createARMMachORelocationInfo
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
comment|// Defines symbolic names for ARM registers.  This defines a mapping from
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
file|"ARMGenRegisterInfo.inc"
end_include

begin_comment
comment|// Defines symbolic names for the ARM instructions.
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
file|"ARMGenInstrInfo.inc"
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"ARMGenSubtargetInfo.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

