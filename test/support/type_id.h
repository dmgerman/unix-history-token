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
file|<typeinfo>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<cstdio>
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

begin_include
include|#
directive|include
file|"demangle.h"
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
name|std
operator|::
name|string
name|name
argument_list|()
specifier|const
block|{
return|return
name|demangle
argument_list|(
name|m_id
argument_list|)
return|;
block|}
name|void
name|dump
argument_list|()
specifier|const
block|{
name|std
operator|::
name|string
name|s
operator|=
name|name
argument_list|()
block|;
name|std
operator|::
name|printf
argument_list|(
literal|"TypeID: %s\n"
argument_list|,
name|s
operator|.
name|c_str
argument_list|()
argument_list|)
block|;   }
name|private
operator|:
name|explicit
name|constexpr
name|TypeID
argument_list|(
specifier|const
name|char
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
name|char
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
name|makeTypeIDImp
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
name|makeTypeIDImp
argument_list|()
block|{
specifier|static
specifier|const
name|TypeID
name|id
argument_list|(
name|typeid
argument_list|(
name|T
argument_list|)
operator|.
name|name
argument_list|()
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
name|T
operator|>
expr|struct
name|TypeWrapper
block|{}
expr_stmt|;
end_expr_stmt

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
return|return
name|makeTypeIDImp
operator|<
name|TypeWrapper
operator|<
name|T
operator|>>
operator|(
operator|)
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
name|makeTypeIDImp
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

begin_comment
comment|// COMPARE_TYPEID(...) is a utility macro for generating diagnostics when
end_comment

begin_comment
comment|// two typeid's are expected to be equal
end_comment

begin_define
define|#
directive|define
name|COMPARE_TYPEID
parameter_list|(
name|LHS
parameter_list|,
name|RHS
parameter_list|)
value|CompareTypeIDVerbose(#LHS, LHS, #RHS, RHS)
end_define

begin_function
specifier|inline
name|bool
name|CompareTypeIDVerbose
parameter_list|(
specifier|const
name|char
modifier|*
name|LHSString
parameter_list|,
name|TypeID
specifier|const
modifier|*
name|LHS
parameter_list|,
specifier|const
name|char
modifier|*
name|RHSString
parameter_list|,
name|TypeID
specifier|const
modifier|*
name|RHS
parameter_list|)
block|{
if|if
condition|(
operator|*
name|LHS
operator|==
operator|*
name|RHS
condition|)
return|return
name|true
return|;
name|std
operator|::
name|printf
argument_list|(
literal|"TypeID's not equal:\n"
argument_list|)
expr_stmt|;
name|std
operator|::
name|printf
argument_list|(
literal|"%s: %s\n----------\n%s: %s\n"
argument_list|,
name|LHSString
argument_list|,
name|LHS
operator|->
name|name
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|,
name|RHSString
argument_list|,
name|RHS
operator|->
name|name
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SUPPORT_TYPE_ID_H
end_comment

end_unit

