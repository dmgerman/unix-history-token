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
name|class
name|Value
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
name|class
name|CodeGenFunction
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
comment|/// Controls whether __builtin_extend_pointer should sign-extend
comment|/// pointers to uint64_t or zero-extend them (the default).  Has
comment|/// no effect for targets:
comment|///   - that have 64-bit pointers, or
comment|///   - that cannot address through registers larger than pointers, or
comment|///   - that implicitly ignore/truncate the top bits when addressing
comment|///     through such registers.
name|virtual
name|bool
name|extendPointerWithSExt
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Performs the code-generation required to convert a return
comment|/// address as stored by the system into the actual address of the
comment|/// next instruction that will be executed.
comment|///
comment|/// Used by __builtin_extract_return_addr().
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|decodeReturnAddress
argument_list|(
argument|CodeGen::CodeGenFunction&CGF
argument_list|,
argument|llvm::Value *Address
argument_list|)
specifier|const
block|{
return|return
name|Address
return|;
block|}
comment|/// Performs the code-generation required to convert the address
comment|/// of an instruction into a return address suitable for storage
comment|/// by the system in a return slot.
comment|///
comment|/// Used by __builtin_frob_return_addr().
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|encodeReturnAddress
argument_list|(
argument|CodeGen::CodeGenFunction&CGF
argument_list|,
argument|llvm::Value *Address
argument_list|)
specifier|const
block|{
return|return
name|Address
return|;
block|}
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

