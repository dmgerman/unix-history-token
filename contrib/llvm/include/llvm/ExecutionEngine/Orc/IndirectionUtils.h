begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IndirectionUtils.h - Utilities for adding indirections --*- C++ -*-===//
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
comment|// Contains utilities for adding indirections and breaking up modules.
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
name|LLVM_EXECUTIONENGINE_ORC_INDIRECTIONUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_INDIRECTIONUTILS_H
end_define

begin_include
include|#
directive|include
file|"JITSymbol.h"
end_include

begin_include
include|#
directive|include
file|"LambdaResolver.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/RuntimeDyld.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IRBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Mangler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Utils/ValueMapper.h"
end_include

begin_include
include|#
directive|include
file|<sstream>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|orc
block|{
comment|/// @brief Base class for JITLayer independent aspects of
comment|///        JITCompileCallbackManager.
name|class
name|JITCompileCallbackManagerBase
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|function
operator|<
name|TargetAddress
argument_list|()
operator|>
name|CompileFtor
expr_stmt|;
comment|/// @brief Handle to a newly created compile callback. Can be used to get an
comment|///        IR constant representing the address of the trampoline, and to set
comment|///        the compile action for the callback.
name|class
name|CompileCallbackInfo
block|{
name|public
label|:
name|CompileCallbackInfo
argument_list|(
argument|TargetAddress Addr
argument_list|,
argument|CompileFtor&Compile
argument_list|)
block|:
name|Addr
argument_list|(
name|Addr
argument_list|)
operator|,
name|Compile
argument_list|(
argument|Compile
argument_list|)
block|{}
name|TargetAddress
name|getAddress
argument_list|()
specifier|const
block|{
return|return
name|Addr
return|;
block|}
name|void
name|setCompileAction
parameter_list|(
name|CompileFtor
name|Compile
parameter_list|)
block|{
name|this
operator|->
name|Compile
operator|=
name|std
operator|::
name|move
argument_list|(
name|Compile
argument_list|)
expr_stmt|;
block|}
name|private
label|:
name|TargetAddress
name|Addr
decl_stmt|;
name|CompileFtor
modifier|&
name|Compile
decl_stmt|;
block|}
empty_stmt|;
comment|/// @brief Construct a JITCompileCallbackManagerBase.
comment|/// @param ErrorHandlerAddress The address of an error handler in the target
comment|///                            process to be used if a compile callback fails.
comment|/// @param NumTrampolinesPerBlock Number of trampolines to emit if there is no
comment|///                             available trampoline when getCompileCallback is
comment|///                             called.
name|JITCompileCallbackManagerBase
argument_list|(
argument|TargetAddress ErrorHandlerAddress
argument_list|,
argument|unsigned NumTrampolinesPerBlock
argument_list|)
block|:
name|ErrorHandlerAddress
argument_list|(
name|ErrorHandlerAddress
argument_list|)
operator|,
name|NumTrampolinesPerBlock
argument_list|(
argument|NumTrampolinesPerBlock
argument_list|)
block|{}
name|virtual
operator|~
name|JITCompileCallbackManagerBase
argument_list|()
block|{}
comment|/// @brief Execute the callback for the given trampoline id. Called by the JIT
comment|///        to compile functions on demand.
name|TargetAddress
name|executeCompileCallback
argument_list|(
argument|TargetAddress TrampolineAddr
argument_list|)
block|{
name|auto
name|I
operator|=
name|ActiveTrampolines
operator|.
name|find
argument_list|(
name|TrampolineAddr
argument_list|)
block|;
comment|// FIXME: Also raise an error in the Orc error-handler when we finally have
comment|//        one.
if|if
condition|(
name|I
operator|==
name|ActiveTrampolines
operator|.
name|end
argument_list|()
condition|)
return|return
name|ErrorHandlerAddress
return|;
comment|// Found a callback handler. Yank this trampoline out of the active list and
comment|// put it back in the available trampolines list, then try to run the
comment|// handler's compile and update actions.
comment|// Moving the trampoline ID back to the available list first means there's at
comment|// least one available trampoline if the compile action triggers a request for
comment|// a new one.
name|auto
name|Compile
operator|=
name|std
operator|::
name|move
argument_list|(
name|I
operator|->
name|second
argument_list|)
expr_stmt|;
name|ActiveTrampolines
operator|.
name|erase
argument_list|(
name|I
argument_list|)
expr_stmt|;
name|AvailableTrampolines
operator|.
name|push_back
argument_list|(
name|TrampolineAddr
argument_list|)
expr_stmt|;
if|if
condition|(
name|auto
name|Addr
init|=
name|Compile
argument_list|()
condition|)
return|return
name|Addr
return|;
return|return
name|ErrorHandlerAddress
return|;
block|}
comment|/// @brief Reserve a compile callback.
name|virtual
name|CompileCallbackInfo
name|getCompileCallback
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// @brief Get a CompileCallbackInfo for an existing callback.
name|CompileCallbackInfo
name|getCompileCallbackInfo
parameter_list|(
name|TargetAddress
name|TrampolineAddr
parameter_list|)
block|{
name|auto
name|I
init|=
name|ActiveTrampolines
operator|.
name|find
argument_list|(
name|TrampolineAddr
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|ActiveTrampolines
operator|.
name|end
argument_list|()
operator|&&
literal|"Not an active trampoline."
argument_list|)
expr_stmt|;
return|return
name|CompileCallbackInfo
argument_list|(
name|I
operator|->
name|first
argument_list|,
name|I
operator|->
name|second
argument_list|)
return|;
block|}
comment|/// @brief Release a compile callback.
comment|///
comment|///   Note: Callbacks are auto-released after they execute. This method should
comment|/// only be called to manually release a callback that is not going to
comment|/// execute.
name|void
name|releaseCompileCallback
parameter_list|(
name|TargetAddress
name|TrampolineAddr
parameter_list|)
block|{
name|auto
name|I
init|=
name|ActiveTrampolines
operator|.
name|find
argument_list|(
name|TrampolineAddr
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|ActiveTrampolines
operator|.
name|end
argument_list|()
operator|&&
literal|"Not an active trampoline."
argument_list|)
expr_stmt|;
name|ActiveTrampolines
operator|.
name|erase
argument_list|(
name|I
argument_list|)
expr_stmt|;
name|AvailableTrampolines
operator|.
name|push_back
argument_list|(
name|TrampolineAddr
argument_list|)
expr_stmt|;
block|}
name|protected
label|:
name|TargetAddress
name|ErrorHandlerAddress
decl_stmt|;
name|unsigned
name|NumTrampolinesPerBlock
decl_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|TargetAddress
operator|,
name|CompileFtor
operator|>
name|TrampolineMapT
expr_stmt|;
name|TrampolineMapT
name|ActiveTrampolines
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|TargetAddress
operator|>
name|AvailableTrampolines
expr_stmt|;
block|}
empty_stmt|;
comment|/// @brief Manage compile callbacks.
name|template
operator|<
name|typename
name|JITLayerT
operator|,
name|typename
name|TargetT
operator|>
name|class
name|JITCompileCallbackManager
operator|:
name|public
name|JITCompileCallbackManagerBase
block|{
name|public
operator|:
comment|/// @brief Construct a JITCompileCallbackManager.
comment|/// @param JIT JIT layer to emit callback trampolines, etc. into.
comment|/// @param Context LLVMContext to use for trampoline& resolve block modules.
comment|/// @param ErrorHandlerAddress The address of an error handler in the target
comment|///                            process to be used if a compile callback fails.
comment|/// @param NumTrampolinesPerBlock Number of trampolines to allocate whenever
comment|///                               there is no existing callback trampoline.
comment|///                               (Trampolines are allocated in blocks for
comment|///                               efficiency.)
name|JITCompileCallbackManager
argument_list|(
argument|JITLayerT&JIT
argument_list|,
argument|RuntimeDyld::MemoryManager&MemMgr
argument_list|,
argument|LLVMContext&Context
argument_list|,
argument|TargetAddress ErrorHandlerAddress
argument_list|,
argument|unsigned NumTrampolinesPerBlock
argument_list|)
operator|:
name|JITCompileCallbackManagerBase
argument_list|(
name|ErrorHandlerAddress
argument_list|,
name|NumTrampolinesPerBlock
argument_list|)
block|,
name|JIT
argument_list|(
name|JIT
argument_list|)
block|,
name|MemMgr
argument_list|(
argument|MemMgr
argument_list|)
block|{
name|emitResolverBlock
argument_list|(
name|Context
argument_list|)
block|;   }
comment|/// @brief Get/create a compile callback with the given signature.
name|CompileCallbackInfo
name|getCompileCallback
argument_list|(
argument|LLVMContext&Context
argument_list|)
name|final
block|{
name|TargetAddress
name|TrampolineAddr
operator|=
name|getAvailableTrampolineAddr
argument_list|(
name|Context
argument_list|)
block|;
name|auto
operator|&
name|Compile
operator|=
name|this
operator|->
name|ActiveTrampolines
index|[
name|TrampolineAddr
index|]
block|;
return|return
name|CompileCallbackInfo
argument_list|(
name|TrampolineAddr
argument_list|,
name|Compile
argument_list|)
return|;
block|}
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>>
name|SingletonSet
argument_list|(
argument|std::unique_ptr<Module> M
argument_list|)
block|{
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>>
name|Ms
block|;
name|Ms
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|M
argument_list|)
argument_list|)
block|;
return|return
name|Ms
return|;
block|}
name|void
name|emitResolverBlock
argument_list|(
argument|LLVMContext&Context
argument_list|)
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
argument_list|(
argument|new Module(
literal|"resolver_block_module"
argument|,                                          Context)
argument_list|)
block|;
name|TargetT
operator|::
name|insertResolverBlock
argument_list|(
operator|*
name|M
argument_list|,
operator|*
name|this
argument_list|)
block|;
name|auto
name|NonResolver
operator|=
name|createLambdaResolver
argument_list|(
argument|[](const std::string&Name) -> RuntimeDyld::SymbolInfo {             llvm_unreachable(
literal|"External symbols in resolver block?"
argument|);           }
argument_list|,
argument|[](const std::string&Name) -> RuntimeDyld::SymbolInfo {             llvm_unreachable(
literal|"Dylib symbols in resolver block?"
argument|);           }
argument_list|)
block|;
name|auto
name|H
operator|=
name|JIT
operator|.
name|addModuleSet
argument_list|(
name|SingletonSet
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|M
argument_list|)
argument_list|)
argument_list|,
operator|&
name|MemMgr
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|NonResolver
argument_list|)
argument_list|)
block|;
name|JIT
operator|.
name|emitAndFinalize
argument_list|(
name|H
argument_list|)
block|;
name|auto
name|ResolverBlockSymbol
operator|=
name|JIT
operator|.
name|findSymbolIn
argument_list|(
name|H
argument_list|,
name|TargetT
operator|::
name|ResolverBlockName
argument_list|,
name|false
argument_list|)
block|;
name|assert
argument_list|(
name|ResolverBlockSymbol
operator|&&
literal|"Failed to insert resolver block"
argument_list|)
block|;
name|ResolverBlockAddr
operator|=
name|ResolverBlockSymbol
operator|.
name|getAddress
argument_list|()
block|;   }
name|TargetAddress
name|getAvailableTrampolineAddr
argument_list|(
argument|LLVMContext&Context
argument_list|)
block|{
if|if
condition|(
name|this
operator|->
name|AvailableTrampolines
operator|.
name|empty
argument_list|()
condition|)
name|grow
argument_list|(
name|Context
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|this
operator|->
name|AvailableTrampolines
operator|.
name|empty
argument_list|()
operator|&&
literal|"Failed to grow available trampolines."
argument_list|)
block|;
name|TargetAddress
name|TrampolineAddr
operator|=
name|this
operator|->
name|AvailableTrampolines
operator|.
name|back
argument_list|()
block|;
name|this
operator|->
name|AvailableTrampolines
operator|.
name|pop_back
argument_list|()
block|;
return|return
name|TrampolineAddr
return|;
block|}
name|void
name|grow
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|)
block|{
name|assert
argument_list|(
name|this
operator|->
name|AvailableTrampolines
operator|.
name|empty
argument_list|()
operator|&&
literal|"Growing prematurely?"
argument_list|)
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
argument_list|(
argument|new Module(
literal|"trampoline_block"
argument|, Context)
argument_list|)
expr_stmt|;
name|auto
name|GetLabelName
init|=
name|TargetT
operator|::
name|insertCompileCallbackTrampolines
argument_list|(
operator|*
name|M
argument_list|,
name|ResolverBlockAddr
argument_list|,
name|this
operator|->
name|NumTrampolinesPerBlock
argument_list|,
name|this
operator|->
name|ActiveTrampolines
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|auto
name|NonResolver
init|=
name|createLambdaResolver
argument_list|(
argument|[](const std::string&Name) -> RuntimeDyld::SymbolInfo {             llvm_unreachable(
literal|"External symbols in trampoline block?"
argument|);           }
argument_list|,
argument|[](const std::string&Name) -> RuntimeDyld::SymbolInfo {             llvm_unreachable(
literal|"Dylib symbols in trampoline block?"
argument|);           }
argument_list|)
decl_stmt|;
name|auto
name|H
init|=
name|JIT
operator|.
name|addModuleSet
argument_list|(
name|SingletonSet
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|M
argument_list|)
argument_list|)
argument_list|,
operator|&
name|MemMgr
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|NonResolver
argument_list|)
argument_list|)
decl_stmt|;
name|JIT
operator|.
name|emitAndFinalize
argument_list|(
name|H
argument_list|)
expr_stmt|;
for|for
control|(
name|unsigned
name|I
init|=
literal|0
init|;
name|I
operator|<
name|this
operator|->
name|NumTrampolinesPerBlock
condition|;
operator|++
name|I
control|)
block|{
name|std
operator|::
name|string
name|Name
operator|=
name|GetLabelName
argument_list|(
name|I
argument_list|)
expr_stmt|;
name|auto
name|TrampolineSymbol
init|=
name|JIT
operator|.
name|findSymbolIn
argument_list|(
name|H
argument_list|,
name|Name
argument_list|,
name|false
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|TrampolineSymbol
operator|&&
literal|"Failed to emit trampoline."
argument_list|)
expr_stmt|;
name|this
operator|->
name|AvailableTrampolines
operator|.
name|push_back
argument_list|(
name|TrampolineSymbol
operator|.
name|getAddress
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|JITLayerT
modifier|&
name|JIT
decl_stmt|;
name|RuntimeDyld
operator|::
name|MemoryManager
operator|&
name|MemMgr
expr_stmt|;
name|TargetAddress
name|ResolverBlockAddr
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// @brief Build a function pointer of FunctionType with the given constant
end_comment

begin_comment
comment|///        address.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   Usage example: Turn a trampoline address into a function pointer constant
end_comment

begin_comment
comment|/// for use in a stub.
end_comment

begin_function_decl
name|Constant
modifier|*
name|createIRTypedAddress
parameter_list|(
name|FunctionType
modifier|&
name|FT
parameter_list|,
name|TargetAddress
name|Addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Create a function pointer with the given type, name, and initializer
end_comment

begin_comment
comment|///        in the given Module.
end_comment

begin_function_decl
name|GlobalVariable
modifier|*
name|createImplPointer
parameter_list|(
name|PointerType
modifier|&
name|PT
parameter_list|,
name|Module
modifier|&
name|M
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Name
parameter_list|,
name|Constant
modifier|*
name|Initializer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Turn a function declaration into a stub function that makes an
end_comment

begin_comment
comment|///        indirect call using the given function pointer.
end_comment

begin_function_decl
name|void
name|makeStub
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|,
name|GlobalVariable
modifier|&
name|ImplPointer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Raise linkage types and rename as necessary to ensure that all
end_comment

begin_comment
comment|///        symbols are accessible for other modules.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   This should be called before partitioning a module to ensure that the
end_comment

begin_comment
comment|/// partitions retain access to each other's symbols.
end_comment

begin_function_decl
name|void
name|makeAllSymbolsExternallyAccessible
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Clone a function declaration into a new module.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   This function can be used as the first step towards creating a callback
end_comment

begin_comment
comment|/// stub (see makeStub), or moving a function body (see moveFunctionBody).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   If the VMap argument is non-null, a mapping will be added between F and
end_comment

begin_comment
comment|/// the new declaration, and between each of F's arguments and the new
end_comment

begin_comment
comment|/// declaration's arguments. This map can then be passed in to moveFunction to
end_comment

begin_comment
comment|/// move the function body if required. Note: When moving functions between
end_comment

begin_comment
comment|/// modules with these utilities, all decls should be cloned (and added to a
end_comment

begin_comment
comment|/// single VMap) before any bodies are moved. This will ensure that references
end_comment

begin_comment
comment|/// between functions all refer to the versions in the new module.
end_comment

begin_function_decl
name|Function
modifier|*
name|cloneFunctionDecl
parameter_list|(
name|Module
modifier|&
name|Dst
parameter_list|,
specifier|const
name|Function
modifier|&
name|F
parameter_list|,
name|ValueToValueMapTy
modifier|*
name|VMap
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Move the body of function 'F' to a cloned function declaration in a
end_comment

begin_comment
comment|///        different module (See related cloneFunctionDecl).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   If the target function declaration is not supplied via the NewF parameter
end_comment

begin_comment
comment|/// then it will be looked up via the VMap.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   This will delete the body of function 'F' from its original parent module,
end_comment

begin_comment
comment|/// but leave its declaration.
end_comment

begin_function_decl
name|void
name|moveFunctionBody
parameter_list|(
name|Function
modifier|&
name|OrigF
parameter_list|,
name|ValueToValueMapTy
modifier|&
name|VMap
parameter_list|,
name|ValueMaterializer
modifier|*
name|Materializer
init|=
name|nullptr
parameter_list|,
name|Function
modifier|*
name|NewF
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Clone a global variable declaration into a new module.
end_comment

begin_function_decl
name|GlobalVariable
modifier|*
name|cloneGlobalVariableDecl
parameter_list|(
name|Module
modifier|&
name|Dst
parameter_list|,
specifier|const
name|GlobalVariable
modifier|&
name|GV
parameter_list|,
name|ValueToValueMapTy
modifier|*
name|VMap
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Move global variable GV from its parent module to cloned global
end_comment

begin_comment
comment|///        declaration in a different module.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   If the target global declaration is not supplied via the NewGV parameter
end_comment

begin_comment
comment|/// then it will be looked up via the VMap.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   This will delete the initializer of GV from its original parent module,
end_comment

begin_comment
comment|/// but leave its declaration.
end_comment

begin_function_decl
name|void
name|moveGlobalVariableInitializer
parameter_list|(
name|GlobalVariable
modifier|&
name|OrigGV
parameter_list|,
name|ValueToValueMapTy
modifier|&
name|VMap
parameter_list|,
name|ValueMaterializer
modifier|*
name|Materializer
init|=
name|nullptr
parameter_list|,
name|GlobalVariable
modifier|*
name|NewGV
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|}
comment|// End namespace orc.
end_comment

begin_comment
unit|}
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_EXECUTIONENGINE_ORC_INDIRECTIONUTILS_H
end_comment

end_unit

