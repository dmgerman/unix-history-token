begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Bitfield  * Copyright (c) 2013, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BITFIELD_H
end_ifndef

begin_define
define|#
directive|define
name|BITFIELD_H
end_define

begin_struct_decl
struct_decl|struct
name|bitfield
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|bitfield
modifier|*
name|bitfield_alloc
parameter_list|(
name|size_t
name|max_bits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bitfield_free
parameter_list|(
name|struct
name|bitfield
modifier|*
name|bf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bitfield_set
parameter_list|(
name|struct
name|bitfield
modifier|*
name|bf
parameter_list|,
name|size_t
name|bit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bitfield_clear
parameter_list|(
name|struct
name|bitfield
modifier|*
name|bf
parameter_list|,
name|size_t
name|bit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bitfield_is_set
parameter_list|(
name|struct
name|bitfield
modifier|*
name|bf
parameter_list|,
name|size_t
name|bit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bitfield_get_first_zero
parameter_list|(
name|struct
name|bitfield
modifier|*
name|bf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BITFIELD_H */
end_comment

end_unit

