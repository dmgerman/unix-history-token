begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ValueMapper.h - Interface shared by lib/Transforms/Utils -*- C++ -*-===//
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
comment|// This file defines the MapValue interface which is used by various parts of
end_comment

begin_comment
comment|// the Transforms/Utils library to implement cloning and linking facilities.
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
name|VALUEMAPPER_H
end_ifndef

begin_define
define|#
directive|define
name|VALUEMAPPER_H
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
name|class
name|Instruction
decl_stmt|;
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
operator|,
name|Value
operator|*
operator|>
name|ValueMapTy
expr_stmt|;
name|Value
modifier|*
name|MapValue
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
name|ValueMapTy
modifier|&
name|VM
parameter_list|)
function_decl|;
name|void
name|RemapInstruction
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
name|ValueMapTy
modifier|&
name|VM
parameter_list|)
function_decl|;
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

