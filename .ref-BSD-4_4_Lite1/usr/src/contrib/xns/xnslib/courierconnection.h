begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CourierConnection as seen by everyone else except the runtime library,  * effectively hiding the internal structure  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CourierConnectionHeader
end_ifndef

begin_define
define|#
directive|define
name|CourierConnectionHeader
end_define

begin_typedef
typedef|typedef
name|int
name|CourierConnection
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|CourierConnection
modifier|*
name|CourierOpen
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|CourierConnectionHeader
end_endif

end_unit

