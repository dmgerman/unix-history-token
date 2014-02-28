begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for most GPIO bindings.  *  * Most GPIO bindings include a flags cell as part of the GPIO specifier.  * In most cases, the format of the flags cell uses the standard values  * defined in this header.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_GPIO_GPIO_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_GPIO_GPIO_H
end_define

begin_define
define|#
directive|define
name|GPIO_ACTIVE_HIGH
value|0
end_define

begin_define
define|#
directive|define
name|GPIO_ACTIVE_LOW
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

