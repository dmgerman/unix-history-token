begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)scope.h	7.3 (Berkeley) 6/28/90  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DOSCOPE
end_ifdef

begin_comment
comment|/*  some i/o addresses used to generate pulses for scopes */
end_comment

begin_define
define|#
directive|define
name|OUT1
value|0xffffb034
end_define

begin_define
define|#
directive|define
name|OUT2
value|0xffffb018
end_define

begin_define
define|#
directive|define
name|OUT3
value|0xffffb020
end_define

begin_define
define|#
directive|define
name|OUT4
value|0xffffb004
end_define

begin_define
define|#
directive|define
name|OUT5
value|0xffffb024
end_define

begin_define
define|#
directive|define
name|OUT6
value|0xffffb00c
end_define

begin_define
define|#
directive|define
name|OUT7
value|0xffffb02c
end_define

begin_define
define|#
directive|define
name|IOaddr
parameter_list|(
name|off
parameter_list|)
value|(caddr_t)(&vmem[(off)& 0x0fffff])
end_define

begin_decl_stmt
specifier|extern
name|char
name|vmem
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cold
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|scope_out
parameter_list|(
name|x
parameter_list|)
value|if (!cold) movob(IOaddr(OUT
comment|/**/
value|x),0)
end_define

begin_define
define|#
directive|define
name|scope_in
parameter_list|(
name|x
parameter_list|)
value|if( !cold) dummy =  *IOaddr(IN
comment|/**/
value|x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|scope_out
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|scope_in
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

