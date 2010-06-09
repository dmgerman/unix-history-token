begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/PluginLoader.h - Plugin Loader for Tools ---*- C++ -*-===//
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
comment|// A tool can #include this file to get a -load option that allows the user to
end_comment

begin_comment
comment|// load arbitrary shared objects into the tool's address space.  Note that this
end_comment

begin_comment
comment|// header can only be included by a program ONCE, so it should never to used by
end_comment

begin_comment
comment|// library authors.
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
name|LLVM_SUPPORT_PLUGINLOADER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_PLUGINLOADER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct|struct
name|PluginLoader
block|{
name|void
name|operator
init|=
operator|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
operator|)
decl_stmt|;
specifier|static
name|unsigned
name|getNumPlugins
parameter_list|()
function_decl|;
specifier|static
name|std
operator|::
name|string
operator|&
name|getPlugin
argument_list|(
argument|unsigned num
argument_list|)
expr_stmt|;
block|}
struct|;
ifndef|#
directive|ifndef
name|DONT_GET_PLUGIN_LOADER_OPTION
comment|// This causes operator= above to be invoked for every -load option.
specifier|static
name|cl
operator|::
name|opt
operator|<
name|PluginLoader
operator|,
name|false
operator|,
name|cl
operator|::
name|parser
operator|<
name|std
operator|::
name|string
operator|>
expr|>
name|LoadOpt
argument_list|(
literal|"load"
argument_list|,
name|cl
operator|::
name|ZeroOrMore
argument_list|,
name|cl
operator|::
name|value_desc
argument_list|(
literal|"pluginfilename"
argument_list|)
argument_list|,
name|cl
operator|::
name|desc
argument_list|(
literal|"Load the specified plugin"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

