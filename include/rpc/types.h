begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  *	from: @(#)types.h 1.18 87/07/24 SMI  *	from: @(#)types.h	2.3 88/08/15 4.0 RPCSRC  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Rpc additions to<sys/types.h>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_TYPES_H
end_define

begin_define
define|#
directive|define
name|bool_t
value|int32_t
end_define

begin_define
define|#
directive|define
name|enum_t
value|int32_t
end_define

begin_define
define|#
directive|define
name|__dontcare__
value|-1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|mem_alloc
parameter_list|(
name|bsize
parameter_list|)
value|malloc(bsize)
end_define

begin_define
define|#
directive|define
name|mem_free
parameter_list|(
name|ptr
parameter_list|,
name|bsize
parameter_list|)
value|free(ptr)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|makedev
end_ifndef

begin_comment
comment|/* ie, we haven't already included it */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_TYPES_H */
end_comment

end_unit

