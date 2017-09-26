begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Formatters.h ---------------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_NATIVE_FORMATTERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_NATIVE_FORMATTERS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/Formatters.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/RawConstants.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/RawTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FormatProviders.h"
end_include

begin_define
define|#
directive|define
name|FORMAT_CASE
parameter_list|(
name|Value
parameter_list|,
name|Name
parameter_list|)
define|\
value|case Value:                                                                  \     Stream<< Name;                                                            \     break;
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
operator|>
expr|struct
name|format_provider
operator|<
name|pdb
operator|::
name|PdbRaw_ImplVer
operator|>
block|{
specifier|static
name|void
name|format
argument_list|(
argument|const pdb::PdbRaw_ImplVer&V
argument_list|,
argument|llvm::raw_ostream&Stream
argument_list|,
argument|StringRef Style
argument_list|)
block|{
switch|switch
condition|(
name|V
condition|)
block|{
name|FORMAT_CASE
argument_list|(
argument|pdb::PdbRaw_ImplVer::PdbImplVC110
argument_list|,
literal|"VC110"
argument_list|)
name|FORMAT_CASE
argument_list|(
argument|pdb::PdbRaw_ImplVer::PdbImplVC140
argument_list|,
literal|"VC140"
argument_list|)
name|FORMAT_CASE
argument_list|(
argument|pdb::PdbRaw_ImplVer::PdbImplVC2
argument_list|,
literal|"VC2"
argument_list|)
name|FORMAT_CASE
argument_list|(
argument|pdb::PdbRaw_ImplVer::PdbImplVC4
argument_list|,
literal|"VC4"
argument_list|)
name|FORMAT_CASE
argument_list|(
argument|pdb::PdbRaw_ImplVer::PdbImplVC41
argument_list|,
literal|"VC41"
argument_list|)
name|FORMAT_CASE
argument_list|(
argument|pdb::PdbRaw_ImplVer::PdbImplVC50
argument_list|,
literal|"VC50"
argument_list|)
name|FORMAT_CASE
argument_list|(
argument|pdb::PdbRaw_ImplVer::PdbImplVC70
argument_list|,
literal|"VC70"
argument_list|)
name|FORMAT_CASE
argument_list|(
argument|pdb::PdbRaw_ImplVer::PdbImplVC70Dep
argument_list|,
literal|"VC70Dep"
argument_list|)
name|FORMAT_CASE
argument_list|(
argument|pdb::PdbRaw_ImplVer::PdbImplVC80
argument_list|,
literal|"VC80"
argument_list|)
name|FORMAT_CASE
argument_list|(
argument|pdb::PdbRaw_ImplVer::PdbImplVC98
argument_list|,
literal|"VC98"
argument_list|)
block|}
block|}
block|}
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

