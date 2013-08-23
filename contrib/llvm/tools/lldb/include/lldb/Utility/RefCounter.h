begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RefCounter.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_RefCounter_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RefCounter_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_utility
block|{
comment|//----------------------------------------------------------------------
comment|// A simple reference counter object. You need an uint32_t* to use it
comment|// Once that is in place, everyone who needs to ref-count, can say
comment|// RefCounter ref(ptr);
comment|// (of course, the pointer is a shared resource, and must be accessible to
comment|// everyone who needs it). Synchronization is handled by RefCounter itself
comment|// The counter is decreased each time a RefCounter to it goes out of scope
comment|//----------------------------------------------------------------------
name|class
name|RefCounter
block|{
name|public
label|:
typedef|typedef
name|uint32_t
name|value_type
typedef|;
name|RefCounter
argument_list|(
name|value_type
operator|*
name|ctr
argument_list|)
expr_stmt|;
operator|~
name|RefCounter
argument_list|()
expr_stmt|;
name|private
label|:
name|value_type
modifier|*
name|m_counter
decl_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|RefCounter
argument_list|)
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|T
name|increment
argument_list|(
argument|T* t
argument_list|)
block|{
return|return
name|__sync_fetch_and_add
argument_list|(
name|t
argument_list|,
literal|1
argument_list|)
return|;
block|}
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|T
name|decrement
argument_list|(
argument|T* t
argument_list|)
block|{
return|return
name|__sync_fetch_and_add
argument_list|(
name|t
argument_list|,
operator|-
literal|1
argument_list|)
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_utility
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_RefCounter_h_
end_comment

end_unit

