begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|VERSION
value|"1.7b 1985-04-19"
end_define

begin_comment
comment|/* Choose one of these */
end_comment

begin_comment
comment|/* #define XENIX */
end_comment

begin_comment
comment|/* XENIX implies UNIX                           */
end_comment

begin_comment
comment|/* #define SIII */
end_comment

begin_comment
comment|/* SIII  implies UNIX, (NDELAY a la System III) */
end_comment

begin_define
define|#
directive|define
name|UNIX
end_define

begin_comment
comment|/* UNIX                                         */
end_comment

begin_comment
comment|/* #define VMS */
end_comment

begin_comment
comment|/* VMS not done yet -- send me your version!!!! */
end_comment

begin_comment
comment|/* #define SARG20 */
end_comment

begin_comment
comment|/* Sargasso C for TOPS-20                       */
end_comment

begin_comment
comment|/* #define SARG10 */
end_comment

begin_comment
comment|/* Sargasso C for TOPS-10                       */
end_comment

begin_comment
comment|/* These #ifdef:s are implementation dependent stuff for the Sargasso C */
end_comment

begin_comment
comment|/* Unix C barfs on directives like "#strings", so we keep them	        */
end_comment

begin_comment
comment|/* indented. Then unix c can't find them, but Sargasso C *can*.		*/
end_comment

begin_comment
comment|/* Admittedly kludgey, but it works...)					*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SARG10
end_ifdef

begin_define
define|#
directive|define
name|_UNIXCON
end_define

begin_comment
comment|/* Make UNIX-flavored I/O on TOPS */
end_comment

begin_empty
empty|#strings low
end_empty

begin_comment
comment|/* put strings in lowseg mem so we can modify them. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SARG20
end_ifdef

begin_define
define|#
directive|define
name|_UNIXCON
end_define

begin_comment
comment|/* Make UNIX-flavored I/O on TOPS */
end_comment

begin_empty
empty|#strings low
end_empty

begin_comment
comment|/* put strings in lowseg mem so we can modify them. */
end_comment

begin_include
include|#
directive|include
file|<TOPS20.HDR>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
name|jmp_buf
name|intrenv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sgttyb
name|sgttyOrg
decl_stmt|,
name|sgttyNew
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|stdioBuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|brkrd
decl_stmt|,
name|reading
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern onterm(
end_extern

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|onbrk
argument_list|()
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SIII
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|ttymode
decl_stmt|;
end_decl_stmt

end_unit

