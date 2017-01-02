begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LogFilterChain.h ----------------------------------------*- C++ -*-===//
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
name|LogFilterChain_h
end_ifndef

begin_define
define|#
directive|define
name|LogFilterChain_h
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"DarwinLogInterfaces.h"
end_include

begin_decl_stmt
name|class
name|LogFilterChain
block|{
name|public
label|:
name|LogFilterChain
argument_list|(
argument|bool default_accept
argument_list|)
empty_stmt|;
name|void
name|AppendFilter
parameter_list|(
specifier|const
name|LogFilterSP
modifier|&
name|filter_sp
parameter_list|)
function_decl|;
name|void
name|ClearFilterChain
parameter_list|()
function_decl|;
name|bool
name|GetDefaultAccepts
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetDefaultAccepts
parameter_list|(
name|bool
name|default_accepts
parameter_list|)
function_decl|;
name|bool
name|GetAcceptMessage
argument_list|(
specifier|const
name|LogMessage
operator|&
name|message
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|using
name|FilterVector
init|=
name|std
operator|::
name|vector
operator|<
name|LogFilterSP
operator|>
decl_stmt|;
name|FilterVector
name|m_filters
decl_stmt|;
name|bool
name|m_default_accept
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LogFilterChain_hpp */
end_comment

end_unit

