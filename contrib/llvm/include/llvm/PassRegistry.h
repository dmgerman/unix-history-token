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
comment|// and registration of passes.  At initialization, passes are registered with
end_comment

begin_comment
comment|// the PassRegistry, which is later provided to the PassManager for dependency
end_comment

begin_comment
comment|// resolution and similar tasks.
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
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Mutex.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<set>
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
name|class
name|PassRegistry
block|{
comment|/// Guards the contents of this class.
name|mutable
name|sys
operator|::
name|SmartMutex
operator|<
name|true
operator|>
name|Lock
expr_stmt|;
comment|/// PassInfoMap - Keep track of the PassInfo object for each registered pass.
typedef|typedef
name|std
operator|::
name|map
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
name|std
operator|::
name|set
operator|<
specifier|const
name|PassInfo
operator|*
operator|>
name|Implementations
expr_stmt|;
block|}
struct|;
name|std
operator|::
name|map
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
name|PassRegistrationListener
operator|*
operator|>
name|Listeners
expr_stmt|;
name|public
label|:
specifier|static
name|PassRegistry
modifier|*
name|getPassRegistry
parameter_list|()
function_decl|;
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
name|void
name|registerPass
parameter_list|(
specifier|const
name|PassInfo
modifier|&
name|PI
parameter_list|)
function_decl|;
name|void
name|unregisterPass
parameter_list|(
specifier|const
name|PassInfo
modifier|&
name|PI
parameter_list|)
function_decl|;
comment|/// Analysis Group Mechanisms.
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
parameter_list|)
function_decl|;
name|void
name|enumerateWith
parameter_list|(
name|PassRegistrationListener
modifier|*
name|L
parameter_list|)
function_decl|;
name|void
name|addRegistrationListener
parameter_list|(
name|PassRegistrationListener
modifier|*
name|L
parameter_list|)
function_decl|;
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
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

