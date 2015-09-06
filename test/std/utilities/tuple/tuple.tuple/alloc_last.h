begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----------------------------------------------------------------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
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
name|ALLOC_LAST_H
end_ifndef

begin_define
define|#
directive|define
name|ALLOC_LAST_H
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|"allocators.h"
end_include

begin_struct
struct|struct
name|alloc_last
block|{
specifier|static
name|bool
name|allocator_constructed
decl_stmt|;
typedef|typedef
name|A1
operator|<
name|int
operator|>
name|allocator_type
expr_stmt|;
name|int
name|data_
decl_stmt|;
name|alloc_last
argument_list|()
operator|:
name|data_
argument_list|(
literal|0
argument_list|)
block|{}
name|alloc_last
argument_list|(
argument|int d
argument_list|)
operator|:
name|data_
argument_list|(
argument|d
argument_list|)
block|{}
name|alloc_last
argument_list|(
specifier|const
name|A1
operator|<
name|int
operator|>
operator|&
name|a
argument_list|)
operator|:
name|data_
argument_list|(
literal|0
argument_list|)
block|{
name|assert
argument_list|(
name|a
operator|.
name|id
argument_list|()
operator|==
literal|5
argument_list|)
block|;
name|allocator_constructed
operator|=
name|true
block|;     }
name|alloc_last
argument_list|(
argument|int d
argument_list|,
argument|const A1<int>& a
argument_list|)
operator|:
name|data_
argument_list|(
argument|d
argument_list|)
block|{
name|assert
argument_list|(
name|a
operator|.
name|id
argument_list|()
operator|==
literal|5
argument_list|)
block|;
name|allocator_constructed
operator|=
name|true
block|;     }
name|alloc_last
argument_list|(
specifier|const
name|alloc_last
operator|&
name|d
argument_list|,
specifier|const
name|A1
operator|<
name|int
operator|>
operator|&
name|a
argument_list|)
operator|:
name|data_
argument_list|(
argument|d.data_
argument_list|)
block|{
name|assert
argument_list|(
name|a
operator|.
name|id
argument_list|()
operator|==
literal|5
argument_list|)
block|;
name|allocator_constructed
operator|=
name|true
block|;     }
operator|~
name|alloc_last
argument_list|()
block|{
name|data_
operator|=
operator|-
literal|1
block|;}
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|alloc_last
operator|&
name|x
operator|,
specifier|const
name|alloc_last
operator|&
name|y
operator|)
block|{
return|return
name|x
operator|.
name|data_
operator|==
name|y
operator|.
name|data_
return|;
block|}
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|alloc_last
operator|&
name|x
operator|,
specifier|const
name|alloc_last
operator|&
name|y
operator|)
block|{
return|return
name|x
operator|.
name|data_
operator|<
name|y
operator|.
name|data_
return|;
block|}
block|}
struct|;
end_struct

begin_expr_stmt
name|bool
name|alloc_last
operator|::
name|allocator_constructed
operator|=
name|false
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ALLOC_LAST_H
end_comment

end_unit

