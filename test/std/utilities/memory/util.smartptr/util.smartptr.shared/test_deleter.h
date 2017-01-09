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

begin_comment
comment|//<memory>
end_comment

begin_comment
comment|// shared_ptr
end_comment

begin_comment
comment|// Example move-only deleter
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DELETER_H
end_ifndef

begin_define
define|#
directive|define
name|DELETER_H
end_define

begin_include
include|#
directive|include
file|<type_traits>
end_include

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

begin_if
if|#
directive|if
name|TEST_STD_VER
operator|>=
literal|11
end_if

begin_define
define|#
directive|define
name|DELETE_FUNCTION
value|= delete
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DELETE_FUNCTION
value|{ assert(false); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|test_deleter_base
block|{
specifier|static
name|int
name|count
decl_stmt|;
specifier|static
name|int
name|dealloc_count
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|int
name|test_deleter_base
operator|::
name|count
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|test_deleter_base
operator|::
name|dealloc_count
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|test_deleter
operator|:
name|public
name|test_deleter_base
block|{
name|int
name|state_
block|;
name|public
operator|:
name|test_deleter
argument_list|()
operator|:
name|state_
argument_list|(
literal|0
argument_list|)
block|{
operator|++
name|count
block|;}
name|explicit
name|test_deleter
argument_list|(
argument|int s
argument_list|)
operator|:
name|state_
argument_list|(
argument|s
argument_list|)
block|{
operator|++
name|count
block|;}
name|test_deleter
argument_list|(
specifier|const
name|test_deleter
operator|&
name|d
argument_list|)
operator|:
name|state_
argument_list|(
argument|d.state_
argument_list|)
block|{
operator|++
name|count
block|;}
operator|~
name|test_deleter
argument_list|()
block|{
name|assert
argument_list|(
name|state_
operator|>=
literal|0
argument_list|)
block|;
operator|--
name|count
block|;
name|state_
operator|=
operator|-
literal|1
block|;}
name|int
name|state
argument_list|()
specifier|const
block|{
return|return
name|state_
return|;
block|}
name|void
name|set_state
argument_list|(
argument|int i
argument_list|)
block|{
name|state_
operator|=
name|i
block|;}
name|void
name|operator
argument_list|()
operator|(
name|T
operator|*
name|p
operator|)
block|{
name|assert
argument_list|(
name|state_
operator|>=
literal|0
argument_list|)
block|;
operator|++
name|dealloc_count
block|;
name|delete
name|p
block|;}
name|test_deleter
operator|*
name|operator
operator|&
operator|(
operator|)
specifier|const
name|DELETE_FUNCTION
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|>
name|void
name|swap
argument_list|(
argument|test_deleter<T>& x
argument_list|,
argument|test_deleter<T>& y
argument_list|)
block|{
name|test_deleter
operator|<
name|T
operator|>
name|t
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|x
argument_list|)
argument_list|)
block|;
name|x
operator|=
name|std
operator|::
name|move
argument_list|(
name|y
argument_list|)
block|;
name|y
operator|=
name|std
operator|::
name|move
argument_list|(
name|t
argument_list|)
block|; }
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// DELETER_H
end_comment

end_unit

