begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm-readobj.h ----------------------------------------------------===//
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
name|LLVM_TOOLS_LLVM_READOBJ_LLVM_READOBJ_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVM_READOBJ_LLVM_READOBJ_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
name|class
name|RelocationRef
decl_stmt|;
block|}
comment|// Various helper functions.
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|reportError
parameter_list|(
name|Twine
name|Msg
parameter_list|)
function_decl|;
name|void
name|error
argument_list|(
name|std
operator|::
name|error_code
name|EC
argument_list|)
decl_stmt|;
name|void
name|error
argument_list|(
name|llvm
operator|::
name|Error
name|EC
argument_list|)
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|error
argument_list|(
argument|llvm::Expected<T>&&E
argument_list|)
block|{
name|error
argument_list|(
name|E
operator|.
name|takeError
argument_list|()
argument_list|)
block|;
return|return
name|std
operator|::
name|move
argument_list|(
operator|*
name|E
argument_list|)
return|;
block|}
name|template
operator|<
name|class
name|T
operator|>
name|T
name|unwrapOrError
argument_list|(
argument|ErrorOr<T> EO
argument_list|)
block|{
if|if
condition|(
name|EO
condition|)
return|return
operator|*
name|EO
return|;
name|reportError
argument_list|(
name|EO
operator|.
name|getError
argument_list|()
operator|.
name|message
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|T
name|unwrapOrError
argument_list|(
argument|Expected<T> EO
argument_list|)
block|{
if|if
condition|(
name|EO
condition|)
return|return
operator|*
name|EO
return|;
name|std
operator|::
name|string
name|Buf
expr_stmt|;
end_expr_stmt

begin_function_decl
name|raw_string_ostream
name|OS
parameter_list|(
name|Buf
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|logAllUnhandledErrors
argument_list|(
name|EO
operator|.
name|takeError
argument_list|()
argument_list|,
name|OS
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OS
operator|.
name|flush
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|reportError
argument_list|(
name|Buf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
unit|}   bool
name|relocAddressLess
argument_list|(
argument|object::RelocationRef A
argument_list|,
argument|object::RelocationRef B
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_macro
unit|namespace
name|opts
end_macro

begin_block
block|{
extern|extern llvm::cl::list<std::string> InputFilenames;
extern|extern llvm::cl::opt<bool> FileHeaders;
extern|extern llvm::cl::opt<bool> Sections;
extern|extern llvm::cl::opt<bool> SectionRelocations;
extern|extern llvm::cl::opt<bool> SectionSymbols;
extern|extern llvm::cl::opt<bool> SectionData;
extern|extern llvm::cl::opt<bool> Relocations;
extern|extern llvm::cl::opt<bool> Symbols;
extern|extern llvm::cl::opt<bool> DynamicSymbols;
extern|extern llvm::cl::opt<bool> UnwindInfo;
extern|extern llvm::cl::opt<bool> ExpandRelocs;
extern|extern llvm::cl::opt<bool> CodeView;
extern|extern llvm::cl::opt<bool> CodeViewSubsectionBytes;
extern|extern llvm::cl::opt<bool> ARMAttributes;
extern|extern llvm::cl::opt<bool> MipsPLTGOT;
enum|enum
name|OutputStyleTy
block|{
name|LLVM
block|,
name|GNU
block|}
enum|;
extern|extern llvm::cl::opt<OutputStyleTy> Output;
block|}
end_block

begin_comment
comment|// namespace opts
end_comment

begin_define
define|#
directive|define
name|LLVM_READOBJ_ENUM_ENT
parameter_list|(
name|ns
parameter_list|,
name|enum
define|) \   { #enum, ns::enum }
end_define

begin_define
define|#
directive|define
name|LLVM_READOBJ_ENUM_CLASS_ENT
parameter_list|(
name|enum_class
parameter_list|,
name|enum
define|) \   { #enum, std::underlying_type<enum_class>::type(enum_class::enum) }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

