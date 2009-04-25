begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB2_REVISION_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_REVISION_H_
end_define

begin_comment
comment|/*  * The "USB_SPEED" macro defines all the supported USB speeds.  */
end_comment

begin_enum
enum|enum
block|{
name|USB_SPEED_VARIABLE
block|,
name|USB_SPEED_LOW
block|,
name|USB_SPEED_FULL
block|,
name|USB_SPEED_HIGH
block|,
name|USB_SPEED_SUPER
block|,
name|USB_SPEED_MAX
block|}
enum|;
end_enum

begin_comment
comment|/*  * The "USB_REV" macro defines all the supported USB revisions.  */
end_comment

begin_enum
enum|enum
block|{
name|USB_REV_UNKNOWN
block|,
name|USB_REV_PRE_1_0
block|,
name|USB_REV_1_0
block|,
name|USB_REV_1_1
block|,
name|USB_REV_2_0
block|,
name|USB_REV_2_5
block|,
name|USB_REV_3_0
block|,
name|USB_REV_MAX
block|}
enum|;
end_enum

begin_comment
comment|/*  * The "USB_MODE" macro defines all the supported USB modes.  */
end_comment

begin_enum
enum|enum
block|{
name|USB_MODE_HOST
block|,
name|USB_MODE_DEVICE
block|,
name|USB_MODE_MAX
block|}
enum|;
end_enum

begin_comment
comment|/*  * The "USB_MODE" macro defines all the supported device states.  */
end_comment

begin_enum
enum|enum
name|usb_dev_state
block|{
name|USB_STATE_DETACHED
block|,
name|USB_STATE_ATTACHED
block|,
name|USB_STATE_POWERED
block|,
name|USB_STATE_ADDRESSED
block|,
name|USB_STATE_CONFIGURED
block|,
name|USB_STATE_SUSPENDED
block|,
name|USB_STATE_MAX
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_REVISION_H_ */
end_comment

end_unit

