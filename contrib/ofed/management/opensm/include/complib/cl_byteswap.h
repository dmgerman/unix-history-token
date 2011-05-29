begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2006 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	provides byteswapping utilities. Basic functions are obtained from  *  platform specific implementations from byteswap_osd.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_BYTESWAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_BYTESWAP_H_
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_byteswap_osd.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__cplusplus */
end_comment

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_function
name|BEGIN_C_DECLS
comment|/****h* Component Library/Byte Swapping * NAME *	Byte Swapping * * DESCRIPTION *	The byte swapping functions and macros allow swapping bytes from network *	byte order to host byte order. * *	All data transmitted between systems should be in network byte order. *	In order to utilize such data, it must be converted to host byte order *	before use. * * SEE ALSO *	Functions: *		cl_ntoh16, cl_hton16, cl_ntoh32, cl_hton32, cl_ntoh64, cl_hton64, *		cl_ntoh * *	Macros: *		CL_NTOH16, CL_HTON16, CL_NTOH32, CL_HTON32, CL_NTOH64, CL_HTON64 *********/
comment|/*  * The byteswap_osd.h provides the following macros.  *		__LITTLE_ENDIAN  *		__BIG_ENDIAN  *		__BYTE_ORDER  *  * If the platform provides byte swapping functions, byteswap_osd.h also  * provides the following macros.  *		ntoh16, hton16  *		ntoh32, hton32  *		ntoh64, hton64  */
ifndef|#
directive|ifndef
name|__BYTE_ORDER
error|#
directive|error
literal|"__BYTE_ORDER macro undefined. Missing in endian.h?"
endif|#
directive|endif
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__LITTLE_ENDIAN
define|#
directive|define
name|CPU_LE
value|1
define|#
directive|define
name|CPU_BE
value|0
else|#
directive|else
define|#
directive|define
name|CPU_LE
value|0
define|#
directive|define
name|CPU_BE
value|1
endif|#
directive|endif
comment|/****d* Component Library: Byte Swapping/CL_NTOH16 * NAME *	CL_NTOH16 * * DESCRIPTION *	The CL_NTOH16 macro converts a 16-bit value from network byte order to *	host byte order.  The CL_NTOH16 macro will cause constant values to be *	swapped by the pre-processor.  For variables, CL_NTOH16 is less efficient *	than the cl_ntoh16 function. * * SYNOPSIS *	CL_NTOH16( val ); * * PARAMETERS *	val *		[in] 16-bit value to swap from network byte order to host byte order. * * RESULT *	Value of val converted to host byte order. * * NOTES *	This macro is analogous to CL_HTON16. * * SEE ALSO *	Byte Swapping, CL_HTON16, CL_NTOH32, CL_NTOH64, *	cl_ntoh16, cl_ntoh32, cl_ntoh64, cl_ntoh *********/
comment|/****d* Component Library: Byte Swapping/CL_HTON16 * NAME *	CL_HTON16 * * DESCRIPTION *	The CL_HTON16 macro converts a 16-bit value from host byte order to *	network byte order.  The CL_HTON16 macro will cause constant values to be *	swapped by the pre-processor.  For variables, CL_HTON16 is less efficient *	than the cl_hton16 function. * * SYNOPSIS *	CL_HTON16( val ); * * PARAMETERS *	val *		[in] 16-bit value to swap from host byte order to network byte order. * * RESULT *	Value of val converted to network byte order. * * NOTES *	This macro is analogous to CL_NTOH16. * * SEE ALSO *	Byte Swapping, CL_NTOH16, CL_HTON32, CL_HTON64, *	cl_hton16, cl_hton32, cl_hton64, cl_ntoh *********/
if|#
directive|if
name|CPU_LE
define|#
directive|define
name|CL_NTOH16
parameter_list|(
name|x
parameter_list|)
value|(uint16_t)(		\ 			(((uint16_t)(x)& 0x00FF)<< 8) |		\ 			(((uint16_t)(x)& 0xFF00)>> 8) )
else|#
directive|else
define|#
directive|define
name|CL_NTOH16
parameter_list|(
name|x
parameter_list|)
value|(x)
endif|#
directive|endif
define|#
directive|define
name|CL_HTON16
value|CL_NTOH16
comment|/****f* Component Library: Byte Swapping/cl_ntoh16 * NAME *	cl_ntoh16 * * DESCRIPTION *	The cl_ntoh16 function converts a 16-bit value from network byte order to *	host byte order. * * SYNOPSIS *	uint16_t *	cl_ntoh16( *		IN	const uint16_t	val ); * * PARAMETERS *	val *		[in] Value to swap from network byte order to host byte order. * * RETURN VALUE *	Value of val converted to host byte order. * * NOTES *	This function is analogous to cl_hton16. * * SEE ALSO *	Byte Swapping, cl_hton16, cl_ntoh32, cl_ntoh64, cl_ntoh *********/
comment|/****f* Component Library: Byte Swapping/cl_hton16 * NAME *	cl_hton16 * * DESCRIPTION *	The cl_hton16 function converts a 16-bit value from host byte order to *	network byte order. * * SYNOPSIS *	uint16_t *	cl_hton16( *		IN	const uint16_t	val ); * * PARAMETERS *	val *		[in] Value to swap from host byte order to network byte order . * * RETURN VALUE *	Value of val converted to network byte order. * * NOTES *	This function is analogous to cl_ntoh16. * * SEE ALSO *	Byte Swapping, cl_ntoh16, cl_hton32, cl_hton64, cl_ntoh *********/
ifndef|#
directive|ifndef
name|cl_ntoh16
define|#
directive|define
name|cl_ntoh16
value|CL_NTOH16
define|#
directive|define
name|cl_hton16
value|CL_HTON16
endif|#
directive|endif
comment|/****d* Component Library: Byte Swapping/CL_NTOH32 * NAME *	CL_NTOH32 * * DESCRIPTION *	The CL_NTOH32 macro converts a 32-bit value from network byte order to *	host byte order.  The CL_NTOH32 macro will cause constant values to be *	swapped by the pre-processor.  For variables, CL_NTOH32 is less efficient *	than the cl_ntoh32 function. * * SYNOPSIS *	CL_NTOH32( val ); * * PARAMETERS *	val *		[in] 32-bit value to swap from network byte order to host byte order. * * RESULT *	Value of val converted to host byte order. * * NOTES *	This macro is analogous to CL_HTON32. * * SEE ALSO *	Byte Swapping, CL_HTON32, CL_NTOH16, CL_NTOH64, *	cl_ntoh16, cl_ntoh32, cl_ntoh64, cl_ntoh *********/
comment|/****d* Component Library: Byte Swapping/CL_HTON32 * NAME *	CL_HTON32 * * DESCRIPTION *	The CL_HTON32 macro converts a 32-bit value from host byte order to *	network byte order.  The CL_HTON32 macro will cause constant values to be *	swapped by the pre-processor.  For variables, CL_HTON32 is less efficient *	than the cl_hton32 function. * * SYNOPSIS *	CL_HTON32( val ); * * PARAMETERS *	val *		[in] 32-bit value to swap from host byte order to network byte order. * * RESULT *	Value of val converted to network byte order. * * NOTES *	This macro is analogous to CL_NTOH32. * * SEE ALSO *	Byte Swapping, CL_NTOH32, CL_HTON16, CL_HTON64, *	cl_hton16, cl_hton32, cl_hton64, cl_ntoh *********/
if|#
directive|if
name|CPU_LE
define|#
directive|define
name|CL_NTOH32
parameter_list|(
name|x
parameter_list|)
value|(uint32_t)(			\ 			(((uint32_t)(x)& 0x000000FF)<< 24) |	\ 			(((uint32_t)(x)& 0x0000FF00)<< 8) |	\ 			(((uint32_t)(x)& 0x00FF0000)>> 8) |	\ 			(((uint32_t)(x)& 0xFF000000)>> 24) )
else|#
directive|else
define|#
directive|define
name|CL_NTOH32
parameter_list|(
name|x
parameter_list|)
value|(x)
endif|#
directive|endif
define|#
directive|define
name|CL_HTON32
value|CL_NTOH32
comment|/****f* Component Library: Byte Swapping/cl_ntoh32 * NAME *	cl_ntoh32 * * DESCRIPTION *	The cl_ntoh32 function converts a 32-bit value from network byte order to *	host byte order. * * SYNOPSIS *	uint32_t *	cl_ntoh32( *		IN	const uint32_t	val ); * * PARAMETERS *	val *		[in] Value to swap from network byte order to host byte order. * * RETURN VALUE *	Value of val converted in host byte order. * * NOTES *	This function is analogous to cl_hton32. * * SEE ALSO *	Byte Swapping, cl_hton32, cl_ntoh16, cl_ntoh64, cl_ntoh *********/
comment|/****f* Component Library: Byte Swapping/cl_hton32 * NAME *	cl_hton32 * * DESCRIPTION *	The cl_hton32 function converts a 32-bit value from host byte order to *	network byte order. * * SYNOPSIS *	uint32_t *	cl_hton32( *		IN	const uint32_t	val ); * * PARAMETERS *	val *		[in] Value to swap from host byte order to network byte order . * * RETURN VALUE *	Value of val converted to network byte order. * * NOTES *	This function is analogous to cl_ntoh32. * * SEE ALSO *	Byte Swapping, cl_ntoh32, cl_hton16, cl_hton64, cl_ntoh *********/
ifndef|#
directive|ifndef
name|cl_ntoh32
define|#
directive|define
name|cl_ntoh32
value|CL_NTOH32
define|#
directive|define
name|cl_hton32
value|CL_HTON32
endif|#
directive|endif
comment|/****d* Component Library: Byte Swapping/CL_NTOH64 * NAME *	CL_NTOH64 * * DESCRIPTION *	The CL_NTOH64 macro converts a 64-bit value from network byte order to *	host byte order.  The CL_NTOH64 macro will cause constant values to be *	swapped by the pre-processor.  For variables, CL_NTOH64 is less efficient *	than the cl_ntoh64 function. * * SYNOPSIS *	CL_NTOH64( val ); * * PARAMETERS *	val *		[in] 64-bit value to swap from network byte order to host byte order. * * RESULT *	Value of val converted to host byte order. * * NOTES *	This macro is analogous to CL_HTON64. * * SEE ALSO *	Byte Swapping, CL_HTON64, CL_NTOH16, CL_NTOH32, *	cl_ntoh16, cl_ntoh32, cl_ntoh64, cl_ntoh *********/
comment|/****d* Component Library: Byte Swapping/CL_HTON64 * NAME *	CL_HTON64 * * DESCRIPTION *	The CL_HTON64 macro converts a 64-bit value from host byte order to *	network byte order.  The CL_HTON64 macro will cause constant values to be *	swapped by the pre-processor.  For variables, CL_HTON64 is less efficient *	than the cl_hton64 function. * * SYNOPSIS *	CL_HTON64( val ); * * PARAMETERS *	val *		[in] 64-bit value to swap from host byte order to network byte order. * * RESULT *	Value of val converted to network byte order. * * NOTES *	This macro is analogous to CL_NTOH64. * * SEE ALSO *	Byte Swapping, CL_NTOH64, CL_HTON16, CL_HTON32, *	cl_hton16, cl_hton32, cl_hton64, cl_ntoh *********/
if|#
directive|if
name|CPU_LE
define|#
directive|define
name|CL_NTOH64
parameter_list|(
name|x
parameter_list|)
value|(uint64_t)(					\ 			(((uint64_t)(x)& 0x00000000000000FFULL)<< 56) |	\ 			(((uint64_t)(x)& 0x000000000000FF00ULL)<< 40) |	\ 			(((uint64_t)(x)& 0x0000000000FF0000ULL)<< 24) |	\ 			(((uint64_t)(x)& 0x00000000FF000000ULL)<< 8 ) |	\ 			(((uint64_t)(x)& 0x000000FF00000000ULL)>> 8 ) |	\ 			(((uint64_t)(x)& 0x0000FF0000000000ULL)>> 24) |	\ 			(((uint64_t)(x)& 0x00FF000000000000ULL)>> 40) |	\ 			(((uint64_t)(x)& 0xFF00000000000000ULL)>> 56) )
else|#
directive|else
define|#
directive|define
name|CL_NTOH64
parameter_list|(
name|x
parameter_list|)
value|(x)
endif|#
directive|endif
define|#
directive|define
name|CL_HTON64
value|CL_NTOH64
comment|/****f* Component Library: Byte Swapping/cl_ntoh64 * NAME *	cl_ntoh64 * * DESCRIPTION *	The cl_ntoh64 function converts a 64-bit value from network byte order to *	host byte order. * * SYNOPSIS *	uint64_t *	cl_ntoh64( *		IN	const uint64_t	val ); * * PARAMETERS *	val *		[in] Value to swap from network byte order to host byte order. * * RETURN VALUE *	Value of val converted in host byte order. * * NOTES *	This function is analogous to cl_hton64. * * SEE ALSO *	Byte Swapping, cl_hton64, cl_ntoh16, cl_ntoh32, cl_ntoh *********/
comment|/****f* Component Library: Byte Swapping/cl_hton64 * NAME *	cl_hton64 * * DESCRIPTION *	The cl_hton64 function converts a 64-bit value from host byte order to *	network byte order. * * SYNOPSIS *	uint64_t *	cl_hton64( *		IN	const uint64_t	val ); * * PARAMETERS *	val *		[in] Value to swap from host byte order to network byte order . * * RETURN VALUE *	Value of val converted to network byte order. * * NOTES *	This function is analogous to cl_ntoh64. * * SEE ALSO *	Byte Swapping, cl_ntoh64, cl_hton16, cl_hton32, cl_ntoh *********/
ifndef|#
directive|ifndef
name|cl_ntoh64
define|#
directive|define
name|cl_ntoh64
value|CL_NTOH64
define|#
directive|define
name|cl_hton64
value|CL_HTON64
endif|#
directive|endif
comment|/****f* Component Library: Byte Swapping/cl_ntoh * NAME *	cl_ntoh * * DESCRIPTION *	The cl_ntoh function converts a value from network byte order to *	host byte order. * * SYNOPSIS */
specifier|static
specifier|inline
name|void
name|cl_ntoh
parameter_list|(
name|OUT
name|char
modifier|*
specifier|const
name|p_dest
parameter_list|,
name|IN
specifier|const
name|char
modifier|*
specifier|const
name|p_src
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|size
parameter_list|)
block|{
if|#
directive|if
name|CPU_LE
name|uint8_t
name|i
decl_stmt|;
name|char
name|temp
decl_stmt|;
if|if
condition|(
name|p_src
operator|==
name|p_dest
condition|)
block|{
comment|/* Swap in place if source and destination are the same. */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|size
operator|/
literal|2
condition|;
name|i
operator|++
control|)
block|{
name|temp
operator|=
name|p_dest
index|[
name|i
index|]
expr_stmt|;
name|p_dest
index|[
name|i
index|]
operator|=
name|p_src
index|[
name|size
operator|-
literal|1
operator|-
name|i
index|]
expr_stmt|;
name|p_dest
index|[
name|size
operator|-
literal|1
operator|-
name|i
index|]
operator|=
name|temp
expr_stmt|;
block|}
block|}
else|else
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
name|i
operator|++
control|)
name|p_dest
index|[
name|i
index|]
operator|=
name|p_src
index|[
name|size
operator|-
literal|1
operator|-
name|i
index|]
expr_stmt|;
block|}
else|#
directive|else
comment|/* 	 * If the source and destination are not the same, copy the source to 	 * the destination. 	 */
if|if
condition|(
name|p_src
operator|!=
name|p_dest
condition|)
name|memcpy
argument_list|(
name|p_dest
argument_list|,
name|p_src
argument_list|,
name|size
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_dest *		[in] Pointer to a byte array to contain the converted value of p_src. * *	p_src *		[in] Pointer to a byte array to be converted from network byte *		ordering. * *	size *		[in] Number of bytes to swap.p_dest * * RETURN VALUE *	This function does not return a value. * * NOTES *	cl_ntoh can perform in place swapping if both p_src and p_dest point to *	the same buffer. * * SEE ALSO *	Byte Swapping, cl_ntoh16, cl_ntoh32, cl_ntoh64 *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_BYTESWAP_H_ */
end_comment

end_unit

