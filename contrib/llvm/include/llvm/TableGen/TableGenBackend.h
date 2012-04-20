begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/TableGen/TableGenBackend.h - Backend base class -----*- C++ -*-===//
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
comment|// The TableGenBackend class is provided as a common interface for all TableGen
end_comment

begin_comment
comment|// backends.  It provides useful services and an standardized interface.
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
name|LLVM_TABLEGEN_TABLEGENBACKEND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TABLEGEN_TABLEGENBACKEND_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Record
decl_stmt|;
name|class
name|RecordKeeper
decl_stmt|;
struct|struct
name|TableGenBackend
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|virtual
operator|~
name|TableGenBackend
argument_list|()
block|{}
comment|// run - All TableGen backends should implement the run method, which should
comment|// be the main entry point.
name|virtual
name|void
name|run
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
operator|=
literal|0
expr_stmt|;
name|public
label|:
comment|// Useful helper routines...
comment|/// EmitSourceFileHeader - Output a LLVM style file header to the specified
comment|/// ostream.
name|void
name|EmitSourceFileHeader
argument_list|(
name|StringRef
name|Desc
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

