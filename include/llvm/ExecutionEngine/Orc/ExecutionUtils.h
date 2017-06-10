begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ExecutionUtils.h - Utilities for executing code in Orc --*- C++ -*-===//
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
comment|// Contains utilities for executing code in Orc.
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
name|LLVM_EXECUTIONENGINE_ORC_EXECUTIONUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_EXECUTIONUTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/JITSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/RuntimeDyld.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ConstantArray
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|namespace
name|orc
block|{
comment|/// @brief This iterator provides a convenient way to iterate over the elements
comment|///        of an llvm.global_ctors/llvm.global_dtors instance.
comment|///
comment|///   The easiest way to get hold of instances of this class is to use the
comment|/// getConstructors/getDestructors functions.
name|class
name|CtorDtorIterator
block|{
name|public
label|:
comment|/// @brief Accessor for an element of the global_ctors/global_dtors array.
comment|///
comment|///   This class provides a read-only view of the element with any casts on
comment|/// the function stripped away.
struct|struct
name|Element
block|{
name|Element
argument_list|(
argument|unsigned Priority
argument_list|,
argument|Function *Func
argument_list|,
argument|Value *Data
argument_list|)
block|:
name|Priority
argument_list|(
name|Priority
argument_list|)
operator|,
name|Func
argument_list|(
name|Func
argument_list|)
operator|,
name|Data
argument_list|(
argument|Data
argument_list|)
block|{}
name|unsigned
name|Priority
expr_stmt|;
name|Function
modifier|*
name|Func
decl_stmt|;
name|Value
modifier|*
name|Data
decl_stmt|;
block|}
struct|;
comment|/// @brief Construct an iterator instance. If End is true then this iterator
comment|///        acts as the end of the range, otherwise it is the beginning.
name|CtorDtorIterator
argument_list|(
argument|const GlobalVariable *GV
argument_list|,
argument|bool End
argument_list|)
empty_stmt|;
comment|/// @brief Test iterators for equality.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|CtorDtorIterator
operator|&
name|Other
operator|)
specifier|const
expr_stmt|;
comment|/// @brief Test iterators for inequality.
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|CtorDtorIterator
operator|&
name|Other
operator|)
specifier|const
expr_stmt|;
comment|/// @brief Pre-increment iterator.
name|CtorDtorIterator
operator|&
name|operator
operator|++
operator|(
operator|)
expr_stmt|;
comment|/// @brief Post-increment iterator.
name|CtorDtorIterator
name|operator
operator|++
operator|(
name|int
operator|)
expr_stmt|;
comment|/// @brief Dereference iterator. The resulting value provides a read-only view
comment|///        of this element of the global_ctors/global_dtors list.
name|Element
name|operator
operator|*
operator|(
operator|)
specifier|const
expr_stmt|;
name|private
label|:
specifier|const
name|ConstantArray
modifier|*
name|InitList
decl_stmt|;
name|unsigned
name|I
decl_stmt|;
block|}
empty_stmt|;
comment|/// @brief Create an iterator range over the entries of the llvm.global_ctors
comment|///        array.
name|iterator_range
operator|<
name|CtorDtorIterator
operator|>
name|getConstructors
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|)
expr_stmt|;
comment|/// @brief Create an iterator range over the entries of the llvm.global_ctors
comment|///        array.
name|iterator_range
operator|<
name|CtorDtorIterator
operator|>
name|getDestructors
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|)
expr_stmt|;
comment|/// @brief Convenience class for recording constructor/destructor names for
comment|///        later execution.
name|template
operator|<
name|typename
name|JITLayerT
operator|>
name|class
name|CtorDtorRunner
block|{
name|public
operator|:
comment|/// @brief Construct a CtorDtorRunner for the given range using the given
comment|///        name mangling function.
name|CtorDtorRunner
argument_list|(
argument|std::vector<std::string> CtorDtorNames
argument_list|,
argument|typename JITLayerT::ModuleSetHandleT H
argument_list|)
operator|:
name|CtorDtorNames
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|CtorDtorNames
argument_list|)
argument_list|)
block|,
name|H
argument_list|(
argument|H
argument_list|)
block|{}
comment|/// @brief Run the recorded constructors/destructors through the given JIT
comment|///        layer.
name|bool
name|runViaLayer
argument_list|(
argument|JITLayerT&JITLayer
argument_list|)
specifier|const
block|{
typedef|typedef
name|void
function_decl|(
modifier|*
name|CtorDtorTy
function_decl|)
parameter_list|()
function_decl|;
name|bool
name|Error
operator|=
name|false
block|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|CtorDtorName
range|:
name|CtorDtorNames
control|)
if|if
condition|(
name|auto
name|CtorDtorSym
init|=
name|JITLayer
operator|.
name|findSymbolIn
argument_list|(
name|H
argument_list|,
name|CtorDtorName
argument_list|,
name|false
argument_list|)
condition|)
block|{
name|CtorDtorTy
name|CtorDtor
init|=
name|reinterpret_cast
operator|<
name|CtorDtorTy
operator|>
operator|(
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|CtorDtorSym
operator|.
name|getAddress
argument_list|()
operator|)
operator|)
decl_stmt|;
name|CtorDtor
argument_list|()
expr_stmt|;
block|}
else|else
name|Error
operator|=
name|true
expr_stmt|;
return|return
operator|!
name|Error
return|;
block|}
name|private
label|:
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|CtorDtorNames
expr_stmt|;
name|typename
name|JITLayerT
operator|::
name|ModuleSetHandleT
name|H
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// @brief Support class for static dtor execution. For hosted (in-process) JITs
end_comment

begin_comment
comment|///        only!
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   If a __cxa_atexit function isn't found C++ programs that use static
end_comment

begin_comment
comment|/// destructors will fail to link. However, we don't want to use the host
end_comment

begin_comment
comment|/// process's __cxa_atexit, because it will schedule JIT'd destructors to run
end_comment

begin_comment
comment|/// after the JIT has been torn down, which is no good. This class makes it easy
end_comment

begin_comment
comment|/// to override __cxa_atexit (and the related __dso_handle).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   To use, clients should manually call searchOverrides from their symbol
end_comment

begin_comment
comment|/// resolver. This should generally be done after attempting symbol resolution
end_comment

begin_comment
comment|/// inside the JIT, but before searching the host process's symbol table. When
end_comment

begin_comment
comment|/// the client determines that destructors should be run (generally at JIT
end_comment

begin_comment
comment|/// teardown or after a return from main), the runDestructors method should be
end_comment

begin_comment
comment|/// called.
end_comment

begin_decl_stmt
name|class
name|LocalCXXRuntimeOverrides
block|{
name|public
label|:
comment|/// Create a runtime-overrides class.
name|template
operator|<
name|typename
name|MangleFtorT
operator|>
name|LocalCXXRuntimeOverrides
argument_list|(
argument|const MangleFtorT&Mangle
argument_list|)
block|{
name|addOverride
argument_list|(
name|Mangle
argument_list|(
literal|"__dso_handle"
argument_list|)
argument_list|,
name|toTargetAddress
argument_list|(
operator|&
name|DSOHandleOverride
argument_list|)
argument_list|)
block|;
name|addOverride
argument_list|(
name|Mangle
argument_list|(
literal|"__cxa_atexit"
argument_list|)
argument_list|,
name|toTargetAddress
argument_list|(
operator|&
name|CXAAtExitOverride
argument_list|)
argument_list|)
block|;   }
comment|/// Search overrided symbols.
name|JITEvaluatedSymbol
name|searchOverrides
argument_list|(
argument|const std::string&Name
argument_list|)
block|{
name|auto
name|I
operator|=
name|CXXRuntimeOverrides
operator|.
name|find
argument_list|(
name|Name
argument_list|)
block|;
if|if
condition|(
name|I
operator|!=
name|CXXRuntimeOverrides
operator|.
name|end
argument_list|()
condition|)
return|return
name|JITEvaluatedSymbol
argument_list|(
name|I
operator|->
name|second
argument_list|,
name|JITSymbolFlags
operator|::
name|Exported
argument_list|)
return|;
return|return
name|nullptr
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Run any destructors recorded by the overriden __cxa_atexit function
end_comment

begin_comment
comment|/// (CXAAtExitOverride).
end_comment

begin_function_decl
name|void
name|runDestructors
parameter_list|()
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|template
operator|<
name|typename
name|PtrTy
operator|>
name|JITTargetAddress
name|toTargetAddress
argument_list|(
argument|PtrTy* P
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|JITTargetAddress
operator|>
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|P
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|addOverride
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|,
name|JITTargetAddress
name|Addr
argument_list|)
block|{
name|CXXRuntimeOverrides
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Name
argument_list|,
name|Addr
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|StringMap
operator|<
name|JITTargetAddress
operator|>
name|CXXRuntimeOverrides
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|DestructorPtr
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|DestructorPtr
operator|,
name|void
operator|*
operator|>
name|CXXDestructorDataPair
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CXXDestructorDataPair
operator|>
name|CXXDestructorDataPairList
expr_stmt|;
end_typedef

begin_decl_stmt
name|CXXDestructorDataPairList
name|DSOHandleOverride
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|CXAAtExitOverride
parameter_list|(
name|DestructorPtr
name|Destructor
parameter_list|,
name|void
modifier|*
name|Arg
parameter_list|,
name|void
modifier|*
name|DSOHandle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};  }
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
comment|// LLVM_EXECUTIONENGINE_ORC_EXECUTIONUTILS_H
end_comment

end_unit

