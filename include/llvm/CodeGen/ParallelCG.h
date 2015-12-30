begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/ParallelCG.h - Parallel code generation ----*- C++ -*-===//
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
comment|// This header declares functions that can be used for parallel code generation.
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
name|LLVM_CODEGEN_PARALLELCG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_PARALLELCG_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|TargetOptions
decl_stmt|;
name|class
name|raw_pwrite_stream
decl_stmt|;
comment|/// Split M into OSs.size() partitions, and generate code for each. Writes
comment|/// OSs.size() output files to the output streams in OSs. The resulting output
comment|/// files if linked together are intended to be equivalent to the single output
comment|/// file that would have been code generated from M.
comment|///
comment|/// \returns M if OSs.size() == 1, otherwise returns std::unique_ptr<Module>().
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|splitCodeGen
argument_list|(
argument|std::unique_ptr<Module> M
argument_list|,
argument|ArrayRef<raw_pwrite_stream *> OSs
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef Features
argument_list|,
argument|const TargetOptions&Options
argument_list|,
argument|Reloc::Model RM = Reloc::Default
argument_list|,
argument|CodeModel::Model CM = CodeModel::Default
argument_list|,
argument|CodeGenOpt::Level OL = CodeGenOpt::Default
argument_list|,
argument|TargetMachine::CodeGenFileType FT = TargetMachine::CGFT_ObjectFile
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

