begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*! \file sa.h  *  \brief The file defines the constants, data structure, and functions defined by LL API  */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SA_H__
end_ifndef

begin_define
define|#
directive|define
name|__SA_H__
end_define

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/api/sa_spec.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/api/sa_err.h>
end_include

begin_comment
comment|/* TestBase needed to have the 'Multi-Data fetch disable' feature */
end_comment

begin_define
define|#
directive|define
name|SA_CONFIG_MDFD_REGISTRY
end_define

begin_define
define|#
directive|define
name|OSSA_OFFSET_OF
parameter_list|(
name|STRUCT_TYPE
parameter_list|,
name|FEILD
parameter_list|)
define|\
value|(bitptr)&(((STRUCT_TYPE *)0)->FEILD)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SA_CPU_LITTLE_ENDIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|OSSA_WRITE_LE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE16
parameter_list|)
define|\
value|(*((bit16 *)(((bit8 *)DMA_ADDR)+(OFFSET)))) = (bit16)(VALUE16);
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_LE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE32
parameter_list|)
define|\
value|(*((bit32 *)(((bit8 *)DMA_ADDR)+(OFFSET)))) = (bit32)(VALUE32);
end_define

begin_define
define|#
directive|define
name|OSSA_READ_LE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR16
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*((bit16 *)ADDR16)) = (*((bit16 *)(((bit8 *)DMA_ADDR)+(OFFSET))))
end_define

begin_define
define|#
directive|define
name|OSSA_READ_LE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR32
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*((bit32 *)ADDR32)) = (*((bit32 *)(((bit8 *)DMA_ADDR)+(OFFSET))))
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE16
parameter_list|)
define|\
value|(*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))))   = (bit8)((((bit16)VALUE16)>>8)&0xFF);  \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))) = (bit8)(((bit16)VALUE16)&0xFF);
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE32
parameter_list|)
define|\
value|(*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))))   = (bit8)((((bit32)VALUE32)>>24)&0xFF); \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))) = (bit8)((((bit32)VALUE32)>>16)&0xFF); \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+2))) = (bit8)((((bit32)VALUE32)>>8)&0xFF);  \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+3))) = (bit8)(((bit32)VALUE32)&0xFF);
end_define

begin_define
define|#
directive|define
name|OSSA_READ_BE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR16
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*(bit8 *)(((bit8 *)ADDR16)+1)) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))));   \         (*(bit8 *)(((bit8 *)ADDR16)))   = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1)));
end_define

begin_define
define|#
directive|define
name|OSSA_READ_BE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR32
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*(bit8 *)(((bit8 *)ADDR32)+3)) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))));   \         (*(bit8 *)(((bit8 *)ADDR32)+2)) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))); \         (*(bit8 *)(((bit8 *)ADDR32)+1)) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+2))); \         (*(bit8 *)(((bit8 *)ADDR32)))   = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+3)));
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BYTE_STRING
parameter_list|(
name|AGROOT
parameter_list|,
name|DEST_ADDR
parameter_list|,
name|SRC_ADDR
parameter_list|,
name|LEN
parameter_list|)
define|\
value|si_memcpy(DEST_ADDR, SRC_ADDR, LEN);
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SA_CPU_BIG_ENDIAN
argument_list|)
end_elif

begin_define
define|#
directive|define
name|OSSA_WRITE_LE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE16
parameter_list|)
define|\
value|(*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))) = (bit8)((((bit16)VALUE16)>>8)&0xFF);   \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))))   = (bit8)(((bit16)VALUE16)&0xFF);
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_LE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE32
parameter_list|)
define|\
value|(*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+3))) = (bit8)((((bit32)VALUE32)>>24)&0xFF);  \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+2))) = (bit8)((((bit32)VALUE32)>>16)&0xFF);  \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))) = (bit8)((((bit32)VALUE32)>>8)&0xFF);   \         (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))))   = (bit8)(((bit32)VALUE32)&0xFF);
end_define

begin_define
define|#
directive|define
name|OSSA_READ_LE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR16
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*(bit8 *)(((bit8 *)ADDR16)+1)) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))));   \         (*(bit8 *)(((bit8 *)ADDR16)))   = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1)));
end_define

begin_define
define|#
directive|define
name|OSSA_READ_LE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR32
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*((bit8 *)(((bit8 *)ADDR32)+3))) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET))));   \         (*((bit8 *)(((bit8 *)ADDR32)+2))) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+1))); \         (*((bit8 *)(((bit8 *)ADDR32)+1))) = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+2))); \         (*((bit8 *)(((bit8 *)ADDR32))))   = (*((bit8 *)(((bit8 *)DMA_ADDR)+(OFFSET)+3)));
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE16
parameter_list|)
define|\
value|(*((bit16 *)(((bit8 *)DMA_ADDR)+(OFFSET)))) = (bit16)(VALUE16);
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|,
name|VALUE32
parameter_list|)
define|\
value|(*((bit32 *)(((bit8 *)DMA_ADDR)+(OFFSET)))) = (bit32)(VALUE32);
end_define

begin_define
define|#
directive|define
name|OSSA_READ_BE_16
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR16
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*((bit16 *)ADDR16)) = (*((bit16 *)(((bit8 *)DMA_ADDR)+(OFFSET))));
end_define

begin_define
define|#
directive|define
name|OSSA_READ_BE_32
parameter_list|(
name|AGROOT
parameter_list|,
name|ADDR32
parameter_list|,
name|DMA_ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(*((bit32 *)ADDR32)) = (*((bit32 *)(((bit8 *)DMA_ADDR)+(OFFSET))));
end_define

begin_define
define|#
directive|define
name|OSSA_WRITE_BYTE_STRING
parameter_list|(
name|AGROOT
parameter_list|,
name|DEST_ADDR
parameter_list|,
name|SRC_ADDR
parameter_list|,
name|LEN
parameter_list|)
define|\
value|si_memcpy(DEST_ADDR, SRC_ADDR, LEN);
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|(Host CPU endianess undefined!!)
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AGSA_WRITE_SGL
parameter_list|(
name|sglDest
parameter_list|,
name|sgLower
parameter_list|,
name|sgUpper
parameter_list|,
name|len
parameter_list|,
name|extReserved
parameter_list|)
define|\
value|OSSA_WRITE_LE_32(agRoot, sglDest, 0, sgLower);                  \         OSSA_WRITE_LE_32(agRoot, sglDest, 4, sgUpper);                  \         OSSA_WRITE_LE_32(agRoot, sglDest, 8, len);                      \         OSSA_WRITE_LE_32(agRoot, sglDest, 12, extReserved);
end_define

begin_comment
comment|/**************************************************************************  *                        define byte swap macro                          *  **************************************************************************/
end_comment

begin_comment
comment|/*! \def AGSA_FLIP_2_BYTES(_x) * \brief AGSA_FLIP_2_BYTES macro * * use to flip two bytes */
end_comment

begin_define
define|#
directive|define
name|AGSA_FLIP_2_BYTES
parameter_list|(
name|_x
parameter_list|)
value|((bit16)(((((bit16)(_x))&0x00FF)<<8)|  \                                      ((((bit16)(_x))&0xFF00)>>8)))
end_define

begin_comment
comment|/*! \def AGSA_FLIP_4_BYTES(_x) * \brief AGSA_FLIP_4_BYTES macro * * use to flip four bytes */
end_comment

begin_define
define|#
directive|define
name|AGSA_FLIP_4_BYTES
parameter_list|(
name|_x
parameter_list|)
value|((bit32)(((((bit32)(_x))&0x000000FF)<<24)|  \                                      ((((bit32)(_x))&0x0000FF00)<<8)|   \                                      ((((bit32)(_x))&0x00FF0000)>>8)|   \                                      ((((bit32)(_x))&0xFF000000)>>24)))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SA_CPU_LITTLE_ENDIAN
argument_list|)
end_if

begin_comment
comment|/*! \def LEBIT16_TO_BIT16(_x) * \brief LEBIT16_TO_BIT16 macro * * use to convert little endian bit16 to host bit16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|LEBIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def BIT16_TO_LEBIT16(_x) * \brief BIT16_TO_LEBIT16 macro * * use to convert host bit16 to little endian bit16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_LEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_LEBIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def BEBIT16_TO_BIT16(_x) * \brief BEBIT16_TO_BIT16 macro * * use to convert big endian bit16 to host bit16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|BEBIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def BIT16_TO_BEBIT16(_x) * \brief BIT16_TO_BEBIT16 macro * * use to convert host bit16 to big endian bit16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_BEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_BEBIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def LEBIT32_TO_BIT32(_x) * \brief LEBIT32_TO_BIT32 macro * * use to convert little endian bit32 to host bit32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|LEBIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def BIT32_TO_LEBIT32(_x) * \brief BIT32_TO_LEBIT32 macro * * use to convert host bit32 to little endian bit32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_LEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_LEBIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def BEBIT32_TO_BIT32(_x) * \brief BEBIT32_TO_BIT32 macro * * use to convert big endian bit32 to host bit32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|BEBIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def BIT32_TO_BEBIT32(_x) * \brief BIT32_TO_BEBIT32 macro * * use to convert host bit32 to big endian bit32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_BEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_BEBIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * bit8 to Byte[x] of bit32  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIT8_TO_BIT32_B0
end_ifndef

begin_define
define|#
directive|define
name|BIT8_TO_BIT32_B0
parameter_list|(
name|_x
parameter_list|)
value|((bit32)(_x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT8_TO_BIT32_B1
end_ifndef

begin_define
define|#
directive|define
name|BIT8_TO_BIT32_B1
parameter_list|(
name|_x
parameter_list|)
value|(((bit32)(_x))<< 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT8_TO_BIT32_B2
end_ifndef

begin_define
define|#
directive|define
name|BIT8_TO_BIT32_B2
parameter_list|(
name|_x
parameter_list|)
value|(((bit32)(_x))<< 16)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT8_TO_BIT32_B3
end_ifndef

begin_define
define|#
directive|define
name|BIT8_TO_BIT32_B3
parameter_list|(
name|_x
parameter_list|)
value|(((bit32)(_x))<< 24)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Byte[x] of bit32 to bit8  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_B0_TO_BIT8
end_ifndef

begin_define
define|#
directive|define
name|BIT32_B0_TO_BIT8
parameter_list|(
name|_x
parameter_list|)
value|((bit8)(((bit32)(_x))& 0x000000FF))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_B1_TO_BIT8
end_ifndef

begin_define
define|#
directive|define
name|BIT32_B1_TO_BIT8
parameter_list|(
name|_x
parameter_list|)
value|((bit8)((((bit32)(_x))& 0x0000FF00)>> 8))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_B2_TO_BIT8
end_ifndef

begin_define
define|#
directive|define
name|BIT32_B2_TO_BIT8
parameter_list|(
name|_x
parameter_list|)
value|((bit8)((((bit32)(_x))& 0x00FF0000)>> 16))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_B3_TO_BIT8
end_ifndef

begin_define
define|#
directive|define
name|BIT32_B3_TO_BIT8
parameter_list|(
name|_x
parameter_list|)
value|((bit8)((((bit32)(_x))& 0xFF000000)>> 24))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SA_CPU_BIG_ENDIAN
argument_list|)
end_elif

begin_comment
comment|/*! \def LEBIT16_TO_BIT16(_x) * \brief LEBIT16_TO_BIT16 macro * * use to convert little endian bit16 to host bit16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|LEBIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def BIT16_TO_LEBIT16(_x) * \brief BIT16_TO_LEBIT16 macro * * use to convert host bit16 to little endian bit16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_LEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_LEBIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def BEBIT16_TO_BIT16(_x) * \brief BEBIT16_TO_BIT16 macro * * use to convert big endian bit16 to host bit16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|BEBIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def BIT16_TO_BEBIT16(_x) * \brief BIT16_TO_BEBIT16 macro * * use to convert host bit16 to big endian bit16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_BEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_BEBIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def LEBIT32_TO_BIT32(_x) * \brief LEBIT32_TO_BIT32 macro * * use to convert little endian bit32 to host bit32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|LEBIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def BIT32_TO_LEBIT32(_x) * \brief BIT32_TO_LEBIT32 macro * * use to convert host bit32 to little endian bit32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_LEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_LEBIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def BEBIT32_TO_BIT32(_x) * \brief BEBIT32_TO_BIT32 macro * * use to convert big endian bit32 to host bit32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|BEBIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def BIT32_TO_BEBIT32(_x) * \brief BIT32_TO_BEBIT32 macro * * use to convert host bit32 to big endian bit32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_BEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_BEBIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * bit8 to Byte[x] of bit32  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIT8_TO_BIT32_B0
end_ifndef

begin_define
define|#
directive|define
name|BIT8_TO_BIT32_B0
parameter_list|(
name|_x
parameter_list|)
value|(((bit32)(_x))<< 24)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT8_TO_BIT32_B1
end_ifndef

begin_define
define|#
directive|define
name|BIT8_TO_BIT32_B1
parameter_list|(
name|_x
parameter_list|)
value|(((bit32)(_x))<< 16)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT8_TO_BIT32_B2
end_ifndef

begin_define
define|#
directive|define
name|BIT8_TO_BIT32_B2
parameter_list|(
name|_x
parameter_list|)
value|(((bit32)(_x))<< 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT8_TO_BIT32_B3
end_ifndef

begin_define
define|#
directive|define
name|BIT8_TO_BIT32_B3
parameter_list|(
name|_x
parameter_list|)
value|((bit32)(_x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Byte[x] of bit32 to bit8  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_B0_TO_BIT8
end_ifndef

begin_define
define|#
directive|define
name|BIT32_B0_TO_BIT8
parameter_list|(
name|_x
parameter_list|)
value|((bit8)((((bit32)(_x))& 0xFF000000)>> 24))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_B1_TO_BIT8
end_ifndef

begin_define
define|#
directive|define
name|BIT32_B1_TO_BIT8
parameter_list|(
name|_x
parameter_list|)
value|((bit8)((((bit32)(_x))& 0x00FF0000)>> 16))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_B2_TO_BIT8
end_ifndef

begin_define
define|#
directive|define
name|BIT32_B2_TO_BIT8
parameter_list|(
name|_x
parameter_list|)
value|((bit8)((((bit32)(_x))& 0x0000FF00)>> 8))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_B3_TO_BIT8
end_ifndef

begin_define
define|#
directive|define
name|BIT32_B3_TO_BIT8
parameter_list|(
name|_x
parameter_list|)
value|((bit8)(((bit32)(_x))& 0x000000FF))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|No definition of SA_CPU_BIG_ENDIAN or SA_CPU_LITTLE_ENDIAN
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SA_DMA_LITTLE_ENDIAN
argument_list|)
end_if

begin_comment
comment|/*  * ** bit32 to bit32  * */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|DMA_BIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_LEBIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|DMA_LEBIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BEBIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|DMA_BEBIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_DMA_BIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_DMA_BIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_DMA_LEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_DMA_LEBIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_DMA_BEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_DMA_BEBIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ** bit16 to bit16  * */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|DMA_BIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_LEBIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|DMA_LEBIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BEBIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|DMA_BEBIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_DMA_BIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_DMA_BIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_DMA_LEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_DMA_LEBIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_DMA_BEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_DMA_BEBIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SA_CPU_LITTLE_ENDIAN
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT32_TO_DMA_BEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BEBIT32_TO_DMA_BEBIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT32_TO_DMA_LEBIT32
end_ifndef

begin_define
define|#
directive|define
name|LEBIT32_TO_DMA_LEBIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_LEBIT32_TO_LEBIT32
end_ifndef

begin_define
define|#
directive|define
name|DMA_LEBIT32_TO_LEBIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BEBIT32_TO_BEBIT32
end_ifndef

begin_define
define|#
directive|define
name|DMA_BEBIT32_TO_BEBIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ** bit16 to bit16  * */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT16_TO_DMA_BEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BEBIT16_TO_DMA_BEBIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT16_TO_DMA_LEBIT16
end_ifndef

begin_define
define|#
directive|define
name|LEBIT16_TO_DMA_LEBIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_LEBIT16_TO_LEBIT16
end_ifndef

begin_define
define|#
directive|define
name|DMA_LEBIT16_TO_LEBIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BEBIT16_TO_BEBIT16
end_ifndef

begin_define
define|#
directive|define
name|DMA_BEBIT16_TO_BEBIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(SA_CPU_BIG_ENDIAN) */
end_comment

begin_comment
comment|/*  * ** bit32 to bit32  * */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT32_TO_DMA_BEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BEBIT32_TO_DMA_BEBIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT32_TO_DMA_LEBIT32
end_ifndef

begin_define
define|#
directive|define
name|LEBIT32_TO_DMA_LEBIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_LEBIT32_TO_LEBIT32
end_ifndef

begin_define
define|#
directive|define
name|DMA_LEBIT32_TO_LEBIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BEBIT32_TO_BEBIT32
end_ifndef

begin_define
define|#
directive|define
name|DMA_BEBIT32_TO_BEBIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ** bit16 to bit16  * */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT16_TO_DMA_BEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BEBIT16_TO_DMA_BEBIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT16_TO_DMA_LEBIT16
end_ifndef

begin_define
define|#
directive|define
name|LEBIT16_TO_DMA_LEBIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_LEBIT16_TO_LEBIT16
end_ifndef

begin_define
define|#
directive|define
name|DMA_LEBIT16_TO_LEBIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BEBIT16_TO_BEBIT16
end_ifndef

begin_define
define|#
directive|define
name|DMA_BEBIT16_TO_BEBIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * bit8 to Byte[x] of bit32  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIT8_TO_DMA_BIT32_B0
end_ifndef

begin_define
define|#
directive|define
name|BIT8_TO_DMA_BIT32_B0
parameter_list|(
name|_x
parameter_list|)
value|((bit32)(_x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT8_TO_DMA_BIT32_B1
end_ifndef

begin_define
define|#
directive|define
name|BIT8_TO_DMA_BIT32_B1
parameter_list|(
name|_x
parameter_list|)
value|(((bit32)(_x))<< 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT8_TO_DMA_BIT32_B2
end_ifndef

begin_define
define|#
directive|define
name|BIT8_TO_DMA_BIT32_B2
parameter_list|(
name|_x
parameter_list|)
value|(((bit32)(_x))<< 16)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT8_TO_DMA_BIT32_B3
end_ifndef

begin_define
define|#
directive|define
name|BIT8_TO_DMA_BIT32_B3
parameter_list|(
name|_x
parameter_list|)
value|(((bit32)(_x))<< 24)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Byte[x] of bit32 to bit8  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BIT32_B0_TO_BIT8
end_ifndef

begin_define
define|#
directive|define
name|DMA_BIT32_B0_TO_BIT8
parameter_list|(
name|_x
parameter_list|)
value|((bit8)(((bit32)(_x))& 0x000000FF))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BIT32_B1_TO_BIT8
end_ifndef

begin_define
define|#
directive|define
name|DMA_BIT32_B1_TO_BIT8
parameter_list|(
name|_x
parameter_list|)
value|((bit8)((((bit32)(_x))& 0x0000FF00)>> 8))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BIT32_B2_TO_BIT8
end_ifndef

begin_define
define|#
directive|define
name|DMA_BIT32_B2_TO_BIT8
parameter_list|(
name|_x
parameter_list|)
value|((bit8)((((bit32)(_x))& 0x00FF0000)>> 16))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BIT32_B3_TO_BIT8
end_ifndef

begin_define
define|#
directive|define
name|DMA_BIT32_B3_TO_BIT8
parameter_list|(
name|_x
parameter_list|)
value|((bit8)((((bit32)(_x))& 0xFF000000)>> 24))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*|                                                                   |   | end of DMA access macros for LITTLE ENDIAN                        |   ---------------------------------------------------------------------  */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SA_DMA_BIG_ENDIAN
argument_list|)
end_elif

begin_comment
comment|/* DMA big endian */
end_comment

begin_comment
comment|/*--------------------------------------------------------------------  | DMA buffer access macros for BIG ENDIAN                           |  |                                                                   |  */
end_comment

begin_comment
comment|/* bit32 to bit32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BEBIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|DMA_BEBIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_LEBIT32_TO_BIT32
end_ifndef

begin_define
define|#
directive|define
name|DMA_LEBIT32_TO_BIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_DMA_BIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_DMA_BIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_DMA_LEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_DMA_LEBIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT32_TO_DMA_BEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BIT32_TO_DMA_BEBIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bit16 to bit16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BEBIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|DMA_BEBIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_LEBIT16_TO_BIT16
end_ifndef

begin_define
define|#
directive|define
name|DMA_LEBIT16_TO_BIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_DMA_BIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_DMA_BIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_DMA_LEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_DMA_LEBIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT16_TO_DMA_BEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BIT16_TO_DMA_BEBIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SA_CPU_LITTLE_ENDIAN
argument_list|)
end_if

begin_comment
comment|/* CPU little endain */
end_comment

begin_comment
comment|/* bit32 to bit32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT32_TO_DMA_BEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BEBIT32_TO_DMA_BEBIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT32_TO_DMA_LEBIT32
end_ifndef

begin_define
define|#
directive|define
name|LEBIT32_TO_DMA_LEBIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_LEBIT32_TO_LEBIT32
end_ifndef

begin_define
define|#
directive|define
name|DMA_LEBIT32_TO_LEBIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BEBIT32_TO_BEBIT32
end_ifndef

begin_define
define|#
directive|define
name|DMA_BEBIT32_TO_BEBIT32
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_4_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bit16 to bit16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT16_TO_DMA_BEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BEBIT16_TO_DMA_BEBIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT16_TO_DMA_LEBIT16
end_ifndef

begin_define
define|#
directive|define
name|LEBIT16_TO_DMA_LEBIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_LEBIT16_TO_LEBIT16
end_ifndef

begin_define
define|#
directive|define
name|DMA_LEBIT16_TO_LEBIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BEBIT16_TO_BEBIT16
end_ifndef

begin_define
define|#
directive|define
name|DMA_BEBIT16_TO_BEBIT16
parameter_list|(
name|_x
parameter_list|)
value|AGSA_FLIP_2_BYTES(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(SA_CPU_BIG_ENDIAN) */
end_comment

begin_comment
comment|/* bit32 to bit32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT32_TO_DMA_BEBIT32
end_ifndef

begin_define
define|#
directive|define
name|BEBIT32_TO_DMA_BEBIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT32_TO_DMA_LEBIT32
end_ifndef

begin_define
define|#
directive|define
name|LEBIT32_TO_DMA_LEBIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_LEBIT32_TO_LEBIT32
end_ifndef

begin_define
define|#
directive|define
name|DMA_LEBIT32_TO_LEBIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BEBIT32_TO_BEBIT32
end_ifndef

begin_define
define|#
directive|define
name|DMA_BEBIT32_TO_BEBIT32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bit16 to bit16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BEBIT16_TO_DMA_BEBIT16
end_ifndef

begin_define
define|#
directive|define
name|BEBIT16_TO_DMA_BEBIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LEBIT16_TO_DMA_LEBIT16
end_ifndef

begin_define
define|#
directive|define
name|LEBIT16_TO_DMA_LEBIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_LEBIT16_TO_LEBIT16
end_ifndef

begin_define
define|#
directive|define
name|DMA_LEBIT16_TO_LEBIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BEBIT16_TO_BEBIT16
end_ifndef

begin_define
define|#
directive|define
name|DMA_BEBIT16_TO_BEBIT16
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * bit8 to Byte[x] of bit32  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIT8_TO_DMA_BIT32_B0
end_ifndef

begin_define
define|#
directive|define
name|BIT8_TO_DMA_BIT32_B0
parameter_list|(
name|_x
parameter_list|)
value|(((bit32)(_x))<< 24)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT8_TO_DMA_BIT32_B1
end_ifndef

begin_define
define|#
directive|define
name|BIT8_TO_DMA_BIT32_B1
parameter_list|(
name|_x
parameter_list|)
value|(((bit32)(_x))<< 16)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT8_TO_DMA_BIT32_B2
end_ifndef

begin_define
define|#
directive|define
name|BIT8_TO_DMA_BIT32_B2
parameter_list|(
name|_x
parameter_list|)
value|(((bit32)(_x))<< 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIT8_TO_DMA_BIT32_B3
end_ifndef

begin_define
define|#
directive|define
name|BIT8_TO_DMA_BIT32_B3
parameter_list|(
name|_x
parameter_list|)
value|((bit32)(_x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ** Byte[x] of bit32 to bit8  * */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BIT32_B0_TO_BIT8
end_ifndef

begin_define
define|#
directive|define
name|DMA_BIT32_B0_TO_BIT8
parameter_list|(
name|_x
parameter_list|)
value|((bit8)((((bit32)(_x))& 0xFF000000)>> 24))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BIT32_B1_TO_BIT8
end_ifndef

begin_define
define|#
directive|define
name|DMA_BIT32_B1_TO_BIT8
parameter_list|(
name|_x
parameter_list|)
value|((bit8)((((bit32)(_x))& 0x00FF0000)>> 16))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BIT32_B2_TO_BIT8
end_ifndef

begin_define
define|#
directive|define
name|DMA_BIT32_B2_TO_BIT8
parameter_list|(
name|_x
parameter_list|)
value|((bit8)((((bit32)(_x))& 0x0000FF00)>> 8))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BIT32_B3_TO_BIT8
end_ifndef

begin_define
define|#
directive|define
name|DMA_BIT32_B3_TO_BIT8
parameter_list|(
name|_x
parameter_list|)
value|((bit8)(((bit32)(_x))& 0x000000FF))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*|                                                                   |   | end of DMA access macros for BIG ENDIAN                           |   --------------------------------------------------------------------- */
end_comment

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|No definition of SA_DMA_BIG_ENDIAN or SA_DMA_LITTLE_ENDIAN
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DMA endian */
end_comment

begin_comment
comment|/*  * End of DMA buffer access macros                                   *  *                                                                    *  **********************************************************************  */
end_comment

begin_comment
comment|/************************************************************************************  *                                                                                  *  *               Constants defined for LL Layer starts                              *  *                                                                                  *  ************************************************************************************/
end_comment

begin_comment
comment|/*********************************************************  *   sTSDK LL revision and Interface revision, FW version  *********************************************************/
end_comment

begin_define
define|#
directive|define
name|FW_THIS_VERSION_SPC12G
value|0x03060005
end_define

begin_define
define|#
directive|define
name|FW_THIS_VERSION_SPC6G
value|0x02092400
end_define

begin_define
define|#
directive|define
name|FW_THIS_VERSION_SPC
value|0x01110000
end_define

begin_define
define|#
directive|define
name|STSDK_LL_INTERFACE_VERSION
value|0x20A
end_define

begin_define
define|#
directive|define
name|STSDK_LL_OLD_INTERFACE_VERSION
value|0x1
end_define

begin_comment
comment|/* SPC and SPCv before 02030401 */
end_comment

begin_define
define|#
directive|define
name|STSDK_LL_VERSION
value|FW_THIS_VERSION_SPC6G
end_define

begin_comment
comment|/**< current sTSDK version */
end_comment

begin_define
define|#
directive|define
name|MAX_FW_VERSION_SUPPORTED
value|FW_THIS_VERSION_SPC6G
end_define

begin_comment
comment|/**< FW */
end_comment

begin_define
define|#
directive|define
name|MATCHING_V_FW_VERSION
value|FW_THIS_VERSION_SPC6G
end_define

begin_comment
comment|/**< current V  matching FW version */
end_comment

begin_define
define|#
directive|define
name|MIN_FW_SPCVE_VERSION_SUPPORTED
value|0x02000000
end_define

begin_comment
comment|/**< 2.00 FW */
end_comment

begin_define
define|#
directive|define
name|STSDK_LL_12G_INTERFACE_VERSION
value|0x302
end_define

begin_define
define|#
directive|define
name|STSDK_LL_12G_VERSION
value|FW_THIS_VERSION_SPC12G
end_define

begin_comment
comment|/**< current sTSDK version */
end_comment

begin_define
define|#
directive|define
name|MAX_FW_12G_VERSION_SUPPORTED
value|FW_THIS_VERSION_SPC12G
end_define

begin_comment
comment|/**< FW */
end_comment

begin_define
define|#
directive|define
name|MATCHING_12G_V_FW_VERSION
value|FW_THIS_VERSION_SPC12G
end_define

begin_comment
comment|/**< current V  matching FW version */
end_comment

begin_define
define|#
directive|define
name|MIN_FW_12G_SPCVE_VERSION_SUPPORTED
value|0x03000000
end_define

begin_comment
comment|/**< 3.00 FW */
end_comment

begin_define
define|#
directive|define
name|STSDK_LL_SPC_VERSION
value|0x01100000
end_define

begin_comment
comment|/**< current SPC FW version supported */
end_comment

begin_define
define|#
directive|define
name|MATCHING_SPC_FW_VERSION
value|FW_THIS_VERSION_SPC
end_define

begin_comment
comment|/**< current SPC matching FW version */
end_comment

begin_define
define|#
directive|define
name|MIN_FW_SPC_VERSION_SUPPORTED
value|0x01062502
end_define

begin_comment
comment|/**< 1.06d FW */
end_comment

begin_define
define|#
directive|define
name|STSDK_LL_INTERFACE_VERSION_IGNORE_MASK
value|0xF00
end_define

begin_comment
comment|/*************************************************  *   constants for API return values  *************************************************/
end_comment

begin_define
define|#
directive|define
name|AGSA_RC_SUCCESS
value|0x00
end_define

begin_comment
comment|/**< Successful function return value */
end_comment

begin_define
define|#
directive|define
name|AGSA_RC_FAILURE
value|0x01
end_define

begin_comment
comment|/**< Failed function return value */
end_comment

begin_define
define|#
directive|define
name|AGSA_RC_BUSY
value|0x02
end_define

begin_comment
comment|/**< Busy function return value */
end_comment

begin_comment
comment|/* current only return from saGetControllerInfo() and saGetControllerStatus() */
end_comment

begin_define
define|#
directive|define
name|AGSA_RC_HDA_NO_FW_RUNNING
value|0x03
end_define

begin_comment
comment|/**< HDA mode and no FW running */
end_comment

begin_define
define|#
directive|define
name|AGSA_RC_FW_NOT_IN_READY_STATE
value|0x04
end_define

begin_comment
comment|/**< FW not in ready state */
end_comment

begin_comment
comment|/* current only return from saInitialize() for version checking */
end_comment

begin_define
define|#
directive|define
name|AGSA_RC_VERSION_INCOMPATIBLE
value|0x05
end_define

begin_comment
comment|/**< Version mismatch */
end_comment

begin_define
define|#
directive|define
name|AGSA_RC_VERSION_UNTESTED
value|0x06
end_define

begin_comment
comment|/**< Version not tested */
end_comment

begin_define
define|#
directive|define
name|AGSA_RC_NOT_SUPPORTED
value|0x07
end_define

begin_comment
comment|/**< Operation not supported on the current hardware */
end_comment

begin_define
define|#
directive|define
name|AGSA_RC_COMPLETE
value|0x08
end_define

begin_comment
comment|/*************************************************  *   constants for type field in agsaMem_t  *************************************************/
end_comment

begin_define
define|#
directive|define
name|AGSA_CACHED_MEM
value|0x00
end_define

begin_comment
comment|/**< CACHED memory type */
end_comment

begin_define
define|#
directive|define
name|AGSA_DMA_MEM
value|0x01
end_define

begin_comment
comment|/**< DMA memory type */
end_comment

begin_define
define|#
directive|define
name|AGSA_CACHED_DMA_MEM
value|0x02
end_define

begin_comment
comment|/**< CACHED DMA memory type */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SA_ENABLE_TRACE_FUNCTIONS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|FAST_IO_TEST
end_ifdef

begin_define
define|#
directive|define
name|AGSA_NUM_MEM_CHUNKS
value|(12 + AGSA_MAX_INBOUND_Q + AGSA_MAX_OUTBOUND_Q)
end_define

begin_comment
comment|/**< max # of memory chunks supported */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AGSA_NUM_MEM_CHUNKS
value|(11 + AGSA_MAX_INBOUND_Q + AGSA_MAX_OUTBOUND_Q)
end_define

begin_comment
comment|/**< max # of memory chunks supported */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|FAST_IO_TEST
end_ifdef

begin_define
define|#
directive|define
name|AGSA_NUM_MEM_CHUNKS
value|(11 + AGSA_MAX_INBOUND_Q + AGSA_MAX_OUTBOUND_Q)
end_define

begin_comment
comment|/**< max # of memory chunks supported */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AGSA_NUM_MEM_CHUNKS
value|(10 + AGSA_MAX_INBOUND_Q + AGSA_MAX_OUTBOUND_Q)
end_define

begin_comment
comment|/**< max # of memory chunks supported */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END SA_ENABLE_TRACE_FUNCTIONS */
end_comment

begin_comment
comment|/**********************************  * default constant for phy count  **********************************/
end_comment

begin_define
define|#
directive|define
name|AGSA_MAX_VALID_PHYS
value|16
end_define

begin_comment
comment|/* was 8 for SPC */
end_comment

begin_comment
comment|/**< max # of phys supported by the hardware */
end_comment

begin_comment
comment|/************************************  * default constant for Esgl entries  ************************************/
end_comment

begin_define
define|#
directive|define
name|MAX_ESGL_ENTRIES
value|10
end_define

begin_comment
comment|/**< max # of extended SG list entry */
end_comment

begin_comment
comment|/*******************************************  * constant for max inbound/outbound queues  *******************************************/
end_comment

begin_define
define|#
directive|define
name|AGSA_MAX_INBOUND_Q
value|64
end_define

begin_comment
comment|/**< max # of inbound queue */
end_comment

begin_define
define|#
directive|define
name|AGSA_MAX_OUTBOUND_Q
value|64
end_define

begin_comment
comment|/**< max # of outbound queue */
end_comment

begin_define
define|#
directive|define
name|AGSA_MAX_BEST_INBOUND_Q
value|16
end_define

begin_comment
comment|/* Max inbound Q number with good IO performance */
end_comment

begin_comment
comment|/****************************  *   Phy Control constants  ****************************/
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_LINK_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|AGSA_PHY_HARD_RESET
value|0x02
end_define

begin_define
define|#
directive|define
name|AGSA_PHY_GET_ERROR_COUNTS
value|0x03
end_define

begin_comment
comment|/* SPC only used in original saLocalPhyControl */
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_CLEAR_ERROR_COUNTS
value|0x04
end_define

begin_comment
comment|/* SPC only */
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_GET_BW_COUNTS
value|0x05
end_define

begin_comment
comment|/* SPC only */
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_NOTIFY_ENABLE_SPINUP
value|0x10
end_define

begin_define
define|#
directive|define
name|AGSA_PHY_BROADCAST_ASYNCH_EVENT
value|0x12
end_define

begin_define
define|#
directive|define
name|AGSA_PHY_COMINIT_OOB
value|0x20
end_define

begin_define
define|#
directive|define
name|AGSA_SAS_PHY_ERR_COUNTERS_PAGE
value|0x01
end_define

begin_comment
comment|/* retrieve the SAS PHY error counters */
end_comment

begin_define
define|#
directive|define
name|AGSA_SAS_PHY_ERR_COUNTERS_CLR_PAGE
value|0x02
end_define

begin_comment
comment|/* retrieve the SAS PHY error counters After capturing the errors, the hardware error counters are cleared and restarted. */
end_comment

begin_define
define|#
directive|define
name|AGSA_SAS_PHY_BW_COUNTERS_PAGE
value|0x03
end_define

begin_comment
comment|/* retrieve the SAS PHY transmit and receive bandwidth counters. */
end_comment

begin_define
define|#
directive|define
name|AGSA_SAS_PHY_ANALOG_SETTINGS_PAGE
value|0x04
end_define

begin_comment
comment|/* retrieve the SAS PHY analog settings  */
end_comment

begin_define
define|#
directive|define
name|AGSA_SAS_PHY_GENERAL_STATUS_PAGE
value|0x05
end_define

begin_comment
comment|/* retrieve the SAS PHY general status for the PHY specified in the phyID parameter   */
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_SNW3_PAGE
value|0x06
end_define

begin_define
define|#
directive|define
name|AGSA_PHY_RATE_CONTROL_PAGE
value|0x07
end_define

begin_comment
comment|/* Used to set several rate control parameters. */
end_comment

begin_define
define|#
directive|define
name|AGSA_SAS_PHY_MISC_PAGE
value|0x08
end_define

begin_define
define|#
directive|define
name|AGSA_SAS_PHY_OPEN_REJECT_RETRY_BACKOFF_THRESHOLD_PAGE
value|0x08
end_define

begin_comment
comment|/* Used to set retry and backoff threshold  parameters. */
end_comment

begin_comment
comment|/*****************  * HW Reset  *****************/
end_comment

begin_define
define|#
directive|define
name|AGSA_CHIP_RESET
value|0x00
end_define

begin_comment
comment|/**< flag to reset hard reset */
end_comment

begin_define
define|#
directive|define
name|AGSA_SOFT_RESET
value|0x01
end_define

begin_comment
comment|/**< flag to reset the controller chip */
end_comment

begin_comment
comment|/***************************************  * Discovery Types  ***************************************/
end_comment

begin_define
define|#
directive|define
name|AG_SA_DISCOVERY_TYPE_SAS
value|0x00
end_define

begin_comment
comment|/**< flag to discover SAS devices */
end_comment

begin_define
define|#
directive|define
name|AG_SA_DISCOVERY_TYPE_SATA
value|0x01
end_define

begin_comment
comment|/**< flag to discover SATA devices */
end_comment

begin_comment
comment|/***************************************  * Discovery Options  ***************************************/
end_comment

begin_define
define|#
directive|define
name|AG_SA_DISCOVERY_OPTION_FULL_START
value|0x00
end_define

begin_comment
comment|/**< flag to start full discovery */
end_comment

begin_define
define|#
directive|define
name|AG_SA_DISCOVERY_OPTION_INCREMENTAL_START
value|0x01
end_define

begin_comment
comment|/**< flag to start incremental discovery */
end_comment

begin_define
define|#
directive|define
name|AG_SA_DISCOVERY_OPTION_ABORT
value|0x02
end_define

begin_comment
comment|/**< flag to abort a discovery */
end_comment

begin_comment
comment|/****************************************************************  * SSP/SMP/SATA Request type  ****************************************************************/
end_comment

begin_comment
comment|/* bit31-28 - request type    bit27-16 - reserved    bit15-10 - SATA ATAP    bit9-8   - direction    bit7     - AUTO    bit6     - reserved    bit5     - EXT    bit4     - MSG    bit3-0   - Initiator, target or task mode (1 to 8)    */
end_comment

begin_define
define|#
directive|define
name|AGSA_REQTYPE_MASK
value|0xF0000000
end_define

begin_comment
comment|/**< request type mask */
end_comment

begin_define
define|#
directive|define
name|AGSA_REQ_TYPE_UNKNOWN
value|0x00000000
end_define

begin_comment
comment|/**< unknown request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_REQTYPE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AGSA_SMP_REQTYPE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_REQTYPE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AGSA_DIR_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|AGSA_AUTO_MASK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_ATAP_MASK
value|0x0000FC00
end_define

begin_define
define|#
directive|define
name|AGSA_DIR_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AGSA_DIR_CONTROLLER_TO_HOST
value|0x00000100
end_define

begin_comment
comment|/**< used to be called AGSA_DIR_READ */
end_comment

begin_define
define|#
directive|define
name|AGSA_DIR_HOST_TO_CONTROLLER
value|0x00000200
end_define

begin_comment
comment|/**< used to be called AGSA_DIR_WRITE */
end_comment

begin_comment
comment|/* bit definition - AUTO mode */
end_comment

begin_define
define|#
directive|define
name|AGSA_AUTO_GOOD_RESPONSE
value|0x00000080
end_define

begin_comment
comment|/* request type - not bit difination */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_INIT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_MODE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AGSA_SSP_TASK_MGNT
value|0x00000005
end_define

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_RSP
value|0x00000006
end_define

begin_define
define|#
directive|define
name|AGSA_SMP_INIT
value|0x00000007
end_define

begin_define
define|#
directive|define
name|AGSA_SMP_TGT
value|0x00000008
end_define

begin_comment
comment|/* request type for SSP Initiator and extend */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_INIT_EXT
value|(AGSA_SSP_INIT | AGSA_SSP_EXT_BIT)
end_define

begin_comment
comment|/* request type for SSP Initiator and indirect */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_INIT_INDIRECT
value|(AGSA_SSP_INIT | AGSA_SSP_INDIRECT_BIT)
end_define

begin_comment
comment|/* bit definition */
end_comment

begin_define
define|#
directive|define
name|AGSA_MSG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AGSA_SSP_EXT_BIT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AGSA_SSP_INDIRECT_BIT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AGSA_MSG_BIT
value|AGSA_MSG>> 2
end_define

begin_comment
comment|/* agsaSSPIniEncryptIOStartCmd_t dirMTlr bits*/
end_comment

begin_define
define|#
directive|define
name|AGSA_INDIRECT_CDB_BIT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AGSA_SKIP_MASK_BIT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AGSA_ENCRYPT_BIT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_BIT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_LA_BIT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AGSA_DIRECTION_BITS
value|0x00000300
end_define

begin_define
define|#
directive|define
name|AGSA_SKIP_MASK_OFFSET_BITS
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|AGSA_SSP_INFO_LENGTH_BITS
value|0xF0000000
end_define

begin_comment
comment|/*  agsaSSPTgtIOStartCmd_t INITagAgrDir bits */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_BITS_INI_TAG
value|0xFFFF0000
end_define

begin_comment
comment|/* 16 31  */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_BITS_ODS
value|0x00008000
end_define

begin_comment
comment|/* 15 */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_BITS_DEE_DIF
value|0x00004000
end_define

begin_comment
comment|/* 14 */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_BITS_DEE
value|0x00002000
end_define

begin_comment
comment|/* 13 14 */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_BITS_R
value|0x00001000
end_define

begin_comment
comment|/* 12 */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_BITS_DAD
value|0x00000600
end_define

begin_comment
comment|/* 11 10 */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_BITS_DIR
value|0x00000300
end_define

begin_comment
comment|/* 8 9 */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_BITS_DIR_IN
value|0x00000100
end_define

begin_comment
comment|/* 8 9 */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_BITS_DIR_OUT
value|0x00000200
end_define

begin_comment
comment|/* 8 9 */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_BITS_AGR
value|0x00000080
end_define

begin_comment
comment|/* 7 */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_BITS_RDF
value|0x00000040
end_define

begin_comment
comment|/* 6 */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_BITS_RTE
value|0x00000030
end_define

begin_comment
comment|/* 4 5 */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_BITS_AN
value|0x00000006
end_define

begin_comment
comment|/* 2 3 */
end_comment

begin_comment
comment|/* agsaSSPIniEncryptIOStartCmd_t DIF_flags bit definitions */
end_comment

begin_define
define|#
directive|define
name|AGSA_DIF_UPDATE_BITS
value|0xFC000000
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_VERIFY_BITS
value|0x03F00000
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_BLOCK_SIZE_BITS
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_ENABLE_BLOCK_COUNT_BIT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_CRC_SEED_BIT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_CRC_INVERT_BIT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_CRC_VERIFY_BIT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_OP_BITS
value|0x00000007
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_OP_INSERT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_OP_VERIFY_AND_FORWARD
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_OP_VERIFY_AND_DELETE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_OP_VERIFY_AND_REPLACE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_OP_RESERVED2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_OP_VERIFY_UDT_REPLACE_CRC
value|0x00000005
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_OP_RESERVED3
value|0x00000006
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_OP_REPLACE_UDT_REPLACE_CRC
value|0x00000007
end_define

begin_comment
comment|/* agsaSSPIniEncryptIOStartCmd_t EncryptFlagsLo bit definitions */
end_comment

begin_define
define|#
directive|define
name|AGSA_ENCRYPT_DEK_BITS
value|0xFFFFFF000
end_define

begin_define
define|#
directive|define
name|AGSA_ENCRYPT_SKIP_DIF_BIT
value|0x000000010
end_define

begin_define
define|#
directive|define
name|AGSA_ENCRYPT_KEY_TABLE_BITS
value|0x00000000C
end_define

begin_define
define|#
directive|define
name|AGSA_ENCRYPT_KEY_TAG_BIT
value|0x000000002
end_define

begin_comment
comment|/* Cipher mode to be used for this I/O. */
end_comment

begin_define
define|#
directive|define
name|AGSA_ENCRYPT_ECB_Mode
value|0
end_define

begin_define
define|#
directive|define
name|AGSA_ENCRYPT_XTS_Mode
value|0x6
end_define

begin_comment
comment|/* agsaSSPIniEncryptIOStartCmd_t EncryptFlagsHi bit definitions */
end_comment

begin_define
define|#
directive|define
name|AGSA_ENCRYPT_KEK_SELECT_BITS
value|0x0000000E0
end_define

begin_define
define|#
directive|define
name|AGSA_ENCRYPT_SECTOR_SIZE_BITS
value|0x00000001F
end_define

begin_comment
comment|/* defined in the sTSDK spec. */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_INIT_NONDATA
value|(AGSA_SSP_REQTYPE | AGSA_DIR_NONE | AGSA_SSP_INIT)
end_define

begin_comment
comment|/**< SSP initiator non data request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_INIT_READ
value|(AGSA_SSP_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SSP_INIT)
end_define

begin_comment
comment|/**< SSP initiator read request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_INIT_WRITE
value|(AGSA_SSP_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SSP_INIT)
end_define

begin_comment
comment|/**< SSP initiator write request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_READ_DATA
value|(AGSA_SSP_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SSP_TGT_MODE)
end_define

begin_comment
comment|/**< SSP target read data request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_READ
value|(AGSA_SSP_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SSP_TGT_MODE)
end_define

begin_comment
comment|/**< SSP target read data request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_READ_GOOD_RESP
value|(AGSA_SSP_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SSP_TGT_MODE | AGSA_AUTO_GOOD_RESPONSE)
end_define

begin_comment
comment|/**< SSP target read data with automatic good response request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_WRITE_DATA
value|(AGSA_SSP_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SSP_TGT_MODE)
end_define

begin_comment
comment|/**< SSP target write data request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_WRITE
value|(AGSA_SSP_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SSP_TGT_MODE)
end_define

begin_comment
comment|/**< SSP target write data request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_WRITE_GOOD_RESP
value|(AGSA_SSP_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SSP_TGT_MODE  | AGSA_AUTO_GOOD_RESPONSE)
end_define

begin_comment
comment|/**< SSP target write data request type with automatic good response request type*/
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TASK_MGNT_REQ
value|(AGSA_SSP_REQTYPE | AGSA_SSP_TASK_MGNT)
end_define

begin_comment
comment|/**< SSP task management request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_TGT_CMD_OR_TASK_RSP
value|(AGSA_SSP_REQTYPE | AGSA_SSP_TGT_RSP)
end_define

begin_comment
comment|/**< SSP command or task management response request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SMP_INIT_REQ
value|(AGSA_SMP_REQTYPE | AGSA_SMP_INIT)
end_define

begin_comment
comment|/**< SMP initiator request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SMP_TGT_RESPONSE
value|(AGSA_SMP_REQTYPE | AGSA_SMP_TGT)
end_define

begin_comment
comment|/**< SMP target response request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_INIT_READ_M
value|(AGSA_SSP_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SSP_INIT | AGSA_MSG)
end_define

begin_define
define|#
directive|define
name|AGSA_SSP_INIT_WRITE_M
value|(AGSA_SSP_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SSP_INIT | AGSA_MSG)
end_define

begin_define
define|#
directive|define
name|AGSA_SSP_TASK_MGNT_REQ_M
value|(AGSA_SSP_REQTYPE | AGSA_SSP_TASK_MGNT                          | AGSA_MSG)
end_define

begin_define
define|#
directive|define
name|AGSA_SSP_INIT_READ_EXT
value|(AGSA_SSP_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SSP_INIT_EXT)
end_define

begin_comment
comment|/**< SSP initiator read request Ext type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_INIT_WRITE_EXT
value|(AGSA_SSP_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SSP_INIT_EXT)
end_define

begin_comment
comment|/**< SSP initiator write request Ext type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_INIT_READ_INDIRECT
value|(AGSA_SSP_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SSP_INIT_INDIRECT)
end_define

begin_comment
comment|/**< SSP initiator read request indirect type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_INIT_WRITE_INDIRECT
value|(AGSA_SSP_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SSP_INIT_INDIRECT)
end_define

begin_comment
comment|/**< SSP initiator write request indirect type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_INIT_READ_INDIRECT_M
value|(AGSA_SSP_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SSP_INIT_INDIRECT | AGSA_MSG)
end_define

begin_comment
comment|/**< SSP initiator read request indirect type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_INIT_WRITE_INDIRECT_M
value|(AGSA_SSP_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SSP_INIT_INDIRECT | AGSA_MSG)
end_define

begin_comment
comment|/**< SSP initiator write request indirect type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SSP_INIT_READ_EXT_M
value|(AGSA_SSP_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SSP_INIT_EXT | AGSA_MSG)
end_define

begin_define
define|#
directive|define
name|AGSA_SSP_INIT_WRITE_EXT_M
value|(AGSA_SSP_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SSP_INIT_EXT | AGSA_MSG)
end_define

begin_define
define|#
directive|define
name|AGSA_SMP_IOCTL_REQUEST
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_ATAP_SRST_ASSERT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_ATAP_SRST_DEASSERT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_ATAP_EXECDEVDIAG
value|0x00000C00
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_ATAP_NON_DATA
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_ATAP_PIO
value|0x00001400
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_ATAP_DMA
value|0x00001800
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_ATAP_NCQ
value|0x00001C00
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_ATAP_PKT_DEVRESET
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_ATAP_PKT
value|0x00002400
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_NON_DATA
value|(AGSA_SATA_REQTYPE | AGSA_DIR_NONE  | AGSA_SATA_ATAP_NON_DATA)
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_PIO_READ
value|(AGSA_SATA_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SATA_ATAP_PIO)
end_define

begin_comment
comment|/**< SATA PIO read request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_DMA_READ
value|(AGSA_SATA_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SATA_ATAP_DMA)
end_define

begin_comment
comment|/**< SATA DMA read request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_FPDMA_READ
value|(AGSA_SATA_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SATA_ATAP_NCQ)
end_define

begin_comment
comment|/**< SATA FDMA read request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_PIO_WRITE
value|(AGSA_SATA_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SATA_ATAP_PIO)
end_define

begin_comment
comment|/**< SATA PIO read request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_DMA_WRITE
value|(AGSA_SATA_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SATA_ATAP_DMA)
end_define

begin_comment
comment|/**< SATA DMA read request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_FPDMA_WRITE
value|(AGSA_SATA_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SATA_ATAP_NCQ)
end_define

begin_comment
comment|/**< SATA FDMA read request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_DEV_RESET
value|(AGSA_SATA_REQTYPE | AGSA_DIR_NONE  | AGSA_SATA_ATAP_PKT_DEVRESET)
end_define

begin_comment
comment|/**< SATA device reset request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_SRST_ASSERT
value|(AGSA_SATA_REQTYPE | AGSA_DIR_NONE  | AGSA_SATA_ATAP_SRST_ASSERT)
end_define

begin_comment
comment|/**< SATA device reset assert */
end_comment

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_SRST_DEASSERT
value|(AGSA_SATA_REQTYPE | AGSA_DIR_NONE  | AGSA_SATA_ATAP_SRST_DEASSERT)
end_define

begin_comment
comment|/**< SATA device reset deassert */
end_comment

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_D2H_PKT
value|(AGSA_SATA_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SATA_ATAP_PKT)
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_H2D_PKT
value|(AGSA_SATA_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SATA_ATAP_PKT)
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_NON_PKT
value|(AGSA_SATA_REQTYPE | AGSA_DIR_NONE | AGSA_SATA_ATAP_PKT)
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_NON_DATA_M
value|(AGSA_SATA_REQTYPE | AGSA_DIR_NONE          | AGSA_SATA_ATAP_NON_DATA | AGSA_MSG)
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_PIO_READ_M
value|(AGSA_SATA_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SATA_ATAP_PIO | AGSA_MSG)
end_define

begin_comment
comment|/**< SATA PIO read request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_DMA_READ_M
value|(AGSA_SATA_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SATA_ATAP_DMA | AGSA_MSG)
end_define

begin_comment
comment|/**< SATA DMA read request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_FPDMA_READ_M
value|(AGSA_SATA_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SATA_ATAP_NCQ | AGSA_MSG)
end_define

begin_comment
comment|/**< SATA FDMA read request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_PIO_WRITE_M
value|(AGSA_SATA_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SATA_ATAP_PIO | AGSA_MSG)
end_define

begin_comment
comment|/**< SATA PIO read request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_DMA_WRITE_M
value|(AGSA_SATA_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SATA_ATAP_DMA | AGSA_MSG)
end_define

begin_comment
comment|/**< SATA DMA read request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_FPDMA_WRITE_M
value|(AGSA_SATA_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SATA_ATAP_NCQ | AGSA_MSG)
end_define

begin_comment
comment|/**< SATA FDMA read request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_D2H_PKT_M
value|(AGSA_SATA_REQTYPE | AGSA_DIR_CONTROLLER_TO_HOST | AGSA_SATA_ATAP_PKT | AGSA_MSG)
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_H2D_PKT_M
value|(AGSA_SATA_REQTYPE | AGSA_DIR_HOST_TO_CONTROLLER | AGSA_SATA_ATAP_PKT | AGSA_MSG)
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_NON_PKT_M
value|(AGSA_SATA_REQTYPE | AGSA_DIR_NONE               | AGSA_SATA_ATAP_PKT | AGSA_MSG)
end_define

begin_comment
comment|/* TestBase */
end_comment

begin_define
define|#
directive|define
name|AGSA_SATA_PROTOCOL_DEV_RESET_M
value|(AGSA_SATA_REQTYPE | AGSA_DIR_NONE  | AGSA_SATA_ATAP_PKT_DEVRESET     | AGSA_MSG)
end_define

begin_comment
comment|/**< SATA device reset request type */
end_comment

begin_define
define|#
directive|define
name|AGSA_INTERRUPT_HANDLE_ALL_CHANNELS
value|0xFFFFFFFF
end_define

begin_comment
comment|/**< flag indicates handles interrupts for all channles */
end_comment

begin_comment
comment|/**************************************************************************** ** INBOUND Queue related macros ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|AGSA_IBQ_PRIORITY_NORMAL
value|0x0
end_define

begin_define
define|#
directive|define
name|AGSA_IBQ_PRIORITY_HIGH
value|0x1
end_define

begin_comment
comment|/**************************************************************************** ** Phy properties related macros ****************************************************************************/
end_comment

begin_comment
comment|/* link rate */
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_MAX_LINK_RATE_MASK
value|0x0000000F
end_define

begin_comment
comment|/* bits 0-3 */
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_MAX_LINK_RATE_1_5G
value|0x00000001
end_define

begin_comment
comment|/* 0001b */
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_MAX_LINK_RATE_3_0G
value|0x00000002
end_define

begin_comment
comment|/* 0010b */
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_MAX_LINK_RATE_6_0G
value|0x00000004
end_define

begin_comment
comment|/* 0100b */
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_MAX_LINK_RATE_12_0G
value|0x00000008
end_define

begin_comment
comment|/* 1000b */
end_comment

begin_comment
comment|/* SAS/SATA mode */
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_MODE_MASK
value|0x00000030
end_define

begin_comment
comment|/* bits 4-5 */
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_MODE_SAS
value|0x00000010
end_define

begin_comment
comment|/* 01b */
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_MODE_SATA
value|0x00000020
end_define

begin_comment
comment|/* 10b */
end_comment

begin_comment
comment|/* control spin-up hold */
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_SPIN_UP_HOLD_MASK
value|0x00000040
end_define

begin_comment
comment|/* bit6 */
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_SPIN_UP_HOLD_ON
value|0x00000040
end_define

begin_comment
comment|/* 1b */
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_SPIN_UP_HOLD_OFF
value|0x00000000
end_define

begin_comment
comment|/* 0b */
end_comment

begin_comment
comment|/**************************************************************************** ** Device Info related macros ****************************************************************************/
end_comment

begin_comment
comment|/* S (SAS/SATA) */
end_comment

begin_define
define|#
directive|define
name|AGSA_DEV_INFO_SASSATA_MASK
value|0x00000010
end_define

begin_comment
comment|/* bit 4 */
end_comment

begin_define
define|#
directive|define
name|AGSA_DEV_INFO_SASSATA_SAS
value|0x00000010
end_define

begin_comment
comment|/* 1b */
end_comment

begin_define
define|#
directive|define
name|AGSA_DEV_INFO_SASSATA_SATA
value|0x00000000
end_define

begin_comment
comment|/* 0b */
end_comment

begin_comment
comment|/* Rate (link-rate) */
end_comment

begin_define
define|#
directive|define
name|AGSA_DEV_INFO_RATE_MASK
value|0x0000000F
end_define

begin_comment
comment|/* bits 0-3 */
end_comment

begin_define
define|#
directive|define
name|AGSA_DEV_INFO_RATE_1_5G
value|0x00000008
end_define

begin_comment
comment|/* 8h */
end_comment

begin_define
define|#
directive|define
name|AGSA_DEV_INFO_RATE_3_0G
value|0x00000009
end_define

begin_comment
comment|/* 9h */
end_comment

begin_define
define|#
directive|define
name|AGSA_DEV_INFO_RATE_6_0G
value|0x0000000A
end_define

begin_comment
comment|/* Ah */
end_comment

begin_define
define|#
directive|define
name|AGSA_DEV_INFO_RATE_12_0G
value|0x0000000B
end_define

begin_comment
comment|/* Bh */
end_comment

begin_comment
comment|/* devType */
end_comment

begin_define
define|#
directive|define
name|AGSA_DEV_INFO_DEV_TYPE_MASK
value|0x000000E0
end_define

begin_comment
comment|/* bits 5-7 */
end_comment

begin_define
define|#
directive|define
name|AGSA_DEV_INFO_DEV_TYPE_END_DEVICE
value|0x00000020
end_define

begin_comment
comment|/* 001b */
end_comment

begin_define
define|#
directive|define
name|AGSA_DEV_INFO_DEV_TYPE_EDGE_EXP_DEVICE
value|0x00000040
end_define

begin_comment
comment|/* 010b */
end_comment

begin_define
define|#
directive|define
name|AGSA_DEV_INFO_DEV_TYPE_FANOUT_EXP_DEVICE
value|0x00000060
end_define

begin_comment
comment|/* 011b */
end_comment

begin_comment
comment|/***************************************************************************** ** SAS TM Function definitions see SAS spec p308 Table 105 (Revision 7) *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|AGSA_ABORT_TASK
value|0x01
end_define

begin_define
define|#
directive|define
name|AGSA_ABORT_TASK_SET
value|0x02
end_define

begin_define
define|#
directive|define
name|AGSA_CLEAR_TASK_SET
value|0x04
end_define

begin_define
define|#
directive|define
name|AGSA_LOGICAL_UNIT_RESET
value|0x08
end_define

begin_define
define|#
directive|define
name|AGSA_IT_NEXUS_RESET
value|0x10
end_define

begin_define
define|#
directive|define
name|AGSA_CLEAR_ACA
value|0x40
end_define

begin_define
define|#
directive|define
name|AGSA_QUERY_TASK
value|0x80
end_define

begin_define
define|#
directive|define
name|AGSA_QUERY_TASK_SET
value|0x81
end_define

begin_define
define|#
directive|define
name|AGSA_QUERY_UNIT_ATTENTION
value|0x82
end_define

begin_comment
comment|/***************************************************************************** ** SAS TM Function Response Code see SAS spec p312 Table 111 (Revision 7) *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|AGSA_TASK_MANAGEMENT_FUNCTION_COMPLETE
value|0x0
end_define

begin_define
define|#
directive|define
name|AGSA_INVALID_FRAME
value|0x2
end_define

begin_define
define|#
directive|define
name|AGSA_TASK_MANAGEMENT_FUNCTION_NOT_SUPPORTED
value|0x4
end_define

begin_define
define|#
directive|define
name|AGSA_TASK_MANAGEMENT_FUNCTION_FAILED
value|0x5
end_define

begin_define
define|#
directive|define
name|AGSA_TASK_MANAGEMENT_FUNCTION_SUCCEEDED
value|0x8
end_define

begin_define
define|#
directive|define
name|AGSA_INCORRECT_LOGICAL_UNIT_NUMBER
value|0x9
end_define

begin_comment
comment|/* SAS spec 9.2.2.5.3 p356 Table 128 (Revision 9e) */
end_comment

begin_define
define|#
directive|define
name|AGSA_OVERLAPPED_TAG_ATTEMPTED
value|0xA
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_BSY_OVERRIDE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_CLOSE_CLEAR_AFFILIATION
value|0x00400000
end_define

begin_define
define|#
directive|define
name|AGSA_MAX_SMPPAYLOAD_VIA_SFO
value|40
end_define

begin_define
define|#
directive|define
name|AGSA_MAX_SSPPAYLOAD_VIA_SFO
value|36
end_define

begin_comment
comment|/* SATA Initiator Request option field defintion */
end_comment

begin_define
define|#
directive|define
name|AGSA_RETURN_D2H_FIS_GOOD_COMPLETION
value|0x000001
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_ENABLE_ENCRYPTION
value|0x000004
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_ENABLE_DIF
value|0x000008
end_define

begin_define
define|#
directive|define
name|AGSA_SATA_SKIP_QWORD
value|0xFFFF00
end_define

begin_comment
comment|/* SAS Initiator Request flag definitions */
end_comment

begin_comment
comment|/* Bits 0,1 use TLR_MASK */
end_comment

begin_define
define|#
directive|define
name|AGSA_SAS_ENABLE_ENCRYPTION
value|0x0004
end_define

begin_define
define|#
directive|define
name|AGSA_SAS_ENABLE_DIF
value|0x0008
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SAFLAG_USE_DIF_ENC_IOMB
end_ifdef

begin_define
define|#
directive|define
name|AGSA_SAS_USE_DIF_ENC_OPSTART
value|0x0010
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SAFLAG_USE_DIF_ENC_IOMB */
end_comment

begin_define
define|#
directive|define
name|AGSA_SAS_ENABLE_SKIP_MASK
value|0x0010
end_define

begin_define
define|#
directive|define
name|AGSA_SAS_SKIP_MASK_OFFSET
value|0xFFE0
end_define

begin_comment
comment|/**************************************************************************** ** SMP Phy control Phy Operation field ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|AGSA_PHY_CONTROL_LINK_RESET_OP
value|0x1
end_define

begin_define
define|#
directive|define
name|AGSA_PHY_CONTROL_HARD_RESET_OP
value|0x2
end_define

begin_define
define|#
directive|define
name|AGSA_PHY_CONTROL_DISABLE
value|0x3
end_define

begin_define
define|#
directive|define
name|AGSA_PHY_CONTROL_CLEAR_ERROR_LOG_OP
value|0x5
end_define

begin_define
define|#
directive|define
name|AGSA_PHY_CONTROL_CLEAR_AFFILIATION
value|0x6
end_define

begin_define
define|#
directive|define
name|AGSA_PHY_CONTROL_XMIT_SATA_PS_SIGNAL
value|0x7
end_define

begin_comment
comment|/**************************************************************************** ** SAS Diagnostic Operation code ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|AGSA_SAS_DIAG_START
value|0x1
end_define

begin_define
define|#
directive|define
name|AGSA_SAS_DIAG_END
value|0x0
end_define

begin_comment
comment|/**************************************************************************** ** Port Control constants ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|AGSA_PORT_SET_SMP_PHY_WIDTH
value|0x1
end_define

begin_define
define|#
directive|define
name|AGSA_PORT_SET_PORT_RECOVERY_TIME
value|0x2
end_define

begin_define
define|#
directive|define
name|AGSA_PORT_IO_ABORT
value|0x3
end_define

begin_define
define|#
directive|define
name|AGSA_PORT_SET_PORT_RESET_TIME
value|0x4
end_define

begin_define
define|#
directive|define
name|AGSA_PORT_HARD_RESET
value|0x5
end_define

begin_define
define|#
directive|define
name|AGSA_PORT_CLEAN_UP
value|0x6
end_define

begin_define
define|#
directive|define
name|AGSA_STOP_PORT_RECOVERY_TIMER
value|0x7
end_define

begin_comment
comment|/* Device State */
end_comment

begin_define
define|#
directive|define
name|SA_DS_OPERATIONAL
value|0x1
end_define

begin_define
define|#
directive|define
name|SA_DS_PORT_IN_RESET
value|0x2
end_define

begin_define
define|#
directive|define
name|SA_DS_IN_RECOVERY
value|0x3
end_define

begin_define
define|#
directive|define
name|SA_DS_IN_ERROR
value|0x4
end_define

begin_define
define|#
directive|define
name|SA_DS_NON_OPERATIONAL
value|0x7
end_define

begin_comment
comment|/************************************************************************************  *                                                                                  *  *               Constants defined for LL Layer ends                                *  *                                                                                  *  ************************************************************************************/
end_comment

begin_comment
comment|/************************************************************************************  *                                                                                  *  *               Constants defined for OS Layer starts                              *  *                                                                                  *  ************************************************************************************/
end_comment

begin_comment
comment|/*****************************************  *  ossaXXX return values  ******************************************/
end_comment

begin_comment
comment|/* common for all ossaXXX CB */
end_comment

begin_define
define|#
directive|define
name|OSSA_SUCCESS
value|0x00
end_define

begin_comment
comment|/**< flag indicates successful callback status */
end_comment

begin_define
define|#
directive|define
name|OSSA_FAILURE
value|0x01
end_define

begin_comment
comment|/**< flag indicates failed callback status */
end_comment

begin_comment
comment|/* ossaHwCB() */
end_comment

begin_define
define|#
directive|define
name|OSSA_RESET_PENDING
value|0x03
end_define

begin_comment
comment|/**< flag indicates reset pending callback status */
end_comment

begin_define
define|#
directive|define
name|OSSA_CHIP_FAILED
value|0x04
end_define

begin_comment
comment|/**< flag indicates chip failed callback status */
end_comment

begin_define
define|#
directive|define
name|OSSA_FREEZE_FAILED
value|0x05
end_define

begin_comment
comment|/**< flag indicates freeze failed callback status */
end_comment

begin_comment
comment|/* ossaLocalPhyControl() */
end_comment

begin_define
define|#
directive|define
name|OSSA_PHY_CONTROL_FAILURE
value|0x03
end_define

begin_comment
comment|/**< flag indicates phy Control operation failure */
end_comment

begin_comment
comment|/* ossaDeviceRegisterCB() */
end_comment

begin_define
define|#
directive|define
name|OSSA_FAILURE_OUT_OF_RESOURCE
value|0x01
end_define

begin_comment
comment|/**< flag indicates failed callback status */
end_comment

begin_define
define|#
directive|define
name|OSSA_FAILURE_DEVICE_ALREADY_REGISTERED
value|0x02
end_define

begin_comment
comment|/**< flag indicates failed callback status */
end_comment

begin_define
define|#
directive|define
name|OSSA_FAILURE_INVALID_PHY_ID
value|0x03
end_define

begin_comment
comment|/**< flag indicates failed callback status */
end_comment

begin_define
define|#
directive|define
name|OSSA_FAILURE_PHY_ID_ALREADY_REGISTERED
value|0x04
end_define

begin_comment
comment|/**< flag indicates failed callback status */
end_comment

begin_define
define|#
directive|define
name|OSSA_FAILURE_PORT_ID_OUT_OF_RANGE
value|0x05
end_define

begin_comment
comment|/**< flag indicates failed callback status */
end_comment

begin_define
define|#
directive|define
name|OSSA_FAILURE_PORT_NOT_VALID_STATE
value|0x06
end_define

begin_comment
comment|/**< flag indicates failed callback status */
end_comment

begin_define
define|#
directive|define
name|OSSA_FAILURE_DEVICE_TYPE_NOT_VALID
value|0x07
end_define

begin_comment
comment|/**< flag indicates failed callback status */
end_comment

begin_define
define|#
directive|define
name|OSSA_ERR_DEVICE_HANDLE_UNAVAILABLE
value|0x1020
end_define

begin_define
define|#
directive|define
name|OSSA_ERR_DEVICE_ALREADY_REGISTERED
value|0x1021
end_define

begin_define
define|#
directive|define
name|OSSA_ERR_DEVICE_TYPE_NOT_VALID
value|0x1022
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_DEVICE_ACCEPT_PENDING
value|0x1027
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|OSSA_ERR_PORT_INVALID
value|0x1041
end_define

begin_define
define|#
directive|define
name|OSSA_ERR_PORT_STATE_NOT_VALID
value|0x1042
end_define

begin_define
define|#
directive|define
name|OSSA_ERR_PORT_SMP_PHY_WIDTH_EXCEED
value|0x1045
end_define

begin_define
define|#
directive|define
name|OSSA_ERR_PHY_ID_INVALID
value|0x1061
end_define

begin_define
define|#
directive|define
name|OSSA_ERR_PHY_ID_ALREADY_REGISTERED
value|0x1062
end_define

begin_comment
comment|/* ossaDeregisterDeviceCB() */
end_comment

begin_define
define|#
directive|define
name|OSSA_INVALID_HANDLE
value|0x02
end_define

begin_comment
comment|/**< flag indicates failed callback status */
end_comment

begin_define
define|#
directive|define
name|OSSA_ERR_DEVICE_HANDLE_INVALID
value|0x1023
end_define

begin_comment
comment|/* MPI_ERR_DEVICE_HANDLE_INVALID The device handle associated with DEVICE_ID does not exist. */
end_comment

begin_define
define|#
directive|define
name|OSSA_ERR_DEVICE_BUSY
value|0x1024
end_define

begin_comment
comment|/* MPI_ERR_DEVICE_BUSY Device has outstanding I/Os. */
end_comment

begin_define
define|#
directive|define
name|OSSA_RC_ACCEPT
value|0x00
end_define

begin_comment
comment|/**< flag indicates the result of the callback function */
end_comment

begin_define
define|#
directive|define
name|OSSA_RC_REJECT
value|0x01
end_define

begin_comment
comment|/**< flag indicates the result of the callback function */
end_comment

begin_comment
comment|/* ossaSetDeviceStateCB() */
end_comment

begin_define
define|#
directive|define
name|OSSA_INVALID_STATE
value|0x0001
end_define

begin_define
define|#
directive|define
name|OSSA_ERR_DEVICE_NEW_STATE_INVALID
value|0x1025
end_define

begin_define
define|#
directive|define
name|OSSA_ERR_DEVICE_STATE_CHANGE_NOT_ALLOWED
value|0x1026
end_define

begin_define
define|#
directive|define
name|OSSA_ERR_DEVICE_STATE_INVALID
value|0x0049
end_define

begin_comment
comment|/* status of ossaSASDiagExecuteCB() */
end_comment

begin_define
define|#
directive|define
name|OSSA_DIAG_SUCCESS
value|0x00
end_define

begin_comment
comment|/* Successful SAS diagnostic command. */
end_comment

begin_define
define|#
directive|define
name|OSSA_DIAG_INVALID_COMMAND
value|0x01
end_define

begin_comment
comment|/* Invalid SAS diagnostic command. */
end_comment

begin_define
define|#
directive|define
name|OSSA_REGISTER_ACCESS_TIMEOUT
value|0x02
end_define

begin_comment
comment|/* Register access has been timed-out. This is applicable only to the SPCv controller. */
end_comment

begin_define
define|#
directive|define
name|OSSA_DIAG_FAIL
value|0x02
end_define

begin_comment
comment|/* SAS diagnostic command failed. This is applicable only to the SPC controller. */
end_comment

begin_define
define|#
directive|define
name|OSSA_DIAG_NOT_IN_DIAGNOSTIC_MODE
value|0x03
end_define

begin_comment
comment|/* Attempted to execute SAS diagnostic command but PHY is not in diagnostic mode */
end_comment

begin_define
define|#
directive|define
name|OSSA_DIAG_INVALID_PHY
value|0x04
end_define

begin_comment
comment|/* Attempted to execute SAS diagnostic command on an invalid/out-of-range PHY. */
end_comment

begin_define
define|#
directive|define
name|OSSA_MEMORY_ALLOC_FAILURE
value|0x05
end_define

begin_comment
comment|/* Memory allocation failed in diagnostic. This is applicable only to the SPCv controller. */
end_comment

begin_comment
comment|/* status of ossaSASDiagStartEndCB() */
end_comment

begin_define
define|#
directive|define
name|OSSA_DIAG_SE_SUCCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|OSSA_DIAG_SE_INVALID_PHY_ID
value|0x01
end_define

begin_define
define|#
directive|define
name|OSSA_DIAG_PHY_NOT_DISABLED
value|0x02
end_define

begin_define
define|#
directive|define
name|OSSA_DIAG_OTHER_FAILURE
value|0x03
end_define

begin_comment
comment|/* SPC */
end_comment

begin_define
define|#
directive|define
name|OSSA_DIAG_OPCODE_INVALID
value|0x03
end_define

begin_comment
comment|/* status of ossaPortControlCB() */
end_comment

begin_define
define|#
directive|define
name|OSSA_PORT_CONTROL_FAILURE
value|0x03
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_PORT_IO_RESOURCE_UNAVAILABLE
value|0x1004
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_PORT_INVALID
value|0x1041
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_PORT_OP_NOT_IN_USE
value|0x1043
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_PORT_OP_NOT_SUPPORTED
value|0x1044
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_PORT_SMP_WIDTH_EXCEEDED
value|0x1045
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_PORT_NOT_IN_CORRECT_STATE
value|0x1047
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*regDumpNum of agsaRegDumpInfo_t */
end_comment

begin_define
define|#
directive|define
name|GET_GSM_SM_INFO
value|0x02
end_define

begin_define
define|#
directive|define
name|GET_IOST_RB_INFO
value|0x03
end_define

begin_comment
comment|/************************************************************************************  *               HW Events  ************************************************************************************/
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_RESET_START
value|0x01
end_define

begin_comment
comment|/**< flag indicates reset started event */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_RESET_COMPLETE
value|0x02
end_define

begin_comment
comment|/**< flag indicates chip reset completed event */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_PHY_STOP_STATUS
value|0x03
end_define

begin_comment
comment|/**< flag indicates phy stop event status */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_SAS_PHY_UP
value|0x04
end_define

begin_comment
comment|/**< flag indicates SAS link up event */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_SATA_PHY_UP
value|0x05
end_define

begin_comment
comment|/**< flag indicates SATA link up event */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_SATA_SPINUP_HOLD
value|0x06
end_define

begin_comment
comment|/**< flag indicates SATA spinup hold event */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_PHY_DOWN
value|0x07
end_define

begin_comment
comment|/**< flag indicates link down event */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_BROADCAST_CHANGE
value|0x09
end_define

begin_comment
comment|/**< flag indicates broadcast change event */
end_comment

begin_comment
comment|/* not used spcv 0x0A*/
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_PHY_ERROR
value|0x0A
end_define

begin_comment
comment|/**< flag indicates link error event */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_BROADCAST_SES
value|0x0B
end_define

begin_comment
comment|/**< flag indicates broadcast change (SES) event */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_PHY_ERR_INBOUND_CRC
value|0x0C
end_define

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_HARD_RESET_RECEIVED
value|0x0D
end_define

begin_comment
comment|/**< flag indicates hardware reset received event */
end_comment

begin_comment
comment|/* not used spcv 0x0E*/
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_MALFUNCTION
value|0x0E
end_define

begin_comment
comment|/**< flag indicates unrecoverable Error */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_ID_FRAME_TIMEOUT
value|0x0F
end_define

begin_comment
comment|/**< flag indicates ID Frame Timeout event */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_BROADCAST_EXP
value|0x10
end_define

begin_comment
comment|/**< flag indicates broadcast (EXPANDER) event */
end_comment

begin_comment
comment|/* not used spcv 0x11*/
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_PHY_START_STATUS
value|0x11
end_define

begin_comment
comment|/**< flag indicates phy start event status */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_PHY_ERR_INVALID_DWORD
value|0x12
end_define

begin_comment
comment|/**< flag indicates Link error invalid DWORD */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_PHY_ERR_DISPARITY_ERROR
value|0x13
end_define

begin_comment
comment|/**< flag indicates Phy error disparity */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_PHY_ERR_CODE_VIOLATION
value|0x14
end_define

begin_comment
comment|/**< flag indicates Phy error code violation */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_PHY_ERR_LOSS_OF_DWORD_SYNCH
value|0x15
end_define

begin_comment
comment|/**< flag indicates Link error loss of DWORD synch */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_PHY_ERR_PHY_RESET_FAILED
value|0x16
end_define

begin_comment
comment|/**< flag indicates Link error phy reset failed */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_PORT_RECOVERY_TIMER_TMO
value|0x17
end_define

begin_comment
comment|/**< flag indicates Port Recovery timeout */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_PORT_RECOVER
value|0x18
end_define

begin_comment
comment|/**< flag indicates Port Recovery */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_PORT_RESET_TIMER_TMO
value|0x19
end_define

begin_comment
comment|/**< flag indicates Port Reset Timer out */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_PORT_RESET_COMPLETE
value|0x20
end_define

begin_comment
comment|/**< flag indicates Port Reset Complete */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_BROADCAST_ASYNCH_EVENT
value|0x21
end_define

begin_comment
comment|/**< flag indicates Broadcast Asynch Event */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_IT_NEXUS_LOSS
value|0x22
end_define

begin_comment
comment|/**< Custom: H/W event for IT Nexus Loss */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_OPEN_RETRY_BACKOFF_THR_ADJUSTED
value|0x25
end_define

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_ENCRYPTION
value|0x83
end_define

begin_comment
comment|/**< TSDK internal flag indicating that an encryption event occurred */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_MODE
value|0x84
end_define

begin_comment
comment|/**< TSDK internal flag indicating that a controller mode page operation completed */
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_EVENT_SECURITY_MODE
value|0x85
end_define

begin_comment
comment|/**< TSDK internal flag indicating that saEncryptSetMode() completed */
end_comment

begin_comment
comment|/* port state */
end_comment

begin_define
define|#
directive|define
name|OSSA_PORT_NOT_ESTABLISHED
value|0x00
end_define

begin_comment
comment|/**< flag indicates port is not established */
end_comment

begin_define
define|#
directive|define
name|OSSA_PORT_VALID
value|0x01
end_define

begin_comment
comment|/**< flag indicates port valid */
end_comment

begin_define
define|#
directive|define
name|OSSA_PORT_LOSTCOMM
value|0x02
end_define

begin_comment
comment|/**< flag indicates port lost communication */
end_comment

begin_define
define|#
directive|define
name|OSSA_PORT_IN_RESET
value|0x04
end_define

begin_comment
comment|/**< flag indicates port in reset state */
end_comment

begin_define
define|#
directive|define
name|OSSA_PORT_3RDPARTY_RESET
value|0x07
end_define

begin_comment
comment|/**< flag indicates port in 3rd party reset state */
end_comment

begin_define
define|#
directive|define
name|OSSA_PORT_INVALID
value|0x08
end_define

begin_comment
comment|/**< flag indicates port invalid */
end_comment

begin_comment
comment|/* status for agsaHWEventMode_t */
end_comment

begin_define
define|#
directive|define
name|OSSA_CTL_SUCCESS
value|0x0000
end_define

begin_define
define|#
directive|define
name|OSSA_CTL_INVALID_CONFIG_PAGE
value|0x1001
end_define

begin_define
define|#
directive|define
name|OSSA_CTL_INVALID_PARAM_IN_CONFIG_PAGE
value|0x1002
end_define

begin_define
define|#
directive|define
name|OSSA_CTL_INVALID_ENCRYPTION_SECURITY_MODE
value|0x1003
end_define

begin_define
define|#
directive|define
name|OSSA_CTL_RESOURCE_NOT_AVAILABLE
value|0x1004
end_define

begin_define
define|#
directive|define
name|OSSA_CTL_CONTROLLER_NOT_IDLE
value|0x1005
end_define

begin_comment
comment|// #define OSSA_CTL_NVM_MEMORY_ACCESS_ERR              0x100B
end_comment

begin_define
define|#
directive|define
name|OSSA_CTL_OPERATOR_AUTHENTICATION_FAILURE
value|0x100XX
end_define

begin_comment
comment|/************************************************************************************  *               General Events value  ************************************************************************************/
end_comment

begin_define
define|#
directive|define
name|OSSA_INBOUND_V_BIT_NOT_SET
value|0x01
end_define

begin_define
define|#
directive|define
name|OSSA_INBOUND_OPC_NOT_SUPPORTED
value|0x02
end_define

begin_define
define|#
directive|define
name|OSSA_INBOUND_IOMB_INVALID_OBID
value|0x03
end_define

begin_comment
comment|/************************************************************************************  *               FW Flash Update status values  ************************************************************************************/
end_comment

begin_define
define|#
directive|define
name|OSSA_FLASH_UPDATE_COMPLETE_PENDING_REBOOT
value|0x00
end_define

begin_comment
comment|/**< flag indicates fw flash update completed */
end_comment

begin_define
define|#
directive|define
name|OSSA_FLASH_UPDATE_IN_PROGRESS
value|0x01
end_define

begin_comment
comment|/**< flag indicates fw flash update in progress */
end_comment

begin_define
define|#
directive|define
name|OSSA_FLASH_UPDATE_HDR_ERR
value|0x02
end_define

begin_comment
comment|/**< flag indicates fw flash header error */
end_comment

begin_define
define|#
directive|define
name|OSSA_FLASH_UPDATE_OFFSET_ERR
value|0x03
end_define

begin_comment
comment|/**< flag indicates fw flash offset error */
end_comment

begin_define
define|#
directive|define
name|OSSA_FLASH_UPDATE_CRC_ERR
value|0x04
end_define

begin_comment
comment|/**< flag indicates fw flash CRC error */
end_comment

begin_define
define|#
directive|define
name|OSSA_FLASH_UPDATE_LENGTH_ERR
value|0x05
end_define

begin_comment
comment|/**< flag indicates fw flash length error */
end_comment

begin_define
define|#
directive|define
name|OSSA_FLASH_UPDATE_HW_ERR
value|0x06
end_define

begin_comment
comment|/**< flag indicates fw flash HW error */
end_comment

begin_define
define|#
directive|define
name|OSSA_FLASH_UPDATE_HMAC_ERR
value|0x0E
end_define

begin_comment
comment|/**< flag indicates fw flash Firmware image HMAC authentication failure.*/
end_comment

begin_define
define|#
directive|define
name|OSSA_FLASH_UPDATE_DNLD_NOT_SUPPORTED
value|0x10
end_define

begin_comment
comment|/**< flag indicates fw flash down load not supported */
end_comment

begin_define
define|#
directive|define
name|OSSA_FLASH_UPDATE_DISABLED
value|0x11
end_define

begin_comment
comment|/**< flag indicates fw flash Update disabled */
end_comment

begin_define
define|#
directive|define
name|OSSA_FLASH_FWDNLD_DEVICE_UNSUPPORT
value|0x12
end_define

begin_comment
comment|/**< flag indicates fw flash Update disabled */
end_comment

begin_comment
comment|/************************************************************************************ *               Discovery status values ************************************************************************************/
end_comment

begin_define
define|#
directive|define
name|OSSA_DISCOVER_STARTED
value|0x00
end_define

begin_comment
comment|/**< flag indicates discover started */
end_comment

begin_define
define|#
directive|define
name|OSSA_DISCOVER_FOUND_DEVICE
value|0x01
end_define

begin_comment
comment|/**< flag indicates discovery found a new device */
end_comment

begin_define
define|#
directive|define
name|OSSA_DISCOVER_REMOVED_DEVICE
value|0x02
end_define

begin_comment
comment|/**< flag indicates discovery found a device removed */
end_comment

begin_define
define|#
directive|define
name|OSSA_DISCOVER_COMPLETE
value|0x03
end_define

begin_comment
comment|/**< flag indicates discover completed */
end_comment

begin_define
define|#
directive|define
name|OSSA_DISCOVER_ABORT
value|0x04
end_define

begin_comment
comment|/**< flag indicates discover error12 */
end_comment

begin_define
define|#
directive|define
name|OSSA_DISCOVER_ABORT_ERROR_1
value|0x05
end_define

begin_comment
comment|/**< flag indicates discover error1 */
end_comment

begin_define
define|#
directive|define
name|OSSA_DISCOVER_ABORT_ERROR_2
value|0x06
end_define

begin_comment
comment|/**< flag indicates discover error2 */
end_comment

begin_define
define|#
directive|define
name|OSSA_DISCOVER_ABORT_ERROR_3
value|0x07
end_define

begin_comment
comment|/**< flag indicates discover error3 */
end_comment

begin_define
define|#
directive|define
name|OSSA_DISCOVER_ABORT_ERROR_4
value|0x08
end_define

begin_comment
comment|/**< flag indicates discover error4 */
end_comment

begin_define
define|#
directive|define
name|OSSA_DISCOVER_ABORT_ERROR_5
value|0x09
end_define

begin_comment
comment|/**< flag indicates discover error5 */
end_comment

begin_define
define|#
directive|define
name|OSSA_DISCOVER_ABORT_ERROR_6
value|0x0A
end_define

begin_comment
comment|/**< flag indicates discover error6 */
end_comment

begin_define
define|#
directive|define
name|OSSA_DISCOVER_ABORT_ERROR_7
value|0x0B
end_define

begin_comment
comment|/**< flag indicates discover error7 */
end_comment

begin_define
define|#
directive|define
name|OSSA_DISCOVER_ABORT_ERROR_8
value|0x0C
end_define

begin_comment
comment|/**< flag indicates discover error8 */
end_comment

begin_define
define|#
directive|define
name|OSSA_DISCOVER_ABORT_ERROR_9
value|0x0D
end_define

begin_comment
comment|/**< flag indicates discover error9 */
end_comment

begin_comment
comment|/***********************************************************************************  *                        Log Debug Levels  ***********************************************************************************/
end_comment

begin_define
define|#
directive|define
name|OSSA_DEBUG_LEVEL_0
value|0x00
end_define

begin_comment
comment|/**< debug level 0 */
end_comment

begin_define
define|#
directive|define
name|OSSA_DEBUG_LEVEL_1
value|0x01
end_define

begin_comment
comment|/**< debug level 1 */
end_comment

begin_define
define|#
directive|define
name|OSSA_DEBUG_LEVEL_2
value|0x02
end_define

begin_comment
comment|/**< debug level 2 */
end_comment

begin_define
define|#
directive|define
name|OSSA_DEBUG_LEVEL_3
value|0x03
end_define

begin_comment
comment|/**< debug level 3 */
end_comment

begin_define
define|#
directive|define
name|OSSA_DEBUG_LEVEL_4
value|0x04
end_define

begin_comment
comment|/**< debug level 4 */
end_comment

begin_define
define|#
directive|define
name|OSSA_DEBUG_PRINT_INVALID_NUMBER
value|0xFFFFFFFF
end_define

begin_comment
comment|/**< the number won't be printed by OS layer */
end_comment

begin_define
define|#
directive|define
name|OSSA_FRAME_TYPE_SSP_CMD
value|0x06
end_define

begin_comment
comment|/**< flag indicates received frame is SSP command */
end_comment

begin_define
define|#
directive|define
name|OSSA_FRAME_TYPE_SSP_TASK
value|0x16
end_define

begin_comment
comment|/**< flag indicates received frame is SSP task management */
end_comment

begin_comment
comment|/* Event Source Type of saRegisterEventCallback() */
end_comment

begin_define
define|#
directive|define
name|OSSA_EVENT_SOURCE_DEVICE_HANDLE_ADDED
value|0x00
end_define

begin_define
define|#
directive|define
name|OSSA_EVENT_SOURCE_DEVICE_HANDLE_REMOVED
value|0x01
end_define

begin_comment
comment|/* Status of Get Device Info CB */
end_comment

begin_define
define|#
directive|define
name|OSSA_DEV_INFO_INVALID_HANDLE
value|0x01
end_define

begin_define
define|#
directive|define
name|OSSA_DEV_INFO_NO_EXTENDED_INFO
value|0x02
end_define

begin_define
define|#
directive|define
name|OSSA_DEV_INFO_SAS_EXTENDED_INFO
value|0x03
end_define

begin_define
define|#
directive|define
name|OSSA_DEV_INFO_SATA_EXTENDED_INFO
value|0x04
end_define

begin_comment
comment|/* Diagnostic Command Type */
end_comment

begin_define
define|#
directive|define
name|AGSA_CMD_TYPE_DIAG_OPRN_PERFORM
value|0x00
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_TYPE_DIAG_OPRN_STOP
value|0x01
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_TYPE_DIAG_THRESHOLD_SPECIFY
value|0x02
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_TYPE_DIAG_RECEIVE_ENABLE
value|0x03
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_TYPE_DIAG_REPORT_GET
value|0x04
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_TYPE_DIAG_ERR_CNT_RESET
value|0x05
end_define

begin_comment
comment|/* Command Description for CMD_TYPE DIAG_OPRN_PERFORM, DIAG_OPRN_STOP, THRESHOLD_SPECIFY */
end_comment

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_PRBS
value|0x00
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_CJTPAT
value|0x01
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_USR_PATTERNS
value|0x02
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_PRBS_ERR_INSERT
value|0x08
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_PRBS_INVERT
value|0x09
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_CJTPAT_INVERT
value|0x0A
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_CODE_VIOL_INSERT
value|0x0B
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_DISP_ERR_INSERT
value|0x0C
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_SSPA_PERF_EVENT_1
value|0x0E
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_LINE_SIDE_ANA_LPBK
value|0x10
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_LINE_SIDE_DIG_LPBK
value|0x11
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_SYS_SIDE_ANA_LPBK
value|0x12
end_define

begin_comment
comment|/* Command Description for CMD_TYPE DIAG_REPORT_GET and ERR_CNT_RESET */
end_comment

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_PRBS_ERR_CNT
value|0x00
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_CODE_VIOL_ERR_CNT
value|0x01
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_DISP_ERR_CNT
value|0x02
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_LOST_DWD_SYNC_CNT
value|0x05
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_INVALID_DWD_CNT
value|0x06
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_CODE_VIOL_ERR_CNT_THHD
value|0x09
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_DISP_ERR_CNT_THHD
value|0x0A
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_SSPA_PERF_CNT
value|0x0B
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_PHY_RST_CNT
value|0x0C
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_SSPA_PERF_1_THRESHOLD
value|0x0E
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_CODE_VIOL_ERR_THHD
value|0x19
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_DISP_ERR_THHD
value|0x1A
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_RX_LINK_BANDWIDTH
value|0x1B
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_TX_LINK_BANDWIDTH
value|0x1C
end_define

begin_define
define|#
directive|define
name|AGSA_CMD_DESC_ALL
value|0x1F
end_define

begin_comment
comment|/* NVMDevice type */
end_comment

begin_define
define|#
directive|define
name|AGSA_NVMD_TWI_DEVICES
value|0x00
end_define

begin_define
define|#
directive|define
name|AGSA_NVMD_CONFIG_SEEPROM
value|0x01
end_define

begin_define
define|#
directive|define
name|AGSA_NVMD_VPD_FLASH
value|0x04
end_define

begin_define
define|#
directive|define
name|AGSA_NVMD_AAP1_REG_FLASH
value|0x05
end_define

begin_define
define|#
directive|define
name|AGSA_NVMD_IOP_REG_FLASH
value|0x06
end_define

begin_define
define|#
directive|define
name|AGSA_NVMD_EXPANSION_ROM
value|0x07
end_define

begin_define
define|#
directive|define
name|AGSA_NVMD_REG_FLASH
value|0x05
end_define

begin_comment
comment|/* GET/SET NVMD Data Response errors */
end_comment

begin_define
define|#
directive|define
name|OSSA_NVMD_SUCCESS
value|0x0000
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_MODE_ERROR
value|0x0001
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_LENGTH_ERROR
value|0x0002
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_TWI_ADDRESS_SIZE_ERROR
value|0x0005
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_TWI_NACK_ERROR
value|0x2001
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_TWI_LOST_ARB_ERROR
value|0x2002
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_TWI_TIMEOUT_ERROR
value|0x2021
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_TWI_BUS_NACK_ERROR
value|0x2081
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_TWI_ARB_FAILED_ERROR
value|0x2082
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_TWI_BUS_TIMEOUT_ERROR
value|0x20FF
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_FLASH_PARTITION_NUM_ERROR
value|0x9001
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_FLASH_LENGTH_TOOBIG_ERROR
value|0x9002
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_FLASH_PROGRAM_ERROR
value|0x9003
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_FLASH_DEVICEID_ERROR
value|0x9004
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_FLASH_VENDORID_ERROR
value|0x9005
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_FLASH_ERASE_TIMEOUT_ERROR
value|0x9006
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_FLASH_ERASE_ERROR
value|0x9007
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_FLASH_BUSY_ERROR
value|0x9008
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_FLASH_NOT_SUPPORT_DEVICE_ERROR
value|0x9009
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_FLASH_CFI_INF_ERROR
value|0x900A
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_FLASH_MORE_ERASE_BLOCK_ERROR
value|0x900B
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_FLASH_READ_ONLY_ERROR
value|0x900C
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_FLASH_MAP_TYPE_ERROR
value|0x900D
end_define

begin_define
define|#
directive|define
name|OSSA_NVMD_FLASH_MAP_DISABLE_ERROR
value|0x900E
end_define

begin_comment
comment|/************************************************************ * ossaHwCB Encryption encryptOperation of agsaHWEventEncrypt_t ************************************************************/
end_comment

begin_define
define|#
directive|define
name|OSSA_HW_ENCRYPT_KEK_UPDATE
value|0x0000
end_define

begin_define
define|#
directive|define
name|OSSA_HW_ENCRYPT_KEK_UPDATE_AND_STORE
value|0x0001
end_define

begin_define
define|#
directive|define
name|OSSA_HW_ENCRYPT_KEK_INVALIDTE
value|0x0002
end_define

begin_define
define|#
directive|define
name|OSSA_HW_ENCRYPT_DEK_UPDATE
value|0x0003
end_define

begin_define
define|#
directive|define
name|OSSA_HW_ENCRYPT_DEK_INVALIDTE
value|0x0004
end_define

begin_define
define|#
directive|define
name|OSSA_HW_ENCRYPT_OPERATOR_MANAGEMENT
value|0x0005
end_define

begin_define
define|#
directive|define
name|OSSA_HW_ENCRYPT_TEST_EXECUTE
value|0x0006
end_define

begin_define
define|#
directive|define
name|OSSA_HW_ENCRYPT_SET_OPERATOR
value|0x0007
end_define

begin_define
define|#
directive|define
name|OSSA_HW_ENCRYPT_GET_OPERATOR
value|0x0008
end_define

begin_comment
comment|/************************************************************ * ossaHwCB Encryption status of agsaHWEventEncrypt_t ************************************************************/
end_comment

begin_comment
comment|/* KEK and DEK managment status from PM */
end_comment

begin_define
define|#
directive|define
name|OSSA_INVALID_ENCRYPTION_SECURITY_MODE
value|0x1003
end_define

begin_define
define|#
directive|define
name|OSSA_KEK_MGMT_SUBOP_NOT_SUPPORTED_
value|0x2000
end_define

begin_comment
comment|/*not in PM 101222*/
end_comment

begin_define
define|#
directive|define
name|OSSA_DEK_MGMT_SUBOP_NOT_SUPPORTED
value|0x2000
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ENC_ERR_ILLEGAL_DEK_PARAM
value|0x2001
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_DEK_MANAGEMENT_DEK_UNWRAP_FAIL
value|0x2002
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ENC_ERR_ILLEGAL_KEK_PARAM
value|0x2021
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_KEK_MANAGEMENT_KEK_UNWRAP_FAIL
value|0x2022
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_KEK_MANAGEMENT_NVRAM_OPERATION_FAIL
value|0x2023
end_define

begin_comment
comment|/*encrypt operator management response status */
end_comment

begin_define
define|#
directive|define
name|OSSA_OPR_MGMT_OP_NOT_SUPPORTED
value|0x2060
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ENC_ERR_OPR_PARAM_ILLEGAL
value|0x2061
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ENC_ERR_OPR_ID_NOT_FOUND
value|0x2062
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ENC_ERR_OPR_ROLE_NOT_MATCH
value|0x2063
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ENC_ERR_OPR_MAX_NUM_EXCEEDED
value|0x2064
end_define

begin_comment
comment|/*encrypt saSetOperator() response status */
end_comment

begin_define
define|#
directive|define
name|OSSA_MPI_ENC_ERR_CONTROLLER_NOT_IDLE
value|0x1005
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ENC_NVM_MEM_ACCESS_ERR
value|0x100B
end_define

begin_comment
comment|/* agsaEncryptSMX | agsaEncryptCipherMode == cipherMode for saEncryptSetMode()*/
end_comment

begin_comment
comment|/* Make sure all definitions are unique bits */
end_comment

begin_define
define|#
directive|define
name|agsaEncryptSMF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|agsaEncryptSMA
value|0x00000100
end_define

begin_define
define|#
directive|define
name|agsaEncryptSMB
value|0x00000200
end_define

begin_define
define|#
directive|define
name|agsaEncryptReturnSMF
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|agsaEncryptAuthorize
value|(1<< 13)
end_define

begin_comment
comment|/* Bits 16-23: Allowable Cipher Mode(ACM) Bit 16: Enable AES ECB. If set to 1, AES ECB is enable. If set to 0, AES ECB is disabled. Bit 22: Enable AES XTS. If set to 1, AES XTS is enable. If set to 0, AES XTS is disabled. */
end_comment

begin_define
define|#
directive|define
name|agsaEncryptAcmMask
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|agsaEncryptEnableAES_ECB
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|agsaEncryptEnableAES_XTS
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|agsaEncryptCipherModeECB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|agsaEncryptCipherModeXTS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|agsaEncryptStatusNoNVRAM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|agsaEncryptStatusNVRAMErr
value|0x00000002
end_define

begin_comment
comment|/*  Bin    Hex  Sector      Total 00000 :0x0  512B        512 11000 :0x1  520B        520 00010 :0x2  4K          4096 00011 :0x3  4K+64B      4160 00100 :0x4  4K+128B     4224  11000 :0x18 512+8B      520 11001 :0x19 520+8B      528 11010 :0x1A 4K+8B       4104 11011 :0x1B 4K+64B+8B   4168 11100 :0x1C 4K+128B+8B  4232  */
end_comment

begin_define
define|#
directive|define
name|agsaEncryptSectorSize512
value|0
end_define

begin_comment
comment|/*  define agsaEncryptSectorSize520                     1 Not supported */
end_comment

begin_define
define|#
directive|define
name|agsaEncryptSectorSize4096
value|2
end_define

begin_define
define|#
directive|define
name|agsaEncryptSectorSize4160
value|3
end_define

begin_define
define|#
directive|define
name|agsaEncryptSectorSize4224
value|4
end_define

begin_define
define|#
directive|define
name|agsaEncryptDIFSectorSize520
value|(agsaEncryptSectorSize512  | 0x18)
end_define

begin_define
define|#
directive|define
name|agsaEncryptDIFSectorSize528
value|( 0x19)
end_define

begin_define
define|#
directive|define
name|agsaEncryptDIFSectorSize4104
value|(agsaEncryptSectorSize4096 | 0x18)
end_define

begin_define
define|#
directive|define
name|agsaEncryptDIFSectorSize4168
value|(agsaEncryptSectorSize4160 | 0x18)
end_define

begin_define
define|#
directive|define
name|agsaEncryptDIFSectorSize4232
value|(agsaEncryptSectorSize4224 | 0x18)
end_define

begin_define
define|#
directive|define
name|AGSA_ENCRYPT_STORE_NVRAM
value|1
end_define

begin_comment
comment|/************************************************************ * ossaHwCB Mode page event definitions ************************************************************/
end_comment

begin_define
define|#
directive|define
name|agsaModePageGet
value|1
end_define

begin_define
define|#
directive|define
name|agsaModePageSet
value|2
end_define

begin_comment
comment|/************************************************************ * saSgpio() SGPIO Function and Register type ************************************************************/
end_comment

begin_define
define|#
directive|define
name|AGSA_READ_SGPIO_REGISTER
value|0x02
end_define

begin_define
define|#
directive|define
name|AGSA_WRITE_SGPIO_REGISTER
value|0x82
end_define

begin_define
define|#
directive|define
name|AGSA_SGPIO_CONFIG_REG
value|0x0
end_define

begin_define
define|#
directive|define
name|AGSA_SGPIO_DRIVE_BY_DRIVE_RECEIVE_REG
value|0x1
end_define

begin_define
define|#
directive|define
name|AGSA_SGPIO_GENERAL_PURPOSE_RECEIVE_REG
value|0x2
end_define

begin_define
define|#
directive|define
name|AGSA_SGPIO_DRIVE_BY_DRIVE_TRANSMIT_REG
value|0x3
end_define

begin_define
define|#
directive|define
name|AGSA_SGPIO_GENERAL_PURPOSE_TRANSMIT_REG
value|0x4
end_define

begin_comment
comment|/************************************************************ * ossaSGpioCB() Function result ************************************************************/
end_comment

begin_define
define|#
directive|define
name|OSSA_SGPIO_COMMAND_SUCCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|OSSA_SGPIO_CMD_ERROR_WRONG_FRAME_TYPE
value|0x01
end_define

begin_define
define|#
directive|define
name|OSSA_SGPIO_CMD_ERROR_WRONG_REG_TYPE
value|0x02
end_define

begin_define
define|#
directive|define
name|OSSA_SGPIO_CMD_ERROR_WRONG_REG_INDEX
value|0x03
end_define

begin_define
define|#
directive|define
name|OSSA_SGPIO_CMD_ERROR_WRONG_REG_COUNT
value|0x04
end_define

begin_define
define|#
directive|define
name|OSSA_SGPIO_CMD_ERROR_WRONG_FRAME_REG_TYPE
value|0x05
end_define

begin_define
define|#
directive|define
name|OSSA_SGPIO_CMD_ERROR_WRONG_FUNCTION
value|0x06
end_define

begin_define
define|#
directive|define
name|OSSA_SGPIO_CMD_ERROR_WRONG_FRAME_TYPE_REG_INDEX
value|0x19
end_define

begin_define
define|#
directive|define
name|OSSA_SGPIO_CMD_ERROR_WRONG_FRAME_TYPE_REG_CNT
value|0x81
end_define

begin_define
define|#
directive|define
name|OSSA_SGPIO_CMD_ERROR_WRONG_REG_TYPE_REG_INDEX
value|0x1A
end_define

begin_define
define|#
directive|define
name|OSSA_SGPIO_CMD_ERROR_WRONG_REG_TYPE_REG_COUNT
value|0x82
end_define

begin_define
define|#
directive|define
name|OSSA_SGPIO_CMD_ERROR_WRONG_REG_INDEX_REG_COUNT
value|0x83
end_define

begin_define
define|#
directive|define
name|OSSA_SGPIO_CMD_ERROR_WRONG_FRAME_REG_TYPE_REG_INDEX
value|0x1D
end_define

begin_define
define|#
directive|define
name|OSSA_SGPIO_CMD_ERROR_WRONG_ALL_HEADER_PARAMS
value|0x9D
end_define

begin_define
define|#
directive|define
name|OSSA_SGPIO_MAX_READ_DATA_COUNT
value|0x0D
end_define

begin_define
define|#
directive|define
name|OSSA_SGPIO_MAX_WRITE_DATA_COUNT
value|0x0C
end_define

begin_comment
comment|/************************************************************ * ossaGetDFEDataCB() status ************************************************************/
end_comment

begin_define
define|#
directive|define
name|OSSA_DFE_MPI_IO_SUCCESS
value|0x0000
end_define

begin_define
define|#
directive|define
name|OSSA_DFE_DATA_OVERFLOW
value|0x0002
end_define

begin_define
define|#
directive|define
name|OSSA_DFE_MPI_ERR_RESOURCE_UNAVAILABLE
value|0x1004
end_define

begin_define
define|#
directive|define
name|OSSA_DFE_CHANNEL_DOWN
value|0x100E
end_define

begin_define
define|#
directive|define
name|OSSA_DFE_MEASUREMENT_IN_PROGRESS
value|0x100F
end_define

begin_define
define|#
directive|define
name|OSSA_DFE_CHANNEL_INVALID
value|0x1010
end_define

begin_define
define|#
directive|define
name|OSSA_DFE_DMA_FAILURE
value|0x1011
end_define

begin_comment
comment|/************************************************************************************  *                                                                                  *  *               Constants defined for OS Layer ends                                *  *                                                                                  *  ************************************************************************************/
end_comment

begin_comment
comment|/************************************************************************************  *                                                                                  *  *               Data Structures Defined for LL API start                           *  *                                                                                  *  ************************************************************************************/
end_comment

begin_comment
comment|/** \brief data structure stores OS specific and LL specific context  *  * The agsaContext_t data structure contains two generic pointers,  * also known as handles, which are used to store OS Layer-specific and  * LL Layer-specific contexts. Only the handle specific to a layer can  * be modified by the layer. The other layer's handle must be returned  * unmodified when communicating between the layers.   * A layer's handle is typically typecast to an instance of a layer-specific  * data structure. The layer can use its handle to point to any data type  * that is to be associated with a function call. A handle provides a way  * to uniquely identify responses when multiple calls to the same function  * are necessary.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaContext_s
block|{
name|void
modifier|*
name|osData
decl_stmt|;
comment|/**< Pointer-sized value used internally by the OS Layer */
name|void
modifier|*
name|sdkData
decl_stmt|;
comment|/**< Pointer-sized value used internally by the LL Layer */
block|}
name|agsaContext_t
typedef|;
end_typedef

begin_comment
comment|/** \brief hold points to global data strutures used by the LL and OS Layers  *  * The agsaRoot_t data structure is used to hold pointer-sized values for  * internal use by the LL and OS Layers. It is intended that the  * sdkData element of the agsaRoot_t data structure be used to  * identify an instance of the hardware context. The sdkData  * element is set by the LL Layer in the saHwInitialize()  * function and returned to the OS Layer in the agsaRoot_t data  * structure  */
end_comment

begin_typedef
typedef|typedef
name|agsaContext_t
name|agsaRoot_t
typedef|;
end_typedef

begin_comment
comment|/** \brief holds the pointers to the device data structure used by the LL and OS Layers  *  * The agsaDevHandle_t data structure is the device instance handle.  * It holds pointer-sized values used internally by each of the LL and  * OS Layers. It is intended that the agsaDevHandle_t data  * structure be used to identify a specific device instance. A  * device instance is uniquely identified by its device handle.  */
end_comment

begin_typedef
typedef|typedef
name|agsaContext_t
name|agsaDevHandle_t
typedef|;
end_typedef

begin_comment
comment|/** \brief holds the pointers to the port data structure used by the LL and  *  OS Layers  *  * The agsaPortContext_t data structure is used to describe an instance of  * SAS port or SATA port. It holds pointer-sized values used  * internally by each of the LL and OS Layers.  *  * When connected to other SAS end-devices or expanders, each instance of  * agsaPortContext_t represents a SAS local narrow-port or  * wide-port.  *  * When connected to SATA device, each instance of agsaPortContext_t  * represents a local SATA port.  *  */
end_comment

begin_typedef
typedef|typedef
name|agsaContext_t
name|agsaPortContext_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure pointer to IO request structure  *  * It is intended that the agsaIORequest_t structure be used to  * uniquely identify each I/O Request for either target or  * initiator. The OS Layer is responsible for allocating and  * managing agsaIORequest_t structures. The LL Layer uses each  * structure only between calls to: saSSPStart() and  * ossaSSPCompleted(), saSATAStart() and ossaSATACompleted(),  * saSMPStart() and ossaSMPCompleted()  *  */
end_comment

begin_typedef
typedef|typedef
name|agsaContext_t
name|agsaIORequest_t
typedef|;
end_typedef

begin_comment
comment|/** \brief handle to access frame  *  * This data structure is the handle to access frame  */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|agsaFrameHandle_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a SAS ReCofiguration structure in the SAS/SATA hardware  *  * Describe a SAS ReConfiguration in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSASReconfig_s
block|{
name|bit32
name|flags
decl_stmt|;
comment|/* flag to indicate a change to the default parameter                                       bit31-30:reserved                                       bit29:   a change to the default SAS/SATA ports is requested                                       bit28:   the OPEN REJECT (RETRY) in command phase is requested                                       bit27:   the OPEN REJECT (RETRY) in data phase is requested                                       bit26:   REJECT will be mapped into OPEN REJECT                                       bit25:   delay for SATA Head-of-Line blocking detection timeout                                       bit24-00:reserved */
name|bit16
name|reserved0
decl_stmt|;
comment|/* reserved */
name|bit8
name|reserved1
decl_stmt|;
comment|/* reserved */
name|bit8
name|maxPorts
decl_stmt|;
comment|/* This field is valid if bit 29 of the flags field is set to 1 */
name|bit16
name|openRejectRetriesCmd
decl_stmt|;
comment|/* This field is valid if bit 28 of the flags field is set to 1 */
name|bit16
name|openRejectRetriesData
decl_stmt|;
comment|/* This field is valid if bit 27 of the flags field is set to 1.*/
name|bit16
name|reserved2
decl_stmt|;
comment|/* reserved */
name|bit16
name|sataHolTmo
decl_stmt|;
comment|/* This field is valid if bit 25 of the flags field is set to 1 */
block|}
name|agsaSASReconfig_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a Phy Analog Setup registers for a Controller in the SAS/SATA hardware  *  * Describe a Phy Analog Setup registers for a controller in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPhyAnalogSetupRegisters_s
block|{
name|bit32
name|spaRegister0
decl_stmt|;
name|bit32
name|spaRegister1
decl_stmt|;
name|bit32
name|spaRegister2
decl_stmt|;
name|bit32
name|spaRegister3
decl_stmt|;
name|bit32
name|spaRegister4
decl_stmt|;
name|bit32
name|spaRegister5
decl_stmt|;
name|bit32
name|spaRegister6
decl_stmt|;
name|bit32
name|spaRegister7
decl_stmt|;
name|bit32
name|spaRegister8
decl_stmt|;
name|bit32
name|spaRegister9
decl_stmt|;
block|}
name|agsaPhyAnalogSetupRegisters_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_INDEX
value|10
end_define

begin_comment
comment|/** \brief  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPhyAnalogSetupTable_s
block|{
name|agsaPhyAnalogSetupRegisters_t
name|phyAnalogSetupRegisters
index|[
name|MAX_INDEX
index|]
decl_stmt|;
block|}
name|agsaPhyAnalogSetupTable_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a Phy Analog Setting  *  * Describe a Phy Analog Setup registers for a controller in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPhyAnalogSettingsPage_s
block|{
name|bit32
name|Dword0
decl_stmt|;
name|bit32
name|Dword1
decl_stmt|;
name|bit32
name|Dword2
decl_stmt|;
name|bit32
name|Dword3
decl_stmt|;
name|bit32
name|Dword4
decl_stmt|;
name|bit32
name|Dword5
decl_stmt|;
name|bit32
name|Dword6
decl_stmt|;
name|bit32
name|Dword7
decl_stmt|;
name|bit32
name|Dword8
decl_stmt|;
name|bit32
name|Dword9
decl_stmt|;
block|}
name|agsaPhyAnalogSettingsPage_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a Open reject retry backoff threshold page  *  * Describe a Open reject retry backoff threshold registers in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSASPhyOpenRejectRetryBackOffThresholdPage_s
block|{
name|bit32
name|Dword0
decl_stmt|;
name|bit32
name|Dword1
decl_stmt|;
name|bit32
name|Dword2
decl_stmt|;
name|bit32
name|Dword3
decl_stmt|;
block|}
name|agsaSASPhyOpenRejectRetryBackOffThresholdPage_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a Phy Rate Control  *  4.56  agsaPhyRateControlPage_t  *  Description  *  This profile page is used to read or set several rate control  *  parameters. The page code for this profile page is 0x07. This page can  *  be READ by issuing saGetPhyProfile(). It can be read anytime and there  *  is no need to quiesce the I/O to the controller.  *  Related parameters can be modified by issuing saSetPhyProfile() before  *  calling saPhyStart() to the PHY.  *  Note: This page is applicable only to the SPCv controller.  *  Usage  *  Initiator and target.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPhyRateControlPage_s
block|{
name|bit32
name|Dword0
decl_stmt|;
name|bit32
name|Dword1
decl_stmt|;
name|bit32
name|Dword2
decl_stmt|;
block|}
name|agsaPhyRateControlPage_t
typedef|;
end_typedef

begin_comment
comment|/**  *  Dword0 Bits 0-11: ALIGN_RATE(ALNR). Align Insertion rate is 2 in every  *  ALIGN_RATE+1 DWord. The default value results in the standard compliant  *  value of 2/256. This rate applies to out of connection, SMP and SSP  *  connections. The default value is 0x0ff. Other bits are reserved.  *  Dword1 Bits 0 -11: STP_ALIGN_RATE(STPALNR) Align Insertion rate is 2 in  *  every ALIGN_RATE+1 DWords. Default value results in standard compliant  *  value of 2/256. This rate applies to out of STP connections. The default  *  value is 0x0ff. Other bits are reserved.  *  Dword2 Bits 0-7: SSP_FRAME_RATE(SSPFRMR) The number of idle DWords  *  between each SSP frame. 0 means no idle cycles. The default value is  *  0x0. Other bits are reserved. **/
end_comment

begin_comment
comment|/** \brief describe a Register Dump information for a Controller in the SAS/SATA hardware  *  * Describe a register dump information for a controller in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaRegDumpInfo_s
block|{
name|bit8
name|regDumpSrc
decl_stmt|;
name|bit8
name|regDumpNum
decl_stmt|;
name|bit8
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|bit32
name|regDumpOffset
decl_stmt|;
name|bit32
name|directLen
decl_stmt|;
name|void
modifier|*
name|directData
decl_stmt|;
name|bit32
name|indirectAddrUpper32
decl_stmt|;
name|bit32
name|indirectAddrLower32
decl_stmt|;
name|bit32
name|indirectLen
decl_stmt|;
block|}
name|agsaRegDumpInfo_t
typedef|;
end_typedef

begin_comment
comment|/* 7 :  SPC GSM register at [MEMBASE-III SHIFT =  0x00_0000] 8 :  SPC GSM register at [MEMBASE-III SHIFT =  0x05_0000] 9 :  BDMA GSM register at [MEMBASE-III SHIFT =  0x01_0000] 10:  PCIe APP GSM register at [MEMBASE-III SHIFT =  0x01_0000] 11:  PCIe PHY GSM register at [MEMBASE-III SHIFT =  0x01_0000] 12:  PCIe CORE GSM register at [MEMBASE-III SHIFT =  0x01_0000] 13:  OSSP GSM register at [MEMBASE-III SHIFT =  0x02_0000] 14:  SSPA GSM register at [MEMBASE-III SHIFT =  0x03_0000] 15:  SSPA GSM register at [MEMBASE-III SHIFT =  0x04_0000] 16:  HSST GSM register at [MEMBASE-III SHIFT =  0x02_0000] 17:  LMS_DSS(A) GSM register at [MEMBASE-III SHIFT =  0x03_0000] 18:  SSPL_6G GSM register at [MEMBASE-III SHIFT =  0x03_0000] 19:  HSST(A) GSM register at [MEMBASE-III SHIFT =  0x03_0000] 20:  LMS_DSS(A) GSM register at [MEMBASE-III SHIFT =  0x04_0000] 21:  SSPL_6G GSM register at [MEMBASE-III SHIFT =  0x04_0000] 22:  HSST(A) GSM register at [MEMBASE-III SHIFT =  0x04_0000] 23:  MBIC IOP GSM register at [MEMBASE-III SHIFT =  0x06_0000] 24:  MBIC AAP1 GSM register at [MEMBASE-III SHIFT =  0x07_0000] 25:  SPBC GSM register at [MEMBASE-III SHIFT =  0x09_0000] 26:  GSM GSM register at [MEMBASE-III SHIFT =  0x70_0000] */
end_comment

begin_define
define|#
directive|define
name|TYPE_GSM_SPACE
value|1
end_define

begin_define
define|#
directive|define
name|TYPE_QUEUE
value|2
end_define

begin_define
define|#
directive|define
name|TYPE_FATAL
value|3
end_define

begin_define
define|#
directive|define
name|TYPE_NON_FATAL
value|4
end_define

begin_define
define|#
directive|define
name|TYPE_INBOUND_QUEUE
value|5
end_define

begin_define
define|#
directive|define
name|TYPE_OUTBOUND_QUEUE
value|6
end_define

begin_define
define|#
directive|define
name|BAR_SHIFT_GSM_OFFSET
value|0x400000
end_define

begin_define
define|#
directive|define
name|ONE_MEGABYTE
value|0x100000
end_define

begin_define
define|#
directive|define
name|SIXTYFOURKBYTE
value|(1024 * 64)
end_define

begin_define
define|#
directive|define
name|TYPE_INBOUND
value|1
end_define

begin_define
define|#
directive|define
name|TYPE_OUTBOUND
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|bit32
name|DataType
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|bit32
name|directLen
decl_stmt|;
name|bit32
name|directOffset
decl_stmt|;
name|bit32
name|readLen
decl_stmt|;
name|void
modifier|*
name|directData
decl_stmt|;
block|}
name|gsmBuf
struct|;
struct|struct
block|{
name|bit16
name|queueType
decl_stmt|;
name|bit16
name|queueIndex
decl_stmt|;
name|bit32
name|directLen
decl_stmt|;
name|void
modifier|*
name|directData
decl_stmt|;
block|}
name|queueBuf
struct|;
struct|struct
block|{
name|bit32
name|directLen
decl_stmt|;
name|bit32
name|directOffset
decl_stmt|;
name|bit32
name|readLen
decl_stmt|;
name|void
modifier|*
name|directData
decl_stmt|;
block|}
name|dataBuf
struct|;
block|}
name|BufferType
union|;
block|}
name|agsaForensicData_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a NVMData for a Controller in the SAS/SATA hardware  *  * Describe a NVMData for a controller in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaNVMDData_s
block|{
name|bit32
name|indirectPayload
range|:
literal|1
decl_stmt|;
name|bit32
name|reserved
range|:
literal|7
decl_stmt|;
name|bit32
name|TWIDeviceAddress
range|:
literal|8
decl_stmt|;
name|bit32
name|TWIBusNumber
range|:
literal|4
decl_stmt|;
name|bit32
name|TWIDevicePageSize
range|:
literal|4
decl_stmt|;
name|bit32
name|TWIDeviceAddressSize
range|:
literal|4
decl_stmt|;
name|bit32
name|NVMDevice
range|:
literal|4
decl_stmt|;
name|bit32
name|directLen
range|:
literal|8
decl_stmt|;
name|bit32
name|dataOffsetAddress
range|:
literal|24
decl_stmt|;
name|void
modifier|*
name|directData
decl_stmt|;
name|bit32
name|indirectAddrUpper32
decl_stmt|;
name|bit32
name|indirectAddrLower32
decl_stmt|;
name|bit32
name|indirectLen
decl_stmt|;
name|bit32
name|signature
decl_stmt|;
block|}
name|agsaNVMDData_t
typedef|;
end_typedef

begin_comment
comment|/* status of ossaPCIeDiagExecuteCB() is shared with ossaSASDiagExecuteCB() */
end_comment

begin_define
define|#
directive|define
name|OSSA_PCIE_DIAG_SUCCESS
value|0x0000
end_define

begin_define
define|#
directive|define
name|OSSA_PCIE_DIAG_INVALID_COMMAND
value|0x0001
end_define

begin_define
define|#
directive|define
name|OSSA_PCIE_DIAG_INTERNAL_FAILURE
value|0x0002
end_define

begin_define
define|#
directive|define
name|OSSA_PCIE_DIAG_INVALID_CMD_TYPE
value|0x1006
end_define

begin_define
define|#
directive|define
name|OSSA_PCIE_DIAG_INVALID_CMD_DESC
value|0x1007
end_define

begin_define
define|#
directive|define
name|OSSA_PCIE_DIAG_INVALID_PCIE_ADDR
value|0x1008
end_define

begin_define
define|#
directive|define
name|OSSA_PCIE_DIAG_INVALID_BLOCK_SIZE
value|0x1009
end_define

begin_define
define|#
directive|define
name|OSSA_PCIE_DIAG_LENGTH_NOT_BLOCK_SIZE_ALIGNED
value|0x100A
end_define

begin_define
define|#
directive|define
name|OSSA_PCIE_DIAG_IO_XFR_ERROR_DIF_MISMATCH
value|0x3000
end_define

begin_define
define|#
directive|define
name|OSSA_PCIE_DIAG_IO_XFR_ERROR_DIF_APPLICATION_TAG_MISMATCH
value|0x3001
end_define

begin_define
define|#
directive|define
name|OSSA_PCIE_DIAG_IO_XFR_ERROR_DIF_REFERENCE_TAG_MISMATCH
value|0x3002
end_define

begin_define
define|#
directive|define
name|OSSA_PCIE_DIAG_IO_XFR_ERROR_DIF_CRC_MISMATCH
value|0x3003
end_define

begin_define
define|#
directive|define
name|OSSA_PCIE_DIAG_MPI_ERR_INVALID_LENGTH
value|0x0042
end_define

begin_define
define|#
directive|define
name|OSSA_PCIE_DIAG_MPI_ERR_IO_RESOURCE_UNAVAILABLE
value|0x1004
end_define

begin_define
define|#
directive|define
name|OSSA_PCIE_DIAG_MPI_ERR_CONTROLLER_NOT_IDLE
value|0x1005
end_define

begin_typedef
typedef|typedef
struct|struct
name|agsaPCIeDiagExecute_s
block|{
name|bit32
name|command
decl_stmt|;
name|bit32
name|flags
decl_stmt|;
name|bit16
name|initialIOSeed
decl_stmt|;
name|bit16
name|reserved
decl_stmt|;
name|bit32
name|rdAddrLower
decl_stmt|;
name|bit32
name|rdAddrUpper
decl_stmt|;
name|bit32
name|wrAddrLower
decl_stmt|;
name|bit32
name|wrAddrUpper
decl_stmt|;
name|bit32
name|len
decl_stmt|;
name|bit32
name|pattern
decl_stmt|;
name|bit8
name|udtArray
index|[
literal|6
index|]
decl_stmt|;
name|bit8
name|udrtArray
index|[
literal|6
index|]
decl_stmt|;
block|}
name|agsaPCIeDiagExecute_t
typedef|;
end_typedef

begin_comment
comment|/** \brief agsaPCIeDiagResponse_t  *  *  status of ossaPCIeDiagExecuteCB()  *  The agsaPCIeDiagResponse_t structure is a parameter passed to  *   ossaPCIeDiagExecuteCB()  * to contain a PCIe Diagnostic command response.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPCIeDiagResponse_s
block|{
name|bit32
name|ERR_BLKH
decl_stmt|;
name|bit32
name|ERR_BLKL
decl_stmt|;
name|bit32
name|DWord8
decl_stmt|;
name|bit32
name|DWord9
decl_stmt|;
name|bit32
name|DWord10
decl_stmt|;
name|bit32
name|DWord11
decl_stmt|;
name|bit32
name|DIF_ERR
decl_stmt|;
block|}
name|agsaPCIeDiagResponse_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a fatal error information for a Controller in the SAS/SATA hardware  *  * Describe a fatal error information for a controller in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaFatalErrorInfo_s
block|{
name|bit32
name|errorInfo0
decl_stmt|;
name|bit32
name|errorInfo1
decl_stmt|;
name|bit32
name|errorInfo2
decl_stmt|;
name|bit32
name|errorInfo3
decl_stmt|;
name|bit32
name|regDumpBusBaseNum0
decl_stmt|;
name|bit32
name|regDumpOffset0
decl_stmt|;
name|bit32
name|regDumpLen0
decl_stmt|;
name|bit32
name|regDumpBusBaseNum1
decl_stmt|;
name|bit32
name|regDumpOffset1
decl_stmt|;
name|bit32
name|regDumpLen1
decl_stmt|;
block|}
name|agsaFatalErrorInfo_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a information for a Event in the SAS/SATA hardware  *  * Describe a general information for a Event in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaEventSource_s
block|{
name|agsaPortContext_t
modifier|*
name|agPortContext
decl_stmt|;
name|bit32
name|event
decl_stmt|;
name|bit32
name|param
decl_stmt|;
block|}
name|agsaEventSource_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a information for a Controller in the SAS/SATA hardware  *  * Describe a general information for a controller in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaControllerInfo_s
block|{
name|bit32
name|signature
decl_stmt|;
comment|/* coherent controller information */
name|bit32
name|fwInterfaceRev
decl_stmt|;
comment|/* host and controller interface version */
name|bit32
name|hwRevision
decl_stmt|;
comment|/* controller HW Revision number */
name|bit32
name|fwRevision
decl_stmt|;
comment|/* controller FW Revision number */
name|bit32
name|ilaRevision
decl_stmt|;
comment|/* controller ILA Revision number */
name|bit32
name|maxPendingIO
decl_stmt|;
comment|/* maximum number of outstanding I/Os supported */
name|bit32
name|maxDevices
decl_stmt|;
comment|/* Maximum Device Supported by controller */
name|bit32
name|maxSgElements
decl_stmt|;
comment|/* maximum number of SG elements supported */
name|bit32
name|queueSupport
decl_stmt|;
comment|/* maximum number of IQ and OQ supported                                bit31-19 reserved                                bit18    interrupt coalescing                                bit17    reserved                                bit16    high priority IQ supported                                bit15-08 maximum number of OQ                                bit07-00 maximum number of IQ */
name|bit8
name|phyCount
decl_stmt|;
comment|/* number of phy available in the controller */
name|bit8
name|controllerSetting
decl_stmt|;
comment|/* Controller setting                                bit07-04 reserved                                bit03-00 HDA setting */
name|bit8
name|PCILinkRate
decl_stmt|;
comment|/* PCI generation 1/2/3 2.5g/5g/8g  */
name|bit8
name|PCIWidth
decl_stmt|;
comment|/* PCI number of lanes */
name|bit32
name|sasSpecsSupport
decl_stmt|;
comment|/* the supported SAS spec. */
name|bit32
name|sdkInterfaceRev
decl_stmt|;
comment|/* sdk interface reversion */
name|bit32
name|sdkRevision
decl_stmt|;
comment|/* sdk reversion */
block|}
name|agsaControllerInfo_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a status for a Controller in the SAS/SATA hardware  *  * Describe a general status for a controller in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaControllerStatus_s
block|{
name|agsaFatalErrorInfo_t
name|fatalErrorInfo
decl_stmt|;
comment|/* fatal error information */
name|bit32
name|interfaceState
decl_stmt|;
comment|/* host and controller interface state                                           bit02-00 state of host and controller                                           bit16-03 reserved                                           bit31-16 detail of error based on error state */
name|bit32
name|iqFreezeState0
decl_stmt|;
comment|/* freeze state of 1st set of IQ */
name|bit32
name|iqFreezeState1
decl_stmt|;
comment|/* freeze state of 2nd set of IQ */
name|bit32
name|tickCount0
decl_stmt|;
comment|/* tick count in second for internal CPU-0 */
name|bit32
name|tickCount1
decl_stmt|;
comment|/* tick count in second for internal CPU-1 */
name|bit32
name|tickCount2
decl_stmt|;
comment|/* tick count in second for internal CPU-2 */
name|bit32
name|phyStatus
index|[
literal|8
index|]
decl_stmt|;
comment|/* status of phy 0 to phy 15 */
name|bit32
name|recoverableErrorInfo
index|[
literal|8
index|]
decl_stmt|;
comment|/* controller specific recoverable error information */
name|bit32
name|bootStatus
decl_stmt|;
name|bit16
name|bootComponentState
index|[
literal|8
index|]
decl_stmt|;
block|}
name|agsaControllerStatus_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a GPIO Event Setup Infomation in the SAS/SATA hardware  *  * Describe a configuration for a GPIO Event Setup Infomation in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGpioEventSetupInfo_s
block|{
name|bit32
name|gpioPinMask
decl_stmt|;
name|bit32
name|gpioEventLevel
decl_stmt|;
name|bit32
name|gpioEventRisingEdge
decl_stmt|;
name|bit32
name|gpioEventFallingEdge
decl_stmt|;
block|}
name|agsaGpioEventSetupInfo_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a GPIO Pin Setup Infomation in the SAS/SATA hardware  *  * Describe a configuration for a GPIO Pin Setup Infomation in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGpioPinSetupInfo_t
block|{
name|bit32
name|gpioPinMask
decl_stmt|;
name|bit32
name|gpioInputEnabled
decl_stmt|;
name|bit32
name|gpioTypePart1
decl_stmt|;
name|bit32
name|gpioTypePart2
decl_stmt|;
block|}
name|agsaGpioPinSetupInfo_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a serial GPIO operation in the SAS/SATA hardware  *  * Describe a configuration for a GPIO write Setup Infomation in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGpioWriteSetupInfo_s
block|{
name|bit32
name|gpioWritemask
decl_stmt|;
name|bit32
name|gpioWriteVal
decl_stmt|;
block|}
name|agsaGpioWriteSetupInfo_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a GPIO Read Infomation in the SAS/SATA hardware  *  * Describe a configuration for a GPIO read Infomation in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGpioReadInfo_s
block|{
name|bit32
name|gpioReadValue
decl_stmt|;
name|bit32
name|gpioInputEnabled
decl_stmt|;
comment|/* GPIOIE */
name|bit32
name|gpioEventLevelChangePart1
decl_stmt|;
comment|/* GPIEVCHANGE (pins 11-0) */
name|bit32
name|gpioEventLevelChangePart2
decl_stmt|;
comment|/* GPIEVCHANGE (pins 23-20) */
name|bit32
name|gpioEventRisingEdgePart1
decl_stmt|;
comment|/* GPIEVRISE (pins 11-0) */
name|bit32
name|gpioEventRisingEdgePart2
decl_stmt|;
comment|/* GPIEVRISE (pins 23-20) */
name|bit32
name|gpioEventFallingEdgePart1
decl_stmt|;
comment|/* GPIEVALL (pins 11-0) */
name|bit32
name|gpioEventFallingEdgePart2
decl_stmt|;
comment|/* GPIEVALL (pins 23-20) */
block|}
name|agsaGpioReadInfo_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a serial GPIO request and response in the SAS/SATA hardware  *  * Describe the fields required for serial GPIO request and response in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSGpioReqResponse_s
block|{
name|bit8
name|smpFrameType
decl_stmt|;
comment|/* 0x40 for request, 0x41 for response*/
name|bit8
name|function
decl_stmt|;
comment|/* 0x02 for read, 0x82 for write */
name|bit8
name|registerType
decl_stmt|;
comment|/* used only in request */
name|bit8
name|registerIndex
decl_stmt|;
comment|/* used only in request */
name|bit8
name|registerCount
decl_stmt|;
comment|/* used only in request */
name|bit8
name|functionResult
decl_stmt|;
comment|/* used only in response */
name|bit32
name|readWriteData
index|[
name|OSSA_SGPIO_MAX_READ_DATA_COUNT
index|]
decl_stmt|;
comment|/* write data for request; read data for response */
block|}
name|agsaSGpioReqResponse_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a serial GPIO operation response in the SAS/SATA hardware  *  * Describe the fields required for serial GPIO operations response in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSGpioCfg0
block|{
name|bit8
name|reserved1
decl_stmt|;
name|bit8
name|version
range|:
literal|4
decl_stmt|;
name|bit8
name|reserved2
range|:
literal|4
decl_stmt|;
name|bit8
name|gpRegisterCount
range|:
literal|4
decl_stmt|;
name|bit8
name|cfgRegisterCount
range|:
literal|3
decl_stmt|;
name|bit8
name|gpioEnable
range|:
literal|1
decl_stmt|;
name|bit8
name|supportedDriveCount
decl_stmt|;
block|}
name|agsaSGpioCfg0_t
typedef|;
end_typedef

begin_comment
comment|/** \brief SGPIO configuration register 1  *  * These fields constitute SGPIO configuration register 1, as defined by SFF-8485 spec  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSGpioCfg1
block|{
name|bit8
name|reserved
decl_stmt|;
name|bit8
name|blinkGenA
range|:
literal|4
decl_stmt|;
name|bit8
name|blinkGenB
range|:
literal|4
decl_stmt|;
name|bit8
name|maxActOn
range|:
literal|4
decl_stmt|;
name|bit8
name|forceActOff
range|:
literal|4
decl_stmt|;
name|bit8
name|stretchActOn
range|:
literal|4
decl_stmt|;
name|bit8
name|stretchActOff
range|:
literal|4
decl_stmt|;
block|}
name|agsaSGpioCfg1_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a configuration for a PHY in the SAS/SATA hardware  *  * Describe a configuration for a PHY in the SAS/SATA hardware  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPhyConfig_s
block|{
name|bit32
name|phyProperties
decl_stmt|;
comment|/**< b31-b8 reserved */
comment|/**< b16-b19 SSC Disable */
comment|/**< b15-b8 phy analog setup index */
comment|/**< b7     phy analog setup enable */
comment|/**< b6     Control spin up hold */
comment|/**< b5-b4  SAS/SATA mode, bit4 - SAS, bit5 - SATA, 11b - Auto mode */
comment|/**< b3-b0  Max. Link Rate, bit0 - 1.5Gb/s, bit1 - 3.0Gb/s,                                   bit2 - 6.0Gb/s, bit3 - reserved */
block|}
name|agsaPhyConfig_t
typedef|;
end_typedef

begin_comment
comment|/** \brief Structure is used as a parameter passed in saLocalPhyControlCB() to describe the error counter  *  * Description  * This profile page is used to read or set the SNW-3 PHY capabilities of a  * SAS PHY. This page can be read by calling saGetPhyProfile(). It can be  * read anytime and there is no need to quiesce he I/O to the controller.  * The format of the 32-bit SNW3 is the same as defined in the SAS 2  * specification.  * Local SNW3 can be modified by calling saSetPhyProfile() before  * saPhyStart() to the PHY. REQUESTED LOGICAL LINK RATE is reserved.  * The SPCv will calculate the PARITY field.   * Note: This page is applicable only to the SPCv controller.  * Usage  * Initiator and target.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPhySNW3Page_s
block|{
name|bit32
name|LSNW3
decl_stmt|;
name|bit32
name|RSNW3
decl_stmt|;
block|}
name|agsaPhySNW3Page_t
typedef|;
end_typedef

begin_comment
comment|/** \brief structure describe error counters of a PHY in the SAS/SATA  *  * Structure is used as a parameter passed in saLocalPhyControlCB()  * to describe the error counter  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPhyErrCounters_s
block|{
name|bit32
name|invalidDword
decl_stmt|;
comment|/* Number of invalid dwords that have been                                        received outside of phy reset sequences.*/
name|bit32
name|runningDisparityError
decl_stmt|;
comment|/* Number of dwords containing running disparity                                        errors that have been received outside of phy                                        reset sequences.*/
name|bit32
name|lossOfDwordSynch
decl_stmt|;
comment|/* Number of times the phy has restarted the link                                        reset sequence because it lost dword synchronization.*/
name|bit32
name|phyResetProblem
decl_stmt|;
comment|/* Number of times the phy did not obtain dword                                        synchronization during the final SAS speed                                        negotiation window.*/
name|bit32
name|elasticityBufferOverflow
decl_stmt|;
comment|/* Number of times the phys receive elasticity                                        buffer has overflowed.*/
name|bit32
name|receivedErrorPrimitive
decl_stmt|;
comment|/* Number of times the phy received an ERROR primitive */
name|bit32
name|inboundCRCError
decl_stmt|;
comment|/* Number of inbound CRC Error */
name|bit32
name|codeViolation
decl_stmt|;
comment|/* Number of code violation */
block|}
name|agsaPhyErrCounters_t
typedef|;
end_typedef

begin_comment
comment|/** \brief  * used in saGetPhyProfile  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPhyErrCountersPage_s
block|{
name|bit32
name|invalidDword
decl_stmt|;
name|bit32
name|runningDisparityError
decl_stmt|;
name|bit32
name|codeViolation
decl_stmt|;
name|bit32
name|lossOfDwordSynch
decl_stmt|;
name|bit32
name|phyResetProblem
decl_stmt|;
name|bit32
name|inboundCRCError
decl_stmt|;
block|}
name|agsaPhyErrCountersPage_t
typedef|;
end_typedef

begin_comment
comment|/** \brief structure describes bandwidth counters of a PHY in the SAS/SATA  *  * Structure is used as a parameter passed in saGetPhyProfile()  * to describe the error counter  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPhyBWCountersPage_s
block|{
name|bit32
name|TXBWCounter
decl_stmt|;
name|bit32
name|RXBWCounter
decl_stmt|;
block|}
name|agsaPhyBWCountersPage_t
typedef|;
end_typedef

begin_comment
comment|/** \brief structure describe hardware configuration  *  * Structure is used as a parameter passed in saInitialize() to describe the  * configuration used during hardware initialization  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaHwConfig_s
block|{
name|bit32
name|phyCount
decl_stmt|;
comment|/**< Number of PHYs that are to be configured                                          and initialized.  */
name|bit32
name|hwInterruptCoalescingTimer
decl_stmt|;
comment|/**< Host Interrupt CoalescingTimer */
name|bit32
name|hwInterruptCoalescingControl
decl_stmt|;
comment|/**< Host Interrupt CoalescingControl */
name|bit32
name|intReassertionOption
decl_stmt|;
comment|/**< Interrupt Ressertion Option */
name|bit32
name|hwOption
decl_stmt|;
comment|/** PCAD64 on 64 bit addressing */
name|agsaPhyAnalogSetupTable_t
name|phyAnalogConfig
decl_stmt|;
comment|/**< Phy Analog Setting Table */
block|}
name|agsaHwConfig_t
typedef|;
end_typedef

begin_comment
comment|/** \brief structure describe software configuration  *  * Structure is used as a parameter passed in saInitialize() to describe the  * configuration used during software initialization  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSwConfig_s
block|{
name|bit32
name|maxActiveIOs
decl_stmt|;
comment|/**< Maximum active I/O requests supported */
name|bit32
name|numDevHandles
decl_stmt|;
comment|/**< Number of SAS/SATA device handles allocated                                          in the pool */
name|bit32
name|smpReqTimeout
decl_stmt|;
comment|/**< SMP request time out in millisecond */
name|bit32
name|numberOfEventRegClients
decl_stmt|;
comment|/**< Maximum number of OS Layer clients for the event                                              registration defined by saRegisterEventCallback() */
name|bit32
name|sizefEventLog1
decl_stmt|;
comment|/**< Size of Event Log 1 */
name|bit32
name|sizefEventLog2
decl_stmt|;
comment|/**< Size of Event Log 2 */
name|bit32
name|eventLog1Option
decl_stmt|;
comment|/**< Option of Event Log 1 */
name|bit32
name|eventLog2Option
decl_stmt|;
comment|/**< Option of Event Log 2 */
name|bit32
name|fatalErrorInterruptEnable
range|:
literal|1
decl_stmt|;
comment|/**< 0 Fatal Error Iterrupt Enable */
name|bit32
name|sgpioSupportEnable
range|:
literal|1
decl_stmt|;
comment|/**< 1 SGPIO Support Enable */
name|bit32
name|fatalErrorInterruptVector
range|:
literal|8
decl_stmt|;
comment|/**< 2-9  Fatal Error Interrupt Vector */
name|bit32
name|max_MSI_InterruptVectors
range|:
literal|8
decl_stmt|;
comment|/**< 10-18 Maximum MSI Interrupt Vectors */
name|bit32
name|max_MSIX_InterruptVectors
range|:
literal|8
decl_stmt|;
comment|/**< 18-25 Maximum MSIX Interrupt Vectors */
name|bit32
name|legacyInt_X
range|:
literal|1
decl_stmt|;
comment|/**< 26 Support Legacy Interrupt */
name|bit32
name|hostDirectAccessSupport
range|:
literal|1
decl_stmt|;
comment|/**< 27 Support HDA mode */
name|bit32
name|hostDirectAccessMode
range|:
literal|2
decl_stmt|;
comment|/**< 28-29 HDA mode: 00b - HDA SoftReset, 01b - HDA Normal */
name|bit32
name|enableDIF
range|:
literal|1
decl_stmt|;
comment|/**< 30 */
name|bit32
name|enableEncryption
range|:
literal|1
decl_stmt|;
comment|/**< 31 */
ifdef|#
directive|ifdef
name|SA_CONFIG_MDFD_REGISTRY
name|bit32
name|disableMDF
decl_stmt|;
comment|/*disable MDF*/
endif|#
directive|endif
name|bit32
name|param1
decl_stmt|;
comment|/**< parameter1 */
name|bit32
name|param2
decl_stmt|;
comment|/**< parameter2 */
name|void
modifier|*
name|param3
decl_stmt|;
comment|/**< parameter3 */
name|void
modifier|*
name|param4
decl_stmt|;
comment|/**< paramater4 */
name|bit32
name|stallUsec
decl_stmt|;
name|bit32
name|FWConfig
decl_stmt|;
name|bit32
name|PortRecoveryResetTimer
decl_stmt|;
name|void
modifier|*
name|mpiContextTable
decl_stmt|;
comment|/** Pointer to a table that contains agsaMPIContext_t                                             entries. This table is used to fill in MPI table                                             fields. Values in this table are written to MPI table last.                                             Any previous values in MPI table are overwritten by values                                             in this table. */
name|bit32
name|mpiContextTablelen
decl_stmt|;
comment|/** Number of agsaMPIContext_t entries in mpiContextTable */
if|#
directive|if
name|defined
argument_list|(
name|SALLSDK_DEBUG
argument_list|)
name|bit32
name|sallDebugLevel
decl_stmt|;
comment|/**< Low Layer debug level */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SA_ENABLE_PCI_TRIGGER
name|bit32
name|PCI_trigger
decl_stmt|;
endif|#
directive|endif
comment|/* SA_ENABLE_PCI_TRIGGER */
ifdef|#
directive|ifdef
name|SA_ENABLE_TRACE_FUNCTIONS
name|bit32
name|TraceDestination
decl_stmt|;
name|bit32
name|TraceBufferSize
decl_stmt|;
name|bit32
name|TraceMask
decl_stmt|;
endif|#
directive|endif
comment|/* SA_ENABLE_TRACE_FUNCTIONS */
block|}
name|agsaSwConfig_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaQueueInbound_s
block|{
name|bit32
name|elementCount
range|:
literal|16
decl_stmt|;
comment|/* Maximum number of elements in the queue (queue depth).                                A value of zero indicates that the host disabled this queue.*/
name|bit32
name|elementSize
range|:
literal|16
decl_stmt|;
comment|/* Size of each element in the queue in bytes.*/
name|bit32
name|priority
range|:
literal|2
decl_stmt|;
comment|/* Queue priority:                                     00: normal priority                                     01: high priority                                     10: reserved                                     11: reserved */
name|bit32
name|reserved
range|:
literal|30
decl_stmt|;
block|}
name|agsaQueueInbound_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaQueueOutbound_s
block|{
name|bit32
name|elementCount
range|:
literal|16
decl_stmt|;
comment|/* Maximum number of elements in the queue (queue depth).                                        A value of zero indicates that the host disabled                                        this queue.*/
name|bit32
name|elementSize
range|:
literal|16
decl_stmt|;
comment|/* Size of each element in the queue in bytes.*/
name|bit32
name|interruptDelay
range|:
literal|16
decl_stmt|;
comment|/* Time, in usec, to delay interrupts to the host.                                        Zero means not to delay based on time. An                                        interrupt is passed to the host when either of                                        the interruptDelay or interruptCount parameters                                        is satisfied. Default value is 0.*/
name|bit32
name|interruptCount
range|:
literal|16
decl_stmt|;
comment|/* Number of interrupts required before passing to                                        the host. Zero means not to coalesce based on count. */
name|bit32
name|interruptVectorIndex
range|:
literal|8
decl_stmt|;
comment|/* MSI/MSI-X interrupt vector index. For MSI, when                                        Multiple Messages is enabled, this field is the                                        index to the MSI vectors derived from a single                                        Message Address and multiple Message Data.                                        For MSI-X, this field is the index to the                                        MSI-X Table Structure. */
name|bit32
name|interruptEnable
range|:
literal|1
decl_stmt|;
comment|/* 0b: No interrupt to host (host polling)                                        1b: Interrupt enabled */
name|bit32
name|reserved
range|:
literal|23
decl_stmt|;
block|}
name|agsaQueueOutbound_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaPhyCalibrationTbl_s
block|{
name|bit32
name|txPortConfig1
decl_stmt|;
comment|/* transmitter per port configuration 1 SAS_SATA G1 */
name|bit32
name|txPortConfig2
decl_stmt|;
comment|/* transmitter per port configuration 2 SAS_SATA G1*/
name|bit32
name|txPortConfig3
decl_stmt|;
comment|/* transmitter per port configuration 3 SAS_SATA G1*/
name|bit32
name|txConfig1
decl_stmt|;
comment|/* transmitter configuration 1 */
name|bit32
name|rvPortConfig1
decl_stmt|;
comment|/* reveiver per port configuration 1 SAS_SATA G1G2 */
name|bit32
name|rvPortConfig2
decl_stmt|;
comment|/* reveiver per port configuration 2 SAS_SATA G3 */
name|bit32
name|rvConfig1
decl_stmt|;
comment|/* reveiver per configuration 1 */
name|bit32
name|rvConfig2
decl_stmt|;
comment|/* reveiver per configuration 2 */
name|bit32
name|reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* reserved */
block|}
name|agsaPhyCalibrationTbl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaQueueConfig_s
block|{
name|bit16
name|numInboundQueues
decl_stmt|;
name|bit16
name|numOutboundQueues
decl_stmt|;
name|bit8
name|sasHwEventQueue
index|[
name|AGSA_MAX_VALID_PHYS
index|]
decl_stmt|;
name|bit8
name|sataNCQErrorEventQueue
index|[
name|AGSA_MAX_VALID_PHYS
index|]
decl_stmt|;
name|bit8
name|tgtITNexusEventQueue
index|[
name|AGSA_MAX_VALID_PHYS
index|]
decl_stmt|;
name|bit8
name|tgtSSPEventQueue
index|[
name|AGSA_MAX_VALID_PHYS
index|]
decl_stmt|;
name|bit8
name|tgtSMPEventQueue
index|[
name|AGSA_MAX_VALID_PHYS
index|]
decl_stmt|;
name|bit8
name|iqNormalPriorityProcessingDepth
decl_stmt|;
name|bit8
name|iqHighPriorityProcessingDepth
decl_stmt|;
name|bit8
name|generalEventQueue
decl_stmt|;
name|bit8
name|tgtDeviceRemovedEventQueue
decl_stmt|;
name|bit32
name|queueOption
decl_stmt|;
name|agsaQueueInbound_t
name|inboundQueues
index|[
name|AGSA_MAX_INBOUND_Q
index|]
decl_stmt|;
name|agsaQueueOutbound_t
name|outboundQueues
index|[
name|AGSA_MAX_OUTBOUND_Q
index|]
decl_stmt|;
block|}
name|agsaQueueConfig_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OQ_SHARE_PATH_BIT
value|0x00000001
end_define

begin_typedef
typedef|typedef
struct|struct
name|agsaFwImg_s
block|{
name|bit8
modifier|*
name|aap1Img
decl_stmt|;
comment|/**< AAP1 Image */
name|bit32
name|aap1Len
decl_stmt|;
comment|/**< AAP1 Image Length */
name|bit8
modifier|*
name|ilaImg
decl_stmt|;
comment|/**< ILA Image */
name|bit32
name|ilaLen
decl_stmt|;
comment|/**< ILA Image Length */
name|bit8
modifier|*
name|iopImg
decl_stmt|;
comment|/**< IOP Image */
name|bit32
name|iopLen
decl_stmt|;
comment|/**< IOP Image Length */
name|bit8
modifier|*
name|istrImg
decl_stmt|;
comment|/**< Init String */
name|bit32
name|istrLen
decl_stmt|;
comment|/**< Init String Length */
block|}
name|agsaFwImg_t
typedef|;
end_typedef

begin_comment
comment|/** \brief generic memory descriptor  *  * a generic memory descriptor used for describing a memory requirement in a structure  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaMem_s
block|{
name|void
modifier|*
name|virtPtr
decl_stmt|;
comment|/**< Virtual pointer to the memory chunk */
name|void
modifier|*
name|osHandle
decl_stmt|;
comment|/**< Handle used for OS to free memory */
name|bit32
name|phyAddrUpper
decl_stmt|;
comment|/**< Upper 32 bits of physical address */
name|bit32
name|phyAddrLower
decl_stmt|;
comment|/**< Lower 32 bits of physical address */
name|bit32
name|totalLength
decl_stmt|;
comment|/**< Total length in bytes allocated */
name|bit32
name|numElements
decl_stmt|;
comment|/**< Number of elements */
name|bit32
name|singleElementLength
decl_stmt|;
comment|/**< Size in bytes of an element */
name|bit32
name|alignment
decl_stmt|;
comment|/**< Alignment in bytes needed. A value of one indicates                                      no specific alignment requirement */
name|bit32
name|type
decl_stmt|;
comment|/**< DMA or Cache */
name|bit32
name|reserved
decl_stmt|;
comment|/**< reserved */
block|}
name|agsaMem_t
typedef|;
end_typedef

begin_comment
comment|/** \brief specify the controller Event Log for the SAS/SATA LL Layer  *  * data structure used in the saGetControllerEventLogInfo() function calls  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaControllerEventLog_s
block|{
name|agsaMem_t
name|eventLog1
decl_stmt|;
name|agsaMem_t
name|eventLog2
decl_stmt|;
name|bit32
name|eventLog1Option
decl_stmt|;
name|bit32
name|eventLog2Option
decl_stmt|;
block|}
name|agsaControllerEventLog_t
typedef|;
end_typedef

begin_comment
comment|/* Log Option - bit3-0 */
end_comment

begin_define
define|#
directive|define
name|DISABLE_LOGGING
value|0x0
end_define

begin_define
define|#
directive|define
name|CRITICAL_ERROR
value|0x1
end_define

begin_define
define|#
directive|define
name|WARNING
value|0x2
end_define

begin_define
define|#
directive|define
name|NOTICE
value|0x3
end_define

begin_define
define|#
directive|define
name|INFORMATION
value|0x4
end_define

begin_define
define|#
directive|define
name|DEBUGGING
value|0x5
end_define

begin_comment
comment|/** \brief specify the SAS Diagnostic Parameters for the SAS/SATA LL Layer  *  * data structure used in the saGetRequirements() and the saInitialize() function calls  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSASDiagExecute_s
block|{
name|bit32
name|command
decl_stmt|;
name|bit32
name|param0
decl_stmt|;
name|bit32
name|param1
decl_stmt|;
name|bit32
name|param2
decl_stmt|;
name|bit32
name|param3
decl_stmt|;
name|bit32
name|param4
decl_stmt|;
name|bit32
name|param5
decl_stmt|;
block|}
name|agsaSASDiagExecute_t
typedef|;
end_typedef

begin_comment
comment|/** \brief  for the SAS/SATA LL Layer  *  *  This data structure contains the general status of a SAS Phy.  *  Section 4.60  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSASPhyGeneralStatusPage_s
block|{
name|bit32
name|Dword0
decl_stmt|;
name|bit32
name|Dword1
decl_stmt|;
block|}
name|agsaSASPhyGeneralStatusPage_t
typedef|;
end_typedef

begin_comment
comment|/** \brief specify the memory allocation requirement for the SAS/SATA LL Layer  *  * data structure used in the saGetRequirements() and the saInitialize() function calls  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaMemoryRequirement_s
block|{
name|bit32
name|count
decl_stmt|;
comment|/**< The number of memory chunks used                                                   in the agMemory table */
name|agsaMem_t
name|agMemory
index|[
name|AGSA_NUM_MEM_CHUNKS
index|]
decl_stmt|;
comment|/**< The structure that defines the memory                                                   requirement structure */
block|}
name|agsaMemoryRequirement_t
typedef|;
end_typedef

begin_comment
comment|/** \brief describe a SAS address and PHY Identifier  *  * This structure is used  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSASAddressID_s
block|{
name|bit8
name|sasAddressLo
index|[
literal|4
index|]
decl_stmt|;
comment|/**< HOST SAS address lower part */
name|bit8
name|sasAddressHi
index|[
literal|4
index|]
decl_stmt|;
comment|/**< HOST SAS address higher part */
name|bit8
name|phyIdentifier
decl_stmt|;
comment|/**< PHY IDENTIFIER of the PHY */
block|}
name|agsaSASAddressID_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure provides some information about a SATA device  *  * data structure provides some information about a SATA device discovered  * following the SATA discovery.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaDeviceInfo_s
block|{
name|bit16
name|smpTimeout
decl_stmt|;
name|bit16
name|it_NexusTimeout
decl_stmt|;
name|bit16
name|firstBurstSize
decl_stmt|;
name|bit8
name|reserved
decl_stmt|;
comment|/* Not Used */
name|bit8
name|devType_S_Rate
decl_stmt|;
comment|/* Bit 6-7: reserved        Bit 4-5: Two-bit flag to specify a SSP/SMP, or directly attached SATA or STP device                 00: STP device                 01: SSP or SMP device                 10: Direct SATA device        Bit 0-3: Connection Rate field when opening the device.                 Code Description:                 08h:  1.5 Gbps                 09h:  3.0 Gbps                 0ah:  6.0 Gbps                 All others Reserved     */
name|bit8
name|sasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|sasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit32
name|flag
decl_stmt|;
comment|/* flag Bit 0: Retry flag.       1b: enable SAS TLR (Transport Layer Retry).       0b: disable SAS TLR (Transport Layer Retry).           When used during device registration, it is recommended that TLR is           enabled, i.e. set the bit to 1. Bit 1: Priority setting for AWT (Arbitration Wait Time) for this device.       0b: Default setting (recommended). Actual AWT value TBD.       1b: Increase priority. Actual AWT value TBD. Bit 2-3: Reserved Bit 4-11: Zero-based PHY identifier. This field is used only if bits 4-5 in devType_S_Rate are set to 10b           which indicates a directly-attached SATA drive. Bit 12-15: Reserved Bit 16-19 : Maximum Connection Number. This field specifies the maximum number of connections that             can be established with the device concurrently. This field is set to the lowest port width along the pathway             from the controller to the device. This is applicable only to the SPCv controller.             However, for backward compatibility reasons, if this field is set to zero, it is treated as 1 so that the controller             can establish at least one connection. Bit 20: Initiator Role         This bit indicates whether the device has SSP initiator role capability. This is applicable only to the SPCv controller.       0b : The device has no SSP initiator capability.       1b : The device has SSP initiator capability. Bit 21: ATAPI Device Flag. (Only applies to the SPCv) Flag to indicate ATAPI protocol support       0b : Device does not support ATAPI protocol.       1b : Device supports ATAPI protocol. Bit 22-31: Reserved */
block|}
name|agsaDeviceInfo_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEV_INFO_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|DEV_INFO_MCN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DEV_INFO_IR_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|RETRY_DEVICE_FLAG
value|(1<< SHIFT0)
end_define

begin_define
define|#
directive|define
name|AWT_DEVICE_FLAG
value|(1<< SHIFT1)
end_define

begin_define
define|#
directive|define
name|SSP_DEVICE_FLAG
value|(1<< SHIFT20)
end_define

begin_define
define|#
directive|define
name|ATAPI_DEVICE_FLAG
value|0x200000
end_define

begin_comment
comment|/* bit21  */
end_comment

begin_define
define|#
directive|define
name|XFER_RDY_PRIORTY_DEVICE_FLAG
value|(1<< SHIFT22)
end_define

begin_define
define|#
directive|define
name|DEV_LINK_RATE
value|0x3F
end_define

begin_define
define|#
directive|define
name|SA_DEVINFO_GET_SAS_ADDRESSLO
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(devInfo)->sasAddressLo)
end_define

begin_define
define|#
directive|define
name|SA_DEVINFO_GET_SAS_ADDRESSHI
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(devInfo)->sasAddressHi)
end_define

begin_define
define|#
directive|define
name|SA_DEVINFO_GET_DEVICETTYPE
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|(((devInfo)->devType_S_Rate& 0xC0)>> 5)
end_define

begin_define
define|#
directive|define
name|SA_DEVINFO_PUT_SAS_ADDRESSLO
parameter_list|(
name|devInfo
parameter_list|,
name|src32
parameter_list|)
define|\
value|*(bit32 *)((devInfo)->sasAddressLo) = BIT32_TO_DMA_BEBIT32(src32)
end_define

begin_define
define|#
directive|define
name|SA_DEVINFO_PUT_SAS_ADDRESSHI
parameter_list|(
name|devInfo
parameter_list|,
name|src32
parameter_list|)
define|\
value|*(bit32 *)((devInfo)->sasAddressHi) = BIT32_TO_DMA_BEBIT32(src32)
end_define

begin_comment
comment|/** \brief data structure provides some information about a SATA device  *  * data structure provides some information about a SATA device discovered  * following the SATA discovery.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSATADeviceInfo_s
block|{
name|agsaDeviceInfo_t
name|commonDevInfo
decl_stmt|;
comment|/**< The general/common part of the                                                          SAS/SATA device information */
name|bit8
name|connection
decl_stmt|;
comment|/**< How device is connected:                                                            0: Direct attached.                                                            1: Behind Port Multiplier,                                                               portMultiplierField is valid.                                                            2: STP, stpPhyIdentifier is valid */
name|bit8
name|portMultiplierField
decl_stmt|;
comment|/**< The first 4 bits indicate that                                                          the Port Multiplier field is defined                                                          by SATA-II. This field is valid only                                                          if the connection field above is                                                          set to 1 */
name|bit8
name|stpPhyIdentifier
decl_stmt|;
comment|/**< PHY ID of the STP PHY. Valid only if                                                          connection field is set to 2 (STP). */
name|bit8
name|reserved
decl_stmt|;
name|bit8
name|signature
index|[
literal|8
index|]
decl_stmt|;
comment|/**< The signature of SATA in Task                                                          File registers following power up.                                                          Only five bytes are defined by ATA.                                                          The added three bytes are for                                                          alignment purposes */
block|}
name|agsaSATADeviceInfo_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure provides some information about a SAS device  *  * data structure provides some information about a SAS device discovered  * following the SAS discovery  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSASDeviceInfo_s
block|{
name|agsaDeviceInfo_t
name|commonDevInfo
decl_stmt|;
comment|/**< The general/common part of the SAS/SATA                                                  device information */
name|bit8
name|initiator_ssp_stp_smp
decl_stmt|;
comment|/**< SAS initiator capabilities */
comment|/* b4-7: reserved */
comment|/* b3:   SSP initiator port */
comment|/* b2:   STP initiator port */
comment|/* b1:   SMP initiator port */
comment|/* b0:   reserved */
name|bit8
name|target_ssp_stp_smp
decl_stmt|;
comment|/**< SAS target capabilities */
comment|/* b4-7: reserved */
comment|/* b3:   SSP target port */
comment|/* b2:   STP target port */
comment|/* b1:   SMP target port */
comment|/* b0:   reserved */
name|bit32
name|numOfPhys
decl_stmt|;
comment|/**< Number of PHYs in the device */
name|bit8
name|phyIdentifier
decl_stmt|;
comment|/**< PHY IDENTIFIER in IDENTIFY address                                                  frame as defined by the SAS                                                  specification. */
block|}
name|agsaSASDeviceInfo_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SA_SASDEV_SSP_BIT
value|SA_IDFRM_SSP_BIT
end_define

begin_comment
comment|/* SSP Initiator port */
end_comment

begin_define
define|#
directive|define
name|SA_SASDEV_STP_BIT
value|SA_IDFRM_STP_BIT
end_define

begin_comment
comment|/* STP Initiator port */
end_comment

begin_define
define|#
directive|define
name|SA_SASDEV_SMP_BIT
value|SA_IDFRM_SMP_BIT
end_define

begin_comment
comment|/* SMP Initiator port */
end_comment

begin_define
define|#
directive|define
name|SA_SASDEV_SATA_BIT
value|SA_IDFRM_SATA_BIT
end_define

begin_comment
comment|/* SATA device, valid in the discovery response only */
end_comment

begin_define
define|#
directive|define
name|SA_SASDEV_IS_SSP_INITIATOR
parameter_list|(
name|sasDev
parameter_list|)
define|\
value|(((sasDev)->initiator_ssp_stp_smp& SA_SASDEV_SSP_BIT) == SA_SASDEV_SSP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_SASDEV_IS_STP_INITIATOR
parameter_list|(
name|sasDev
parameter_list|)
define|\
value|(((sasDev)->initiator_ssp_stp_smp& SA_SASDEV_STP_BIT) == SA_SASDEV_STP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_SASDEV_IS_SMP_INITIATOR
parameter_list|(
name|sasDev
parameter_list|)
define|\
value|(((sasDev)->initiator_ssp_stp_smp& SA_SASDEV_SMP_BIT) == SA_SASDEV_SMP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_SASDEV_IS_SSP_TARGET
parameter_list|(
name|sasDev
parameter_list|)
define|\
value|(((sasDev)->target_ssp_stp_smp& SA_SASDEV_SSP_BIT) == SA_SASDEV_SSP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_SASDEV_IS_STP_TARGET
parameter_list|(
name|sasDev
parameter_list|)
define|\
value|(((sasDev)->target_ssp_stp_smp& SA_SASDEV_STP_BIT) == SA_SASDEV_STP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_SASDEV_IS_SMP_TARGET
parameter_list|(
name|sasDev
parameter_list|)
define|\
value|(((sasDev)->target_ssp_stp_smp& SA_SASDEV_SMP_BIT) == SA_SASDEV_SMP_BIT)
end_define

begin_define
define|#
directive|define
name|SA_SASDEV_IS_SATA_DEVICE
parameter_list|(
name|sasDev
parameter_list|)
define|\
value|(((sasDev)->target_ssp_stp_smp& SA_SASDEV_SATA_BIT) == SA_SASDEV_SATA_BIT)
end_define

begin_comment
comment|/** \brief the data structure describe SG list  *  * the data structure describe SG list  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SASG_DESCRIPTOR
block|{
name|bit32
name|sgLower
decl_stmt|;
comment|/**< Lower 32 bits of data area physical address */
name|bit32
name|sgUpper
decl_stmt|;
comment|/**< Upper 32 bits of data area physical address */
name|bit32
name|len
decl_stmt|;
comment|/**< Total data length in bytes */
block|}
name|SASG_DESCRIPTOR
operator|,
typedef|*
name|PSASG_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure used to pass information about the scatter-gather list to the LL Layer  *  * The ESGL pages are uncached, have a configurable number of SGL  * of (min, max) = (1, 10), and are 16-byte aligned. Although  * the application can configure the page size, the size must be  * incremented in TBD-byte increments. Refer the hardware  * documentation for more detail on the format of ESGL  * structure.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSgl_s
block|{
name|bit32
name|sgLower
decl_stmt|;
comment|/**< Lower 32 bits of data area physical address */
name|bit32
name|sgUpper
decl_stmt|;
comment|/**< Upper 32 bits of data area physical address */
name|bit32
name|len
decl_stmt|;
comment|/**< Total data length in bytes */
name|bit32
name|extReserved
decl_stmt|;
comment|/**< bit31 is for extended sgl list */
block|}
name|agsaSgl_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure is used to pass information about the extended  *  scatter-gather list (ESGL) to the LL Layer  *  * The agsaEsgl_t data structure is used to pass information about the  * extended scatter-gather list (ESGL) to the LL Layer.  *  * When ESGL is used, its starting address is specified the first descriptor  * entry (i.e. descriptor[0]) in agsaSgl_t structure.  *  * The ESGL pages are uncached, have a fixed number of SGL of 10, and are  * 16-byte aligned. Refer the hardware documentation for more  * detail on ESGL.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaEsgl_s
block|{
name|agsaSgl_t
name|descriptor
index|[
name|MAX_ESGL_ENTRIES
index|]
decl_stmt|;
block|}
name|agsaEsgl_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure describes an SSP Command INFORMATION UNIT  *  * data structure describes an SSP Command INFORMATION UNIT used for SSP command and is part of  * the SSP frame.  *  * Currently, Additional CDB length is supported to 16 bytes  *  */
end_comment

begin_define
define|#
directive|define
name|MAX_CDB_LEN
value|32
end_define

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPCmdInfoUnitExt_s
block|{
name|bit8
name|lun
index|[
literal|8
index|]
decl_stmt|;
name|bit8
name|reserved1
decl_stmt|;
name|bit8
name|efb_tp_taskAttribute
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|additionalCdbLen
decl_stmt|;
name|bit8
name|cdb
index|[
name|MAX_CDB_LEN
index|]
decl_stmt|;
block|}
name|agsaSSPCmdInfoUnitExt_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DIF_UDT_SIZE
value|6
end_define

begin_comment
comment|/* difAction in agsaDif_t */
end_comment

begin_define
define|#
directive|define
name|AGSA_DIF_INSERT
value|0
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_VERIFY_FORWARD
value|1
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_VERIFY_DELETE
value|2
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_VERIFY_REPLACE
value|3
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_VERIFY_UDT_REPLACE_CRC
value|5
end_define

begin_define
define|#
directive|define
name|AGSA_DIF_REPLACE_UDT_REPLACE_CRC
value|7
end_define

begin_define
define|#
directive|define
name|agsaDIFSectorSize512
value|0
end_define

begin_define
define|#
directive|define
name|agsaDIFSectorSize520
value|1
end_define

begin_define
define|#
directive|define
name|agsaDIFSectorSize4096
value|2
end_define

begin_define
define|#
directive|define
name|agsaDIFSectorSize4160
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
name|agsaDif_s
block|{
name|agBOOLEAN
name|enableDIFPerLA
decl_stmt|;
name|bit32
name|flags
decl_stmt|;
name|bit16
name|initialIOSeed
decl_stmt|;
name|bit16
name|reserved
decl_stmt|;
name|bit32
name|DIFPerLAAddrLo
decl_stmt|;
name|bit32
name|DIFPerLAAddrHi
decl_stmt|;
name|bit16
name|DIFPerLARegion0SecCount
decl_stmt|;
name|bit16
name|Reserved2
decl_stmt|;
name|bit8
name|udtArray
index|[
name|DIF_UDT_SIZE
index|]
decl_stmt|;
name|bit8
name|udrtArray
index|[
name|DIF_UDT_SIZE
index|]
decl_stmt|;
block|}
name|agsaDif_t
typedef|;
end_typedef

begin_comment
comment|/* From LL SDK2 */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_ACTION
value|0x00000007
end_define

begin_comment
comment|/* 0-2*/
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_CRC_VER
value|0x00000008
end_define

begin_comment
comment|/* 3 */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_CRC_INV
value|0x00000010
end_define

begin_comment
comment|/* 4 */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_CRC_SEED
value|0x00000020
end_define

begin_comment
comment|/* 5 */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_UDT_REF_TAG
value|0x00000040
end_define

begin_comment
comment|/* 6 */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_UDT_APP_TAG
value|0x00000080
end_define

begin_comment
comment|/* 7 */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_UDTR_REF_BLKCOUNT
value|0x00000100
end_define

begin_comment
comment|/* 8 */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_UDTR_APP_BLKCOUNT
value|0x00000200
end_define

begin_comment
comment|/* 9 */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_CUST_APP_TAG
value|0x00000C00
end_define

begin_comment
comment|/* 10 11*/
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_EPRC
value|0x00001000
end_define

begin_comment
comment|/* 12 */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_Reserved
value|0x0000E000
end_define

begin_comment
comment|/* 13 14 15*/
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_BLOCKSIZE_MASK
value|0x00070000
end_define

begin_comment
comment|/* 16 17 18 */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_BLOCKSIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_BLOCKSIZE_512
value|0x00000000
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_BLOCKSIZE_520
value|0x00010000
end_define

begin_comment
comment|/* 16 */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_BLOCKSIZE_4096
value|0x00020000
end_define

begin_comment
comment|/* 17 */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_BLOCKSIZE_4160
value|0x00030000
end_define

begin_comment
comment|/* 16 17 */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_UDTVMASK
value|0x03F00000
end_define

begin_comment
comment|/* 20 21 22 23 24 25 */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_UDTV_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_UDTUPMASK
value|0xF6000000
end_define

begin_comment
comment|/* 26 27 28 29 30 31  */
end_comment

begin_define
define|#
directive|define
name|DIF_FLAG_BITS_UDTUPSHIFT
value|26
end_define

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptDek_s
block|{
name|bit32
name|dekTable
decl_stmt|;
name|bit32
name|dekIndex
decl_stmt|;
block|}
name|agsaEncryptDek_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaEncrypt_s
block|{
name|agsaEncryptDek_t
name|dekInfo
decl_stmt|;
name|bit32
name|kekIndex
decl_stmt|;
name|agBOOLEAN
name|keyTagCheck
decl_stmt|;
name|agBOOLEAN
name|enableEncryptionPerLA
decl_stmt|;
comment|/* new */
name|bit32
name|sectorSizeIndex
decl_stmt|;
name|bit32
name|cipherMode
decl_stmt|;
name|bit32
name|keyTag_W0
decl_stmt|;
name|bit32
name|keyTag_W1
decl_stmt|;
name|bit32
name|tweakVal_W0
decl_stmt|;
name|bit32
name|tweakVal_W1
decl_stmt|;
name|bit32
name|tweakVal_W2
decl_stmt|;
name|bit32
name|tweakVal_W3
decl_stmt|;
name|bit32
name|EncryptionPerLAAddrLo
decl_stmt|;
comment|/* new */
name|bit32
name|EncryptionPerLAAddrHi
decl_stmt|;
comment|/* new */
name|bit16
name|EncryptionPerLRegion0SecCount
decl_stmt|;
comment|/* new */
name|bit16
name|reserved
decl_stmt|;
block|}
name|agsaEncrypt_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure describes a SAS SSP command request to be sent to the target device  *  * data structure describes a SAS SSP command request to be sent to the  * target device. This structure limits the CDB length in SSP  * command up to 16 bytes long.  *  * This data structure is one instance of the generic request issued to  * saSSPStart() and is passed as an agsaSASRequestBody_t .  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPInitiatorRequest_s
block|{
name|agsaSgl_t
name|agSgl
decl_stmt|;
comment|/**< This structure is used to define either                                                  an ESGL list or a single SGL for the SSP                                                  command operation */
name|bit32
name|dataLength
decl_stmt|;
comment|/**< Total data length in bytes */
name|bit16
name|firstBurstSize
decl_stmt|;
comment|/**< First Burst Size field as defined by                                                  SAS specification */
name|bit16
name|flag
decl_stmt|;
comment|/**< bit1-0 TLR as SAS specification                                                  bit31-2 reserved */
name|agsaSSPCmdInfoUnit_t
name|sspCmdIU
decl_stmt|;
comment|/**< Structure containing SSP Command                                                  INFORMATION UNIT */
name|agsaDif_t
name|dif
decl_stmt|;
name|agsaEncrypt_t
name|encrypt
decl_stmt|;
ifdef|#
directive|ifdef
name|SA_TESTBASE_EXTRA
comment|/* Added by TestBase */
name|bit16
name|bstIndex
decl_stmt|;
endif|#
directive|endif
comment|/*  SA_TESTBASE_EXTRA */
block|}
name|agsaSSPInitiatorRequest_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure describes a SAS SSP command request Ext to be sent to the target device  *  * data structure describes a SAS SSP command request to be sent to the  * target device. This structure support the CDB length in SSP  * command more than 16 bytes long.  *  * This data structure is one instance of the generic request issued to  * saSSPStart() and is passed as an agsaSASRequestBody_t .  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPInitiatorRequestExt_s
block|{
name|agsaSgl_t
name|agSgl
decl_stmt|;
comment|/**< This structure is used to define either                                                  an ESGL list or a single SGL for the SSP                                                  command operation */
name|bit32
name|dataLength
decl_stmt|;
name|bit16
name|firstBurstSize
decl_stmt|;
name|bit16
name|flag
decl_stmt|;
name|agsaSSPCmdInfoUnitExt_t
name|sspCmdIUExt
decl_stmt|;
name|agsaDif_t
name|dif
decl_stmt|;
name|agsaEncrypt_t
name|encrypt
decl_stmt|;
block|}
name|agsaSSPInitiatorRequestExt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPInitiatorRequestIndirect_s
block|{
name|agsaSgl_t
name|agSgl
decl_stmt|;
comment|/**< This structure is used to define either                                                  an ESGL list or a single SGL for the SSP                                                  command operation */
name|bit32
name|dataLength
decl_stmt|;
name|bit16
name|firstBurstSize
decl_stmt|;
name|bit16
name|flag
decl_stmt|;
name|bit32
name|sspInitiatorReqAddrUpper32
decl_stmt|;
comment|/**< The upper 32 bits of the 64-bit physical  DMA address of the SSP initiator request buffer */
name|bit32
name|sspInitiatorReqAddrLower32
decl_stmt|;
comment|/**< The lower 32 bits of the 64-bit physical  DMA address of the SSP initiator request buffer */
name|bit32
name|sspInitiatorReqLen
decl_stmt|;
comment|/**< Specifies the length of the SSP initiator request in bytes */
name|agsaDif_t
name|dif
decl_stmt|;
name|agsaEncrypt_t
name|encrypt
decl_stmt|;
block|}
name|agsaSSPInitiatorRequestIndirect_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure describes a SAS SSP target read and write request  *  * The agsaSSPTargetRequest_t data structure describes a SAS SSP target read  * and write request to be issued on the port. It includes the  * length of the data to be received or sent, an offset into the  * data block where the transfer is to start, and a list of  * scatter-gather buffers.  *  * This data structure is one instance of the generic request issued  * to saSSPStart() and is passed as an agsaSASRequestBody_t .  *  */
end_comment

begin_comment
comment|/** bit definitions for sspOption     Bit 0-1: Transport Layer Retry setting for other phase:     00b: No retry     01b: Retry on ACK/NAK timeout     10b: Retry on NAK received     11b: Retry on both ACK/NAK timeout and NAK received     Bit 2-3: Transport Layer Retry setting for data phase:     00b: No retry     01b: Retry on ACK/NAK timeout     10b: Retry on NAK received     11b: Retry on both ACK/NAK timeout and NAK received     Bit 4:  Retry Data Frame. Valid only on write command. Indicates whether Target supports RTL for this particular IO.     1b: enabled     0b: disabled     Bit 5: Auto good response on successful read (data transfer from target to initiator) request.     1b: Enabled     0b: Disabled     Bits 6-15 : Reserved.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPTargetRequest_s
block|{
name|agsaSgl_t
name|agSgl
decl_stmt|;
comment|/**< This structure is used to define either an ESGL list or                                  a single SGL for the target read or write operation */
name|bit32
name|dataLength
decl_stmt|;
comment|/**< Specifies the amount of data to be sent in this data phase */
name|bit32
name|offset
decl_stmt|;
comment|/**< Specifies the offset into the overall data block                                  where this data phase is to begin */
name|bit16
name|agTag
decl_stmt|;
comment|/**< Tag from ossaSSPReqReceived(). */
name|bit16
name|sspOption
decl_stmt|;
comment|/**< SSP option for retry */
name|agsaDif_t
name|dif
decl_stmt|;
block|}
name|agsaSSPTargetRequest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SSP_OPTION_BITS
value|0x3F
end_define

begin_comment
comment|/**< bit5-AGR, bit4-RDF bit3,2-RTE, bit1,0-AN */
end_comment

begin_define
define|#
directive|define
name|SSP_OPTION_ODS
value|0x8000
end_define

begin_comment
comment|/**< bit15-ODS */
end_comment

begin_define
define|#
directive|define
name|SSP_OPTION_OTHR_NO_RETRY
value|0
end_define

begin_define
define|#
directive|define
name|SSP_OPTION_OTHR_RETRY_ON_ACK_NAK_TIMEOUT
value|1
end_define

begin_define
define|#
directive|define
name|SSP_OPTION_OTHR_RETRY_ON_NAK_RECEIVED
value|2
end_define

begin_define
define|#
directive|define
name|SSP_OPTION_OTHR_RETRY_ON_BOTH_ACK_NAK_TIMEOUT_AND_NAK_RECEIVED
value|3
end_define

begin_define
define|#
directive|define
name|SSP_OPTION_DATA_NO_RETRY
value|0
end_define

begin_define
define|#
directive|define
name|SSP_OPTION_DATA_RETRY_ON_ACK_NAK_TIMEOUT
value|1
end_define

begin_define
define|#
directive|define
name|SSP_OPTION_DATA_RETRY_ON_NAK_RECEIVED
value|2
end_define

begin_define
define|#
directive|define
name|SSP_OPTION_DATA_RETRY_ON_BOTH_ACK_NAK_TIMEOUT_AND_NAK_RECEIVED
value|3
end_define

begin_define
define|#
directive|define
name|SSP_OPTION_RETRY_DATA_FRAME_ENABLED
value|(1<< SHIFT4)
end_define

begin_define
define|#
directive|define
name|SSP_OPTION_AUTO_GOOD_RESPONSE
value|(1<< SHIFT5)
end_define

begin_define
define|#
directive|define
name|SSP_OPTION_ENCRYPT
value|(1<< SHIFT6)
end_define

begin_define
define|#
directive|define
name|SSP_OPTION_DIF
value|(1<< SHIFT7)
end_define

begin_define
define|#
directive|define
name|SSP_OPTION_OVERRIDE_DEVICE_STATE
value|(1<< SHIFT15)
end_define

begin_comment
comment|/** \brief data structure describes a SAS SSP target response to be issued  *  on the port  *  * This data structure is one instance of the generic request issued to  * saSSPStart() and is passed as an agsaSASRequestBody_t  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPTargetResponse_s
block|{
name|bit32
name|agTag
decl_stmt|;
comment|/**< Tag from ossaSSPReqReceived(). */
name|void
modifier|*
name|frameBuf
decl_stmt|;
name|bit32
name|respBufLength
decl_stmt|;
comment|/**< Specifies the length of the Response buffer */
name|bit32
name|respBufUpper
decl_stmt|;
comment|/**< Upper 32 bit of physical address of OS Layer                                      allocated the Response buffer                                      (agsaSSPResponseInfoUnit_t).                                      Valid only when respBufLength is not zero  */
name|bit32
name|respBufLower
decl_stmt|;
comment|/**< Lower 32 bit of physical address of OS Layer                                      allocated the Response buffer                                      (agsaSSPResponseInfoUnit_t).                                      Valid only when respBufLength is not zero  */
name|bit32
name|respOption
decl_stmt|;
comment|/**< Bit 0-1: ACK and NAK retry option:                                      00b: No retry                                      01b: Retry on ACK/NAK timeout                                      10b: Retry on NAK received                                      11b: Retry on both ACK/NAK timeout and NAK received */
block|}
name|agsaSSPTargetResponse_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RESP_OPTION_BITS
value|0x3
end_define

begin_comment
comment|/** bit0-1 */
end_comment

begin_define
define|#
directive|define
name|RESP_OPTION_ODS
value|0x8000
end_define

begin_comment
comment|/** bit15 */
end_comment

begin_comment
comment|/** \brief data structure describes a SMP request or response frame to be sent on the SAS port  *  * The agsaSMPFrame_t data structure describes a SMP request or response  * frame to be issued or sent on the SAS port.  *  * This data structure is one instance of the generic request issued to  * saSMPStart() and is passed as an agsaSASRequestBody_t .  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSMPFrame_s
block|{
name|void
modifier|*
name|outFrameBuf
decl_stmt|;
comment|/**< if payload is less than 32 bytes,A virtual                                                frameBuf can be used. instead of physical                                                address. Set to NULL and use physical                                                address if payload is> 32 bytes */
name|bit32
name|outFrameAddrUpper32
decl_stmt|;
comment|/**< The upper 32 bits of the 64-bit physical                                                DMA address of the SMP frame buffer */
name|bit32
name|outFrameAddrLower32
decl_stmt|;
comment|/**< The lower 32 bits of the 64-bit physical                                                DMA address of the SMP frame buffer */
name|bit32
name|outFrameLen
decl_stmt|;
comment|/**< Specifies the length of the SMP request                                                frame excluding the CRC field in bytes */
name|bit32
name|inFrameAddrUpper32
decl_stmt|;
comment|/**< The upper 32 bits of the 64-bit phsical address                                                of DMA address of response SMP Frame buffer */
name|bit32
name|inFrameAddrLower32
decl_stmt|;
comment|/**< The lower 32 bits of the 64-bit phsical address                                                of DMA address of response SMP Frame buffer */
name|bit32
name|inFrameLen
decl_stmt|;
comment|/**< Specifies the length of the SMP response                                                frame excluding the CRC field in bytes */
name|bit32
name|expectedRespLen
decl_stmt|;
comment|/**< Specifies the length of SMP Response */
name|bit32
name|flag
decl_stmt|;
comment|/** For the SPCv controller:                                                  Bit 0: Indirect Response (IR). This indicates                                                         direct or indirect mode for SMP response frame                                                         to be received.                                                     0b: Direct mode                                                     1b: Indirect mode                                                   Bit 1: Indirect Payload (IP). This indicates                                                         direct or indirect mode for SMP request frame                                                         to be sent.                                                     0b: Direct mode                                                     1b: Indirect mode                                                   Bits 2-31: Reserved                                                 For the SPC controller: This is not applicable.                                                 */
block|}
name|agsaSMPFrame_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|smpFrameFlagDirectResponse
value|0
end_define

begin_define
define|#
directive|define
name|smpFrameFlagIndirectResponse
value|1
end_define

begin_define
define|#
directive|define
name|smpFrameFlagDirectPayload
value|0
end_define

begin_define
define|#
directive|define
name|smpFrameFlagIndirectPayload
value|2
end_define

begin_comment
comment|/** \brief union data structure specifies a request  *  * union data structure specifies a request  */
end_comment

begin_typedef
typedef|typedef
union|union
name|agsaSASRequestBody_u
block|{
name|agsaSSPInitiatorRequest_t
name|sspInitiatorReq
decl_stmt|;
comment|/**< Structure containing the SSP initiator request, Support up to 16 bytes CDB */
name|agsaSSPInitiatorRequestExt_t
name|sspInitiatorReqExt
decl_stmt|;
comment|/**< Structure containing the SSP initiator request for CDB> 16 bytes */
name|agsaSSPInitiatorRequestIndirect_t
name|sspInitiatorReqIndirect
decl_stmt|;
comment|/**< Structure containing the SSP indirect initiator request */
name|agsaSSPTargetRequest_t
name|sspTargetReq
decl_stmt|;
comment|/**< Structure containing the SSP Target request */
name|agsaSSPScsiTaskMgntReq_t
name|sspTaskMgntReq
decl_stmt|;
comment|/**< Structure containing the SSP SCSI Task Management request */
name|agsaSSPTargetResponse_t
name|sspTargetResponse
decl_stmt|;
comment|/**< Structure containing the SSP Target response. */
name|agsaSMPFrame_t
name|smpFrame
decl_stmt|;
comment|/**< Structure containing SMP request or response frame */
block|}
name|agsaSASRequestBody_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure describes an STP or direct connect SATA command  *  * The agsaSATAInitiatorRequest_t data structure describes an STP or direct  * connect SATA command request to be sent to the device and  * passed as a parameter to saSATAStart() function.  *  * This structure is an encapsulation of SATA FIS (Frame Information  * Structures), which enables the execution of ATA command  * descriptor using SATA transport  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSATAInitiatorRequest_s
block|{
name|agsaSgl_t
name|agSgl
decl_stmt|;
comment|/**< This structure is used to define either an ESGL                                      list or a single SGL for operation that involves                                      DMA transfer */
name|bit32
name|dataLength
decl_stmt|;
comment|/**< Total data length in bytes */
name|bit32
name|option
decl_stmt|;
comment|/**< Operational option, defined using the bit field.                                      b7-1: reserved                                      b0:   AGSA-STP-CLOSE-CLEAR-AFFILIATION */
name|agsaSATAHostFis_t
name|fis
decl_stmt|;
comment|/**< The FIS request */
name|agsaDif_t
name|dif
decl_stmt|;
name|agsaEncrypt_t
name|encrypt
decl_stmt|;
name|bit8
name|scsiCDB
index|[
literal|16
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|SA_TESTBASE_EXTRA
comment|/* Added by TestBase */
name|bit16
name|bstIndex
decl_stmt|;
endif|#
directive|endif
comment|/*  SA_TESTBASE_EXTRA */
block|}
name|agsaSATAInitiatorRequest_t
typedef|;
end_typedef

begin_comment
comment|/* controller Configuration page */
end_comment

begin_define
define|#
directive|define
name|AGSA_SAS_PROTOCOL_TIMER_CONFIG_PAGE
value|0x04
end_define

begin_define
define|#
directive|define
name|AGSA_INTERRUPT_CONFIGURATION_PAGE
value|0x05
end_define

begin_define
define|#
directive|define
name|AGSA_IO_GENERAL_CONFIG_PAGE
value|0x06
end_define

begin_define
define|#
directive|define
name|AGSA_ENCRYPTION_GENERAL_CONFIG_PAGE
value|0x20
end_define

begin_define
define|#
directive|define
name|AGSA_ENCRYPTION_DEK_CONFIG_PAGE
value|0x21
end_define

begin_define
define|#
directive|define
name|AGSA_ENCRYPTION_CONTROL_PARM_PAGE
value|0x22
end_define

begin_define
define|#
directive|define
name|AGSA_ENCRYPTION_HMAC_CONFIG_PAGE
value|0x23
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HIALEAH_ENCRYPTION
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptGeneralPage_s
block|{
name|bit32
name|numberOfKeksPageCode
decl_stmt|;
comment|/* 0x20 */
name|bit32
name|KeyCardIdKekIndex
decl_stmt|;
name|bit32
name|KeyCardId3_0
decl_stmt|;
name|bit32
name|KeyCardId7_4
decl_stmt|;
name|bit32
name|KeyCardId11_8
decl_stmt|;
block|}
name|agsaEncryptGeneralPage_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptGeneralPage_s
block|{
name|bit32
name|pageCode
decl_stmt|;
comment|/* 0x20 */
name|bit32
name|numberOfDeks
decl_stmt|;
block|}
name|agsaEncryptGeneralPage_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HIALEAH_ENCRYPTION */
end_comment

begin_define
define|#
directive|define
name|AGSA_ENC_CONFIG_PAGE_KEK_NUMBER
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|AGSA_ENC_CONFIG_PAGE_KEK_SHIFT
value|8
end_define

begin_comment
comment|/* sTSDK 4.14   */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptDekConfigPage_s
block|{
name|bit32
name|pageCode
decl_stmt|;
name|bit32
name|table0AddrLo
decl_stmt|;
name|bit32
name|table0AddrHi
decl_stmt|;
name|bit32
name|table0Entries
decl_stmt|;
name|bit32
name|table0BFES
decl_stmt|;
name|bit32
name|table1AddrLo
decl_stmt|;
name|bit32
name|table1AddrHi
decl_stmt|;
name|bit32
name|table1Entries
decl_stmt|;
name|bit32
name|table1BFES
decl_stmt|;
block|}
name|agsaEncryptDekConfigPage_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AGSA_ENC_DEK_CONFIG_PAGE_DEK_TABLE_NUMBER
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|AGSA_ENC_DEK_CONFIG_PAGE_DEK_TABLE_SHIFT
value|SHIFT28
end_define

begin_define
define|#
directive|define
name|AGSA_ENC_DEK_CONFIG_PAGE_DEK_CACHE_WAY
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|AGSA_ENC_DEK_CONFIG_PAGE_DEK_CACHE_SHIFT
value|SHIFT24
end_define

begin_comment
comment|/*sTSDK 4.18   */
end_comment

begin_comment
comment|/* CCS (Current Crypto Services)  and NOPR (Number of Operators) are valid only in GET_CONTROLLER_CONFIG */
end_comment

begin_comment
comment|/* NAR, CORCAP and USRCAP are valid only when AUT==1 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptControlParamPage_s
block|{
name|bit32
name|pageCode
decl_stmt|;
comment|/* 0x22 */
name|bit32
name|CORCAP
decl_stmt|;
comment|/* Crypto Officer Role Capabilities */
name|bit32
name|USRCAP
decl_stmt|;
comment|/* User Role Capabilities */
name|bit32
name|CCS
decl_stmt|;
comment|/* Current Crypto Services */
name|bit32
name|NOPR
decl_stmt|;
comment|/* Number of Operators */
block|}
name|agsaEncryptControlParamPage_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptInfo_s
block|{
name|bit32
name|encryptionCipherMode
decl_stmt|;
name|bit32
name|encryptionSecurityMode
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|flag
decl_stmt|;
block|}
name|agsaEncryptInfo_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OperatorAuthenticationEnable_AUT
value|1
end_define

begin_define
define|#
directive|define
name|ReturnToFactoryMode_ARF
value|2
end_define

begin_comment
comment|/*sTSDK 4.19   */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptSelfTestBitMap_s
block|{
name|bit32
name|AES_Test
decl_stmt|;
name|bit32
name|KEY_WRAP_Test
decl_stmt|;
name|bit32
name|HMAC_Test
decl_stmt|;
block|}
name|agsaEncryptSelfTestBitMap_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptSelfTestStatusBitMap_s
block|{
name|bit32
name|AES_Status
decl_stmt|;
name|bit32
name|KEY_WRAP_Status
decl_stmt|;
name|bit32
name|HMAC_Status
decl_stmt|;
block|}
name|agsaEncryptSelfTestStatusBitMap_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptHMACTestDescriptor_s
block|{
name|bit32
name|Dword0
decl_stmt|;
name|bit32
name|MsgAddrLo
decl_stmt|;
name|bit32
name|MsgAddrHi
decl_stmt|;
name|bit32
name|MsgLen
decl_stmt|;
name|bit32
name|DigestAddrLo
decl_stmt|;
name|bit32
name|DigestAddrHi
decl_stmt|;
name|bit32
name|KeyAddrLo
decl_stmt|;
name|bit32
name|KeyAddrHi
decl_stmt|;
name|bit32
name|KeyLen
decl_stmt|;
block|}
name|agsaEncryptHMACTestDescriptor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptHMACTestResult_s
block|{
name|bit32
name|Dword0
decl_stmt|;
name|bit32
name|Dword
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaEncryptHMACTestResult_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptSHATestDescriptor_s
block|{
name|bit32
name|Dword0
decl_stmt|;
name|bit32
name|MsgAddrLo
decl_stmt|;
name|bit32
name|MsgAddrHi
decl_stmt|;
name|bit32
name|MsgLen
decl_stmt|;
name|bit32
name|DigestAddrLo
decl_stmt|;
name|bit32
name|DigestAddrHi
decl_stmt|;
block|}
name|agsaEncryptSHATestDescriptor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptSHATestResult_s
block|{
name|bit32
name|Dword0
decl_stmt|;
name|bit32
name|Dword
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaEncryptSHATestResult_t
typedef|;
end_typedef

begin_comment
comment|/* types of self test */
end_comment

begin_define
define|#
directive|define
name|AGSA_BIST_TEST
value|0x1
end_define

begin_define
define|#
directive|define
name|AGSA_HMAC_TEST
value|0x2
end_define

begin_define
define|#
directive|define
name|AGSA_SHA_TEST
value|0x3
end_define

begin_comment
comment|/*sTSDK  4.13  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptDekBlob_s
block|{
name|bit8
name|dekBlob
index|[
literal|80
index|]
decl_stmt|;
block|}
name|agsaEncryptDekBlob_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptKekBlob_s
block|{
name|bit8
name|kekBlob
index|[
literal|48
index|]
decl_stmt|;
block|}
name|agsaEncryptKekBlob_t
typedef|;
end_typedef

begin_comment
comment|/*sTSDK  4.45  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptHMACConfigPage_s
block|{
name|bit32
name|PageCode
decl_stmt|;
name|bit32
name|CustomerTag
decl_stmt|;
name|bit32
name|KeyAddrLo
decl_stmt|;
name|bit32
name|KeyAddrHi
decl_stmt|;
block|}
name|agsaEncryptHMACConfigPage_t
typedef|;
end_typedef

begin_comment
comment|/*sTSDK  4.38  */
end_comment

begin_define
define|#
directive|define
name|AGSA_ID_SIZE
value|31
end_define

begin_typedef
typedef|typedef
struct|struct
name|agsaID_s
block|{
name|bit8
name|ID
index|[
name|AGSA_ID_SIZE
index|]
decl_stmt|;
block|}
name|agsaID_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SA_OPR_MGMNT_FLAG_MASK
value|0x00003000
end_define

begin_define
define|#
directive|define
name|SA_OPR_MGMNT_FLAG_SHIFT
value|12
end_define

begin_comment
comment|/* */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSASPhyMiscPage_s
block|{
name|bit32
name|Dword0
decl_stmt|;
name|bit32
name|Dword1
decl_stmt|;
block|}
name|agsaSASPhyMiscPage_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaHWEventEncrypt_s
block|{
name|bit32
name|encryptOperation
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|eq
decl_stmt|;
comment|/* error qualifier */
name|bit32
name|info
decl_stmt|;
name|void
modifier|*
name|handle
decl_stmt|;
name|void
modifier|*
name|param
decl_stmt|;
block|}
name|agsaHWEventEncrypt_t
typedef|;
end_typedef

begin_comment
comment|/*sTSDK  4.32  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaHWEventMode_s
block|{
name|bit32
name|modePageOperation
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|modePageLen
decl_stmt|;
name|void
modifier|*
name|modePage
decl_stmt|;
name|void
modifier|*
name|context
decl_stmt|;
block|}
name|agsaHWEventMode_t
typedef|;
end_typedef

begin_comment
comment|/*sTSDK  4.33  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaInterruptConfigPage_s
block|{
name|bit32
name|pageCode
decl_stmt|;
name|bit32
name|vectorMask0
decl_stmt|;
name|bit32
name|vectorMask1
decl_stmt|;
name|bit32
name|ICTC0
decl_stmt|;
name|bit32
name|ICTC1
decl_stmt|;
name|bit32
name|ICTC2
decl_stmt|;
name|bit32
name|ICTC3
decl_stmt|;
name|bit32
name|ICTC4
decl_stmt|;
name|bit32
name|ICTC5
decl_stmt|;
name|bit32
name|ICTC6
decl_stmt|;
name|bit32
name|ICTC7
decl_stmt|;
block|}
name|agsaInterruptConfigPage_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaIoGeneralPage_s
block|{
name|bit32
name|pageCode
decl_stmt|;
comment|/* 0x06 */
name|bit32
name|ActiveMask
decl_stmt|;
name|bit32
name|QrntTime
decl_stmt|;
block|}
name|agsaIoGeneralPage_t
typedef|;
end_typedef

begin_comment
comment|/* \brief data structure defines detail information about Agilent Error * Detection Code (DIF) errors. * * The  agsaDifDetails_t data structure defines detail information about * PMC Error Detection Code (DIF) error.  Please refer to the latest T10 SBC * and SPC draft/specification for the definition of the Protection * Information. * * This structure is filled by the function saGetDifErrorDetails(). */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaDifDetails_s
block|{
name|bit32
name|UpperLBA
decl_stmt|;
name|bit32
name|LowerLBA
decl_stmt|;
name|bit8
name|sasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|sasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit32
name|ExpectedCRCUDT01
decl_stmt|;
name|bit32
name|ExpectedUDT2345
decl_stmt|;
name|bit32
name|ActualCRCUDT01
decl_stmt|;
name|bit32
name|ActualUDT2345
decl_stmt|;
name|bit32
name|DIFErrDevID
decl_stmt|;
name|bit32
name|ErrBoffsetEDataLen
decl_stmt|;
name|void
modifier|*
name|frame
decl_stmt|;
block|}
name|agsaDifDetails_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for SAS protocol timer configuration page.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSASProtocolTimerConfigurationPage_s
block|{
name|bit32
name|pageCode
decl_stmt|;
comment|/* 0 */
name|bit32
name|MST_MSI
decl_stmt|;
comment|/* 1 */
name|bit32
name|STP_SSP_MCT_TMO
decl_stmt|;
comment|/* 2 */
name|bit32
name|STP_FRM_TMO
decl_stmt|;
comment|/* 3 */
name|bit32
name|STP_IDLE_TMO
decl_stmt|;
comment|/* 4 */
name|bit32
name|OPNRJT_RTRY_INTVL
decl_stmt|;
comment|/* 5 */
name|bit32
name|Data_Cmd_OPNRJT_RTRY_TMO
decl_stmt|;
comment|/* 6 */
name|bit32
name|Data_Cmd_OPNRJT_RTRY_THR
decl_stmt|;
comment|/* 7 */
name|bit32
name|MAX_AIP
decl_stmt|;
comment|/* 8 */
block|}
name|agsaSASProtocolTimerConfigurationPage_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for firmware flash update saFwFlashUpdate().  *  * The agsaUpdateFwFlash data structure specifies a request to saFwFlashUpdate()  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaUpdateFwFlash_s
block|{
name|bit32
name|currentImageOffset
decl_stmt|;
name|bit32
name|currentImageLen
decl_stmt|;
name|bit32
name|totalImageLen
decl_stmt|;
name|agsaSgl_t
name|agSgl
decl_stmt|;
block|}
name|agsaUpdateFwFlash_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for extended firmware flash update saFwFlashExtUpdate().  *  * The agsaFlashExtExecute_s data structure specifies a request to saFwFlashExtUpdate()  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaFlashExtExecute_s
block|{
name|bit32
name|command
decl_stmt|;
name|bit32
name|partOffset
decl_stmt|;
name|bit32
name|dataLen
decl_stmt|;
name|agsaSgl_t
modifier|*
name|agSgl
decl_stmt|;
block|}
name|agsaFlashExtExecute_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for firmware flash update saFwFlashUpdate().  *  * The agsaFlashExtResponse_t data structure specifies a request to ossaFlashExtExecuteCB().()  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaFlashExtResponse_s
block|{
name|bit32
name|epart_size
decl_stmt|;
name|bit32
name|epart_sect_size
decl_stmt|;
block|}
name|agsaFlashExtResponse_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for set fields in MPI table.  *  The agsaMPIContext_t data structure is used to set fields in MPI table.  *  For details of MPI table, refer to PM8001 Tachyon SPC 8x6G Programmers'  *  Manual PMC-2080222 or PM8008/PM8009/PM8018 Tachyon SPCv/SPCve/SPCv+ Programmers Manual  *  PMC-2091148/PMC-2102373.     sTSDK  section 4.39  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaMPIContext_s
block|{
name|bit32
name|MPITableType
decl_stmt|;
name|bit32
name|offset
decl_stmt|;
name|bit32
name|value
decl_stmt|;
block|}
name|agsaMPIContext_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AGSA_MPI_MAIN_CONFIGURATION_TABLE
value|1
end_define

begin_define
define|#
directive|define
name|AGSA_MPI_GENERAL_STATUS_TABLE
value|2
end_define

begin_define
define|#
directive|define
name|AGSA_MPI_INBOUND_QUEUE_CONFIGURATION_TABLE
value|3
end_define

begin_define
define|#
directive|define
name|AGSA_MPI_OUTBOUND_QUEUE_CONFIGURATION_TABLE
value|4
end_define

begin_define
define|#
directive|define
name|AGSA_MPI_SAS_PHY_ANALOG_SETUP_TABLE
value|5
end_define

begin_define
define|#
directive|define
name|AGSA_MPI_INTERRUPT_VECTOR_TABLE
value|6
end_define

begin_define
define|#
directive|define
name|AGSA_MPI_PER_SAS_PHY_ATTRIBUTE_TABLE
value|7
end_define

begin_define
define|#
directive|define
name|AGSA_MPI_OUTBOUND_QUEUE_FAILOVER_TABLE
value|8
end_define

begin_comment
comment|/************************************************************/
end_comment

begin_comment
comment|/*This flag and datastructure are specific for fw profiling, Now defined as compiler flag*/
end_comment

begin_comment
comment|//#define SPC_ENABLE_PROFILE
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SPC_ENABLE_PROFILE
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|agsaFwProfile_s
block|{
name|bit32
name|tcid
decl_stmt|;
name|bit32
name|processor
decl_stmt|;
name|bit32
name|cmd
decl_stmt|;
name|bit32
name|len
decl_stmt|;
name|bit32
name|codeStartAdd
decl_stmt|;
name|bit32
name|codeEndAdd
decl_stmt|;
name|agsaSgl_t
name|agSgl
decl_stmt|;
block|}
name|agsaFwProfile_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************************************************/
end_comment

begin_comment
comment|/** \brief Callback definition for .ossaDeviceRegistration  *  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ossaDeviceRegistrationCB_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|agsaDevHandle_t
modifier|*
name|agDevHandle
parameter_list|,
name|bit32
name|deviceID
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** \brief Callback definition for  *  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ossaDeregisterDeviceHandleCB_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|agsaDevHandle_t
modifier|*
name|agDevHandle
parameter_list|,
name|bit32
name|status
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** \brief Callback definition for  *  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ossaGenericCB_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** \brief Callback definition for abort SMP SSP SATA callback  *  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ossaGenericAbortCB_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|agIORequest
parameter_list|,
name|bit32
name|flag
parameter_list|,
name|bit32
name|status
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ossaLocalPhyControlCB_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|phyId
parameter_list|,
name|bit32
name|phyOperation
parameter_list|,
name|bit32
name|status
parameter_list|,
name|void
modifier|*
name|parm
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** \brief Callback definition for  *  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ossaSATACompletedCB_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|agIORequest
parameter_list|,
name|bit32
name|agIOStatus
parameter_list|,
name|void
modifier|*
name|agFirstDword
parameter_list|,
name|bit32
name|agIOInfoLen
parameter_list|,
name|void
modifier|*
name|agParam
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** \brief Callback definition for  *  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ossaSMPCompletedCB_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|agIORequest
parameter_list|,
name|bit32
name|agIOStatus
parameter_list|,
name|bit32
name|agIOInfoLen
parameter_list|,
name|agsaFrameHandle_t
name|agFrameHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** \brief Callback definition for  *  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ossaSSPCompletedCB_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|agIORequest
parameter_list|,
name|bit32
name|agIOStatus
parameter_list|,
name|bit32
name|agIOInfoLen
parameter_list|,
name|void
modifier|*
name|agParam
parameter_list|,
name|bit16
name|sspTag
parameter_list|,
name|bit32
name|agOtherInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** \brief Callback definition for  *  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ossaSetDeviceInfoCB_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|agsaDevHandle_t
modifier|*
name|agDevHandle
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|option
parameter_list|,
name|bit32
name|param
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaOffloadDifDetails_s
block|{
name|bit32
name|ExpectedCRCUDT01
decl_stmt|;
name|bit32
name|ExpectedUDT2345
decl_stmt|;
name|bit32
name|ActualCRCUDT01
decl_stmt|;
name|bit32
name|ActualUDT2345
decl_stmt|;
name|bit32
name|DIFErr
decl_stmt|;
name|bit32
name|ErrBoffset
decl_stmt|;
block|}
name|agsaOffloadDifDetails_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaDifEncPayload_s
block|{
name|agsaSgl_t
name|SrcSgl
decl_stmt|;
name|bit32
name|SrcDL
decl_stmt|;
name|agsaSgl_t
name|DstSgl
decl_stmt|;
name|bit32
name|DstDL
decl_stmt|;
name|agsaDif_t
name|dif
decl_stmt|;
name|agsaEncrypt_t
name|encrypt
decl_stmt|;
block|}
name|agsaDifEncPayload_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ossaVhistCaptureCB_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|bit32
name|len
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ossaDIFEncryptionOffloadStartCB_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaContext_t
modifier|*
name|agContext
parameter_list|,
name|bit32
name|status
parameter_list|,
name|agsaOffloadDifDetails_t
modifier|*
name|agsaOffloadDifDetails
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|SA_RESERVED_REQUEST_COUNT
value|16
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SA_FW_TIMER_READS_STATUS
end_ifdef

begin_define
define|#
directive|define
name|SA_FW_TIMER_READS_STATUS_INTERVAL
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SA_FW_TIMER_READS_STATUS */
end_comment

begin_define
define|#
directive|define
name|SIZE_DW
value|4
end_define

begin_comment
comment|/**< Size in bytes */
end_comment

begin_define
define|#
directive|define
name|SIZE_QW
value|8
end_define

begin_comment
comment|/**< Size in bytes */
end_comment

begin_define
define|#
directive|define
name|PCIBAR0
value|0
end_define

begin_comment
comment|/**< PCI Base Address 0 */
end_comment

begin_define
define|#
directive|define
name|PCIBAR1
value|1
end_define

begin_comment
comment|/**< PCI Base Address 1 */
end_comment

begin_define
define|#
directive|define
name|PCIBAR2
value|2
end_define

begin_comment
comment|/**< PCI Base Address 2 */
end_comment

begin_define
define|#
directive|define
name|PCIBAR3
value|3
end_define

begin_comment
comment|/**< PCI Base Address 3 */
end_comment

begin_define
define|#
directive|define
name|PCIBAR4
value|4
end_define

begin_comment
comment|/**< PCI Base Address 4 */
end_comment

begin_define
define|#
directive|define
name|PCIBAR5
value|5
end_define

begin_comment
comment|/**< PCI Base Address 5 */
end_comment

begin_comment
comment|/** \brief describe an element of SPC-SPCV converter  *  * This structure is used  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaBarOffset_s
block|{
name|bit32
name|Generic
decl_stmt|;
comment|/* */
name|bit32
name|Bar
decl_stmt|;
comment|/* */
name|bit32
name|Offset
decl_stmt|;
comment|/* */
name|bit32
name|Length
decl_stmt|;
comment|/* */
block|}
name|agsaBarOffset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|agsabit32bit64_U
block|{
name|bit32
name|S32
index|[
literal|2
index|]
decl_stmt|;
name|bit64
name|B64
decl_stmt|;
block|}
name|agsabit32bit64
typedef|;
end_typedef

begin_comment
comment|/* The agsaIOErrorEventStats_t data structure is used as parameter in ossaGetIOErrorStatsCB(),ossaGetIOEventStatsCB(). This data structure contains the number of IO error and event. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaIOErrorEventStats_s
block|{
name|bit32
name|agOSSA_IO_COMPLETED_ERROR_SCSI_STATUS
decl_stmt|;
name|bit32
name|agOSSA_IO_ABORTED
decl_stmt|;
name|bit32
name|agOSSA_IO_OVERFLOW
decl_stmt|;
name|bit32
name|agOSSA_IO_UNDERFLOW
decl_stmt|;
name|bit32
name|agOSSA_IO_FAILED
decl_stmt|;
name|bit32
name|agOSSA_IO_ABORT_RESET
decl_stmt|;
name|bit32
name|agOSSA_IO_NOT_VALID
decl_stmt|;
name|bit32
name|agOSSA_IO_NO_DEVICE
decl_stmt|;
name|bit32
name|agOSSA_IO_ILLEGAL_PARAMETER
decl_stmt|;
name|bit32
name|agOSSA_IO_LINK_FAILURE
decl_stmt|;
name|bit32
name|agOSSA_IO_PROG_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_DIF_IN_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_DIF_OUT_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_ERROR_HW_TIMEOUT
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_BREAK
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_PHY_NOT_READY
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_PROTOCOL_NOT_SUPPORTED
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_ZONE_VIOLATION
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_BREAK
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_BAD_DESTINATION
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_CONNECTION_RATE_NOT_SUPPORTED
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_STP_RESOURCES_BUSY
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_WRONG_DESTINATION
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_UNKNOWN_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_NAK_RECEIVED
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_ACK_NAK_TIMEOUT
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_PEER_ABORTED
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_RX_FRAME
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_DMA
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_CREDIT_TIMEOUT
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_SATA_LINK_TIMEOUT
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_SATA
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_ABORTED_DUE_TO_SRST
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_REJECTED_NCQ_MODE
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_ABORTED_NCQ_MODE
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_OPEN_RETRY_TIMEOUT
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_SMP_RESP_CONNECTION_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_UNEXPECTED_PHASE
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_XFER_RDY_OVERRUN
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_XFER_RDY_NOT_EXPECTED
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_CMD_ISSUE_ACK_NAK_TIMEOUT
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_CMD_ISSUE_BREAK_BEFORE_ACK_NAK
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_CMD_ISSUE_PHY_DOWN_BEFORE_ACK_NAK
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_OFFSET_MISMATCH
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_XFER_ZERO_DATA_LEN
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_CMD_FRAME_ISSUED
decl_stmt|;
name|bit32
name|agOSSA_IO_ERROR_INTERNAL_SMP_RESOURCE
decl_stmt|;
name|bit32
name|agOSSA_IO_PORT_IN_RESET
decl_stmt|;
name|bit32
name|agOSSA_IO_DS_NON_OPERATIONAL
decl_stmt|;
name|bit32
name|agOSSA_IO_DS_IN_RECOVERY
decl_stmt|;
name|bit32
name|agOSSA_IO_TM_TAG_NOT_FOUND
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_PIO_SETUP_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_SSP_EXT_IU_ZERO_LEN_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_DS_IN_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_HW_RESOURCE_BUSY
decl_stmt|;
name|bit32
name|agOSSA_IO_ABORT_IN_PROGRESS
decl_stmt|;
name|bit32
name|agOSSA_IO_ABORT_DELAYED
decl_stmt|;
name|bit32
name|agOSSA_IO_INVALID_LENGTH
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_HW_RESOURCE_BUSY_ALT
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS_OPEN_RETRY_BACKOFF_THRESHOLD_REACHED
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS_OPEN_TMO
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS_NO_DEST
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS_OPEN_COLLIDE
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS_PATHWAY_BLOCKED
decl_stmt|;
name|bit32
name|agOSSA_IO_DS_INVALID
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_READ_COMPL_ERR
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERR_LAST_PIO_DATAIN_CRC_ERR
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_INTERNAL_CRC_ERROR
decl_stmt|;
name|bit32
name|agOSSA_MPI_IO_RQE_BUSY_FULL
decl_stmt|;
name|bit32
name|agOSSA_MPI_ERR_IO_RESOURCE_UNAVAILABLE
decl_stmt|;
name|bit32
name|agOSSA_MPI_ERR_ATAPI_DEVICE_BUSY
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DEK_KEY_CACHE_MISS
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DEK_KEY_TAG_MISMATCH
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_CIPHER_MODE_INVALID
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DEK_IV_MISMATCH
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DEK_RAM_INTERFACE_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_INTERNAL_RAM
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DIF_MISMATCH
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DIF_APPLICATION_TAG_MISMATCH
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DIF_REFERENCE_TAG_MISMATCH
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DIF_CRC_MISMATCH
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_INVALID_SSP_RSP_FRAME
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERR_EOB_DATA_OVERRUN
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DEK_INDEX_OUT_OF_BOUNDS
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_OPEN_PREEMPTED
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DEK_ILLEGAL_TABLE
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_DIF_INTERNAL_ERROR
decl_stmt|;
name|bit32
name|agOSSA_MPI_ERR_OFFLOAD_DIF_OR_ENC_NOT_ENABLED
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_DMA_ACTIVATE_TIMEOUT
decl_stmt|;
name|bit32
name|agOSSA_IO_UNKNOWN_ERROR
decl_stmt|;
block|}
name|agsaIOErrorEventStats_t
typedef|;
end_typedef

begin_comment
comment|/************************************************************************************  *                                                                                  *  *               Data Structures Defined for LL API ends                            *  *                                                                                  *  ************************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SALL_API_TEST
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|agsaIOCountInfo_s
block|{
name|bit32
name|numSSPStarted
decl_stmt|;
comment|// saSSPStart()
name|bit32
name|numSSPAborted
decl_stmt|;
comment|// saSSPAbort()
name|bit32
name|numSSPAbortedCB
decl_stmt|;
comment|// ossaSSPAbortCB()
name|bit32
name|numSSPCompleted
decl_stmt|;
comment|// includes success and aborted IOs
name|bit32
name|numSMPStarted
decl_stmt|;
comment|// saSMPStart()
name|bit32
name|numSMPAborted
decl_stmt|;
comment|// saSMPAbort()
name|bit32
name|numSMPAbortedCB
decl_stmt|;
comment|// ossaSMPAbortCB()
name|bit32
name|numSMPCompleted
decl_stmt|;
comment|// includes success and aborted IOs
name|bit32
name|numSataStarted
decl_stmt|;
comment|// saSATAStart()
name|bit32
name|numSataAborted
decl_stmt|;
comment|// saSATAAbort()
name|bit32
name|numSataAbortedCB
decl_stmt|;
comment|// ossaSATAAbortCB()
name|bit32
name|numSataCompleted
decl_stmt|;
comment|// includes success and aborted IOs
name|bit32
name|numEchoSent
decl_stmt|;
comment|// saEchoCommand()
name|bit32
name|numEchoCB
decl_stmt|;
comment|// ossaEchoCB()
name|bit32
name|numUNKNWRespIOMB
decl_stmt|;
comment|// unknow Response IOMB received
name|bit32
name|numOurIntCount
decl_stmt|;
comment|//InterruptHandler() counter
name|bit32
name|numSpuriousInt
decl_stmt|;
comment|//spurious interrupts
comment|//  bit32 numSpInts[64];    //spuriours interrupts count for each OBQ (PI=CI)
comment|//  bit32 numSpInts1[64];   //spuriours interrupts count for each OBQ (PI!=CI)
block|}
name|agsaIOCountInfo_t
typedef|;
end_typedef

begin_comment
comment|/* Total IO Counter */
end_comment

begin_define
define|#
directive|define
name|LL_COUNTERS
value|17
end_define

begin_comment
comment|/* Counter Bit Map */
end_comment

begin_define
define|#
directive|define
name|COUNTER_SSP_START
value|0x000001
end_define

begin_define
define|#
directive|define
name|COUNTER_SSP_ABORT
value|0x000002
end_define

begin_define
define|#
directive|define
name|COUNTER_SSPABORT_CB
value|0x000004
end_define

begin_define
define|#
directive|define
name|COUNTER_SSP_COMPLETEED
value|0x000008
end_define

begin_define
define|#
directive|define
name|COUNTER_SMP_START
value|0x000010
end_define

begin_define
define|#
directive|define
name|COUNTER_SMP_ABORT
value|0x000020
end_define

begin_define
define|#
directive|define
name|COUNTER_SMPABORT_CB
value|0x000040
end_define

begin_define
define|#
directive|define
name|COUNTER_SMP_COMPLETEED
value|0x000080
end_define

begin_define
define|#
directive|define
name|COUNTER_SATA_START
value|0x000100
end_define

begin_define
define|#
directive|define
name|COUNTER_SATA_ABORT
value|0x000200
end_define

begin_define
define|#
directive|define
name|COUNTER_SATAABORT_CB
value|0x000400
end_define

begin_define
define|#
directive|define
name|COUNTER_SATA_COMPLETEED
value|0x000800
end_define

begin_define
define|#
directive|define
name|COUNTER_ECHO_SENT
value|0x001000
end_define

begin_define
define|#
directive|define
name|COUNTER_ECHO_CB
value|0x002000
end_define

begin_define
define|#
directive|define
name|COUNTER_UNKWN_IOMB
value|0x004000
end_define

begin_define
define|#
directive|define
name|COUNTER_OUR_INT
value|0x008000
end_define

begin_define
define|#
directive|define
name|COUNTER_SPUR_INT
value|0x010000
end_define

begin_define
define|#
directive|define
name|ALL_COUNTERS
value|0xFFFFFF
end_define

begin_typedef
typedef|typedef
union|union
name|agsaLLCountInfo_s
block|{
name|agsaIOCountInfo_t
name|IOCounter
decl_stmt|;
name|bit32
name|arrayIOCounter
index|[
name|LL_COUNTERS
index|]
decl_stmt|;
block|}
name|agsaLLCountInfo_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SALL_API_TEST */
end_comment

begin_define
define|#
directive|define
name|MAX_IO_DEVICE_ENTRIES
value|4096
end_define

begin_comment
comment|/**< Maximum Device Entries */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SA_ENABLE_POISION_TLP
end_ifdef

begin_define
define|#
directive|define
name|SA_PTNFE_POISION_TLP
value|1
end_define

begin_comment
comment|/* Enable if one  */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SA_ENABLE_POISION_TLP */
end_comment

begin_define
define|#
directive|define
name|SA_PTNFE_POISION_TLP
value|0
end_define

begin_comment
comment|/* Disable if zero default setting */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SA_ENABLE_POISION_TLP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SA_DISABLE_MDFD
end_ifdef

begin_define
define|#
directive|define
name|SA_MDFD_MULTI_DATA_FETCH
value|1
end_define

begin_comment
comment|/* Disable if one  */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SA_DISABLE_MDFD */
end_comment

begin_define
define|#
directive|define
name|SA_MDFD_MULTI_DATA_FETCH
value|0
end_define

begin_comment
comment|/* Enable if zero default setting */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SA_DISABLE_MDFD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SA_ENABLE_ARBTE
end_ifdef

begin_define
define|#
directive|define
name|SA_ARBTE
value|1
end_define

begin_comment
comment|/* Enable if one  */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SA_ENABLE_ARBTE */
end_comment

begin_define
define|#
directive|define
name|SA_ARBTE
value|0
end_define

begin_comment
comment|/* Disable if zero default setting */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SA_ENABLE_ARBTE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SA_DISABLE_OB_COAL
end_ifdef

begin_define
define|#
directive|define
name|SA_OUTBOUND_COALESCE
value|0
end_define

begin_comment
comment|/* Disable if zero */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SA_DISABLE_OB_COAL */
end_comment

begin_define
define|#
directive|define
name|SA_OUTBOUND_COALESCE
value|1
end_define

begin_comment
comment|/* Enable if one default setting */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SA_DISABLE_OB_COAL */
end_comment

begin_comment
comment|/***********************************************************************************  *                                                                                 *  *              The OS Layer Functions Declarations start                          *  *                                                                                 *  ***********************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"saosapi.h"
end_include

begin_comment
comment|/***********************************************************************************  *                                                                                 *  *              The OS Layer Functions Declarations end                            *  *                                                                                 *  ***********************************************************************************/
end_comment

begin_comment
comment|/***********************************************************************************  *                                                                                 *  *              The LL Layer Functions Declarations start                          *  *                                                                                 *  ***********************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FAST_IO_TEST
end_ifdef

begin_comment
comment|/* needs to be allocated by the xPrepare() caller, one struct per IO */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaFastCBBuf_s
block|{
name|void
modifier|*
name|cb
decl_stmt|;
name|void
modifier|*
name|cbArg
decl_stmt|;
name|void
modifier|*
name|pSenseData
decl_stmt|;
name|bit8
modifier|*
name|senseLen
decl_stmt|;
comment|/* internal */
name|void
modifier|*
name|oneDeviceData
decl_stmt|;
comment|/* tdsaDeviceData_t */
block|}
name|agsaFastCBBuf_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaFastCommand_s
block|{
comment|/* in */
name|void
modifier|*
name|agRoot
decl_stmt|;
comment|/* modified by TD tiFastPrepare() */
name|void
modifier|*
name|devHandle
decl_stmt|;
comment|/* agsaDevHandle_t* */
name|void
modifier|*
name|agSgl
decl_stmt|;
comment|/* agsaSgl_t* */
name|bit32
name|dataLength
decl_stmt|;
name|bit32
name|extDataLength
decl_stmt|;
name|bit8
name|additionalCdbLen
decl_stmt|;
name|bit8
modifier|*
name|cdb
decl_stmt|;
name|bit8
modifier|*
name|lun
decl_stmt|;
comment|/* modified by TD tiFastPrepare() */
name|bit8
name|taskAttribute
decl_stmt|;
comment|/* TD_xxx */
name|bit16
name|flag
decl_stmt|;
comment|/* TLR_MASK */
name|bit32
name|agRequestType
decl_stmt|;
name|bit32
name|queueNum
decl_stmt|;
name|agsaFastCBBuf_t
modifier|*
name|safb
decl_stmt|;
block|}
name|agsaFastCommand_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable test by setting bits in gFPGA_TEST */
end_comment

begin_define
define|#
directive|define
name|EnableFPGA_TEST_ICCcontrol
value|0x01
end_define

begin_define
define|#
directive|define
name|EnableFPGA_TEST_ReadDEV
value|0x02
end_define

begin_define
define|#
directive|define
name|EnableFPGA_TEST_WriteCALAll
value|0x04
end_define

begin_define
define|#
directive|define
name|EnableFPGA_TEST_ReconfigSASParams
value|0x08
end_define

begin_define
define|#
directive|define
name|EnableFPGA_TEST_LocalPhyControl
value|0x10
end_define

begin_define
define|#
directive|define
name|EnableFPGA_TEST_PortControl
value|0x20
end_define

begin_comment
comment|/* PM8001/PM8008/PM8009/PM8018 sTSDK Low-Level Architecture Specification SDK2 3.3 Encryption Status Definitions Encryption engine generated errors. Table 7 Encryption Engine Generated Errors Error Definition */
end_comment

begin_comment
comment|/* PM 1.01 section 4.26.12.6 Encryption Errors Table 51 lists initialization errors related to encryption functionality. For information on errors reported for inbound IOMB commands, refer to the corresponding outbound response sections. The error codes listed in Table 51 are reported in the Scratchpad 3 Register. */
end_comment

begin_define
define|#
directive|define
name|OSSA_ENCRYPT_ENGINE_FAILURE_MASK
value|0x00FF0000
end_define

begin_comment
comment|/* Encrypt Engine failed the BIST Test */
end_comment

begin_define
define|#
directive|define
name|OSSA_ENCRYPT_SEEPROM_NOT_FOUND
value|0x01
end_define

begin_comment
comment|/* SEEPROM is not installed. This condition is reported based on the bootstrap pin setting. */
end_comment

begin_define
define|#
directive|define
name|OSSA_ENCRYPT_SEEPROM_IPW_RD_ACCESS_TMO
value|0x02
end_define

begin_comment
comment|/* SEEPROM access timeout detected while reading initialization password or Allowable Cipher Modes. */
end_comment

begin_define
define|#
directive|define
name|OSSA_ENCRYPT_SEEPROM_IPW_RD_CRC_ERR
value|0x03
end_define

begin_comment
comment|/* CRC Error detected when reading initialization password or Allowable Cipher Modes.  */
end_comment

begin_define
define|#
directive|define
name|OSSA_ENCRYPT_SEEPROM_IPW_INVALID
value|0x04
end_define

begin_comment
comment|/* Initialization password read from SEEPROM doesn't match any valid password value. This could also mean SEEPROM is blank.  */
end_comment

begin_define
define|#
directive|define
name|OSSA_ENCRYPT_SEEPROM_WR_ACCESS_TMO
value|0x05
end_define

begin_comment
comment|/* access timeout detected while writing initialization password or Allowable Cipher Modes.  */
end_comment

begin_define
define|#
directive|define
name|OSSA_ENCRYPT_FLASH_ACCESS_TMO
value|0x20
end_define

begin_comment
comment|/* Timeout while reading flash memory. */
end_comment

begin_define
define|#
directive|define
name|OSSA_ENCRYPT_FLASH_SECTOR_ERASE_TMO
value|0x21
end_define

begin_comment
comment|/* Flash sector erase timeout while writing to flash memory. */
end_comment

begin_define
define|#
directive|define
name|OSSA_ENCRYPT_FLASH_SECTOR_ERASE_ERR
value|0x22
end_define

begin_comment
comment|/* Flash sector erase failure while writing to flash memory. */
end_comment

begin_define
define|#
directive|define
name|OSSA_ENCRYPT_FLASH_ECC_CHECK_ERR
value|0x23
end_define

begin_comment
comment|/* Flash ECC check failure. */
end_comment

begin_define
define|#
directive|define
name|OSSA_ENCRYPT_FLASH_NOT_INSTALLED
value|0x24
end_define

begin_comment
comment|/* Flash memory not installed, this error is only detected in Security Mode B.  */
end_comment

begin_define
define|#
directive|define
name|OSSA_ENCRYPT_INITIAL_KEK_NOT_FOUND
value|0x40
end_define

begin_comment
comment|/* Initial KEK is not found in the flash memory. This error is only detected in Security Mode B. */
end_comment

begin_define
define|#
directive|define
name|OSSA_ENCRYPT_AES_BIST_ERR
value|0x41
end_define

begin_comment
comment|/* Built-In Test Failure */
end_comment

begin_define
define|#
directive|define
name|OSSA_ENCRYPT_KWP_BIST_FAILURE
value|0x42
end_define

begin_comment
comment|/* Built-In Test Failed on Key Wrap Engine */
end_comment

begin_comment
comment|/* 0x01:ENC_ERR_SEEPROM_NOT_INSTALLED */
end_comment

begin_comment
comment|/* 0x02:ENC_ERR_SEEPROM_IPW_RD_ACCESS_TMO */
end_comment

begin_comment
comment|/* 0x03:ENC_ERR_SEEPROM_IPW_RD_CRC_ERR */
end_comment

begin_comment
comment|/* 0x04:ENC_ERR_SEEPROM_IPW_INVALID */
end_comment

begin_comment
comment|/* 0x05:ENC_ERR_SEEPROM_WR_ACCESS_TMO */
end_comment

begin_comment
comment|/* 0x20:ENC_ERR_FLASH_ACCESS_TMO */
end_comment

begin_comment
comment|/* 0x21:ENC_ERR_FLASH_SECTOR_ERASE_TMO */
end_comment

begin_comment
comment|/* 0x22:ENC_ERR_FLASH_SECTOR_ERASE_FAILURE */
end_comment

begin_comment
comment|/* 0x23:ENC_ERR_FLASH_ECC_CHECK_FAILURE */
end_comment

begin_comment
comment|/* 0x24:ENC_ERR_FLASH_NOT_INSTALLED */
end_comment

begin_comment
comment|/* 0x40:ENC_ERR_INITIAL_KEK_NOT_FOUND */
end_comment

begin_comment
comment|/* 0x41:ENC_ERR_AES_BIST_FAILURE */
end_comment

begin_comment
comment|/* 0x42:ENC_ERR_KWP_BIST_FAILURE */
end_comment

begin_comment
comment|/* This field indicates self test failure in DIF engine bits [27:24]. */
end_comment

begin_define
define|#
directive|define
name|OSSA_DIF_ENGINE_FAILURE_MASK
value|0x0F000000
end_define

begin_comment
comment|/* DIF Engine failed the BIST Test */
end_comment

begin_define
define|#
directive|define
name|OSSA_DIF_ENGINE_0_BIST_FAILURE
value|0x1
end_define

begin_comment
comment|/* DIF Engine 0 failed the BIST Test */
end_comment

begin_define
define|#
directive|define
name|OSSA_DIF_ENGINE_1_BIST_FAILURE
value|0x2
end_define

begin_comment
comment|/* DIF Engine 1 failed the BIST Test */
end_comment

begin_define
define|#
directive|define
name|OSSA_DIF_ENGINE_2_BIST_FAILURE
value|0x4
end_define

begin_comment
comment|/* DIF Engine 2 failed the BIST Test */
end_comment

begin_define
define|#
directive|define
name|OSSA_DIF_ENGINE_3_BIST_FAILURE
value|0x8
end_define

begin_comment
comment|/* DIF Engine 3 failed the BIST Test */
end_comment

begin_define
define|#
directive|define
name|SA_ROLE_CAPABILITIES_CSP
value|0x001
end_define

begin_define
define|#
directive|define
name|SA_ROLE_CAPABILITIES_OPR
value|0x002
end_define

begin_define
define|#
directive|define
name|SA_ROLE_CAPABILITIES_SCO
value|0x004
end_define

begin_define
define|#
directive|define
name|SA_ROLE_CAPABILITIES_STS
value|0x008
end_define

begin_define
define|#
directive|define
name|SA_ROLE_CAPABILITIES_TST
value|0x010
end_define

begin_define
define|#
directive|define
name|SA_ROLE_CAPABILITIES_KEK
value|0x020
end_define

begin_define
define|#
directive|define
name|SA_ROLE_CAPABILITIES_DEK
value|0x040
end_define

begin_define
define|#
directive|define
name|SA_ROLE_CAPABILITIES_IOS
value|0x080
end_define

begin_define
define|#
directive|define
name|SA_ROLE_CAPABILITIES_FWU
value|0x100
end_define

begin_define
define|#
directive|define
name|SA_ROLE_CAPABILITIES_PRM
value|0x200
end_define

begin_include
include|#
directive|include
file|"saapi.h"
end_include

begin_comment
comment|/***********************************************************************************  *                                                                                 *  *              The LL Layer Functions Declarations end                            *  *                                                                                 *  ***********************************************************************************/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__SA_H__ */
end_comment

end_unit

