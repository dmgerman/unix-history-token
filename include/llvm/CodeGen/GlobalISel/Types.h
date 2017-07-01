begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/CodeGen/GlobalISel/Types.h - Types used by GISel ----*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// This file describes high level types that are used by several passes or
end_comment

begin_comment
comment|/// APIs involved in the GlobalISel pipeline.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_GLOBALISEL_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_TYPES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
comment|/// Map a value to a virtual register.
comment|/// For now, we chose to map aggregate types to on single virtual
comment|/// register. This might be revisited if it turns out to be inefficient.
comment|/// PR26161 tracks that.
comment|/// Note: We need to expose this type to the target hooks for thing like
comment|/// ABI lowering that would be used during IRTranslation.
name|using
name|ValueToVReg
init|=
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
decl_stmt|,
name|unsigned
decl|>
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
comment|// LLVM_CODEGEN_GLOBALISEL_TYPES_H
end_comment

end_unit

