begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)in_systm.h	7.4 (Berkeley) 6/28/90  */
end_comment

begin_comment
comment|/*  * Miscellaneous internetwork  * definitions for kernel.  */
end_comment

begin_comment
comment|/*  * Network types.  *  * Internally the system keeps counters in the headers with the bytes  * swapped so that VAX instructions will work on them.  It reverses  * the bytes before transmission at each protocol level.  The n_ types  * represent the types with the bytes in ``high-ender'' order.  */
end_comment

begin_typedef
typedef|typedef
name|u_short
name|n_short
typedef|;
end_typedef

begin_comment
comment|/* short as received from the net */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|n_long
typedef|;
end_typedef

begin_comment
comment|/* long as received from the net */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|n_time
typedef|;
end_typedef

begin_comment
comment|/* ms since 00:00 GMT, byte rev */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|n_time
name|iptime
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

