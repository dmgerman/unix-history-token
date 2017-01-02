begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DarwinLogInterfaces.h -----------------------------------*- C++ -*-===//
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
name|DarwinLogInterfaces_h
end_ifndef

begin_define
define|#
directive|define
name|DarwinLogInterfaces_h
end_define

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|class
name|ActivityStore
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|LogFilter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|using
name|LogFilterSP
init|=
name|std
operator|::
name|shared_ptr
operator|<
name|LogFilter
operator|>
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|LogFilterChain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|using
name|LogFilterChainSP
init|=
name|std
operator|::
name|shared_ptr
operator|<
name|LogFilterChain
operator|>
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|LogMessage
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DarwinLogInterfaces_h */
end_comment

end_unit

