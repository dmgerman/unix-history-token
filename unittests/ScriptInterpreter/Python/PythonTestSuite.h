begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PythonTestSuite.cpp -------------------------------------*- C++ -*-===//
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

begin_include
include|#
directive|include
file|"gtest/gtest.h"
end_include

begin_decl_stmt
name|using
name|namespace
name|lldb_private
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|PythonTestSuite
range|:
name|public
name|testing
operator|::
name|Test
block|{
name|public
operator|:
name|void
name|SetUp
argument_list|()
name|override
block|;
name|void
name|TearDown
argument_list|()
name|override
block|;
name|private
operator|:
name|PyGILState_STATE
name|m_gil_state
block|; }
decl_stmt|;
end_decl_stmt

end_unit

