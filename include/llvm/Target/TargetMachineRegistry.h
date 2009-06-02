begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Target/TargetMachineRegistry.h - Target Registration ----*- C++ -*-===//
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
comment|// This file exposes two classes: the TargetMachineRegistry class, which allows
end_comment

begin_comment
comment|// tools to inspect all of registered targets, and the RegisterTarget class,
end_comment

begin_comment
comment|// which TargetMachine implementations should use to register themselves with
end_comment

begin_comment
comment|// the system.
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
name|LLVM_TARGET_TARGETMACHINEREGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETMACHINEREGISTRY_H
end_define

begin_include
include|#
directive|include
file|"llvm/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Registry.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
struct|struct
name|TargetMachineRegistryEntry
block|{
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
specifier|const
name|char
modifier|*
name|ShortDesc
decl_stmt|;
name|TargetMachine
argument_list|*
call|(
modifier|*
name|CtorFn
call|)
argument_list|(
specifier|const
name|Module
operator|&
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
argument_list|)
argument_list|;
name|unsigned
argument_list|(
operator|*
name|ModuleMatchQualityFn
argument_list|)
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|)
argument_list|;
name|unsigned
argument_list|(
operator|*
name|JITMatchQualityFn
argument_list|)
argument_list|()
argument_list|;
name|public
operator|:
name|TargetMachineRegistryEntry
argument_list|(
specifier|const
name|char
operator|*
name|N
argument_list|,
specifier|const
name|char
operator|*
name|SD
argument_list|,
name|TargetMachine
operator|*
call|(
modifier|*
name|CF
call|)
argument_list|(
specifier|const
name|Module
operator|&
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
argument_list|)
argument_list|,
name|unsigned
argument_list|(
operator|*
name|MMF
argument_list|)
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|)
argument_list|,
name|unsigned
argument_list|(
operator|*
name|JMF
argument_list|)
argument_list|()
argument_list|)
operator|:
name|Name
argument_list|(
name|N
argument_list|)
argument_list|,
name|ShortDesc
argument_list|(
name|SD
argument_list|)
argument_list|,
name|CtorFn
argument_list|(
name|CF
argument_list|)
argument_list|,
name|ModuleMatchQualityFn
argument_list|(
name|MMF
argument_list|)
argument_list|,
name|JITMatchQualityFn
argument_list|(
argument|JMF
argument_list|)
block|{}
block|}
struct|;
name|template
operator|<
operator|>
name|class
name|RegistryTraits
operator|<
name|TargetMachine
operator|>
block|{
name|public
operator|:
typedef|typedef
name|TargetMachineRegistryEntry
name|entry
typedef|;
specifier|static
specifier|const
name|char
operator|*
name|nameof
argument_list|(
argument|const entry&Entry
argument_list|)
block|{
return|return
name|Entry
operator|.
name|Name
return|;
block|}
specifier|static
specifier|const
name|char
operator|*
name|descof
argument_list|(
argument|const entry&Entry
argument_list|)
block|{
return|return
name|Entry
operator|.
name|ShortDesc
return|;
block|}
block|}
empty_stmt|;
name|struct
name|TargetMachineRegistry
range|:
name|public
name|Registry
operator|<
name|TargetMachine
operator|>
block|{
comment|/// getClosestStaticTargetForModule - Given an LLVM module, pick the best
comment|/// target that is compatible with the module.  If no close target can be
comment|/// found, this returns null and sets the Error string to a reason.
specifier|static
specifier|const
name|entry
operator|*
name|getClosestStaticTargetForModule
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|,
name|std
operator|::
name|string
operator|&
name|Error
argument_list|)
block|;
comment|/// getClosestTargetForJIT - Pick the best target that is compatible with
comment|/// the current host.  If no close target can be found, this returns null
comment|/// and sets the Error string to a reason.
specifier|static
specifier|const
name|entry
operator|*
name|getClosestTargetForJIT
argument_list|(
name|std
operator|::
name|string
operator|&
name|Error
argument_list|)
block|;    }
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|/// RegisterTarget - This class is used to make targets automatically register
comment|/// themselves with the tool they are linked.  Targets should define an
comment|/// instance of this and implement the static methods described in the
comment|/// TargetMachine comments.
comment|/// The type 'TargetMachineImpl' should provide a constructor with two
comment|/// parameters:
comment|/// - const Module& M: the module that is being compiled:
comment|/// - const std::string& FS: target-specific string describing target
comment|///   flavour.
name|template
operator|<
name|class
name|TargetMachineImpl
operator|>
expr|struct
name|RegisterTarget
block|{
name|RegisterTarget
argument_list|(
specifier|const
name|char
operator|*
name|Name
argument_list|,
specifier|const
name|char
operator|*
name|ShortDesc
argument_list|)
operator|:
name|Entry
argument_list|(
name|Name
argument_list|,
name|ShortDesc
argument_list|,
operator|&
name|Allocator
argument_list|,
operator|&
name|TargetMachineImpl
operator|::
name|getModuleMatchQuality
argument_list|,
operator|&
name|TargetMachineImpl
operator|::
name|getJITMatchQuality
argument_list|)
block|,
name|Node
argument_list|(
argument|Entry
argument_list|)
block|{}
name|private
operator|:
name|TargetMachineRegistry
operator|::
name|entry
name|Entry
block|;
name|TargetMachineRegistry
operator|::
name|node
name|Node
block|;
specifier|static
name|TargetMachine
operator|*
name|Allocator
argument_list|(
argument|const Module&M
argument_list|,
argument|const std::string&FS
argument_list|)
block|{
return|return
name|new
name|TargetMachineImpl
argument_list|(
name|M
argument_list|,
name|FS
argument_list|)
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

