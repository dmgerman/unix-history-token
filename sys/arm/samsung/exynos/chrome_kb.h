begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_function_decl
name|void
name|ckb_ec_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|KEYMAP_LEN
value|75
end_define

begin_decl_stmt
name|pcell_t
name|default_keymap
index|[
name|KEYMAP_LEN
index|]
init|=
block|{
literal|0x0001007d
block|,
comment|/* lmeta */
literal|0x0002003b
block|,
comment|/* F1 */
literal|0x00030030
block|,
comment|/* B */
literal|0x00040044
block|,
comment|/* F10 */
literal|0x00060031
block|,
comment|/* N */
literal|0x0008000d
block|,
comment|/* = */
literal|0x000a0064
block|,
comment|/* ralt */
literal|0x01010001
block|,
comment|/* escape */
literal|0x0102003e
block|,
comment|/* F4 */
literal|0x01030022
block|,
comment|/* G */
literal|0x01040041
block|,
comment|/* F7 */
literal|0x01060023
block|,
comment|/* H */
literal|0x01080028
block|,
comment|/* ' */
literal|0x01090043
block|,
comment|/* F9 */
literal|0x010b000e
block|,
comment|/* backspace */
literal|0x0200001d
block|,
comment|/* lctrl */
literal|0x0201000f
block|,
comment|/* tab */
literal|0x0202003d
block|,
comment|/* F3 */
literal|0x02030014
block|,
comment|/* t */
literal|0x02040040
block|,
comment|/* F6 */
literal|0x0205001b
block|,
comment|/* ] */
literal|0x02060015
block|,
comment|/* y */
literal|0x02070056
block|,
comment|/* 102nd */
literal|0x0208001a
block|,
comment|/* [ */
literal|0x02090042
block|,
comment|/* F8 */
literal|0x03010029
block|,
comment|/* grave */
literal|0x0302003c
block|,
comment|/* F2 */
literal|0x03030006
block|,
comment|/* 5 */
literal|0x0304003f
block|,
comment|/* F5 */
literal|0x03060007
block|,
comment|/* 6 */
literal|0x0308000c
block|,
comment|/* - */
literal|0x030b002b
block|,
comment|/* \ */
literal|0x04000061
block|,
comment|/* rctrl */
literal|0x0401001e
block|,
comment|/* a */
literal|0x04020020
block|,
comment|/* d */
literal|0x04030021
block|,
comment|/* f */
literal|0x0404001f
block|,
comment|/* s */
literal|0x04050025
block|,
comment|/* k */
literal|0x04060024
block|,
comment|/* j */
literal|0x04080027
block|,
comment|/* ; */
literal|0x04090026
block|,
comment|/* l */
literal|0x040a002b
block|,
comment|/* \ */
literal|0x040b001c
block|,
comment|/* enter */
literal|0x0501002c
block|,
comment|/* z */
literal|0x0502002e
block|,
comment|/* c */
literal|0x0503002f
block|,
comment|/* v */
literal|0x0504002d
block|,
comment|/* x */
literal|0x05050033
block|,
comment|/* , */
literal|0x05060032
block|,
comment|/* m */
literal|0x0507002a
block|,
comment|/* lsh */
literal|0x05080035
block|,
comment|/* / */
literal|0x05090034
block|,
comment|/* . */
literal|0x050B0039
block|,
comment|/* space */
literal|0x06010002
block|,
comment|/* 1 */
literal|0x06020004
block|,
comment|/* 3 */
literal|0x06030005
block|,
comment|/* 4 */
literal|0x06040003
block|,
comment|/* 2 */
literal|0x06050009
block|,
comment|/* 8 */
literal|0x06060008
block|,
comment|/* 7 */
literal|0x0608000b
block|,
comment|/* 0 */
literal|0x0609000a
block|,
comment|/* 9 */
literal|0x060a0038
block|,
comment|/* lalt */
literal|0x060b0064
block|,
comment|/* down */
literal|0x060c0062
block|,
comment|/* right */
literal|0x07010010
block|,
comment|/* q */
literal|0x07020012
block|,
comment|/* e */
literal|0x07030013
block|,
comment|/* r */
literal|0x07040011
block|,
comment|/* w */
literal|0x07050017
block|,
comment|/* i */
literal|0x07060016
block|,
comment|/* u */
literal|0x07070036
block|,
comment|/* rsh */
literal|0x07080019
block|,
comment|/* p */
literal|0x07090018
block|,
comment|/* o */
literal|0x070b005F
block|,
comment|/* up */
literal|0x070c0061
block|,
comment|/* left */
block|}
decl_stmt|;
end_decl_stmt

end_unit

