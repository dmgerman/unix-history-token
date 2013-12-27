begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Baton.h -------------------------------------------------*- C++ -*-===//
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
name|lldb_Baton_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Baton_h_
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
file|"lldb/lldb-public.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Baton Baton.h "lldb/Core/Baton.h"
comment|/// @brief A class designed to wrap callback batons so they can cleanup
comment|///        any acquired resources
comment|///
comment|/// This class is designed to be used by any objects that have a
comment|/// callback function that takes a baton where the baton might need to
comment|/// free/delete/close itself.
comment|///
comment|/// The default behavior is to not free anything. Subclasses can
comment|/// free any needed resources in their destructors.
comment|//----------------------------------------------------------------------
name|class
name|Baton
block|{
name|public
label|:
name|explicit
name|Baton
argument_list|(
name|void
operator|*
name|p
argument_list|)
operator|:
name|m_data
argument_list|(
argument|p
argument_list|)
block|{     }
name|virtual
operator|~
name|Baton
argument_list|()
block|{
comment|// The default destructor for a baton does NOT attempt to clean up
comment|// anything in m_baton
block|}
name|virtual
name|void
name|GetDescription
argument_list|(
argument|Stream *s
argument_list|,
argument|lldb::DescriptionLevel level
argument_list|)
specifier|const
expr_stmt|;
name|void
modifier|*
name|m_data
decl_stmt|;
comment|// Leave baton public for easy access
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For Baton only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Baton
argument_list|)
expr_stmt|;
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

begin_comment
comment|// lldb_Baton_h_
end_comment

end_unit

