begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CrashReason.h -------------------------------------------*- C++ -*-===//
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
name|liblldb_CrashReason_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CrashReason_H_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|enum
name|class
name|CrashReason
block|{
name|eInvalidCrashReason
operator|,
comment|// SIGSEGV crash reasons.
name|eInvalidAddress
operator|,
name|ePrivilegedAddress
operator|,
comment|// SIGILL crash reasons.
name|eIllegalOpcode
operator|,
name|eIllegalOperand
operator|,
name|eIllegalAddressingMode
operator|,
name|eIllegalTrap
operator|,
name|ePrivilegedOpcode
operator|,
name|ePrivilegedRegister
operator|,
name|eCoprocessorError
operator|,
name|eInternalStackError
operator|,
comment|// SIGBUS crash reasons,
name|eIllegalAlignment
operator|,
name|eIllegalAddress
operator|,
name|eHardwareError
operator|,
comment|// SIGFPE crash reasons,
name|eIntegerDivideByZero
operator|,
name|eIntegerOverflow
operator|,
name|eFloatDivideByZero
operator|,
name|eFloatOverflow
operator|,
name|eFloatUnderflow
operator|,
name|eFloatInexactResult
operator|,
name|eFloatInvalidOperation
operator|,
name|eFloatSubscriptRange
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|GetCrashReasonString
argument_list|(
argument|CrashReason reason
argument_list|,
argument|lldb::addr_t fault_addr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|const
name|char
modifier|*
name|CrashReasonAsString
parameter_list|(
name|CrashReason
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CrashReason
name|GetCrashReason
parameter_list|(
specifier|const
name|siginfo_t
modifier|&
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_CrashReason_H_
end_comment

end_unit

