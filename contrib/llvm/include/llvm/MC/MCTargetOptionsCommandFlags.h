begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MCTargetOptionsCommandFlags.h --------------------------*- C++ -*-===//
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
comment|// This file contains machine code-specific flags that are shared between
end_comment

begin_comment
comment|// different command line tools.
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
name|LLVM_MC_MCTARGETOPTIONSCOMMANDFLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCTARGETOPTIONSCOMMANDFLAGS_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCTargetOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_decl_stmt
name|using
name|namespace
name|llvm
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|cl
operator|::
name|opt
operator|<
name|MCTargetOptions
operator|::
name|AsmInstrumentation
operator|>
name|AsmInstrumentation
argument_list|(
literal|"asm-instrumentation"
argument_list|,
name|cl
operator|::
name|desc
argument_list|(
literal|"Instrumentation of inline assembly and "
literal|"assembly source files"
argument_list|)
argument_list|,
name|cl
operator|::
name|init
argument_list|(
name|MCTargetOptions
operator|::
name|AsmInstrumentationNone
argument_list|)
argument_list|,
name|cl
operator|::
name|values
argument_list|(
name|clEnumValN
argument_list|(
name|MCTargetOptions
operator|::
name|AsmInstrumentationNone
argument_list|,
literal|"none"
argument_list|,
literal|"no instrumentation at all"
argument_list|)
argument_list|,
name|clEnumValN
argument_list|(
name|MCTargetOptions
operator|::
name|AsmInstrumentationAddress
argument_list|,
literal|"address"
argument_list|,
literal|"instrument instructions with memory arguments"
argument_list|)
argument_list|,
name|clEnumValEnd
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cl
operator|::
name|opt
operator|<
name|bool
operator|>
name|RelaxAll
argument_list|(
literal|"mc-relax-all"
argument_list|,
name|cl
operator|::
name|desc
argument_list|(
literal|"When used with filetype=obj, "
literal|"relax all fixups in the emitted object file"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cl
operator|::
name|opt
operator|<
name|bool
operator|>
name|IncrementalLinkerCompatible
argument_list|(
literal|"incremental-linker-compatible"
argument_list|,
name|cl
operator|::
name|desc
argument_list|(
literal|"When used with filetype=obj, "
literal|"emit an object file which can be used with an incremental linker"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cl
operator|::
name|opt
operator|<
name|int
operator|>
name|DwarfVersion
argument_list|(
literal|"dwarf-version"
argument_list|,
name|cl
operator|::
name|desc
argument_list|(
literal|"Dwarf version"
argument_list|)
argument_list|,
name|cl
operator|::
name|init
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cl
operator|::
name|opt
operator|<
name|bool
operator|>
name|ShowMCInst
argument_list|(
literal|"asm-show-inst"
argument_list|,
name|cl
operator|::
name|desc
argument_list|(
literal|"Emit internal instruction representation to "
literal|"assembly file"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cl
operator|::
name|opt
operator|<
name|bool
operator|>
name|FatalWarnings
argument_list|(
literal|"fatal-warnings"
argument_list|,
name|cl
operator|::
name|desc
argument_list|(
literal|"Treat warnings as errors"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cl
operator|::
name|opt
operator|<
name|bool
operator|>
name|NoWarn
argument_list|(
literal|"no-warn"
argument_list|,
name|cl
operator|::
name|desc
argument_list|(
literal|"Suppress all warnings"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cl
operator|::
name|alias
name|NoWarnW
argument_list|(
literal|"W"
argument_list|,
name|cl
operator|::
name|desc
argument_list|(
literal|"Alias for --no-warn"
argument_list|)
argument_list|,
name|cl
operator|::
name|aliasopt
argument_list|(
name|NoWarn
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cl
operator|::
name|opt
operator|<
name|std
operator|::
name|string
operator|>
name|ABIName
argument_list|(
literal|"target-abi"
argument_list|,
name|cl
operator|::
name|Hidden
argument_list|,
name|cl
operator|::
name|desc
argument_list|(
literal|"The name of the ABI to be targeted from the backend."
argument_list|)
argument_list|,
name|cl
operator|::
name|init
argument_list|(
literal|""
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
specifier|inline
name|MCTargetOptions
name|InitMCTargetOptionsFromFlags
parameter_list|()
block|{
name|MCTargetOptions
name|Options
decl_stmt|;
name|Options
operator|.
name|SanitizeAddress
operator|=
operator|(
name|AsmInstrumentation
operator|==
name|MCTargetOptions
operator|::
name|AsmInstrumentationAddress
operator|)
expr_stmt|;
name|Options
operator|.
name|MCRelaxAll
operator|=
name|RelaxAll
expr_stmt|;
name|Options
operator|.
name|MCIncrementalLinkerCompatible
operator|=
name|IncrementalLinkerCompatible
expr_stmt|;
name|Options
operator|.
name|DwarfVersion
operator|=
name|DwarfVersion
expr_stmt|;
name|Options
operator|.
name|ShowMCInst
operator|=
name|ShowMCInst
expr_stmt|;
name|Options
operator|.
name|ABIName
operator|=
name|ABIName
expr_stmt|;
name|Options
operator|.
name|MCFatalWarnings
operator|=
name|FatalWarnings
expr_stmt|;
name|Options
operator|.
name|MCNoWarn
operator|=
name|NoWarn
expr_stmt|;
return|return
name|Options
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

