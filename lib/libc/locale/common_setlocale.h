begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|categories
value|_categories
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_categories
index|[
name|_LC_LAST
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|current_categories
value|_current_categories
end_define

begin_decl_stmt
specifier|extern
name|char
name|_current_categories
index|[
name|_LC_LAST
index|]
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|new_categories
value|_new_categories
end_define

begin_decl_stmt
specifier|extern
name|char
name|_new_categories
index|[
name|_LC_LAST
index|]
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|current_locale_string
value|_current_locale_string
end_define

begin_decl_stmt
specifier|extern
name|char
name|_current_locale_string
index|[
name|_LC_LAST
operator|*
literal|33
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|currentlocale
value|_currentlocale
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_currentlocale
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

