begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Poul-Henning Kamp<phk@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_IEEE488_UGPIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_IEEE488_UGPIB_H_
end_define

begin_comment
comment|/* ibfoo() return values */
end_comment

begin_define
define|#
directive|define
name|EDVR
value|0
end_define

begin_comment
comment|/* System error				*/
end_comment

begin_define
define|#
directive|define
name|ECIC
value|1
end_define

begin_comment
comment|/* Not Active Controller		*/
end_comment

begin_define
define|#
directive|define
name|ENOL
value|2
end_define

begin_comment
comment|/* Nobody listening			*/
end_comment

begin_define
define|#
directive|define
name|EADR
value|3
end_define

begin_comment
comment|/* Controller not addressed		*/
end_comment

begin_define
define|#
directive|define
name|EARG
value|4
end_define

begin_comment
comment|/* Invalid argument			*/
end_comment

begin_define
define|#
directive|define
name|ESAC
value|5
end_define

begin_comment
comment|/* Not System Controller		*/
end_comment

begin_define
define|#
directive|define
name|EABO
value|6
end_define

begin_comment
comment|/* I/O Aborted/Time out			*/
end_comment

begin_define
define|#
directive|define
name|ENEB
value|7
end_define

begin_comment
comment|/* No such controller			*/
end_comment

begin_define
define|#
directive|define
name|EOIP
value|10
end_define

begin_comment
comment|/* Async I/O in progress		*/
end_comment

begin_define
define|#
directive|define
name|ECAP
value|11
end_define

begin_comment
comment|/* No such capability			*/
end_comment

begin_define
define|#
directive|define
name|EFSO
value|12
end_define

begin_comment
comment|/* File system error			*/
end_comment

begin_define
define|#
directive|define
name|EBUS
value|14
end_define

begin_comment
comment|/* Command byte xfer error		*/
end_comment

begin_define
define|#
directive|define
name|ESTB
value|15
end_define

begin_comment
comment|/* Serial poll status byte lost		*/
end_comment

begin_define
define|#
directive|define
name|ESRQ
value|16
end_define

begin_comment
comment|/* SRQ line stuck			*/
end_comment

begin_define
define|#
directive|define
name|ETAB
value|20
end_define

begin_comment
comment|/* Table problem			*/
end_comment

begin_comment
comment|/* ibsta bits */
end_comment

begin_define
define|#
directive|define
name|ERR
value|(1<<15)
end_define

begin_comment
comment|/* Error				*/
end_comment

begin_define
define|#
directive|define
name|TIMO
value|(1<<14)
end_define

begin_comment
comment|/* Timeout				*/
end_comment

begin_define
define|#
directive|define
name|END
value|(1<<13)
end_define

begin_comment
comment|/* EOI/EOS				*/
end_comment

begin_define
define|#
directive|define
name|SRQI
value|(1<<12)
end_define

begin_comment
comment|/* SRQ					*/
end_comment

begin_define
define|#
directive|define
name|RQS
value|(1<<11)
end_define

begin_comment
comment|/* Device requests service		*/
end_comment

begin_define
define|#
directive|define
name|SPOLL
value|(1<<10)
end_define

begin_comment
comment|/* Serial Poll				*/
end_comment

begin_define
define|#
directive|define
name|EVENT
value|(1<<9)
end_define

begin_comment
comment|/* Event occured			*/
end_comment

begin_define
define|#
directive|define
name|CMPL
value|(1<<8)
end_define

begin_comment
comment|/* I/O complete				*/
end_comment

begin_define
define|#
directive|define
name|LOK
value|(1<<7)
end_define

begin_comment
comment|/* Lockout				*/
end_comment

begin_define
define|#
directive|define
name|REM
value|(1<<6)
end_define

begin_comment
comment|/* Remote				*/
end_comment

begin_define
define|#
directive|define
name|CIC
value|(1<<5)
end_define

begin_comment
comment|/* CIC					*/
end_comment

begin_define
define|#
directive|define
name|ATN
value|(1<<4)
end_define

begin_comment
comment|/* ATN					*/
end_comment

begin_define
define|#
directive|define
name|TACS
value|(1<<3)
end_define

begin_comment
comment|/* Talker				*/
end_comment

begin_define
define|#
directive|define
name|LACS
value|(1<<2)
end_define

begin_comment
comment|/* Listener				*/
end_comment

begin_define
define|#
directive|define
name|DTAS
value|(1<<1)
end_define

begin_comment
comment|/* Device trigger status		*/
end_comment

begin_define
define|#
directive|define
name|DCAS
value|(1<<0)
end_define

begin_comment
comment|/* Device clear state			*/
end_comment

begin_comment
comment|/* Timeouts */
end_comment

begin_define
define|#
directive|define
name|TNONE
value|0
end_define

begin_define
define|#
directive|define
name|T10us
value|1
end_define

begin_define
define|#
directive|define
name|T30us
value|2
end_define

begin_define
define|#
directive|define
name|T100us
value|3
end_define

begin_define
define|#
directive|define
name|T300us
value|4
end_define

begin_define
define|#
directive|define
name|T1ms
value|5
end_define

begin_define
define|#
directive|define
name|T3ms
value|6
end_define

begin_define
define|#
directive|define
name|T10ms
value|7
end_define

begin_define
define|#
directive|define
name|T30ms
value|8
end_define

begin_define
define|#
directive|define
name|T100ms
value|9
end_define

begin_define
define|#
directive|define
name|T300ms
value|10
end_define

begin_define
define|#
directive|define
name|T1s
value|11
end_define

begin_define
define|#
directive|define
name|T3s
value|12
end_define

begin_define
define|#
directive|define
name|T10s
value|13
end_define

begin_define
define|#
directive|define
name|T30s
value|14
end_define

begin_define
define|#
directive|define
name|T100s
value|15
end_define

begin_define
define|#
directive|define
name|T300s
value|16
end_define

begin_define
define|#
directive|define
name|T1000s
value|17
end_define

begin_comment
comment|/* EOS bits */
end_comment

begin_define
define|#
directive|define
name|REOS
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|XEOS
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|BIN
value|(1<< 12)
end_define

begin_comment
comment|/* Bus commands */
end_comment

begin_define
define|#
directive|define
name|GTL
value|0x01
end_define

begin_comment
comment|/* Go To Local				*/
end_comment

begin_define
define|#
directive|define
name|SDC
value|0x04
end_define

begin_comment
comment|/* Selected Device Clear		*/
end_comment

begin_define
define|#
directive|define
name|GET
value|0x08
end_define

begin_comment
comment|/* Group Execute Trigger		*/
end_comment

begin_define
define|#
directive|define
name|LAD
value|0x20
end_define

begin_comment
comment|/* Listen address			*/
end_comment

begin_define
define|#
directive|define
name|UNL
value|0x3F
end_define

begin_comment
comment|/* Unlisten				*/
end_comment

begin_define
define|#
directive|define
name|TAD
value|0x40
end_define

begin_comment
comment|/* Talk address				*/
end_comment

begin_define
define|#
directive|define
name|UNT
value|0x5F
end_define

begin_comment
comment|/* Untalk				*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|ibcnt
decl_stmt|,
name|iberr
decl_stmt|,
name|ibsta
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ibask
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|option
parameter_list|,
name|int
modifier|*
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibbna
parameter_list|(
name|int
name|handle
parameter_list|,
name|char
modifier|*
name|bdname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcac
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibclr
parameter_list|(
name|int
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcmd
parameter_list|(
name|int
name|handle
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|long
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcmda
parameter_list|(
name|int
name|handle
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|long
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibconfig
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|option
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibdev
parameter_list|(
name|int
name|boardID
parameter_list|,
name|int
name|pad
parameter_list|,
name|int
name|sad
parameter_list|,
name|int
name|tmo
parameter_list|,
name|int
name|eot
parameter_list|,
name|int
name|eos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibdiag
parameter_list|(
name|int
name|handle
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|long
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibdma
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibeos
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|eos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibeot
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|eot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibevent
parameter_list|(
name|int
name|handle
parameter_list|,
name|short
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibfind
parameter_list|(
name|char
modifier|*
name|bdname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibgts
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibist
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iblines
parameter_list|(
name|int
name|handle
parameter_list|,
name|short
modifier|*
name|lines
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibllo
parameter_list|(
name|int
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibln
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|padval
parameter_list|,
name|int
name|sadval
parameter_list|,
name|short
modifier|*
name|listenflag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibloc
parameter_list|(
name|int
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibonl
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibpad
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|pad
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibpct
parameter_list|(
name|int
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibpoke
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|option
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibppc
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibrd
parameter_list|(
name|int
name|handle
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|long
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibrda
parameter_list|(
name|int
name|handle
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|long
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibrdf
parameter_list|(
name|int
name|handle
parameter_list|,
name|char
modifier|*
name|flname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibrdkey
parameter_list|(
name|int
name|handle
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|int
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibrpp
parameter_list|(
name|int
name|handle
parameter_list|,
name|char
modifier|*
name|ppr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibrsc
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibrsp
parameter_list|(
name|int
name|handle
parameter_list|,
name|char
modifier|*
name|spr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibrsv
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibsad
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|sad
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibsgnl
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibsic
parameter_list|(
name|int
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibsre
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibsrq
parameter_list|(
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibstop
parameter_list|(
name|int
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibtmo
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|tmo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibtrap
parameter_list|(
name|int
name|mask
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibtrg
parameter_list|(
name|int
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibwait
parameter_list|(
name|int
name|handle
parameter_list|,
name|int
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibwrt
parameter_list|(
name|int
name|handle
parameter_list|,
specifier|const
name|void
modifier|*
name|buffer
parameter_list|,
name|long
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibwrta
parameter_list|(
name|int
name|handle
parameter_list|,
specifier|const
name|void
modifier|*
name|buffer
parameter_list|,
name|long
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibwrtf
parameter_list|(
name|int
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
name|flname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibwrtkey
parameter_list|(
name|int
name|handle
parameter_list|,
specifier|const
name|void
modifier|*
name|buffer
parameter_list|,
name|int
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibxtrc
parameter_list|(
name|int
name|handle
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|long
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_IEEE488_UGPIB_H_ */
end_comment

end_unit

