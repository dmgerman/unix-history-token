begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)general.h	1.2 (Berkeley) 3/8/88  */
end_comment

begin_comment
comment|/*  * Some general definitions.  *  * @(#)general.h	3.1 (Berkeley) 8/11/87  */
end_comment

begin_define
define|#
directive|define
name|numberof
parameter_list|(
name|x
parameter_list|)
value|(sizeof x/sizeof x[0])
end_define

begin_define
define|#
directive|define
name|highestof
parameter_list|(
name|x
parameter_list|)
value|(numberof(x)-1)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|unix
argument_list|)
end_if

begin_define
define|#
directive|define
name|ClearElement
parameter_list|(
name|x
parameter_list|)
value|bzero((char *)&x, sizeof x)
end_define

begin_define
define|#
directive|define
name|ClearArray
parameter_list|(
name|x
parameter_list|)
value|bzero((char *)x, sizeof x)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(unix) */
end_comment

begin_define
define|#
directive|define
name|ClearElement
parameter_list|(
name|x
parameter_list|)
value|memset((char *)&x, 0, sizeof x)
end_define

begin_define
define|#
directive|define
name|ClearArray
parameter_list|(
name|x
parameter_list|)
value|memset((char *)x, 0, sizeof x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(unix) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|unix
argument_list|)
end_if

begin_comment
comment|/* Define BSD equivalent mem* functions */
end_comment

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
value|bcopy(src,dest,n)
end_define

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
value|bcopy(src,dest,n)
end_define

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
value|if (c == 0) { \ 				    bzero(s,n); \ 				} else { \ 				    register char *src = s; \ 				    register int count = n; \ 					\ 				    while (count--) { \ 					*src++ = c; \ 				    } \ 				}
end_define

begin_define
define|#
directive|define
name|memcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|bcmp(s1,s2,n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(unix) */
end_comment

end_unit

