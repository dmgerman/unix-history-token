begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * Macros for storing and retrieving data in msb first and lsb first order.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/* RCSID("$OpenBSD: getput.h,v 1.7 2001/01/10 22:56:22 markus Exp $"); */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GETPUT_H
end_ifndef

begin_define
define|#
directive|define
name|GETPUT_H
end_define

begin_comment
comment|/*------------ macros for storing/extracting msb first words -------------*/
end_comment

begin_define
define|#
directive|define
name|GET_64BIT
parameter_list|(
name|cp
parameter_list|)
value|(((u_int64_t)(u_char)(cp)[0]<< 56) | \ 		       ((u_int64_t)(u_char)(cp)[1]<< 48) | \ 		       ((u_int64_t)(u_char)(cp)[2]<< 40) | \ 		       ((u_int64_t)(u_char)(cp)[3]<< 32) | \ 		       ((u_int64_t)(u_char)(cp)[4]<< 24) | \ 		       ((u_int64_t)(u_char)(cp)[5]<< 16) | \ 		       ((u_int64_t)(u_char)(cp)[6]<< 8) | \ 		       ((u_int64_t)(u_char)(cp)[7]))
end_define

begin_define
define|#
directive|define
name|GET_32BIT
parameter_list|(
name|cp
parameter_list|)
value|(((u_long)(u_char)(cp)[0]<< 24) | \ 		       ((u_long)(u_char)(cp)[1]<< 16) | \ 		       ((u_long)(u_char)(cp)[2]<< 8) | \ 		       ((u_long)(u_char)(cp)[3]))
end_define

begin_define
define|#
directive|define
name|GET_16BIT
parameter_list|(
name|cp
parameter_list|)
value|(((u_long)(u_char)(cp)[0]<< 8) | \ 		       ((u_long)(u_char)(cp)[1]))
end_define

begin_define
define|#
directive|define
name|PUT_64BIT
parameter_list|(
name|cp
parameter_list|,
name|value
parameter_list|)
value|do { \   (cp)[0] = (value)>> 56; \   (cp)[1] = (value)>> 48; \   (cp)[2] = (value)>> 40; \   (cp)[3] = (value)>> 32; \   (cp)[4] = (value)>> 24; \   (cp)[5] = (value)>> 16; \   (cp)[6] = (value)>> 8; \   (cp)[7] = (value); } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_32BIT
parameter_list|(
name|cp
parameter_list|,
name|value
parameter_list|)
value|do { \   (cp)[0] = (value)>> 24; \   (cp)[1] = (value)>> 16; \   (cp)[2] = (value)>> 8; \   (cp)[3] = (value); } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_16BIT
parameter_list|(
name|cp
parameter_list|,
name|value
parameter_list|)
value|do { \   (cp)[0] = (value)>> 8; \   (cp)[1] = (value); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GETPUT_H */
end_comment

end_unit

