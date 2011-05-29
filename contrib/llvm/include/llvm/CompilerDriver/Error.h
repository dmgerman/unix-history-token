begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Error.h - The LLVM Compiler Driver ---------------------*- C++ -*-===//
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
comment|// This file is distributed under the University of Illinois Open
end_comment

begin_comment
comment|// Source License. See LICENSE.TXT for details.
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
comment|//  Error handling.
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
name|LLVM_INCLUDE_COMPILER_DRIVER_ERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_INCLUDE_COMPILER_DRIVER_ERROR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvmc
block|{
specifier|inline
name|void
name|PrintError
argument_list|(
name|llvm
operator|::
name|StringRef
name|Err
argument_list|)
block|{
specifier|extern
specifier|const
name|char
modifier|*
name|ProgramName
decl_stmt|;
name|llvm
operator|::
name|errs
argument_list|()
operator|<<
name|ProgramName
operator|<<
literal|": "
operator|<<
name|Err
operator|<<
literal|'\n'
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_INCLUDE_COMPILER_DRIVER_ERROR_H
end_comment

end_unit

