begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* logger.h - logging routines */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/logger.h,v 7.4 91/02/22 09:24:46 mrose Interim $  *  *  * $Log:	logger.h,v $  * Revision 7.4  91/02/22  09:24:46  mrose  * Interim 6.8  *   * Revision 7.3  90/12/23  18:41:49  mrose  * update  *   * Revision 7.2  90/11/21  11:32:07  mrose  * sun  *   * Revision 7.1  90/07/01  21:03:49  mrose  * pepsy  *   * Revision 7.0  89/11/23  21:55:48  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOGGER_
end_ifndef

begin_define
define|#
directive|define
name|_LOGGER_
end_define

begin_include
include|#
directive|include
file|"manifest.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ll_struct
block|{
name|char
modifier|*
name|ll_file
decl_stmt|;
comment|/* path name to logging file */
name|char
modifier|*
name|ll_hdr
decl_stmt|;
comment|/* text to put in opening line */
name|char
modifier|*
name|ll_dhdr
decl_stmt|;
comment|/* dynamic header - changes */
name|int
name|ll_events
decl_stmt|;
comment|/* interesting events */
define|#
directive|define
name|LLOG_NONE
value|0
define|#
directive|define
name|LLOG_FATAL
value|0x01
comment|/*   fatal errors */
define|#
directive|define
name|LLOG_EXCEPTIONS
value|0x02
comment|/*   exceptional events */
define|#
directive|define
name|LLOG_NOTICE
value|0x04
comment|/*   informational notices */
define|#
directive|define
name|LLOG_PDUS
value|0x08
comment|/*   PDU printing */
define|#
directive|define
name|LLOG_TRACE
value|0x10
comment|/*   program tracing */
define|#
directive|define
name|LLOG_DEBUG
value|0x20
comment|/*   full debugging */
define|#
directive|define
name|LLOG_ALL
value|0xff
define|#
directive|define
name|LLOG_MASK
define|\
value|"\020\01FATAL\02EXCEPTIONS\03NOTICE\04PDUS\05TRACE\06DEBUG"
name|int
name|ll_syslog
decl_stmt|;
comment|/* interesting events to send to syslog */
comment|/*   takes same values as ll_events */
name|int
name|ll_msize
decl_stmt|;
comment|/* max size for log, in Kbytes */
name|int
name|ll_stat
decl_stmt|;
comment|/* assorted switches */
define|#
directive|define
name|LLOGNIL
value|0x00
define|#
directive|define
name|LLOGCLS
value|0x01
comment|/*   keep log closed, except when writing */
define|#
directive|define
name|LLOGCRT
value|0x02
comment|/*   create log if necessary */
define|#
directive|define
name|LLOGZER
value|0x04
comment|/*   truncate log when limits reached */
define|#
directive|define
name|LLOGERR
value|0x08
comment|/*   log closed due to (soft) error */
define|#
directive|define
name|LLOGTTY
value|0x10
comment|/*   also log to stderr */
define|#
directive|define
name|LLOGHDR
value|0x20
comment|/*   static header allocated */
define|#
directive|define
name|LLOGDHR
value|0x40
comment|/*   dynamic header allocated */
name|int
name|ll_fd
decl_stmt|;
comment|/* file descriptor */
block|}
name|LLog
typedef|;
end_typedef

begin_comment
comment|/*
comment|*/
end_comment

begin_define
define|#
directive|define
name|SLOG
parameter_list|(
name|lp
parameter_list|,
name|event
parameter_list|,
name|what
parameter_list|,
name|args
parameter_list|)
define|\
value|if (lp -> ll_events& (event)) { \     (void) ll_log (lp, event, what, "%s", ll_preset args); \ } \ else
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LLOG
end_ifndef

begin_define
define|#
directive|define
name|LLOG
parameter_list|(
name|lp
parameter_list|,
name|event
parameter_list|,
name|args
parameter_list|)
value|SLOG (lp, event, NULLCP, args)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DLOG
parameter_list|(
name|lp
parameter_list|,
name|event
parameter_list|,
name|args
parameter_list|)
value|SLOG (lp, event, NULLCP, args)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DLOG
parameter_list|(
name|lp
parameter_list|,
name|event
parameter_list|,
name|args
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|PEPSY_VERSION
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|PLOGP
parameter_list|(
name|lp
parameter_list|,
name|args
parameter_list|,
name|pe
parameter_list|,
name|text
parameter_list|,
name|rw
parameter_list|)
define|\
value|if ((lp) -> ll_events& LLOG_PDUS) { \ 	pvpdu (lp, print_##args##_P, pe, text, rw); \     } \     else
end_define

begin_define
define|#
directive|define
name|PLOG
parameter_list|(
name|lp
parameter_list|,
name|fnx
parameter_list|,
name|pe
parameter_list|,
name|text
parameter_list|,
name|rw
parameter_list|)
define|\
value|if ((lp) -> ll_events& LLOG_PDUS) { \ 	pvpdu (lp, fnx##_P, pe, text, rw); \     } \     else
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PLOGP
parameter_list|(
name|lp
parameter_list|,
name|args
parameter_list|,
name|pe
parameter_list|,
name|text
parameter_list|,
name|rw
parameter_list|)
define|\
value|if ((lp) -> ll_events& LLOG_PDUS) { \ 	pvpdu (lp, print_
comment|/* */
value|args
comment|/* */
value|_P, pe, text, rw); \     } \     else
end_define

begin_define
define|#
directive|define
name|PLOG
parameter_list|(
name|lp
parameter_list|,
name|fnx
parameter_list|,
name|pe
parameter_list|,
name|text
parameter_list|,
name|rw
parameter_list|)
define|\
value|if ((lp) -> ll_events& LLOG_PDUS) { \ 	pvpdu (lp, fnx
comment|/* */
value|_P, pe, text, rw); \     } \     else
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !PEPSY_VERSION */
end_comment

begin_define
define|#
directive|define
name|PLOG
parameter_list|(
name|lp
parameter_list|,
name|fnx
parameter_list|,
name|pe
parameter_list|,
name|text
parameter_list|,
name|rw
parameter_list|)
define|\
value|if ((lp) -> ll_events& LLOG_PDUS) { \ 	vpdu (lp, fnx, pe, text, rw); \     } \     else
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !PEPSY_VERSION */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_undef
undef|#
directive|undef
name|PLOGP
end_undef

begin_define
define|#
directive|define
name|PLOGP
parameter_list|(
name|lp
parameter_list|,
name|args
parameter_list|,
name|pe
parameter_list|,
name|text
parameter_list|,
name|rw
parameter_list|)
define|\
value|if ((lp) -> ll_events& LLOG_PDUS) { \ 	_pvpdu (lp, pe, text, rw); \     } \     else
end_define

begin_define
define|#
directive|define
name|pvpdu
parameter_list|(
name|lp
parameter_list|,
name|cookie
parameter_list|,
name|pe
parameter_list|,
name|text
parameter_list|,
name|rw
parameter_list|)
define|\
value|_pvpdu(lp, pe, text, rw)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !DEBUG */
end_comment

begin_define
define|#
directive|define
name|PLOG
parameter_list|(
name|lp
parameter_list|,
name|fnx
parameter_list|,
name|pe
parameter_list|,
name|text
parameter_list|,
name|rw
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PLOGP
parameter_list|(
name|lp
parameter_list|,
name|args
parameter_list|,
name|pe
parameter_list|,
name|text
parameter_list|,
name|rw
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|ll_open
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|ll_log
argument_list|()
decl_stmt|,
name|_ll_log
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ll_close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ll_hdinit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ll_dbinit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ll_printf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ll_sync
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ll_preset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ll_check
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ll_defmhdr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|IFP
name|ll_setmhdr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

