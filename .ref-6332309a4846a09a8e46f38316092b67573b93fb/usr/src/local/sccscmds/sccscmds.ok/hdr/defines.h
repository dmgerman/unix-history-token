begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|"../hdr/macros.h"
end_include

begin_include
include|#
directive|include
file|"../hdr/fatal.h"
end_include

begin_comment
comment|/*  *	defines.h 2.3 of 5/18/78  *	defines.h 4.4 of %G%  */
end_comment

begin_define
define|#
directive|define
name|CTLSTR
value|"%c%c\n"
end_define

begin_define
define|#
directive|define
name|CTLCHAR
value|1
end_define

begin_define
define|#
directive|define
name|HEAD
value|'h'
end_define

begin_define
define|#
directive|define
name|STATS
value|'s'
end_define

begin_define
define|#
directive|define
name|BDELTAB
value|'d'
end_define

begin_define
define|#
directive|define
name|INCLUDE
value|'i'
end_define

begin_define
define|#
directive|define
name|EXCLUDE
value|'x'
end_define

begin_define
define|#
directive|define
name|IGNORE
value|'g'
end_define

begin_define
define|#
directive|define
name|MRNUM
value|'m'
end_define

begin_define
define|#
directive|define
name|COMMENTS
value|'c'
end_define

begin_define
define|#
directive|define
name|EDELTAB
value|'e'
end_define

begin_define
define|#
directive|define
name|BUSERNAM
value|'u'
end_define

begin_define
define|#
directive|define
name|EUSERNAM
value|'U'
end_define

begin_define
define|#
directive|define
name|NFLAGS
value|26
end_define

begin_define
define|#
directive|define
name|FLAG
value|'f'
end_define

begin_define
define|#
directive|define
name|NULLFLAG
value|'n'
end_define

begin_define
define|#
directive|define
name|DEFTFLAG
value|'d'
end_define

begin_define
define|#
directive|define
name|TYPEFLAG
value|'t'
end_define

begin_define
define|#
directive|define
name|VALFLAG
value|'v'
end_define

begin_define
define|#
directive|define
name|BRCHFLAG
value|'b'
end_define

begin_define
define|#
directive|define
name|IDFLAG
value|'i'
end_define

begin_define
define|#
directive|define
name|MODFLAG
value|'m'
end_define

begin_define
define|#
directive|define
name|FLORFLAG
value|'f'
end_define

begin_define
define|#
directive|define
name|CEILFLAG
value|'c'
end_define

begin_define
define|#
directive|define
name|BUSERTXT
value|'t'
end_define

begin_define
define|#
directive|define
name|EUSERTXT
value|'T'
end_define

begin_define
define|#
directive|define
name|INS
value|'I'
end_define

begin_define
define|#
directive|define
name|DEL
value|'D'
end_define

begin_define
define|#
directive|define
name|END
value|'E'
end_define

begin_define
define|#
directive|define
name|FILESIZE
value|510
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MAX
end_ifdef

begin_undef
undef|#
directive|undef
name|MAX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAX
value|9999
end_define

begin_define
define|#
directive|define
name|DELIVER
value|'*'
end_define

begin_comment
comment|/* 	Declares for external subroutines and/or functions */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|sname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|cat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|dname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|repeat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|satoi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|substr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|trnslat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|zero
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|zeropad
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 	size of login name */
end_comment

begin_define
define|#
directive|define
name|SZLNAM
value|9
end_define

begin_comment
comment|/* size of login name */
end_comment

begin_define
define|#
directive|define
name|LNLNAM
value|8
end_define

begin_comment
comment|/* length of login name */
end_comment

begin_comment
comment|/* 	SCCS Internal Structures. */
end_comment

begin_struct
struct|struct
name|apply
block|{
name|char
name|a_inline
decl_stmt|;
comment|/* in the line of normally applied deltas */
name|char
name|a_code
decl_stmt|;
comment|/* APPLY, NOAPPLY or EMPTY */
name|int
name|a_reason
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|APPLY
value|(1)
end_define

begin_define
define|#
directive|define
name|NOAPPLY
value|(-1)
end_define

begin_define
define|#
directive|define
name|EMPTY
value|(0)
end_define

begin_define
define|#
directive|define
name|IGNR
value|0100
end_define

begin_define
define|#
directive|define
name|USER
value|040
end_define

begin_define
define|#
directive|define
name|INCL
value|1
end_define

begin_define
define|#
directive|define
name|EXCL
value|2
end_define

begin_define
define|#
directive|define
name|CUTOFF
value|4
end_define

begin_define
define|#
directive|define
name|INCLUSER
value|(USER | INCL)
end_define

begin_define
define|#
directive|define
name|EXCLUSER
value|(USER | EXCL)
end_define

begin_define
define|#
directive|define
name|IGNRUSER
value|(USER | IGNR)
end_define

begin_struct
struct|struct
name|queue
block|{
name|struct
name|queue
modifier|*
name|q_next
decl_stmt|;
name|int
name|q_sernum
decl_stmt|;
comment|/* serial number */
name|char
name|q_keep
decl_stmt|;
comment|/* keep switch setting */
name|char
name|q_iord
decl_stmt|;
comment|/* INS or DEL */
name|char
name|q_ixmsg
decl_stmt|;
comment|/* caused inex msg */
name|char
name|q_user
decl_stmt|;
comment|/* inex'ed by user */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|YES
value|(1)
end_define

begin_define
define|#
directive|define
name|NO
value|(-1)
end_define

begin_struct
struct|struct
name|sid
block|{
name|int
name|s_rel
decl_stmt|;
name|int
name|s_lev
decl_stmt|;
name|int
name|s_br
decl_stmt|;
name|int
name|s_seq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|deltab
block|{
name|struct
name|sid
name|d_sid
decl_stmt|;
name|int
name|d_serial
decl_stmt|;
name|int
name|d_pred
decl_stmt|;
name|long
name|d_datetime
decl_stmt|;
name|char
name|d_pgmr
index|[
name|SZLNAM
index|]
decl_stmt|;
name|char
name|d_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixg
block|{
name|struct
name|ixg
modifier|*
name|i_next
decl_stmt|;
name|char
name|i_type
decl_stmt|;
name|char
name|i_cnt
decl_stmt|;
name|int
name|i_ser
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|idel
block|{
name|struct
name|sid
name|i_sid
decl_stmt|;
name|struct
name|ixg
modifier|*
name|i_ixg
decl_stmt|;
name|int
name|i_pred
decl_stmt|;
name|long
name|i_datetime
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|maxser
parameter_list|(
name|pkt
parameter_list|)
value|((pkt)->p_idel->i_pred)
end_define

begin_define
define|#
directive|define
name|sccsfile
parameter_list|(
name|f
parameter_list|)
value|imatch("s.", sname(f))
end_define

begin_struct
struct|struct
name|packet
block|{
name|char
name|p_file
index|[
name|FILESIZE
index|]
decl_stmt|;
comment|/* file name containing module */
name|struct
name|sid
name|p_reqsid
decl_stmt|;
comment|/* requested SID, then new SID */
name|struct
name|sid
name|p_gotsid
decl_stmt|;
comment|/* gotten SID */
name|struct
name|sid
name|p_inssid
decl_stmt|;
comment|/* SID which inserted current line */
name|char
name|p_verbose
decl_stmt|;
comment|/* verbose flags (see #define's below) */
name|char
name|p_upd
decl_stmt|;
comment|/* update flag (!0 = update mode) */
name|long
name|p_cutoff
decl_stmt|;
comment|/* specified cutoff date-time */
name|int
name|p_ihash
decl_stmt|;
comment|/* initial (input) hash */
name|int
name|p_chash
decl_stmt|;
comment|/* current (input) hash */
name|int
name|p_nhash
decl_stmt|;
comment|/* new (output) hash */
name|int
name|p_glnno
decl_stmt|;
comment|/* line number of current gfile line */
name|int
name|p_slnno
decl_stmt|;
comment|/* line number of current input line */
name|char
name|p_wrttn
decl_stmt|;
comment|/* written flag (!0 = written) */
name|char
name|p_keep
decl_stmt|;
comment|/* keep switch for readmod() */
name|struct
name|apply
modifier|*
name|p_apply
decl_stmt|;
comment|/* ptr to apply array */
name|struct
name|queue
modifier|*
name|p_q
decl_stmt|;
comment|/* ptr to control queue */
name|FILE
modifier|*
name|p_iop
decl_stmt|;
comment|/* input file */
name|char
name|p_buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* input file buffer */
name|char
name|p_line
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* buffer for getline() */
name|long
name|p_cdt
decl_stmt|;
comment|/* date/time of newest applied delta */
name|char
modifier|*
name|p_lfile
decl_stmt|;
comment|/* 0 = no l-file; else ptr to l arg */
name|struct
name|idel
modifier|*
name|p_idel
decl_stmt|;
comment|/* ptr to internal delta table */
name|FILE
modifier|*
name|p_stdout
decl_stmt|;
comment|/* standard output for warnings and messages */
name|FILE
modifier|*
name|p_gout
decl_stmt|;
comment|/* g-file output file */
name|char
name|p_user
decl_stmt|;
comment|/* !0 = user on user list */
name|char
name|p_chkeof
decl_stmt|;
comment|/* 0 = eof generates error */
name|int
name|p_maxr
decl_stmt|;
comment|/* largest release number */
name|int
name|p_ixmsg
decl_stmt|;
comment|/* inex msg counter */
name|int
name|p_reopen
decl_stmt|;
comment|/* reopen flag used by getline on eof */
name|int
name|p_ixuser
decl_stmt|;
comment|/* HADI | HADX (in get) */
name|int
name|do_chksum
decl_stmt|;
comment|/* for getline(), 1 = do check sum */
block|}
struct|;
end_struct

begin_comment
comment|/* 	Masks for p_verbose */
end_comment

begin_define
define|#
directive|define
name|RLACCESS
value|(1)
end_define

begin_define
define|#
directive|define
name|NLINES
value|(2)
end_define

begin_define
define|#
directive|define
name|DOLIST
value|(4)
end_define

begin_define
define|#
directive|define
name|UNACK
value|(8)
end_define

begin_define
define|#
directive|define
name|NEWRL
value|(16)
end_define

begin_define
define|#
directive|define
name|WARNING
value|(32)
end_define

begin_struct
struct|struct
name|stats
block|{
name|int
name|s_ins
decl_stmt|;
name|int
name|s_del
decl_stmt|;
name|int
name|s_unc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pfile
block|{
name|struct
name|sid
name|pf_gsid
decl_stmt|;
name|struct
name|sid
name|pf_nsid
decl_stmt|;
name|char
name|pf_user
index|[
name|SZLNAM
index|]
decl_stmt|;
name|long
name|pf_date
decl_stmt|;
name|char
modifier|*
name|pf_ilist
decl_stmt|;
name|char
modifier|*
name|pf_elist
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RESPSIZE
value|512
end_define

begin_define
define|#
directive|define
name|NVARGS
value|64
end_define

begin_define
define|#
directive|define
name|VSTART
value|3
end_define

end_unit

