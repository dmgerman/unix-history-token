begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|VISUAL
end_define

begin_comment
comment|/*  * Ex - text editor  * Bill Joy UCB June 1977  *  * Based on an earlier editor "ex" written by  * William Joy and Charles Haley.  *  * And of course an inestimable debt to "ed"!  */
end_comment

begin_define
define|#
directive|define
name|STATIC
end_define

begin_define
define|#
directive|define
name|CHAR
end_define

begin_define
define|#
directive|define
name|NIL
value|0
end_define

begin_define
define|#
directive|define
name|QUOTE
value|0200
end_define

begin_define
define|#
directive|define
name|HUP
value|1
end_define

begin_define
define|#
directive|define
name|INTR
value|2
end_define

begin_define
define|#
directive|define
name|QUIT
value|3
end_define

begin_define
define|#
directive|define
name|FNSIZE
value|64
end_define

begin_define
define|#
directive|define
name|LBSIZE
value|512
end_define

begin_define
define|#
directive|define
name|EOF
value|-1
end_define

begin_decl_stmt
name|char
name|ruptible
decl_stmt|,
name|inglobal
decl_stmt|,
name|inopen
decl_stmt|,
name|inconf
decl_stmt|,
name|listf
decl_stmt|,
name|endline
decl_stmt|,
name|laste
decl_stmt|,
name|intty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|shudclob
decl_stmt|,
name|diddle
decl_stmt|,
name|die
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|chngflag
decl_stmt|,
name|xchngflag
decl_stmt|,
name|tchngflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
comment|/* savedfile[FNS, */
name|file
index|[
name|FNSIZE
index|]
decl_stmt|,
name|altfile
index|[
name|FNSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|linebuf
index|[
name|LBSIZE
index|]
decl_stmt|,
name|genbuf
index|[
name|LBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|address
argument_list|()
decl_stmt|,
modifier|*
name|addr1
decl_stmt|,
modifier|*
name|addr2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|zero
decl_stmt|,
modifier|*
name|one
decl_stmt|,
modifier|*
name|dot
decl_stmt|,
modifier|*
name|dol
decl_stmt|,
modifier|*
name|unddol
decl_stmt|,
modifier|*
name|endcore
decl_stmt|,
modifier|*
name|fendcore
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|unddel
decl_stmt|,
modifier|*
name|undap1
decl_stmt|,
modifier|*
name|undap2
decl_stmt|,
modifier|*
name|undadot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|undkind
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UNDCHANGE
value|0
end_define

begin_define
define|#
directive|define
name|UNDMOVE
value|1
end_define

begin_define
define|#
directive|define
name|UNDALL
value|2
end_define

begin_define
define|#
directive|define
name|UNDNONE
value|3
end_define

begin_decl_stmt
name|int
name|io
decl_stmt|,
name|erfile
decl_stmt|,
name|tfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|globp
decl_stmt|,
modifier|*
name|erpath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|names
index|[
literal|27
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|outcol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|home
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Command
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getfile
argument_list|()
decl_stmt|,
name|gettty
argument_list|()
decl_stmt|,
name|getchar
argument_list|()
decl_stmt|,
name|getsub
argument_list|()
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"ex_vars.h"
end_include

begin_define
define|#
directive|define
name|eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp(a, b) == 0)
end_define

begin_define
define|#
directive|define
name|CTRL
parameter_list|(
name|c
parameter_list|)
value|('c'& 037)
end_define

begin_define
define|#
directive|define
name|ECHO
value|010
end_define

begin_define
define|#
directive|define
name|RAW
value|040
end_define

begin_decl_stmt
name|char
name|normtty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|normf
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
block|{
name|int
name|fildes
decl_stmt|;
name|int
name|nunused
decl_stmt|;
name|char
modifier|*
name|xfree
decl_stmt|;
name|char
name|buff
index|[
literal|512
index|]
decl_stmt|;
block|}
name|obuf
struct|;
end_struct

begin_decl_stmt
name|int
name|oldhup
decl_stmt|,
name|onhup
argument_list|()
decl_stmt|,
name|oldquit
decl_stmt|,
name|onintr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
block|{
name|int
name|Atime
index|[
literal|2
index|]
decl_stmt|;
name|int
name|Auid
decl_stmt|;
name|int
name|Alines
decl_stmt|;
name|int
name|Afname
index|[
name|FNSIZE
index|]
decl_stmt|;
name|int
name|Ablocks
index|[
literal|100
index|]
decl_stmt|;
block|}
name|header
struct|;
end_struct

begin_define
define|#
directive|define
name|savedfile
value|header.Afname
end_define

begin_define
define|#
directive|define
name|blocks
value|header.Ablocks
end_define

begin_decl_stmt
name|int
name|dirtcnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|recov
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|TTYNAM
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|TMODE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lastc
decl_stmt|,
name|peekc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|lastchar
parameter_list|()
value|lastc
end_define

begin_define
define|#
directive|define
name|setlastchar
parameter_list|(
name|c
parameter_list|)
value|lastc = c
end_define

begin_define
define|#
directive|define
name|ungetchar
parameter_list|(
name|c
parameter_list|)
value|peekc = c
end_define

begin_decl_stmt
name|char
name|aiflag
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|setai
parameter_list|(
name|i
parameter_list|)
value|aiflag = i
end_define

begin_decl_stmt
name|int
name|pid
decl_stmt|,
name|rpid
decl_stmt|,
name|status
decl_stmt|,
name|tty
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|allredraw
decl_stmt|,
name|pfast
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mask
decl_stmt|,
name|vcntcol
decl_stmt|;
end_decl_stmt

end_unit

