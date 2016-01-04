begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnLLDBBroadcaster.h ----------------------------------*- C++ -*-===//
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
file|"lldb/API/SBBroadcaster.h"
end_include

begin_include
include|#
directive|include
file|"MICmnBase.h"
end_include

begin_include
include|#
directive|include
file|"MIUtilSingletonBase.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI derived class from LLDB SBBroadcaster API.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//          *** This class (files) is a place holder until we know we need it or
end_comment

begin_comment
comment|//          *** not
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//          A singleton class.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnLLDBBroadcaster
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|lldb
decl|::
name|SBBroadcaster
decl_stmt|,
name|public
name|MI
decl|::
name|ISingleton
decl|<
name|CMICmnLLDBBroadcaster
decl|>
block|{
name|friend
name|MI
operator|::
name|ISingleton
operator|<
name|CMICmnLLDBBroadcaster
operator|>
expr_stmt|;
comment|// Methods:
name|public
label|:
name|bool
name|Initialize
argument_list|()
name|override
expr_stmt|;
name|bool
name|Shutdown
argument_list|()
name|override
expr_stmt|;
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMICmnLLDBBroadcaster
argument_list|()
expr_stmt|;
comment|/* ctor */
name|CMICmnLLDBBroadcaster
argument_list|(
specifier|const
name|CMICmnLLDBBroadcaster
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CMICmnLLDBBroadcaster
operator|&
operator|)
decl_stmt|;
comment|// Overridden:
name|private
label|:
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmnLLDBBroadcaster
argument_list|()
name|override
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

