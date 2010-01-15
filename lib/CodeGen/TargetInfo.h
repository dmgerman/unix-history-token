begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- TargetInfo.h - Encapsulate target details -------------*- C++ -*-===//
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
name|CLANG_CODEGEN_TARGETINFO_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_TARGETINFO_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ABIInfo
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenModule
decl_stmt|;
block|}
comment|/// TargetCodeGenInfo - This class organizes various target-specific
comment|/// codegeneration issues, like target-specific attributes, builtins and so
comment|/// on.
name|class
name|TargetCodeGenInfo
block|{
name|ABIInfo
modifier|*
name|Info
decl_stmt|;
name|public
label|:
comment|// WARNING: Acquires the ownership of ABIInfo.
name|TargetCodeGenInfo
argument_list|(
name|ABIInfo
operator|*
name|info
operator|=
literal|0
argument_list|)
operator|:
name|Info
argument_list|(
argument|info
argument_list|)
block|{ }
expr_stmt|;
name|virtual
operator|~
name|TargetCodeGenInfo
argument_list|()
expr_stmt|;
comment|/// getABIInfo() - Returns ABI info helper for the target.
specifier|const
name|ABIInfo
operator|&
name|getABIInfo
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Info
return|;
block|}
comment|/// SetTargetAttributes - Provides a convenient hook to handle extra
comment|/// target-specific attributes for the given global.
name|virtual
name|void
name|SetTargetAttributes
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|GlobalValue
operator|*
name|GV
argument_list|,
name|CodeGen
operator|::
name|CodeGenModule
operator|&
name|M
argument_list|)
decl|const
block|{ }
empty_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CLANG_CODEGEN_TARGETINFO_H
end_comment

end_unit

