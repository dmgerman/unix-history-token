begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Defines macros and constants for Renesas RZ/A1 pin controller pin  * muxing functions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_PINCTRL_RENESAS_RZA1_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_PINCTRL_RENESAS_RZA1_H
end_define

begin_define
define|#
directive|define
name|RZA1_PINS_PER_PORT
value|16
end_define

begin_comment
comment|/*  * Create the pin index from its bank and position numbers and store in  * the upper 16 bits the alternate function identifier  */
end_comment

begin_define
define|#
directive|define
name|RZA1_PINMUX
parameter_list|(
name|b
parameter_list|,
name|p
parameter_list|,
name|f
parameter_list|)
value|((b) * RZA1_PINS_PER_PORT + (p) | (f<< 16))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_PINCTRL_RENESAS_RZA1_H */
end_comment

end_unit

