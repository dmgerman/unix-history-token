begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/IR/ModuleSlotTracker.h -----------------------------*- C++ -*-===//
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
name|LLVM_IR_MODULESLOTTRACKER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_MODULESLOTTRACKER_H
end_define

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|SlotTracker
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// Manage lifetime of a slot tracker for printing IR.
comment|///
comment|/// Wrapper around the \a SlotTracker used internally by \a AsmWriter.  This
comment|/// class allows callers to share the cost of incorporating the metadata in a
comment|/// module or a function.
comment|///
comment|/// If the IR changes from underneath \a ModuleSlotTracker, strings like
comment|/// "<badref>" will be printed, or, worse, the wrong slots entirely.
name|class
name|ModuleSlotTracker
block|{
comment|/// Storage for a slot tracker.
name|std
operator|::
name|unique_ptr
operator|<
name|SlotTracker
operator|>
name|MachineStorage
expr_stmt|;
specifier|const
name|Module
modifier|*
name|M
init|=
name|nullptr
decl_stmt|;
specifier|const
name|Function
modifier|*
name|F
init|=
name|nullptr
decl_stmt|;
name|SlotTracker
modifier|*
name|Machine
init|=
name|nullptr
decl_stmt|;
name|public
label|:
comment|/// Wrap a preinitialized SlotTracker.
name|ModuleSlotTracker
argument_list|(
name|SlotTracker
operator|&
name|Machine
argument_list|,
specifier|const
name|Module
operator|*
name|M
argument_list|,
specifier|const
name|Function
operator|*
name|F
operator|=
name|nullptr
argument_list|)
expr_stmt|;
comment|/// Construct a slot tracker from a module.
comment|///
comment|/// If \a M is \c nullptr, uses a null slot tracker.  Otherwise, initializes
comment|/// a slot tracker, and initializes all metadata slots.  \c
comment|/// ShouldInitializeAllMetadata defaults to true because this is expected to
comment|/// be shared between multiple callers, and otherwise MDNode references will
comment|/// not match up.
name|explicit
name|ModuleSlotTracker
parameter_list|(
specifier|const
name|Module
modifier|*
name|M
parameter_list|,
name|bool
name|ShouldInitializeAllMetadata
init|=
name|true
parameter_list|)
function_decl|;
comment|/// Destructor to clean up storage.
operator|~
name|ModuleSlotTracker
argument_list|()
expr_stmt|;
name|SlotTracker
operator|*
name|getMachine
argument_list|()
specifier|const
block|{
return|return
name|Machine
return|;
block|}
specifier|const
name|Module
operator|*
name|getModule
argument_list|()
specifier|const
block|{
return|return
name|M
return|;
block|}
specifier|const
name|Function
operator|*
name|getCurrentFunction
argument_list|()
specifier|const
block|{
return|return
name|F
return|;
block|}
comment|/// Incorporate the given function.
comment|///
comment|/// Purge the currently incorporated function and incorporate \c F.  If \c F
comment|/// is currently incorporated, this is a no-op.
name|void
name|incorporateFunction
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
comment|/// Return the slot number of the specified local value.
comment|///
comment|/// A function that defines this value should be incorporated prior to calling
comment|/// this method.
comment|/// Return -1 if the value is not in the function's SlotTracker.
name|int
name|getLocalSlot
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
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

end_unit

