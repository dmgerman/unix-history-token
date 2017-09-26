begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_FuncUnwinders_h
end_ifndef

begin_define
define|#
directive|define
name|liblldb_FuncUnwinders_h
end_define

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"lldb/Core/AddressRange.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/AddressRange.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|UnwindTable
decl_stmt|;
name|class
name|FuncUnwinders
block|{
name|public
label|:
comment|// FuncUnwinders objects are used to track UnwindPlans for a function
comment|// (named or not - really just an address range)
comment|// We'll record four different UnwindPlans for each address range:
comment|//
comment|//   1. Unwinding from a call site (a valid exception throw location)
comment|//      This is often sourced from the eh_frame exception handling info
comment|//   2. Unwinding from a non-call site (any location in the function)
comment|//      This is often done by analyzing the function prologue assembly
comment|//      language instructions
comment|//   3. A fast unwind method for this function which only retrieves a
comment|//      limited set of registers necessary to walk the stack
comment|//   4. An architectural default unwind plan when none of the above are
comment|//      available for some reason.
comment|// Additionally, FuncUnwinds object can be asked where the prologue
comment|// instructions are finished for migrating breakpoints past the
comment|// stack frame setup instructions when we don't have line table information.
name|FuncUnwinders
argument_list|(
argument|lldb_private::UnwindTable&unwind_table
argument_list|,
argument|AddressRange range
argument_list|)
empty_stmt|;
operator|~
name|FuncUnwinders
argument_list|()
expr_stmt|;
comment|// current_offset is the byte offset into the function.
comment|// 0 means no instructions have executed yet.  -1 means the offset is unknown.
comment|// On architectures where the pc points to the next instruction that will
comment|// execute, this
comment|// offset value will have already been decremented by 1 to stay within the
comment|// bounds of the
comment|// correct function body.
name|lldb
operator|::
name|UnwindPlanSP
name|GetUnwindPlanAtCallSite
argument_list|(
argument|Target&target
argument_list|,
argument|int current_offset
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|GetUnwindPlanAtNonCallSite
argument_list|(
argument|Target&target
argument_list|,
argument|lldb_private::Thread&thread
argument_list|,
argument|int current_offset
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|GetUnwindPlanFastUnwind
argument_list|(
name|Target
operator|&
name|target
argument_list|,
name|lldb_private
operator|::
name|Thread
operator|&
name|thread
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|GetUnwindPlanArchitectureDefault
argument_list|(
name|lldb_private
operator|::
name|Thread
operator|&
name|thread
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|GetUnwindPlanArchitectureDefaultAtFunctionEntry
argument_list|(
name|lldb_private
operator|::
name|Thread
operator|&
name|thread
argument_list|)
expr_stmt|;
name|Address
modifier|&
name|GetFirstNonPrologueInsn
parameter_list|(
name|Target
modifier|&
name|target
parameter_list|)
function_decl|;
specifier|const
name|Address
operator|&
name|GetFunctionStartAddress
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|ContainsAddress
argument_list|(
specifier|const
name|Address
operator|&
name|addr
argument_list|)
decl|const
block|{
return|return
name|m_range
operator|.
name|ContainsFileAddress
argument_list|(
name|addr
argument_list|)
return|;
block|}
comment|// A function may have a Language Specific Data Area specified -- a block of
comment|// data in
comment|// the object file which is used in the processing of an exception throw /
comment|// catch.
comment|// If any of the UnwindPlans have the address of the LSDA region for this
comment|// function,
comment|// this will return it.
name|Address
name|GetLSDAAddress
parameter_list|(
name|Target
modifier|&
name|target
parameter_list|)
function_decl|;
comment|// A function may have a Personality Routine associated with it -- used in the
comment|// processing of throwing an exception.  If any of the UnwindPlans have the
comment|// address of the personality routine, this will return it.  Read the
comment|// target-pointer
comment|// at this address to get the personality function address.
name|Address
name|GetPersonalityRoutinePtrAddress
parameter_list|(
name|Target
modifier|&
name|target
parameter_list|)
function_decl|;
comment|// The following methods to retrieve specific unwind plans should rarely be
comment|// used.
comment|// Instead, clients should ask for the *behavior* they are looking for, using
comment|// one
comment|// of the above UnwindPlan retrieval methods.
name|lldb
operator|::
name|UnwindPlanSP
name|GetAssemblyUnwindPlan
argument_list|(
argument|Target&target
argument_list|,
argument|Thread&thread
argument_list|,
argument|int current_offset
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|GetEHFrameUnwindPlan
argument_list|(
argument|Target&target
argument_list|,
argument|int current_offset
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|GetEHFrameAugmentedUnwindPlan
argument_list|(
argument|Target&target
argument_list|,
argument|Thread&thread
argument_list|,
argument|int current_offset
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|GetDebugFrameUnwindPlan
argument_list|(
argument|Target&target
argument_list|,
argument|int current_offset
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|GetDebugFrameAugmentedUnwindPlan
argument_list|(
argument|Target&target
argument_list|,
argument|Thread&thread
argument_list|,
argument|int current_offset
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|GetCompactUnwindUnwindPlan
argument_list|(
argument|Target&target
argument_list|,
argument|int current_offset
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|GetArmUnwindUnwindPlan
argument_list|(
argument|Target&target
argument_list|,
argument|int current_offset
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|GetArchDefaultUnwindPlan
argument_list|(
name|Thread
operator|&
name|thread
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|GetArchDefaultAtFuncEntryUnwindPlan
argument_list|(
name|Thread
operator|&
name|thread
argument_list|)
expr_stmt|;
name|private
label|:
name|lldb
operator|::
name|UnwindAssemblySP
name|GetUnwindAssemblyProfiler
argument_list|(
name|Target
operator|&
name|target
argument_list|)
expr_stmt|;
comment|// Do a simplistic comparison for the register restore rule for getting
comment|// the caller's pc value on two UnwindPlans -- returns LazyBoolYes if
comment|// they have the same unwind rule for the pc, LazyBoolNo if they do not
comment|// have the same unwind rule for the pc, and LazyBoolCalculate if it was
comment|// unable to determine this for some reason.
name|lldb_private
operator|::
name|LazyBool
name|CompareUnwindPlansForIdenticalInitialPCLocation
argument_list|(
name|Thread
operator|&
name|thread
argument_list|,
specifier|const
name|lldb
operator|::
name|UnwindPlanSP
operator|&
name|a
argument_list|,
specifier|const
name|lldb
operator|::
name|UnwindPlanSP
operator|&
name|b
argument_list|)
expr_stmt|;
name|UnwindTable
modifier|&
name|m_unwind_table
decl_stmt|;
name|AddressRange
name|m_range
decl_stmt|;
name|std
operator|::
name|recursive_mutex
name|m_mutex
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|m_unwind_plan_assembly_sp
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|m_unwind_plan_eh_frame_sp
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|m_unwind_plan_debug_frame_sp
expr_stmt|;
comment|// augmented by assembly inspection so it's valid everywhere
name|lldb
operator|::
name|UnwindPlanSP
name|m_unwind_plan_eh_frame_augmented_sp
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|m_unwind_plan_debug_frame_augmented_sp
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|UnwindPlanSP
operator|>
name|m_unwind_plan_compact_unwind
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|m_unwind_plan_arm_unwind_sp
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|m_unwind_plan_fast_sp
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|m_unwind_plan_arch_default_sp
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|m_unwind_plan_arch_default_at_func_entry_sp
expr_stmt|;
comment|// Fetching the UnwindPlans can be expensive - if we've already attempted
comment|// to get one& failed, don't try again.
name|bool
name|m_tried_unwind_plan_assembly
range|:
literal|1
decl_stmt|,
name|m_tried_unwind_plan_eh_frame
range|:
literal|1
decl_stmt|,
name|m_tried_unwind_plan_debug_frame
range|:
literal|1
decl_stmt|,
name|m_tried_unwind_plan_eh_frame_augmented
range|:
literal|1
decl_stmt|,
name|m_tried_unwind_plan_debug_frame_augmented
range|:
literal|1
decl_stmt|,
name|m_tried_unwind_plan_compact_unwind
range|:
literal|1
decl_stmt|,
name|m_tried_unwind_plan_arm_unwind
range|:
literal|1
decl_stmt|,
name|m_tried_unwind_fast
range|:
literal|1
decl_stmt|,
name|m_tried_unwind_arch_default
range|:
literal|1
decl_stmt|,
name|m_tried_unwind_arch_default_at_func_entry
range|:
literal|1
decl_stmt|;
name|Address
name|m_first_non_prologue_insn
decl_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|FuncUnwinders
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|// class FuncUnwinders
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_FuncUnwinders_h
end_comment

end_unit

