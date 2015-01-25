begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- clang/Basic/PrettyStackTrace.h - Pretty Crash Handling --*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the PrettyStackTraceEntry class, which is used to make
end_comment

begin_comment
comment|/// crashes give more contextual information about what the program was doing
end_comment

begin_comment
comment|/// when it crashed.
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
name|LLVM_CLANG_BASIC_PRETTYSTACKTRACE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_PRETTYSTACKTRACE_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/PrettyStackTrace.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// If a crash happens while one of these objects are live, the message
comment|/// is printed out along with the specified source location.
name|class
name|PrettyStackTraceLoc
range|:
name|public
name|llvm
operator|::
name|PrettyStackTraceEntry
block|{
name|SourceManager
operator|&
name|SM
block|;
name|SourceLocation
name|Loc
block|;
specifier|const
name|char
operator|*
name|Message
block|;
name|public
operator|:
name|PrettyStackTraceLoc
argument_list|(
argument|SourceManager&sm
argument_list|,
argument|SourceLocation L
argument_list|,
argument|const char *Msg
argument_list|)
operator|:
name|SM
argument_list|(
name|sm
argument_list|)
block|,
name|Loc
argument_list|(
name|L
argument_list|)
block|,
name|Message
argument_list|(
argument|Msg
argument_list|)
block|{}
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
name|override
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

