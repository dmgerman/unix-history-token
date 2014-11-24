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

begin_decl_stmt
name|namespace
name|SIInstrFlags
block|{
enum|enum
block|{
name|MIMG
init|=
literal|1
operator|<<
literal|3
block|,
name|SMRD
init|=
literal|1
operator|<<
literal|4
block|,
name|VOP1
init|=
literal|1
operator|<<
literal|5
block|,
name|VOP2
init|=
literal|1
operator|<<
literal|6
block|,
name|VOP3
init|=
literal|1
operator|<<
literal|7
block|,
name|VOPC
init|=
literal|1
operator|<<
literal|8
block|,
name|SALU
init|=
literal|1
operator|<<
literal|9
block|}
enum|;
block|}
end_decl_stmt

begin_define
define|#
directive|define
name|R_00B028_SPI_SHADER_PGM_RSRC1_PS
value|0x00B028
end_define

begin_define
define|#
directive|define
name|R_00B02C_SPI_SHADER_PGM_RSRC2_PS
value|0x00B02C
end_define

begin_define
define|#
directive|define
name|S_00B02C_EXTRA_LDS_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 8)
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
name|R_00B84C_COMPUTE_PGM_RSRC2
value|0x00B84C
end_define

begin_define
define|#
directive|define
name|S_00B02C_SCRATCH_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|S_00B84C_LDS_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FF)<< 15)
end_define

begin_define
define|#
directive|define
name|R_0286CC_SPI_PS_INPUT_ENA
value|0x0286CC
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
name|S_00B848_VGPRS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3F)<< 0)
end_define

begin_define
define|#
directive|define
name|G_00B848_VGPRS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3F)
end_define

begin_define
define|#
directive|define
name|C_00B848_VGPRS
value|0xFFFFFFC0
end_define

begin_define
define|#
directive|define
name|S_00B848_SGPRS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x0F)<< 6)
end_define

begin_define
define|#
directive|define
name|G_00B848_SGPRS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x0F)
end_define

begin_define
define|#
directive|define
name|C_00B848_SGPRS
value|0xFFFFFC3F
end_define

begin_define
define|#
directive|define
name|S_00B848_PRIORITY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x03)<< 10)
end_define

begin_define
define|#
directive|define
name|G_00B848_PRIORITY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x03)
end_define

begin_define
define|#
directive|define
name|C_00B848_PRIORITY
value|0xFFFFF3FF
end_define

begin_define
define|#
directive|define
name|S_00B848_FLOAT_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 12)
end_define

begin_define
define|#
directive|define
name|G_00B848_FLOAT_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xFF)
end_define

begin_define
define|#
directive|define
name|C_00B848_FLOAT_MODE
value|0xFFF00FFF
end_define

begin_define
define|#
directive|define
name|S_00B848_PRIV
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_00B848_PRIV
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00B848_PRIV
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_00B848_DX10_CLAMP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 21)
end_define

begin_define
define|#
directive|define
name|G_00B848_DX10_CLAMP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00B848_DX10_CLAMP
value|0xFFDFFFFF
end_define

begin_define
define|#
directive|define
name|S_00B848_DEBUG_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 22)
end_define

begin_define
define|#
directive|define
name|G_00B848_DEBUG_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00B848_DEBUG_MODE
value|0xFFBFFFFF
end_define

begin_define
define|#
directive|define
name|S_00B848_IEEE_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 23)
end_define

begin_define
define|#
directive|define
name|G_00B848_IEEE_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00B848_IEEE_MODE
value|0xFF7FFFFF
end_define

begin_comment
comment|// Helpers for setting FLOAT_MODE
end_comment

begin_define
define|#
directive|define
name|FP_ROUND_ROUND_TO_NEAREST
value|0
end_define

begin_define
define|#
directive|define
name|FP_ROUND_ROUND_TO_INF
value|1
end_define

begin_define
define|#
directive|define
name|FP_ROUND_ROUND_TO_NEGINF
value|2
end_define

begin_define
define|#
directive|define
name|FP_ROUND_ROUND_TO_ZERO
value|3
end_define

begin_comment
comment|// Bits 3:0 control rounding mode. 1:0 control single precision, 3:2 double
end_comment

begin_comment
comment|// precision.
end_comment

begin_define
define|#
directive|define
name|FP_ROUND_MODE_SP
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x3)
end_define

begin_define
define|#
directive|define
name|FP_ROUND_MODE_DP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 2)
end_define

begin_define
define|#
directive|define
name|FP_DENORM_FLUSH_IN_FLUSH_OUT
value|0
end_define

begin_define
define|#
directive|define
name|FP_DENORM_FLUSH_OUT
value|1
end_define

begin_define
define|#
directive|define
name|FP_DENORM_FLUSH_IN
value|2
end_define

begin_define
define|#
directive|define
name|FP_DENORM_FLUSH_NONE
value|3
end_define

begin_comment
comment|// Bits 7:4 control denormal handling. 5:4 control single precision, 6:7 double
end_comment

begin_comment
comment|// precision.
end_comment

begin_define
define|#
directive|define
name|FP_DENORM_MODE_SP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 4)
end_define

begin_define
define|#
directive|define
name|FP_DENORM_MODE_DP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 6)
end_define

begin_define
define|#
directive|define
name|R_00B860_COMPUTE_TMPRING_SIZE
value|0x00B860
end_define

begin_define
define|#
directive|define
name|S_00B860_WAVESIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FFF)<< 12)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SIDEFINES_H_
end_comment

end_unit

