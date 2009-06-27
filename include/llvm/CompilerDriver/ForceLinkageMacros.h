begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ForceLinkageMacros.h - The LLVM Compiler Driver --------*- C++ -*-===//
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
comment|//  Preprocessor magic that forces references to static libraries - common
end_comment

begin_comment
comment|//  macros used by both driver and plugins.
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
name|LLVM_INCLUDE_COMPILER_DRIVER_FORCE_LINKAGE_MACROS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_INCLUDE_COMPILER_DRIVER_FORCE_LINKAGE_MACROS_H
end_define

begin_define
define|#
directive|define
name|LLVMC_FORCE_LINKAGE_PREFIX
parameter_list|(
name|PluginName
parameter_list|)
value|ForceLinkage ## PluginName
end_define

begin_define
define|#
directive|define
name|LLVMC_FORCE_LINKAGE_FUN
parameter_list|(
name|PluginName
parameter_list|)
define|\
value|LLVMC_FORCE_LINKAGE_PREFIX(PluginName)
end_define

begin_define
define|#
directive|define
name|LLVMC_FORCE_LINKAGE_DECL
parameter_list|(
name|PluginName
parameter_list|)
define|\
value|void LLVMC_FORCE_LINKAGE_FUN(PluginName) ()
end_define

begin_define
define|#
directive|define
name|LLVMC_FORCE_LINKAGE_CALL
parameter_list|(
name|PluginName
parameter_list|)
define|\
value|LLVMC_FORCE_LINKAGE_FUN(PluginName) ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_INCLUDE_COMPILER_DRIVER_FORCE_LINKAGE_MACROS_H
end_comment

end_unit

