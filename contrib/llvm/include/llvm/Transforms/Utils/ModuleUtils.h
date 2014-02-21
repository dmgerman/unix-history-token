begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ModuleUtils.h - Functions to manipulate Modules ---------*- C++ -*-===//
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
comment|// This family of functions perform manipulations on Modules.
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
name|LLVM_TRANSFORMS_UTILS_MODULEUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_MODULEUTILS_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|template
operator|<
name|class
name|PtrType
operator|,
name|unsigned
name|SmallSize
operator|>
name|class
name|SmallPtrSet
expr_stmt|;
comment|/// Append F to the list of global ctors of module M with the given Priority.
comment|/// This wraps the function in the appropriate structure and stores it along
comment|/// side other global constructors. For details see
comment|/// http://llvm.org/docs/LangRef.html#intg_global_ctors
name|void
name|appendToGlobalCtors
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|,
name|Function
modifier|*
name|F
parameter_list|,
name|int
name|Priority
parameter_list|)
function_decl|;
comment|/// Same as appendToGlobalCtors(), but for global dtors.
name|void
name|appendToGlobalDtors
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|,
name|Function
modifier|*
name|F
parameter_list|,
name|int
name|Priority
parameter_list|)
function_decl|;
comment|/// \brief Given "llvm.used" or "llvm.compiler.used" as a global name, collect
comment|/// the initializer elements of that global in Set and return the global itself.
name|GlobalVariable
modifier|*
name|collectUsedGlobalVariables
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|SmallPtrSet
operator|<
name|GlobalValue
operator|*
argument_list|,
literal|8
operator|>
operator|&
name|Set
argument_list|,
name|bool
name|CompilerUsed
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//  LLVM_TRANSFORMS_UTILS_MODULEUTILS_H
end_comment

end_unit

