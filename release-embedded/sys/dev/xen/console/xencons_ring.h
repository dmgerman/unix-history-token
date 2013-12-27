begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XENCONS_RING_H
end_ifndef

begin_define
define|#
directive|define
name|_XENCONS_RING_H
end_define

begin_define
define|#
directive|define
name|CN_LOCK
parameter_list|(
name|l
parameter_list|)
define|\
value|do {											\ 				if (panicstr == NULL)					\                         mtx_lock_spin(&(l));			\ 		} while (0)
end_define

begin_define
define|#
directive|define
name|CN_UNLOCK
parameter_list|(
name|l
parameter_list|)
define|\
value|do {											\ 				if (panicstr == NULL)					\                         mtx_unlock_spin(&(l));			\ 		} while (0)
end_define

begin_function_decl
name|int
name|xencons_ring_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xencons_ring_send
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|unsigned
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xencons_rx
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xencons_tx
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
name|xencons_receiver_func
function_decl|)
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|len
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|xencons_ring_register_receiver
parameter_list|(
name|xencons_receiver_func
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xencons_handle_input
parameter_list|(
name|void
modifier|*
name|unused
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xencons_has_input
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
comment|/* _XENCONS_RING_H */
end_comment

end_unit

