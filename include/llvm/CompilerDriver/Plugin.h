begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Plugin.h - The LLVM Compiler Driver --------------------*- C++ -*-===//
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
comment|// This file is distributed under the University of Illinois Open
end_comment

begin_comment
comment|// Source License. See LICENSE.TXT for details.
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
comment|//  Plugin support for llvmc.
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
name|LLVM_INCLUDE_COMPILER_DRIVER_PLUGIN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_INCLUDE_COMPILER_DRIVER_PLUGIN_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Registry.h"
end_include

begin_decl_stmt
name|namespace
name|llvmc
block|{
name|class
name|LanguageMap
decl_stmt|;
name|class
name|CompilationGraph
decl_stmt|;
comment|/// BasePlugin - An abstract base class for all LLVMC plugins.
struct|struct
name|BasePlugin
block|{
comment|/// Priority - Plugin priority, useful for handling dependencies
comment|/// between plugins. Plugins with lower priorities are loaded
comment|/// first.
name|virtual
name|int
name|Priority
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// PreprocessOptions - The auto-generated function that performs various
comment|/// consistency checks on options (like ensuring that -O2 and -O3 are not
comment|/// used together).
name|virtual
name|void
name|PreprocessOptions
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// PopulateLanguageMap - The auto-generated function that fills in
comment|/// the language map (map from file extensions to language names).
name|virtual
name|void
name|PopulateLanguageMap
argument_list|(
name|LanguageMap
operator|&
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// PopulateCompilationGraph - The auto-generated function that
comment|/// populates the compilation graph with nodes and edges.
name|virtual
name|void
name|PopulateCompilationGraph
argument_list|(
name|CompilationGraph
operator|&
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Needed to avoid a compiler warning.
name|virtual
operator|~
name|BasePlugin
argument_list|()
block|{}
block|}
struct|;
typedef|typedef
name|llvm
operator|::
name|Registry
operator|<
name|BasePlugin
operator|>
name|PluginRegistry
expr_stmt|;
name|template
operator|<
name|class
name|P
operator|>
expr|struct
name|RegisterPlugin
operator|:
name|public
name|PluginRegistry
operator|::
name|Add
operator|<
name|P
operator|>
block|{
typedef|typedef
name|PluginRegistry
operator|::
name|Add
operator|<
name|P
operator|>
name|Base
expr_stmt|;
name|RegisterPlugin
argument_list|(
specifier|const
name|char
operator|*
name|Name
operator|=
literal|"Nameless"
argument_list|,
specifier|const
name|char
operator|*
name|Desc
operator|=
literal|"Auto-generated plugin"
argument_list|)
operator|:
name|Base
argument_list|(
argument|Name
argument_list|,
argument|Desc
argument_list|)
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// PluginLoader - Helper class used by the main program for
end_comment

begin_comment
comment|/// lifetime management.
end_comment

begin_struct
struct|struct
name|PluginLoader
block|{
name|PluginLoader
argument_list|()
expr_stmt|;
operator|~
name|PluginLoader
argument_list|()
expr_stmt|;
comment|/// RunInitialization - Calls PreprocessOptions, PopulateLanguageMap and
comment|/// PopulateCompilationGraph methods of all plugins. This populates the
comment|/// global language map and the compilation graph.
name|void
name|RunInitialization
argument_list|(
name|LanguageMap
operator|&
name|langMap
argument_list|,
name|CompilationGraph
operator|&
name|graph
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
comment|// noncopyable
name|PluginLoader
argument_list|(
specifier|const
name|PluginLoader
operator|&
name|other
argument_list|)
expr_stmt|;
specifier|const
name|PluginLoader
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PluginLoader
operator|&
name|other
operator|)
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_INCLUDE_COMPILER_DRIVER_PLUGIN_H
end_comment

end_unit

