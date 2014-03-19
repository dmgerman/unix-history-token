begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ELWrapper.h ---------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|// EditLine editor function return codes.
end_comment

begin_comment
comment|// For user-defined function interface
end_comment

begin_define
define|#
directive|define
name|CC_NORM
value|0
end_define

begin_define
define|#
directive|define
name|CC_NEWLINE
value|1
end_define

begin_define
define|#
directive|define
name|CC_EOF
value|2
end_define

begin_define
define|#
directive|define
name|CC_ARGHACK
value|3
end_define

begin_define
define|#
directive|define
name|CC_REFRESH
value|4
end_define

begin_define
define|#
directive|define
name|CC_CURSOR
value|5
end_define

begin_define
define|#
directive|define
name|CC_ERROR
value|6
end_define

begin_define
define|#
directive|define
name|CC_FATAL
value|7
end_define

begin_define
define|#
directive|define
name|CC_REDISPLAY
value|8
end_define

begin_define
define|#
directive|define
name|CC_REFRESH_BEEP
value|9
end_define

begin_comment
comment|// el_set/el_get parameters
end_comment

begin_define
define|#
directive|define
name|EL_PROMPT
value|0
end_define

begin_comment
comment|// , el_pfunc_t
end_comment

begin_define
define|#
directive|define
name|EL_TERMINAL
value|1
end_define

begin_comment
comment|// , const char *
end_comment

begin_define
define|#
directive|define
name|EL_EDITOR
value|2
end_define

begin_comment
comment|// , const char *
end_comment

begin_define
define|#
directive|define
name|EL_SIGNAL
value|3
end_define

begin_comment
comment|// , int);
end_comment

begin_define
define|#
directive|define
name|EL_BIND
value|4
end_define

begin_comment
comment|// , const char *, ..., NULL
end_comment

begin_define
define|#
directive|define
name|EL_TELLTC
value|5
end_define

begin_comment
comment|// , const char *, ..., NULL
end_comment

begin_define
define|#
directive|define
name|EL_SETTC
value|6
end_define

begin_comment
comment|// , const char *, ..., NULL
end_comment

begin_define
define|#
directive|define
name|EL_ECHOTC
value|7
end_define

begin_comment
comment|// , const char *, ..., NULL
end_comment

begin_define
define|#
directive|define
name|EL_SETTY
value|8
end_define

begin_comment
comment|// , const char *, ..., NULL
end_comment

begin_define
define|#
directive|define
name|EL_ADDFN
value|9
end_define

begin_comment
comment|// , const char *, const char *, el_func_t
end_comment

begin_define
define|#
directive|define
name|EL_HIST
value|10
end_define

begin_comment
comment|// , hist_fun_t, const char *
end_comment

begin_define
define|#
directive|define
name|EL_EDITMODE
value|11
end_define

begin_comment
comment|// , int
end_comment

begin_define
define|#
directive|define
name|EL_RPROMPT
value|12
end_define

begin_comment
comment|// , el_pfunc_t
end_comment

begin_define
define|#
directive|define
name|EL_GETCFN
value|13
end_define

begin_comment
comment|// , el_rfunc_t
end_comment

begin_define
define|#
directive|define
name|EL_CLIENTDATA
value|14
end_define

begin_comment
comment|// , void *
end_comment

begin_define
define|#
directive|define
name|EL_UNBUFFERED
value|15
end_define

begin_comment
comment|// , int
end_comment

begin_define
define|#
directive|define
name|EL_PREP_TERM
value|16
end_define

begin_comment
comment|// , int
end_comment

begin_define
define|#
directive|define
name|EL_GETTC
value|17
end_define

begin_comment
comment|// , const char *, ..., NULL
end_comment

begin_define
define|#
directive|define
name|EL_GETFP
value|18
end_define

begin_comment
comment|// , int, FILE **
end_comment

begin_define
define|#
directive|define
name|EL_SETFP
value|19
end_define

begin_comment
comment|// , int, FILE *
end_comment

begin_define
define|#
directive|define
name|EL_REFRESH
value|20
end_define

begin_comment
comment|// , void
end_comment

begin_define
define|#
directive|define
name|EL_BUILTIN_GETCFN
value|(NULL)
end_define

begin_comment
comment|// history defines
end_comment

begin_define
define|#
directive|define
name|H_FUNC
value|0
end_define

begin_comment
comment|// , UTSL
end_comment

begin_define
define|#
directive|define
name|H_SETSIZE
value|1
end_define

begin_comment
comment|// , const int
end_comment

begin_define
define|#
directive|define
name|H_GETSIZE
value|2
end_define

begin_comment
comment|// , void
end_comment

begin_define
define|#
directive|define
name|H_FIRST
value|3
end_define

begin_comment
comment|// , void
end_comment

begin_define
define|#
directive|define
name|H_LAST
value|4
end_define

begin_comment
comment|// , void
end_comment

begin_define
define|#
directive|define
name|H_PREV
value|5
end_define

begin_comment
comment|// , void
end_comment

begin_define
define|#
directive|define
name|H_NEXT
value|6
end_define

begin_comment
comment|// , void
end_comment

begin_define
define|#
directive|define
name|H_CURR
value|8
end_define

begin_comment
comment|// , const int
end_comment

begin_define
define|#
directive|define
name|H_SET
value|7
end_define

begin_comment
comment|// , int
end_comment

begin_define
define|#
directive|define
name|H_ADD
value|9
end_define

begin_comment
comment|// , const char *
end_comment

begin_define
define|#
directive|define
name|H_ENTER
value|10
end_define

begin_comment
comment|// , const char *
end_comment

begin_define
define|#
directive|define
name|H_APPEND
value|11
end_define

begin_comment
comment|// , const char *
end_comment

begin_define
define|#
directive|define
name|H_END
value|12
end_define

begin_comment
comment|// , void
end_comment

begin_define
define|#
directive|define
name|H_NEXT_STR
value|13
end_define

begin_comment
comment|// , const char *
end_comment

begin_define
define|#
directive|define
name|H_PREV_STR
value|14
end_define

begin_comment
comment|// , const char *
end_comment

begin_define
define|#
directive|define
name|H_NEXT_EVENT
value|15
end_define

begin_comment
comment|// , const int
end_comment

begin_define
define|#
directive|define
name|H_PREV_EVENT
value|16
end_define

begin_comment
comment|// , const int
end_comment

begin_define
define|#
directive|define
name|H_LOAD
value|17
end_define

begin_comment
comment|// , const char *
end_comment

begin_define
define|#
directive|define
name|H_SAVE
value|18
end_define

begin_comment
comment|// , const char *
end_comment

begin_define
define|#
directive|define
name|H_CLEAR
value|19
end_define

begin_comment
comment|// , void
end_comment

begin_define
define|#
directive|define
name|H_SETUNIQUE
value|20
end_define

begin_comment
comment|// , int
end_comment

begin_define
define|#
directive|define
name|H_GETUNIQUE
value|21
end_define

begin_comment
comment|// , void
end_comment

begin_define
define|#
directive|define
name|H_DEL
value|22
end_define

begin_comment
comment|// , int
end_comment

begin_struct
struct|struct
name|EditLine
block|{ }
struct|;
end_struct

begin_struct
struct|struct
name|LineInfo
block|{
specifier|const
name|char
modifier|*
name|buffer
decl_stmt|;
specifier|const
name|char
modifier|*
name|cursor
decl_stmt|;
specifier|const
name|char
modifier|*
name|lastchar
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|History
block|{ }
struct|;
end_struct

begin_struct
struct|struct
name|HistEvent
block|{
name|int
name|num
decl_stmt|;
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
block|}
struct|;
end_struct

begin_extern
extern|extern
literal|"C"
block|{
comment|// edit line API
name|EditLine
modifier|*
name|el_init
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|el_gets
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
name|int
name|el_set
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
name|void
name|el_end
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
name|void
name|el_reset
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
name|int
name|el_getc
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
name|el_push
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
name|el_beep
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
name|int
name|el_parse
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|int
name|el_get
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
name|int
name|el_source
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
name|el_resize
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
specifier|const
name|LineInfo
modifier|*
name|el_line
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
name|int
name|el_insertstr
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
name|el_deletestr
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|// history API
name|History
modifier|*
name|history_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|history_end
parameter_list|(
name|History
modifier|*
parameter_list|)
function_decl|;
name|int
name|history
parameter_list|(
name|History
modifier|*
parameter_list|,
name|HistEvent
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
block|}
end_extern

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

