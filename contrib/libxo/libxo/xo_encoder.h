begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015, Juniper Networks, Inc.  * All rights reserved.  * This SOFTWARE is licensed under the LICENSE provided in the  * ../Copyright file. By downloading, installing, copying, or otherwise  * using the SOFTWARE, you agree to be bound by the terms of that  * LICENSE.  * Phil Shafer, August 2015  */
end_comment

begin_comment
comment|/*  * NOTE WELL: This file is needed to software that implements an  * external encoder for libxo that allows libxo data to be encoded in  * new and bizarre formats.  General libxo code should _never_  * include this header file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XO_ENCODER_H
end_ifndef

begin_define
define|#
directive|define
name|XO_ENCODER_H
end_define

begin_comment
comment|/*  * Expose libxo's memory allocation functions  */
end_comment

begin_decl_stmt
specifier|extern
name|xo_realloc_func_t
name|xo_realloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|xo_free_func_t
name|xo_free
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|unsigned
name|xo_encoder_op_t
typedef|;
end_typedef

begin_comment
comment|/* Encoder operations; names are in xo_encoder.c:xo_encoder_op_name() */
end_comment

begin_define
define|#
directive|define
name|XO_OP_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|XO_OP_CREATE
value|1
end_define

begin_comment
comment|/* Called when the handle is init'd */
end_comment

begin_define
define|#
directive|define
name|XO_OP_OPEN_CONTAINER
value|2
end_define

begin_define
define|#
directive|define
name|XO_OP_CLOSE_CONTAINER
value|3
end_define

begin_define
define|#
directive|define
name|XO_OP_OPEN_LIST
value|4
end_define

begin_define
define|#
directive|define
name|XO_OP_CLOSE_LIST
value|5
end_define

begin_define
define|#
directive|define
name|XO_OP_OPEN_LEAF_LIST
value|6
end_define

begin_define
define|#
directive|define
name|XO_OP_CLOSE_LEAF_LIST
value|7
end_define

begin_define
define|#
directive|define
name|XO_OP_OPEN_INSTANCE
value|8
end_define

begin_define
define|#
directive|define
name|XO_OP_CLOSE_INSTANCE
value|9
end_define

begin_define
define|#
directive|define
name|XO_OP_STRING
value|10
end_define

begin_comment
comment|/* Quoted UTF-8 string */
end_comment

begin_define
define|#
directive|define
name|XO_OP_CONTENT
value|11
end_define

begin_comment
comment|/* Other content */
end_comment

begin_define
define|#
directive|define
name|XO_OP_FINISH
value|12
end_define

begin_comment
comment|/* Finish any pending output */
end_comment

begin_define
define|#
directive|define
name|XO_OP_FLUSH
value|13
end_define

begin_comment
comment|/* Flush any buffered output */
end_comment

begin_define
define|#
directive|define
name|XO_OP_DESTROY
value|14
end_define

begin_comment
comment|/* Clean up function */
end_comment

begin_define
define|#
directive|define
name|XO_OP_ATTRIBUTE
value|15
end_define

begin_comment
comment|/* Attribute name/value */
end_comment

begin_define
define|#
directive|define
name|XO_OP_VERSION
value|16
end_define

begin_comment
comment|/* Version string */
end_comment

begin_define
define|#
directive|define
name|XO_ENCODER_HANDLER_ARGS
define|\
value|xo_handle_t *xop __attribute__ ((__unused__)),		\ 	xo_encoder_op_t op __attribute__ ((__unused__)),	\ 	const char *name __attribute__ ((__unused__)),		\         const char *value __attribute__ ((__unused__)),		\ 	void *private __attribute__ ((__unused__))
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xo_encoder_func_t
function_decl|)
parameter_list|(
name|XO_ENCODER_HANDLER_ARGS
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xo_encoder_init_args_s
block|{
name|unsigned
name|xei_version
decl_stmt|;
comment|/* Current version */
name|xo_encoder_func_t
name|xei_handler
decl_stmt|;
comment|/* Encoding handler */
block|}
name|xo_encoder_init_args_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XO_ENCODER_VERSION
value|1
end_define

begin_comment
comment|/* Current version */
end_comment

begin_define
define|#
directive|define
name|XO_ENCODER_INIT_ARGS
define|\
value|xo_encoder_init_args_t *arg __attribute__ ((__unused__))
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xo_encoder_init_func_t
function_decl|)
parameter_list|(
name|XO_ENCODER_INIT_ARGS
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Each encoder library must define a function named xo_encoder_init  * that takes the arguments defined in XO_ENCODER_INIT_ARGS.  It  * should return zero for success.  */
end_comment

begin_define
define|#
directive|define
name|XO_ENCODER_INIT_NAME_TOKEN
value|xo_encoder_library_init
end_define

begin_define
define|#
directive|define
name|XO_STRINGIFY
parameter_list|(
name|_x
parameter_list|)
value|#_x
end_define

begin_define
define|#
directive|define
name|XO_STRINGIFY2
parameter_list|(
name|_x
parameter_list|)
value|XO_STRINGIFY(_x)
end_define

begin_define
define|#
directive|define
name|XO_ENCODER_INIT_NAME
value|XO_STRINGIFY2(XO_ENCODER_INIT_NAME_TOKEN)
end_define

begin_function_decl
specifier|extern
name|int
name|XO_ENCODER_INIT_NAME_TOKEN
parameter_list|(
name|XO_ENCODER_INIT_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_encoder_register
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|xo_encoder_func_t
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_encoder_unregister
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|xo_get_private
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_encoder_path_add
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_set_private
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|void
modifier|*
name|opaque
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_encoder_func_t
name|xo_get_encoder
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_set_encoder
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|xo_encoder_func_t
name|encoder
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_encoder_init
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xo_handle_t
modifier|*
name|xo_encoder_create
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|xo_xof_flags_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xo_encoder_handle
parameter_list|(
name|xo_handle_t
modifier|*
name|xop
parameter_list|,
name|xo_encoder_op_t
name|op
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xo_encoders_clean
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|xo_encoder_op_name
parameter_list|(
name|xo_encoder_op_t
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XO_ENCODER_H */
end_comment

end_unit

