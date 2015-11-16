begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* unity_config.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|UNITY_CONFIG_H
end_define

begin_define
define|#
directive|define
name|UNITY_INCLUDE_DOUBLE
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STDINT_H
end_ifndef

begin_define
define|#
directive|define
name|UNITY_EXCLUDE_STDINT_H
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
comment|/* UNITY_CONFIG_H */
end_comment

end_unit

