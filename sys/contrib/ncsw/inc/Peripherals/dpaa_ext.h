begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2012 Freescale Semiconductor, Inc  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          dpaa_ext.h   @Description   DPAA Application Programming Interface. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DPAA_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__DPAA_EXT_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"error_ext.h"
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         DPAA_grp Data Path Acceleration Architecture API   @Description   DPAA API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__MWERKS__)&& ... */
end_comment

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_define
define|#
directive|define
name|__BYTE_ORDER__
value|BYTE_ORDER
end_define

begin_define
define|#
directive|define
name|__ORDER_BIG_ENDIAN__
value|BIG_ENDIAN
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Frame descriptor */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_DpaaFD
block|{
if|#
directive|if
name|__BYTE_ORDER__
operator|==
name|__ORDER_BIG_ENDIAN__
specifier|volatile
name|uint8_t
name|liodn
decl_stmt|;
specifier|volatile
name|uint8_t
name|bpid
decl_stmt|;
specifier|volatile
name|uint8_t
name|elion
decl_stmt|;
specifier|volatile
name|uint8_t
name|addrh
decl_stmt|;
specifier|volatile
name|uint32_t
name|addrl
decl_stmt|;
else|#
directive|else
specifier|volatile
name|uint32_t
name|addrl
decl_stmt|;
specifier|volatile
name|uint8_t
name|addrh
decl_stmt|;
specifier|volatile
name|uint8_t
name|elion
decl_stmt|;
specifier|volatile
name|uint8_t
name|bpid
decl_stmt|;
specifier|volatile
name|uint8_t
name|liodn
decl_stmt|;
endif|#
directive|endif
specifier|volatile
name|uint32_t
name|length
decl_stmt|;
comment|/**< Frame length */
specifier|volatile
name|uint32_t
name|status
decl_stmt|;
comment|/**< FD status */
block|}
name|_PackedType
name|t_DpaaFD
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining frame format */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_DpaaFDFormatType
block|{
name|e_DPAA_FD_FORMAT_TYPE_SHORT_SBSF
init|=
literal|0x0
block|,
comment|/**< Simple frame Single buffer; Offset and                                                     small length (9b OFFSET, 20b LENGTH) */
name|e_DPAA_FD_FORMAT_TYPE_LONG_SBSF
init|=
literal|0x2
block|,
comment|/**< Simple frame, single buffer; big length                                                     (29b LENGTH ,No OFFSET) */
name|e_DPAA_FD_FORMAT_TYPE_SHORT_MBSF
init|=
literal|0x4
block|,
comment|/**< Simple frame, Scatter Gather table; Offset                                                     and small length (9b OFFSET, 20b LENGTH) */
name|e_DPAA_FD_FORMAT_TYPE_LONG_MBSF
init|=
literal|0x6
block|,
comment|/**< Simple frame, Scatter Gather table;                                                     big length (29b LENGTH ,No OFFSET) */
name|e_DPAA_FD_FORMAT_TYPE_COMPOUND
init|=
literal|0x1
block|,
comment|/**< Compound Frame (29b CONGESTION-WEIGHT                                                     No LENGTH or OFFSET) */
name|e_DPAA_FD_FORMAT_TYPE_DUMMY
block|}
name|e_DpaaFDFormatType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection   Frame descriptor macros */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_DD_MASK
value|0xc0000000
end_define

begin_comment
comment|/**< FD DD field mask */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_PID_MASK
value|0x3f000000
end_define

begin_comment
comment|/**< FD PID field mask */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_ELIODN_MASK
value|0x0000f000
end_define

begin_comment
comment|/**< FD ELIODN field mask */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_BPID_MASK
value|0x00ff0000
end_define

begin_comment
comment|/**< FD BPID field mask */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_ADDRH_MASK
value|0x000000ff
end_define

begin_comment
comment|/**< FD ADDRH field mask */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_ADDRL_MASK
value|0xffffffff
end_define

begin_comment
comment|/**< FD ADDRL field mask */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_FORMAT_MASK
value|0xe0000000
end_define

begin_comment
comment|/**< FD FORMAT field mask */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_OFFSET_MASK
value|0x1ff00000
end_define

begin_comment
comment|/**< FD OFFSET field mask */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_LENGTH_MASK
value|0x000fffff
end_define

begin_comment
comment|/**< FD LENGTH field mask */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_GET_ADDRH
parameter_list|(
name|fd
parameter_list|)
value|((t_DpaaFD *)fd)->addrh
end_define

begin_comment
comment|/**< Macro to get FD ADDRH field */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_GET_ADDRL
parameter_list|(
name|fd
parameter_list|)
value|((t_DpaaFD *)fd)->addrl
end_define

begin_comment
comment|/**< Macro to get FD ADDRL field */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_GET_PHYS_ADDR
parameter_list|(
name|fd
parameter_list|)
value|((physAddress_t)(((uint64_t)DPAA_FD_GET_ADDRH(fd)<< 32) | (uint64_t)DPAA_FD_GET_ADDRL(fd)))
end_define

begin_comment
comment|/**< Macro to get FD ADDR field */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_GET_FORMAT
parameter_list|(
name|fd
parameter_list|)
value|((((t_DpaaFD *)fd)->length& DPAA_FD_FORMAT_MASK)>> (31-2))
end_define

begin_comment
comment|/**< Macro to get FD FORMAT field */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_GET_OFFSET
parameter_list|(
name|fd
parameter_list|)
value|((((t_DpaaFD *)fd)->length& DPAA_FD_OFFSET_MASK)>> (31-11))
end_define

begin_comment
comment|/**< Macro to get FD OFFSET field */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_GET_LENGTH
parameter_list|(
name|fd
parameter_list|)
value|(((t_DpaaFD *)fd)->length& DPAA_FD_LENGTH_MASK)
end_define

begin_comment
comment|/**< Macro to get FD LENGTH field */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_GET_STATUS
parameter_list|(
name|fd
parameter_list|)
value|((t_DpaaFD *)fd)->status
end_define

begin_comment
comment|/**< Macro to get FD STATUS field */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_GET_ADDR
parameter_list|(
name|fd
parameter_list|)
value|XX_PhysToVirt(DPAA_FD_GET_PHYS_ADDR(fd))
end_define

begin_comment
comment|/**< Macro to get FD ADDR (virtual) */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_SET_ADDRH
parameter_list|(
name|fd
parameter_list|,
name|val
parameter_list|)
value|((t_DpaaFD *)fd)->addrh = (val)
end_define

begin_comment
comment|/**< Macro to set FD ADDRH field */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_SET_ADDRL
parameter_list|(
name|fd
parameter_list|,
name|val
parameter_list|)
value|((t_DpaaFD *)fd)->addrl = (val)
end_define

begin_comment
comment|/**< Macro to set FD ADDRL field */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_SET_ADDR
parameter_list|(
name|fd
parameter_list|,
name|val
parameter_list|)
define|\
value|do {                                                        \     uint64_t physAddr = (uint64_t)(XX_VirtToPhys(val));     \     DPAA_FD_SET_ADDRH(fd, ((uint32_t)(physAddr>> 32)));    \     DPAA_FD_SET_ADDRL(fd, (uint32_t)physAddr);              \ } while (0)
end_define

begin_comment
comment|/**< Macro to set FD ADDR field */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_SET_FORMAT
parameter_list|(
name|fd
parameter_list|,
name|val
parameter_list|)
value|(((t_DpaaFD *)fd)->length = ((((t_DpaaFD *)fd)->length& ~DPAA_FD_FORMAT_MASK) | (((val)<< (31-2))& DPAA_FD_FORMAT_MASK)))
end_define

begin_comment
comment|/**< Macro to set FD FORMAT field */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_SET_OFFSET
parameter_list|(
name|fd
parameter_list|,
name|val
parameter_list|)
value|(((t_DpaaFD *)fd)->length = ((((t_DpaaFD *)fd)->length& ~DPAA_FD_OFFSET_MASK) | (((val)<< (31-11))& DPAA_FD_OFFSET_MASK) ))
end_define

begin_comment
comment|/**< Macro to set FD OFFSET field */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_SET_LENGTH
parameter_list|(
name|fd
parameter_list|,
name|val
parameter_list|)
value|(((t_DpaaFD *)fd)->length = (((t_DpaaFD *)fd)->length& ~DPAA_FD_LENGTH_MASK) | ((val)& DPAA_FD_LENGTH_MASK))
end_define

begin_comment
comment|/**< Macro to set FD LENGTH field */
end_comment

begin_define
define|#
directive|define
name|DPAA_FD_SET_STATUS
parameter_list|(
name|fd
parameter_list|,
name|val
parameter_list|)
value|((t_DpaaFD *)fd)->status = (val)
end_define

begin_comment
comment|/**< Macro to set FD STATUS field */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Frame Scatter/Gather Table Entry */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_DpaaSGTE
block|{
specifier|volatile
name|uint32_t
name|addrh
decl_stmt|;
comment|/**< Buffer Address high */
specifier|volatile
name|uint32_t
name|addrl
decl_stmt|;
comment|/**< Buffer Address low */
specifier|volatile
name|uint32_t
name|length
decl_stmt|;
comment|/**< Buffer length */
specifier|volatile
name|uint32_t
name|offset
decl_stmt|;
comment|/**< SGTE offset */
block|}
name|_PackedType
name|t_DpaaSGTE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DPAA_NUM_OF_SG_TABLE_ENTRY
value|16
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Frame Scatter/Gather Table */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_DpaaSGT
block|{
name|t_DpaaSGTE
name|tableEntry
index|[
name|DPAA_NUM_OF_SG_TABLE_ENTRY
index|]
decl_stmt|;
comment|/**< Structure that holds information about                                          a single S/G entry. */
block|}
name|_PackedType
name|t_DpaaSGT
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Compound Frame Table */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_DpaaCompTbl
block|{
name|t_DpaaSGTE
name|outputBuffInfo
decl_stmt|;
comment|/**< Structure that holds information about                                          the compound-frame output buffer;                                          NOTE: this may point to a S/G table */
name|t_DpaaSGTE
name|inputBuffInfo
decl_stmt|;
comment|/**< Structure that holds information about                                          the compound-frame input buffer;                                          NOTE: this may point to a S/G table */
block|}
name|_PackedType
name|t_DpaaCompTbl
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection   Frame Scatter/Gather Table Entry macros */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_ADDRH_MASK
value|0x000000ff
end_define

begin_comment
comment|/**< SGTE ADDRH field mask */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_ADDRL_MASK
value|0xffffffff
end_define

begin_comment
comment|/**< SGTE ADDRL field mask */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_E_MASK
value|0x80000000
end_define

begin_comment
comment|/**< SGTE Extension field mask */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_F_MASK
value|0x40000000
end_define

begin_comment
comment|/**< SGTE Final field mask */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_LENGTH_MASK
value|0x3fffffff
end_define

begin_comment
comment|/**< SGTE LENGTH field mask */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_BPID_MASK
value|0x00ff0000
end_define

begin_comment
comment|/**< SGTE BPID field mask */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_OFFSET_MASK
value|0x00001fff
end_define

begin_comment
comment|/**< SGTE OFFSET field mask */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_GET_ADDRH
parameter_list|(
name|sgte
parameter_list|)
value|(((t_DpaaSGTE *)sgte)->addrh& DPAA_SGTE_ADDRH_MASK)
end_define

begin_comment
comment|/**< Macro to get SGTE ADDRH field */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_GET_ADDRL
parameter_list|(
name|sgte
parameter_list|)
value|((t_DpaaSGTE *)sgte)->addrl
end_define

begin_comment
comment|/**< Macro to get SGTE ADDRL field */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_GET_PHYS_ADDR
parameter_list|(
name|sgte
parameter_list|)
value|((physAddress_t)(((uint64_t)DPAA_SGTE_GET_ADDRH(sgte)<< 32) | (uint64_t)DPAA_SGTE_GET_ADDRL(sgte)))
end_define

begin_comment
comment|/**< Macro to get FD ADDR field */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_GET_EXTENSION
parameter_list|(
name|sgte
parameter_list|)
value|((((t_DpaaSGTE *)sgte)->length& DPAA_SGTE_E_MASK)>> (31-0))
end_define

begin_comment
comment|/**< Macro to get SGTE EXTENSION field */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_GET_FINAL
parameter_list|(
name|sgte
parameter_list|)
value|((((t_DpaaSGTE *)sgte)->length& DPAA_SGTE_F_MASK)>> (31-1))
end_define

begin_comment
comment|/**< Macro to get SGTE FINAL field */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_GET_LENGTH
parameter_list|(
name|sgte
parameter_list|)
value|(((t_DpaaSGTE *)sgte)->length& DPAA_SGTE_LENGTH_MASK)
end_define

begin_comment
comment|/**< Macro to get SGTE LENGTH field */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_GET_BPID
parameter_list|(
name|sgte
parameter_list|)
value|((((t_DpaaSGTE *)sgte)->offset& DPAA_SGTE_BPID_MASK)>> (31-15))
end_define

begin_comment
comment|/**< Macro to get SGTE BPID field */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_GET_OFFSET
parameter_list|(
name|sgte
parameter_list|)
value|(((t_DpaaSGTE *)sgte)->offset& DPAA_SGTE_OFFSET_MASK)
end_define

begin_comment
comment|/**< Macro to get SGTE OFFSET field */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_GET_ADDR
parameter_list|(
name|sgte
parameter_list|)
value|XX_PhysToVirt(DPAA_SGTE_GET_PHYS_ADDR(sgte))
end_define

begin_define
define|#
directive|define
name|DPAA_SGTE_SET_ADDRH
parameter_list|(
name|sgte
parameter_list|,
name|val
parameter_list|)
value|(((t_DpaaSGTE *)sgte)->addrh = ((((t_DpaaSGTE *)sgte)->addrh& ~DPAA_SGTE_ADDRH_MASK) | ((val)& DPAA_SGTE_ADDRH_MASK)))
end_define

begin_comment
comment|/**< Macro to set SGTE ADDRH field */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_SET_ADDRL
parameter_list|(
name|sgte
parameter_list|,
name|val
parameter_list|)
value|((t_DpaaSGTE *)sgte)->addrl = (val)
end_define

begin_comment
comment|/**< Macro to set SGTE ADDRL field */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_SET_ADDR
parameter_list|(
name|sgte
parameter_list|,
name|val
parameter_list|)
define|\
value|do {                                                            \     uint64_t physAddr = (uint64_t)(XX_VirtToPhys(val));         \     DPAA_SGTE_SET_ADDRH(sgte, ((uint32_t)(physAddr>> 32)));    \     DPAA_SGTE_SET_ADDRL(sgte, (uint32_t)physAddr);              \ } while (0)
end_define

begin_comment
comment|/**< Macro to set SGTE ADDR field */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_SET_EXTENSION
parameter_list|(
name|sgte
parameter_list|,
name|val
parameter_list|)
value|(((t_DpaaSGTE *)sgte)->length = ((((t_DpaaSGTE *)sgte)->length& ~DPAA_SGTE_E_MASK) | (((val)<< (31-0))& DPAA_SGTE_E_MASK)))
end_define

begin_comment
comment|/**< Macro to set SGTE EXTENSION field */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_SET_FINAL
parameter_list|(
name|sgte
parameter_list|,
name|val
parameter_list|)
value|(((t_DpaaSGTE *)sgte)->length = ((((t_DpaaSGTE *)sgte)->length& ~DPAA_SGTE_F_MASK) | (((val)<< (31-1))& DPAA_SGTE_F_MASK)))
end_define

begin_comment
comment|/**< Macro to set SGTE FINAL field */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_SET_LENGTH
parameter_list|(
name|sgte
parameter_list|,
name|val
parameter_list|)
value|(((t_DpaaSGTE *)sgte)->length = (((t_DpaaSGTE *)sgte)->length& ~DPAA_SGTE_LENGTH_MASK) | ((val)& DPAA_SGTE_LENGTH_MASK))
end_define

begin_comment
comment|/**< Macro to set SGTE LENGTH field */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_SET_BPID
parameter_list|(
name|sgte
parameter_list|,
name|val
parameter_list|)
value|(((t_DpaaSGTE *)sgte)->offset = ((((t_DpaaSGTE *)sgte)->offset& ~DPAA_SGTE_BPID_MASK) | (((val)<< (31-15))& DPAA_SGTE_BPID_MASK)))
end_define

begin_comment
comment|/**< Macro to set SGTE BPID field */
end_comment

begin_define
define|#
directive|define
name|DPAA_SGTE_SET_OFFSET
parameter_list|(
name|sgte
parameter_list|,
name|val
parameter_list|)
value|(((t_DpaaSGTE *)sgte)->offset = ((((t_DpaaSGTE *)sgte)->offset& ~DPAA_SGTE_OFFSET_MASK) | (((val)<< (31-31))& DPAA_SGTE_OFFSET_MASK) ))
end_define

begin_comment
comment|/**< Macro to set SGTE OFFSET field */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__MWERKS__)&& ... */
end_comment

begin_define
define|#
directive|define
name|DPAA_LIODN_DONT_OVERRIDE
value|(-1)
end_define

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of DPAA_grp group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DPAA_EXT_H */
end_comment

end_unit

