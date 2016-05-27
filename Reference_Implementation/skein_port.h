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
comment|/******************************************************************* ** ** Platform-specific definitions for Skein hash function. ** ** Source code author: Doug Whiting, 2008. ** ** This algorithm and source code is released to the public domain. ** ** Many thanks to Brian Gladman for his portable header files, which ** have been modified slightly here, to handle a few more platforms. ** ** To port Skein to an "unsupported" platform, change the definitions ** in this file appropriately. **  ********************************************************************/
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

begin_comment
comment|/*  * Skein is "natively" little-endian (unlike SHA-xxx), for optimal  * performance on x86 CPUs.  The Skein code requires the following  * definitions for dealing with endianness:  *  *    Skein_Put64_LSB_First  *    Skein_Get64_LSB_First  *    Skein_Swap64  *  * In the reference code, these functions are implemented in a  * very portable (and thus slow) fashion, for clarity. See the file  * "skein_port.h" in the Optimized_Code directory for ways to make  * these functions fast(er) on x86 platforms.  */
end_comment

begin_function_decl
name|u64b_t
name|Skein_Swap64
parameter_list|(
name|u64b_t
name|w64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
comment|/* ifndef _SKEIN_PORT_H_ */
end_comment

end_unit

