begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_TUI_SOURCE_H
end_ifndef

begin_define
define|#
directive|define
name|_TUI_SOURCE_H
end_define

begin_comment
comment|/* ** This header file supports */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_include
include|#
directive|include
file|"breakpoint.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|TuiStatus
name|tuiSetSourceContent
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab
operator|*
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
name|void
name|tuiShowSource
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab
operator|*
operator|,
name|Opaque
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiShowSourceAsIs
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab
operator|*
operator|,
name|Opaque
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tuiSourceIsDisplayed
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiVerticalSourceScroll
name|PARAMS
argument_list|(
operator|(
name|TuiScrollDirection
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/******************* ** MACROS         ** *******************/
end_comment

begin_define
define|#
directive|define
name|m_tuiShowSourceAsIs
parameter_list|(
name|s
parameter_list|,
name|line
parameter_list|,
name|noerror
parameter_list|)
value|tuiUpdateSourceWindowAsIs(srcWin, s, line, noerror)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_TUI_SOURCE_H*/
end_comment

end_unit

