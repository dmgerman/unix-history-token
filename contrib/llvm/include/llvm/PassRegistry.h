begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/PassRegistry.h - Pass Information Registry ----------*- C++ -*-===//
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
comment|// This file defines PassRegistry, a class that is used in the initialization
end_comment

begin_comment
comment|// and registration of passes.  At application startup, passes are registered
end_comment

begin_comment
comment|// with the PassRegistry, which is later provided to the PassManager for
end_comment

begin_comment
comment|// dependency resolution and similar tasks.
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
name|LLVM_PASSREGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PASSREGISTRY_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/Core.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/PassInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CBindingWrapping.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/RWMutex.h"
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
name|PassInfo
decl_stmt|;
struct_decl|struct
name|PassRegistrationListener
struct_decl|;
comment|/// PassRegistry - This class manages the registration and intitialization of
comment|/// the pass subsystem as application startup, and assists the PassManager
comment|/// in resolving pass dependencies.
comment|/// NOTE: PassRegistry is NOT thread-safe.  If you want to use LLVM on multiple
comment|/// threads simultaneously, you will need to use a separate PassRegistry on
comment|/// each thread.
name|class
name|PassRegistry
block|{
name|mutable
name|sys
operator|::
name|SmartRWMutex
operator|<
name|true
operator|>
name|Lock
expr_stmt|;
comment|/// PassInfoMap - Keep track of the PassInfo object for each registered pass.
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|void
operator|*
operator|,
specifier|const
name|PassInfo
operator|*
operator|>
name|MapType
expr_stmt|;
name|MapType
name|PassInfoMap
decl_stmt|;
typedef|typedef
name|StringMap
operator|<
specifier|const
name|PassInfo
operator|*
operator|>
name|StringMapType
expr_stmt|;
name|StringMapType
name|PassInfoStringMap
decl_stmt|;
comment|/// AnalysisGroupInfo - Keep track of information for each analysis group.
struct|struct
name|AnalysisGroupInfo
block|{
name|SmallPtrSet
operator|<
specifier|const
name|PassInfo
operator|*
operator|,
literal|8
operator|>
name|Implementations
expr_stmt|;
block|}
struct|;
name|DenseMap
operator|<
specifier|const
name|PassInfo
operator|*
operator|,
name|AnalysisGroupInfo
operator|>
name|AnalysisGroupInfoMap
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
specifier|const
name|PassInfo
operator|>>
name|ToFree
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|PassRegistrationListener
operator|*
operator|>
name|Listeners
expr_stmt|;
name|public
label|:
name|PassRegistry
argument_list|()
block|{ }
operator|~
name|PassRegistry
argument_list|()
expr_stmt|;
comment|/// getPassRegistry - Access the global registry object, which is
comment|/// automatically initialized at application launch and destroyed by
comment|/// llvm_shutdown.
specifier|static
name|PassRegistry
modifier|*
name|getPassRegistry
parameter_list|()
function_decl|;
comment|/// getPassInfo - Look up a pass' corresponding PassInfo, indexed by the pass'
comment|/// type identifier (&MyPass::ID).
specifier|const
name|PassInfo
modifier|*
name|getPassInfo
argument_list|(
specifier|const
name|void
operator|*
name|TI
argument_list|)
decl|const
decl_stmt|;
comment|/// getPassInfo - Look up a pass' corresponding PassInfo, indexed by the pass'
comment|/// argument string.
specifier|const
name|PassInfo
modifier|*
name|getPassInfo
argument_list|(
name|StringRef
name|Arg
argument_list|)
decl|const
decl_stmt|;
comment|/// registerPass - Register a pass (by means of its PassInfo) with the
comment|/// registry.  Required in order to use the pass with a PassManager.
name|void
name|registerPass
parameter_list|(
specifier|const
name|PassInfo
modifier|&
name|PI
parameter_list|,
name|bool
name|ShouldFree
init|=
name|false
parameter_list|)
function_decl|;
comment|/// registerPass - Unregister a pass (by means of its PassInfo) with the
comment|/// registry.
name|void
name|unregisterPass
parameter_list|(
specifier|const
name|PassInfo
modifier|&
name|PI
parameter_list|)
function_decl|;
comment|/// registerAnalysisGroup - Register an analysis group (or a pass implementing
comment|// an analysis group) with the registry.  Like registerPass, this is required
comment|// in order for a PassManager to be able to use this group/pass.
name|void
name|registerAnalysisGroup
parameter_list|(
specifier|const
name|void
modifier|*
name|InterfaceID
parameter_list|,
specifier|const
name|void
modifier|*
name|PassID
parameter_list|,
name|PassInfo
modifier|&
name|Registeree
parameter_list|,
name|bool
name|isDefault
parameter_list|,
name|bool
name|ShouldFree
init|=
name|false
parameter_list|)
function_decl|;
comment|/// enumerateWith - Enumerate the registered passes, calling the provided
comment|/// PassRegistrationListener's passEnumerate() callback on each of them.
name|void
name|enumerateWith
parameter_list|(
name|PassRegistrationListener
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// addRegistrationListener - Register the given PassRegistrationListener
comment|/// to receive passRegistered() callbacks whenever a new pass is registered.
name|void
name|addRegistrationListener
parameter_list|(
name|PassRegistrationListener
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// removeRegistrationListener - Unregister a PassRegistrationListener so that
comment|/// it no longer receives passRegistered() callbacks.
name|void
name|removeRegistrationListener
parameter_list|(
name|PassRegistrationListener
modifier|*
name|L
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|// Create wrappers for C Binding types (see CBindingWrapping.h).
name|DEFINE_STDCXX_CONVERSION_FUNCTIONS
argument_list|(
argument|PassRegistry
argument_list|,
argument|LLVMPassRegistryRef
argument_list|)
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

