begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SIDefines.h - SI Helper Macros ----------------------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIDEFINES_H_
end_ifndef

begin_define
define|#
directive|define
name|SIDEFINES_H_
end_define

begin_define
define|#
directive|define
name|R_00B028_SPI_SHADER_PGM_RSRC1_PS
value|0x00B028
end_define

begin_define
define|#
directive|define
name|R_00B128_SPI_SHADER_PGM_RSRC1_VS
value|0x00B128
end_define

begin_define
define|#
directive|define
name|R_00B228_SPI_SHADER_PGM_RSRC1_GS
value|0x00B228
end_define

begin_define
define|#
directive|define
name|R_00B848_COMPUTE_PGM_RSRC1
value|0x00B848
end_define

begin_define
define|#
directive|define
name|S_00B028_VGPRS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3F)<< 0)
end_define

begin_define
define|#
directive|define
name|S_00B028_SGPRS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x0F)<< 6)
end_define

begin_define
define|#
directive|define
name|R_0286CC_SPI_PS_INPUT_ENA
value|0x0286CC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SIDEFINES_H_
end_comment

end_unit

