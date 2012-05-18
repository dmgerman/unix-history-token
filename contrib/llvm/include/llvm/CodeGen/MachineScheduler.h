begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- MachineScheduler.h - MachineInstr Scheduling Pass ----------*- C++ -*-==//
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
comment|// This file provides a MachineSchedRegistry for registering alternative machine
end_comment

begin_comment
comment|// schedulers. A Target may provide an alternative scheduler implementation by
end_comment

begin_comment
comment|// implementing the following boilerplate:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// static ScheduleDAGInstrs *createCustomMachineSched(MachineSchedContext *C) {
end_comment

begin_comment
comment|//  return new CustomMachineScheduler(C);
end_comment

begin_comment
comment|// }
end_comment

begin_comment
comment|// static MachineSchedRegistry
end_comment

begin_comment
comment|// SchedCustomRegistry("custom", "Run my target's custom scheduler",
end_comment

begin_comment
comment|//                     createCustomMachineSched);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Inside<Target>PassConfig:
end_comment

begin_comment
comment|//   enablePass(MachineSchedulerID);
end_comment

begin_comment
comment|//   MachineSchedRegistry::setDefault(createCustomMachineSched);
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
name|MACHINESCHEDULER_H
end_ifndef

begin_define
define|#
directive|define
name|MACHINESCHEDULER_H
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
name|AliasAnalysis
decl_stmt|;
name|class
name|LiveIntervals
decl_stmt|;
name|class
name|MachineDominatorTree
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|ScheduleDAGInstrs
decl_stmt|;
comment|/// MachineSchedContext provides enough context from the MachineScheduler pass
comment|/// for the target to instantiate a scheduler.
struct|struct
name|MachineSchedContext
block|{
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
specifier|const
name|MachineLoopInfo
modifier|*
name|MLI
decl_stmt|;
specifier|const
name|MachineDominatorTree
modifier|*
name|MDT
decl_stmt|;
specifier|const
name|TargetPassConfig
modifier|*
name|PassConfig
decl_stmt|;
name|AliasAnalysis
modifier|*
name|AA
decl_stmt|;
name|LiveIntervals
modifier|*
name|LIS
decl_stmt|;
name|MachineSchedContext
argument_list|()
operator|:
name|MF
argument_list|(
literal|0
argument_list|)
operator|,
name|MLI
argument_list|(
literal|0
argument_list|)
operator|,
name|MDT
argument_list|(
literal|0
argument_list|)
operator|,
name|PassConfig
argument_list|(
literal|0
argument_list|)
operator|,
name|AA
argument_list|(
literal|0
argument_list|)
operator|,
name|LIS
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
comment|/// MachineSchedRegistry provides a selection of available machine instruction
comment|/// schedulers.
name|class
name|MachineSchedRegistry
range|:
name|public
name|MachinePassRegistryNode
block|{
name|public
operator|:
typedef|typedef
name|ScheduleDAGInstrs
modifier|*
function_decl|(
modifier|*
name|ScheduleDAGCtor
function_decl|)
parameter_list|(
name|MachineSchedContext
modifier|*
parameter_list|)
function_decl|;
comment|// RegisterPassParser requires a (misnamed) FunctionPassCtor type.
typedef|typedef
name|ScheduleDAGCtor
name|FunctionPassCtor
typedef|;
specifier|static
name|MachinePassRegistry
name|Registry
decl_stmt|;
name|MachineSchedRegistry
argument_list|(
argument|const char *N
argument_list|,
argument|const char *D
argument_list|,
argument|ScheduleDAGCtor C
argument_list|)
block|:
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
expr_stmt|;
block|}
operator|~
name|MachineSchedRegistry
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
comment|//
name|MachineSchedRegistry
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
operator|(
name|MachineSchedRegistry
operator|*
operator|)
name|MachinePassRegistryNode
operator|::
name|getNext
argument_list|()
return|;
block|}
specifier|static
name|MachineSchedRegistry
modifier|*
name|getList
parameter_list|()
block|{
return|return
operator|(
name|MachineSchedRegistry
operator|*
operator|)
name|Registry
operator|.
name|getList
argument_list|()
return|;
block|}
specifier|static
name|ScheduleDAGCtor
name|getDefault
parameter_list|()
block|{
return|return
operator|(
name|ScheduleDAGCtor
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
parameter_list|(
name|ScheduleDAGCtor
name|C
parameter_list|)
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
expr_stmt|;
block|}
specifier|static
name|void
name|setListener
parameter_list|(
name|MachinePassRegistryListener
modifier|*
name|L
parameter_list|)
block|{
name|Registry
operator|.
name|setListener
argument_list|(
name|L
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

