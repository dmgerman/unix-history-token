begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- JITRegistrar.h - Registers objects with a debugger ----------------===//
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
name|LLVM_EXECUTION_ENGINE_JIT_REGISTRAR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTION_ENGINE_JIT_REGISTRAR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/ObjectBuffer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Global access point for the JIT debugging interface.
name|class
name|JITRegistrar
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
comment|/// Instantiates the JIT service.
name|JITRegistrar
argument_list|()
block|{}
comment|/// Unregisters each object that was previously registered and releases all
comment|/// internal resources.
name|virtual
operator|~
name|JITRegistrar
argument_list|()
block|{}
comment|/// Creates an entry in the JIT registry for the buffer @p Object,
comment|/// which must contain an object file in executable memory with any
comment|/// debug information for the debugger.
name|virtual
name|void
name|registerObject
argument_list|(
specifier|const
name|ObjectBuffer
operator|&
name|Object
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Removes the internal registration of @p Object, and
comment|/// frees associated resources.
comment|/// Returns true if @p Object was previously registered.
name|virtual
name|bool
name|deregisterObject
parameter_list|(
specifier|const
name|ObjectBuffer
modifier|&
name|Object
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Returns a reference to a GDB JIT registrar singleton
specifier|static
name|JITRegistrar
modifier|&
name|getGDBRegistrar
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_EXECUTION_ENGINE_JIT_REGISTRAR_H
end_comment

end_unit

