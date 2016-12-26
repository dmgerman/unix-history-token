begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- HexagonRDF.h -----------------------------------------------------===//
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
name|HEXAGON_RDF_H
end_ifndef

begin_define
define|#
directive|define
name|HEXAGON_RDF_H
end_define

begin_include
include|#
directive|include
file|"RDFGraph.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TargetRegisterInfo
decl_stmt|;
name|namespace
name|rdf
block|{
name|struct
name|HexagonRegisterAliasInfo
range|:
name|public
name|RegisterAliasInfo
block|{
name|HexagonRegisterAliasInfo
argument_list|(
specifier|const
name|TargetRegisterInfo
operator|&
name|TRI
argument_list|)
operator|:
name|RegisterAliasInfo
argument_list|(
argument|TRI
argument_list|)
block|{}
name|bool
name|covers
argument_list|(
argument|RegisterRef RA
argument_list|,
argument|RegisterRef RR
argument_list|)
specifier|const
name|override
block|;
name|bool
name|covers
argument_list|(
argument|const RegisterSet&RRs
argument_list|,
argument|RegisterRef RR
argument_list|)
specifier|const
name|override
block|;   }
decl_stmt|;
block|}
comment|// namespace rdf
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

