begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

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
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_TYPES_H_
end_ifndef

begin_comment
comment|/* Avoid redefining this typedef */
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

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|u_int8_t
name|u08b_t
typedef|;
end_typedef

begin_comment
comment|/*  8-bit unsigned integer */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|uint_32t
typedef|;
end_typedef

begin_comment
comment|/* 32-bit unsigned integer */
end_comment

begin_typedef
typedef|typedef
name|u_int64_t
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

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * Skein is "natively" little-endian (unlike SHA-xxx), for optimal  * performance on x86 CPUs.  The Skein code requires the following  * definitions for dealing with endianness:  *  *    SKEIN_NEED_SWAP:  0 for little-endian, 1 for big-endian  *    Skein_Put64_LSB_First  *    Skein_Get64_LSB_First  *    Skein_Swap64  *  * If SKEIN_NEED_SWAP is defined at compile time, it is used here  * along with the portable versions of Put64/Get64/Swap64, which   * are slow in general.  *  * Otherwise, an "auto-detect" of endianness is attempted below.  * If the default handling doesn't work well, the user may insert  * platform-specific code instead (e.g., for big-endian CPUs).  *  */
ifndef|#
directive|ifndef
name|SKEIN_NEED_SWAP
comment|/* compile-time "override" for endianness? */
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
comment|/* here for big-endian CPUs */
define|#
directive|define
name|SKEIN_NEED_SWAP
value|(1)
ifdef|#
directive|ifdef
name|SKEIN_PORT_CODE
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
function_decl|;
end_function_decl

begin_function_decl
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
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifdef SKEIN_PORT_CODE */
end_comment

begin_elif
elif|#
directive|elif
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
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
value|bswap64(w64)
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
operator|/
literal|8
condition|;
name|n
operator|++
control|)
name|le64enc
argument_list|(
name|dst
operator|+
name|n
operator|*
literal|8
argument_list|,
name|src
index|[
name|n
index|]
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
name|wCnt
condition|;
name|n
operator|++
control|)
name|dst
index|[
name|n
index|]
operator|=
name|le64dec
argument_list|(
name|src
operator|+
name|n
operator|*
literal|8
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
comment|/* ifndef Skein_Get64_LSB_First */
end_comment

begin_comment
comment|/* Start FreeBSD libmd shims */
end_comment

begin_comment
comment|/* Ensure libmd symbols do not clash with libcrypto */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SKEIN256_Init
end_ifndef

begin_define
define|#
directive|define
name|SKEIN256_Init
value|_libmd_SKEIN256_Init
end_define

begin_define
define|#
directive|define
name|SKEIN512_Init
value|_libmd_SKEIN512_Init
end_define

begin_define
define|#
directive|define
name|SKEIN1024_Init
value|_libmd_SKEIN1024_Init
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SKEIN256_Update
end_ifndef

begin_define
define|#
directive|define
name|SKEIN256_Update
value|_libmd_SKEIN256_Update
end_define

begin_define
define|#
directive|define
name|SKEIN512_Update
value|_libmd_SKEIN512_Update
end_define

begin_define
define|#
directive|define
name|SKEIN1024_Update
value|_libmd_SKEIN1024_Update
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SKEIN256_Final
end_ifndef

begin_define
define|#
directive|define
name|SKEIN256_Final
value|_libmd_SKEIN256_Final
end_define

begin_define
define|#
directive|define
name|SKEIN512_Final
value|_libmd_SKEIN512_Final
end_define

begin_define
define|#
directive|define
name|SKEIN1024_Final
value|_libmd_SKEIN1024_Final
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SKEIN256_End
end_ifndef

begin_define
define|#
directive|define
name|SKEIN256_End
value|_libmd_SKEIN256_End
end_define

begin_define
define|#
directive|define
name|SKEIN512_End
value|_libmd_SKEIN512_End
end_define

begin_define
define|#
directive|define
name|SKEIN1024_End
value|_libmd_SKEIN1024_End
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SKEIN256_Fd
end_ifndef

begin_define
define|#
directive|define
name|SKEIN256_Fd
value|_libmd_SKEIN256_Fd
end_define

begin_define
define|#
directive|define
name|SKEIN512_Fd
value|_libmd_SKEIN512_Fd
end_define

begin_define
define|#
directive|define
name|SKEIN1024_Fd
value|_libmd_SKEIN1024_Fd
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SKEIN256_FdChunk
end_ifndef

begin_define
define|#
directive|define
name|SKEIN256_FdChunk
value|_libmd_SKEIN256_FdChunk
end_define

begin_define
define|#
directive|define
name|SKEIN512_FdChunk
value|_libmd_SKEIN512_FdChunk
end_define

begin_define
define|#
directive|define
name|SKEIN1024_FdChunk
value|_libmd_SKEIN1024_FdChunk
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SKEIN256_File
end_ifndef

begin_define
define|#
directive|define
name|SKEIN256_File
value|_libmd_SKEIN256_File
end_define

begin_define
define|#
directive|define
name|SKEIN512_File
value|_libmd_SKEIN512_File
end_define

begin_define
define|#
directive|define
name|SKEIN1024_File
value|_libmd_SKEIN1024_File
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SKEIN256_FileChunk
end_ifndef

begin_define
define|#
directive|define
name|SKEIN256_FileChunk
value|_libmd_SKEIN256_FileChunk
end_define

begin_define
define|#
directive|define
name|SKEIN512_FileChunk
value|_libmd_SKEIN512_FileChunk
end_define

begin_define
define|#
directive|define
name|SKEIN1024_FileChunk
value|_libmd_SKEIN1024_FileChunk
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SKEIN256_Data
end_ifndef

begin_define
define|#
directive|define
name|SKEIN256_Data
value|_libmd_SKEIN256_Data
end_define

begin_define
define|#
directive|define
name|SKEIN512_Data
value|_libmd_SKEIN512_Data
end_define

begin_define
define|#
directive|define
name|SKEIN1024_Data
value|_libmd_SKEIN1024_Data
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef _SKEIN_PORT_H_ */
end_comment

end_unit

