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
name|bool
name|error
argument_list|(
name|std
operator|::
name|error_code
name|ec
argument_list|)
decl_stmt|;
name|bool
name|relocAddressLess
argument_list|(
name|object
operator|::
name|RelocationRef
name|A
argument_list|,
name|object
operator|::
name|RelocationRef
name|B
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|opts
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
extern|extern llvm::cl::opt<bool> CodeViewLineTables;
extern|extern llvm::cl::opt<bool> ARMAttributes;
extern|extern llvm::cl::opt<bool> MipsPLTGOT;
block|}
end_decl_stmt

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

