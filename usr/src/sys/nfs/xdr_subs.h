begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)xdr_subs.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Macros used for conversion to/from xdr representation by nfs...  * These use the MACHINE DEPENDENT routines ntohl, htonl  * As defined by "XDR: External Data Representation Standard" RFC1014  */
end_comment

begin_comment
comment|/* From xdr to machine */
end_comment

begin_define
define|#
directive|define
name|fxdr_unsigned
parameter_list|(
name|t
parameter_list|,
name|v
parameter_list|)
value|((t)ntohl((long)(v)))
end_define

begin_define
define|#
directive|define
name|fxdr_time
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{((struct timeval *)(t))->tv_sec=ntohl( \ 				((struct timeval *)(f))->tv_sec); \ 				((struct timeval *)(t))->tv_usec=ntohl( \ 				((struct timeval *)(f))->tv_usec);}
end_define

begin_comment
comment|/* from machine to xdr */
end_comment

begin_define
define|#
directive|define
name|txdr_unsigned
parameter_list|(
name|v
parameter_list|)
value|(htonl((long)(v)))
end_define

begin_define
define|#
directive|define
name|txdr_time
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{((struct timeval *)(t))->tv_sec=htonl( \ 				((struct timeval *)(f))->tv_sec); \ 				((struct timeval *)(t))->tv_usec=htonl( \ 				((struct timeval *)(f))->tv_usec);}
end_define

end_unit

