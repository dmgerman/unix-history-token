begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GLOBAL.H - RSAREF types and constants  */
end_comment

begin_comment
comment|/* PROTOTYPES should be set to one if and only if the compiler supports   function argument prototyping. The following makes PROTOTYPES default to 0 if it has not already   been defined with C compiler flags.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROTOTYPES
end_ifndef

begin_define
define|#
directive|define
name|PROTOTYPES
value|0
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* UINT2 defines a two byte word */
end_comment

begin_comment
unit|typedef unsigned short int UINT2;
comment|/* UINT4 defines a four byte word */
end_comment

begin_else
unit|typedef unsigned long int UINT4;
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* UINT2 defines a two byte word */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|UINT2
typedef|;
end_typedef

begin_comment
comment|/* UINT4 defines a four byte word */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|UINT4
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/* PROTO_LIST is defined depending on how PROTOTYPES is defined above. If using PROTOTYPES, then PROTO_LIST returns the list, otherwise it   returns an empty list.  */
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

end_unit

