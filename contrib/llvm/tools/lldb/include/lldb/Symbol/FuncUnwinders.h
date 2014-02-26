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
file|"lldb/Core/AddressRange.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/AddressRange.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
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
comment|// We'll record three different UnwindPlans for each address range:
comment|//   1. Unwinding from a call site (a valid exception throw location)
comment|//      This is often sourced from the eh_frame exception handling info
comment|//   2. Unwinding from a non-call site (any location in the function)
comment|//      This is often done by analyzing the function prologue assembly
comment|//      langauge instructions
comment|//   3. A fast unwind method for this function which only retrieves a
comment|//      limited set of registers necessary to walk the stack
comment|//   4. An architectural default unwind plan when none of the above are
comment|//      available for some reason.
comment|// Additionally, FuncUnwinds object can be asked where the prologue
comment|// instructions are finished for migrating breakpoints past the
comment|// stack frame setup instructions when we don't have line table information.
name|FuncUnwinders
argument_list|(
argument|lldb_private::UnwindTable& unwind_table
argument_list|,
argument|const lldb::UnwindAssemblySP& assembly_profiler
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
comment|// On architectures where the pc points to the next instruction that will execute, this
comment|// offset value will have already been decremented by 1 to stay within the bounds of the
comment|// correct function body.
name|lldb
operator|::
name|UnwindPlanSP
name|GetUnwindPlanAtCallSite
argument_list|(
argument|int current_offset
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|GetUnwindPlanAtNonCallSite
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
name|GetUnwindPlanFastUnwind
argument_list|(
name|lldb_private
operator|::
name|Thread
operator|&
name|Thread
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
comment|// When we're doing an unwind using the UnwindPlanAtNonCallSite and we find an
comment|// impossible unwind condition, we know that the UnwindPlan is invalid.  Calling
comment|// this method on the FuncUnwinder will tell it to replace that UnwindPlan with
comment|// the architectural default UnwindPlan so hopefully our stack walk will get past
comment|// this frame.
name|void
name|InvalidateNonCallSiteUnwindPlan
argument_list|(
name|lldb_private
operator|::
name|Thread
operator|&
name|Thread
argument_list|)
decl_stmt|;
name|private
label|:
name|UnwindTable
modifier|&
name|m_unwind_table
decl_stmt|;
name|lldb
operator|::
name|UnwindAssemblySP
name|m_assembly_profiler
expr_stmt|;
name|AddressRange
name|m_range
decl_stmt|;
name|Mutex
name|m_mutex
decl_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|m_unwind_plan_call_site_sp
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|m_unwind_plan_non_call_site_sp
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
name|bool
name|m_tried_unwind_at_call_site
range|:
literal|1
decl_stmt|,
name|m_tried_unwind_at_non_call_site
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
comment|//liblldb_FuncUnwinders_h
end_comment

end_unit

