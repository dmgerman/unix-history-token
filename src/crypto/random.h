begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Random number generator  * Copyright (c) 2010-2011, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RANDOM_H
end_ifndef

begin_define
define|#
directive|define
name|RANDOM_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NO_RANDOM_POOL
end_ifdef

begin_define
define|#
directive|define
name|random_init
parameter_list|(
name|e
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|random_deinit
parameter_list|()
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|random_add_randomness
parameter_list|(
name|b
parameter_list|,
name|l
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|random_get_bytes
parameter_list|(
name|b
parameter_list|,
name|l
parameter_list|)
value|os_get_random((b), (l))
end_define

begin_define
define|#
directive|define
name|random_pool_ready
parameter_list|()
value|1
end_define

begin_define
define|#
directive|define
name|random_mark_pool_ready
parameter_list|()
value|do { } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_NO_RANDOM_POOL */
end_comment

begin_function_decl
name|void
name|random_init
parameter_list|(
specifier|const
name|char
modifier|*
name|entropy_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_deinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_add_randomness
parameter_list|(
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|random_get_bytes
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|random_pool_ready
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_mark_pool_ready
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NO_RANDOM_POOL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RANDOM_H */
end_comment

end_unit

