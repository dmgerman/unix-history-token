begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- CGCXX.h - C++ related code CodeGen declarations ------*- C++ -*-===//
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
comment|// These classes wrap the information about a call or function
end_comment

begin_comment
comment|// definition used to handle ABI compliancy.
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
name|CLANG_CODEGEN_CGCXX_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CGCXX_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// CXXCtorType - C++ constructor types
enum|enum
name|CXXCtorType
block|{
name|Ctor_Complete
block|,
comment|// Complete object ctor
name|Ctor_Base
block|,
comment|// Base object ctor
name|Ctor_CompleteAllocating
comment|// Complete object allocating ctor
block|}
enum|;
comment|/// CXXDtorType - C++ destructor types
enum|enum
name|CXXDtorType
block|{
name|Dtor_Deleting
block|,
comment|// Deleting dtor
name|Dtor_Complete
block|,
comment|// Complete object dtor
name|Dtor_Base
comment|// Base object dtor
block|}
enum|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CLANG_CODEGEN_CGCXX_H
end_comment

end_unit

