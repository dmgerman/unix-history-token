begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SingleStepCheck.h ------------------------------------- -*- C++ -*-===//
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
name|liblldb_SingleStepCheck_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_SingleStepCheck_H_
end_define

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<sched.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_linux
block|{
comment|// arm64 linux had a bug which prevented single-stepping and watchpoints from
comment|// working on non-boot cpus, due to them being incorrectly initialized after
comment|// coming out of suspend.  This issue is particularly affecting android M, which
comment|// uses suspend ("doze mode") quite aggressively. This code detects that
comment|// situation and makes single-stepping work by doing all the step operations on
comment|// the boot cpu.
comment|//
comment|// The underlying issue has been fixed in android N and linux 4.4. This code can
comment|// be removed once these systems become obsolete.
if|#
directive|if
name|defined
argument_list|(
name|__arm64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__aarch64__
argument_list|)
name|class
name|SingleStepWorkaround
block|{
operator|::
name|pid_t
name|m_tid
expr_stmt|;
name|cpu_set_t
name|m_original_set
decl_stmt|;
name|SingleStepWorkaround
argument_list|(
specifier|const
name|SingleStepWorkaround
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|SingleStepWorkaround
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|public
label|:
name|SingleStepWorkaround
argument_list|(
argument|::pid_t tid
argument_list|,
argument|cpu_set_t original_set
argument_list|)
block|:
name|m_tid
argument_list|(
name|tid
argument_list|)
operator|,
name|m_original_set
argument_list|(
argument|original_set
argument_list|)
block|{}
operator|~
name|SingleStepWorkaround
argument_list|()
expr_stmt|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|SingleStepWorkaround
operator|>
name|Get
argument_list|(
argument|::pid_t tid
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
else|#
directive|else
name|class
name|SingleStepWorkaround
block|{
name|public
label|:
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|SingleStepWorkaround
operator|>
name|Get
argument_list|(
argument|::pid_t tid
argument_list|)
block|{
return|return
name|nullptr
return|;
block|}
block|}
empty_stmt|;
endif|#
directive|endif
block|}
comment|// end namespace process_linux
block|}
end_decl_stmt

begin_comment
comment|// end namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_SingleStepCheck_H_
end_comment

end_unit

