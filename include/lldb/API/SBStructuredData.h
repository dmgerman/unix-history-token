begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBStructuredData.h --------------------------------------*- C++ -*-===//
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
name|SBStructuredData_h
end_ifndef

begin_define
define|#
directive|define
name|SBStructuredData_h
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBModule.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBStructuredData
block|{
name|public
label|:
name|SBStructuredData
argument_list|()
expr_stmt|;
name|SBStructuredData
argument_list|(
specifier|const
name|lldb
operator|::
name|SBStructuredData
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|SBStructuredData
argument_list|(
specifier|const
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
expr_stmt|;
operator|~
name|SBStructuredData
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBStructuredData
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBStructuredData
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBError
name|SetFromJSON
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|stream
argument_list|)
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBError
name|GetAsJSON
argument_list|(
argument|lldb::SBStream&stream
argument_list|)
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBError
name|GetDescription
argument_list|(
argument|lldb::SBStream&stream
argument_list|)
specifier|const
expr_stmt|;
name|protected
label|:
name|friend
name|class
name|SBTraceOptions
decl_stmt|;
name|StructuredDataImplUP
name|m_impl_up
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SBStructuredData_h */
end_comment

end_unit

