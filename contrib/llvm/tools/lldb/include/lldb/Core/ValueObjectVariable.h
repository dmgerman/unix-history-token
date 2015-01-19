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
file|"lldb/Core/ValueObject.h"
end_include

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
name|virtual
operator|~
name|ValueObjectVariable
argument_list|()
block|;
name|virtual
name|uint64_t
name|GetByteSize
argument_list|()
block|;
name|virtual
name|ConstString
name|GetTypeName
argument_list|()
block|;
name|virtual
name|ConstString
name|GetQualifiedTypeName
argument_list|()
block|;
name|virtual
name|ConstString
name|GetDisplayTypeName
argument_list|()
block|;
name|virtual
name|size_t
name|CalculateNumChildren
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|ValueType
name|GetValueType
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|IsInScope
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|ModuleSP
name|GetModule
argument_list|()
block|;
name|virtual
name|SymbolContextScope
operator|*
name|GetSymbolContextScope
argument_list|()
block|;
name|virtual
name|bool
name|GetDeclaration
argument_list|(
name|Declaration
operator|&
name|decl
argument_list|)
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetLocationAsCString
argument_list|()
block|;
name|virtual
name|bool
name|SetValueFromCString
argument_list|(
specifier|const
name|char
operator|*
name|value_str
argument_list|,
name|Error
operator|&
name|error
argument_list|)
block|;
name|virtual
name|bool
name|SetData
argument_list|(
name|DataExtractor
operator|&
name|data
argument_list|,
name|Error
operator|&
name|error
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|bool
name|UpdateValue
argument_list|()
block|;
name|virtual
name|ClangASTType
name|GetClangTypeImpl
argument_list|()
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
comment|///< The value that DWARFExpression resolves this variable to before we patch it up
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

