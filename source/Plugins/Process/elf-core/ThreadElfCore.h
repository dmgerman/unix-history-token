begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadElfCore.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_ThreadElfCore_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadElfCore_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/DataExtractor.h"
end_include

begin_struct
struct|struct
name|compat_timeval
block|{
name|alignas
argument_list|(
literal|8
argument_list|)
name|uint64_t
name|tv_sec
decl_stmt|;
name|alignas
argument_list|(
literal|8
argument_list|)
name|uint64_t
name|tv_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// PRSTATUS structure's size differs based on architecture.
end_comment

begin_comment
comment|// This is the layout in the x86-64 arch.
end_comment

begin_comment
comment|// In the i386 case we parse it manually and fill it again
end_comment

begin_comment
comment|// in the same structure
end_comment

begin_comment
comment|// The gp registers are also a part of this struct, but they are handled
end_comment

begin_comment
comment|// separately
end_comment

begin_undef
undef|#
directive|undef
name|si_signo
end_undef

begin_undef
undef|#
directive|undef
name|si_code
end_undef

begin_undef
undef|#
directive|undef
name|si_errno
end_undef

begin_struct
struct|struct
name|ELFLinuxPrStatus
block|{
name|int32_t
name|si_signo
decl_stmt|;
name|int32_t
name|si_code
decl_stmt|;
name|int32_t
name|si_errno
decl_stmt|;
name|int16_t
name|pr_cursig
decl_stmt|;
name|alignas
argument_list|(
literal|8
argument_list|)
name|uint64_t
name|pr_sigpend
decl_stmt|;
name|alignas
argument_list|(
literal|8
argument_list|)
name|uint64_t
name|pr_sighold
decl_stmt|;
name|uint32_t
name|pr_pid
decl_stmt|;
name|uint32_t
name|pr_ppid
decl_stmt|;
name|uint32_t
name|pr_pgrp
decl_stmt|;
name|uint32_t
name|pr_sid
decl_stmt|;
name|compat_timeval
name|pr_utime
decl_stmt|;
name|compat_timeval
name|pr_stime
decl_stmt|;
name|compat_timeval
name|pr_cutime
decl_stmt|;
name|compat_timeval
name|pr_cstime
decl_stmt|;
name|ELFLinuxPrStatus
argument_list|()
expr_stmt|;
name|lldb_private
operator|::
name|Error
name|Parse
argument_list|(
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
expr_stmt|;
comment|// Return the bytesize of the structure
comment|// 64 bit - just sizeof
comment|// 32 bit - hardcoded because we are reusing the struct, but some of the
comment|// members are smaller -
comment|// so the layout is not the same
specifier|static
name|size_t
name|GetSize
argument_list|(
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|ELFLinuxPrStatus
argument_list|)
operator|==
literal|112
argument_list|,
literal|"sizeof ELFLinuxPrStatus is not correct!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|ELFLinuxSigInfo
block|{
name|int32_t
name|si_signo
decl_stmt|;
name|int32_t
name|si_code
decl_stmt|;
name|int32_t
name|si_errno
decl_stmt|;
name|ELFLinuxSigInfo
argument_list|()
expr_stmt|;
name|lldb_private
operator|::
name|Error
name|Parse
argument_list|(
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
expr_stmt|;
comment|// Return the bytesize of the structure
comment|// 64 bit - just sizeof
comment|// 32 bit - hardcoded because we are reusing the struct, but some of the
comment|// members are smaller -
comment|// so the layout is not the same
specifier|static
name|size_t
name|GetSize
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|ELFLinuxSigInfo
argument_list|)
operator|==
literal|12
argument_list|,
literal|"sizeof ELFLinuxSigInfo is not correct!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// PRPSINFO structure's size differs based on architecture.
end_comment

begin_comment
comment|// This is the layout in the x86-64 arch case.
end_comment

begin_comment
comment|// In the i386 case we parse it manually and fill it again
end_comment

begin_comment
comment|// in the same structure
end_comment

begin_struct
struct|struct
name|ELFLinuxPrPsInfo
block|{
name|char
name|pr_state
decl_stmt|;
name|char
name|pr_sname
decl_stmt|;
name|char
name|pr_zomb
decl_stmt|;
name|char
name|pr_nice
decl_stmt|;
name|alignas
argument_list|(
literal|8
argument_list|)
name|uint64_t
name|pr_flag
decl_stmt|;
name|uint32_t
name|pr_uid
decl_stmt|;
name|uint32_t
name|pr_gid
decl_stmt|;
name|int32_t
name|pr_pid
decl_stmt|;
name|int32_t
name|pr_ppid
decl_stmt|;
name|int32_t
name|pr_pgrp
decl_stmt|;
name|int32_t
name|pr_sid
decl_stmt|;
name|char
name|pr_fname
index|[
literal|16
index|]
decl_stmt|;
name|char
name|pr_psargs
index|[
literal|80
index|]
decl_stmt|;
name|ELFLinuxPrPsInfo
argument_list|()
expr_stmt|;
name|lldb_private
operator|::
name|Error
name|Parse
argument_list|(
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
expr_stmt|;
comment|// Return the bytesize of the structure
comment|// 64 bit - just sizeof
comment|// 32 bit - hardcoded because we are reusing the struct, but some of the
comment|// members are smaller -
comment|// so the layout is not the same
specifier|static
name|size_t
name|GetSize
argument_list|(
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|ELFLinuxPrPsInfo
argument_list|)
operator|==
literal|136
argument_list|,
literal|"sizeof ELFLinuxPrPsInfo is not correct!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|ThreadData
block|{
name|lldb_private
operator|::
name|DataExtractor
name|gpregset
expr_stmt|;
name|lldb_private
operator|::
name|DataExtractor
name|fpregset
expr_stmt|;
name|lldb_private
operator|::
name|DataExtractor
name|vregset
expr_stmt|;
name|lldb
operator|::
name|tid_t
name|tid
expr_stmt|;
name|int
name|signo
init|=
literal|0
decl_stmt|;
name|int
name|prstatus_sig
init|=
literal|0
decl_stmt|;
name|std
operator|::
name|string
name|name
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|class
name|ThreadElfCore
range|:
name|public
name|lldb_private
operator|::
name|Thread
block|{
name|public
operator|:
name|ThreadElfCore
argument_list|(
name|lldb_private
operator|::
name|Process
operator|&
name|process
argument_list|,
specifier|const
name|ThreadData
operator|&
name|td
argument_list|)
block|;
operator|~
name|ThreadElfCore
argument_list|()
name|override
block|;
name|void
name|RefreshStateAfterStop
argument_list|()
name|override
block|;
name|lldb
operator|::
name|RegisterContextSP
name|GetRegisterContext
argument_list|()
name|override
block|;
name|lldb
operator|::
name|RegisterContextSP
name|CreateRegisterContextForFrame
argument_list|(
argument|lldb_private::StackFrame *frame
argument_list|)
name|override
block|;
name|void
name|ClearStackFrames
argument_list|()
name|override
block|;
specifier|static
name|bool
name|ThreadIDIsValid
argument_list|(
argument|lldb::tid_t thread
argument_list|)
block|{
return|return
name|thread
operator|!=
literal|0
return|;
block|}
specifier|const
name|char
operator|*
name|GetName
argument_list|()
name|override
block|{
if|if
condition|(
name|m_thread_name
operator|.
name|empty
argument_list|()
condition|)
return|return
name|NULL
return|;
return|return
name|m_thread_name
operator|.
name|c_str
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|void
name|SetName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function|override
block|{
if|if
condition|(
name|name
operator|&&
name|name
index|[
literal|0
index|]
condition|)
name|m_thread_name
operator|.
name|assign
argument_list|(
name|name
argument_list|)
expr_stmt|;
else|else
name|m_thread_name
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_label
name|protected
label|:
end_label

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Member variables.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|m_thread_name
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|RegisterContextSP
name|m_thread_reg_ctx_sp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|m_signo
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|DataExtractor
name|m_gpregset_data
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|DataExtractor
name|m_fpregset_data
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|DataExtractor
name|m_vregset_data
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|CalculateStopInfo
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ThreadElfCore_h_
end_comment

end_unit

