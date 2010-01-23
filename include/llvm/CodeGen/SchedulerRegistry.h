begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/SchedulerRegistry.h ------------------------*- C++ -*-===//
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
name|LLVM_CODEGENSCHEDULERREGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGENSCHEDULERREGISTRY_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachinePassRegistry.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
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
name|SelectionDAGISel
decl_stmt|;
name|class
name|ScheduleDAGSDNodes
decl_stmt|;
name|class
name|SelectionDAG
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|RegisterScheduler
range|:
name|public
name|MachinePassRegistryNode
block|{
name|public
operator|:
typedef|typedef
name|ScheduleDAGSDNodes
modifier|*
typedef|(
modifier|*
name|FunctionPassCtor
typedef|)
parameter_list|(
name|SelectionDAGISel
modifier|*
parameter_list|,
typedef|CodeGenOpt::
name|Level
typedef|);
specifier|static
name|MachinePassRegistry
name|Registry
decl_stmt|;
name|RegisterScheduler
argument_list|(
argument|const char *N
argument_list|,
argument|const char *D
argument_list|,
argument|FunctionPassCtor C
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
comment|//
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
modifier|*
name|getList
parameter_list|()
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
name|FunctionPassCtor
name|getDefault
parameter_list|()
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
parameter_list|(
name|FunctionPassCtor
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
comment|/// createBURRListDAGScheduler - This creates a bottom up register usage
end_comment

begin_comment
comment|/// reduction list scheduler.
end_comment

begin_decl_stmt
name|ScheduleDAGSDNodes
modifier|*
name|createBURRListDAGScheduler
argument_list|(
name|SelectionDAGISel
operator|*
name|IS
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// createTDRRListDAGScheduler - This creates a top down register usage
end_comment

begin_comment
comment|/// reduction list scheduler.
end_comment

begin_decl_stmt
name|ScheduleDAGSDNodes
modifier|*
name|createTDRRListDAGScheduler
argument_list|(
name|SelectionDAGISel
operator|*
name|IS
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// createBURRListDAGScheduler - This creates a bottom up register usage
end_comment

begin_comment
comment|/// reduction list scheduler that schedules in source code order when possible.
end_comment

begin_decl_stmt
name|ScheduleDAGSDNodes
modifier|*
name|createSourceListDAGScheduler
argument_list|(
name|SelectionDAGISel
operator|*
name|IS
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// createTDListDAGScheduler - This creates a top-down list scheduler with
end_comment

begin_comment
comment|/// a hazard recognizer.
end_comment

begin_decl_stmt
name|ScheduleDAGSDNodes
modifier|*
name|createTDListDAGScheduler
argument_list|(
name|SelectionDAGISel
operator|*
name|IS
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// createFastDAGScheduler - This creates a "fast" scheduler.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|ScheduleDAGSDNodes
modifier|*
name|createFastDAGScheduler
argument_list|(
name|SelectionDAGISel
operator|*
name|IS
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// createDefaultScheduler - This creates an instruction scheduler appropriate
end_comment

begin_comment
comment|/// for the target.
end_comment

begin_decl_stmt
name|ScheduleDAGSDNodes
modifier|*
name|createDefaultScheduler
argument_list|(
name|SelectionDAGISel
operator|*
name|IS
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

