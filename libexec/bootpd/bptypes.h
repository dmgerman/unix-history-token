begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BPTYPES_H
end_ifndef

begin_define
define|#
directive|define
name|BPTYPES_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * 32 bit integers are different types on various architectures  */
end_comment

begin_define
define|#
directive|define
name|int32
value|int32_t
end_define

begin_define
define|#
directive|define
name|u_int32
value|u_int32_t
end_define

begin_comment
comment|/*  * Nice typedefs. . .  */
end_comment

begin_typedef
typedef|typedef
name|int
name|boolean
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|byte
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BPTYPES_H */
end_comment

end_unit

