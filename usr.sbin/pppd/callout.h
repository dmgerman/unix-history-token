begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Note:  This is a copy of /usr/include/sys/callout.h with the c_func */
end_comment

begin_comment
comment|/* member of struct callout changed from a pointer to a function of type int*/
end_comment

begin_comment
comment|/* to a pointer to a function of type void (generic pointer) as per */
end_comment

begin_comment
comment|/* ANSI C */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ppp_callout_h
end_ifndef

begin_define
define|#
directive|define
name|_ppp_callout_h
end_define

begin_struct
struct|struct
name|callout
block|{
name|int
name|c_time
decl_stmt|;
comment|/* incremental time */
name|caddr_t
name|c_arg
decl_stmt|;
comment|/* argument to routine */
name|void
function_decl|(
modifier|*
name|c_func
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine (changed to void (*)() */
name|struct
name|callout
modifier|*
name|c_next
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!_ppp_callout_h*/
end_comment

end_unit

