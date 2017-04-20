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
name|SUPPORT_TRACKED_VALUE_H
end_ifndef

begin_define
define|#
directive|define
name|SUPPORT_TRACKED_VALUE_H
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|"test_macros.h"
end_include

begin_struct
struct|struct
name|TrackedValue
block|{
enum|enum
name|State
block|{
name|CONSTRUCTED
block|,
name|MOVED_FROM
block|,
name|DESTROYED
block|}
enum|;
name|State
name|state
decl_stmt|;
name|TrackedValue
argument_list|()
operator|:
name|state
argument_list|(
argument|State::CONSTRUCTED
argument_list|)
block|{}
name|TrackedValue
argument_list|(
name|TrackedValue
specifier|const
operator|&
name|t
argument_list|)
operator|:
name|state
argument_list|(
argument|State::CONSTRUCTED
argument_list|)
block|{
name|assert
argument_list|(
name|t
operator|.
name|state
operator|!=
name|State
operator|::
name|MOVED_FROM
operator|&&
literal|"copying a moved-from object"
argument_list|)
block|;
name|assert
argument_list|(
name|t
operator|.
name|state
operator|!=
name|State
operator|::
name|DESTROYED
operator|&&
literal|"copying a destroyed object"
argument_list|)
block|;     }
if|#
directive|if
name|TEST_STD_VER
operator|>=
literal|11
name|TrackedValue
argument_list|(
name|TrackedValue
operator|&&
name|t
argument_list|)
operator|:
name|state
argument_list|(
argument|State::CONSTRUCTED
argument_list|)
block|{
name|assert
argument_list|(
name|t
operator|.
name|state
operator|!=
name|State
operator|::
name|MOVED_FROM
operator|&&
literal|"double moving from an object"
argument_list|)
block|;
name|assert
argument_list|(
name|t
operator|.
name|state
operator|!=
name|State
operator|::
name|DESTROYED
operator|&&
literal|"moving from a destroyed object"
argument_list|)
block|;
name|t
operator|.
name|state
operator|=
name|State
operator|::
name|MOVED_FROM
block|;     }
endif|#
directive|endif
name|TrackedValue
operator|&
name|operator
operator|=
operator|(
name|TrackedValue
specifier|const
operator|&
name|t
operator|)
block|{
name|assert
argument_list|(
name|state
operator|!=
name|State
operator|::
name|DESTROYED
operator|&&
literal|"copy assigning into destroyed object"
argument_list|)
block|;
name|assert
argument_list|(
name|t
operator|.
name|state
operator|!=
name|State
operator|::
name|MOVED_FROM
operator|&&
literal|"copying a moved-from object"
argument_list|)
block|;
name|assert
argument_list|(
name|t
operator|.
name|state
operator|!=
name|State
operator|::
name|DESTROYED
operator|&&
literal|"copying a destroyed object"
argument_list|)
block|;
name|state
operator|=
name|t
operator|.
name|state
block|;
return|return
operator|*
name|this
return|;
block|}
if|#
directive|if
name|TEST_STD_VER
operator|>=
literal|11
name|TrackedValue
modifier|&
name|operator
init|=
operator|(
name|TrackedValue
operator|&&
name|t
operator|)
block|{
name|assert
argument_list|(
name|state
operator|!=
name|State
operator|::
name|DESTROYED
operator|&&
literal|"move assigning into destroyed object"
argument_list|)
block|;
name|assert
argument_list|(
name|t
operator|.
name|state
operator|!=
name|State
operator|::
name|MOVED_FROM
operator|&&
literal|"double moving from an object"
argument_list|)
block|;
name|assert
argument_list|(
name|t
operator|.
name|state
operator|!=
name|State
operator|::
name|DESTROYED
operator|&&
literal|"moving from a destroyed object"
argument_list|)
block|;
name|state
operator|=
name|t
operator|.
name|state
block|;
name|t
operator|.
name|state
operator|=
name|State
operator|::
name|MOVED_FROM
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
operator|~
name|TrackedValue
argument_list|()
block|{
name|assert
argument_list|(
name|state
operator|!=
name|State
operator|::
name|DESTROYED
operator|&&
literal|"double-destroying an object"
argument_list|)
block|;
name|state
operator|=
name|State
operator|::
name|DESTROYED
block|;     }
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SUPPORT_TRACKED_VALUE_H
end_comment

end_unit

