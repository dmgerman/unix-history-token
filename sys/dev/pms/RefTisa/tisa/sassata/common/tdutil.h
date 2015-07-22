begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \file  *  * The file defines utilities for SAS/SATA TD layer  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TDUTIL_H__
end_ifndef

begin_define
define|#
directive|define
name|__TDUTIL_H__
end_define

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/api/sa.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/tidefs.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/titypes.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/tiapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/common/tdlist.h>
end_include

begin_define
define|#
directive|define
name|HEXDIGIT2CHAR
parameter_list|(
name|x
parameter_list|)
value|(((x)< 10) ? ('0' + (x)) : ('A' + ((x) - 10)))
end_define

begin_comment
comment|/***************************************************************************** *! \brief tdDecimal2String * *  Purpose:  This function converts a given number into a decimal string. *             *  \param s:                  string to be generated *  \param num:                number to be converted * *  \return None * *  \note - string s should be large enough to store decimal string of *        num and a '\0' character * *****************************************************************************/
end_comment

begin_function_decl
name|void
name|tdDecimal2String
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|bit32
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tdHexToString
parameter_list|(
name|char
modifier|*
name|String
parameter_list|,
name|bit32
name|Value1
parameter_list|,
name|bit32
name|Value2
parameter_list|,
name|bit32
name|Strlength
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bit8
name|tdStr2Bit8
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bit32
name|tdStr2ALPA
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tdStr2WWN
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|bit8
modifier|*
name|NodeName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tdWWN2Str
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|bit8
modifier|*
name|NodeName
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/***************************************************************************** *! \brief tdNextPowerOf2 * *  Purpose:  This function is called to calculate the next power of 2 *            value of given value. *             * *  \param  Value:             The value for which next power of 2 is requested * *  \return: The next power of 2 value of given Value * *****************************************************************************/
end_comment

begin_function_decl
name|bit32
name|tdNextPowerOf2
parameter_list|(
name|bit32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|osGLOBAL
name|agBOOLEAN
name|tdListElementOnList
parameter_list|(
name|tdList_t
modifier|*
name|toFindHdr
parameter_list|,
name|tdList_t
modifier|*
name|listHdr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TDUTIL_H__ */
end_comment

end_unit

