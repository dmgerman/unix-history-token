begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBHostOS.h ----------------------------------------------*- C++ -*-===//
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
name|LLDB_SBHostOS_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBHostOS_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBFileSpec.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBHostOS
block|{
name|public
label|:
specifier|static
name|lldb
operator|::
name|SBFileSpec
name|GetProgramFileSpec
argument_list|()
expr_stmt|;
specifier|static
name|lldb
operator|::
name|SBFileSpec
name|GetLLDBPythonPath
argument_list|()
expr_stmt|;
specifier|static
name|void
name|ThreadCreated
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
specifier|static
name|lldb
operator|::
name|thread_t
name|ThreadCreate
argument_list|(
argument|const char *name
argument_list|,
argument|thread_func_t thread_function
argument_list|,
argument|void *thread_arg
argument_list|,
argument|lldb::SBError *err
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|ThreadCancel
argument_list|(
name|lldb
operator|::
name|thread_t
name|thread
argument_list|,
name|lldb
operator|::
name|SBError
operator|*
name|err
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|ThreadDetach
argument_list|(
name|lldb
operator|::
name|thread_t
name|thread
argument_list|,
name|lldb
operator|::
name|SBError
operator|*
name|err
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|ThreadJoin
argument_list|(
name|lldb
operator|::
name|thread_t
name|thread
argument_list|,
name|thread_result_t
operator|*
name|result
argument_list|,
name|lldb
operator|::
name|SBError
operator|*
name|err
argument_list|)
decl_stmt|;
name|private
label|:
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBHostOS_h_
end_comment

end_unit

