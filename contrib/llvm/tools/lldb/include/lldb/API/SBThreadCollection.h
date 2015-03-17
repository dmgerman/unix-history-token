begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBThreadCollection.h ------------------------------------*- C++ -*-===//
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
name|LLDB_SBThreadCollection_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBThreadCollection_h_
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
name|SBThreadCollection
block|{
name|public
label|:
name|SBThreadCollection
argument_list|()
expr_stmt|;
name|SBThreadCollection
argument_list|(
specifier|const
name|SBThreadCollection
operator|&
name|rhs
argument_list|)
expr_stmt|;
specifier|const
name|SBThreadCollection
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SBThreadCollection
operator|&
name|rhs
operator|)
decl_stmt|;
operator|~
name|SBThreadCollection
argument_list|()
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|size_t
name|GetSize
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBThread
name|GetThreadAtIndex
argument_list|(
argument|size_t idx
argument_list|)
expr_stmt|;
name|protected
label|:
comment|// Mimic shared pointer...
name|lldb_private
operator|::
name|ThreadCollection
operator|*
name|get
argument_list|()
specifier|const
expr_stmt|;
name|lldb_private
operator|::
name|ThreadCollection
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
decl_stmt|;
name|lldb
operator|::
name|ThreadCollectionSP
operator|&
name|operator
operator|*
operator|(
operator|)
expr_stmt|;
specifier|const
name|lldb
operator|::
name|ThreadCollectionSP
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
expr_stmt|;
name|SBThreadCollection
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadCollectionSP
operator|&
name|threads
argument_list|)
expr_stmt|;
name|void
name|SetOpaque
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadCollectionSP
operator|&
name|threads
argument_list|)
decl_stmt|;
name|private
label|:
name|friend
name|class
name|SBProcess
decl_stmt|;
name|lldb
operator|::
name|ThreadCollectionSP
name|m_opaque_sp
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBThreadCollection_h_
end_comment

end_unit

