begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBTypeNameSpecifier.h --------------------------------------*- C++ -*-===//
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
name|LLDB_SBTypeNameSpecifier_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBTypeNameSpecifier_h_
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
name|SBTypeNameSpecifier
block|{
name|public
label|:
name|SBTypeNameSpecifier
argument_list|()
expr_stmt|;
name|SBTypeNameSpecifier
argument_list|(
argument|const char* name
argument_list|,
argument|bool is_regex = false
argument_list|)
empty_stmt|;
name|SBTypeNameSpecifier
argument_list|(
argument|SBType type
argument_list|)
empty_stmt|;
name|SBTypeNameSpecifier
argument_list|(
specifier|const
name|lldb
operator|::
name|SBTypeNameSpecifier
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SBTypeNameSpecifier
argument_list|()
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
modifier|*
name|GetName
parameter_list|()
function_decl|;
name|SBType
name|GetType
parameter_list|()
function_decl|;
name|bool
name|IsRegex
parameter_list|()
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
name|SBTypeNameSpecifier
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBTypeNameSpecifier
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|IsEqualTo
argument_list|(
name|lldb
operator|::
name|SBTypeNameSpecifier
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
name|SBTypeNameSpecifier
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
name|SBTypeNameSpecifier
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
name|lldb
operator|::
name|TypeNameSpecifierImplSP
name|GetSP
argument_list|()
expr_stmt|;
name|void
name|SetSP
argument_list|(
specifier|const
name|lldb
operator|::
name|TypeNameSpecifierImplSP
operator|&
name|type_namespec_sp
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|TypeNameSpecifierImplSP
name|m_opaque_sp
expr_stmt|;
name|SBTypeNameSpecifier
argument_list|(
specifier|const
name|lldb
operator|::
name|TypeNameSpecifierImplSP
operator|&
argument_list|)
expr_stmt|;
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
comment|// LLDB_SBTypeNameSpecifier_h_
end_comment

end_unit

