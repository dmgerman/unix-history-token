begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Damjan Marion<dmarion@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AM335X_SCM_PADCONF_H
end_ifndef

begin_define
define|#
directive|define
name|AM335X_SCM_PADCONF_H
end_define

begin_define
define|#
directive|define
name|SLEWCTRL
value|(0x01<< 6)
end_define

begin_comment
comment|/* faster(0) or slower(1) slew rate. */
end_comment

begin_define
define|#
directive|define
name|RXACTIVE
value|(0x01<< 5)
end_define

begin_comment
comment|/* Input enable value for the Pad */
end_comment

begin_define
define|#
directive|define
name|PULLTYPESEL
value|(0x01<< 4)
end_define

begin_comment
comment|/* Pad pullup/pulldown type selection */
end_comment

begin_define
define|#
directive|define
name|PULLUDEN
value|(0x01<< 3)
end_define

begin_comment
comment|/* Pullup/pulldown disabled */
end_comment

begin_define
define|#
directive|define
name|PADCONF_OUTPUT
value|(PULLUDEN)
end_define

begin_define
define|#
directive|define
name|PADCONF_OUTPUT_PULLUP
value|(PULLTYPESEL)
end_define

begin_define
define|#
directive|define
name|PADCONF_OUTPUT_PULLDOWN
value|(0)
end_define

begin_define
define|#
directive|define
name|PADCONF_INPUT
value|(RXACTIVE | PULLUDEN)
end_define

begin_define
define|#
directive|define
name|PADCONF_INPUT_PULLUP
value|(RXACTIVE | PULLTYPESEL)
end_define

begin_define
define|#
directive|define
name|PADCONF_INPUT_PULLDOWN
value|(RXACTIVE)
end_define

begin_define
define|#
directive|define
name|PADCONF_INPUT_PULLUP_SLOW
value|(PADCONF_INPUT_PULLUP | SLEWCTRL)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ti_pinmux_device
name|ti_am335x_pinmux_dev
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AM335X_SCM_PADCONF_H */
end_comment

end_unit

