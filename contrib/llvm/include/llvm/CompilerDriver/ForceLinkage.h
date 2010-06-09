begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ForceLinkage.h - The LLVM Compiler Driver --------------*- C++ -*-===//
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
comment|//  A bit of preprocessor magic to force references to static libraries. Needed
end_comment

begin_comment
comment|//  because plugin initialization is done via static variables.
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
name|LLVM_INCLUDE_COMPILER_DRIVER_FORCE_LINKAGE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_INCLUDE_COMPILER_DRIVER_FORCE_LINKAGE_H
end_define

begin_include
include|#
directive|include
file|"llvm/CompilerDriver/ForceLinkageMacros.h"
end_include

begin_decl_stmt
name|namespace
name|llvmc
block|{
comment|// Declare all ForceLinkage$(PluginName) functions.
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_1
name|LLVMC_FORCE_LINKAGE_DECL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_1
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_2
name|LLVMC_FORCE_LINKAGE_DECL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_2
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_3
name|LLVMC_FORCE_LINKAGE_DECL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_3
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_4
name|LLVMC_FORCE_LINKAGE_DECL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_4
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_5
name|LLVMC_FORCE_LINKAGE_DECL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_5
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_6
name|LLVMC_FORCE_LINKAGE_DECL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_6
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_7
name|LLVMC_FORCE_LINKAGE_DECL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_7
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_8
name|LLVMC_FORCE_LINKAGE_DECL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_8
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_9
name|LLVMC_FORCE_LINKAGE_DECL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_9
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_10
name|LLVMC_FORCE_LINKAGE_DECL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_10
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|namespace
name|force_linkage
block|{
struct|struct
name|LinkageForcer
block|{
name|LinkageForcer
argument_list|()
block|{
comment|// Call all ForceLinkage$(PluginName) functions.
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_1
name|LLVMC_FORCE_LINKAGE_CALL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_1
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_2
name|LLVMC_FORCE_LINKAGE_CALL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_2
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_3
name|LLVMC_FORCE_LINKAGE_CALL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_3
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_4
name|LLVMC_FORCE_LINKAGE_CALL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_4
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_5
name|LLVMC_FORCE_LINKAGE_CALL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_5
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_6
name|LLVMC_FORCE_LINKAGE_CALL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_6
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_7
name|LLVMC_FORCE_LINKAGE_CALL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_7
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_8
name|LLVMC_FORCE_LINKAGE_CALL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_8
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_9
name|LLVMC_FORCE_LINKAGE_CALL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_9
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LLVMC_BUILTIN_PLUGIN_10
name|LLVMC_FORCE_LINKAGE_CALL
argument_list|(
name|LLVMC_BUILTIN_PLUGIN_10
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
struct|;
block|}
comment|// End namespace force_linkage.
comment|// The only externally used bit.
name|void
name|ForceLinkage
parameter_list|()
block|{
name|force_linkage
operator|::
name|LinkageForcer
name|dummy
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvmc.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_INCLUDE_COMPILER_DRIVER_FORCE_LINKAGE_H
end_comment

end_unit

