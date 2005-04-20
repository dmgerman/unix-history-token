begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GLOBAL.H - RSAREF types and constants */
end_comment

begin_comment
comment|/* Copyright (C) RSA Laboratories, a division of RSA Data Security,      Inc., created 1991. All rights reserved.  */
end_comment

begin_comment
comment|/*  * Note: the modifications are necessary for little-endian machines  */
end_comment

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_comment
comment|/* local modification */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLOBAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_GLOBAL_H_
value|1
end_define

begin_comment
comment|/* PROTOTYPES should be set to one if and only if the compiler supports      function argument prototyping.    The following makes PROTOTYPES default to 1 if it has not already been      defined as 0 with C compiler flags.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PROTOTYPES
end_ifdef

begin_define
define|#
directive|define
name|PROTOTYPES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POINTER defines a generic pointer type */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
modifier|*
name|POINTER
typedef|;
end_typedef

begin_comment
comment|/* UINT2 defines a two byte word */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|int
name|UINT2
typedef|;
end_typedef

begin_comment
comment|/* UINT4 defines a four byte word */
end_comment

begin_typedef
typedef|typedef
name|u_int32
name|UINT4
typedef|;
end_typedef

begin_comment
comment|/* local modification */
end_comment

begin_comment
comment|/* BYTE defines a unsigned character */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BYTE
typedef|;
end_typedef

begin_comment
comment|/* local modification for RSAEuro */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL_PTR
end_ifndef

begin_define
define|#
directive|define
name|NULL_PTR
value|((POINTER)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNUSED_ARG
end_ifndef

begin_define
define|#
directive|define
name|UNUSED_ARG
parameter_list|(
name|x
parameter_list|)
value|x = *(&x);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROTO_LIST is defined depending on how PROTOTYPES is defined above.    If using PROTOTYPES, then PROTO_LIST returns the list, otherwise it      returns an empty list.    */
end_comment

begin_if
if|#
directive|if
name|PROTOTYPES
end_if

begin_define
define|#
directive|define
name|PROTO_LIST
parameter_list|(
name|list
parameter_list|)
value|list
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROTO_LIST
parameter_list|(
name|list
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* end _GLOBAL_H_ */
end_comment

end_unit

