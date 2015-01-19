begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CPPLanguageRuntime.h ---------------------------------------------------*- C++ -*-===//
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
name|liblldb_CPPLanguageRuntime_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CPPLanguageRuntime_h_
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
file|"lldb/Core/PluginInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/LanguageRuntime.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CPPLanguageRuntime
range|:
name|public
name|LanguageRuntime
block|{
name|public
operator|:
name|class
name|MethodName
block|{
name|public
operator|:
expr|enum
name|Type
block|{
name|eTypeInvalid
block|,
name|eTypeUnknownMethod
block|,
name|eTypeClassMethod
block|,
name|eTypeInstanceMethod
block|}
block|;
name|MethodName
argument_list|()
operator|:
name|m_full
argument_list|()
block|,
name|m_basename
argument_list|()
block|,
name|m_context
argument_list|()
block|,
name|m_arguments
argument_list|()
block|,
name|m_qualifiers
argument_list|()
block|,
name|m_type
argument_list|(
name|eTypeInvalid
argument_list|)
block|,
name|m_parsed
argument_list|(
name|false
argument_list|)
block|,
name|m_parse_error
argument_list|(
argument|false
argument_list|)
block|{         }
name|MethodName
argument_list|(
specifier|const
name|ConstString
operator|&
name|s
argument_list|)
operator|:
name|m_full
argument_list|(
name|s
argument_list|)
block|,
name|m_basename
argument_list|()
block|,
name|m_context
argument_list|()
block|,
name|m_arguments
argument_list|()
block|,
name|m_qualifiers
argument_list|()
block|,
name|m_type
argument_list|(
name|eTypeInvalid
argument_list|)
block|,
name|m_parsed
argument_list|(
name|false
argument_list|)
block|,
name|m_parse_error
argument_list|(
argument|false
argument_list|)
block|{         }
name|void
name|Clear
argument_list|()
block|;
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_parse_error
condition|)
return|return
name|false
return|;
if|if
condition|(
name|m_type
operator|==
name|eTypeInvalid
condition|)
return|return
name|false
return|;
return|return
operator|(
name|bool
operator|)
name|m_full
return|;
block|}
name|Type
name|GetType
argument_list|()
specifier|const
block|{
return|return
name|m_type
return|;
block|}
specifier|const
name|ConstString
operator|&
name|GetFullName
argument_list|()
specifier|const
block|{
return|return
name|m_full
return|;
block|}
name|llvm
operator|::
name|StringRef
name|GetBasename
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|GetContext
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|GetArguments
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|GetQualifiers
argument_list|()
expr_stmt|;
name|protected
label|:
name|void
name|Parse
parameter_list|()
function_decl|;
name|ConstString
name|m_full
decl_stmt|;
comment|// Full name:    "lldb::SBTarget::GetBreakpointAtIndex(unsigned int) const"
name|llvm
operator|::
name|StringRef
name|m_basename
expr_stmt|;
comment|// Basename:     "GetBreakpointAtIndex"
name|llvm
operator|::
name|StringRef
name|m_context
expr_stmt|;
comment|// Decl context: "lldb::SBTarget"
name|llvm
operator|::
name|StringRef
name|m_arguments
expr_stmt|;
comment|// Arguments:    "(unsigned int)"
name|llvm
operator|::
name|StringRef
name|m_qualifiers
expr_stmt|;
comment|// Qualifiers:   "const"
name|Type
name|m_type
decl_stmt|;
name|bool
name|m_parsed
decl_stmt|;
name|bool
name|m_parse_error
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|virtual
operator|~
name|CPPLanguageRuntime
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
name|lldb
operator|::
name|LanguageType
name|GetLanguageType
argument_list|()
specifier|const
block|{
return|return
name|lldb
operator|::
name|eLanguageTypeC_plus_plus
return|;
block|}
end_expr_stmt

begin_function_decl
name|virtual
name|bool
name|IsVTableName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|bool
name|GetObjectDescription
parameter_list|(
name|Stream
modifier|&
name|str
parameter_list|,
name|ValueObject
modifier|&
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|bool
name|GetObjectDescription
parameter_list|(
name|Stream
modifier|&
name|str
parameter_list|,
name|Value
modifier|&
name|value
parameter_list|,
name|ExecutionContextScope
modifier|*
name|exe_scope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bool
name|IsCPPMangledName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bool
name|StripNamespacesFromVariableName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
modifier|&
name|base_name_start
parameter_list|,
specifier|const
name|char
modifier|*
modifier|&
name|base_name_end
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// in some cases, compilers will output different names for one same type. when that happens, it might be impossible
end_comment

begin_comment
comment|// to construct SBType objects for a valid type, because the name that is available is not the same as the name that
end_comment

begin_comment
comment|// can be used as a search key in FindTypes(). the equivalents map here is meant to return possible alternative names
end_comment

begin_comment
comment|// for a type through which a search can be conducted. Currently, this is only enabled for C++ but can be extended
end_comment

begin_comment
comment|// to ObjC or other languages if necessary
end_comment

begin_decl_stmt
specifier|static
name|uint32_t
name|FindEquivalentNames
argument_list|(
name|ConstString
name|type_name
argument_list|,
name|std
operator|::
name|vector
operator|<
name|ConstString
operator|>
operator|&
name|equivalents
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Classes that inherit from CPPLanguageRuntime can see and modify these
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|CPPLanguageRuntime
argument_list|(
name|Process
operator|*
name|process
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|CPPLanguageRuntime
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_CPPLanguageRuntime_h_
end_comment

end_unit

