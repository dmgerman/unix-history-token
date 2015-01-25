begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GCs.h - Garbage collector linkage hacks ---------------------------===//
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
comment|// This file contains hack functions to force linking in the GC components.
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
name|LLVM_CODEGEN_GCS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GCS_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GCStrategy
decl_stmt|;
name|class
name|GCMetadataPrinter
decl_stmt|;
comment|/// FIXME: Collector instances are not useful on their own. These no longer
comment|///        serve any purpose except to link in the plugins.
comment|/// Creates an ocaml-compatible garbage collector.
name|void
name|linkOcamlGC
parameter_list|()
function_decl|;
comment|/// Creates an ocaml-compatible metadata printer.
name|void
name|linkOcamlGCPrinter
parameter_list|()
function_decl|;
comment|/// Creates an erlang-compatible garbage collector.
name|void
name|linkErlangGC
parameter_list|()
function_decl|;
comment|/// Creates an erlang-compatible metadata printer.
name|void
name|linkErlangGCPrinter
parameter_list|()
function_decl|;
comment|/// Creates a shadow stack garbage collector. This collector requires no code
comment|/// generator support.
name|void
name|linkShadowStackGC
parameter_list|()
function_decl|;
name|void
name|linkStatepointExampleGC
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

