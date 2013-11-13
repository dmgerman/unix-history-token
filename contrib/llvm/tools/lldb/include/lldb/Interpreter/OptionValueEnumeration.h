begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionValueEnumeration.h --------------------------------*- C++ -*-===//
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
name|liblldb_OptionValueEnumeration_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionValueEnumeration_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Stream.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StreamString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/UniqueCStringMap.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/OptionValue.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|OptionValueEnumeration
range|:
name|public
name|OptionValue
block|{
name|public
operator|:
typedef|typedef
name|int64_t
name|enum_type
typedef|;
block|struct
name|EnumeratorInfo
block|{
name|enum_type
name|value
block|;
specifier|const
name|char
operator|*
name|description
block|;     }
decl_stmt|;
typedef|typedef
name|UniqueCStringMap
operator|<
name|EnumeratorInfo
operator|>
name|EnumerationMap
expr_stmt|;
typedef|typedef
name|EnumerationMap
operator|::
name|Entry
name|EnumerationMapEntry
expr_stmt|;
name|OptionValueEnumeration
argument_list|(
argument|const OptionEnumValueElement *enumerators
argument_list|,
argument|enum_type value
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|OptionValueEnumeration
argument_list|()
expr_stmt|;
comment|//---------------------------------------------------------------------
comment|// Virtual subclass pure virtual overrides
comment|//---------------------------------------------------------------------
name|virtual
name|OptionValue
operator|::
name|Type
name|GetType
argument_list|()
specifier|const
block|{
return|return
name|eTypeEnum
return|;
block|}
name|virtual
name|void
name|DumpValue
parameter_list|(
specifier|const
name|ExecutionContext
modifier|*
name|exe_ctx
parameter_list|,
name|Stream
modifier|&
name|strm
parameter_list|,
name|uint32_t
name|dump_mask
parameter_list|)
function_decl|;
name|virtual
name|Error
name|SetValueFromCString
parameter_list|(
specifier|const
name|char
modifier|*
name|value
parameter_list|,
name|VarSetOperationType
name|op
init|=
name|eVarSetOperationAssign
parameter_list|)
function_decl|;
name|virtual
name|bool
name|Clear
parameter_list|()
block|{
name|m_current_value
operator|=
name|m_default_value
expr_stmt|;
name|m_value_was_set
operator|=
name|false
expr_stmt|;
return|return
name|true
return|;
block|}
name|virtual
name|lldb
operator|::
name|OptionValueSP
name|DeepCopy
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|size_t
name|AutoComplete
parameter_list|(
name|CommandInterpreter
modifier|&
name|interpreter
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|match_start_point
parameter_list|,
name|int
name|max_return_elements
parameter_list|,
name|bool
modifier|&
name|word_complete
parameter_list|,
name|StringList
modifier|&
name|matches
parameter_list|)
function_decl|;
comment|//---------------------------------------------------------------------
comment|// Subclass specific functions
comment|//---------------------------------------------------------------------
name|enum_type
name|operator
init|=
operator|(
name|enum_type
name|value
operator|)
block|{
name|m_current_value
operator|=
name|value
block|;
return|return
name|m_current_value
return|;
block|}
name|enum_type
name|GetCurrentValue
argument_list|()
specifier|const
block|{
return|return
name|m_current_value
return|;
block|}
name|enum_type
name|GetDefaultValue
argument_list|()
specifier|const
block|{
return|return
name|m_default_value
return|;
block|}
name|void
name|SetCurrentValue
parameter_list|(
name|enum_type
name|value
parameter_list|)
block|{
name|m_current_value
operator|=
name|value
expr_stmt|;
block|}
name|void
name|SetDefaultValue
parameter_list|(
name|enum_type
name|value
parameter_list|)
block|{
name|m_default_value
operator|=
name|value
expr_stmt|;
block|}
name|protected
label|:
name|void
name|SetEnumerations
parameter_list|(
specifier|const
name|OptionEnumValueElement
modifier|*
name|enumerators
parameter_list|)
function_decl|;
name|enum_type
name|m_current_value
decl_stmt|;
name|enum_type
name|m_default_value
decl_stmt|;
name|EnumerationMap
name|m_enumerations
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_OptionValueEnumeration_h_
end_comment

end_unit

