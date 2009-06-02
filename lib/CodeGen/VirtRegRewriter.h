begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/VirtRegRewriter.h - VirtRegRewriter -*- C++ -*--------===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_VIRTREGREWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_VIRTREGREWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IndexedMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Streams.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LiveIntervalAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFrameInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstrBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"VirtRegMap.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_comment
comment|// TODO:
end_comment

begin_comment
comment|//       - Finish renaming Spiller -> Rewriter
end_comment

begin_comment
comment|//         - SimpleSpiller
end_comment

begin_comment
comment|//         - LocalSpiller
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// VirtRegRewriter interface: Implementations of this interface assign
comment|/// spilled virtual registers to stack slots, rewriting the code.
struct|struct
name|VirtRegRewriter
block|{
name|virtual
operator|~
name|VirtRegRewriter
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|runOnMachineFunction
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|,
name|VirtRegMap
modifier|&
name|VRM
parameter_list|,
name|LiveIntervals
modifier|*
name|LIs
parameter_list|)
init|=
literal|0
function_decl|;
block|}
struct|;
comment|/// createVirtRegRewriter - Create an return a rewriter object, as specified
comment|/// on the command line.
name|VirtRegRewriter
modifier|*
name|createVirtRegRewriter
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

