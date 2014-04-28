begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_function_decl
name|void
name|ckb_ec_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|key
block|{
name|uint8_t
name|row
decl_stmt|;
name|uint8_t
name|col
decl_stmt|;
name|uint8_t
name|key
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KEYMAP_LEN
value|75
end_define

begin_decl_stmt
name|struct
name|key
name|keymap
index|[
name|KEYMAP_LEN
index|]
init|=
block|{
block|{
literal|0x00
block|,
literal|0x01
block|,
literal|0x7d
block|}
block|,
comment|/* lmeta */
block|{
literal|0x00
block|,
literal|0x02
block|,
literal|0x3b
block|}
block|,
comment|/* F1 */
block|{
literal|0x00
block|,
literal|0x03
block|,
literal|0x30
block|}
block|,
comment|/* B */
block|{
literal|0x00
block|,
literal|0x04
block|,
literal|0x44
block|}
block|,
comment|/* F10 */
block|{
literal|0x00
block|,
literal|0x06
block|,
literal|0x31
block|}
block|,
comment|/* N */
block|{
literal|0x00
block|,
literal|0x08
block|,
literal|0x0d
block|}
block|,
comment|/* = */
block|{
literal|0x00
block|,
literal|0x0a
block|,
literal|0x64
block|}
block|,
comment|/* ralt */
block|{
literal|0x01
block|,
literal|0x01
block|,
literal|0x01
block|}
block|,
comment|/* escape */
block|{
literal|0x01
block|,
literal|0x02
block|,
literal|0x3e
block|}
block|,
comment|/* F4 */
block|{
literal|0x01
block|,
literal|0x03
block|,
literal|0x22
block|}
block|,
comment|/* G */
block|{
literal|0x01
block|,
literal|0x04
block|,
literal|0x41
block|}
block|,
comment|/* F7 */
block|{
literal|0x01
block|,
literal|0x06
block|,
literal|0x23
block|}
block|,
comment|/* H */
block|{
literal|0x01
block|,
literal|0x08
block|,
literal|0x28
block|}
block|,
comment|/* ' */
block|{
literal|0x01
block|,
literal|0x09
block|,
literal|0x43
block|}
block|,
comment|/* F9 */
block|{
literal|0x01
block|,
literal|0x0b
block|,
literal|0x0e
block|}
block|,
comment|/* backspace */
block|{
literal|0x02
block|,
literal|0x00
block|,
literal|0x1d
block|}
block|,
comment|/* lctrl */
block|{
literal|0x02
block|,
literal|0x01
block|,
literal|0x0f
block|}
block|,
comment|/* tab */
block|{
literal|0x02
block|,
literal|0x02
block|,
literal|0x3d
block|}
block|,
comment|/* F3 */
block|{
literal|0x02
block|,
literal|0x03
block|,
literal|0x14
block|}
block|,
comment|/* t */
block|{
literal|0x02
block|,
literal|0x04
block|,
literal|0x40
block|}
block|,
comment|/* F6 */
block|{
literal|0x02
block|,
literal|0x05
block|,
literal|0x1b
block|}
block|,
comment|/* ] */
block|{
literal|0x02
block|,
literal|0x06
block|,
literal|0x15
block|}
block|,
comment|/* y */
block|{
literal|0x02
block|,
literal|0x07
block|,
literal|0x56
block|}
block|,
comment|/* 102nd */
block|{
literal|0x02
block|,
literal|0x08
block|,
literal|0x1a
block|}
block|,
comment|/* [ */
block|{
literal|0x02
block|,
literal|0x09
block|,
literal|0x42
block|}
block|,
comment|/* F8 */
block|{
literal|0x03
block|,
literal|0x01
block|,
literal|0x29
block|}
block|,
comment|/* grave */
block|{
literal|0x03
block|,
literal|0x02
block|,
literal|0x3c
block|}
block|,
comment|/* F2 */
block|{
literal|0x03
block|,
literal|0x03
block|,
literal|0x06
block|}
block|,
comment|/* 5 */
block|{
literal|0x03
block|,
literal|0x04
block|,
literal|0x3f
block|}
block|,
comment|/* F5 */
block|{
literal|0x03
block|,
literal|0x06
block|,
literal|0x07
block|}
block|,
comment|/* 6 */
block|{
literal|0x03
block|,
literal|0x08
block|,
literal|0x0c
block|}
block|,
comment|/* - */
block|{
literal|0x03
block|,
literal|0x0b
block|,
literal|0x2b
block|}
block|,
comment|/* \ */
block|{
literal|0x04
block|,
literal|0x00
block|,
literal|0x61
block|}
block|,
comment|/* rctrl */
block|{
literal|0x04
block|,
literal|0x01
block|,
literal|0x1e
block|}
block|,
comment|/* a */
block|{
literal|0x04
block|,
literal|0x02
block|,
literal|0x20
block|}
block|,
comment|/* d */
block|{
literal|0x04
block|,
literal|0x03
block|,
literal|0x21
block|}
block|,
comment|/* f */
block|{
literal|0x04
block|,
literal|0x04
block|,
literal|0x1f
block|}
block|,
comment|/* s */
block|{
literal|0x04
block|,
literal|0x05
block|,
literal|0x25
block|}
block|,
comment|/* k */
block|{
literal|0x04
block|,
literal|0x06
block|,
literal|0x24
block|}
block|,
comment|/* j */
block|{
literal|0x04
block|,
literal|0x08
block|,
literal|0x27
block|}
block|,
comment|/* ; */
block|{
literal|0x04
block|,
literal|0x09
block|,
literal|0x26
block|}
block|,
comment|/* l */
block|{
literal|0x04
block|,
literal|0x0a
block|,
literal|0x2b
block|}
block|,
comment|/* \ */
block|{
literal|0x04
block|,
literal|0x0b
block|,
literal|0x1c
block|}
block|,
comment|/* enter */
block|{
literal|0x05
block|,
literal|0x01
block|,
literal|0x2c
block|}
block|,
comment|/* z */
block|{
literal|0x05
block|,
literal|0x02
block|,
literal|0x2e
block|}
block|,
comment|/* c */
block|{
literal|0x05
block|,
literal|0x03
block|,
literal|0x2f
block|}
block|,
comment|/* v */
block|{
literal|0x05
block|,
literal|0x04
block|,
literal|0x2d
block|}
block|,
comment|/* x */
block|{
literal|0x05
block|,
literal|0x05
block|,
literal|0x33
block|}
block|,
comment|/* , */
block|{
literal|0x05
block|,
literal|0x06
block|,
literal|0x32
block|}
block|,
comment|/* m */
block|{
literal|0x05
block|,
literal|0x07
block|,
literal|0x2a
block|}
block|,
comment|/* lsh */
block|{
literal|0x05
block|,
literal|0x08
block|,
literal|0x35
block|}
block|,
comment|/* / */
block|{
literal|0x05
block|,
literal|0x09
block|,
literal|0x34
block|}
block|,
comment|/* . */
block|{
literal|0x05
block|,
literal|0x0B
block|,
literal|0x39
block|}
block|,
comment|/* space */
block|{
literal|0x06
block|,
literal|0x01
block|,
literal|0x02
block|}
block|,
comment|/* 1 */
block|{
literal|0x06
block|,
literal|0x02
block|,
literal|0x04
block|}
block|,
comment|/* 3 */
block|{
literal|0x06
block|,
literal|0x03
block|,
literal|0x05
block|}
block|,
comment|/* 4 */
block|{
literal|0x06
block|,
literal|0x04
block|,
literal|0x03
block|}
block|,
comment|/* 2 */
block|{
literal|0x06
block|,
literal|0x05
block|,
literal|0x09
block|}
block|,
comment|/* 8 */
block|{
literal|0x06
block|,
literal|0x06
block|,
literal|0x08
block|}
block|,
comment|/* 7 */
block|{
literal|0x06
block|,
literal|0x08
block|,
literal|0x0b
block|}
block|,
comment|/* 0 */
block|{
literal|0x06
block|,
literal|0x09
block|,
literal|0x0a
block|}
block|,
comment|/* 9 */
block|{
literal|0x06
block|,
literal|0x0a
block|,
literal|0x38
block|}
block|,
comment|/* lalt */
block|{
literal|0x06
block|,
literal|0x0b
block|,
literal|0x64
block|}
block|,
comment|/* down */
block|{
literal|0x06
block|,
literal|0x0c
block|,
literal|0x62
block|}
block|,
comment|/* right */
block|{
literal|0x07
block|,
literal|0x01
block|,
literal|0x10
block|}
block|,
comment|/* q */
block|{
literal|0x07
block|,
literal|0x02
block|,
literal|0x12
block|}
block|,
comment|/* e */
block|{
literal|0x07
block|,
literal|0x03
block|,
literal|0x13
block|}
block|,
comment|/* r */
block|{
literal|0x07
block|,
literal|0x04
block|,
literal|0x11
block|}
block|,
comment|/* w */
block|{
literal|0x07
block|,
literal|0x05
block|,
literal|0x17
block|}
block|,
comment|/* i */
block|{
literal|0x07
block|,
literal|0x06
block|,
literal|0x16
block|}
block|,
comment|/* u */
block|{
literal|0x07
block|,
literal|0x07
block|,
literal|0x36
block|}
block|,
comment|/* rsh */
block|{
literal|0x07
block|,
literal|0x08
block|,
literal|0x19
block|}
block|,
comment|/* p */
block|{
literal|0x07
block|,
literal|0x09
block|,
literal|0x18
block|}
block|,
comment|/* o */
block|{
literal|0x07
block|,
literal|0x0b
block|,
literal|0x5F
block|}
block|,
comment|/* up */
block|{
literal|0x07
block|,
literal|0x0c
block|,
literal|0x61
block|}
block|,
comment|/* left */
block|}
decl_stmt|;
end_decl_stmt

end_unit

