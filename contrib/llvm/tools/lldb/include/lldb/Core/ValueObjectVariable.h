begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ValueObjectVariable.h -----------------------------------*- C++ -*-===//
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
name|liblldb_ValueObjectVariable_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ValueObjectVariable_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/ValueObject.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Value.h"
end_include

begin_comment
comment|// for Value
end_comment

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerType.h"
end_include

begin_comment
comment|// for CompilerType
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_comment
comment|// for ConstString
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for DISALLOW_COPY_AND_ASSIGN
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for ValueType
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for VariableSP, ModuleSP, ValueObj...
end_comment

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
comment|// for uint32_t, uint64_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|DataExtractor
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Declaration
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Status
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ExecutionContextScope
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SymbolContextScope
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// A ValueObject that contains a root variable that may or may not
comment|// have children.
comment|//----------------------------------------------------------------------
name|class
name|ValueObjectVariable
range|:
name|public
name|ValueObject
block|{
name|public
operator|:
operator|~
name|ValueObjectVariable
argument_list|()
name|override
block|;
specifier|static
name|lldb
operator|::
name|ValueObjectSP
name|Create
argument_list|(
name|ExecutionContextScope
operator|*
name|exe_scope
argument_list|,
specifier|const
name|lldb
operator|::
name|VariableSP
operator|&
name|var_sp
argument_list|)
block|;
name|uint64_t
name|GetByteSize
argument_list|()
name|override
block|;
name|ConstString
name|GetTypeName
argument_list|()
name|override
block|;
name|ConstString
name|GetQualifiedTypeName
argument_list|()
name|override
block|;
name|ConstString
name|GetDisplayTypeName
argument_list|()
name|override
block|;
name|size_t
name|CalculateNumChildren
argument_list|(
argument|uint32_t max
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ValueType
name|GetValueType
argument_list|()
specifier|const
name|override
block|;
name|bool
name|IsInScope
argument_list|()
name|override
block|;
name|lldb
operator|::
name|ModuleSP
name|GetModule
argument_list|()
name|override
block|;
name|SymbolContextScope
operator|*
name|GetSymbolContextScope
argument_list|()
name|override
block|;
name|bool
name|GetDeclaration
argument_list|(
argument|Declaration&decl
argument_list|)
name|override
block|;
specifier|const
name|char
operator|*
name|GetLocationAsCString
argument_list|()
name|override
block|;
name|bool
name|SetValueFromCString
argument_list|(
argument|const char *value_str
argument_list|,
argument|Status&error
argument_list|)
name|override
block|;
name|bool
name|SetData
argument_list|(
argument|DataExtractor&data
argument_list|,
argument|Status&error
argument_list|)
name|override
block|;
name|virtual
name|lldb
operator|::
name|VariableSP
name|GetVariable
argument_list|()
name|override
block|{
return|return
name|m_variable_sp
return|;
block|}
name|protected
operator|:
name|bool
name|UpdateValue
argument_list|()
name|override
block|;
name|CompilerType
name|GetCompilerTypeImpl
argument_list|()
name|override
block|;
name|lldb
operator|::
name|VariableSP
name|m_variable_sp
block|;
comment|///< The variable that this value object is based upon
name|Value
name|m_resolved_value
block|;
comment|///< The value that DWARFExpression resolves this
comment|///variable to before we patch it up
name|private
operator|:
name|ValueObjectVariable
argument_list|(
name|ExecutionContextScope
operator|*
name|exe_scope
argument_list|,
specifier|const
name|lldb
operator|::
name|VariableSP
operator|&
name|var_sp
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// For ValueObject only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ValueObjectVariable
argument_list|)
block|; }
decl_stmt|;
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
comment|// liblldb_ValueObjectVariable_h_
end_comment

end_unit

