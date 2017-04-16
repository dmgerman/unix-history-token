begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Symbols.h -----------------------------------------------*- C++ -*-===//
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
name|liblldb_Symbols_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Symbols_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ArchSpec
decl_stmt|;
name|class
name|ModuleSpec
decl_stmt|;
name|class
name|UUID
decl_stmt|;
name|class
name|Symbols
block|{
name|public
label|:
comment|//----------------------------------------------------------------------
comment|// Locate the executable file given a module specification.
comment|//
comment|// Locating the file should happen only on the local computer or using
comment|// the current computers global settings.
comment|//----------------------------------------------------------------------
specifier|static
name|ModuleSpec
name|LocateExecutableObjectFile
parameter_list|(
specifier|const
name|ModuleSpec
modifier|&
name|module_spec
parameter_list|)
function_decl|;
comment|//----------------------------------------------------------------------
comment|// Locate the symbol file given a module specification.
comment|//
comment|// Locating the file should happen only on the local computer or using
comment|// the current computers global settings.
comment|//----------------------------------------------------------------------
specifier|static
name|FileSpec
name|LocateExecutableSymbolFile
parameter_list|(
specifier|const
name|ModuleSpec
modifier|&
name|module_spec
parameter_list|)
function_decl|;
specifier|static
name|FileSpec
name|FindSymbolFileInBundle
argument_list|(
specifier|const
name|FileSpec
operator|&
name|dsym_bundle_fspec
argument_list|,
specifier|const
name|lldb_private
operator|::
name|UUID
operator|*
name|uuid
argument_list|,
specifier|const
name|ArchSpec
operator|*
name|arch
argument_list|)
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|// Locate the object and symbol file given a module specification.
comment|//
comment|// Locating the file can try to download the file from a corporate build
comment|// repository, or using any other means necessary to locate both the
comment|// unstripped object file and the debug symbols.
comment|// The force_lookup argument controls whether the external program is called
comment|// unconditionally to find the symbol file, or if the user's settings are
comment|// checked to see if they've enabled the external program before calling.
comment|//
comment|//----------------------------------------------------------------------
specifier|static
name|bool
name|DownloadObjectAndSymbolFile
parameter_list|(
name|ModuleSpec
modifier|&
name|module_spec
parameter_list|,
name|bool
name|force_lookup
init|=
name|true
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Symbols_h_
end_comment

end_unit

