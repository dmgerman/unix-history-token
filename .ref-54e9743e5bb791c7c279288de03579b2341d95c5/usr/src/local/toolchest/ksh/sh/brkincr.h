begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)brkincr.h	1.1 */
end_comment

begin_comment
comment|/*  *	UNIX shell  *	S. R. Bourne  *	Rewritten by David Korn  *  */
end_comment

begin_if
if|#
directive|if
name|u370
operator|||
name|uts
end_if

begin_define
define|#
directive|define
name|BRKINCR
value|4096
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BRKINCR
value|((int)(0400*sizeof(char*)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* u370 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INT16
end_ifdef

begin_define
define|#
directive|define
name|BRKMAX
value|((unsigned)(077777-BRKINCR))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BRKMAX
value|(1024*BRKINCR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INT16 */
end_comment

begin_define
define|#
directive|define
name|MINTRAP
value|0
end_define

begin_define
define|#
directive|define
name|MAXTRAP
value|NSIG+1
end_define

begin_define
define|#
directive|define
name|SIGBITS
value|8
end_define

begin_define
define|#
directive|define
name|SIGSLOW
value|1
end_define

begin_define
define|#
directive|define
name|SIGSET
value|4
end_define

begin_define
define|#
directive|define
name|SIGMOD
value|8
end_define

begin_comment
comment|/*  * SIGNOSET means that signal not set unless mentioned explicitly  * SIGCAUGHT signals trap to fault, others to done  */
end_comment

begin_define
define|#
directive|define
name|SIGCAUGHT
value|16
end_define

begin_define
define|#
directive|define
name|SIGNOSET
value|32
end_define

begin_define
define|#
directive|define
name|SIGIGNORE
value|64
end_define

begin_define
define|#
directive|define
name|SIGJOBS
value|128
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|BSD_4_2
end_ifdef

begin_define
define|#
directive|define
name|sighold
parameter_list|(
name|s
parameter_list|)
value|sigblock(1<<((s)-1))
end_define

begin_define
define|#
directive|define
name|sigrelse
parameter_list|(
name|s
parameter_list|)
value|sigsetmask(sigblock(0)&~(1<<((s)-1)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|signal
value|sigset
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD_4_2 */
end_comment

begin_else
else|#
directive|else
end_else

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_define
define|#
directive|define
name|SIGFAIL
value|0200
end_define

begin_define
define|#
directive|define
name|SIGFLG
value|0200
end_define

begin_define
define|#
directive|define
name|TRAPSET
value|2
end_define

begin_struct
struct|struct
name|blk
comment|/* heap storage */
block|{
name|BLKPTR
name|word
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|brkbegin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BLKPTR
name|blokp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current search pointer*/
end_comment

begin_decl_stmt
specifier|extern
name|BLKPTR
name|bloktop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*top of arena (last blok) 						   initialized in addblok */
end_comment

begin_decl_stmt
specifier|extern
name|jmp_buf
name|subshell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* jump here for subshell */
end_comment

begin_decl_stmt
specifier|extern
name|jmp_buf
modifier|*
name|freturn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return pointer for functions or failure */
end_comment

begin_decl_stmt
specifier|extern
name|jmp_buf
name|errshell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return here on failures */
end_comment

end_unit

