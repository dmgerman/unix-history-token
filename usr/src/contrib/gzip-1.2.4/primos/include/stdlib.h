begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** stdlib.h ** ** Emulation of the Unix stdlib.h header file for PRIMOS ** ** Author: Peter Eriksson<pen@lysator.liu.se> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDLIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__STDLIB_H__
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

