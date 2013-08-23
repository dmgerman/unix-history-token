begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UnwindAssembly.h --------------------------------*- C++ -*-===//
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
name|utility_UnwindAssembly_h_
end_ifndef

begin_define
define|#
directive|define
name|utility_UnwindAssembly_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|UnwindAssembly
range|:
name|public
name|PluginInterface
block|{
name|public
operator|:
specifier|static
name|UnwindAssembly
operator|*
name|FindPlugin
argument_list|(
specifier|const
name|ArchSpec
operator|&
name|arch
argument_list|)
block|;
name|virtual
operator|~
name|UnwindAssembly
argument_list|()
block|;
name|virtual
name|bool
name|GetNonCallSiteUnwindPlanFromAssembly
argument_list|(
name|AddressRange
operator|&
name|func
argument_list|,
name|Thread
operator|&
name|thread
argument_list|,
name|UnwindPlan
operator|&
name|unwind_plan
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|GetFastUnwindPlan
argument_list|(
name|AddressRange
operator|&
name|func
argument_list|,
name|Thread
operator|&
name|thread
argument_list|,
name|UnwindPlan
operator|&
name|unwind_plan
argument_list|)
operator|=
literal|0
block|;
comment|// thread may be NULL in which case we only use the Target (e.g. if this is called pre-process-launch).
name|virtual
name|bool
name|FirstNonPrologueInsn
argument_list|(
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
name|Address
operator|&
name|first_non_prologue_insn
argument_list|)
operator|=
literal|0
block|;
name|protected
operator|:
name|UnwindAssembly
argument_list|(
specifier|const
name|ArchSpec
operator|&
name|arch
argument_list|)
block|;
name|ArchSpec
name|m_arch
block|;
name|private
operator|:
name|UnwindAssembly
argument_list|()
block|;
comment|// Outlaw default constructor
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|UnwindAssembly
argument_list|)
block|; }
decl_stmt|;
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
comment|//utility_UnwindAssembly_h_
end_comment

end_unit

