begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Ex - a text editor  * Bill Joy UCB September 1977  */
end_comment

begin_decl_stmt
name|int
name|TTY
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|CLEAR
decl_stmt|,
modifier|*
name|NDSPACE
decl_stmt|,
modifier|*
name|UPLINE
decl_stmt|,
modifier|*
name|HSTR
decl_stmt|,
modifier|*
name|CE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|CA
decl_stmt|,
name|AM
decl_stmt|,
name|BS
decl_stmt|,
name|OS
decl_stmt|,
name|PT
decl_stmt|,
name|NOCR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|LINES
decl_stmt|,
name|COLUMNS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|UPPERCASE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ttytype
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|outcol
decl_stmt|,
name|outline
decl_stmt|,
name|destcol
decl_stmt|,
name|destline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * As yet unused capabilities...  * char	*AL, *DL, *CD; char	IT; int	MODES[2];  */
end_comment

end_unit

