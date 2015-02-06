begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnLLDBProxySBValue.h ---------------------------------*- C++ -*-===//
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
comment|//++
end_comment

begin_comment
comment|// File:        MICmnLLDBProxySBValue.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMICmnLLDBProxySBValue interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Environment: Compilers:  Visual C++ 12.
end_comment

begin_comment
comment|//                          gcc (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
end_comment

begin_comment
comment|//              Libraries:  See MIReadmetxt.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Copyright:   None.
end_comment

begin_comment
comment|//--
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_comment
comment|// Third Party Headers:
end_comment

begin_include
include|#
directive|include
file|<lldb/API/SBValue.h>
end_include

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MIDataTypes.h"
end_include

begin_comment
comment|// Declerations:
end_comment

begin_decl_stmt
name|class
name|CMIUtilString
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI proxy wrapper class to lldb::SBValue. The class provides functionality
end_comment

begin_comment
comment|//          to assist in the use of SBValue's parculiar function usage.
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 03/04/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnLLDBProxySBValue
block|{
comment|// Statics:
name|public
label|:
specifier|static
name|bool
name|GetValueAsSigned
argument_list|(
specifier|const
name|lldb
operator|::
name|SBValue
operator|&
name|vrValue
argument_list|,
name|MIint64
operator|&
name|vwValue
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|GetValueAsUnsigned
argument_list|(
specifier|const
name|lldb
operator|::
name|SBValue
operator|&
name|vrValue
argument_list|,
name|MIuint64
operator|&
name|vwValue
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|GetCString
argument_list|(
specifier|const
name|lldb
operator|::
name|SBValue
operator|&
name|vrValue
argument_list|,
name|CMIUtilString
operator|&
name|vwCString
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

