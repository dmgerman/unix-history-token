begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)kbd.h	8.1 (Berkeley) 6/11/93  *  * from: $Header: kbd.h,v 1.5 92/11/26 01:15:33 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Keyboard `registers'.  (This should be called kbd_reg.h but we need to  * be compatible.)  */
end_comment

begin_comment
comment|/*  * Control codes sent from type 2, 3, and 4 keyboards.  *  * Note that KBD_RESET is followed by a keyboard ID, while KBD_IDLE is not.  * KBD_IDLE does not take the place of any `up' transitions (it merely occurs  * after them).  */
end_comment

begin_define
define|#
directive|define
name|KBD_RESET
value|0xff
end_define

begin_comment
comment|/* keyboard `reset' response */
end_comment

begin_define
define|#
directive|define
name|KBD_IDLE
value|0x7f
end_define

begin_comment
comment|/* keyboard `all keys are up' code */
end_comment

begin_comment
comment|/* Keyboard IDs */
end_comment

begin_define
define|#
directive|define
name|KB_SUN2
value|2
end_define

begin_comment
comment|/* type 2 keyboard */
end_comment

begin_define
define|#
directive|define
name|KB_SUN3
value|3
end_define

begin_comment
comment|/* type 3 keyboard */
end_comment

begin_define
define|#
directive|define
name|KB_SUN4
value|4
end_define

begin_comment
comment|/* type 4 keyboard */
end_comment

begin_comment
comment|/* Key codes are in 0x00..0x7e; KBD_UP is set if the key goes up */
end_comment

begin_define
define|#
directive|define
name|KBD_KEYMASK
value|0x7f
end_define

begin_comment
comment|/* keyboard key mask */
end_comment

begin_define
define|#
directive|define
name|KBD_UP
value|0x80
end_define

begin_comment
comment|/* keyboard `up' transition */
end_comment

begin_comment
comment|/* Keyboard codes needed to recognize the L1-A sequence */
end_comment

begin_define
define|#
directive|define
name|KBD_L1
value|1
end_define

begin_comment
comment|/* keyboard code for `L1' key */
end_comment

begin_define
define|#
directive|define
name|KBD_A
value|77
end_define

begin_comment
comment|/* keyboard code for `A' key */
end_comment

begin_comment
comment|/* Control codes sent to the various keyboards */
end_comment

begin_define
define|#
directive|define
name|KBD_CMD_RESET
value|1
end_define

begin_comment
comment|/* reset keyboard */
end_comment

begin_define
define|#
directive|define
name|KBD_CMD_BELL
value|2
end_define

begin_comment
comment|/* turn bell on */
end_comment

begin_define
define|#
directive|define
name|KBD_CMD_NOBELL
value|3
end_define

begin_comment
comment|/* turn bell off */
end_comment

begin_define
define|#
directive|define
name|KBD_CMD_CLICK
value|10
end_define

begin_comment
comment|/* turn keyclick on */
end_comment

begin_define
define|#
directive|define
name|KBD_CMD_NOCLICK
value|11
end_define

begin_comment
comment|/* turn keyclick off */
end_comment

end_unit

