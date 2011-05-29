begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- OptParserEmitter.h - Table Driven Command Line Parsing ---*- C++ -*-===//
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
name|UTILS_TABLEGEN_OPTPARSEREMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|UTILS_TABLEGEN_OPTPARSEREMITTER_H
end_define

begin_include
include|#
directive|include
file|"TableGenBackend.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// OptParserEmitter - This tablegen backend takes an input .td file
comment|/// describing a list of options and emits a data structure for parsing and
comment|/// working with those options when given an input command line.
name|class
name|OptParserEmitter
range|:
name|public
name|TableGenBackend
block|{
name|RecordKeeper
operator|&
name|Records
block|;
name|bool
name|GenDefs
block|;
name|public
operator|:
name|OptParserEmitter
argument_list|(
argument|RecordKeeper&R
argument_list|,
argument|bool _GenDefs
argument_list|)
operator|:
name|Records
argument_list|(
name|R
argument_list|)
block|,
name|GenDefs
argument_list|(
argument|_GenDefs
argument_list|)
block|{}
comment|/// run - Output the option parsing information.
comment|///
comment|/// \param GenHeader - Generate the header describing the option IDs.x
name|void
name|run
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

