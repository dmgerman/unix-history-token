begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Mini EMBED (pair.c) */
end_comment

begin_define
define|#
directive|define
name|chkpage
value|sdbm__chkpage
end_define

begin_define
define|#
directive|define
name|delpair
value|sdbm__delpair
end_define

begin_define
define|#
directive|define
name|duppair
value|sdbm__duppair
end_define

begin_define
define|#
directive|define
name|fitpair
value|sdbm__fitpair
end_define

begin_define
define|#
directive|define
name|getnkey
value|sdbm__getnkey
end_define

begin_define
define|#
directive|define
name|getpair
value|sdbm__getpair
end_define

begin_define
define|#
directive|define
name|putpair
value|sdbm__putpair
end_define

begin_define
define|#
directive|define
name|splpage
value|sdbm__splpage
end_define

begin_decl_stmt
specifier|extern
name|int
name|fitpair
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|putpair
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|,
name|datum
operator|,
name|datum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|datum
name|getpair
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|,
name|datum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|delpair
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|,
name|datum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|chkpage
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|datum
name|getnkey
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|splpage
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SEEDUPS
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|duppair
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|,
name|datum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

