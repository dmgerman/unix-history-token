begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcFileReader.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_ProcFileReader_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ProcFileReader_h_
end_define

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_linux
block|{
name|class
name|ProcFileReader
block|{
name|public
label|:
specifier|static
name|lldb
operator|::
name|DataBufferSP
name|ReadIntoDataBuffer
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|const char *name
argument_list|)
expr_stmt|;
comment|/// Parse the /proc/{@a pid}/{@a name} file line by line, passing each line to
comment|/// line_parser, until
comment|/// either end of file or until line_parser returns false.
specifier|static
name|Error
name|ProcessLineByLine
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|,
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|line
argument_list|)
operator|>
name|line_parser
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace process_linux
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
comment|// #ifndef liblldb_ProcFileReader_h_
end_comment

end_unit

