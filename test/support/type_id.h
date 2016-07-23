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
name|SUPPORT_TYPE_ID_H
end_ifndef

begin_define
define|#
directive|define
name|SUPPORT_TYPE_ID_H
end_define

begin_include
include|#
directive|include
file|<functional>
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
operator|<
literal|11
end_if

begin_error
error|#
directive|error
error|This header requires C++11 or greater
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TypeID - Represent a unique identifier for a type. TypeID allows equality
end_comment

begin_comment
comment|// comparisons between different types.
end_comment

begin_struct
struct|struct
name|TypeID
block|{
name|friend
name|bool
name|operator
operator|==
operator|(
name|TypeID
specifier|const
operator|&
name|LHS
operator|,
name|TypeID
specifier|const
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|m_id
operator|==
name|RHS
operator|.
name|m_id
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
name|TypeID
specifier|const
operator|&
name|LHS
operator|,
name|TypeID
specifier|const
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|m_id
operator|!=
name|RHS
operator|.
name|m_id
return|;
block|}
name|private
label|:
name|explicit
name|constexpr
name|TypeID
argument_list|(
specifier|const
name|int
operator|*
name|xid
argument_list|)
operator|:
name|m_id
argument_list|(
argument|xid
argument_list|)
block|{}
name|TypeID
argument_list|(
specifier|const
name|TypeID
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|TypeID
modifier|&
name|operator
init|=
operator|(
name|TypeID
specifier|const
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
specifier|const
name|int
modifier|*
specifier|const
name|m_id
decl_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|friend
name|TypeID
specifier|const
operator|&
name|makeTypeID
argument_list|()
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// makeTypeID - Return the TypeID for the specified type 'T'.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|TypeID
specifier|const
operator|&
name|makeTypeID
argument_list|()
block|{
specifier|static
name|int
name|dummy
block|;
specifier|static
specifier|const
name|TypeID
name|id
argument_list|(
operator|&
name|dummy
argument_list|)
block|;
return|return
name|id
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
operator|...
name|Args
operator|>
expr|struct
name|ArgumentListID
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// makeArgumentID - Create and return a unique identifier for a given set
end_comment

begin_comment
comment|// of arguments.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
operator|...
name|Args
operator|>
specifier|inline
name|TypeID
specifier|const
operator|&
name|makeArgumentID
argument_list|()
block|{
return|return
name|makeTypeID
operator|<
name|ArgumentListID
operator|<
name|Args
operator|...
operator|>>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SUPPORT_TYPE_ID_H
end_comment

end_unit

