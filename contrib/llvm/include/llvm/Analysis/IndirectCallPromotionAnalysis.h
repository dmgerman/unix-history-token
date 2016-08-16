begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IndirectCallPromotionAnalysis.h - Indirect call analysis -*- C++ -*-===//
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
comment|/// Interface to identify indirect call promotion candidates.
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
name|LLVM_ANALYSIS_INDIRECTCALLPROMOTIONANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_INDIRECTCALLPROMOTIONANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ProfileData/InstrProf.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Instruction
decl_stmt|;
comment|// Class for identifying profitable indirect call promotion candidates when
comment|// the indirect-call value profile metadata is available.
name|class
name|ICallPromotionAnalysis
block|{
name|private
label|:
comment|// Allocate space to read the profile annotation.
name|std
operator|::
name|unique_ptr
operator|<
name|InstrProfValueData
index|[]
operator|>
name|ValueDataArray
expr_stmt|;
comment|// Count is the call count for the direct-call target and
comment|// TotalCount is the call count for the indirect-call callsite.
comment|// Return true we should promote this indirect-call target.
name|bool
name|isPromotionProfitable
parameter_list|(
name|uint64_t
name|Count
parameter_list|,
name|uint64_t
name|TotalCount
parameter_list|)
function_decl|;
comment|// Returns the number of profitable candidates to promote for the
comment|// current ValueDataArray and the given \p Inst.
name|uint32_t
name|getProfitablePromotionCandidates
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|Inst
parameter_list|,
name|uint32_t
name|NumVals
parameter_list|,
name|uint64_t
name|TotalCount
parameter_list|)
function_decl|;
comment|// Noncopyable
name|ICallPromotionAnalysis
argument_list|(
specifier|const
name|ICallPromotionAnalysis
operator|&
name|other
argument_list|)
operator|=
name|delete
expr_stmt|;
name|ICallPromotionAnalysis
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ICallPromotionAnalysis
operator|&
name|other
operator|)
operator|=
name|delete
decl_stmt|;
name|public
label|:
name|ICallPromotionAnalysis
argument_list|()
expr_stmt|;
comment|/// \brief Returns reference to array of InstrProfValueData for the given
comment|/// instruction \p I.
comment|///
comment|/// The \p NumVals, \p TotalCount and \p NumCandidates
comment|/// are set to the number of values in the array, the total profile count
comment|/// of the indirect call \p I, and the number of profitable candidates
comment|/// in the given array (which is sorted in reverse order of profitability).
comment|///
comment|/// The returned array space is owned by this class, and overwritten on
comment|/// subsequent calls.
name|ArrayRef
operator|<
name|InstrProfValueData
operator|>
name|getPromotionCandidatesForInstruction
argument_list|(
specifier|const
name|Instruction
operator|*
name|I
argument_list|,
name|uint32_t
operator|&
name|NumVals
argument_list|,
name|uint64_t
operator|&
name|TotalCount
argument_list|,
name|uint32_t
operator|&
name|NumCandidates
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
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

