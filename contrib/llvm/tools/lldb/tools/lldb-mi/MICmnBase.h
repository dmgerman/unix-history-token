begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnBase.h ---------------------------------------------*- C++ -*-===//
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

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MIDataTypes.h"
end_include

begin_include
include|#
directive|include
file|"MIUtilString.h"
end_include

begin_comment
comment|// Declarations:
end_comment

begin_decl_stmt
name|class
name|CMICmnLog
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI common code implementation base class.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnBase
block|{
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CMICmnBase
argument_list|()
expr_stmt|;
name|bool
name|HaveErrorDescription
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|CMIUtilString
operator|&
name|GetErrorDescription
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetErrorDescription
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrTxt
argument_list|)
decl|const
decl_stmt|;
name|void
name|SetErrorDescriptionn
argument_list|(
specifier|const
name|char
operator|*
name|vFormat
argument_list|,
operator|...
argument_list|)
decl|const
decl_stmt|;
name|void
name|SetErrorDescriptionNoLog
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrTxt
argument_list|)
decl|const
decl_stmt|;
name|void
name|ClrErrorDescription
argument_list|()
specifier|const
expr_stmt|;
comment|// Overrideable:
name|public
label|:
comment|/* dtor */
name|virtual
operator|~
name|CMICmnBase
argument_list|()
expr_stmt|;
comment|// Attributes:
name|protected
label|:
name|mutable
name|CMIUtilString
name|m_strMILastErrorDescription
decl_stmt|;
name|bool
name|m_bInitialized
decl_stmt|;
comment|// True = yes successfully initialized, false = no yet or
comment|// failed
name|CMICmnLog
modifier|*
name|m_pLog
decl_stmt|;
comment|// Allow all derived classes to use the logger
name|MIint
name|m_clientUsageRefCnt
decl_stmt|;
comment|// Count of client using *this object so not
comment|// shutdown() object to early
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

