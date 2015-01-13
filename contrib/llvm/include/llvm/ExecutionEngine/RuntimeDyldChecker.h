begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- RuntimeDyldChecker.h - RuntimeDyld tester framework -----*- C++ -*-=//
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
name|LLVM_RUNTIMEDYLDCHECKER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_RUNTIMEDYLDCHECKER_H
end_define

begin_include
include|#
directive|include
file|"RuntimeDyld.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCDisassembler
decl_stmt|;
name|class
name|MCInstPrinter
decl_stmt|;
comment|/// \brief RuntimeDyld invariant checker for verifying that RuntimeDyld has
comment|///        correctly applied relocations.
comment|///
comment|/// The RuntimeDyldChecker class evaluates expressions against an attached
comment|/// RuntimeDyld instance to verify that relocations have been applied
comment|/// correctly.
comment|///
comment|/// The expression language supports basic pointer arithmetic and bit-masking,
comment|/// and has limited disassembler integration for accessing instruction
comment|/// operands and the next PC (program counter) address for each instruction.
comment|///
comment|/// The language syntax is:
comment|///
comment|/// check = expr '=' expr
comment|///
comment|/// expr = binary_expr
comment|///      | sliceable_expr
comment|///
comment|/// sliceable_expr = '*{' number '}' load_addr_expr [slice]
comment|///                | '(' expr ')' [slice]
comment|///                | ident_expr [slice]
comment|///                | number [slice]
comment|///
comment|/// slice = '[' high-bit-index ':' low-bit-index ']'
comment|///
comment|/// load_addr_expr = symbol
comment|///                | '(' symbol '+' number ')'
comment|///                | '(' symbol '-' number ')'
comment|///
comment|/// ident_expr = 'decode_operand' '(' symbol ',' operand-index ')'
comment|///            | 'next_pc'        '(' symbol ')'
comment|///            | symbol
comment|///
comment|/// binary_expr = expr '+' expr
comment|///             | expr '-' expr
comment|///             | expr '&' expr
comment|///             | expr '|' expr
comment|///             | expr '<<' expr
comment|///             | expr '>>' expr
comment|///
name|class
name|RuntimeDyldChecker
block|{
name|friend
name|class
name|RuntimeDyldCheckerExprEval
decl_stmt|;
name|public
label|:
name|RuntimeDyldChecker
argument_list|(
name|RuntimeDyld
operator|&
name|RTDyld
argument_list|,
name|MCDisassembler
operator|*
name|Disassembler
argument_list|,
name|MCInstPrinter
operator|*
name|InstPrinter
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|ErrStream
argument_list|)
operator|:
name|RTDyld
argument_list|(
operator|*
name|RTDyld
operator|.
name|Dyld
argument_list|)
operator|,
name|Disassembler
argument_list|(
name|Disassembler
argument_list|)
operator|,
name|InstPrinter
argument_list|(
name|InstPrinter
argument_list|)
operator|,
name|ErrStream
argument_list|(
argument|ErrStream
argument_list|)
block|{}
comment|/// \brief Check a single expression against the attached RuntimeDyld
comment|///        instance.
name|bool
name|check
argument_list|(
argument|StringRef CheckExpr
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Scan the given memory buffer for lines beginning with the string
comment|///        in RulePrefix. The remainder of the line is passed to the check
comment|///        method to be evaluated as an expression.
name|bool
name|checkAllRulesInBuffer
argument_list|(
name|StringRef
name|RulePrefix
argument_list|,
name|MemoryBuffer
operator|*
name|MemBuf
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|bool
name|isSymbolValid
argument_list|(
name|StringRef
name|Symbol
argument_list|)
decl|const
decl_stmt|;
name|uint64_t
name|getSymbolAddress
argument_list|(
name|StringRef
name|Symbol
argument_list|)
decl|const
decl_stmt|;
name|uint64_t
name|readMemoryAtSymbol
argument_list|(
name|StringRef
name|Symbol
argument_list|,
name|int64_t
name|Offset
argument_list|,
name|unsigned
name|Size
argument_list|)
decl|const
decl_stmt|;
name|StringRef
name|getSubsectionStartingAt
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
name|RuntimeDyldImpl
modifier|&
name|RTDyld
decl_stmt|;
name|MCDisassembler
modifier|*
name|Disassembler
decl_stmt|;
name|MCInstPrinter
modifier|*
name|InstPrinter
decl_stmt|;
name|llvm
operator|::
name|raw_ostream
operator|&
name|ErrStream
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
comment|// LLVM_RUNTIMEDYLDCHECKER_H
end_comment

end_unit

