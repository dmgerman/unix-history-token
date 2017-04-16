begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCTargetOptions.h - MC Target Options --------------------*- C++ -*-===//
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
name|LLVM_MC_MCTARGETOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCTARGETOPTIONS_H
end_define

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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|enum
name|class
name|ExceptionHandling
block|{
name|None
operator|,
comment|/// No exception support
name|DwarfCFI
operator|,
comment|/// DWARF-like instruction based exceptions
name|SjLj
operator|,
comment|/// setjmp/longjmp based exceptions
name|ARM
operator|,
comment|/// ARM EHABI
name|WinEH
operator|,
comment|/// Windows Exception Handling
block|}
empty_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|MCTargetOptions
block|{
name|public
label|:
enum|enum
name|AsmInstrumentation
block|{
name|AsmInstrumentationNone
block|,
name|AsmInstrumentationAddress
block|}
enum|;
comment|/// Enables AddressSanitizer instrumentation at machine level.
name|bool
name|SanitizeAddress
range|:
literal|1
decl_stmt|;
name|bool
name|MCRelaxAll
range|:
literal|1
decl_stmt|;
name|bool
name|MCNoExecStack
range|:
literal|1
decl_stmt|;
name|bool
name|MCFatalWarnings
range|:
literal|1
decl_stmt|;
name|bool
name|MCNoWarn
range|:
literal|1
decl_stmt|;
name|bool
name|MCNoDeprecatedWarn
range|:
literal|1
decl_stmt|;
name|bool
name|MCSaveTempLabels
range|:
literal|1
decl_stmt|;
name|bool
name|MCUseDwarfDirectory
range|:
literal|1
decl_stmt|;
name|bool
name|MCIncrementalLinkerCompatible
range|:
literal|1
decl_stmt|;
name|bool
name|MCPIECopyRelocations
range|:
literal|1
decl_stmt|;
name|bool
name|ShowMCEncoding
range|:
literal|1
decl_stmt|;
name|bool
name|ShowMCInst
range|:
literal|1
decl_stmt|;
name|bool
name|AsmVerbose
range|:
literal|1
decl_stmt|;
comment|/// Preserve Comments in Assembly.
name|bool
name|PreserveAsmComments
range|:
literal|1
decl_stmt|;
name|int
name|DwarfVersion
init|=
literal|0
decl_stmt|;
name|std
operator|::
name|string
name|ABIName
expr_stmt|;
comment|/// Additional paths to search for `.include` directives when using the
comment|/// integrated assembler.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|IASSearchPaths
expr_stmt|;
name|MCTargetOptions
argument_list|()
expr_stmt|;
comment|/// getABIName - If this returns a non-empty string this represents the
comment|/// textual name of the ABI that we want the backend to use, e.g. o32, or
comment|/// aapcs-linux.
name|StringRef
name|getABIName
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_MCTARGETOPTIONS_H
end_comment

end_unit

