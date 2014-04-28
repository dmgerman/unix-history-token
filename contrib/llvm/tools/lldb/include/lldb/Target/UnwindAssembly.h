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
name|std
operator|::
name|enable_shared_from_this
operator|<
name|UnwindAssembly
operator|>
decl_stmt|,
name|public
name|PluginInterface
block|{
name|public
label|:
specifier|static
name|lldb
operator|::
name|UnwindAssemblySP
name|FindPlugin
argument_list|(
specifier|const
name|ArchSpec
operator|&
name|arch
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|UnwindAssembly
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|GetNonCallSiteUnwindPlanFromAssembly
parameter_list|(
name|AddressRange
modifier|&
name|func
parameter_list|,
name|Thread
modifier|&
name|thread
parameter_list|,
name|UnwindPlan
modifier|&
name|unwind_plan
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|GetFastUnwindPlan
parameter_list|(
name|AddressRange
modifier|&
name|func
parameter_list|,
name|Thread
modifier|&
name|thread
parameter_list|,
name|UnwindPlan
modifier|&
name|unwind_plan
parameter_list|)
init|=
literal|0
function_decl|;
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
init|=
literal|0
decl_stmt|;
name|protected
label|:
name|UnwindAssembly
argument_list|(
specifier|const
name|ArchSpec
operator|&
name|arch
argument_list|)
expr_stmt|;
name|ArchSpec
name|m_arch
decl_stmt|;
name|private
label|:
name|UnwindAssembly
argument_list|()
expr_stmt|;
comment|// Outlaw default constructor
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|UnwindAssembly
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
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

