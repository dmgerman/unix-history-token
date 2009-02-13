begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CXGB_TCP_OFFLOAD_H_
end_ifndef

begin_define
define|#
directive|define
name|CXGB_TCP_OFFLOAD_H_
end_define

begin_struct_decl
struct_decl|struct
name|sockbuf
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|sockbuf_lock
parameter_list|(
name|struct
name|sockbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sockbuf_lock_assert
parameter_list|(
name|struct
name|sockbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sockbuf_unlock
parameter_list|(
name|struct
name|sockbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sockbuf_sbspace
parameter_list|(
name|struct
name|sockbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CXGB_TCP_OFFLOAD_H_ */
end_comment

end_unit

