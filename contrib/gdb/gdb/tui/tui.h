begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* External/Public TUI Header File */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TUI_H
end_ifndef

begin_define
define|#
directive|define
name|TUI_H
end_define

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_PROTOTYPES
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|reg
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|reg
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|chtype
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|chtype
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Opaque data type */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|Opaque
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Opaque
argument_list|(
argument|*OpaqueFuncPtr
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|va_list
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
modifier|*
name|OpaqueList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|OpaqueList
name|OpaquePtr
typedef|;
end_typedef

begin_comment
comment|/* Generic function pointer */
end_comment

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*TuiVoidFuncPtr
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|va_list
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*TuiIntFuncPtr
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|va_list
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* typedef     Opaque            (*TuiOpaqueFuncPtr) PARAMS ((va_list)); */
end_comment

begin_typedef
typedef|typedef
name|OpaqueFuncPtr
name|TuiOpaqueFuncPtr
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|Opaque
name|vcatch_errors
name|PARAMS
argument_list|(
operator|(
name|OpaqueFuncPtr
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Opaque
name|va_catch_errors
name|PARAMS
argument_list|(
operator|(
name|OpaqueFuncPtr
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|strcat_to_buf
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|strcat_to_buf_with_fmt
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Types of error returns */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TUI_SUCCESS
block|,
name|TUI_FAILURE
block|}
name|TuiStatus
operator|,
typedef|*
name|TuiStatusPtr
typedef|;
end_typedef

begin_comment
comment|/* Types of windows */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SRC_WIN
init|=
literal|0
block|,
name|DISASSEM_WIN
block|,
name|DATA_WIN
block|,
name|CMD_WIN
block|,
comment|/* This must ALWAYS be AFTER the major windows last */
name|MAX_MAJOR_WINDOWS
block|,
comment|/* auxillary windows */
name|LOCATOR_WIN
block|,
name|EXEC_INFO_WIN
block|,
name|DATA_ITEM_WIN
block|,
comment|/* This must ALWAYS be next to last */
name|MAX_WINDOWS
block|,
name|UNDEFINED_WIN
comment|/* LAST */
block|}
name|TuiWinType
operator|,
typedef|*
name|TuiWinTypePtr
typedef|;
end_typedef

begin_comment
comment|/* This is a point definition */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TuiPoint
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|TuiPoint
operator|,
typedef|*
name|TuiPointPtr
typedef|;
end_typedef

begin_comment
comment|/* Generic window information */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TuiGenWinInfo
block|{
name|WINDOW
modifier|*
name|handle
decl_stmt|;
comment|/* window handle */
name|TuiWinType
name|type
decl_stmt|;
comment|/* type of window */
name|int
name|width
decl_stmt|;
comment|/* window width */
name|int
name|height
decl_stmt|;
comment|/* window height */
name|TuiPoint
name|origin
decl_stmt|;
comment|/* origin of window */
name|OpaquePtr
name|content
decl_stmt|;
comment|/* content of window */
name|int
name|contentSize
decl_stmt|;
comment|/* Size of content (# of elements) */
name|int
name|contentInUse
decl_stmt|;
comment|/* Can it be used, or is it already used? */
name|int
name|viewportHeight
decl_stmt|;
comment|/* viewport height */
name|int
name|lastVisibleLine
decl_stmt|;
comment|/* index of last visible line */
name|int
name|isVisible
decl_stmt|;
comment|/* whether the window is visible or not */
block|}
name|TuiGenWinInfo
operator|,
typedef|*
name|TuiGenWinInfoPtr
typedef|;
end_typedef

begin_comment
comment|/* GENERAL TUI FUNCTIONS */
end_comment

begin_comment
comment|/* tui.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|tuiInit
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|argv0
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiInitWindows
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiResetScreen
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiCleanUp
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiError
name|PARAMS
argument_list|(
operator|(
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
name|void
name|tui_vError
name|PARAMS
argument_list|(
operator|(
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiFree
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
name|Opaque
name|tuiDo
name|PARAMS
argument_list|(
operator|(
name|TuiOpaqueFuncPtr
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Opaque
name|tuiDoAndReturnToTop
name|PARAMS
argument_list|(
operator|(
name|TuiOpaqueFuncPtr
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Opaque
name|tuiGetLowDisassemblyAddress
name|PARAMS
argument_list|(
operator|(
name|Opaque
operator|,
name|Opaque
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Opaque
name|tui_vGetLowDisassemblyAddress
name|PARAMS
argument_list|(
operator|(
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tui_vSelectSourceSymtab
name|PARAMS
argument_list|(
operator|(
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tuiDataWin.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|tui_vCheckDataValues
name|PARAMS
argument_list|(
operator|(
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tuiIO.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|tui_vStartNewLines
name|PARAMS
argument_list|(
operator|(
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tuiLayout.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|tui_vAddWinToLayout
name|PARAMS
argument_list|(
operator|(
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiStatus
name|tui_vSetLayoutTo
name|PARAMS
argument_list|(
operator|(
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tuiSourceWin.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|tuiDisplayMainFunction
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiUpdateAllExecInfos
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiUpdateOnEnd
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tui_vAllSetHasBreakAt
name|PARAMS
argument_list|(
operator|(
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tui_vUpdateSourceWindowsWithAddr
name|PARAMS
argument_list|(
operator|(
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tuiStack.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|tui_vShowFrameInfo
name|PARAMS
argument_list|(
operator|(
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tui_vUpdateLocatorFilename
name|PARAMS
argument_list|(
operator|(
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TUI_H */
end_comment

end_unit

