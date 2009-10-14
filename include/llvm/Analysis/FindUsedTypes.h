begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/FindUsedTypes.h - Find all Types in use ----*- C++ -*-===//
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
comment|// This pass is used to seek out all of the types in use by the program.
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
name|LLVM_ANALYSIS_FINDUSEDTYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_FINDUSEDTYPES_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Type
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|FindUsedTypes
range|:
name|public
name|ModulePass
block|{
name|std
operator|::
name|set
operator|<
specifier|const
name|Type
operator|*
operator|>
name|UsedTypes
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|FindUsedTypes
argument_list|()
operator|:
name|ModulePass
argument_list|(
argument|&ID
argument_list|)
block|{}
comment|/// getTypes - After the pass has been run, return the set containing all of
comment|/// the types used in the module.
comment|///
specifier|const
name|std
operator|::
name|set
operator|<
specifier|const
name|Type
operator|*
operator|>
operator|&
name|getTypes
argument_list|()
specifier|const
block|{
return|return
name|UsedTypes
return|;
block|}
comment|/// Print the types found in the module.  If the optional Module parameter is
comment|/// passed in, then the types are printed symbolically if possible, using the
comment|/// symbol table from the module.
comment|///
name|void
name|print
argument_list|(
argument|raw_ostream&o
argument_list|,
argument|const Module *M
argument_list|)
specifier|const
block|;
name|private
operator|:
comment|/// IncorporateType - Incorporate one type and all of its subtypes into the
comment|/// collection of used types.
comment|///
name|void
name|IncorporateType
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// IncorporateValue - Incorporate all of the types used by this value.
comment|///
name|void
name|IncorporateValue
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
block|;
name|public
operator|:
comment|/// run - This incorporates all types used by the specified module
name|bool
name|runOnModule
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
comment|/// getAnalysisUsage - We do not modify anything.
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|{
name|AU
operator|.
name|setPreservesAll
argument_list|()
block|;   }
block|}
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

