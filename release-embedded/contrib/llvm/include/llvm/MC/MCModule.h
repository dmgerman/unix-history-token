begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCModule.h - MCModule class ---------------------*- C++ -*-===//
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
comment|// This file contains the declaration of the MCModule class, which is used to
end_comment

begin_comment
comment|// represent a complete, disassembled object file or executable.
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
name|LLVM_MC_MCMODULE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCMODULE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntervalMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAtom
decl_stmt|;
comment|/// MCModule - This class represent a completely disassembled object file or
comment|/// executable.  It comprises a list of MCAtom's, and a branch target table.
comment|/// Each atom represents a contiguous range of either instructions or data.
name|class
name|MCModule
block|{
comment|/// AtomAllocationTracker - An MCModule owns its component MCAtom's, so it
comment|/// must track them in order to ensure they are properly freed as atoms are
comment|/// merged or otherwise manipulated.
name|SmallPtrSet
operator|<
name|MCAtom
operator|*
operator|,
literal|8
operator|>
name|AtomAllocationTracker
expr_stmt|;
comment|/// OffsetMap - Efficiently maps offset ranges to MCAtom's.
name|IntervalMap
operator|<
name|uint64_t
operator|,
name|MCAtom
operator|*
operator|>
name|OffsetMap
expr_stmt|;
comment|/// BranchTargetMap - Maps offsets that are determined to be branches and
comment|/// can be statically resolved to their target offsets.
name|DenseMap
operator|<
name|uint64_t
operator|,
name|MCAtom
operator|*
operator|>
name|BranchTargetMap
expr_stmt|;
name|friend
name|class
name|MCAtom
decl_stmt|;
comment|/// remap - Update the interval mapping for an MCAtom.
name|void
name|remap
parameter_list|(
name|MCAtom
modifier|*
name|Atom
parameter_list|,
name|uint64_t
name|NewBegin
parameter_list|,
name|uint64_t
name|NewEnd
parameter_list|)
function_decl|;
name|public
label|:
name|MCModule
argument_list|(
name|IntervalMap
operator|<
name|uint64_t
argument_list|,
name|MCAtom
operator|*
operator|>
operator|::
name|Allocator
operator|&
name|A
argument_list|)
operator|:
name|OffsetMap
argument_list|(
argument|A
argument_list|)
block|{ }
comment|/// createAtom - Creates a new MCAtom covering the specified offset range.
name|MCAtom
operator|*
name|createAtom
argument_list|(
argument|MCAtom::AtomType Type
argument_list|,
argument|uint64_t Begin
argument_list|,
argument|uint64_t End
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

