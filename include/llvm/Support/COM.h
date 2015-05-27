begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/COM.h ---------------------------------------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides a library for accessing COM functionality of the Host OS.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_COM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_COM_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
name|enum
name|class
name|COMThreadingMode
block|{
name|SingleThreaded
operator|,
name|MultiThreaded
block|}
empty_stmt|;
name|class
name|InitializeCOMRAII
block|{
name|public
label|:
name|explicit
name|InitializeCOMRAII
parameter_list|(
name|COMThreadingMode
name|Threading
parameter_list|,
name|bool
name|SpeedOverMemory
init|=
name|false
parameter_list|)
function_decl|;
operator|~
name|InitializeCOMRAII
argument_list|()
expr_stmt|;
name|private
label|:
name|InitializeCOMRAII
argument_list|(
specifier|const
name|InitializeCOMRAII
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
name|InitializeCOMRAII
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

