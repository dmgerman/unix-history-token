begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/DebugInfo/Symbolize/DIPrinter.h ---------------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file declares the DIPrinter class, which is responsible for printing
end_comment

begin_comment
comment|// structures defined in DebugInfo/DIContext.h
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
name|LLVM_DEBUGINFO_SYMBOLIZE_DIPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_SYMBOLIZE_DIPRINTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct_decl|struct
name|DILineInfo
struct_decl|;
name|class
name|DIInliningInfo
decl_stmt|;
struct_decl|struct
name|DIGlobal
struct_decl|;
name|namespace
name|symbolize
block|{
name|class
name|DIPrinter
block|{
name|raw_ostream
modifier|&
name|OS
decl_stmt|;
name|bool
name|PrintFunctionNames
decl_stmt|;
name|bool
name|PrintPretty
decl_stmt|;
name|int
name|PrintSourceContext
decl_stmt|;
name|bool
name|Verbose
decl_stmt|;
name|void
name|print
parameter_list|(
specifier|const
name|DILineInfo
modifier|&
name|Info
parameter_list|,
name|bool
name|Inlined
parameter_list|)
function_decl|;
name|void
name|printContext
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|FileName
argument_list|,
name|int64_t
name|Line
argument_list|)
decl_stmt|;
name|public
label|:
name|DIPrinter
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|bool PrintFunctionNames = true
argument_list|,
argument|bool PrintPretty = false
argument_list|,
argument|int PrintSourceContext =
literal|0
argument_list|,
argument|bool Verbose = false
argument_list|)
block|:
name|OS
argument_list|(
name|OS
argument_list|)
operator|,
name|PrintFunctionNames
argument_list|(
name|PrintFunctionNames
argument_list|)
operator|,
name|PrintPretty
argument_list|(
name|PrintPretty
argument_list|)
operator|,
name|PrintSourceContext
argument_list|(
name|PrintSourceContext
argument_list|)
operator|,
name|Verbose
argument_list|(
argument|Verbose
argument_list|)
block|{}
name|DIPrinter
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DILineInfo
operator|&
name|Info
operator|)
expr_stmt|;
name|DIPrinter
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DIInliningInfo
operator|&
name|Info
operator|)
expr_stmt|;
name|DIPrinter
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DIGlobal
operator|&
name|Global
operator|)
expr_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

