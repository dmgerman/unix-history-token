begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)if_slvar.h	7.4 (Berkeley) %G% */
end_comment

begin_comment
comment|/*  * Definitions for SLIP interface data structures  *   * (this exists so programs like slstats can get at the definition  *  of sl_softc.)  *  * $Header: if_slvar.h,v 1.3 89/05/31 02:25:18 van Exp $  */
end_comment

begin_struct
struct|struct
name|sl_softc
block|{
name|struct
name|ifnet
name|sc_if
decl_stmt|;
comment|/* network-visible interface */
name|struct
name|ifqueue
name|sc_fastq
decl_stmt|;
comment|/* interactive output queue */
name|struct
name|tty
modifier|*
name|sc_ttyp
decl_stmt|;
comment|/* pointer to tty structure */
name|u_char
modifier|*
name|sc_mp
decl_stmt|;
comment|/* pointer to next available buf char */
name|u_char
modifier|*
name|sc_ep
decl_stmt|;
comment|/* pointer to last available buf char */
name|u_char
modifier|*
name|sc_buf
decl_stmt|;
comment|/* input buffer */
name|u_int
name|sc_flags
decl_stmt|;
comment|/* see below */
name|u_int
name|sc_escape
decl_stmt|;
comment|/* =1 if last char input was FRAME_ESCAPE */
name|u_int
name|sc_bytessent
decl_stmt|;
name|u_int
name|sc_bytesrcvd
decl_stmt|;
name|long
name|sc_lasttime
decl_stmt|;
comment|/* last time a char arrived */
name|long
name|sc_starttime
decl_stmt|;
comment|/* last time a char arrived */
name|long
name|sc_abortcount
decl_stmt|;
comment|/* number of abort esacpe chars */
ifdef|#
directive|ifdef
name|INET
comment|/* XXX */
name|struct
name|slcompress
name|sc_comp
decl_stmt|;
comment|/* tcp compression data */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* visible flags */
end_comment

begin_define
define|#
directive|define
name|SC_COMPRESS
value|0x0002
end_define

begin_comment
comment|/* compress TCP traffic */
end_comment

begin_define
define|#
directive|define
name|SC_NOICMP
value|0x0004
end_define

begin_comment
comment|/* supress ICMP traffic */
end_comment

begin_define
define|#
directive|define
name|SC_AUTOCOMP
value|0x0008
end_define

begin_comment
comment|/* auto-enable TCP compression */
end_comment

begin_comment
comment|/* internal flags (should be separate) */
end_comment

begin_define
define|#
directive|define
name|SC_ABORT
value|0x10000
end_define

begin_comment
comment|/* have been sent an abort request */
end_comment

begin_comment
comment|/* this stuff doesn't belong here... */
end_comment

begin_define
define|#
directive|define
name|SLIOCGFLAGS
value|_IOR('t', 90, int)
end_define

begin_comment
comment|/* get configuration flags */
end_comment

begin_define
define|#
directive|define
name|SLIOCSFLAGS
value|_IOW('t', 89, int)
end_define

begin_comment
comment|/* set configuration flags */
end_comment

begin_define
define|#
directive|define
name|SLIOGUNIT
value|_IOW('t', 88, int)
end_define

begin_comment
comment|/* get slip unit number */
end_comment

end_unit

