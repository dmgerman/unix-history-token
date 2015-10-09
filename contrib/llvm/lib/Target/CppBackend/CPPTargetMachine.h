begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CPPTargetMachine.h - TargetMachine for the C++ backend --*- C++ -*-===//
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
comment|// This file declares the TargetMachine that is used by the C++ backend.
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
name|LLVM_LIB_TARGET_CPPBACKEND_CPPTARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_CPPBACKEND_CPPTARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetSubtargetInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|formatted_raw_ostream
decl_stmt|;
name|struct
name|CPPTargetMachine
range|:
name|public
name|TargetMachine
block|{
name|CPPTargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|const Triple&TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetOptions&Options
argument_list|,
argument|Reloc::Model RM
argument_list|,
argument|CodeModel::Model CM
argument_list|,
argument|CodeGenOpt::Level OL
argument_list|)
operator|:
name|TargetMachine
argument_list|(
argument|T
argument_list|,
literal|""
argument_list|,
argument|TT
argument_list|,
argument|CPU
argument_list|,
argument|FS
argument_list|,
argument|Options
argument_list|)
block|{}
name|public
operator|:
name|bool
name|addPassesToEmitFile
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|raw_pwrite_stream&Out
argument_list|,
argument|CodeGenFileType FileType
argument_list|,
argument|bool DisableVerify
argument_list|,
argument|AnalysisID StartBefore
argument_list|,
argument|AnalysisID StartAfter
argument_list|,
argument|AnalysisID StopAfter
argument_list|,
argument|MachineFunctionInitializer *MFInitializer
argument_list|)
name|override
block|; }
decl_stmt|;
specifier|extern
name|Target
name|TheCppBackendTarget
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

