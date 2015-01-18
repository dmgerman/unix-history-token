begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- tools/dsymutil/dsymutil.h - dsymutil high-level functionality ------===//
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

begin_comment
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file contains the class declaration for the code that parses STABS
end_comment

begin_comment
comment|/// debug maps that are embedded in the binaries symbol tables.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TOOLS_DSYMUTIL_DSYMUTIL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_DSYMUTIL_DSYMUTIL_H
end_define

begin_include
include|#
directive|include
file|"DebugMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|dsymutil
block|{
comment|/// \brief Extract the DebugMap from the given file.
comment|/// The file has to be a MachO object file.
name|llvm
operator|::
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|DebugMap
operator|>>
name|parseDebugMap
argument_list|(
argument|StringRef InputFile
argument_list|,
argument|StringRef PrependPath =
literal|""
argument_list|,
argument|bool Verbose = false
argument_list|)
expr_stmt|;
comment|/// \brief Link the Dwarf debuginfo as directed by the passed DebugMap
comment|/// \p DM into a DwarfFile named \p OutputFilename.
comment|/// \returns false if the link failed.
name|bool
name|linkDwarf
parameter_list|(
name|StringRef
name|OutputFilename
parameter_list|,
specifier|const
name|DebugMap
modifier|&
name|DM
parameter_list|,
name|bool
name|Verbose
init|=
name|false
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TOOLS_DSYMUTIL_DSYMUTIL_H
end_comment

end_unit

