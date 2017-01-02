begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DarwinLogEvent.h ----------------------------------------*- C++ -*-===//
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
name|DarwinLogEvent_h
end_ifndef

begin_define
define|#
directive|define
name|DarwinLogEvent_h
end_define

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"JSONGenerator.h"
end_include

begin_comment
comment|// =============================================================================
end_comment

begin_comment
comment|/// Each discrete unit of information is described as an event, such as
end_comment

begin_comment
comment|/// the emission of a single log message.
end_comment

begin_comment
comment|// =============================================================================
end_comment

begin_decl_stmt
name|using
name|DarwinLogEvent
init|=
name|JSONGenerator
operator|::
name|Dictionary
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|using
name|DarwinLogEventSP
init|=
name|std
operator|::
name|shared_ptr
operator|<
name|DarwinLogEvent
operator|>
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|using
name|DarwinLogEventVector
init|=
name|std
operator|::
name|vector
operator|<
name|DarwinLogEventSP
operator|>
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

