begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|B300
value|7
end_define

begin_define
define|#
directive|define
name|B1200
value|9
end_define

begin_define
define|#
directive|define
name|B2400
value|11
end_define

begin_define
define|#
directive|define
name|B9600
value|13
end_define

begin_define
define|#
directive|define
name|TIOCGETP
value|_IOR(t, 8,struct sgttyb)
end_define

begin_comment
comment|/* get parameters -- gtty */
end_comment

begin_define
define|#
directive|define
name|TIOCSETP
value|_IOW(t, 9,struct sgttyb)
end_define

begin_comment
comment|/* set parameters -- stty */
end_comment

begin_define
define|#
directive|define
name|CBREAK
value|0x00000002
end_define

begin_comment
comment|/* half-cooked mode */
end_comment

begin_define
define|#
directive|define
name|LCASE
value|0x00000004
end_define

begin_comment
comment|/* simulate lower case */
end_comment

begin_define
define|#
directive|define
name|ECHO
value|0x00000008
end_define

begin_comment
comment|/* echo input */
end_comment

begin_define
define|#
directive|define
name|CRMOD
value|0x00000010
end_define

begin_comment
comment|/* map \r to \r\n on output */
end_comment

begin_define
define|#
directive|define
name|RAW
value|0x00000020
end_define

begin_comment
comment|/* no i/o processing */
end_comment

begin_define
define|#
directive|define
name|XTABS
value|0x00000c00
end_define

begin_comment
comment|/* expand tabs on output */
end_comment

begin_struct
struct|struct
name|sgttyb
block|{
name|char
name|sg_ispeed
decl_stmt|;
comment|/* input speed */
name|char
name|sg_ospeed
decl_stmt|;
comment|/* output speed */
name|char
name|sg_erase
decl_stmt|;
comment|/* erase character */
name|char
name|sg_kill
decl_stmt|;
comment|/* kill character */
name|short
name|sg_flags
decl_stmt|;
comment|/* mode flags */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tchars
block|{
name|char
name|t_intrc
decl_stmt|;
comment|/* interrupt */
name|char
name|t_quitc
decl_stmt|;
comment|/* quit */
name|char
name|t_startc
decl_stmt|;
comment|/* start output */
name|char
name|t_stopc
decl_stmt|;
comment|/* stop output */
name|char
name|t_eofc
decl_stmt|;
comment|/* end-of-file */
name|char
name|t_brkc
decl_stmt|;
comment|/* input delimiter (like nl) */
block|}
struct|;
end_struct

end_unit

