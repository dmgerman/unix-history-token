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
comment|//  Exception classes for llvmc.
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
file|<stdexcept>
end_include

begin_decl_stmt
name|namespace
name|llvmc
block|{
comment|/// error_code - This gets thrown during the compilation process if a tool
comment|/// invocation returns a non-zero exit code.
name|class
name|error_code
range|:
name|public
name|std
operator|::
name|runtime_error
block|{
name|int
name|Code_
block|;
name|public
operator|:
name|error_code
argument_list|(
argument|int c
argument_list|)
operator|:
name|std
operator|::
name|runtime_error
argument_list|(
literal|"Tool returned error code"
argument_list|)
block|,
name|Code_
argument_list|(
argument|c
argument_list|)
block|{}
name|int
name|code
argument_list|()
specifier|const
block|{
return|return
name|Code_
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_INCLUDE_COMPILER_DRIVER_ERROR_H
end_comment

end_unit

