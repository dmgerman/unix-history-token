begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if_slvar.h	7.1	89/06/29	*/
end_comment

begin_comment
comment|/*  * Definitions for SLIP "interface" data structure.  *  * (This exists so that programs can interpret the kernel data structures.)  */
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
name|short
name|sc_flags
decl_stmt|;
comment|/* see below */
name|short
name|sc_ilen
decl_stmt|;
comment|/* length of input-packet-so-far */
name|struct
name|tty
modifier|*
name|sc_ttyp
decl_stmt|;
comment|/* pointer to tty structure */
name|char
modifier|*
name|sc_mp
decl_stmt|;
comment|/* pointer to next available buf char */
name|char
modifier|*
name|sc_buf
decl_stmt|;
comment|/* input buffer */
name|long
name|sc_lasttime
decl_stmt|;
comment|/* last time a char arrived - seconds */
name|long
name|sc_starttime
decl_stmt|;
comment|/* last time a char arrived - seconds */
name|long
name|sc_abortcount
decl_stmt|;
comment|/* number of abort esacpe chars */
ifdef|#
directive|ifdef
name|INET
name|struct
name|slcompress
name|sc_comp
decl_stmt|;
comment|/* tcp compression state */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|SC_ESCAPED
value|0x0001
end_define

begin_comment
comment|/* saw a FRAME_ESCAPE */
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
name|SC_ABORT
value|0x0008
end_define

begin_comment
comment|/* have been sent an abort request */
end_comment

begin_define
define|#
directive|define
name|SC_OACTIVE
value|0x0010
end_define

begin_comment
comment|/* output is active */
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

end_unit

