begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ExpressionSourceCode.h ----------------------------------*- C++ -*-===//
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
name|liblldb_ExpressionSourceCode_h
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ExpressionSourceCode_h
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ExecutionContext
decl_stmt|;
name|class
name|ExpressionSourceCode
block|{
name|public
label|:
specifier|static
specifier|const
name|char
modifier|*
name|g_expression_prefix
decl_stmt|;
specifier|static
name|ExpressionSourceCode
modifier|*
name|CreateWrapped
parameter_list|(
specifier|const
name|char
modifier|*
name|prefix
parameter_list|,
specifier|const
name|char
modifier|*
name|body
parameter_list|)
block|{
return|return
name|new
name|ExpressionSourceCode
argument_list|(
literal|"$__lldb_expr"
argument_list|,
name|prefix
argument_list|,
name|body
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|ExpressionSourceCode
modifier|*
name|CreateUnwrapped
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|body
parameter_list|)
block|{
return|return
name|new
name|ExpressionSourceCode
argument_list|(
name|name
argument_list|,
literal|""
argument_list|,
name|body
argument_list|,
name|false
argument_list|)
return|;
block|}
name|bool
name|NeedsWrapping
argument_list|()
specifier|const
block|{
return|return
name|m_wrap
return|;
block|}
specifier|const
name|char
operator|*
name|GetName
argument_list|()
specifier|const
block|{
return|return
name|m_name
operator|.
name|c_str
argument_list|()
return|;
block|}
name|bool
name|GetText
argument_list|(
name|std
operator|::
name|string
operator|&
name|text
argument_list|,
name|lldb
operator|::
name|LanguageType
name|wrapping_language
argument_list|,
name|bool
name|const_object
argument_list|,
name|bool
name|static_method
argument_list|,
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|ExpressionSourceCode
argument_list|(
argument|const char *name
argument_list|,
argument|const char *prefix
argument_list|,
argument|const char *body
argument_list|,
argument|bool wrap
argument_list|)
block|:
name|m_name
argument_list|(
name|name
argument_list|)
operator|,
name|m_prefix
argument_list|(
name|prefix
argument_list|)
operator|,
name|m_body
argument_list|(
name|body
argument_list|)
operator|,
name|m_wrap
argument_list|(
argument|wrap
argument_list|)
block|{     }
name|std
operator|::
name|string
name|m_name
expr_stmt|;
name|std
operator|::
name|string
name|m_prefix
expr_stmt|;
name|std
operator|::
name|string
name|m_body
expr_stmt|;
name|bool
name|m_wrap
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

