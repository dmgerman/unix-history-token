begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/CodeGen/SchedulerRegistry.h -------------------------*- C++ -*-===//
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
comment|// This file contains the implementation for instruction scheduler function
end_comment

begin_comment
comment|// pass registry (RegisterScheduler).
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
name|LLVM_CODEGEN_SCHEDULERREGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SCHEDULERREGISTRY_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachinePassRegistry.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//===----------------------------------------------------------------------===//
comment|///
comment|/// RegisterScheduler class - Track the registration of instruction schedulers.
comment|///
comment|//===----------------------------------------------------------------------===//
name|class
name|ScheduleDAGSDNodes
decl_stmt|;
name|class
name|SelectionDAGISel
decl_stmt|;
name|class
name|RegisterScheduler
range|:
name|public
name|MachinePassRegistryNode
block|{
name|public
operator|:
name|using
name|FunctionPassCtor
operator|=
name|ScheduleDAGSDNodes
operator|*
call|(
modifier|*
call|)
argument_list|(
name|SelectionDAGISel
operator|*
argument_list|,
name|CodeGenOpt
operator|::
name|Level
argument_list|)
block|;
specifier|static
name|MachinePassRegistry
name|Registry
block|;
name|RegisterScheduler
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
block|; }
operator|~
name|RegisterScheduler
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
name|RegisterScheduler
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
operator|(
name|RegisterScheduler
operator|*
operator|)
name|MachinePassRegistryNode
operator|::
name|getNext
argument_list|()
return|;
block|}
specifier|static
name|RegisterScheduler
operator|*
name|getList
argument_list|()
block|{
return|return
operator|(
name|RegisterScheduler
operator|*
operator|)
name|Registry
operator|.
name|getList
argument_list|()
return|;
block|}
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
block|;
comment|/// createBURRListDAGScheduler - This creates a bottom up register usage
comment|/// reduction list scheduler.
name|ScheduleDAGSDNodes
operator|*
name|createBURRListDAGScheduler
argument_list|(
argument|SelectionDAGISel *IS
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|)
block|;
comment|/// createBURRListDAGScheduler - This creates a bottom up list scheduler that
comment|/// schedules nodes in source code order when possible.
name|ScheduleDAGSDNodes
operator|*
name|createSourceListDAGScheduler
argument_list|(
argument|SelectionDAGISel *IS
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|)
block|;
comment|/// createHybridListDAGScheduler - This creates a bottom up register pressure
comment|/// aware list scheduler that make use of latency information to avoid stalls
comment|/// for long latency instructions in low register pressure mode. In high
comment|/// register pressure mode it schedules to reduce register pressure.
name|ScheduleDAGSDNodes
operator|*
name|createHybridListDAGScheduler
argument_list|(
name|SelectionDAGISel
operator|*
name|IS
argument_list|,
name|CodeGenOpt
operator|::
name|Level
argument_list|)
block|;
comment|/// createILPListDAGScheduler - This creates a bottom up register pressure
comment|/// aware list scheduler that tries to increase instruction level parallelism
comment|/// in low register pressure mode. In high register pressure mode it schedules
comment|/// to reduce register pressure.
name|ScheduleDAGSDNodes
operator|*
name|createILPListDAGScheduler
argument_list|(
name|SelectionDAGISel
operator|*
name|IS
argument_list|,
name|CodeGenOpt
operator|::
name|Level
argument_list|)
block|;
comment|/// createFastDAGScheduler - This creates a "fast" scheduler.
comment|///
name|ScheduleDAGSDNodes
operator|*
name|createFastDAGScheduler
argument_list|(
argument|SelectionDAGISel *IS
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|)
block|;
comment|/// createVLIWDAGScheduler - Scheduler for VLIW targets. This creates top down
comment|/// DFA driven list scheduler with clustering heuristic to control
comment|/// register pressure.
name|ScheduleDAGSDNodes
operator|*
name|createVLIWDAGScheduler
argument_list|(
argument|SelectionDAGISel *IS
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|)
block|;
comment|/// createDefaultScheduler - This creates an instruction scheduler appropriate
comment|/// for the target.
name|ScheduleDAGSDNodes
operator|*
name|createDefaultScheduler
argument_list|(
argument|SelectionDAGISel *IS
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|)
block|;
comment|/// createDAGLinearizer - This creates a "no-scheduling" scheduler which
comment|/// linearize the DAG using topological order.
name|ScheduleDAGSDNodes
operator|*
name|createDAGLinearizer
argument_list|(
argument|SelectionDAGISel *IS
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|)
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
comment|// LLVM_CODEGEN_SCHEDULERREGISTRY_H
end_comment

end_unit

