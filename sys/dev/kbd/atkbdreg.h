begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Kazutaka YOKOTA<yokota@zodiac.mech.utsunomiya-u.ac.jp>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_KBD_ATKBDREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_KBD_ATKBDREG_H_
end_define

begin_define
define|#
directive|define
name|ATKBD_DRIVER_NAME
value|"atkbd"
end_define

begin_comment
comment|/* device configuration flags (atkbdprobe, atkbdattach) */
end_comment

begin_define
define|#
directive|define
name|KB_CONF_FAIL_IF_NO_KBD
value|(1<< 0)
end_define

begin_comment
comment|/* don't install if no kbd is found */
end_comment

begin_define
define|#
directive|define
name|KB_CONF_NO_RESET
value|(1<< 1)
end_define

begin_comment
comment|/* don't reset the keyboard */
end_comment

begin_define
define|#
directive|define
name|KB_CONF_ALT_SCANCODESET
value|(1<< 2)
end_define

begin_comment
comment|/* assume the XT type keyboard */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|atkbd_probe_unit
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|ctlr
parameter_list|,
name|int
name|irq
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atkbd_attach_unit
parameter_list|(
name|int
name|unit
parameter_list|,
name|keyboard_t
modifier|*
modifier|*
name|kbd
parameter_list|,
name|int
name|ctlr
parameter_list|,
name|int
name|irq
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_KBD_ATKBDREG_H_ */
end_comment

end_unit

