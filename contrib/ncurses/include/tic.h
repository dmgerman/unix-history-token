begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2005,2006 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Thomas E. Dickey 1996 on                                        *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * $Id: tic.h,v 1.55 2006/08/19 14:17:49 tom Exp $  *	tic.h - Global variables and structures for the terminfo  *			compiler.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TIC_H
end_ifndef

begin_define
define|#
directive|define
name|__TIC_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<curses.h>
comment|/* for the _tracef() prototype, ERR/OK, bool defs */
comment|/* ** The format of compiled terminfo files is as follows: ** **		Header (12 bytes), containing information given below **		Names Section, containing the names of the terminal **		Boolean Section, containing the values of all of the **				boolean capabilities **				A null byte may be inserted here to make **				sure that the Number Section begins on an **				even word boundary. **		Number Section, containing the values of all of the numeric **				capabilities, each as a short integer **		String Section, containing short integer offsets into the **				String Table, one per string capability **		String Table, containing the actual characters of the string **				capabilities. ** **	NOTE that all short integers in the file are stored using VAX/PDP-style **	byte-order, i.e., least-significant byte first. ** **	There is no structure definition here because it would only confuse **	matters.  Terminfo format is a raw byte layout, not a structure **	dump.  If you happen to be on a little-endian machine with 16-bit **	shorts that requires no padding between short members in a struct, **	then there is a natural C structure that captures the header, but **	not very helpfully. */
define|#
directive|define
name|MAGIC
value|0432
comment|/* first two bytes of a compiled entry */
undef|#
directive|undef
name|BYTE
define|#
directive|define
name|BYTE
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|(unsigned char)((p)[n])
define|#
directive|define
name|IS_NEG1
parameter_list|(
name|p
parameter_list|)
value|((BYTE(p,0) == 0377)&& (BYTE(p,1) == 0377))
define|#
directive|define
name|IS_NEG2
parameter_list|(
name|p
parameter_list|)
value|((BYTE(p,0) == 0376)&& (BYTE(p,1) == 0377))
define|#
directive|define
name|LOW_MSB
parameter_list|(
name|p
parameter_list|)
value|(BYTE(p,0) + 256*BYTE(p,1))
define|#
directive|define
name|IS_TIC_MAGIC
parameter_list|(
name|p
parameter_list|)
value|(LOW_MSB(p) == MAGIC)
comment|/*  * The "maximum" here is misleading; XSI guarantees minimum values, which a  * given implementation may exceed.  */
define|#
directive|define
name|MAX_NAME_SIZE
value|512
comment|/* maximum legal name field size (XSI:127) */
define|#
directive|define
name|MAX_ENTRY_SIZE
value|4096
comment|/* maximum legal entry size */
comment|/*  * The maximum size of individual name or alias is guaranteed in XSI to be at  * least 14, since that corresponds to the older filename lengths.  Newer  * systems allow longer aliases, though not many terminal descriptions are  * written to use them.  The MAX_ALIAS symbol is used for warnings.  */
if|#
directive|if
name|HAVE_LONG_FILE_NAMES
define|#
directive|define
name|MAX_ALIAS
value|32
comment|/* smaller than POSIX minimum for PATH_MAX */
else|#
directive|else
define|#
directive|define
name|MAX_ALIAS
value|14
comment|/* SVr3 filename length */
endif|#
directive|endif
comment|/* location of user's personal info directory */
define|#
directive|define
name|PRIVATE_INFO
value|"%s/.terminfo"
comment|/* plug getenv("HOME") into %s */
comment|/*  * Some traces are designed to be used via tic's verbose option (and similar in  * infocmp and toe) rather than the 'trace()' function.  So we use the bits  * above the normal trace() parameter as a debug-level.  */
define|#
directive|define
name|MAX_DEBUG_LEVEL
value|15
define|#
directive|define
name|DEBUG_LEVEL
parameter_list|(
name|n
parameter_list|)
value|((n)<< TRACE_SHIFT)
define|#
directive|define
name|set_trace_level
parameter_list|(
name|n
parameter_list|)
define|\
value|_nc_tracing&= DEBUG_LEVEL(MAX_DEBUG_LEVEL), \ 	_nc_tracing |= DEBUG_LEVEL(n)
ifdef|#
directive|ifdef
name|TRACE
define|#
directive|define
name|DEBUG
parameter_list|(
name|n
parameter_list|,
name|a
parameter_list|)
value|if (_nc_tracing>= DEBUG_LEVEL(n)) _tracef a
else|#
directive|else
define|#
directive|define
name|DEBUG
parameter_list|(
name|n
parameter_list|,
name|a
parameter_list|)
comment|/*nothing*/
endif|#
directive|endif
extern|extern NCURSES_EXPORT_VAR(unsigned
block|)
name|_nc_tracing
expr_stmt|;
end_extern

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_macro
unit|)
name|_nc_tracef
argument_list|(
argument|char *
argument_list|,
argument|...
argument_list|)
end_macro

begin_expr_stmt
name|GCC_PRINTFLIKE
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(const char *
end_extern

begin_expr_stmt
unit|)
name|_nc_visbuf
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(const char *
end_extern

begin_expr_stmt
unit|)
name|_nc_visbuf2
argument_list|(
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * These are the types of tokens returned by the scanner.  The first  * three are also used in the hash table of capability names.  The scanner  * returns one of these values after loading the specifics into the global  * structure curr_token.  */
end_comment

begin_define
define|#
directive|define
name|BOOLEAN
value|0
end_define

begin_comment
comment|/* Boolean capability */
end_comment

begin_define
define|#
directive|define
name|NUMBER
value|1
end_define

begin_comment
comment|/* Numeric capability */
end_comment

begin_define
define|#
directive|define
name|STRING
value|2
end_define

begin_comment
comment|/* String-valued capability */
end_comment

begin_define
define|#
directive|define
name|CANCEL
value|3
end_define

begin_comment
comment|/* Capability to be cancelled in following tc's */
end_comment

begin_define
define|#
directive|define
name|NAMES
value|4
end_define

begin_comment
comment|/* The names for a terminal type */
end_comment

begin_define
define|#
directive|define
name|UNDEF
value|5
end_define

begin_comment
comment|/* Undefined */
end_comment

begin_define
define|#
directive|define
name|NO_PUSHBACK
value|-1
end_define

begin_comment
comment|/* used in pushtype to indicate no pushback */
end_comment

begin_comment
comment|/* 	 *	The global structure in which the specific parts of a 	 *	scanned token are returned. 	 * 	 */
end_comment

begin_struct
struct|struct
name|token
block|{
name|char
modifier|*
name|tk_name
decl_stmt|;
comment|/* name of capability */
name|int
name|tk_valnumber
decl_stmt|;
comment|/* value of capability (if a number) */
name|char
modifier|*
name|tk_valstring
decl_stmt|;
comment|/* value of capability (if a string) */
block|}
struct|;
end_struct

begin_extern
extern|extern NCURSES_EXPORT_VAR(struct token
end_extern

begin_expr_stmt
unit|)
name|_nc_curr_token
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 * List of keynames with their corresponding code. 	 */
end_comment

begin_struct
struct|struct
name|kn
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|code
decl_stmt|;
block|}
struct|;
end_struct

begin_extern
extern|extern NCURSES_EXPORT_VAR(const struct kn
end_extern

begin_expr_stmt
unit|)
name|_nc_key_names
index|[]
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 * Offsets to string capabilities, with the corresponding functionkey 	 * codes. 	 */
end_comment

begin_struct
struct|struct
name|tinfo_fkeys
block|{
name|unsigned
name|offset
decl_stmt|;
name|chtype
name|code
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|BROKEN_LINKER
end_if

begin_define
define|#
directive|define
name|_nc_tinfo_fkeys
value|_nc_tinfo_fkeysf()
end_define

begin_extern
extern|extern NCURSES_EXPORT(struct tinfo_fkeys *
end_extern

begin_expr_stmt
unit|)
name|_nc_tinfo_fkeysf
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_extern
extern|extern NCURSES_EXPORT_VAR(struct tinfo_fkeys
end_extern

begin_expr_stmt
unit|)
name|_nc_tinfo_fkeys
index|[]
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	 * The file comp_captab.c contains an array of these structures, one 	 * per possible capability.  These are indexed by a hash table array of 	 * pointers to the same structures for use by the parser. 	 */
end_comment

begin_struct
struct|struct
name|name_table_entry
block|{
specifier|const
name|char
modifier|*
name|nte_name
decl_stmt|;
comment|/* name to hash on */
name|int
name|nte_type
decl_stmt|;
comment|/* BOOLEAN, NUMBER or STRING */
name|short
name|nte_index
decl_stmt|;
comment|/* index of associated variable in its array */
name|short
name|nte_link
decl_stmt|;
comment|/* index in table of next hash, or -1 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|alias
block|{
specifier|const
name|char
modifier|*
name|from
decl_stmt|;
specifier|const
name|char
modifier|*
name|to
decl_stmt|;
specifier|const
name|char
modifier|*
name|source
decl_stmt|;
block|}
struct|;
end_struct

begin_extern
extern|extern NCURSES_EXPORT_VAR(const struct name_table_entry * const
end_extern

begin_expr_stmt
unit|)
name|_nc_info_hash_table
index|[]
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(const struct name_table_entry * const
end_extern

begin_expr_stmt
unit|)
name|_nc_cap_hash_table
index|[]
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(const struct alias
end_extern

begin_expr_stmt
unit|)
name|_nc_capalias_table
index|[]
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(const struct alias
end_extern

begin_expr_stmt
unit|)
name|_nc_infoalias_table
index|[]
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(const struct name_table_entry *
end_extern

begin_expr_stmt
unit|)
name|_nc_get_table
argument_list|(
name|bool
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(const struct name_table_entry * const *
end_extern

begin_expr_stmt
unit|)
name|_nc_get_hash_table
argument_list|(
name|bool
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|NOTFOUND
value|((struct name_table_entry *) 0)
end_define

begin_comment
comment|/* out-of-band values for representing absent capabilities */
end_comment

begin_define
define|#
directive|define
name|ABSENT_BOOLEAN
value|((signed char)-1)
end_define

begin_comment
comment|/* 255 */
end_comment

begin_define
define|#
directive|define
name|ABSENT_NUMERIC
value|(-1)
end_define

begin_define
define|#
directive|define
name|ABSENT_STRING
value|(char *)0
end_define

begin_comment
comment|/* out-of-band values for representing cancels */
end_comment

begin_define
define|#
directive|define
name|CANCELLED_BOOLEAN
value|((signed char)-2)
end_define

begin_comment
comment|/* 254 */
end_comment

begin_define
define|#
directive|define
name|CANCELLED_NUMERIC
value|(-2)
end_define

begin_define
define|#
directive|define
name|CANCELLED_STRING
value|(char *)(-1)
end_define

begin_define
define|#
directive|define
name|VALID_BOOLEAN
parameter_list|(
name|s
parameter_list|)
value|((unsigned char)(s)<= 1)
end_define

begin_comment
comment|/* reject "-1" */
end_comment

begin_define
define|#
directive|define
name|VALID_NUMERIC
parameter_list|(
name|s
parameter_list|)
value|((s)>= 0)
end_define

begin_define
define|#
directive|define
name|VALID_STRING
parameter_list|(
name|s
parameter_list|)
value|((s) != CANCELLED_STRING&& (s) != ABSENT_STRING)
end_define

begin_comment
comment|/* termcap entries longer than this may break old binaries */
end_comment

begin_define
define|#
directive|define
name|MAX_TERMCAP_LENGTH
value|1023
end_define

begin_comment
comment|/* this is a documented limitation of terminfo */
end_comment

begin_define
define|#
directive|define
name|MAX_TERMINFO_LENGTH
value|4096
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TERMINFO
end_ifndef

begin_define
define|#
directive|define
name|TERMINFO
value|"/usr/share/terminfo"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* access.c */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(unsigned
end_extern

begin_expr_stmt
unit|)
name|_nc_pathlast
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_is_abs_path
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_is_dir_path
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_is_file_path
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(char *
end_extern

begin_expr_stmt
unit|)
name|_nc_basename
argument_list|(
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(char *
end_extern

begin_expr_stmt
unit|)
name|_nc_rootname
argument_list|(
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* comp_hash.c: name lookup */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(struct name_table_entry const *
end_extern

begin_expr_stmt
unit|)
name|_nc_find_entry
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
expr|struct
name|name_table_entry
operator|*
specifier|const
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(struct name_table_entry const *
end_extern

begin_expr_stmt
unit|)
name|_nc_find_type_entry
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
expr|struct
name|name_table_entry
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* comp_scan.c: lexical analysis */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|_nc_get_token
argument_list|(
name|bool
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_panic_mode
argument_list|(
name|char
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_push_token
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_reset_input
argument_list|(
name|FILE
operator|*
argument_list|,
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(int
end_extern

begin_expr_stmt
unit|)
name|_nc_curr_col
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(int
end_extern

begin_expr_stmt
unit|)
name|_nc_curr_line
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(int
end_extern

begin_expr_stmt
unit|)
name|_nc_syntax
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(long
end_extern

begin_expr_stmt
unit|)
name|_nc_comment_end
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(long
end_extern

begin_expr_stmt
unit|)
name|_nc_comment_start
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(long
end_extern

begin_expr_stmt
unit|)
name|_nc_curr_file_pos
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(long
end_extern

begin_expr_stmt
unit|)
name|_nc_start_line
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|SYN_TERMINFO
value|0
end_define

begin_define
define|#
directive|define
name|SYN_TERMCAP
value|1
end_define

begin_comment
comment|/* comp_error.c: warning& abort messages */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(const char *
end_extern

begin_expr_stmt
unit|)
name|_nc_get_source
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_macro
unit|)
name|_nc_err_abort
argument_list|(
argument|const char *const
argument_list|,
argument|...
argument_list|)
end_macro

begin_macro
name|GCC_PRINTFLIKE
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
end_macro

begin_expr_stmt
name|GCC_NORETURN
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_get_type
argument_list|(
name|char
operator|*
name|name
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_set_source
argument_list|(
specifier|const
name|char
operator|*
specifier|const
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_set_type
argument_list|(
specifier|const
name|char
operator|*
specifier|const
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_macro
unit|)
name|_nc_syserr_abort
argument_list|(
argument|const char *const
argument_list|,
argument|...
argument_list|)
end_macro

begin_macro
name|GCC_PRINTFLIKE
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
end_macro

begin_expr_stmt
name|GCC_NORETURN
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_macro
unit|)
name|_nc_warning
argument_list|(
argument|const char *const
argument_list|,
argument|...
argument_list|)
end_macro

begin_expr_stmt
name|GCC_PRINTFLIKE
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_suppress_warnings
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* comp_expand.c: expand string into readable form */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(char *
end_extern

begin_expr_stmt
unit|)
name|_nc_tic_expand
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|bool
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* comp_scan.c: decode string from readable form */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|_nc_trans_string
argument_list|(
name|char
operator|*
argument_list|,
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* captoinfo.c: capability conversion */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(char *
end_extern

begin_expr_stmt
unit|)
name|_nc_captoinfo
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|int
specifier|const
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(char *
end_extern

begin_expr_stmt
unit|)
name|_nc_infotocap
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|int
specifier|const
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* home_terminfo.c */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(char *
end_extern

begin_expr_stmt
unit|)
name|_nc_home_terminfo
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* lib_tparm.c */
end_comment

begin_define
define|#
directive|define
name|NUM_PARM
value|9
end_define

begin_extern
extern|extern NCURSES_EXPORT_VAR(int
end_extern

begin_expr_stmt
unit|)
name|_nc_tparm_err
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|_nc_tparm_analyze
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|char
operator|*
operator|*
argument_list|,
name|int
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* lib_tputs.c */
end_comment

begin_extern
extern|extern NCURSES_EXPORT_VAR(int
end_extern

begin_expr_stmt
unit|)
name|_nc_nulls_sent
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Add one for every null sent */
end_comment

begin_comment
comment|/* comp_main.c: compiler main */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|_nc_progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* db_iterator.c */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dbdTIC
init|=
literal|0
block|,
if|#
directive|if
name|USE_DATABASE
name|dbdEnvOnce
block|,
name|dbdHome
block|,
name|dbdEnvList
block|,
name|dbdCfgList
block|,
name|dbdCfgOnce
block|,
endif|#
directive|endif
if|#
directive|if
name|USE_TERMCAP
name|dbdEnvOnce2
block|,
name|dbdEnvList2
block|,
name|dbdCfgList2
block|,
endif|#
directive|endif
name|dbdLAST
block|}
name|DBDIRS
typedef|;
end_typedef

begin_extern
extern|extern NCURSES_EXPORT(const char *
end_extern

begin_expr_stmt
unit|)
name|_nc_next_db
argument_list|(
name|DBDIRS
operator|*
argument_list|,
name|int
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(const char *
end_extern

begin_expr_stmt
unit|)
name|_nc_tic_dir
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_first_db
argument_list|(
name|DBDIRS
operator|*
argument_list|,
name|int
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_last_db
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* write_entry.c */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|_nc_tic_written
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TIC_H */
end_comment

end_unit

