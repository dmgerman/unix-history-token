begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Property.h ----------------------------------------------*- C++ -*-===//
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
name|liblldb_Property_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Property_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Interpreter/OptionValue.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Flags.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-types.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// A structure that can be used to create a global table for all properties.
comment|// Property class instances can be constructed using one of these.
struct|struct
name|PropertyDefinition
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|OptionValue
operator|::
name|Type
name|type
expr_stmt|;
name|bool
name|global
decl_stmt|;
comment|// false == this setting is a global setting by default
name|uintptr_t
name|default_uint_value
decl_stmt|;
specifier|const
name|char
modifier|*
name|default_cstr_value
decl_stmt|;
name|OptionEnumValueElement
modifier|*
name|enum_values
decl_stmt|;
specifier|const
name|char
modifier|*
name|description
decl_stmt|;
block|}
struct|;
name|class
name|Property
block|{
name|public
label|:
name|Property
argument_list|(
specifier|const
name|PropertyDefinition
operator|&
name|definition
argument_list|)
expr_stmt|;
name|Property
argument_list|(
argument|const ConstString&name
argument_list|,
argument|const ConstString&desc
argument_list|,
argument|bool is_global
argument_list|,
argument|const lldb::OptionValueSP&value_sp
argument_list|)
empty_stmt|;
name|llvm
operator|::
name|StringRef
name|GetName
argument_list|()
specifier|const
block|{
return|return
name|m_name
operator|.
name|GetStringRef
argument_list|()
return|;
block|}
name|llvm
operator|::
name|StringRef
name|GetDescription
argument_list|()
specifier|const
block|{
return|return
name|m_description
operator|.
name|GetStringRef
argument_list|()
return|;
block|}
specifier|const
name|lldb
operator|::
name|OptionValueSP
operator|&
name|GetValue
argument_list|()
specifier|const
block|{
return|return
name|m_value_sp
return|;
block|}
name|void
name|SetOptionValue
argument_list|(
specifier|const
name|lldb
operator|::
name|OptionValueSP
operator|&
name|value_sp
argument_list|)
block|{
name|m_value_sp
operator|=
name|value_sp
expr_stmt|;
block|}
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
operator|(
name|bool
operator|)
name|m_value_sp
return|;
block|}
name|bool
name|IsGlobal
argument_list|()
specifier|const
block|{
return|return
name|m_is_global
return|;
block|}
name|void
name|Dump
argument_list|(
specifier|const
name|ExecutionContext
operator|*
name|exe_ctx
argument_list|,
name|Stream
operator|&
name|strm
argument_list|,
name|uint32_t
name|dump_mask
argument_list|)
decl|const
decl_stmt|;
name|bool
name|DumpQualifiedName
argument_list|(
name|Stream
operator|&
name|strm
argument_list|)
decl|const
decl_stmt|;
name|void
name|DumpDescription
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|,
name|Stream
operator|&
name|strm
argument_list|,
name|uint32_t
name|output_width
argument_list|,
name|bool
name|display_qualified_name
argument_list|)
decl|const
decl_stmt|;
name|void
name|SetValueChangedCallback
parameter_list|(
name|OptionValueChangedCallback
name|callback
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
name|protected
label|:
name|ConstString
name|m_name
decl_stmt|;
name|ConstString
name|m_description
decl_stmt|;
name|lldb
operator|::
name|OptionValueSP
name|m_value_sp
expr_stmt|;
name|bool
name|m_is_global
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
comment|// liblldb_Property_h_
end_comment

end_unit

