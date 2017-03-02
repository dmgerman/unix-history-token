begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Action.h - Abstract compilation steps ------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_DRIVER_ACTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_DRIVER_ACTION_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Cuda.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Types.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Util.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|namespace
name|opt
block|{
name|class
name|Arg
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|class
name|ToolChain
decl_stmt|;
comment|/// Action - Represent an abstract compilation step to perform.
comment|///
comment|/// An action represents an edge in the compilation graph; typically
comment|/// it is a job to transform an input using some tool.
comment|///
comment|/// The current driver is hard wired to expect actions which produce a
comment|/// single primary output, at least in terms of controlling the
comment|/// compilation. Actions can produce auxiliary files, but can only
comment|/// produce a single output to feed into subsequent actions.
comment|///
comment|/// Actions are usually owned by a Compilation, which creates new
comment|/// actions via MakeAction().
name|class
name|Action
block|{
name|public
label|:
typedef|typedef
name|ActionList
operator|::
name|size_type
name|size_type
expr_stmt|;
typedef|typedef
name|ActionList
operator|::
name|iterator
name|input_iterator
expr_stmt|;
typedef|typedef
name|ActionList
operator|::
name|const_iterator
name|input_const_iterator
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|input_iterator
operator|>
name|input_range
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|input_const_iterator
operator|>
name|input_const_range
expr_stmt|;
enum|enum
name|ActionClass
block|{
name|InputClass
init|=
literal|0
block|,
name|BindArchClass
block|,
name|OffloadClass
block|,
name|PreprocessJobClass
block|,
name|PrecompileJobClass
block|,
name|AnalyzeJobClass
block|,
name|MigrateJobClass
block|,
name|CompileJobClass
block|,
name|BackendJobClass
block|,
name|AssembleJobClass
block|,
name|LinkJobClass
block|,
name|LipoJobClass
block|,
name|DsymutilJobClass
block|,
name|VerifyDebugInfoJobClass
block|,
name|VerifyPCHJobClass
block|,
name|OffloadBundlingJobClass
block|,
name|OffloadUnbundlingJobClass
block|,
name|JobClassFirst
init|=
name|PreprocessJobClass
block|,
name|JobClassLast
init|=
name|OffloadUnbundlingJobClass
block|}
enum|;
comment|// The offloading kind determines if this action is binded to a particular
comment|// programming model. Each entry reserves one bit. We also have a special kind
comment|// to designate the host offloading tool chain.
enum|enum
name|OffloadKind
block|{
name|OFK_None
init|=
literal|0x00
block|,
comment|// The host offloading tool chain.
name|OFK_Host
init|=
literal|0x01
block|,
comment|// The device offloading tool chains - one bit for each programming model.
name|OFK_Cuda
init|=
literal|0x02
block|,
name|OFK_OpenMP
init|=
literal|0x04
block|,   }
enum|;
specifier|static
specifier|const
name|char
modifier|*
name|getClassName
parameter_list|(
name|ActionClass
name|AC
parameter_list|)
function_decl|;
name|private
label|:
name|ActionClass
name|Kind
decl_stmt|;
comment|/// The output type of this action.
name|types
operator|::
name|ID
name|Type
expr_stmt|;
name|ActionList
name|Inputs
decl_stmt|;
comment|/// Flag that is set to true if this action can be collapsed with others
comment|/// actions that depend on it. This is true by default and set to false when
comment|/// the action is used by two different tool chains, which is enabled by the
comment|/// offloading support implementation.
name|bool
name|CanBeCollapsedWithNextDependentAction
init|=
name|true
decl_stmt|;
name|protected
label|:
comment|///
comment|/// Offload information.
comment|///
comment|/// The host offloading kind - a combination of kinds encoded in a mask.
comment|/// Multiple programming models may be supported simultaneously by the same
comment|/// host.
name|unsigned
name|ActiveOffloadKindMask
init|=
literal|0u
decl_stmt|;
comment|/// Offloading kind of the device.
name|OffloadKind
name|OffloadingDeviceKind
init|=
name|OFK_None
decl_stmt|;
comment|/// The Offloading architecture associated with this action.
specifier|const
name|char
modifier|*
name|OffloadingArch
init|=
name|nullptr
decl_stmt|;
name|Action
argument_list|(
argument|ActionClass Kind
argument_list|,
argument|types::ID Type
argument_list|)
block|:
name|Action
argument_list|(
argument|Kind
argument_list|,
argument|ActionList()
argument_list|,
argument|Type
argument_list|)
block|{}
name|Action
argument_list|(
argument|ActionClass Kind
argument_list|,
argument|Action *Input
argument_list|,
argument|types::ID Type
argument_list|)
block|:
name|Action
argument_list|(
argument|Kind
argument_list|,
argument|ActionList({Input})
argument_list|,
argument|Type
argument_list|)
block|{}
name|Action
argument_list|(
argument|ActionClass Kind
argument_list|,
argument|Action *Input
argument_list|)
block|:
name|Action
argument_list|(
argument|Kind
argument_list|,
argument|ActionList({Input})
argument_list|,
argument|Input->getType()
argument_list|)
block|{}
name|Action
argument_list|(
argument|ActionClass Kind
argument_list|,
argument|const ActionList&Inputs
argument_list|,
argument|types::ID Type
argument_list|)
block|:
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|Type
argument_list|(
name|Type
argument_list|)
operator|,
name|Inputs
argument_list|(
argument|Inputs
argument_list|)
block|{}
name|public
operator|:
name|virtual
operator|~
name|Action
argument_list|()
expr_stmt|;
specifier|const
name|char
operator|*
name|getClassName
argument_list|()
specifier|const
block|{
return|return
name|Action
operator|::
name|getClassName
argument_list|(
name|getKind
argument_list|()
argument_list|)
return|;
block|}
name|ActionClass
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|types
operator|::
name|ID
name|getType
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
name|ActionList
modifier|&
name|getInputs
parameter_list|()
block|{
return|return
name|Inputs
return|;
block|}
specifier|const
name|ActionList
operator|&
name|getInputs
argument_list|()
specifier|const
block|{
return|return
name|Inputs
return|;
block|}
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|Inputs
operator|.
name|size
argument_list|()
return|;
block|}
name|input_iterator
name|input_begin
parameter_list|()
block|{
return|return
name|Inputs
operator|.
name|begin
argument_list|()
return|;
block|}
name|input_iterator
name|input_end
parameter_list|()
block|{
return|return
name|Inputs
operator|.
name|end
argument_list|()
return|;
block|}
name|input_range
name|inputs
parameter_list|()
block|{
return|return
name|input_range
argument_list|(
name|input_begin
argument_list|()
argument_list|,
name|input_end
argument_list|()
argument_list|)
return|;
block|}
name|input_const_iterator
name|input_begin
argument_list|()
specifier|const
block|{
return|return
name|Inputs
operator|.
name|begin
argument_list|()
return|;
block|}
name|input_const_iterator
name|input_end
argument_list|()
specifier|const
block|{
return|return
name|Inputs
operator|.
name|end
argument_list|()
return|;
block|}
name|input_const_range
name|inputs
argument_list|()
specifier|const
block|{
return|return
name|input_const_range
argument_list|(
name|input_begin
argument_list|()
argument_list|,
name|input_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// Mark this action as not legal to collapse.
name|void
name|setCannotBeCollapsedWithNextDependentAction
parameter_list|()
block|{
name|CanBeCollapsedWithNextDependentAction
operator|=
name|false
expr_stmt|;
block|}
comment|/// Return true if this function can be collapsed with others.
name|bool
name|isCollapsingWithNextDependentActionLegal
argument_list|()
specifier|const
block|{
return|return
name|CanBeCollapsedWithNextDependentAction
return|;
block|}
comment|/// Return a string containing the offload kind of the action.
name|std
operator|::
name|string
name|getOffloadingKindPrefix
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return a string that can be used as prefix in order to generate unique
comment|/// files for each offloading kind. By default, no prefix is used for
comment|/// non-device kinds, except if \a CreatePrefixForHost is set.
specifier|static
name|std
operator|::
name|string
name|GetOffloadingFileNamePrefix
argument_list|(
argument|OffloadKind Kind
argument_list|,
argument|llvm::StringRef NormalizedTriple
argument_list|,
argument|bool CreatePrefixForHost = false
argument_list|)
expr_stmt|;
comment|/// Return a string containing a offload kind name.
specifier|static
name|StringRef
name|GetOffloadKindName
parameter_list|(
name|OffloadKind
name|Kind
parameter_list|)
function_decl|;
comment|/// Set the device offload info of this action and propagate it to its
comment|/// dependences.
name|void
name|propagateDeviceOffloadInfo
parameter_list|(
name|OffloadKind
name|OKind
parameter_list|,
specifier|const
name|char
modifier|*
name|OArch
parameter_list|)
function_decl|;
comment|/// Append the host offload info of this action and propagate it to its
comment|/// dependences.
name|void
name|propagateHostOffloadInfo
parameter_list|(
name|unsigned
name|OKinds
parameter_list|,
specifier|const
name|char
modifier|*
name|OArch
parameter_list|)
function_decl|;
comment|/// Set the offload info of this action to be the same as the provided action,
comment|/// and propagate it to its dependences.
name|void
name|propagateOffloadInfo
parameter_list|(
specifier|const
name|Action
modifier|*
name|A
parameter_list|)
function_decl|;
name|unsigned
name|getOffloadingHostActiveKinds
argument_list|()
specifier|const
block|{
return|return
name|ActiveOffloadKindMask
return|;
block|}
name|OffloadKind
name|getOffloadingDeviceKind
argument_list|()
specifier|const
block|{
return|return
name|OffloadingDeviceKind
return|;
block|}
specifier|const
name|char
operator|*
name|getOffloadingArch
argument_list|()
specifier|const
block|{
return|return
name|OffloadingArch
return|;
block|}
comment|/// Check if this action have any offload kinds. Note that host offload kinds
comment|/// are only set if the action is a dependence to a host offload action.
name|bool
name|isHostOffloading
argument_list|(
name|OffloadKind
name|OKind
argument_list|)
decl|const
block|{
return|return
name|ActiveOffloadKindMask
operator|&
name|OKind
return|;
block|}
name|bool
name|isDeviceOffloading
argument_list|(
name|OffloadKind
name|OKind
argument_list|)
decl|const
block|{
return|return
name|OffloadingDeviceKind
operator|==
name|OKind
return|;
block|}
name|bool
name|isOffloading
argument_list|(
name|OffloadKind
name|OKind
argument_list|)
decl|const
block|{
return|return
name|isHostOffloading
argument_list|(
name|OKind
argument_list|)
operator|||
name|isDeviceOffloading
argument_list|(
name|OKind
argument_list|)
return|;
block|}
block|}
empty_stmt|;
name|class
name|InputAction
range|:
name|public
name|Action
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|Arg
operator|&
name|Input
block|;
name|public
operator|:
name|InputAction
argument_list|(
argument|const llvm::opt::Arg&Input
argument_list|,
argument|types::ID Type
argument_list|)
block|;
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|Arg
operator|&
name|getInputArg
argument_list|()
specifier|const
block|{
return|return
name|Input
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|InputClass
return|;
block|}
expr|}
block|;
name|class
name|BindArchAction
operator|:
name|public
name|Action
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// The architecture to bind, or 0 if the default architecture
comment|/// should be bound.
name|StringRef
name|ArchName
block|;
name|public
operator|:
name|BindArchAction
argument_list|(
argument|Action *Input
argument_list|,
argument|StringRef ArchName
argument_list|)
block|;
name|StringRef
name|getArchName
argument_list|()
specifier|const
block|{
return|return
name|ArchName
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|BindArchClass
return|;
block|}
expr|}
block|;
comment|/// An offload action combines host or/and device actions according to the
comment|/// programming model implementation needs and propagates the offloading kind to
comment|/// its dependences.
name|class
name|OffloadAction
name|final
operator|:
name|public
name|Action
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
comment|/// Type used to communicate device actions. It associates bound architecture,
comment|/// toolchain, and offload kind to each action.
name|class
name|DeviceDependences
name|final
block|{
name|public
operator|:
typedef|typedef
name|SmallVector
operator|<
specifier|const
name|ToolChain
operator|*
operator|,
literal|3
operator|>
name|ToolChainList
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
specifier|const
name|char
operator|*
operator|,
literal|3
operator|>
name|BoundArchList
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|OffloadKind
operator|,
literal|3
operator|>
name|OffloadKindList
expr_stmt|;
name|private
operator|:
comment|// Lists that keep the information for each dependency. All the lists are
comment|// meant to be updated in sync. We are adopting separate lists instead of a
comment|// list of structs, because that simplifies forwarding the actions list to
comment|// initialize the inputs of the base Action class.
comment|/// The dependence actions.
name|ActionList
name|DeviceActions
block|;
comment|/// The offloading toolchains that should be used with the action.
name|ToolChainList
name|DeviceToolChains
block|;
comment|/// The architectures that should be used with this action.
name|BoundArchList
name|DeviceBoundArchs
block|;
comment|/// The offload kind of each dependence.
name|OffloadKindList
name|DeviceOffloadKinds
block|;
name|public
operator|:
comment|/// Add a action along with the associated toolchain, bound arch, and
comment|/// offload kind.
name|void
name|add
argument_list|(
argument|Action&A
argument_list|,
argument|const ToolChain&TC
argument_list|,
argument|const char *BoundArch
argument_list|,
argument|OffloadKind OKind
argument_list|)
block|;
comment|/// Get each of the individual arrays.
specifier|const
name|ActionList
operator|&
name|getActions
argument_list|()
specifier|const
block|{
return|return
name|DeviceActions
return|;
block|}
block|;
specifier|const
name|ToolChainList
operator|&
name|getToolChains
argument_list|()
specifier|const
block|{
return|return
name|DeviceToolChains
return|;
block|}
block|;
specifier|const
name|BoundArchList
operator|&
name|getBoundArchs
argument_list|()
specifier|const
block|{
return|return
name|DeviceBoundArchs
return|;
block|}
block|;
specifier|const
name|OffloadKindList
operator|&
name|getOffloadKinds
argument_list|()
specifier|const
block|{
return|return
name|DeviceOffloadKinds
return|;
block|}
block|;   }
decl_stmt|;
comment|/// Type used to communicate host actions. It associates bound architecture,
comment|/// toolchain, and offload kinds to the host action.
name|class
name|HostDependence
name|final
block|{
comment|/// The dependence action.
name|Action
modifier|&
name|HostAction
decl_stmt|;
comment|/// The offloading toolchain that should be used with the action.
specifier|const
name|ToolChain
modifier|&
name|HostToolChain
decl_stmt|;
comment|/// The architectures that should be used with this action.
specifier|const
name|char
modifier|*
name|HostBoundArch
init|=
name|nullptr
decl_stmt|;
comment|/// The offload kind of each dependence.
name|unsigned
name|HostOffloadKinds
init|=
literal|0u
decl_stmt|;
name|public
label|:
name|HostDependence
argument_list|(
argument|Action&A
argument_list|,
argument|const ToolChain&TC
argument_list|,
argument|const char *BoundArch
argument_list|,
argument|const unsigned OffloadKinds
argument_list|)
block|:
name|HostAction
argument_list|(
name|A
argument_list|)
operator|,
name|HostToolChain
argument_list|(
name|TC
argument_list|)
operator|,
name|HostBoundArch
argument_list|(
name|BoundArch
argument_list|)
operator|,
name|HostOffloadKinds
argument_list|(
argument|OffloadKinds
argument_list|)
block|{}
expr_stmt|;
comment|/// Constructor version that obtains the offload kinds from the device
comment|/// dependencies.
name|HostDependence
argument_list|(
name|Action
operator|&
name|A
argument_list|,
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|,
specifier|const
name|char
operator|*
name|BoundArch
argument_list|,
specifier|const
name|DeviceDependences
operator|&
name|DDeps
argument_list|)
expr_stmt|;
name|Action
operator|*
name|getAction
argument_list|()
specifier|const
block|{
return|return
operator|&
name|HostAction
return|;
block|}
empty_stmt|;
specifier|const
name|ToolChain
operator|*
name|getToolChain
argument_list|()
specifier|const
block|{
return|return
operator|&
name|HostToolChain
return|;
block|}
empty_stmt|;
specifier|const
name|char
operator|*
name|getBoundArch
argument_list|()
specifier|const
block|{
return|return
name|HostBoundArch
return|;
block|}
empty_stmt|;
name|unsigned
name|getOffloadKinds
argument_list|()
specifier|const
block|{
return|return
name|HostOffloadKinds
return|;
block|}
empty_stmt|;
block|}
empty_stmt|;
typedef|typedef
name|llvm
operator|::
name|function_ref
operator|<
name|void
argument_list|(
name|Action
operator|*
argument_list|,
specifier|const
name|ToolChain
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
operator|>
name|OffloadActionWorkTy
expr_stmt|;
name|private
label|:
comment|/// The host offloading toolchain that should be used with the action.
specifier|const
name|ToolChain
modifier|*
name|HostTC
init|=
name|nullptr
decl_stmt|;
comment|/// The tool chains associated with the list of actions.
name|DeviceDependences
operator|::
name|ToolChainList
name|DevToolChains
expr_stmt|;
name|public
label|:
name|OffloadAction
argument_list|(
specifier|const
name|HostDependence
operator|&
name|HDep
argument_list|)
expr_stmt|;
name|OffloadAction
argument_list|(
argument|const DeviceDependences&DDeps
argument_list|,
argument|types::ID Ty
argument_list|)
empty_stmt|;
name|OffloadAction
argument_list|(
specifier|const
name|HostDependence
operator|&
name|HDep
argument_list|,
specifier|const
name|DeviceDependences
operator|&
name|DDeps
argument_list|)
expr_stmt|;
comment|/// Execute the work specified in \a Work on the host dependence.
name|void
name|doOnHostDependence
argument_list|(
specifier|const
name|OffloadActionWorkTy
operator|&
name|Work
argument_list|)
decl|const
decl_stmt|;
comment|/// Execute the work specified in \a Work on each device dependence.
name|void
name|doOnEachDeviceDependence
argument_list|(
specifier|const
name|OffloadActionWorkTy
operator|&
name|Work
argument_list|)
decl|const
decl_stmt|;
comment|/// Execute the work specified in \a Work on each dependence.
name|void
name|doOnEachDependence
argument_list|(
specifier|const
name|OffloadActionWorkTy
operator|&
name|Work
argument_list|)
decl|const
decl_stmt|;
comment|/// Execute the work specified in \a Work on each host or device dependence if
comment|/// \a IsHostDependenceto is true or false, respectively.
name|void
name|doOnEachDependence
argument_list|(
name|bool
name|IsHostDependence
argument_list|,
specifier|const
name|OffloadActionWorkTy
operator|&
name|Work
argument_list|)
decl|const
decl_stmt|;
comment|/// Return true if the action has a host dependence.
name|bool
name|hasHostDependence
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return the host dependence of this action. This function is only expected
comment|/// to be called if the host dependence exists.
name|Action
operator|*
name|getHostDependence
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return true if the action has a single device dependence. If \a
comment|/// DoNotConsiderHostActions is set, ignore the host dependence, if any, while
comment|/// accounting for the number of dependences.
name|bool
name|hasSingleDeviceDependence
argument_list|(
name|bool
name|DoNotConsiderHostActions
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the single device dependence of this action. This function is only
comment|/// expected to be called if a single device dependence exists. If \a
comment|/// DoNotConsiderHostActions is set, a host dependence is allowed.
name|Action
modifier|*
name|getSingleDeviceDependence
argument_list|(
name|bool
name|DoNotConsiderHostActions
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Action
modifier|*
name|A
parameter_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|OffloadClass
return|;
block|}
block|}
empty_stmt|;
name|class
name|JobAction
range|:
name|public
name|Action
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|protected
operator|:
name|JobAction
argument_list|(
argument|ActionClass Kind
argument_list|,
argument|Action *Input
argument_list|,
argument|types::ID Type
argument_list|)
block|;
name|JobAction
argument_list|(
argument|ActionClass Kind
argument_list|,
argument|const ActionList&Inputs
argument_list|,
argument|types::ID Type
argument_list|)
block|;
name|public
operator|:
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
operator|(
name|A
operator|->
name|getKind
argument_list|()
operator|>=
name|JobClassFirst
operator|&&
name|A
operator|->
name|getKind
argument_list|()
operator|<=
name|JobClassLast
operator|)
return|;
block|}
expr|}
block|;
name|class
name|PreprocessJobAction
operator|:
name|public
name|JobAction
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|PreprocessJobAction
argument_list|(
argument|Action *Input
argument_list|,
argument|types::ID OutputType
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|PreprocessJobClass
return|;
block|}
expr|}
block|;
name|class
name|PrecompileJobAction
operator|:
name|public
name|JobAction
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|PrecompileJobAction
argument_list|(
argument|Action *Input
argument_list|,
argument|types::ID OutputType
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|PrecompileJobClass
return|;
block|}
expr|}
block|;
name|class
name|AnalyzeJobAction
operator|:
name|public
name|JobAction
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|AnalyzeJobAction
argument_list|(
argument|Action *Input
argument_list|,
argument|types::ID OutputType
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|AnalyzeJobClass
return|;
block|}
expr|}
block|;
name|class
name|MigrateJobAction
operator|:
name|public
name|JobAction
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|MigrateJobAction
argument_list|(
argument|Action *Input
argument_list|,
argument|types::ID OutputType
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|MigrateJobClass
return|;
block|}
expr|}
block|;
name|class
name|CompileJobAction
operator|:
name|public
name|JobAction
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|CompileJobAction
argument_list|(
argument|Action *Input
argument_list|,
argument|types::ID OutputType
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|CompileJobClass
return|;
block|}
expr|}
block|;
name|class
name|BackendJobAction
operator|:
name|public
name|JobAction
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|BackendJobAction
argument_list|(
argument|Action *Input
argument_list|,
argument|types::ID OutputType
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|BackendJobClass
return|;
block|}
expr|}
block|;
name|class
name|AssembleJobAction
operator|:
name|public
name|JobAction
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|AssembleJobAction
argument_list|(
argument|Action *Input
argument_list|,
argument|types::ID OutputType
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|AssembleJobClass
return|;
block|}
expr|}
block|;
name|class
name|LinkJobAction
operator|:
name|public
name|JobAction
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|LinkJobAction
argument_list|(
argument|ActionList&Inputs
argument_list|,
argument|types::ID Type
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|LinkJobClass
return|;
block|}
expr|}
block|;
name|class
name|LipoJobAction
operator|:
name|public
name|JobAction
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|LipoJobAction
argument_list|(
argument|ActionList&Inputs
argument_list|,
argument|types::ID Type
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|LipoJobClass
return|;
block|}
expr|}
block|;
name|class
name|DsymutilJobAction
operator|:
name|public
name|JobAction
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|DsymutilJobAction
argument_list|(
argument|ActionList&Inputs
argument_list|,
argument|types::ID Type
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|DsymutilJobClass
return|;
block|}
expr|}
block|;
name|class
name|VerifyJobAction
operator|:
name|public
name|JobAction
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|VerifyJobAction
argument_list|(
argument|ActionClass Kind
argument_list|,
argument|Action *Input
argument_list|,
argument|types::ID Type
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|VerifyDebugInfoJobClass
operator|||
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|VerifyPCHJobClass
return|;
block|}
expr|}
block|;
name|class
name|VerifyDebugInfoJobAction
operator|:
name|public
name|VerifyJobAction
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|VerifyDebugInfoJobAction
argument_list|(
argument|Action *Input
argument_list|,
argument|types::ID Type
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|VerifyDebugInfoJobClass
return|;
block|}
expr|}
block|;
name|class
name|VerifyPCHJobAction
operator|:
name|public
name|VerifyJobAction
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|VerifyPCHJobAction
argument_list|(
argument|Action *Input
argument_list|,
argument|types::ID Type
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|VerifyPCHJobClass
return|;
block|}
expr|}
block|;
name|class
name|OffloadBundlingJobAction
operator|:
name|public
name|JobAction
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
comment|// Offloading bundling doesn't change the type of output.
name|OffloadBundlingJobAction
argument_list|(
name|ActionList
operator|&
name|Inputs
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|OffloadBundlingJobClass
return|;
block|}
expr|}
block|;
name|class
name|OffloadUnbundlingJobAction
name|final
operator|:
name|public
name|JobAction
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
comment|/// Type that provides information about the actions that depend on this
comment|/// unbundling action.
expr|struct
name|DependentActionInfo
name|final
block|{
comment|/// \brief The tool chain of the dependent action.
specifier|const
name|ToolChain
operator|*
name|DependentToolChain
operator|=
name|nullptr
block|;
comment|/// \brief The bound architecture of the dependent action.
name|StringRef
name|DependentBoundArch
block|;
comment|/// \brief The offload kind of the dependent action.
specifier|const
name|OffloadKind
name|DependentOffloadKind
operator|=
name|OFK_None
block|;
name|DependentActionInfo
argument_list|(
argument|const ToolChain *DependentToolChain
argument_list|,
argument|StringRef DependentBoundArch
argument_list|,
argument|const OffloadKind DependentOffloadKind
argument_list|)
operator|:
name|DependentToolChain
argument_list|(
name|DependentToolChain
argument_list|)
block|,
name|DependentBoundArch
argument_list|(
name|DependentBoundArch
argument_list|)
block|,
name|DependentOffloadKind
argument_list|(
argument|DependentOffloadKind
argument_list|)
block|{}
block|;   }
block|;
name|private
operator|:
comment|/// Container that keeps information about each dependence of this unbundling
comment|/// action.
name|SmallVector
operator|<
name|DependentActionInfo
block|,
literal|6
operator|>
name|DependentActionInfoArray
block|;
name|public
operator|:
comment|// Offloading unbundling doesn't change the type of output.
name|OffloadUnbundlingJobAction
argument_list|(
name|Action
operator|*
name|Input
argument_list|)
block|;
comment|/// Register information about a dependent action.
name|void
name|registerDependentActionInfo
argument_list|(
argument|const ToolChain *TC
argument_list|,
argument|StringRef BoundArch
argument_list|,
argument|OffloadKind Kind
argument_list|)
block|{
name|DependentActionInfoArray
operator|.
name|push_back
argument_list|(
block|{
name|TC
block|,
name|BoundArch
block|,
name|Kind
block|}
argument_list|)
block|;   }
comment|/// Return the information about all depending actions.
name|ArrayRef
operator|<
name|DependentActionInfo
operator|>
name|getDependentActionsInfo
argument_list|()
specifier|const
block|{
return|return
name|DependentActionInfoArray
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Action *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|OffloadUnbundlingJobClass
return|;
block|}
expr|}
block|;  }
comment|// end namespace driver
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

