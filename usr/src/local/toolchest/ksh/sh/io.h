begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)io.h	1.1 */
end_comment

begin_comment
comment|/*  *	UNIX shell  *	S. R. Bourne  *	rewritten by David Korn  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFILE
end_ifndef

begin_comment
comment|/* This is true for BSD 4.3 */
end_comment

begin_define
define|#
directive|define
name|_NFILE
value|20
end_define

begin_define
define|#
directive|define
name|_N_STATIC_IOBS
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NFILE */
end_comment

begin_comment
comment|/* used for input and output of shell */
end_comment

begin_define
define|#
directive|define
name|FCIO
value|19
end_define

begin_comment
comment|/* history file */
end_comment

begin_define
define|#
directive|define
name|INIO
value|18
end_define

begin_comment
comment|/* saved standard ioput */
end_comment

begin_define
define|#
directive|define
name|TMPIO
value|17
end_define

begin_comment
comment|/* used for command substitution */
end_comment

begin_define
define|#
directive|define
name|CINPIPE
value|16
end_define

begin_comment
comment|/* inpipe for cooperating process */
end_comment

begin_define
define|#
directive|define
name|COTPIPE
value|15
end_define

begin_comment
comment|/* outpipe for cooperating process */
end_comment

begin_define
define|#
directive|define
name|MAXFILES
value|10
end_define

begin_comment
comment|/* maximum number of saved open files */
end_comment

begin_comment
comment|/*io nodes*/
end_comment

begin_define
define|#
directive|define
name|USERIO
value|10
end_define

begin_define
define|#
directive|define
name|IOUFD
value|15
end_define

begin_define
define|#
directive|define
name|IODOC
value|16
end_define

begin_define
define|#
directive|define
name|IOPUT
value|32
end_define

begin_define
define|#
directive|define
name|IOAPP
value|64
end_define

begin_define
define|#
directive|define
name|IOMOV
value|128
end_define

begin_define
define|#
directive|define
name|IORDW
value|256
end_define

begin_define
define|#
directive|define
name|IOSTRIP
value|512
end_define

begin_define
define|#
directive|define
name|INPIPE
value|0
end_define

begin_define
define|#
directive|define
name|OTPIPE
value|1
end_define

begin_define
define|#
directive|define
name|DUPFLG
value|0100
end_define

begin_define
define|#
directive|define
name|TMPSIZ
value|20
end_define

begin_define
define|#
directive|define
name|F_STRING
value|((unsigned char)_NFILE)
end_define

begin_comment
comment|/* file number for incore files */
end_comment

begin_define
define|#
directive|define
name|F_INFINITE
value|0x7fff
end_define

begin_comment
comment|/* effectively infinite */
end_comment

begin_comment
comment|/* temp files and io */
end_comment

begin_comment
comment|/* SHELL file structure */
end_comment

begin_struct
struct|struct
name|fileblk
block|{
name|FILE
modifier|*
name|fdes
decl_stmt|;
name|unsigned
name|flin
decl_stmt|;
name|char
modifier|*
modifier|*
name|feval
decl_stmt|;
name|SHFILE
name|fstak
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_N_STATIC_IOBS
end_ifdef

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|file_fd
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|FILE
name|_myiob
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|file_fd
parameter_list|(
name|n
parameter_list|)
value|(&_iob[n])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _N_STATIC_IOBS */
end_comment

begin_define
define|#
directive|define
name|input
value|(standin->fdes)
end_define

begin_define
define|#
directive|define
name|fisopen
parameter_list|(
name|fd
parameter_list|)
value|((fd)->_flag)
end_define

begin_define
define|#
directive|define
name|fiswrite
parameter_list|(
name|fd
parameter_list|)
value|((fd)->_flag&(_IOWRT|_IORW))
end_define

begin_define
define|#
directive|define
name|fisread
parameter_list|(
name|fd
parameter_list|)
value|((fd)->_flag&(_IOREAD|_IORW))
end_define

begin_define
define|#
directive|define
name|fnobuff
parameter_list|(
name|fd
parameter_list|)
value|(((fd)->_flag&_IONBF)||(fd)->_base==NULL)
end_define

begin_define
define|#
directive|define
name|nextchar
parameter_list|(
name|fd
parameter_list|)
value|(*((fd)->_ptr))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|clearerr
end_ifndef

begin_define
define|#
directive|define
name|clearerr
parameter_list|(
name|fd
parameter_list|)
value|((fd)->_flag&= ~(_IOERR|_IOEOF))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ionod
block|{
name|int
name|iofile
decl_stmt|;
name|char
modifier|*
name|ioname
decl_stmt|;
name|char
modifier|*
name|iolink
decl_stmt|;
name|IOPTR
name|ionxt
decl_stmt|;
name|IOPTR
name|iolst
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IOTYPE
value|(sizeof(struct ionod))
end_define

begin_struct
struct|struct
name|filesave
block|{
name|short
name|org_fd
decl_stmt|;
name|short
name|dup_fd
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|rmtemp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|frenumber
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|_sibuf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|_sobuf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILEBLK
name|stdfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tmpout
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the following are readonly */
end_comment

begin_decl_stmt
specifier|extern
name|MSG
name|badcreate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|badfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|badopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|devnull
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|endoffile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|nomorefiles
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|piperr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|profile
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BSD_4_2
end_ifdef

begin_decl_stmt
specifier|extern
name|MSG
name|prohibited
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD_4_2 */
end_comment

begin_decl_stmt
specifier|extern
name|MSG
name|sysprofile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|unknown
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SUID_EXEC
end_ifdef

begin_decl_stmt
specifier|extern
name|MSG
name|devfdNN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|suid_exec
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUID_EXEC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|apollo
end_ifdef

begin_comment
comment|/* only a fool would have changed these names */
end_comment

begin_define
define|#
directive|define
name|_IOREAD
value|_SIRD
end_define

begin_define
define|#
directive|define
name|_IOWRT
value|_SIWR
end_define

begin_define
define|#
directive|define
name|_IOLBF
value|_SINLB
end_define

begin_define
define|#
directive|define
name|_IONBF
value|_SIUNB
end_define

begin_define
define|#
directive|define
name|_IOMYBUF
value|_SIBIG
end_define

begin_define
define|#
directive|define
name|_IORW
value|_SIUP
end_define

begin_define
define|#
directive|define
name|_IOEOF
value|_SIEOF
end_define

begin_define
define|#
directive|define
name|_IOERR
value|_SIERR
end_define

begin_define
define|#
directive|define
name|_flsbuf
value|_flshbuf
end_define

begin_define
define|#
directive|define
name|_file
value|_fd
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* apollo */
end_comment

end_unit

