begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Keyboard definitions  *	from: unknown origin, 386BSD 0.1  *	$Id: kbd.h,v 1.4 1995/05/30 08:02:38 rgrimes Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_KBD_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_ISA_KBD_H_
value|1
end_define

begin_comment
comment|/* Reference:	IBM AT Technical Reference Manual,  * pp. 1-38 to 1-43, 4-3 to 4-22  */
end_comment

begin_comment
comment|/* commands and responses */
end_comment

begin_define
define|#
directive|define
name|KBC_RESET
value|0xFF
end_define

begin_comment
comment|/* Reset the keyboard */
end_comment

begin_define
define|#
directive|define
name|KBC_STSIND
value|0xED
end_define

begin_comment
comment|/* set keyboard status indicators */
end_comment

begin_define
define|#
directive|define
name|KBR_OVERRUN
value|0xFE
end_define

begin_comment
comment|/* Keyboard flooded */
end_comment

begin_define
define|#
directive|define
name|KBR_RESEND
value|0xFE
end_define

begin_comment
comment|/* Keyboard needs resend of command */
end_comment

begin_define
define|#
directive|define
name|KBR_ACK
value|0xFA
end_define

begin_comment
comment|/* Keyboard did receive command */
end_comment

begin_define
define|#
directive|define
name|KBR_RSTDONE
value|0xAA
end_define

begin_comment
comment|/* Keyboard reset complete */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_ISA_KBD_H_ */
end_comment

end_unit

