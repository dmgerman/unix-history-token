begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * unctrl.h  *  * Display a printable version of a control character.  * Control characters are displayed in caret notation (^x), DELETE is displayed  * as ^?. Printable characters sre displatyed as is.  *  * The returned pointer points to a static buffer which gets overwritten by  * each call. Therefore, you must copy the resulting string to a safe place  * before calling unctrl() again.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNCTRL_H
end_ifndef

begin_define
define|#
directive|define
name|_UNCTRL_H
value|1
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|unctrl
parameter_list|(
name|unsigned
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNCTRL_H */
end_comment

end_unit

