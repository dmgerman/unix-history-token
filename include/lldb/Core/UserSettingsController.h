begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//====-- UserSettingsController.h --------------------------------*- C++-*-===//
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
name|liblldb_UserSettingsController_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_UserSettingsController_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/Error.h"
end_include

begin_comment
comment|// for Error
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for OptionValuePropertiesSP
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private-enumerations.h"
end_include

begin_comment
comment|// for VarSetOperationType
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// for StringRef
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

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint32_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CommandInterpreter
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ConstString
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ExecutionContext
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Property
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Properties
block|{
name|public
label|:
name|Properties
argument_list|()
operator|:
name|m_collection_sp
argument_list|()
block|{}
name|Properties
argument_list|(
specifier|const
name|lldb
operator|::
name|OptionValuePropertiesSP
operator|&
name|collection_sp
argument_list|)
operator|:
name|m_collection_sp
argument_list|(
argument|collection_sp
argument_list|)
block|{}
name|virtual
operator|~
name|Properties
argument_list|()
block|{}
name|virtual
name|lldb
operator|::
name|OptionValuePropertiesSP
name|GetValueProperties
argument_list|()
specifier|const
block|{
comment|// This function is virtual in case subclasses want to lazily
comment|// implement creating the properties.
return|return
name|m_collection_sp
return|;
block|}
name|virtual
name|lldb
operator|::
name|OptionValueSP
name|GetPropertyValue
argument_list|(
argument|const ExecutionContext *exe_ctx
argument_list|,
argument|llvm::StringRef property_path
argument_list|,
argument|bool will_modify
argument_list|,
argument|Error&error
argument_list|)
specifier|const
expr_stmt|;
name|virtual
name|Error
name|SetPropertyValue
argument_list|(
specifier|const
name|ExecutionContext
operator|*
name|exe_ctx
argument_list|,
name|VarSetOperationType
name|op
argument_list|,
name|llvm
operator|::
name|StringRef
name|property_path
argument_list|,
name|llvm
operator|::
name|StringRef
name|value
argument_list|)
decl_stmt|;
name|virtual
name|Error
name|DumpPropertyValue
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
name|llvm
operator|::
name|StringRef
name|property_path
argument_list|,
name|uint32_t
name|dump_mask
argument_list|)
decl_stmt|;
name|virtual
name|void
name|DumpAllPropertyValues
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
name|void
name|DumpAllDescriptions
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|,
name|Stream
operator|&
name|strm
argument_list|)
decl|const
decl_stmt|;
name|size_t
name|Apropos
argument_list|(
name|llvm
operator|::
name|StringRef
name|keyword
argument_list|,
name|std
operator|::
name|vector
operator|<
specifier|const
name|Property
operator|*
operator|>
operator|&
name|matching_properties
argument_list|)
decl|const
decl_stmt|;
name|lldb
operator|::
name|OptionValuePropertiesSP
name|GetSubProperty
argument_list|(
specifier|const
name|ExecutionContext
operator|*
name|exe_ctx
argument_list|,
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
expr_stmt|;
comment|// We sometimes need to introduce a setting to enable experimental features,
comment|// but then we don't want the setting for these to cause errors when the
comment|// setting
comment|// goes away.  Add a sub-topic of the settings using this experimental name,
comment|// and
comment|// two things will happen.  One is that settings that don't find the name will
comment|// not
comment|// be treated as errors.  Also, if you decide to keep the settings just move
comment|// them into
comment|// the containing properties, and we will auto-forward the experimental
comment|// settings to the
comment|// real one.
specifier|static
specifier|const
name|char
modifier|*
name|GetExperimentalSettingsName
parameter_list|()
function_decl|;
specifier|static
name|bool
name|IsSettingExperimental
argument_list|(
name|llvm
operator|::
name|StringRef
name|setting
argument_list|)
decl_stmt|;
name|protected
label|:
name|lldb
operator|::
name|OptionValuePropertiesSP
name|m_collection_sp
expr_stmt|;
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
comment|// liblldb_UserSettingsController_h_
end_comment

end_unit

