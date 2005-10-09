begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_PRUTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_PRUTIL_H_
end_define

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_struct_decl
struct_decl|struct
name|sched_param
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|quit
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|sched_text
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_is
parameter_list|(
name|int
name|line
parameter_list|,
name|struct
name|sched_param
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PRUTIL_H_ */
end_comment

end_unit

