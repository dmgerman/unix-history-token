begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ConvertEnum.h -------------------------------------------*- C++ -*-===//
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
name|LLDB_UTILITY_CONVERTENUM_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_UTILITY_CONVERTENUM_H
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-enumerations.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
specifier|const
name|char
modifier|*
name|GetVoteAsCString
parameter_list|(
name|Vote
name|vote
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|GetSectionTypeAsCString
argument_list|(
name|lldb
operator|::
name|SectionType
name|sect_type
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

