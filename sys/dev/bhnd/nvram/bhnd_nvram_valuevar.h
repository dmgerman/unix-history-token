begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_VALUEVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_VALUEVAR_H_
end_define

begin_include
include|#
directive|include
file|"bhnd_nvram_value.h"
end_include

begin_function_decl
name|int
name|bhnd_nvram_val_generic_encode
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
name|bhnd_nvram_val_generic_encode_elem
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
specifier|const
name|void
modifier|*
name|bhnd_nvram_val_generic_next
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

begin_comment
comment|/**  * Filter input data prior to initialization.  *   * This may be used to permit direct initialization from data types other than  * the default native_type defined by @p fmt.  *  * @param[in,out]	fmt	Indirect pointer to the NVRAM value format. If  *				modified by the caller, initialization will be  *				restarted and performed using the provided  *				format instance.  * @param		inp	Input data.  * @param		ilen	Input data length.  * @param		itype	Input data type.  *  * @retval 0		If initialization from @p inp is supported.  * @retval EFTYPE	If initialization from @p inp is unsupported.  * @retval EFAULT	if @p ilen is not correctly aligned for elements of  *			@p itype.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_val_op_filter
function_decl|)
parameter_list|(
specifier|const
name|bhnd_nvram_val_fmt_t
modifier|*
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
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_val_encode() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_val_op_encode
function_decl|)
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
end_typedef

begin_comment
comment|/** @see bhnd_nvram_val_encode_elem() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_val_op_encode_elem
function_decl|)
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
end_typedef

begin_comment
comment|/** @see bhnd_nvram_val_next() */
end_comment

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
function_decl|(
name|bhnd_nvram_val_op_next
function_decl|)
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
end_typedef

begin_comment
comment|/** @see bhnd_nvram_val_nelem() */
end_comment

begin_typedef
typedef|typedef
name|size_t
function_decl|(
name|bhnd_nvram_val_op_nelem
function_decl|)
parameter_list|(
name|bhnd_nvram_val_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * NVRAM value format.  *   * Provides a set of callbacks to support defining custom parsing  * and encoding/conversion behavior when representing values as  * instances of bhnd_nvram_val.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_val_fmt
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< type name */
name|bhnd_nvram_type
name|native_type
decl_stmt|;
comment|/**< native value representation */
name|bhnd_nvram_val_op_filter
modifier|*
name|op_filter
decl_stmt|;
name|bhnd_nvram_val_op_encode
modifier|*
name|op_encode
decl_stmt|;
name|bhnd_nvram_val_op_encode_elem
modifier|*
name|op_encode_elem
decl_stmt|;
name|bhnd_nvram_val_op_nelem
modifier|*
name|op_nelem
decl_stmt|;
name|bhnd_nvram_val_op_next
modifier|*
name|op_next
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_VALUEVAR_H_ */
end_comment

end_unit

