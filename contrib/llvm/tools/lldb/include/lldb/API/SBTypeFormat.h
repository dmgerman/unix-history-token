begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBTypeFormat.h --------------------------------------------*- C++ -*-===//
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
name|LLDB_SBTypeFormat_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBTypeFormat_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBTypeFormat
block|{
name|public
label|:
name|SBTypeFormat
argument_list|()
expr_stmt|;
name|SBTypeFormat
argument_list|(
argument|lldb::Format format
argument_list|,
argument|uint32_t options =
literal|0
argument_list|)
empty_stmt|;
comment|// see lldb::eTypeOption values
name|SBTypeFormat
argument_list|(
argument|const char* type
argument_list|,
argument|uint32_t options =
literal|0
argument_list|)
empty_stmt|;
comment|// see lldb::eTypeOption values
name|SBTypeFormat
argument_list|(
specifier|const
name|lldb
operator|::
name|SBTypeFormat
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SBTypeFormat
argument_list|()
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|Format
name|GetFormat
argument_list|()
expr_stmt|;
specifier|const
name|char
modifier|*
name|GetTypeName
parameter_list|()
function_decl|;
name|uint32_t
name|GetOptions
parameter_list|()
function_decl|;
name|void
name|SetFormat
argument_list|(
name|lldb
operator|::
name|Format
argument_list|)
decl_stmt|;
name|void
name|SetTypeName
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
name|SetOptions
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
name|bool
name|GetDescription
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|description_level
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|SBTypeFormat
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBTypeFormat
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|IsEqualTo
argument_list|(
name|lldb
operator|::
name|SBTypeFormat
operator|&
name|rhs
argument_list|)
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
name|lldb
operator|::
name|SBTypeFormat
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
name|lldb
operator|::
name|SBTypeFormat
operator|&
name|rhs
operator|)
expr_stmt|;
name|protected
label|:
name|friend
name|class
name|SBDebugger
decl_stmt|;
name|friend
name|class
name|SBTypeCategory
decl_stmt|;
name|friend
name|class
name|SBValue
decl_stmt|;
name|lldb
operator|::
name|TypeFormatImplSP
name|GetSP
argument_list|()
expr_stmt|;
name|void
name|SetSP
argument_list|(
specifier|const
name|lldb
operator|::
name|TypeFormatImplSP
operator|&
name|typeformat_impl_sp
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|TypeFormatImplSP
name|m_opaque_sp
expr_stmt|;
name|SBTypeFormat
argument_list|(
specifier|const
name|lldb
operator|::
name|TypeFormatImplSP
operator|&
argument_list|)
expr_stmt|;
name|enum
name|class
name|Type
block|{
name|eTypeKeepSame
operator|,
name|eTypeFormat
operator|,
name|eTypeEnum
block|}
empty_stmt|;
name|bool
name|CopyOnWrite_Impl
parameter_list|(
name|Type
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBTypeFormat_h_
end_comment

end_unit

