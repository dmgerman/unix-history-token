begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- REPL.h --------------------------------------------------*- C++ -*-===//
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
name|lldb_REPL_h
end_ifndef

begin_define
define|#
directive|define
name|lldb_REPL_h
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<string>
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
file|"lldb/../../source/Commands/CommandObjectExpression.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/OptionGroupFormat.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/OptionGroupValueObjectDisplay.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|REPL
range|:
name|public
name|IOHandlerDelegate
block|{
name|public
operator|:
comment|//----------------------------------------------------------------------
comment|// See TypeSystem.h for how to add subclasses to this.
comment|//----------------------------------------------------------------------
expr|enum
name|LLVMCastKind
block|{
name|eKindClang
block|,
name|eKindSwift
block|,
name|eKindGo
block|,
name|kNumKinds
block|}
block|;
name|LLVMCastKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|m_kind
return|;
block|}
name|REPL
argument_list|(
argument|LLVMCastKind kind
argument_list|,
argument|Target&target
argument_list|)
block|;
operator|~
name|REPL
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Get a REPL with an existing target (or, failing that, a debugger to use),
comment|/// and (optional) extra arguments for the compiler.
comment|///
comment|/// @param[out] error
comment|///     If this language is supported but the REPL couldn't be created, this
comment|///     error is populated with the reason.
comment|///
comment|/// @param[in] language
comment|///     The language to create a REPL for.
comment|///
comment|/// @param[in] debugger
comment|///     If provided, and target is nullptr, the debugger to use when setting
comment|///     up a top-level REPL.
comment|///
comment|/// @param[in] target
comment|///     If provided, the target to put the REPL inside.
comment|///
comment|/// @param[in] repl_options
comment|///     If provided, additional options for the compiler when parsing REPL
comment|///     expressions.
comment|///
comment|/// @return
comment|///     The range of the containing object in the target process.
comment|//------------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|REPLSP
name|Create
argument_list|(
argument|Status&Status
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|Debugger *debugger
argument_list|,
argument|Target *target
argument_list|,
argument|const char *repl_options
argument_list|)
block|;
name|void
name|SetFormatOptions
argument_list|(
argument|const OptionGroupFormat&options
argument_list|)
block|{
name|m_format_options
operator|=
name|options
block|;   }
name|void
name|SetValueObjectDisplayOptions
argument_list|(
argument|const OptionGroupValueObjectDisplay&options
argument_list|)
block|{
name|m_varobj_options
operator|=
name|options
block|;   }
name|void
name|SetCommandOptions
argument_list|(
argument|const CommandObjectExpression::CommandOptions&options
argument_list|)
block|{
name|m_command_options
operator|=
name|options
block|;   }
name|void
name|SetCompilerOptions
argument_list|(
argument|const char *options
argument_list|)
block|{
if|if
condition|(
name|options
condition|)
name|m_compiler_options
operator|=
name|options
expr_stmt|;
block|}
name|lldb
operator|::
name|IOHandlerSP
name|GetIOHandler
argument_list|()
block|;
name|Status
name|RunLoop
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// IOHandler::Delegate functions
comment|//------------------------------------------------------------------
name|void
name|IOHandlerActivated
argument_list|(
argument|IOHandler&io_handler
argument_list|)
name|override
block|;
name|bool
name|IOHandlerInterrupt
argument_list|(
argument|IOHandler&io_handler
argument_list|)
name|override
block|;
name|void
name|IOHandlerInputInterrupted
argument_list|(
argument|IOHandler&io_handler
argument_list|,
argument|std::string&line
argument_list|)
name|override
block|;
specifier|const
name|char
operator|*
name|IOHandlerGetFixIndentationCharacters
argument_list|()
name|override
block|;
name|ConstString
name|IOHandlerGetControlSequence
argument_list|(
argument|char ch
argument_list|)
name|override
block|;
specifier|const
name|char
operator|*
name|IOHandlerGetCommandPrefix
argument_list|()
name|override
block|;
specifier|const
name|char
operator|*
name|IOHandlerGetHelpPrologue
argument_list|()
name|override
block|;
name|bool
name|IOHandlerIsInputComplete
argument_list|(
argument|IOHandler&io_handler
argument_list|,
argument|StringList&lines
argument_list|)
name|override
block|;
name|int
name|IOHandlerFixIndentation
argument_list|(
argument|IOHandler&io_handler
argument_list|,
argument|const StringList&lines
argument_list|,
argument|int cursor_position
argument_list|)
name|override
block|;
name|void
name|IOHandlerInputComplete
argument_list|(
argument|IOHandler&io_handler
argument_list|,
argument|std::string&line
argument_list|)
name|override
block|;
name|int
name|IOHandlerComplete
argument_list|(
argument|IOHandler&io_handler
argument_list|,
argument|const char *current_line
argument_list|,
argument|const char *cursor
argument_list|,
argument|const char *last_char
argument_list|,
argument|int skip_first_n_matches
argument_list|,
argument|int max_matches
argument_list|,
argument|StringList&matches
argument_list|)
name|override
block|;
name|protected
operator|:
specifier|static
name|int
name|CalculateActualIndentation
argument_list|(
specifier|const
name|StringList
operator|&
name|lines
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|// Subclasses should override these functions to implement a functional REPL.
comment|//----------------------------------------------------------------------
name|virtual
name|Status
name|DoInitialization
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|ConstString
name|GetSourceFileBasename
argument_list|()
operator|=
literal|0
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetAutoIndentCharacters
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|SourceIsComplete
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|source
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|offset_t
name|GetDesiredIndentation
argument_list|(
argument|const StringList&lines
argument_list|,
argument|int cursor_position
argument_list|,
argument|int tab_size
argument_list|)
operator|=
literal|0
block|;
comment|// LLDB_INVALID_OFFSET means no change
name|virtual
name|lldb
operator|::
name|LanguageType
name|GetLanguage
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|PrintOneVariable
argument_list|(
name|Debugger
operator|&
name|debugger
argument_list|,
name|lldb
operator|::
name|StreamFileSP
operator|&
name|output_sp
argument_list|,
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|valobj_sp
argument_list|,
name|ExpressionVariable
operator|*
name|var
operator|=
name|nullptr
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|CompleteCode
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|current_code
argument_list|,
name|StringList
operator|&
name|matches
argument_list|)
operator|=
literal|0
block|;
name|OptionGroupFormat
name|m_format_options
operator|=
name|OptionGroupFormat
argument_list|(
name|lldb
operator|::
name|eFormatDefault
argument_list|)
block|;
name|OptionGroupValueObjectDisplay
name|m_varobj_options
block|;
name|CommandObjectExpression
operator|::
name|CommandOptions
name|m_command_options
block|;
name|std
operator|::
name|string
name|m_compiler_options
block|;
name|bool
name|m_enable_auto_indent
operator|=
name|true
block|;
name|std
operator|::
name|string
name|m_indent_str
block|;
comment|// Use this string for each level of indentation
name|std
operator|::
name|string
name|m_current_indent_str
block|;
name|uint32_t
name|m_current_indent_level
operator|=
literal|0
block|;
name|std
operator|::
name|string
name|m_repl_source_path
block|;
name|bool
name|m_dedicated_repl_mode
operator|=
name|false
block|;
name|StringList
name|m_code
block|;
comment|// All accumulated REPL statements are saved here
name|Target
operator|&
name|m_target
block|;
name|lldb
operator|::
name|IOHandlerSP
name|m_io_handler_sp
block|;
name|LLVMCastKind
name|m_kind
block|;
name|private
operator|:
name|std
operator|::
name|string
name|GetSourcePath
argument_list|()
block|; }
decl_stmt|;
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
comment|// lldb_REPL_h
end_comment

end_unit

