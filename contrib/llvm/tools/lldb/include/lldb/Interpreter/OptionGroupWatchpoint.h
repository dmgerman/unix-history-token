begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionGroupWatchpoint.h ---------------------------------*- C++ -*-===//
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
name|liblldb_OptionGroupWatchpoint_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionGroupWatchpoint_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Interpreter/Options.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//-------------------------------------------------------------------------
comment|// OptionGroupWatchpoint
comment|//-------------------------------------------------------------------------
name|class
name|OptionGroupWatchpoint
range|:
name|public
name|OptionGroup
block|{
name|public
operator|:
name|OptionGroupWatchpoint
argument_list|()
block|;
operator|~
name|OptionGroupWatchpoint
argument_list|()
name|override
block|;
specifier|static
name|bool
name|IsWatchSizeSupported
argument_list|(
argument|uint32_t watch_size
argument_list|)
block|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|OptionDefinition
operator|>
name|GetDefinitions
argument_list|()
name|override
block|;
name|Status
name|SetOptionValue
argument_list|(
argument|uint32_t option_idx
argument_list|,
argument|llvm::StringRef option_value
argument_list|,
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
name|Status
name|SetOptionValue
argument_list|(
name|uint32_t
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|ExecutionContext
operator|*
argument_list|)
operator|=
name|delete
block|;
name|void
name|OptionParsingStarting
argument_list|(
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
comment|// Note:
comment|// eWatchRead == LLDB_WATCH_TYPE_READ; and
comment|// eWatchWrite == LLDB_WATCH_TYPE_WRITE
typedef|typedef
enum|enum
name|WatchType
block|{
name|eWatchInvalid
init|=
literal|0
block|,
name|eWatchRead
block|,
name|eWatchWrite
block|,
name|eWatchReadWrite
decl|}
name|WatchType
empty_stmt|;
name|WatchType
name|watch_type
block|;
name|uint32_t
name|watch_size
block|;
name|bool
name|watch_type_specified
block|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|OptionGroupWatchpoint
argument_list|)
empty_stmt|;
block|}
enum|;
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
comment|// liblldb_OptionGroupWatchpoint_h_
end_comment

end_unit

