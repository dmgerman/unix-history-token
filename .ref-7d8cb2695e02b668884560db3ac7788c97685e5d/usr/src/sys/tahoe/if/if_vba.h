begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)if_vba.h	1.2 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|ifvba
block|{
name|struct
name|mbuf
modifier|*
name|iff_mbuf
decl_stmt|;
comment|/* associated mbuf to free */
name|caddr_t
name|iff_buffer
decl_stmt|;
comment|/* contiguous memory for data, kernel address */
name|u_long
name|iff_physaddr
decl_stmt|;
comment|/* contiguous memory for data, phys address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VIFF_16BIT
value|1
end_define

begin_comment
comment|/* only allow two byte transfers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|struct
name|mbuf
modifier|*
name|if_vbaget
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

