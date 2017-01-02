begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBVariablesOptions.h ------------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|LLDB_SBVariablesOptions_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBVariablesOptions_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_decl_stmt
name|class
name|VariablesOptionsImpl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|LLDB_API
name|SBVariablesOptions
block|{
name|public
label|:
name|SBVariablesOptions
argument_list|()
expr_stmt|;
name|SBVariablesOptions
argument_list|(
specifier|const
name|SBVariablesOptions
operator|&
name|options
argument_list|)
expr_stmt|;
name|SBVariablesOptions
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SBVariablesOptions
operator|&
name|options
operator|)
decl_stmt|;
operator|~
name|SBVariablesOptions
argument_list|()
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|GetIncludeArguments
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetIncludeArguments
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|bool
name|GetIncludeLocals
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetIncludeLocals
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|bool
name|GetIncludeStatics
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetIncludeStatics
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|bool
name|GetInScopeOnly
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetInScopeOnly
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|bool
name|GetIncludeRuntimeSupportValues
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetIncludeRuntimeSupportValues
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|lldb
operator|::
name|DynamicValueType
name|GetUseDynamic
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetUseDynamic
argument_list|(
name|lldb
operator|::
name|DynamicValueType
argument_list|)
decl_stmt|;
name|protected
label|:
name|VariablesOptionsImpl
operator|*
name|operator
operator|->
expr|(
block|)
decl_stmt|;
specifier|const
name|VariablesOptionsImpl
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|VariablesOptionsImpl
modifier|*
name|get
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|VariablesOptionsImpl
modifier|&
name|ref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|VariablesOptionsImpl
modifier|&
name|ref
parameter_list|()
function_decl|const;
end_function_decl

begin_expr_stmt
name|SBVariablesOptions
argument_list|(
name|VariablesOptionsImpl
operator|*
name|lldb_object_ptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|SetOptions
parameter_list|(
name|VariablesOptionsImpl
modifier|*
name|lldb_object_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|VariablesOptionsImpl
operator|>
name|m_opaque_ap
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBValue_h_
end_comment

end_unit

