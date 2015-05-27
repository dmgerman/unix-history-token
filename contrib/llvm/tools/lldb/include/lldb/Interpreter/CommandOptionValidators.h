begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CommandOptionValidators.h -------------------------------*- C++ -*-===//
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
name|liblldb_CommandOptionValidators_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CommandOptionValidators_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-private-types.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Platform
decl_stmt|;
name|class
name|ExecutionContext
decl_stmt|;
name|class
name|PosixPlatformCommandOptionValidator
range|:
name|public
name|OptionValidator
block|{
name|virtual
name|bool
name|IsValid
argument_list|(
argument|Platform&platform
argument_list|,
argument|const ExecutionContext&target
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|char
operator|*
name|ShortConditionString
argument_list|()
specifier|const
block|;
name|virtual
specifier|const
name|char
operator|*
name|LongConditionString
argument_list|()
specifier|const
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
comment|// liblldb_CommandOptionValidators_h_
end_comment

end_unit

