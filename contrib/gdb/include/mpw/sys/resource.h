begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__SYS_RESOURCE_H__
end_ifndef

begin_define
define|#
directive|define
name|__SYS_RESOURCE_H__
end_define

begin_struct
struct|struct
name|rusage
block|{
name|struct
name|timeval
name|ru_utime
decl_stmt|;
name|struct
name|timeval
name|ru_stime
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SYS_RESOURCE_H__ */
end_comment

end_unit

