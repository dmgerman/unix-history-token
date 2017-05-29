begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AtomicExpandUtils.h - Utilities for expanding atomic instructions --===//
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
name|LLVM_CODEGEN_ATOMICEXPANDUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_ATOMICEXPANDUTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IRBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/AtomicOrdering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AtomicRMWInst
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// Parameters (see the expansion example below):
comment|/// (the builder, %addr, %loaded, %new_val, ordering,
comment|///  /* OUT */ %success, /* OUT */ %new_loaded)
name|using
name|CreateCmpXchgInstFun
init|=
name|function_ref
operator|<
name|void
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
argument_list|,
name|Value
operator|*
argument_list|,
name|Value
operator|*
argument_list|,
name|Value
operator|*
argument_list|,
name|AtomicOrdering
argument_list|,
name|Value
operator|*
operator|&
argument_list|,
name|Value
operator|*
operator|&
argument_list|)
operator|>
decl_stmt|;
comment|/// \brief Expand an atomic RMW instruction into a loop utilizing
comment|/// cmpxchg. You'll want to make sure your target machine likes cmpxchg
comment|/// instructions in the first place and that there isn't another, better,
comment|/// transformation available (for example AArch32/AArch64 have linked loads).
comment|///
comment|/// This is useful in passes which can't rewrite the more exotic RMW
comment|/// instructions directly into a platform specific intrinsics (because, say,
comment|/// those intrinsics don't exist). If such a pass is able to expand cmpxchg
comment|/// instructions directly however, then, with this function, it could avoid two
comment|/// extra module passes (avoiding passes by `-atomic-expand` and itself). A
comment|/// specific example would be PNaCl's `RewriteAtomics` pass.
comment|///
comment|/// Given: atomicrmw some_op iN* %addr, iN %incr ordering
comment|///
comment|/// The standard expansion we produce is:
comment|///     [...]
comment|///     %init_loaded = load atomic iN* %addr
comment|///     br label %loop
comment|/// loop:
comment|///     %loaded = phi iN [ %init_loaded, %entry ], [ %new_loaded, %loop ]
comment|///     %new = some_op iN %loaded, %incr
comment|/// ; This is what -atomic-expand will produce using this function on i686
comment|/// targets:
comment|///     %pair = cmpxchg iN* %addr, iN %loaded, iN %new_val
comment|///     %new_loaded = extractvalue { iN, i1 } %pair, 0
comment|///     %success = extractvalue { iN, i1 } %pair, 1
comment|/// ; End callback produced IR
comment|///     br i1 %success, label %atomicrmw.end, label %loop
comment|/// atomicrmw.end:
comment|///     [...]
comment|///
comment|/// Returns true if the containing function was modified.
name|bool
name|expandAtomicRMWToCmpXchg
parameter_list|(
name|AtomicRMWInst
modifier|*
name|AI
parameter_list|,
name|CreateCmpXchgInstFun
name|Factory
parameter_list|)
function_decl|;
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
comment|// LLVM_CODEGEN_ATOMICEXPANDUTILS_H
end_comment

end_unit

