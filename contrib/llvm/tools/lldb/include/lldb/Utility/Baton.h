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

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for DescriptionLevel
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_comment
comment|// for unique_ptr
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stream
decl_stmt|;
block|}
end_decl_stmt

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
name|Baton
argument_list|()
block|{}
name|virtual
operator|~
name|Baton
argument_list|()
block|{}
name|virtual
name|void
operator|*
name|data
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|GetDescription
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|level
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
name|class
name|UntypedBaton
range|:
name|public
name|Baton
block|{
name|public
operator|:
name|UntypedBaton
argument_list|(
name|void
operator|*
name|Data
argument_list|)
operator|:
name|m_data
argument_list|(
argument|Data
argument_list|)
block|{}
name|virtual
operator|~
name|UntypedBaton
argument_list|()
block|{
comment|// The default destructor for an untyped baton does NOT attempt to clean up
comment|// anything in m_data.
block|}
name|void
operator|*
name|data
argument_list|()
name|override
block|{
return|return
name|m_data
return|;
block|}
name|void
name|GetDescription
argument_list|(
argument|Stream *s
argument_list|,
argument|lldb::DescriptionLevel level
argument_list|)
specifier|const
name|override
block|;
name|void
operator|*
name|m_data
block|;
comment|// Leave baton public for easy access
block|}
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|TypedBaton
operator|:
name|public
name|Baton
block|{
name|public
operator|:
name|explicit
name|TypedBaton
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|T
operator|>
name|Item
argument_list|)
operator|:
name|Item
argument_list|(
argument|std::move(Item)
argument_list|)
block|{}
name|T
operator|*
name|getItem
argument_list|()
block|{
return|return
name|Item
operator|.
name|get
argument_list|()
return|;
block|}
specifier|const
name|T
operator|*
name|getItem
argument_list|()
specifier|const
block|{
return|return
name|Item
operator|.
name|get
argument_list|()
return|;
block|}
name|void
operator|*
name|data
argument_list|()
name|override
block|{
return|return
name|Item
operator|.
name|get
argument_list|()
return|;
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
name|override
block|{}
name|protected
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|T
operator|>
name|Item
block|; }
expr_stmt|;
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

