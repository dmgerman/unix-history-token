begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//- WebAssemblyISelLowering.h - WebAssembly DAG Lowering Interface -*- C++ -*-//
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
comment|/// \brief This file defines the interfaces that WebAssembly uses to lower LLVM
end_comment

begin_comment
comment|/// code into a selection DAG.
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
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|WebAssemblyISD
block|{
enum|enum
block|{
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
comment|// add memory opcodes starting at ISD::FIRST_TARGET_MEMORY_OPCODE here...
block|}
enum|;
block|}
comment|// end namespace WebAssemblyISD
name|class
name|WebAssemblySubtarget
decl_stmt|;
name|class
name|WebAssemblyTargetMachine
decl_stmt|;
name|class
name|WebAssemblyTargetLowering
name|final
range|:
name|public
name|TargetLowering
block|{
name|public
operator|:
name|WebAssemblyTargetLowering
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|WebAssemblySubtarget
operator|&
name|STI
argument_list|)
block|;
name|private
operator|:
comment|/// Keep a pointer to the WebAssemblySubtarget around so that we can make the
comment|/// right decision when generating code for different targets.
specifier|const
name|WebAssemblySubtarget
operator|*
name|Subtarget
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

