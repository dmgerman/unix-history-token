begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- yaml2obj.h - -------------------------------------------*- C++ -*-===//
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
comment|/// \brief Common declarations for yaml2obj
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TOOLS_YAML2OBJ_YAML2OBJ_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_YAML2OBJ_YAML2OBJ_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|namespace
name|yaml
block|{
name|class
name|Input
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|yaml2coff
argument_list|(
name|llvm
operator|::
name|yaml
operator|::
name|Input
operator|&
name|YIn
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|Out
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yaml2elf
argument_list|(
name|llvm
operator|::
name|yaml
operator|::
name|Input
operator|&
name|YIn
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|Out
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

