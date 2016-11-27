begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_VALUE_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_VALUE_H_
end_define

begin_include
include|#
directive|include
file|<sys/refcount.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_include
include|#
directive|include
file|"bhnd_nvram.h"
end_include

begin_typedef
typedef|typedef
name|struct
name|bhnd_nvram_val_fmt
name|bhnd_nvram_val_fmt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bhnd_nvram_val
name|bhnd_nvram_val_t
typedef|;
end_typedef

begin_function_decl
name|int
name|bhnd_nvram_val_init
parameter_list|(
name|bhnd_nvram_val_t
modifier|*
name|value
parameter_list|,
specifier|const
name|bhnd_nvram_val_fmt_t
modifier|*
name|fmt
parameter_list|,
specifier|const
name|void
modifier|*
name|inp
parameter_list|,
name|size_t
name|ilen
parameter_list|,
name|bhnd_nvram_type
name|itype
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_val_new
parameter_list|(
name|bhnd_nvram_val_t
modifier|*
modifier|*
name|value
parameter_list|,
specifier|const
name|bhnd_nvram_val_fmt_t
modifier|*
name|fmt
parameter_list|,
specifier|const
name|void
modifier|*
name|inp
parameter_list|,
name|size_t
name|ilen
parameter_list|,
name|bhnd_nvram_type
name|itype
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_nvram_val_t
modifier|*
name|bhnd_nvram_val_copy
parameter_list|(
name|bhnd_nvram_val_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_nvram_val_release
parameter_list|(
name|bhnd_nvram_val_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_val_encode
parameter_list|(
name|bhnd_nvram_val_t
modifier|*
name|value
parameter_list|,
name|void
modifier|*
name|outp
parameter_list|,
name|size_t
modifier|*
name|olen
parameter_list|,
name|bhnd_nvram_type
name|otype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_val_encode_elem
parameter_list|(
name|bhnd_nvram_val_t
modifier|*
name|value
parameter_list|,
specifier|const
name|void
modifier|*
name|inp
parameter_list|,
name|size_t
name|ilen
parameter_list|,
name|void
modifier|*
name|outp
parameter_list|,
name|size_t
modifier|*
name|olen
parameter_list|,
name|bhnd_nvram_type
name|otype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_val_printf
parameter_list|(
name|bhnd_nvram_val_t
modifier|*
name|value
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|char
modifier|*
name|outp
parameter_list|,
name|size_t
modifier|*
name|olen
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_val_vprintf
parameter_list|(
name|bhnd_nvram_val_t
modifier|*
name|value
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|char
modifier|*
name|outp
parameter_list|,
name|size_t
modifier|*
name|olen
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|void
modifier|*
name|bhnd_nvram_val_bytes
parameter_list|(
name|bhnd_nvram_val_t
modifier|*
name|value
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|,
name|bhnd_nvram_type
modifier|*
name|itype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_nvram_type
name|bhnd_nvram_val_elem_type
parameter_list|(
name|bhnd_nvram_val_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|void
modifier|*
name|bhnd_nvram_val_next
parameter_list|(
name|bhnd_nvram_val_t
modifier|*
name|value
parameter_list|,
specifier|const
name|void
modifier|*
name|prev
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|bhnd_nvram_val_nelem
parameter_list|(
name|bhnd_nvram_val_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * NVRAM value flags  */
end_comment

begin_enum
enum|enum
block|{
comment|/** 	 * Do not allocate additional space for value data; all data must be 	 * represented inline within the value structure (default). 	 */
name|BHND_NVRAM_VAL_FIXED
init|=
operator|(
literal|0
operator|<<
literal|0
operator|)
block|,
comment|/** 	 * Automatically allocate additional space for value data if it cannot 	 * be represented within the value structure. 	 */
name|BHND_NVRAM_VAL_DYNAMIC
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|/**  	 * Copy the value data upon initialization. (default). 	 */
name|BHND_NVRAM_VAL_COPY_DATA
init|=
operator|(
literal|0
operator|<<
literal|1
operator|)
block|,
comment|/** 	 * Do not perform an initial copy of the value data; the data must 	 * remain valid for the lifetime of the NVRAM value. 	 *  	 * Value data will still be copied if the value itself is copied to the 	 * heap. 	 */
name|BHND_NVRAM_VAL_BORROW_DATA
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/** 	 * Do not copy the value data when copying the value to the heap; the 	 * vlaue data is assumed to be statically allocated and must remain 	 * valid for the lifetime of the process. 	 *  	 * Implies BHND_NVRAM_VAL_BORROW_DATA. 	 */
name|BHND_NVRAM_VAL_STATIC_DATA
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * @internal  *  * NVRAM value storage types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/** 	 * The value structure has an automatic or static storage duration 	 * (e.g. it is stack allocated, or is otherwise externally managed), 	 * and no destructors will be run prior to deallocation of the value. 	 * 	 * When performing copy/retain, the existing structure must be copied 	 * to a new heap allocation. 	 */
name|BHND_NVRAM_VAL_STORAGE_AUTO
init|=
literal|0
block|,
comment|/** 	 * The value structure was heap allocated and is fully managed by the 	 * the NVRAM value API. 	 * 	 * When performing copy/retain, the existing structure may be retained 	 * as-is. 	 */
name|BHND_NVRAM_VAL_STORAGE_DYNAMIC
init|=
literal|2
block|, }
name|bhnd_nvram_val_storage_t
typedef|;
end_typedef

begin_comment
comment|/**  * @internal  *  * NVRAM data storage types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/** Value has no active representation. This is the default for 	*  zero-initialized value structures. */
name|BHND_NVRAM_VAL_DATA_NONE
init|=
literal|0
block|,
comment|/** Value data is represented inline */
name|BHND_NVRAM_VAL_DATA_INLINE
init|=
literal|1
block|,
comment|/** 	* Value represented by an external reference to data with a static 	* storage location. The data need not be copied if copying the value. 	*/
name|BHND_NVRAM_VAL_DATA_EXT_STATIC
init|=
literal|2
block|,
comment|/** 	* Value represented by weak external reference, which must be copied 	* if copying the value */
name|BHND_NVRAM_VAL_DATA_EXT_WEAK
init|=
literal|3
block|,
comment|/** 	* Value represented by an external reference that must be deallocated 	* when deallocating the value 	*/
name|BHND_NVRAM_VAL_DATA_EXT_ALLOC
init|=
literal|4
block|, }
name|bhnd_nvram_val_data_storage_t
typedef|;
end_typedef

begin_comment
comment|/**  * NVRAM value  */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_val
block|{
specifier|volatile
name|u_int
name|refs
decl_stmt|;
comment|/**< reference count */
name|bhnd_nvram_val_storage_t
name|val_storage
decl_stmt|;
comment|/**< value structure storage */
specifier|const
name|bhnd_nvram_val_fmt_t
modifier|*
name|fmt
decl_stmt|;
comment|/**< value format, or NULL for default behavior */
name|bhnd_nvram_val_data_storage_t
name|data_storage
decl_stmt|;
comment|/**< data storage */
name|bhnd_nvram_type
name|data_type
decl_stmt|;
comment|/**< data type */
name|size_t
name|data_len
decl_stmt|;
comment|/**< data size */
comment|/** data representation */
union|union
block|{
name|uint8_t
name|u8
index|[
literal|8
index|]
decl_stmt|;
comment|/**< 8-bit unsigned data */
name|uint16_t
name|u16
index|[
literal|4
index|]
decl_stmt|;
comment|/**< 16-bit unsigned data */
name|uint32_t
name|u32
index|[
literal|2
index|]
decl_stmt|;
comment|/**< 32-bit unsigned data */
name|uint32_t
name|u64
index|[
literal|1
index|]
decl_stmt|;
comment|/**< 64-bit unsigned data */
name|int8_t
name|i8
index|[
literal|8
index|]
decl_stmt|;
comment|/**< 8-bit signed data */
name|int16_t
name|i16
index|[
literal|4
index|]
decl_stmt|;
comment|/**< 16-bit signed data */
name|int32_t
name|i32
index|[
literal|2
index|]
decl_stmt|;
comment|/**< 32-bit signed data */
name|int64_t
name|i64
index|[
literal|1
index|]
decl_stmt|;
comment|/**< 64-bit signed data */
name|unsigned
name|char
name|ch
index|[
literal|8
index|]
decl_stmt|;
comment|/**< 8-bit character data */
specifier|const
name|void
modifier|*
name|ptr
decl_stmt|;
comment|/**< external data */
block|}
name|data
union|;
block|}
struct|;
end_struct

begin_comment
comment|/** Declare a bhnd_nvram_val_fmt with name @p _n */
end_comment

begin_define
define|#
directive|define
name|BHND_NVRAM_VAL_TYPE_DECL
parameter_list|(
name|_n
parameter_list|)
define|\
value|extern const bhnd_nvram_val_fmt_t bhnd_nvram_val_ ## _n ## _fmt;
end_define

begin_expr_stmt
name|BHND_NVRAM_VAL_TYPE_DECL
argument_list|(
name|bcm_decimal
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BHND_NVRAM_VAL_TYPE_DECL
argument_list|(
name|bcm_hex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BHND_NVRAM_VAL_TYPE_DECL
argument_list|(
name|bcm_leddc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BHND_NVRAM_VAL_TYPE_DECL
argument_list|(
name|bcm_macaddr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BHND_NVRAM_VAL_TYPE_DECL
argument_list|(
name|bcm_string
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_VALUE_H_ */
end_comment

end_unit

