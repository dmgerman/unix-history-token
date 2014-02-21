begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- PrettyStackTraceLocationContext.h - show analysis backtrace --*- C++ -*-//
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
name|LLVM_CLANG_STATICANALYZER_PRETTYSTACKTRACELOCATIONCONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_PRETTYSTACKTRACELOCATIONCONTEXT_H
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/AnalysisContext.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
comment|/// While alive, includes the current analysis stack in a crash trace.
comment|///
comment|/// Example:
comment|/// \code
comment|/// 0.     Program arguments: ...
comment|/// 1.<eof> parser at end of file
comment|/// 2.     While analyzing stack:
comment|///        #0 void inlined()
comment|///        #1 void test()
comment|/// 3.     crash-trace.c:6:3: Error evaluating statement
comment|/// \endcode
name|class
name|PrettyStackTraceLocationContext
range|:
name|public
name|llvm
operator|::
name|PrettyStackTraceEntry
block|{
specifier|const
name|LocationContext
operator|*
name|LCtx
block|;
name|public
operator|:
name|PrettyStackTraceLocationContext
argument_list|(
specifier|const
name|LocationContext
operator|*
name|LC
argument_list|)
operator|:
name|LCtx
argument_list|(
argument|LC
argument_list|)
block|{
name|assert
argument_list|(
name|LCtx
argument_list|)
block|;   }
name|virtual
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|{
name|OS
operator|<<
literal|"While analyzing stack: \n"
block|;
name|LCtx
operator|->
name|dumpStack
argument_list|(
name|OS
argument_list|,
literal|"\t"
argument_list|)
block|;   }
block|}
decl_stmt|;
block|}
comment|// end ento namespace
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

