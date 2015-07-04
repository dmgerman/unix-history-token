begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemInitializer.h -------------------------------------*- C++ -*-===//
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
name|LLDB_INITIALIZATION_SYSTEM_INITIALIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_INITIALIZATION_SYSTEM_INITIALIZER_H
end_define

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SystemInitializer
block|{
name|public
label|:
name|SystemInitializer
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|SystemInitializer
argument_list|()
expr_stmt|;
name|virtual
name|void
name|Initialize
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|Terminate
parameter_list|()
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

