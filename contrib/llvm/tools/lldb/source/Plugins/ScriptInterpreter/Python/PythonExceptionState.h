begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PythonExceptionState.h ----------------------------------*- C++ -*-===//
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
name|LLDB_PLUGINS_SCRIPTINTERPRETER_PYTHON_PYTHONEXCEPTIONSTATE_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_PLUGINS_SCRIPTINTERPRETER_PYTHON_PYTHONEXCEPTIONSTATE_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_DISABLE_PYTHON
end_ifndef

begin_include
include|#
directive|include
file|"PythonDataObjects.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|PythonExceptionState
block|{
name|public
label|:
name|explicit
name|PythonExceptionState
parameter_list|(
name|bool
name|restore_on_exit
parameter_list|)
function_decl|;
operator|~
name|PythonExceptionState
argument_list|()
expr_stmt|;
name|void
name|Acquire
parameter_list|(
name|bool
name|restore_on_exit
parameter_list|)
function_decl|;
name|void
name|Restore
parameter_list|()
function_decl|;
name|void
name|Discard
parameter_list|()
function_decl|;
name|void
name|Reset
parameter_list|()
function_decl|;
specifier|static
name|bool
name|HasErrorOccurred
parameter_list|()
function_decl|;
name|bool
name|IsError
argument_list|()
specifier|const
expr_stmt|;
name|PythonObject
name|GetType
argument_list|()
specifier|const
expr_stmt|;
name|PythonObject
name|GetValue
argument_list|()
specifier|const
expr_stmt|;
name|PythonObject
name|GetTraceback
argument_list|()
specifier|const
expr_stmt|;
name|std
operator|::
name|string
name|Format
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|std
operator|::
name|string
name|ReadBacktrace
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|m_restore_on_exit
decl_stmt|;
name|PythonObject
name|m_type
decl_stmt|;
name|PythonObject
name|m_value
decl_stmt|;
name|PythonObject
name|m_traceback
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

