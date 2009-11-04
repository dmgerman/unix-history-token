begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- JITEventListener.h - Exposes events from JIT compilation -*- C++ -*-===//
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
comment|// This file defines the JITEventListener interface, which lets users get
end_comment

begin_comment
comment|// callbacks when significant events happen during the JIT compilation process.
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
name|LLVM_EXECUTION_ENGINE_JIT_EVENTLISTENER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTION_ENGINE_JIT_EVENTLISTENER_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DebugLoc.h"
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
name|Function
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
comment|/// Empty for now, but this object will contain all details about the
comment|/// generated machine code that a Listener might care about.
struct|struct
name|JITEvent_EmittedFunctionDetails
block|{
specifier|const
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
struct|struct
name|LineStart
block|{
comment|// The address at which the current line changes.
name|uintptr_t
name|Address
decl_stmt|;
comment|// The new location information.  These can be translated to
comment|// DebugLocTuples using MF->getDebugLocTuple().
name|DebugLoc
name|Loc
decl_stmt|;
block|}
struct|;
comment|// This holds line boundary information sorted by address.
name|std
operator|::
name|vector
operator|<
name|LineStart
operator|>
name|LineStarts
expr_stmt|;
block|}
struct|;
comment|/// JITEventListener - This interface is used by the JIT to notify clients about
comment|/// significant events during compilation.  For example, we could have
comment|/// implementations for profilers and debuggers that need to know where
comment|/// functions have been emitted.
comment|///
comment|/// Each method defaults to doing nothing, so you only need to override the ones
comment|/// you care about.
name|class
name|JITEventListener
block|{
name|public
label|:
name|JITEventListener
argument_list|()
block|{}
name|virtual
operator|~
name|JITEventListener
argument_list|()
expr_stmt|;
comment|// Defined in JIT.cpp.
typedef|typedef
name|JITEvent_EmittedFunctionDetails
name|EmittedFunctionDetails
typedef|;
comment|/// NotifyFunctionEmitted - Called after a function has been successfully
comment|/// emitted to memory.  The function still has its MachineFunction attached,
comment|/// if you should happen to need that.
name|virtual
name|void
name|NotifyFunctionEmitted
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|,
name|void
modifier|*
name|Code
parameter_list|,
name|size_t
name|Size
parameter_list|,
specifier|const
name|EmittedFunctionDetails
modifier|&
name|Details
parameter_list|)
block|{}
comment|/// NotifyFreeingMachineCode - This is called inside of
comment|/// freeMachineCodeForFunction(), after the global mapping is removed, but
comment|/// before the machine code is returned to the allocator.  OldPtr is the
comment|/// address of the machine code and will be the same as the Code parameter to
comment|/// a previous NotifyFunctionEmitted call.  The Function passed to
comment|/// NotifyFunctionEmitted may have been destroyed by the time of the matching
comment|/// NotifyFreeingMachineCode call.
name|virtual
name|void
name|NotifyFreeingMachineCode
parameter_list|(
name|void
modifier|*
name|OldPtr
parameter_list|)
block|{}
block|}
empty_stmt|;
comment|// This returns NULL if support isn't available.
name|JITEventListener
modifier|*
name|createOProfileJITEventListener
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

