begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DynamicRegisterInfo.h -----------------------------------*- C++ -*-===//
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
name|lldb_DynamicRegisterInfo_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_DynamicRegisterInfo_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ConstString.h"
end_include

begin_decl_stmt
name|class
name|DynamicRegisterInfo
block|{
name|public
label|:
name|DynamicRegisterInfo
argument_list|()
expr_stmt|;
name|DynamicRegisterInfo
argument_list|(
specifier|const
name|lldb_private
operator|::
name|PythonDictionary
operator|&
name|dict
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|DynamicRegisterInfo
argument_list|()
expr_stmt|;
name|size_t
name|SetRegisterInfo
argument_list|(
specifier|const
name|lldb_private
operator|::
name|PythonDictionary
operator|&
name|dict
argument_list|)
decl_stmt|;
name|void
name|AddRegister
argument_list|(
name|lldb_private
operator|::
name|RegisterInfo
operator|&
name|reg_info
argument_list|,
name|lldb_private
operator|::
name|ConstString
operator|&
name|reg_name
argument_list|,
name|lldb_private
operator|::
name|ConstString
operator|&
name|reg_alt_name
argument_list|,
name|lldb_private
operator|::
name|ConstString
operator|&
name|set_name
argument_list|)
decl_stmt|;
name|void
name|Finalize
parameter_list|()
function_decl|;
name|size_t
name|GetNumRegisters
argument_list|()
specifier|const
expr_stmt|;
name|size_t
name|GetNumRegisterSets
argument_list|()
specifier|const
expr_stmt|;
name|size_t
name|GetRegisterDataByteSize
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfoAtIndex
argument_list|(
argument|uint32_t i
argument_list|)
specifier|const
expr_stmt|;
specifier|const
name|lldb_private
operator|::
name|RegisterSet
operator|*
name|GetRegisterSet
argument_list|(
argument|uint32_t i
argument_list|)
specifier|const
expr_stmt|;
name|uint32_t
name|GetRegisterSetIndexByName
argument_list|(
name|lldb_private
operator|::
name|ConstString
operator|&
name|set_name
argument_list|,
name|bool
name|can_create
argument_list|)
decl_stmt|;
name|uint32_t
name|ConvertRegisterKindToRegisterNumber
argument_list|(
name|uint32_t
name|kind
argument_list|,
name|uint32_t
name|num
argument_list|)
decl|const
decl_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from DynamicRegisterInfo can see and modify these
comment|//------------------------------------------------------------------
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|RegisterInfo
operator|>
name|reg_collection
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|RegisterSet
operator|>
name|set_collection
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|reg_num_collection
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|reg_num_collection
operator|>
name|set_reg_num_collection
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|ConstString
operator|>
name|name_collection
expr_stmt|;
name|reg_collection
name|m_regs
decl_stmt|;
name|set_collection
name|m_sets
decl_stmt|;
name|set_reg_num_collection
name|m_set_reg_nums
decl_stmt|;
name|name_collection
name|m_set_names
decl_stmt|;
name|size_t
name|m_reg_data_byte_size
decl_stmt|;
comment|// The number of bytes required to store all registers
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
comment|// lldb_DynamicRegisterInfo_h_
end_comment

end_unit

