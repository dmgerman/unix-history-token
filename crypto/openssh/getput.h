begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * getput.h  *  * Author: Tatu Ylonen<ylo@cs.hut.fi>  *  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * Created: Wed Jun 28 22:36:30 1995 ylo  *  * Macros for storing and retrieving data in msb first and lsb first order.  *  */
end_comment

begin_comment
comment|/* RCSID("$Id: getput.h,v 1.3 2000/04/14 10:30:31 markus Exp $"); */
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
name|GET_32BIT
parameter_list|(
name|cp
parameter_list|)
value|(((unsigned long)(unsigned char)(cp)[0]<< 24) | \ 		       ((unsigned long)(unsigned char)(cp)[1]<< 16) | \ 		       ((unsigned long)(unsigned char)(cp)[2]<< 8) | \ 		       ((unsigned long)(unsigned char)(cp)[3]))
end_define

begin_define
define|#
directive|define
name|GET_16BIT
parameter_list|(
name|cp
parameter_list|)
value|(((unsigned long)(unsigned char)(cp)[0]<< 8) | \ 		       ((unsigned long)(unsigned char)(cp)[1]))
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

begin_comment
comment|/*------------ macros for storing/extracting lsb first words -------------*/
end_comment

begin_define
define|#
directive|define
name|GET_32BIT_LSB_FIRST
parameter_list|(
name|cp
parameter_list|)
define|\
value|(((unsigned long)(unsigned char)(cp)[0]) | \   ((unsigned long)(unsigned char)(cp)[1]<< 8) | \   ((unsigned long)(unsigned char)(cp)[2]<< 16) | \   ((unsigned long)(unsigned char)(cp)[3]<< 24))
end_define

begin_define
define|#
directive|define
name|GET_16BIT_LSB_FIRST
parameter_list|(
name|cp
parameter_list|)
define|\
value|(((unsigned long)(unsigned char)(cp)[0]) | \   ((unsigned long)(unsigned char)(cp)[1]<< 8))
end_define

begin_define
define|#
directive|define
name|PUT_32BIT_LSB_FIRST
parameter_list|(
name|cp
parameter_list|,
name|value
parameter_list|)
value|do { \   (cp)[0] = (value); \   (cp)[1] = (value)>> 8; \   (cp)[2] = (value)>> 16; \   (cp)[3] = (value)>> 24; } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_16BIT_LSB_FIRST
parameter_list|(
name|cp
parameter_list|,
name|value
parameter_list|)
value|do { \   (cp)[0] = (value); \   (cp)[1] = (value)>> 8; } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GETPUT_H */
end_comment

end_unit

