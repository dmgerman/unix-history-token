begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Poul-Henning Kamp  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * This file defines the ABI between the userland gpib library and the  * kernel.  This file should not be used anywhere else.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_typedef
typedef|typedef
name|void
name|ibsrq_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_enum
enum|enum
name|ibfoo_id
block|{
name|__ID_INVALID
init|=
literal|0
block|,
name|__ID_IBASK
block|,
name|__ID_IBBNA
block|,
name|__ID_IBCAC
block|,
name|__ID_IBCLR
block|,
name|__ID_IBCMD
block|,
name|__ID_IBCMDA
block|,
name|__ID_IBCONFIG
block|,
name|__ID_IBDEV
block|,
name|__ID_IBDIAG
block|,
name|__ID_IBDMA
block|,
name|__ID_IBEOS
block|,
name|__ID_IBEOT
block|,
name|__ID_IBEVENT
block|,
name|__ID_IBFIND
block|,
name|__ID_IBGTS
block|,
name|__ID_IBIST
block|,
name|__ID_IBLINES
block|,
name|__ID_IBLLO
block|,
name|__ID_IBLN
block|,
name|__ID_IBLOC
block|,
name|__ID_IBONL
block|,
name|__ID_IBPAD
block|,
name|__ID_IBPCT
block|,
name|__ID_IBPOKE
block|,
name|__ID_IBPPC
block|,
name|__ID_IBRD
block|,
name|__ID_IBRDA
block|,
name|__ID_IBRDF
block|,
name|__ID_IBRDKEY
block|,
name|__ID_IBRPP
block|,
name|__ID_IBRSC
block|,
name|__ID_IBRSP
block|,
name|__ID_IBRSV
block|,
name|__ID_IBSAD
block|,
name|__ID_IBSGNL
block|,
name|__ID_IBSIC
block|,
name|__ID_IBSRE
block|,
name|__ID_IBSRQ
block|,
name|__ID_IBSTOP
block|,
name|__ID_IBTMO
block|,
name|__ID_IBTRAP
block|,
name|__ID_IBTRG
block|,
name|__ID_IBWAIT
block|,
name|__ID_IBWRT
block|,
name|__ID_IBWRTA
block|,
name|__ID_IBWRTF
block|,
name|__ID_IBWRTKEY
block|,
name|__ID_IBXTRC
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|__F_HANDLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|__F_SPR
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|__F_BUFFER
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|__F_RETVAL
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|__F_BDNAME
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|__F_MASK
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|__F_PADVAL
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|__F_SADVAL
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|__F_CNT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|__F_TMO
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|__F_EOS
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|__F_PPR
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|__F_EOT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|__F_V
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|__F_VALUE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|__F_SAD
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|__F_BOARDID
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|__F_OPTION
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|__F_FLNAME
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|__F_FUNC
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|__F_LINES
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|__F_PAD
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|__F_MODE
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|__F_LISTENFLAG
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|__F_EVENT
value|(1<< 24)
end_define

begin_struct
struct|struct
name|ibarg
block|{
name|enum
name|ibfoo_id
name|__ident
decl_stmt|;
name|unsigned
name|int
name|__field
decl_stmt|;
name|int
name|__retval
decl_stmt|;
name|int
name|__ibsta
decl_stmt|;
name|int
name|__iberr
decl_stmt|;
name|int
name|__ibcnt
decl_stmt|;
name|int
name|handle
decl_stmt|;
name|char
modifier|*
name|spr
decl_stmt|;
name|void
modifier|*
name|buffer
decl_stmt|;
name|int
modifier|*
name|retval
decl_stmt|;
name|char
modifier|*
name|bdname
decl_stmt|;
name|int
name|mask
decl_stmt|;
name|int
name|padval
decl_stmt|;
name|int
name|sadval
decl_stmt|;
name|long
name|cnt
decl_stmt|;
name|int
name|tmo
decl_stmt|;
name|int
name|eos
decl_stmt|;
name|char
modifier|*
name|ppr
decl_stmt|;
name|int
name|eot
decl_stmt|;
name|int
name|v
decl_stmt|;
name|int
name|value
decl_stmt|;
name|int
name|sad
decl_stmt|;
name|int
name|boardID
decl_stmt|;
name|int
name|option
decl_stmt|;
name|char
modifier|*
name|flname
decl_stmt|;
name|ibsrq_t
modifier|*
name|func
decl_stmt|;
name|short
modifier|*
name|lines
decl_stmt|;
name|int
name|pad
decl_stmt|;
name|int
name|mode
decl_stmt|;
name|short
modifier|*
name|listenflag
decl_stmt|;
name|short
modifier|*
name|event
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GPIB_IBFOO
value|_IOWR(4, 0, struct ibarg)
end_define

end_unit

