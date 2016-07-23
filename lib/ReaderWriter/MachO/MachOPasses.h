begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/MachO/MachOPasses.h -------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
name|LLD_READER_WRITER_MACHO_PASSES_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_MACHO_PASSES_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"lld/ReaderWriter/MachOLinkingContext.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|mach_o
block|{
name|void
name|addLayoutPass
parameter_list|(
name|PassManager
modifier|&
name|pm
parameter_list|,
specifier|const
name|MachOLinkingContext
modifier|&
name|ctx
parameter_list|)
function_decl|;
name|void
name|addStubsPass
parameter_list|(
name|PassManager
modifier|&
name|pm
parameter_list|,
specifier|const
name|MachOLinkingContext
modifier|&
name|ctx
parameter_list|)
function_decl|;
name|void
name|addGOTPass
parameter_list|(
name|PassManager
modifier|&
name|pm
parameter_list|,
specifier|const
name|MachOLinkingContext
modifier|&
name|ctx
parameter_list|)
function_decl|;
name|void
name|addTLVPass
parameter_list|(
name|PassManager
modifier|&
name|pm
parameter_list|,
specifier|const
name|MachOLinkingContext
modifier|&
name|ctx
parameter_list|)
function_decl|;
name|void
name|addCompactUnwindPass
parameter_list|(
name|PassManager
modifier|&
name|pm
parameter_list|,
specifier|const
name|MachOLinkingContext
modifier|&
name|ctx
parameter_list|)
function_decl|;
name|void
name|addObjCPass
parameter_list|(
name|PassManager
modifier|&
name|pm
parameter_list|,
specifier|const
name|MachOLinkingContext
modifier|&
name|ctx
parameter_list|)
function_decl|;
name|void
name|addShimPass
parameter_list|(
name|PassManager
modifier|&
name|pm
parameter_list|,
specifier|const
name|MachOLinkingContext
modifier|&
name|ctx
parameter_list|)
function_decl|;
block|}
comment|// namespace mach_o
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_READER_WRITER_MACHO_PASSES_H
end_comment

end_unit

