begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Atsushi Murai (amurai@spec.co.jp)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Atsushi Murai(amurai@spec.co.jp)``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)iso_rrip.h  *	$Id: iso_rrip.h,v 1.3 1993/10/25 19:43:02 rgrimes Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISOFS_ISO_RRIP_H_
end_ifndef

begin_define
define|#
directive|define
name|_ISOFS_ISO_RRIP_H_
value|1
end_define

begin_comment
comment|/*  *	Analyze function flag  */
end_comment

begin_define
define|#
directive|define
name|ISO_SUSP_ATTR
value|0x0001
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_DEVICE
value|0x0002
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_SLINK
value|0x0004
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_ALTNAME
value|0x0008
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_CLINK
value|0x0010
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_PLINK
value|0x0020
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_RELDIR
value|0x0040
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_TSTAMP
value|0x0080
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_IDFLAG
value|0x0100
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_EXFLAG
value|0x0200
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_UNKNOWN
value|0x0400
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|ISO_RRIP_INODE
name|inode
decl_stmt|;
name|u_short
name|iso_altlen
decl_stmt|;
comment|/* Alt Name length */
name|u_short
name|iso_symlen
decl_stmt|;
comment|/* Symbol Name length */
name|char
modifier|*
name|iso_altname
decl_stmt|;
comment|/* Alt Name (no Null terminated ) */
name|char
modifier|*
name|iso_symname
decl_stmt|;
comment|/* Symbol Name (no NULL termninated )*/
block|}
name|ISO_RRIP_ANALYZE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISOFS_ISO_RRIP_H_ */
end_comment

end_unit

