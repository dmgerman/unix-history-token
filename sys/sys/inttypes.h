begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file is in the public domain.  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_INTTYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_INTTYPES_H_
end_define

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_typedef
typedef|typedef
name|__int8_t
name|int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int16_t
name|int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32_t
name|int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64_t
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint8_t
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint16_t
name|uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint32_t
name|uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint64_t
name|uint64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__intptr_t
name|intptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uintptr_t
name|uintptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_INTTYPES_H_ */
end_comment

end_unit

