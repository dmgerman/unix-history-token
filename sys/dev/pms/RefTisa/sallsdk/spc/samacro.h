begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*! \file samacro.h  *  \brief The file defines macros used in LL sTSDK  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SAMACRO_H__
end_ifndef

begin_define
define|#
directive|define
name|__SAMACRO_H__
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SALLSDK_DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|MPI_IBQ_IOMB_LOG_ENABLE
end_define

begin_define
define|#
directive|define
name|MPI_OBQ_IOMB_LOG_ENABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def MIN(a,b) * \brief MIN macro * * use to find MIN of two values */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def MAX(a,b) * \brief MAX macro * * use to find MAX of two values */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (b) : (a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*************************************************************************************************  *                      define Phy status macros                                                 *  *************************************************************************************************/
end_comment

begin_comment
comment|/*! \def PHY_STATUS_SET(pPhy, value) * \brief PHY_STATUS_SET macro * * use to set phy status */
end_comment

begin_define
define|#
directive|define
name|PHY_STATUS_SET
parameter_list|(
name|pPhy
parameter_list|,
name|value
parameter_list|)
value|((pPhy)->status = (((pPhy)->status& 0xFFFF0000) | (value)))
end_define

begin_comment
comment|/*! \def PHY_STATUS_CHECK(pPhy, value) * \brief PHY_STATUS_CHECK macro * * use to check phy status */
end_comment

begin_define
define|#
directive|define
name|PHY_STATUS_CHECK
parameter_list|(
name|pPhy
parameter_list|,
name|value
parameter_list|)
value|( ((pPhy)->status& 0x0000FFFF) == (value) )
end_define

begin_comment
comment|/************************************************************************************  *                        define CBUFFER operation macros                           *  ************************************************************************************/
end_comment

begin_comment
comment|/*! \def AGSAMEM_ELEMENT_READ(pMem, index) * \brief AGSAMEM_ELEMENT_READ macro * * use to read an element of a memory array */
end_comment

begin_define
define|#
directive|define
name|AGSAMEM_ELEMENT_READ
parameter_list|(
name|pMem
parameter_list|,
name|index
parameter_list|)
value|(((bit8 *)(pMem)->virtPtr) + (pMem)->singleElementLength * (index))
end_define

begin_comment
comment|/************************************************************************************  *                        define Chip ID macro                                      *  ************************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SA_TREAT_SFC_AS_SPC
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SA_TREAT_SFC_AS_SPC
end_ifdef

begin_define
define|#
directive|define
name|SA_SFC_AS_SPC
value|1
end_define

begin_define
define|#
directive|define
name|SA_SFC_AS_SPCV
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* TREAT_SFC_AS_SPCv */
end_comment

begin_define
define|#
directive|define
name|SA_SFC_AS_SPC
value|0
end_define

begin_define
define|#
directive|define
name|SA_SFC_AS_SPCV
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SA_TREAT_SFC_AS_SPC */
end_comment

begin_define
define|#
directive|define
name|IS_SDKDATA
parameter_list|(
name|agr
parameter_list|)
value|(((agr)->sdkData != agNULL ) ? 1 : 0)
end_define

begin_comment
comment|/* returns true if sdkdata is available */
end_comment

begin_define
define|#
directive|define
name|smIsCfgSpcREV_A
parameter_list|(
name|agr
parameter_list|)
value|(8  ==( ossaHwRegReadConfig32((agr), 8 )& 0xF) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is REVA */
end_comment

begin_define
define|#
directive|define
name|smIsCfgSpcREV_B
parameter_list|(
name|agr
parameter_list|)
value|(4  ==( ossaHwRegReadConfig32((agr), 8 )& 0xF) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is REVB */
end_comment

begin_define
define|#
directive|define
name|smIsCfgSpcREV_C
parameter_list|(
name|agr
parameter_list|)
value|(5  ==( ossaHwRegReadConfig32((agr), 8 )& 0xF) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is REVC */
end_comment

begin_define
define|#
directive|define
name|smIsCfgVREV_A
parameter_list|(
name|agr
parameter_list|)
value|(4  ==( ossaHwRegReadConfig32((agr), 8 )& 0xF) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is REVA */
end_comment

begin_define
define|#
directive|define
name|smIsCfgVREV_B
parameter_list|(
name|agr
parameter_list|)
value|(5  ==( ossaHwRegReadConfig32((agr), 8 )& 0xF) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is REVB */
end_comment

begin_define
define|#
directive|define
name|smIsCfgVREV_C
parameter_list|(
name|agr
parameter_list|)
value|(6  ==( ossaHwRegReadConfig32((agr), 8 )& 0xF) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is REVC */
end_comment

begin_define
define|#
directive|define
name|smIsCfg8001
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPC   == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000)  ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC */
end_comment

begin_define
define|#
directive|define
name|smIsCfg8081
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_HIL   == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000 ) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is Hialeah */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V8025
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SFC   == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000)  ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SFC  */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V8008
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPCV  == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000)  ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCv */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V8009
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPCVE == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000)  ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCv */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V8018
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPCVP == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000)  ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCv */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V8019
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPCVEP== (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000)  ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCv */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V8088
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_ADAPVP == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCv */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V8089
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_ADAPVEP== (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCv */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V8070
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPC12V  == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC12v */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V8071
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPC12VE == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC12v */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V8072
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPC12VP == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC12v */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V8073
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPC12VEP== (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC12v */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V8074
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPC12ADP   == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is Adaptec SPC12v */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V8075
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPC12ADPE  == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is Adaptec SPC12v */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V8076
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPC12ADPP  == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is Adaptec SPC12v */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V8077
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPC12ADPEP == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is Adaptec SPC12v */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V8006
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_SPC12SATA  == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is Adaptec SPC12v */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V9015
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_9015 == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC12v */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_V9060
parameter_list|(
name|agr
parameter_list|)
value|(VEN_DEV_9060 == (ossaHwRegReadConfig32((agr),0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC12v */
end_comment

begin_define
define|#
directive|define
name|smIsCfg_SPC_ANY
parameter_list|(
name|agr
parameter_list|)
value|((smIsCfg8001((agr))    == 1) ? 1 : \                               (smIsCfg8081((agr))    == 1) ? 1 : \                               (smIsCfg_V8025((agr)) == 1) ? SA_SFC_AS_SPC : 0)
end_define

begin_define
define|#
directive|define
name|smIS_SPCV8008
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_SPCV )  ? 1 : 0) : smIsCfg_V8008((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SPCV8009
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_SPCVE)  ? 1 : 0) : smIsCfg_V8009((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SPCV8018
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_SPCVP)  ? 1 : 0) : smIsCfg_V8018((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SPCV8019
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_SPCVEP) ? 1 : 0) : smIsCfg_V8019((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_ADAP8088
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_ADAPVP) ? 1 : 0) : smIsCfg_V8088((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_ADAP8089
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_ADAPVEP)? 1 : 0): smIsCfg_V8089((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SPCV8070
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_SPC12V ) ? 1 : 0) : smIsCfg_V8070((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SPCV8071
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_SPC12VE) ? 1 : 0) : smIsCfg_V8071((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SPCV8072
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_SPC12VP) ? 1 : 0) : smIsCfg_V8072((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SPCV8073
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_SPC12VEP)? 1 : 0) : smIsCfg_V8073((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SPCV8074
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_SPC12ADP ) ? 1 : 0) : smIsCfg_V8074((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SPCV8075
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_SPC12ADPE) ? 1 : 0) : smIsCfg_V8075((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SPCV8076
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_SPC12ADPP) ? 1 : 0) : smIsCfg_V8076((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SPCV8077
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_SPC12ADPEP)? 1 : 0) : smIsCfg_V8077((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SPCV8006
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_SPC12SATA) ? 1 : 0) : smIsCfg_V8006((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SPCV9015
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_9015)    ? 1 : 0) : smIsCfg_V9015((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SPCV9060
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_9060)    ? 1 : 0) : smIsCfg_V9060((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SPCV8025
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_SFC  ) ? 1 : 0) : smIsCfg_V8025((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SFC
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_SFC  ) ? 1 : 0) : smIsCfg_V8025((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_spc8001
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_SPC  ) ? 1 : 0) : smIsCfg8001((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_spc8081
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->ChipId == VEN_DEV_HIL  ) ? 1 : 0) : smIsCfg8081((agr)))
end_define

begin_define
define|#
directive|define
name|smIS_SFC_AS_SPC
parameter_list|(
name|agr
parameter_list|)
value|((smIS_SFC((agr)) == 1) ? SA_SFC_AS_SPC : 0 )
end_define

begin_define
define|#
directive|define
name|smIS_SFC_AS_V
parameter_list|(
name|agr
parameter_list|)
value|((smIS_SFC((agr)) == 1 )? SA_SFC_AS_SPCV : 0 )
end_define

begin_comment
comment|/* Use 64 bit interrupts for SPCv, before getting saroot. Once saroot available only use 64bit when needed */
end_comment

begin_define
define|#
directive|define
name|smIS64bInt
parameter_list|(
name|agr
parameter_list|)
value|(IS_SDKDATA((agr)) ? ( (((agsaLLRoot_t *)((agr)->sdkData))->Use64bit) ? 1 : 0)  : smIS_SPCV(agr))
end_define

begin_define
define|#
directive|define
name|WHATTABLE
parameter_list|(
name|agr
parameter_list|)
define|\
value|(                                                                               \ IS_SDKDATA((agr)) ?                                                               \   (smIS_SPC((agr))  ?&SPCTable[0]  : (smIS_SPCV((agr)) ?&SPC_V_Table[0] : agNULL ) )  \ :                                                                               \   (smIsCfg_SPC_ANY((agr)) ?&SPCTable[0] : (smIsCfg_V_ANY((agr)) ?&SPC_V_Table[0] : agNULL ) ) \ ) \  #if defined(SALLSDK_DEBUG)
end_define

begin_comment
comment|/* * for debugging purposes. */
end_comment

begin_decl_stmt
specifier|extern
name|bit32
name|gLLDebugLevel
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SA_DBG0
parameter_list|(
name|format
parameter_list|)
value|ossaLogDebugString(gLLDebugLevel, 0, format)
end_define

begin_define
define|#
directive|define
name|SA_DBG1
parameter_list|(
name|format
parameter_list|)
value|ossaLogDebugString(gLLDebugLevel, 1, format)
end_define

begin_define
define|#
directive|define
name|SA_DBG2
parameter_list|(
name|format
parameter_list|)
value|ossaLogDebugString(gLLDebugLevel, 2, format)
end_define

begin_define
define|#
directive|define
name|SA_DBG3
parameter_list|(
name|format
parameter_list|)
value|ossaLogDebugString(gLLDebugLevel, 3, format)
end_define

begin_define
define|#
directive|define
name|SA_DBG4
parameter_list|(
name|format
parameter_list|)
value|ossaLogDebugString(gLLDebugLevel, 4, format)
end_define

begin_define
define|#
directive|define
name|SA_DBG5
parameter_list|(
name|format
parameter_list|)
value|ossaLogDebugString(gLLDebugLevel, 5, format)
end_define

begin_define
define|#
directive|define
name|SA_DBG6
parameter_list|(
name|format
parameter_list|)
value|ossaLogDebugString(gLLDebugLevel, 6, format)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SA_DBG0
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SA_DBG1
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SA_DBG2
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SA_DBG3
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SA_DBG4
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SA_DBG5
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SA_DBG6
parameter_list|(
name|format
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SA_ASSERT
value|OS_ASSERT
end_define

begin_typedef
typedef|typedef
enum|enum
name|siPrintType_e
block|{
name|SA_8
block|,
name|SA_16
block|,
name|SA_32
block|}
name|siPrintType
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SALLSDK_DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|SA_PRINTBUF
parameter_list|(
name|lDebugLevel
parameter_list|,
name|lWidth
parameter_list|,
name|pHeader
parameter_list|,
name|pBuffer
parameter_list|,
name|lLength
parameter_list|)
value|siPrintBuffer(lDebugLevel,lWidth,pHeader,pBuffer,lLength)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SA_PRINTBUF
parameter_list|(
name|lDebugLevel
parameter_list|,
name|lWidth
parameter_list|,
name|pHeader
parameter_list|,
name|pBuffer
parameter_list|,
name|lLength
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SALLSDK_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DBG_DUMP_SSPSTART_CMDIU
parameter_list|(
name|agDevHandle
parameter_list|,
name|agRequestType
parameter_list|,
name|agRequestBody
parameter_list|)
value|siDumpSSPStartIu(agDevHandle,agRequestType,agRequestBody)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBG_DUMP_SSPSTART_CMDIU
parameter_list|(
name|agDevHandle
parameter_list|,
name|agRequestType
parameter_list|,
name|agRequestBody
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MPI_DEBUG_TRACE_ENABLE
end_ifdef

begin_define
define|#
directive|define
name|MPI_DEBUG_TRACE_ENTER_LOCK
value|ossaSingleThreadedEnter(agRoot, LL_IOMB_TRACE_LOCK);
end_define

begin_define
define|#
directive|define
name|MPI_DEBUG_TRACE_LEAVE_LOCK
value|ossaSingleThreadedLeave(agRoot, LL_IOMB_TRACE_LOCK);
end_define

begin_define
define|#
directive|define
name|MPI_DEBUG_TRACE
parameter_list|(
name|queue
parameter_list|,
name|pici
parameter_list|,
name|ib
parameter_list|,
name|iomb
parameter_list|,
name|count
parameter_list|)
define|\
value|MPI_DEBUG_TRACE_ENTER_LOCK \  mpiTraceAdd( (queue), (pici),(ib), (iomb), (count)); \   MPI_DEBUG_TRACE_LEAVE_LOCK
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MPI_DEBUG_TRACE
parameter_list|(
name|queue
parameter_list|,
name|pici
parameter_list|,
name|ib
parameter_list|,
name|iomb
parameter_list|,
name|count
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MPI_DEBUG_TRACE_ENABLE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MPI_IBQ_IOMB_LOG_ENABLE
end_ifdef

begin_define
define|#
directive|define
name|MPI_IBQ_IOMB_LOG
parameter_list|(
name|qNumber
parameter_list|,
name|msgHeader
parameter_list|,
name|msgLength
parameter_list|)
define|\
value|do \ { \   bit32 i; \   SA_DBG3(("\n")); \   SA_DBG3(("mpiMsgProduce: IBQ %d\n", (qNumber))); \   for (i = 0; i< msgLength/16; i++) \   { \     SA_DBG3(("Inb: DW %02d 0x%08x 0x%08x 0x%08x 0x%08x\n", i*4, *((bit32 *)msgHeader+(i*4)), \            *((bit32 *)msgHeader+(i*4)+1), *((bit32 *)msgHeader+(i*4)+2), \            *((bit32 *)msgHeader+(i*4)+3))); \   } \ } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MPI_OBQ_IOMB_LOG_ENABLE
end_ifdef

begin_define
define|#
directive|define
name|MPI_OBQ_IOMB_LOG
parameter_list|(
name|qNumber
parameter_list|,
name|msgHeader
parameter_list|,
name|msgLength
parameter_list|)
define|\
value|do \ { \   bit32 i; \   SA_DBG3(("\n")); \   SA_DBG3(("mpiMsgConsume: OBQ %d\n", qNumber)); \   for (i = 0; i< msgLength/16; i++) \   { \     SA_DBG3(("Out: DW %02d 0x%08x 0x%08x 0x%08x 0x%08x\n", i*4, *((bit32 *)msgHeader+(i*4)), \            *((bit32 *)msgHeader+(i*4)+1), *((bit32 *)msgHeader+(i*4)+2), \            *((bit32 *)msgHeader+(i*4)+3))); \   } \ } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************************************************************************  *                        Wait X Second                                             *  ************************************************************************************/
end_comment

begin_define
define|#
directive|define
name|WAIT_SECONDS
parameter_list|(
name|x
parameter_list|)
value|((x) * 1000 * 1000 )
end_define

begin_define
define|#
directive|define
name|ONE_HUNDRED_MILLISECS
value|(100 * 1000)
end_define

begin_comment
comment|/* 100,000 microseconds  */
end_comment

begin_define
define|#
directive|define
name|WAIT_INCREMENT_DEFAULT
value|1000
end_define

begin_define
define|#
directive|define
name|WAIT_INCREMENT
value|(IS_SDKDATA(agRoot) ? ( ((agsaLLRoot_t *)(agRoot->sdkData))->minStallusecs ) : WAIT_INCREMENT_DEFAULT )
end_define

begin_comment
comment|// (((agsaLLRoot_t *)(agRoot->sdkData))->minStallusecs)
end_comment

begin_define
define|#
directive|define
name|MAKE_MODULO
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a) % (b)) ? ((a) - ((a) % (b))) : (a))
end_define

begin_define
define|#
directive|define
name|HDA_STEP_2
value|1
end_define

begin_define
define|#
directive|define
name|HDA_STEP_3
value|1
end_define

begin_define
define|#
directive|define
name|HDA_STEP_4
value|1
end_define

begin_define
define|#
directive|define
name|HDA_STEP_5
value|1
end_define

begin_define
define|#
directive|define
name|HDA_STEP_6
value|1
end_define

begin_define
define|#
directive|define
name|HDA_STEP_7
value|1
end_define

begin_define
define|#
directive|define
name|HDA_STEP_8
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SAMACRO_H__ */
end_comment

end_unit

