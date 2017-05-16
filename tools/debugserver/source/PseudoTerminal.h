begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PseudoTerminal.h ----------------------------------------*- C++ -*-===//
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
comment|//  Created by Greg Clayton on 1/8/08.
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
name|__PseudoTerminal_h__
end_ifndef

begin_define
define|#
directive|define
name|__PseudoTerminal_h__
end_define

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_decl_stmt
name|class
name|PseudoTerminal
block|{
name|public
label|:
enum|enum
block|{
name|invalid_fd
init|=
operator|-
literal|1
block|,
name|invalid_pid
init|=
operator|-
literal|1
block|}
enum|;
enum|enum
name|Status
block|{
name|success
init|=
literal|0
block|,
name|err_posix_openpt_failed
init|=
operator|-
literal|2
block|,
name|err_grantpt_failed
init|=
operator|-
literal|3
block|,
name|err_unlockpt_failed
init|=
operator|-
literal|4
block|,
name|err_ptsname_failed
init|=
operator|-
literal|5
block|,
name|err_open_slave_failed
init|=
operator|-
literal|6
block|,
name|err_fork_failed
init|=
operator|-
literal|7
block|,
name|err_setsid_failed
init|=
operator|-
literal|8
block|,
name|err_failed_to_acquire_controlling_terminal
init|=
operator|-
literal|9
block|,
name|err_dup2_failed_on_stdin
init|=
operator|-
literal|10
block|,
name|err_dup2_failed_on_stdout
init|=
operator|-
literal|11
block|,
name|err_dup2_failed_on_stderr
init|=
operator|-
literal|12
block|}
enum|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|PseudoTerminal
argument_list|()
expr_stmt|;
operator|~
name|PseudoTerminal
argument_list|()
expr_stmt|;
name|void
name|CloseMaster
parameter_list|()
function_decl|;
name|void
name|CloseSlave
parameter_list|()
function_decl|;
name|Status
name|OpenFirstAvailableMaster
parameter_list|(
name|int
name|oflag
parameter_list|)
function_decl|;
name|Status
name|OpenSlave
parameter_list|(
name|int
name|oflag
parameter_list|)
function_decl|;
name|int
name|MasterFD
argument_list|()
specifier|const
block|{
return|return
name|m_master_fd
return|;
block|}
name|int
name|SlaveFD
argument_list|()
specifier|const
block|{
return|return
name|m_slave_fd
return|;
block|}
name|int
name|ReleaseMasterFD
parameter_list|()
block|{
comment|// Release ownership of the master pseudo terminal file
comment|// descriptor without closing it. (the destructor for this
comment|// class will close it otherwise!)
name|int
name|fd
init|=
name|m_master_fd
decl_stmt|;
name|m_master_fd
operator|=
name|invalid_fd
expr_stmt|;
return|return
name|fd
return|;
block|}
name|int
name|ReleaseSlaveFD
parameter_list|()
block|{
comment|// Release ownership of the slave pseudo terminal file
comment|// descriptor without closing it (the destructor for this
comment|// class will close it otherwise!)
name|int
name|fd
init|=
name|m_slave_fd
decl_stmt|;
name|m_slave_fd
operator|=
name|invalid_fd
expr_stmt|;
return|return
name|fd
return|;
block|}
specifier|const
name|char
operator|*
name|SlaveName
argument_list|()
specifier|const
expr_stmt|;
name|pid_t
name|Fork
parameter_list|(
name|Status
modifier|&
name|error
parameter_list|)
function_decl|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from PseudoTerminal can see and modify these
comment|//------------------------------------------------------------------
name|int
name|m_master_fd
decl_stmt|;
name|int
name|m_slave_fd
decl_stmt|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|// Outlaw copy and assignment constructors
comment|//------------------------------------------------------------------
name|PseudoTerminal
argument_list|(
specifier|const
name|PseudoTerminal
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|PseudoTerminal
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PseudoTerminal
operator|&
name|rhs
operator|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef __PseudoTerminal_h__
end_comment

end_unit

