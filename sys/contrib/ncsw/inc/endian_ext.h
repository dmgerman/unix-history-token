begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**   @File          endian_ext.h   @Description   Big/little endian swapping routines. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ENDIAN_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__ENDIAN_EXT_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         gen_id  General Drivers Utilities   @Description   General usage API. This API is intended for usage by both the                 internal modules and the user's application.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         endian_id Big/Little-Endian Conversion   @Description   Routines and macros for Big/Little-Endian conversion and                 general byte swapping.                  All routines and macros are expecting unsigned values as                 parameters, but will generate the correct result also for                 signed values. Therefore, signed/unsigned casting is allowed.  @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection    Byte-Swap Macros                  Macros for swapping byte order.   @Cautions      The parameters of these macros are evaluated multiple times.                 For calculated expressions or expressions that contain function                 calls it is recommended to use the byte-swap routines.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Swaps the byte order of a given 16-bit value.   @Param[in]     val - The 16-bit value to swap.   @Return        The byte-swapped value..   @Cautions      The given value is evaluated multiple times by this macro.                 For calculated expressions or expressions that contain function                 calls it is recommended to use the SwapUint16() routine.   @hideinitializer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SWAP_UINT16
parameter_list|(
name|val
parameter_list|)
define|\
value|((uint16_t)((((val)& 0x00FF)<< 8) | (((val)& 0xFF00)>> 8)))
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Swaps the byte order of a given 32-bit value.   @Param[in]     val - The 32-bit value to swap.   @Return        The byte-swapped value..   @Cautions      The given value is evaluated multiple times by this macro.                 For calculated expressions or expressions that contain function                 calls it is recommended to use the SwapUint32() routine.   @hideinitializer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SWAP_UINT32
parameter_list|(
name|val
parameter_list|)
define|\
value|((uint32_t)((((val)& 0x000000FF)<< 24) | \                 (((val)& 0x0000FF00)<<  8) | \                 (((val)& 0x00FF0000)>>  8) | \                 (((val)& 0xFF000000)>> 24)))
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Swaps the byte order of a given 64-bit value.   @Param[in]     val - The 64-bit value to swap.   @Return        The byte-swapped value..   @Cautions      The given value is evaluated multiple times by this macro.                 For calculated expressions or expressions that contain function                 calls it is recommended to use the SwapUint64() routine.   @hideinitializer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SWAP_UINT64
parameter_list|(
name|val
parameter_list|)
define|\
value|((uint64_t)((((val)& 0x00000000000000FFULL)<< 56) | \                 (((val)& 0x000000000000FF00ULL)<< 40) | \                 (((val)& 0x0000000000FF0000ULL)<< 24) | \                 (((val)& 0x00000000FF000000ULL)<<  8) | \                 (((val)& 0x000000FF00000000ULL)>>  8) | \                 (((val)& 0x0000FF0000000000ULL)>> 24) | \                 (((val)& 0x00FF000000000000ULL)>> 40) | \                 (((val)& 0xFF00000000000000ULL)>> 56)))
end_define

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection    Byte-Swap Routines                  Routines for swapping the byte order of a given parameter and                 returning the swapped value.                  These inline routines are safer than the byte-swap macros,                 because they evaluate the parameter expression only once.  @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      SwapUint16   @Description   Returns the byte-swapped value of a given 16-bit value.   @Param[in]     val - The 16-bit value.   @Return        The byte-swapped value of the parameter. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function
specifier|static
name|__inline__
name|uint16_t
name|SwapUint16
parameter_list|(
name|uint16_t
name|val
parameter_list|)
block|{
return|return
call|(
name|uint16_t
call|)
argument_list|(
operator|(
operator|(
name|val
operator|&
literal|0x00FF
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|val
operator|&
literal|0xFF00
operator|)
operator|>>
literal|8
operator|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      SwapUint32   @Description   Returns the byte-swapped value of a given 32-bit value.   @Param[in]     val - The 32-bit value.   @Return        The byte-swapped value of the parameter. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function
specifier|static
name|__inline__
name|uint32_t
name|SwapUint32
parameter_list|(
name|uint32_t
name|val
parameter_list|)
block|{
return|return
call|(
name|uint32_t
call|)
argument_list|(
operator|(
operator|(
name|val
operator|&
literal|0x000000FF
operator|)
operator|<<
literal|24
operator|)
operator||
operator|(
operator|(
name|val
operator|&
literal|0x0000FF00
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|val
operator|&
literal|0x00FF0000
operator|)
operator|>>
literal|8
operator|)
operator||
operator|(
operator|(
name|val
operator|&
literal|0xFF000000
operator|)
operator|>>
literal|24
operator|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      SwapUint64   @Description   Returns the byte-swapped value of a given 64-bit value.   @Param[in]     val - The 64-bit value.   @Return        The byte-swapped value of the parameter. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function
specifier|static
name|__inline__
name|uint64_t
name|SwapUint64
parameter_list|(
name|uint64_t
name|val
parameter_list|)
block|{
return|return
call|(
name|uint64_t
call|)
argument_list|(
operator|(
operator|(
name|val
operator|&
literal|0x00000000000000FFULL
operator|)
operator|<<
literal|56
operator|)
operator||
operator|(
operator|(
name|val
operator|&
literal|0x000000000000FF00ULL
operator|)
operator|<<
literal|40
operator|)
operator||
operator|(
operator|(
name|val
operator|&
literal|0x0000000000FF0000ULL
operator|)
operator|<<
literal|24
operator|)
operator||
operator|(
operator|(
name|val
operator|&
literal|0x00000000FF000000ULL
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|val
operator|&
literal|0x000000FF00000000ULL
operator|)
operator|>>
literal|8
operator|)
operator||
operator|(
operator|(
name|val
operator|&
literal|0x0000FF0000000000ULL
operator|)
operator|>>
literal|24
operator|)
operator||
operator|(
operator|(
name|val
operator|&
literal|0x00FF000000000000ULL
operator|)
operator|>>
literal|40
operator|)
operator||
operator|(
operator|(
name|val
operator|&
literal|0xFF00000000000000ULL
operator|)
operator|>>
literal|56
operator|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection    In-place Byte-Swap-And-Set Routines                  Routines for swapping the byte order of a given variable and                 setting the swapped value back to the same variable.  @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      SwapUint16P   @Description   Swaps the byte order of a given 16-bit variable.   @Param[in]     p_Val - Pointer to the 16-bit variable.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|SwapUint16P
parameter_list|(
name|uint16_t
modifier|*
name|p_Val
parameter_list|)
block|{
operator|*
name|p_Val
operator|=
name|SwapUint16
argument_list|(
operator|*
name|p_Val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      SwapUint32P   @Description   Swaps the byte order of a given 32-bit variable.   @Param[in]     p_Val - Pointer to the 32-bit variable.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|SwapUint32P
parameter_list|(
name|uint32_t
modifier|*
name|p_Val
parameter_list|)
block|{
operator|*
name|p_Val
operator|=
name|SwapUint32
argument_list|(
operator|*
name|p_Val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      SwapUint64P   @Description   Swaps the byte order of a given 64-bit variable.   @Param[in]     p_Val - Pointer to the 64-bit variable.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|SwapUint64P
parameter_list|(
name|uint64_t
modifier|*
name|p_Val
parameter_list|)
block|{
operator|*
name|p_Val
operator|=
name|SwapUint64
argument_list|(
operator|*
name|p_Val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection    Little-Endian Conversion Macros                  These macros convert given parameters to or from Little-Endian                 format. Use these macros when you want to read or write a specific                 Little-Endian value in memory, without a-priori knowing the CPU                 byte order.                  These macros use the byte-swap routines. For conversion of                 constants in initialization structures, you may use the CONST                 versions of these macros (see below), which are using the                 byte-swap macros instead.  @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Converts a given 16-bit value from CPU byte order to                 Little-Endian byte order.   @Param[in]     val - The 16-bit value to convert.   @Return        The converted value.   @hideinitializer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CPU_TO_LE16
parameter_list|(
name|val
parameter_list|)
value|SwapUint16(val)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Converts a given 32-bit value from CPU byte order to                 Little-Endian byte order.   @Param[in]     val - The 32-bit value to convert.   @Return        The converted value.   @hideinitializer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CPU_TO_LE32
parameter_list|(
name|val
parameter_list|)
value|SwapUint32(val)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Converts a given 64-bit value from CPU byte order to                 Little-Endian byte order.   @Param[in]     val - The 64-bit value to convert.   @Return        The converted value.   @hideinitializer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CPU_TO_LE64
parameter_list|(
name|val
parameter_list|)
value|SwapUint64(val)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Converts a given 16-bit value from Little-Endian byte order to                 CPU byte order.   @Param[in]     val - The 16-bit value to convert.   @Return        The converted value.   @hideinitializer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|LE16_TO_CPU
parameter_list|(
name|val
parameter_list|)
value|CPU_TO_LE16(val)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Converts a given 32-bit value from Little-Endian byte order to                 CPU byte order.   @Param[in]     val - The 32-bit value to convert.   @Return        The converted value.   @hideinitializer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|LE32_TO_CPU
parameter_list|(
name|val
parameter_list|)
value|CPU_TO_LE32(val)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Converts a given 64-bit value from Little-Endian byte order to                 CPU byte order.   @Param[in]     val - The 64-bit value to convert.   @Return        The converted value.   @hideinitializer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|LE64_TO_CPU
parameter_list|(
name|val
parameter_list|)
value|CPU_TO_LE64(val)
end_define

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection    Little-Endian Constant Conversion Macros                  These macros convert given constants to or from Little-Endian                 format. Use these macros when you want to read or write a specific                 Little-Endian constant in memory, without a-priori knowing the                 CPU byte order.                  These macros use the byte-swap macros, therefore can be used for                 conversion of constants in initialization structures.   @Cautions      The parameters of these macros are evaluated multiple times.                 For non-constant expressions, use the non-CONST macro versions.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Converts a given 16-bit constant from CPU byte order to                 Little-Endian byte order.   @Param[in]     val - The 16-bit value to convert.   @Return        The converted value.   @hideinitializer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CONST_CPU_TO_LE16
parameter_list|(
name|val
parameter_list|)
value|SWAP_UINT16(val)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Converts a given 32-bit constant from CPU byte order to                 Little-Endian byte order.   @Param[in]     val - The 32-bit value to convert.   @Return        The converted value.   @hideinitializer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CONST_CPU_TO_LE32
parameter_list|(
name|val
parameter_list|)
value|SWAP_UINT32(val)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Converts a given 64-bit constant from CPU byte order to                 Little-Endian byte order.   @Param[in]     val - The 64-bit value to convert.   @Return        The converted value.   @hideinitializer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CONST_CPU_TO_LE64
parameter_list|(
name|val
parameter_list|)
value|SWAP_UINT64(val)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Converts a given 16-bit constant from Little-Endian byte order                 to CPU byte order.   @Param[in]     val - The 16-bit value to convert.   @Return        The converted value.   @hideinitializer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CONST_LE16_TO_CPU
parameter_list|(
name|val
parameter_list|)
value|CONST_CPU_TO_LE16(val)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Converts a given 32-bit constant from Little-Endian byte order                 to CPU byte order.   @Param[in]     val - The 32-bit value to convert.   @Return        The converted value.   @hideinitializer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CONST_LE32_TO_CPU
parameter_list|(
name|val
parameter_list|)
value|CONST_CPU_TO_LE32(val)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Converts a given 64-bit constant from Little-Endian byte order                 to CPU byte order.   @Param[in]     val - The 64-bit value to convert.   @Return        The converted value.   @hideinitializer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CONST_LE64_TO_CPU
parameter_list|(
name|val
parameter_list|)
value|CONST_CPU_TO_LE64(val)
end_define

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of endian_id group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of gen_id group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ENDIAN_EXT_H */
end_comment

end_unit

