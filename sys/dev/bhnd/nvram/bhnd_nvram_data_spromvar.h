begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_SPROMVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_SPROMVAR_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/bitstring.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<bitstring.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"bhnd_nvram_private.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram_datavar.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram_io.h"
end_include

begin_comment
comment|/** The maximum number of array elements encoded in a single SPROM variable */
end_comment

begin_define
define|#
directive|define
name|BHND_SPROM_ARRAY_MAXLEN
value|12
end_define

begin_typedef
typedef|typedef
name|struct
name|bhnd_sprom_opcode_state
name|bhnd_sprom_opcode_state
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bhnd_sprom_opcode_bind
name|bhnd_sprom_opcode_bind
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bhnd_sprom_opcode_var
name|bhnd_sprom_opcode_var
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bhnd_sprom_opcode_idx_entry
name|bhnd_sprom_opcode_idx_entry
typedef|;
end_typedef

begin_function_decl
name|int
name|bhnd_sprom_opcode_init
parameter_list|(
name|bhnd_sprom_opcode_state
modifier|*
name|state
parameter_list|,
specifier|const
name|bhnd_sprom_layout
modifier|*
name|layout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_sprom_opcode_fini
parameter_list|(
name|bhnd_sprom_opcode_state
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_sprom_opcode_idx_entry
modifier|*
name|bhnd_sprom_opcode_index_find
parameter_list|(
name|bhnd_sprom_opcode_state
modifier|*
name|state
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_sprom_opcode_idx_entry
modifier|*
name|bhnd_sprom_opcode_index_next
parameter_list|(
name|bhnd_sprom_opcode_state
modifier|*
name|state
parameter_list|,
name|bhnd_sprom_opcode_idx_entry
modifier|*
name|prev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_sprom_opcode_init_entry
parameter_list|(
name|bhnd_sprom_opcode_state
modifier|*
name|state
parameter_list|,
name|bhnd_sprom_opcode_idx_entry
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_sprom_opcode_eval_var
parameter_list|(
name|bhnd_sprom_opcode_state
modifier|*
name|state
parameter_list|,
name|bhnd_sprom_opcode_idx_entry
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_sprom_opcode_seek
parameter_list|(
name|bhnd_sprom_opcode_state
modifier|*
name|state
parameter_list|,
name|bhnd_sprom_opcode_idx_entry
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_sprom_opcode_next_var
parameter_list|(
name|bhnd_sprom_opcode_state
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_sprom_opcode_next_binding
parameter_list|(
name|bhnd_sprom_opcode_state
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_sprom_opcode_apply_scale
parameter_list|(
name|bhnd_sprom_opcode_state
modifier|*
name|state
parameter_list|,
name|uint32_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * SPROM opcode per-bind evaluation state.  */
end_comment

begin_struct
struct|struct
name|bhnd_sprom_opcode_bind
block|{
name|uint8_t
name|count
decl_stmt|;
name|uint32_t
name|skip_in
decl_stmt|;
comment|/**< input element skips */
name|bool
name|skip_in_negative
decl_stmt|;
comment|/**< skip_in should be subtracted */
name|uint32_t
name|skip_out
decl_stmt|;
comment|/**< output element skip */
block|}
struct|;
end_struct

begin_comment
comment|/**  * SPROM opcode per-variable evaluation state.  */
end_comment

begin_struct
struct|struct
name|bhnd_sprom_opcode_var
block|{
name|uint8_t
name|nelem
decl_stmt|;
comment|/**< variable array length */
name|uint32_t
name|mask
decl_stmt|;
comment|/**< current bind input mask */
name|int8_t
name|shift
decl_stmt|;
comment|/**< current bind input shift */
name|bhnd_nvram_type
name|base_type
decl_stmt|;
comment|/**< current bind input type */
name|uint32_t
name|scale
decl_stmt|;
comment|/**< current scale to apply to scaled encodings */
name|bhnd_sprom_opcode_bind
name|bind
decl_stmt|;
comment|/**< current bind state */
name|bool
name|have_bind
decl_stmt|;
comment|/**< if bind state is defined */
name|size_t
name|bind_total
decl_stmt|;
comment|/**< total count of bind operations performed */
block|}
struct|;
end_struct

begin_comment
comment|/**  * SPROM opcode variable definition states.  *   * Ordered to support inequality comparisons  * (e.g.>= SPROM_OPCODE_VAR_STATE_OPEN)  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SPROM_OPCODE_VAR_STATE_NONE
init|=
literal|1
block|,
comment|/**< no variable entry available */
name|SPROM_OPCODE_VAR_STATE_OPEN
init|=
literal|2
block|,
comment|/**< currently parsing a variable entry */
name|SPROM_OPCODE_VAR_STATE_DONE
init|=
literal|3
comment|/**< full variable entry has been parsed */
block|}
name|bhnd_sprom_opcode_var_state
typedef|;
end_typedef

begin_comment
comment|/**  * SPROM opcode evaluation state  */
end_comment

begin_struct
struct|struct
name|bhnd_sprom_opcode_state
block|{
specifier|const
name|bhnd_sprom_layout
modifier|*
name|layout
decl_stmt|;
comment|/**< SPROM layout */
name|bhnd_sprom_opcode_idx_entry
modifier|*
name|idx
decl_stmt|;
comment|/**< variable index (NULL during initialization) */
name|size_t
name|num_idx
decl_stmt|;
comment|/**< variable index entry count */
comment|/** Current SPROM revision range */
name|bitstr_t
name|bit_decl
parameter_list|(
name|revs
parameter_list|,
name|SPROM_OP_REV_MAX
parameter_list|)
function_decl|;
specifier|const
name|uint8_t
modifier|*
name|input
decl_stmt|;
comment|/**< opcode input position */
comment|/* State preserved across variable definitions */
name|uint32_t
name|offset
decl_stmt|;
comment|/**< SPROM offset */
name|size_t
name|vid
decl_stmt|;
comment|/**< Variable ID */
comment|/* State reset after end of each variable definition */
name|bhnd_sprom_opcode_var
name|var
decl_stmt|;
comment|/**< variable record (if any) */
name|bhnd_sprom_opcode_var_state
name|var_state
decl_stmt|;
comment|/**< variable record state */
block|}
struct|;
end_struct

begin_comment
comment|/**  * SPROM opcode variable index entry  */
end_comment

begin_struct
struct|struct
name|bhnd_sprom_opcode_idx_entry
block|{
name|uint16_t
name|vid
decl_stmt|;
comment|/**< SPROM variable ID */
name|uint16_t
name|offset
decl_stmt|;
comment|/**< SPROM input offset */
name|uint16_t
name|opcodes
decl_stmt|;
comment|/**< SPROM opcode offset */
block|}
struct|;
end_struct

begin_comment
comment|/**  * SPROM value storage.  *  * Sufficient for representing the native encoding of any defined SPROM  * variable.  */
end_comment

begin_union
union|union
name|bhnd_nvram_sprom_storage
block|{
name|uint8_t
name|u8
index|[
name|BHND_SPROM_ARRAY_MAXLEN
index|]
decl_stmt|;
name|uint16_t
name|u16
index|[
name|BHND_SPROM_ARRAY_MAXLEN
index|]
decl_stmt|;
name|uint32_t
name|u32
index|[
name|BHND_SPROM_ARRAY_MAXLEN
index|]
decl_stmt|;
name|int8_t
name|i8
index|[
name|BHND_SPROM_ARRAY_MAXLEN
index|]
decl_stmt|;
name|int16_t
name|i16
index|[
name|BHND_SPROM_ARRAY_MAXLEN
index|]
decl_stmt|;
name|int32_t
name|i32
index|[
name|BHND_SPROM_ARRAY_MAXLEN
index|]
decl_stmt|;
name|char
name|ch
index|[
name|BHND_SPROM_ARRAY_MAXLEN
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/**  * SPROM data class instance state.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_sprom
block|{
name|struct
name|bhnd_nvram_data
name|nv
decl_stmt|;
comment|/**< common instance state */
name|struct
name|bhnd_nvram_io
modifier|*
name|data
decl_stmt|;
comment|/**< backing SPROM image */
specifier|const
name|bhnd_sprom_layout
modifier|*
name|layout
decl_stmt|;
comment|/**< layout definition */
name|bhnd_sprom_opcode_state
name|state
decl_stmt|;
comment|/**< opcode eval state */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_SPROMVAR_H_ */
end_comment

end_unit

