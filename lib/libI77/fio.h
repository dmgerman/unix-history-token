begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_include
include|#
directive|include
file|"errno.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_comment
comment|/* ANSI C */
end_comment

begin_include
include|#
directive|include
file|"stddef.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|NON_UNIX_STDIO
end_ifndef

begin_define
define|#
directive|define
name|NON_UNIX_STDIO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UIOLEN_int
end_ifdef

begin_typedef
typedef|typedef
name|int
name|uiolen
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|long
name|uiolen
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*units*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FILE
modifier|*
name|ufd
decl_stmt|;
comment|/*0=unconnected*/
name|char
modifier|*
name|ufnm
decl_stmt|;
ifndef|#
directive|ifndef
name|MSDOS
name|long
name|uinode
decl_stmt|;
name|int
name|udev
decl_stmt|;
endif|#
directive|endif
name|int
name|url
decl_stmt|;
comment|/*0=sequential*/
name|flag
name|useek
decl_stmt|;
comment|/*true=can backspace, use dir, ...*/
name|flag
name|ufmt
decl_stmt|;
name|flag
name|uprnt
decl_stmt|;
name|flag
name|ublnk
decl_stmt|;
name|flag
name|uend
decl_stmt|;
name|flag
name|uwrt
decl_stmt|;
comment|/*last io was write*/
name|flag
name|uscrtch
decl_stmt|;
block|}
name|unit
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|flag
name|f__init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cilist
modifier|*
name|f__elist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*active external io list*/
end_comment

begin_decl_stmt
specifier|extern
name|flag
name|f__reading
decl_stmt|,
name|f__external
decl_stmt|,
name|f__sequential
decl_stmt|,
name|f__formatted
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|Void
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_define
define|#
directive|define
name|Void
end_define

begin_comment
comment|/*void*/
end_comment

begin_decl_stmt
specifier|extern
name|int
argument_list|(
operator|*
name|f__getn
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|f__putn
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*for formatted io*/
end_comment

begin_function_decl
specifier|extern
name|long
name|f__inode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VOID
name|sig_die
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
argument_list|(
operator|*
name|f__donewrec
argument_list|)
argument_list|()
decl_stmt|,
name|t_putc
argument_list|()
decl_stmt|,
name|x_wSL
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_sfe
argument_list|()
decl_stmt|,
name|err__fl
argument_list|()
decl_stmt|,
name|xrd_SL
argument_list|()
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Void
value|void
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
specifier|extern
name|int
argument_list|(
operator|*
name|f__getn
argument_list|)
argument_list|(
name|void
argument_list|)
decl_stmt|,
argument_list|(
operator|*
name|f__putn
argument_list|)
argument_list|(
name|int
argument_list|)
decl_stmt|;
comment|/*for formatted io*/
specifier|extern
name|long
name|f__inode
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|sig_die
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|f__fatal
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|t_runc
parameter_list|(
name|alist
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|f__nowreading
argument_list|(
name|unit
operator|*
argument_list|)
decl_stmt|,
name|f__nowwriting
argument_list|(
name|unit
operator|*
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|fk_open
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|ftnint
parameter_list|)
function_decl|;
specifier|extern
name|int
name|en_fio
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|f_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
argument_list|(
operator|*
name|f__donewrec
argument_list|)
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|t_putc
argument_list|(
name|int
argument_list|)
decl_stmt|,
name|x_wSL
argument_list|(
name|void
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|b_char
argument_list|(
name|char
operator|*
argument_list|,
name|char
operator|*
argument_list|,
name|ftnlen
argument_list|)
decl_stmt|,
name|g_char
argument_list|(
name|char
operator|*
argument_list|,
name|ftnlen
argument_list|,
name|char
operator|*
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|c_sfe
argument_list|(
name|cilist
operator|*
argument_list|)
decl_stmt|,
name|z_rnew
argument_list|(
name|void
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|isatty
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|err__fl
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|xrd_SL
parameter_list|(
name|void
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|f__doend
function_decl|)
parameter_list|(
name|Void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|f__cf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current file*/
end_comment

begin_decl_stmt
specifier|extern
name|unit
modifier|*
name|f__curunit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current unit*/
end_comment

begin_decl_stmt
specifier|extern
name|unit
name|f__units
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|err
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|,
name|s
parameter_list|)
value|{if(f) errno= m; else f__fatal(m,s); return(m);}
end_define

begin_define
define|#
directive|define
name|errfl
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|,
name|s
parameter_list|)
value|return err__fl((int)f,m,s)
end_define

begin_comment
comment|/*Table sizes*/
end_comment

begin_define
define|#
directive|define
name|MXUNIT
value|100
end_define

begin_decl_stmt
specifier|extern
name|int
name|f__recpos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*position in current record*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f__cursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset to move to */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f__hiwater
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* so TL doesn't confuse us */
end_comment

begin_define
define|#
directive|define
name|WRITE
value|1
end_define

begin_define
define|#
directive|define
name|READ
value|2
end_define

begin_define
define|#
directive|define
name|SEQ
value|3
end_define

begin_define
define|#
directive|define
name|DIR
value|4
end_define

begin_define
define|#
directive|define
name|FMT
value|5
end_define

begin_define
define|#
directive|define
name|UNF
value|6
end_define

begin_define
define|#
directive|define
name|EXT
value|7
end_define

begin_define
define|#
directive|define
name|INT
value|8
end_define

begin_define
define|#
directive|define
name|buf_end
parameter_list|(
name|x
parameter_list|)
value|(x->_flag& _IONBF ? x->_ptr : x->_base + BUFSIZ)
end_define

end_unit

