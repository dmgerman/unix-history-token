begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangModulesDeclVendor.h --------------------------------*- C++ -*-===//
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
name|_liblldb_ClangModulesDeclVendor_
end_ifndef

begin_define
define|#
directive|define
name|_liblldb_ClangModulesDeclVendor_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ClangForward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/DeclVendor.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Platform.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ClangModulesDeclVendor
range|:
name|public
name|DeclVendor
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|ClangModulesDeclVendor
argument_list|()
block|;
name|virtual
operator|~
name|ClangModulesDeclVendor
argument_list|()
block|;
specifier|static
name|ClangModulesDeclVendor
operator|*
name|Create
argument_list|(
name|Target
operator|&
name|target
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Add a module to the list of modules to search.
comment|///
comment|/// @param[in] path
comment|///     The path to the exact module to be loaded.  E.g., if the desired
comment|///     module is std.io, then this should be { "std", "io" }.
comment|///
comment|/// @param[in] error_stream
comment|///     A stream to populate with the output of the Clang parser when
comment|///     it tries to load the module.
comment|///
comment|/// @return
comment|///     True if the module could be loaded; false if not.  If the
comment|///     compiler encountered a fatal error during a previous module
comment|///     load, then this will always return false for this ModuleImporter.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|AddModule
argument_list|(
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|StringRef
operator|>
operator|&
name|path
argument_list|,
name|Stream
operator|&
name|error_stream
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_lldb_ClangModulesDeclVendor_) */
end_comment

end_unit

