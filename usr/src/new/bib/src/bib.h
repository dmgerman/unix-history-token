begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)bib.h	2.7	9/10/85  */
end_comment

begin_comment
comment|/*   various arguments for bib and listrefs processors */
end_comment

begin_comment
comment|/* constants */
end_comment

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_define
define|#
directive|define
name|err
value|-1
end_define

begin_define
define|#
directive|define
name|REFSIZE
value|2048
end_define

begin_comment
comment|/* maximum size of reference string    */
end_comment

begin_define
define|#
directive|define
name|MAXFIELD
value|512
end_define

begin_comment
comment|/* maximum size of any field in referece*/
end_comment

begin_comment
comment|/* reference citation marker genrated in pass 1 */
end_comment

begin_define
define|#
directive|define
name|CITEMARK
value|(char) 02
end_define

begin_define
define|#
directive|define
name|CITEEND
value|(char) 03
end_define

begin_define
define|#
directive|define
name|FMTSTART
value|(char) 04
end_define

begin_define
define|#
directive|define
name|FMTEND
value|(char) 05
end_define

begin_comment
comment|/* file names */
end_comment

begin_comment
comment|/* output of invert, input file for references */
end_comment

begin_define
define|#
directive|define
name|INDXFILE
value|"INDEX"
end_define

begin_comment
comment|/* pass1 reference collection file */
end_comment

begin_define
define|#
directive|define
name|TMPREFFILE
value|"/tmp/bibrXXXXXX"
end_define

begin_comment
comment|/* pass2 text collection file */
end_comment

begin_define
define|#
directive|define
name|TMPTEXTFILE
value|"/tmp/bibpXXXXXX"
end_define

begin_comment
comment|/* temp file used in invert */
end_comment

begin_define
define|#
directive|define
name|INVTEMPFILE
value|"/tmp/invertXXXXXX"
end_define

begin_define
define|#
directive|define
name|SYSINDEX
value|"/usr/dict/papers/INDEX"
end_define

begin_comment
comment|/* default system dictionary */
end_comment

begin_define
define|#
directive|define
name|N_BMACLIB
value|"/usr/new/lib/bmac"
end_define

begin_comment
comment|/* where macro libraries live */
end_comment

begin_define
define|#
directive|define
name|N_COMFILE
value|"/usr/new/lib/bmac/common"
end_define

begin_comment
comment|/* common words */
end_comment

begin_define
define|#
directive|define
name|N_DEFSTYLE
value|"/usr/new/lib/bmac/bib.stdsn"
end_define

begin_comment
comment|/* default style of refs */
end_comment

begin_decl_stmt
name|char
name|BMACLIB
index|[
literal|64
index|]
decl_stmt|,
name|COMFILE
index|[
literal|64
index|]
decl_stmt|,
name|DEFSTYLE
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size limits */
end_comment

begin_comment
comment|/* maximum number of characters in common file */
end_comment

begin_define
define|#
directive|define
name|MAXCOMM
value|1000
end_define

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* fix needed for systems where open [w]+ doesn't work */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|READWRITE
end_ifdef

begin_define
define|#
directive|define
name|READ
value|1
end_define

begin_define
define|#
directive|define
name|WRITE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*     *	Reference information     */
end_comment

begin_struct
struct|struct
name|refinfo
block|{
name|char
modifier|*
name|ri_ref
decl_stmt|;
comment|/* actual value, base value */
name|char
modifier|*
name|ri_cite
decl_stmt|;
comment|/* citation string */
name|char
name|ri_disambig
index|[
literal|2
index|]
decl_stmt|;
comment|/* disambiguation string */
name|int
name|ri_length
decl_stmt|;
comment|/* length of reference string, plus null */
name|long
name|int
name|ri_pos
decl_stmt|;
comment|/* reference seek position */
name|int
name|ri_n
decl_stmt|;
comment|/* number of citation in pass1 */
name|struct
name|refinfo
modifier|*
name|ri_hp
decl_stmt|;
comment|/* hash chain */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wordinfo
block|{
name|char
modifier|*
name|wi_word
decl_stmt|;
comment|/* actual word */
name|char
modifier|*
name|wi_def
decl_stmt|;
comment|/* actual definition */
name|int
name|wi_length
decl_stmt|;
comment|/* word length */
name|struct
name|wordinfo
modifier|*
name|wi_hp
decl_stmt|;
comment|/* hash chain */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|strhash
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|HASHSIZE
value|509
end_define

begin_define
define|#
directive|define
name|reg
value|register
end_define

end_unit

