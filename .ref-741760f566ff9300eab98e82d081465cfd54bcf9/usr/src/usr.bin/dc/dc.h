begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	dc.h	1.3	86/04/26	*/
end_comment

begin_define
define|#
directive|define
name|FATAL
value|0
end_define

begin_define
define|#
directive|define
name|NFATAL
value|1
end_define

begin_define
define|#
directive|define
name|BLK
value|sizeof(struct blk)
end_define

begin_define
define|#
directive|define
name|PTRSZ
value|sizeof(int *)
end_define

begin_define
define|#
directive|define
name|HEADSZ
value|1024
end_define

begin_define
define|#
directive|define
name|STKSZ
value|100
end_define

begin_define
define|#
directive|define
name|RDSKSZ
value|100
end_define

begin_define
define|#
directive|define
name|TBLSZ
value|256
end_define

begin_define
define|#
directive|define
name|ARRAYST
value|0241
end_define

begin_define
define|#
directive|define
name|MAXIND
value|2048
end_define

begin_define
define|#
directive|define
name|NL
value|1
end_define

begin_define
define|#
directive|define
name|NG
value|2
end_define

begin_define
define|#
directive|define
name|NE
value|3
end_define

begin_define
define|#
directive|define
name|length
parameter_list|(
name|p
parameter_list|)
value|((p)->wt-(p)->beg)
end_define

begin_define
define|#
directive|define
name|rewind
parameter_list|(
name|p
parameter_list|)
value|(p)->rd=(p)->beg
end_define

begin_define
define|#
directive|define
name|create
parameter_list|(
name|p
parameter_list|)
value|(p)->rd = (p)->wt = (p)->beg
end_define

begin_define
define|#
directive|define
name|fsfile
parameter_list|(
name|p
parameter_list|)
value|(p)->rd = (p)->wt
end_define

begin_define
define|#
directive|define
name|truncate
parameter_list|(
name|p
parameter_list|)
value|(p)->wt = (p)->rd
end_define

begin_define
define|#
directive|define
name|sfeof
parameter_list|(
name|p
parameter_list|)
value|(((p)->rd==(p)->wt)?1:0)
end_define

begin_define
define|#
directive|define
name|sfbeg
parameter_list|(
name|p
parameter_list|)
value|(((p)->rd==(p)->beg)?1:0)
end_define

begin_define
define|#
directive|define
name|sungetc
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|*(--(p)->rd)=c
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|interdata
end_ifdef

begin_define
define|#
directive|define
name|NEGBYTE
value|0200
end_define

begin_define
define|#
directive|define
name|MASK
value|(-1& ~0377)
end_define

begin_define
define|#
directive|define
name|sgetc
parameter_list|(
name|p
parameter_list|)
value|( ((p)->rd==(p)->wt) ? EOF :( ((*(p)->rd& NEGBYTE) != 0) ? ( *(p)->rd++ | MASK): *(p)->rd++ ))
end_define

begin_define
define|#
directive|define
name|slookc
parameter_list|(
name|p
parameter_list|)
value|( ((p)->rd==(p)->wt) ? EOF :( ((*(p)->rd& NEGBYTE) != 0) ? (*(p)->rd | MASK) : *(p)->rd ))
end_define

begin_define
define|#
directive|define
name|sbackc
parameter_list|(
name|p
parameter_list|)
value|( ((p)->rd==(p)->beg) ? EOF :( ((*(--(p)->rd)& NEGBYTE) != 0) ? (*(p)->rd | MASK): *(p)->rd ))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|interdata
end_ifndef

begin_define
define|#
directive|define
name|sgetc
parameter_list|(
name|p
parameter_list|)
value|(((p)->rd==(p)->wt)?EOF:*(p)->rd++)
end_define

begin_define
define|#
directive|define
name|slookc
parameter_list|(
name|p
parameter_list|)
value|(((p)->rd==(p)->wt)?EOF:*(p)->rd)
end_define

begin_define
define|#
directive|define
name|sbackc
parameter_list|(
name|p
parameter_list|)
value|(((p)->rd==(p)->beg)?EOF:*(--(p)->rd))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|sputc
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|{if((p)->wt==(p)->last)more(p); *(p)->wt++ = c; }
end_define

begin_define
define|#
directive|define
name|salterc
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|{if((p)->rd==(p)->last)more(p); *(p)->rd++ = c; if((p)->rd>(p)->wt)(p)->wt=(p)->rd;}
end_define

begin_define
define|#
directive|define
name|sunputc
parameter_list|(
name|p
parameter_list|)
value|(*( (p)->rd = --(p)->wt))
end_define

begin_define
define|#
directive|define
name|zero
parameter_list|(
name|p
parameter_list|)
value|for(pp=(p)->beg;pp<(p)->last;)*pp++='\0'
end_define

begin_define
define|#
directive|define
name|OUTC
parameter_list|(
name|x
parameter_list|)
value|{printf("%c",x); if(--count == 0){printf("\\\n"); count=ll;} }
end_define

begin_define
define|#
directive|define
name|TEST2
value|{if((count -= 2)<=0){printf("\\\n");count=ll;}}
end_define

begin_define
define|#
directive|define
name|EMPTY
value|if(stkerr != 0){printf("stack empty\n"); continue; }
end_define

begin_define
define|#
directive|define
name|EMPTYR
parameter_list|(
name|x
parameter_list|)
value|if(stkerr!=0){pushp(x);printf("stack empty\n");continue;}
end_define

begin_define
define|#
directive|define
name|EMPTYS
value|if(stkerr != 0){printf("stack empty\n"); return(1);}
end_define

begin_define
define|#
directive|define
name|EMPTYSR
parameter_list|(
name|x
parameter_list|)
value|if(stkerr !=0){printf("stack empty\n");pushp(x);return(1);}
end_define

begin_define
define|#
directive|define
name|error
parameter_list|(
name|p
parameter_list|)
value|{printf(p); continue; }
end_define

begin_define
define|#
directive|define
name|errorrt
parameter_list|(
name|p
parameter_list|)
value|{printf(p); return(1); }
end_define

begin_struct
struct|struct
name|blk
block|{
name|char
modifier|*
name|rd
decl_stmt|;
name|char
modifier|*
name|wt
decl_stmt|;
name|char
modifier|*
name|beg
decl_stmt|;
name|char
modifier|*
name|last
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|blk
modifier|*
name|hfree
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|blk
modifier|*
name|getwd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|blk
modifier|*
name|lookwd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|blk
modifier|*
name|getdec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|blk
modifier|*
name|morehd
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|blk
modifier|*
name|arg1
decl_stmt|,
modifier|*
name|arg2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|savk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|svargv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dbg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ifile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|curfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|blk
modifier|*
name|scalptr
decl_stmt|,
modifier|*
name|basptr
decl_stmt|,
modifier|*
name|tenptr
decl_stmt|,
modifier|*
name|inbas
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|blk
modifier|*
name|sqtemp
decl_stmt|,
modifier|*
name|chptr
decl_stmt|,
modifier|*
name|strptr
decl_stmt|,
modifier|*
name|divxyz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|blk
modifier|*
name|stack
index|[
name|STKSZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|blk
modifier|*
modifier|*
name|stkptr
decl_stmt|,
modifier|*
modifier|*
name|stkbeg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|blk
modifier|*
modifier|*
name|stkend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|stkerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lastchar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|blk
modifier|*
name|readstk
index|[
name|RDSKSZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|blk
modifier|*
modifier|*
name|readptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|blk
modifier|*
name|rem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|blk
modifier|*
name|irem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|skd
decl_stmt|,
name|skr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|blk
modifier|*
name|pop
argument_list|()
decl_stmt|,
modifier|*
name|readin
argument_list|()
decl_stmt|,
modifier|*
name|add0
argument_list|()
decl_stmt|,
modifier|*
name|mult
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|blk
modifier|*
name|scalint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|blk
modifier|*
name|removc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|blk
modifier|*
name|add
argument_list|()
decl_stmt|,
modifier|*
name|div
argument_list|()
decl_stmt|,
modifier|*
name|removr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|blk
modifier|*
name|exp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|blk
modifier|*
name|sqrt
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|blk
modifier|*
name|salloc
argument_list|()
decl_stmt|,
modifier|*
name|copy
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|blk
modifier|*
name|scale
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|neg
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|sym
block|{
name|struct
name|sym
modifier|*
name|next
decl_stmt|;
name|struct
name|blk
modifier|*
name|val
decl_stmt|;
block|}
name|symlst
index|[
name|TBLSZ
index|]
struct|;
end_struct

begin_decl_stmt
name|struct
name|sym
modifier|*
name|stable
index|[
name|TBLSZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sym
modifier|*
name|sptr
decl_stmt|,
modifier|*
name|sfree
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|wblk
block|{
name|struct
name|blk
modifier|*
modifier|*
name|rdw
decl_stmt|;
name|struct
name|blk
modifier|*
modifier|*
name|wtw
decl_stmt|;
name|struct
name|blk
modifier|*
modifier|*
name|begw
decl_stmt|;
name|struct
name|blk
modifier|*
modifier|*
name|lastw
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|FILE
modifier|*
name|fsave
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|rel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|nbytes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|all
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|headmor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|obase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fw
decl_stmt|,
name|fw1
decl_stmt|,
name|ll
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
name|outdit
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|bigot
argument_list|()
decl_stmt|,
name|hexot
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|logo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|log10
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|pp
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|int
argument_list|(
operator|*
name|signal
argument_list|()
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|onintr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|nalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

end_unit

