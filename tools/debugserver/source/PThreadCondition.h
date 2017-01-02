begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PThreadCondition.h --------------------------------------*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|//  Created by Greg Clayton on 6/16/07.
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
name|__PThreadCondition_h__
end_ifndef

begin_define
define|#
directive|define
name|__PThreadCondition_h__
end_define

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_decl_stmt
name|class
name|PThreadCondition
block|{
name|public
label|:
name|PThreadCondition
argument_list|()
block|{
operator|::
name|pthread_cond_init
argument_list|(
operator|&
name|m_condition
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
operator|~
name|PThreadCondition
argument_list|()
block|{
operator|::
name|pthread_cond_destroy
argument_list|(
operator|&
name|m_condition
argument_list|)
block|; }
name|pthread_cond_t
operator|*
name|Condition
argument_list|()
block|{
return|return
operator|&
name|m_condition
return|;
block|}
name|int
name|Broadcast
parameter_list|()
block|{
return|return
operator|::
name|pthread_cond_broadcast
argument_list|(
operator|&
name|m_condition
argument_list|)
return|;
block|}
name|int
name|Signal
parameter_list|()
block|{
return|return
operator|::
name|pthread_cond_signal
argument_list|(
operator|&
name|m_condition
argument_list|)
return|;
block|}
name|protected
label|:
name|pthread_cond_t
name|m_condition
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

