begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  linux/include/linux/clocksource.h  *  *  MLX4_CORE_PORT  *  *  This file contains the structure definitions for clocksources.  *  *  If you are not a clocksource, or timekeeping code, you should  *  not be including this file!  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_CLOCKSOURCE_H
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_CLOCKSOURCE_H
end_define

begin_comment
comment|/* clocksource cycle base type */
end_comment

begin_typedef
typedef|typedef
name|u64
name|cycle_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_CLOCKSOURCE_H */
end_comment

end_unit

