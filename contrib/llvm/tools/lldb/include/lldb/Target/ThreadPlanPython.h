begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlanPython.h --------------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|liblldb_ThreadPlan_Python_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlan_Python_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/StopInfo.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Target.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ThreadPlan.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ThreadPlanTracer.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StructuredData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//------------------------------------------------------------------
comment|//  ThreadPlanPython:
comment|//
comment|//------------------------------------------------------------------
name|class
name|ThreadPlanPython
range|:
name|public
name|ThreadPlan
block|{
name|public
operator|:
name|ThreadPlanPython
argument_list|(
name|Thread
operator|&
name|thread
argument_list|,
specifier|const
name|char
operator|*
name|class_name
argument_list|)
block|;
operator|~
name|ThreadPlanPython
argument_list|()
name|override
block|;
name|void
name|GetDescription
argument_list|(
argument|Stream *s
argument_list|,
argument|lldb::DescriptionLevel level
argument_list|)
name|override
block|;
name|bool
name|ValidatePlan
argument_list|(
argument|Stream *error
argument_list|)
name|override
block|;
name|bool
name|ShouldStop
argument_list|(
argument|Event *event_ptr
argument_list|)
name|override
block|;
name|bool
name|MischiefManaged
argument_list|()
name|override
block|;
name|bool
name|WillStop
argument_list|()
name|override
block|;
name|bool
name|StopOthers
argument_list|()
name|override
block|;
name|void
name|DidPush
argument_list|()
name|override
block|;
name|bool
name|IsPlanStale
argument_list|()
name|override
block|;
name|protected
operator|:
name|bool
name|DoPlanExplainsStop
argument_list|(
argument|Event *event_ptr
argument_list|)
name|override
block|;
name|lldb
operator|::
name|StateType
name|GetPlanRunState
argument_list|()
name|override
block|;
name|private
operator|:
name|std
operator|::
name|string
name|m_class_name
block|;
name|StructuredData
operator|::
name|ObjectSP
name|m_implementation_sp
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanPython
argument_list|)
block|; }
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
comment|// liblldb_ThreadPlan_Python_h_
end_comment

end_unit

