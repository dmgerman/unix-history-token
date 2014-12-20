begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ntp_scanner.h  *  * The header file for a simple lexical analyzer.   *  * Written By:	Sachin Kamboj  *		University of Delaware  *		Newark, DE 19711  * Copyright (c) 2006  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_SCANNER_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_SCANNER_H
end_define

begin_include
include|#
directive|include
file|"ntp_config.h"
end_include

begin_comment
comment|/*  * ntp.conf syntax is slightly irregular in that some tokens such as  * hostnames do not require quoting even if they might otherwise be  * recognized as T_ terminal tokens.  This hand-crafted lexical scanner  * uses a "followed by" value associated with each keyword to indicate  * normal scanning of the next token, forced scanning of the next token  * alone as a T_String, or forced scanning of all tokens to the end of  * the command as T_String.  * In the past the identifiers for this functionality ended in _ARG:  *  * NO_ARG	->	FOLLBY_TOKEN  * SINGLE_ARG	->	FOLLBY_STRING  * MULTIPLE_ARG	->	FOLLBY_STRINGS_TO_EOC  *  * Note that some tokens use FOLLBY_TOKEN even though they sometimes  * are followed by strings.  FOLLBY_STRING is used only when needed to  * avoid the keyword scanner matching a token where a string is needed.  *  * FOLLBY_NON_ACCEPT is an overloading of this field to distinguish  * non-accepting states (where the state number does not match a T_  * value).  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FOLLBY_TOKEN
init|=
literal|0
block|,
name|FOLLBY_STRING
block|,
name|FOLLBY_STRINGS_TO_EOC
block|,
name|FOLLBY_NON_ACCEPTING
block|}
name|follby
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAXLINE
value|1024
end_define

begin_comment
comment|/* maximum length of line */
end_comment

begin_define
define|#
directive|define
name|MAXINCLUDELEVEL
value|5
end_define

begin_comment
comment|/* maximum include file levels */
end_comment

begin_comment
comment|/* STRUCTURES  * ----------  */
end_comment

begin_comment
comment|/*   * Define a structure to hold the FSA for the keywords.  * The structure is actually a trie.  *  * To save space, a single u_int32 encodes four fields, and a fifth  * (the token completed for terminal states) is implied by the index of  * the rule within the scan state array, taking advantage of the fact  * there are more scan states than the highest T_ token number.  *  * The lowest 8 bits hold the character the state matches on.  * Bits 8 and 9 hold the followedby value (0 - 3).  For non-accepting  *   states (which do not match a completed token) the followedby  *   value 3 (FOLLBY_NONACCEPTING) denotes that fact.  For accepting  *   states, values 0 - 2 control whether the scanner forces the  *   following token(s) to strings.  * Bits 10 through 20 hold the next state to check not matching  * this state's character.  * Bits 21 through 31 hold the next state to check matching the char.  */
end_comment

begin_define
define|#
directive|define
name|S_ST
parameter_list|(
name|ch
parameter_list|,
name|fb
parameter_list|,
name|match_n
parameter_list|,
name|other_n
parameter_list|)
value|(			\ 	(u_char)((ch)& 0xff) |					\ 	((u_int32)(fb)<< 8) |					\ 	((u_int32)(match_n)<< 10) |				\ 	((u_int32)(other_n)<< 21)				\ )
end_define

begin_define
define|#
directive|define
name|SS_CH
parameter_list|(
name|ss
parameter_list|)
value|((char)(u_char)((ss)& 0xff))
end_define

begin_define
define|#
directive|define
name|SS_FB
parameter_list|(
name|ss
parameter_list|)
value|(((u_int)(ss)>>  8)& 0x3)
end_define

begin_define
define|#
directive|define
name|SS_MATCH_N
parameter_list|(
name|ss
parameter_list|)
value|(((u_int)(ss)>> 10)& 0x7ff)
end_define

begin_define
define|#
directive|define
name|SS_OTHER_N
parameter_list|(
name|ss
parameter_list|)
value|(((u_int)(ss)>> 21)& 0x7ff)
end_define

begin_typedef
typedef|typedef
name|u_int32
name|scan_state
typedef|;
end_typedef

begin_comment
comment|/* Structure to hold a filename, file pointer and positional info */
end_comment

begin_struct
struct|struct
name|FILE_INFO
block|{
specifier|const
name|char
modifier|*
name|fname
decl_stmt|;
comment|/* Path to the file */
name|FILE
modifier|*
name|fd
decl_stmt|;
comment|/* File Descriptor */
name|int
name|line_no
decl_stmt|;
comment|/* Line Number */
name|int
name|col_no
decl_stmt|;
comment|/* Column Number */
name|int
name|prev_line_col_no
decl_stmt|;
comment|/* Col No on the  						   previous line when a 						   '\n' was seen */
name|int
name|prev_token_line_no
decl_stmt|;
comment|/* Line at start of 						   token */
name|int
name|prev_token_col_no
decl_stmt|;
comment|/* Col No at start of 						   token */
name|int
name|err_line_no
decl_stmt|;
name|int
name|err_col_no
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* SCANNER GLOBAL VARIABLES   * ------------------------  */
end_comment

begin_decl_stmt
specifier|extern
name|config_tree
name|cfgt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parser output stored here */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|curr_include_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The current include level */
end_comment

begin_comment
comment|/* VARIOUS EXTERNAL DECLARATIONS  * -----------------------------  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|old_config_style
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|input_from_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|FILE_INFO
modifier|*
name|fp
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* VARIOUS SUBROUTINE DECLARATIONS  * -------------------------------  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|keyword
parameter_list|(
name|int
name|token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|quote_if_needed
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yylex
parameter_list|(
name|struct
name|FILE_INFO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|FILE_INFO
modifier|*
name|F_OPEN
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|FGETC
parameter_list|(
name|struct
name|FILE_INFO
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|UNGETC
parameter_list|(
name|int
name|ch
parameter_list|,
name|struct
name|FILE_INFO
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|FCLOSE
parameter_list|(
name|struct
name|FILE_INFO
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_SCANNER_H */
end_comment

end_unit

