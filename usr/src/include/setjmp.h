begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	setjmp.h	4.2	89/10/16	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SETJMP_
end_ifndef

begin_define
define|#
directive|define
name|_SETJMP_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|_JBLEN
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_define
define|#
directive|define
name|_JBLEN
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|hp300
end_ifdef

begin_define
define|#
directive|define
name|_JBLEN
value|17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|jmp_buf
index|[
name|_JBLEN
index|]
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|setjmp
argument_list|(
name|jmp_buf
argument_list|)
decl_stmt|,
name|_setjmp
argument_list|(
name|jmp_buf
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|longjmp
argument_list|(
name|jmp_buf
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|_longjmp
argument_list|(
name|jmp_buf
argument_list|,
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__STDC__ */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|setjmp
argument_list|()
decl_stmt|,
name|_setjmp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|longjmp
argument_list|()
decl_stmt|,
name|_longjmp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

