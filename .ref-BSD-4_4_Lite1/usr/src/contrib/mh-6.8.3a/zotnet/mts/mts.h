begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mts.h - definitions for the mail system */
end_comment

begin_comment
comment|/* Local and UUCP Host Name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|LocalName
argument_list|()
decl_stmt|,
modifier|*
name|SystemName
argument_list|()
decl_stmt|,
modifier|*
name|UucpChan
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mailboxes */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mmdfldir
decl_stmt|,
modifier|*
name|mmdflfil
decl_stmt|,
modifier|*
name|uucpldir
decl_stmt|,
modifier|*
name|uucplfil
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAILDIR
value|(mmdfldir&& *mmdfldir ? mmdfldir : getenv ("HOME"))
end_define

begin_define
define|#
directive|define
name|MAILFIL
value|(mmdflfil&& *mmdflfil ? mmdflfil : getusr ())
end_define

begin_define
define|#
directive|define
name|UUCPDIR
value|(uucpldir&& *uucpldir ? uucpldir : getenv ("HOME"))
end_define

begin_define
define|#
directive|define
name|UUCPFIL
value|(uucplfil&& *uucplfil ? uucplfil : getusr ())
end_define

begin_decl_stmt
name|char
modifier|*
name|getusr
argument_list|()
decl_stmt|,
modifier|*
name|getfullname
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Separators */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mmdlm1
decl_stmt|,
modifier|*
name|mmdlm2
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|isdlm1
parameter_list|(
name|s
parameter_list|)
value|(strcmp (s, mmdlm1) == 0)
end_define

begin_define
define|#
directive|define
name|isdlm2
parameter_list|(
name|s
parameter_list|)
value|(strcmp (s, mmdlm2) == 0)
end_define

begin_comment
comment|/* Filters */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|umincproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Locking Directory */
end_comment

begin_define
define|#
directive|define
name|LOK_UNIX
value|0
end_define

begin_define
define|#
directive|define
name|LOK_BELL
value|1
end_define

begin_define
define|#
directive|define
name|LOK_MMDF
value|2
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MMDFONLY
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|lockstyle
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MMDFONLY */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|lockldir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lkopen
argument_list|()
decl_stmt|,
name|lkclose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|FILE
modifier|*
name|lkfopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lkfclose
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* MTS specific variables */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MHMTS
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Mailqdir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|TMailqdir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Syscpy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Overseer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Mailer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Fromtmp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Msgtmp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Errtmp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Tmpmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Okhosts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Okdests
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MHMTS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MMDFMTS
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MMDFMTS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SENDMTS
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hostable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sendmail
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SENDMTS */
end_comment

begin_comment
comment|/* SMTP/POP stuff */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|clientname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|servers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pophost
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* BBoards-specific variables */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|bb_domain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* POP BBoards-specific variables */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BPOP
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|popbbhost
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|popbbuser
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|popbblist
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BPOP */
end_comment

begin_comment
comment|/* MailDelivery */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|maildelivery
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Aliasing Facility (doesn't belong here) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Everyone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|NoShell
decl_stmt|;
end_decl_stmt

end_unit

