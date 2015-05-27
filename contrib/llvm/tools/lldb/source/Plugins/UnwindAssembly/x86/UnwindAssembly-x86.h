begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UnwindAssembly-x86.h -------------------------------------*- C++ -*-===//
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
name|liblldb_UnwindAssembly_x86_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_UnwindAssembly_x86_h_
end_define

begin_include
include|#
directive|include
file|"llvm-c/Disassembler.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/UnwindAssembly.h"
end_include

begin_decl_stmt
name|class
name|UnwindAssembly_x86
range|:
name|public
name|lldb_private
operator|::
name|UnwindAssembly
block|{
name|public
operator|:
operator|~
name|UnwindAssembly_x86
argument_list|()
block|;
name|virtual
name|bool
name|GetNonCallSiteUnwindPlanFromAssembly
argument_list|(
name|lldb_private
operator|::
name|AddressRange
operator|&
name|func
argument_list|,
name|lldb_private
operator|::
name|Thread
operator|&
name|thread
argument_list|,
name|lldb_private
operator|::
name|UnwindPlan
operator|&
name|unwind_plan
argument_list|)
block|;
name|virtual
name|bool
name|AugmentUnwindPlanFromCallSite
argument_list|(
name|lldb_private
operator|::
name|AddressRange
operator|&
name|func
argument_list|,
name|lldb_private
operator|::
name|Thread
operator|&
name|thread
argument_list|,
name|lldb_private
operator|::
name|UnwindPlan
operator|&
name|unwind_plan
argument_list|)
block|;
name|virtual
name|bool
name|GetFastUnwindPlan
argument_list|(
name|lldb_private
operator|::
name|AddressRange
operator|&
name|func
argument_list|,
name|lldb_private
operator|::
name|Thread
operator|&
name|thread
argument_list|,
name|lldb_private
operator|::
name|UnwindPlan
operator|&
name|unwind_plan
argument_list|)
block|;
comment|// thread may be NULL in which case we only use the Target (e.g. if this is called pre-process-launch).
name|virtual
name|bool
name|FirstNonPrologueInsn
argument_list|(
name|lldb_private
operator|::
name|AddressRange
operator|&
name|func
argument_list|,
specifier|const
name|lldb_private
operator|::
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|lldb_private
operator|::
name|Address
operator|&
name|first_non_prologue_insn
argument_list|)
block|;
specifier|static
name|lldb_private
operator|::
name|UnwindAssembly
operator|*
name|CreateInstance
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetPluginDescriptionStatic
argument_list|()
block|;
name|virtual
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
block|;
name|virtual
name|uint32_t
name|GetPluginVersion
argument_list|()
block|;
name|private
operator|:
name|UnwindAssembly_x86
argument_list|(
argument|const lldb_private::ArchSpec&arch
argument_list|,
argument|int cpu
argument_list|)
block|;
name|int
name|m_cpu
block|;
name|lldb_private
operator|::
name|ArchSpec
name|m_arch
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_UnwindAssembly_x86_h_
end_comment

end_unit

