begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Adam Glass  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Adam Glass.  * 4. The name of the Author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Adam Glass ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: idprom.h,v 1.2 1998/09/05 23:57:26 eeh Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IDPROM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IDPROM_H_
end_define

begin_comment
comment|/*  * ID prom format.  The ``host id'' is set up by taking the machine  * ID as the top byte and the hostid field as the remaining three.  * The id_xxx0 field appears to contain some other number.  The id_xxx1  * contains a bunch of 00's and a5's on my machines, suggesting it is  * not actually used.  The checksum seems to include them, however.  */
end_comment

begin_struct
struct|struct
name|idprom
block|{
name|u_char
name|id_format
decl_stmt|;
comment|/* format identifier (= 1) */
name|u_char
name|id_machine
decl_stmt|;
comment|/* machine type (see param.h) */
name|u_char
name|id_ether
index|[
literal|6
index|]
decl_stmt|;
comment|/* ethernet address */
name|int
name|id_date
decl_stmt|;
comment|/* date of manufacture */
name|u_char
name|id_hostid
index|[
literal|3
index|]
decl_stmt|;
comment|/* ``host id'' bytes */
name|u_char
name|id_checksum
decl_stmt|;
comment|/* xor of everything else */
name|char
name|id_undef
index|[
literal|16
index|]
decl_stmt|;
comment|/* undefined */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ID_SUN4_100
value|0x22
end_define

begin_define
define|#
directive|define
name|ID_SUN4_200
value|0x21
end_define

begin_define
define|#
directive|define
name|ID_SUN4_300
value|0x23
end_define

begin_define
define|#
directive|define
name|ID_SUN4_400
value|0x24
end_define

begin_define
define|#
directive|define
name|IDPROM_VERSION
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_IDPROM_H_ */
end_comment

end_unit

