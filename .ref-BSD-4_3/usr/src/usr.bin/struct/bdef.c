begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)bdef.c	4.1	(Berkeley)	2/11/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_define
define|#
directive|define
name|xxtop
value|100
end_define

begin_comment
comment|/* max size of xxstack */
end_comment

begin_decl_stmt
name|int
name|xxindent
decl_stmt|,
name|xxval
decl_stmt|,
name|newflag
decl_stmt|,
name|xxmaxchars
decl_stmt|,
name|xxbpertab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xxlineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of lines already output */
end_comment

begin_decl_stmt
name|int
name|xxstind
decl_stmt|,
name|xxstack
index|[
name|xxtop
index|]
decl_stmt|,
name|xxlablast
decl_stmt|,
name|xxt
decl_stmt|;
end_decl_stmt

end_unit

