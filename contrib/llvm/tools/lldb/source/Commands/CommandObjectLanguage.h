begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CommandObjectLanguage.h ---------------------------------*- C++ -*-===//
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
name|liblldb_CommandObjectLanguage_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CommandObjectLanguage_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/CommandObjectMultiword.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CommandObjectLanguage
range|:
name|public
name|CommandObjectMultiword
block|{
name|public
operator|:
name|CommandObjectLanguage
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
block|;
operator|~
name|CommandObjectLanguage
argument_list|()
name|override
block|;
name|void
name|GenerateHelpText
argument_list|(
argument|Stream&output_stream
argument_list|)
name|override
block|;
name|protected
operator|:
name|bool
name|DoExecute
argument_list|(
name|Args
operator|&
name|command
argument_list|,
name|CommandReturnObject
operator|&
name|result
argument_list|)
block|;     }
decl_stmt|;
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
comment|// liblldb_CommandObjectLanguage_h_
end_comment

end_unit

