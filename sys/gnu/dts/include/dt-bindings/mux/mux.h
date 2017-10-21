begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for most Multiplexer bindings.  *  * Most Multiplexer bindings specify an idle state. In most cases, the  * the multiplexer can be left as is when idle, and in some cases it can  * disconnect the input/output and leave the multiplexer in a high  * impedance state.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_MUX_MUX_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_MUX_MUX_H
end_define

begin_define
define|#
directive|define
name|MUX_IDLE_AS_IS
value|(-1)
end_define

begin_define
define|#
directive|define
name|MUX_IDLE_DISCONNECT
value|(-2)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

