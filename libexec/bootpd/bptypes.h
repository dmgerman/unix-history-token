begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bptypes.h */
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

begin_comment
comment|/*  * 32 bit integers are different types on various architectures  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|int32
end_ifndef

begin_define
define|#
directive|define
name|int32
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|int32
name|u_int32
typedef|;
end_typedef

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

