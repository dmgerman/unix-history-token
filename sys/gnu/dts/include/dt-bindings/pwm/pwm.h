begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for most PWM bindings.  *  * Most PWM bindings can include a flags cell as part of the PWM specifier.  * In most cases, the format of the flags cell uses the standard values  * defined in this header.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_PWM_PWM_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_PWM_PWM_H
end_define

begin_define
define|#
directive|define
name|PWM_POLARITY_INVERTED
value|(1<< 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

