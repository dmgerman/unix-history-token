begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HexagonTargetTransformInfo.cpp - Hexagon specific TTI pass --------===//
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
comment|/// \file
end_comment

begin_comment
comment|/// This file implements a TargetTransformInfo analysis pass specific to the
end_comment

begin_comment
comment|/// Hexagon target machine. It uses the target's detailed information to provide
end_comment

begin_comment
comment|/// more precise answers to certain TTI queries, while letting the target
end_comment

begin_comment
comment|/// independent and default TTI implementations handle the rest.
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
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONTARGETTRANSFORMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONTARGETTRANSFORMINFO_H
end_define

begin_include
include|#
directive|include
file|"Hexagon.h"
end_include

begin_include
include|#
directive|include
file|"HexagonTargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/TargetTransformInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/BasicTTIImpl.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|HexagonTTIImpl
range|:
name|public
name|BasicTTIImplBase
operator|<
name|HexagonTTIImpl
operator|>
block|{
typedef|typedef
name|BasicTTIImplBase
operator|<
name|HexagonTTIImpl
operator|>
name|BaseT
expr_stmt|;
typedef|typedef
name|TargetTransformInfo
name|TTI
typedef|;
name|friend
name|BaseT
decl_stmt|;
specifier|const
name|HexagonSubtarget
modifier|*
name|ST
decl_stmt|;
specifier|const
name|HexagonTargetLowering
modifier|*
name|TLI
decl_stmt|;
specifier|const
name|HexagonSubtarget
operator|*
name|getST
argument_list|()
specifier|const
block|{
return|return
name|ST
return|;
block|}
specifier|const
name|HexagonTargetLowering
operator|*
name|getTLI
argument_list|()
specifier|const
block|{
return|return
name|TLI
return|;
block|}
name|public
label|:
name|explicit
name|HexagonTTIImpl
argument_list|(
specifier|const
name|HexagonTargetMachine
operator|*
name|TM
argument_list|,
specifier|const
name|Function
operator|&
name|F
argument_list|)
operator|:
name|BaseT
argument_list|(
name|TM
argument_list|,
name|F
operator|.
name|getParent
argument_list|()
operator|->
name|getDataLayout
argument_list|()
argument_list|)
operator|,
name|ST
argument_list|(
name|TM
operator|->
name|getSubtargetImpl
argument_list|(
name|F
argument_list|)
argument_list|)
operator|,
name|TLI
argument_list|(
argument|ST->getTargetLowering()
argument_list|)
block|{}
comment|/// \name Scalar TTI Implementations
comment|/// @{
name|TTI
operator|::
name|PopcntSupportKind
name|getPopcntSupport
argument_list|(
argument|unsigned IntTyWidthInBit
argument_list|)
specifier|const
expr_stmt|;
comment|// The Hexagon target can unroll loops with run-time trip counts.
name|void
name|getUnrollingPreferences
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
name|ScalarEvolution
operator|&
name|SE
argument_list|,
name|TTI
operator|::
name|UnrollingPreferences
operator|&
name|UP
argument_list|)
decl_stmt|;
comment|// L1 cache prefetch.
name|unsigned
name|getPrefetchDistance
argument_list|()
specifier|const
expr_stmt|;
name|unsigned
name|getCacheLineSize
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
comment|/// \name Vector TTI Implementations
comment|/// @{
name|unsigned
name|getNumberOfRegisters
argument_list|(
name|bool
name|vector
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
name|int
name|getUserCost
argument_list|(
specifier|const
name|User
operator|*
name|U
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Value
operator|*
operator|>
name|Operands
argument_list|)
decl_stmt|;
comment|// Hexagon specific decision to generate a lookup table.
name|bool
name|shouldBuildLookupTables
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

