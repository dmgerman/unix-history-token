begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)endian.h	7.6 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Definitions for byte order,  * according to byte significance from low address to high.  */
end_comment

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_comment
comment|/* least-significant byte first (vax) */
end_comment

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_comment
comment|/* most-significant byte first (IBM, net) */
end_comment

begin_define
define|#
directive|define
name|PDP_ENDIAN
value|3412
end_define

begin_comment
comment|/* LSB first in word, MSW first in long (pdp) */
end_comment

begin_define
define|#
directive|define
name|BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/*  * Macros for network/external number representation conversion.  */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_define
define|#
directive|define
name|ntohl
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|ntohs
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|htonl
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|htons
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|NTOHL
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|NTOHS
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|HTONL
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|HTONS
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|unsigned
name|short
name|ntohs
argument_list|()
decl_stmt|,
name|htons
argument_list|()
decl_stmt|;
end_decl_stmt

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

begin_define
define|#
directive|define
name|NTOHL
parameter_list|(
name|x
parameter_list|)
value|(x) = ntohl(x)
end_define

begin_define
define|#
directive|define
name|NTOHS
parameter_list|(
name|x
parameter_list|)
value|(x) = ntohs(x)
end_define

begin_define
define|#
directive|define
name|HTONL
parameter_list|(
name|x
parameter_list|)
value|(x) = htonl(x)
end_define

begin_define
define|#
directive|define
name|HTONS
parameter_list|(
name|x
parameter_list|)
value|(x) = htons(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

