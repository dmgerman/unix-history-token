begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mmdfonly.h - include file for stand-alone BBoards MMDF-II channel */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V4_2BSD
end_ifdef

begin_define
define|#
directive|define
name|BSD42
end_define

begin_endif
endif|#
directive|endif
endif|V4_2BSD
end_endif

begin_comment
comment|/* manifest constants */
end_comment

begin_define
define|#
directive|define
name|NOTOK
value|(-1)
end_define

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_define
define|#
directive|define
name|NULLCP
value|((char *) 0)
end_define

begin_define
define|#
directive|define
name|MAXFOLDER
value|2000
end_define

begin_comment
comment|/* no mtstailor/.mh_profile here */
end_comment

begin_define
define|#
directive|define
name|mts_init
parameter_list|(
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|m_gmprot
parameter_list|()
value|0644
end_define

begin_comment
comment|/* maildrop delimiters */
end_comment

begin_define
define|#
directive|define
name|mmdlm1
value|delim1
end_define

begin_define
define|#
directive|define
name|mmdlm2
value|delim2
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|delim1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|delim2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* locking parameters */
end_comment

begin_define
define|#
directive|define
name|lockstyle
value|LOK_UNIX
end_define

begin_define
define|#
directive|define
name|lockldir
value|lckdfldir
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|lckdfldir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MH subroutines/stubs */
end_comment

begin_function_decl
name|void
name|admonish
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stringdex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|r1bindex
parameter_list|()
function_decl|;
end_function_decl

end_unit

