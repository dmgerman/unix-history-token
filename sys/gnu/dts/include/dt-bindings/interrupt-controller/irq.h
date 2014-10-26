begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for most IRQ bindings.  *  * Most IRQ bindings include a flags cell as part of the IRQ specifier.  * In most cases, the format of the flags cell uses the standard values  * defined in this header.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_INTERRUPT_CONTROLLER_IRQ_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_INTERRUPT_CONTROLLER_IRQ_H
end_define

begin_define
define|#
directive|define
name|IRQ_TYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|IRQ_TYPE_EDGE_RISING
value|1
end_define

begin_define
define|#
directive|define
name|IRQ_TYPE_EDGE_FALLING
value|2
end_define

begin_define
define|#
directive|define
name|IRQ_TYPE_EDGE_BOTH
value|(IRQ_TYPE_EDGE_FALLING | IRQ_TYPE_EDGE_RISING)
end_define

begin_define
define|#
directive|define
name|IRQ_TYPE_LEVEL_HIGH
value|4
end_define

begin_define
define|#
directive|define
name|IRQ_TYPE_LEVEL_LOW
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

