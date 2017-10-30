begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DDR_SDT_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__DDR_SDT_EXT_H
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         ddr_Generic_Resources   @Description   ddr generic functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   SPD maximum size */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SPD_MAX_SIZE
value|256
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   DDR types select */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_DdrType
block|{
name|e_DDR_DDR1
block|,
name|e_DDR_DDR2
block|,
name|e_DDR_DDR3
block|,
name|e_DDR_DDR3L
block|,
name|e_DDR_DDR4
block|}
name|e_DdrType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   DDR Mode. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_DdrMode
block|{
name|e_DDR_BUS_WIDTH_32BIT
block|,
name|e_DDR_BUS_WIDTH_64BIT
block|}
name|e_DdrMode
typedef|;
end_typedef

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of ddr_Generic_Resources group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DDR_SDT_EXT_H */
end_comment

end_unit

