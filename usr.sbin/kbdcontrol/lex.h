begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994-1995 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|TNOP
value|256
end_define

begin_define
define|#
directive|define
name|TLSH
value|257
end_define

begin_define
define|#
directive|define
name|TRSH
value|258
end_define

begin_define
define|#
directive|define
name|TCLK
value|259
end_define

begin_define
define|#
directive|define
name|TNLK
value|260
end_define

begin_define
define|#
directive|define
name|TSLK
value|261
end_define

begin_define
define|#
directive|define
name|TLALT
value|262
end_define

begin_define
define|#
directive|define
name|TLCTR
value|263
end_define

begin_define
define|#
directive|define
name|TNEXT
value|264
end_define

begin_define
define|#
directive|define
name|TRCTR
value|265
end_define

begin_define
define|#
directive|define
name|TRALT
value|266
end_define

begin_define
define|#
directive|define
name|TALK
value|267
end_define

begin_define
define|#
directive|define
name|TASH
value|268
end_define

begin_define
define|#
directive|define
name|TMETA
value|269
end_define

begin_define
define|#
directive|define
name|TRBT
value|270
end_define

begin_define
define|#
directive|define
name|TDBG
value|271
end_define

begin_define
define|#
directive|define
name|TFUNC
value|272
end_define

begin_define
define|#
directive|define
name|TSCRN
value|273
end_define

begin_define
define|#
directive|define
name|TLET
value|274
end_define

begin_define
define|#
directive|define
name|TNUM
value|275
end_define

begin_define
define|#
directive|define
name|TFLAG
value|276
end_define

begin_define
define|#
directive|define
name|TBTAB
value|277
end_define

begin_define
define|#
directive|define
name|TSUSP
value|278
end_define

begin_define
define|#
directive|define
name|TACC
value|279
end_define

begin_define
define|#
directive|define
name|TSPSC
value|280
end_define

begin_define
define|#
directive|define
name|TPREV
value|281
end_define

begin_define
define|#
directive|define
name|TPANIC
value|282
end_define

begin_define
define|#
directive|define
name|TLSHA
value|283
end_define

begin_define
define|#
directive|define
name|TRSHA
value|284
end_define

begin_define
define|#
directive|define
name|TLCTRA
value|285
end_define

begin_define
define|#
directive|define
name|TRCTRA
value|286
end_define

begin_define
define|#
directive|define
name|TLALTA
value|287
end_define

begin_define
define|#
directive|define
name|TRALTA
value|288
end_define

begin_define
define|#
directive|define
name|THALT
value|289
end_define

begin_define
define|#
directive|define
name|TPDWN
value|290
end_define

begin_decl_stmt
specifier|extern
name|int
name|number
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|letter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|yyin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yylex
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

