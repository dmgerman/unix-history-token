begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) Comtrol Corporation<support@comtrol.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted prodived that the follwoing conditions  * are met.  * 1. Redistributions of source code must retain the above copyright   *    notive, this list of conditions and the following disclainer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials prodided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *       This product includes software developed by Comtrol Corporation.  * 4. The name of Comtrol Corporation may not be used to endorse or   *    promote products derived from this software without specific   *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY COMTROL CORPORATION ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL COMTROL CORPORATION BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * rpvar.h --- RocketPort data structure includes for FreeBSD  */
end_comment

begin_define
define|#
directive|define
name|RP_UNIT
parameter_list|(
name|x
parameter_list|)
value|dv_unit(x)
end_define

begin_define
define|#
directive|define
name|RP_PORT
parameter_list|(
name|x
parameter_list|)
value|(minor(x)& 0x3f)
end_define

begin_define
define|#
directive|define
name|MAX_RP_PORTS
value|128
end_define

begin_struct
struct|struct
name|rp_port
block|{
name|struct
name|tty
modifier|*
name|rp_tty
decl_stmt|;
comment|/* cross reference */
name|unsigned
name|char
name|state
decl_stmt|;
comment|/* state of dtr */
name|int
name|rp_port
decl_stmt|;
name|int
name|rp_flags
decl_stmt|;
name|int
name|rp_unit
range|:
literal|2
decl_stmt|;
name|int
name|rp_aiop
range|:
literal|2
decl_stmt|;
name|int
name|rp_chan
range|:
literal|3
decl_stmt|;
name|int
name|rp_intmask
decl_stmt|;
name|int
name|rp_imask
decl_stmt|;
comment|/* Input mask */
name|int
name|rp_fifo_lw
decl_stmt|;
name|int
name|rp_restart
decl_stmt|;
name|int
name|rp_overflows
decl_stmt|;
name|int
name|rp_rts_iflow
range|:
literal|1
decl_stmt|;
name|int
name|rp_disable_writes
range|:
literal|1
decl_stmt|;
name|int
name|rp_cts
range|:
literal|1
decl_stmt|;
name|int
name|rp_waiting
range|:
literal|1
decl_stmt|;
name|int
name|rp_xmit_stopped
range|:
literal|1
decl_stmt|;
name|CONTROLLER_t
modifier|*
name|rp_ctlp
decl_stmt|;
name|CHANNEL_t
name|rp_channel
decl_stmt|;
name|unsigned
name|char
name|TxBuf
index|[
name|TXFIFO_SIZE
index|]
decl_stmt|;
name|unsigned
name|char
name|RxBuf
index|[
name|RXFIFO_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Actually not used */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|termios
name|deftermios
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* notdef */
end_comment

end_unit

