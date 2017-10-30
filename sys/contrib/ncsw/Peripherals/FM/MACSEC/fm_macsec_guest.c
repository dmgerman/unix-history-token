begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2015 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          fm_macsec.c   @Description   FM MACSEC driver routines implementation. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

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

begin_include
include|#
directive|include
file|"xx_ext.h"
end_include

begin_include
include|#
directive|include
file|"string_ext.h"
end_include

begin_include
include|#
directive|include
file|"sprint_ext.h"
end_include

begin_include
include|#
directive|include
file|"debug_ext.h"
end_include

begin_include
include|#
directive|include
file|"fm_macsec.h"
end_include

begin_comment
comment|/****************************************/
end_comment

begin_comment
comment|/*       static functions               */
end_comment

begin_comment
comment|/****************************************/
end_comment

begin_comment
comment|/****************************************/
end_comment

begin_comment
comment|/*       API Init unit functions        */
end_comment

begin_comment
comment|/****************************************/
end_comment

begin_function
name|t_Handle
name|FM_MACSEC_GUEST_Config
parameter_list|(
name|t_FmMacsecParams
modifier|*
name|p_FmMacsecParam
parameter_list|)
block|{
name|UNUSED
argument_list|(
name|p_FmMacsecParam
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

end_unit

