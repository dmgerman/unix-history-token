begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*========================================================================*  *				Mined.h					  *  *========================================================================*/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|YMAX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_undef
undef|#
directive|undef
name|putchar
end_undef

begin_undef
undef|#
directive|undef
name|getchar
end_undef

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_undef
undef|#
directive|undef
name|EOF
end_undef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CE
decl_stmt|,
modifier|*
name|VS
decl_stmt|,
modifier|*
name|SO
decl_stmt|,
modifier|*
name|SE
decl_stmt|,
modifier|*
name|CL
decl_stmt|,
modifier|*
name|AL
decl_stmt|,
modifier|*
name|CM
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|YMAX
value|49
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|YMAX
value|24
end_define

begin_comment
comment|/* Maximum y coordinate starting at 0 */
end_comment

begin_comment
comment|/* Escape sequences. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|enter_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* String printed on entering mined */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rev_video
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* String for starting reverse video */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|normal_video
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* String for leaving reverse video */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rev_scroll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* String for reverse scrolling */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pos_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Absolute cursor positioning */
end_comment

begin_define
define|#
directive|define
name|X_PLUS
value|' '
end_define

begin_comment
comment|/* To be added to x for cursor sequence */
end_comment

begin_define
define|#
directive|define
name|Y_PLUS
value|' '
end_define

begin_comment
comment|/* To be added to y for cursor sequence */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_define
define|#
directive|define
name|XMAX
value|79
end_define

begin_comment
comment|/* Maximum x coordinate starting at 0*/
end_comment

begin_define
define|#
directive|define
name|SCREENMAX
value|(YMAX - 1)
end_define

begin_comment
comment|/* Number of lines displayed */
end_comment

begin_define
define|#
directive|define
name|XBREAK
value|(XMAX - 1)
end_define

begin_comment
comment|/* Line shift at this coordinate */
end_comment

begin_define
define|#
directive|define
name|SHIFT_SIZE
value|25
end_define

begin_comment
comment|/* Number of chars to shift */
end_comment

begin_define
define|#
directive|define
name|SHIFT_MARK
value|'!'
end_define

begin_comment
comment|/* Char indicating line continues */
end_comment

begin_define
define|#
directive|define
name|MAX_CHARS
value|1024
end_define

begin_comment
comment|/* Maximum chars on one line */
end_comment

begin_comment
comment|/* LINE_START must be rounded up to the lowest SHIFT_SIZE */
end_comment

begin_define
define|#
directive|define
name|LINE_START
value|(((-MAX_CHARS - 1) / SHIFT_SIZE) * SHIFT_SIZE \   				   - SHIFT_SIZE)
end_define

begin_define
define|#
directive|define
name|LINE_END
value|(MAX_CHARS + 1)
end_define

begin_comment
comment|/* Highest x-coordinate for line */
end_comment

begin_define
define|#
directive|define
name|LINE_LEN
value|(XMAX + 1)
end_define

begin_comment
comment|/* Number of characters on line */
end_comment

begin_define
define|#
directive|define
name|SCREEN_SIZE
value|(XMAX * YMAX)
end_define

begin_comment
comment|/* Size of I/O buffering */
end_comment

begin_define
define|#
directive|define
name|BLOCK_SIZE
value|1024
end_define

begin_comment
comment|/* Return values of functions */
end_comment

begin_define
define|#
directive|define
name|ERRORS
value|-1
end_define

begin_define
define|#
directive|define
name|NO_LINE
value|(ERRORS - 1)
end_define

begin_comment
comment|/* Must be< 0 */
end_comment

begin_define
define|#
directive|define
name|FINE
value|(ERRORS + 1)
end_define

begin_define
define|#
directive|define
name|NO_INPUT
value|(ERRORS + 2)
end_define

begin_define
define|#
directive|define
name|STD_OUT
value|1
end_define

begin_comment
comment|/* File descriptor for terminal */
end_comment

begin_if
if|#
directive|if
operator|(
name|CHIP
operator|==
name|INTEL
operator|)
end_if

begin_define
define|#
directive|define
name|MEMORY_SIZE
value|(50 * 1024)
end_define

begin_comment
comment|/* Size of data space to malloc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|REPORT
value|2
end_define

begin_comment
comment|/* Report change of lines on # lines */
end_comment

begin_typedef
typedef|typedef
name|int
name|FLAG
typedef|;
end_typedef

begin_comment
comment|/* General flags */
end_comment

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|NOT_VALID
value|2
end_define

begin_define
define|#
directive|define
name|VALID
value|3
end_define

begin_define
define|#
directive|define
name|OFF
value|4
end_define

begin_define
define|#
directive|define
name|ON
value|5
end_define

begin_comment
comment|/* Expression flags */
end_comment

begin_define
define|#
directive|define
name|FORWARD
value|6
end_define

begin_define
define|#
directive|define
name|REVERSE
value|7
end_define

begin_comment
comment|/* Yank flags */
end_comment

begin_define
define|#
directive|define
name|SMALLER
value|8
end_define

begin_define
define|#
directive|define
name|BIGGER
value|9
end_define

begin_define
define|#
directive|define
name|SAME
value|10
end_define

begin_define
define|#
directive|define
name|EMPTY
value|11
end_define

begin_define
define|#
directive|define
name|NO_DELETE
value|12
end_define

begin_define
define|#
directive|define
name|DELETE
value|13
end_define

begin_define
define|#
directive|define
name|READ
value|14
end_define

begin_define
define|#
directive|define
name|WRITE
value|15
end_define

begin_comment
comment|/*  * The Line structure.  Each line entry contains a pointer to the next line,  * a pointer to the previous line, a pointer to the text and an unsigned char  * telling at which offset of the line printing should start (usually 0).  */
end_comment

begin_struct
struct|struct
name|Line
block|{
name|struct
name|Line
modifier|*
name|next
decl_stmt|;
name|struct
name|Line
modifier|*
name|prev
decl_stmt|;
name|char
modifier|*
name|text
decl_stmt|;
name|unsigned
name|char
name|shift_count
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|Line
name|LINE
typedef|;
end_typedef

begin_comment
comment|/* Dummy line indicator */
end_comment

begin_define
define|#
directive|define
name|DUMMY
value|0x80
end_define

begin_define
define|#
directive|define
name|DUMMY_MASK
value|0x7F
end_define

begin_comment
comment|/* Expression definitions */
end_comment

begin_define
define|#
directive|define
name|NO_MATCH
value|0
end_define

begin_define
define|#
directive|define
name|MATCH
value|1
end_define

begin_define
define|#
directive|define
name|REG_ERROR
value|2
end_define

begin_define
define|#
directive|define
name|BEGIN_LINE
value|(2 * REG_ERROR)
end_define

begin_define
define|#
directive|define
name|END_LINE
value|(2 * BEGIN_LINE)
end_define

begin_comment
comment|/*  * The regex structure. Status can be any of 0, BEGIN_LINE or REG_ERROR. In  * the last case, the result.err_mess field is assigned. Start_ptr and end_ptr  * point to the match found. For more details see the documentation file.  */
end_comment

begin_struct
struct|struct
name|regex
block|{
union|union
block|{
name|char
modifier|*
name|err_mess
decl_stmt|;
name|int
modifier|*
name|expression
decl_stmt|;
block|}
name|result
union|;
name|char
name|status
decl_stmt|;
name|char
modifier|*
name|start_ptr
decl_stmt|;
name|char
modifier|*
name|end_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|regex
name|REGEX
typedef|;
end_typedef

begin_comment
comment|/* NULL definitions */
end_comment

begin_define
define|#
directive|define
name|NIL_PTR
value|((char *) 0)
end_define

begin_define
define|#
directive|define
name|NIL_LINE
value|((LINE *) 0)
end_define

begin_define
define|#
directive|define
name|NIL_REG
value|((REGEX *) 0)
end_define

begin_define
define|#
directive|define
name|NIL_INT
value|((int *) 0)
end_define

begin_comment
comment|/*  * Forward declarations  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nlines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of lines in file */
end_comment

begin_decl_stmt
specifier|extern
name|LINE
modifier|*
name|header
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Head of line list */
end_comment

begin_decl_stmt
specifier|extern
name|LINE
modifier|*
name|tail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last line in line list */
end_comment

begin_decl_stmt
specifier|extern
name|LINE
modifier|*
name|top_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* First line of screen */
end_comment

begin_decl_stmt
specifier|extern
name|LINE
modifier|*
name|bot_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last line of screen */
end_comment

begin_decl_stmt
specifier|extern
name|LINE
modifier|*
name|cur_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current line in use */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cur_text
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to char on current line in use */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|last_y
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last y of screen. Usually SCREENMAX */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ymax
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|screenmax
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|screen
index|[
name|SCREEN_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output buffer for "writes" and "reads" */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* x, y coordinates on screen */
end_comment

begin_decl_stmt
specifier|extern
name|FLAG
name|modified
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set when file is modified */
end_comment

begin_decl_stmt
specifier|extern
name|FLAG
name|stat_visible
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set if status_line is visible */
end_comment

begin_decl_stmt
specifier|extern
name|FLAG
name|writable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set if file cannot be written */
end_comment

begin_decl_stmt
specifier|extern
name|FLAG
name|quit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set when quit character is typed */
end_comment

begin_decl_stmt
specifier|extern
name|FLAG
name|rpipe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set if file should be read from stdin */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|input_fd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fd for command input */
end_comment

begin_decl_stmt
specifier|extern
name|FLAG
name|loading
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set if we're loading a file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|out_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index in output buffer */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|file_name
index|[
name|LINE_LEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of file in use */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|text_buffer
index|[
name|MAX_CHARS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer for modifying text */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|blank_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clear line to end */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|yank_file
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temp file for buffer */
end_comment

begin_decl_stmt
specifier|extern
name|FLAG
name|yank_status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Status of yank_file */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|chars_saved
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nr of chars saved in buffer */
end_comment

begin_comment
comment|/*  * Empty output buffer  */
end_comment

begin_define
define|#
directive|define
name|clear_buffer
parameter_list|()
value|(out_count = 0)
end_define

begin_comment
comment|/*  * Print character on terminal  */
end_comment

begin_define
define|#
directive|define
name|putchar
parameter_list|(
name|c
parameter_list|)
value|(void) write_char(STD_OUT, (c))
end_define

begin_comment
comment|/*  * Ring bell on terminal  */
end_comment

begin_define
define|#
directive|define
name|ring_bell
parameter_list|()
value|putchar('\07')
end_define

begin_comment
comment|/*  * Print string on terminal  */
end_comment

begin_define
define|#
directive|define
name|string_print
parameter_list|(
name|str
parameter_list|)
value|(void) writeline(STD_OUT, (str))
end_define

begin_comment
comment|/*  * Flush output buffer  */
end_comment

begin_define
define|#
directive|define
name|flush
parameter_list|()
value|(void) flush_buffer(STD_OUT)
end_define

begin_comment
comment|/*  * Convert cnt to nearest tab position  */
end_comment

begin_define
define|#
directive|define
name|tab
parameter_list|(
name|cnt
parameter_list|)
value|(((cnt) + 8)& ~07)
end_define

begin_define
define|#
directive|define
name|is_tab
parameter_list|(
name|c
parameter_list|)
value|((c) == '\t')
end_define

begin_comment
comment|/*  * Word defenitions  */
end_comment

begin_define
define|#
directive|define
name|white_space
parameter_list|(
name|c
parameter_list|)
value|((c) == ' ' || (c) == '\t')
end_define

begin_define
define|#
directive|define
name|alpha
parameter_list|(
name|c
parameter_list|)
value|((c) != ' '&& (c) != '\t'&& (c) != '\n')
end_define

begin_comment
comment|/*  * Print line on terminal at offset 0 and clear tail of line  */
end_comment

begin_define
define|#
directive|define
name|line_print
parameter_list|(
name|line
parameter_list|)
value|put_line(line, 0, TRUE)
end_define

begin_comment
comment|/*  * Move to coordinates and set textp. (Don't use address)  */
end_comment

begin_define
define|#
directive|define
name|move_to
parameter_list|(
name|nx
parameter_list|,
name|ny
parameter_list|)
value|move((nx), NIL_PTR, (ny))
end_define

begin_comment
comment|/*  * Move to coordinates on screen as indicated by textp.  */
end_comment

begin_define
define|#
directive|define
name|move_address
parameter_list|(
name|address
parameter_list|)
value|move(0, (address), y)
end_define

begin_comment
comment|/*  * Functions handling status_line. ON means in reverse video.  */
end_comment

begin_define
define|#
directive|define
name|status_line
parameter_list|(
name|str1
parameter_list|,
name|str2
parameter_list|)
value|(void) bottom_line(ON, (str1), \ 						    (str2), NIL_PTR, FALSE)
end_define

begin_define
define|#
directive|define
name|error
parameter_list|(
name|str1
parameter_list|,
name|str2
parameter_list|)
value|(void) bottom_line(ON, (str1), \ 						    (str2), NIL_PTR, FALSE)
end_define

begin_define
define|#
directive|define
name|get_string
parameter_list|(
name|str1
parameter_list|,
name|str2
parameter_list|,
name|fl
parameter_list|)
value|bottom_line(ON, (str1), NIL_PTR, (str2), fl)
end_define

begin_define
define|#
directive|define
name|clear_status
parameter_list|()
value|(void) bottom_line(OFF, NIL_PTR, NIL_PTR, \ 						    NIL_PTR, FALSE)
end_define

begin_comment
comment|/*  * Print info about current file and buffer.  */
end_comment

begin_define
define|#
directive|define
name|fstatus
parameter_list|(
name|mess
parameter_list|,
name|cnt
parameter_list|)
value|file_status((mess), (cnt), file_name, \ 					     nlines, writable, modified)
end_define

begin_comment
comment|/*  * Get real shift value.  */
end_comment

begin_define
define|#
directive|define
name|get_shift
parameter_list|(
name|cnt
parameter_list|)
value|((cnt)& DUMMY_MASK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* YMAX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|_PROTOTYPE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x ## y
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mined1.c */
end_comment

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void FS
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void VI
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int WT
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void XWT
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void SH
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|LINE
operator|*
name|proceed
argument_list|,
operator|(
name|LINE
operator|*
name|line
operator|,
name|int
name|count
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int bottom_line
argument_list|,
argument|(FLAG revfl, char *s1, char *s2, char *inbuf, FLAG statfl )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int count_chars
argument_list|,
argument|(LINE *line )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void move
argument_list|,
argument|(int new_x, char *new_address, int new_y )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int find_x
argument_list|,
argument|(LINE *line, char *address )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|find_address
argument_list|,
operator|(
name|LINE
operator|*
name|line
operator|,
name|int
name|x_coord
operator|,
name|int
operator|*
name|old_x
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int length_of
argument_list|,
argument|(char *string )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void copy_string
argument_list|,
argument|(char *to, char *from )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void reset
argument_list|,
argument|(LINE *head_line, int screen_y )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void set_cursor
argument_list|,
argument|(int nx, int ny )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void open_device
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int getchar
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void display
argument_list|,
argument|(int x_coord, int y_coord, LINE *line, int count )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int write_char
argument_list|,
argument|(int fd, int c )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int writeline
argument_list|,
argument|(int fd, char *text )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void put_line
argument_list|,
argument|(LINE *line, int offset, FLAG clear_line )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int flush_buffer
argument_list|,
argument|(int fd )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void bad_write
argument_list|,
argument|(int fd )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void catch
argument_list|,
argument|(int sig )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void abort_mined
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void raw_mode
argument_list|,
argument|(FLAG state )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void panic
argument_list|,
argument|(char *message )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|alloc
argument_list|,
operator|(
name|int
name|bytes
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void free_space
argument_list|,
argument|(char *p )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* #ifdef UNIX _PROTOTYPE(void (*key_map [128]), (void)); #else _PROTOTYPE(void (*key_map [256]), (void)); #endif */
end_comment

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void initialize
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|basename
argument_list|,
operator|(
name|char
operator|*
name|path
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void load_file
argument_list|,
argument|(char *file )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int get_line
argument_list|,
argument|(int fd, char *buffer )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|LINE
operator|*
name|install_line
argument_list|,
operator|(
name|char
operator|*
name|buffer
operator|,
name|int
name|length
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|void
expr|main
argument_list|,
operator|(
name|int
name|argc
operator|,
name|char
operator|*
name|argv
index|[]
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void RD
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void I
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void XT
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void ESC
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int ask_save
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int line_number
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void file_status
argument_list|,
argument|(char *message, long count, char *file, int lines, 						 FLAG writefl, FLAG changed )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
name|void
name|build_string
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|build_string
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|num_out
argument_list|,
operator|(
name|long
name|number
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int get_number
argument_list|,
argument|(char *message, int *result )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int input
argument_list|,
argument|(char *inbuf, FLAG clearfl )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int get_file
argument_list|,
argument|(char *message, char *file )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int _getchar
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void _flush
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void _putchar
argument_list|,
argument|(int c )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void get_term
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* mined2.c */
end_comment

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void UP
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void DN
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void LF
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void RT
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void HIGH
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void LOW
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void BL
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void EL
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void GOTO
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void HLP
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void PD
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void PU
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void HO
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void EF
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void SU
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void SD
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int forward_scroll
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int reverse_scroll
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void MP
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void move_previous_word
argument_list|,
argument|(FLAG remove )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void MN
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void move_next_word
argument_list|,
argument|(FLAG remove )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void DCC
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void DPC
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void DLN
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void DNW
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void DPW
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void S
argument_list|,
argument|(int character )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void CTL
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void LIB
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|LINE
operator|*
name|line_insert
argument_list|,
operator|(
name|LINE
operator|*
name|line
operator|,
name|char
operator|*
name|string
operator|,
name|int
name|len
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int insert
argument_list|,
argument|(LINE *line, char *location, char *string )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|LINE
operator|*
name|line_delete
argument_list|,
operator|(
name|LINE
operator|*
name|line
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void delete
argument_list|,
argument|(LINE *start_line, char *start_textp, LINE *end_line, char *end_textp )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void PT
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void IF
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void file_insert
argument_list|,
argument|(int fd, FLAG old_pos )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void WB
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void MA
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void YA
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void DT
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void set_up
argument_list|,
argument|(FLAG remove )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|FLAG checkmark
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int legal
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void yank
argument_list|,
argument|(LINE *start_line, char *start_textp, LINE *end_line, char *end_textp, FLAG remove )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int scratch_file
argument_list|,
argument|(FLAG mode )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void SF
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void SR
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|REGEX
operator|*
name|get_expression
argument_list|,
operator|(
name|char
operator|*
name|message
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void GR
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void LR
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void change
argument_list|,
argument|(char *message, FLAG file )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|substitute
argument_list|,
operator|(
name|LINE
operator|*
name|line
operator|,
name|REGEX
operator|*
name|program
operator|,
name|char
operator|*
name|replacement
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void search
argument_list|,
argument|(char *message, FLAG method )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int find_y
argument_list|,
argument|(LINE *match_line )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void finished
argument_list|,
argument|(REGEX *program, int *last_exp )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void compile
argument_list|,
argument|(char *pattern, REGEX *program )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|LINE
operator|*
name|match
argument_list|,
operator|(
name|REGEX
operator|*
name|program
operator|,
name|char
operator|*
name|string
operator|,
name|FLAG
name|method
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int line_check
argument_list|,
argument|(REGEX *program, char *string, FLAG method )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int check_string
argument_list|,
argument|(REGEX *program, char *string, int *expression )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int star
argument_list|,
argument|(REGEX *program, char *end_position, char *string, int *expression )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int in_list
argument_list|,
argument|(int *list, int c, int list_length, int opcode )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void dummy_line
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

