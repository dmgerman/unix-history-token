begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: ngsrch.h,v 4.3 85/05/01 11:44:56 lwall Exp $  *  * $Log:	ngsrch.h,v $  * Revision 4.3  85/05/01  11:44:56  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NGSEARCH
end_ifdef

begin_define
define|#
directive|define
name|NGS_ABORT
value|0
end_define

begin_define
define|#
directive|define
name|NGS_FOUND
value|1
end_define

begin_define
define|#
directive|define
name|NGS_INTR
value|2
end_define

begin_define
define|#
directive|define
name|NGS_NOTFOUND
value|3
end_define

begin_function_decl
name|EXT
name|bool
name|ng_doread
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* search read newsgroups? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ngsrch_init
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NGSEARCH
end_ifdef

begin_function_decl
name|int
name|ng_search
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ng_wanted
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NGSORONLY
end_ifdef

begin_function_decl
name|char
modifier|*
name|ng_comp
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

