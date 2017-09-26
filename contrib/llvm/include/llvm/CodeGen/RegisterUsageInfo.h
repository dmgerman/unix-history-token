begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- RegisterUsageInfo.h - Register Usage Informartion Storage --*- C++ -*-==//
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
comment|/// \file
end_comment

begin_comment
comment|/// This pass is required to take advantage of the interprocedural register
end_comment

begin_comment
comment|/// allocation infrastructure.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This pass is simple immutable pass which keeps RegMasks (calculated based on
end_comment

begin_comment
comment|/// actual register allocation) for functions in a module and provides simple
end_comment

begin_comment
comment|/// API to query this information.
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
name|LLVM_CODEGEN_PHYSICALREGISTERUSAGEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_PHYSICALREGISTERUSAGEINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|PhysicalRegisterUsageInfo
range|:
name|public
name|ImmutablePass
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|PhysicalRegisterUsageInfo
argument_list|()
operator|:
name|ImmutablePass
argument_list|(
argument|ID
argument_list|)
block|{
name|PassRegistry
operator|&
name|Registry
operator|=
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
block|;
name|initializePhysicalRegisterUsageInfoPass
argument_list|(
name|Registry
argument_list|)
block|;   }
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|{
name|AU
operator|.
name|setPreservesAll
argument_list|()
block|;   }
comment|/// To set TargetMachine *, which is used to print
comment|/// analysis when command line option -print-regusage is used.
name|void
name|setTargetMachine
argument_list|(
argument|const TargetMachine *TM_
argument_list|)
block|{
name|TM
operator|=
name|TM_
block|; }
name|bool
name|doInitialization
argument_list|(
argument|Module&M
argument_list|)
name|override
block|;
name|bool
name|doFinalization
argument_list|(
argument|Module&M
argument_list|)
name|override
block|;
comment|/// To store RegMask for given Function *.
name|void
name|storeUpdateRegUsageInfo
argument_list|(
specifier|const
name|Function
operator|*
name|FP
argument_list|,
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|RegMask
argument_list|)
block|;
comment|/// To query stored RegMask for given Function *, it will return nullptr if
comment|/// function is not known.
specifier|const
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
operator|*
name|getRegUsageInfo
argument_list|(
specifier|const
name|Function
operator|*
name|FP
argument_list|)
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module *M = nullptr
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
comment|/// A Dense map from Function * to RegMask.
comment|/// In RegMask 0 means register used (clobbered) by function.
comment|/// and 1 means content of register will be preserved around function call.
name|DenseMap
operator|<
specifier|const
name|Function
operator|*
block|,
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>>
name|RegMasks
block|;
specifier|const
name|TargetMachine
operator|*
name|TM
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

begin_comment
comment|// LLVM_CODEGEN_PHYSICALREGISTERUSAGEINFO_H
end_comment

end_unit

