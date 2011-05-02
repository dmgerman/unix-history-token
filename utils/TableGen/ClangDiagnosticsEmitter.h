begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ClangDiagnosticsEmitter.h - Generate Clang diagnostics tables -*- C++ -*-
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
comment|// These tablegen backends emit Clang diagnostics tables.
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
name|CLANGDIAGS_EMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|CLANGDIAGS_EMITTER_H
end_define

begin_include
include|#
directive|include
file|"TableGenBackend.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// ClangDiagsDefsEmitter - The top-level class emits .def files containing
comment|///  declarations of Clang diagnostics.
comment|///
name|class
name|ClangDiagsDefsEmitter
range|:
name|public
name|TableGenBackend
block|{
name|RecordKeeper
operator|&
name|Records
block|;
specifier|const
name|std
operator|::
name|string
operator|&
name|Component
block|;
name|public
operator|:
name|explicit
name|ClangDiagsDefsEmitter
argument_list|(
name|RecordKeeper
operator|&
name|R
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|component
argument_list|)
operator|:
name|Records
argument_list|(
name|R
argument_list|)
block|,
name|Component
argument_list|(
argument|component
argument_list|)
block|{}
comment|// run - Output the .def file contents
name|void
name|run
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|; }
decl_stmt|;
name|class
name|ClangDiagGroupsEmitter
range|:
name|public
name|TableGenBackend
block|{
name|RecordKeeper
operator|&
name|Records
block|;
name|public
operator|:
name|explicit
name|ClangDiagGroupsEmitter
argument_list|(
name|RecordKeeper
operator|&
name|R
argument_list|)
operator|:
name|Records
argument_list|(
argument|R
argument_list|)
block|{}
name|void
name|run
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|; }
decl_stmt|;
name|class
name|ClangDiagsIndexNameEmitter
range|:
name|public
name|TableGenBackend
block|{
name|RecordKeeper
operator|&
name|Records
block|;
name|public
operator|:
name|explicit
name|ClangDiagsIndexNameEmitter
argument_list|(
name|RecordKeeper
operator|&
name|R
argument_list|)
operator|:
name|Records
argument_list|(
argument|R
argument_list|)
block|{}
name|void
name|run
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

