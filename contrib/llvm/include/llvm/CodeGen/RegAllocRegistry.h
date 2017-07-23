begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/CodeGen/RegAllocRegistry.h --------------------------*- C++ -*-===//
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
comment|// This file contains the implementation for register allocator function
end_comment

begin_comment
comment|// pass registry (RegisterRegAlloc).
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
name|LLVM_CODEGEN_REGALLOCREGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_REGALLOCREGISTRY_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachinePassRegistry.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionPass
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|///
comment|/// RegisterRegAlloc class - Track the registration of register allocators.
comment|///
comment|//===----------------------------------------------------------------------===//
name|class
name|RegisterRegAlloc
range|:
name|public
name|MachinePassRegistryNode
block|{
name|public
operator|:
name|using
name|FunctionPassCtor
operator|=
name|FunctionPass
operator|*
call|(
modifier|*
call|)
argument_list|()
block|;
specifier|static
name|MachinePassRegistry
name|Registry
block|;
name|RegisterRegAlloc
argument_list|(
argument|const char *N
argument_list|,
argument|const char *D
argument_list|,
argument|FunctionPassCtor C
argument_list|)
operator|:
name|MachinePassRegistryNode
argument_list|(
argument|N
argument_list|,
argument|D
argument_list|,
argument|(MachinePassCtor)C
argument_list|)
block|{
name|Registry
operator|.
name|Add
argument_list|(
name|this
argument_list|)
block|;   }
operator|~
name|RegisterRegAlloc
argument_list|()
block|{
name|Registry
operator|.
name|Remove
argument_list|(
name|this
argument_list|)
block|; }
comment|// Accessors.
name|RegisterRegAlloc
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
operator|(
name|RegisterRegAlloc
operator|*
operator|)
name|MachinePassRegistryNode
operator|::
name|getNext
argument_list|()
return|;
block|}
specifier|static
name|RegisterRegAlloc
operator|*
name|getList
argument_list|()
block|{
return|return
operator|(
name|RegisterRegAlloc
operator|*
operator|)
name|Registry
operator|.
name|getList
argument_list|()
return|;
block|}
specifier|static
name|FunctionPassCtor
name|getDefault
argument_list|()
block|{
return|return
operator|(
name|FunctionPassCtor
operator|)
name|Registry
operator|.
name|getDefault
argument_list|()
return|;
block|}
specifier|static
name|void
name|setDefault
argument_list|(
argument|FunctionPassCtor C
argument_list|)
block|{
name|Registry
operator|.
name|setDefault
argument_list|(
operator|(
name|MachinePassCtor
operator|)
name|C
argument_list|)
block|;   }
specifier|static
name|void
name|setListener
argument_list|(
argument|MachinePassRegistryListener *L
argument_list|)
block|{
name|Registry
operator|.
name|setListener
argument_list|(
name|L
argument_list|)
block|;   }
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_REGALLOCREGISTRY_H
end_comment

end_unit

