begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/GCMetadataPrinter.h - Prints asm GC tables -*- C++ -*-===//
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
comment|// The abstract base class GCMetadataPrinter supports writing GC metadata tables
end_comment

begin_comment
comment|// as assembly code. This is a separate class from GCStrategy in order to allow
end_comment

begin_comment
comment|// users of the LLVM JIT to avoid linking with the AsmWriter.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Subclasses of GCMetadataPrinter must be registered using the
end_comment

begin_comment
comment|// GCMetadataPrinterRegistry. This is separate from the GCStrategy itself
end_comment

begin_comment
comment|// because these subclasses are logically plugins for the AsmWriter.
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
name|LLVM_CODEGEN_GCMETADATAPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GCMETADATAPRINTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/GCMetadata.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/GCStrategy.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Registry.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GCMetadataPrinter
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// GCMetadataPrinterRegistry - The GC assembly printer registry uses all the
comment|/// defaults from Registry.
typedef|typedef
name|Registry
operator|<
name|GCMetadataPrinter
operator|>
name|GCMetadataPrinterRegistry
expr_stmt|;
comment|/// GCMetadataPrinter - Emits GC metadata as assembly code.
comment|///
name|class
name|GCMetadataPrinter
block|{
name|public
label|:
typedef|typedef
name|GCStrategy
operator|::
name|list_type
name|list_type
expr_stmt|;
typedef|typedef
name|GCStrategy
operator|::
name|iterator
name|iterator
expr_stmt|;
name|private
label|:
name|GCStrategy
modifier|*
name|S
decl_stmt|;
name|friend
name|class
name|AsmPrinter
decl_stmt|;
name|protected
label|:
comment|// May only be subclassed.
name|GCMetadataPrinter
argument_list|()
expr_stmt|;
comment|// Do not implement.
name|GCMetadataPrinter
argument_list|(
specifier|const
name|GCMetadataPrinter
operator|&
argument_list|)
expr_stmt|;
name|GCMetadataPrinter
modifier|&
name|operator
init|=
operator|(
specifier|const
name|GCMetadataPrinter
operator|&
operator|)
decl_stmt|;
name|public
label|:
name|GCStrategy
modifier|&
name|getStrategy
parameter_list|()
block|{
return|return
operator|*
name|S
return|;
block|}
specifier|const
name|Module
operator|&
name|getModule
argument_list|()
specifier|const
block|{
return|return
name|S
operator|->
name|getModule
argument_list|()
return|;
block|}
comment|/// begin/end - Iterate over the collected function metadata.
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|S
operator|->
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|S
operator|->
name|end
argument_list|()
return|;
block|}
comment|/// beginAssembly/finishAssembly - Emit module metadata as assembly code.
name|virtual
name|void
name|beginAssembly
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|AsmPrinter
modifier|&
name|AP
parameter_list|,
specifier|const
name|MCAsmInfo
modifier|&
name|MAI
parameter_list|)
function_decl|;
name|virtual
name|void
name|finishAssembly
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|AsmPrinter
modifier|&
name|AP
parameter_list|,
specifier|const
name|MCAsmInfo
modifier|&
name|MAI
parameter_list|)
function_decl|;
name|virtual
operator|~
name|GCMetadataPrinter
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

