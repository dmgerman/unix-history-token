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
name|liblldb_ClangModulesDeclVendor_h
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ClangModulesDeclVendor_h
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
file|<set>
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
operator|~
name|ClangModulesDeclVendor
argument_list|()
name|override
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
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|ConstString
operator|>
name|ModulePath
expr_stmt|;
typedef|typedef
name|uintptr_t
name|ModuleID
typedef|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|ModuleID
operator|>
name|ModuleVector
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Add a module to the list of modules to search.
comment|///
comment|/// @param[in] path
comment|///     The path to the exact module to be loaded.  E.g., if the desired
comment|///     module is std.io, then this should be { "std", "io" }.
comment|///
comment|/// @param[in] exported_modules
comment|///     If non-NULL, a pointer to a vector to populate with the ID of every
comment|///     module that is re-exported by the specified module.
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
parameter_list|(
name|ModulePath
modifier|&
name|path
parameter_list|,
name|ModuleVector
modifier|*
name|exported_modules
parameter_list|,
name|Stream
modifier|&
name|error_stream
parameter_list|)
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Add all modules referred to in a given compilation unit to the list
comment|/// of modules to search.
comment|///
comment|/// @param[in] cu
comment|///     The compilation unit to scan for imported modules.
comment|///
comment|/// @param[in] exported_modules
comment|///     A vector to populate with the ID of each module loaded (directly
comment|///     and via re-exports) in this way.
comment|///
comment|/// @param[in] error_stream
comment|///     A stream to populate with the output of the Clang parser when
comment|///     it tries to load the modules.
comment|///
comment|/// @return
comment|///     True if all modules referred to by the compilation unit could be
comment|///     loaded; false if one could not be loaded.  If the compiler
comment|///     encountered a fatal error during a previous module
comment|///     load, then this will always return false for this ModuleImporter.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|AddModulesForCompileUnit
parameter_list|(
name|CompileUnit
modifier|&
name|cu
parameter_list|,
name|ModuleVector
modifier|&
name|exported_modules
parameter_list|,
name|Stream
modifier|&
name|error_stream
parameter_list|)
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Enumerate all the macros that are defined by a given set of modules
comment|/// that are already imported.
comment|///
comment|/// @param[in] modules
comment|///     The unique IDs for all modules to query.  Later modules have higher
comment|///     priority, just as if you @imported them in that order.  This matters
comment|///     if module A #defines a macro and module B #undefs it.
comment|///
comment|/// @param[in] handler
comment|///     A function to call with the text of each #define (including the
comment|///     #define directive).  #undef directives are not included; we simply
comment|///     elide any corresponding #define.  If this function returns true,
comment|///     we stop the iteration immediately.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|ForEachMacro
argument_list|(
specifier|const
name|ModuleVector
operator|&
name|modules
argument_list|,
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
argument_list|)
operator|>
name|handler
argument_list|)
init|=
literal|0
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Query whether Clang supports modules for a particular language.
comment|/// LLDB uses this to decide whether to try to find the modules loaded
comment|/// by a gaiven compile unit.
comment|///
comment|/// @param[in] language
comment|///     The language to query for.
comment|///
comment|/// @return
comment|///     True if Clang has modules for the given language.
comment|//------------------------------------------------------------------
specifier|static
name|bool
name|LanguageSupportsClangModules
argument_list|(
name|lldb
operator|::
name|LanguageType
name|language
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ClangModulesDeclVendor_h
end_comment

end_unit

