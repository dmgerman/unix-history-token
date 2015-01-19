begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CmpInstAnalysis.h - Utils to help fold compare insts ----*- C++ -*-===//
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
comment|// This file holds routines to help analyse compare instructions
end_comment

begin_comment
comment|// and fold them into constants or other compare instructions
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
name|LLVM_TRANSFORMS_UTILS_CMPINSTANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_CMPINSTANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/InstrTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ICmpInst
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// getICmpCode - Encode a icmp predicate into a three bit mask.  These bits
comment|/// are carefully arranged to allow folding of expressions such as:
comment|///
comment|///      (A< B) | (A> B) --> (A != B)
comment|///
comment|/// Note that this is only valid if the first and second predicates have the
comment|/// same sign. Is illegal to do: (A u< B) | (A s> B)
comment|///
comment|/// Three bits are used to represent the condition, as follows:
comment|///   0  A> B
comment|///   1  A == B
comment|///   2  A< B
comment|///
comment|///<=>  Value  Definition
comment|/// 000     0   Always false
comment|/// 001     1   A>  B
comment|/// 010     2   A == B
comment|/// 011     3   A>= B
comment|/// 100     4   A<  B
comment|/// 101     5   A != B
comment|/// 110     6   A<= B
comment|/// 111     7   Always true
comment|///
name|unsigned
name|getICmpCode
parameter_list|(
specifier|const
name|ICmpInst
modifier|*
name|ICI
parameter_list|,
name|bool
name|InvertPred
init|=
name|false
parameter_list|)
function_decl|;
comment|/// getICmpValue - This is the complement of getICmpCode, which turns an
comment|/// opcode and two operands into either a constant true or false, or the
comment|/// predicate for a new ICmp instruction. The sign is passed in to determine
comment|/// which kind of predicate to use in the new icmp instruction.
comment|/// Non-NULL return value will be a true or false constant.
comment|/// NULL return means a new ICmp is needed.  The predicate for which is
comment|/// output in NewICmpPred.
name|Value
modifier|*
name|getICmpValue
argument_list|(
name|bool
name|Sign
argument_list|,
name|unsigned
name|Code
argument_list|,
name|Value
operator|*
name|LHS
argument_list|,
name|Value
operator|*
name|RHS
argument_list|,
name|CmpInst
operator|::
name|Predicate
operator|&
name|NewICmpPred
argument_list|)
decl_stmt|;
comment|/// PredicatesFoldable - Return true if both predicates match sign or if at
comment|/// least one of them is an equality comparison (which is signless).
name|bool
name|PredicatesFoldable
argument_list|(
name|CmpInst
operator|::
name|Predicate
name|p1
argument_list|,
name|CmpInst
operator|::
name|Predicate
name|p2
argument_list|)
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

