begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: us.h,v 7.0.1.1 86/10/16 10:53:58 lwall Exp $ */
end_comment

begin_comment
comment|/* $Log:	us.h,v $  * Revision 7.0.1.1  86/10/16  10:53:58  lwall  * Added Damage.  Fixed random bugs.  *   * Revision 7.0  86/10/08  15:14:27  lwall  * Split into separate files.  Added amoebas and pirates.  *   */
end_comment

begin_decl_stmt
name|EXT
name|bool
name|cloaking
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|bool
name|cloaked
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|status
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|entmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|evely
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|evelx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|bvely
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|bvelx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAXDAMAGE
value|9
end_define

begin_define
define|#
directive|define
name|NOWARP
value|0
end_define

begin_define
define|#
directive|define
name|NOIMPULSE
value|1
end_define

begin_define
define|#
directive|define
name|NOPHASERS
value|2
end_define

begin_define
define|#
directive|define
name|NOTORPS
value|3
end_define

begin_define
define|#
directive|define
name|NOCLOAKING
value|4
end_define

begin_define
define|#
directive|define
name|NOSHIELDS
value|5
end_define

begin_define
define|#
directive|define
name|NOZAPPER
value|6
end_define

begin_define
define|#
directive|define
name|NODESTRUCT
value|7
end_define

begin_define
define|#
directive|define
name|NOTRACTORS
value|8
end_define

begin_decl_stmt
name|EXT
name|int
name|dam
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|lastdam
name|INIT
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|damage
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|olddamage
name|INIT
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|dammess
index|[
name|MAXDAMAGE
index|]
init|=
block|{
literal|"WARP"
block|,
literal|"IMPULSE"
block|,
literal|"PHASERS"
block|,
literal|"TORPS"
block|,
literal|"CLOAKING"
block|,
literal|"SHIELDS"
block|,
literal|"ZAPPER"
block|,
literal|"DESTRUCT"
block|,
literal|"TRACTORS"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|damflag
index|[
name|MAXDAMAGE
index|]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dammess
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|damflag
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|do_direction
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctrl_direction
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|shift_direction
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_commands
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|us_init
parameter_list|()
function_decl|;
end_function_decl

end_unit

