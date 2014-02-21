begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCModuleYAML.h - MCModule YAMLIO implementation ----------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file declares classes for handling the YAML representation
end_comment

begin_comment
comment|/// of MCModule.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_MC_MCMODULEYAML_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCMODULEYAML_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCModule.h"
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
name|MCInstrInfo
decl_stmt|;
name|class
name|MCRegisterInfo
decl_stmt|;
comment|/// \brief Dump a YAML representation of the MCModule \p MCM to \p OS.
comment|/// \returns The empty string on success, an error message on failure.
name|StringRef
name|mcmodule2yaml
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|MCModule
modifier|&
name|MCM
parameter_list|,
specifier|const
name|MCInstrInfo
modifier|&
name|MII
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|&
name|MRI
parameter_list|)
function_decl|;
comment|/// \brief Creates a new module and returns it in \p MCM.
comment|/// \returns The empty string on success, an error message on failure.
name|StringRef
name|yaml2mcmodule
argument_list|(
name|OwningPtr
operator|<
name|MCModule
operator|>
operator|&
name|MCM
argument_list|,
name|StringRef
name|YamlContent
argument_list|,
specifier|const
name|MCInstrInfo
operator|&
name|MII
argument_list|,
specifier|const
name|MCRegisterInfo
operator|&
name|MRI
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

