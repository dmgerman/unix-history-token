begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The option table.  */
end_comment

begin_include
include|#
directive|include
file|"less.h"
end_include

begin_include
include|#
directive|include
file|"option.h"
end_include

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
value|((c)-'a'+'A')
end_define

begin_comment
comment|/*  * Variables controlled by command line options.  */
end_comment

begin_decl_stmt
name|public
name|int
name|quiet
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Should we suppress the audible bell? */
end_comment

begin_decl_stmt
name|public
name|int
name|how_search
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where should forward searches start? */
end_comment

begin_decl_stmt
name|public
name|int
name|top_scroll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Repaint screen from top? 				   (alternative is scroll from bottom) */
end_comment

begin_decl_stmt
name|public
name|int
name|pr_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Type of prompt (short, medium, long) */
end_comment

begin_decl_stmt
name|public
name|int
name|bs_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* How to process backspaces */
end_comment

begin_decl_stmt
name|public
name|int
name|know_dumb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't complain about dumb terminals */
end_comment

begin_decl_stmt
name|public
name|int
name|quit_at_eof
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Quit after hitting end of file twice */
end_comment

begin_decl_stmt
name|public
name|int
name|squeeze
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Squeeze multiple blank lines into one */
end_comment

begin_decl_stmt
name|public
name|int
name|tabstop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tab settings */
end_comment

begin_decl_stmt
name|public
name|int
name|back_scroll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Repaint screen on backwards movement */
end_comment

begin_decl_stmt
name|public
name|int
name|forw_scroll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Repaint screen on forward movement */
end_comment

begin_decl_stmt
name|public
name|int
name|twiddle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Display "~" for lines after EOF */
end_comment

begin_decl_stmt
name|public
name|int
name|caseless
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do "caseless" searches */
end_comment

begin_decl_stmt
name|public
name|int
name|linenums
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use line numbers */
end_comment

begin_decl_stmt
name|public
name|int
name|cbufs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current number of buffers */
end_comment

begin_decl_stmt
name|public
name|int
name|autobuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Automatically allocate buffers as needed */
end_comment

begin_decl_stmt
name|public
name|int
name|nohelp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Disable the HELP command */
end_comment

begin_decl_stmt
name|public
name|int
name|ctldisp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Send control chars to screen untranslated */
end_comment

begin_decl_stmt
name|public
name|int
name|force_open
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Open the file even if not regular file */
end_comment

begin_decl_stmt
name|public
name|int
name|swindow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Size of scrolling window */
end_comment

begin_decl_stmt
name|public
name|int
name|jump_sline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Screen line of "jump target" */
end_comment

begin_decl_stmt
name|public
name|int
name|chopline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Truncate displayed lines at screen width */
end_comment

begin_if
if|#
directive|if
name|__MSDOS__
end_if

begin_decl_stmt
name|public
name|int
name|output_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Which screen output method */
end_comment

begin_decl_stmt
name|public
name|int
name|refresh_on_quit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Repaint screen on quit, if possible */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Table of all options and their semantics.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|option
name|option
index|[]
init|=
block|{
block|{
literal|'a'
block|,
name|BOOL
block|,
literal|0
block|,
operator|&
name|how_search
block|,
name|NULL
block|,
literal|"Search includes displayed screen"
block|,
literal|"Search skips displayed screen"
block|,
name|NULL
block|}
block|,
block|{
literal|'b'
block|,
name|NUMBER
block|,
literal|10
block|,
operator|&
name|cbufs
block|,
name|opt_b
block|,
literal|"Buffers: "
block|,
literal|"%d buffers"
block|,
name|NULL
block|}
block|,
block|{
literal|'B'
block|,
name|BOOL
block|,
literal|1
block|,
operator|&
name|autobuf
block|,
name|NULL
block|,
literal|"Don't automatically allocate buffers"
block|,
literal|"Automatically allocate buffers when needed"
block|,
name|NULL
block|}
block|,
block|{
literal|'c'
block|,
name|TRIPLE
block|,
literal|0
block|,
operator|&
name|top_scroll
block|,
name|NULL
block|,
literal|"Repaint by scrolling from bottom of screen"
block|,
literal|"Repaint by clearing each line"
block|,
literal|"Repaint by painting from top of screen"
block|}
block|,
block|{
literal|'d'
block|,
name|BOOL
operator||
name|NO_TOGGLE
block|,
literal|0
block|,
operator|&
name|know_dumb
block|,
name|NULL
block|,
literal|"Assume intelligent terminal"
block|,
literal|"Assume dumb terminal"
block|,
name|NULL
block|}
block|,
block|{
literal|'e'
block|,
name|TRIPLE
block|,
literal|0
block|,
operator|&
name|quit_at_eof
block|,
name|NULL
block|,
literal|"Don't quit at end-of-file"
block|,
literal|"Quit at end-of-file"
block|,
literal|"Quit immediately at end-of-file"
block|}
block|,
block|{
literal|'f'
block|,
name|BOOL
block|,
literal|0
block|,
operator|&
name|force_open
block|,
name|NULL
block|,
literal|"Open only regular files"
block|,
literal|"Open even non-regular files"
block|,
name|NULL
block|}
block|,
block|{
literal|'h'
block|,
name|NUMBER
block|,
operator|-
literal|1
block|,
operator|&
name|back_scroll
block|,
name|NULL
block|,
literal|"Backwards scroll limit: "
block|,
literal|"Backwards scroll limit is %d lines"
block|,
name|NULL
block|}
block|,
block|{
literal|'H'
block|,
name|BOOL
operator||
name|NO_TOGGLE
block|,
literal|0
block|,
operator|&
name|nohelp
block|,
name|NULL
block|,
literal|"Allow help command"
block|,
literal|"Don't allow help command"
block|,
name|NULL
block|}
block|,
block|{
literal|'i'
block|,
name|BOOL
block|,
literal|0
block|,
operator|&
name|caseless
block|,
name|NULL
block|,
literal|"Case is significant in searches"
block|,
literal|"Ignore case in searches"
block|,
name|NULL
block|}
block|,
block|{
literal|'j'
block|,
name|NUMBER
block|,
literal|1
block|,
operator|&
name|jump_sline
block|,
name|NULL
block|,
literal|"Target line: "
block|,
literal|"Position target at screen line %d"
block|,
name|NULL
block|}
block|,
if|#
directive|if
name|USERFILE
block|{
literal|'k'
block|,
name|STRING
operator||
name|NO_TOGGLE
block|,
literal|0
block|,
name|NULL
block|,
name|opt_k
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|LOGFILE
block|{
literal|'l'
block|,
name|STRING
block|,
literal|0
block|,
name|NULL
block|,
name|opt_l
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|'L'
block|,
name|STRING
block|,
literal|0
block|,
name|NULL
block|,
name|opt__L
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
endif|#
directive|endif
block|{
literal|'m'
block|,
name|TRIPLE
block|,
literal|0
block|,
operator|&
name|pr_type
block|,
name|NULL
block|,
literal|"Short prompt"
block|,
literal|"Medium prompt"
block|,
literal|"Long prompt"
block|}
block|,
block|{
literal|'n'
block|,
name|TRIPLE
operator||
name|REPAINT
block|,
literal|1
block|,
operator|&
name|linenums
block|,
name|NULL
block|,
literal|"Don't use line numbers"
block|,
literal|"Use line numbers"
block|,
literal|"Constantly display line numbers"
block|}
block|,
if|#
directive|if
name|LOGFILE
block|{
literal|'o'
block|,
name|STRING
block|,
literal|0
block|,
name|NULL
block|,
name|opt_o
block|,
literal|"log file: "
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|'O'
block|,
name|STRING
block|,
literal|0
block|,
name|NULL
block|,
name|opt__O
block|,
literal|"Log file: "
block|,
name|NULL
block|,
name|NULL
block|}
block|,
endif|#
directive|endif
block|{
literal|'p'
block|,
name|STRING
operator||
name|NO_TOGGLE
block|,
literal|0
block|,
name|NULL
block|,
name|opt_p
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|'P'
block|,
name|STRING
block|,
literal|0
block|,
name|NULL
block|,
name|opt__P
block|,
literal|"prompt: "
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|'q'
block|,
name|TRIPLE
block|,
literal|0
block|,
operator|&
name|quiet
block|,
name|NULL
block|,
literal|"Ring the bell for errors AND at eof/bof"
block|,
literal|"Ring the bell for errors but not at eof/bof"
block|,
literal|"Never ring the bell"
block|}
block|,
block|{
literal|'r'
block|,
name|BOOL
operator||
name|REPAINT
block|,
literal|1
block|,
operator|&
name|ctldisp
block|,
name|NULL
block|,
literal|"Display control characters directly"
block|,
literal|"Display control characters as ^X"
block|,
name|NULL
block|}
block|,
if|#
directive|if
name|__MSDOS__
block|{
literal|'R'
block|,
name|BOOL
operator||
name|REPAINT
block|,
literal|0
block|,
operator|&
name|refresh_on_quit
block|,
name|NULL
block|,
literal|"Don't repaint screen on quit"
block|,
literal|"Repaint screen on quit"
block|,
name|NULL
block|}
block|,
endif|#
directive|endif
block|{
literal|'s'
block|,
name|BOOL
operator||
name|REPAINT
block|,
literal|0
block|,
operator|&
name|squeeze
block|,
name|NULL
block|,
literal|"Display all blank lines"
block|,
literal|"Squeeze multiple blank lines"
block|,
name|NULL
block|}
block|,
block|{
literal|'S'
block|,
name|BOOL
operator||
name|REPAINT
block|,
literal|0
block|,
operator|&
name|chopline
block|,
name|NULL
block|,
literal|"Fold long lines"
block|,
literal|"Chop long lines"
block|,
name|NULL
block|}
block|,
if|#
directive|if
name|TAGS
block|{
literal|'t'
block|,
name|STRING
block|,
literal|0
block|,
name|NULL
block|,
name|opt_t
block|,
literal|"tag: "
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|'T'
block|,
name|STRING
block|,
literal|0
block|,
name|NULL
block|,
name|opt__T
block|,
literal|"tags file: "
block|,
name|NULL
block|,
name|NULL
block|}
block|,
endif|#
directive|endif
block|{
literal|'u'
block|,
name|TRIPLE
operator||
name|REPAINT
block|,
literal|0
block|,
operator|&
name|bs_mode
block|,
name|NULL
block|,
literal|"Display underlined text in underline mode"
block|,
literal|"Backspaces cause overstrike"
block|,
literal|"Print backspace as ^H"
block|}
block|,
if|#
directive|if
name|__MSDOS__
block|{
literal|'v'
block|,
name|TRIPLE
operator||
name|NO_TOGGLE
block|,
literal|0
block|,
operator|&
name|output_mode
block|,
name|opt_v
block|,
literal|"Output is to standard output, using ansi screen control"
block|,
literal|"Output is to video BIOS"
block|,
literal|"Output is directly to memory mapped video"
block|}
block|,
endif|#
directive|endif
block|{
literal|'w'
block|,
name|BOOL
operator||
name|REPAINT
block|,
literal|1
block|,
operator|&
name|twiddle
block|,
name|NULL
block|,
literal|"Display nothing for lines after end-of-file"
block|,
literal|"Display ~ for lines after end-of-file"
block|,
name|NULL
block|}
block|,
if|#
directive|if
name|__MSDOS__
if|#
directive|if
name|MOVE_WINDOW
define|#
directive|define
name|W_FLAGS
value|STRING
else|#
directive|else
define|#
directive|define
name|W_FLAGS
value|STRING|NO_TOGGLE
endif|#
directive|endif
block|{
literal|'W'
block|,
name|W_FLAGS
block|,
literal|0
block|,
name|NULL
block|,
name|opt_W
block|,
literal|"window boundaries: "
block|,
name|NULL
block|,
name|NULL
block|}
block|,
undef|#
directive|undef
name|W_FLAGS
endif|#
directive|endif
block|{
literal|'x'
block|,
name|NUMBER
operator||
name|REPAINT
block|,
literal|8
block|,
operator|&
name|tabstop
block|,
name|NULL
block|,
literal|"Tab stops: "
block|,
literal|"Tab stops every %d spaces"
block|,
name|NULL
block|}
block|,
block|{
literal|'y'
block|,
name|NUMBER
block|,
operator|-
literal|1
block|,
operator|&
name|forw_scroll
block|,
name|NULL
block|,
literal|"Forward scroll limit: "
block|,
literal|"Forward scroll limit is %d lines"
block|,
name|NULL
block|}
block|,
block|{
literal|'z'
block|,
name|NUMBER
block|,
operator|-
literal|1
block|,
operator|&
name|swindow
block|,
name|NULL
block|,
literal|"Scroll window size: "
block|,
literal|"Scroll window size is %d lines"
block|,
name|NULL
block|}
block|,
block|{
literal|'?'
block|,
name|NOVAR
block|,
literal|0
block|,
name|NULL
block|,
name|opt_query
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|'\0'
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Initialize each option to its default value.  */
end_comment

begin_function
name|public
name|void
name|init_option
parameter_list|()
block|{
specifier|register
name|struct
name|option
modifier|*
name|o
decl_stmt|;
for|for
control|(
name|o
operator|=
name|option
init|;
name|o
operator|->
name|oletter
operator|!=
literal|'\0'
condition|;
name|o
operator|++
control|)
block|{
comment|/* 		 * Set each variable to its default. 		 */
if|if
condition|(
name|o
operator|->
name|ovar
operator|!=
name|NULL
condition|)
operator|*
operator|(
name|o
operator|->
name|ovar
operator|)
operator|=
name|o
operator|->
name|odefault
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Find an option in the option table.  */
end_comment

begin_function
name|public
name|struct
name|option
modifier|*
name|findopt
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
specifier|register
name|struct
name|option
modifier|*
name|o
decl_stmt|;
for|for
control|(
name|o
operator|=
name|option
init|;
name|o
operator|->
name|oletter
operator|!=
literal|'\0'
condition|;
name|o
operator|++
control|)
block|{
if|if
condition|(
name|o
operator|->
name|oletter
operator|==
name|c
condition|)
return|return
operator|(
name|o
operator|)
return|;
if|if
condition|(
operator|(
name|o
operator|->
name|otype
operator|&
name|TRIPLE
operator|)
operator|&&
name|toupper
argument_list|(
name|o
operator|->
name|oletter
argument_list|)
operator|==
name|c
condition|)
return|return
operator|(
name|o
operator|)
return|;
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

end_unit

