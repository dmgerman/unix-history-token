begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990,1994 Regents of The University of Michigan.  * All Rights Reserved.  See COPYRIGHT.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATALK_DDP_PCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETATALK_DDP_PCB_H_
end_define

begin_function_decl
name|int
name|at_pcballoc
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|at_pcbconnect
parameter_list|(
name|struct
name|ddpcb
modifier|*
name|ddp
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at_pcbdetach
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|ddpcb
modifier|*
name|ddp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at_pcbdisconnect
parameter_list|(
name|struct
name|ddpcb
modifier|*
name|ddp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|at_pcbsetaddr
parameter_list|(
name|struct
name|ddpcb
modifier|*
name|ddp
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at_sockaddr
parameter_list|(
name|struct
name|ddpcb
modifier|*
name|ddp
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

