begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * macros.h - macro definitions for Phantasia  */
end_comment

begin_define
define|#
directive|define
name|ROLL
parameter_list|(
name|BASE
parameter_list|,
name|INTERVAL
parameter_list|)
value|floor((BASE) + (INTERVAL) * drandom())
end_define

begin_define
define|#
directive|define
name|SGN
parameter_list|(
name|X
parameter_list|)
value|((X)< 0 ? -1 : 1)
end_define

begin_define
define|#
directive|define
name|CIRCLE
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|floor(distance(X, 0.0, Y, 0.0) / 125.0 + 1)
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|((A)> (B) ? (A) : (B))
end_define

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|((A)< (B) ? (A) : (B))
end_define

begin_define
define|#
directive|define
name|ILLCMD
parameter_list|()
value|mvaddstr(5, 0, Illcmd)
end_define

begin_define
define|#
directive|define
name|MAXMOVE
parameter_list|()
value|(Player.p_level * 1.5 + 1)
end_define

begin_define
define|#
directive|define
name|ILLMOVE
parameter_list|()
value|mvaddstr(5, 0, Illmove)
end_define

begin_define
define|#
directive|define
name|ILLSPELL
parameter_list|()
value|mvaddstr(5, 0, Illspell)
end_define

begin_define
define|#
directive|define
name|NOMANA
parameter_list|()
value|mvaddstr(5, 0, Nomana)
end_define

begin_define
define|#
directive|define
name|SOMEBETTER
parameter_list|()
value|addstr(Somebetter)
end_define

begin_define
define|#
directive|define
name|NOBETTER
parameter_list|()
value|mvaddstr(17, 0, Nobetter)
end_define

end_unit

