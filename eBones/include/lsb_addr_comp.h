begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  * Comparison macros to emulate LSBFIRST comparison results of network  * byte-order quantities  *  *	from: lsb_addr_comp.h,v 4.0 89/01/23 15:44:46 jtkohl Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LSB_ADDR_COMP_DEFS
end_ifndef

begin_define
define|#
directive|define
name|LSB_ADDR_COMP_DEFS
end_define

begin_include
include|#
directive|include
file|"osconf.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|LSBFIRST
end_ifdef

begin_define
define|#
directive|define
name|lsb_net_ulong_less
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x< y) ? -1 : ((x> y) ? 1 : 0))
end_define

begin_define
define|#
directive|define
name|lsb_net_ushort_less
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x< y) ? -1 : ((x> y) ? 1 : 0))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MSBFIRST */
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

begin_comment
comment|/* This is gross, but... */
end_comment

begin_define
define|#
directive|define
name|lsb_net_ulong_less
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|long_less_than((u_char *)&x, (u_char *)&y)
end_define

begin_define
define|#
directive|define
name|lsb_net_ushort_less
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|short_less_than((u_char *)&x, (u_char *)&y)
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
value|(u_char_comp((x)[3],(y)[3])?u_char_comp((x)[3],(y)[3]): \ 	 (u_char_comp((x)[2],(y)[2])?u_char_comp((x)[2],(y)[2]): \ 	  (u_char_comp((x)[1],(y)[1])?u_char_comp((x)[1],(y)[1]): \ 	   (u_char_comp((x)[0],(y)[0])))))
end_define

begin_define
define|#
directive|define
name|short_less_than
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(u_char_comp((x)[1],(y)[1])?u_char_comp((x)[1],(y)[1]): \ 	   (u_char_comp((x)[0],(y)[0])))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LSBFIRST */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  LSB_ADDR_COMP_DEFS */
end_comment

end_unit

