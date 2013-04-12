begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== RegistryParser.h - Linker-supported plugin registries -----*- C++ -*-===//
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
comment|// Defines a command-line parser for a registry.
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
name|LLVM_SUPPORT_REGISTRYPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_REGISTRYPARSER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Registry.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A command-line parser for a registry. Use like such:
comment|///
comment|///   static cl::opt<Registry<Collector>::entry, false,
comment|///                  RegistryParser<Collector>>
comment|///   GCOpt("gc", cl::desc("Garbage collector to use."),
comment|///               cl::value_desc());
comment|///
comment|/// To make use of the value:
comment|///
comment|///   Collector *TheCollector = GCOpt->instantiate();
comment|///
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|=
name|RegistryTraits
operator|<
name|T
operator|>
expr|>
name|class
name|RegistryParser
operator|:
name|public
name|cl
operator|::
name|parser
operator|<
specifier|const
name|typename
name|U
operator|::
name|entry
operator|*
operator|>
operator|,
name|public
name|Registry
operator|<
name|T
operator|,
name|U
operator|>
operator|::
name|listener
block|{
typedef|typedef
name|U
name|traits
typedef|;
typedef|typedef
name|typename
name|U
operator|::
name|entry
name|entry
expr_stmt|;
typedef|typedef
name|typename
name|Registry
operator|<
name|T
operator|,
name|U
operator|>
operator|::
name|listener
name|listener
expr_stmt|;
name|protected
label|:
name|void
name|registered
parameter_list|(
specifier|const
name|entry
modifier|&
name|E
parameter_list|)
block|{
name|addLiteralOption
argument_list|(
name|traits
operator|::
name|nameof
argument_list|(
name|E
argument_list|)
argument_list|,
operator|&
name|E
argument_list|,
name|traits
operator|::
name|descof
argument_list|(
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|public
label|:
name|void
name|initialize
argument_list|(
name|cl
operator|::
name|Option
operator|&
name|O
argument_list|)
block|{
name|listener
operator|::
name|init
argument_list|()
expr_stmt|;
name|cl
operator|::
name|parser
operator|<
specifier|const
name|typename
name|U
operator|::
name|entry
operator|*
operator|>
operator|::
name|initialize
argument_list|(
name|O
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_REGISTRYPARSER_H
end_comment

end_unit

