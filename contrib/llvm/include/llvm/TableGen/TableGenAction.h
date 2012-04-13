begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/TableGen/TableGenAction.h - defines TableGenAction --*- C++ -*-===//
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
comment|// This file defines the TableGenAction base class to be derived from by
end_comment

begin_comment
comment|// tblgen tools.
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
name|LLVM_TABLEGEN_TABLEGENACTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TABLEGEN_TABLEGENACTION_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|RecordKeeper
decl_stmt|;
name|class
name|TableGenAction
block|{
name|public
label|:
name|virtual
operator|~
name|TableGenAction
argument_list|()
block|{}
comment|/// Perform the action using Records, and write output to OS.
comment|/// @returns true on error, false otherwise
name|virtual
name|bool
name|operator
argument_list|()
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|RecordKeeper
operator|&
name|Records
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

