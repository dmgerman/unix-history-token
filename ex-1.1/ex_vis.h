begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Ex - a text editor  * Bill Joy UCB June 1977  */
end_comment

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
name|FS
value|CTRL(\\\\)
end_define

begin_define
define|#
directive|define
name|NL
value|CTRL(j)
end_define

begin_define
define|#
directive|define
name|CR
value|CTRL(m)
end_define

begin_define
define|#
directive|define
name|INF
value|30000
end_define

begin_define
define|#
directive|define
name|DELETE
value|0177
end_define

begin_define
define|#
directive|define
name|ESCAPE
value|033
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VISUAL
end_ifdef

begin_decl_stmt
name|char
name|visual
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|cursor
decl_stmt|,
modifier|*
name|wcursor
decl_stmt|,
modifier|*
name|tcursor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vlast
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|vputc
parameter_list|(
name|c
parameter_list|)
value|putc(c,&obuf)
end_define

begin_define
define|#
directive|define
name|TUBELINES
value|24
end_define

begin_define
define|#
directive|define
name|TUBECOLS
value|160
end_define

begin_define
define|#
directive|define
name|TUBESIZE
value|1920
end_define

begin_decl_stmt
name|char
name|vliny
index|[
name|TUBELINES
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vcline
decl_stmt|,
name|vcnt
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ESCAPE
value|033
end_define

begin_decl_stmt
name|char
name|vch
decl_stmt|,
modifier|*
name|vtube
index|[
name|TUBELINES
index|]
decl_stmt|,
modifier|*
name|vtube0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|VLINES
decl_stmt|,
name|VCOLUMNS
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|vlast
value|vliny[vcnt]
end_define

begin_decl_stmt
name|char
name|vmoving
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|vmovcol
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|vdelete
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|Outchar
argument_list|)
argument_list|()
decl_stmt|,
name|qcount
argument_list|()
decl_stmt|,
name|vputchar
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|VISUAL
end_ifdef

begin_decl_stmt
name|char
name|vholdmove
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|beep
value|obeep
end_define

begin_decl_stmt
name|int
name|vcntcol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|holdat
decl_stmt|,
name|splitw
decl_stmt|,
name|hadup
decl_stmt|,
modifier|*
name|nextic
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VNONE
value|0
end_define

begin_define
define|#
directive|define
name|VCHNG
value|1
end_define

begin_define
define|#
directive|define
name|VMANY
value|2
end_define

begin_decl_stmt
name|char
name|vundkind
decl_stmt|,
modifier|*
name|vutmp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vulines
index|[
name|TUBELINES
index|]
decl_stmt|,
name|vylines
index|[
name|TUBELINES
index|]
decl_stmt|,
modifier|*
name|vresaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vrestore
argument_list|()
decl_stmt|,
name|vrescnt
decl_stmt|,
name|vresCNT
decl_stmt|,
name|vdelcnt
decl_stmt|,
name|vrescurs
decl_stmt|,
name|vyancnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|wdkind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vSCROLL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
argument_list|(
operator|*
name|Pline
argument_list|)
argument_list|()
decl_stmt|,
name|numbline
argument_list|()
decl_stmt|,
name|normline
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BUFSIZE
value|128
end_define

begin_decl_stmt
name|char
name|Xhadcnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Xcnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|lasthad
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lastcnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|lastcmd
index|[
literal|5
index|]
decl_stmt|,
modifier|*
name|lastcp
decl_stmt|,
name|workcmd
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|DEL
index|[
name|BUFSIZE
index|]
decl_stmt|,
name|INS
index|[
name|BUFSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|OVERBUF
value|CR
end_define

begin_decl_stmt
name|char
modifier|*
name|vglobp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|HADUP
decl_stmt|,
name|HADZERO
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|CDCNT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ZERO
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ogcursor
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

