begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1987, 1988, 1989 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  * Include file for address comparison macros.  *  *	from: addr_comp.h,v 4.0 89/01/23 09:57:44 jtkohl Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ADDR_COMP_DEFS
end_ifndef

begin_define
define|#
directive|define
name|ADDR_COMP_DEFS
end_define

begin_comment
comment|/* ** Look boys and girls, a big kludge ** We need to compare the two internet addresses in network byte order, not **   local byte order.  This is a *really really slow way of doing that* ** But..... **         .....it works ** so we run with it ** ** long_less_than gets fed two (u_char *)'s.... */
end_comment

begin_define
define|#
directive|define
name|u_char_comp
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(((x)>(y))?(1):(((x)==(y))?(0):(-1)))
end_define

begin_define
define|#
directive|define
name|long_less_than
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(u_char_comp((x)[0],(y)[0])?u_char_comp((x)[0],(y)[0]): \ 	 (u_char_comp((x)[1],(y)[1])?u_char_comp((x)[1],(y)[1]): \ 	  (u_char_comp((x)[2],(y)[2])?u_char_comp((x)[2],(y)[2]): \ 	   (u_char_comp((x)[3],(y)[3])))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ADDR_COMP_DEFS */
end_comment

end_unit

