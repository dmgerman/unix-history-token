begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*	@(#)tp_meas.h	7.3 (Berkeley) %G% */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TPPT
end_ifdef

begin_define
define|#
directive|define
name|TP_PERF_MEAS
end_define

begin_endif
endif|#
directive|endif
endif|TPPT
end_endif

begin_define
define|#
directive|define
name|tpmeas
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|t
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
define|\
value|Tpmeas((u_int)(a), (u_int)(b), t, (u_int)(c), (u_int)(d), (u_int)(e))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TP_PERF_MEAS
end_ifdef

begin_struct
struct|struct
name|tp_Meas
block|{
name|int
name|tpm_tseq
decl_stmt|;
name|u_char
name|tpm_kind
decl_stmt|;
name|u_short
name|tpm_ref
decl_stmt|;
name|u_short
name|tpm_size
decl_stmt|;
name|u_short
name|tpm_window
decl_stmt|;
name|u_int
name|tpm_seq
decl_stmt|;
name|struct
name|timeval
name|tpm_time
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TPMEASN
value|4000
end_define

begin_decl_stmt
specifier|extern
name|int
name|tp_Measn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tp_Meas
name|tp_Meas
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * the kinds of events for packet tracing are:  */
end_comment

begin_define
define|#
directive|define
name|TPtime_from_session
value|0x01
end_define

begin_define
define|#
directive|define
name|TPtime_to_session
value|0x02
end_define

begin_define
define|#
directive|define
name|TPtime_ack_rcvd
value|0x03
end_define

begin_define
define|#
directive|define
name|TPtime_ack_sent
value|0x04
end_define

begin_define
define|#
directive|define
name|TPtime_from_ll
value|0x05
end_define

begin_define
define|#
directive|define
name|TPtime_to_ll
value|0x06
end_define

begin_define
define|#
directive|define
name|TPsbsend
value|0x07
end_define

begin_define
define|#
directive|define
name|TPtime_open
value|0x08
end_define

begin_define
define|#
directive|define
name|TPtime_open_X
value|0x28
end_define

begin_comment
comment|/* xtd format */
end_comment

begin_define
define|#
directive|define
name|TPtime_close
value|0x09
end_define

begin_endif
endif|#
directive|endif
endif|TP_PERF_MEAS
end_endif

end_unit

