begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/PrettyStackTrace.h - Pretty Crash Handling --*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|// This file defines the PrettyStackTraceEntry class, which is used to make
end_comment

begin_comment
comment|// crashes give more contextual information about what the program was doing
end_comment

begin_comment
comment|// when it crashed.
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
name|LLVM_SUPPORT_PRETTYSTACKTRACE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_PRETTYSTACKTRACE_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
comment|/// DisablePrettyStackTrace - Set this to true to disable this module. This
comment|/// might be neccessary if the host application installs its own signal
comment|/// handlers which conflict with the ones installed by this module.
comment|/// Defaults to false.
specifier|extern
name|bool
name|DisablePrettyStackTrace
decl_stmt|;
comment|/// PrettyStackTraceEntry - This class is used to represent a frame of the
comment|/// "pretty" stack trace that is dumped when a program crashes. You can define
comment|/// subclasses of this and declare them on the program stack: when they are
comment|/// constructed and destructed, they will add their symbolic frames to a
comment|/// virtual stack trace.  This gets dumped out if the program crashes.
name|class
name|PrettyStackTraceEntry
block|{
specifier|const
name|PrettyStackTraceEntry
modifier|*
name|NextEntry
decl_stmt|;
name|PrettyStackTraceEntry
argument_list|(
specifier|const
name|PrettyStackTraceEntry
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|PrettyStackTraceEntry
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|PrettyStackTraceEntry
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|PrettyStackTraceEntry
argument_list|()
expr_stmt|;
comment|/// print - Emit information about this stack frame to OS.
name|virtual
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// getNextEntry - Return the next entry in the list of frames.
specifier|const
name|PrettyStackTraceEntry
operator|*
name|getNextEntry
argument_list|()
specifier|const
block|{
return|return
name|NextEntry
return|;
block|}
block|}
empty_stmt|;
comment|/// PrettyStackTraceString - This object prints a specified string (which
comment|/// should not contain newlines) to the stream as the stack trace when a crash
comment|/// occurs.
name|class
name|PrettyStackTraceString
range|:
name|public
name|PrettyStackTraceEntry
block|{
specifier|const
name|char
operator|*
name|Str
block|;
name|public
operator|:
name|PrettyStackTraceString
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|)
operator|:
name|Str
argument_list|(
argument|str
argument_list|)
block|{}
name|virtual
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;   }
decl_stmt|;
comment|/// PrettyStackTraceProgram - This object prints a specified program arguments
comment|/// to the stream as the stack trace when a crash occurs.
name|class
name|PrettyStackTraceProgram
range|:
name|public
name|PrettyStackTraceEntry
block|{
name|int
name|ArgC
block|;
specifier|const
name|char
operator|*
specifier|const
operator|*
name|ArgV
block|;
name|public
operator|:
name|PrettyStackTraceProgram
argument_list|(
argument|int argc
argument_list|,
argument|const char * const*argv
argument_list|)
operator|:
name|ArgC
argument_list|(
name|argc
argument_list|)
block|,
name|ArgV
argument_list|(
argument|argv
argument_list|)
block|{}
name|virtual
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

