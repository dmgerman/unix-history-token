begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 University of Utah.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Mark Davies of the Department of Computer  * Science, Victoria University of Wellington, New Zealand.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: grf_hyreg.h 1.1 92/01/22$  *  *	@(#)grf_hyreg.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_include
include|#
directive|include
file|<hp/dev/iotypes.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_struct
struct|struct
name|hyboxfb
block|{
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|reset
decl_stmt|;
comment|/* reset register		0x01 */
name|vu_char
name|fb_address
decl_stmt|;
comment|/* frame buffer address 	0x02 */
name|vu_char
name|interrupt
decl_stmt|;
comment|/* interrupt register		0x03 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|fbwmsb
decl_stmt|;
comment|/* frame buffer width MSB	0x05 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|fbwlsb
decl_stmt|;
comment|/* frame buffer width MSB	0x07 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|fbhmsb
decl_stmt|;
comment|/* frame buffer height MSB	0x09 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|fbhlsb
decl_stmt|;
comment|/* frame buffer height MSB	0x0b */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|dwmsb
decl_stmt|;
comment|/* display width MSB		0x0d */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|dwlsb
decl_stmt|;
comment|/* display width MSB		0x0f */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|dhmsb
decl_stmt|;
comment|/* display height MSB		0x11 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|dhlsb
decl_stmt|;
comment|/* display height MSB		0x13 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|fbid
decl_stmt|;
comment|/* Scondary frame buffer id	0x15 */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|bits
decl_stmt|;
comment|/* square(0)/double-high(1) 	0x17 */
name|u_char
name|f1
index|[
literal|0x5b
operator|-
literal|0x17
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|num_planes
decl_stmt|;
comment|/* number of color planes       0x5b */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|fbomsb
decl_stmt|;
comment|/* frame buffer offset MSB	0x5d */
name|u_char
label|:
literal|8
expr_stmt|;
name|vu_char
name|fbolsb
decl_stmt|;
comment|/* frame buffer offset LSB	0x5f */
name|u_char
name|f2
index|[
literal|0x4000
operator|-
literal|0x5f
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|nblank
decl_stmt|;
comment|/* display enable planes      0x4000 */
block|}
struct|;
end_struct

end_unit

