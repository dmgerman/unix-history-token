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

begin_comment
comment|/* Bit 0 express polarity */
end_comment

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

begin_comment
comment|/* Bit 1 express single-endedness */
end_comment

begin_define
define|#
directive|define
name|GPIO_PUSH_PULL
value|0
end_define

begin_define
define|#
directive|define
name|GPIO_SINGLE_ENDED
value|2
end_define

begin_comment
comment|/* Bit 2 express Open drain or open source */
end_comment

begin_define
define|#
directive|define
name|GPIO_LINE_OPEN_SOURCE
value|0
end_define

begin_define
define|#
directive|define
name|GPIO_LINE_OPEN_DRAIN
value|4
end_define

begin_comment
comment|/*  * Open Drain/Collector is the combination of single-ended open drain interface.  * Open Source/Emitter is the combination of single-ended open source interface.  */
end_comment

begin_define
define|#
directive|define
name|GPIO_OPEN_DRAIN
value|(GPIO_SINGLE_ENDED | GPIO_LINE_OPEN_DRAIN)
end_define

begin_define
define|#
directive|define
name|GPIO_OPEN_SOURCE
value|(GPIO_SINGLE_ENDED | GPIO_LINE_OPEN_SOURCE)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

