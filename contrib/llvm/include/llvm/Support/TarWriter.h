begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/TarWriter.h - Tar archive file creator -----*- C++ -*-===//
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
name|LLVM_SUPPORT_TAR_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_TAR_WRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TarWriter
block|{
name|public
label|:
specifier|static
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|TarWriter
operator|>>
name|create
argument_list|(
argument|StringRef OutputPath
argument_list|,
argument|StringRef BaseDir
argument_list|)
expr_stmt|;
name|void
name|append
parameter_list|(
name|StringRef
name|Path
parameter_list|,
name|StringRef
name|Data
parameter_list|)
function_decl|;
name|private
label|:
name|TarWriter
argument_list|(
argument|int FD
argument_list|,
argument|StringRef BaseDir
argument_list|)
empty_stmt|;
name|raw_fd_ostream
name|OS
decl_stmt|;
name|std
operator|::
name|string
name|BaseDir
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

