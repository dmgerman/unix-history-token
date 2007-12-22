begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** Copyright (C) 1991, 1997 Free Software Foundation, Inc. **  ** This file is part of TACK. **  ** TACK is free software; you can redistribute it and/or modify ** it under the terms of the GNU General Public License as published by ** the Free Software Foundation; either version 2, or (at your option) ** any later version. **  ** TACK is distributed in the hope that it will be useful, ** but WITHOUT ANY WARRANTY; without even the implied warranty of ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the ** GNU General Public License for more details. **  ** You should have received a copy of the GNU General Public License ** along with TACK; see the file COPYING.  If not, write to ** the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, ** Boston, MA 02110-1301, USA */
end_comment

begin_comment
comment|/* $Id: tack.h,v 1.16 2006/11/25 23:45:00 tom Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NCURSES_TACK_H_incl
end_ifndef

begin_define
define|#
directive|define
name|NCURSES_TACK_H_incl
value|1
end_define

begin_comment
comment|/* terminfo action checker include file */
end_comment

begin_define
define|#
directive|define
name|MAJOR_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|MINOR_VERSION
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<ncurses_cfg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_define
define|#
directive|define
name|GCC_UNUSED
end_define

begin_comment
comment|/*nothing*/
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SELECT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_SELECT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
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
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|<term_entry.h>
end_include

begin_include
include|#
directive|include
file|<nc_tparm.h>
end_include

begin_if
if|#
directive|if
name|USE_RCS_IDS
end_if

begin_define
define|#
directive|define
name|MODULE_ID
parameter_list|(
name|id
parameter_list|)
value|static const char Ident[] = id;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MODULE_ID
parameter_list|(
name|id
parameter_list|)
end_define

begin_comment
comment|/*nothing*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_STRSTR
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|_nc_strstr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|strstr
parameter_list|(
name|h
parameter_list|,
name|n
parameter_list|)
value|_nc_strstr(h,n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CUR_TP
value|(&(cur_term->type))
end_define

begin_define
define|#
directive|define
name|MAX_STRINGS
value|NUM_STRINGS(CUR_TP)
end_define

begin_define
define|#
directive|define
name|STR_NAME
parameter_list|(
name|n
parameter_list|)
value|ExtStrname(CUR_TP,n,strnames)
end_define

begin_define
define|#
directive|define
name|UChar
parameter_list|(
name|c
parameter_list|)
value|((unsigned char)(c))
end_define

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|log_fp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|debug_fp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|debug_level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|temp
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tty_basename
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tty_shortname
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SYNC_FAILED
value|0
end_define

begin_define
define|#
directive|define
name|SYNC_TESTED
value|1
end_define

begin_define
define|#
directive|define
name|SYNC_NOT_TESTED
value|2
end_define

begin_define
define|#
directive|define
name|SYNC_NEEDED
value|3
end_define

begin_decl_stmt
specifier|extern
name|int
name|tty_can_sync
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|total_pads_sent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count pad characters sent */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|total_caps_sent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count caps sent */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|total_printing_characters
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count printing characters sent */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|no_alarm_event
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if the alarm has not gone off yet */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|usec_run_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of last test in microseconds */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|raw_characters_sent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Total output characters */
end_comment

begin_comment
comment|/* Stopwatch event timers */
end_comment

begin_define
define|#
directive|define
name|TIME_TEST
value|0
end_define

begin_define
define|#
directive|define
name|TIME_SYNC
value|1
end_define

begin_define
define|#
directive|define
name|TIME_FLUSH
value|2
end_define

begin_define
define|#
directive|define
name|MAX_TIMERS
value|3
end_define

begin_comment
comment|/* definitions for pad.c */
end_comment

begin_define
define|#
directive|define
name|EXIT_CONDITION
value|(no_alarm_event&& (tt_delay_used< tt_delay_max))
end_define

begin_define
define|#
directive|define
name|SLOW_TERMINAL_EXIT
value|if (!test_complete&& !EXIT_CONDITION) { break; }
end_define

begin_define
define|#
directive|define
name|CAP_NOT_FOUND
value|if (auto_pad_mode) return
end_define

begin_decl_stmt
specifier|extern
name|char
name|letters
index|[
literal|26
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NEXT_LETTER
value|letter = letters[letter_number =\ 	letters[letter_number + 1] ? letter_number + 1 : 0]
end_define

begin_decl_stmt
specifier|extern
name|int
name|test_complete
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* counts number of tests completed */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|letter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|letter_number
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|augment
decl_stmt|,
name|repeats
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|char_sent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|pad_repeat_test
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* commands that force repeat */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|replace_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|char_count
decl_stmt|,
name|line_count
decl_stmt|,
name|expand_chars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|can_go_home
decl_stmt|,
name|can_clear_screen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|translate_mode
decl_stmt|,
name|scan_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|auto_pad_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE for auto time tests */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|char_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hex_out
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Display output in hex */
end_comment

begin_comment
comment|/* Parity bit macros */
end_comment

begin_define
define|#
directive|define
name|STRIP_PARITY
value|0x7f
end_define

begin_define
define|#
directive|define
name|ALLOW_PARITY
value|0xff
end_define

begin_comment
comment|/* select_delay_type:	0 -> reset all delays 			1 -> force long delays 			2 -> do not change the delays */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|select_delay_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* select_xon_xoff:	0 -> reset xon/xoff 			1 -> set xon/xoff 			2 -> do not change xon/xoff */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|select_xon_xoff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tty_frame_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|tty_baud_rate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|tty_cps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of characters per second */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|not_a_tty
decl_stmt|,
name|nodelay_read
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|send_reset_init
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* definitions for stty_query() and initial_stty_query() */
end_comment

begin_define
define|#
directive|define
name|TTY_CHAR_MODE
value|0
end_define

begin_define
define|#
directive|define
name|TTY_NOECHO
value|1
end_define

begin_define
define|#
directive|define
name|TTY_OUT_TRANS
value|2
end_define

begin_define
define|#
directive|define
name|TTY_8_BIT
value|3
end_define

begin_define
define|#
directive|define
name|TTY_XON_XOFF
value|4
end_define

begin_comment
comment|/* scan code definitions */
end_comment

begin_define
define|#
directive|define
name|MAX_SCAN
value|256
end_define

begin_comment
comment|/* translate mode default strings */
end_comment

begin_struct
struct|struct
name|default_string_list
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* terminfo name */
specifier|const
name|char
modifier|*
name|value
decl_stmt|;
comment|/* value of default string */
name|int
name|index
decl_stmt|;
comment|/* index into the strfname[] array */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TM_last
value|8
end_define

begin_decl_stmt
specifier|extern
name|struct
name|default_string_list
name|TM_string
index|[
name|TM_last
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* attribute structure definition */
end_comment

begin_struct
struct|struct
name|mode_list
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
name|begin_mode
decl_stmt|;
specifier|const
name|char
modifier|*
name|end_mode
decl_stmt|;
name|int
name|number
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|mode_list
name|alt_modes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|mode_map
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Test data base */
end_comment

begin_define
define|#
directive|define
name|FLAG_CAN_TEST
value|1
end_define

begin_define
define|#
directive|define
name|FLAG_TESTED
value|2
end_define

begin_define
define|#
directive|define
name|FLAG_LABEL
value|4
end_define

begin_define
define|#
directive|define
name|FLAG_FUNCTION_KEY
value|8
end_define

begin_comment
comment|/* caps under test data base */
end_comment

begin_define
define|#
directive|define
name|TT_MAX
value|8
end_define

begin_define
define|#
directive|define
name|MAX_CHANGES
value|(TT_MAX+2)
end_define

begin_decl_stmt
specifier|extern
name|int
name|tt_delay_max
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max number of milliseconds we can delay */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tt_delay_used
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of milliseconds consumed in delay */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|tt_cap
index|[
name|TT_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of string */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tt_affected
index|[
name|TT_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lines or columns effected (repetition 				   factor) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tt_count
index|[
name|TT_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of times sent */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tt_delay
index|[
name|TT_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of milliseconds delay */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ttp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of entries used */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|tx_cap
index|[
name|TT_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of string */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tx_affected
index|[
name|TT_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lines or columns effected (repetition 				   factor) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tx_count
index|[
name|TT_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of times sent */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tx_delay
index|[
name|TT_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of milliseconds delay */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tx_index
index|[
name|TT_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* String index */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|txp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of entries used */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tx_characters
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* printing characters sent by test */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|tx_cps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* characters per second */
end_comment

begin_comment
comment|/* 	Menu control for tack. */
end_comment

begin_struct
struct|struct
name|test_results
block|{
name|struct
name|test_results
modifier|*
name|next
decl_stmt|;
comment|/* point to next entry */
name|struct
name|test_list
modifier|*
name|test
decl_stmt|;
comment|/* Test which got these results */
name|int
name|reps
decl_stmt|;
comment|/* repeat count */
name|int
name|delay
decl_stmt|;
comment|/* delay times 10 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|test_list
block|{
name|int
name|flags
decl_stmt|;
comment|/* Test description flags */
name|int
name|lines_needed
decl_stmt|;
comment|/* Lines needed for test (0->no action) */
specifier|const
name|char
modifier|*
name|caps_done
decl_stmt|;
comment|/* Caps shown in Done message */
specifier|const
name|char
modifier|*
name|caps_tested
decl_stmt|;
comment|/* Other caps also being tested */
specifier|const
name|char
modifier|*
name|menu_entry
decl_stmt|;
comment|/* Menu entry text (optional) */
comment|/* Function that does testing */
name|void
function_decl|(
modifier|*
name|test_procedure
function_decl|)
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
name|struct
name|test_menu
modifier|*
name|sub_menu
decl_stmt|;
comment|/* Nested sub-menu */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|test_menu
block|{
name|int
name|flags
decl_stmt|;
comment|/* Menu feature flag */
name|int
name|default_action
decl_stmt|;
comment|/* Default command if<cr><lf> entered */
specifier|const
name|char
modifier|*
name|menu_text
decl_stmt|;
comment|/* Describe this test_menu */
specifier|const
name|char
modifier|*
name|menu_title
decl_stmt|;
comment|/* Title for the menu */
specifier|const
name|char
modifier|*
name|ident
decl_stmt|;
comment|/* short menu name */
specifier|const
name|char
modifier|*
name|standard_tests
decl_stmt|;
comment|/* Standard test text */
comment|/* print current settings (optional) */
name|void
function_decl|(
modifier|*
name|menu_function
function_decl|)
parameter_list|(
name|struct
name|test_menu
modifier|*
parameter_list|)
function_decl|;
name|struct
name|test_list
modifier|*
name|tests
decl_stmt|;
comment|/* Pointer to the menu/function pairs */
name|struct
name|test_list
modifier|*
name|resume_tests
decl_stmt|;
comment|/* Standard test resume point */
name|int
name|resume_state
decl_stmt|;
comment|/* resume state of test group */
name|int
name|resume_char
decl_stmt|;
comment|/* resume ch of test group */
block|}
struct|;
end_struct

begin_comment
comment|/* menu flags */
end_comment

begin_define
define|#
directive|define
name|MENU_100c
value|0x00001a00
end_define

begin_comment
comment|/* Augment 100% of columns */
end_comment

begin_define
define|#
directive|define
name|MENU_90c
value|0x00001900
end_define

begin_comment
comment|/* Augment 90% of columns */
end_comment

begin_define
define|#
directive|define
name|MENU_80c
value|0x00001800
end_define

begin_comment
comment|/* Augment 80% of columns */
end_comment

begin_define
define|#
directive|define
name|MENU_70c
value|0x00001700
end_define

begin_comment
comment|/* Augment 70% of columns */
end_comment

begin_define
define|#
directive|define
name|MENU_60c
value|0x00001600
end_define

begin_comment
comment|/* Augment 60% of columns */
end_comment

begin_define
define|#
directive|define
name|MENU_50c
value|0x00001500
end_define

begin_comment
comment|/* Augment 50% of columns */
end_comment

begin_define
define|#
directive|define
name|MENU_40c
value|0x00001400
end_define

begin_comment
comment|/* Augment 40% of columns */
end_comment

begin_define
define|#
directive|define
name|MENU_30c
value|0x00001300
end_define

begin_comment
comment|/* Augment 30% of columns */
end_comment

begin_define
define|#
directive|define
name|MENU_20c
value|0x00001200
end_define

begin_comment
comment|/* Augment 20% of columns */
end_comment

begin_define
define|#
directive|define
name|MENU_10c
value|0x00001100
end_define

begin_comment
comment|/* Augment 10% of columns */
end_comment

begin_define
define|#
directive|define
name|MENU_LM1
value|0x00002e00
end_define

begin_comment
comment|/* Augment lines - 1 */
end_comment

begin_define
define|#
directive|define
name|MENU_100l
value|0x00002a00
end_define

begin_comment
comment|/* Augment 100% of lines */
end_comment

begin_define
define|#
directive|define
name|MENU_90l
value|0x00002900
end_define

begin_comment
comment|/* Augment 90% of lines */
end_comment

begin_define
define|#
directive|define
name|MENU_50l
value|0x00002500
end_define

begin_comment
comment|/* Augment 50% of lines */
end_comment

begin_define
define|#
directive|define
name|MENU_lines
value|0x00002000
end_define

begin_comment
comment|/* Augment of lines */
end_comment

begin_define
define|#
directive|define
name|MENU_columns
value|0x00001000
end_define

begin_comment
comment|/* Augment of columns */
end_comment

begin_define
define|#
directive|define
name|MENU_LC_MASK
value|0x00003000
end_define

begin_comment
comment|/* Augment mask for lines and columns */
end_comment

begin_define
define|#
directive|define
name|MENU_1L
value|0x00002f00
end_define

begin_comment
comment|/* Augment == one */
end_comment

begin_define
define|#
directive|define
name|MENU_1C
value|0x00001f00
end_define

begin_comment
comment|/* Augment == one */
end_comment

begin_define
define|#
directive|define
name|MENU_ONE
value|0x00000f00
end_define

begin_comment
comment|/* Augment == one */
end_comment

begin_define
define|#
directive|define
name|MENU_ONE_MASK
value|0x00000f00
end_define

begin_comment
comment|/* Augment == one mask */
end_comment

begin_define
define|#
directive|define
name|MENU_REP_MASK
value|0x00003f00
end_define

begin_comment
comment|/* Augment mask */
end_comment

begin_define
define|#
directive|define
name|MENU_CLEAR
value|0x00010000
end_define

begin_comment
comment|/* clear screen */
end_comment

begin_define
define|#
directive|define
name|MENU_INIT
value|0x00020000
end_define

begin_comment
comment|/* Initialization function */
end_comment

begin_define
define|#
directive|define
name|MENU_NEXT
value|0x00040000
end_define

begin_comment
comment|/* Next test in sequence */
end_comment

begin_define
define|#
directive|define
name|MENU_LAST
value|0x00080000
end_define

begin_comment
comment|/* End of menu list */
end_comment

begin_define
define|#
directive|define
name|MENU_STOP
value|0x00100000
end_define

begin_comment
comment|/* Stop testing next-in-sequence */
end_comment

begin_define
define|#
directive|define
name|MENU_COMPLETE
value|0x00200000
end_define

begin_comment
comment|/* Test complete after this */
end_comment

begin_define
define|#
directive|define
name|MENU_MENU
value|0x00400000
end_define

begin_comment
comment|/* Pass the menu name not test name */
end_comment

begin_define
define|#
directive|define
name|REQUEST_PROMPT
value|256
end_define

begin_comment
comment|/* tack.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|test_menu
name|edit_menu
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|show_usage
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_version
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* output.c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|expand
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|expand_command
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|expand_to
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|hex_expand_to
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|print_expand
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getchp
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getnext
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tc_putch
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tc_putp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|wait_here
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|go_home
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|home_down
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|maybe_wait
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ptext
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ptextln
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_clear
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_columns
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_cr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_crlf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_dec
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_ind
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_lf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_newlines
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_str
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_this
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|putchp
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|putln
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|read_string
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|three_digit
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tt_putp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tt_putparm
parameter_list|(
name|NCURSES_CONST
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tt_tputs
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|put_that
parameter_list|(
name|n
parameter_list|)
value|put_this((int) (n))
end_define

begin_comment
comment|/* control.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|test_list
name|color_test_list
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|liberated
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|txt_longer_augment
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|txt_longer_test_time
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|txt_shorter_augment
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|txt_shorter_test_time
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|msec_cost
parameter_list|(
specifier|const
name|char
modifier|*
specifier|const
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|skip_pad_test
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sliding_scale
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|still_testing
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|event_time
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|control_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_test_stats
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|event_start
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|longer_augment
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|longer_test_time
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pad_test_shutdown
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pad_test_startup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|page_loop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_augment_txt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|shorter_augment
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|shorter_test_time
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* charset.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|test_list
name|acs_test_list
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|set_attr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|eat_cookie
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_mode
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* crum.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|test_list
name|crum_test_list
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ansi.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|tools_status
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tools_charset
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tools_sgr
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* edit.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|test_menu
name|change_pad_menu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|test_list
name|edit_test_list
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_string_cap_byname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cap_match
parameter_list|(
specifier|const
name|char
modifier|*
name|names
parameter_list|,
specifier|const
name|char
modifier|*
name|cap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|get_string_cap_byvalue
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|user_modified
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|can_test
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cap_index
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|edit_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|save_info
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_report
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fun.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|test_list
name|funkey_test_list
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|test_list
name|printer_test_list
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|enter_key
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tty_meta_prep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tools_report
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* init.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|reset_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|display_basic
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_name
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|charset_can_test
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|curses_setup
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bye_kids
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* scan.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|scan_up
decl_stmt|,
modifier|*
modifier|*
name|scan_down
decl_stmt|,
modifier|*
modifier|*
name|scan_name
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|scan_key
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|unsigned
name|scan_max
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of longest scan code */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
modifier|*
name|scan_tested
decl_stmt|,
modifier|*
name|scan_length
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|scan_init
parameter_list|(
name|char
modifier|*
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sysdep.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|initial_stty_query
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|stty_query
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ignoresig
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|read_key
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_alarm_clock
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|spin_flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tty_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tty_raw
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tty_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tty_set
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* menu.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|prompt_string
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* menu prompt storage */
end_comment

begin_function_decl
specifier|extern
name|int
name|subtest_menu
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|test_list
modifier|*
name|augment_test
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|generic_done_message
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|menu_can_scan
parameter_list|(
specifier|const
name|struct
name|test_menu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|menu_clear_screen
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|menu_display
parameter_list|(
name|struct
name|test_menu
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|menu_prompt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|menu_reset_init
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pad_done_message
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* modes.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|test_list
name|mode_test_list
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pad.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|test_list
name|pad_test_list
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sync.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|test_menu
name|sync_menu
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|tty_sync_error
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flush_input
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sync_handshake
parameter_list|(
name|struct
name|test_list
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sync_test
parameter_list|(
name|struct
name|test_menu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|verify_time
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCURSES_TACK_H_incl */
end_comment

end_unit

