begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|argp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|chname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|eibuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|enda
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fitab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fontab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|kerntab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ibufp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|obufp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|unlkp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xbufp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xeibuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|codetab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|devname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|fontfile
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ibuf
index|[
name|IBUFSZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|nextf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|obuf
index|[]
decl_stmt|,
modifier|*
name|obufp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|termtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|xbuf
index|[
name|IBUFSZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|filep
name|apptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|filep
name|ip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|filep
name|nextb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|filep
name|offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|filep
name|roff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|filep
name|woff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|chtab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|pnp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|pslp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|pstab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|vlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Bflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ad
decl_stmt|,
name|admod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|adrem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|adsp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|app
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|apts
decl_stmt|,
name|apts1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ascii
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|back
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bdtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ccs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ce
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|code
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|copyf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cwidth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dfact
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dfactd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|diflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dilev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|donef
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dotT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dotc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dpn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ejf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|em
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|eqflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|error
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|esc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|eschar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|evi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|evlist
index|[
name|EVLSZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fmt
index|[
name|NN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|font1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|font
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fontlab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|stip1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|stip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
modifier|*
name|stiplab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hyf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hyoff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ibf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|icf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ics
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ifi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ifile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ifl
index|[
name|NSO
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|in1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|in
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inc
index|[
name|NN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|it
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|itmac
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lastl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lgf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ll1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lnmod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lnsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ls1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ls
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lss1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lt1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|macerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mfont
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mlist
index|[
name|NTRAP
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mpts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nchar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ndf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ndone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ne
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|newmn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nflush
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfonts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nstips
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nform
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nhyp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ni
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nlflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nlist
index|[
name|NTRAP
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nms
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|no_out
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nofeed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nonumb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|noscale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|npn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|npnflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nwd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ohc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|oldbits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|oldmn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|over
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|padc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|paper
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pendnf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pendt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pfont
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pfrom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pipeflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pnlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|po1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|po
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ppts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|psflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ptid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pto
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pts1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|quiet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|r
index|[
name|NN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ralss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|raw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|res
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|setwdf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sfont
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|spacesz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|spflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|spread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|stdi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|stop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tabc
decl_stmt|,
name|dotc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tabch
decl_stmt|,
name|ldrch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tabtab
index|[
name|NTAB
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tdelim
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tlss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|totout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|trap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|trflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|trtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ttyod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ttysave
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ul
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|ulbit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ulfont
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|un1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|un
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|waitf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|wbfi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|wch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|widthp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|wne
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xbitf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xfont
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xpts
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern	no_out;
end_extern

begin_decl_stmt
specifier|extern
name|struct
name|font
modifier|*
name|fontbase
index|[
name|NFONT
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* origin of each font in core hole */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|s
modifier|*
name|ejl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|s
modifier|*
name|frame
decl_stmt|,
modifier|*
name|stk
decl_stmt|,
modifier|*
name|nxf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sgttyb
name|ttys
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
modifier|*
modifier|*
name|hyp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
modifier|*
name|ap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
modifier|*
name|hyptr
index|[
name|NHYP
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
modifier|*
name|linep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
modifier|*
name|olinep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
modifier|*
name|pendw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
modifier|*
name|wdstart
decl_stmt|,
modifier|*
name|wdend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
modifier|*
name|wordp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|cbuf
index|[
name|NC
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|ch0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|ch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|chbits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|ic
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|inchar
index|[
name|LNSIZE
index|]
decl_stmt|,
modifier|*
name|pinchar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|line
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|nmbits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|nrbits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|oline
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|rchar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|word
index|[]
decl_stmt|;
end_decl_stmt

end_unit

