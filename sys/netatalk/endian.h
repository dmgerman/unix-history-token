begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990,1991 Regents of The University of Michigan.  * All Rights Reserved.  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright notice appears in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation, and that the name of The University  * of Michigan not be used in advertising or publicity pertaining to  * distribution of the software without specific, written prior  * permission. This software is supplied as is without expressed or  * implied warranties of any kind.  *  *	Research Systems Unix Group  *	The University of Michigan  *	c/o Mike Clark  *	535 W. William Street  *	Ann Arbor, Michigan  *	+1-313-763-0525  *	netatalk@itd.umich.edu  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATALK_ENDIAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATALK_ENDIAN_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_IBMR2
end_ifdef

begin_include
include|#
directive|include
file|<sys/machine.h>
end_include

begin_endif
endif|#
directive|endif
endif|_IBMR2
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|linux
end_ifdef

begin_include
include|#
directive|include
file|<bytesex.h>
end_include

begin_define
define|#
directive|define
name|BYTE_ORDER
value|__BYTE_ORDER
end_define

begin_endif
endif|#
directive|endif
endif|linux
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_endif
endif|#
directive|endif
endif|__FreeBSD__
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BYTE_ORDER
end_ifndef

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_define
define|#
directive|define
name|PDP_ENDIAN
value|3412
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|i386
end_ifdef

begin_define
define|#
directive|define
name|BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_else
else|#
directive|else
else|i386
end_else

begin_define
define|#
directive|define
name|BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
endif|i386
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MIPSEB
end_ifdef

begin_define
define|#
directive|define
name|BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MIPSEL
end_ifdef

begin_define
define|#
directive|define
name|BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|Like
operator|,
name|what
name|is
name|your
name|byte
name|order
operator|,
name|man
condition|?
endif|#
directive|endif
endif|MIPSEL
endif|#
directive|endif
endif|MIPSEB
endif|#
directive|endif
endif|sun
endif|#
directive|endif
endif|BYTE_ORDER
ifndef|#
directive|ifndef
name|ntohl
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|ultrix
argument_list|)
operator|||
name|defined
argument_list|(
name|_IBMR2
argument_list|)
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
define|#
directive|define
name|ntohl
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|ntohs
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|htonl
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|htons
parameter_list|(
name|x
parameter_list|)
value|(x)
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|mips
argument_list|)
operator|&&
name|defined
argument_list|(
name|KERNEL
argument_list|)
define|#
directive|define
name|ntohl
parameter_list|(
name|x
parameter_list|)
value|nuxi_l(x)
define|#
directive|define
name|ntohs
parameter_list|(
name|x
parameter_list|)
value|nuxi_s(x)
define|#
directive|define
name|htonl
parameter_list|(
name|x
parameter_list|)
value|nuxi_l(x)
define|#
directive|define
name|htons
parameter_list|(
name|x
parameter_list|)
value|nuxi_s(x)
else|#
directive|else
else|mips KERNEL
name|unsigned
name|short
name|ntohs
argument_list|()
operator|,
name|htons
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|long
name|ntohl
argument_list|()
decl_stmt|,
name|htonl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|mips KERNEL
end_endif

begin_endif
endif|#
directive|endif
endif|BYTE_ORDER
end_endif

begin_endif
endif|#
directive|endif
endif|sun ultrix _IBMR2
end_endif

begin_endif
endif|#
directive|endif
endif|ntohl
end_endif

begin_endif
endif|#
directive|endif
endif|_ATALK_ENDIAN_H_
end_endif

end_unit

