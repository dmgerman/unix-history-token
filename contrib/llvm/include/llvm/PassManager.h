begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/PassManager.h - Container for Passes ----------------*- C++ -*-===//
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
comment|// This is a legacy redirect header for the old PassManager. It is intended to
end_comment

begin_comment
comment|// be used by clients that have not been converted to be aware of the new pass
end_comment

begin_comment
comment|// management infrastructure being built for LLVM, which is every client
end_comment

begin_comment
comment|// initially. Eventually this header (and the legacy management layer) will go
end_comment

begin_comment
comment|// away, but we want to minimize changes to out-of-tree users of LLVM in the
end_comment

begin_comment
comment|// interim.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that this header *must not* be included into the same file as the new
end_comment

begin_comment
comment|// pass management infrastructure is included. Things will break spectacularly.
end_comment

begin_comment
comment|// If you are starting that conversion, you should switch to explicitly
end_comment

begin_comment
comment|// including LegacyPassManager.h and using the legacy namespace.
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
name|LLVM_PASSMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PASSMANAGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/LegacyPassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Pull these into the llvm namespace so that existing code that expects it
comment|// there can find it.
name|using
name|legacy
operator|::
name|PassManagerBase
expr_stmt|;
name|using
name|legacy
operator|::
name|PassManager
expr_stmt|;
name|using
name|legacy
operator|::
name|FunctionPassManager
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

