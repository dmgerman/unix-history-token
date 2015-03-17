begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBValueList.h -------------------------------------------*- C++ -*-===//
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
name|LLDB_SBValueList_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBValueList_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_decl_stmt
name|class
name|ValueListImpl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBValueList
block|{
name|public
label|:
name|SBValueList
argument_list|()
expr_stmt|;
name|SBValueList
argument_list|(
specifier|const
name|lldb
operator|::
name|SBValueList
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SBValueList
argument_list|()
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|void
name|Append
argument_list|(
specifier|const
name|lldb
operator|::
name|SBValue
operator|&
name|val_obj
argument_list|)
decl_stmt|;
name|void
name|Append
argument_list|(
specifier|const
name|lldb
operator|::
name|SBValueList
operator|&
name|value_list
argument_list|)
decl_stmt|;
name|uint32_t
name|GetSize
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|GetValueAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|GetFirstValueByName
argument_list|(
argument|const char* name
argument_list|)
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|FindValueObjectByUID
argument_list|(
argument|lldb::user_id_t uid
argument_list|)
expr_stmt|;
specifier|const
name|lldb
operator|::
name|SBValueList
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBValueList
operator|&
name|rhs
operator|)
expr_stmt|;
name|protected
label|:
comment|// only useful for visualizing the pointer or comparing two SBValueLists
comment|// to see if they are backed by the same underlying Impl.
name|void
modifier|*
name|opaque_ptr
parameter_list|()
function_decl|;
name|private
label|:
name|friend
name|class
name|SBFrame
decl_stmt|;
name|SBValueList
argument_list|(
specifier|const
name|ValueListImpl
operator|*
name|lldb_object_ptr
argument_list|)
expr_stmt|;
name|void
name|Append
argument_list|(
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|val_obj_sp
argument_list|)
decl_stmt|;
name|void
name|CreateIfNeeded
parameter_list|()
function_decl|;
name|ValueListImpl
operator|*
name|operator
operator|->
expr|(
block|)
decl_stmt|;
name|ValueListImpl
modifier|&
name|operator
modifier|*
parameter_list|()
function_decl|;
specifier|const
name|ValueListImpl
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|ValueListImpl
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|ValueListImpl
modifier|&
name|ref
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|ValueListImpl
operator|>
name|m_opaque_ap
expr_stmt|;
end_expr_stmt

begin_comment
unit|};   }
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBValueList_h_
end_comment

end_unit

