begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Mach Operating System  * Copyright (c) 1991,1990 Carnegie Mellon University  * All Rights Reserved.  *  * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_X86_STACK_H
end_ifndef

begin_define
define|#
directive|define
name|_X86_STACK_H
end_define

begin_comment
comment|/*  * Stack trace.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_struct
struct|struct
name|i386_frame
block|{
name|struct
name|i386_frame
modifier|*
name|f_frame
decl_stmt|;
name|u_int
name|f_retaddr
decl_stmt|;
name|u_int
name|f_arg0
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_struct
struct|struct
name|amd64_frame
block|{
name|struct
name|amd64_frame
modifier|*
name|f_frame
decl_stmt|;
name|u_long
name|f_retaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i386_frame
block|{
name|uint32_t
name|f_frame
decl_stmt|;
name|uint32_t
name|f_retaddr
decl_stmt|;
name|uint32_t
name|f_arg0
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __amd64__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|stack_nmi_handler
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_X86_STACK_H */
end_comment

end_unit

