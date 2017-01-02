begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ActivityStore.h -----------------------------------------*- C++ -*-===//
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
name|ActivityStore_h
end_ifndef

begin_define
define|#
directive|define
name|ActivityStore_h
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"ActivityStreamSPI.h"
end_include

begin_decl_stmt
name|class
name|ActivityStore
block|{
name|public
label|:
name|virtual
operator|~
name|ActivityStore
argument_list|()
expr_stmt|;
name|virtual
specifier|const
name|char
modifier|*
name|GetActivityForID
argument_list|(
name|os_activity_id_t
name|activity_id
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|std
operator|::
name|string
name|GetActivityChainForID
argument_list|(
argument|os_activity_id_t activity_id
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
name|protected
label|:
name|ActivityStore
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ActivityStore_h */
end_comment

end_unit

