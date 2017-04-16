begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GoFormatterFunctions.h-----------------------------------*- C++ -*-===//
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
name|liblldb_GoFormatterFunctions_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_GoFormatterFunctions_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/FormatClasses.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/TypeSynthetic.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ObjCLanguageRuntime.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Target.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|formatters
block|{
name|bool
name|GoStringSummaryProvider
parameter_list|(
name|ValueObject
modifier|&
name|valobj
parameter_list|,
name|Stream
modifier|&
name|stream
parameter_list|,
specifier|const
name|TypeSummaryOptions
modifier|&
name|options
parameter_list|)
function_decl|;
name|SyntheticChildrenFrontEnd
modifier|*
name|GoSliceSyntheticFrontEndCreator
argument_list|(
name|CXXSyntheticChildren
operator|*
argument_list|,
name|lldb
operator|::
name|ValueObjectSP
argument_list|)
decl_stmt|;
block|}
comment|// namespace formatters
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
comment|// liblldb_GoFormatterFunctions_h_
end_comment

end_unit

