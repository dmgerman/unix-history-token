begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)hpibvar.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_define
define|#
directive|define
name|HPIB_IPL
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 4)& 0x3) + 3)
end_define

begin_define
define|#
directive|define
name|HPIBA
value|32
end_define

begin_define
define|#
directive|define
name|HPIBB
value|1
end_define

begin_define
define|#
directive|define
name|HPIBC
value|8
end_define

begin_define
define|#
directive|define
name|HPIBA_BA
value|21
end_define

begin_define
define|#
directive|define
name|HPIBC_BA
value|30
end_define

begin_define
define|#
directive|define
name|HPIBA_IPL
value|3
end_define

begin_define
define|#
directive|define
name|CSA_BA
value|0x1F
end_define

begin_define
define|#
directive|define
name|IDS_WDMA
value|0x04
end_define

begin_define
define|#
directive|define
name|IDS_WRITE
value|0x08
end_define

begin_define
define|#
directive|define
name|IDS_IR
value|0x40
end_define

begin_define
define|#
directive|define
name|IDS_IE
value|0x80
end_define

begin_define
define|#
directive|define
name|IDS_DMA
parameter_list|(
name|x
parameter_list|)
value|(1<< (x))
end_define

begin_define
define|#
directive|define
name|C_DCL
value|0x14
end_define

begin_define
define|#
directive|define
name|C_LAG
value|0x20
end_define

begin_define
define|#
directive|define
name|C_UNL
value|0x3f
end_define

begin_define
define|#
directive|define
name|C_TAG
value|0x40
end_define

begin_define
define|#
directive|define
name|C_UNA
value|0x5e
end_define

begin_define
define|#
directive|define
name|C_UNT
value|0x5f
end_define

begin_define
define|#
directive|define
name|C_SCG
value|0x60
end_define

begin_struct
struct|struct
name|hpib_softc
block|{
name|struct
name|hp_ctlr
modifier|*
name|sc_hc
decl_stmt|;
name|int
name|sc_flags
decl_stmt|;
name|struct
name|devqueue
name|sc_dq
decl_stmt|;
name|struct
name|devqueue
name|sc_sq
decl_stmt|;
name|int
name|sc_ba
decl_stmt|;
name|int
name|sc_type
decl_stmt|;
name|char
modifier|*
name|sc_addr
decl_stmt|;
name|int
name|sc_count
decl_stmt|;
name|int
name|sc_curcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* sc_flags */
end_comment

begin_define
define|#
directive|define
name|HPIBF_IO
value|0x1
end_define

begin_define
define|#
directive|define
name|HPIBF_DONE
value|0x2
end_define

begin_define
define|#
directive|define
name|HPIBF_PPOLL
value|0x4
end_define

begin_define
define|#
directive|define
name|HPIBF_READ
value|0x8
end_define

begin_define
define|#
directive|define
name|HPIBF_DMA16
value|0x8000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|hpib_softc
name|hpib_softc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|caddr_t
name|internalhpib
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hpibtimeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hpibdmathresh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fhpibppwatch
name|__P
argument_list|(
operator|(
name|void
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nhpibppwatch
name|__P
argument_list|(
operator|(
name|void
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

