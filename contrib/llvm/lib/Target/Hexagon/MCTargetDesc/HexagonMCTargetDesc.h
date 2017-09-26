begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HexagonMCTargetDesc.h - Hexagon Target Descriptions -----*- C++ -*-===//
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
comment|// This file provides Hexagon specific target descriptions.
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
name|LLVM_LIB_TARGET_HEXAGON_MCTARGETDESC_HEXAGONMCTARGETDESC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_MCTARGETDESC_HEXAGONMCTARGETDESC_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct_decl|struct
name|InstrItinerary
struct_decl|;
struct_decl|struct
name|InstrStage
struct_decl|;
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
name|MCTargetOptions
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|Triple
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|raw_pwrite_stream
decl_stmt|;
name|Target
modifier|&
name|getTheHexagonTarget
parameter_list|()
function_decl|;
extern|extern cl::opt<bool> HexagonDisableCompound;
extern|extern cl::opt<bool> HexagonDisableDuplex;
specifier|extern
specifier|const
name|InstrStage
name|HexagonStages
index|[]
decl_stmt|;
name|MCInstrInfo
modifier|*
name|createHexagonMCInstrInfo
parameter_list|()
function_decl|;
name|MCRegisterInfo
modifier|*
name|createHexagonMCRegisterInfo
parameter_list|(
name|StringRef
name|TT
parameter_list|)
function_decl|;
name|namespace
name|Hexagon_MC
block|{
name|StringRef
name|ParseHexagonTriple
parameter_list|(
specifier|const
name|Triple
modifier|&
name|TT
parameter_list|,
name|StringRef
name|CPU
parameter_list|)
function_decl|;
name|StringRef
name|selectHexagonCPU
parameter_list|(
specifier|const
name|Triple
modifier|&
name|TT
parameter_list|,
name|StringRef
name|CPU
parameter_list|)
function_decl|;
comment|/// Create a Hexagon MCSubtargetInfo instance. This is exposed so Asm parser,
comment|/// etc. do not need to go through TargetRegistry.
name|MCSubtargetInfo
modifier|*
name|createHexagonMCSubtargetInfo
parameter_list|(
specifier|const
name|Triple
modifier|&
name|TT
parameter_list|,
name|StringRef
name|CPU
parameter_list|,
name|StringRef
name|FS
parameter_list|)
function_decl|;
name|unsigned
name|GetELFFlags
parameter_list|(
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|)
function_decl|;
block|}
name|MCCodeEmitter
modifier|*
name|createHexagonMCCodeEmitter
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
name|MCContext
modifier|&
name|MCT
parameter_list|)
function_decl|;
name|MCAsmBackend
modifier|*
name|createHexagonAsmBackend
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
specifier|const
name|Triple
modifier|&
name|TT
parameter_list|,
name|StringRef
name|CPU
parameter_list|,
specifier|const
name|MCTargetOptions
modifier|&
name|Options
parameter_list|)
function_decl|;
name|MCObjectWriter
modifier|*
name|createHexagonELFObjectWriter
parameter_list|(
name|raw_pwrite_stream
modifier|&
name|OS
parameter_list|,
name|uint8_t
name|OSABI
parameter_list|,
name|StringRef
name|CPU
parameter_list|)
function_decl|;
name|unsigned
name|HexagonGetLastSlot
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_comment
comment|// Define symbolic names for Hexagon registers.  This defines a mapping from
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
file|"HexagonGenRegisterInfo.inc"
end_include

begin_comment
comment|// Defines symbolic names for the Hexagon instructions.
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
file|"HexagonGenInstrInfo.inc"
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"HexagonGenSubtargetInfo.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_HEXAGON_MCTARGETDESC_HEXAGONMCTARGETDESC_H
end_comment

end_unit

