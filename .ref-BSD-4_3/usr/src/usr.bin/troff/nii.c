begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)nii.c	4.1 6/7/82"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|"tdef.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NROFF
end_ifdef

begin_include
include|#
directive|include
file|"tw.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sdef.h"
end_include

begin_include
include|#
directive|include
file|"d.h"
end_include

begin_include
include|#
directive|include
file|"v.h"
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_decl_stmt
name|int
modifier|*
name|vlist
init|=
operator|(
name|int
operator|*
operator|)
operator|&
name|v
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|s
modifier|*
name|frame
decl_stmt|,
modifier|*
name|stk
decl_stmt|,
modifier|*
name|ejl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|s
modifier|*
name|nxf
decl_stmt|,
modifier|*
name|litlev
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NROFF
end_ifdef

begin_decl_stmt
name|int
name|pipeflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eqflg
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NROFF
end_ifndef

begin_decl_stmt
name|int
name|xpts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|verm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|pslp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|psflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ppts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfont
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|paper
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mpts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mfont
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mcase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|escm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|code
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ccs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|back
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|stdi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|waitf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nofeed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|quiet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|stop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ibuf
index|[
name|IBUFSZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|xbuf
index|[
name|IBUFSZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ibufp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|xbufp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|eibuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|xeibuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cbuf
index|[
name|NC
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ch
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ibf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttyod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sgttyb
name|ttys
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|enda
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|trtab
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lgf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|copyf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ch0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cwidth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|filep
name|ip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nlflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|ap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|donef
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nflush
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nchar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rchar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ifile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|padc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|raw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ifl
index|[
name|NSO
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ifi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nonumb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|trap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ejf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dilev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tlss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|filep
name|offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|em
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|filep
name|woff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|app
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ndone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ralss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|filep
name|nextb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|argtop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nrbits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nform
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|oldmn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|newmn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|macerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|filep
name|apptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|diflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|filep
name|roff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wbfi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|inc
index|[
name|NN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fmt
index|[
name|NN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|noscale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|po1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nlist
index|[
name|NTRAP
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mlist
index|[
name|NTRAP
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evlist
index|[
name|EVLSZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sfont
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|esc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|widthp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xfont
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setwdf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xbitf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|over
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nhyp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
modifier|*
name|hyp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|olinep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|esct
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttysave
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dotT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|unlkp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|no_out
decl_stmt|;
end_decl_stmt

end_unit

