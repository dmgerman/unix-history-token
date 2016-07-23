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
file|"llvm/Support/Process.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Utils/ValueMapper.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|orc
block|{
comment|/// @brief Target-independent base class for compile callback management.
name|class
name|JITCompileCallbackManager
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
comment|/// @brief Construct a JITCompileCallbackManager.
comment|/// @param ErrorHandlerAddress The address of an error handler in the target
comment|///                            process to be used if a compile callback fails.
name|JITCompileCallbackManager
argument_list|(
argument|TargetAddress ErrorHandlerAddress
argument_list|)
block|:
name|ErrorHandlerAddress
argument_list|(
argument|ErrorHandlerAddress
argument_list|)
block|{}
name|virtual
operator|~
name|JITCompileCallbackManager
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
comment|// Moving the trampoline ID back to the available list first means there's
comment|// at
comment|// least one available trampoline if the compile action triggers a request
comment|// for
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
name|CompileCallbackInfo
name|getCompileCallback
parameter_list|()
block|{
name|TargetAddress
name|TrampolineAddr
init|=
name|getAvailableTrampolineAddr
argument_list|()
decl_stmt|;
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
expr_stmt|;
return|return
name|CompileCallbackInfo
argument_list|(
name|TrampolineAddr
argument_list|,
name|Compile
argument_list|)
return|;
block|}
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
name|private
label|:
name|TargetAddress
name|getAvailableTrampolineAddr
parameter_list|()
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
argument_list|()
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
expr_stmt|;
name|TargetAddress
name|TrampolineAddr
init|=
name|this
operator|->
name|AvailableTrampolines
operator|.
name|back
argument_list|()
decl_stmt|;
name|this
operator|->
name|AvailableTrampolines
operator|.
name|pop_back
argument_list|()
expr_stmt|;
return|return
name|TrampolineAddr
return|;
block|}
comment|// Create new trampolines - to be implemented in subclasses.
name|virtual
name|void
name|grow
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
block|}
empty_stmt|;
comment|/// @brief Manage compile callbacks for in-process JITs.
name|template
operator|<
name|typename
name|TargetT
operator|>
name|class
name|LocalJITCompileCallbackManager
operator|:
name|public
name|JITCompileCallbackManager
block|{
name|public
operator|:
comment|/// @brief Construct a InProcessJITCompileCallbackManager.
comment|/// @param ErrorHandlerAddress The address of an error handler in the target
comment|///                            process to be used if a compile callback fails.
name|LocalJITCompileCallbackManager
argument_list|(
argument|TargetAddress ErrorHandlerAddress
argument_list|)
operator|:
name|JITCompileCallbackManager
argument_list|(
argument|ErrorHandlerAddress
argument_list|)
block|{
comment|/// Set up the resolver block.
name|std
operator|::
name|error_code
name|EC
block|;
name|ResolverBlock
operator|=
name|sys
operator|::
name|OwningMemoryBlock
argument_list|(
name|sys
operator|::
name|Memory
operator|::
name|allocateMappedMemory
argument_list|(
name|TargetT
operator|::
name|ResolverCodeSize
argument_list|,
name|nullptr
argument_list|,
name|sys
operator|::
name|Memory
operator|::
name|MF_READ
operator||
name|sys
operator|::
name|Memory
operator|::
name|MF_WRITE
argument_list|,
name|EC
argument_list|)
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|EC
operator|&&
literal|"Failed to allocate resolver block"
argument_list|)
block|;
name|TargetT
operator|::
name|writeResolverCode
argument_list|(
name|static_cast
operator|<
name|uint8_t
operator|*
operator|>
operator|(
name|ResolverBlock
operator|.
name|base
argument_list|()
operator|)
argument_list|,
operator|&
name|reenter
argument_list|,
name|this
argument_list|)
block|;
name|EC
operator|=
name|sys
operator|::
name|Memory
operator|::
name|protectMappedMemory
argument_list|(
name|ResolverBlock
operator|.
name|getMemoryBlock
argument_list|()
argument_list|,
name|sys
operator|::
name|Memory
operator|::
name|MF_READ
operator||
name|sys
operator|::
name|Memory
operator|::
name|MF_EXEC
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|EC
operator|&&
literal|"Failed to mprotect resolver block"
argument_list|)
block|;   }
name|private
operator|:
specifier|static
name|TargetAddress
name|reenter
argument_list|(
argument|void *CCMgr
argument_list|,
argument|void *TrampolineId
argument_list|)
block|{
name|JITCompileCallbackManager
operator|*
name|Mgr
operator|=
name|static_cast
operator|<
name|JITCompileCallbackManager
operator|*
operator|>
operator|(
name|CCMgr
operator|)
block|;
return|return
name|Mgr
operator|->
name|executeCompileCallback
argument_list|(
name|static_cast
operator|<
name|TargetAddress
operator|>
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|TrampolineId
operator|)
operator|)
argument_list|)
return|;
block|}
name|void
name|grow
argument_list|()
name|override
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
block|;
name|std
operator|::
name|error_code
name|EC
block|;
name|auto
name|TrampolineBlock
operator|=
name|sys
operator|::
name|OwningMemoryBlock
argument_list|(
name|sys
operator|::
name|Memory
operator|::
name|allocateMappedMemory
argument_list|(
name|sys
operator|::
name|Process
operator|::
name|getPageSize
argument_list|()
argument_list|,
name|nullptr
argument_list|,
name|sys
operator|::
name|Memory
operator|::
name|MF_READ
operator||
name|sys
operator|::
name|Memory
operator|::
name|MF_WRITE
argument_list|,
name|EC
argument_list|)
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|EC
operator|&&
literal|"Failed to allocate trampoline block"
argument_list|)
block|;
name|unsigned
name|NumTrampolines
operator|=
operator|(
name|sys
operator|::
name|Process
operator|::
name|getPageSize
argument_list|()
operator|-
name|TargetT
operator|::
name|PointerSize
operator|)
operator|/
name|TargetT
operator|::
name|TrampolineSize
block|;
name|uint8_t
operator|*
name|TrampolineMem
operator|=
name|static_cast
operator|<
name|uint8_t
operator|*
operator|>
operator|(
name|TrampolineBlock
operator|.
name|base
argument_list|()
operator|)
block|;
name|TargetT
operator|::
name|writeTrampolines
argument_list|(
name|TrampolineMem
argument_list|,
name|ResolverBlock
operator|.
name|base
argument_list|()
argument_list|,
name|NumTrampolines
argument_list|)
block|;
for|for
control|(
name|unsigned
name|I
init|=
literal|0
init|;
name|I
operator|<
name|NumTrampolines
condition|;
operator|++
name|I
control|)
name|this
operator|->
name|AvailableTrampolines
operator|.
name|push_back
argument_list|(
name|static_cast
operator|<
name|TargetAddress
operator|>
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|TrampolineMem
operator|+
operator|(
name|I
operator|*
name|TargetT
operator|::
name|TrampolineSize
operator|)
operator|)
operator|)
argument_list|)
expr_stmt|;
name|EC
operator|=
name|sys
operator|::
name|Memory
operator|::
name|protectMappedMemory
argument_list|(
name|TrampolineBlock
operator|.
name|getMemoryBlock
argument_list|()
argument_list|,
name|sys
operator|::
name|Memory
operator|::
name|MF_READ
operator||
name|sys
operator|::
name|Memory
operator|::
name|MF_EXEC
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|EC
operator|&&
literal|"Failed to mprotect trampoline block"
argument_list|)
block|;
name|TrampolineBlocks
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|TrampolineBlock
argument_list|)
argument_list|)
block|;   }
name|sys
operator|::
name|OwningMemoryBlock
name|ResolverBlock
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|sys
operator|::
name|OwningMemoryBlock
operator|>
name|TrampolineBlocks
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// @brief Base class for managing collections of named indirect stubs.
end_comment

begin_decl_stmt
name|class
name|IndirectStubsManager
block|{
name|public
label|:
comment|/// @brief Map type for initializing the manager. See init.
typedef|typedef
name|StringMap
operator|<
name|std
operator|::
name|pair
operator|<
name|TargetAddress
operator|,
name|JITSymbolFlags
operator|>>
name|StubInitsMap
expr_stmt|;
name|virtual
operator|~
name|IndirectStubsManager
argument_list|()
block|{}
comment|/// @brief Create a single stub with the given name, target address and flags.
name|virtual
name|Error
name|createStub
argument_list|(
argument|StringRef StubName
argument_list|,
argument|TargetAddress StubAddr
argument_list|,
argument|JITSymbolFlags StubFlags
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// @brief Create StubInits.size() stubs with the given names, target
comment|///        addresses, and flags.
name|virtual
name|Error
name|createStubs
parameter_list|(
specifier|const
name|StubInitsMap
modifier|&
name|StubInits
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// @brief Find the stub with the given name. If ExportedStubsOnly is true,
comment|///        this will only return a result if the stub's flags indicate that it
comment|///        is exported.
name|virtual
name|JITSymbol
name|findStub
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|bool
name|ExportedStubsOnly
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// @brief Find the implementation-pointer for the stub.
name|virtual
name|JITSymbol
name|findPointer
parameter_list|(
name|StringRef
name|Name
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// @brief Change the value of the implementation pointer for the stub.
name|virtual
name|Error
name|updatePointer
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|TargetAddress
name|NewAddr
parameter_list|)
init|=
literal|0
function_decl|;
name|private
label|:
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// @brief IndirectStubsManager implementation for the host architecture, e.g.
end_comment

begin_comment
comment|///        OrcX86_64. (See OrcArchitectureSupport.h).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|TargetT
operator|>
name|class
name|LocalIndirectStubsManager
operator|:
name|public
name|IndirectStubsManager
block|{
name|public
operator|:
name|Error
name|createStub
argument_list|(
argument|StringRef StubName
argument_list|,
argument|TargetAddress StubAddr
argument_list|,
argument|JITSymbolFlags StubFlags
argument_list|)
name|override
block|{
if|if
condition|(
name|auto
name|Err
init|=
name|reserveStubs
argument_list|(
literal|1
argument_list|)
condition|)
return|return
name|Err
return|;
name|createStubInternal
argument_list|(
name|StubName
argument_list|,
name|StubAddr
argument_list|,
name|StubFlags
argument_list|)
block|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|Error
name|createStubs
parameter_list|(
specifier|const
name|StubInitsMap
modifier|&
name|StubInits
parameter_list|)
function|override
block|{
if|if
condition|(
name|auto
name|Err
init|=
name|reserveStubs
argument_list|(
name|StubInits
operator|.
name|size
argument_list|()
argument_list|)
condition|)
return|return
name|Err
return|;
for|for
control|(
name|auto
operator|&
name|Entry
operator|:
name|StubInits
control|)
name|createStubInternal
argument_list|(
name|Entry
operator|.
name|first
argument_list|()
argument_list|,
name|Entry
operator|.
name|second
operator|.
name|first
argument_list|,
name|Entry
operator|.
name|second
operator|.
name|second
argument_list|)
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_function

begin_function
name|JITSymbol
name|findStub
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|bool
name|ExportedStubsOnly
parameter_list|)
function|override
block|{
name|auto
name|I
init|=
name|StubIndexes
operator|.
name|find
argument_list|(
name|Name
argument_list|)
decl_stmt|;
if|if
condition|(
name|I
operator|==
name|StubIndexes
operator|.
name|end
argument_list|()
condition|)
return|return
name|nullptr
return|;
name|auto
name|Key
init|=
name|I
operator|->
name|second
operator|.
name|first
decl_stmt|;
name|void
modifier|*
name|StubAddr
init|=
name|IndirectStubsInfos
index|[
name|Key
operator|.
name|first
index|]
operator|.
name|getStub
argument_list|(
name|Key
operator|.
name|second
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|StubAddr
operator|&&
literal|"Missing stub address"
argument_list|)
expr_stmt|;
name|auto
name|StubTargetAddr
init|=
name|static_cast
operator|<
name|TargetAddress
operator|>
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|StubAddr
operator|)
operator|)
decl_stmt|;
name|auto
name|StubSymbol
init|=
name|JITSymbol
argument_list|(
name|StubTargetAddr
argument_list|,
name|I
operator|->
name|second
operator|.
name|second
argument_list|)
decl_stmt|;
if|if
condition|(
name|ExportedStubsOnly
operator|&&
operator|!
name|StubSymbol
operator|.
name|isExported
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
name|StubSymbol
return|;
block|}
end_function

begin_function
name|JITSymbol
name|findPointer
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function|override
block|{
name|auto
name|I
init|=
name|StubIndexes
operator|.
name|find
argument_list|(
name|Name
argument_list|)
decl_stmt|;
if|if
condition|(
name|I
operator|==
name|StubIndexes
operator|.
name|end
argument_list|()
condition|)
return|return
name|nullptr
return|;
name|auto
name|Key
init|=
name|I
operator|->
name|second
operator|.
name|first
decl_stmt|;
name|void
modifier|*
name|PtrAddr
init|=
name|IndirectStubsInfos
index|[
name|Key
operator|.
name|first
index|]
operator|.
name|getPtr
argument_list|(
name|Key
operator|.
name|second
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|PtrAddr
operator|&&
literal|"Missing pointer address"
argument_list|)
expr_stmt|;
name|auto
name|PtrTargetAddr
init|=
name|static_cast
operator|<
name|TargetAddress
operator|>
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|PtrAddr
operator|)
operator|)
decl_stmt|;
return|return
name|JITSymbol
argument_list|(
name|PtrTargetAddr
argument_list|,
name|I
operator|->
name|second
operator|.
name|second
argument_list|)
return|;
block|}
end_function

begin_function
name|Error
name|updatePointer
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|TargetAddress
name|NewAddr
parameter_list|)
function|override
block|{
name|auto
name|I
init|=
name|StubIndexes
operator|.
name|find
argument_list|(
name|Name
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|StubIndexes
operator|.
name|end
argument_list|()
operator|&&
literal|"No stub pointer for symbol"
argument_list|)
expr_stmt|;
name|auto
name|Key
init|=
name|I
operator|->
name|second
operator|.
name|first
decl_stmt|;
operator|*
name|IndirectStubsInfos
index|[
name|Key
operator|.
name|first
index|]
operator|.
name|getPtr
argument_list|(
name|Key
operator|.
name|second
argument_list|)
operator|=
name|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|NewAddr
operator|)
operator|)
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_function
name|Error
name|reserveStubs
parameter_list|(
name|unsigned
name|NumStubs
parameter_list|)
block|{
if|if
condition|(
name|NumStubs
operator|<=
name|FreeStubs
operator|.
name|size
argument_list|()
condition|)
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
name|unsigned
name|NewStubsRequired
init|=
name|NumStubs
operator|-
name|FreeStubs
operator|.
name|size
argument_list|()
decl_stmt|;
name|unsigned
name|NewBlockId
init|=
name|IndirectStubsInfos
operator|.
name|size
argument_list|()
decl_stmt|;
name|typename
name|TargetT
operator|::
name|IndirectStubsInfo
name|ISI
expr_stmt|;
if|if
condition|(
name|auto
name|Err
init|=
name|TargetT
operator|::
name|emitIndirectStubsBlock
argument_list|(
name|ISI
argument_list|,
name|NewStubsRequired
argument_list|,
name|nullptr
argument_list|)
condition|)
return|return
name|Err
return|;
for|for
control|(
name|unsigned
name|I
init|=
literal|0
init|;
name|I
operator|<
name|ISI
operator|.
name|getNumStubs
argument_list|()
condition|;
operator|++
name|I
control|)
name|FreeStubs
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|NewBlockId
argument_list|,
name|I
argument_list|)
argument_list|)
expr_stmt|;
name|IndirectStubsInfos
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|ISI
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_function

begin_function
name|void
name|createStubInternal
parameter_list|(
name|StringRef
name|StubName
parameter_list|,
name|TargetAddress
name|InitAddr
parameter_list|,
name|JITSymbolFlags
name|StubFlags
parameter_list|)
block|{
name|auto
name|Key
init|=
name|FreeStubs
operator|.
name|back
argument_list|()
decl_stmt|;
name|FreeStubs
operator|.
name|pop_back
argument_list|()
expr_stmt|;
operator|*
name|IndirectStubsInfos
index|[
name|Key
operator|.
name|first
index|]
operator|.
name|getPtr
argument_list|(
name|Key
operator|.
name|second
argument_list|)
operator|=
name|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|InitAddr
operator|)
operator|)
expr_stmt|;
name|StubIndexes
index|[
name|StubName
index|]
operator|=
name|std
operator|::
name|make_pair
argument_list|(
name|Key
argument_list|,
name|StubFlags
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|typename
name|TargetT
operator|::
name|IndirectStubsInfo
operator|>
name|IndirectStubsInfos
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|uint16_t
operator|,
name|uint16_t
operator|>
name|StubKey
expr_stmt|;
end_typedef

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|StubKey
operator|>
name|FreeStubs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|StringMap
operator|<
name|std
operator|::
name|pair
operator|<
name|StubKey
operator|,
name|JITSymbolFlags
operator|>>
name|StubIndexes
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// @brief Create a local compile callback manager.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The given target triple will determine the ABI, and the given
end_comment

begin_comment
comment|/// ErrorHandlerAddress will be used by the resulting compile callback
end_comment

begin_comment
comment|/// manager if a compile callback fails.
end_comment

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|JITCompileCallbackManager
operator|>
name|createLocalCompileCallbackManager
argument_list|(
argument|const Triple&T
argument_list|,
argument|TargetAddress ErrorHandlerAddress
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @brief Create a local indriect stubs manager builder.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The given target triple will determine the ABI.
end_comment

begin_expr_stmt
name|std
operator|::
name|function
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|IndirectStubsManager
operator|>
operator|(
operator|)
operator|>
name|createLocalIndirectStubsManagerBuilder
argument_list|(
specifier|const
name|Triple
operator|&
name|T
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|Value
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
comment|/// @brief Clone
end_comment

begin_function_decl
name|GlobalAlias
modifier|*
name|cloneGlobalAliasDecl
parameter_list|(
name|Module
modifier|&
name|Dst
parameter_list|,
specifier|const
name|GlobalAlias
modifier|&
name|OrigA
parameter_list|,
name|ValueToValueMapTy
modifier|&
name|VMap
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

