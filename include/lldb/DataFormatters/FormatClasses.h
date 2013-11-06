begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FormatClasses.h -----------------------------------------*- C++ -*-===//
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
name|lldb_FormatClasses_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_FormatClasses_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

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
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ValueObject.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/ScriptInterpreterPython.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/ClangASTType.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/Type.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/TypeFormat.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/TypeSummary.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/TypeSynthetic.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|TypeNameSpecifierImpl
block|{
name|public
label|:
name|TypeNameSpecifierImpl
argument_list|()
operator|:
name|m_is_regex
argument_list|(
name|false
argument_list|)
operator|,
name|m_type
argument_list|()
block|{     }
name|TypeNameSpecifierImpl
argument_list|(
argument|const char* name
argument_list|,
argument|bool is_regex
argument_list|)
operator|:
name|m_is_regex
argument_list|(
name|is_regex
argument_list|)
operator|,
name|m_type
argument_list|()
block|{
if|if
condition|(
name|name
condition|)
name|m_type
operator|.
name|m_type_name
operator|.
name|assign
argument_list|(
name|name
argument_list|)
expr_stmt|;
block|}
comment|// if constructing with a given type, is_regex cannot be true since we are
comment|// giving an exact type to match
name|TypeNameSpecifierImpl
argument_list|(
argument|lldb::TypeSP type
argument_list|)
block|:
name|m_is_regex
argument_list|(
name|false
argument_list|)
operator|,
name|m_type
argument_list|()
block|{
if|if
condition|(
name|type
condition|)
block|{
name|m_type
operator|.
name|m_type_name
operator|.
name|assign
argument_list|(
name|type
operator|->
name|GetName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
expr_stmt|;
name|m_type
operator|.
name|m_type_pair
operator|.
name|SetType
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
block|}
name|TypeNameSpecifierImpl
argument_list|(
argument|ClangASTType type
argument_list|)
operator|:
name|m_is_regex
argument_list|(
name|false
argument_list|)
operator|,
name|m_type
argument_list|()
block|{
if|if
condition|(
name|type
operator|.
name|IsValid
argument_list|()
condition|)
block|{
name|m_type
operator|.
name|m_type_name
operator|.
name|assign
argument_list|(
name|type
operator|.
name|GetConstTypeName
argument_list|()
operator|.
name|GetCString
argument_list|()
argument_list|)
expr_stmt|;
name|m_type
operator|.
name|m_type_pair
operator|.
name|SetType
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
block|}
specifier|const
name|char
operator|*
name|GetName
argument_list|()
block|{
if|if
condition|(
name|m_type
operator|.
name|m_type_name
operator|.
name|size
argument_list|()
condition|)
return|return
name|m_type
operator|.
name|m_type_name
operator|.
name|c_str
argument_list|()
return|;
return|return
name|NULL
return|;
block|}
name|lldb
operator|::
name|TypeSP
name|GetTypeSP
argument_list|()
block|{
if|if
condition|(
name|m_type
operator|.
name|m_type_pair
operator|.
name|IsValid
argument_list|()
condition|)
return|return
name|m_type
operator|.
name|m_type_pair
operator|.
name|GetTypeSP
argument_list|()
return|;
return|return
name|lldb
operator|::
name|TypeSP
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|ClangASTType
name|GetClangASTType
parameter_list|()
block|{
if|if
condition|(
name|m_type
operator|.
name|m_type_pair
operator|.
name|IsValid
argument_list|()
condition|)
return|return
name|m_type
operator|.
name|m_type_pair
operator|.
name|GetClangASTType
argument_list|()
return|;
return|return
name|ClangASTType
argument_list|()
return|;
block|}
end_function

begin_function
name|bool
name|IsRegex
parameter_list|()
block|{
return|return
name|m_is_regex
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|bool
name|m_is_regex
decl_stmt|;
end_decl_stmt

begin_comment
comment|// this works better than TypeAndOrName because the latter only wraps a TypeSP
end_comment

begin_comment
comment|// whereas TypePair can also be backed by a ClangASTType
end_comment

begin_struct
struct|struct
name|TypeOrName
block|{
name|std
operator|::
name|string
name|m_type_name
expr_stmt|;
name|TypePair
name|m_type_pair
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|TypeOrName
name|m_type
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TypeNameSpecifierImpl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};      }
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_FormatClasses_h_
end_comment

end_unit

