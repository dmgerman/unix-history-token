begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|ADS_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|ADS_DEBUG_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|int16
end_ifndef

begin_define
define|#
directive|define
name|int32
value|long
end_define

begin_define
define|#
directive|define
name|int16
value|short
end_define

begin_define
define|#
directive|define
name|int8
value|char
end_define

begin_define
define|#
directive|define
name|uint32
value|unsigned long
end_define

begin_define
define|#
directive|define
name|uint16
value|unsigned short
end_define

begin_define
define|#
directive|define
name|uint8
value|unsigned char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bool
end_ifndef

begin_define
define|#
directive|define
name|bool
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|true
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|nil
end_ifndef

begin_define
define|#
directive|define
name|nil
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|byte
end_ifndef

begin_define
define|#
directive|define
name|byte
value|unsigned char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|min
end_ifndef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a<b)?a:b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NODEBUG
end_ifndef

begin_comment
comment|/* extern bool Dflg; /* */
end_comment

begin_define
define|#
directive|define
name|Dflg
value|true
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GNU_CPP
end_ifdef

begin_define
define|#
directive|define
name|STRINGIFY
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STRINGIFY
parameter_list|(
name|x
parameter_list|)
value|"x"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|name2
end_ifndef

begin_define
define|#
directive|define
name|name2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a
comment|/**/
value|b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|dbg
parameter_list|(
name|s
parameter_list|)
value|if (Dflg) {fprintf(stderr,STRINGIFY(s));
end_define

begin_define
define|#
directive|define
name|dbgaxl
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
value|fprintf(stderr,dbgaxlstring,STRINGIFY(a),i,a[i]);
end_define

begin_define
define|#
directive|define
name|dbgb
parameter_list|(
name|s
parameter_list|)
value|fprintf(stderr,dbgbstring,STRINGIFY(s),s?"true":"false");
end_define

begin_define
define|#
directive|define
name|dbgc
parameter_list|(
name|s
parameter_list|)
value|fprintf(stderr,dbgcstring,STRINGIFY(s),s);
end_define

begin_define
define|#
directive|define
name|dbgd
parameter_list|(
name|s
parameter_list|)
value|fprintf(stderr,dbgdstring,STRINGIFY(s),s);
end_define

begin_define
define|#
directive|define
name|dbgg
parameter_list|(
name|s
parameter_list|)
value|fprintf(stderr,dbggstring,STRINGIFY(s),s);
end_define

begin_define
define|#
directive|define
name|dbgo
parameter_list|(
name|s
parameter_list|)
value|fprintf(stderr,dbgostring,STRINGIFY(s),s);
end_define

begin_define
define|#
directive|define
name|dbgs
parameter_list|(
name|s
parameter_list|)
value|fprintf(stderr,dbgsstring,STRINGIFY(s),s);
end_define

begin_define
define|#
directive|define
name|dbgx
parameter_list|(
name|s
parameter_list|)
value|fprintf(stderr,dbgxstring,STRINGIFY(s),s);
end_define

begin_define
define|#
directive|define
name|dbgxl
parameter_list|(
name|w
parameter_list|)
value|fprintf(stderr,dbgxlstring,STRINGIFY(w),w);
end_define

begin_define
define|#
directive|define
name|dbgxw
parameter_list|(
name|w
parameter_list|)
value|fprintf(stderr,dbgxstring,STRINGIFY(w),(0xFFFF& w));
end_define

begin_define
define|#
directive|define
name|eol
value|fprintf(stderr,"\n"); fflush(stderr);
end_define

begin_define
define|#
directive|define
name|eor
value|eol } else {}
end_define

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|x
parameter_list|)
value|{if (!(x)) {		\ 	fprintf(stderr,"(x) failed\n");	\ 	assertionFailedMacro		\ 	exit(99);			\ 	} }
end_define

begin_decl_stmt
specifier|static
name|char
name|dbgaxlstring
index|[]
init|=
literal|" %s[%d]=0x%lx"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|dbgbstring
index|[]
init|=
literal|" %s=%s"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|dbgcstring
index|[]
init|=
literal|" %s='%c'"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|dbgdstring
index|[]
init|=
literal|" %s=%d"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|dbggstring
index|[]
init|=
literal|" %s=%g"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|dbgostring
index|[]
init|=
literal|" %s=%o"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|dbgsstring
index|[]
init|=
literal|" %s=\"%s\""
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|dbgxstring
index|[]
init|=
literal|" %s=0x%x"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|dbgxlstring
index|[]
init|=
literal|" %s=0x%lx"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dbg
parameter_list|(
name|s
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|dbgaxl
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|dbgb
parameter_list|(
name|s
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|dbgo
parameter_list|(
name|s
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|dbgs
parameter_list|(
name|s
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|dbgg
parameter_list|(
name|s
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|dbgd
parameter_list|(
name|s
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|dbgc
parameter_list|(
name|s
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|dbgx
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|dbgxl
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|dbgxw
parameter_list|(
name|w
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|eol
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|eor
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

