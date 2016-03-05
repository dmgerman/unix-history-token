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

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_comment
comment|// for std::pair
end_comment

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
name|class
name|Constant
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|template
operator|<
name|class
name|PtrType
operator|>
name|class
name|SmallPtrSetImpl
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
name|SmallPtrSetImpl
operator|<
name|GlobalValue
operator|*
operator|>
operator|&
name|Set
argument_list|,
name|bool
name|CompilerUsed
argument_list|)
decl_stmt|;
comment|// Validate the result of Module::getOrInsertFunction called for an interface
comment|// function of given sanitizer. If the instrumented module defines a function
comment|// with the same name, their prototypes must match, otherwise
comment|// getOrInsertFunction returns a bitcast.
name|Function
modifier|*
name|checkSanitizerInterfaceFunction
parameter_list|(
name|Constant
modifier|*
name|FuncOrBitcast
parameter_list|)
function_decl|;
comment|/// \brief Creates sanitizer constructor function, and calls sanitizer's init
comment|/// function from it.
comment|/// \return Returns pair of pointers to constructor, and init functions
comment|/// respectively.
name|std
operator|::
name|pair
operator|<
name|Function
operator|*
operator|,
name|Function
operator|*
operator|>
name|createSanitizerCtorAndInitFunctions
argument_list|(
argument|Module&M
argument_list|,
argument|StringRef CtorName
argument_list|,
argument|StringRef InitName
argument_list|,
argument|ArrayRef<Type *> InitArgTypes
argument_list|,
argument|ArrayRef<Value *> InitArgs
argument_list|,
argument|StringRef VersionCheckName = StringRef()
argument_list|)
expr_stmt|;
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

