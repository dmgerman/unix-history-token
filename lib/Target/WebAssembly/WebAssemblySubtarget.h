begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- WebAssemblySubtarget.h - Define Subtarget for the WebAssembly -*- C++ -*-//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file declares the WebAssembly-specific subclass of
end_comment

begin_comment
comment|/// TargetSubtarget.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYSUBTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYSUBTARGET_H
end_define

begin_include
include|#
directive|include
file|"WebAssemblyFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"WebAssemblyISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"WebAssemblyInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"WebAssemblySelectionDAGInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetSubtargetInfo.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"WebAssemblyGenSubtargetInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|WebAssemblySubtarget
name|final
range|:
name|public
name|WebAssemblyGenSubtargetInfo
block|{
name|bool
name|HasSIMD128
block|;
comment|/// String name of used CPU.
name|std
operator|::
name|string
name|CPUString
block|;
comment|/// What processor and OS we're targeting.
name|Triple
name|TargetTriple
block|;
name|WebAssemblyFrameLowering
name|FrameLowering
block|;
name|WebAssemblyInstrInfo
name|InstrInfo
block|;
name|WebAssemblySelectionDAGInfo
name|TSInfo
block|;
name|WebAssemblyTargetLowering
name|TLInfo
block|;
comment|/// Initializes using CPUString and the passed in feature string so that we
comment|/// can use initializer lists for subtarget initialization.
name|WebAssemblySubtarget
operator|&
name|initializeSubtargetDependencies
argument_list|(
argument|StringRef FS
argument_list|)
block|;
name|public
operator|:
comment|/// This constructor initializes the data members to match that
comment|/// of the specified triple.
name|WebAssemblySubtarget
argument_list|(
specifier|const
name|Triple
operator|&
name|TT
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|CPU
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|FS
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
specifier|const
name|WebAssemblySelectionDAGInfo
operator|*
name|getSelectionDAGInfo
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|TSInfo
return|;
block|}
specifier|const
name|WebAssemblyFrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|FrameLowering
return|;
block|}
specifier|const
name|WebAssemblyTargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|TLInfo
return|;
block|}
specifier|const
name|WebAssemblyInstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|InstrInfo
return|;
block|}
specifier|const
name|WebAssemblyRegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|getInstrInfo
argument_list|()
operator|->
name|getRegisterInfo
argument_list|()
return|;
block|}
specifier|const
name|Triple
operator|&
name|getTargetTriple
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
return|;
block|}
name|bool
name|enableMachineScheduler
argument_list|()
specifier|const
name|override
block|;
name|bool
name|useAA
argument_list|()
specifier|const
name|override
block|;
comment|// Predicates used by WebAssemblyInstrInfo.td.
name|bool
name|hasAddr64
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|isArch64Bit
argument_list|()
return|;
block|}
name|bool
name|hasSIMD128
argument_list|()
specifier|const
block|{
return|return
name|HasSIMD128
return|;
block|}
comment|/// Parses features string setting specified subtarget options. Definition of
comment|/// function is auto generated by tblgen.
name|void
name|ParseSubtargetFeatures
argument_list|(
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

