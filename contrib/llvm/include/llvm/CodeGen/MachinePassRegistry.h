begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/MachinePassRegistry.h ----------------------*- C++ -*-===//
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
comment|// This file contains the mechanics for machine function pass registries.  A
end_comment

begin_comment
comment|// function pass registry (MachinePassRegistry) is auto filled by the static
end_comment

begin_comment
comment|// constructors of MachinePassRegistryNode.  Further there is a command line
end_comment

begin_comment
comment|// parser (RegisterPassParser) which listens to each registry for additions
end_comment

begin_comment
comment|// and deletions, so that the appropriate command option is updated.
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
name|LLVM_CODEGEN_MACHINEPASSREGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEPASSREGISTRY_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/Passes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|MachinePassCtor
function_decl|)
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|///
comment|/// MachinePassRegistryListener - Listener to adds and removals of nodes in
comment|/// registration list.
comment|///
comment|//===----------------------------------------------------------------------===//
name|class
name|MachinePassRegistryListener
block|{
name|public
label|:
name|MachinePassRegistryListener
argument_list|()
block|{}
name|virtual
operator|~
name|MachinePassRegistryListener
argument_list|()
block|{}
name|virtual
name|void
name|NotifyAdd
argument_list|(
argument|const char *N
argument_list|,
argument|MachinePassCtor C
argument_list|,
argument|const char *D
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|NotifyRemove
parameter_list|(
specifier|const
name|char
modifier|*
name|N
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|///
comment|/// MachinePassRegistryNode - Machine pass node stored in registration list.
comment|///
comment|//===----------------------------------------------------------------------===//
name|class
name|MachinePassRegistryNode
block|{
name|private
label|:
name|MachinePassRegistryNode
modifier|*
name|Next
decl_stmt|;
comment|// Next function pass in list.
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
comment|// Name of function pass.
specifier|const
name|char
modifier|*
name|Description
decl_stmt|;
comment|// Description string.
name|MachinePassCtor
name|Ctor
decl_stmt|;
comment|// Function pass creator.
name|public
label|:
name|MachinePassRegistryNode
argument_list|(
argument|const char *N
argument_list|,
argument|const char *D
argument_list|,
argument|MachinePassCtor C
argument_list|)
block|:
name|Next
argument_list|(
name|NULL
argument_list|)
operator|,
name|Name
argument_list|(
name|N
argument_list|)
operator|,
name|Description
argument_list|(
name|D
argument_list|)
operator|,
name|Ctor
argument_list|(
argument|C
argument_list|)
block|{}
comment|// Accessors
name|MachinePassRegistryNode
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
name|Next
return|;
block|}
name|MachinePassRegistryNode
modifier|*
modifier|*
name|getNextAddress
parameter_list|()
block|{
return|return
operator|&
name|Next
return|;
block|}
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
specifier|const
name|char
operator|*
name|getDescription
argument_list|()
specifier|const
block|{
return|return
name|Description
return|;
block|}
name|MachinePassCtor
name|getCtor
argument_list|()
specifier|const
block|{
return|return
name|Ctor
return|;
block|}
name|void
name|setNext
parameter_list|(
name|MachinePassRegistryNode
modifier|*
name|N
parameter_list|)
block|{
name|Next
operator|=
name|N
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|///
comment|/// MachinePassRegistry - Track the registration of machine passes.
comment|///
comment|//===----------------------------------------------------------------------===//
name|class
name|MachinePassRegistry
block|{
name|private
label|:
name|MachinePassRegistryNode
modifier|*
name|List
decl_stmt|;
comment|// List of registry nodes.
name|MachinePassCtor
name|Default
decl_stmt|;
comment|// Default function pass creator.
name|MachinePassRegistryListener
modifier|*
name|Listener
decl_stmt|;
comment|// Listener for list adds are removes.
name|public
label|:
comment|// NO CONSTRUCTOR - we don't want static constructor ordering to mess
comment|// with the registry.
comment|// Accessors.
comment|//
name|MachinePassRegistryNode
modifier|*
name|getList
parameter_list|()
block|{
return|return
name|List
return|;
block|}
name|MachinePassCtor
name|getDefault
parameter_list|()
block|{
return|return
name|Default
return|;
block|}
name|void
name|setDefault
parameter_list|(
name|MachinePassCtor
name|C
parameter_list|)
block|{
name|Default
operator|=
name|C
expr_stmt|;
block|}
name|void
name|setListener
parameter_list|(
name|MachinePassRegistryListener
modifier|*
name|L
parameter_list|)
block|{
name|Listener
operator|=
name|L
expr_stmt|;
block|}
comment|/// Add - Adds a function pass to the registration list.
comment|///
name|void
name|Add
parameter_list|(
name|MachinePassRegistryNode
modifier|*
name|Node
parameter_list|)
function_decl|;
comment|/// Remove - Removes a function pass from the registration list.
comment|///
name|void
name|Remove
parameter_list|(
name|MachinePassRegistryNode
modifier|*
name|Node
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|///
comment|/// RegisterPassParser class - Handle the addition of new machine passes.
comment|///
comment|//===----------------------------------------------------------------------===//
name|template
operator|<
name|class
name|RegistryClass
operator|>
name|class
name|RegisterPassParser
operator|:
name|public
name|MachinePassRegistryListener
operator|,
name|public
name|cl
operator|::
name|parser
operator|<
name|typename
name|RegistryClass
operator|::
name|FunctionPassCtor
operator|>
block|{
name|public
operator|:
name|RegisterPassParser
argument_list|()
block|{}
operator|~
name|RegisterPassParser
argument_list|()
block|{
name|RegistryClass
operator|::
name|setListener
argument_list|(
name|NULL
argument_list|)
block|; }
name|void
name|initialize
argument_list|(
argument|cl::Option&O
argument_list|)
block|{
name|cl
operator|::
name|parser
operator|<
name|typename
name|RegistryClass
operator|::
name|FunctionPassCtor
operator|>
operator|::
name|initialize
argument_list|(
name|O
argument_list|)
block|;
comment|// Add existing passes to option.
for|for
control|(
name|RegistryClass
modifier|*
name|Node
init|=
name|RegistryClass
operator|::
name|getList
argument_list|()
init|;
name|Node
condition|;
name|Node
operator|=
name|Node
operator|->
name|getNext
argument_list|()
control|)
block|{
name|this
operator|->
name|addLiteralOption
argument_list|(
name|Node
operator|->
name|getName
argument_list|()
argument_list|,
operator|(
name|typename
name|RegistryClass
operator|::
name|FunctionPassCtor
operator|)
name|Node
operator|->
name|getCtor
argument_list|()
argument_list|,
name|Node
operator|->
name|getDescription
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Make sure we listen for list changes.
name|RegistryClass
operator|::
name|setListener
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
comment|// Implement the MachinePassRegistryListener callbacks.
comment|//
name|virtual
name|void
name|NotifyAdd
argument_list|(
argument|const char *N
argument_list|,
argument|MachinePassCtor C
argument_list|,
argument|const char *D
argument_list|)
block|{
name|this
operator|->
name|addLiteralOption
argument_list|(
name|N
argument_list|,
operator|(
name|typename
name|RegistryClass
operator|::
name|FunctionPassCtor
operator|)
name|C
argument_list|,
name|D
argument_list|)
block|;   }
name|virtual
name|void
name|NotifyRemove
argument_list|(
argument|const char *N
argument_list|)
block|{
name|this
operator|->
name|removeLiteralOption
argument_list|(
name|N
argument_list|)
block|;   }
expr|}
block|;   }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

