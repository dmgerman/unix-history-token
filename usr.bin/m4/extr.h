begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Header : extr.h     Author : Ozan Yigit     Updated: %G% */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|putback
end_ifndef

begin_decl_stmt
specifier|extern
name|ndptr
name|hashtab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash table for macros etc.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|buf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* push-back buffer	       */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|bp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first available character   */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|bb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current beginning of bp     */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|endpbb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of push-back buffer     */
end_comment

begin_decl_stmt
specifier|extern
name|stae
name|mstack
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stack of m4 machine         */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first free char in strspace */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|endest
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of string space	       */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current m4  stack pointer   */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* m4 call frame pointer       */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|bbstack
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|infile
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file stack (0=stdin)  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|outfile
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* diversion array(0=bitbucket)*/
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|active
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* active output file pointer  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|m4temp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* filename for diversions     */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|UNIQUE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where to change m4temp      */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ilevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file stack pointer    */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|oindex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* diversion index..	       */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|null
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* as it says.. just a null..  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|m4wraps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* m4wrap string default..     */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|lquote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* left quote character  (`)   */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|rquote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* right quote character (')   */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|vquote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* verbatim quote character ^V */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|scommt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start character for comment */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ecommt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end character for comment   */
end_comment

begin_comment
comment|/* inlined versions of chrsave() and putback() */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|pbmsg
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error message for putback */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|csmsg
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error message for chrsave */
end_comment

begin_define
define|#
directive|define
name|putback
parameter_list|(
name|c
parameter_list|)
value|do { if (bp>= endpbb) error(pbmsg); *bp++ = c; } while (0)
end_define

begin_define
define|#
directive|define
name|chrsave
parameter_list|(
name|c
parameter_list|)
value|do { if (ep>= endest) error(csmsg); *ep++ = c; } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* functions from misc.c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strsave
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|indx
parameter_list|(
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
name|void
name|pbstr
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pbqtd
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pbnum
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pbrad
parameter_list|(
name|long
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
name|getdiv
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|killdiv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|error
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|onintr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|usage
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* functions from look.c */
end_comment

begin_function_decl
specifier|extern
name|ndptr
name|lookup
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ndptr
name|addent
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remhash
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
name|addkywd
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* functions from int2str.c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|int2str
parameter_list|(
comment|/* char*, int, long */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* functions from serv.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|expand
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dodefine
parameter_list|(
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
name|void
name|dopushdef
parameter_list|(
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
name|void
name|dodefn
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dodump
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doifelse
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|doincl
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dochq
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dochc
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dodiv
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doundiv
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dosub
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|map
parameter_list|(
name|char
modifier|*
parameter_list|,
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

begin_ifdef
ifdef|#
directive|ifdef
name|EXTENDED
end_ifdef

begin_function_decl
specifier|extern
name|int
name|dopaste
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|m4trim
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dodefqt
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doqutr
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* functions from expr.c */
end_comment

begin_function_decl
specifier|extern
name|long
name|expr
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* functions from misc.c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strsave
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|indx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pbstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pbqtd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pbnum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pbrad
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|getdiv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|killdiv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|onintr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|usage
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* functions from look.c */
end_comment

begin_function_decl
specifier|extern
name|ndptr
name|lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ndptr
name|addent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remhash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|addkywd
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* functions from int2str.c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|int2str
parameter_list|(
comment|/* char*, int, long */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* functions from serv.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|expand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dodefine
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dopushdef
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dodefn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dodump
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doifelse
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|doincl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dochq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dochc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dodiv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doundiv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dosub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|map
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|EXTENDED
end_ifdef

begin_function_decl
specifier|extern
name|int
name|dopaste
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|m4trim
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dodefqt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doqutr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* functions from expr.c */
end_comment

begin_function_decl
specifier|extern
name|long
name|expr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

