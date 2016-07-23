begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- TailRecursionElimination.h ----------------------------*- C++ -*-===//
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
comment|// This file transforms calls of the current function (self recursion) followed
end_comment

begin_comment
comment|// by a return instruction with a branch to the entry of the function, creating
end_comment

begin_comment
comment|// a loop.  This pass also implements the following extensions to the basic
end_comment

begin_comment
comment|// algorithm:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  1. Trivial instructions between the call and return do not prevent the
end_comment

begin_comment
comment|//     transformation from taking place, though currently the analysis cannot
end_comment

begin_comment
comment|//     support moving any really useful instructions (only dead ones).
end_comment

begin_comment
comment|//  2. This pass transforms functions that are prevented from being tail
end_comment

begin_comment
comment|//     recursive by an associative and commutative expression to use an
end_comment

begin_comment
comment|//     accumulator variable, thus compiling the typical naive factorial or
end_comment

begin_comment
comment|//     'fib' implementation into efficient code.
end_comment

begin_comment
comment|//  3. TRE is performed if the function returns void, if the return
end_comment

begin_comment
comment|//     returns the result returned by the call, or if the function returns a
end_comment

begin_comment
comment|//     run-time constant on all exits from the function.  It is possible, though
end_comment

begin_comment
comment|//     unlikely, that the return returns something else (like constant 0), and
end_comment

begin_comment
comment|//     can still be TRE'd.  It can be TRE'd if ALL OTHER return instructions in
end_comment

begin_comment
comment|//     the function return the exact same value.
end_comment

begin_comment
comment|//  4. If it can prove that callees do not access their caller stack frame,
end_comment

begin_comment
comment|//     they are marked as eligible for tail call elimination (by the code
end_comment

begin_comment
comment|//     generator).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// There are several improvements that could be made:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  1. If the function has any alloca instructions, these instructions will be
end_comment

begin_comment
comment|//     moved out of the entry block of the function, causing them to be
end_comment

begin_comment
comment|//     evaluated each time through the tail recursion.  Safely keeping allocas
end_comment

begin_comment
comment|//     in the entry block requires analysis to proves that the tail-called
end_comment

begin_comment
comment|//     function does not read or write the stack object.
end_comment

begin_comment
comment|//  2. Tail recursion is only performed if the call immediately precedes the
end_comment

begin_comment
comment|//     return instruction.  It's possible that there could be a jump between
end_comment

begin_comment
comment|//     the call and the return.
end_comment

begin_comment
comment|//  3. There can be intervening operations between the call and the return that
end_comment

begin_comment
comment|//     prevent the TRE from occurring.  For example, there could be GEP's and
end_comment

begin_comment
comment|//     stores to memory that will not be read or written by the call.  This
end_comment

begin_comment
comment|//     requires some substantial analysis (such as with DSA) to prove safe to
end_comment

begin_comment
comment|//     move ahead of the call, but doing so could allow many more TREs to be
end_comment

begin_comment
comment|//     performed, for example in TreeAdd/TreeAlloc from the treeadd benchmark.
end_comment

begin_comment
comment|//  4. The algorithm we use to detect if callees access their caller stack
end_comment

begin_comment
comment|//     frames is very primitive.
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
name|LLVM_TRANSFORMS_SCALAR_TAILRECURSIONELIMINATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_TAILRECURSIONELIMINATION_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|struct
name|TailCallElimPass
range|:
name|PassInfoMixin
operator|<
name|TailCallElimPass
operator|>
block|{
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_SCALAR_TAILRECURSIONELIMINATION_H
end_comment

end_unit

