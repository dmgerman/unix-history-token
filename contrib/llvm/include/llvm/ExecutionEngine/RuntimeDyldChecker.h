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
name|LLVM_EXECUTIONENGINE_RUNTIMEDYLDCHECKER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_RUNTIMEDYLDCHECKER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|class
name|MCDisassembler
decl_stmt|;
name|class
name|MemoryBuffer
decl_stmt|;
name|class
name|MCInstPrinter
decl_stmt|;
name|class
name|RuntimeDyld
decl_stmt|;
name|class
name|RuntimeDyldCheckerImpl
decl_stmt|;
name|class
name|raw_ostream
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
comment|///            | 'stub_addr' '(' file-name ',' section-name ',' symbol ')'
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
name|raw_ostream
operator|&
name|ErrStream
argument_list|)
expr_stmt|;
operator|~
name|RuntimeDyldChecker
argument_list|()
expr_stmt|;
comment|// \brief Get the associated RTDyld instance.
name|RuntimeDyld
modifier|&
name|getRTDyld
parameter_list|()
function_decl|;
comment|// \brief Get the associated RTDyld instance.
specifier|const
name|RuntimeDyld
operator|&
name|getRTDyld
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Check a single expression against the attached RuntimeDyld
comment|///        instance.
name|bool
name|check
argument_list|(
name|StringRef
name|CheckExpr
argument_list|)
decl|const
decl_stmt|;
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
comment|/// \brief Returns the address of the requested section (or an error message
comment|///        in the second element of the pair if the address cannot be found).
comment|///
comment|/// if 'LocalAddress' is true, this returns the address of the section
comment|/// within the linker's memory. If 'LocalAddress' is false it returns the
comment|/// address within the target process (i.e. the load address).
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|std
operator|::
name|string
operator|>
name|getSectionAddr
argument_list|(
argument|StringRef FileName
argument_list|,
argument|StringRef SectionName
argument_list|,
argument|bool LocalAddress
argument_list|)
expr_stmt|;
comment|/// \brief If there is a section at the given local address, return its load
comment|///        address, otherwise return none.
name|Optional
operator|<
name|uint64_t
operator|>
name|getSectionLoadAddress
argument_list|(
argument|void *LocalAddress
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
name|std
operator|::
name|unique_ptr
operator|<
name|RuntimeDyldCheckerImpl
operator|>
name|Impl
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

end_unit

