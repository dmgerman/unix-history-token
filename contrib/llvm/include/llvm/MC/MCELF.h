begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/MC/MCELF.h - ELF MC --------------------------------------------===//
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
comment|// This file contains some support functions used by the ELF Streamer and
end_comment

begin_comment
comment|// ObjectWriter.
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
name|LLVM_MC_MCELF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCELF_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCExpr.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSymbolData
decl_stmt|;
name|class
name|MCELF
block|{
name|public
label|:
specifier|static
name|void
name|SetBinding
parameter_list|(
name|MCSymbolData
modifier|&
name|SD
parameter_list|,
name|unsigned
name|Binding
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|GetBinding
parameter_list|(
specifier|const
name|MCSymbolData
modifier|&
name|SD
parameter_list|)
function_decl|;
specifier|static
name|void
name|SetType
parameter_list|(
name|MCSymbolData
modifier|&
name|SD
parameter_list|,
name|unsigned
name|Type
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|GetType
parameter_list|(
specifier|const
name|MCSymbolData
modifier|&
name|SD
parameter_list|)
function_decl|;
specifier|static
name|void
name|SetVisibility
parameter_list|(
name|MCSymbolData
modifier|&
name|SD
parameter_list|,
name|unsigned
name|Visibility
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|GetVisibility
parameter_list|(
specifier|const
name|MCSymbolData
modifier|&
name|SD
parameter_list|)
function_decl|;
specifier|static
name|void
name|setOther
parameter_list|(
name|MCSymbolData
modifier|&
name|SD
parameter_list|,
name|unsigned
name|Other
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|getOther
parameter_list|(
specifier|const
name|MCSymbolData
modifier|&
name|SD
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

