begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/MC/MCAsmParserUtils.h - Asm Parser Utilities --------*- C++ -*-===//
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
name|LLVM_MC_MCPARSER_MCASMPARSERUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCPARSER_MCASMPARSERUTILS_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmParser
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|namespace
name|MCParserUtils
block|{
comment|/// Parse a value expression and return whether it can be assigned to a symbol
comment|/// with the given name.
comment|///
comment|/// On success, returns false and sets the Symbol and Value output parameters.
name|bool
name|parseAssignmentExpression
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|bool
name|allow_redef
parameter_list|,
name|MCAsmParser
modifier|&
name|Parser
parameter_list|,
name|MCSymbol
modifier|*
modifier|&
name|Symbol
parameter_list|,
specifier|const
name|MCExpr
modifier|*
modifier|&
name|Value
parameter_list|)
function_decl|;
block|}
comment|// namespace MCParserUtils
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_MCPARSER_MCASMPARSERUTILS_H
end_comment

end_unit

