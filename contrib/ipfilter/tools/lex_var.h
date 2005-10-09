begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_decl_stmt
specifier|extern
name|long
name|string_start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|string_end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|string_val
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|pos
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|YY_INPUT
parameter_list|(
name|buf
parameter_list|,
name|result
parameter_list|,
name|max_size
parameter_list|)
define|\
value|if (pos>= string_start&& pos<= string_end) { \ 		buf[0] = string_val[pos - string_start]; \ 		pos++; \ 		result = 1; \ 	} else if ( yy_current_buffer->yy_is_interactive ) \ 		{ \ 		int c = '*', n; \ 		for ( n = 0; n< 1&& \ 			     (c = getc( yyin )) != EOF&& c != '\n'; ++n ) \ 			buf[n] = (char) c; \ 		if ( c == '\n' ) \ 			buf[n++] = (char) c; \ 		if ( c == EOF&& ferror( yyin ) ) \ 			YY_FATAL_ERROR( "input in flex scanner failed" ); \ 		result = n; \ 		pos++; \ 		} \ 	else if ( ((result = fread( buf, 1, 1, yyin )) == 0) \&& ferror( yyin ) ) \ 		YY_FATAL_ERROR( "input in flex scanner failed" );
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|input
end_ifdef

begin_undef
undef|#
directive|undef
name|input
end_undef

begin_define
define|#
directive|define
name|input
parameter_list|()
value|(((pos>= string_start)&& (pos< string_end)) ? \ 		  yysptr = yysbuf, string_val[pos++ - string_start] : \ 		  ((yytchar = yysptr> yysbuf ? U(*--yysptr) : \ 		   getc(yyin)) == 10 ? (pos++, yylineno++, yytchar) : \ 		  yytchar) == EOF ? (pos++, 0) : (pos++, yytchar))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|lex_input
end_ifdef

begin_undef
undef|#
directive|undef
name|lex_input
end_undef

begin_define
define|#
directive|define
name|lex_input
parameter_list|()
value|(((pos>= string_start)&& (pos< string_end)) ? \ 		  yysptr = yysbuf, string_val[pos++ - string_start] : \ 		  ((yytchar = yysptr> yysbuf ? U(*--yysptr) : \ 		   getc(yyin)) == 10 ? (pos++, yylineno++, yytchar) : \ 		  yytchar) == EOF ? (pos++, 0) : (pos++, yytchar))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|unput
end_ifdef

begin_undef
undef|#
directive|undef
name|unput
end_undef

begin_define
define|#
directive|define
name|unput
parameter_list|(
name|c
parameter_list|)
value|{ if (pos> 0) pos--; \ 		    yytchar = (c); if (yytchar == '\n') yylineno--; \ 		    *yysptr++ = yytchar; }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

