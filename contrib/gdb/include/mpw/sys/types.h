begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Imitation sys/types.h. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SYS_TYPES_H__
end_ifndef

begin_define
define|#
directive|define
name|__SYS_TYPES_H__
end_define

begin_include
include|#
directive|include
file|<Types.h>
end_include

begin_typedef
typedef|typedef
name|short
name|dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|ino_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|off_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SYS_TYPES_H__ */
end_comment

end_unit

