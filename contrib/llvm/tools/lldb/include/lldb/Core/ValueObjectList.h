begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ValueObjectList.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_ValueObjectList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ValueObjectList_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for ValueObjectSP
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_comment
comment|// for user_id_t
end_comment

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ValueObject
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// A collection of ValueObject values that
comment|//----------------------------------------------------------------------
name|class
name|ValueObjectList
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|ValueObjectList
argument_list|()
expr_stmt|;
name|ValueObjectList
argument_list|(
specifier|const
name|ValueObjectList
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|ValueObjectList
argument_list|()
expr_stmt|;
specifier|const
name|ValueObjectList
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ValueObjectList
operator|&
name|rhs
operator|)
decl_stmt|;
name|void
name|Append
argument_list|(
specifier|const
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|val_obj_sp
argument_list|)
decl_stmt|;
name|void
name|Append
parameter_list|(
specifier|const
name|ValueObjectList
modifier|&
name|valobj_list
parameter_list|)
function_decl|;
name|lldb
operator|::
name|ValueObjectSP
name|FindValueObjectByPointer
argument_list|(
name|ValueObject
operator|*
name|valobj
argument_list|)
expr_stmt|;
name|size_t
name|GetSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Resize
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
name|lldb
operator|::
name|ValueObjectSP
name|GetValueObjectAtIndex
argument_list|(
argument|size_t idx
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|ValueObjectSP
name|RemoveValueObjectAtIndex
argument_list|(
argument|size_t idx
argument_list|)
expr_stmt|;
name|void
name|SetValueObjectAtIndex
argument_list|(
name|size_t
name|idx
argument_list|,
specifier|const
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|valobj_sp
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|ValueObjectSP
name|FindValueObjectByValueName
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|ValueObjectSP
name|FindValueObjectByUID
argument_list|(
argument|lldb::user_id_t uid
argument_list|)
expr_stmt|;
name|void
name|Swap
parameter_list|(
name|ValueObjectList
modifier|&
name|value_object_list
parameter_list|)
function_decl|;
name|void
name|Clear
parameter_list|()
block|{
name|m_value_objects
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|ValueObjectSP
operator|>
operator|&
name|GetObjects
argument_list|()
specifier|const
block|{
return|return
name|m_value_objects
return|;
block|}
name|protected
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|ValueObjectSP
operator|>
name|collection
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Classes that inherit from ValueObjectList can see and modify these
comment|//------------------------------------------------------------------
name|collection
name|m_value_objects
decl_stmt|;
block|}
empty_stmt|;
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
comment|// liblldb_ValueObjectList_h_
end_comment

end_unit

