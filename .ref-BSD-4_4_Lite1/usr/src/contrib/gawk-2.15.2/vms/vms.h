begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * vms.h - miscellaneous definitions for use with VMS system services.  *							Pat Rankin, Nov'89  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<iodef.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IO$_WRITEVBLK
value|48
end_define

begin_comment
comment|/* write virtual block */
end_comment

begin_define
define|#
directive|define
name|IO$V_CANCTRLO
value|6
end_define

begin_comment
comment|/* cancel<ctrl/O> (ie, resume tty output) */
end_comment

begin_define
define|#
directive|define
name|IO$M_CANCTRLO
value|(1<< IO$V_CANCTRLO)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<clidef.h>
end_include

begin_include
include|#
directive|include
file|<cliverbdef.h>
end_include

begin_include
include|#
directive|include
file|<fscndef.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CLI$K_GETCMD
value|1
end_define

begin_define
define|#
directive|define
name|CLI$K_VERB_MCR
value|33
end_define

begin_define
define|#
directive|define
name|CLI$K_VERB_RUN
value|36
end_define

begin_define
define|#
directive|define
name|FSCN$_FILESPEC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<climsgdef.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CLI$_RUNUSED
value|0x00030000
end_define

begin_comment
comment|/* value returned by $CLI for "RUN" */
end_comment

begin_define
define|#
directive|define
name|CLI$_SYNTAX
value|0x000310FC
end_define

begin_comment
comment|/* error signalled by CLI$DCL_PARSE */
end_comment

begin_define
define|#
directive|define
name|CLI$_INSFPRM
value|0x00038048
end_define

begin_comment
comment|/* insufficient parameters */
end_comment

begin_define
define|#
directive|define
name|CLI$_VALREQ
value|0x00038150
end_define

begin_comment
comment|/* missing required value  */
end_comment

begin_define
define|#
directive|define
name|CLI$_CONFLICT
value|0x00038258
end_define

begin_comment
comment|/* conflicting qualifiers  */
end_comment

begin_define
define|#
directive|define
name|CLI$_NOOPTPRS
value|0x00038840
end_define

begin_comment
comment|/* no option present	   */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<psldef.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PSL$C_USER
value|3
end_define

begin_comment
comment|/* user mode */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_TYPES_
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u_long
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u_short
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_dsc
block|{
name|int
name|len
decl_stmt|;
name|char
modifier|*
name|adr
decl_stmt|;
block|}
name|Dsc
typedef|;
end_typedef

begin_comment
comment|/* limited string descriptor */
end_comment

begin_comment
comment|/* standard VMS itemlist-3 structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_itm
block|{
name|u_short
name|len
decl_stmt|,
name|code
decl_stmt|;
name|void
modifier|*
name|buffer
decl_stmt|;
name|u_short
modifier|*
name|retlen
decl_stmt|;
block|}
name|Itm
typedef|;
end_typedef

begin_define
define|#
directive|define
name|vmswork
parameter_list|(
name|sts
parameter_list|)
value|((sts)&1)
end_define

begin_define
define|#
directive|define
name|vmsfail
parameter_list|(
name|sts
parameter_list|)
value|(!vmswork(sts))
end_define

begin_define
define|#
directive|define
name|CondVal
parameter_list|(
name|sts
parameter_list|)
value|((sts)&0x0FFFFFF8)
end_define

begin_comment
comment|/* strip severity& msg inhibit */
end_comment

begin_define
define|#
directive|define
name|Descrip
parameter_list|(
name|strdsc
parameter_list|,
name|strbuf
parameter_list|)
value|Dsc strdsc = {sizeof strbuf - 1, strbuf}
end_define

begin_decl_stmt
specifier|extern
name|int
name|shell$is_shell
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|LIB$FIND_FILE
name|P
argument_list|(
operator|(
specifier|const
name|Dsc
operator|*
operator|,
name|Dsc
operator|*
operator|,
name|void
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|LIB$FIND_FILE_END
name|P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NO_TTY_FWRITE
end_ifndef

begin_decl_stmt
specifier|extern
name|u_long
name|LIB$GET_EF
name|P
argument_list|(
operator|(
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|SYS$ASSIGN
name|P
argument_list|(
operator|(
specifier|const
name|Dsc
operator|*
operator|,
name|short
operator|*
operator|,
name|long
operator|,
specifier|const
name|Dsc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|SYS$DASSGN
name|P
argument_list|(
operator|(
name|short
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|SYS$QIO
name|P
argument_list|(
operator|(
name|u_long
operator|,
name|u_long
operator|,
name|u_long
operator|,
name|void
operator|*
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|u_long
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|u_long
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|SYS$SYNCH
name|P
argument_list|(
operator|(
name|long
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!NO_TTY_FWRITE*/
end_comment

begin_comment
comment|/* system services for logical name manipulation */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|SYS$TRNLNM
name|P
argument_list|(
operator|(
specifier|const
name|u_long
operator|*
operator|,
specifier|const
name|Dsc
operator|*
operator|,
specifier|const
name|Dsc
operator|*
operator|,
specifier|const
name|unsigned
name|char
operator|*
operator|,
name|Itm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|SYS$CRELNM
name|P
argument_list|(
operator|(
specifier|const
name|u_long
operator|*
operator|,
specifier|const
name|Dsc
operator|*
operator|,
specifier|const
name|Dsc
operator|*
operator|,
specifier|const
name|unsigned
name|char
operator|*
operator|,
specifier|const
name|Itm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|SYS$CRELOG
name|P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|Dsc
operator|*
operator|,
specifier|const
name|Dsc
operator|*
operator|,
name|unsigned
name|char
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|SYS$DELLNM
name|P
argument_list|(
operator|(
specifier|const
name|Dsc
operator|*
operator|,
specifier|const
name|Dsc
operator|*
operator|,
specifier|const
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|v_add_arg
name|P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|vms_exit
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|vms_strerror
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|vms_strdup
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vms_devopen
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vms_execute
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vms_gawk
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|Cli_Present
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|Cli_Get_Value
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|Cli_Parse_Command
name|P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

