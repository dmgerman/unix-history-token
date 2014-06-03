begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2007 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSDSTAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_BSDSTAT_H_
end_define

begin_comment
comment|/*  * Base class for managing+displaying periodically collected statistics.  */
end_comment

begin_comment
comment|/*  * Statistic definition/description.  The are defined  * for stats that correspond 1-1 w/ a collected stat  * and for stats that are calculated indirectly.  */
end_comment

begin_struct
struct|struct
name|fmt
block|{
name|int
name|width
decl_stmt|;
comment|/* printed field width */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* stat field name referenced by user */
specifier|const
name|char
modifier|*
name|label
decl_stmt|;
comment|/* printed header label */
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
comment|/* verbose description */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BSDSTAT_DECL_METHODS
parameter_list|(
name|_p
parameter_list|)
define|\
comment|/* set the format of the statistics to display */
define|\
value|void (*setfmt)(_p, const char *);			\
comment|/* collect+store ``current statistics'' */
value|\ 	void (*collect_cur)(_p);				\
comment|/* collect+store ``total statistics'' */
value|\ 	void (*collect_tot)(_p);				\
comment|/* update ``total statistics'' if necessary from current */
value|\ 	void (*update_tot)(_p);					\
comment|/* format a statistic from the current stats */
value|\ 	int (*get_curstat)(_p, int, char [], size_t);		\
comment|/* format a statistic from the total stats */
value|\ 	int (*get_totstat)(_p, int, char [], size_t);		\
comment|/* print field headers terminated by a \n */
value|\ 	void (*print_header)(_p, FILE *);			\
comment|/* print current statistics terminated by a \n */
value|\ 	void (*print_current)(_p, FILE *);			\
comment|/* print total statistics terminated by a \n */
value|\ 	void (*print_total)(_p, FILE *);			\
comment|/* print total statistics in a verbose (1 stat/line) format */
value|\ 	void (*print_verbose)(_p, FILE *);			\
comment|/* print available statistics */
value|\ 	void (*print_fields)(_p, FILE *)
end_define

begin_comment
comment|/*  * Statistics base class.  This class is not usable; only  * classes derived from it are useful.  */
end_comment

begin_struct
struct|struct
name|bsdstat
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* statistics name, e.g. wlanstats */
specifier|const
name|struct
name|fmt
modifier|*
name|stats
decl_stmt|;
comment|/* statistics in class */
name|int
name|nstats
decl_stmt|;
comment|/* number of stats */
define|#
directive|define
name|FMTS_IS_STAT
value|0x80
comment|/* the following two bytes are the stat id */
name|unsigned
name|char
name|fmts
index|[
literal|4096
index|]
decl_stmt|;
comment|/* private: compiled stats to display */
name|BSDSTAT_DECL_METHODS
argument_list|(
expr|struct
name|bsdstat
operator|*
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|bsdstat_init
parameter_list|(
name|struct
name|bsdstat
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|struct
name|fmt
modifier|*
name|stats
parameter_list|,
name|int
name|nstats
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BSDSTAT_DEFINE_BOUNCE
parameter_list|(
name|_t
parameter_list|)
define|\
value|static void _t##_setfmt(struct _t *wf, const char *fmt0)	\ 	{ wf->base.setfmt(&wf->base, fmt0); }			\ static void _t##_collect_cur(struct _t *wf)			\ 	{ wf->base.collect_cur(&wf->base); }			\ static void _t##_collect_tot(struct _t *wf)			\ 	{ wf->base.collect_tot(&wf->base); }			\ static void _t##_update_tot(struct _t *wf)			\ 	{ wf->base.update_tot(&wf->base); }			\ static int _t##_get_curstat(struct _t *wf, int s, char b[], size_t bs) \ 	{ return wf->base.get_curstat(&wf->base, s, b, bs); }	\ static int _t##_get_totstat(struct _t *wf, int s, char b[], size_t bs) \ 	{ return wf->base.get_totstat(&wf->base, s, b, bs); }	\ static void _t##_print_header(struct _t *wf, FILE *fd)		\ 	{ wf->base.print_header(&wf->base, fd); }		\ static void _t##_print_current(struct _t *wf, FILE *fd)		\ 	{ wf->base.print_current(&wf->base, fd); }		\ static void _t##_print_total(struct _t *wf, FILE *fd)		\ 	{ wf->base.print_total(&wf->base, fd); }		\ static void _t##_print_verbose(struct _t *wf, FILE *fd)		\ 	{ wf->base.print_verbose(&wf->base, fd); }		\ static void _t##_print_fields(struct _t *wf, FILE *fd)		\ 	{ wf->base.print_fields(&wf->base, fd); }
end_define

begin_define
define|#
directive|define
name|BSDSTAT_BOUNCE
parameter_list|(
name|_p
parameter_list|,
name|_t
parameter_list|)
value|do {				\ 	_p->base.setfmt = _t##_setfmt;				\ 	_p->base.collect_cur = _t##_collect_cur;		\ 	_p->base.collect_tot = _t##_collect_tot;		\ 	_p->base.update_tot = _t##_update_tot;			\ 	_p->base.get_curstat = _t##_get_curstat;		\ 	_p->base.get_totstat = _t##_get_totstat;		\ 	_p->base.print_header = _t##_print_header;		\ 	_p->base.print_current = _t##_print_current;		\ 	_p->base.print_total = _t##_print_total;		\ 	_p->base.print_verbose = _t##_print_verbose;		\ 	_p->base.print_fields = _t##_print_fields;		\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSDSTAT_H_ */
end_comment

end_unit

