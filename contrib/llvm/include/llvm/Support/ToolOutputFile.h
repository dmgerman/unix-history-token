begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ToolOutputFile.h - Output files for compiler-like tools -----------===//
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
comment|//  This file defines the tool_output_file class.
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
name|LLVM_SUPPORT_TOOLOUTPUTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_TOOLOUTPUTFILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// tool_output_file - This class contains a raw_fd_ostream and adds a
comment|/// few extra features commonly needed for compiler-like tool output files:
comment|///   - The file is automatically deleted if the process is killed.
comment|///   - The file is automatically deleted when the tool_output_file
comment|///     object is destroyed unless the client calls keep().
name|class
name|tool_output_file
block|{
comment|/// Installer - This class is declared before the raw_fd_ostream so that
comment|/// it is constructed before the raw_fd_ostream is constructed and
comment|/// destructed after the raw_fd_ostream is destructed. It installs
comment|/// cleanups in its constructor and uninstalls them in its destructor.
name|class
name|CleanupInstaller
block|{
comment|/// Filename - The name of the file.
name|std
operator|::
name|string
name|Filename
expr_stmt|;
name|public
label|:
comment|/// Keep - The flag which indicates whether we should not delete the file.
name|bool
name|Keep
decl_stmt|;
name|explicit
name|CleanupInstaller
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
operator|~
name|CleanupInstaller
argument_list|()
expr_stmt|;
block|}
name|Installer
expr_stmt|;
comment|/// OS - The contained stream. This is intentionally declared after
comment|/// Installer.
name|raw_fd_ostream
name|OS
decl_stmt|;
name|public
label|:
comment|/// tool_output_file - This constructor's arguments are passed to
comment|/// to raw_fd_ostream's constructor.
name|tool_output_file
argument_list|(
argument|const char *filename
argument_list|,
argument|std::string&ErrorInfo
argument_list|,
argument|sys::fs::OpenFlags Flags = sys::fs::F_None
argument_list|)
empty_stmt|;
name|tool_output_file
argument_list|(
argument|const char *Filename
argument_list|,
argument|int FD
argument_list|)
empty_stmt|;
comment|/// os - Return the contained raw_fd_ostream.
name|raw_fd_ostream
modifier|&
name|os
parameter_list|()
block|{
return|return
name|OS
return|;
block|}
comment|/// keep - Indicate that the tool's job wrt this output file has been
comment|/// successful and the file should not be deleted.
name|void
name|keep
parameter_list|()
block|{
name|Installer
operator|.
name|Keep
operator|=
name|true
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

