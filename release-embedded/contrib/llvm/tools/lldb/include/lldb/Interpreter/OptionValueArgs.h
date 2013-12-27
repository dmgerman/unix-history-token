begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionValueArgs.h --------------------------------------*- C++ -*-===//
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
name|liblldb_OptionValueArgs_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionValueArgs_h_
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
file|"lldb/Interpreter/OptionValueArray.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|OptionValueArgs
range|:
name|public
name|OptionValueArray
block|{
name|public
operator|:
name|OptionValueArgs
argument_list|()
operator|:
name|OptionValueArray
argument_list|(
argument|OptionValue::ConvertTypeToMask (OptionValue::eTypeString)
argument_list|)
block|{     }
name|virtual
operator|~
name|OptionValueArgs
argument_list|()
block|{     }
name|size_t
name|GetArgs
argument_list|(
name|Args
operator|&
name|args
argument_list|)
block|;
name|virtual
name|Type
name|GetType
argument_list|()
specifier|const
block|{
return|return
name|eTypeArgs
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_OptionValueArgs_h_
end_comment

end_unit

