begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- RAIIObjectsForParser.h - RAII helpers for the parser ---*- C++ -*-===//
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
comment|// This file defines and implements the some simple RAII objects that are used
end_comment

begin_comment
comment|// by the parser to manage bits in recursion.
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
name|LLVM_CLANG_PARSE_RAII_OBJECTS_FOR_PARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_PARSE_RAII_OBJECTS_FOR_PARSER_H
end_define

begin_include
include|#
directive|include
file|"clang/Parse/ParseDiagnostic.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|// TODO: move ParsingDeclRAIIObject here.
comment|// TODO: move ParsingClassDefinition here.
comment|// TODO: move TentativeParsingAction here.
comment|/// ExtensionRAIIObject - This saves the state of extension warnings when
comment|/// constructed and disables them.  When destructed, it restores them back to
comment|/// the way they used to be.  This is used to handle __extension__ in the
comment|/// parser.
name|class
name|ExtensionRAIIObject
block|{
name|void
name|operator
init|=
operator|(
specifier|const
name|ExtensionRAIIObject
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|ExtensionRAIIObject
argument_list|(
specifier|const
name|ExtensionRAIIObject
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|DiagnosticsEngine
modifier|&
name|Diags
decl_stmt|;
name|public
label|:
name|ExtensionRAIIObject
argument_list|(
name|DiagnosticsEngine
operator|&
name|diags
argument_list|)
operator|:
name|Diags
argument_list|(
argument|diags
argument_list|)
block|{
name|Diags
operator|.
name|IncrementAllExtensionsSilenced
argument_list|()
block|;     }
operator|~
name|ExtensionRAIIObject
argument_list|()
block|{
name|Diags
operator|.
name|DecrementAllExtensionsSilenced
argument_list|()
block|;     }
block|}
empty_stmt|;
comment|/// ColonProtectionRAIIObject - This sets the Parser::ColonIsSacred bool and
comment|/// restores it when destroyed.  This says that "foo:" should not be
comment|/// considered a possible typo for "foo::" for error recovery purposes.
name|class
name|ColonProtectionRAIIObject
block|{
name|Parser
modifier|&
name|P
decl_stmt|;
name|bool
name|OldVal
decl_stmt|;
name|public
label|:
name|ColonProtectionRAIIObject
argument_list|(
argument|Parser&p
argument_list|,
argument|bool Value = true
argument_list|)
block|:
name|P
argument_list|(
name|p
argument_list|)
operator|,
name|OldVal
argument_list|(
argument|P.ColonIsSacred
argument_list|)
block|{
name|P
operator|.
name|ColonIsSacred
operator|=
name|Value
block|;     }
comment|/// restore - This can be used to restore the state early, before the dtor
comment|/// is run.
name|void
name|restore
argument_list|()
block|{
name|P
operator|.
name|ColonIsSacred
operator|=
name|OldVal
block|;     }
operator|~
name|ColonProtectionRAIIObject
argument_list|()
block|{
name|restore
argument_list|()
block|;     }
block|}
empty_stmt|;
comment|/// \brief RAII object that makes '>' behave either as an operator
comment|/// or as the closing angle bracket for a template argument list.
name|class
name|GreaterThanIsOperatorScope
block|{
name|bool
modifier|&
name|GreaterThanIsOperator
decl_stmt|;
name|bool
name|OldGreaterThanIsOperator
decl_stmt|;
name|public
label|:
name|GreaterThanIsOperatorScope
argument_list|(
argument|bool&GTIO
argument_list|,
argument|bool Val
argument_list|)
block|:
name|GreaterThanIsOperator
argument_list|(
name|GTIO
argument_list|)
operator|,
name|OldGreaterThanIsOperator
argument_list|(
argument|GTIO
argument_list|)
block|{
name|GreaterThanIsOperator
operator|=
name|Val
block|;     }
operator|~
name|GreaterThanIsOperatorScope
argument_list|()
block|{
name|GreaterThanIsOperator
operator|=
name|OldGreaterThanIsOperator
block|;     }
block|}
empty_stmt|;
name|class
name|InMessageExpressionRAIIObject
block|{
name|bool
modifier|&
name|InMessageExpression
decl_stmt|;
name|bool
name|OldValue
decl_stmt|;
name|public
label|:
name|InMessageExpressionRAIIObject
argument_list|(
argument|Parser&P
argument_list|,
argument|bool Value
argument_list|)
block|:
name|InMessageExpression
argument_list|(
name|P
operator|.
name|InMessageExpression
argument_list|)
operator|,
name|OldValue
argument_list|(
argument|P.InMessageExpression
argument_list|)
block|{
name|InMessageExpression
operator|=
name|Value
block|;     }
operator|~
name|InMessageExpressionRAIIObject
argument_list|()
block|{
name|InMessageExpression
operator|=
name|OldValue
block|;     }
block|}
empty_stmt|;
comment|/// \brief RAII object that makes sure paren/bracket/brace count is correct
comment|/// after declaration/statement parsing, even when there's a parsing error.
name|class
name|ParenBraceBracketBalancer
block|{
name|Parser
modifier|&
name|P
decl_stmt|;
name|unsigned
name|short
name|ParenCount
decl_stmt|,
name|BracketCount
decl_stmt|,
name|BraceCount
decl_stmt|;
name|public
label|:
name|ParenBraceBracketBalancer
argument_list|(
name|Parser
operator|&
name|p
argument_list|)
operator|:
name|P
argument_list|(
name|p
argument_list|)
operator|,
name|ParenCount
argument_list|(
name|p
operator|.
name|ParenCount
argument_list|)
operator|,
name|BracketCount
argument_list|(
name|p
operator|.
name|BracketCount
argument_list|)
operator|,
name|BraceCount
argument_list|(
argument|p.BraceCount
argument_list|)
block|{ }
operator|~
name|ParenBraceBracketBalancer
argument_list|()
block|{
name|P
operator|.
name|ParenCount
operator|=
name|ParenCount
block|;
name|P
operator|.
name|BracketCount
operator|=
name|BracketCount
block|;
name|P
operator|.
name|BraceCount
operator|=
name|BraceCount
block|;     }
block|}
empty_stmt|;
name|class
name|PoisonSEHIdentifiersRAIIObject
block|{
name|PoisonIdentifierRAIIObject
name|Ident_AbnormalTermination
decl_stmt|;
name|PoisonIdentifierRAIIObject
name|Ident_GetExceptionCode
decl_stmt|;
name|PoisonIdentifierRAIIObject
name|Ident_GetExceptionInfo
decl_stmt|;
name|PoisonIdentifierRAIIObject
name|Ident__abnormal_termination
decl_stmt|;
name|PoisonIdentifierRAIIObject
name|Ident__exception_code
decl_stmt|;
name|PoisonIdentifierRAIIObject
name|Ident__exception_info
decl_stmt|;
name|PoisonIdentifierRAIIObject
name|Ident___abnormal_termination
decl_stmt|;
name|PoisonIdentifierRAIIObject
name|Ident___exception_code
decl_stmt|;
name|PoisonIdentifierRAIIObject
name|Ident___exception_info
decl_stmt|;
name|public
label|:
name|PoisonSEHIdentifiersRAIIObject
argument_list|(
argument|Parser&Self
argument_list|,
argument|bool NewValue
argument_list|)
block|:
name|Ident_AbnormalTermination
argument_list|(
name|Self
operator|.
name|Ident_AbnormalTermination
argument_list|,
name|NewValue
argument_list|)
operator|,
name|Ident_GetExceptionCode
argument_list|(
name|Self
operator|.
name|Ident_GetExceptionCode
argument_list|,
name|NewValue
argument_list|)
operator|,
name|Ident_GetExceptionInfo
argument_list|(
name|Self
operator|.
name|Ident_GetExceptionInfo
argument_list|,
name|NewValue
argument_list|)
operator|,
name|Ident__abnormal_termination
argument_list|(
name|Self
operator|.
name|Ident__abnormal_termination
argument_list|,
name|NewValue
argument_list|)
operator|,
name|Ident__exception_code
argument_list|(
name|Self
operator|.
name|Ident__exception_code
argument_list|,
name|NewValue
argument_list|)
operator|,
name|Ident__exception_info
argument_list|(
name|Self
operator|.
name|Ident__exception_info
argument_list|,
name|NewValue
argument_list|)
operator|,
name|Ident___abnormal_termination
argument_list|(
name|Self
operator|.
name|Ident___abnormal_termination
argument_list|,
name|NewValue
argument_list|)
operator|,
name|Ident___exception_code
argument_list|(
name|Self
operator|.
name|Ident___exception_code
argument_list|,
name|NewValue
argument_list|)
operator|,
name|Ident___exception_info
argument_list|(
argument|Self.Ident___exception_info
argument_list|,
argument|NewValue
argument_list|)
block|{     }
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

