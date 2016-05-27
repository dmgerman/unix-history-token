begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_SKEIN_PORT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SKEIN_PORT_H_
end_define

begin_comment
comment|/******************************************************************* ** ** Platform-specific definitions for Skein hash function. ** ** Source code author: Doug Whiting, 2008. ** ** This algorithm and source code is released to the public domain. ** ** Many thanks to Brian Gladman for his portable header files. ** ** To port Skein to an "unsupported" platform, change the definitions ** in this file appropriately. **  ********************************************************************/
end_comment

begin_include
include|#
directive|include
file|"brg_types.h"
end_include

begin_comment
comment|/* get integer type definitions */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint_t
typedef|;
end_typedef

begin_comment
comment|/* native unsigned integer */
end_comment

begin_typedef
typedef|typedef
name|uint_8t
name|u08b_t
typedef|;
end_typedef

begin_comment
comment|/*  8-bit unsigned integer */
end_comment

begin_typedef
typedef|typedef
name|uint_64t
name|u64b_t
typedef|;
end_typedef

begin_comment
comment|/* 64-bit unsigned integer */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RotL_64
end_ifndef

begin_define
define|#
directive|define
name|RotL_64
parameter_list|(
name|x
parameter_list|,
name|N
parameter_list|)
value|(((x)<< (N)) | ((x)>> (64-(N))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Skein is "natively" little-endian (unlike SHA-xxx), for optimal  * performance on x86 CPUs.  The Skein code requires the following  * definitions for dealing with endianness:  *  *    SKEIN_NEED_SWAP:  0 for little-endian, 1 for big-endian  *    Skein_Put64_LSB_First  *    Skein_Get64_LSB_First  *    Skein_Swap64  *  * If SKEIN_NEED_SWAP is defined at compile time, it is used here  * along with the portable versions of Put64/Get64/Swap64, which   * are slow in general.  *  * Otherwise, an "auto-detect" of endianness is attempted below.  * If the default handling doesn't work well, the user may insert  * platform-specific code instead (e.g., for big-endian CPUs).  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SKEIN_NEED_SWAP
end_ifndef

begin_comment
comment|/* compile-time "override" for endianness? */
end_comment

begin_include
include|#
directive|include
file|"brg_endian.h"
end_include

begin_comment
comment|/* get endianness selection */
end_comment

begin_if
if|#
directive|if
name|PLATFORM_BYTE_ORDER
operator|==
name|IS_BIG_ENDIAN
end_if

begin_comment
comment|/* here for big-endian CPUs */
end_comment

begin_define
define|#
directive|define
name|SKEIN_NEED_SWAP
value|(1)
end_define

begin_elif
elif|#
directive|elif
name|PLATFORM_BYTE_ORDER
operator|==
name|IS_LITTLE_ENDIAN
end_elif

begin_comment
comment|/* here for x86 and x86-64 CPUs (and other detected little-endian CPUs) */
end_comment

begin_define
define|#
directive|define
name|SKEIN_NEED_SWAP
value|(0)
end_define

begin_if
if|#
directive|if
name|PLATFORM_MUST_ALIGN
operator|==
literal|0
end_if

begin_comment
comment|/* ok to use "fast" versions? */
end_comment

begin_define
define|#
directive|define
name|Skein_Put64_LSB_First
parameter_list|(
name|dst08
parameter_list|,
name|src64
parameter_list|,
name|bCnt
parameter_list|)
value|memcpy(dst08,src64,bCnt)
end_define

begin_define
define|#
directive|define
name|Skein_Get64_LSB_First
parameter_list|(
name|dst64
parameter_list|,
name|src08
parameter_list|,
name|wCnt
parameter_list|)
value|memcpy(dst64,src08,8*(wCnt))
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
literal|"Skein needs endianness setting!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef SKEIN_NEED_SWAP */
end_comment

begin_comment
comment|/*  ******************************************************************  *      Provide any definitions still needed.  ******************************************************************  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|Skein_Swap64
end_ifndef

begin_comment
comment|/* swap for big-endian, nop for little-endian */
end_comment

begin_if
if|#
directive|if
name|SKEIN_NEED_SWAP
end_if

begin_define
define|#
directive|define
name|Skein_Swap64
parameter_list|(
name|w64
parameter_list|)
define|\
value|( (( ((u64b_t)(w64))& 0xFF)<< 56) |   \     (((((u64b_t)(w64))>> 8)& 0xFF)<< 48) |   \     (((((u64b_t)(w64))>>16)& 0xFF)<< 40) |   \     (((((u64b_t)(w64))>>24)& 0xFF)<< 32) |   \     (((((u64b_t)(w64))>>32)& 0xFF)<< 24) |   \     (((((u64b_t)(w64))>>40)& 0xFF)<< 16) |   \     (((((u64b_t)(w64))>>48)& 0xFF)<<  8) |   \     (((((u64b_t)(w64))>>56)& 0xFF)      ) )
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Skein_Swap64
parameter_list|(
name|w64
parameter_list|)
value|(w64)
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
comment|/* ifndef Skein_Swap64 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|Skein_Put64_LSB_First
end_ifndef

begin_function
name|void
name|Skein_Put64_LSB_First
parameter_list|(
name|u08b_t
modifier|*
name|dst
parameter_list|,
specifier|const
name|u64b_t
modifier|*
name|src
parameter_list|,
name|size_t
name|bCnt
parameter_list|)
ifdef|#
directive|ifdef
name|SKEIN_PORT_CODE
comment|/* instantiate the function code here? */
block|{
comment|/* this version is fully portable (big-endian or little-endian), but slow */
name|size_t
name|n
decl_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|bCnt
condition|;
name|n
operator|++
control|)
name|dst
index|[
name|n
index|]
operator|=
call|(
name|u08b_t
call|)
argument_list|(
name|src
index|[
name|n
operator|>>
literal|3
index|]
operator|>>
operator|(
literal|8
operator|*
operator|(
name|n
operator|&
literal|7
operator|)
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* output only the function prototype */
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
comment|/* ifndef Skein_Put64_LSB_First */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|Skein_Get64_LSB_First
end_ifndef

begin_function
name|void
name|Skein_Get64_LSB_First
parameter_list|(
name|u64b_t
modifier|*
name|dst
parameter_list|,
specifier|const
name|u08b_t
modifier|*
name|src
parameter_list|,
name|size_t
name|wCnt
parameter_list|)
ifdef|#
directive|ifdef
name|SKEIN_PORT_CODE
comment|/* instantiate the function code here? */
block|{
comment|/* this version is fully portable (big-endian or little-endian), but slow */
name|size_t
name|n
decl_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
literal|8
operator|*
name|wCnt
condition|;
name|n
operator|+=
literal|8
control|)
name|dst
index|[
name|n
operator|/
literal|8
index|]
operator|=
operator|(
operator|(
operator|(
name|u64b_t
operator|)
name|src
index|[
name|n
index|]
operator|)
operator|)
operator|+
operator|(
operator|(
operator|(
name|u64b_t
operator|)
name|src
index|[
name|n
operator|+
literal|1
index|]
operator|)
operator|<<
literal|8
operator|)
operator|+
operator|(
operator|(
operator|(
name|u64b_t
operator|)
name|src
index|[
name|n
operator|+
literal|2
index|]
operator|)
operator|<<
literal|16
operator|)
operator|+
operator|(
operator|(
operator|(
name|u64b_t
operator|)
name|src
index|[
name|n
operator|+
literal|3
index|]
operator|)
operator|<<
literal|24
operator|)
operator|+
operator|(
operator|(
operator|(
name|u64b_t
operator|)
name|src
index|[
name|n
operator|+
literal|4
index|]
operator|)
operator|<<
literal|32
operator|)
operator|+
operator|(
operator|(
operator|(
name|u64b_t
operator|)
name|src
index|[
name|n
operator|+
literal|5
index|]
operator|)
operator|<<
literal|40
operator|)
operator|+
operator|(
operator|(
operator|(
name|u64b_t
operator|)
name|src
index|[
name|n
operator|+
literal|6
index|]
operator|)
operator|<<
literal|48
operator|)
operator|+
operator|(
operator|(
operator|(
name|u64b_t
operator|)
name|src
index|[
name|n
operator|+
literal|7
index|]
operator|)
operator|<<
literal|56
operator|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* output only the function prototype */
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
comment|/* ifndef Skein_Get64_LSB_First */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef _SKEIN_PORT_H_ */
end_comment

end_unit

