begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MachOUtils.h - Mach-o specific helpers for dsymutil  --------------===//
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
name|LLVM_TOOLS_DSYMUTIL_MACHOUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_DSYMUTIL_MACHOUTILS_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCStreamer
decl_stmt|;
name|class
name|raw_fd_ostream
decl_stmt|;
name|namespace
name|dsymutil
block|{
name|class
name|DebugMap
decl_stmt|;
struct_decl|struct
name|LinkOptions
struct_decl|;
name|namespace
name|MachOUtils
block|{
struct|struct
name|ArchAndFilename
block|{
name|std
operator|::
name|string
name|Arch
operator|,
name|Path
expr_stmt|;
name|ArchAndFilename
argument_list|(
argument|StringRef Arch
argument_list|,
argument|StringRef Path
argument_list|)
block|:
name|Arch
argument_list|(
name|Arch
argument_list|)
operator|,
name|Path
argument_list|(
argument|Path
argument_list|)
block|{}
block|}
struct|;
name|bool
name|generateUniversalBinary
argument_list|(
name|SmallVectorImpl
operator|<
name|ArchAndFilename
operator|>
operator|&
name|ArchFiles
argument_list|,
name|StringRef
name|OutputFileName
argument_list|,
specifier|const
name|LinkOptions
operator|&
argument_list|,
name|StringRef
name|SDKPath
argument_list|)
decl_stmt|;
name|bool
name|generateDsymCompanion
parameter_list|(
specifier|const
name|DebugMap
modifier|&
name|DM
parameter_list|,
name|MCStreamer
modifier|&
name|MS
parameter_list|,
name|raw_fd_ostream
modifier|&
name|OutFile
parameter_list|)
function_decl|;
name|std
operator|::
name|string
name|getArchName
argument_list|(
argument|StringRef Arch
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TOOLS_DSYMUTIL_MACHOUTILS_H
end_comment

end_unit

