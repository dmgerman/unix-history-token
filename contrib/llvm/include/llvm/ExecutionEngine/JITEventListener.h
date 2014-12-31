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
name|LLVM_EXECUTIONENGINE_JITEVENTLISTENER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_JITEVENTLISTENER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Config/llvm-config.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
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
name|class
name|OProfileWrapper
decl_stmt|;
name|class
name|IntelJITEventsWrapper
decl_stmt|;
name|class
name|ObjectImage
decl_stmt|;
comment|/// JITEvent_EmittedFunctionDetails - Helper struct for containing information
comment|/// about a generated machine code function.
struct|struct
name|JITEvent_EmittedFunctionDetails
block|{
struct|struct
name|LineStart
block|{
comment|/// The address at which the current line changes.
name|uintptr_t
name|Address
decl_stmt|;
comment|/// The new location information.  These can be translated to DebugLocTuples
comment|/// using MF->getDebugLocTuple().
name|DebugLoc
name|Loc
decl_stmt|;
block|}
struct|;
comment|/// The machine function the struct contains information for.
specifier|const
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
comment|/// The list of line boundary information, sorted by address.
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
comment|/// JITEventListener - Abstract interface for use by the JIT to notify clients
comment|/// about significant events during compilation. For example, to notify
comment|/// profilers and debuggers that need to know where functions have been emitted.
comment|///
comment|/// The default implementation of each method does nothing.
name|class
name|JITEventListener
block|{
name|public
label|:
typedef|typedef
name|JITEvent_EmittedFunctionDetails
name|EmittedFunctionDetails
typedef|;
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
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|EmittedFunctionDetails
modifier|&
parameter_list|)
block|{}
comment|/// NotifyFreeingMachineCode - Called from freeMachineCodeForFunction(), after
comment|/// the global mapping is removed, but before the machine code is returned to
comment|/// the allocator.
comment|///
comment|/// OldPtr is the address of the machine code and will be the same as the Code
comment|/// parameter to a previous NotifyFunctionEmitted call.  The Function passed
comment|/// to NotifyFunctionEmitted may have been destroyed by the time of the
comment|/// matching NotifyFreeingMachineCode call.
name|virtual
name|void
name|NotifyFreeingMachineCode
parameter_list|(
name|void
modifier|*
parameter_list|)
block|{}
comment|/// NotifyObjectEmitted - Called after an object has been successfully
comment|/// emitted to memory.  NotifyFunctionEmitted will not be called for
comment|/// individual functions in the object.
comment|///
comment|/// ELF-specific information
comment|/// The ObjectImage contains the generated object image
comment|/// with section headers updated to reflect the address at which sections
comment|/// were loaded and with relocations performed in-place on debug sections.
name|virtual
name|void
name|NotifyObjectEmitted
parameter_list|(
specifier|const
name|ObjectImage
modifier|&
name|Obj
parameter_list|)
block|{}
comment|/// NotifyFreeingObject - Called just before the memory associated with
comment|/// a previously emitted object is released.
name|virtual
name|void
name|NotifyFreeingObject
parameter_list|(
specifier|const
name|ObjectImage
modifier|&
name|Obj
parameter_list|)
block|{}
if|#
directive|if
name|LLVM_USE_INTEL_JITEVENTS
comment|// Construct an IntelJITEventListener
specifier|static
name|JITEventListener
modifier|*
name|createIntelJITEventListener
parameter_list|()
function_decl|;
comment|// Construct an IntelJITEventListener with a test Intel JIT API implementation
specifier|static
name|JITEventListener
modifier|*
name|createIntelJITEventListener
parameter_list|(
name|IntelJITEventsWrapper
modifier|*
name|AlternativeImpl
parameter_list|)
function_decl|;
else|#
directive|else
specifier|static
name|JITEventListener
modifier|*
name|createIntelJITEventListener
parameter_list|()
block|{
return|return
name|nullptr
return|;
block|}
specifier|static
name|JITEventListener
modifier|*
name|createIntelJITEventListener
parameter_list|(
name|IntelJITEventsWrapper
modifier|*
name|AlternativeImpl
parameter_list|)
block|{
return|return
name|nullptr
return|;
block|}
endif|#
directive|endif
comment|// USE_INTEL_JITEVENTS
if|#
directive|if
name|LLVM_USE_OPROFILE
comment|// Construct an OProfileJITEventListener
specifier|static
name|JITEventListener
modifier|*
name|createOProfileJITEventListener
parameter_list|()
function_decl|;
comment|// Construct an OProfileJITEventListener with a test opagent implementation
specifier|static
name|JITEventListener
modifier|*
name|createOProfileJITEventListener
parameter_list|(
name|OProfileWrapper
modifier|*
name|AlternativeImpl
parameter_list|)
function_decl|;
else|#
directive|else
specifier|static
name|JITEventListener
modifier|*
name|createOProfileJITEventListener
parameter_list|()
block|{
return|return
name|nullptr
return|;
block|}
specifier|static
name|JITEventListener
modifier|*
name|createOProfileJITEventListener
parameter_list|(
name|OProfileWrapper
modifier|*
name|AlternativeImpl
parameter_list|)
block|{
return|return
name|nullptr
return|;
block|}
endif|#
directive|endif
comment|// USE_OPROFILE
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined LLVM_EXECUTIONENGINE_JITEVENTLISTENER_H
end_comment

end_unit

