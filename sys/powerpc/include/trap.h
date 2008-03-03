begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AIM
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/trap_aim.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|E500
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<machine/trap_booke.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|trap
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

