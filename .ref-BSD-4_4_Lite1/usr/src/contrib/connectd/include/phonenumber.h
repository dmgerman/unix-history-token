begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Bill Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)phonenumber.h	5.2 (Berkeley) 5/29/93  */
end_comment

begin_comment
comment|/*  * Telephone number address processing  */
end_comment

begin_comment
comment|/*  * Structures returned by network  * data base library.  */
end_comment

begin_struct
struct|struct
name|phonenumberent
block|{
name|char
modifier|*
name|pn_name
decl_stmt|;
comment|/* directory listing name */
name|char
modifier|*
modifier|*
name|pn_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|pn_length
decl_stmt|;
comment|/* length of phone number address */
name|char
modifier|*
modifier|*
name|pn_addr_list
decl_stmt|;
comment|/* list of addresses from name server */
name|struct
name|pn_addr
modifier|*
name|pn_addrtype
decl_stmt|;
comment|/* list of phone number address types */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pn_addrtype
block|{
name|u_char
name|pn_tos
decl_stmt|;
comment|/* type of service */
define|#
directive|define
name|PNT_POTS
value|0
comment|/* plain ordinary telephone service */
define|#
directive|define
name|PNT_ISDN
value|1
comment|/* Integrated Services Digital Network*/
name|int
name|pn_tnplan
decl_stmt|;
comment|/* type of numbering plan */
define|#
directive|define
name|PNAT_INTL
value|0x21
comment|/* International number */
define|#
directive|define
name|PNAT_NATNL
value|0x41
comment|/* National number */
define|#
directive|define
name|PNAT_LOCAL
value|0x81
comment|/* Local(directory) number */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|phonenumberent
modifier|*
name|getphonenumberbyname
argument_list|()
decl_stmt|,
modifier|*
name|getnamebyphonenumber
argument_list|()
decl_stmt|,
modifier|*
name|getphonenumberent
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Error return codes from getphonenumberbyname() and getnamebyphonenumber()  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pn_errno
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ENTRY_NOT_FOUND
value|1
end_define

begin_comment
comment|/* Authoritive Answer Host not found */
end_comment

begin_define
define|#
directive|define
name|TRY_AGAIN
value|2
end_define

begin_comment
comment|/* Non-Authoritive Host not found, or SERVERFAIL */
end_comment

begin_define
define|#
directive|define
name|NO_RECOVERY
value|3
end_define

begin_comment
comment|/* Non recoverable errors, FORMERR, REFUSED, NOTIMP */
end_comment

begin_define
define|#
directive|define
name|NO_ADDRESS
value|4
end_define

begin_comment
comment|/* Valid host name, no address, look for MX record */
end_comment

end_unit

