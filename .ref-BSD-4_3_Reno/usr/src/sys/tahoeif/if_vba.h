begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)if_vba.h	1.2 (Berkeley) 6/28/90  */
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

