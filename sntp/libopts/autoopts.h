begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  \file autoopts.h  *  *  This file defines all the global structures and special values  *  used in the automated option processing library.  *  * @group autoopts  * @{  */
end_comment

begin_comment
comment|/*  *  This file is part of AutoOpts, a companion to AutoGen.  *  AutoOpts is free software.  *  AutoOpts is Copyright (C) 1992-2014 by Bruce Korb - all rights reserved  *  *  AutoOpts is available under any one of two licenses.  The license  *  in use must be one of these two and the choice is under the control  *  of the user of the license.  *  *   The GNU Lesser General Public License, version 3 or later  *      See the files "COPYING.lgplv3" and "COPYING.gplv3"  *  *   The Modified Berkeley Software Distribution License  *      See the file "COPYING.mbsd"  *  *  These files have the following sha256 sums:  *  *  8584710e9b04216a394078dc156b781d0b47e1729104d666658aecef8ee32e95  COPYING.gplv3  *  4379e7444a0e2ce2b12dd6f5a52a27a4d02d39d247901d3285c88cf0d37f477b  COPYING.lgplv3  *  13aa749a5b0a454917a944ed8fffc530b784f5ead522b1aacaf4ec8aa55a6239  COPYING.mbsd  */
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
file|<stdnoreturn.h>
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

begin_ifndef
ifndef|#
directive|ifndef
name|NUL
end_ifndef

begin_define
define|#
directive|define
name|NUL
value|'\0'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BEL
value|'\a'
end_define

begin_define
define|#
directive|define
name|BS
value|'\b'
end_define

begin_define
define|#
directive|define
name|HT
value|'\t'
end_define

begin_define
define|#
directive|define
name|LF
value|'\n'
end_define

begin_define
define|#
directive|define
name|VT
value|'\v'
end_define

begin_define
define|#
directive|define
name|FF
value|'\f'
end_define

begin_define
define|#
directive|define
name|CR
value|'\r'
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
name|EX_USAGE
end_ifndef

begin_comment
comment|/**     *  Command line usage problem     */
end_comment

begin_define
define|#
directive|define
name|EX_USAGE
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EX_DATAERR
end_ifndef

begin_comment
comment|/**     *  The input data was incorrect in some way.     */
end_comment

begin_define
define|#
directive|define
name|EX_DATAERR
value|64
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

begin_comment
comment|/**     *  option state was requested from a file that cannot be loaded.     */
end_comment

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

begin_comment
comment|/**     *  AutoOpts Software failure.     */
end_comment

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
name|EX_OSERR
end_ifndef

begin_comment
comment|/**     *  Command line usage problem     */
end_comment

begin_define
define|#
directive|define
name|EX_OSERR
value|71
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NL
value|'\n'
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|C
end_ifndef

begin_comment
comment|/**  *  Coercive cast.  Compel an address to be interpreted as the type  *  of the first argument.  No complaints, just do it.  */
end_comment

begin_define
define|#
directive|define
name|C
parameter_list|(
name|_t
parameter_list|,
name|_p
parameter_list|)
value|((_t)(void *)(_p))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The __attribute__((__warn_unused_result__)) feature    is available in gcc versions 3.4 and newer,    while the typeof feature has been available since 2.7 at least.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|3
operator|||
operator|(
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|<
literal|4
operator|)
end_if

begin_define
define|#
directive|define
name|ignore_val
parameter_list|(
name|x
parameter_list|)
value|((void) (x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ignore_val
parameter_list|(
name|x
parameter_list|)
value|(({ __typeof__ (x) __x = (x); (void) __x; }))
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
value|(((p)->fOptState& OPTST_IMMUTABLE_MASK) != 0)
end_define

begin_typedef
typedef|typedef
name|int
name|tDirection
typedef|;
end_typedef

begin_comment
comment|/**  * handling option presets.  Start with command line and work through  * config settings in reverse order.  */
end_comment

begin_define
define|#
directive|define
name|DIRECTION_PRESET
value|-1
end_define

begin_comment
comment|/**  * handling normal options.  Start with first config file, then environment  * variables and finally the command line.  */
end_comment

begin_define
define|#
directive|define
name|DIRECTION_PROCESS
value|1
end_define

begin_comment
comment|/**  * An initialzation phase or an option being loaded from program sources.  */
end_comment

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
name|CALLED
parameter_list|(
name|d
parameter_list|)
value|((d)==0)
end_define

begin_comment
comment|/**  *  When loading a line (or block) of text as an option, the value can  *  be processed in any of several modes.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/**      *  If the value looks like a quoted string, then process it.  Double      *  quoted strings are processed the way strings are in "C" programs,      *  except they are treated as regular characters if the following      *  character is not a well-established escape sequence.  Single quoted      *  strings (quoted with apostrophies) are handled the way strings are      *  handled in shell scripts, *except* that backslash escapes are      *  honored before backslash escapes and apostrophies.      */
name|OPTION_LOAD_COOKED
block|,
comment|/**      * Even if the value begins with quote characters, do not do quote      * processing.  Strip leading and trailing white space.      */
name|OPTION_LOAD_UNCOOKED
block|,
comment|/**      * Keep every part of the value between the delimiters.      */
name|OPTION_LOAD_KEEP
block|}
name|tOptionLoadMode
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|tOptionLoadMode
name|option_load_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  *  The pager state is used by optionPagedUsage() procedure.  *  When it runs, it sets itself up to be called again on exit.  *  If, however, a routine needs a child process to do some work  *  before it is done, then 'pagerState' must be set to  *  'PAGER_STATE_CHILD' so that optionPagedUsage() will not try  *  to run the pager program before its time.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PAGER_STATE_INITIAL
block|,
comment|//@< initial option paging state
comment|/**      * temp file created and optionPagedUsage is scheduled to run at exit      */
name|PAGER_STATE_READY
block|,
comment|/**      *  This is a child process used in creating shell script usage.      */
name|PAGER_STATE_CHILD
block|}
name|tePagerState
typedef|;
end_typedef

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
name|char
specifier|const
modifier|*
name|pzOptArg
decl_stmt|;
name|opt_state_mask_t
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
value|_TT_(LONGUSAGE) \         _TT_(USAGE) \         _TT_(VERSION)
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

begin_comment
comment|/**  * option argument types.  Used to create usage information for  * particular options.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
specifier|const
modifier|*
name|pzStr
decl_stmt|;
name|char
specifier|const
modifier|*
name|pzReq
decl_stmt|;
name|char
specifier|const
modifier|*
name|pzNum
decl_stmt|;
name|char
specifier|const
modifier|*
name|pzFile
decl_stmt|;
name|char
specifier|const
modifier|*
name|pzKey
decl_stmt|;
name|char
specifier|const
modifier|*
name|pzKeyL
decl_stmt|;
name|char
specifier|const
modifier|*
name|pzBool
decl_stmt|;
name|char
specifier|const
modifier|*
name|pzNest
decl_stmt|;
name|char
specifier|const
modifier|*
name|pzOpt
decl_stmt|;
name|char
specifier|const
modifier|*
name|pzNo
decl_stmt|;
name|char
specifier|const
modifier|*
name|pzBrk
decl_stmt|;
name|char
specifier|const
modifier|*
name|pzNoF
decl_stmt|;
name|char
specifier|const
modifier|*
name|pzSpc
decl_stmt|;
name|char
specifier|const
modifier|*
name|pzOptFmt
decl_stmt|;
name|char
specifier|const
modifier|*
name|pzTime
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
value|free((void *)(intptr_t)p)
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

begin_define
define|#
directive|define
name|ao_free
parameter_list|(
name|_p
parameter_list|)
value|free((void *)_p)
end_define

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

begin_comment
comment|/**  *  DO option handling?  *  *  Options are examined at two times:  at immediate handling time and at  *  normal handling time.  If an option is disabled, the timing may be  *  different from the handling of the undisabled option.  The OPTST_DIABLED  *  bit indicates the state of the currently discovered option.  *  So, here's how it works:  *  *  A) handling at "immediate" time, either 1 or 2:  *  *  1.  OPTST_DISABLED is not set:  *      IMM           must be set  *      DISABLE_IMM   don't care  *      TWICE         don't care  *      DISABLE_TWICE don't care  *      0 -and-  1 x x x  *  *  2.  OPTST_DISABLED is set:  *      IMM           don't care  *      DISABLE_IMM   must be set  *      TWICE         don't care  *      DISABLE_TWICE don't care  *      1 -and-  x 1 x x  */
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
comment|/**  *  B) handling at "regular" time because it was not immediate  *  *  1.  OPTST_DISABLED is not set:  *      IMM           must *NOT* be set  *      DISABLE_IMM   don't care  *      TWICE         don't care  *      DISABLE_TWICE don't care  *      0 -and-  0 x x x  *  *  2.  OPTST_DISABLED is set:  *      IMM           don't care  *      DISABLE_IMM   don't care  *      TWICE         must be set  *      DISABLE_TWICE don't care  *      1 -and-  x x 1 x  */
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
comment|/**  *  C)  handling at "regular" time because it is to be handled twice.  *      The immediate bit was already tested and found to be set:  *  *  3.  OPTST_DISABLED is not set:  *      IMM           is set (but don't care)  *      DISABLE_IMM   don't care  *      TWICE         must be set  *      DISABLE_TWICE don't care  *      0 -and-  ? x 1 x  *  *  4.  OPTST_DISABLED is set:  *      IMM           don't care  *      DISABLE_IMM   is set (but don't care)  *      TWICE         don't care  *      DISABLE_TWICE must be set  *      1 -and-  x ? x 1  */
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
comment|/**  * INQUERY_CALL() tests whether the option handling function has been  * called by an inquery (help text needed, or option being reset),  * or called by a set-the-option operation.  */
end_comment

begin_define
define|#
directive|define
name|INQUERY_CALL
parameter_list|(
name|_o
parameter_list|,
name|_d
parameter_list|)
value|(                  \     ((_o)<= OPTPROC_EMIT_LIMIT)                \     || ((_d) == NULL)                           \     || (((_d)->fOptState& OPTST_RESET) != 0) )
end_define

begin_comment
comment|/**  *  Define and initialize all the user visible strings.  *  We do not do translations.  If translations are to be done, then  *  the client will provide a callback for that purpose.  */
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
comment|/**  *  File pointer for usage output  */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|option_usage_fp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  *  If provided in the option structure  */
end_comment

begin_decl_stmt
specifier|static
name|char
specifier|const
modifier|*
name|program_pkgdatadir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * privately exported functions  */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|AUTOOPTS_INTERNAL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|PKGDATADIR
end_ifndef

begin_define
define|#
directive|define
name|PKGDATADIR
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|APOSTROPHE
value|'\''
end_define

begin_define
define|#
directive|define
name|OPTPROC_L_N_S
value|(OPTPROC_LONGOPT | OPTPROC_SHORTOPT)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ENABLE_NLS
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_LIBINTL_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|size_t
name|fnm_len
decl_stmt|;
name|uint32_t
name|fnm_mask
decl_stmt|;
name|char
specifier|const
modifier|*
name|fnm_name
decl_stmt|;
block|}
name|ao_flag_names_t
typedef|;
end_typedef

begin_comment
comment|/**  * Automated Options Usage Flags.  * NB: no entry may be a prefix of another entry  */
end_comment

begin_define
define|#
directive|define
name|AOFLAG_TABLE
define|\
value|_aof_(gnu,             OPTPROC_GNUUSAGE )   \     _aof_(autoopts,        ~OPTPROC_GNUUSAGE)   \     _aof_(no_misuse_usage, OPTPROC_MISUSE   )   \     _aof_(misuse_usage,    ~OPTPROC_MISUSE  )   \     _aof_(compute,         OPTPROC_COMPUTE  )
end_define

begin_define
define|#
directive|define
name|_aof_
parameter_list|(
name|_n
parameter_list|,
name|_f
parameter_list|)
value|AOUF_ ## _n ## _ID,
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|AOFLAG_TABLE
name|AOUF_COUNT
block|}
name|ao_flag_id_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_aof_
end_undef

begin_define
define|#
directive|define
name|_aof_
parameter_list|(
name|_n
parameter_list|,
name|_f
parameter_list|)
value|AOUF_ ## _n = (1<< AOUF_ ## _n ## _ID),
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|AOFLAG_TABLE
block|}
name|ao_flags_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_aof_
end_undef

begin_decl_stmt
specifier|static
name|char
specifier|const
name|zNil
index|[]
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|arg_types_t
name|argTypes
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|line_fmt_buf
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|displayEnum
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
specifier|const
name|pkgdatadir_default
index|[]
init|=
name|PKGDATADIR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
specifier|const
modifier|*
name|program_pkgdatadir
init|=
name|pkgdatadir_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|tOptionLoadMode
name|option_load_mode
init|=
name|OPTION_LOAD_UNCOOKED
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|tePagerState
name|pagerState
init|=
name|PAGER_STATE_INITIAL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|option_usage_fp
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
specifier|const
modifier|*
name|pz_enum_err_fmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tOptions
modifier|*
name|optionParseShellOptions
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
specifier|const
modifier|*
name|shell_prog
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|script_leader
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|script_trailer
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|script_text
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|print_exit
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTOOPTS_INTERNAL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTOGEN_AUTOOPTS_H */
end_comment

begin_comment
comment|/**  * @}  * Local Variables:  * mode: C  * c-file-style: "stroustrup"  * indent-tabs-mode: nil  * End:  * end of autoopts/autoopts.h */
end_comment

end_unit

