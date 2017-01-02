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

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_linux
block|{
name|namespace
name|impl
block|{
specifier|extern
name|bool
name|SingleStepWorkaroundNeeded
parameter_list|()
function_decl|;
block|}
comment|// arm64 linux had a bug which prevented single-stepping and watchpoints from
comment|// working on non-boot
comment|// cpus, due to them being incorrectly initialized after coming out of suspend.
comment|// This issue is
comment|// particularly affecting android M, which uses suspend ("doze mode") quite
comment|// aggressively. This
comment|// code detects that situation and makes single-stepping work by doing all the
comment|// step operations on
comment|// the boot cpu.
comment|//
comment|// The underlying issue has been fixed in android N and linux 4.4. This code can
comment|// be removed once
comment|// these systems become obsolete.
specifier|inline
name|bool
name|SingleStepWorkaroundNeeded
parameter_list|()
block|{
specifier|static
name|bool
name|value
init|=
name|impl
operator|::
name|SingleStepWorkaroundNeeded
argument_list|()
decl_stmt|;
return|return
name|value
return|;
block|}
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

