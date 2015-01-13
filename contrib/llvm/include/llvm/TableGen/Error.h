begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/TableGen/Error.h - tblgen error handling helpers ----*- C++ -*-===//
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
comment|// This file contains error handling helper routines to pretty-print diagnostic
end_comment

begin_comment
comment|// messages from tblgen.
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
name|LLVM_TABLEGEN_ERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TABLEGEN_ERROR_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/SourceMgr.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|void
name|PrintWarning
argument_list|(
name|ArrayRef
operator|<
name|SMLoc
operator|>
name|WarningLoc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
decl_stmt|;
name|void
name|PrintWarning
parameter_list|(
specifier|const
name|char
modifier|*
name|Loc
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
name|void
name|PrintWarning
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
name|void
name|PrintError
argument_list|(
name|ArrayRef
operator|<
name|SMLoc
operator|>
name|ErrorLoc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
decl_stmt|;
name|void
name|PrintError
parameter_list|(
specifier|const
name|char
modifier|*
name|Loc
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
name|void
name|PrintError
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|PrintFatalError
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|PrintFatalError
argument_list|(
name|ArrayRef
operator|<
name|SMLoc
operator|>
name|ErrorLoc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
decl_stmt|;
specifier|extern
name|SourceMgr
name|SrcMgr
decl_stmt|;
specifier|extern
name|unsigned
name|ErrorsPrinted
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace "llvm"
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

