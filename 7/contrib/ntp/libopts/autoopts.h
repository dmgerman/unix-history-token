begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Time-stamp:      "2007-04-15 09:59:39 bkorb"  *  *  autoopts.h  $Id: autoopts.h,v 4.23 2007/04/15 19:01:18 bkorb Exp $  *  Time-stamp:      "2005-02-14 05:59:50 bkorb"  *  *  This file defines all the global structures and special values  *  used in the automated option processing library.  */
end_comment

begin_comment
comment|/*  *  Automated Options copyright 1992-2007 Bruce Korb  *  *  Automated Options is free software.  *  You may redistribute it and/or modify it under the terms of the  *  GNU General Public License, as published by the Free Software  *  Foundation; either version 2, or (at your option) any later version.  *  *  Automated Options is distributed in the hope that it will be useful,  *  but WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *  GNU General Public License for more details.  *  *  You should have received a copy of the GNU General Public License  *  along with Automated Options.  See the file "COPYING".  If not,  *  write to:  The Free Software Foundation, Inc.,  *             51 Franklin Street, Fifth Floor,  *             Boston, MA  02110-1301, USA.  *  * As a special exception, Bruce Korb gives permission for additional  * uses of the text contained in his release of AutoOpts.  *  * The exception is that, if you link the AutoOpts library with other  * files to produce an executable, this does not by itself cause the  * resulting executable to be covered by the GNU General Public License.  * Your use of that executable is in no way restricted on account of  * linking the AutoOpts library code into it.  *  * This exception does not however invalidate any other reasons why  * the executable file might be covered by the GNU General Public License.  *  * This exception applies only to the code released by Bruce Korb under  * the name AutoOpts.  If you copy code from other sources under the  * General Public License into a copy of AutoOpts, as the General Public  * License permits, the exception does not apply to the code that you add  * in this way.  To avoid misleading anyone as to the status of such  * modified files, you must delete this exception notice from them.  *  * If you write modifications of your own for AutoOpts, it is your choice  * whether to permit this exception to apply to your modifications.  * If you do not wish that, delete this exception notice.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTOGEN_AUTOOPTS_H
end_ifndef

begin_define
define|#
directive|define
name|AUTOGEN_AUTOOPTS_H
end_define

begin_include
include|#
directive|include
file|"compat/compat.h"
end_include

begin_define
define|#
directive|define
name|AO_NAME_LIMIT
value|127
end_define

begin_define
define|#
directive|define
name|AO_NAME_SIZE
value|((size_t)(AO_NAME_LIMIT + 1))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|AG_PATH_MAX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PATH_MAX
end_ifdef

begin_define
define|#
directive|define
name|AG_PATH_MAX
value|((size_t)PATH_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AG_PATH_MAX
value|((size_t)4096)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PATH_MAX
argument_list|)
operator|&&
operator|(
name|PATH_MAX
operator|>
name|MAXPATHLEN
operator|)
end_if

begin_undef
undef|#
directive|undef
name|AG_PATH_MAX
end_undef

begin_define
define|#
directive|define
name|AG_PATH_MAX
value|((size_t)PATH_MAX)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|EXPORT
end_undef

begin_define
define|#
directive|define
name|EXPORT
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_define
define|#
directive|define
name|DIRCH
value|'\\'
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DIRCH
value|'/'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EX_NOINPUT
end_ifndef

begin_define
define|#
directive|define
name|EX_NOINPUT
value|66
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EX_SOFTWARE
end_ifndef

begin_define
define|#
directive|define
name|EX_SOFTWARE
value|70
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EX_CONFIG
end_ifndef

begin_define
define|#
directive|define
name|EX_CONFIG
value|78
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  Convert the number to a list usable in a printf call  */
end_comment

begin_define
define|#
directive|define
name|NUM_TO_VER
parameter_list|(
name|n
parameter_list|)
value|((n)>> 12), ((n)>> 7)& 0x001F, (n)& 0x007F
end_define

begin_define
define|#
directive|define
name|NAMED_OPTS
parameter_list|(
name|po
parameter_list|)
define|\
value|(((po)->fOptSet& (OPTPROC_SHORTOPT | OPTPROC_LONGOPT)) == 0)
end_define

begin_define
define|#
directive|define
name|SKIP_OPT
parameter_list|(
name|p
parameter_list|)
value|(((p)->fOptState& (OPTST_DOCUMENT|OPTST_OMITTED)) != 0)
end_define

begin_typedef
typedef|typedef
name|int
name|tDirection
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DIRECTION_PRESET
value|-1
end_define

begin_define
define|#
directive|define
name|DIRECTION_PROCESS
value|1
end_define

begin_define
define|#
directive|define
name|DIRECTION_CALLED
value|0
end_define

begin_define
define|#
directive|define
name|PROCESSING
parameter_list|(
name|d
parameter_list|)
value|((d)>0)
end_define

begin_define
define|#
directive|define
name|PRESETTING
parameter_list|(
name|d
parameter_list|)
value|((d)<0)
end_define

begin_define
define|#
directive|define
name|ISNAMECHAR
parameter_list|(
name|c
parameter_list|)
value|(isalnum(c) || ((c) == '_') || ((c) == '-'))
end_define

begin_comment
comment|/*  *  Procedure success codes  *  *  USAGE:  define procedures to return "tSuccess".  Test their results  *          with the SUCCEEDED, FAILED and HADGLITCH macros.  *  *  Microsoft sticks its nose into user space here, so for Windows' sake,  *  make sure all of these are undefined.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUCCESS
end_undef

begin_undef
undef|#
directive|undef
name|FAILURE
end_undef

begin_undef
undef|#
directive|undef
name|PROBLEM
end_undef

begin_undef
undef|#
directive|undef
name|SUCCEEDED
end_undef

begin_undef
undef|#
directive|undef
name|SUCCESSFUL
end_undef

begin_undef
undef|#
directive|undef
name|FAILED
end_undef

begin_undef
undef|#
directive|undef
name|HADGLITCH
end_undef

begin_define
define|#
directive|define
name|SUCCESS
value|((tSuccess) 0)
end_define

begin_define
define|#
directive|define
name|FAILURE
value|((tSuccess)-1)
end_define

begin_define
define|#
directive|define
name|PROBLEM
value|((tSuccess) 1)
end_define

begin_typedef
typedef|typedef
name|int
name|tSuccess
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SUCCEEDED
parameter_list|(
name|p
parameter_list|)
value|((p) == SUCCESS)
end_define

begin_define
define|#
directive|define
name|SUCCESSFUL
parameter_list|(
name|p
parameter_list|)
value|SUCCEEDED( p )
end_define

begin_define
define|#
directive|define
name|FAILED
parameter_list|(
name|p
parameter_list|)
value|((p)<  SUCCESS)
end_define

begin_define
define|#
directive|define
name|HADGLITCH
parameter_list|(
name|p
parameter_list|)
value|((p)>  SUCCESS)
end_define

begin_comment
comment|/*  *  When loading a line (or block) of text as an option, the value can  *  be processed in any of several modes:  *  *  @table @samp  *  @item keep  *  Every part of the value between the delimiters is saved.  *  *  @item uncooked  *  Even if the value begins with quote characters, do not do quote processing.  *  *  @item cooked  *  If the value looks like a quoted string, then process it.  *  Double quoted strings are processed the way strings are in "C" programs,  *  except they are treated as regular characters if the following character  *  is not a well-established escape sequence.  *  Single quoted strings (quoted with apostrophies) are handled the way  *  strings are handled in shell scripts, *except* that backslash escapes  *  are honored before backslash escapes and apostrophies.  *  @end table  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|OPTION_LOAD_COOKED
block|,
name|OPTION_LOAD_UNCOOKED
block|,
name|OPTION_LOAD_KEEP
block|}
name|tOptionLoadMode
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|tOptionLoadMode
name|option_load_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *  The pager state is used by optionPagedUsage() procedure.  *  When it runs, it sets itself up to be called again on exit.  *  If, however, a routine needs a child process to do some work  *  before it is done, then 'pagerState' must be set to  *  'PAGER_STATE_CHILD' so that optionPagedUsage() will not try  *  to run the pager program before its time.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PAGER_STATE_INITIAL
block|,
name|PAGER_STATE_READY
block|,
name|PAGER_STATE_CHILD
block|}
name|tePagerState
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|tePagerState
name|pagerState
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
enum|enum
block|{
name|ENV_ALL
block|,
name|ENV_IMM
block|,
name|ENV_NON_IMM
block|}
name|teEnvPresetType
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|TOPT_UNDEFINED
init|=
literal|0
block|,
name|TOPT_SHORT
block|,
name|TOPT_LONG
block|,
name|TOPT_DEFAULT
block|}
name|teOptType
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|tOptDesc
modifier|*
name|pOD
decl_stmt|;
name|tCC
modifier|*
name|pzOptArg
decl_stmt|;
name|tAoUL
name|flags
decl_stmt|;
name|teOptType
name|optType
decl_stmt|;
block|}
name|tOptState
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OPTSTATE_INITIALIZER
parameter_list|(
name|st
parameter_list|)
define|\
value|{ NULL, NULL, OPTST_ ## st, TOPT_UNDEFINED }
end_define

begin_define
define|#
directive|define
name|TEXTTO_TABLE
define|\
value|_TT_( LONGUSAGE ) \         _TT_( USAGE ) \         _TT_( VERSION )
end_define

begin_define
define|#
directive|define
name|_TT_
parameter_list|(
name|n
parameter_list|)
define|\
value|TT_ ## n ,
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|TEXTTO_TABLE
name|COUNT_TT
block|}
name|teTextTo
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_TT_
end_undef

begin_typedef
typedef|typedef
struct|struct
block|{
name|tCC
modifier|*
name|pzStr
decl_stmt|;
name|tCC
modifier|*
name|pzReq
decl_stmt|;
name|tCC
modifier|*
name|pzNum
decl_stmt|;
name|tCC
modifier|*
name|pzKey
decl_stmt|;
name|tCC
modifier|*
name|pzKeyL
decl_stmt|;
name|tCC
modifier|*
name|pzBool
decl_stmt|;
name|tCC
modifier|*
name|pzNest
decl_stmt|;
name|tCC
modifier|*
name|pzOpt
decl_stmt|;
name|tCC
modifier|*
name|pzNo
decl_stmt|;
name|tCC
modifier|*
name|pzBrk
decl_stmt|;
name|tCC
modifier|*
name|pzNoF
decl_stmt|;
name|tCC
modifier|*
name|pzSpc
decl_stmt|;
name|tCC
modifier|*
name|pzOptFmt
decl_stmt|;
block|}
name|arg_types_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AGALOC
parameter_list|(
name|c
parameter_list|,
name|w
parameter_list|)
value|ao_malloc((size_t)c)
end_define

begin_define
define|#
directive|define
name|AGREALOC
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|,
name|w
parameter_list|)
value|ao_realloc((void*)p, (size_t)c)
end_define

begin_define
define|#
directive|define
name|AGFREE
parameter_list|(
name|p
parameter_list|)
value|ao_free((void*)p)
end_define

begin_define
define|#
directive|define
name|AGDUPSTR
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|,
name|w
parameter_list|)
value|(p = ao_strdup(s))
end_define

begin_function_decl
specifier|static
name|void
modifier|*
name|ao_malloc
parameter_list|(
name|size_t
name|sz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
modifier|*
name|ao_realloc
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|sz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ao_free
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|char
modifier|*
name|ao_strdup
parameter_list|(
name|char
specifier|const
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TAGMEM
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|)
end_define

begin_comment
comment|/*  *  DO option handling?  *  *  Options are examined at two times:  at immediate handling time and at  *  normal handling time.  If an option is disabled, the timing may be  *  different from the handling of the undisabled option.  The OPTST_DIABLED  *  bit indicates the state of the currently discovered option.  *  So, here's how it works:  *  *  A) handling at "immediate" time, either 1 or 2:  *  *  1.  OPTST_DISABLED is not set:  *      IMM           must be set  *      DISABLE_IMM   don't care  *      TWICE         don't care  *      DISABLE_TWICE don't care  *      0 -and-  1 x x x  *  *  2.  OPTST_DISABLED is set:  *      IMM           don't care  *      DISABLE_IMM   must be set  *      TWICE         don't care  *      DISABLE_TWICE don't care  *      1 -and-  x 1 x x  */
end_comment

begin_define
define|#
directive|define
name|DO_IMMEDIATELY
parameter_list|(
name|_flg
parameter_list|)
define|\
value|(  (((_flg)& (OPTST_DISABLED|OPTST_IMM)) == OPTST_IMM) \     || (   ((_flg)& (OPTST_DISABLED|OPTST_DISABLE_IMM))    \         == (OPTST_DISABLED|OPTST_DISABLE_IMM)  ))
end_define

begin_comment
comment|/*  B) handling at "regular" time because it was not immediate  *  *  1.  OPTST_DISABLED is not set:  *      IMM           must *NOT* be set  *      DISABLE_IMM   don't care  *      TWICE         don't care  *      DISABLE_TWICE don't care  *      0 -and-  0 x x x  *  *  2.  OPTST_DISABLED is set:  *      IMM           don't care  *      DISABLE_IMM   don't care  *      TWICE         must be set  *      DISABLE_TWICE don't care  *      1 -and-  x x 1 x  */
end_comment

begin_define
define|#
directive|define
name|DO_NORMALLY
parameter_list|(
name|_flg
parameter_list|)
value|( \        (((_flg)& (OPTST_DISABLED|OPTST_IMM))            == 0)  \     || (((_flg)& (OPTST_DISABLED|OPTST_DISABLE_IMM))    ==     \                   OPTST_DISABLED)  )
end_define

begin_comment
comment|/*  C)  handling at "regular" time because it is to be handled twice.  *      The immediate bit was already tested and found to be set:  *  *  3.  OPTST_DISABLED is not set:  *      IMM           is set (but don't care)  *      DISABLE_IMM   don't care  *      TWICE         must be set  *      DISABLE_TWICE don't care  *      0 -and-  ? x 1 x  *  *  4.  OPTST_DISABLED is set:  *      IMM           don't care  *      DISABLE_IMM   is set (but don't care)  *      TWICE         don't care  *      DISABLE_TWICE must be set  *      1 -and-  x ? x 1  */
end_comment

begin_define
define|#
directive|define
name|DO_SECOND_TIME
parameter_list|(
name|_flg
parameter_list|)
value|( \        (((_flg)& (OPTST_DISABLED|OPTST_TWICE))          ==     \                   OPTST_TWICE)                                  \     || (((_flg)& (OPTST_DISABLED|OPTST_DISABLE_TWICE))  ==     \                   (OPTST_DISABLED|OPTST_DISABLE_TWICE)  ))
end_define

begin_comment
comment|/*  *  text_mmap structure.  Only active on platforms with mmap(2).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_MMAN_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|PROT_READ
end_ifndef

begin_define
define|#
directive|define
name|PROT_READ
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PROT_WRITE
end_ifndef

begin_define
define|#
directive|define
name|PROT_WRITE
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAP_SHARED
end_ifndef

begin_define
define|#
directive|define
name|MAP_SHARED
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAP_PRIVATE
end_ifndef

begin_define
define|#
directive|define
name|MAP_PRIVATE
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAP_FAILED
end_ifndef

begin_define
define|#
directive|define
name|MAP_FAILED
value|((void*)-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SC_PAGESIZE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_SC_PAGE_SIZE
end_ifdef

begin_define
define|#
directive|define
name|_SC_PAGESIZE
value|_SC_PAGE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRCHR
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strchr
parameter_list|(
name|char
specifier|const
modifier|*
name|s
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strrchr
parameter_list|(
name|char
specifier|const
modifier|*
name|s
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  Define and initialize all the user visible strings.  *  We do not do translations.  If translations are to be done, then  *  the client will provide a callback for that purpose.  */
end_comment

begin_undef
undef|#
directive|undef
name|DO_TRANSLATIONS
end_undef

begin_include
include|#
directive|include
file|"autoopts/usage-txt.h"
end_include

begin_comment
comment|/*  *  File pointer for usage output  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|option_usage_fp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tOptProc
name|optionPrintVersion
decl_stmt|,
name|optionPagedUsage
decl_stmt|,
name|optionLoadOpt
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTOGEN_AUTOOPTS_H */
end_comment

begin_comment
comment|/*  * Local Variables:  * mode: C  * c-file-style: "stroustrup"  * indent-tabs-mode: nil  * End:  * end of autoopts/autoopts.h */
end_comment

end_unit

